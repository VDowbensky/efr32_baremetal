// -----------------------------------------------------------------------------
/// @file coexistence.c
/// @brief Radio coexistence utilities
///
/// @author Silicon Laboratories Inc.
/// @version 1.0.0
///
/// @section License
/// <b>(C) Copyright 2017 Silicon Laboratories, http://www.silabs.com</b>
///
/// This file is licensed under the Silabs License Agreement. See the file
/// "Silabs_License_Agreement.txt" for details. Before using this software for
/// any purpose, you must agree to the terms of that agreement.
///
// -----------------------------------------------------------------------------
#include "em_core.h"
#include "coexistence/coexistence.h"

#define coexReqAndGntIrqShared() \
  (reqCfg.cb == &COEX_GNT_ISR)

#define NUM_COEX_REQ_MODES 3

static void (*setCoexPowerStateCallbackPtr)(bool powerUp);
static bool (*setCoexReqCallbackPtr)(COEX_Req_t coexReq, COEX_ReqMode_t coexReqMode);
static const COEX_HalCallbacks_t *coexHalCallbacks;
static const COEX_RadioCallbacks_t *coexRadioCallbacks;
static void coexNotifyRadio(void);

/** PTA radio hold off GPIO configuration */
COEX_GpioHandle_t rhoHandle = NULL;

/** PTA grant GPIO configuration */
COEX_GpioHandle_t gntHandle = NULL;

/** PTA request GPIO configuration */
COEX_GpioHandle_t reqHandle = NULL;

/** PTA priority GPIO configuration */
COEX_GpioHandle_t priHandle = NULL;

typedef struct COEX_Cfg{
  /** PTA request states*/
  volatile COEX_Req_t reqStates[NUM_COEX_REQ_MODES];
  volatile COEX_Req_t combinedReqState;
  volatile bool radioOn : 1;

  COEX_Options_t options;
} COEX_Cfg_t;

static void COEX_REQ_ISR(void);
static void COEX_GNT_ISR(void);
static void RHO_ISR(void);

static COEX_Cfg_t coexCfg;

static COEX_GpioConfig_t rhoCfg = {
  .options = (COEX_GpioOptions_t)(COEX_GPIO_OPTION_INT_ASSERTED
                                  | COEX_GPIO_OPTION_INT_DEASSERTED),
  .cb = &RHO_ISR
};

static COEX_GpioConfig_t gntCfg = {
  .options = (COEX_GpioOptions_t)(COEX_GPIO_OPTION_INT_ASSERTED
                                  | COEX_GPIO_OPTION_INT_DEASSERTED),
  .cb = &COEX_GNT_ISR
};

static COEX_GpioConfig_t reqCfg = {
  .options = (COEX_GpioOptions_t)(COEX_GPIO_OPTION_INT_DEASSERTED
                                  | COEX_GPIO_OPTION_OUTPUT),
  .cb = &COEX_REQ_ISR
};

static COEX_GpioConfig_t priCfg = {
  .options = COEX_GPIO_OPTION_OUTPUT
};

/** @brief Enables or disables Radio HoldOff support
 *
 * @return true if Radio HoldOff was configured as desired
 * or false if requesting it be enabled but RHO has not
 * been configured by the BOARD_HEADER.
 */
static bool setRadioHoldOff(COEX_GpioHandle_t gpioHandle);

static bool gntWasAsserted = false;

void COEX_SetHalCallbacks(const COEX_HalCallbacks_t *callbacks)
{
  coexHalCallbacks = callbacks;
}

void COEX_SetRadioCallbacks(const COEX_RadioCallbacks_t *callbacks)
{
  coexRadioCallbacks = callbacks;
}

static bool isReqShared(void)
{
  return reqCfg.options & COEX_GPIO_OPTION_SHARED;
}

static void coexReqRandomBackoff(void)
{
  if (coexHalCallbacks->randomDelay != NULL) {
    coexHalCallbacks->randomDelay(coexCfg.options
                                  & COEX_OPTION_MAX_REQ_BACKOFF_MASK);
  }
}

