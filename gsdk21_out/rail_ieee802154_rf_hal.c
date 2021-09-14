#include "rail_ieee802154_rf_hal.h"



void RFHAL_IEEE802154Enable(void)

{
  GENERIC_PHY_EnableIEEE802154();
  return;
}



void RFHAL_IEEE802154Disable(void)

{
  GENERIC_PHY_DisableIEEE802154();
  return;
}



void RFHAL_IEEE802154IsEnabled(void)

{
  GENERIC_PHY_IsEnabledIEEE802154();
  return;
}



undefined4
RFHAL_IEEE802154RadioConfig2p4GHz
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  RAILCore_ConfigChannels(param_1,&ieee802154_noncoherent_channelConfig,param_3,param_4,param_4);
  return 0;
}



int RFHAL_IEEE802154SetBroadcastAddresses
              (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 local_14;
  int local_10;
  int local_c;
  
  local_14 = CONCAT22((int16_t)((uint32_t)param_2 >> 0x10),0xffff);
  local_10 = param_3;
  local_c = param_4;
  iVar1 = GENERIC_PHY_SetIeeePanId(param_1,0,&local_14,0xffff,param_1);
  if ((iVar1 == 0) && (iVar1 = GENERIC_PHY_SetIeeeShortAddress(param_1,0,&local_14), iVar1 == 0)) {
    local_10 = iVar1;
    local_c = iVar1;
    iVar1 = GENERIC_PHY_SetIeeeLongAddress(param_1,0,&local_10);
  }
  return iVar1;
}



void RFHAL_IEEE802154SetPanId(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 local_c;
  int iStack8;
  
  local_c = param_2;
  iStack8 = param_3;
  GENERIC_PHY_SetIeeePanId(param_1,param_3 + 1U & 0xff,&local_c,param_4,param_1);
  return;
}



void RFHAL_IEEE802154SetShortAddress
               (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 local_c;
  int iStack8;
  
  local_c = param_2;
  iStack8 = param_3;
  GENERIC_PHY_SetIeeeShortAddress(param_1,param_3 + 1U & 0xff,&local_c,param_4,param_1);
  return;
}



void RFHAL_IEEE802154SetLongAddress(undefined4 param_1,undefined4 param_2,char param_3)

{
  GENERIC_PHY_SetIeeeLongAddress(param_1,param_3 + '\x01',param_2);
  return;
}



undefined4
RFHAL_IEEE802154SetPromiscuousMode
          (undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0x10000;
  }
  GENERIC_PHY_SetFeatures(param_1,0x10000,uVar1,param_4,param_4);
  return 0;
}



undefined4
RFHAL_IEEE802154SetPanCoordinator
          (undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0x800000;
  }
  GENERIC_PHY_SetFeatures(param_1,0x800000,uVar1,param_4,param_4);
  return 0;
}



undefined4
RFHAL_IEEE802154AcceptFrames(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  GENERIC_PHY_SetFeatures(param_1,0x1e0000,param_2 << 0x11,param_4,param_4);
  return 0;
}



undefined4 RFHAL_IEEE802154SetFeatures(undefined4 param_1,int param_2,int param_3,uint32_t param_4)

{
  uint32_t uVar1;
  uint32_t uVar2;
  
  uVar1 = 0x8000b0;
  if (param_2 == 0) {
    uVar1 = 0xb0;
  }
  uVar1 = (param_4 & 0xf) << 0x11 | uVar1;
  if (param_3 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0x10000;
  }
  GENERIC_PHY_SetFeatures(param_1,0x9f01b8,uVar2 | uVar1,uVar1,param_4);
  return 0;
}



uint32_t RFHAL_IEEE802154SetFramePending(void)

{
  uint32_t uVar1;
  int iVar2;
  uint32_t uVar3;
  
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
    return uVar3;
  }
  return 2;
}



void RFHAL_IEEE802154LoadAck(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_c;
  undefined4 uStack8;
  
  local_c = CONCAT31((int3)((uint32_t)param_2 >> 8),5);
  uStack8 = param_3;
  RFHAL_WriteAutoAckFifo(param_1,&local_c,1,5,param_1);
  return;
}


