#include "rail_tx.h"



RAIL_Status_t
RAILInt_PreTxOps(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (RFHAL_OkToTransmit() != 0) return RAILInt_SetChannel(param_1,param_2,param_3,param_4);
  else return RAIL_STATUS_INVALID_STATE;
}



void RAILCore_StartTx(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  if (RAILInt_PreTxOps() == RAIL_STATUS_NO_ERROR) RFHAL_StartTx(param_1,param_3);
}



void RAILCore_StartScheduledTx
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (RAILInt_PreTxOps() == RAIL_STATUS_NO_ERROR) RFHAL_StartScheduledTx(param_1,param_3,param_4);
}



//void RAIL_SetCcaThreshold(int param_1)
RAIL_Status_t RAIL_SetCcaThreshold(RAIL_Handle_t railHandle,
                                   int8_t ccaThresholdDbm)
{
  return RFHAL_SetCcaThreshold(railHandle + 0xc,ccaThresholdDbm);
}



void RAILCore_StartCcaCsmaTx
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (RAILInt_PreTxOps() == RAIL_STATUS_NO_ERROR) RFHAL_StartCcaCsmaTx(param_1,param_3,param_4);
}



void RAILCore_StartCcaLbtTx
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (RAILInt_PreTxOps() == RAIL_STATUS_NO_ERROR) RFHAL_StartCcaLbtTx(param_1,param_3,param_4);
}



int RAILCore_StartTxStream(undefined4 param_1,undefined4 param_2,uint32_t param_3)

{
  int iVar1;
  
  if (1 < param_3) return 1;
  iVar1 = RAILInt_SetChannel();
  if (RAILInt_SetChannel() == 0) 
  {
    RAILCore_Idle(1,1);
    if (param_3 == 0) 
	{
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
  return RFHAL_SetTxPower(railHandle + 0xc,power);
}



//void RAIL_GetTxPower(int param_1)
RAIL_TxPower_t RAIL_GetTxPowerDbm(RAIL_Handle_t railHandle)
{
  return RFHAL_GetTxPower(railHandle + 0xc);
}



//void RAIL_ConfigTxPower(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
RAIL_Status_t RAIL_ConfigTxPower(RAIL_Handle_t railHandle,
                                 const RAIL_TxPowerConfig_t *config)
{
  RFHAL_SetTxPower(param_1 + 0xc,0,1,param_4,param_4);
  return RFHAL_ConfigTxPower(param_1 + 0xc,param_2);
}



//void RAIL_GetTxPowerConfig(int param_1)
RAIL_Status_t RAIL_GetTxPowerConfig(RAIL_Handle_t railHandle,
                                    RAIL_TxPowerConfig_t *config)
{
  return RFHAL_GetTxPowerConfig(railHandle + 0xc,&config);
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
  return RFHAL_SetTxPower(param_1 + 0xc,RAIL_ConvertDbmToRaw(param_1,local_18 & 0xff,param_2),1);
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
  return RAIL_ConvertRawToDbm(param_1,local_18 & 0xff,uVar1);
}



void RAILCore_OverrideDebugFrequency(void)

{
  RFHAL_OverrideDebugFrequency();
}



//void RAIL_GetTxPacketDetails(int param_1)
RAIL_Status_t RAIL_GetTxPacketDetails(RAIL_Handle_t railHandle,
                                      RAIL_TxPacketDetails_t *pPacketDetails)
{
  return RFHAL_GetTxPacketDetails(param_1 + 0xc,&pPacketDetails);
}



//void RAIL_EnablePaCal(void)
void RAIL_EnablePaCal(bool enable)
{
  RFHAL_EnablePaCal(enable);
}



//void RAIL_EnableTxHoldOff(int param_1)
void RAIL_EnableTxHoldOff(RAIL_Handle_t railHandle, bool enable)
{
  RFHAL_EnableTxHoldOff(param_1 + 0xc,enable);
}



//void RAIL_IsTxHoldOffEnabled(int param_1)
bool RAIL_IsTxHoldOffEnabled(RAIL_Handle_t railHandle)
{
  return RFHAL_IsTxHoldOffEnabled(param_1 + 0xc);
}