static void setGpio(COEX_GpioHandle_t gpioHandle, bool enabled)
{
  if (coexHalCallbacks->setGpio != NULL && gpioHandle != NULL) {
    coexHalCallbacks->setGpio(gpioHandle, enabled);
  }
}

static bool isGpioInSet(COEX_GpioHandle_t gpioHandle, bool defaultValue)
{
  if (coexHalCallbacks->isGpioInSet != NULL && gpioHandle != NULL) {
    return coexHalCallbacks->isGpioInSet(gpioHandle);
  }
  return defaultValue;
}

static bool getGpioOut(COEX_GpioHandle_t gpioHandle, bool defaultValue)
{
  if (coexHalCallbacks->isGpioOutSet != NULL && gpioHandle != NULL) {
    return coexHalCallbacks->isGpioOutSet(gpioHandle);
  }
  return defaultValue;
}

static void enableGpioInt(COEX_GpioHandle_t gpioHandle, bool *wasAsserted)
{
  if (coexHalCallbacks->enableGpioInt != NULL && gpioHandle != NULL) {
    coexHalCallbacks->enableGpioInt(gpioHandle, true, wasAsserted);
  }
}

static void disableGpioInt(COEX_GpioHandle_t gpioHandle)
{
  if (coexHalCallbacks->enableGpioInt != NULL && gpioHandle != NULL) {
    coexHalCallbacks->enableGpioInt(gpioHandle, false, NULL);
  }
}

static void setGpioFlag(COEX_GpioHandle_t gpioHandle)
{
  if (coexHalCallbacks->setGpioFlag != NULL && gpioHandle != NULL) {
    coexHalCallbacks->setGpioFlag(gpioHandle, true);
  }
}

static void clearGpioFlag(COEX_GpioHandle_t gpioHandle)
{
  if (coexHalCallbacks->setGpioFlag != NULL && gpioHandle != NULL) {
    coexHalCallbacks->setGpioFlag(gpioHandle, false);
  }
}

static void configGpio(COEX_GpioHandle_t gpioHandle,
                       COEX_GpioHandle_t *handlePtr,
                       COEX_GpioConfig_t *config)
{
  if (coexHalCallbacks->configGpio != NULL) {
    if (*handlePtr != NULL && config->cb != NULL) {
      disableGpioInt(*handlePtr);
    }
    *handlePtr = gpioHandle;
    if (gpioHandle != NULL) {
      coexHalCallbacks->configGpio(gpioHandle, config);
    }
  }
}

static void abortTx(void)
{
  if (coexRadioCallbacks->abortTx != NULL) {
    coexRadioCallbacks->abortTx();
  }
}

static void toggleCoexReq(void)
{
  if ( (coexCfg.options
        & COEX_OPTION_PULSE_REQ_ON_RHO_RELEASE) // Pulse request on RHO release selected
       && getGpioOut(reqHandle, false)          // REQUESTing and
       && !isGpioInSet(rhoHandle, false)          // RHO not asserted and
       && !isGpioInSet(gntHandle, true)) {        // GRANT not asserted
    setGpio(reqHandle, false);
    setGpio(reqHandle, true);
  }
}

// Must be called with interrupts disabled
static void coexUpdateReqIsr(void)
{
  COEX_Req_t combinedReqState = coexCfg.combinedReqState; // Local non-volatile flavor avoids warnings
  bool myReq = !!(combinedReqState & COEX_REQ_ON);     // I need to REQUEST
  bool force = !!(combinedReqState & COEX_REQ_FORCE);  // (ignoring others)
  bool exReq;                                          // external requestor?
  if (getGpioOut(reqHandle, false)) {  // in GRANT phase
    exReq = false;                // ignore external requestors
  } else {                        // in REQUEST phase
    clearGpioFlag(reqHandle);  // Before sampling REQUEST, avoids race
    exReq = isReqShared() && isGpioInSet(reqHandle, false);
  }
  if (myReq) {                    // want to assert REQUEST
    if (force || !exReq) {        // can assert REQUEST
      clearGpioFlag(gntHandle);
      enableGpioInt(gntHandle, &gntWasAsserted);
      setGpio(reqHandle, true);
      setGpio(priHandle, !!(combinedReqState & COEX_REQ_HIPRI));
      setGpioFlag(gntHandle); // Manually force GRANT check if missed/no edge
    } else {                      // must wait for REQUEST
      enableGpioInt(reqHandle, NULL);
    }
  } else {                        // negate REQUEST
    setGpio(priHandle, false);
    setGpio(reqHandle, false);
    disableGpioInt(gntHandle);
    disableGpioInt(reqHandle);
    coexNotifyRadio(); // Reassess (assert) RHO
  }
}

