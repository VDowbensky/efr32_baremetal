#include "rail_ieee802154.h"



void RAILCore_IEEE802154_Reinit2p4(void)

{
  RFHAL_IEEE802154LoadAck();
}



void RAILCore_IEEE802154_Config2p4GHzRadio(void)

{
  RFHAL_IEEE802154RadioConfig2p4GHz();
}



//void RAIL_IEEE802154_Config2p4GHzRadio(int param_1)
RAIL_Status_t RAIL_IEEE802154_Config2p4GHzRadio(RAIL_Handle_t railHandle)
{
  return RFHAL_IEEE802154RadioConfig2p4GHz(railHandle + 0xc);
}



RAIL_Status_t RAILCore_IEEE802154_Deinit(RAIL_Handle_t railHandle)

{
  if (RAILCore_GetRadioState() == 1) 
  {
    RFHAL_IEEE802154Disable();
    return 0;
  }
  return 2;
}



//void RAIL_IEEE802154_Deinit(int param_1)
RAIL_Status_t RAIL_IEEE802154_Deinit(RAIL_Handle_t railHandle)
{
  return RAILCore_IEEE802154_Deinit(railHandle + 0xc);
}



//void RAIL_IEEE802154_IsEnabled(int param_1)
bool RAIL_IEEE802154_IsEnabled(RAIL_Handle_t railHandle)
{
  return RFHAL_IEEE802154IsEnabled(railHandle + 0xc);
}



int RAILCore_IEEE802154_SetAddresses(RAIL_Handle_t railHandle,undefined2 *param_2)

{
  int iVar1;
  uint32_t uVar2;
  undefined2 *puVar3;
  undefined2 local_44;
  undefined2 local_42;
  undefined2 local_40;
  undefined2 local_3e;
  undefined2 local_3c;
  undefined2 local_3a;
  
  memset(&local_44,0,0x24);
  if (param_2 == NULL) param_2 = &local_44;
  uVar2 = 0;
  local_44 = 0xffff;
  local_42 = 0xffff;
  local_40 = 0xffff;
  local_3e = 0xffff;
  local_3c = 0xffff;
  local_3a = 0xffff;
  puVar3 = param_2 + 6;
  iVar1 = 0;
  do 
  {
    if (iVar1 == 0) 
	{
      iVar1 = RFHAL_IEEE802154SetPanId(railHandle,param_2[uVar2],uVar2 & 0xff);
      if ((iVar1 == 0) && (iVar1 = RFHAL_IEEE802154SetShortAddress(railHandle,param_2[uVar2 + 3],uVar2 & 0xff),iVar1 == 0)) iVar1 = RFHAL_IEEE802154SetLongAddress(railHandle,puVar3);
    }
    uVar2 ++;
    puVar3 = puVar3 + 4;
  } while (uVar2 != 3);
  return iVar1;
}



//RAIL_Status_t RAILCore_IEEE802154_Init
//              (RAIL_Handle_t railHandle,undefined4 *param_2,undefined4 param_3,undefined4 param_4)
RAIL_Status_t RAILCore_IEEE802154_Init(RAIL_Handle_t railHandle,
                                   const RAIL_IEEE802154_Config_t *fifteenFourConfig)
{
  int iVar1;
  undefined4 *local_1c;
  undefined4 uStack24;
  undefined4 uStack20;
  
  local_1c = param_2;
  uStack24 = param_3;
  uStack20 = param_4;
  RFHAL_IEEE802154SetFeatures
            (railHandle,*(undefined *)((int)param_2 + 0x1a),*(undefined *)((int)param_2 + 0x19),
             *(undefined *)(param_2 + 6),railHandle);
  local_1c = (undefined4 *)param_2[3];
  uStack24 = param_2[4];
  uStack20 = param_2[5];
  RFHAL_SetStateTiming(railHandle,&local_1c);
  iVar1 = RAILCore_ConfigAutoAck(railHandle,param_2 + 1);
  if (((iVar1 == 0) && (iVar1 = RFHAL_IEEE802154LoadAck(railHandle), iVar1 == 0)) && (iVar1 = RFHAL_ConfigAddressFilter(railHandle,&initialAddrConfig), iVar1 == 0)) 
  {
    iVar1 = RFHAL_IEEE802154SetBroadcastAddresses(railHandle);
  }
  RAILCore_IEEE802154_SetAddresses(railHandle,*param_2);
  return iVar1;
}



