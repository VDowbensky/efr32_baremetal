#include "bufc.h"



void BUFC_ReadHelper(int param_1,void *param_2,size_t param_3,uint32_t param_4,char param_5)

{
  uint32_t uVar1;
  void *pvVar2;
  uint32_t uVar3;
  uint32_t __n;
  void *__src;
  bool bVar4;
  
  uVar3 = 1 << ((&BUFC->BUF0_CTRL)[param_1 * 0xc] & 7) + 6;
  uVar1 = param_4 & uVar3 - 1;
  __n = uVar3 - uVar1;
  __src = (void *)((&BUFC->BUF0_ADDR)[param_1 * 0xc] | 0x20000000);
  pvVar2 = (void *)(uVar1 + (int)__src);
  if (__n < param_3) {
    pvVar2 = memcpy(param_2,pvVar2,__n);
    memcpy((void *)((int)pvVar2 + __n),__src,param_3 - __n);
  }
  else memcpy(param_2,pvVar2,param_3);
  if (param_5 != '\0') 
  {
    uVar3 = (uVar3 | uVar3 - 1) & param_3 + param_4;
    (&BUFC->BUF0_READOFFSET)[param_1 * 0xc] = uVar3;
    uVar1 = (&BUFC->BUF0_WRITEOFFSET)[param_1 * 0xc];
    bVar4 = uVar3 != uVar1;
    if (bVar4) uVar1 = 2;
    if (bVar4) (&BUFC->BUF0_CMD)[param_1 * 0xc] = uVar1;
  }
  return;
}



void checkAndAddRxLenOverflowEntry(void)

{
  if (BUFC->IF & BUFC_IF_BUF2OF_Msk) 
  {
    BUFC->IFC = BUFC_IFC_BUF2OF_Msk;
    BUS_RegMaskedSet(&BUFC->IEN,BUFC_IEN_BUF2OF_Msk);
	BUFC->BUF2_WRITEDATA = BUFC->BUF1_WRITEOFFSET & 0xff;
    BUFC->BUF2_WRITEDATA = (BUFC->BUF1_WRITEOFFSET << 0x10) >> 0x18;
    BUFC->BUF2_WRITEDATA = 4;
    BUFC->BUF2_WRITEDATA = 0;
  }
}



void BUFC_SetTxBuffer(uint32_t param_1,uint32_t param_2,uint32_t param_3)

