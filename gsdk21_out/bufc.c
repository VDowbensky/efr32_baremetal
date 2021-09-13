#include "bufc.h"



void BUFC_ReadHelper(int param_1,void *param_2,size_t param_3,uint param_4,char param_5)

{
  uint uVar1;
  void *pvVar2;
  uint uVar3;
  uint __n;
  void *__src;
  bool bVar4;
  
  uVar3 = 1 << ((&Peripherals::BUFC.BUF0_CTRL)[param_1 * 0xc] & 7) + 6;
  uVar1 = param_4 & uVar3 - 1;
  __n = uVar3 - uVar1;
  __src = (void *)((&Peripherals::BUFC.BUF0_ADDR)[param_1 * 0xc] | 0x20000000);
  pvVar2 = (void *)(uVar1 + (int)__src);
  if (__n < param_3) {
    pvVar2 = memcpy(param_2,pvVar2,__n);
    memcpy((void *)((int)pvVar2 + __n),__src,param_3 - __n);
  }
  else {
    memcpy(param_2,pvVar2,param_3);
  }
  if (param_5 != '\0') {
    uVar3 = (uVar3 | uVar3 - 1) & param_3 + param_4;
    (&Peripherals::BUFC.BUF0_READOFFSET)[param_1 * 0xc] = uVar3;
    uVar1 = (&Peripherals::BUFC.BUF0_WRITEOFFSET)[param_1 * 0xc];
    bVar4 = uVar3 != uVar1;
    if (bVar4) {
      uVar1 = 2;
    }
    if (bVar4) {
      (&Peripherals::BUFC.BUF0_CMD)[param_1 * 0xc] = uVar1;
    }
  }
  return;
}



void checkAndAddRxLenOverflowEntry(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::BUFC.IF);
  if ((int)(uVar1 << 0xf) < 0) {
    write_volatile_4(Peripherals::BUFC.IFC,0x10000);
    write_volatile_4(Peripherals::BUFC_SET.IEN,0x10000);
    uVar1 = read_volatile_4(Peripherals::BUFC.BUF1_WRITEOFFSET);
    write_volatile_4(Peripherals::BUFC.BUF2_WRITEDATA,uVar1 & 0xff);
    uVar1 = read_volatile_4(Peripherals::BUFC.BUF1_WRITEOFFSET);
    write_volatile_4(Peripherals::BUFC.BUF2_WRITEDATA,(uVar1 << 0x10) >> 0x18);
    write_volatile_4(Peripherals::BUFC.BUF2_WRITEDATA,4);
    write_volatile_4(Peripherals::BUFC.BUF2_WRITEDATA,0);
  }
  return;
}



void BUFC_SetTxBuffer(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  bool bVar2;
  
  write_volatile_4(Peripherals::BUFC.BUF0_CTRL,param_3);
  write_volatile_4(Peripherals::BUFC.BUF0_ADDR,param_1);
  CORE_EnterCritical();
  uVar1 = read_volatile_4(Peripherals::BUFC.IF);
  uVar1 = uVar1 << 0x1d;
  bVar2 = -1 < (int)uVar1;
  if (bVar2) {
    uVar1 = 4;
  }
  write_volatile_4(Peripherals::BUFC.BUF0_READOFFSET,0);
  write_volatile_4(Peripherals::BUFC.BUF0_WRITEOFFSET,param_2);
  if (bVar2) {
    write_volatile_4(Peripherals::BUFC.IFC,uVar1);
  }
  CORE_ExitCritical();
  if (param_2 != 0) {
    write_volatile_4(Peripherals::BUFC.BUF0_CMD,2);
  }
  return;
}



void BUFC_WriteBuffer(int param_1,byte *param_2,int param_3)

