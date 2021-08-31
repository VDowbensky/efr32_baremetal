#ifndef _RAIL_AUTOACK_H_
#define _RAIL_AUTOACK_H_

RAIL_Status_t RAIL_AutoAckDisable(void);
bool RAIL_AutoAckIsEnabled(void);
RAIL_Status_t RAIL_AutoAckConfig(RAIL_AutoAckConfig_t *config);
RAIL_Status_t RAIL_AutoAckLoadBuffer(RAIL_AutoAckData_t *ackData);
void RAIL_AutoAckRxPause(void);
void RAIL_AutoAckRxResume(void);
bool RAIL_AutoAckRxIsPaused(void);
void RAIL_AutoAckTxPause(void);
void RAIL_AutoAckTxResume(void);
bool RAIL_AutoAckTxIsPaused(void);
bool RAIL_AutoAckUseTxBuffer(void);
bool RAIL_AutoAckCancelAck(void);
bool RAIL_AutoAckWaitingForAck(void);

#endif