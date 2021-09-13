#include "rail_singleprotocol.h"



int RAILInt_GetActiveConfig(void)

{
  int iVar1;
  
  iVar1 = activeRailConfig;
  if (activeRailConfig != 0) {
    iVar1 = 1;
  }
  RAILInt_Assert(iVar1,0x26);
  return activeRailConfig;
}



//void RAIL_Init(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
RAIL_Handle_t RAIL_Init(RAIL_Config_t *railCfg,
                        RAIL_InitCompleteCallbackPtr_t cb)
{
  activeRailConfig = param_1;
  RFHAL_SetCallbackConfig();
  RAILCore_Init(param_1,param_2,param_3,param_4);
  return;
}



//undefined4 RAIL_GetSchedulerStatus(void)
RAIL_SchedulerStatus_t RAIL_GetSchedulerStatus(RAIL_Handle_t railHandle)
{
  return 1;
}



//undefined4 RAIL_ConfigSleep(undefined4 param_1,int param_2)
RAIL_Status_t RAIL_ConfigSleep(RAIL_Handle_t railHandle,
                               RAIL_SleepConfig_t sleepConfig)
{
  undefined4 uVar1;
  
  railSleepConfig = (undefined)param_2;
  if (param_2 == 1) {
    uVar1 = RAILCore_InitTimerSync();
    return uVar1;
  }
  return 0;
}



//void RAIL_Wake(void)
RAIL_Status_t RAIL_Wake(uint32_t elapsedTime)
{
  RAILCore_Wake();
  return;
}



//void RAIL_Sleep(undefined4 param_1,undefined4 param_2)
RAIL_Status_t RAIL_Sleep(uint16_t wakeupProcessTime, bool *deepSleepAllowed)
{
  RAILCore_Sleep(railSleepConfig == '\x01',param_1,param_2);
  return;
}



//void RAIL_GetRadioState(void)
RAIL_RadioState_t RAIL_GetRadioState(RAIL_Handle_t railHandle)
{
  RAILCore_GetRadioState();
  return;
}



//void RAIL_Idle(undefined4 param_1,undefined4 param_2,undefined4 param_3)
void RAIL_Idle(RAIL_Handle_t railHandle,
               RAIL_IdleMode_t mode,
               bool wait)
{
  RAILCore_Idle(param_2,param_3);
  return;
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
  RAILCore_StartRfSense(param_2,param_3,param_4);
  return;
}



//void RAIL_IsRfSensed(void)
bool RAIL_IsRfSensed(RAIL_Handle_t railHandle)
{
  RAILCore_IsRfSensed();
  return;
}



//void RAIL_GetRadioEntropy(undefined4 param_1,undefined4 param_2,undefined4 param_3)
uint16_t RAIL_GetRadioEntropy(RAIL_Handle_t railHandle,
                              uint8_t *buffer,
                              uint16_t bytes)
{
  RAILCore_GetRadioEntropy(param_2,param_3);
  return;
}



//void RAIL_SetTimer(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
RAIL_Status_t RAIL_SetTimer(RAIL_Handle_t railHandle,
                            uint32_t time,
                            RAIL_TimeMode_t mode,
                            RAIL_TimerCallback_t cb)
{
  RFHAL_SetTimer(param_2,param_3,param_4,param_1);
  return;
}



//void RAIL_GetTimer(void)
uint32_t RAIL_GetTimer(RAIL_Handle_t railHandle)
{
  RFHAL_GetTimer();
  return;
}



//void RAIL_CancelTimer(void)
void RAIL_CancelTimer(RAIL_Handle_t railHandle)
{
  RFHAL_CancelTimer();
  return;
}



//void RAIL_IsTimerExpired(void)
bool RAIL_IsTimerExpired(RAIL_Handle_t railHandle)
{
  RFHAL_IsTimerExpired();
  return;
}



//void RAIL_IsTimerRunning(void)
bool RAIL_IsTimerRunning(RAIL_Handle_t railHandle)
{
  RFHAL_IsTimerRunning();
  return;
}