{
  uint uVar1;
  void *__dest;
  uint __n;
  uint uVar2;
  void *__dest_00;
  uint uVar3;
  uint __n_00;
  
  switch(param_3) {
  case 4:
    (&Peripherals::BUFC.BUF0_WRITEDATA)[param_1 * 0xc] = (uint)*param_2;
    param_2 = param_2 + 1;
  case 3:
    (&Peripherals::BUFC.BUF0_WRITEDATA)[param_1 * 0xc] = (uint)*param_2;
    param_2 = param_2 + 1;
  case 2:
    (&Peripherals::BUFC.BUF0_WRITEDATA)[param_1 * 0xc] = (uint)*param_2;
    param_2 = param_2 + 1;
  case 1:
    (&Peripherals::BUFC.BUF0_WRITEDATA)[param_1 * 0xc] = (uint)*param_2;
    return;
  case -0x452e541f:
    return;
  default:
    (&Peripherals::BUFC.BUF0_WRITEDATA)[param_1 * 0xc] = (uint)*param_2;
    (&Peripherals::BUFC.BUF0_WRITEDATA)[param_1 * 0xc] = (uint)param_2[1];
    (&Peripherals::BUFC.BUF0_WRITEDATA)[param_1 * 0xc] = (uint)param_2[2];
    (&Peripherals::BUFC.BUF0_WRITEDATA)[param_1 * 0xc] = (uint)param_2[3];
    uVar2 = (&Peripherals::BUFC.BUF0_WRITEOFFSET)[param_1 * 0xc];
    uVar3 = 1 << ((&Peripherals::BUFC.BUF0_CTRL)[param_1 * 0xc] & 7) + 6;
    uVar1 = uVar3 - 1 & uVar2;
    __n_00 = uVar3 - uVar1;
    __n = param_3 - 4;
    param_2 = param_2 + 4;
    __dest_00 = (void *)((&Peripherals::BUFC.BUF0_ADDR)[param_1 * 0xc] | 0x20000000);
    __dest = (void *)(uVar1 + (int)__dest_00);
    if (__n_00 < __n) {
      memcpy(__dest,param_2,__n_00);
      memcpy(__dest_00,param_2 + __n_00,__n - __n_00);
    }
    else {
      memcpy(__dest,param_2,__n);
    }
    (&Peripherals::BUFC.BUF0_WRITEOFFSET)[param_1 * 0xc] = __n + uVar2 & (uVar3 - 1 | uVar3);
    return;
  }
}



void BUFC_ReadBuffer(uint param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar2 = param_2;
  uVar3 = param_3;
  do {
    uVar1 = (&Peripherals::BUFC.BUF0_STATUS)[param_1 * 0xc] & 0x1fff;
    if (uVar1 == 0) {
      if (param_3 == 0) {
        return;
      }
      write_volatile_4(Peripherals::BUFC.IFS,2 << ((param_1 & 0x1f) << 3));
      return;
    }
    if (param_3 <= uVar1) {
      uVar1 = param_3;
    }
    BUFC_ReadHelper(param_1 & 0xff,param_2,uVar1 & 0xffff,
                    (&Peripherals::BUFC.BUF0_READOFFSET)[param_1 * 0xc] & 0xffff,1,uVar2,uVar3);
    param_3 = param_3 - uVar1;
  } while (param_3 != 0);
  return;
}



undefined4 BUFC_Peek(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  BUFC_ReadHelper();
  return param_3;
}



uint BUFC_PeekByte(int param_1,uint param_2)

