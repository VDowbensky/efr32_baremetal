#include "rail_data.h"



uint8_t RAIL_TxDataLoad(RAIL_TxData_t *txData)

{
  RFHAL_TxDataLoad();
  return;
}

uint8_t RFHAL_TxDataLoad(RAIL_TxData_t *txData)

{
  CORE_irqState_t irqState;
  uint uVar1;
  
  irqState = CORE_EnterCritical();
  _DAT_43081100 = 1;
  uVar1 = read_volatile_4(Peripherals::RAC.SR0);
  uVar1 = uVar1 & 0x10000;
  if (uVar1 == 0) {
    RADIO_TxBufferSet(txData->dataPtr,txData->dataLength,0,0);
  }
  else {
    uVar1 = 3;
  }
  _DAT_43081100 = 0;
  CORE_ExitCritical(irqState);
  return (uint8_t)uVar1;
}

RAIL_Status_t RAIL_DataConfig(RAIL_DataConfig_t *dataConfig)

{
  RFHAL_DataConfig();
  return;
}



uint16_t RAIL_WriteTxFifo(uint8_t *dataPtr, uint16_t writeLength)

{
  RFHAL_WriteTxFifo();
  return;
}



uint16_t RAIL_ReadRxFifo(uint8_t *dataPtr, uint16_t readLength)

{
  RFHAL_ReadRxFifo();
  return;
}



void RAIL_ReadRxFifoAppendedInfo(RAIL_AppendedInfo_t *appendedInfo)

{
  RFHAL_ReadRxFifoAppendedInfo();
  return;
}



uint16_t RAIL_SetTxFifoThreshold(uint16_t txThreshold)

{
  if (param_1 != 0) {
    RFHAL_SetTxFifoThreshold();
    return;
  }
  RFHAL_GetTxFifoThreshold();
  return;
}



uint16_t RAIL_SetRxFifoThreshold(uint16_t rxThreshold)

{
  if (param_1 != 0xffff) {
    RFHAL_SetRxFifoThreshold();
    return;
  }
  RFHAL_GetRxFifoThreshold();
  return;
}



uint16_t RAIL_GetTxFifoThreshold(void)

{
  RFHAL_GetTxFifoThreshold();
  return;
}



uint16_t RAIL_GetRxFifoThreshold(void)

{
  RFHAL_GetRxFifoThreshold();
  return;
}



void RAIL_EnableRxFifoThreshold(void)

{
  RFHAL_EnableRxFifoThreshold();
  return;
}



void RAIL_DisableRxFifoThreshold(void)

{
  RFHAL_DisableRxFifoThreshold();
  return;
}



uint16_t  RAIL_GetTxFifoSpaceAvailable(void)

{
  RFHAL_GetTxFifoSpaceAvailable();
  return;
}



uint16_t  RAIL_GetRxFifoBytesAvailable(void)

{
  RFHAL_GetRxFifoBytesAvailable();
  return;
}



void RAIL_ResetFifo(bool txFifo, bool rxFifo)

{
  if (param_1 != 0) {
    RFHAL_ResetTxFifo();
  }
  if (param_2 != 0) {
    RFHAL_ResetRxFifo();
    return;
  }
  return;
}


