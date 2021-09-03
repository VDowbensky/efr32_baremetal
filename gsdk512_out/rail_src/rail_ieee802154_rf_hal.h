rail_ieee802154_rf_hal.h
#ifndef _RAIL_IEEE802154_RFHAL_H_
#define _RAIL_IEEE802154_RFHAL_H_

void RFHAL_802154SetPhyforChan(int phy);
void RFHAL_IEEE802154Enable(void);
void RFHAL_IEEE802154Disable(void);
bool RFHAL_IEEE802154IsEnabled(void);
RAIL_Status_t RFHAL_IEEE802154RadioConfig2p4GHz(void);

uint8_t RFHAL_IEEE802154SetBroadcastAddresses(undefined4 param_1,undefined4 param_2,undefined4 param_3);

bool RFHAL_IEEE802154SetPanId(uint16_t panId);
void RFHAL_IEEE802154SetShortAddress(uint16_t shortAddr);
bool RFHAL_IEEE802154SetLongAddress(uint8_t *longAddr);
RAIL_Status_t RFHAL_IEEE802154SetPromiscuousMode(bool enable);
RAIL_Status_t RFHAL_IEEE802154SetPanCoordinator(bool isPanCoordinator);
RAIL_Status_t RFHAL_IEEE802154AcceptFrames(uint8_t framesMask);
uint32_t RFHAL_IEEE802154SetFramePending(void);

void RFHAL_IEEE802154LoadAck(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
#endif
