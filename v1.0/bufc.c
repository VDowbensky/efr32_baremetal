#include "bufc.h"



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void BUFC_SetCallbacks(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  availableCallbacks = 0;
  if (param_1 != 0) {
    uVar1 = 0;
    do {
      if (*(int *)(param_1 + uVar1 * 4) != 0) {
        uVar2 = uVar2 | 1 << (uVar1 & 0xff);
      }
      uVar1 = uVar1 + 1;
      availableCallbacks = uVar2;
    } while (uVar1 != 4);
  }
  currentCallbacks = param_1;
  _DAT_e000e100 = 0x80;
  _DAT_e000e180 = 0x80;
  _DAT_e000e280 = 0x80;
  return;
}



void BUFC_ConfigureCallbacks(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  enabledCallbacks = param_1 & availableCallbacks;
  uVar3 = 0x90e0a09;
  if ((enabledCallbacks & 1) != 0) {
    uVar3 = 0x90e0a0d;
  }
  if ((int)(enabledCallbacks << 0x1e) < 0) {
    uVar3 = uVar3 | 1;
  }
  if ((int)(enabledCallbacks << 0x1d) < 0) {
    uVar3 = uVar3 | 0x400;
  }
  uVar1 = read_volatile_4(Peripherals::BUFC.IEN);
  if ((int)(enabledCallbacks << 0x1c) < 0) {
    uVar3 = uVar3 | 0x200;
  }
  uVar2 = uVar1 & (uVar3 ^ uVar1);
  write_volatile_4(Peripherals::BUFC_CLR.IEN,uVar2);
  write_volatile_4(Peripherals::BUFC.IFC,uVar2);
  uVar3 = uVar3 & (uVar3 ^ uVar1);
  write_volatile_4(Peripherals::BUFC.IFC,uVar3);
  write_volatile_4(Peripherals::BUFC_SET.IEN,uVar3);
  return;
}



void BUFC_WriteBuffer(int param_1,byte *param_2,uint param_3)

