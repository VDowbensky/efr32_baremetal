#include "bufc.h"



void BUFC_SetCallbacks(uint32_t *callbacks)

{
  uint32_t i;
  uint uVar2;
  
  uVar2 = 0;
  availableCallbacks = 0;
  if (callbacks != (uint32_t *)0x0) 
  {
    i = 0;
    do 
	{
      if (callbacks[i] != 0) uVar2 = uVar2 | 1 << (i & 0xff);
      i = i + 1;
      availableCallbacks = uVar2;
    } while (i != 4);
  }
  currentCallbacks = callbacks;
  _DAT_e000e100 = 0x80;
  _DAT_e000e180 = 0x80;
  _DAT_e000e280 = 0x80;
}


void BUFC_ConfigureCallbacks(uint32_t callbacks)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  enabledCallbacks = callbacks & availableCallbacks;
  uVar3 = 0x90e0a09;
  if ((enabledCallbacks & 1) != 0) uVar3 = 0x90e0a0d;
  if ((int)(enabledCallbacks << 0x1e) < 0) uVar3 = uVar3 | 1;
  if ((int)(enabledCallbacks << 0x1d) < 0) uVar3 = uVar3 | 0x400;
  uVar1 = (BUFC->IEN);
  if ((int)(enabledCallbacks << 0x1c) < 0) uVar3 = uVar3 | 0x200;
  uVar2 = uVar1 & (uVar3 ^ uVar1);
  BUS_RegMaskedClear(&BUFC->IEN,uVar2);
  BUFC->IFC = uVar2;
  uVar3 = uVar3 & (uVar3 ^ uVar1);
  BUFC->IFC = uVar3;
  BUS_RegMaskedSet(&BUFC->IEN,uVar3);
}



void BUFC_WriteBuffer(uint32_t buf,uint8_t *src,uint16_t len)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (uint)len;
  if (uVar1 == 0) return;
  uVar2 = uVar1 + 7 >> 3;
  switch(uVar1 & 7) 
  {
  case 1:
    break;
  case 2:
    goto switchD_0001015e_caseD_2;
  case 3:
    goto switchD_0001015e_caseD_3;
  case 4:
    goto switchD_0001015e_caseD_4;
  case 5:
    goto switchD_0001015e_caseD_5;
  case 6:
    goto switchD_0001015e_caseD_6;
  case 7:
    goto switchD_0001015e_caseD_7;
  default:
    goto switchD_0001015e_caseD_7;
  }
switchD_0001015e_caseD_1:
  (&BUFC->BUF0_WRITEDATA)[buf * 0xc] = (uint)*src;
  uVar2 = uVar2 - 1;
  if (uVar2 == 0) return;
  src = src + 1;
switchD_0001015e_caseD_7:
  (&BUFC->BUF0_WRITEDATA)[buf * 0xc] = (uint)*src;
  src = src + 1;
switchD_0001015e_caseD_7:
  (&BUFC->BUF0_WRITEDATA)[buf * 0xc] = (uint)*src;
  src = src + 1;
switchD_0001015e_caseD_6:
  (&BUFC->BUF0_WRITEDATA)[buf * 0xc] = (uint)*src;
  src = src + 1;
switchD_0001015e_caseD_5:
  (&BUFC->BUF0_WRITEDATA)[buf * 0xc] = (uint)*src;
  src = src + 1;
switchD_0001015e_caseD_4:
  (&BUFC->BUF0_WRITEDATA)[buf * 0xc] = (uint)*src;
  src = src + 1;
switchD_0001015e_caseD_3:
  (&BUFC->BUF0_WRITEDATA)[buf * 0xc] = (uint)*src;
  src = src + 1;
switchD_0001015e_caseD_2:
  (&BUFC->BUF0_WRITEDATA)[buf * 0xc] = (uint)*src;
  src = src + 1;
  goto switchD_0001015e_caseD_1;
}




void BUFC_ReadBuffer(uint32_t buf,uint8_t *dest,uint16_t len)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (uint)len;
  if (uVar1 == 0) return;
  uVar2 = uVar1 + 7 >> 3;
  switch(uVar1 & 7) 
  {
  case 1:
    break;
  case 2:
    goto switchD_000101c4_caseD_2;
  case 3:
    goto switchD_000101c4_caseD_3;
  case 4:
    goto switchD_000101c4_caseD_4;
  case 5:
    goto switchD_000101c4_caseD_5;
  case 6:
    goto switchD_000101c4_caseD_6;
  case 7:
    goto switchD_000101c4_caseD_7;
  default:
    goto switchD_000101c4_caseD_7;
  }
switchD_000101c4_caseD_1:
  *dest = (uint8_t)(&BUFC->BUF0_READDATA)[buf * 0xc];
  uVar2 = uVar2 - 1;
  if (uVar2 == 0) return;
  dest = dest + 1;
