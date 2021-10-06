#include "rail_data.h"



/* void RAIL_TxDataLoad(void)

{
  RFHAL_TxDataLoad();
  return;
}
 */
uint8_t RAIL_TxDataLoad(RAIL_TxData_t *txData)

{
  CORE_irqState_t irqState;
  uint uVar1;
  uint8_t uVar2;
  
  irqState = CORE_EnterCritical();
  uVar1 = (RAC->STATUS << 4) >> 0x1c;
  if (((uVar1 - 7 < 3) || (uVar1 == 0xc)) && ((RAC->SR0 << 0xf) < 0)) uVar2 = '\x03';
  else 
  {
    BUFC->BUF0_CMD = 1;
    BUFC_WriteBuffer(0,txData->dataPtr,txData->dataLength);
    uVar2 = '\0';
  }
  CORE_ExitCritical(irqState);
  return uVar2;
}

/* void RAIL_DataConfig(void)

{
  RFHAL_DataConfig();
  return;
}
 */
RAIL_Status_t RAIL_DataConfig(RAIL_DataConfig_t *dataConfig)

{
  if (dataConfig->txMethod == dataConfig->rxMethod) 
  {
    if (dataConfig->rxSource == RX_PACKET_DATA) RFHAL_DisableRxRawCapture();
    else RFHAL_EnableRxRawCapture();
    if (dataConfig->txMethod == PACKET_MODE) 
	{
      bufcEnabledCallbacks = bufcEnabledCallbacks & 0xffffff00 | (uint)((byte)bufcEnabledCallbacks & 0xfe);
    }
    else 
	{
      bufcEnabledCallbacks =  bufcEnabledCallbacks & 0xffffff00 | (uint)((byte)bufcEnabledCallbacks | 1);
      RFHAL_ResetTxFifo();
    }
    if (dataConfig->rxMethod == PACKET_MODE) 
	{
      bufcEnabledCallbacks = bufcEnabledCallbacks & 0xffffff00 | (uint)((byte)bufcEnabledCallbacks & 0xfb);
      BUS_RegMaskedSet(&FRC->RXCTRL,0x60);
      BUS_RegMaskedClear(&RAC->SR0,0x40);
      BUS_RegMaskedClear(&FRC->RXCTRL,2);
    }
    else 
	{
      bufcEnabledCallbacks = bufcEnabledCallbacks | 4;
      BUS_RegMaskedClear(&FRC->RXCTRL,0x60);
      RFHAL_ResetRxFifo();
      BUS_RegMaskedSet(&RAC->SR0,0x40);
      BUS_RegMaskedSet(&FRC->RXCTRL,2);
    }
    BUFC_ConfigureCallbacks(bufcEnabledCallbacks);
    return RAIL_STATUS_NO_ERROR;
  }
  return RAIL_STATUS_INVALID_PARAMETER;
}

void RAIL_WriteTxFifo(void)

{
  RFHAL_WriteTxFifo();
}



/* void RAIL_ReadRxFifo(void)

{
  RFHAL_ReadRxFifo();
  return;
} */

uint16_t RAIL_ReadRxFifo(uint8_t *dataPtr,uint16_t readLength)

{
  if (BUFC_GetBytesAvailable(1) <= readLength) readLength = BUFC_GetBytesAvailable(1);
  BUFC_ReadBuffer(1,dataPtr,readLength);
  return readLength;
}

void RAIL_ReadRxFifoAppendedInfo(void)

{
  RFHAL_ReadRxFifoAppendedInfo();
}



/* void RAIL_SetTxFifoThreshold(int param_1)

{
  if (param_1 != 0) {
    RFHAL_SetTxFifoThreshold();
    return;
  }
  RFHAL_GetTxFifoThreshold();
  return;
} */

uint16_t RAIL_SetTxFifoThreshold(uint16_t txThreshold)

{
  if (txThreshold != 0) return RFHAL_SetTxFifoThreshold(txThreshold);
  else return RFHAL_GetTxFifoThreshold();
}

uint16_t RAIL_SetRxFifoThreshold(uint16_t rxThreshold)

{
  if (rxThreshold != 0xffff) return RFHAL_SetRxFifoThreshold(rxThreshold);
  else return RFHAL_GetRxFifoThreshold();
}




/* void RAIL_GetTxFifoThreshold(void)

{
  RFHAL_GetTxFifoThreshold();
  return;
} */


uint16_t RAIL_GetTxFifoThreshold(void)

{
  return (uint16_t)(((BUFC->BUF0_THRESHOLDCTRL << 0x14) >> 0x14) + 1);
}



/* void RAIL_GetRxFifoThreshold(void)

{
  RFHAL_GetRxFifoThreshold();
  return;
} */

uint16_t RAIL_GetRxFifoThreshold(void)

{
  return (uint16_t)((BUFC->BUF1_THRESHOLDCTRL << 0x14) >> 0x14);
}

void RAIL_EnableRxFifoThreshold(void)

{
  RFHAL_EnableRxFifoThreshold();
}



void RAIL_DisableRxFifoThreshold(void)

{
  RFHAL_DisableRxFifoThreshold();
}



/* void RAIL_GetTxFifoSpaceAvailable(void)

{
  RFHAL_GetTxFifoSpaceAvailable();
  return;
} */

uint16_t RAIL_GetTxFifoSpaceAvailable(void)

{
  return BUFC_GetSpaceAvailable(0);
}

/* void RAIL_GetRxFifoBytesAvailable(void)

{
  RFHAL_GetRxFifoBytesAvailable();
  return;
} */

uint16_t RFHAL_GetRxFifoBytesAvailable(void)

{
  return (uint16_t)BUFC_GetBytesAvailable(1);
}

void RAIL_ResetFifo(bool txFifo,bool rxFifo)

{
  if (txFifo != false) RFHAL_ResetTxFifo();
  if (rxFifo != false) RFHAL_ResetRxFifo();
}


