#include "rail_calibration.h"



void RAILINT_CalibrationEnable(RAIL_CalMask_t cbtoenable)

{
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  RAIL_CalPend = 0;
  RAIL_CalEnable = cbtoenable;
  CORE_ExitCritical(irqState);
}


void RAILINT_CalibrationPend(RAIL_CalMask_t calpend)

{
  CORE_irqState_t irqState;
  RAIL_CalMask_t cal;
  
  irqState = CORE_EnterCritical();
  cal = calpend & RAIL_CalEnable;
  RAIL_CalPend = RAIL_CalPend | cal;
  CORE_ExitCritical(irqState);
  if (cal != 0) RAILCb_CalNeeded();
}



RAIL_CalMask_t RAILINT_CalibrationClear(RAIL_CalMask_t caltoclear)

{
  CORE_irqState_t irqState;
  RAIL_CalMask_t cal;
  
  irqState = CORE_EnterCritical();
  cal = RAIL_CalPend & ~(caltoclear & RAIL_CalEnable);
  RAIL_CalPend = cal;
  CORE_ExitCritical(irqState);
  return cal;
}



RAIL_CalMask_t RAILINT_CalibrationEnableGet(void)

{
  return RAIL_CalEnable;
}



RAIL_CalMask_t RAIL_CalPendingGet(void)

{
  RAIL_CalMask_t cal;
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  cal = RAIL_CalPend;
  CORE_ExitCritical(irqState);
  return cal;
}



void RAIL_CalStart(RAIL_CalValues_t *calValues,RAIL_CalMask_t calForce,RAIL_CalMask_t calSave)

{
  int local_14;
  
  if (calValues == (undefined4 *)0x0) local_14 = -1;
  else local_14 = *calValues;
  if (calForce == 0) calForce = RAIL_CalPendingGet();
  RAILINT_CalibrationClear(calForce);
  RFHAL_CalibrationRun(&local_14,calForce);
  if ((calSave != 0) && (calValues != (undefined4 *)0x0)) *calValues = local_14;
}



uint8_t RAIL_CalInit(RAIL_CalInit_t *railCalInit)

{
  uint8_t res;
  
  res = RFHAL_CalibrationInit(railCalInit);
  RAILINT_CalibrationEnable(railCalInit->calEnable & 0x10001);
  return res;
}


