#include "rail_singleprotocol.h"



int RAILInt_GetActiveConfig(void)

{
  int iVar1;
  
  iVar1 = activeRailConfig;
  if (activeRailConfig != 0) iVar1 = 1;
  RAILInt_Assert(iVar1,0x26);
  return activeRailConfig;
}



//void RAIL_Init(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
RAIL_Handle_t RAIL_Init(RAIL_Config_t *railCfg,RAIL_InitCompleteCallbackPtr_t cb)
{
  activeRailConfig = param_1;
  RFHAL_SetCallbackConfig();
  return RAILCore_Init(param_1,param_2,param_3,param_4);
}


/* RAIL_ENUM(RAIL_SchedulerStatus_t) {
  RAIL_SCHEDULER_STATUS_NO_ERROR,
  RAIL_SCHEDULER_STATUS_UNSUPPORTED,
  RAIL_SCHEDULER_STATUS_EVENT_INTERRUPTED,
  RAIL_SCHEDULER_STATUS_SCHEDULE_FAIL,
  RAIL_SCHEDULER_STATUS_SCHEDULED_TX_FAIL,
  RAIL_SCHEDULER_STATUS_SINGLE_TX_FAIL,
  RAIL_SCHEDULER_STATUS_CCA_CSMA_TX_FAIL,
  RAIL_SCHEDULER_STATUS_CCA_LBT_TX_FAIL,
  RAIL_SCHEDULER_STATUS_SCHEDULED_RX_FAIL,
  RAIL_SCHEDULER_STATUS_TX_STREAM_FAIL,
  RAIL_SCHEDULER_STATUS_AVERAGE_RSSI_FAIL,
  RAIL_SCHEDULER_STATUS_INTERNAL_ERROR,
}; */
//undefined4 RAIL_GetSchedulerStatus(void)
RAIL_SchedulerStatus_t RAIL_GetSchedulerStatus(RAIL_Handle_t railHandle)
{
  return RAIL_SCHEDULER_STATUS_UNSUPPORTED;
}



//undefined4 RAIL_ConfigSleep(undefined4 param_1,int param_2)
RAIL_Status_t RAIL_ConfigSleep(RAIL_Handle_t railHandle,RAIL_SleepConfig_t sleepConfig)
{
  railSleepConfig = (undefined)sleepConfig;
  if (sleepConfig == 1) return RAILCore_InitTimerSync();
  return RAIL_STATUS_NO_ERROR;
}



//void RAIL_Wake(void)
RAIL_Status_t RAIL_Wake(uint32_t elapsedTime)
{
  return RAILCore_Wake();
}



//void RAIL_Sleep(undefined4 param_1,undefined4 param_2)
RAIL_Status_t RAIL_Sleep(uint16_t wakeupProcessTime, bool *deepSleepAllowed)
{
  return RAILCore_Sleep(railSleepConfig == '\x01',param_1,param_2);
}



//void RAIL_GetRadioState(void)
RAIL_RadioState_t RAIL_GetRadioState(RAIL_Handle_t railHandle)
{
  return RAILCore_GetRadioState();
}



//void RAIL_Idle(undefined4 param_1,undefined4 param_2,undefined4 param_3)
void RAIL_Idle(RAIL_Handle_t railHandle,
               RAIL_IdleMode_t mode,
               bool wait)
{
  RAILCore_Idle(mode,wait);
}



//void RAIL_YieldRadio(void)
void RAIL_YieldRadio(RAIL_Handle_t railHandle)
{
  return;
}



//void RAIL_StartRfSense(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
uint32_t RAIL_StartRfSense(RAIL_Handle_t railHandle,
                           RAIL_RfSenseBand_t band,
                           uint32_t senseTime,
                           RAIL_RfSense_CallbackPtr_t cb)
{
  return RAILCore_StartRfSense(band,senseTime,cb);
}



//void RAIL_IsRfSensed(void)
bool RAIL_IsRfSensed(RAIL_Handle_t railHandle)
{
  return RAILCore_IsRfSensed();
}



//void RAIL_GetRadioEntropy(undefined4 param_1,undefined4 param_2,undefined4 param_3)
uint16_t RAIL_GetRadioEntropy(RAIL_Handle_t railHandle,
                              uint8_t *buffer,
                              uint16_t bytes)
{
  return RAILCore_GetRadioEntropy(&buffer,bytes);
}



//void RAIL_SetTimer(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
RAIL_Status_t RAIL_SetTimer(RAIL_Handle_t railHandle,
                            uint32_t time,
                            RAIL_TimeMode_t mode,
                            RAIL_TimerCallback_t cb)
{
  return RFHAL_SetTimer(time,mode,cb,railHandle);
}



//void RAIL_GetTimer(void)
uint32_t RAIL_GetTimer(RAIL_Handle_t railHandle)
{
  return RFHAL_GetTimer();
}