void COEX_UpdateGrant(void)
{
  if (getGpioOut(reqHandle, false)) {    // GRANT phase
    bool newGnt = isGpioInSet(gntHandle, false);   // Sample GPIO once, now
    if (newGnt != gntWasAsserted) {
      gntWasAsserted = newGnt;
      coexNotifyRadio();

      if (!newGnt) {
        // If grant is lost mid transmit,
        // cancel request if we are transmitting
        if ((coexCfg.options & COEX_OPTION_TX_ABORT)
            && (coexCfg.reqStates[COEX_REQ_MODE_TX] != COEX_REQ_OFF)) {
          abortTx();
        }
        // Issue callbacks on GRANT assert or negate
        // These are not one-shot callbacks
        // Do we need this to meet GRANT -> REQUEST timing?
        // On GNT deassertion, pulse REQUEST to keep us going.
        // Don't want to revert to REQUEST phase here but stay in GRANT phase.
        // This seems dangerous in that it could allow a peer to assert their
        // REQUEST causing a conflict/race.
        if (coexCfg.options & COEX_OPTION_PULSE_REQ_ON_GNT_RELEASE) {
          setGpio(reqHandle, false);
          setGpio(reqHandle, true);
        }
      }
    }
  } else {                          // REQUEST phase
    if (coexReqAndGntIrqShared() && isReqShared()) {
      // External REQUEST deasserted so we can assert ours
      disableGpioInt(reqHandle);   // This is a one-shot event
      coexReqRandomBackoff();
      coexUpdateReqIsr();
    } else {
      // Ignore GRANT changes unless we are REQUESTing
    }
  }
}

// Triggered on both GRANT edges
static void COEX_GNT_ISR(void)
{
  clearGpioFlag(gntHandle);
  COEX_UpdateGrant();
}

// This IRQ is triggered on the negate REQUEST edge,
// needed only when REQUEST signal is shared,
// and not piggybacking GNT and REQ on same IRQ.
static void COEX_REQ_ISR(void)
{
  // External REQUEST deasserted so we can assert ours
  //clearGpioFlag(reqHandle) // Covered within disableGpioInt(reqHandle)
  disableGpioInt(reqHandle); // This is a one-shot event
  coexReqRandomBackoff();
  coexUpdateReqIsr();
}

// Public API
bool COEX_SetRequest(COEX_Req_t coexReq,
                     COEX_ReqMode_t coexReqMode)
{
  bool status = false;

  if (setCoexReqCallbackPtr != NULL) {
    status = setCoexReqCallbackPtr(coexReq, coexReqMode);
  }
  return status;
}

static bool setCoexReqCallback(COEX_Req_t coexReq,
                               COEX_ReqMode_t coexReqMode)
{
  CORE_DECLARE_IRQ_STATE;
  bool status = true;
  unsigned int reqType;
  COEX_Req_t combinedReqState = COEX_REQ_OFF;
  CORE_ENTER_ATOMIC();
  for (reqType = 0; coexReqMode && (reqType < NUM_COEX_REQ_MODES); ++reqType) {
    if (coexReqMode & 1) {
      if (coexCfg.reqStates[reqType] != coexReq) {
        coexCfg.reqStates[reqType] = coexReq;
      }
    }
    combinedReqState |= coexCfg.reqStates[reqType];
    coexReqMode >>= 1;
  }
  coexCfg.combinedReqState = combinedReqState;
  coexUpdateReqIsr();
  status = true;
  CORE_EXIT_ATOMIC();
  return status;
}

