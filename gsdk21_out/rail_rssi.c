#include "rail_rssi.h"



//void RAILCore_GetRssi(void)
int16_t RAILCore_GetRssi(bool wait)
{
  return RFHAL_GetRssi();
}



//void RAILCore_StartAverageRssi(void)
RAIL_Status_t RAILCore_StartAverageRssi(RAIL_Handle_t railHandle,uint16_t channel,uint32_t averagingTimeUs,const RAIL_SchedulerInfo_t *schedulerInfo)
{
  return RFHAL_StartAverageRssi(railHandle,channel,averagingTimeUs,&schedulerInfo);
}



//void RAIL_GetAverageRssi(int param_1)
int16_t RAIL_GetAverageRssi(RAIL_Handle_t railHandle)
{
  return RFHAL_GetAverageRssi(param_1 + 0xc);
}



//int RAIL_IsAverageRssiReady(int param_1)
bool RAIL_IsAverageRssiReady(RAIL_Handle_t railHandle)
{
  int iVar1;
  
  iVar1 = RFHAL_GetAverageRssi(railHandle + 0xc);
  if (RFHAL_GetAverageRssi(railHandle + 0xc) != 0) iVar1 = 1;
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



bool RAILCore_IsRfSensed(void)

{
  return RFHAL_IsRfSensed();
}


