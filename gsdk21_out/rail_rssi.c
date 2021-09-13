#include "rail_rssi.h"



void RAILCore_GetRssi(void)

{
  RFHAL_GetRssi();
  return;
}



void RAILCore_StartAverageRssi(void)

{
  RFHAL_StartAverageRssi();
  return;
}



void RAIL_GetAverageRssi(int param_1)

{
  RFHAL_GetAverageRssi(param_1 + 0xc);
  return;
}



int RAIL_IsAverageRssiReady(int param_1)

{
  int iVar1;
  
  iVar1 = RFHAL_GetAverageRssi(param_1 + 0xc);
  if (iVar1 != 0) {
    iVar1 = 1;
  }
  return iVar1;
}



void RAILCore_GetRadioEntropy(void)

{
  RFHAL_GetRadioEntropy();
  return;
}



void RAILCore_StartRfSense(void)

{
  RFHAL_StartRfSense();
  return;
}



void RAILCore_IsRfSensed(void)

{
  RFHAL_IsRfSensed();
  return;
}


