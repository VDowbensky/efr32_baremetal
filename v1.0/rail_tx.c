#include "rail_tx.h"



void RAIL_TxConfig(void)

{
  RFHAL_TxIntEnable();
  return;
}



int RAIL_TxStartWithOptions
              (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = RFHAL_OkToTransmit();
  if (iVar1 == 0) {
    iVar1 = 2;
  }
  else {
    iVar1 = RAILInt_SetChannel(param_1);
    if (iVar1 == 0) {
      iVar1 = RFHAL_TxStart(param_1,param_2,param_3,param_4);
      return iVar1;
    }
  }
  return iVar1;
}



void RAIL_TxStart(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  RAIL_TxStartWithOptions(param_1,0,param_2,param_3);
  return;
}



int RAIL_TxToneStart(void)

{
  int iVar1;
  
  iVar1 = RAILInt_SetChannel();
  if (iVar1 == 0) {
    RFHAL_StartCWTestMode();
  }
  return iVar1;
}



undefined4 RAIL_TxToneStop(void)

{
  RFHAL_StopTestMode();
  return 0;
}



int RAIL_TxStreamStart(undefined4 param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 1) {
    iVar1 = RAILInt_SetChannel();
    if (iVar1 == 0) {
      RFHAL_StartStreamTestMode();
    }
    return iVar1;
  }
  return 1;
}



undefined4 RAIL_TxStreamStop(void)

{
  RFHAL_StopTestMode();
  return 0;
}



void RAIL_TxPowerSet(void)

{
  RFHAL_SetCurrPowerLevel();
  return;
}



void RAIL_TxPowerGet(void)

{
  RFHAL_GetCurrPowerLevel();
  return;
}


