#include "generic_phy.h"



void GENERIC_PHY_RAC_IRQCallback(void)

{
  uint32_t flags;
  uint32_t flags1;

  flags = RAC->IEN & RAC->IF;
  RAC->IFC = flags;
  if ((int)(flags << 0x1f) < 0) (**(code **)(currentCallbacks + 0x3c))();
  if ((int)(flags << 0x1d) < 0) (**(code **)(currentCallbacks + 0x38))();
  if ((int)(flags << 6) < 0) 
  {
    if ((int)((uint)enabledCallbacks._2_1_ << 0x1f) < 0) (**(code **)(currentCallbacks + 0x40))();
    PA_PeakDetectorHighRun();
  }
  if ((int)(flags << 5) < 0) 
  {
    if ((int)((uint)enabledCallbacks._2_1_ << 0x1e) < 0) (**(code **)(currentCallbacks + 0x44))();
    PA_PeakDetectorLowRun();
  }
  if ((int)(flags << 4) < 0) 
  {
    if ((int)((uint)enabledCallbacks._2_1_ << 0x1d) < 0) (**(code **)(currentCallbacks + 0x48))();
    PA_BatHighRun();
  }
  flags1 = flags & 0xff0000;
  if (flags1 != 0) 
  {
    if ((flags & 0x40000) != 0) 
	{
      if ((int)((uint)enabledCallbacks._2_1_ << 0x1c) < 0) (**(code **)(currentCallbacks + 0x4c))();
      flags1 = flags & 0xfb0000;
    }
    if ((int)(flags1 << 0xf) < 0) 
	{
      if ((int)((uint)(byte)enabledCallbacks << 0x19) < 0) (**(code **)(currentCallbacks + 0x18))(2);
      flags1 = flags1 & 0xfffeffff;
    }
    if ((int)(flags1 << 0xe) < 0) 
	{
      if ((int)((uint)(byte)enabledCallbacks << 0x1e) < 0) (**(code **)(currentCallbacks + 4))(0x10);
      flags1 = flags1 & 0xfffdffff;
    }
    if ((int)(flags1 << 0xb) < 0) 
	{
      if ((int)((uint)enabledCallbacks._1_1_ << 0x1e) < 0) (**(code **)(currentCallbacks + 0x24))();
      flags1 = flags1 & 0xffefffff;
    }
    if ((*(code **)(currentCallbacks + 0x50) != (code *)0x0) && (flags1 != 0)) 
	{
                    // WARNING: Could not recover jumptable at 0x000100e0. Too many branches
                    // WARNING: Treating indirect jump as call
      (**(code **)(currentCallbacks + 0x50))(flags1);
    }
  }
}



void GENERIC_PHY_MODEM_IRQCallback(void)

{
  uint32_t flags;

  flags = MODEM->IEN & MODEM->IF;
  MODEM->IFC = flags;
  if ((int)(flags << 0x12) < 0) (**(code **)(currentCallbacks + 0x28))();
  if ((int)(flags << 0x16) < 0) (**(code **)(currentCallbacks + 0x2c))();
  if ((int)(flags << 0x15) < 0) (**(code **)(currentCallbacks + 0x30))();
  if ((int)(flags << 0x14) < 0) 
  {
                    // WARNING: Could not recover jumptable at 0x00010134. Too many branches
                    // WARNING: Treating indirect jump as call
    (**(code **)(currentCallbacks + 0x34))();
  }
}



void GENERIC_PHY_AGC_IRQCallback(void)

{
  uint32_t flags;

  flags = AGC->IEN & AGC->IF;
  AGC->IFC = flags;
  if ((int)((flags) << 0x1f) < 0) 
  {
                    // WARNING: Could not recover jumptable at 0x00010154. Too many branches
                    // WARNING: Treating indirect jump as call
    (**(code **)(currentCallbacks + 0x68))();
  }
}



void RADIO_RACRxAbort(undefined4 param_1,undefined4 param_2,int param_3)

{
  CORE_EnterCritical();
  if ((RAC->STATUS << 4) >> 0x1c == 3) 
  {
    param_3 = 0x21000f64;
	SEQ->REG06C &= 0xffffff0f;
	SEQ->REG06C |= 0xe0;
  }
  if ((RAC->STATUS << 4) >> 0x1c == 3) *(uint *)(param_3 + 8) = uVar1;
  FRC->CMD = 1;
  CORE_ExitCritical();
}



void GENERIC_PHY_PROTIMER_IRQCallback(void)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  code *pcVar4;
  uint flags;
  
  flags = PROTIMER->IEN & PROTIMER->IF;
  PROTIMER->IFC = flags;
  if ((int)(flags << 0x14) < 0) PROTIMER_CCTimerStop(3);
  if ((flags & 0x500000) == 0) {
    if (-1 < (int)(flags << 0x13)) goto LAB_0001022a;
    if (PROTIMER_LBTIsActive() != 0) goto LAB_000101c4;
    PROTIMER_CCTimerStop(3);
    PROTIMER_CCTimerStop(4);
    PROTIMER_ClearRxEnable();
    uVar2 = CORE_EnterCritical();
    if (scheduledRxHardEnd != '\0') RADIO_RACRxAbort();
	{
      RADIO_RACRxAbort();
    }
    if (((RAC->STATUS << 4) >> 0x1c == 3) || (BUFC_RxBufferBytesAvailable() != 0)) 
	{
      iVar1 = 1;
      pendedRxWindowEnd = scheduledRxLoop;
    }
    CORE_ExitCritical(uVar2);
    if ((iVar1 != 0) || (-1 < (int)((uint)(byte)enabledCallbacks << 0x19))) goto LAB_0001022a;
    pcVar4 = *(code **)(currentCallbacks + 0x18);
    uVar3 = 1;
  }
  else 
  {
LAB_000101c4:
    pcVar4 = *(code **)(currentCallbacks + 0x58);
    uVar3 = uVar5;
  }
  (*pcVar4)(uVar3);
