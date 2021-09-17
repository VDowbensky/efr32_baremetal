#include "rail_calibration.h"




void RAIL_RfHalCalibrationInit(RAIL_CalMask_t calenable)

{
  INT_Disable();
  RAIL_CalPend = 0;
  RAIL_CalEnable = calenable;
  INT_Enable();
}



void RAIL_RfHalCalibrationSet(RAIL_CalMask_t cal)

{
  INT_Disable();
  cal = cal & RAIL_CalEnable;
  RAIL_CalPend = cal;
  INT_Enable();
  if (cal != 0) RAILCb_CalNeeded();
}



void RAIL_RfHalCalibrationPend(RAIL_CalMask_t cal)

{
  INT_Disable();
  RAIL_CalPend |= cal & RAIL_CalEnable;
  INT_Enable();
  if (cal & RAIL_CalEnable != 0) RAILCb_CalNeeded();
}



uint8_t RAIL_RfHalCalibrationClear(bool calforce)

{
  uint8_t tmp;
  
  INT_Disable();
  tmp = RAIL_CalPend & ~(calforce & RAIL_CalEnable);
  RAIL_CalPend = tmp;
  INT_Enable();
  return tmp;
}



RAIL_CalMask_t RAIL_RfHalCalibrationEnableGet(void)

{
  return RAIL_CalEnable;
}



RAIL_CalMask_t RAIL_RfHalCalibrationPendingGet(void)

{
  RAIL_CalMask_t tmp;
  
  INT_Disable();
  tmp = RAIL_CalPend;
  INT_Enable();
  return tmp;
}



RAIL_CalMask_t RAIL_CalPendingGet(void)

{
  RAIL_CalMask_t tmp;
  
  INT_Disable();
  tmp = RAIL_CalPend;
  INT_Enable();
  return tmp;
}



void RAIL_CalStart(RAIL_CalValues_t *calValues,RAIL_CalMask_t calForce,bool calSave)

{
  int local_14;
  
  if (calValues == NULL) local_14 = -1;
  else local_14 = *calValues;
  if (calForce == 0) calForce = RAIL_RfHalCalibrationPendingGet();
  RAIL_RfHalCalibrationClear(SUB41(calForce,0));
  RAIL_RfHalCalibrationRun(&local_14,SUB41(calForce,0));
  if ((calSave != false) && (calValues != NULL)) *calValues = local_14;
}



uint8_t RAIL_CalInit(RAIL_CalInit_t *railCalInit)

{
  uint8_t tmp;
  
  tmp = IRCAL_Init(railCalInit->irCalSettings);
  RAIL_RfHalCalibrationInit(railCalInit->calEnable & 0x10001);
  return tmp;
}


