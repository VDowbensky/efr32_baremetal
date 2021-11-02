#ifndef _RAIL_RFHAL_H_
#define _RAIL_RFHAL_H_

#include "em_device.h"
#include <stdint.h>
#include <stdbool.h>
#include "rail_types.h"

void pktTxDoneEvt(uint32_t param_1,RAIL_TxPacketInfo_t param_2,uint32_t param_3);
void pktRxOverflow(void);
void preambleDetected(void);
void frameDet0(void);
void sequencerInterrupt(int param_1);
void RAIL_RFSENSE_Callback(void);
void pktTxErrorEvt(void);
void racStateChange(void);
void softwareTimerExpired(void);
void racCalRequest(void);
void protmrLbtEvt(int param_1);
void pktRxDoneEvt(void);
void pktRxFrmErr(void);
uint8_t RAIL_RfHalInit(const RAIL_Init_t *railInit);
void RAIL_RfHalIdleStart(void);

uint32_t RFHAL_HeadedToIdle(void);
uint8_t RAIL_RfHalTxDataLoad(RAIL_TxData_t *txData);
uint8_t RAIL_CcaCsma(void *params);
uint8_t RAIL_CcaLbt(void *params);
uint8_t RAIL_ScheduleTx(void *params);
uint8_t RAIL_RfHalTxStart(uint8_t channel, RAIL_PreTxOp_t preTxOp, void *preTxOpParams);
uint8_t RAIL_RfHalRxStart(uint8_t channel);
uint8_t RAIL_RfHalRxIntEnable(uint8_t cbToEn);
RAIL_Status_t RAIL_RfHalErrorConfig(RAIL_RadioState_t errors);
uint32_t RAIL_RfHalSetChannelConfig(int param_1);
RAIL_Status_t RAIL_PaCtuneSet(uint8_t txPaCtuneValue, uint8_t rxPaCtuneValue);
RAIL_Status_t RAIL_TimerSet(uint32_t time, RAIL_TimeMode_t mode);
uint32_t RAIL_TimerGet(void);
void RAIL_TimerCancel(void);
bool RAIL_TimerExpired(void);
bool RAIL_TimerIsRunning(void);
uint32_t RAIL_SymbolRateGet(void);
uint32_t RAIL_BitRateGet(void);
uint32_t RAIL_RfSense(RAIL_RfSenseBand_t band, uint32_t senseTime, bool enableCb);
bool RAIL_RfSensed(void);
void RAIL_DebugCbConfig(uint32_t cbToEnable);
void RAIL_RfHalCalibrationRun(int *param_1,int param_2);
RAIL_Status_t RAIL_RfHalSetTxTransitions(RAIL_RadioState_t success,RAIL_RadioState_t error);
RAIL_Status_t RAIL_RfHalSetRxTransitions(RAIL_RadioState_t success,RAIL_RadioState_t error);
void RFHAL_SetBerConfig(RAIL_BerConfig_t *config);
void RFHAL_StartBerRx(void);
void RFHAL_StopBerRx(void);
void RFHAL_GetBerStatus (RAIL_BerStatus_t *status);

RAIL_RadioState_t RAIL_RfHalStateGet(void);

void PHY_UTILS_DelayUs(uint32_t us);


#endif