LAB_0001022a:
  if ((int)(uVar5 << 10) < 0) 
  {
    (**(code **)(currentCallbacks + 0x5c))();
  }
  if ((int)(uVar5 << 6) < 0) 
  {
    (**(code **)(currentCallbacks + 0x60))();
  }
  if (-1 < (int)(uVar5 << 0x15)) return;
                    // WARNING: Could not recover jumptable at 0x00010250. Too many branches
                    // WARNING: Treating indirect jump as call
  (**(code **)(currentCallbacks + 100))();
  return;
}



void GENERIC_PHY_SetAddressFilteringMatchTable(void)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint *puVar11;
  uint uVar12;
  uint local_38;
  uint local_34;
  
  uVar5 = 0;
  local_34 = 0;
  uVar3 = 0;
  do 
  {
    uVar6 = uVar3 + 1;
    uVar1 = uVar6 * 5;
    uVar12 = addressFilterMatchTable >> (uVar1 & 0xff) & 0x1f;
    uVar7 = addressFilterMatchTable >> (uVar6 & 0xff) & 0x108421;
    uVar9 = uVar6 * 8;
    local_38 = uVar1;
    for (uVar8 = uVar6; local_38 = local_38 + 5, uVar8 != 4; uVar8 = uVar8 + 1) 
	{
      puVar11 = &SEQ->REG010;
      bVar2 = read_volatile_1(SEQ->REG058._0_1_);
      uVar4 = 1 << (uVar8 & 0xff) | 1 << (uVar3 & 0xff);
      if ((uVar4 & bVar2) == uVar4) {
        bVar2 = read_volatile_1(SEQ->REG054._2_1_);
        for (iVar10 = 0; iVar10 < (int)(uint)bVar2; iVar10 = iVar10 + 1) 
		{
          puVar11 = puVar11 + 1;
          if (((*puVar11 >> (uVar9 & 0xff) ^ *puVar11 >> (uVar5 & 0xff)) & 0xff) != 0)
          goto LAB_000102fe;
        }
        uVar12 = uVar12 | addressFilterMatchTable >> (local_38 & 0xff) & 0x1f;
      }
LAB_000102fe:
      bVar2 = read_volatile_1(SEQ->REG058._1_1_);
      if ((uVar4 & bVar2) == uVar4) {
        bVar2 = read_volatile_1(SEQ->REG054._3_1_);
        puVar11 = &SEQ->REG030;
        for (iVar10 = 0; iVar10 < (int)(uint)bVar2; iVar10 = iVar10 + 1) 
		{
          puVar11 = puVar11 + 1;
          if (((*puVar11 >> (uVar9 & 0xff) ^ *puVar11 >> (uVar5 & 0xff)) & 0xff) != 0)
          goto LAB_00010346;
        }
        uVar7 = uVar7 | addressFilterMatchTable >> (uVar8 + 1 & 0xff) & 0x108421;
      }
LAB_00010346:
      uVar9 = uVar9 + 8;
    }
    local_34 = local_34 | uVar7 << (uVar6 & 0xff) | uVar12 << (uVar1 & 0xff);
    uVar5 = uVar5 + 8;
    uVar3 = uVar6;
    if (uVar6 == 4) 
	{
      write_volatile_4(SEQ->REG010,local_34);
      return;
    }
  } while( true );
}



void GENERIC_PHY_ConfigureCallbacks(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  enabledCallbacks = param_1 & availableCallbacks;
  uVar3 = 0x161;
  if ((enabledCallbacks & 1) != 0) uVar3 = 0x163;
  if ((int)(enabledCallbacks << 0x1e) < 0) uVar3 = uVar3 | 0xc;
  if ((int)(enabledCallbacks << 0x18) < 0) uVar3 = uVar3 | 0x4000;
  uVar2 = FRC->IEN;
  if ((int)(enabledCallbacks << 0x17) < 0) uVar3 = uVar3 | 0x2000;
  uVar1 = (uVar3 ^ uVar2) & 0xffffffef;
  uVar2 = uVar2 & uVar1;
  BUS_RegMaskedClear(&FRC->IEN,uVar2);
  FRC->IFC = uVar2;
  uVar3 = uVar3 & uVar1;
  FRC->IFC = uVar3;
  BUS_RegMaskedSet(&FRC->IEN,uVar3);
  if ((enabledCallbacks & 0x400) == 0) uVar3 = 0;
  else uVar3 = 0x2000;
  if ((int)(enabledCallbacks << 0x14) < 0) uVar3 = uVar3 | 0x200;
  if ((int)(enabledCallbacks << 0x13) < 0) uVar3 = uVar3 | 0x400;
  uVar2 = MODEM->IEN;
  if ((int)(enabledCallbacks << 0x12) < 0) uVar3 = uVar3 | 0x800;
  uVar1 = uVar2 & (uVar3 ^ uVar2);
  BUS_RegMaskedClear(&MODEM->IEN,uVar1);
  MODEM->IFC = uVar1;
  uVar3 = uVar3 & (uVar3 ^ uVar2);
  MODEM->IFC = uVar3;
  BUS_RegMaskedSet(&MODEM->IEN,uVar3);
  if ((enabledCallbacks & 0x4000) == 0) uVar3 = 0;
  else uVar3 = 4;
  if ((int)(enabledCallbacks << 0x10) < 0) uVar3 = uVar3 | 1;
  if ((int)(enabledCallbacks << 0xc) < 0) uVar3 = uVar3 | 0x40000;
  if ((int)(enabledCallbacks << 0x1e) < 0) uVar3 = uVar3 | 0x20000;
  if ((int)(enabledCallbacks << 0x19) < 0) uVar3 = uVar3 | 0x10000;uVar3 = uVar3 | 0x10000;
  if ((int)(enabledCallbacks << 0x16) < 0) uVar3 = uVar3 | 0x100000;
  uVar2 = RAC->IEN;
  if ((int)(enabledCallbacks << 0xb) < 0) uVar3 = uVar3 | 0xe80000;
  uVar1 = uVar2 & (uVar3 ^ uVar2);
  BUS_RegMaskedClear(&RAC->IEN,uVar1);
  write_volatile_4(RAC->IFC,uVar1);
  uVar3 = uVar3 & (uVar3 ^ uVar2);
  write_volatile_4(RAC->IFC,uVar3);
  BUS_RegMaskedSet(&RAC->IEN,uVar3);
  uVar3 = 0x501800;
  if ((enabledCallbacks & 0x400000) == 0) uVar3 = 0x1800;
  if ((int)(enabledCallbacks << 8) < 0) uVar3 = uVar3 | 0x200000;
  if ((int)(enabledCallbacks << 7) < 0) uVar3 = uVar3 | 0x2000000;
  uVar2 = PROTIMER->IEN;
  if ((int)(enabledCallbacks << 6) < 0) uVar3 = uVar3 | 0x400;
  uVar1 = uVar2 & (uVar3 ^ uVar2);
  BUS_RegMaskedClear(&PROTIMER->IEN,uVar1);
  PROTIMER->IFC = uVar1;
  uVar3 = uVar3 & (uVar3 ^ uVar2);
  PROTIMER->IFC = uVar3;
  BUS_RegMaskedSet(&PROTIMER->IEN,uVar3);
  uVar3 = AGC->IEN;
  uVar2 = (enabledCallbacks << 5) >> 0x1f;
  uVar1 = uVar2 ^ uVar3;
  uVar3 = uVar3 & uVar1;
  BUS_RegMaskedClear(&AGC->IEN,uVar3);
  AGC->IFC = uVar3;
  uVar2 = uVar2 & uVar1;
  AGC->IFC = uVar2;
  BUS_RegMaskedSet(&AGC->IEN,uVar2);
}

