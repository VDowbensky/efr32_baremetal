#include "rail_calibration.h"



void RAILINT_CalibrationEnable(undefined4 param_1)

{
  CORE_EnterCritical();
  RAIL_CalPend = 0;
  RAIL_CalEnable = param_1;
  CORE_ExitCritical();
  return;
}



void RAILINT_CalibrationPend(uint param_1)

{
  CORE_EnterCritical();
  param_1 = param_1 & RAIL_CalEnable;
  RAIL_CalPend = RAIL_CalPend | param_1;
  CORE_ExitCritical();
  if (param_1 != 0) {
    RAILCb_CalNeeded();
    return;
  }
  return;
}



uint RAILINT_CalibrationClear(uint param_1)

{
  uint uVar1;
  
  CORE_EnterCritical();
  uVar1 = RAIL_CalPend & ~(param_1 & RAIL_CalEnable);
  RAIL_CalPend = uVar1;
  CORE_ExitCritical();
  return uVar1;
}



undefined4 RAILINT_CalibrationEnableGet(void)

{
  return RAIL_CalEnable;
}



undefined4 RAIL_CalPendingGet(void)

{
  undefined4 uVar1;
  
  CORE_EnterCritical();
  uVar1 = RAIL_CalPend;
  CORE_ExitCritical();
  return uVar1;
}



void RAIL_CalStart(undefined4 *param_1,int param_2,int param_3)

{
  undefined4 local_14;
  
  if (param_1 == (undefined4 *)0x0) {
    local_14 = 0xffffffff;
  }
  else {
    local_14 = *param_1;
  }
  if (param_2 == 0) {
    param_2 = RAIL_CalPendingGet();
  }
  RAILINT_CalibrationClear(param_2);
  RFHAL_CalibrationRun(&local_14,param_2);
  if ((param_3 != 0) && (param_1 != (undefined4 *)0x0)) {
    *param_1 = local_14;
  }
  return;
}



undefined4 RAIL_CalInit(uint *param_1)

{
  undefined4 uVar1;
  
  uVar1 = RFHAL_CalibrationInit();
  RAILINT_CalibrationEnable(*param_1 & 0x10001);
  return uVar1;
}


