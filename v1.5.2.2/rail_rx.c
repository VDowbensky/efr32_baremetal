#include "rail_rx.h"



uint8_t RAIL_RxConfig(uint32_t cbToEnable,bool appendedInfoEnable)

{
  uint8_t uVar1;
  
  if (appendedInfoEnable == false) {
    RFHAL_DisableRxAppendedInfo();
  }
  else {
    RFHAL_EnableRxAppendedInfo();
  }
  uVar1 = RFHAL_RxIntEnable(cbToEnable);
  return uVar1;
}


/* void RAIL_SetRxOptions(void)

{
  RFHAL_SetRxOptions();
  return;
}
 */
RAIL_Status_t RAIL_SetRxOptions(uint32_t options)

{
  uint uVar1;
  RAIL_Status_t RVar2;
  
  uVar1 = (RAC->STATUS);
  if ((uVar1 << 4) >> 0x1c == 3) {
    return RAIL_STATUS_INVALID_STATE;
  }
  RVar2 = (RAIL_Status_t)(options & 1);
  if ((options & 1) == 0) {
    BUS_RegMaskedClear(&FRC->RXCTRL,1);
  }
  else {
    RVar2 = RAIL_STATUS_NO_ERROR;
    BUS_RegMaskedSet(&FRC->RXCTRL,1);
  }
  return RVar2;
}



uint8_t RAIL_RxStart(uint8_t channel)

{
  uint8_t uVar1;
  
  uVar1 = RAILInt_SetChannel(channel);
  if (uVar1 == '\0') {
    uVar1 = RFHAL_RxStart(channel);
    return uVar1;
  }
  return uVar1;
}


uint8_t RAIL_ScheduleRx(uint8_t channel,RAIL_ScheduleRxConfig_t *cfg)

{
  RAIL_RadioState_t RVar1;
  uint8_t uVar2;
  
  RVar1 = RAIL_RfStateGet();
  if (RVar1 == RAIL_RF_STATE_IDLE) {
    uVar2 = RAILInt_SetChannel(channel);
    if (uVar2 == '\0') {
      RFHAL_ScheduleRx(channel,cfg);
      return channel;
    }
  }
  else {
    uVar2 = '\x02';
  }
  return uVar2;
}



void RAILCb_RxRadioStatus(void)

{
  return;
}



void RAILCb_RxRadioStatusExt(char param_1)

{
  if (param_1 != '\0') {
    RAILCb_RxRadioStatus();
  }
  return;
}


