#ifndef _RAIL_CAL_H_
#define _RAIL_CAL_H_

#include "em_device.h"
#include <stdint.h>
#include <stdbool.h>
#include "rail_types.h"

void RAIL_RfHalCalibrationInit(uint32_t cal);
void RAIL_RfHalCalibrationSet(uint32_t cal);
void RAIL_RfHalCalibrationPend(uint32_t cal);
uint32_t RAIL_RfHalCalibrationClear(uint32_t cal);
uint32_t RAIL_RfHalCalibrationEnableGet(void);
uint32_t RAIL_RfHalCalibrationPendingGet(void);
RAIL_CalMask_t RAIL_CalPendingGet(void);
void RAIL_CalStart(RAIL_CalValues_t *calValues, RAIL_CalMask_t calForce, bool calSave);
uint8_t RAIL_CalInit(const RAIL_CalInit_t *railCalInit);


extern uint32_t RAIL_CalPend;
extern uint32_t RAIL_CalEnable;

#endif
