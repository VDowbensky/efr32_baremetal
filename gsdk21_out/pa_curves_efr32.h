/***************************************************************************//**
 * @file pa_curves_efr32.h
 * @brief PA power conversion curves used by Silicon Labs PA power conversion
 * functions
 * @details
 * This file contains the curves needed convert PA power levels
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
#ifndef __PA_CURVES_EFR32_H_
#define __PA_CURVES_EFR32_H_

#define RAIL_PA_CURVES_LP_VALUES 7
#define RAIL_PA_CURVES_2P4_HP_SG_PIECEWISE_SEGMENTS 8

#define RAIL_PA_CURVES_2P4_HP_VBAT_MAX_POWER      200
#define RAIL_PA_CURVES_2P4_HP_VBAT_MIN_POWER      -260
#define RAIL_PA_CURVES_2P4_HP_VBAT_CURVES \
  { { 252, 2776, -300026 },               \
    { 157, 1335, -73192 },                \
    { 117, 772, -7179 },                  \
    { 73, 441, 17309 },                   \
    { 53, 343, 22520 },                   \
    { 22, 209, 22360 },                   \
    { 14, 124, 18896 },                   \
    { 8, 75, 14632 } }

#define RAIL_PA_CURVES_2P4_HP_DCDC_MAX_POWER      140
#define RAIL_PA_CURVES_2P4_HP_DCDC_MIN_POWER      -260
#define RAIL_PA_CURVES_2P4_HP_DCDC_CURVES \
  { { -1, 0, 0 },                         \
    { 252, 4306, -391604 },               \
    { 129, 1435, -52495 },                \
    { 80, 610, 13579 },                   \
    { 38, 331, 24456 },                   \
    { 24, 224, 23902 },                   \
    { 14, 140, 20330 },                   \
    { 8, 81, 15607 } }

#define RAIL_PA_CURVES_SG_VBAT_MAX_POWER          200
#define RAIL_PA_CURVES_SG_VBAT_MIN_POWER          -260
#define RAIL_PA_CURVES_SG_VBAT_CURVES \
  { { 248, 2924, -336264 },           \
    { 159, 1265, -71090 },            \
    { 117, 735, -8632 },              \
    { 76, 451, 13197 },               \
    { 36, 281, 19428 },               \
    { 19, 172, 19088 },               \
    { 12, 108, 16305 },               \
    { 7, 67, 12870 } }

#define RAIL_PA_CURVES_SG_DCDC_MAX_POWER          150
#define RAIL_PA_CURVES_SG_DCDC_MIN_POWER          -260
#define RAIL_PA_CURVES_SG_DCDC_CURVES \
  { { 248, 9069, -1171644 },          \
    { 248, 3826, -378994 },           \
    { 123, 932, -22748 },             \
    { 78, 470, 13485 },               \
    { 37, 304, 19712 },               \
    { 19, 192, 19146 },               \
    { 11, 110, 15607 },               \
    { 6, 56, 11146 } }

#define RAIL_PA_CURVES_2P4_LP  \
  {                            \
    -125, /*! Power Level 1 */ \
    -65,  /*! Power Level 2 */ \
    -30,  /*! Power Level 3 */ \
    -15,  /*! Power Level 4 */ \
    -7,   /*! Power Level 5 */ \
    -2,   /*! Power Level 6 */ \
    0     /*! Power Level 7 */ \
  }

/**
 * Macros to ease in the delcarations of the various power amplifier units
 * conversion curves.
 */
#define RAIL_DECLARE_PA_2P4_HP_VBAT                                                                             \
  static const RAIL_TxPowerCurveSegment_t twoPointFourHpVbatCurves[RAIL_PA_CURVES_2P4_HP_SG_PIECEWISE_SEGMENTS] \
    = RAIL_PA_CURVES_2P4_HP_VBAT_CURVES;

#define RAIL_DECLARE_PA_2P4_HP_DCDC                                                                             \
  static const RAIL_TxPowerCurveSegment_t twoPointFourHpDcdcCurves[RAIL_PA_CURVES_2P4_HP_SG_PIECEWISE_SEGMENTS] \
    = RAIL_PA_CURVES_2P4_HP_DCDC_CURVES;