{
  CORE_irqState_t irqState;
  
  BUFC->BUF0_CTRL = param_3;
  BUFC->BUF0_ADDR = param_1;
  irqState = CORE_EnterCritical();
  BUFC->BUF0_READOFFSET = 0;
  BUFC->BUF0_WRITEOFFSET = param_2;
  if (!(BUFC->IF & BUFC_IF_BUF0THR_Msk) BUFC->IFC = BUFC_IF_BUF0THR_Msk;
  CORE_ExitCritical(irqState);
  if (param_2 != 0) BUFC->BUF0_CMD = BUFC_BUF0_CMD_PREFETCH_Msk; //2;
}



void BUFC_WriteBuffer(int param_1,uint8_t *param_2,int param_3)

{
  uint32_t uVar1;
  void *__dest;
  uint32_t __n;
  uint32_t uVar2;
  void *__dest_00;
  uint32_t uVar3;
  uint32_t __n_00;
  
  switch(param_3) 
  {
  case 4:
    (&BUFC->BUF0_WRITEDATA)[param_1 * 0xc] = (uint32_t)*param_2;
    param_2 = param_2 + 1;
  case 3:
    (&BUFC->BUF0_WRITEDATA)[param_1 * 0xc] = (uint32_t)*param_2;
    param_2 = param_2 + 1;
  case 2:
    (&BUFC->BUF0_WRITEDATA)[param_1 * 0xc] = (uint32_t)*param_2;
    param_2 = param_2 + 1;
  case 1:
    (&BUFC->BUF0_WRITEDATA)[param_1 * 0xc] = (uint32_t)*param_2;
    return;
  case -0x452e541f:
    return;
  default:
    (&BUFC->BUF0_WRITEDATA)[param_1 * 0xc] = (uint32_t)*param_2;
    (&BUFC->BUF0_WRITEDATA)[param_1 * 0xc] = (uint32_t)param_2[1];
    (&BUFC->BUF0_WRITEDATA)[param_1 * 0xc] = (uint32_t)param_2[2];
    (&BUFC->BUF0_WRITEDATA)[param_1 * 0xc] = (uint32_t)param_2[3];
    uVar2 = (&BUFC->BUF0_WRITEOFFSET)[param_1 * 0xc];
    uVar3 = 1 << ((&BUFC->BUF0_CTRL)[param_1 * 0xc] & 7) + 6;
    uVar1 = uVar3 - 1 & uVar2;
    __n_00 = uVar3 - uVar1;
    __n = param_3 - 4;
    param_2 = param_2 + 4;
    __dest_00 = (void *)((&BUFC->BUF0_ADDR)[param_1 * 0xc] | 0x20000000);
    __dest = (void *)(uVar1 + (int)__dest_00);
    if (__n_00 < __n) 
	{
      memcpy(__dest,param_2,__n_00);
      memcpy(__dest_00,param_2 + __n_00,__n - __n_00);
    }
    else 
	{
      memcpy(__dest,param_2,__n);
    }
    (&BUFC->BUF0_WRITEOFFSET)[param_1 * 0xc] = __n + uVar2 & (uVar3 - 1 | uVar3);
    return;
  }
}



void BUFC_ReadBuffer(uint32_t param_1,undefined4 param_2,uint32_t param_3)

{
  uint32_t uVar1;
  undefined4 uVar2;
  uint32_t uVar3;
  
  uVar2 = param_2;
  uVar3 = param_3;
  do 
  {
    uVar1 = (&BUFC->BUF0_STATUS)[param_1 * 0xc] & 0x1fff;
    if (uVar1 == 0) 
	{
      if (param_3 == 0) return;
      BUFC->IFS = 2 << ((param_1 & 0x1f) << 3);
      return;
    }
    if (param_3 <= uVar1) uVar1 = param_3;
    BUFC_ReadHelper(param_1 & 0xff,param_2,uVar1 & 0xffff,(&BUFC->BUF0_READOFFSET)[param_1 * 0xc] & 0xffff,1,uVar2,uVar3);
    param_3 = param_3 - uVar1;
  } while (param_3 != 0);
}



undefined4 BUFC_Peek(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  BUFC_ReadHelper();
  return param_3;
}



uint32_t BUFC_PeekByte(int param_1,uint32_t param_2)

{
  uint32_t uVar1;
  
  if (param_2 < ((&BUFC->BUF0_STATUS)[param_1 * 0xc] & 0x1ff)) uVar1 = (uint32_t)*(uint8_t *)((&BUFC->BUF0_ADDR)[param_1 * 0xc] + (param_2 + (&BUFC->BUF0_READOFFSET)[param_1 * 0xc] & 0x1ff) + 0x20000000);
  else uVar1 = 0xffffffff;
  return uVar1;
}



uint32_t BUFC_GetSpaceAvailable(int param_1)

{
  return (1 << ((&BUFC->BUF0_CTRL)[param_1 * 0xc] & 7) + 6) - ((&BUFC->BUF0_STATUS)[param_1 * 0xc] & 0x1fff) & 0xffff;
}



uint32_t BUFC_GetBytesAvailable(int param_1)

{
  return (&BUFC->BUF0_STATUS)[param_1 * 0xc] & 0x1fff;
}



bool BUFC_TxAckBufferSet(undefined4 param_1,uint32_t param_2)

{
  CORE_irqState_t irqState;
  
  if (0x40 >= param_2) 
  {
    BUFC->BUF3_CMD = BUFC_BUF3_CMD_CLEAR_Msk;
    irqState = CORE_EnterCritical();
    BUFC_WriteBuffer(3,param_1,param_2);
    CORE_ExitCritical(irqState);
    BUFC->BUF3_CMD = 4;
  }
  return 0x40 < param_2;
}



void BUFC_TxAckBufferReset(void)

{
  BUFC_TxAckBufferSet(0,0);
  return;
}



uint32_t BUFC_TxAckBufferBytesAvailable(void)

{
  return BUFC->BUF3_STATUS & 0x1fff;
}



void BUFC_RxBufferReset(void)

{
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  BUFC->BUF1_CMD = 1;
  BUFC->BUF2_CMD = 1;
  BUFC->BUF2_CTRL = 0;
  BUFC->BUF2_ADDR = (uint32_t)&BUFC_RxLenBuffer;
  BUFC->BUF2_THRESHOLDCTRL = 3;
  BUFC_RxLenBufferThreshold = 3;
  BUFC_RxLenBufferReadOffset = 0;
  BUFC->IFC = BUFC_IFS_BUF2THR_Msk | BUFC_IFS_BUF2OF_Msk; //0x50000;
  BUS_RegMaskedSet(&BUFC->IEN,BUFC_IEN_BUF2THR_Msk | BUFC_IEN_BUF2OF_Msk); //0x50000);
  callbackRxLenEntry = 0;
  CORE_ExitCritical(irqState);
}



void BUFC_Init(undefined4 param_1)

{
  BUFC->BUF1_CTRL = 3;
  BUFC->BUF1_ADDR = (uint32_t)BUFC_RxBuffer;
  BUFC->BUF1_THRESHOLDCTRL = 0xfff;
  BUFC->BUF2_CTRL = 0;
  BUFC->BUF2_ADDR = (uint32_t)&BUFC_RxLenBuffer;
  BUFC->BUF2_THRESHOLDCTR = 3;
  BUFC_RxLenBufferThreshold = 3;
  BUFC_RxLenBufferReadOffset = 0;
  BUFC->BUF3_CTRL = 0;
  BUFC->BUF3_ADDR = (uint32_t)&BUFC_TxAckBuffer;
  BUFC->BUF3_THRESHOLDCTRL = 0x2000);
  protocolRxOverflowHook = param_1;
  RADIO_FrameControlDescrBufferIdSet(0,0);
  RADIO_FrameControlDescrBufferIdSet(1,0);
  RADIO_FrameControlDescrBufferIdSet(2,1);
  RADIO_FrameControlDescrBufferIdSet(3,1);
  BUS_RegMaskedClear(&FRC->CTRL,FRC_CTRL_RXFCDMODE_Msk | FRC_CTRL_TXFCDMODE_Msk); //0xf0);
  BUS_RegMaskedSet(&FRC->CTRL,0xa0);
  BUFC->BUF3_CMD = BUFC_BUF3_CMD_CLEAR_Msk; //1;
  BUFC_RxBufferReset();
}



