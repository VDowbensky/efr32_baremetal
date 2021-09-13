#include "rail_rx.h"



void RAIL_ConfigRxOptions(int param_1)

{
  RFHAL_ConfigRxOptions(param_1 + 0xc);
  return;
}



void RAILCore_StartRx(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = RAILInt_SetChannel();
  if (iVar1 == 0) {
    RFHAL_StartRx(param_1,param_2,param_3,param_4);
    return;
  }
  return;
}



int RAILCore_ScheduleRx(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = RAILCore_GetRadioState();
  if (iVar1 == 1) {
    iVar1 = RAILInt_SetChannel(param_1,param_2);
    if (iVar1 == 0) {
      iVar1 = RFHAL_ScheduleRx(param_1,param_2,param_3);
      return iVar1;
    }
  }
  else {
    iVar1 = 2;
  }
  return iVar1;
}



void RAILInt_ConfigFrameTypeLength(int param_1)

{
  RFHAL_ConfigFrameTypeLength(param_1 + 0xc);
  return;
}


