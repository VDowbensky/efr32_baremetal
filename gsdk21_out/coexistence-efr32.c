// -----------------------------------------------------------------------------
/// @file
/// @brief Radio coexistence EFR32 utilities
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
#include "coexistence/coexistence-efr32.h"

#ifdef HAL_CONFIG
#include HAL_CONFIG

#ifdef BSP_COEX_GNT_PORT
static COEX_EFR32_GpioConfig_t ptaGntCfg = {
  .port = BSP_COEX_GNT_PORT,
  .pin = BSP_COEX_GNT_PIN,
  .polarity = BSP_COEX_GNT_ASSERT_LEVEL
};
#endif //BSP_COEX_GNT_PORT

#ifdef BSP_COEX_PRI_PORT
static COEX_EFR32_GpioConfig_t ptaPriCfg = {
  .port = BSP_COEX_PRI_PORT,
  .pin = BSP_COEX_PRI_PIN,
  .polarity = BSP_COEX_PRI_ASSERT_LEVEL
};
#endif //BSP_COEX_PRI_PORT

#ifdef BSP_COEX_REQ_PORT
static COEX_EFR32_GpioConfig_t ptaReqCfg = {
  .port = BSP_COEX_REQ_PORT,
  .pin = BSP_COEX_REQ_PIN,
  .polarity = BSP_COEX_REQ_ASSERT_LEVEL
};
#endif //BSP_COEX_REQ_PORT

#ifdef BSP_COEX_RHO_PORT
static COEX_EFR32_GpioConfig_t rhoCfg = {
  .port = BSP_COEX_RHO_PORT,
  .pin = BSP_COEX_RHO_PIN,
  .polarity = BSP_COEX_RHO_ASSERT_LEVEL
};
#endif //BSP_COEX_RHO_PORT

#endif //HAL_CONFIG

#define GPIO_FLAG(x) (1ul << x)

extern uint16_t RFRAND_GetPseudoRandom(void);

static void (*reqCallback)(void) = NULL;
static void (*gntCallback)(void) = NULL;
static void (*rhoCallback)(void) = NULL;

static void COEX_EFR32_REQ_ISR(uint8_t pin)
{
  (void)pin;
  reqCallback();
}

static void COEX_EFR32_GNT_ISR(uint8_t pin)
{
  (void)pin;
  gntCallback();
}

static void COEX_EFR32_RHO_ISR(uint8_t pin)
{
  (void)pin;
  rhoCallback();
}

static void setGpioConfig(COEX_GpioHandle_t gpioHandle)
{
  COEX_EFR32_GpioConfig_t *gpio = (COEX_EFR32_GpioConfig_t*)gpioHandle;
  GPIO_PinModeSet(gpio->port, gpio->pin,
                  gpio->mode, GPIO_PinOutGet(gpio->port, gpio->pin));
}

static GPIO_Mode_TypeDef getGpioConfig(COEX_GpioHandle_t gpioHandle)
{
  COEX_EFR32_GpioConfig_t *gpio = (COEX_EFR32_GpioConfig_t*)gpioHandle;
  return (GPIO_Mode_TypeDef)
         ((BUS_RegMaskedRead((gpio->pin < 8) ? &GPIO->P[gpio->port].MODEL
                             : &GPIO->P[gpio->port].MODEH,
                             0xF << ((gpio->pin % 8) * 4))) >> ((gpio->pin % 8) * 4));
}

static void enableGpioInt(COEX_GpioHandle_t gpioHandle,
                          bool enabled,
                          bool *wasAsserted)
{
  COEX_EFR32_GpioConfig_t *gpio = (COEX_EFR32_GpioConfig_t*)gpioHandle;
  COEX_GpioConfig_t *railGpio = &(gpio->config);

  bool intAsserted = railGpio->options & COEX_GPIO_OPTION_INT_ASSERTED;
  bool intDeasserted = railGpio->options & COEX_GPIO_OPTION_INT_DEASSERTED;

  if (enabled) {
    // Disable triggering and clear any stale events
    GPIO_IntConfig(gpio->port, gpio->pin,
                   false, false, false);
    if (wasAsserted != NULL) {
      *wasAsserted = false; // Ensures we won't miss GNT assertion
    }
    // Register callbacks before setting up and enabling pin interrupt
    GPIOINT_CallbackRegister(gpio->pin, gpio->isr);
    // Enable both edges' interrupt
    GPIO_IntConfig(gpio->port,
                   gpio->pin,
                   gpio->polarity ? intAsserted : intDeasserted,
                   gpio->polarity ? intDeasserted : intAsserted,
                   true);
  } else {
    GPIO_IntDisable(GPIO_FLAG(gpio->pin));
    GPIO_IntClear(GPIO_FLAG(gpio->pin));
  }
}

static void setGpio(COEX_GpioHandle_t gpioHandle, bool enabled)
{
  COEX_EFR32_GpioConfig_t *gpio = (COEX_EFR32_GpioConfig_t*)gpioHandle;

  if (enabled == gpio->polarity) {
    GPIO_PinOutSet(gpio->port, gpio->pin);
  } else {
    GPIO_PinOutClear(gpio->port, gpio->pin);
  }
}

