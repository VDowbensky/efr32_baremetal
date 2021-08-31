#include "rail_rx.h"



uint8_t RAIL_RxConfig(uint32_t cbToEnable,bool appendedInfoEnable)

{
  if (appendedInfoEnable == false) RFHAL_DisableRxAppendedInfo();
  else RFHAL_EnableRxAppendedInfo();
  return RFHAL_RxIntEnable(cbToEnable);
}



RAIL_Status_t RAIL_SetRxOptions(uint32_t options)

{
  return RFHAL_SetRxOptions(options);
}



uint8_t RAIL_RxStart(uint8_t channel)

{
  uint8_t tmp;
  tmp = RAILInt_SetChannel(channel);
  if (tmp != 0) return tmp;
  else return RFHAL_RxStart(channel);
}



uint8_t RAIL_ScheduleRx(uint8_t channel, RAIL_ScheduleRxConfig_t *cfg)

{
  if (RAIL_RfStateGet() == 0) 
  {
    if (RAILInt_SetChannel(channel) == 0) return RFHAL_ScheduleRx(channel,*cfg); 
  }
  return 2;
}



void RAILCb_RxRadioStatus(uint8_t status)

{
  return;
}



void RAILCb_RxRadioStatusExt(uint32_t status)

{
  if ((status & 0xff) != 0) RAILCb_RxRadioStatus((uint8_t)(status & 0xff));
}