//void RAIL_IEEE802154_Init(int param_1)
RAIL_Status_t RAIL_IEEE802154_Init(RAIL_Handle_t railHandle,
                                   const RAIL_IEEE802154_Config_t *fifteenFourConfig)
{
  return RAILCore_IEEE802154_Init(railHandle + 0xc, &fifteenFourConfig);
}



//void RAIL_IEEE802154_SetAddresses(int param_1)
RAIL_Status_t RAIL_IEEE802154_SetAddresses(RAIL_Handle_t railHandle,
                                           const RAIL_IEEE802154_AddrConfig_t *addresses)
{
  return RAILCore_IEEE802154_SetAddresses(railHandle + 0xc);
}



//undefined4 RAIL_IEEE802154_SetPanId(int param_1,undefined4 param_2,uint32_t param_3)
RAIL_Status_t RAIL_IEEE802154_SetPanId(RAIL_Handle_t railHandle,
                                       uint16_t panId,
                                       uint8_t index)
{
  if (param_3 < 3) return RFHAL_IEEE802154SetPanId(railHandle + 0xc);
  return 1;
}



//undefined4 RAIL_IEEE802154_SetShortAddress(int param_1,undefined4 param_2,uint32_t param_3)
RAIL_Status_t RAIL_IEEE802154_SetShortAddress(RAIL_Handle_t railHandle,
                                              uint16_t int16_tAddr,
                                              uint8_t index)
{
  if (param_3 < 3) return RFHAL_IEEE802154SetShortAddress(railHandle + 0xc);
  return 1;
}



//undefined4 RAIL_IEEE802154_SetLongAddress(int param_1,undefined4 param_2,uint32_t param_3)
RAIL_Status_t RAIL_IEEE802154_SetLongAddress(RAIL_Handle_t railHandle,
                                             const uint8_t *longAddr,
                                             uint8_t index)
{
  if (param_3 < 3) return RFHAL_IEEE802154SetLongAddress(railHandle + 0xc);
  return 1;
}



//undefined4 RAIL_IEEE802154_SetPanCoordinator(int param_1,undefined4 param_2)
RAIL_Status_t RAIL_IEEE802154_SetPanCoordinator(RAIL_Handle_t railHandle,
                                                bool isPanCoordinator)
{
  if (RFHAL_IEEE802154IsEnabled(param_1 + 0xc) != 0) return RFHAL_IEEE802154SetPanCoordinator(railHandle + 0xc,param_2);
  return 2;
}



//undefined4 RAIL_IEEE802154_SetPromiscuousMode(int param_1,undefined4 param_2)
RAIL_Status_t RAIL_IEEE802154_SetPromiscuousMode(RAIL_Handle_t railHandle,
                                                 bool enable)
{
  if (RFHAL_IEEE802154IsEnabled(railHandle + 0xc) != 0) return RFHAL_IEEE802154SetPromiscuousMode(railHandle + 0xc,param_2);
  return 2;
}



//undefined4 RAIL_IEEE802154_AcceptFrames(int param_1,undefined4 param_2)
RAIL_Status_t RAIL_IEEE802154_AcceptFrames(RAIL_Handle_t railHandle,
                                           uint8_t framesMask)
{
  if (RFHAL_IEEE802154IsEnabled(railHandle + 0xc) != 0) return RFHAL_IEEE802154AcceptFrames(railHandle + 0xc,param_2);
  return 2;
}



//void RAIL_IEEE802154_SetFramePending(int param_1)
RAIL_Status_t RAIL_IEEE802154_SetFramePending(RAIL_Handle_t railHandle)
{
  return RFHAL_IEEE802154SetFramePending(railHandle + 0xc);
}



//void RAIL_IEEE802154_GetAddress(undefined4 param_1,undefined4 param_2)
RAIL_Status_t RAIL_IEEE802154_GetAddress(RAIL_Handle_t railHandle,
                                         RAIL_IEEE802154_Address_t *pAddress)
{
  return RFHAL_IEEE802154GetAddress(&pAddress);
}


