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



void RAIL_Init(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  activeRailConfig = param_1;
  RFHAL_SetCallbackConfig();
  RAILCore_Init(param_1,param_2,param_3,param_4);
  return;
}



undefined4 RAIL_GetSchedulerStatus(void)

{
  return 1;
}



undefined4 RAIL_ConfigSleep(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  railSleepConfig = (undefined)param_2;
  if (param_2 == 1) {
    uVar1 = RAILCore_InitTimerSync();
    return uVar1;
  }
  return 0;
}



void RAIL_Wake(void)

{
  RAILCore_Wake();
  return;
}



void RAIL_Sleep(undefined4 param_1,undefined4 param_2)

{
  RAILCore_Sleep(railSleepConfig == '\x01',param_1,param_2);
  return;
}



void RAIL_GetRadioState(void)

{
  RAILCore_GetRadioState();
  return;
}



void RAIL_Idle(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  RAILCore_Idle(param_2,param_3);
  return;
}



void RAIL_YieldRadio(void)

{
  return;
}



void RAIL_StartRfSense(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  RAILCore_StartRfSense(param_2,param_3,param_4);
  return;
}



void RAIL_IsRfSensed(void)

{
  RAILCore_IsRfSensed();
  return;
}



void RAIL_GetRadioEntropy(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  RAILCore_GetRadioEntropy(param_2,param_3);
  return;
}



void RAIL_SetTimer(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  RFHAL_SetTimer(param_2,param_3,param_4,param_1);
  return;
}



void RAIL_GetTimer(void)

{
  RFHAL_GetTimer();
  return;
}



void RAIL_CancelTimer(void)

{
  RFHAL_CancelTimer();
  return;
}



void RAIL_IsTimerExpired(void)

{
  RFHAL_IsTimerExpired();
  return;
}



void RAIL_IsTimerRunning(void)

{
  RFHAL_IsTimerRunning();
  return;
}



void RAIL_StartTx(int param_1)

{
  RAILCore_StartTx(param_1 + 0xc);
  return;
}



void RAIL_StartScheduledTx(int param_1)

{
  RAILCore_StartScheduledTx(param_1 + 0xc);
  return;
}



void RAIL_StartCcaCsmaTx(int param_1)

{
  RAILCore_StartCcaCsmaTx(param_1 + 0xc);
  return;
}



void RAIL_StartCcaLbtTx(int param_1)

{
  RAILCore_StartCcaLbtTx(param_1 + 0xc);
  return;
}



void RAIL_StartTxStream(int param_1)

{
  RAILCore_StartTxStream(param_1 + 0xc);
  return;
}



undefined4 RAIL_StopTxStream(void)

{
  RFHAL_StopTestMode();
  return 0;
}



void RAIL_StartRx(int param_1)

{
  RAILCore_StartRx(param_1 + 0xc);
  return;
}



void RAIL_ScheduleRx(int param_1)

{
  RAILCore_ScheduleRx(param_1 + 0xc);
  return;
}



void RAIL_GetRssi(int param_1)

{
  RAILCore_GetRssi(param_1 + 0xc);
  return;
}



void RAIL_StartAverageRssi(int param_1)

{
  RAILCore_StartAverageRssi(param_1 + 0xc);
  return;
}



undefined4 RAIL_EnableDirectMode(undefined4 param_1,undefined4 param_2)

{
  RAILCore_EnableDirectMode(param_2);
  return 0;
}



void RAIL_OverrideDebugFrequency(undefined4 param_1,undefined4 param_2)

{
  RAILCore_OverrideDebugFrequency(param_2);
  return;
}