void BUFC_RxBufferReadBytes(undefined4 param_1,undefined4 param_2)

{
  BUFC_ReadBuffer(1,param_1,param_2);
  return;
}



void BUFC_RxBufferDropBytes(uint32_t param_1,undefined4 param_2)

{
  uint32_t uVar2;
  undefined4 uStack12;
  
  uVar2 = BUFC->BUF1_STATUS & 0x1fff;
  uStack12 = param_2;
  if (param_1 <= (BUFC->BUF1_STATUS & 0x1fff)) uVar2 = param_1;
  for (; uVar2 != 0; uVar2 = uVar2 - 1 & 0xffff) BUFC_RxBufferReadBytes((int)&uStack12 + 3,1);
}



uint32_t BUFC_RxBufferBytesAvailable(void)

{
  return BUFC->BUF1_STATUS & 0x1fff;
}



uint32_t BUFC_HoldRxPacket(void)

{
  uint32_t uVar1;
  
  uVar1 = callbackRxLenEntry;
  if (callbackRxLenEntry != 0) 
  {
    uVar1 = callbackRxLenEntry & 0xfffffffe;
    callbackRxLenEntry = callbackRxLenEntry | 1;
  }
  return uVar1;
}



undefined4 BUFC_ReleaseRxPacket(uint16_t *param_1)

