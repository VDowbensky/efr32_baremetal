#include "rail_calibration.h"

RAIL_CalMask_t RAIL_CalPend;
RAIL_CalMask_t RAIL_CalEnable;

void RAILINT_CalibrationEnable(RAIL_CalMask_t cal)

{
  uint32_t q;
  
  q = CORE_EnterCritical();
  RAIL_CalPend = 0;
  RAIL_CalEnable = cal;
  CORE_ExitCritical(q);
}



void RAILINT_CalibrationPend(RAIL_CalMask_t cal)

{
  CORE_EnterCritical();
  cal = &= RAIL_CalEnable;
  RAIL_CalPend = RAIL_CalPend | cal;
  CORE_ExitCritical();
  if (cal != 0) RAILCb_CalNeeded();
}



RAIL_CalMask_t RAILINT_CalibrationClear(RAIL_CalMask_t cal)

{
  RAIL_CalMask_t tmp;
  uint32_t q;
  
  q = CORE_EnterCritical();
  tmp = RAIL_CalPend & ~(cal & RAIL_CalEnable);
  RAIL_CalPend = tmp;
  CORE_ExitCritical(q);
  return tmp;
}



RAIL_CalMask_t RAILINT_CalibrationEnableGet(void)

{
  return RAIL_CalEnable;
}



RAIL_CalMask_t RAIL_CalPendingGet(void)

{
  RAIL_CalMask_t tmp;
  uint32_t q;
  
  q = CORE_EnterCritical();
  tmp = RAIL_CalPend;
  CORE_ExitCritical(q);
  return tmp;
}



//void RAIL_CalStart(undefined4 *calValues,int calForce,bool calSave)
void RAIL_CalStart(RAIL_CalValues_t *calValues, RAIL_CalMask_t calForce, bool calSave);
{
  undefined4 local_14;
  
  if (calValues == (undefined4 *)0x0) local_14 = 0xffffffff;
  else local_14 = *calValues;
  if (calForce == 0) calForce = RAIL_CalPendingGet();
  RAILINT_CalibrationClear(calForce);
  RFHAL_CalibrationRun(&local_14,calForce);
  if ((calSave != false) && (calValues != (undefined4 *)0x0)) *calValues = local_14;
}



uint8_t RAIL_CalInit(const RAIL_CalInit_t *railCalInit)

{
  uint8_t tmp;
  
  tmp = RFHAL_CalibrationInit();
  RAILINT_CalibrationEnable(*railCalInit & 0x10001);
  return tmp;
}


