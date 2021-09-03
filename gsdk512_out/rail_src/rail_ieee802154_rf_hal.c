#include "rail_ieee802154_rf_hal.h"

//prevRadioCfg;
static const unsigned char DAT_000101ba[2UL + 1] = {0xFF, 0xFF, 0x00};

void RFHAL_802154SetPhyforChan(int phy)

{
  undefined *puVar1;
  
  if (phy == 0xd) puVar1 = &ieee802154_config_2415MHz_min;
  else 
  {
    puVar1 = &ieee802154_config_base_min;
    if (phy == 0xe) puVar1 = &ieee802154_config_2420MHz_min;
  }
  if ((puVar1 != prevRadioCfg) && (RAIL_RadioConfig(&ieee802154_config_base_min), puVar1 != &ieee802154_config_base_min)) RAIL_RadioConfig(puVar1);
  prevRadioCfg = puVar1;
}



void RFHAL_IEEE802154Enable(void)

{
  GENERIC_PHY_EnableIEEE802154();
}



void RFHAL_IEEE802154Disable(void)

{
  RFHAL_SetProtocolSpecificChCheckCB(0);
  GENERIC_PHY_DisableIEEE802154();
}



bool RFHAL_IEEE802154IsEnabled(void)

{
  return GENERIC_PHY_IsEnabledIEEE802154();
}



RAIL_Status_t RFHAL_IEEE802154RadioConfig2p4GHz(void)

{
  RAIL_RadioConfig(&ieee802154_config_base);
  RFHAL_SetProtocolSpecificChCheckCB(RFHAL_802154SetPhyforChan);
  prevRadioCfg = &ieee802154_config_base_min;
  return RAIL_STATUS_NO_ERROR;
}



uint8_t RFHAL_IEEE802154SetBroadcastAddresses(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  uint8_t bVar1;
  uint8_t bVar2;
  undefined4 local_c;
  
  local_c = CONCAT22((short)((uint)param_2 >> 0x10),0xffff);
  bVar1 = GENERIC_PHY_SetIeeePanId(0,&local_c,param_3,0xffff,param_1);
  bVar2 = GENERIC_PHY_SetIeeeShortAddress(0,&local_c);
  return bVar2 & bVar1;
}



bool RFHAL_IEEE802154SetPanId(uint16_t panId)

{
  uint local_c;
  undefined4 uStack8;
  
  local_c = param_2 & 0xffff0000 | param_1 & 0xffff;
  uStack8 = param_3;
  return GENERIC_PHY_SetIeeePanId(1,&local_c,param_3,param_4,param_1);
}



void RFHAL_IEEE802154SetShortAddress(uint16_t shortAddr)

{
  uint local_c;
  undefined4 uStack8;
  
  local_c = param_2 & 0xffff0000 | param_1 & 0xffff;
  uStack8 = param_3;
  GENERIC_PHY_SetIeeeShortAddress(1,&local_c,param_3,param_4,param_1);
}



bool RFHAL_IEEE802154SetLongAddress(uint8_t *longAddr)

{
  return GENERIC_PHY_SetIeeeLongAddress(1,*longAddr);
}



RAIL_Status_t RFHAL_IEEE802154SetPromiscuousMode(bool enable)

{
  uint32_t t;
  
  t = CORE_EnterCritical();
  if (enable == 0) SEQ->REG000 &= 0xfffeffff;
  else SEQ->REG000 |= 0x10000;
  CORE_ExitCritical(t);
  return RAIL_STATUS_NO_ERROR;
}



RAIL_Status_t RFHAL_IEEE802154SetPanCoordinator(bool isPanCoordinator)

{
  uint32_t t;
  
  t = CORE_EnterCritical();
  if (param_1 == false) SEQ->REG000 &= 0xff7fffff;
  else SEQ->REG000 |= 0x800000;
  CORE_ExitCritical(t);
  return RAIL_STATUS_NO_ERROR;
}



RAIL_Status_t RFHAL_IEEE802154AcceptFrames(uint8_t framesMask)

{
  uint32_t t;
  
  t = CORE_EnterCritical();
  SEQ->REG000 &= 0xffe1ffff;
  SEQ->REG000 |= framesMask << 0x11;
  CORE_ExitCritical(t);
  return RAIL_STATUS_NO_ERROR;
}



uint32_t RFHAL_IEEE802154SetFramePending(void)

{
  uint32_t uVar3;
  
  uVar3 = 2;
  if (GENERIC_PHY_CanModifyAck() != false) 
  {
    BUS_RegMaskedSet(&RAC->SR0,2);
    if ((RAC->SR0 & 0x20000) == 0) 
	{
      BUS_RegMaskedSet(&RAC->SR2,0x10);
      uVar3 = RAC->SR0 & 0x20000;
    }
    BUS_RegMaskedClear(&RAC->SR0,2);
    return uVar3;
  }
  return 2;
}


void RFHAL_IEEE802154LoadAck(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_14;
  undefined4 *local_10;
  undefined4 local_c;
  
  local_10 = &local_14;
  local_14 = CONCAT31((int3)((uint)param_2 >> 8),5);
  local_c = CONCAT31((int3)((uint)param_4 >> 8),1);
  RAIL_AutoAckLoadBuffer(&local_10);
  return;
}


