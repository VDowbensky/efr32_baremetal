#include "rail_rx.h"



uint8_t RAIL_RxConfig(uint32_t cbToEnable,bool appendedInfoEnable)

{
  if (appendedInfoEnable == false) FRC->TRAILRXDATA = 0;;
  else FRC->TRAILRXDATA = 0x1b;
  return RFHAL_RxIntEnable(cbToEnable);
}



RAIL_Status_t RAIL_SetRxOptions(uint32_t options)

{
  if ((RAC->STATUS & RAC_STATUS_STATE_Msk) >> RAC_STATUS_STATE_Pos == 3) return RAIL_STATUS_INVALID_STATE;
  if ((options & 1) == 0) BUS_RegMaskedClear(&FRC->RXCTRL,FRC_RXCTRL_STORECRC_Msk); //1);
  else BUS_RegMaskedSet(&FRC->RXCTRL,FRC_RXCTRL_STORECRC_Msk); //1);
  return RAIL_STATUS_NO_ERROR;
}



uint8_t RAIL_RxStart(uint8_t channel)

{
  if (RAILInt_SetChannel(channel) == 0) return RFHAL_RxStart(channel);
  else return 2;
}


uint8_t RAIL_ScheduleRx(uint8_t channel,RAIL_ScheduleRxConfig_t *cfg)

{
  if (RAIL_RfStateGet() == RAIL_RF_STATE_IDLE) 
  {
    if (RAILInt_SetChannel(channel) == 0) 
	{
      RFHAL_ScheduleRx(channel,cfg);
      //return channel;
	  return 0;
    }
  }
  else return 2;
}



void RAILCb_RxRadioStatus(uint8_t status)

{
  return;
}



void RAILCb_RxRadioStatusExt(uint8_t status)

{
  if (status != 0) RAILCb_RxRadioStatus(status);
}