{
  undefined4 uVar1;
  uint32_t uVar2;
  int iVar3;
  int iVar4;
  uint16_t *puVar5;
  uint32_t uVar6;
  CORE_irqState_t irqState;
  
  if (param_1 == NULL) return 3;
  irqState = CORE_EnterCritical();
  uVar2 = (uint32_t)BUFC_RxLenBufferReadOffset;
  if (param_1 == (uint16_t *)0x2) 
  {
    if (callbackRxLenEntry == 0) goto LAB_00010472;
    param_1 = (uint16_t *)(callbackRxLenEntry & 0xfffffffe);
  }
  else 
  {
    if (param_1 == (uint16_t *)0x1) param_1 = (uint16_t *)(&BUFC_RxLenBuffer + (uVar2 & 0x3c));
  }
  if (param_1 == (uint16_t *)(callbackRxLenEntry & 0xfffffffe)) callbackRxLenEntry = 0;
  else 
  {
    iVar3 = (int)param_1 - (uVar2 & 0x3f);
    iVar4 = iVar3 + -0x1077a;
    if (iVar4 < 0) iVar4 = iVar3 + -0x1073a;
    if ((int)(BUFC_RxLenBufferThreshold - 4) <= iVar4) 
	{
LAB_00010472:
      CORE_ExitCritical(irqState);
      return 3;
    }
  }
  *param_1 = ~((uint16_t)~(uint16_t)(((uint32_t)*param_1 << 0x11) >> 0x10) >> 1);
  if (param_1 == (uint16_t *)(&BUFC_RxLenBuffer + (uVar2 & 0x3c))) 
  {
    uVar6 = (uint32_t)BUFC_RxLenBufferThreshold;
    uVar2 = uVar6;
    do 
	{
      puVar5 = param_1;
      uVar2 = uVar2 - 4 & 0xffff;
      param_1 = puVar5 + 2;
      if ((uint16_t *)0x107b9 < puVar5 + 2) param_1 = (uint16_t *)&BUFC_RxLenBuffer;
    } while ((4 < uVar2) && ((int16_t)*param_1 < 0));
    BUFC_RxLenBufferThreshold = (uint16_t)uVar2;
    BUFC->BUF1_READOFFSET = *puVar5 & 0x1fff;
    uVar6 = (BUFC_RxLenBufferReadOffset + uVar6) - uVar2 & 0x7f;
    BUFC_RxLenBufferReadOffset = (uint16_t)uVar6;
    BUFC->BUF2_READOFFSET = uVar6;
    BUFC->BUF2_THRESHOLDCTR = uVar2;
    if ((*(uint8_t *)(puVar5 + 1) & 7) == 4) 
	{
      if (protocolRxOverflowHook != NULL) (*protocolRxOverflowHook)();
      RADIO_RACClearRxOverflow();
    }
  }
  checkAndAddRxLenOverflowEntry();
  CORE_ExitCritical(irqState);
  return 0;
}



void BUFC_StartRxLenThrEvent(void)

{
  uint8_t bVar1;
  uint8_t bVar2;
  undefined4 uVar3;
  uint32_t uVar4;
  undefined4 *puVar5;
  uint32_t uVar6;
  undefined4 *puVar7;
  undefined4 local_38 [8];
  
  uVar4 = BUFC_RxLenBufferThreshold + 4 & 0xffff;
  uVar6 = ((uint32_t)BUFC_RxLenBufferReadOffset + (uint32_t)BUFC_RxLenBufferThreshold) - 3 & 0x3c;
  BUFC_RxLenBufferThreshold = (uint16_t)uVar4;
  BUFC->BUF2_THRESHOLDCTR = uVar4;
  bVar1 = (&DAT_0001077c)[uVar6];
  bVar2 = bVar1 & 7;
  puVar7 = local_38;
  if ((bVar1 & 7) == 0) 
  {
    bVar2 = (&DAT_0001077d)[uVar6];
    if ((bVar2 & 0x81) == 0) 
	{
      puVar5 = &DAT_00010758;
      do 
	  {
        uVar3 = puVar5[1];
        *puVar7 = *puVar5;
        puVar7[1] = uVar3;
        puVar7 = puVar7 + 2;
        puVar5 = puVar5 + 2;
      } while (puVar5 != (undefined4 *)&BUFC_RxLenBufferThreshold);
      bVar2 = *(uint8_t *)((int)local_38 + (uint32_t)(bVar2 >> 2));
    }
    else bVar2 = 4;
    (&DAT_0001077c)[uVar6] = bVar1 | bVar2;
  }
  if (bVar2 == 4) 
  {
    while (RAC->STATUS & RAC_STATUS_FORCESTATEACTIVE_Msk);
  }
  callbackRxLenEntry = &BUFC_RxLenBuffer + uVar6;
}



void BUFC_EndRxLenThrEvent(void)

{
  if (callbackRxLenEntry != 0) 
  {
    if (!(callbackRxLenEntry & 0x01)) BUFC_ReleaseRxPacket();
    callbackRxLenEntry = 0;
  }
}



void BUFC_HandleRxLenOvfEvent(void)

{
  BUS_RegMaskedClear(&BUFC->IEN,BUFC_IEN_BUF2OF_Msk); //0x10000);
  BUFC->IFS = BUFC_IFS_BUF2OF_Msk; //0x10000);
  if ((BUFC->BUF2_STATUS & 0x1fff) < 0x3d) checkAndAddRxLenOverflowEntry();
}