void GENERIC_PHY_SetCallbacks(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  _DAT_e000e280 = 0x8000000;
  _DAT_e000e180 = 0x8000000;
  uVar2 = 0;
  availableCallbacks = 0;
  if (param_1 != 0) 
  {
    uVar1 = 0;
    do 
	{
      if (*(int *)(param_1 + uVar1 * 4) != 0) uVar2 = uVar2 | 1 << (uVar1 & 0xff);
      uVar1 = uVar1 + 1;
      availableCallbacks = uVar2;
    } while (uVar1 != 0x1b);
  }
  currentCallbacks = param_1;
  GENERIC_PHY_ConfigureCallbacks(0xffffffff);
  _DAT_e000e100 = 0x8000000;
  _DAT_e000e280 = 0x8000000;
}



void GENERIC_PHY_PacketTxCommon(void)

{
  if (((FRC->DFLCTRL & 7) == 0) && (SEQ->REG060 != 0)) FRC->WCNTCMP0 = BUFC_GetBytesAvailable() - 1;
  BUS_RegMaskedSet(&RAC->SR0,0x80);
  SEQ->REG000 &= 0xffffffbf;
}



bool GENERIC_PHY_PacketTx(void)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = CORE_EnterCritical();
  if ((PROTIMER_CCTimerIsEnabled(3) == 0) && (PROTIMER_LBTIsActive() == 0)) 
  {
    GENERIC_PHY_PacketTxCommon();
    RAC->CMD = 1;
    CORE_ExitCritical(uVar1);
    return false;
  }
  CORE_ExitCritical(uVar1);
  return true;
}



undefined4 GENERIC_PHY_SchedulePacketRx(undefined4 param_1,int param_2,int param_3,int param_4,char param_5,undefined param_6)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = param_4;
  uVar1 = CORE_EnterCritical();
  if (param_2 != 2) 
  {
    iVar2 = PROTIMER_CCTimerIsEnabled(3);
    if (iVar2 != 0) 
	{
      CORE_ExitCritical(uVar1);
      return 1;
    }
    PROTIMER_ClearRxEnable();
    PROTIMER_ClearTxEnable();
    scheduledRxLoop = param_5;
    uVar4 = SEQ->REG000;
    if (param_5 == '\0') uVar4 = uVar4 & 0xffffffbf; 
    else uVar4 = uVar4 | 0x40;
    SEQ->REG000 = uVar4;
    iVar3 = PROTIMER_ScheduleRxEnable(3,param_1,param_2,&SEQ,iVar3);
    if (iVar3 == 0) 
	{
      CORE_ExitCritical(uVar1);
      return 2;
    }
  }
  if (param_4 != 2) 
  {
    if ((PROTIMER_CCTimerIsEnabled(3) == 0) && (-1 < (int)(RAC->STATUS << 0x11))) 
	{
      CORE_ExitCritical(uVar1);
      return 4;
    }
    scheduledRxHardEnd = param_6;
    if ((param_4 == 1) && (param_2 != 2)) 
	{
      iVar3 = PROTIMER_GetCCTime(3);
      TIMING_RxWarmTimeGet();
      iVar2 = PROTIMER_UsToPrecntOverflow();
      param_4 = 0;
      param_3 = param_3 + iVar3 + iVar2;
    }
    pendedRxWindowEnd = 0;
    iVar3 = PROTIMER_ScheduleRxDisable(4,param_3,param_4);
    if (iVar3 == 0) 
	{
      PROTIMER_CCTimerStop(3);
      PROTIMER_ClearRxEnable();
      CORE_ExitCritical(uVar1);
      return 3;
    }
  }
  CORE_ExitCritical(uVar1);
  return 0;
}



undefined4 GENERIC_PHY_SchedulePacketTx(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = CORE_EnterCritical();
  if ((PROTIMER_CCTimerIsEnabled(3) == 0) && (PROTIMER_LBTIsActive() == 0)) 
  {
    GENERIC_PHY_PacketTxCommon();
    PROTIMER_ClearRxEnable();
    PROTIMER_ClearTxEnable();
    if (PROTIMER_ScheduleTxEnable(3,param_1,param_2) == 0) 
	{
      CORE_ExitCritical(uVar1);
      return 2;
    }
    CORE_ExitCritical(uVar1);
    return 0;
  }
  CORE_ExitCritical(uVar1);
  return 1;
}



void GENERIC_PHY_StopTx(void)

{
  RAC->CMD = 8;
}



uint GENERIC_PHY_PacketRxDataHelper(int param_1,uint param_2)

{
  BUFC_RxBufferBytesAvailable();
  if (param_1 == 0) BUFC_RxBufferDropBytes(param_2);
  else BUFC_RxBufferReadBytes(param_1,param_2 & 0xff);
  return param_2;
}



