#include "rail_ieee802154.h"



RAIL_Status_t RAIL_IEEE802154_2p4GHzRadioConfig(void)

{
  RAIL_Status_t RVar1;
  
  RAIL_ChannelConfig((RAIL_ChannelConfig_t *)&channels);
  RVar1 = RFHAL_IEEE802154RadioConfig2p4GHz();
  return RVar1;
}



int RAIL_IEEE802154_Deinit(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 local_10;
  undefined4 uStack12;
  
  local_10 = param_1;
  uStack12 = param_2;
  iVar1 = RAIL_RfStateGet();
  if (iVar1 == 0) {
    RAIL_AddressFilterDisable();
    RAIL_AddressFilterReset();
    RAIL_AutoAckDisable();
    local_10 = 0x640064;
    uStack12 = 0x640064;
    RAIL_SetStateTiming(&local_10,0x640064,&DAT_00010160,&stack0xfffffff8);
    RFHAL_IEEE802154Disable();
  }
  else {
    iVar1 = 2;
  }
  return iVar1;
}



void RAIL_IEEE802154_IsEnabled(void)

{
  RFHAL_IEEE802154IsEnabled();
  return;
}



bool RAIL_IEEE802154_SetAddresses(RAIL_IEEE802154_AddrConfig_t *addresses)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  
  if (addresses != (RAIL_IEEE802154_AddrConfig_t *)0x0) {
    bVar1 = RFHAL_IEEE802154SetPanId(addresses->panId);
    bVar2 = RFHAL_IEEE802154SetShortAddress(addresses->shortAddr);
    bVar3 = RFHAL_IEEE802154SetLongAddress(addresses->longAddr);
    return (bool)(bVar3 | bVar2 | bVar1);
  }
  return false;
}


/* void RAIL_IEEE802154_SetPanId(void)

{
  RFHAL_IEEE802154SetPanId();
  return;
} */

bool RAIL_IEEE802154_SetPanId(uint16_t panId)

{
  undefined uVar1;
  uint in_r1;
  undefined4 in_r2;
  undefined4 in_r3;
  uint auStack12 [3];
  
  auStack12[0] = in_r1 & 0xffff0000 | (uint)panId;
  uVar1 = GENERIC_PHY_SetIeeePanId(1,auStack12,in_r2,in_r3,panId);
  return (bool)uVar1;
}

/* void RAIL_IEEE802154_SetShortAddress(void)

{
  RFHAL_IEEE802154SetShortAddress();
  return;
}
 */
bool RAIL_IEEE802154_SetShortAddress(uint16_t shortAddr)

{
  bool bVar1;
  
  bVar1 = GENERIC_PHY_SetIeeeShortAddress(1);
  return bVar1;
}

/* void RAIL_IEEE802154_SetLongAddress(void)

{
  RFHAL_IEEE802154SetLongAddress();
  return;
} */

bool RAIL_IEEE802154_SetLongAddress(uint8_t *longAddr)

{
  bool bVar1;
  
  bVar1 = GENERIC_PHY_SetIeeeLongAddress(1,longAddr);
  return bVar1;
}

RAIL_Status_t RAIL_IEEE802154_SetPanCoordinator(bool isPanCoordinator)

{
  bool bVar1;
  RAIL_Status_t RVar2;
  
  bVar1 = RFHAL_IEEE802154IsEnabled();
  if (bVar1 != false) {
    RVar2 = RFHAL_IEEE802154SetPanCoordinator(isPanCoordinator);
    return RVar2;
  }
  return RAIL_STATUS_INVALID_STATE;
}




RAIL_Status_t RAIL_IEEE802154_SetPromiscuousMode(bool enable)

{
  bool bVar1;
  RAIL_Status_t RVar2;
  
  bVar1 = RFHAL_IEEE802154IsEnabled();
  if (bVar1 != false) {
    RVar2 = RFHAL_IEEE802154SetPromiscuousMode(enable);
    return RVar2;
  }
  return RAIL_STATUS_INVALID_STATE;
}



RAIL_Status_t RAIL_IEEE802154_AcceptFrames(uint8_t framesMask)

{
  bool bVar1;
  RAIL_Status_t RVar2;
  
  bVar1 = RFHAL_IEEE802154IsEnabled();
  if (bVar1 != false) {
    RVar2 = RFHAL_IEEE802154AcceptFrames(framesMask);
    return RVar2;
  }
  return RAIL_STATUS_INVALID_STATE;
}



RAIL_Status_t RAIL_IEEE802154_Init(RAIL_IEEE802154_Config_t *config)

{
  RAIL_Status_t RVar1;
  bool bVar2;
  int iVar3;
  uint8_t local_30;
  undefined local_2f;
  undefined2 local_2c [2];
  RAIL_AutoAckConfig_t local_28;
  RAIL_AddrConfig_t local_20;
  
  local_20.offsets = &local_30;
  RFHAL_IEEE802154Enable();
  RAIL_IEEE802154_SetPanCoordinator((bool)config->isPanCoordinator);
  RAIL_IEEE802154_SetPromiscuousMode((bool)config->promiscuousMode);
  RAIL_IEEE802154_AcceptFrames(config->framesMask);
  local_28.defaultState = config->defaultState;
  local_28.idleTiming = config->idleTime;
  local_28.turnaroundTime = config->turnaroundTime;
  local_28.ackTimeout = config->ackTimeout;
  RVar1 = RAIL_AutoAckConfig(&local_28);
  if (RVar1 == RAIL_STATUS_NO_ERROR) {
    RVar1 = RFHAL_IEEE802154LoadAck();
  }
  RAIL_AddressFilterReset();
  local_2c[0] = 0x802;
  local_20.numFields = '\x02';
  local_20.sizes = (uint8_t *)local_2c;
  local_30 = '\0';
  local_2f = 0;
  local_20.matchTable = 0;
  bVar2 = RAIL_AddressFilterConfig(&local_20);
  iVar3 = RFHAL_IEEE802154SetBroadcastAddresses();
  if ((iVar3 == 0) || (bVar2 == false)) {
    RVar1 = RAIL_STATUS_INVALID_PARAMETER;
  }
  RAIL_AddressFilterEnable();
  RAIL_IEEE802154_SetAddresses(config->addresses);
  return RVar1;
}



/* void RAIL_IEEE802154_SetFramePending(void)

{
  RFHAL_IEEE802154SetFramePending();
  return;
}
 */
RAIL_Status_t RAIL_IEEE802154_SetFramePending(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = GENERIC_PHY_CanModifyAck();
  uVar3 = 2;
  if (iVar2 != 0) {
    BUS_RegMaskedSet(&RAC->SR0,2);
    uVar1 = (RAC->SR0);
    if ((uVar1 & 0x20000) == 0) {
      BUS_RegMaskedSet(&RAC->SR2,0x10);
      uVar3 = uVar1 & 0x20000;
    }
    BUS_RegMaskedClear(&RAC->SR0,2);
    return (RAIL_Status_t)uVar3;
  }
  return RAIL_STATUS_INVALID_STATE;
}

