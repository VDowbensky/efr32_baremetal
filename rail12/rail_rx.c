#include "rail_rx.h"



uint8_t RAIL_RxConfig(uint8_t cbToEnable,bool appendedInfoEnable)

{
  if (RAIL_RfStateGet() != RAIL_RF_STATE_RX) return RAIL_RfHalRxIntEnable(cbToEnable);
  return 2;
}



uint8_t RAIL_RxStart(uint8_t channel)

{
  bool bVar1;
  RAIL_Status_t RVar2;
  char *pcVar3;
  
  if (RFHAL_HeadedToIdle() == false) return 2;
  pcVar3 = (char *)RAILInt_SetChannelConfig(channel);
  if (pcVar3 != NULL) return (uint8_t) RAIL_RfHalRxStart(channel - *pcVar3);
  return 1;
}