uint GENERIC_PHY_PacketRxAppendedInfoHelper(uint param_1,void *param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  void *apvStack28 [3];
  
  uVar1 = (FRC->TRAILRXDATA);
  apvStack28[0] = param_2;
  apvStack28[1] = (void *)param_3;
  apvStack28[2] = (void *)param_4;
  if (param_2 == NULL) BUFC_RxBufferDropBytes();
  else 
  {
    BUFC_RxBufferReadBytes(apvStack28,param_1 & 0xff,param_3,&FRC,param_1);
    uVar3 = 0x14;
    memset(param_2,0,0x14);
    bVar6 = (int)(uVar1 << 0x1a) < 0;
    uVar5 = param_1;
    if (bVar6) 
	{
      uVar5 = param_1 - 4 & 0xffff;
      uVar3 = *(undefined4 *)((int)apvStack28 + uVar5);
    }
    if (bVar6) *(undefined4 *)((int)param_2 + 0x10) = uVar3;
    if ((int)(uVar1 << 0x1b) < 0) 
	{
      uVar5 = uVar5 - 2 & 0xffff;
      *(uint *)((int)param_2 + 0xc) = *(uint *)((int)param_2 + 0xc) | (uint)*(ushort *)((int)apvStack28 + uVar5) << 0x10;
    }
    uVar4 = uVar1 << 0x1c;
    if ((int)uVar4 < 0) 
	{
      uVar5 = uVar5 - 2 & 0xffff;
      uVar4 = (uint)*(ushort *)((int)apvStack28 + uVar5) | *(uint *)((int)param_2 + 0xc);
      *(uint *)((int)param_2 + 0xc) = uVar4;
    }
    uVar2 = (undefined2)uVar4;
    bVar6 = (int)(uVar1 << 0x1d) < 0;
    if (bVar6) 
	{
      uVar5 = uVar5 - 2 & 0xffff;
      uVar2 = *(undefined2 *)((int)apvStack28 + uVar5);
    }
    if (bVar6) *(undefined2 *)((int)param_2 + 8) = uVar2;
    if ((int)(uVar1 << 0x1e) < 0) 
	{
      uVar5 = uVar5 - 1 & 0xffff;
      *(byte *)((int)param_2 + 6) = *(byte *)((int)apvStack28 + uVar5) >> 7;
    }
    bVar6 = (int)(uVar1 << 0x1f) < 0;
    if (bVar6) uVar5 = (uint)*(byte *)((int)apvStack28 + (uVar5 - 1 & 0xffff));
    if (bVar6) *(char *)((int)param_2 + 5) = (char)uVar5;
  }
  return param_1;
}



uint16_t GENERIC_PHY_PacketRxHelper(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = RADIO_RxTrailDataLength();
  uVar2 = param_1 - iVar1 & 0xffff;
  GENERIC_PHY_PacketRxDataHelper(param_2,uVar2);
  GENERIC_PHY_PacketRxAppendedInfoHelper(iVar1,param_3);
  return (uint16_t)uVar2;
}



void GENERIC_PHY_PacketRxGet(uint16_t *param_1)

{
  uint16_t uVar1;
  undefined4 uVar2;
  ushort local_28 [2];
  undefined4 local_24;
  undefined4 uStack32;
  undefined4 uStack28;
  undefined4 uStack24;
  undefined4 local_14;
  
  if (param_1 != (uint16_t *)0x0) 
  {
    uVar2 = BUFC_RxBufferGet();
    BUFC_RxLengthReadNext(local_28);
    if (local_28[0] == 0xffff) 
	{
      *(undefined4 *)(param_1 + 2) = 0;
      *param_1 = 0;
    }
    else {
      uVar1 = GENERIC_PHY_PacketRxHelper((uint)local_28[0],uVar2,&local_24);
      *(undefined4 *)(param_1 + 2) = uVar2;
      *param_1 = uVar1;
      *(undefined4 *)(param_1 + 4) = local_24;
      *(undefined4 *)(param_1 + 6) = uStack32;
      *(undefined4 *)(param_1 + 8) = uStack28;
      *(undefined4 *)(param_1 + 10) = uStack24;
      *(undefined4 *)(param_1 + 0xc) = local_14;
      if (*(code **)(currentCallbacks + 0x54) != (code *)0x0) 
	  {
        uVar2 = (**(code **)(currentCallbacks + 0x54))();
      }
      BUFC_RxBufferSet(uVar2);
    }
  }
  return;
}



void GENERIC_PHY_StartRx(int param_1)

{
  uint uVar1;
  int iVar2;
  
  if (param_1 != 0) 
  {
    write_volatile_4(FRC->WCNTCMP0,param_1 - 1);
  }
  iVar2 = BUFC_RxBufferGet();
  if ((iVar2 == 0) && (*(code **)(currentCallbacks + 0x54) != (code *)0x0)) 
  {
    (**(code **)(currentCallbacks + 0x54))();
    BUFC_RxBufferSet();
  }
  CORE_EnterCritical();
  uVar1 = (SEQ->REG000);
  write_volatile_4(SEQ->REG000,uVar1 & 0xffffffbf);
  CORE_ExitCritical();
  BUS_RegMaskedSet(&RAC->RXENSRCEN,2);
  return;
}



void GENERIC_PHY_ChannelSet(uint8_t channel)

{
  SYNTH_ChannelSet(channel,1);
  return;
}



void GENERIC_PHY_SeqAtomicLock(void)

{
  uint uVar1;
  
  read_volatile(RAC->SR0._0_1_);
  BUS_RegMaskedSet(&RAC->SR0,4);
  while (uVar1 = (RAC->SR0), (int)(uVar1 << 0xd) < 0) 
  {
    BUS_RegMaskedClear(&RAC->SR0,4);
    PROTIMER_DelayUs(2);
    BUS_RegMaskedSet(&RAC->SR0,4);
  }
  return;
}



