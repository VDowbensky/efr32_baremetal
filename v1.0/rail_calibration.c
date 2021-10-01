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



RAIL_CalMask_t RAIL_CalPendingGet(void)

{
  RAIL_CalMask_t RVar1;
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  RVar1 = RAIL_CalPend;
  CORE_ExitCritical(irqState);
  return RVar1;
}




void RAIL_CalStart(RAIL_CalValues_t *calValues,RAIL_CalMask_t calForce,bool calSave)

{
  undefined4 local_14;
  
  if (calValues == (undefined4 *)0x0) {
    local_14 = 0xffffffff;
  }
  else {
    local_14 = *calValues;
  }
  if (calForce == 0) {
    calForce = RFHAL_CalibrationPendingGet();
  }
  RFHAL_CalibrationClear(calForce);
  RFHAL_CalibrationRun(&local_14,calForce);
  if ((calSave != false) && (calValues != (undefined4 *)0x0)) {
    *calValues = local_14;
  }
  return;
}



uint8_t RAIL_CalInit(RAIL_CalInit_t *railCalInit)

{
  RAIL_Status_t RVar1;
  
  RVar1 = IRCAL_Init(railCalInit->irCalSettings);
  RFHAL_CalibrationInit(railCalInit->calEnable & 0x10001);
  return (uint8_t)RVar1;
}

