#include "rail_rx.h"



//void RAIL_ConfigRxOptions(int param_1)
RAIL_Status_t RAIL_ConfigRxOptions(RAIL_Handle_t railHandle,
                                   RAIL_RxOptions_t mask,
                                   RAIL_RxOptions_t options)
{
  return RFHAL_ConfigRxOptions(railHandle + 0xc,mask,options);
}



void RAILCore_StartRx(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (RAILInt_SetChannel() == 0) RFHAL_StartRx(param_1,param_2,param_3,param_4);
}



RAIL_Status_t RAILCore_ScheduleRx(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  if (RAILCore_GetRadioState() == 1) 
  {
    if (RAILInt_SetChannel(param_1,param_2) == 0) return RFHAL_ScheduleRx(param_1,param_2,param_3);
  }
  else return RAIL_STATUS_INVALID_STATE;
}



void RAILInt_ConfigFrameTypeLength(RAIL_Handle_t railHandle)

{
  RFHAL_ConfigFrameTypeLength(railHandle + 0xc);
  return;
}


