#include "bufc.h"

uint32_t currentCallbacks; //???

uint32_t enabledCallbacks;
uint32_t availableCallbacks;
uint32_t bufcPendRxFrameError;
uint8_t BUFC_TxAckBuffer[64];
uint8_t BUFC_TxBuffer[512];
uint8_t BUFC_RxLengthBuffer[64];


void BUFC_SetCallbacks(uint32_t cb)

{
  uint32_t i;
  availableCallbacks = 0;
  if (cb != 0) 
  {
	for(i = 0; i < 4; i++)
	{
      if (*(int32_t *)(cb + i * 4) != 0) availableCallbacks |= 1 << (i & 0xff);
    }
  }
  currentCallbacks = cb;
  NVIC_EnableIRQ(BUFC_IRQn); //???
  NVIC_DisableIRQ(BUFC_IRQn);
  NVIC_ClearPendingIRQ(BUFC_IRQn);
}



void BUFC_ConfigureCallbacks(uint32_t cb)

{
  uint32_t flags;
  uint32_t cbtoset;
  
  enabledCallbacks = cb & availableCallbacks;
  cbtoset = 0x90e0a09;
  //if (enabledCallbacks & 0x01) cbtoset = 0x90e0a0d; //27,24,19,18,17,11,9,3,2,0
  if (enabledCallbacks & 0x01) cbtoset = BUFC_IEN_BUF3CORR_Msk | BUFC_IEN_BUF3OF_Msk | BUFC_IEN_BUF2CORR_Msk | BUFC_IEN_BUF2THR_Msk | BUFC_IEN_BUF2UF_Msk | BUFC_IEN_BUF1CORR_Msk | BUFC_IEN_BUF1UF_Msk | BUFC_IEN_BUF0CORR_Msk | BUFC_IEN_BUF0UF_Msk |  BUFC_IEN_BUF0OF_Msk);
  if (enabledCallbacks & 0x02) cbtoset |= BUFC_IEN_BUF0OF_Msk; //1;
  if (enabledCallbacks & 0x04) cbtoset |= BUFC_IEN_BUF1THR_Msk; //0x400;
  if (enabledCallbacks & 0x08) cbtoset |= BUFC_IEN_BUF1UF_Msk; //0x200;

  flags = BUFC->IEN & (cbtoset ^ BUFC->IEN);
  flags = (BUFC->IEN ^ cbtoset) & BUFC->IEN;
  BUS_RegMaskedClear(&BUFC->IEN,flags);
  BUFC->IFC = flags;
  cbtoset &= (cbtoset ^ BUFC->IEN);
  BUFC->IFC = cbtoset;
  BUS_RegMaskedSet(&BUFC->IEN,cbtoset);
}



void BUFC_WriteBuffer(uint32_t bufnum,uint8_t *src,uint32_t len )

{
  uint32_t i;
  if (len == 0) return;
  for(i = 1; i < len; i++)
  {
	(&BUFC->BUF0_WRITEDATA)[bufnum * 0xc] = (uint32_t)*src;
	src++;
  }
}



void BUFC_ReadBuffer(uint32_t bufnum,uint8_t *dest,uint32_t len)

{
  uint32_t i;
  
  if (len == 0) return;
  for(i = 0; i < len; i++)
  {
	*dest = (uint8_t)(&BUFC->BUF0_READDATA)[bufnum * 0xc];
	dest++;
  }
}



uint32_t BUFC_GetSpaceAvailable(int32_t bufnum)

{
  return 0x200 - ((&BUFC->BUF0_STATUS)[bufnum * 0xc] & 0x1fff) & 0xffff;
}



uint32_t BUFC_GetBytesAvailable(int32_t bufnum)

{
  return (&BUFC->BUF0_STATUS)[bufnum * 0xc] & 0x1fff;
}



void BUFC_TxAckBufferSet(uint8_t *src,uint32_t len)

{
  CORE_irqState_t irqState;
  
  BUFC->BUF3_CMD = BUFC_BUF3_CMD_CLEAR_Msk; //1;
  irqState = CORE_EnterCritical();
  BUFC_WriteBuffer(3,*src,len);
  CORE_ExitCritical(irqState);
  BUFC->BUF3_CMD = 4;
}



void BUFC_TxAckBufferReset(void)

{
  BUFC_TxAckBufferSet(0,0);
}



