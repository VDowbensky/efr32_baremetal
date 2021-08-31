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
  _DAT_e000e100 = 0x80;
  _DAT_e000e180 = 0x80;
  _DAT_e000e280 = 0x80;
}



void BUFC_ConfigureCallbacks(uint32_t cb)

{
  uint32_t flags;
  uint32_t uVar3;
  
  enabledCallbacks = cb & availableCallbacks;
  uVar3 = 0x90e0a09;
  if (enabledCallbacks & 0x01) uVar3 = 0x90e0a0d;
  if (enabledCallbacks & 0x02) uVar3 |= 1;
  if (enabledCallbacks & 0x04) uVar3 |= 0x400;
  if (enabledCallbacks & 0x08) uVar3 |= 0x200;

  flags = BUFC->IEN & (uVar3 ^ BUFC->IEN);
  flags = (BUFC->IEN ^ uVar3) & BUFC->IEN;
  BUS_RegMaskedClear(&BUFC->IEN,flags);
  BUFC->IFC = flags;
  uVar3 &= (uVar3 ^ BUFC->IEN);
  BUFC->IFC = uVar3;
  BUS_RegMaskedSet(&BUFC->IEN,uVar3);
}



void BUFC_WriteBuffer(uint32_t bufnum,uint8_t *src,uint32_t param_3)

{
  uint32_t uVar1;
  
  if (param_3 == 0) return;
  uVar1 = param_3 + 7 >> 3;
  switch(param_3 & 7) 
  {
  case 1:
    break;
  case 2:
    goto switchD_000100da_caseD_2;
  case 3:
    goto switchD_000100da_caseD_3;
  case 4:
    goto switchD_000100da_caseD_4;
  case 5:
    goto switchD_000100da_caseD_5;
  case 6:
    goto switchD_000100da_caseD_6;
  case 7:
    goto switchD_000100da_caseD_7;
  default:
    goto switchD_000100da_caseD_7;
  }
switchD_000100da_caseD_1:
  (&BUFC->BUF0_WRITEDATA)[bufnum * 0xc] = (uint32_t)*src;
  uVar1--;
  if (uVar1 == 0) return;
  src++;
switchD_000100da_caseD_7:
  (&BUFC->BUF0_WRITEDATA)[bufnum * 0xc] = (uint32_t)*src;
  src++;
switchD_000100da_caseD_7:
  (&BUFC->BUF0_WRITEDATA)[bufnum * 0xc] = (uint32_t)*src;
  src++;
switchD_000100da_caseD_6:
  (&BUFC->BUF0_WRITEDATA)[bufnum * 0xc] = (uint32_t)*src;
  src++;
switchD_000100da_caseD_5:
  (&BUFC->BUF0_WRITEDATA)[bufnum * 0xc] = (uint32_t)*src;
  src++;
switchD_000100da_caseD_4:
  (&BUFC->BUF0_WRITEDATA)[bufnum * 0xc] = (uint32_t)*src;
  src++;
switchD_000100da_caseD_3:
  (&BUFC->BUF0_WRITEDATA)[bufnum * 0xc] = (uint32_t)*src;
  src++;
switchD_000100da_caseD_2:
  (&BUFC->BUF0_WRITEDATA)[bufnum * 0xc] = (uint32_t)*src;
  src++;
  goto switchD_000100da_caseD_1;
}



void BUFC_ReadBuffer(uint32_t bufnum,uint8_t *dest,uint32_t param_3)

{
  uint32_t uVar1;
  
  if (param_3 == 0) return;
  uVar1 = param_3 + 7 >> 3;
  switch(param_3 & 7) 
  {
  case 1:
    break;
  case 2:
    goto switchD_00010140_caseD_2;
  case 3:
    goto switchD_00010140_caseD_3;
  case 4:
    goto switchD_00010140_caseD_4;
  case 5:
    goto switchD_00010140_caseD_5;
  case 6:
    goto switchD_00010140_caseD_6;
  case 7:
    goto switchD_00010140_caseD_7;
  default:
    goto switchD_00010140_caseD_7;
  }
switchD_00010140_caseD_1:
  *dest = (char)(&BUFC->BUF0_READDATA)[bufnum * 0xc];
  uVar1--;
  if (uVar1 == 0) return;
  dest++;
switchD_00010140_caseD_7:
  *dest = (char)(&BUFC->BUF0_READDATA)[bufnum * 0xc];
  dest++;
switchD_00010140_caseD_7:
  *dest = (char)(&BUFC->BUF0_READDATA)[bufnum * 0xc];
  dest++;
switchD_00010140_caseD_6:
  *dest = (char)(&BUFC->BUF0_READDATA)[bufnum * 0xc];
  dest++;
switchD_00010140_caseD_5:
  *dest = (char)(&BUFC->BUF0_READDATA)[bufnum * 0xc];
  dest++;
switchD_00010140_caseD_4:
  *dest = (char)(&BUFC->BUF0_READDATA)[bufnum * 0xc];
  dest++;
switchD_00010140_caseD_3:
  *dest = (char)(&BUFC->BUF0_READDATA)[bufnum * 0xc];
  dest++;
switchD_00010140_caseD_2:
  *dest = (char)(&BUFC->BUF0_READDATA)[bufnum * 0xc];
  dest++;
  goto switchD_00010140_caseD_1;
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
  uint32_t tmp;
  
  BUFC->BUF3_CMD = 1;
  tmp = CORE_EnterCritical();
  BUFC_WriteBuffer(3,*src,len);
  CORE_ExitCritical(tmp);
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
  if (param_1 != 0) BUS_RegMaskedSet(&BUFC->IEN,0x400);
  bufcRxStreaming._0_2_ = 0;
  bufcRxStreaming._4_4_ = addr;
}