switchD_000101c4_caseD_7:
  *dest = (uint8_t)(&BUFC->BUF0_READDATA)[buf * 0xc];
  dest = dest + 1;
switchD_000101c4_caseD_7:
  *dest = (uint8_t)(&BUFC->BUF0_READDATA)[buf * 0xc];
  dest = dest + 1;
switchD_000101c4_caseD_6:
  *dest = (uint8_t)(&BUFC->BUF0_READDATA)[buf * 0xc];
  dest = dest + 1;
switchD_000101c4_caseD_5:
  *dest = (uint8_t)(&BUFC->BUF0_READDATA)[buf * 0xc];
  dest = dest + 1;
switchD_000101c4_caseD_4:
  *dest = (uint8_t)(&BUFC->BUF0_READDATA)[buf * 0xc];
  dest = dest + 1;
switchD_000101c4_caseD_3:
  *dest = (uint8_t)(&BUFC->BUF0_READDATA)[buf * 0xc];
  dest = dest + 1;
switchD_000101c4_caseD_2:
  *dest = (uint8_t)(&BUFC->BUF0_READDATA)[buf * 0xc];
  dest = dest + 1;
  goto switchD_000101c4_caseD_1;
}



uint16_t BUFC_GetSpaceAvailable(uint32_t buf)

{
  return 0x200 - (uint16_t)(((&BUFC->BUF0_STATUS)[buf * 0xc] << 0x13) >> 0x13);
}




uint16_t BUFC_GetBytesAvailable(uint32_t buf)

{
  return (uint16_t)(((&BUFC->BUF0_STATUS)[buf * 0xc] << 0x13) >> 0x13);
}




void BUFC_TxAckBufferSet(uint8_t *src,uint16_t len)

{
  CORE_irqState_t irqState;
  
  BUFC->BUF3_CMD = 1;
  irqState = CORE_EnterCritical();
  BUFC_WriteBuffer(3,src,len);
  CORE_ExitCritical(irqState);
  BUFC->BUF3_CMD = 4;
}



void BUFC_TxAckBufferReset(void)

{
  BUFC_TxAckBufferSet(NULL,0);
}



uint16_t BUFC_TxAckBufferBytesAvailable(void)

{
  return BUFC->BUF3_STATUS & 0x1fff;
}



void BUFC_RxBufferSet(int param_1)

{
  if (param_1 != 0) BUS_RegMaskedSet(&BUFC->IEN,0x400);
  bufcRxStreaming._0_2_ = 0;
  bufcRxStreaming._4_4_ = param_1;
}



uint32_t BUFC_RxBufferGet(void)

{
  return bufcRxStreaming._4_4_;
}



void BUFC_RxBufferReset(void)

{
  CORE_EnterCritical();
  bufcRxStreaming._0_2_ = 0;
  BUFC->BUF1_CMD = 1;
  BUFC->BUF2_CMD = 1;
  FRC->IFC = 0x10;
  CORE_ExitCritical();
}



void BUFC_Init(void)

{
  BUFC->BUF1_CTRL = 3;
  BUFC->BUF1_ADDR = BUFC_RxBuffer;
  BUFC->BUF1_THRESHOLDCTRL = 0xfff;
  BUFC->BUF0_CTRL = 3;
  BUFC->BUF0_ADDR = BUFC_TxBuffer;
  BUFC->BUF0_THRESHOLDCTRL,0xfff;
  BUFC->BUF2_CTRL = 0;
  BUFC->BUF2_ADDR = BUFC_RxLengthBuffer;
  BUFC->BUF2_THRESHOLDCTR = 3;
  BUFC->BUF3_CTRL = 0;
  BUFC->BUF3_ADDR = BUFC_TxAckBuffer;
  BUFC->BUF3_THRESHOLDCTRL = 0x2000;
  RADIO_FrameControlDescrBufferIdSet(0,0);
  RADIO_FrameControlDescrBufferIdSet(1,0);
  RADIO_FrameControlDescrBufferIdSet(2,1);
  RADIO_FrameControlDescrBufferIdSet(3,1);
  BUS_RegMaskedClear(&FRC->CTRL,0xf0);
  BUS_RegMaskedSet(&FRC->CTRL,0xa0);
  RADIO_RegisterIrqCallback(3,0x10375);
  _DAT_e000e280 = 0x80;
  _DAT_e000e100 = 0x80;
  BUFC->BUF0_CMD = 1;
  BUFC->BUF3_CMD = 1;
  BUFC_RxBufferReset();
  BUFC_ConfigureCallbacks(0);
}



