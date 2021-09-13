/***************************************************************************//**
 * @file pa_curve_types_efr32.h
 * @brief PA power conversion curve types used by Silicon Labs PA power
 * conversion functions
 * @details
 * This file contains the curve types needed convert PA power levels
 * to dBm powers.
 *
 *******************************************************************************
 * @section License
 * <b>(C) Copyright 2017 Silicon Labs, www.silabs.com</b>
 *******************************************************************************
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 * DISCLAIMER OF WARRANTY/LIMITATION OF REMEDIES: Silicon Labs has no
 * obligation to support this Software. Silicon Labs is providing the
 * Software "AS IS", with no express or implied warranties of any kind,
 * including, but not limited to, any implied warranties of merchantability
 * or fitness for any particular purpose or warranties against infringement
 * of any proprietary rights of a third party.
 *
 * Silicon Labs will not be liable for any consequential, incidental, or
 * special damages, or any other relief, or for any claim by any third party,
 * arising from your use of this Software.
 *
 ******************************************************************************/
#ifndef __PA_CURVE_TYPES_EFR32_H_
#define __PA_CURVE_TYPES_EFR32_H_

/**
 * @struct RAIL_TxPowerCurves
 *
 * @brief Structure containing data defining each segment of the
 * power (deci-dBm) to powerLevel mapping curve fits.
 *
 * Note, these used in an equation of the form:
 *
 *    powerLevel * 1000 = slope * power + powerLevel * 1000
 *
 * powerLevel is the 0-252/0-248/1-7 values used in the RAIL_Get/SetTxPower
 * functions, and power is the actual output power of the PA, specified
 * in deci-dBm.
 */
typedef struct RAIL_TxPowerCurveSegment {
  /** The highest power level that this segment will be used to convert */
  uint16_t maxPowerLevel;
  /** slope of the line */
  int16_t slope;
  /** y-intercept of the line */
  int32_t intercept;
} RAIL_TxPowerCurveSegment_t;

/**
 * @struct RAIL_TxPowerCurves
 *
 * @brief Structure containing the min and max values for a given
 * PA and voltage supply combination (in deci-dBm).
 */
typedef struct RAIL_TxPowerCurves {
  /** max deci-dBm value */
  int16_t maxPower;
  /** min deci-dBm value */
  int16_t minPower;
  /**
   * Pointer to "piecewiseSegments"-length array of
   * RAIL_TxPowerCurveSegment_t of power (deci-dBm) to
   * powerLevel conversion fits.
   */
  const RAIL_TxPowerCurveSegment_t* powerParams;
} RAIL_TxPowerCurves_t;

/**
 * @struct RAIL_TxPowerCurvesConfig
 *
 * @brief Structure containing curve fit information and other metadata
 * required to properly use the WEAK versions of RAIL_ConvertRawToDb
 * and RAIL_ConvertDbmToRaw
 */
typedef struct RAIL_TxPowerCurvesConfig {
  /**
   * Pointer a RAIL_TxPowerCurves_t representing the piecewise linear segments
   * of curves that map power level to power in dBm for the 2.4 GHz high power
   * PA.
   *
   * @note By the default conversion implementation, segments must be specified
   * in decreasing power order. That is, the 0th entry of this array should be
   * used to convert the highest power (levels). Segment at position n is valid
   * from maxPowerLevel+1 from the segment at n+1 (or 0 if n is array length -
   * 1) to maxPowerLevel of segment n, inclusive.
   */
  const RAIL_TxPowerCurves_t* txPower24HpCurves;

  /**
   * Pointer a RAIL_TxPowerCurves_t representing the piecewise linear segments
   * of curves that map power level to power in dBm for the subgig PA.
   *
   * @note By the default conversion implementation, segments must be specified
   * in decreasing power order. That is, the 0th entry of this array should be
   * used to convert the highest power (levels). Segment at position n is valid
   * from maxPowerLevel+1 from the segment at n+1 (or 0 if n is array length -
   * 1) to maxPowerLevel of segment n, inclusive.
   */
  const RAIL_TxPowerCurves_t* txPowerSgCurves;

  /**
   * Look up table - array of length 7 - for each of the 7 power levels of the
   * 2.4GHz low power amplifier and their equivalent deci-dB value.
   */
  const int16_t* txPower24LpCurves;
  /**
   * The number of piecewise segments provided to the PA in each of the four
   * conversion curve fits. The default is 8, but regardless of the number, it
   * must be the same for all curves.
   */
  uint8_t piecewiseSegments;
} RAIL_TxPowerCurvesConfig_t;

#endif
