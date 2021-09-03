#ifndef _RAIL_RFHAL_H_
#define _RAIL_RFHAL_H_

void pktTxDoneEvt(undefined4 param_1,undefined4 param_2,undefined4 param_3);
void pktRxFrmErr(void);
void pktRxOverflow(void);
void filterPass(void);
void pktRxAborted(void);
void preambleDetected(void);
void frameDet0(void);
void frameDet1(void);void rxFifoUnderflow(void);
void RAIL_RFSENSE_Callback(void);
void protmrRetry(void);
void protmrStartCca(void);
void txFifoOverflow(void);
void racStateChange(void);
void softwareTimerExpired(void);
void rxFifoAlmostFull(void);
void txFifoAlmostEmpty(void);
void racCalRequest(void);
void pktRxDoneEvt(void);

void rxTimeout(int param_1);
void sequencerInterrupt(int param_1);
void rssiAverageDone(void);
bool userTransmitStarted(void);
void pktTxErrorEvt(uint param_1);
void protmrLbtEvt(int param_1);
uint8_t RFHAL_Init(int param_1);

RAIL_Status_t RFHAL_SetPtiProtocol(RAIL_PtiProtocol_t protocol);
void RFHAL_IdleExt(RAIL_RfIdleMode_t mode);
RAIL_RadioState_t RFHAL_StateGet(void);
bool RFHAL_OkToTransmit(void);
int RFHAL_HeadedToIdle(void);
uint8_t RFHAL_TxDataLoad(RAIL_TxData_t *txData);
uint8_t RAIL_CcaCsma(void *params);
uint8_t RAIL_CcaLbt(void *params);
void RFHAL_SetCcaThreshold(void);
int16_t RFHAL_PollAverageRSSI(int32_t time);

int RFHAL_StartAverageRSSI(undefined4 param_1,undefined4 param_2);

int16_t RFHAL_GetAverageRSSI(void);
uint8_t RFHAL_ScheduleRx(uint8_t channel, RAIL_ScheduleRxConfig_t *cfg);

void RAIL_ScheduleTx(undefined4 *param_1);

uint8_t RFHAL_RxStart(uint8_t channel);

undefined4 RFHAL_EnableRxRawCapture(int param_1,uint param_2);

void RFHAL_DisableRxRawCapture(void);
void RFHAL_EnableRxAppendedInfo(void);
void RFHAL_DisableRxAppendedInfo(void);
uint32_t RFHAL_RxIntEnable(uint32_t cbToEnable);
RAIL_Status_t RFHAL_SetRxOptions(uint32_t options);
uint32_t RFHAL_TxIntEnable(uint32_t cbToEnable);
RAIL_Status_t RFHAL_ErrorConfig(uint8_t ignoreErrors);
RAIL_Status_t RAIL_PaCtuneSet(uint8_t txPaCtuneValue, uint8_t rxPaCtuneValue);
uint32_t RAIL_TimerGet(void);
void RAIL_TimerCancel(void);
RAIL_Status_t RAIL_TimerSet(uint32_t time, RAIL_TimeMode_t mode);
bool RAIL_TimerExpired(void);
bool RAIL_TimerIsRunning(void);
uint32_t RAIL_SymbolRateGet(void);
uint32_t RAIL_BitRateGet(void);
uint32_t RAIL_RfSense(RAIL_RfSenseBand_t band, uint32_t senseTime, bool enableCb);
bool RAIL_RfSensed(void);
void RAIL_DebugCbConfig(uint32_t cbToEnable);

void RFHAL_CalibrationInit(int param_1);
void RFHAL_CalibrationRun(int *param_1,int param_2);

RAIL_Status_t RFHAL_SetTxTransitions(RAIL_RadioState_t success,RAIL_RadioState_t error);
RAIL_Status_t RFHAL_SetRxTransitions(RAIL_RadioState_t success,RAIL_RadioState_t error);
void RFHAL_SetBerConfig(RAIL_BerConfig_t *berConfig);
void RFHAL_StartBerRx(void);
void RFHAL_StopBerRx(void);
void RFHAL_GetBerStatus(RAIL_BerStatus_t *status);
void RFHAL_SetCRCInitVal(uint16_t val);
int32_t RFHAL_GetCurrPowerLevel(void);
int32_t RFHAL_SetCurrPowerLevel(int32_t powerLevel);
void RFHAL_SetProtocolSpecificChCheckCB(uint32_t cb);
void RFHAL_StopTestMode(void);
void RFHAL_StartCWTestMode(void);
void RFHAL_StartStreamTestMode(void);

uint32_t RFHAL_SetChannel(int param_1,uint8_t *cfg,int param_3);

bool RFHAL_AutoAckEnable(void);
bool RFHAL_AutoAckDisable(void);
bool RFHAL_AutoAckIsEnabled(void);
void RFHAL_AutoAckConfig(RAIL_AutoAckConfig_t *config);
RAIL_Status_t RFHAL_AutoAckLoadBuffer(RAIL_AutoAckData_t *ackData);
void RFHAL_AutoAckRxPause(void);
void RFHAL_AutoAckRxResume(void);
void RFHAL_AutoAckTxPause(void);
void RFHAL_AutoAckTxResume(void);
bool RFHAL_AutoAckRxIsPaused(void);
bool RFHAL_AutoAckTxIsPaused(void);
bool RFHAL_AutoAckUseTxBuffer(void);
bool RFHAL_AutoAckCancelAck(void);
void RFHAL_AutoAckWaitForAck(int enable);
uint8_t RFHAL_TxStart(uint8_t channel,RAIL_TxOptions_t *options,code void *preTxOpParams,RAIL_PreTxOp_t preTxOp);
bool RFHAL_AutoAckWaitingForAck(void);
uint16_t RFHAL_WriteTxFifo(uint8_t *dataPtr, uint16_t writeLength);
uint16_t RFHAL_ReadRxFifo(uint8_t *dataPtr, uint16_t readLength);
void RFHAL_ReadRxFifoAppendedInfo(RAIL_AppendedInfo_t *appendedInfo);
uint16_t RFHAL_SetRxFifoThreshold(uint16_t rxThreshold);
uint16_t RFHAL_GetTxFifoThreshold(void);
uint16_t RFHAL_SetTxFifoThreshold(uint16_t txThreshold);
uint16_t RFHAL_GetRxFifoThreshold(void);
void RFHAL_EnableRxFifoThreshold(void);
void RFHAL_DisableRxFifoThreshold(void);
uint16_t RFHAL_GetTxFifoSpaceAvailable(void);
uint16_t RFHAL_GetRxFifoBytesAvailable(void);
void RFHAL_ResetTxFifo(void);
void RFHAL_ResetRxFifo(void);
RAIL_Status_t RFHAL_DataConfig(RAIL_DataConfig_t *dataConfig);
uint16_t RFHAL_SetFixedLength(uint16_t length);

#endif