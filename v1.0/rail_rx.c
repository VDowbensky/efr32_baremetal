#include "rail_rx.h"



uint8_t RAIL_RxConfig(uint32_t cbToEnable,bool appendedInfoEnable)

{
  _enabledCallbacks =
       CONCAT11(DAT_20002f75 & 0xe3 | (byte)(((cbToEnable << 0x1e) >> 0x1f) << 2) |
                (byte)(((cbToEnable << 0x1d) >> 0x1f) << 3) |
                (byte)(((cbToEnable << 0x1c) >> 0x1f) << 4),enabledCallbacks);
  _enabledCallbacks =
       _enabledCallbacks & 0xffff0000 | _enabledCallbacks & 0xffffff00 |
       (uint)(byte)(enabledCallbacks & 0x87 | (byte)(((cbToEnable << 0x1b) >> 0x1f) << 3) |
                    (byte)(((cbToEnable << 0x1a) >> 0x1f) << 4) |
                    (byte)(((cbToEnable << 0x15) >> 0x1f) << 5) | ((cbToEnable & 0x300) != 0) << 6);
  rxConfigEvents = cbToEnable;
  GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
  return '\0';
}



void RAIL_SetRxOptions(void)

{
  RFHAL_SetRxOptions();
  return;
}



uint8_t RAIL_RxStart(uint8_t channel)

{
  bool bVar1;
  uint8_t uVar2;
  
  bVar1 = RFHAL_HeadedToIdle();
  if (bVar1 == false) {
    uVar2 = '\x02';
  }
  else {
    uVar2 = RAILInt_SetChannel(channel);
    if (uVar2 == '\0') {
      uVar2 = RFHAL_RxStart();
      return uVar2;
    }
  }
  return uVar2;
}



uint8_t RAIL_ScheduleRx(uint8_t channel,RAIL_ScheduleRxConfig_t *cfg)

{
  RAIL_RadioState_t RVar1;
  uint8_t uVar2;
  
  RVar1 = RAIL_RfStateGet();
  if (RVar1 == RAIL_RF_STATE_IDLE) {
    uVar2 = RAILInt_SetChannel(channel);
    if (uVar2 == '\0') {
      uVar2 = RFHAL_ScheduleRx(channel,cfg);
      return uVar2;
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