uint32_t BUFC_TxAckBufferBytesAvailable(void)

{
  return BUFC->BUF3_STATUS & 0x1fff;
}



void BUFC_RxBufferSet(uint32_t addr)

{
  if (param_1 != 0) BUS_RegMaskedSet(&BUFC->IEN,BUFC_IEN_BUF1THR_Msk); //0x400);
  bufcRxStreaming._0_2_ = 0;
  bufcRxStreaming._4_4_ = addr;
}



uint32_t BUFC_RxBufferGet(void)

{
  return bufcRxStreaming._4_4_;
}



void BUFC_RxBufferReset(void)

{
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  bufcRxStreaming._0_2_ = 0;
  BUFC->BUF1_CMD = BUFC_BUF1_CMD_CLEAR_Msk; //1;
  BUFC->BUF2_CMD = BUFC_BUF2_CMD_CLEAR_Msk; //1;
  FRC->IFC = FRC_IFC_RXDONE_Msk; //0x10;
  CORE_ExitCritical(irqState);
}


void BUFC_Init(void)

{
  BUFC->BUF1_CTRL = 3;
  BUFC->BUF1_ADDR = (uint32_t)BUFC_RxBuffer;
  BUFC->BUF1_THRESHOLDCTRL = 0xfff;
  BUFC->BUF0_CTRL = 3;
  BUFC->BUF0_ADDR = (uint32_t)&BUFC_TxBuffer;
  BUFC->BUF0_THRESHOLDCTRL = 0xfff;
  BUFC->BUF2_CTRL = 0;
  BUFC->BUF2_ADDR = (uint32_t)&BUFC_RxLengthBuffer;
  BUFC->BUF2_THRESHOLDCTR = 3;
  BUFC->BUF3_CTRL = 0;
  BUFC->BUF3_ADDR = (uint32_t)&BUFC_TxAckBuffer;
  BUFC->BUF3_THRESHOLDCTRL = 0x2000;
  RADIO_FrameControlDescrBufferIdSet(0,0);
  RADIO_FrameControlDescrBufferIdSet(1,0);
  RADIO_FrameControlDescrBufferIdSet(2,1);
  RADIO_FrameControlDescrBufferIdSet(3,1);
  BUS_RegMaskedClear(&FRC->CTRL,FRC_CTRL_RXFCDMODE_Msk | FRC_CTRL_TXFCDMODE_Msk; //0xf0);
  BUS_RegMaskedSet(&FRC->CTRL,0xa0);
  RADIO_RegisterIrqCallback(3,BUFC_IrqHandler);
  NVIC_ClearPendingIRQ(BUFC_IRQn);
  NVIC_EnableIRQ(BUFC_IRQn);
  BUFC->BUF0_CMD = BUFC_BUF0_CMD_CLEAR_Msk;
  BUFC->BUF3_CMD = BUFC_BUF3_CMD_CLEAR_Msk;
  BUFC_RxBufferReset();
  BUFC_ConfigureCallbacks(0);
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void BUFC_IrqHandler(void)

{
  uint32_t flags;
  
  flags = BUFC->IF & BUFC->IEN;
  BUFC->IFC = flags;
  if ((flags & FRC_IF_TXABORTED_Msk) && (enabledCallbacks & 0x01)) 
  {
    //if (_DAT_430204b4 == 0) BUS_RegMaskedSet(&BUFC->BUF0_THRESHOLDCTRL,0x2000);
	if (!(BUF0_THRESHOLDCTRL & BUFC_BUF0_THRESHOLDCTRL_THRESHOLDMODE_Msk)) BUS_RegMaskedSet(&BUFC->BUF0_THRESHOLDCTRL,BUFC_BUF0_THRESHOLDCTRL_THRESHOLDMODE_Msk);//bit 13
    else 
	{
      BUS_RegMaskedClear(&BUFC->BUF0_THRESHOLDCTRL,BUFC_BUF0_THRESHOLDCTRL_THRESHOLDMODE_Msk);
      (**currentCallbacks)();
    }
  }
  if (flags & FRC_IF_WCNTCMP1_Msk) && (enabledCallbacks & 0x04) (*currentCallbacks[2])();
  if (flags & BUFC_IF_BUF2THR_Msk) 
  {
    //if (_DAT_430210b4 == 0) 
	if (!(BUF0_THRESHOLDCTRL & BUFC_BUF0_THRESHOLDCTRL_THRESHOLDMODE_Msk))
	{
      FRC->IFS = FRC_IFS_RXDONE_Msk;
      BUS_RegMaskedSet(&FRC->IEN,FRC_IEN_RXDONE_Msk); //0x10);
      if (bufcPendRxFrameError != 0) 
	  {
        bufcPendRxFrameError = 0;
        FRC->IFS = FRC_IFS_FRAMEERROR_Msk;
      }
      BUS_RegMaskedSet(&BUFC->BUF2_THRESHOLDCTRL,0x2000);
    }
    else 
	{
      BUS_RegMaskedClear(&FRC->IEN,FRC_IEN_RXDONE_Msk); //0x10);
      BUS_RegMaskedClear(&BUFC->BUF2_THRESHOLDCTRL,0x2000);
    }
  }
  if ((flags & 0xa0a00) != 0) 
  {
    BUFC_RxBufferReset();
    if ((flags & BUFC_IF_BUF1UF_Msk) && (enabledCallbacks & 0x08)) (*currentCallbacks[3])();
  }
  if ((flags & (BUFC_IF_BUF0CORR_Msk | BUFC_IF_BUF0OF_Msk)) != 0) 
  {
    RAC->CMD = RAC_CMD_TXDIS_Msk; //0x20;
    BUFC->BUF0_CMD = BUFC_BUF0_CMD_CLEAR_Msk; //1;
    if ((flags & BUFC_IF_BUF0OF_Msk) && (enabledCallbacks & 0x02)) (*currentCallbacks[1])();
  }
  if ((flags & 0x9000000) != 0) 
  {
    RAC->CMD = RAC_CMD_TXDIS_Msk; //0x20;
    BUFC_TxAckBufferReset();
  }
}



void BUFC_RxBufferReadBytes(undefined4 buf,undefined4 param_2)

{
  BUFC_ReadBuffer(1,buf,param_2);
}



void BUFC_RxBufferDropBytes(uint32_t param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint32_t uVar1;
  
  uVar1 = param_1;
  for (; param_1 != 0; param_1 = param_1 - 1 & 0xffff) BUFC_RxBufferReadBytes(&stack0xfffffff7,1,param_3,param_4,uVar1,param_2);
}



bool BUFC_RxBufferPacketAvailable(void)

{
  return 3 < (BUFC->BUF2_STATUS & 0x1fff);
}



uint32_t BUFC_RxBufferBytesAvailable(void)

{
  return BUFC->BUF1_STATUS & 0x1fff;
}



uint32_t BUFC_RxBufferReadByte(void)

{
  return BUFC->BUF1_READDATA & 0xff;
}



uint32_t BUFC_RxLengthBufferBytesAvailable(void)

{
  return BUFC->BUF2_STATUS & 0x1fff;
}



void BUFC_RxLengthReadNext(uint16_t *buf)

{
  if (BUFC_RxBufferPacketAvailable() == 0) 
  {
    *(undefined *)(buf + 1) = 0;
    *(undefined *)buf = 0xff;
    *(undefined *)((int32_t)buf + 1) = 0xff;
    return;
  }
  BUFC_ReadBuffer(2,buf,4);
  *buf = (uint16_t)(((uint32_t)*buf << 0x17) >> 0x17);
}



// WARNING: Could not reconcile some variable overlaps

uint32_t BUFC_RxBufferFinalizeAndGet(int32_t *buf,uint32_t len)

{
  uint32_t uVar1;
  int32_t *piVar2;
  uint32_t local_14;
  
  piVar2 = buf;
  local_14 = len;
  BUFC_RxLengthReadNext(&local_14);
  uVar1 = local_14 & 0xffff;
  if (uVar1 != 0xffff) 
  {
    BUFC_ReadBuffer(1,bufcRxStreaming._4_4_ + (uint32_t)(uint16_t)bufcRxStreaming,uVar1 - (uint16_t)bufcRxStreaming,0xffff,piVar2);
    bufcRxStreaming._0_2_ = (uint16_t)local_14;
    BUS_RegMaskedClear(&BUFC->IEN,BUFC_IEN_BUF1THR_Msk);
    *buf = bufcRxStreaming._4_4_;
  }
  return uVar1;
}