//void RAIL_StartTx(int param_1)
RAIL_Status_t RAIL_StartTx(RAIL_Handle_t railHandle,
                           uint16_t channel,
                           RAIL_TxOptions_t options,
                           const RAIL_SchedulerInfo_t *schedulerInfo)
{
  RAILCore_StartTx(param_1 + 0xc);
  return;
}



//void RAIL_StartScheduledTx(int param_1)
RAIL_Status_t RAIL_StartScheduledTx(RAIL_Handle_t railHandle,
                                    uint16_t channel,
                                    RAIL_TxOptions_t options,
                                    const RAIL_ScheduleTxConfig_t *config,
                                    const RAIL_SchedulerInfo_t *schedulerInfo)
{
  RAILCore_StartScheduledTx(param_1 + 0xc);
  return;
}



//void RAIL_StartCcaCsmaTx(int param_1)
RAIL_Status_t RAIL_StartCcaCsmaTx(RAIL_Handle_t railHandle,
                                  uint16_t channel,
                                  RAIL_TxOptions_t options,
                                  const RAIL_CsmaConfig_t *csmaConfig,
                                  const RAIL_SchedulerInfo_t *schedulerInfo)
{
  RAILCore_StartCcaCsmaTx(param_1 + 0xc);
  return;
}



//void RAIL_StartCcaLbtTx(int param_1)
RAIL_Status_t RAIL_StartCcaLbtTx(RAIL_Handle_t railHandle,
                                 uint16_t channel,
                                 RAIL_TxOptions_t options,
                                 const RAIL_LbtConfig_t *lbtConfig,
                                 const RAIL_SchedulerInfo_t *schedulerInfo)
{
  RAILCore_StartCcaLbtTx(param_1 + 0xc);
  return;
}



//void RAIL_StartTxStream(int param_1)
RAIL_Status_t RAIL_StartTxStream(RAIL_Handle_t railHandle,
                                 uint16_t channel,
                                 RAIL_StreamMode_t mode)
{
  RAILCore_StartTxStream(param_1 + 0xc);
  return;
}



//undefined4 RAIL_StopTxStream(void)
RAIL_Status_t RAIL_StopTxStream(RAIL_Handle_t railHandle)
{
  RFHAL_StopTestMode();
  return 0;
}



//void RAIL_StartRx(int param_1)
RAIL_Status_t RAIL_StartRx(RAIL_Handle_t railHandle,
                           uint16_t channel,
                           const RAIL_SchedulerInfo_t *schedulerInfo)
{
  RAILCore_StartRx(param_1 + 0xc);
  return;
}



//void RAIL_ScheduleRx(int param_1)
RAIL_Status_t RAIL_ScheduleRx(RAIL_Handle_t railHandle,
                              uint16_t channel,
                              const RAIL_ScheduleRxConfig_t *cfg,
                              const RAIL_SchedulerInfo_t *schedulerInfo)
{
  RAILCore_ScheduleRx(param_1 + 0xc);
  return;
}



//void RAIL_GetRssi(int param_1)
int16_t RAIL_GetRssi(RAIL_Handle_t railHandle, bool wait)
{
  RAILCore_GetRssi(param_1 + 0xc);
  return;
}



//void RAIL_StartAverageRssi(int param_1)
RAIL_Status_t RAIL_StartAverageRssi(RAIL_Handle_t railHandle,
                                    uint16_t channel,
                                    uint32_t averagingTimeUs,
                                    const RAIL_SchedulerInfo_t *schedulerInfo)
{
  RAILCore_StartAverageRssi(param_1 + 0xc);
  return;
}



//undefined4 RAIL_EnableDirectMode(undefined4 param_1,undefined4 param_2)
RAIL_Status_t RAIL_EnableDirectMode(RAIL_Handle_t railHandle,
                                    bool enable)
{
  RAILCore_EnableDirectMode(param_2);
  return 0;
}



//void RAIL_OverrideDebugFrequency(undefined4 param_1,undefined4 param_2)
RAIL_Status_t RAIL_OverrideDebugFrequency(RAIL_Handle_t railHandle,
                                          uint32_t freq)
{
  RAILCore_OverrideDebugFrequency(param_2);
  return;
}


