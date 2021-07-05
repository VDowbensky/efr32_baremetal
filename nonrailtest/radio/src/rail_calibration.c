#include "rail_calibration.h"
#include <stdbool.h>
#include "em_bus.h"
#include "em_assert.h"
#include "em_int.h"
#include "rail_types.h"
#include "rail_calibration.h"
#include "ir_cal.h"
#include "rail_rf_hal.h"
#include "rail.h"

uint32_t RAIL_CalPend;
uint32_t RAIL_CalEnable;

void RAIL_RfHalCalibrationInit(uint32_t cal)

{
  INT_Disable();
  RAIL_CalPend = 0;
  RAIL_CalEnable = cal;
  INT_Enable();
}



void RAIL_RfHalCalibrationSet(uint32_t cal)

{
  INT_Disable();
  cal = cal & RAIL_CalEnable;
  RAIL_CalPend = cal;
  INT_Enable();
  if (cal != 0) RAILCb_CalNeeded();
}



void RAIL_RfHalCalibrationPend(uint32_t cal)

{
  INT_Disable();
  cal = cal & RAIL_CalEnable;
  RAIL_CalPend = RAIL_CalPend | cal;
  INT_Enable();
  if (cal != 0) RAILCb_CalNeeded();
}



uint32_t RAIL_RfHalCalibrationClear(uint32_t cal)

{
  INT_Disable();
  RAIL_CalPend &= ~(cal & RAIL_CalEnable);
  INT_Enable();
  return RAIL_CalPend;
}



uint32_t RAIL_RfHalCalibrationEnableGet(void)

{
  return RAIL_CalEnable;
}



uint32_t RAIL_RfHalCalibrationPendingGet(void)

{
  uint32_t t;
  
  INT_Disable();
  t = RAIL_CalPend;
  INT_Enable();
  return t;
}


/**
 * Returns the current set of pending calibrations
 *
 * @return A mask of all pending calibrations that the user has been asked to
 * perform.
 *
 * This function will return a full set of pending calibrations. The only way
 * to clear pending calibrations is to perform them using the \ref RAIL_CalStart()
 * API with the appropriate list of calibrations.
 */
RAIL_CalMask_t RAIL_CalPendingGet(void)

{
  uint32_t uVar1;
  
  INT_Disable();
  uVar1 = RAIL_CalPend;
  INT_Enable();
  return uVar1;
}


/**
 * Start the calibration process
 *
 * @param[in] calValues Calibration Values to apply. To force the calibration
 * algorithm to run set the value to \ref RAIL_CAL_INVALID_VALUE.
 * @param[in] calForce  Mask to force certain calibration(s) to execute. These
 * will run even if not enabled during initialization. If specified, only forced
 * calibrations will be run.
 * @param[in] calSave If true, we will update any invalid values in calValues
 * with their computed value. You can use this to save calibrations across runs.
 *
 * This function begins the calibration process while determining which
 * calibrations should be performed. The possible list of calibration options
 * are configured in RAIL_Init_t.calEnable parameter.
 *
 * If the calibration was performed previously and the application saves off
 * the calibration value, it can be passed into function and applied to the
 * chip. If the calibration value provided is \ref RAIL_CAL_INVALID_VALUE then
 * the calibration will be performed to set this value. If calSave is set, the
 * calibration output will update  the pointer's value. If a NULL pointer is
 * passed in all calibrations requested/required will be performed and the
 * results will not be saved regardless of the calSave parameter.
 *
 * @note Some calibrations should only be executed when the radio is IDLE. See
 * chip-specific documentation for more detail.
 */
 //typedef struct RAIL_CalValues {
 // uint32_t imageRejection; /**< Image Rejection (IR) calibration value */
//} RAIL_CalValues_t;
//typedef uint32_t RAIL_CalMask_t;
void RAIL_CalStart(RAIL_CalValues_t *calValues, RAIL_CalMask_t calForce, bool calSave)

{
  RAIL_CalValues_t c;
  
  if (calValues == NULL)
  {
   // c = (RAIL_CalValues_t)0xffffffff; //!!!!!!!!!!!!!!!!!!!!
  }
  else
  {
    c = *calValues;
  }
  if (calForce == 0)
  {
	  calForce = RAIL_RfHalCalibrationPendingGet();
  }
  RAIL_RfHalCalibrationClear(calForce);
//  RAIL_RfHalCalibrationRun(c,calForce);//!!!!!!!!!!!!!!!!!!!!
  if ((calSave != 0) && (calValues != NULL))
  {
    *calValues = c;
  }
  return;
}


/**
 * Initialize RAIL Calibration
 *
 * @param[in] railCalInit The initialization structure to be used for setting
 *   up calibration procedures.
 * @return Returns zero on success and an error code on error.
 *
 * Calibration initialization provides the calibration settings that
 * correspond to the current radio configuration.
 */

uint8_t RAIL_CalInit(const RAIL_CalInit_t *railCalInit)

{
//return IRCAL_Init(&railCalInit);
//  RAIL_RfHalCalibrationInit(*railCalInit & 0x10001); //!!!!!!!!!!!!!!!!!!!!!!!!!
  return 0;
}