uint16_t * BUFC_GetRxPacketInfo(uint16_t *param_1,uint8_t *param_2,undefined2 *param_3)

{
  int16_t sVar1;
  undefined4 uVar2;
  uint16_t *puVar3;
  uint32_t uVar4;
  uint8_t bVar5;
  int iVar6;
  int iVar7;
  undefined1 *puVar8;
  uint16_t uVar9;
  uint32_t uVar10;
  uint32_t uVar11;
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  uVar11 = (uint32_t)BUFC_RxLenBufferReadOffset;
  if (param_1 == (uint16_t *)0x2) 
  {
    if (callbackRxLenEntry == 0) param_1 = (uint16_t *)(&BUFC_RxLenBuffer + ((uVar11 + BUFC_RxLenBufferThreshold) - 3 & 0x3c));
    else param_1 = (uint16_t *)(callbackRxLenEntry & 0xfffffffe);
  }
  else 
  {
    if (param_1 == (uint16_t *)0x1) param_1 = (uint16_t *)(&BUFC_RxLenBuffer + (uVar11 & 0x3c));
  }
  iVar6 = (int)param_1 - (uVar11 & 0x3f);
  iVar7 = iVar6 + -0x1077a;
  if (iVar7 < 0) iVar7 = iVar6 + -0x1073a;
  if (iVar7 < (int)(uint32_t)BUFC_RxLenBufferThreshold) 
  {
    if ((param_2 != NULL) || (param_3 != NULL)) 
	{
      if (param_1 == (uint16_t *)(&BUFC_RxLenBuffer + (uVar11 & 0x3c))) 
	  {
        uVar11 = (BUFC->BUF1_READOFFSET);
        uVar11 = uVar11 & 0xffff;
      }
      else 
	  {
        puVar3 = param_1 + -2;
        if (puVar3 < &BUFC_RxLenBuffer) puVar3 = param_1 + 0x1e;
        uVar11 = *puVar3 & 0x1fff;
      }
      if (param_3 != NULL) *param_3 = (int16_t)uVar11;
      if (param_2 != NULL) 
	  {
        uVar10 = (BUFC->BUF2_STATUS);
        if (iVar7 < (int)(uVar10 & 0x1fff)) 
		{
          uVar9 = *param_1;
          if ((int16_t)uVar9 < 0) goto LAB_000106a0;
          bVar5 = *(uint8_t *)(param_1 + 1);
          *param_2 = bVar5 & 7;
          uVar10 = uVar9 - uVar11 & 0x3ff;
          if (5 < (bVar5 & 7)) 
		  {
            iVar6 = RADIO_RxTrailDataLength();
            uVar10 = uVar10 - iVar6 & 0xffff;
          }
          RAILInt_Assert((~uVar10 << 0x10) >> 0x1f,4);
          *(int16_t *)(param_2 + 2) = (int16_t)uVar10;
        }
        else 
		{
          uVar10 = (BUFC->BUF1_WRITEOFFSET);
          uVar4 = (RAC->STATUS);
          if ((uVar10 - uVar11 & 0x3ff) == 0) 
		  {
            if ((uVar4 << 4) >> 0x1c == 3) bVar5 = 8;
            else bVar5 = 0;
          }
          else bVar5 = 8;
          *param_2 = bVar5;
          sVar1 = RADIO_RxTrailDataLength();
          uVar9 = (uint16_t)((uVar10 - uVar11) * 0x400000 >> 0x16) - sVar1;
          uVar9 = uVar9 & ~((int16_t)uVar9 >> 0x1f);
          uVar10 = (uint32_t)uVar9;
          *(uint16_t *)(param_2 + 2) = uVar9;
        }
        puVar8 = BUFC_RxBuffer;
        uVar11 = uVar11 & 0x1ff;
        *(undefined1 **)(param_2 + 8) = BUFC_RxBuffer + uVar11;
        uVar4 = uVar11 + uVar10;
        if (uVar4 < 0x201) puVar8 = NULL;
        else uVar11 = 0x200 - uVar11;
        if (0x200 < uVar4) *(int16_t *)(param_2 + 4) = (int16_t)uVar11;
        if (uVar4 < 0x201) *(int16_t *)(param_2 + 4) = (int16_t)uVar10;
        *(undefined1 **)(param_2 + 0xc) = puVar8;
      }
    }
    CORE_ExitCritical(irqState);
    return param_1;
  }
LAB_000106a0:
  CORE_ExitCritical(irqState);
  return NULL;
}