static void coexRadioHoldOffPowerDown(void)
{
  coexCfg.radioOn = false;
  // When sleeping radio, no need to monitor RHO anymore
  disableGpioInt(rhoHandle); //clear RHO top level int enable
}

static void coexRadioHoldOffPowerUp(void)
{
  coexCfg.radioOn = true;
  if (rhoHandle != NULL) {
    // When waking radio, set up initial state and resume monitoring
    disableGpioInt(rhoHandle); //ensure RHO interrupt is off
    rhoCfg.cb(); // Manually call ISR to assess current state
    enableGpioInt(rhoHandle, NULL); //enable RHO interrupt
  }
}

void setCoexPowerState(bool powerUp)
{
  if (setCoexPowerStateCallbackPtr != NULL) {
    setCoexPowerStateCallbackPtr(powerUp);
  }
}

static void setCoexPowerStateCallback(bool powerUp)
{
  if (powerUp) {
    coexRadioHoldOffPowerUp();
  } else {
    coexRadioHoldOffPowerDown();
  }
}

static void RHO_ISR(void)
{
  // Ack interrupt before reading GPIO to avoid potential of missing int
  clearGpioFlag(rhoHandle);
  if (rhoHandle != NULL) {
    // Notify Radio land of state change
    toggleCoexReq();
    coexNotifyRadio();
  }
}

static bool setRadioHoldOff(COEX_GpioHandle_t gpioHandle)
{
  // Configure GPIO as input and if pulling, pull it toward deasserted state
  configGpio(gpioHandle, &rhoHandle, &rhoCfg);
  if (coexCfg.radioOn || gpioHandle == NULL) {
    coexNotifyRadio(); //Notify Radio land of current state
  }
  if (coexCfg.radioOn && gpioHandle != NULL) {
    enableGpioInt(rhoHandle, NULL);
  }
  return true;
}

static void coexNotifyRadio(void)
{
  bool coexRho = ((!getGpioOut(reqHandle, true)       // not REQUESTing or
                   || !isGpioInSet(gntHandle, true) ) );    // REQUEST not GRANTed
  if (coexRadioCallbacks->holdOff != NULL) {
    coexRadioCallbacks->holdOff(coexRho || isGpioInSet(rhoHandle, false));
  }
}

bool COEX_IsEnabled(void)
{
  return (rhoHandle != NULL)
         || (gntHandle != NULL)
         || (reqHandle != NULL);
}

bool COEX_ConfigRadioHoldOff(COEX_GpioHandle_t gpioHandle)
{
  setCoexPowerStateCallbackPtr = &setCoexPowerStateCallback;

  if (rhoHandle != gpioHandle) {
    // Register chip specific RHO interrupt
    setRadioHoldOff(gpioHandle);
  }

  return true;
}

bool COEX_ConfigPriority(COEX_GpioHandle_t gpioHandle)
{
  if (coexCfg.options & COEX_OPTION_PRI_SHARED) {
    priCfg.options |= COEX_GPIO_OPTION_SHARED;
  } else {
    priCfg.options &= ~COEX_GPIO_OPTION_SHARED;
  }
  configGpio(gpioHandle, &priHandle, &priCfg);
  return true;
}

bool COEX_ConfigGrant(COEX_GpioHandle_t gpioHandle)
{
  configGpio(gpioHandle, &gntHandle, &gntCfg);
  return true;
}

bool COEX_ConfigRequest(COEX_GpioHandle_t gpioHandle)
{
  setCoexReqCallbackPtr = &setCoexReqCallback;

  if (coexCfg.options & COEX_OPTION_REQ_SHARED) {
    reqCfg.options |= COEX_GPIO_OPTION_SHARED;
  } else {
    reqCfg.options &= ~COEX_GPIO_OPTION_SHARED;
  }
  configGpio(gpioHandle, &reqHandle, &reqCfg);
  COEX_SetRequest(COEX_REQ_OFF, COEX_REQ_MODE_ALL);

  return true;
}

bool COEX_SetOptions(COEX_Options_t options)
{
  coexCfg.options = options;
  return true;
}

COEX_Options_t COEX_GetOptions(void)
{
  return coexCfg.options;
}
