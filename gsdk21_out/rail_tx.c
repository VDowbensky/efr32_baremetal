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



//void RAIL_SetCcaThreshold(int param_1)
RAIL_Status_t RAIL_SetCcaThreshold(RAIL_Handle_t railHandle,
                                   int8_t ccaThresholdDbm)
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



int RAILCore_StartTxStream(undefined4 param_1,undefined4 param_2,uint32_t param_3)

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



//void RAIL_SetTxPower(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
RAIL_Status_t RAIL_SetTxPowerDbm(RAIL_Handle_t railHandle,
                                 RAIL_TxPower_t power)
{
  RFHAL_SetTxPower(param_1 + 0xc,param_2,1,param_4,param_4);
  return;
}



//void RAIL_GetTxPower(int param_1)
RAIL_TxPower_t RAIL_GetTxPowerDbm(RAIL_Handle_t railHandle)
{
  RFHAL_GetTxPower(param_1 + 0xc);
  return;
}



//void RAIL_ConfigTxPower(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
RAIL_Status_t RAIL_ConfigTxPower(RAIL_Handle_t railHandle,
                                 const RAIL_TxPowerConfig_t *config)
{
  RFHAL_SetTxPower(param_1 + 0xc,0,1,param_4,param_4);
  RFHAL_ConfigTxPower(param_1 + 0xc,param_2);
  return;
}



//void RAIL_GetTxPowerConfig(int param_1)
RAIL_Status_t RAIL_GetTxPowerConfig(RAIL_Handle_t railHandle,
                                    RAIL_TxPowerConfig_t *config)
{
  RFHAL_GetTxPowerConfig(param_1 + 0xc);
  return;
}



//void RAIL_SetTxPowerDbm(uint32_t param_1,undefined4 param_2)
RAIL_Status_t RAIL_SetTxPowerDbm(RAIL_Handle_t railHandle,
                                 RAIL_TxPower_t power)
{
  undefined4 uVar1;
  uint32_t local_18;
  undefined4 uStack20;
  
  local_18 = param_1;
  uStack20 = param_2;
  RAIL_GetTxPowerConfig(param_1,&local_18);
  uVar1 = RAIL_ConvertDbmToRaw(param_1,local_18 & 0xff,param_2);
  RFHAL_SetTxPower(param_1 + 0xc,uVar1,1);
  return;
}



//void RAIL_GetTxPowerDbm(uint32_t param_1,undefined4 param_2,undefined4 param_3)
RAIL_TxPower_t RAIL_GetTxPowerDbm(RAIL_Handle_t railHandle)
{
  undefined4 uVar1;
  uint32_t local_18;
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



//void RAIL_GetTxPacketDetails(int param_1)
RAIL_Status_t RAIL_GetTxPacketDetails(RAIL_Handle_t railHandle,
                                      RAIL_TxPacketDetails_t *pPacketDetails)
{
  RFHAL_GetTxPacketDetails(param_1 + 0xc);
  return;
}



//void RAIL_EnablePaCal(void)
void RAIL_EnablePaCal(bool enable)
{
  RFHAL_EnablePaCal();
  return;
}



//void RAIL_EnableTxHoldOff(int param_1)
void RAIL_EnableTxHoldOff(RAIL_Handle_t railHandle, bool enable)
{
  RFHAL_EnableTxHoldOff(param_1 + 0xc);
  return;
}



//void RAIL_IsTxHoldOffEnabled(int param_1)
bool RAIL_IsTxHoldOffEnabled(RAIL_Handle_t railHandle)
{
  RFHAL_IsTxHoldOffEnabled(param_1 + 0xc);
  return;
}


