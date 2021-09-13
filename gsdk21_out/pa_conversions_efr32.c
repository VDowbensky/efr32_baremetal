/***************************************************************************//**
 * @file pa_conversions_efr32.c
 * @brief PA power conversion functions provided to the customer as source for
 *        highest level of customization.
 * @details
 * This file contains the curves and logic that convert PA power levels
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
#include "em_device.h"
#include "em_assert.h"
#include "em_cmu.h"
#include "em_common.h"

#include "pa_conversions_efr32.h"
#include "rail_chip_specific.h"

static const RAIL_TxPowerCurves_t *txPower24HpCurves;

static const RAIL_TxPowerCurves_t *txPowerSgCurves;

static const int16_t *txPower24LpCurves;

static uint8_t piecewiseSegments;

// This macro is defined when Silicon Labs builds this into the library as WEAK
// to ensure it can be overriden by customer versions of these functions. It
// should *not* be defined in a customer build.
#ifdef RAIL_PA_CONVERSIONS_WEAK
SL_WEAK
#endif
const RAIL_TxPowerCurves_t* RAIL_GetTxPowerCurve(RAIL_TxPowerMode_t mode)
{
  if (mode == RAIL_TX_POWER_MODE_2P4_HP) {
    return txPower24HpCurves;
  } else {
    /* Subgig entries */
    return txPowerSgCurves;
  }
}

#ifdef RAIL_PA_CONVERSIONS_WEAK
SL_WEAK
#endif
RAIL_Status_t RAIL_InitTxPowerCurves(RAIL_TxPowerCurvesConfig_t *config)
{
  piecewiseSegments = config->piecewiseSegments;
  txPower24HpCurves = config->txPower24HpCurves;
  txPowerSgCurves = config->txPowerSgCurves;
  txPower24LpCurves = config->txPower24LpCurves;

  return RAIL_STATUS_NO_ERROR;
}

#ifdef RAIL_PA_CONVERSIONS_WEAK
SL_WEAK
#endif
RAIL_TxPowerLevel_t RAIL_ConvertDbmToRaw(RAIL_Handle_t railHandle,
                                         RAIL_TxPowerMode_t mode,
                                         RAIL_TxPower_t power)
{
  // This function is called internally from the RAIL library,
  // so if the user never calls RAIL_InitTxPowerCurves - even
  // if they never intend to use dBm values in their code -
  // they'll always hit the assert below. Give the user a way
  // to not have to call RAIL_InitTxPowerCurves if they don't
  // care about dBm values by picking a dBm value that returns the
  // highest RAIL_TxPowerLevel_t possible. In other words, when
  // a channel dBm limitation greater than or equal to \ref RAIL_TX_POWER_MAX
  // is converted to raw units, the max RAIL_TxPowerLevel_t will be
  // returned. When compared to the current power level of the PA,
  // it will always be greater, indicating that no power coercion
  // is necessary to comply with channel limitations.
  if (power >= RAIL_TX_POWER_MAX) {
    return 255;
  }

  // If the curves haven't been initialized yet, it's definitely not safe to
  // call this function. If you aren't using the curve declaration macros (see
  // pa_curves_efr32.h) or RAIL_InitTxPowerCurves exactly as Silicon Labs
  // provides them, you may have to update this conditional. RAIL_InitTxPowerCurves,
  // as we implement it, is designed to initialize all of these curves,
  // and must be called before conversion functions are called.
  if (txPower24HpCurves == NULL
      || txPowerSgCurves == NULL
      || txPower24LpCurves == NULL) {
    RAILCb_AssertFailed(railHandle, RAIL_ASSERT_CONVERSION_CURVES_NOT_INITIALIZED);
  }

  uint32_t powerLevel;
  int16_t powerIndex;

  RAIL_TxPowerCurveSegment_t const * powerParams;
  RAIL_TxPowerCurves_t const * paParams
    = RAIL_GetTxPowerCurve(mode);

  // If we're in low power mode, just use the simple lookup table
  if (mode == RAIL_TX_POWER_MODE_2P4_LP) {
    /* Loop through the lookup table to find the closest power level
     * without going over */
    for (powerIndex = (RAIL_TX_POWER_LEVEL_LP_MAX - 1);
         (powerIndex != 0) && (power < txPower24LpCurves[powerIndex]);
         powerIndex--) {
      /* Searching */
    }
    return powerIndex + 1;
  }

  // Cap the power based on the PA settings.
  if (power > paParams->maxPower) {
    power = paParams->maxPower;
  } else if (power < INT16_MIN + 200) {
    // Prevent the "- 200" below from underflowing
    // an int32_t.
    power = INT16_MIN + 200;
  } else {
  }
  // Map the power value to a 0 - 7 powerIndex value
  // 0 -> 20dBm - 16dBm; 1 -> 16dBm - 12dBm, etc...
  // These are just starting points to give the code
  // a rough idea of which segment to use, based on
  // how they were fit. Adjustments are made later on
  // if this turns out to be incorrect.
  powerIndex = ((power - 200) / 40);
  powerIndex = -powerIndex;
  if (powerIndex > (piecewiseSegments - 1)) {
    powerIndex = piecewiseSegments - 1;
  }

  do {
    // Select the correct piecewise segment to use for conversion.
    powerParams = &paParams->powerParams[powerIndex];

    // powerLevel can only go down to 0.
    if (powerParams->intercept + powerParams->slope * power < 0) {
      powerLevel = 0;
    } else {
      powerLevel = powerParams->intercept + powerParams->slope * power;
    }

    // Add 500 to do rounding correctly, as opposed to just rounding towards 0
    powerLevel = ((powerLevel + 500) / 1000);

    // In case it turns out the resultant power level was too low and we have
    // to recalculate with the next curve...
    powerIndex++;
  } while ((powerIndex < piecewiseSegments)
           && (powerLevel <= paParams->powerParams[powerIndex].maxPowerLevel));

  // We already know that powerIndex is at most piecewiseSegments
  if (powerLevel > paParams->powerParams[powerIndex - 1].maxPowerLevel) {
    powerLevel = paParams->powerParams[powerIndex - 1].maxPowerLevel;
  }

  // Although 0 is a legitimate power on non-2.4 LP PA's and can be set via
  // "RAIL_SetTxPower(railHandle, 0)" it is MUCH lower than power
  // level 1 (approximately -50 dBm). Including it in the piecewise
  // linear fit would skew the curve substantially, so we exclude it
  // from the conversion.
  if (powerLevel == 0) {
    powerLevel = 1;
  }
  return powerLevel;
}

