#include "rail_ieee802154.h"



RAIL_Status_t RAIL_IEEE802154_2p4GHzRadioConfig(void)

{
  RAIL_ChannelConfig(&channels);
  return RFHAL_IEEE802154RadioConfig2p4GHz();
}



RAIL_Status_t RAIL_IEEE802154_Deinit(void)

{
  undefined4 local_10;
  undefined4 uStack12;
  
  if (RAIL_RfStateGet() == 0) 
  {
    RAIL_AddressFilterDisable();
    RAIL_AddressFilterReset();
    RAIL_AutoAckDisable();
    local_10 = 0x640064;
    uStack12 = 0x640064;
    RAIL_SetStateTiming(&local_10,0x640064,&DAT_00010160,&stack0xfffffff8);
    RFHAL_IEEE802154Disable();
	return RAIL_STATUS_NO_ERROR;
  }
  else return RAIL_STATUS_INVALID_STATE;
}



bool RAIL_IEEE802154_IsEnabled(void)

{
  return RFHAL_IEEE802154IsEnabled();
}



bool RAIL_IEEE802154_SetAddresses(uint16_t *addresses)

{
  if (addresses != (uint16_t *)0x0) 
  {
	return RFHAL_IEEE802154SetPanId(*addresses) | RFHAL_IEEE802154SetShortAddress(addresses[1]) | RFHAL_IEEE802154SetLongAddress((uint8_t)*(undefined4 *)(addresses + 2));
  }
  else return false;
}



bool RAIL_IEEE802154_SetPanId(uint16_t panId)

{
  return RFHAL_IEEE802154SetPanId(panId);
}



bool RAIL_IEEE802154_SetShortAddress(uint16_t shortAddr)

{
  return RFHAL_IEEE802154SetShortAddress(shortAddr);
}



bool RAIL_IEEE802154_SetLongAddress(uint8_t _longAddr)

{
  bool bVar1;
  
  bVar1 = RFHAL_IEEE802154SetLongAddress(_longAddr);
  return bVar1;
}



RAIL_Status_t RAIL_IEEE802154_SetPanCoordinator(bool isPanCoordinator)

{
  if (RFHAL_IEEE802154IsEnabled() != false) return RFHAL_IEEE802154SetPanCoordinator(isPanCoordinator);
  else return RAIL_STATUS_INVALID_STATE;
}



RAIL_Status_t RAIL_IEEE802154_SetPromiscuousMode(bool enable)

{
  if (RFHAL_IEEE802154IsEnabled() != false) return RFHAL_IEEE802154SetPromiscuousMode(enable);
  else return RAIL_STATUS_INVALID_STATE;
}



undefined4 RAIL_IEEE802154_AcceptFrames(uint8_t framesMask)

{
  if (RFHAL_IEEE802154IsEnabled() != false) return RFHAL_IEEE802154AcceptFrames(framesMask);
  else return RAIL_STATUS_INVALID_STATE;
}



RAIL_Status_t RAIL_IEEE802154_Init(RAIL_IEEE802154_Config_t *config)

{
  uint32_t uVar1;
  int iVar2;
  int iVar3;
  undefined local_30;
  undefined local_2f;
  undefined2 local_2c [2];
  undefined local_28 [2];
  undefined2 local_26;
  undefined2 local_24;
  undefined2 local_22;
  undefined local_20 [4];
  undefined *local_1c;
  undefined2 *local_18;
  undefined4 local_14;
  
  local_1c = &local_30;
  RFHAL_IEEE802154Enable();
  RAIL_IEEE802154_SetPanCoordinator((bool)config[1]);
  RAIL_IEEE802154_SetPromiscuousMode((bool)*config);
  RAIL_IEEE802154_AcceptFrames(config[2]);
  local_28[0] = config[3];
  local_26 = *(undefined2 *)(config + 4);
  local_24 = *(undefined2 *)(config + 6);
  local_22 = *(undefined2 *)(config + 8);
  uVar1 = RAIL_AutoAckConfig(local_28);
  if (RAIL_AutoAckConfig(local_28) == 0) uVar1 = RFHAL_IEEE802154LoadAck();
  RAIL_AddressFilterReset();
  local_2c[0] = 0x802;
  local_20[0] = 2;
  local_18 = local_2c;
  local_30 = 0;
  local_2f = 0;
  local_14 = 0;
  iVar2 = RAIL_AddressFilterConfig(local_20);
  iVar3 = RFHAL_IEEE802154SetBroadcastAddresses();
  if ((iVar3 == 0) || (iVar2 == 0)) uVar1 = 1;
  RAIL_AddressFilterEnable();
  RAIL_IEEE802154_SetAddresses(*(uint16_t **)(config + 0xc));
  return uVar1;
}



uint32_t RAIL_IEEE802154_SetFramePending(void)

{
  return RFHAL_IEEE802154SetFramePending();
}