void GENERIC_PHY_RadioIdle(int param_1,int param_2,int param_3)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = CORE_EnterCritical();
  if ((param_1 != 0) || (param_2 != 0)) {
    do 
	{
      uVar1 = (RAC->STATUS);
      if ((uVar1 << 4) >> 0x1c != 3) break;
      uVar1 = (SEQ->REG064);
    } while ((uVar1 & 0xf) != 3);
    if (param_2 != 0) 
	{
      GENERIC_PHY_SeqAtomicLock();
      BUS_RegMaskedSet(&RAC->CTRL,1);
      BUS_RegMaskedClear(&RAC->SR0,4);
      while (uVar1 = (RAC->STATUS), (uVar1 & 0xf000000) != 0) 
	  {
        write_volatile_4(RAC->CMD,0x40);
      }
    }
  }
  BUS_RegMaskedClear(&RAC->SR0,0x80);
  iVar3 = PROTIMER_CCTimerIsEnabled(3);
  if (iVar3 != 0) 
  {
    PROTIMER_CCTimerStop(3);
    PROTIMER_CCTimerStop(4);
  }
  PROTIMER_ClearRxEnable();
  PROTIMER_ClearTxEnable();
  GENERIC_PHY_SeqAtomicLock();
  uVar1 = (SEQ->REG000);
  write_volatile_4(SEQ->REG000,uVar1 | 0x40);
  BUS_RegMaskedClear(&RAC->RXENSRCEN,0xff);
  write_volatile_4(RAC->CMD,0x100);
  BUS_RegMaskedClear(&RAC->SR0,4);
  if (param_1 != 0) 
  {
    RADIO_RACRxAbort();
    write_volatile_4(RAC->CMD,0x20);
    PROTIMER_LBTStop();
    PROTIMER_CCTimerStop(4);
  }
  if (param_2 != 0) 
  {
    BUFC_RxBufferReset();
    BUS_RegMaskedClear(&RAC->CTRL,1);
    if (param_3 != 0) {
      uVar1 = (FRC->IEN);
      write_volatile_4(FRC->IFC,uVar1);
      uVar1 = (RAC->IEN);
      write_volatile_4(RAC->IFC,uVar1);
      uVar1 = (MODEM->IEN);
      write_volatile_4(MODEM->IFC,uVar1);
      uVar1 = (SYNTH->IEN);
      write_volatile_4(SYNTH->IFC,uVar1);
      uVar1 = (Peripherals::BUFC.IEN);
      write_volatile_4(Peripherals::BUFC.IFC,uVar1);
      uVar1 = (AGC->IEN);
      write_volatile_4(AGC->IFC,uVar1);
      write_volatile_4(PROTIMER->IFC,0x2f00050);
      pendedRxWindowEnd = 0;
    }
  }
  CORE_ExitCritical(uVar2);
  return;
}



void GENERIC_PHY_FRC_IRQCallback(void)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  RAC_SET *pRVar4;
  uint uVar5;
  
  uVar2 = CORE_EnterCritical();
  GENERIC_PHY_SeqAtomicLock();
  uVar5 = (FRC->IF);
  uVar1 = (SEQ->REG068);
  write_volatile_4(SEQ->REG068,uVar1 | uVar5);
  BUS_RegMaskedClear(&RAC->SR0,4);
  CORE_ExitCritical(uVar2);
  uVar1 = (FRC->IEN);
  uVar5 = uVar5 & uVar1;
  write_volatile_4(FRC->IFC,uVar5);
  if ((int)(uVar5 << 0x1b) < 0) 
  {
    (*currentCallbacks[2])();
    iVar3 = BUFC_RxBufferPacketAvailable();
    if (iVar3 != 0) 
	{
      write_volatile_4(FRC->IFS,0x10);
    }
  }
  else 
  {
    if ((int)(uVar5 << 0x19) < 0) 
	{
      uVar1 = (FRC->IF);
      if ((((int)(uVar1 << 0x1b) < 0) && (iVar3 = BUFC_RxBufferBytesAvailable(), iVar3 != 0)) && (uVar1 = (FRC->RXCTRL), (int)(uVar1 << 0x1e) < 0)) 
	  {
        bufcPendRxFrameError = 1;
      }
      else {
        if ((int)((uint)(byte)enabledCallbacks << 0x1c) < 0) 
		{
          (*currentCallbacks[3])();
        }
      }
    }
  }
  if (((uVar5 & 3) != 0) && ((int)((uint)(byte)enabledCallbacks << 0x1f) < 0)) 
  {
    (**currentCallbacks)();
  }
  if (((int)(uVar5 << 0x17) < 0) &&
     (uVar1 = (RAC->STATUS), (uVar1 & 0xf000000) == 0x6000000)) 
	 {
    if ((int)((uint)(byte)enabledCallbacks << 0x1b) < 0) 
	{
      (*currentCallbacks[4])();
    }
    iVar3 = BUFC_RxBufferPacketAvailable();
    if (iVar3 == 0) {
      uVar1 = (RAC->SR0);
      if ((uVar1 & 0x40) == 0) 
	  {
        RADIO_FRCErrorHandle();
      }
      uVar1 = (RAC->SR0);
      if (-1 < (int)(uVar1 << 0x18)) 
	  {
        write_volatile_4(RAC->CMD,8);
        uVar1 = (SEQ->REG00C);
        if ((uVar1 & 0x200) == 0) 
		{
          pRVar4 = (RAC_SET *)&Peripherals::RAC_CLR;
        }
        else 
		{
          pRVar4 = &Peripherals::RAC_SET;
        }
        pRVar4->RXENSRCEN = 2;
      }
      write_volatile_4(RAC->CMD,0x40);
    }
    else 
	{
      write_volatile_4(FRC->IFS,0x100);
    }
  }
  if (((int)(uVar5 << 0x1d) < 0) && (uVar1 = (FRC->CTRL), -1 < (int)(uVar1 << 0x1f))) 
  {
    (*currentCallbacks[1])(8);
  }
  if ((int)(uVar5 << 0x1c) < 0) 
  {
    (*currentCallbacks[1])(2);
  }
  if ((int)(uVar5 << 0x11) < 0) 
  {
    (*currentCallbacks[7])();
  }
  if ((int)(uVar5 << 0x12) < 0) 
  {
    (*currentCallbacks[8])();
  }
  if (((pendedRxWindowEnd != '\0') && (iVar3 = BUFC_RxBufferPacketAvailable(), iVar3 == 0)) && (pendedRxWindowEnd = '\0', (int)((uint)(byte)enabledCallbacks << 0x19) < 0)) 
  {
    (*currentCallbacks[6])(1);
  }
  if (-1 < (int)(uVar5 << 0x1a)) 
  {
    return;
  }
                    // WARNING: Could not recover jumptable at 0x00010c08. Too many branches
                    // WARNING: Treating indirect jump as call
  (*currentCallbacks[5])();
  return;
}



