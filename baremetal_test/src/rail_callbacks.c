#include "rail.h"
/**
 * Callback that notifies the application that a calibration is needed.
 *
 * @return void
 *
 * This callback function is called whenever the RAIL library detects that a
 * calibration is needed. It is up to the application to determine a valid
 * window to call \ref RAIL_CalStart().
 */
void RAILCb_CalNeeded(void)
{
	
}

/**
 * Callback function to signify when the radio changes state.
 *
 * @param[in] state Current state of the radio. Exact values are for internal
 * use only.
 *
 * This is for debug and __NOT__ for application use. It is not called by
 * default but is required for the linking process.
 *
 * Create an empty function for this callback as shown below.
 *
 * @code{.c}
 * RAILCb_RadioStateChanged(uint8_t state) {
 * }
 * @endcode
 */
void RAILCb_RadioStateChanged(uint8_t state)
{
	
}

/**
 * Callback for when the radio is finished initializing from \ref RAIL_RfInit
 * and is ready to be configured
 *
 * @return void
 *
 * Callback that notifies the application when the radio is finished
 * initializing and is ready for further configuration. This callback is
 * useful for potential transceiver products that require a power up sequence
 * before further configuration is available.  After this callback fires, the
 * radio is ready for additional configuration before transmit and receive
 * operations.
 */
void RAILCb_RfReady(void)
{
	
}

/**
 * Called whenever an enabled radio status event occurs
 *
 * @param[in] status The event that triggered this callback
 *
 * The triggers that cause this function to be called can be enabled using the
 * RAIL_RxConfig() function.
 *
 * @note This function will return only the first 8 of all possible triggers.
 * For accessing all triggers see the new RAILCb_RxRadioStatusExt() API. If you
 * implement RAILCb_RxRadioStatusExt() this callback will no longer be used by
 * the RAIL library. In RAIL 2.0 this API will be merged with the
 * RAILCb_RxRadioStatusExt() for one clean interface.
 *
 * Triggers:
 *  - \ref RAIL_RX_CONFIG_PREAMBLE_DETECT
 *  - \ref RAIL_RX_CONFIG_SYNC1_DETECT
 *  - \ref RAIL_RX_CONFIG_SYNC2_DETECT
 *  - \ref RAIL_RX_CONFIG_FRAME_ERROR
 *  - \ref RAIL_RX_CONFIG_BUFFER_OVERFLOW
 *  - \ref RAIL_RX_CONFIG_ADDRESS_FILTERED
 *  - \ref RAIL_RX_CONFIG_RF_SENSED
 */
void RAILCb_RxRadioStatus(uint8_t status)
{
	
}

/**
 * This function is called when the RAIL timer expires
 *
 * @return void
 *
 * You must implement a stub for this in your RAIL application even if you
 * don't use the timer. You can use this callback for low-level protocol
 * features.
 */
void RAILCb_TimerExpired(void)
{
	
}

/**
 * Interrupt level callback to signify when the packet was sent
 *
 * @param txPacketInfo Information about the packet that was transmitted.
 * @note that this structure is only valid during the timeframe of the
 * callback.
 *
 * Currently the RAIL_TxPacketInfo_t only contains the time when the packet
 * was transmitted.
 */
//typedef struct RAIL_TxPacketInfo {
  /**
   * Timestamp of the transmitted packet in the RAIL timebase of microseconds.
   * The time is the end of the last bit of the transmitted packet.
   */
//  uint32_t timeUs;
// } RAIL_TxPacketInfo_t;
void RAILCb_TxPacketSent(RAIL_TxPacketInfo_t *txPacketInfo)
{
	
}

/**
 * Callback to indicate an error with a transmission
 *
 * @param[in] status A bit field that defines what event caused the callback
 *
 * This interrupt level callback allows the user finer granularity in handling
 * TX radio errors.
 *
 * Radio Statuses:
 * - \ref RAIL_TX_CONFIG_BUFFER_UNDERFLOW
 * - \ref RAIL_TX_CONFIG_CHANNEL_BUSY
 * - \ref RAIL_TX_CONFIG_TX_ABORTED
 * - \ref RAIL_TX_CONFIG_TX_BLOCKED
 * - \ref RAIL_TX_CONFIG_CHANNEL_CLEAR
 * - \ref RAIL_TX_CONFIG_CCA_RETRY
 * - \ref RAIL_TX_CONFIG_START_CCA
 */
void RAILCb_TxRadioStatus(uint8_t status)
{
	
}

