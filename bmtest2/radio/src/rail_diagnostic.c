#include "rail_diagnostic.h"
#include <stdbool.h>
#include "em_bus.h"
#include "em_assert.h"
#include "rail_rf.h"
#include "rail_rf_hal.h"

RAIL_BerConfig_t berConfigGlobal;
/**
 * Stop BER test
 *
 * @return void
 *
 * Halt a test early, or exit infinite BER receive mode.
 * This function has been deprecated.
 */
void RAIL_BerRxStop(void)

{
  RFHAL_StopBerRx();
  RAIL_RfIdle();
}


/**
 * Configure BER test
 *
 * @param[in] berConfig BER test parameters to apply.
 *
 * Configure settings specific to bit error rate (BER) testing.
 * During BER test mode, this device will expect to receive a standard PN9
 * signal (x^9 + x^5 + 1). In order to use this BER test, the selection
 * for BER mode should be enabled from the radio configurator.
 * This function has been deprecated.
 */
void RAIL_BerConfigSet(RAIL_BerConfig_t *berConfig)

{
  RAIL_BerRxStop();
  RFHAL_SetBerConfig(berConfig);
  berConfigGlobal = *berConfig;
}


/**
 * Start BER test
 *
 * @return void
 *
 * Enter BER receive with the settings specified by RAIL_BerConfigSet().
 * This also resets the BER status.
 * This function has been deprecated.
 */
void RAIL_BerRxStart(void)

{
  RAIL_BerRxStop();
  RFHAL_SetBerConfig(&berConfigGlobal);
  RFHAL_StartBerRx();
}


/**
 * Get BER test status
 *
 * @param[out] status Statistics pertaining to the latest BER test.
 * @return void
 *
 * Get status of latest BER test.
 * This function has been deprecated.
 */
void RAIL_BerStatusGet(RAIL_BerStatus_t *status)

{
  RFHAL_GetBerStatus(status); //!!!
}


