#include "rail_rx.h"



uint8_t RAIL_RxConfig(uint32_t cbToEnable,bool appendedInfoEnable)

{
  if (appendedInfoEnable == false) RFHAL_DisableRxAppendedInfo();
  else RFHAL_EnableRxAppendedInfo();
  return RFHAL_RxIntEnable(cbToEnable);
}


/* void RAIL_SetRxOptions(void)

{
  RFHAL_SetRxOptions();
  return;
}
 */
RAIL_Status_t RAIL_SetRxOptions(uint32_t options)

{
  RAIL_Status_t RVar2;
  
  if ((RAC->STATUS << 4) >> 0x1c == 3) return RAIL_STATUS_INVALID_STATE;
  RVar2 = (RAIL_Status_t)(options & 1);
  if ((options & 1) == 0) BUS_RegMaskedClear(&FRC->RXCTRL,1);
  else 
  {
    RVar2 = RAIL_STATUS_NO_ERROR;
    BUS_RegMaskedSet(&FRC->RXCTRL,1);
  }
  return RVar2;
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