uint32_t BUFC_RxBufferGet(void)

{
  return bufcRxStreaming._4_4_;
}



void BUFC_RxBufferReset(void)

{
  uint32_t tmp;
  
  tmp = CORE_EnterCritical();
  bufcRxStreaming._0_2_ = 0;
  BUFC->BUF1_CMD = 1;
  BUFC->BUF2_CMD = 1;
  FRC->IFC = 0x10;
  CORE_ExitCritical(tmp);
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
  BUS_RegMaskedClear(&FRC->CTRL,0xf0);
  BUS_RegMaskedSet(&FRC->CTRL,0xa0);
  RADIO_RegisterIrqCallback(3,BUFC_IrqHandler);
  _DAT_e000e280 = 0x80;
  _DAT_e000e100 = 0x80;
  BUFC->BUF0_CMD = 1;
  BUFC->BUF3_CMD = 1;
  BUFC_RxBufferReset();
  BUFC_ConfigureCallbacks(0);
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void BUFC_IrqHandler(void)

{
  uint32_t flags;
  
  flags = BUFC->IF & BUFC->IEN;
  BUFC->IFC = flags;
  if ((flags & 0x04) && (enabledCallbacks & 0x01)) 
  {
    if (_DAT_430204b4 == 0) BUS_RegMaskedSet(&BUFC->BUF0_THRESHOLDCTRL,0x2000);
    else 
	{
      BUS_RegMaskedClear(&BUFC->BUF0_THRESHOLDCTRL,0x2000);
      (**currentCallbacks)();
    }
  }
  if (flags & 0x0400) && (enabledCallbacks & 0x04) (*currentCallbacks[2])();
  if (flags & 0x40000) 
  {
    if (_DAT_430210b4 == 0) 
	{
      FRC->IFS = 0x10;
      BUS_RegMaskedSet(&FRC->IEN,0x10);
      if (bufcPendRxFrameError != '\0') 
	  {
        bufcPendRxFrameError = '\0';
        FRC->IFS = 0x40;
      }
      BUS_RegMaskedSet(&BUFC->BUF2_THRESHOLDCTR,0x2000);
    }
    else 
	{
      BUS_RegMaskedClear(&FRC->IEN,0x10);
      BUS_RegMaskedClear(&BUFC->BUF2_THRESHOLDCTR,0x2000);
    }
  }
  if ((flags & 0xa0a00) != 0) 
  {
    BUFC_RxBufferReset();
    if ((flags & 0x200) && (enabledCallbacks & 0x08)) (*currentCallbacks[3])();
  }
  if ((uVar2 & 9) != 0) 
  {
    RAC->CMD = 0x20;
    BUFC->BUF0_CMD = 1;
    if ((flags & 0x01) && (enabledCallbacks & 0x02)) (*currentCallbacks[1])();
  }
  if ((uVar2 & 0x9000000) != 0) 
  {
    RAC->CMD = 0x20;
    BUFC_TxAckBufferReset();
  }
}



void BUFC_RxBufferReadBytes(undefined4 param_1,undefined4 param_2)

{
  BUFC_ReadBuffer(1,param_1,param_2);
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



void BUFC_RxLengthReadNext(ushort *param_1)

{
  int32_t iVar1;
  
  iVar1 = BUFC_RxBufferPacketAvailable();
  if (iVar1 == 0) 
  {
    *(undefined *)(param_1 + 1) = 0;
    *(undefined *)param_1 = 0xff;
    *(undefined *)((int32_t)param_1 + 1) = 0xff;
    return;
  }
  BUFC_ReadBuffer(2,param_1,4);
  *param_1 = (ushort)(((uint32_t)*param_1 << 0x17) >> 0x17);
}



// WARNING: Could not reconcile some variable overlaps

uint32_t BUFC_RxBufferFinalizeAndGet(int32_t *param_1,uint32_t param_2)

{
  uint32_t uVar1;
  int32_t *piVar2;
  uint32_t local_14;
  
  piVar2 = param_1;
  local_14 = param_2;
  BUFC_RxLengthReadNext(&local_14);
  uVar1 = local_14 & 0xffff;
  if (uVar1 != 0xffff) 
  {
    BUFC_ReadBuffer(1,bufcRxStreaming._4_4_ + (uint32_t)(ushort)bufcRxStreaming,uVar1 - (ushort)bufcRxStreaming,0xffff,piVar2);
    bufcRxStreaming._0_2_ = (ushort)local_14;
    BUS_RegMaskedClear(&BUFC->IEN,0x400);
    *param_1 = bufcRxStreaming._4_4_;
  }
  return uVar1;
}


