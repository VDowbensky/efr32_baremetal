#include "rail_ieee802154_rf_hal.h"



uint32_t RFHAL_802154SetPhyforChan(uint32_t channel)

{
  byte bVar1;
  undefined1 *radioConfig;
  
  if (channel == 0xd) radioConfig = &ieee802154_config_2415MHz_min;
  else 
  {
    radioConfig = &ieee802154_config_base_min;
    if (channel == 0xe) radioConfig = &ieee802154_config_2420MHz_min;
  }
  if (radioConfig != prevRadioCfg) 
  {
    bVar1 = RAIL_RadioConfig(&ieee802154_config_base_min);
    channel = (uint32_t)bVar1;
    if (radioConfig != &ieee802154_config_base_min) 
	{
      bVar1 = RAIL_RadioConfig(radioConfig);
      channel = (uint32_t)bVar1;
    }
  }
  prevRadioCfg = radioConfig;
  return channel;
}



/* void RFHAL_IEEE802154Enable(void)

{
  GENERIC_PHY_EnableIEEE802154();
  return;
} */

bool RFHAL_IEEE802154Enable(void)

{
  uint uVar1;
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  uVar1 = SEQ->REG000;
  SEQ->REG000 |= 0x80;
  CORE_ExitCritical(irqState);
  return (bool)((byte)uVar1 >> 7);
}

void RFHAL_IEEE802154Disable(void)

{
  RFHAL_SetProtocolSpecificChCheckCB(0);
  GENERIC_PHY_DisableIEEE802154();
}



/* void RFHAL_IEEE802154IsEnabled(void)

{
  GENERIC_PHY_IsEnabledIEEE802154();
  return;
}
 */
bool RFHAL_IEEE802154IsEnabled(void)

{
  return (bool)((byte)SEQ->REG000 >> 7);
}

RAIL_Status_t RFHAL_IEEE802154RadioConfig2p4GHz(void)

{
  RAIL_RadioConfig(&ieee802154_config_base);
  RFHAL_SetProtocolSpecificChCheckCB(0x129b1);
  prevRadioCfg = &ieee802154_config_base_min;
  return RAIL_STATUS_NO_ERROR;
}



byte RFHAL_IEEE802154SetBroadcastAddresses(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  byte bVar2;
  undefined4 local_c;
  
  local_c = CONCAT22((short)((uint)param_2 >> 0x10),0xffff);
  bVar1 = GENERIC_PHY_SetIeeePanId(0,&local_c,param_3,0xffff,param_1);
  bVar2 = GENERIC_PHY_SetIeeeShortAddress(0,&local_c);
  return bVar2 & bVar1;
}



bool RFHAL_IEEE802154SetPanId(uint16_t panId)

{
  undefined uVar1;
  uint in_r1;
  undefined4 in_r2;
  undefined4 in_r3;
  uint local_c [3];
  
  local_c[0] = in_r1 & 0xffff0000 | (uint)panId;
  return GENERIC_PHY_SetIeeePanId(1,local_c,in_r2,in_r3,panId);
}




bool RFHAL_IEEE802154SetShortAddress(uint16_t shortAddr)

{
  return GENERIC_PHY_SetIeeeShortAddress(1);
}



bool RFHAL_IEEE802154SetLongAddress(uint8_t *longAddr)

{
  return GENERIC_PHY_SetIeeeLongAddress(1,longAddr);
}



RAIL_Status_t RFHAL_IEEE802154SetPromiscuousMode(bool enable)

{
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  if (enable == false) SEQ->REG000 &= 0xfffeffff;;
  else SEQ->REG000 |= 0x10000;;
  CORE_ExitCritical(irqState);
  return RAIL_STATUS_NO_ERROR;
}



RAIL_Status_t RFHAL_IEEE802154SetPanCoordinator(bool isPanCoordinator)

{
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  if (isPanCoordinator == false) SEQ->REG000 &= 0xff7fffff;
  else SEQ->REG000 |= 0x800000;;
  CORE_ExitCritical(irqState);
  return RAIL_STATUS_NO_ERROR;
}



RAIL_Status_t RFHAL_IEEE802154AcceptFrames(uint8_t framesMask)

{
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  SEQ->REG000 &= 0xffe1ffff;
  SEQ->REG000 | (uint32_t)framesMask << 0x11;
  CORE_ExitCritical(irqState);
  return RAIL_STATUS_NO_ERROR;
}



RAIL_Status_t RFHAL_IEEE802154SetFramePending(void)

{
  uint uVar3;
  
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
    return (RAIL_Status_t)uVar3;
  }
  return RAIL_STATUS_INVALID_STATE;
}



RAIL_Status_t RFHAL_IEEE802154LoadAck(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_14;
  undefined8 local_10;
  
  local_10._0_4_ = &local_14;
  local_14 = CONCAT31((int3)((uint)param_2 >> 8),5);
  local_10._4_4_ = CONCAT31((int3)((uint)param_4 >> 8),1);
  return RAIL_AutoAckLoadBuffer((RAIL_AutoAckData_t *)&local_10);
}



