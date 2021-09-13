#include "rail_calibration.h"



void RAILInt_EnableCal(int param_1,undefined4 param_2)

{
  CORE_EnterCritical();
  *(undefined4 *)(param_1 + 0xc) = param_2;
  *(undefined4 *)(param_1 + 8) = 0;
  CORE_ExitCritical();
  return;
}



undefined8 RAILInt_PendCal(int param_1,uint param_2)

{
  CORE_EnterCritical();
  param_2 = param_2 & *(uint *)(param_1 + 0xc);
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | param_2;
  CORE_ExitCritical();
  if (param_2 == 0) {
    return 0;
  }
  return 0x200000000;
}



uint RAILInt_ClearCal(int param_1,uint param_2)

{
  uint uVar1;
  
  CORE_EnterCritical();
  uVar1 = *(uint *)(param_1 + 8) & ~(param_2 & *(uint *)(param_1 + 0xc));
  *(uint *)(param_1 + 8) = uVar1;
  CORE_ExitCritical();
  return uVar1;
}



undefined4 RAILInt_GetEnabledCal(int param_1)

{
  return *(undefined4 *)(param_1 + 0xc);
}



//undefined4 RAIL_GetPendingCal(int param_1)
RAIL_CalMask_t RAIL_GetPendingCal(RAIL_Handle_t railHandle)
{
  return *(undefined4 *)(param_1 + 0x14);
}



void RAILCore_Calibrate(int param_1,undefined4 *param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 local_14;
  
  if (param_2 == (undefined4 *)0x0) {
    local_14 = 0xffffffff;
    if (param_3 != 0) {
      RAILInt_ClearCal(param_1,param_3,param_3,0xffffffff,param_1);
      RFHAL_RunCal(param_1,&local_14,param_3);
      return;
    }
  }
  else {
    local_14 = *param_2;
    if (param_3 != 0) {
      RAILInt_ClearCal(param_1,param_3,param_3,local_14,param_1);
      RFHAL_RunCal(param_1,&local_14,param_3);
      goto LAB_000100a4;
    }
  }
  uVar1 = *(undefined4 *)(param_1 + 8);
  RAILInt_ClearCal(param_1,uVar1,param_3,local_14,param_1);
  RFHAL_RunCal(param_1,&local_14,uVar1);
  if (param_2 == (undefined4 *)0x0) {
    return;
  }
LAB_000100a4:
  *param_2 = local_14;
  return;
}



//undefined4 RAIL_Calibrate(int param_1)
RAIL_Status_t RAIL_Calibrate(RAIL_Handle_t railHandle,
                             RAIL_CalValues_t *calValues,
                             RAIL_CalMask_t calForce)
{
  RAILCore_Calibrate(param_1 + 0xc);
  return 0;
}



//undefined4 RAIL_ConfigCal(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)
RAIL_Status_t RAIL_ConfigCal(RAIL_Handle_t railHandle,
                             RAIL_CalMask_t calEnable)
{
  RAILInt_EnableCal(param_1 + 0xc,param_2 & 0x10001,param_3,param_4,param_4);
  return 0;
}



//void RAIL_SetTune(int param_1)
RAIL_Status_t RAIL_SetTune(RAIL_Handle_t railHandle, uint32_t tune)
{
  RFHAL_SetTune(param_1 + 0xc);
  return;
}



//void RAIL_GetTune(int param_1)
uint32_t RAIL_GetTune(RAIL_Handle_t railHandle)
{
  RFHAL_GetTune(param_1 + 0xc);
  return;
}



//void RAIL_SetPaCTune(int param_1)
RAIL_Status_t RAIL_SetPaCTune(RAIL_Handle_t railHandle,
                              uint8_t txPaCtuneValue,
                              uint8_t rxPaCtuneValue)
{
  RFHAL_SetPaCTune(param_1 + 0xc);
  return;
}


