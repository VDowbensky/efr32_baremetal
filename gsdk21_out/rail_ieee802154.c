#include "rail_ieee802154.o.h"



void RAILCore_IEEE802154_Reinit2p4(void)

{
  RFHAL_IEEE802154LoadAck();
  return;
}



void RAILCore_IEEE802154_Config2p4GHzRadio(void)

{
  RFHAL_IEEE802154RadioConfig2p4GHz();
  return;
}



void RAIL_IEEE802154_Config2p4GHzRadio(int param_1)

{
  RFHAL_IEEE802154RadioConfig2p4GHz(param_1 + 0xc);
  return;
}



undefined4 RAILCore_IEEE802154_Deinit(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = RAILCore_GetRadioState();
  if (iVar1 == 1) {
    RFHAL_IEEE802154Disable(param_1);
    return 0;
  }
  return 2;
}



void RAIL_IEEE802154_Deinit(int param_1)

{
  RAILCore_IEEE802154_Deinit(param_1 + 0xc);
  return;
}



void RAIL_IEEE802154_IsEnabled(int param_1)

{
  RFHAL_IEEE802154IsEnabled(param_1 + 0xc);
  return;
}



int RAILCore_IEEE802154_SetAddresses(undefined4 param_1,undefined2 *param_2)

{
  int iVar1;
  uint uVar2;
  undefined2 *puVar3;
  undefined2 local_44;
  undefined2 local_42;
  undefined2 local_40;
  undefined2 local_3e;
  undefined2 local_3c;
  undefined2 local_3a;
  
  memset(&local_44,0,0x24);
  if (param_2 == (undefined2 *)0x0) {
    param_2 = &local_44;
  }
  uVar2 = 0;
  local_44 = 0xffff;
  local_42 = 0xffff;
  local_40 = 0xffff;
  local_3e = 0xffff;
  local_3c = 0xffff;
  local_3a = 0xffff;
  puVar3 = param_2 + 6;
  iVar1 = 0;
  do {
    if (iVar1 == 0) {
      iVar1 = RFHAL_IEEE802154SetPanId(param_1,param_2[uVar2],uVar2 & 0xff);
      if ((iVar1 == 0) &&
         (iVar1 = RFHAL_IEEE802154SetShortAddress(param_1,param_2[uVar2 + 3],uVar2 & 0xff),
         iVar1 == 0)) {
        iVar1 = RFHAL_IEEE802154SetLongAddress(param_1,puVar3);
      }
    }
    uVar2 = uVar2 + 1;
    puVar3 = puVar3 + 4;
  } while (uVar2 != 3);
  return iVar1;
}



int RAILCore_IEEE802154_Init
              (undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *local_1c;
  undefined4 uStack24;
  undefined4 uStack20;
  
  local_1c = param_2;
  uStack24 = param_3;
  uStack20 = param_4;
  RFHAL_IEEE802154SetFeatures
            (param_1,*(undefined *)((int)param_2 + 0x1a),*(undefined *)((int)param_2 + 0x19),
             *(undefined *)(param_2 + 6),param_1);
  local_1c = (undefined4 *)param_2[3];
  uStack24 = param_2[4];
  uStack20 = param_2[5];
  RFHAL_SetStateTiming(param_1,&local_1c);
  iVar1 = RAILCore_ConfigAutoAck(param_1,param_2 + 1);
  if (((iVar1 == 0) && (iVar1 = RFHAL_IEEE802154LoadAck(param_1), iVar1 == 0)) &&
     (iVar1 = RFHAL_ConfigAddressFilter(param_1,&initialAddrConfig), iVar1 == 0)) {
    iVar1 = RFHAL_IEEE802154SetBroadcastAddresses(param_1);
  }
  RAILCore_IEEE802154_SetAddresses(param_1,*param_2);
  return iVar1;
}



void RAIL_IEEE802154_Init(int param_1)

{
  RAILCore_IEEE802154_Init(param_1 + 0xc);
  return;
}



void RAIL_IEEE802154_SetAddresses(int param_1)

{
  RAILCore_IEEE802154_SetAddresses(param_1 + 0xc);
  return;
}



undefined4 RAIL_IEEE802154_SetPanId(int param_1,undefined4 param_2,uint param_3)

{
  undefined4 uVar1;
  
  if (param_3 < 3) {
    uVar1 = RFHAL_IEEE802154SetPanId(param_1 + 0xc);
    return uVar1;
  }
  return 1;
}



undefined4 RAIL_IEEE802154_SetShortAddress(int param_1,undefined4 param_2,uint param_3)

{
  undefined4 uVar1;
  
  if (param_3 < 3) {
    uVar1 = RFHAL_IEEE802154SetShortAddress(param_1 + 0xc);
    return uVar1;
  }
  return 1;
}



undefined4 RAIL_IEEE802154_SetLongAddress(int param_1,undefined4 param_2,uint param_3)

{
  undefined4 uVar1;
  
  if (param_3 < 3) {
    uVar1 = RFHAL_IEEE802154SetLongAddress(param_1 + 0xc);
    return uVar1;
  }
  return 1;
}



undefined4 RAIL_IEEE802154_SetPanCoordinator(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = RFHAL_IEEE802154IsEnabled(param_1 + 0xc);
  if (iVar1 != 0) {
    uVar2 = RFHAL_IEEE802154SetPanCoordinator(param_1 + 0xc,param_2);
    return uVar2;
  }
  return 2;
}



undefined4 RAIL_IEEE802154_SetPromiscuousMode(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = RFHAL_IEEE802154IsEnabled(param_1 + 0xc);
  if (iVar1 != 0) {
    uVar2 = RFHAL_IEEE802154SetPromiscuousMode(param_1 + 0xc,param_2);
    return uVar2;
  }
  return 2;
}



undefined4 RAIL_IEEE802154_AcceptFrames(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = RFHAL_IEEE802154IsEnabled(param_1 + 0xc);
  if (iVar1 != 0) {
    uVar2 = RFHAL_IEEE802154AcceptFrames(param_1 + 0xc,param_2);
    return uVar2;
  }
  return 2;
}



void RAIL_IEEE802154_SetFramePending(int param_1)

{
  RFHAL_IEEE802154SetFramePending(param_1 + 0xc);
  return;
}



void RAIL_IEEE802154_GetAddress(undefined4 param_1,undefined4 param_2)

{
  RFHAL_IEEE802154GetAddress(param_2);
  return;
}


