#ifndef _RAIL_RF_H_
#define _RAIL_RF_H_

uint8_t RAIL_RfInit(const RAIL_Init_t *railInit);
RAIL_Status_t RAIL_SetPtiProtocol(RAIL_PtiProtocol_t protocol);
void RAIL_RfIdle(void);
void RAIL_RfIdleExt(RAIL_RfIdleMode_t mode,bool wait);
RAIL_RadioState_t RAIL_RfStateGet(void);
RAIL_Status_t RAIL_ChannelExists(uint8_t channel);
void RAIL_VersionGet(RAIL_Version_t * version, bool verbose);
RAIL_Status_t RAIL_DebugModeSet(uint32_t debugMode);
uint32_t RAIL_DebugModeGet(void);
RAIL_Status_t RAIL_SetTxTransitions(RAIL_RadioState_t success,RAIL_RadioState_t error);
RAIL_Status_t RAIL_SetRxTransitions(RAIL_RadioState_t success,RAIL_RadioState_t error,uint8_t ignoreErrors);
uint16_t RAIL_SetFixedLength(uint16_t length)

#endif

