#include "rail_data.h"



uint8_t RAIL_TxDataLoad(RAIL_TxData_t *txData)

{
  return RFHAL_TxDataLoad(*txData);
}



RAIL_Status_t RAIL_DataConfig(RAIL_DataConfig_t *dataConfig)

{
  return RFHAL_DataConfig(*dataConfig);
}



uint16_t RAIL_WriteTxFifo(uint8_t *dataPtr, uint16_t writeLength)

{
  return RFHAL_WriteTxFifo(*dataPtr,writeLength);
}



uint16_t RAIL_ReadRxFifo(uint8_t *dataPtr, uint16_t readLength)

{
  return RFHAL_ReadRxFifo(*dataPtr,readLength);
}



void RAIL_ReadRxFifoAppendedInfo(RAIL_AppendedInfo_t *appendedInfo)

{
  RFHAL_ReadRxFifoAppendedInfo(*appendedInfo);
}



uint16_t RAIL_SetTxFifoThreshold(uint16_t txThreshold)

{
  if (txThreshold != 0) return RFHAL_SetTxFifoThreshold(txThreshold);
  else return RFHAL_GetTxFifoThreshold();
}



uint16_t RAIL_SetRxFifoThreshold(uint16_t rxThreshold)

{
  if (rxThreshold != 0xffff) return RFHAL_SetRxFifoThreshold();
  else return RFHAL_GetRxFifoThreshold();
}



uint16_t RAIL_GetTxFifoThreshold(void)

{
  return RFHAL_GetTxFifoThreshold();
}



uint16_t RAIL_GetRxFifoThreshold(void)

{
  return RFHAL_GetRxFifoThreshold();
}



void RAIL_EnableRxFifoThreshold(void)

{
  RFHAL_EnableRxFifoThreshold();
}



void RAIL_DisableRxFifoThreshold(void)

{
  RFHAL_DisableRxFifoThreshold();
}



uint16_t RAIL_GetTxFifoSpaceAvailable(void)

{
  return RFHAL_GetTxFifoSpaceAvailable();
}



uint16_t RAIL_GetRxFifoBytesAvailable(void)

{
  return RFHAL_GetRxFifoBytesAvailable();
}



void RAIL_ResetFifo(bool txFifo,bool rxFifo)

{
  if (txFifo != false) RFHAL_ResetTxFifo();
  if (rxFifo != false) RFHAL_ResetRxFifo();
}


