#include "rail_rx.h"



uint8_t RAIL_RxConfig(uint8_t cbToEnable,bool appendedInfoEnable)

{
  RAIL_RadioState_t RVar1;
  uint8_t uVar2;
  
  RVar1 = RAIL_RfStateGet();
  if (RVar1 != RAIL_RF_STATE_RX) {
    uVar2 = RAIL_RfHalRxIntEnable(cbToEnable);
    return uVar2;
  }
  return '\x02';
}



uint8_t RAIL_RxStart(uint8_t channel)

{
  bool bVar1;
  RAIL_Status_t RVar2;
  char *pcVar3;
  
  bVar1 = RFHAL_HeadedToIdle();
  if (bVar1 == false) {
    return '\x02';
  }
  pcVar3 = (char *)RAILInt_SetChannelConfig(channel);
  if (pcVar3 != (char *)0x0) {
    RVar2 = RAIL_RfHalRxStart(channel - *pcVar3);
    return (uint8_t)RVar2;
  }
  return '\x01';
}