#ifdef RAIL_PA_CONVERSIONS_WEAK
SL_WEAK
#endif
RAIL_TxPower_t RAIL_ConvertRawToDbm(RAIL_Handle_t railHandle,
                                    RAIL_TxPowerMode_t mode,
                                    RAIL_TxPowerLevel_t powerLevel)
{
  // If the curves haven't been initialized yet, it's definitely not safe to
  // call this function. If you aren't using the curve declaration macros (see
  // pa_curves_efr32.h) or RAIL_InitTxPowerCurves exactly as Silicon Labs
  // provides them, you may have to update this conditional. RAIL_InitTxPowerCurves,
  // as we implement it, is designed to initialize all of these curves,
  // and must be called before conversion functions are called.
  if (txPower24HpCurves == NULL
      || txPowerSgCurves == NULL
      || txPower24LpCurves == NULL) {
    RAILCb_AssertFailed(railHandle, RAIL_ASSERT_CONVERSION_CURVES_NOT_INITIALIZED);
  }

  if (mode == RAIL_TX_POWER_MODE_2P4_LP) {
    // Limit the max power level
    if (powerLevel > RAIL_TX_POWER_LEVEL_LP_MAX) {
      powerLevel = RAIL_TX_POWER_LEVEL_LP_MAX;
    }

    // We 1-index low power PA power levels, but of course arrays are 0 indexed
    if (powerLevel != 0) {
      powerLevel--;
    }

    return txPower24LpCurves[powerLevel];
  } else {
    // Although 0 is a legitimate power on non-2.4 LP PA's and can be set via
    // "RAIL_SetTxPower(railHandle, 0)" it is MUCH lower than power
    // level 1 (approximately -50 dBm). Including it in the piecewise
    // linear fit would skew the curve substantially, so we exclude it
    // from the conversion.
    if (powerLevel == 0) {
      return -500;
    }

    int32_t power;

    RAIL_TxPowerCurves_t const * powerCurves = RAIL_GetTxPowerCurve(mode);

    RAIL_TxPowerCurveSegment_t const * powerParams = powerCurves->powerParams;

    // Hard code the extremes (i.e. don't use the curve fit) in order
    // to make it clear that we are reaching the extent of the chip's
    // capabilities
    if (powerLevel <= 1) {
      return powerCurves->minPower;
    } else if (powerLevel >= ((mode == RAIL_TX_POWER_MODE_2P4_HP)
                              ? RAIL_TX_POWER_LEVEL_HP_MAX
                              : RAIL_TX_POWER_LEVEL_SUBGIG_MAX)) {
      return powerCurves->maxPower;
    } else {
    }

    /*! Figure out which parameter to use based on the power level */
    uint8_t x;
    uint8_t upperBound = piecewiseSegments - 1;
    for (x = 0; x < upperBound; x++) {
      if (powerParams[x + 1].maxPowerLevel < powerLevel) {
        break;
      }
    }

    power = ((1000 * (int32_t)(powerLevel)) - powerParams[x].intercept);
    power = ((power + (powerParams[x].slope / 2)) / powerParams[x].slope);

    return power;
  }
}
