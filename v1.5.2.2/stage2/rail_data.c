#include "rail_data.h"


uint8_t RAIL_TxDataLoad(RAIL_TxData_t *txData)

{
  CORE_irqState_t irqState;
  uint32_t state;
  uint8_t uVar2;
  
  irqState = CORE_EnterCritical();
  uVar1 = (RAC->STATUS & RAC_STATUS_STATE_Msk) >> RAC_STATUS_STATE_Pos;
  if (((state - 7 < 3) || (state == 0xc)) && ((RAC->SR0 << 0xf) < 0)) 
  {
	CORE_ExitCritical(irqState);
	return 3;
  }
  else 
  {
    BUFC->BUF0_CMD = BUFC_BUF0_CMD_CLEAR_Msk;
    BUFC_WriteBuffer(0,txData->dataPtr,txData->dataLength);
	CORE_ExitCritical(irqState);
	return 0;
  }
  
}

RAIL_Status_t RAIL_DataConfig(RAIL_DataConfig_t *dataConfig)

{
  if (dataConfig->txMethod == dataConfig->rxMethod) 
  {
    if (dataConfig->rxSource == RX_PACKET_DATA) RFHAL_DisableRxRawCapture();
    else RFHAL_EnableRxRawCapture();
	bufcEnabledCallbacks = bufcEnabledCallbacks & 0xffffff00;
    if (dataConfig->txMethod == PACKET_MODE) bufcEnabledCallbacks &= 0xfe; 
    else 
	{
      bufcEnabledCallbacks |= 1;
      RFHAL_ResetTxFifo();
    }
    if (dataConfig->rxMethod == PACKET_MODE) 
	{
	  bufcEnabledCallbacks &= 0xffffff00;
	  bufcEnabledCallbacks &= 0xfb;
      BUS_RegMaskedSet(&FRC->RXCTRL,FRC_RXCTRL_BUFRESTORERXABORTED_Msk | FRC_RXCTRL_BUFRESTOREFRAMEERROR_Msk); //0x60);
      BUS_RegMaskedClear(&RAC->SR0,0x40);
      BUS_RegMaskedClear(&FRC->RXCTRL,FRC_RXCTRL_ACCEPTCRCERRORS_Msk); //2);
    }
    else 
	{
      bufcEnabledCallbacks |= 4;
      BUS_RegMaskedClear(&FRC->RXCTRL,FRC_RXCTRL_BUFRESTORERXABORTED_Msk | FRC_RXCTRL_BUFRESTOREFRAMEERROR_Msk);
      RFHAL_ResetRxFifo();
      BUS_RegMaskedSet(&RAC->SR0,0x40);
      BUS_RegMaskedSet(&FRC->RXCTRL,FRC_RXCTRL_ACCEPTCRCERRORS_Msk);
    }
    BUFC_ConfigureCallbacks(bufcEnabledCallbacks);
    return RAIL_STATUS_NO_ERROR;
  }
  return RAIL_STATUS_INVALID_PARAMETER;
}


uint16_t RAIL_WriteTxFifo(uint8_t *dataPtr,uint16_t writeLength)

{
  if (BUFC_GetSpaceAvailable(0) <= writeLength) writeLength = BUFC_GetSpaceAvailable(0);
  BUFC_WriteBuffer(0,dataPtr,writeLength);
  return writeLength;
}



uint16_t RAIL_ReadRxFifo(uint8_t *dataPtr,uint16_t readLength)

{
  if (BUFC_GetBytesAvailable(1) <= readLength) readLength = BUFC_GetBytesAvailable(1);
  BUFC_ReadBuffer(1,dataPtr,readLength);
  return readLength;
}

 /* typedef struct RAIL_AppendedInfo {
  uint32_t timeUs;
  bool crcStatus:1;
  bool frameCodingStatus:1;
  bool isAck:1;
  int8_t rssiLatch;
  uint8_t lqi;
  uint8_t syncWordId;
} RAIL_AppendedInfo_t; */


void RAIL_ReadRxFifoAppendedInfo(RAIL_AppendedInfo_t *appendedInfo)

