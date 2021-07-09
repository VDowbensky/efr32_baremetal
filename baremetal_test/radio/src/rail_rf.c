#include "rail_rf.h"
#include <stdbool.h>
#include "em_bus.h"
#include "em_assert.h"
#include <stddef.h>
#include "rail_rf_hal.h"
#include "rail_calibration.h"

RAIL_ChannelConfig_t channelConfig;
uint32_t RAIL_DebugMode;

/**
 * Initialize RAIL
 *
 * @param[in] railInit The initialization structure to be used for setting up
 *   the library. This will contain memory and other options needed by RAIL.
 * @return Returns zero on success and an error code on error.
 *
 * RF initialization sets the overall maximum packet length, the xtal frequency
 * of the radio, and the calibrations to perform.
 */
 
 
uint8_t RAIL_RfInit(const RAIL_Init_t *railInit)

{
  RAIL_RfHalCalibrationInit(*(uint32_t *)(railInit + 8) & 0x10001);
  RAIL_RfHalInit(railInit);
  return 0; //dummy
}


/**
 * Place the radio into an idle state
 *
 * @return void
 *
 * This function is used to remove the radio from TX and RX states.
 */
void RAIL_RfIdle(void)

{
  RAIL_RfHalIdleStart();
}

/**
 * Get the current radio state
 *
 * @return An enumeration for current radio state
 *
 * Returns the state of the radio as either TX, RX, or IDLE. There are
 * intermediate states that the radio can transistion through which are not
 * reported, but are instead bucketed into the state being transitioned
 * into. (Example: When the transmitter is in the process of shutting down,
 * this function will return TX, as if the shutdown process hadn't started yet)
 */
RAIL_RadioState_t RAIL_RfStateGet(void)

{
  return RAIL_RfHalStateGet();
}

/**
 * Check to see if the channel exists in RAIL
 *
 * @param[in] channel Channel number to check
 * @return Returns 1 on failure, returns 0 on channel exists
 *
 * Will return 1 if the given channel does not exist in the channel config
 * currently being used, and 0 if the channel is valid.
 */
RAIL_Status_t RAIL_ChannelExists(uint8_t channel)

{
//  uint8_t numconfigs;
//  int iVar2;
//  RAIL_ChannelConfigEntry_t config[];
//
//  numconfigs = 0;
//
//	if(channelConfig->length == 0)
//	{
//		return RAIL_STATUS_INVALID_PARAMETER;
//	}
//
//	for (numconfigs = 0; numconfigs < channelConfig->length; numconfigs++ )
//	  {
//		  if ((channel < config[numconfigs]->channelNumberStart) || (channel > config[numconfigs]->channelNumberEnd))
//		  return RAIL_STATUS_INVALID_PARAMETER;
//	  }
  return RAIL_STATUS_NO_ERROR;
}



uint16_t ** RAILInt_SetChannelConfig(uint16_t cfg)

{
	uint16_t **ppuVar1;
	uint16_t **ppuVar2;
	uint16_t **ppuVar3;
  
//  ppuVar3 = channelConfig;
//  if (channelConfig != NULL) {
//    ppuVar1 = (uint16_t **)*channelConfig;
//    if (ppuVar1 == NULL)
//    {
//      return NULL;
//    }
//    ppuVar3 = (uint16_t **)channelConfig[1];
//    if (ppuVar3 != NULL)
//    {
//      ppuVar2 = NULL;
//      while ((channel < *(uint16_t *)ppuVar1 || (*(uint16_t *)((int)ppuVar1 + 2) < cfg)))
//      {
//        ppuVar2 = (uint16_t **)((int)ppuVar2 + 1);
//        ppuVar1 = ppuVar1 + 3;
//        if (ppuVar2 == ppuVar3)
//        {
//          return NULL;
//        }
//      }
//      if (currentConfig != ppuVar1)
//      {
//        currentConfig = ppuVar1;
//        RAIL_RfHalSetChannelConfig(currentConfig);
//      }
//      return currentConfig;
//    }
//  }
  return ppuVar3;
}



void RAILInt_TrackChannelConfig(RAIL_ChannelConfig_t *config)

{
  //channelConfig = config;
}

void RAIL_VersionGet(RAIL_Version_t * version, bool verbose)

{
	version->hash = 0x0000FFFF; //dummy
	version->major = 5;
	version->minor = 0;
	version->rev = 0;
	version->build = 0;
	version->flags = 0;
}


/**
 * Configure the debug mode for the radio library. Do not use this function
 * unless instructed to by Silicon Labs.
 * @param debugMode The debug mode to enter
 * @return Whether this command ran successfully or not.
 */
RAIL_Status_t RAIL_DebugModeSet(uint32_t debugMode)

{
  if (RAIL_DebugMode == 1)
  {
    //currentConfig = 0;
  }
  RAIL_DebugMode = debugMode;
  return 0;
}



uint32_t RAIL_DebugModeGet(void)

{
  return RAIL_DebugMode;
}


/**
 * Configure RAIL automatic state transitions after TX
 *
 * @param[in] success The next radio state to enter after a successful packet
 * transmission.
 * @param[in] error The next radio state to enter after an error during packet
 * transmission.
 * @return Returns zero on success and an error code on error.
 *
 * This function fails if unsupported transitions are passed in, or if the
 * radio is currently the TX state. Success and error can each transition to RX
 * or IDLE.
 */
RAIL_Status_t RAIL_SetTxTransitions(RAIL_RadioState_t success, RAIL_RadioState_t error)

{
  RAIL_Status_t iVar2;
	RAIL_RadioState_t iVar1;
  
  if ((success == RAIL_RF_STATE_TX) || (error == RAIL_RF_STATE_TX))
  {
    iVar2 = 1; //RAIL_STATUS_INVALID_PARAMETER
  }
  else {
    iVar1 = RAIL_RfHalStateGet();
    if (iVar1 != RAIL_RF_STATE_TX) 
			{
      iVar2 = RAIL_RfHalSetTxTransitions(success,error);
      return iVar2;
			}
  }
  return iVar2;
}


/**
 * Configure RAIL automatic state transitions after RX
 *
 * @param[in] success The next radio state to enter after a successful packet
 * reception.
 * @param[in] error The next radio state to enter after an error during packet
 * reception.
 * @param[in] ignoreErrors Define errors during packet handling to be ignored
 * @return Returns zero on success and an error code on error.
 *
 * This function fails if unsupported transitions are passed in, or if the
 * radio is currently in the RX state. Success can transition to TX, RX, or
 * IDLE, while error can transition to RX or IDLE. The full list of options for
 * the ignoreErrors parameter is any define that starts with
 * \link RAIL_IGNORE_NO_ERRORS RAIL_IGNORE_\endlink.
 */
RAIL_Status_t RAIL_SetRxTransitions(RAIL_RadioState_t success,  RAIL_RadioState_t error,  uint8_t ignoreErrors)

{
  RAIL_Status_t iVar1;
  
  if (error == 2)
  {
    return 1;
  }
  //iVar1 = RAIL_RfHalStateGet();
  if (RAIL_RfHalStateGet() == 1)
  {
    iVar1 = 2;
  }
  else
  {
    iVar1 = RAIL_RfHalSetRxTransitions(success,error);
    if (iVar1 == 0) {
      iVar1 = RAIL_RfHalErrorConfig(ignoreErrors);
      return iVar1;
    }
  }
  return iVar1;
}


