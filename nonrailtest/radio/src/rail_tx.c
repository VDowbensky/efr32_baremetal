#include "rail_tx.h"
#include <stdbool.h>
#include "em_bus.h"
#include "em_assert.h"
#include "rail_rf_hal.h"
#include "rail_rf.h"

/**
 * Load payload to transmit.
 *
 * @param[in] txData Pointer to a RAIL_TxData_t structure which defines the
 * payload bytes and the number of bytes to write into the transmit buffer.
 * @return Returns 0 on success and an error code on fail.
 *
 * This function will overwrite current TX data held by RAIL, and will return
 * an error if called during transmit operations. RAIL_TxData_t.dataLength
 * defines the number of bytes to load into the transmit buffer from
 * RAIL_TxData_t.dataPtr while the number of bytes transmitted is determined by
 * the packet configuration defined in the radio configuration.
 *
 * @note This function creates a critical section while writing to the transmit
 * buffer.
 */
uint8_t RAIL_TxDataLoad(RAIL_TxData_t *txData)

{
  return RAIL_RfHalTxDataLoad(txData); //!!!
}


/**
 * Non-blocking Transmit
 *
 * @param[in] channel Define the channel to transmit on.
 * @param[in] preTxOp Function to use for any pre-transmit operation (e.g. for
 * scheduled transmit, CSMA, LBT, etc.), or NULL for an immediate transmit.
 * @param[in] preTxOpParams Pointer to the pre-transmit operation's
 * configuration parameters, or NULL if none.
 * @return Returns 0 on successfully initiating the transmit process, or an
 * error code on failure. If successfully initiated, transmit completion
 * or failure will be reported by later callbacks RAILCb_TxPacketSent()
 * (success) or RAILCb_TxRadioStatus() (failure).
 *
 * Begins transmission of the payload previously loaded via RAIL_TxDataLoad().
 * Will begin transmitting after a received packet if currently receiving a
 * packet. Returns error if the radio is active and the channel needs to be
 * changed.
 */
uint8_t RAIL_TxStart(uint8_t channel, RAIL_PreTxOp_t preTxOp, void *preTxOpParams)

{
  uint8_t *p;
  uint8_t v;

  if (RFHAL_HeadedToIdle() == 0) return 2;
  p = (uint8_t *)RAILInt_SetChannelConfig(channel);
  if (p != NULL)
  {
    v = RAIL_RfHalTxStart(channel - (uint8_t)*p & 0xff,preTxOp,preTxOpParams);
    return v;
  }
  return 1;
}


