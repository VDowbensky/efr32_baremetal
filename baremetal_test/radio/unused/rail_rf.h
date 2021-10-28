#ifndef _RAIL_RF_H_
#define _RAIL_RF_H_

#include "em_device.h"
#include <stdint.h>
#include <stdbool.h>
#include "rail_types.h"

uint8_t RAIL_RfInit(const RAIL_Init_t *railInit);
void RAIL_RfIdle(void);
RAIL_RadioState_t RAIL_RfStateGet(void);
RAIL_Status_t RAIL_ChannelExists(uint8_t channel);
void RAIL_VersionGet(RAIL_Version_t * version, bool verbose);
RAIL_Status_t RAIL_DebugModeSet(uint32_t debugMode);
uint32_t RAIL_DebugModeGet(void);
RAIL_Status_t RAIL_SetTxTransitions(RAIL_RadioState_t success, RAIL_RadioState_t error);
RAIL_Status_t RAIL_SetRxTransitions(RAIL_RadioState_t success,  RAIL_RadioState_t error,  uint8_t ignoreErrors);
void RAILInt_TrackChannelConfig(uint32_t config);

uint16_t ** RAILInt_SetChannelConfig(uint16_t cfg);

#endif