static void configGpio(COEX_GpioHandle_t gpioHandle, COEX_GpioConfig_t *railGpio)
{
  COEX_EFR32_GpioConfig_t *gpio = (COEX_EFR32_GpioConfig_t*)gpioHandle;
  bool defaultAsserted = railGpio->options & COEX_GPIO_OPTION_DEFAULT_ASSERTED;
  gpio->config = *railGpio;

  // Only configure GPIO if it was not set up prior
  if (getGpioConfig(gpio) == gpioModeDisabled) {
    if (railGpio->options & COEX_GPIO_OPTION_SHARED) {
      gpio->mode = gpio->polarity ? gpioModeWiredOr : gpioModeWiredAnd;
    } else if (railGpio->options & COEX_GPIO_OPTION_OUTPUT) {
      gpio->mode = gpioModePushPull;
    } else {
      gpio->mode = gpioModeInputPull;
    }
    setGpioConfig(gpio);
    setGpio(gpio, defaultAsserted);
  }
  // Here we sense asserted state is opposite of its current output state.
  gpio->polarity = (defaultAsserted == (bool)(!!GPIO_PinOutGet(gpio->port, gpio->pin)));
}

static void setGpioFlag(COEX_GpioHandle_t gpioHandle, bool enabled)
{
  COEX_EFR32_GpioConfig_t *gpio = (COEX_EFR32_GpioConfig_t*)gpioHandle;

  if (enabled) {
    GPIO_IntSet(GPIO_FLAG(gpio->pin));
  } else {
    GPIO_IntClear(GPIO_FLAG(gpio->pin));
  }
}

static bool isGpioOutSet(COEX_GpioHandle_t gpioHandle)
{
  COEX_EFR32_GpioConfig_t *gpio = (COEX_EFR32_GpioConfig_t*)gpioHandle;
  return !!GPIO_PinOutGet(gpio->port, gpio->pin) == !!gpio->polarity;
}

static bool isGpioInSet(COEX_GpioHandle_t gpioHandle)
{
  COEX_EFR32_GpioConfig_t *gpio = (COEX_EFR32_GpioConfig_t*)gpioHandle;
  return !!GPIO_PinInGet(gpio->port, gpio->pin) == !!gpio->polarity;
}

static void randomDelay(uint16_t randomDelayMaskUs)
{
  uint32_t startTime = RAIL_GetTime();
  uint16_t delay = RFRAND_GetPseudoRandom() & randomDelayMaskUs;

  while ((uint16_t)(RAIL_GetTime() - startTime) > delay) ;
}

static const COEX_HalCallbacks_t coexHalCallbacks = {
  .randomDelay = &randomDelay,
  .setGpio = &setGpio,
  .setGpioFlag = &setGpioFlag,
  .enableGpioInt = &enableGpioInt,
  .configGpio = &configGpio,
  .isGpioOutSet = &isGpioOutSet,
  .isGpioInSet = &isGpioInSet
};

bool COEX_EFR32_ConfigRequest(COEX_EFR32_GpioConfig_t *gpioConfig)
{
  bool status = false;

  gpioConfig->isr = &COEX_EFR32_REQ_ISR;
  status = COEX_ConfigRequest(gpioConfig);
  if (status) {
    reqCallback = gpioConfig->config.cb;
  }
  return status;
}

bool COEX_EFR32_ConfigRadioHoldOff(COEX_EFR32_GpioConfig_t *gpioConfig)
{
  bool status = false;

  gpioConfig->isr = &COEX_EFR32_RHO_ISR;
  status = COEX_ConfigRadioHoldOff(gpioConfig);
  if (status) {
    rhoCallback = gpioConfig->config.cb;
  }
  return status;
}

bool COEX_EFR32_ConfigPriority(COEX_EFR32_GpioConfig_t *gpioConfig)
{
  return COEX_ConfigPriority(gpioConfig);
}

bool COEX_EFR32_ConfigGrant(COEX_EFR32_GpioConfig_t *gpioConfig)
{
  bool status = false;

  gpioConfig->isr = &COEX_EFR32_GNT_ISR;
  status = COEX_ConfigGrant(gpioConfig);
  if (status) {
    gntCallback = gpioConfig->config.cb;
  }
  return status;
}

void COEX_EFR32_Init(void)
{
  COEX_SetHalCallbacks(&coexHalCallbacks);
  COEX_Options_t options = (COEX_Options_t)0;

  #ifdef BSP_COEX_REQ_PORT
  COEX_EFR32_ConfigRequest(&ptaReqCfg);
  #endif //BSP_COEX_REQ_PORT
  #ifdef BSP_COEX_RHO_PORT
  COEX_EFR32_ConfigRadioHoldOff(&rhoCfg);
  #endif //BSP_COEX_RHO_PORT
  #ifdef BSP_COEX_PRI_PORT
  COEX_EFR32_ConfigPriority(&ptaPriCfg);
  #endif //BSP_COEX_PRI_PORT
  #ifdef BSP_COEX_GNT_PORT
  COEX_EFR32_ConfigGrant(&ptaGntCfg);
  #endif //BSP_COEX_GNT_PORT
  #ifdef HAL_COEX_REQ_BACKOFF
  options |= COEX_OPTION_MAX_REQ_BACKOFF_MASK;
  #endif //HAL_COEX_REQ_BACKOFF
  #ifdef HAL_COEX_REQ_SHARED
  options |= COEX_OPTION_REQ_SHARED;
  #endif //HAL_COEX_REQ_SHARED
  #ifdef HAL_COEX_PRI_SHARED
  options |= COEX_OPTION_PRI_SHARED;
  #endif //HAL_COEX_PRI_SHARED
  #ifdef HAL_COEX_TX_ABORT
  options |= COEX_OPTION_TX_ABORT;
  #endif //HAL_COEX_TX_ABORT
  COEX_SetOptions(options);
}
