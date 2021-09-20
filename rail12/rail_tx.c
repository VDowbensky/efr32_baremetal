#include "rail_tx.h"



uint8_t RAIL_TxDataLoad(RAIL_TxData_t *txData)

{
  uint uStack16;
  uint8_t *puStack12;
  
  uStack16 = (uint32_t)txData & 0xffff0000 | (uint)txData->dataLength;
  puStack12 = txData->dataPtr;
  GENERIC_PHY_LoadTxPacketBuffer(&uStack16);
}



uint8_t RAIL_TxStart(uint8_t channel,RAIL_PreTxOp_t *preTxOp,void *preTxOpParams)

{
  bool bVar1;
  uint8_t uVar2;
  char *pcVar3;
  
  bVar1 = RFHAL_HeadedToIdle();
  if (RFHAL_HeadedToIdle() == false) return 2;
  pcVar3 = (char *)RAILInt_SetChannelConfig(channel);
  if (pcVar3 != NULL) return RAIL_RfHalTxStart(channel - *pcVar3,preTxOp,preTxOpParams);
  return 1;
}


