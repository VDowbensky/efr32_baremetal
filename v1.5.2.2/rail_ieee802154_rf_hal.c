#include "rail_ieee802154_rf_hal.h"



uint32_t RFHAL_802154SetPhyforChan(uint32_t channel)

{
  byte bVar1;
  undefined1 *radioConfig;
  
  if (channel == 0xd) {
    radioConfig = &ieee802154_config_2415MHz_min;
  }
  else {
    radioConfig = &ieee802154_config_base_min;
    if (channel == 0xe) {
      radioConfig = &ieee802154_config_2420MHz_min;
    }
  }
  if (radioConfig != prevRadioCfg) {
    bVar1 = RAIL_RadioConfig(&ieee802154_config_base_min);
    channel = (uint32_t)bVar1;
    if (radioConfig != &ieee802154_config_base_min) {
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
  uVar1 = (SEQ->REG000);
  write_volatile_4(SEQ->REG000,uVar1 | 0x80);
  CORE_ExitCritical(irqState);
  return (bool)((byte)uVar1 >> 7);
}

void RFHAL_IEEE802154Disable(void)

{
  RFHAL_SetProtocolSpecificChCheckCB(0);
  GENERIC_PHY_DisableIEEE802154();
  return;
}



/* void RFHAL_IEEE802154IsEnabled(void)

{
  GENERIC_PHY_IsEnabledIEEE802154();
  return;
}
 */
bool RFHAL_IEEE802154IsEnabled(void)

{
  uint uVar1;
  
  uVar1 = (SEQ->REG000);
  return (bool)((byte)uVar1 >> 7);
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
  uVar1 = GENERIC_PHY_SetIeeePanId(1,local_c,in_r2,in_r3,panId);
  return (bool)uVar1;
}




bool RFHAL_IEEE802154SetShortAddress(uint16_t shortAddr)

{
  bool bVar1;
  
  bVar1 = GENERIC_PHY_SetIeeeShortAddress(1);
  return bVar1;
}



bool RFHAL_IEEE802154SetLongAddress(uint8_t *longAddr)

{
  bool bVar1;
  
  bVar1 = GENERIC_PHY_SetIeeeLongAddress(1,longAddr);
  return bVar1;
}



RAIL_Status_t RFHAL_IEEE802154SetPromiscuousMode(bool enable)

{
  CORE_irqState_t irqState;
  uint uVar1;
  
  irqState = CORE_EnterCritical();
  uVar1 = (SEQ->REG000);
  if (enable == false) {
    uVar1 = uVar1 & 0xfffeffff;
  }
  else {
    uVar1 = uVar1 | 0x10000;
  }
  write_volatile_4(SEQ->REG000,uVar1);
  CORE_ExitCritical(irqState);
  return RAIL_STATUS_NO_ERROR;
}



RAIL_Status_t RFHAL_IEEE802154SetPanCoordinator(bool isPanCoordinator)

{
  CORE_irqState_t irqState;
  uint uVar1;
  
  irqState = CORE_EnterCritical();
  uVar1 = (SEQ->REG000);
  if (isPanCoordinator == false) {
    uVar1 = uVar1 & 0xff7fffff;
  }
  else {
    uVar1 = uVar1 | 0x800000;
  }
  write_volatile_4(SEQ->REG000,uVar1);
  CORE_ExitCritical(irqState);
  return RAIL_STATUS_NO_ERROR;
}



RAIL_Status_t RFHAL_IEEE802154AcceptFrames(uint8_t framesMask)

{
  uint uVar1;
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  uVar1 = (SEQ->REG000);
  write_volatile_4(SEQ->REG000,uVar1 & 0xffe1ffff | (uint)framesMask << 0x11);
  CORE_ExitCritical(irqState);
  return RAIL_STATUS_NO_ERROR;
}



RAIL_Status_t RFHAL_IEEE802154SetFramePending(void)

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



RAIL_Status_t
RFHAL_IEEE802154LoadAck(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  RAIL_Status_t RVar1;
  undefined4 local_14;
  undefined8 local_10;
  
  local_10._0_4_ = &local_14;
  local_14 = CONCAT31((int3)((uint)param_2 >> 8),5);
  local_10._4_4_ = CONCAT31((int3)((uint)param_4 >> 8),1);
  RVar1 = RAIL_AutoAckLoadBuffer((RAIL_AutoAckData_t *)&local_10);
  return RVar1;
}