void BUFC_IrqHandler(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = read_volatile_4(BUFC->IF);
  uVar2 = read_volatile_4(BUFC->IEN);
  uVar2 = uVar2 & uVar1;
  write_volatile_4(BUFC->IFC,uVar2);
  if (((int)(uVar2 << 0x1d) < 0) && ((int)((uint)(byte)enabledCallbacks << 0x1f) < 0)) {
    if (_DAT_430204b4 == 0) {
      write_volatile_4(Peripherals::BUFC_SET.BUF0_THRESHOLDCTRL,0x2000);
    }
    else {
      write_volatile_4(Peripherals::BUFC_CLR.BUF0_THRESHOLDCTRL,0x2000);
      (**currentCallbacks)();
    }
  }
  if (((int)(uVar2 << 0x15) < 0) && ((int)((uint)(byte)enabledCallbacks << 0x1d) < 0)) {
    (*currentCallbacks[2])();
  }
  if ((int)(uVar2 << 0xd) < 0) {
    if (_DAT_430210b4 == 0) {
      write_volatile_4(FRC->IFS,0x10);
      write_volatile_4(Peripherals::FRC_SET.IEN,0x10);
      if (bufcPendRxFrameError != '\0') {
        bufcPendRxFrameError = '\0';
        write_volatile_4(FRC->IFS,0x40);
      }
      write_volatile_4(Peripherals::BUFC_SET.BUF2_THRESHOLDCTR,0x2000);
    }
    else {
      write_volatile_4(Peripherals::FRC_CLR.IEN,0x10);
      write_volatile_4(Peripherals::BUFC_CLR.BUF2_THRESHOLDCTR,0x2000);
    }
  }
  if ((uVar2 & 0xa0a00) != 0) {
    BUFC_RxBufferReset();
    if (((int)(uVar2 << 0x16) < 0) && ((int)((uint)(byte)enabledCallbacks << 0x1c) < 0)) {
      (*currentCallbacks[3])();
    }
  }
  if ((uVar2 & 9) != 0) {
    write_volatile_4(Peripherals::RAC.CMD,0x20);
    write_volatile_4(BUFC->BUF0_CMD,1);
    if (((int)(uVar2 << 0x1f) < 0) && ((int)((uint)(byte)enabledCallbacks << 0x1e) < 0)) {
      (*currentCallbacks[1])();
    }
  }
  if ((uVar2 & 0x9000000) != 0) {
    write_volatile_4(Peripherals::RAC.CMD,0x20);
    BUFC_TxAckBufferReset();
    return;
  }
  return;
}



uint16_t BUFC_RxBufferReadBytes(uint8_t *dest,uint16_t len)

{
  return BUFC_ReadBuffer(1,dest,len);
}



uint16_t BUFC_RxBufferDropBytes(uint param_1,undefined4 param_2)

{
  uint16_t uVar1;
  uint uVar2;
  undefined4 uStack12;
  
  uStack12 = param_2;
  for (uVar2 = param_1; uVar2 != 0; uVar2 = uVar2 - 1 & 0xffff) 
  {
    uVar1 = BUFC_RxBufferReadBytes((uint8_t *)((int)&uStack12 + 3),1);
    param_1 = (uint)uVar1;
  }
  return param_1;
}



bool BUFC_RxBufferPacketAvailable(void)

{
  return 3 < (BUFC->BUF2_STATUS & 0x1fff);
}



uint16_t BUFC_RxBufferBytesAvailable(void)

{
  return (uint16_t)((BUFC->BUF1_STATUS << 0x13) >> 0x13);
}



uint8_t BUFC_RxBufferReadByte(void)

{
  return BUFC->BUF1_READDATA & 0xff;
}



uint16_t BUFC_RxLengthBufferBytesAvailable(void)

{
  return BUFC->BUF2_STATUS & 0x1fff;
}



void BUFC_RxLengthReadNext(uint16_t *param_1)

{
  if (BUFC_RxBufferPacketAvailable() == 0) 
  {
    *(undefined *)(param_1 + 1) = 0;
    *(undefined *)param_1 = 0xff;
    *(undefined *)((int)param_1 + 1) = 0xff;
    return;
  }
  BUFC_ReadBuffer(2,param_1,4);
  *param_1 = (ushort)(((uint)*param_1 << 0x17) >> 0x17);
}



uint BUFC_RxBufferFinalizeAndGet(int *param_1,uint param_2)

{
  uint uVar1;
  int *piVar2;
  uint local_14;
  
  piVar2 = param_1;
  local_14 = param_2;
  BUFC_RxLengthReadNext(&local_14);
  uVar1 = local_14 & 0xffff;
  if (uVar1 != 0xffff) 
  {
    BUFC_ReadBuffer(1,bufcRxStreaming._4_4_ + (uint)(ushort)bufcRxStreaming,
                    uVar1 - (ushort)bufcRxStreaming,0xffff,piVar2);
    bufcRxStreaming._0_2_ = (ushort)local_14;
    write_volatile_4(Peripherals::BUFC_CLR.IEN,0x400);
    *param_1 = bufcRxStreaming._4_4_;
  }
  return uVar1;
}