#define RAIL_DECLARE_PA_SG_VBAT                                                                         \
  static const RAIL_TxPowerCurveSegment_t subgigVbatCurves[RAIL_PA_CURVES_2P4_HP_SG_PIECEWISE_SEGMENTS] \
    = RAIL_PA_CURVES_SG_VBAT_CURVES;

#define RAIL_DECLARE_PA_SG_DCDC                                                                         \
  static const RAIL_TxPowerCurveSegment_t subgigDcdcCurves[RAIL_PA_CURVES_2P4_HP_SG_PIECEWISE_SEGMENTS] \
    = RAIL_PA_CURVES_SG_DCDC_CURVES;

// *INDENT-OFF*
// Macro to declare the variables needed to initialize RAIL_TxPowerCurvesConfig_t for use in
// RAIL_InitTxPowerCurves, assuming battery powered operation
#define RAIL_DECLARE_TX_POWER_VBAT_CURVES(piecewiseSegments, curvesSg, curves24Hp, curves24Lp)               \
  static const uint8_t (piecewiseSegments) = RAIL_PA_CURVES_2P4_HP_SG_PIECEWISE_SEGMENTS;                    \
                                                                                                             \
  RAIL_DECLARE_PA_2P4_HP_VBAT;                                                                               \
  RAIL_DECLARE_PA_SG_VBAT;                                                                                   \
                                                                                                             \
  static const RAIL_TxPowerCurves_t curvesSg[1] =                                                            \
  {                                                                                                          \
    { RAIL_PA_CURVES_SG_VBAT_MAX_POWER, RAIL_PA_CURVES_SG_VBAT_MIN_POWER, subgigVbatCurves }                 \
  };                                                                                                         \
                                                                                                             \
  static const RAIL_TxPowerCurves_t curves24Hp[1] =                                                          \
  {                                                                                                          \
    { RAIL_PA_CURVES_2P4_HP_VBAT_MAX_POWER, RAIL_PA_CURVES_2P4_HP_VBAT_MIN_POWER, twoPointFourHpVbatCurves } \
  };                                                                                                         \
                                                                                                             \
  static const int16_t curves24Lp[RAIL_PA_CURVES_LP_VALUES] = RAIL_PA_CURVES_2P4_LP;
// *INDENT-OFF*

// Macro to declare the variables needed to initialize RAIL_TxPowerCurvesConfig_t for use in
// RAIL_InitTxPowerCurves, assuming DCDC powered operation
#define RAIL_DECLARE_TX_POWER_DCDC_CURVES(piecewiseSegments, curvesSg, curves24Hp, curves24Lp)               \
  static const uint8_t piecewiseSegments = RAIL_PA_CURVES_2P4_HP_SG_PIECEWISE_SEGMENTS;                      \
                                                                                                             \
  RAIL_DECLARE_PA_2P4_HP_DCDC;                                                                               \
  RAIL_DECLARE_PA_SG_DCDC;                                                                                   \
                                                                                                             \
  static const RAIL_TxPowerCurves_t curvesSg[1] =                                                            \
  {                                                                                                          \
    { RAIL_PA_CURVES_SG_DCDC_MAX_POWER, RAIL_PA_CURVES_SG_DCDC_MIN_POWER, subgigDcdcCurves }                 \
  };                                                                                                         \
                                                                                                             \
  static const RAIL_TxPowerCurves_t curves24Hp[1] =                                                          \
  {                                                                                                          \
    { RAIL_PA_CURVES_2P4_HP_DCDC_MAX_POWER, RAIL_PA_CURVES_2P4_HP_DCDC_MIN_POWER, twoPointFourHpDcdcCurves } \
  };                                                                                                         \
                                                                                                             \
  static const int16_t curves24Lp[RAIL_PA_CURVES_LP_VALUES] = RAIL_PA_CURVES_2P4_LP;

#endif