{
  uint uVar1;
  
  if (param_3 == 0) {
    return;
  }
  uVar1 = param_3 + 7 >> 3;
  switch(param_3 & 7) {
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
  (&Peripherals::BUFC.BUF0_WRITEDATA)[param_1 * 0xc] = (uint)*param_2;
  uVar1 = uVar1 - 1;
  if (uVar1 == 0) {
    return;
  }
  param_2 = param_2 + 1;
switchD_000100da_caseD_7:
  (&Peripherals::BUFC.BUF0_WRITEDATA)[param_1 * 0xc] = (uint)*param_2;
  param_2 = param_2 + 1;
switchD_000100da_caseD_7:
  (&Peripherals::BUFC.BUF0_WRITEDATA)[param_1 * 0xc] = (uint)*param_2;
  param_2 = param_2 + 1;
switchD_000100da_caseD_6:
  (&Peripherals::BUFC.BUF0_WRITEDATA)[param_1 * 0xc] = (uint)*param_2;
  param_2 = param_2 + 1;
switchD_000100da_caseD_5:
  (&Peripherals::BUFC.BUF0_WRITEDATA)[param_1 * 0xc] = (uint)*param_2;
  param_2 = param_2 + 1;
switchD_000100da_caseD_4:
  (&Peripherals::BUFC.BUF0_WRITEDATA)[param_1 * 0xc] = (uint)*param_2;
  param_2 = param_2 + 1;
switchD_000100da_caseD_3:
  (&Peripherals::BUFC.BUF0_WRITEDATA)[param_1 * 0xc] = (uint)*param_2;
  param_2 = param_2 + 1;
switchD_000100da_caseD_2:
  (&Peripherals::BUFC.BUF0_WRITEDATA)[param_1 * 0xc] = (uint)*param_2;
  param_2 = param_2 + 1;
  goto switchD_000100da_caseD_1;
}



void BUFC_ReadBuffer(int param_1,undefined *param_2,uint param_3)

{
  uint uVar1;
  
  if (param_3 == 0) {
    return;
  }
  uVar1 = param_3 + 7 >> 3;
  switch(param_3 & 7) {
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
  *param_2 = (char)(&Peripherals::BUFC.BUF0_READDATA)[param_1 * 0xc];
  uVar1 = uVar1 - 1;
  if (uVar1 == 0) {
    return;
  }
  param_2 = param_2 + 1;
switchD_00010140_caseD_7:
  *param_2 = (char)(&Peripherals::BUFC.BUF0_READDATA)[param_1 * 0xc];
  param_2 = param_2 + 1;
switchD_00010140_caseD_7:
  *param_2 = (char)(&Peripherals::BUFC.BUF0_READDATA)[param_1 * 0xc];
  param_2 = param_2 + 1;
switchD_00010140_caseD_6:
  *param_2 = (char)(&Peripherals::BUFC.BUF0_READDATA)[param_1 * 0xc];
  param_2 = param_2 + 1;
switchD_00010140_caseD_5:
  *param_2 = (char)(&Peripherals::BUFC.BUF0_READDATA)[param_1 * 0xc];
  param_2 = param_2 + 1;
switchD_00010140_caseD_4:
  *param_2 = (char)(&Peripherals::BUFC.BUF0_READDATA)[param_1 * 0xc];
  param_2 = param_2 + 1;
switchD_00010140_caseD_3:
  *param_2 = (char)(&Peripherals::BUFC.BUF0_READDATA)[param_1 * 0xc];
  param_2 = param_2 + 1;
switchD_00010140_caseD_2:
  *param_2 = (char)(&Peripherals::BUFC.BUF0_READDATA)[param_1 * 0xc];
  param_2 = param_2 + 1;
  goto switchD_00010140_caseD_1;
}



uint BUFC_GetSpaceAvailable(int param_1)

{
  return 0x200 - ((&Peripherals::BUFC.BUF0_STATUS)[param_1 * 0xc] & 0x1fff) & 0xffff;
}



uint BUFC_GetBytesAvailable(int param_1)

{
  return (&Peripherals::BUFC.BUF0_STATUS)[param_1 * 0xc] & 0x1fff;
}



void BUFC_TxAckBufferSet(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  write_volatile_4(Peripherals::BUFC.BUF3_CMD,1);
  uVar1 = CORE_EnterCritical();
  BUFC_WriteBuffer(3,param_1,param_2);
  CORE_ExitCritical(uVar1);
  write_volatile_4(Peripherals::BUFC.BUF3_CMD,4);
  return;
}



void BUFC_TxAckBufferReset(void)

{
  BUFC_TxAckBufferSet(0,0);
  return;
}



uint BUFC_TxAckBufferBytesAvailable(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::BUFC.BUF3_STATUS);
  return uVar1 & 0x1fff;
}



void BUFC_RxBufferSet(int param_1)

{
  if (param_1 != 0) {
    write_volatile_4(Peripherals::BUFC_SET.IEN,0x400);
  }
  bufcRxStreaming._0_2_ = 0;
  bufcRxStreaming._4_4_ = param_1;
  return;
}



undefined4 BUFC_RxBufferGet(void)

{
  return bufcRxStreaming._4_4_;
}



void BUFC_RxBufferReset(void)

{
  CORE_EnterCritical();
  bufcRxStreaming._0_2_ = 0;
  write_volatile_4(Peripherals::BUFC.BUF1_CMD,1);
  write_volatile_4(Peripherals::BUFC.BUF2_CMD,1);
  write_volatile_4(Peripherals::FRC.IFC,0x10);
  CORE_ExitCritical();
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void BUFC_Init(void)

{
  write_volatile_4(Peripherals::BUFC.BUF1_CTRL,3);
  write_volatile_4(Peripherals::BUFC.BUF1_ADDR,(uint)BUFC_RxBuffer);
  write_volatile_4(Peripherals::BUFC.BUF1_THRESHOLDCTRL,0xfff);
  write_volatile_4(Peripherals::BUFC.BUF0_CTRL,3);
  write_volatile_4(Peripherals::BUFC.BUF0_ADDR,(uint)&BUFC_TxBuffer);
  write_volatile_4(Peripherals::BUFC.BUF0_THRESHOLDCTRL,0xfff);
  write_volatile_4(Peripherals::BUFC.BUF2_CTRL,0);
  write_volatile_4(Peripherals::BUFC.BUF2_ADDR,(uint)&BUFC_RxLengthBuffer);
  write_volatile_4(Peripherals::BUFC.BUF2_THRESHOLDCTR,3);
  write_volatile_4(Peripherals::BUFC.BUF3_CTRL,0);
  write_volatile_4(Peripherals::BUFC.BUF3_ADDR,(uint)&BUFC_TxAckBuffer);
  write_volatile_4(Peripherals::BUFC.BUF3_THRESHOLDCTRL,0x2000);
  RADIO_FrameControlDescrBufferIdSet(0,0);
  RADIO_FrameControlDescrBufferIdSet(1,0);
  RADIO_FrameControlDescrBufferIdSet(2,1);
  RADIO_FrameControlDescrBufferIdSet(3,1);
  write_volatile_4(Peripherals::FRC_CLR.CTRL,0xf0);
  write_volatile_4(Peripherals::FRC_SET.CTRL,0xa0);
  RADIO_RegisterIrqCallback(3,BUFC_IrqHandler);
  _DAT_e000e280 = 0x80;
  _DAT_e000e100 = 0x80;
  write_volatile_4(Peripherals::BUFC.BUF0_CMD,1);
  write_volatile_4(Peripherals::BUFC.BUF3_CMD,1);
  BUFC_RxBufferReset();
  BUFC_ConfigureCallbacks(0);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void BUFC_IrqHandler(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = read_volatile_4(Peripherals::BUFC.IF);
  uVar2 = read_volatile_4(Peripherals::BUFC.IEN);
  uVar2 = uVar2 & uVar1;
  write_volatile_4(Peripherals::BUFC.IFC,uVar2);
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
      write_volatile_4(Peripherals::FRC.IFS,0x10);
      write_volatile_4(Peripherals::FRC_SET.IEN,0x10);
      if (bufcPendRxFrameError != '\0') {
        bufcPendRxFrameError = '\0';
        write_volatile_4(Peripherals::FRC.IFS,0x40);
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
    write_volatile_4(Peripherals::BUFC.BUF0_CMD,1);
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



void BUFC_RxBufferReadBytes(undefined4 param_1,undefined4 param_2)

{
  BUFC_ReadBuffer(1,param_1,param_2);
  return;
}



void BUFC_RxBufferDropBytes(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  
  uVar1 = param_1;
  for (; param_1 != 0; param_1 = param_1 - 1 & 0xffff) {
    BUFC_RxBufferReadBytes(&stack0xfffffff7,1,param_3,param_4,uVar1,param_2);
  }
  return;
}



bool BUFC_RxBufferPacketAvailable(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::BUFC.BUF2_STATUS);
  return 3 < (uVar1 & 0x1fff);
}



uint BUFC_RxBufferBytesAvailable(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::BUFC.BUF1_STATUS);
  return uVar1 & 0x1fff;
}



uint BUFC_RxBufferReadByte(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::BUFC.BUF1_READDATA);
  return uVar1 & 0xff;
}



uint BUFC_RxLengthBufferBytesAvailable(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::BUFC.BUF2_STATUS);
  return uVar1 & 0x1fff;
}



void BUFC_RxLengthReadNext(ushort *param_1)

{
  int iVar1;
  
  iVar1 = BUFC_RxBufferPacketAvailable();
  if (iVar1 == 0) {
    *(undefined *)(param_1 + 1) = 0;
    *(undefined *)param_1 = 0xff;
    *(undefined *)((int)param_1 + 1) = 0xff;
    return;
  }
  BUFC_ReadBuffer(2,param_1,4);
  *param_1 = (ushort)(((uint)*param_1 << 0x17) >> 0x17);
  return;
}



// WARNING: Could not reconcile some variable overlaps

uint BUFC_RxBufferFinalizeAndGet(int *param_1,uint param_2)

{
  uint uVar1;
  int *piVar2;
  uint local_14;
  
  piVar2 = param_1;
  local_14 = param_2;
  BUFC_RxLengthReadNext(&local_14);
  uVar1 = local_14 & 0xffff;
  if (uVar1 != 0xffff) {
    BUFC_ReadBuffer(1,bufcRxStreaming._4_4_ + (uint)(ushort)bufcRxStreaming,
                    uVar1 - (ushort)bufcRxStreaming,0xffff,piVar2);
    bufcRxStreaming._0_2_ = (ushort)local_14;
    write_volatile_4(Peripherals::BUFC_CLR.IEN,0x400);
    *param_1 = bufcRxStreaming._4_4_;
  }
  return uVar1;
}