void GENERIC_PHY_SeqAtomicUnlock(void)

{
  BUS_RegMaskedClear(&RAC->SR0,4);
  return;
}



void GENERIC_PHY_TxDisable(void)

{
  write_volatile_4(RAC->CMD,0x20);
  return;
}



uint32_t GENERIC_PHY_PreviousTxTime(void)

{
  uint32_t uVar1;
  
  uVar1 = PROTIMER_GetCCTime(1);
  return uVar1;
}



void GENERIC_PHY_RACConfig(void)

{
  RADIO_SeqInit(&genericSeqProg,genericSeqProg_size);
  memset(&Peripherals::SEQ,0,100);
  write_volatile_4(RAC->SR0,0);
  write_volatile_4(RAC->SR1,0);
  write_volatile_4(RAC->SR2,0);
  TEMPCAL_Init();
  return;
}



void GENERIC_PHY_FrameConfig(void)

{
  RADIO_Config();
  return;
}



void GENERIC_PHY_DirectModeConfig(byte *param_1)

{
  uint uVar1;
  
  if (param_1 != (byte *)0x0) 
  {
    RADIOCMU_ClockEnable(0x67400,1);
    CMU_ClockEnable(0x82500,1);
    uVar1 = (uint)*param_1;
    BUS_RegMaskedClear(&MODEM->CTRL2,0xc00);
    if (uVar1 == 0) 
	{
      BUS_RegMaskedSet(&MODEM->CTRL2,0);
    }
    else {
      uVar1 = (uint)param_1[4];
      if (uVar1 == 0) 
	  {
        BUS_RegMaskedSet(&MODEM->CTRL2,0x800);
      }
      else 
	  {
        BUS_RegMaskedSet(&MODEM->CTRL2,0xc00);
        uVar1 = 4;
      }
      uVar1 = uVar1 | 1;
    }
    if (param_1[1] != 0) 
	{
      BUS_RegMaskedClear(&MODEM->CTRL2,0x200);
      if (param_1[3] == 0) 
	  {
        BUS_RegMaskedSet(&MODEM->CTRL2,0x200);
      }
      else 
	  {
        BUS_RegMaskedSet(&MODEM->CTRL2,0);
        uVar1 = uVar1 | 4;
      }
      uVar1 = uVar1 | 2;
    }
    if (param_1[2] == 0) 
	{
      BUS_RegMaskedClear(&MODEM->CTRL2,0x100);
    }
    else 
	{
      BUS_RegMaskedSet(&MODEM->CTRL2,0x100);
    }
    write_volatile_4(MODEM->ROUTELOC0,(uint)param_1[8] << 0x10 | (uint)param_1[5] << 8 | (uint)param_1[0xb]);
    BUS_RegMaskedClear(&MODEM->ROUTEPEN,7);
    BUS_RegMaskedSet(&MODEM->ROUTEPEN,uVar1);
    if ((int)(uVar1 << 0x1f) < 0) 
	{
      GPIO_PinModeSet(param_1[0xc],param_1[0xd],1,0);
    }
    if ((int)(uVar1 << 0x1e) < 0) 
	{
      GPIO_PinModeSet(param_1[6],param_1[7],4,0);
    }
    if ((int)(uVar1 << 0x1d) < 0) 
	{
      GPIO_PinModeSet(param_1[9],param_1[10],4,0);
      return;
    }
  }
  return;
}



void GENERIC_PHY_PROTIMERConfig(void)

{
  BUS_RegMaskedClear(&PROTIMER->IEN,0x3f3fff7);
  write_volatile_4(PROTIMER->IFC,0x3f3fff7);
  write_volatile_4(PROTIMER->CTRL,0);
  write_volatile_4(PROTIMER->BASECNT,0);
  write_volatile_4(PROTIMER->WRAPCNT,0);
  write_volatile_4(PROTIMER->BASECNTTOP,0xffff);
  write_volatile_4(PROTIMER->WRAPCNTTOP,0xffffffff);
  write_volatile_4(PROTIMER->LBTCTRL,0);
  return;
}



uint16_t GENERIC_PHY_ChannelGet(void)

{
  uint uVar1;
  
  uVar1 = (SYNTH->CHCTRL);
  return (uint16_t)((ushort)uVar1 & 0xff);
}



void GENERIC_PHY_SYNTH_IRQHandler(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (SYNTH->IF);
  uVar2 = (SYNTH->IEN);
  write_volatile_4(SYNTH->IFC,uVar1 & uVar2);
  return;
}



void GENERIC_PHY_ResetPacketConfig(void)

{
  uint uVar1;
  
  CORE_EnterCritical();
  uVar1 = (SEQ->REG000);
  write_volatile_4(SEQ->REG000,uVar1 & 0xfffffff8);
  CORE_ExitCritical();
  BUS_RegMaskedClear(&FRC->DFLCTRL,7);
  BUS_RegMaskedSet(&FRC->DFLCTRL,0);
  return;
}



void GENERIC_PHY_ConfigureVariableLength(uint param_1,uint param_2,int param_3,int param_4)

{
  uint uVar1;
  
  GENERIC_PHY_ResetPacketConfig();
  write_volatile_4(FRC->WCNTCMP1,param_1 & 0xfff);
  if ((param_2 & 0xf) < 9) 
  {
    uVar1 = 1;
  }
  else 
  {
    if (param_4 == 0) 
	{
      uVar1 = 3;
    }
    else 
	{
      uVar1 = 4;
    }
  }
  write_volatile_4(FRC->MAXLENGTH,0xfff);
  BUS_RegMaskedClear(&FRC->DFLCTRL,0xff07);
  BUS_RegMaskedSet(&FRC->DFLCTRL,(param_2 & 0xf) << 0xc | (param_3 - 1U & 0xf) << 8 | uVar1);
  return;
}