{
  undefined auStack28 [5];
  int8_t iStack23;
  byte bStack22;
  undefined4 uStack16;
  
  GENERIC_PHY_PacketRxAppendedInfoHelper(RADIO_RxTrailDataLength(),auStack28);
  //FRC.IEN._0_1_;

  appendedInfo->frameCodingStatus = FRC->IF ^ FRC_IF_BLOCKERROR_Msk; //0x80;
  FRC->IFC = 0x80;
  
  if (bStack22 != 0) bStack22 = 1; //CRC
  appendedInfo->crcStatus = | bStack22 & 1;
  appendedInfo->rssiLatch = iStack23;

  appendedInfo->timeUs = TIMING_GetRxTimestampUs(uStack16);
  appendedInfo->syncWordId = '\0';
}


uint16_t RAIL_SetTxFifoThreshold(uint16_t txThreshold)

{
  if (txThreshold != 0)
  {	  
	if (0x1ff < threshold) threshold = 0x200;
	BUFC->BUF0_THRESHOLDCTRL &= 0xfffff000;
	BUFC->BUF0_THRESHOLDCTRL |= (uint32_t)(threshold - 1);
  }
  return (uint16_t)((BUFC->BUF0_THRESHOLDCTRL & BUFC_BUF0_THRESHOLDCTRL_THRESHOLD_Msk) + 1);
}

void RAIL_GetTxFifoThreshold(void)

{
  return (uint16_t)((BUFC->BUF0_THRESHOLDCTRL & BUFC_BUF0_THRESHOLDCTRL_THRESHOLD_Msk) + 1);
}


uint16_t RFHAL_SetRxFifoThreshold(uint16_t threshold)

{
  if (threshold > 0x200) threshold = 0x200;
  BUFC->BUF1_THRESHOLDCTRL &= 0xfffff000;
  BUFC->BUF1_THRESHOLDCTRL |= (uint32_t)threshold ;
  return (uint16_t)(BUFC->BUF1_THRESHOLDCTRL & BUFC_BUF1_THRESHOLDCTRL_THRESHOLD_Msk);
}

uint16_t RAIL_GetRxFifoThreshold(void)

{
  return (uint16_t)(BUFC->BUF1_THRESHOLDCTRL & BUFC_BUF1_THRESHOLDCTRL_THRESHOLD_Msk);
}


void RAIL_EnableRxFifoThreshold(void)

{
  BUS_RegMaskedSet(&BUFC->IEN,0x400);
}


void RAIL_DisableRxFifoThreshold(void)

{
  BUS_RegMaskedClear(&BUFC->IEN,0x400);
}


uint16_t RAIL_GetTxFifoSpaceAvailable(void)

{
  return BUFC_GetSpaceAvailable(0);
}


uint16_t RFHAL_GetRxFifoBytesAvailable(void)

{
  return (uint16_t)BUFC_GetBytesAvailable(1);
}

void RAIL_ResetFifo(bool txFifo,bool rxFifo)

{
  if (txFifo) 
  {
	BUS_RegMaskedClear(&BUFC->IEN,BUFC_IEN_BUF0THR_Msk); //4);
	BUFC->BUF0_CMD = BUFC_BUF0_CMD_CLEAR_Msk; //1;
	BUS_RegMaskedClear(&BUFC->BUF0_THRESHOLDCTRL,BUFC_BUF0_THRESHOLDCTRL_THRESHOLDMODE_Msk); //0x2000);
	BUS_RegMaskedSet(&BUFC->IEN,BUFC_IEN_BUF0THR_Msk); //4);
  }
  if (rxFifo) 
  {  
	BUS_RegMaskedClear(&BUFC->IEN,BUFC_IEN_BUF1THR_Msk); //0x400);
	BUFC->BUF1_CMD = BUFC_BUF1_CMD_CLEAR_Msk; //1;
	BUS_RegMaskedClear(&BUFC->BUF1_THRESHOLDCTRL,BUFC_BUF1_THRESHOLDCTRL_THRESHOLDMODE_Msk); //0x2000);
	BUS_RegMaskedSet(&BUFC->IEN,BUFC_IEN_BUF1THR_Msk); //0x400);
  }
}



