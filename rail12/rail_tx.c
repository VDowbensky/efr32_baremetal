#include "rail_tx.h"



uint8_t RAIL_TxDataLoad(RAIL_TxData_t *txData)

{
  uint uStack16;
  uint8_t *puStack12;
  
  uStack16 = (uint)txData & 0xffff0000 | (uint)txData->dataLength;
  puStack12 = txData->dataPtr;
  GENERIC_PHY_LoadTxPacketBuffer(&uStack16);
  return '\0';
}



uint8_t RAIL_TxStart(uint8_t channel,RAIL_PreTxOp_t *preTxOp,void *preTxOpParams)

{
  bool bVar1;
  uint8_t uVar2;
  char *pcVar3;
  
  bVar1 = RFHAL_HeadedToIdle();
  if (bVar1 == false) {
    return '\x02';
  }
  pcVar3 = (char *)RAILInt_SetChannelConfig(channel);
  if (pcVar3 != (char *)0x0) {
    uVar2 = RAIL_RfHalTxStart(channel - *pcVar3,preTxOp,preTxOpParams);
    return uVar2;
  }
  return '\x01';
}