void GENERIC_PHY_ConfigureFixedLength(int param_1)

{
  GENERIC_PHY_ResetPacketConfig();
  write_volatile_4(FRC->WCNTCMP0,param_1 - 1U & 0xfff);
  return;
}



void GENERIC_PHY_ConfigureFrameType(byte *param_1)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_1 == (byte *)0x0) 
  {
    CORE_EnterCritical();
    uVar2 = (SEQ->REG000);
    write_volatile_4(SEQ->REG000,uVar2 & 0xfffffff8);
    CORE_ExitCritical();
    write_volatile_4(SEQ->REG05C,0);
    write_volatile_4(SEQ->REG060,0);
    return;
  }
  GENERIC_PHY_ResetPacketConfig();
  write_volatile_1(SEQ->REG05C._0_1_,*param_1);
  write_volatile_1(SEQ->REG05C._1_1_,param_1[1]);
  uVar3 = 0;
  write_volatile_1(SEQ->REG05C._2_1_,0);
  write_volatile_4(SEQ->REG060,*(uint *)(param_1 + 4));
  uVar2 = 0;
  do 
  {
    if (*(char *)(*(int *)(param_1 + 8) + uVar3) != '\0') 
	{
      uVar2 = uVar2 | 1 << (uVar3 & 0xff) & 0xffU;
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 != 8);
  write_volatile_1(SEQ->REG05C._3_1_,(char)uVar2);
  uVar2 = (uint)param_1[1];
  if (uVar2 != 0) 
  {
    while (-1 < (int)(uVar2 << 0x1f)) 
	{
      cVar1 = read_volatile_1(SEQ->REG05C._2_1_);
      uVar2 = uVar2 >> 1;
      write_volatile_1(SEQ->REG05C._2_1_,cVar1 + '\x01');
    }
  }
  write_volatile_4(FRC->WCNTCMP0,*param_1 + 1);
  CORE_EnterCritical();
  uVar2 = (SEQ->REG000);
  write_volatile_4(SEQ->REG000,uVar2 | 7);
  CORE_ExitCritical();
  return;
}



bool GENERIC_PHY_EnableAddressFiltering(void)

{
  uint uVar1;
  
  CORE_EnterCritical();
  uVar1 = (SEQ->REG000);
  write_volatile_4(SEQ->REG000,uVar1 | 0x10);
  CORE_ExitCritical();
  return SUB41((uVar1 << 0x1b) >> 0x1f,0);
}



bool GENERIC_PHY_DisableAddressFiltering(void)

{
  uint uVar1;
  
  CORE_EnterCritical();
  uVar1 = (SEQ->REG000);
  write_volatile_4(SEQ->REG000,uVar1 & 0xffffffef);
  CORE_ExitCritical();
  return SUB41((uVar1 << 0x1b) >> 0x1f,0);
}



bool GENERIC_PHY_IsEnabledAddressFiltering(void)

{
  uint uVar1;
  
  uVar1 = (SEQ->REG000);
  return SUB41((uVar1 << 0x1b) >> 0x1f,0);
}



void GENERIC_PHY_ResetAddressFiltering(void)

{
  memset(&SEQ->REG010,0,0x4c);
  addressFilterMatchTable = 0;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void GENERIC_PHY_Init(void)

{
  RADIO_Init();
  _DAT_e000e280 = 0x40000000;
  _DAT_e000e180 = 0x40000000;
  GENERIC_PHY_RACConfig();
  RADIO_PTI_Enable();
  BUS_RegMaskedClear(&RAC->CTRL,1);
  RADIO_RegisterIrqCallback(1,GENERIC_PHY_FRC_IRQCallback);
  RADIO_RegisterIrqCallback(2,GENERIC_PHY_MODEM_IRQCallback);
  RADIO_RegisterIrqCallback(5,GENERIC_PHY_RAC_IRQCallback);
  RADIO_RegisterIrqCallback(7,GENERIC_PHY_PROTIMER_IRQCallback);
  RADIO_RegisterIrqCallback(9,GENERIC_PHY_AGC_IRQCallback);
  GENERIC_PHY_ResetAddressFiltering();
  PROTIMER_Init();
  PROTIMER_Start();
  TIMING_InitStimer();
  TIMING_RxSearchTimeSet(0);
  TIMING_TxToRxSearchTimeSet(0);
  TIMING_RxWarmTimeSet(100);
  TIMING_TxToRxTimeSet(100);
  TIMING_TxToTxTimeSet(100);
  TIMING_RxToTxTimeSet(100);
  TIMING_RxFrameToTxTimeSet(100);
  TIMING_TxWarmTimeSet(100);
  PROTIMER_CCTimerCapture(0,0xc00000);
  PROTIMER_CCTimerCapture(1,0x200000);
  RFRAND_SeedProtimerRandom();
  return;
}



bool GENERIC_PHY_ConfigureAddressFiltering(undefined *param_1)

{
  GENERIC_PHY_ResetAddressFiltering();
  if (param_1 == (undefined *)0x0) 
  {
    return true;
  }
  write_volatile_1(SEQ->REG054._0_1_,*param_1);
  if ((byte)param_1[2] < 9) 
  {
    write_volatile_1(SEQ->REG054._2_1_,param_1[2]);
    write_volatile_1(SEQ->REG054._1_1_,param_1[1]);
    if ((byte)param_1[3] < 9) {
      write_volatile_1(SEQ->REG054._3_1_,param_1[3]);
      write_volatile_1(SEQ->REG058._2_1_,param_1[8]);
      addressFilterMatchTable = *(undefined4 *)(param_1 + 4);
      GENERIC_PHY_SetAddressFilteringMatchTable();
      return true;
    }
  }
  return false;
}



bool GENERIC_PHY_EnableAddress(uint param_1,uint param_2)

{
  if ((param_1 < 2) && (param_2 < 4)) 
  {
    *(byte *)((int)&SEQ->REG058 + param_1) =
         (byte)(1 << (param_2 & 0xff)) | *(byte *)((int)&SEQ->REG058 + param_1);
    GENERIC_PHY_SetAddressFilteringMatchTable();
    return true;
  }
  return false;
}



bool GENERIC_PHY_DisableAddress(uint param_1,uint param_2)

{
  if ((param_1 < 2) && (param_2 < 4)) 
  {
    *(byte *)((int)&SEQ->REG058 + param_1) =
         *(byte *)((int)&SEQ->REG058 + param_1) & ~(byte)(1 << (param_2 & 0xff));
    GENERIC_PHY_SetAddressFilteringMatchTable();
    return true;
  }
  return false;
}



bool GENERIC_PHY_SetAddressData(uint param_1,uint param_2,uint param_3,uint param_4,byte param_5,byte *param_6)

{
  uint *puVar1;
  uint uVar2;
  byte *pbVar3;
  
  uVar2 = (uint)param_5;
  if ((((param_1 < 2) && (param_2 < 2)) && (param_4 < uVar2)) && (((uVar2 < 9 && (param_3 < 4)) && (param_6 != (byte *)0x0)))) 
  {
    GENERIC_PHY_DisableAddress(param_1,param_3);
    puVar1 = (uint *)((param_4 + 0x84003c5 + param_2 * 8) * 4);
    for (pbVar3 = param_6; (int)(pbVar3 + (param_4 - (int)param_6)) < (int)uVar2;pbVar3 = pbVar3 + 1) 
	{
      *puVar1 = (uint)*pbVar3 << (param_3 << 3 & 0xff) | *puVar1 & ~(0xff << (param_3 << 3 & 0xff));
      puVar1 = puVar1 + 1;
    }
    return true;
  }
  return false;
}



int32_t GENERIC_PHY_SetIeeePanId(uint param_1,byte *param_2)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  
  bVar2 = GENERIC_PHY_SetAddressData(0,0,param_1,0,2,param_2);
  uVar3 = (uint)bVar2;
  if (uVar3 != 0) 
  {
    if (param_1 < 4) 
	{
      bVar1 = read_volatile_1(SEQ->REG058._0_1_);
      write_volatile_1(SEQ->REG058._0_1_,(byte)(1 << (param_1 & 0xff)) | bVar1);
    }
    else 
	{
      uVar3 = 0;
    }
  }
  return uVar3;
}