//void RAIL_CancelTimer(void)
void RAIL_CancelTimer(RAIL_Handle_t railHandle)
{
  RFHAL_CancelTimer();
}



//void RAIL_IsTimerExpired(void)
bool RAIL_IsTimerExpired(RAIL_Handle_t railHandle)
{
  return RFHAL_IsTimerExpired();
}



//void RAIL_IsTimerRunning(void)
bool RAIL_IsTimerRunning(RAIL_Handle_t railHandle)
{
  return RFHAL_IsTimerRunning();
}



//void RAIL_StartTx(int param_1)
RAIL_Status_t RAIL_StartTx(RAIL_Handle_t railHandle,
                           uint16_t channel,
                           RAIL_TxOptions_t options,
                           const RAIL_SchedulerInfo_t *schedulerInfo)
{
  return RAILCore_StartTx(railHandle + 0xc,channel,options,&schedulerInfo);
}



//void RAIL_StartScheduledTx(int param_1)
RAIL_Status_t RAIL_StartScheduledTx(RAIL_Handle_t railHandle,
                                    uint16_t channel,
                                    RAIL_TxOptions_t options,
                                    const RAIL_ScheduleTxConfig_t *config,
                                    const RAIL_SchedulerInfo_t *schedulerInfo)
{
  return RAILCore_StartScheduledTx(railHandle + 0xc,channel,options,&config,&schedulerInfo);
}



//void RAIL_StartCcaCsmaTx(int param_1)
RAIL_Status_t RAIL_StartCcaCsmaTx(RAIL_Handle_t railHandle,
                                  uint16_t channel,
                                  RAIL_TxOptions_t options,
                                  const RAIL_CsmaConfig_t *csmaConfig,
                                  const RAIL_SchedulerInfo_t *schedulerInfo)
{
  return RAILCore_StartCcaCsmaTx(railHandle + 0xc,channel,options,&csmaConfig,&schedulerInfo);
}



//void RAIL_StartCcaLbtTx(int param_1)
RAIL_Status_t RAIL_StartCcaLbtTx(RAIL_Handle_t railHandle,
                                 uint16_t channel,
                                 RAIL_TxOptions_t options,
                                 const RAIL_LbtConfig_t *lbtConfig,
                                 const RAIL_SchedulerInfo_t *schedulerInfo)
{
  return RAILCore_StartCcaLbtTx(railHandle + 0xc,channel,&lbtConfig,&schedulerInfo);
}



//void RAIL_StartTxStream(int param_1)
RAIL_Status_t RAIL_StartTxStream(RAIL_Handle_t railHandle,
                                 uint16_t channel,
                                 RAIL_StreamMode_t mode)
{
  return RAILCore_StartTxStream(railHandle + 0xc,channel,mode);
}



//undefined4 RAIL_StopTxStream(void)
RAIL_Status_t RAIL_StopTxStream(RAIL_Handle_t railHandle)
{
  RFHAL_StopTestMode();
  return RAIL_STATUS_NO_ERROR;
}



//void RAIL_StartRx(int param_1)
RAIL_Status_t RAIL_StartRx(RAIL_Handle_t railHandle,
                           uint16_t channel,
                           const RAIL_SchedulerInfo_t *schedulerInfo)
{
  return RAILCore_StartRx(railHandle + 0xc,channel,&schedulerInfo);
}



//void RAIL_ScheduleRx(int param_1)
RAIL_Status_t RAIL_ScheduleRx(RAIL_Handle_t railHandle,
                              uint16_t channel,
                              const RAIL_ScheduleRxConfig_t *cfg,
                              const RAIL_SchedulerInfo_t *schedulerInfo)
{
  return RAILCore_ScheduleRx(railHandle + 0xc,channel,&cfg,&schedulerInfo);
}



//void RAIL_GetRssi(int param_1)
int16_t RAIL_GetRssi(RAIL_Handle_t railHandle, bool wait)
{
  return RAILCore_GetRssi(wait);
}



//void RAIL_StartAverageRssi(int param_1)
RAIL_Status_t RAIL_StartAverageRssi(RAIL_Handle_t railHandle,
                                    uint16_t channel,
                                    uint32_t averagingTimeUs,
                                    const RAIL_SchedulerInfo_t *schedulerInfo)
{
  return RAILCore_StartAverageRssi(railHandle,channel,averagingTimeUs,&schedulerInfo);
}



//undefined4 RAIL_EnableDirectMode(undefined4 param_1,undefined4 param_2)
RAIL_Status_t RAIL_EnableDirectMode(RAIL_Handle_t railHandle,
                                    bool enable)
{
  RAILCore_EnableDirectMode(enable);
  return RAIL_STATUS_NO_ERROR;
}



//void RAIL_OverrideDebugFrequency(undefined4 param_1,undefined4 param_2)
RAIL_Status_t RAIL_OverrideDebugFrequency(RAIL_Handle_t railHandle,
                                          uint32_t freq)
{
  return RAILCore_OverrideDebugFrequency(freq);
}