{
  uint uVar1;
  
  if (param_2 < ((&Peripherals::BUFC.BUF0_STATUS)[param_1 * 0xc] & 0x1ff)) {
    uVar1 = (uint)*(byte *)((&Peripherals::BUFC.BUF0_ADDR)[param_1 * 0xc] +
                            (param_2 + (&Peripherals::BUFC.BUF0_READOFFSET)[param_1 * 0xc] & 0x1ff)
                           + 0x20000000);
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



uint BUFC_GetSpaceAvailable(int param_1)

{
  return (1 << ((&Peripherals::BUFC.BUF0_CTRL)[param_1 * 0xc] & 7) + 6) -
         ((&Peripherals::BUFC.BUF0_STATUS)[param_1 * 0xc] & 0x1fff) & 0xffff;
}



uint BUFC_GetBytesAvailable(int param_1)

{
  return (&Peripherals::BUFC.BUF0_STATUS)[param_1 * 0xc] & 0x1fff;
}



bool BUFC_TxAckBufferSet(undefined4 param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (0x40 >= param_2) {
    write_volatile_4(Peripherals::BUFC.BUF3_CMD,1);
    uVar1 = CORE_EnterCritical();
    BUFC_WriteBuffer(3,param_1,param_2);
    CORE_ExitCritical(uVar1);
    write_volatile_4(Peripherals::BUFC.BUF3_CMD,4);
  }
  return 0x40 < param_2;
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



void BUFC_RxBufferReset(void)

{
  CORE_EnterCritical();
  write_volatile_4(Peripherals::BUFC.BUF1_CMD,1);
  write_volatile_4(Peripherals::BUFC.BUF2_CMD,1);
  write_volatile_4(Peripherals::BUFC.BUF2_CTRL,0);
  write_volatile_4(Peripherals::BUFC.BUF2_ADDR,(uint)&BUFC_RxLenBuffer);
  write_volatile_4(Peripherals::BUFC.BUF2_THRESHOLDCTR,3);
  BUFC_RxLenBufferThreshold = 3;
  BUFC_RxLenBufferReadOffset = 0;
  write_volatile_4(Peripherals::BUFC.IFC,0x50000);
  write_volatile_4(Peripherals::BUFC_SET.IEN,0x50000);
  callbackRxLenEntry = 0;
  CORE_ExitCritical();
  return;
}



void BUFC_Init(undefined4 param_1)

{
  write_volatile_4(Peripherals::BUFC.BUF1_CTRL,3);
  write_volatile_4(Peripherals::BUFC.BUF1_ADDR,(uint)BUFC_RxBuffer);
  write_volatile_4(Peripherals::BUFC.BUF1_THRESHOLDCTRL,0xfff);
  write_volatile_4(Peripherals::BUFC.BUF2_CTRL,0);
  write_volatile_4(Peripherals::BUFC.BUF2_ADDR,(uint)&BUFC_RxLenBuffer);
  write_volatile_4(Peripherals::BUFC.BUF2_THRESHOLDCTR,3);
  BUFC_RxLenBufferThreshold = 3;
  BUFC_RxLenBufferReadOffset = 0;
  write_volatile_4(Peripherals::BUFC.BUF3_CTRL,0);
  write_volatile_4(Peripherals::BUFC.BUF3_ADDR,(uint)&BUFC_TxAckBuffer);
  write_volatile_4(Peripherals::BUFC.BUF3_THRESHOLDCTRL,0x2000);
  protocolRxOverflowHook = param_1;
  RADIO_FrameControlDescrBufferIdSet(0,0);
  RADIO_FrameControlDescrBufferIdSet(1,0);
  RADIO_FrameControlDescrBufferIdSet(2,1);
  RADIO_FrameControlDescrBufferIdSet(3,1);
  write_volatile_4(Peripherals::FRC_CLR.CTRL,0xf0);
  write_volatile_4(Peripherals::FRC_SET.CTRL,0xa0);
  write_volatile_4(Peripherals::BUFC.BUF3_CMD,1);
  BUFC_RxBufferReset();
  return;
}



void BUFC_RxBufferReadBytes(undefined4 param_1,undefined4 param_2)

{
  BUFC_ReadBuffer(1,param_1,param_2);
  return;
}



void BUFC_RxBufferDropBytes(uint param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 uStack12;
  
  uVar1 = read_volatile_4(Peripherals::BUFC.BUF1_STATUS);
  uVar2 = uVar1 & 0x1fff;
  uStack12 = param_2;
  if (param_1 <= (uVar1 & 0x1fff)) {
    uVar2 = param_1;
  }
  for (; uVar2 != 0; uVar2 = uVar2 - 1 & 0xffff) {
    BUFC_RxBufferReadBytes((int)&uStack12 + 3,1);
  }
  return;
}



uint BUFC_RxBufferBytesAvailable(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::BUFC.BUF1_STATUS);
  return uVar1 & 0x1fff;
}



uint BUFC_HoldRxPacket(void)

{
  uint uVar1;
  
  uVar1 = callbackRxLenEntry;
  if (callbackRxLenEntry != 0) {
    uVar1 = callbackRxLenEntry & 0xfffffffe;
    callbackRxLenEntry = callbackRxLenEntry | 1;
  }
  return uVar1;
}



undefined4 BUFC_ReleaseRxPacket(ushort *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  ushort *puVar5;
  uint uVar6;
  
  if (param_1 == (ushort *)0x0) {
    return 3;
  }
  uVar1 = CORE_EnterCritical();
  uVar2 = (uint)BUFC_RxLenBufferReadOffset;
  if (param_1 == (ushort *)0x2) {
    if (callbackRxLenEntry == 0) goto LAB_00010472;
    param_1 = (ushort *)(callbackRxLenEntry & 0xfffffffe);
  }
  else {
    if (param_1 == (ushort *)0x1) {
      param_1 = (ushort *)(&BUFC_RxLenBuffer + (uVar2 & 0x3c));
    }
  }
  if (param_1 == (ushort *)(callbackRxLenEntry & 0xfffffffe)) {
    callbackRxLenEntry = 0;
  }
  else {
    iVar3 = (int)param_1 - (uVar2 & 0x3f);
    iVar4 = iVar3 + -0x1077a;
    if (iVar4 < 0) {
      iVar4 = iVar3 + -0x1073a;
    }
    if ((int)(BUFC_RxLenBufferThreshold - 4) <= iVar4) {
LAB_00010472:
      CORE_ExitCritical(uVar1);
      return 3;
    }
  }
  *param_1 = ~((ushort)~(ushort)(((uint)*param_1 << 0x11) >> 0x10) >> 1);
  if (param_1 == (ushort *)(&BUFC_RxLenBuffer + (uVar2 & 0x3c))) {
    uVar6 = (uint)BUFC_RxLenBufferThreshold;
    uVar2 = uVar6;
    do {
      puVar5 = param_1;
      uVar2 = uVar2 - 4 & 0xffff;
      param_1 = puVar5 + 2;
      if ((ushort *)0x107b9 < puVar5 + 2) {
        param_1 = (ushort *)&BUFC_RxLenBuffer;
      }
    } while ((4 < uVar2) && ((short)*param_1 < 0));
    BUFC_RxLenBufferThreshold = (ushort)uVar2;
    write_volatile_4(Peripherals::BUFC.BUF1_READOFFSET,*puVar5 & 0x1fff);
    uVar6 = (BUFC_RxLenBufferReadOffset + uVar6) - uVar2 & 0x7f;
    BUFC_RxLenBufferReadOffset = (ushort)uVar6;
    write_volatile_4(Peripherals::BUFC.BUF2_READOFFSET,uVar6);
    write_volatile_4(Peripherals::BUFC.BUF2_THRESHOLDCTR,uVar2);
    if ((*(byte *)(puVar5 + 1) & 7) == 4) {
      if (protocolRxOverflowHook != (code *)0x0) {
        (*protocolRxOverflowHook)();
      }
      RADIO_RACClearRxOverflow();
    }
  }
  checkAndAddRxLenOverflowEntry();
  CORE_ExitCritical(uVar1);
  return 0;
}



void BUFC_StartRxLenThrEvent(void)

{
  byte bVar1;
  byte bVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 local_38 [8];
  
  uVar4 = BUFC_RxLenBufferThreshold + 4 & 0xffff;
  uVar6 = ((uint)BUFC_RxLenBufferReadOffset + (uint)BUFC_RxLenBufferThreshold) - 3 & 0x3c;
  BUFC_RxLenBufferThreshold = (ushort)uVar4;
  write_volatile_4(Peripherals::BUFC.BUF2_THRESHOLDCTR,uVar4);
  bVar1 = (&DAT_0001077c)[uVar6];
  bVar2 = bVar1 & 7;
  puVar7 = local_38;
  if ((bVar1 & 7) == 0) {
    bVar2 = (&DAT_0001077d)[uVar6];
    if ((bVar2 & 0x81) == 0) {
      puVar5 = &DAT_00010758;
      do {
        uVar3 = puVar5[1];
        *puVar7 = *puVar5;
        puVar7[1] = uVar3;
        puVar7 = puVar7 + 2;
        puVar5 = puVar5 + 2;
      } while (puVar5 != (undefined4 *)&BUFC_RxLenBufferThreshold);
      bVar2 = *(byte *)((int)local_38 + (uint)(bVar2 >> 2));
    }
    else {
      bVar2 = 4;
    }
    (&DAT_0001077c)[uVar6] = bVar1 | bVar2;
  }
  if (bVar2 == 4) {
    do {
      uVar4 = read_volatile_4(Peripherals::RAC.STATUS);
    } while ((int)(uVar4 << 0xc) < 0);
  }
  callbackRxLenEntry = &BUFC_RxLenBuffer + uVar6;
  return;
}



void BUFC_EndRxLenThrEvent(void)

{
  if (callbackRxLenEntry != 0) {
    if (-1 < callbackRxLenEntry << 0x1f) {
      BUFC_ReleaseRxPacket();
    }
    callbackRxLenEntry = 0;
  }
  return;
}



void BUFC_HandleRxLenOvfEvent(void)

{
  uint uVar1;
  
  write_volatile_4(Peripherals::BUFC_CLR.IEN,0x10000);
  write_volatile_4(Peripherals::BUFC.IFS,0x10000);
  uVar1 = read_volatile_4(Peripherals::BUFC.BUF2_STATUS);
  if ((uVar1 & 0x1fff) < 0x3d) {
    checkAndAddRxLenOverflowEntry();
    return;
  }
  return;
}



ushort * BUFC_GetRxPacketInfo(ushort *param_1,byte *param_2,undefined2 *param_3)

{
  short sVar1;
  undefined4 uVar2;
  ushort *puVar3;
  uint uVar4;
  byte bVar5;
  int iVar6;
  int iVar7;
  undefined1 *puVar8;
  ushort uVar9;
  uint uVar10;
  uint uVar11;
  
  uVar2 = CORE_EnterCritical();
  uVar11 = (uint)BUFC_RxLenBufferReadOffset;
  if (param_1 == (ushort *)0x2) {
    if (callbackRxLenEntry == 0) {
      param_1 = (ushort *)(&BUFC_RxLenBuffer + ((uVar11 + BUFC_RxLenBufferThreshold) - 3 & 0x3c));
    }
    else {
      param_1 = (ushort *)(callbackRxLenEntry & 0xfffffffe);
    }
  }
  else {
    if (param_1 == (ushort *)0x1) {
      param_1 = (ushort *)(&BUFC_RxLenBuffer + (uVar11 & 0x3c));
    }
  }
  iVar6 = (int)param_1 - (uVar11 & 0x3f);
  iVar7 = iVar6 + -0x1077a;
  if (iVar7 < 0) {
    iVar7 = iVar6 + -0x1073a;
  }
  if (iVar7 < (int)(uint)BUFC_RxLenBufferThreshold) {
    if ((param_2 != (byte *)0x0) || (param_3 != (undefined2 *)0x0)) {
      if (param_1 == (ushort *)(&BUFC_RxLenBuffer + (uVar11 & 0x3c))) {
        uVar11 = read_volatile_4(Peripherals::BUFC.BUF1_READOFFSET);
        uVar11 = uVar11 & 0xffff;
      }
      else {
        puVar3 = param_1 + -2;
        if (puVar3 < &BUFC_RxLenBuffer) {
          puVar3 = param_1 + 0x1e;
        }
        uVar11 = *puVar3 & 0x1fff;
      }
      if (param_3 != (undefined2 *)0x0) {
        *param_3 = (short)uVar11;
      }
      if (param_2 != (byte *)0x0) {
        uVar10 = read_volatile_4(Peripherals::BUFC.BUF2_STATUS);
        if (iVar7 < (int)(uVar10 & 0x1fff)) {
          uVar9 = *param_1;
          if ((short)uVar9 < 0) goto LAB_000106a0;
          bVar5 = *(byte *)(param_1 + 1);
          *param_2 = bVar5 & 7;
          uVar10 = uVar9 - uVar11 & 0x3ff;
          if (5 < (bVar5 & 7)) {
            iVar6 = RADIO_RxTrailDataLength();
            uVar10 = uVar10 - iVar6 & 0xffff;
          }
          RAILInt_Assert((~uVar10 << 0x10) >> 0x1f,4);
          *(short *)(param_2 + 2) = (short)uVar10;
        }
        else {
          uVar10 = read_volatile_4(Peripherals::BUFC.BUF1_WRITEOFFSET);
          uVar4 = read_volatile_4(Peripherals::RAC.STATUS);
          if ((uVar10 - uVar11 & 0x3ff) == 0) {
            if ((uVar4 << 4) >> 0x1c == 3) {
              bVar5 = 8;
            }
            else {
              bVar5 = 0;
            }
          }
          else {
            bVar5 = 8;
          }
          *param_2 = bVar5;
          sVar1 = RADIO_RxTrailDataLength();
          uVar9 = (ushort)((uVar10 - uVar11) * 0x400000 >> 0x16) - sVar1;
          uVar9 = uVar9 & ~((short)uVar9 >> 0x1f);
          uVar10 = (uint)uVar9;
          *(ushort *)(param_2 + 2) = uVar9;
        }
        puVar8 = BUFC_RxBuffer;
        uVar11 = uVar11 & 0x1ff;
        *(undefined1 **)(param_2 + 8) = BUFC_RxBuffer + uVar11;
        uVar4 = uVar11 + uVar10;
        if (uVar4 < 0x201) {
          puVar8 = (undefined1 *)0x0;
        }
        else {
          uVar11 = 0x200 - uVar11;
        }
        if (0x200 < uVar4) {
          *(short *)(param_2 + 4) = (short)uVar11;
        }
        if (uVar4 < 0x201) {
          *(short *)(param_2 + 4) = (short)uVar10;
        }
        *(undefined1 **)(param_2 + 0xc) = puVar8;
      }
    }
    CORE_ExitCritical(uVar2);
    return param_1;
  }
LAB_000106a0:
  CORE_ExitCritical(uVar2);
  return (ushort *)0x0;
}


