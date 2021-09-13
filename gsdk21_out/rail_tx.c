#include "rail_tx.h"



undefined4
RAILInt_PreTxOps(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = RFHAL_OkToTransmit();
  if (iVar1 != 0) {
    uVar2 = RAILInt_SetChannel(param_1,param_2,param_3,param_4);
    return uVar2;
  }
  return 2;
}



void RAILCore_StartTx(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = RAILInt_PreTxOps();
  if (iVar1 == 0) {
    RFHAL_StartTx(param_1,param_3);
    return;
  }
  return;
}



void RAILCore_StartScheduledTx
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = RAILInt_PreTxOps();
  if (iVar1 == 0) {
    RFHAL_StartScheduledTx(param_1,param_3,param_4);
    return;
  }
  return;
}



void RAIL_SetCcaThreshold(int param_1)

{
  RFHAL_SetCcaThreshold(param_1 + 0xc);
  return;
}



void RAILCore_StartCcaCsmaTx
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = RAILInt_PreTxOps();
  if (iVar1 == 0) {
    RFHAL_StartCcaCsmaTx(param_1,param_3,param_4);
    return;
  }
  return;
}



void RAILCore_StartCcaLbtTx
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = RAILInt_PreTxOps();
  if (iVar1 == 0) {
    RFHAL_StartCcaLbtTx(param_1,param_3,param_4);
    return;
  }
  return;
}



int RAILCore_StartTxStream(undefined4 param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  
  if (1 < param_3) {
    return 1;
  }
  iVar1 = RAILInt_SetChannel();
  if (iVar1 == 0) {
    RAILCore_Idle(1,1);
    if (param_3 == 0) {
      RFHAL_StartCWTestMode();
      return 0;
    }
    RFHAL_StartStreamTestMode();
  }
  return iVar1;
}



void RAIL_SetTxPower(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  RFHAL_SetTxPower(param_1 + 0xc,param_2,1,param_4,param_4);
  return;
}



void RAIL_GetTxPower(int param_1)

{
  RFHAL_GetTxPower(param_1 + 0xc);
  return;
}



void RAIL_ConfigTxPower(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  RFHAL_SetTxPower(param_1 + 0xc,0,1,param_4,param_4);
  RFHAL_ConfigTxPower(param_1 + 0xc,param_2);
  return;
}



void RAIL_GetTxPowerConfig(int param_1)

{
  RFHAL_GetTxPowerConfig(param_1 + 0xc);
  return;
}



void RAIL_SetTxPowerDbm(uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint local_18;
  undefined4 uStack20;
  
  local_18 = param_1;
  uStack20 = param_2;
  RAIL_GetTxPowerConfig(param_1,&local_18);
  uVar1 = RAIL_ConvertDbmToRaw(param_1,local_18 & 0xff,param_2);
  RFHAL_SetTxPower(param_1 + 0xc,uVar1,1);
  return;
}



void RAIL_GetTxPowerDbm(uint param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  uint local_18;
  undefined4 uStack20;
  undefined4 uStack16;
  
  local_18 = param_1;
  uStack20 = param_2;
  uStack16 = param_3;
  RAIL_GetTxPowerConfig(param_1,&local_18);
  uVar1 = RFHAL_GetTxPower(param_1 + 0xc);
  RAIL_ConvertRawToDbm(param_1,local_18 & 0xff,uVar1);
  return;
}



void RAILCore_OverrideDebugFrequency(void)

{
  RFHAL_OverrideDebugFrequency();
  return;
}



void RAIL_GetTxPacketDetails(int param_1)

{
  RFHAL_GetTxPacketDetails(param_1 + 0xc);
  return;
}



void RAIL_EnablePaCal(void)

{
  RFHAL_EnablePaCal();
  return;
}



void RAIL_EnableTxHoldOff(int param_1)

{
  RFHAL_EnableTxHoldOff(param_1 + 0xc);
  return;
}



void RAIL_IsTxHoldOffEnabled(int param_1)

{
  RFHAL_IsTxHoldOffEnabled(param_1 + 0xc);
  return;
}


