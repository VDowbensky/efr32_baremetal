#include "rail_rx.h"
#include <stdbool.h>
#include "em_bus.h"
#include "em_assert.h"
#include <stddef.h>
#include "rail_rf.h"
#include "rail_rf_hal.h"


/**
 * Configure radio receive actions
 *
 * @param[in] cbToEnable Define which callbacks to trigger for receive events.
 *  The full list of available callabcks can be found by looking at the
 *  RAIL_RX_CONFIG_* set of defines.
 * @param[in] appendedInfoEnable Enable/Disable appended info (not implemented)
 * @return Return 0 for success or an error code
 *
 * Setup which receive interrupts will generate a RAILCb_RxRadioStatus()
 * callback. The full list of options is any define that starts with
 * RAIL_RX_CONFIG_.
 */
uint8_t RAIL_RxConfig(uint8_t cbToEnable, bool appendedInfoEnable)

{
  if (RAIL_RfStateGet() != 1) return RAIL_RfHalRxIntEnable(cbToEnable); 
  else return 2;
}


/**
 * Listen on a channel for a packet
 *
 * @param[in] channel Channel to listen on
 * @return Return 0 for success or an error code
 *
 * This is a non-blocking function. RAILCb_RxPacketReceived() will be called
 * when a packet has been received. Returns an error if currently transmitting
 * or receiving.
 */
uint8_t RAIL_RxStart(uint8_t channel)

{
  //int iVar1;
  uint8_t *p;
  uint8_t t;
  
  //iVar1 = RFHAL_HeadedToIdle();
  if (RFHAL_HeadedToIdle() == 0) return 2;
  p = (uint8_t *)RAILInt_SetChannelConfig(channel);
  if (p != NULL)
  {
    t = RAIL_RfHalRxStart(channel - (uint8_t)*p & 0xff);
    return t;
  }
  return 1;
}