int32_t GENERIC_PHY_SetIeeeShortAddress(uint param_1,byte *param_2)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  
  bVar2 = GENERIC_PHY_SetAddressData(1,0,param_1,2,4,param_2);
  uVar3 = (uint)bVar2;
  if (uVar3 != 0) 
  {
    if (param_1 < 4) 
	{
      bVar1 = read_volatile_1(SEQ->REG058._1_1_);
      write_volatile_1(SEQ->REG058._1_1_,(byte)(1 << (param_1 & 0xff)) | bVar1);
    }
    else 
	{
      uVar3 = 0;
    }
  }
  return uVar3;
}



int32_t GENERIC_PHY_SetIeeeLongAddress(uint param_1,byte *param_2)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  
  bVar2 = GENERIC_PHY_SetAddressData(1,1,param_1,0,8,param_2);
  uVar3 = (uint)bVar2;
  if (uVar3 != 0) 
  {
    if (param_1 < 4) 
	{
      bVar1 = read_volatile_1(SEQ->REG058._1_1_);
      write_volatile_1(SEQ->REG058._1_1_,(byte)(1 << (param_1 & 0xff)) | bVar1);
    }
    else 
	{
      uVar3 = 0;
    }
  }
  return uVar3;
}



undefined GENERIC_PHY_SetAddress(uint param_1,uint param_2,byte *param_3,int param_4)

{
  bool bVar1;
  
  bVar1 = GENERIC_PHY_SetAddressData(param_1,param_1,param_2,0,*(byte *)((int)&SEQ->REG054 + param_1 + 2),param_3);
  if ((param_4 != 0) && (bVar1 != false)) 
  {
    bVar1 = GENERIC_PHY_EnableAddress(param_1,param_2);
    return bVar1;
  }
  return bVar1;
}



bool GENERIC_PHY_EnableIEEE802154(void)

{
  uint uVar1;
  
  CORE_EnterCritical();
  uVar1 = (SEQ->REG000);
  write_volatile_4(SEQ->REG000,uVar1 | 0x80);
  CORE_ExitCritical();
  return (bool)((byte)uVar1 >> 7);
}



bool GENERIC_PHY_DisableIEEE802154(void)

{
  uint uVar1;
  
  CORE_EnterCritical();
  uVar1 = (SEQ->REG000);
  write_volatile_4(SEQ->REG000,uVar1 & 0xff7f);
  CORE_ExitCritical();
  return (bool)((byte)uVar1 >> 7);
}



bool GENERIC_PHY_IsEnabledIEEE802154(void)

{
  uint uVar1;
  
  uVar1 = (SEQ->REG000);
  return (bool)((byte)uVar1 >> 7);
}



void GENERIC_PHY_TimerStart(undefined4 param_1,undefined4 param_2)

{
  PROTIMER_CCTimerStart(2,param_1,param_2);
  return;
}



void GENERIC_PHY_TimerStop(void)

{
  PROTIMER_CCTimerStop(2);
  return;
}



uint32_t GENERIC_PHY_TimerGetTimeout(void)

{
  uint32_t uVar1;
  
  uVar1 = PROTIMER_GetCCTime(2);
  return uVar1;
}



bool GENERIC_PHY_TimerExpired(void)

{
  uint uVar1;
  
  uVar1 = (PROTIMER->IF);
  return SUB41((uVar1 << 0x15) >> 0x1f,0);
}



bool GENERIC_PHY_TimerIsRunning(void)

{
  undefined uVar1;
  
  uVar1 = PROTIMER_CCTimerIsEnabled(2);
  return (bool)uVar1;
}



bool GENERIC_PHY_CanModifyAck(void)

{
  uint uVar1;
  
  uVar1 = (RAC->STATUS);
  uVar1 = (uVar1 << 4) >> 0x1c;
  if (1 < uVar1 - 2) 
  {
    return uVar1 == 7;
  }
  return true;
}


