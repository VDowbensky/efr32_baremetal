#include "rail_ieee802154_rf_hal.h"

//prevRadioCfg;

void RFHAL_802154SetPhyforChan(int param_1)

{
  undefined *puVar1;
  
  if (param_1 == 0xd) {
    puVar1 = &ieee802154_config_2415MHz_min;
  }
  else {
    puVar1 = &ieee802154_config_base_min;
    if (param_1 == 0xe) {
      puVar1 = &ieee802154_config_2420MHz_min;
    }
  }
  if ((puVar1 != prevRadioCfg) &&
     (RAIL_RadioConfig(&ieee802154_config_base_min), puVar1 != &ieee802154_config_base_min)) {
    RAIL_RadioConfig(puVar1);
  }
  prevRadioCfg = puVar1;
  return;
}



void RFHAL_IEEE802154Enable(void)

{
  GENERIC_PHY_EnableIEEE802154();
  return;
}



void RFHAL_IEEE802154Disable(void)

{
  RFHAL_SetProtocolSpecificChCheckCB(0);
  GENERIC_PHY_DisableIEEE802154();
  return;
}



void RFHAL_IEEE802154IsEnabled(void)

{
  GENERIC_PHY_IsEnabledIEEE802154();
  return;
}



undefined4 RFHAL_IEEE802154RadioConfig2p4GHz(void)

{
  RAIL_RadioConfig(&ieee802154_config_base);
  RFHAL_SetProtocolSpecificChCheckCB(RFHAL_802154SetPhyforChan);
  prevRadioCfg = &ieee802154_config_base_min;
  return 0;
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



void RFHAL_IEEE802154SetPanId(uint param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  uint local_c;
  undefined4 uStack8;
  
  local_c = param_2 & 0xffff0000 | param_1 & 0xffff;
  uStack8 = param_3;
  GENERIC_PHY_SetIeeePanId(1,&local_c,param_3,param_4,param_1);
  return;
}



void RFHAL_IEEE802154SetShortAddress
               (uint param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  uint local_c;
  undefined4 uStack8;
  
  local_c = param_2 & 0xffff0000 | param_1 & 0xffff;
  uStack8 = param_3;
  GENERIC_PHY_SetIeeeShortAddress(1,&local_c,param_3,param_4,param_1);
  return;
}



void RFHAL_IEEE802154SetLongAddress(undefined4 param_1)

{
  GENERIC_PHY_SetIeeeLongAddress(1,param_1);
  return;
}



undefined4 RFHAL_IEEE802154SetPromiscuousMode(int param_1)

{
  uint uVar1;
  
  CORE_EnterCritical();
  uVar1 = read_volatile_4(Peripherals::SEQ.REG000);
  if (param_1 == 0) {
    uVar1 = uVar1 & 0xfffeffff;
  }
  else {
    uVar1 = uVar1 | 0x10000;
  }
  write_volatile_4(Peripherals::SEQ.REG000,uVar1);
  CORE_ExitCritical();
  return 0;
}



undefined4 RFHAL_IEEE802154SetPanCoordinator(int param_1)

{
  uint uVar1;
  
  CORE_EnterCritical();
  uVar1 = read_volatile_4(Peripherals::SEQ.REG000);
  if (param_1 == 0) {
    uVar1 = uVar1 & 0xff7fffff;
  }
  else {
    uVar1 = uVar1 | 0x800000;
  }
  write_volatile_4(Peripherals::SEQ.REG000,uVar1);
  CORE_ExitCritical();
  return 0;
}



undefined4 RFHAL_IEEE802154AcceptFrames(int param_1)

{
  uint uVar1;
  
  CORE_EnterCritical();
  uVar1 = read_volatile_4(Peripherals::SEQ.REG000);
  write_volatile_4(Peripherals::SEQ.REG000,uVar1 & 0xffe1ffff | param_1 << 0x11);
  CORE_ExitCritical();
  return 0;
}



uint RFHAL_IEEE802154SetFramePending(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = GENERIC_PHY_CanModifyAck();
  uVar3 = 2;
  if (iVar2 != 0) {
    write_volatile_4(Peripherals::RAC_SET.SR0,2);
    uVar1 = read_volatile_4(Peripherals::RAC.SR0);
    if ((uVar1 & 0x20000) == 0) {
      write_volatile_4(Peripherals::RAC_SET.SR2,0x10);
      uVar3 = uVar1 & 0x20000;
    }
    write_volatile_4(Peripherals::RAC_CLR.SR0,2);
    return uVar3;
  }
  return 2;
}



// WARNING: Could not reconcile some variable overlaps

void RFHAL_IEEE802154LoadAck
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

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


