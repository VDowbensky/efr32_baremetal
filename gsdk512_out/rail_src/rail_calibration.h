#ifndef _RAIL_CALIBRATION_H_
#define _RAIL_CALIBRATION_H_

void RAILINT_CalibrationEnable(RAIL_CalMask_t cal);
void RAILINT_CalibrationPend(RAIL_CalMask_t cal);
RAIL_CalMask_t RAILINT_CalibrationClear(RAIL_CalMask_t cal);
RAIL_CalMask_t RAILINT_CalibrationEnableGet(void);
RAIL_CalMask_t RAIL_CalPendingGet(void);
void RAIL_CalStart(RAIL_CalValues_t *calValues, RAIL_CalMask_t calForce, bool calSave);
uint8_t RAIL_CalInit(const RAIL_CalInit_t *railCalInit);

#endif
