
void GENERIC_PHY_RAC_IRQCallback(void)

{
  uint32_t uVar1;
  uint32_t flags;
  
  flags = RAC->IEN & RAC->IF;
  RAC->IFC = flags;
  if ((int)(flags << 0x1f) < 0) (**(code **)(currentCallbacks + 0x3c))();
  if ((int)(flags << 0x1d) < 0) (**(code **)(currentCallbacks + 0x38))();
  if ((int)(flags << 6) < 0) 
  {
    if ((int)((uint)DAT_20003136 << 0x1f) < 0) (**(code **)(currentCallbacks + 0x40))();
    PA_PeakDetectorHighRun();
  }
  if ((int)(flags << 5) < 0) 
  {
    if ((int)((uint)DAT_20003136 << 0x1e) < 0) (**(code **)(currentCallbacks + 0x44))();
    PA_PeakDetectorLowRun();
  }
  if ((int)(flags << 4) < 0) 
  {
    if ((int)((uint)DAT_20003136 << 0x1d) < 0) (**(code **)(currentCallbacks + 0x48))();
    PA_BatHighRun();
  }
  uVar1 = flags & 0xff0000;
  if (uVar1 != 0) 
  {
    if ((flags & 0x40000) != 0) 
	{
      if ((int)((uint)DAT_20003136 << 0x1c) < 0) (**(code **)(currentCallbacks + 0x4c))();
      uVar1 = flags & 0xfb0000;
    }
    if ((int)(uVar1 << 0xf) < 0) 
	{
      if ((int)((uint)enabledCallbacks << 0x19) < 0) (**(code **)(currentCallbacks + 0x18))(2);
      uVar1 = uVar1 & 0xfffeffff;
    }
    if ((int)(uVar1 << 0xe) < 0) 
	{
      if ((int)((uint)enabledCallbacks << 0x1e) < 0) (**(code **)(currentCallbacks + 4))(0x10);
      uVar1 = uVar1 & 0xfffdffff;
    }
    if ((int)(uVar1 << 0xb) < 0) 
	{
      if ((int)((uint)DAT_20003135 << 0x1e) < 0) (**(code **)(currentCallbacks + 0x24))();
      uVar1 = uVar1 & 0xffefffff;
    }
    if ((*(code **)(currentCallbacks + 0x50) != FUN_00000000) && (uVar1 != 0)) 
	{
                    // WARNING: Could not recover jumptable at 0x00011934. Too many branches
                    // WARNING: Treating indirect jump as call
      (**(code **)(currentCallbacks + 0x50))(uVar1);
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
                    // WARNING: Could not recover jumptable at 0x00011988. Too many branches
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
                    // WARNING: Could not recover jumptable at 0x000119a8. Too many branches
                    // WARNING: Treating indirect jump as call
    (**(code **)(currentCallbacks + 0x68))();
    return;
  }
}



void RADIO_RACRxAbort(undefined4 param_1,undefined4 param_2,int param_3)

{
  CORE_irqState_t irqState;
  uint32_t state;

  irqState = CORE_EnterCritical();
  state = (RAC->STATUS & RAC_STATUS_STATE_Msk) >> RAC_STATUS_STATE_Pos;
  if (state == 3) 
  {
	SEQ->REG06C &= 0xffffff0f;
	SEQ->REG06C |= 0xe0;
	FRC->CMD = 1;
  }
  CORE_ExitCritical(irqState);
}



void GENERIC_PHY_PROTIMER_IRQCallback(void)

{
  uint16_t uVar1;
  int iVar2;
  CORE_irqState_t irqState;
  uint uVar3;
  code *pcVar4;
  uint uVar5;
  
  iVar2 = PROTIMER_LBTIsActive();
  uVar3 = PROTIMER->IF;
  uVar5 = PROTIMER->IEN;
  flags = uVar5 & uVar3;
  PROTIMER->IFC = flags;
  if ((int)(flags << 0x14) < 0) PROTIMER_CCTimerStop(3);
  if ((flags & 0x500000) == 0) 
  {
    if (-1 < (int)(flags << 0x13)) goto LAB_00011a7e;
    if (iVar2 != 0) goto LAB_00011a18;
    PROTIMER_CCTimerStop(3);
    PROTIMER_CCTimerStop(4);
    PROTIMER_ClearRxEnable();
    irqState = CORE_EnterCritical();
    if (scheduledRxHardEnd != '\0') RADIO_RACRxAbort();
    uVar3 = RAC->STATUS;
    if (((uVar3 << 4) >> 0x1c == 3) || (uVar1 = BUFC_RxBufferBytesAvailable(), uVar1 != 0)) 
	{
      uVar1 = 1;
      pendedRxWindowEnd = scheduledRxLoop;
    }
    CORE_ExitCritical(irqState);
    if ((uVar1 != 0) || (-1 < (int)((uint)enabledCallbacks << 0x19))) goto LAB_00011a7e;
    pcVar4 = *(code **)(currentCallbacks + 0x18);
    uVar3 = 1;
  }
  else 
  {
LAB_00011a18:
    pcVar4 = *(code **)(currentCallbacks + 0x58);
    uVar3 = flags;
  }
  (*pcVar4)(uVar3);
LAB_00011a7e:
  if ((int)(flags << 10) < 0) (**(code **)(currentCallbacks + 0x5c))();
  if ((int)(flags << 6) < 0) (**(code **)(currentCallbacks + 0x60))();
  if (-1 < (int)(flags << 0x15)) return;
                    // WARNING: Could not recover jumptable at 0x00011aa4. Too many branches
                    // WARNING: Treating indirect jump as call
  (**(code **)(currentCallbacks + 100))();
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
  do {
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
      if ((uVar4 & bVar2) == uVar4) 
	  {
        bVar2 = read_volatile_1(SEQ->REG054._2_1_);
        for (iVar10 = 0; iVar10 < (int)(uint)bVar2; iVar10 = iVar10 + 1) 
		{
          puVar11 = puVar11 + 1;
          if (((*puVar11 >> (uVar9 & 0xff) ^ *puVar11 >> (uVar5 & 0xff)) & 0xff) != 0)
          goto LAB_00011b52;
        }
        uVar12 = uVar12 | addressFilterMatchTable >> (local_38 & 0xff) & 0x1f;
      }
LAB_00011b52:
      bVar2 = read_volatile_1(SEQ->REG058._1_1_);
      if ((uVar4 & bVar2) == uVar4) 
	  {
        bVar2 = read_volatile_1(SEQ->REG054._3_1_);
        puVar11 = &SEQ->REG030;
        for (iVar10 = 0; iVar10 < (int)(uint)bVar2; iVar10 = iVar10 + 1) 
		{
          puVar11 = puVar11 + 1;
          if (((*puVar11 >> (uVar9 & 0xff) ^ *puVar11 >> (uVar5 & 0xff)) & 0xff) != 0)
          goto LAB_00011b9a;
        }
        uVar7 = uVar7 | addressFilterMatchTable >> (uVar8 + 1 & 0xff) & 0x108421;
      }
LAB_00011b9a:
      uVar9 = uVar9 + 8;
    }
    local_34 = local_34 | uVar7 << (uVar6 & 0xff) | uVar12 << (uVar1 & 0xff);
    uVar5 = uVar5 + 8;
    uVar3 = uVar6;
    if (uVar6 == 4) 
	{
      SEQ->REG010 = local_34;
      return;
    }
  } while( true );
}



void GENERIC_PHY_ConfigureCallbacks(uint32_t callbacks)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  _enabledCallbacks = callbacks & availableCallbacks;
  uVar3 = 0x161;
  if ((_enabledCallbacks & 1) != 0) uVar3 = 0x163;
  if (_enabledCallbacks & 0x02) uVar3 = uVar3 | 0xc;
  if (_enabledCallbacks & 0x80) uVar3 = uVar3 | 0x4000;
  uVar2 = FRC->IEN;
  if (_enabledCallbacks & 0x100) uVar3 = uVar3 | 0x2000;
  uVar1 = (uVar3 ^ uVar2) & 0xffffffef;
  uVar2 = FRC->IEN & uVar1;
  BUS_RegMaskedClear(&FRC->IEN,uVar2);
  FRC->IFC = uVar2;
  uVar3 = uVar3 & uVar1;
  FRC->IFC = uVar3;
  BUS_RegMaskedSet(&FRC->IEN,uVar3);
  if ((_enabledCallbacks & 0x400) == 0) uVar3 = 0;
  else uVar3 = 0x2000;
  if (_enabledCallbacks & 0x800) uVar3 = uVar3 | 0x200;
  if (_enabledCallbacks & 0x1000) uVar3 = uVar3 | 0x400;
  uVar2 = MODEM->IEN;
  if (_enabledCallbacks & 0x2000) uVar3 = uVar3 | 0x800;
  uVar1 = uVar2 & (uVar3 ^ uVar2);
  BUS_RegMaskedClear(&MODEM->IEN,uVar1);
  MODEM->IFC = uVar1;
  uVar3 = uVar3 & (uVar3 ^ uVar2);
  MODEM->IFC = uVar3;
  BUS_RegMaskedSet(&MODEM->IEN,uVar3);
  if ((_enabledCallbacks & 0x4000) == 0) uVar3 = 0;
  else uVar3 = 4;
  if (_enabledCallbacks & 0x8000) uVar3 = uVar3 | 1;
  if (_enabledCallbacks & 0x80000) uVar3 = uVar3 | 0x40000;
  if (_enabledCallbacks & 0x02) uVar3 = uVar3 | 0x20000;
  if (_enabledCallbacks & 0x40) uVar3 = uVar3 | 0x10000;
  if (_enabledCallbacks & 0x200) uVar3 = uVar3 | 0x100000;
  uVar2 = RAC->IEN;
  if (_enabledCallbacks & 0x100000) uVar3 = uVar3 | 0xe80000;
  uVar1 = uVar2 & (uVar3 ^ uVar2);
  BUS_RegMaskedClear(&RAC->IEN,uVar1);
  RAC->IFC = uVar1;
  uVar3 = uVar3 & (uVar3 ^ uVar2);
  RAC->IFC = uVar3;
  BUS_RegMaskedSet(&RAC->IEN,uVar3);
  uVar3 = 0x501800;
  if ((_enabledCallbacks & 0x400000) == 0) uVar3 = 0x1800;
  if (_enabledCallbacks & 0x800000) uVar3 = uVar3 | 0x200000;
  if (_enabledCallbacks & 0x1000000) uVar3 = uVar3 | 0x2000000;
  uVar2 = PROTIMER->IEN;
  if (_enabledCallbacks & 0x2000000) uVar3 = uVar3 | 0x400;
  uVar1 = uVar2 & (uVar3 ^ uVar2);
  BUS_RegMaskedClear(&PROTIMER->IEN,uVar1);
  PROTIMER->IFC = uVar1;
  uVar3 = uVar3 & (uVar3 ^ uVar2);
  PROTIMER->IFC = uVar3;
  BUS_RegMaskedSet(&PROTIMER->IEN,uVar3);
  uVar3 = AGC->IEN;
  uVar2 = (_enabledCallbacks << 5) >> 0x1f;
  uVar1 = uVar2 ^ uVar3;
  uVar3 = uVar3 & uVar1;
  BUS_RegMaskedClear(&AGC->IEN,uVar3);
  AGC->IFC = uVar3;
  uVar2 = uVar2 & uVar1;
  AGC->IFC = uVar2;
  BUS_RegMaskedSet(&AGC->IEN,uVar2);
}



void GENERIC_PHY_SetCallbacks(uint32_t *callbacks)

{
  uint uVar1;
  uint uVar2;
  
  _DAT_e000e280 = 0x8000000;
  _DAT_e000e180 = 0x8000000;
  uVar2 = 0;
  availableCallbacks = 0;
  if (callbacks != NULL) 
  {
    uVar1 = 0;
    do 
	{
      if (callbacks[uVar1] != 0) uVar2 = uVar2 | 1 << (uVar1 & 0xff);
      uVar1 = uVar1 + 1;
      availableCallbacks = uVar2;
    } while (uVar1 != 0x1b);
  }
  currentCallbacks = callbacks;
  GENERIC_PHY_ConfigureCallbacks(0xffffffff);
  _DAT_e000e100 = 0x8000000;
  _DAT_e000e280 = 0x8000000;
}



void GENERIC_PHY_PacketTxCommon(void)

{
  if (((FRC->DFLCTRL & 7) == 0) && (SEQ->REG060 != 0)) FRC->WCNTCMP0 = BUFC_GetBytesAvailable(0) - 1;
  BUS_RegMaskedSet(&RAC->SR0,0x80);
  SEQ->REG000 &= 0xffffffbf;
}



RAIL_Status_t GENERIC_PHY_PacketTx(void)

{
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  if ((PROTIMER_CCTimerIsEnabled(3) == false) && (PROTIMER_LBTIsActive() == false)) 
  {
    GENERIC_PHY_PacketTxCommon();
    RAC->CMD = 1;
    CORE_ExitCritical(irqState);
    return RAIL_STATUS_NO_ERROR;
  }
  CORE_ExitCritical(irqState);
  return RAIL_STATUS_INVALID_PARAMETER;
}



undefined4 GENERIC_PHY_SchedulePacketRx(undefined4 param_1,int param_2,int param_3,int param_4,char param_5,undefined param_6)

{
  CORE_irqState_t irqState;
  uint32_t us;
  
  irqState = CORE_EnterCritical();
  if (param_2 != 2) 
  {
    if (PROTIMER_CCTimerIsEnabled(3) != false) 
	{
      CORE_ExitCritical(irqState);
      return 1;
    }
    PROTIMER_ClearRxEnable();
    PROTIMER_ClearTxEnable();
    scheduledRxLoop = param_5;
    if (param_5 == '\0') SEQ->REG000 &= 0xffffffbf; //uVar4 = uVar4 & 0xffffffbf;
    else SEQ->REG000 |= 0x40; //uVar4 = uVar4 | 0x40;
    if (PROTIMER_ScheduleRxEnable(3,param_1,param_2,&SEQ,param_4) == 0) 
	{
      CORE_ExitCritical(irqState);
      return 2;
    }
  }
  if (param_4 != 2) 
  {
    if ((PROTIMER_CCTimerIsEnabled(3) == false) && (-1 < (int)(RAC->STATUS << 0x11))) 
	{
      CORE_ExitCritical(irqState);
      return 4;
    }
    scheduledRxHardEnd = param_6;
    if ((param_4 == 1) && (param_2 != 2)) 
	{
      us = TIMING_RxWarmTimeGet();
      param_4 = 0;
      param_3 = param_3 + PROTIMER_GetCCTime(3) + (int)PROTIMER_UsToPrecntOverflow(us);
    }
    pendedRxWindowEnd = 0;
    if (PROTIMER_ScheduleRxDisable(4,param_3,param_4) == 0) 
	{
      PROTIMER_CCTimerStop(3);
      PROTIMER_ClearRxEnable();
      CORE_ExitCritical(irqState);
      return 3;
    }
  }
  CORE_ExitCritical(irqState);
  return 0;
}



undefined4 GENERIC_PHY_SchedulePacketTx(undefined4 param_1,undefined4 param_2)

{
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  if ((PROTIMER_CCTimerIsEnabled(3) == false) && (iPROTIMER_LBTIsActive() == 0)) 
  {
    GENERIC_PHY_PacketTxCommon();
    PROTIMER_ClearRxEnable();
    PROTIMER_ClearTxEnable();
    if (PROTIMER_ScheduleTxEnable(3,param_1,param_2) == 0) 
	{
      BUS_RegMaskedClear(&RAC->SR0,0x80);
      CORE_ExitCritical(irqState);
      return 2;
    }
    CORE_ExitCritical(irqState);
    return 0;
  }
  CORE_ExitCritical(irqState);
  return 1;
}




void GENERIC_PHY_StopTx(void)

{
  RAC->CMD = RAC_CMD_CLEARTXEN_Msk; //8;
}



uint16_t GENERIC_PHY_PacketRxDataHelper(int param_1,uint param_2)

{
  BUFC_RxBufferBytesAvailable(); //???
  if (param_1 == 0) BUFC_RxBufferDropBytes(param_2);
  else BUFC_RxBufferReadBytes((uint8_t *)param_1,(ushort)param_2 & 0xff);
  return (uint16_t)param_2;
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
    BUFC_RxBufferReadBytes((uint8_t *)apvStack28,(ushort)param_1 & 0xff);
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



uint GENERIC_PHY_PacketRxHelper(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = RADIO_RxTrailDataLength();
  uVar2 = param_1 - RADIO_RxTrailDataLength() & 0xffff;
  GENERIC_PHY_PacketRxDataHelper(param_2,uVar2);
  GENERIC_PHY_PacketRxAppendedInfoHelper(iVar1,param_3);
  return uVar2;
}



void GENERIC_PHY_PacketRxGet(undefined2 *param_1)

{
  undefined2 uVar1;
  undefined4 uVar2;
  short local_28 [2];
  undefined4 local_24;
  undefined4 uStack32;
  undefined4 uStack28;
  undefined4 uStack24;
  undefined4 local_14;
  
  if (param_1 != (undefined2 *)0x0) 
  {
    uVar2 = BUFC_RxBufferGet();
    BUFC_RxLengthReadNext(local_28);
    if (local_28[0] == -1) 
	{
      *(undefined4 *)(param_1 + 2) = 0;
      *param_1 = 0;
    }
    else 
	{
      uVar1 = GENERIC_PHY_PacketRxHelper(local_28[0],uVar2,&local_24);
      *(undefined4 *)(param_1 + 2) = uVar2;
      *param_1 = uVar1;
      *(undefined4 *)(param_1 + 4) = local_24;
      *(undefined4 *)(param_1 + 6) = uStack32;
      *(undefined4 *)(param_1 + 8) = uStack28;
      *(undefined4 *)(param_1 + 10) = uStack24;
      *(undefined4 *)(param_1 + 0xc) = local_14;
      if (*(code **)(currentCallbacks + 0x54) != NULL) uVar2 = (**(code **)(currentCallbacks + 0x54))();
      BUFC_RxBufferSet(uVar2);
    }
  }
}



void GENERIC_PHY_StartRx(int param_1)

{
  int iVar2;
  CORE_irqState_t irqState;
  
  if (param_1 != 0) FRC->WCNTCMP0 = param_1 - 1;
  if ((BUFC_RxBufferGet() == 0) && (*(code **)(currentCallbacks + 0x54) != NULL)) 
  {
    (**(code **)(currentCallbacks + 0x54))();
    BUFC_RxBufferSet();
  }
  irqState = CORE_EnterCritical();
  SEQ->REG000 &= 0xffffffbf);
  CORE_ExitCritical(irqState);
  BUS_RegMaskedSet(&RAC->RXENSRCEN,2);
}



void GENERIC_PHY_ChannelSet(uint8_t channel)

{
  SYNTH_ChannelSet(channel,1);
}


void GENERIC_PHY_SeqAtomicLock(void)

{
  //read_volatile(RAC->SR0._0_1_);
  BUS_RegMaskedSet(&RAC->SR0,4);
  while (RAC->SR0 & 0x40000) 
  {
    BUS_RegMaskedClear(&RAC->SR0,4);
    PROTIMER_DelayUs(2);
    BUS_RegMaskedSet(&RAC->SR0,4);
  }
}


void GENERIC_PHY_RadioIdle(int param_1,int param_2,int param_3)

{
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  if ((param_1 != 0) || (param_2 != 0)) 
  {
    do 
	{
      if (((RAC->STATUS & RAC_STATUS_STATE_Msk) >> RAC_STATUS_STATE_Pos) != 3) break;
    } while ((SEQ->REG064 & 0xf) != 3);
    if (param_2 != 0) 
	{
      GENERIC_PHY_SeqAtomicLock();
      BUS_RegMaskedSet(&RAC->CTRL,1);
      BUS_RegMaskedClear(&RAC->SR0,4);
      while (RAC->STATUS & RAC_STATUS_STATE_Msk != 0) RAC->CMD = 0x40;
    }
  }
  BUS_RegMaskedClear(&RAC->SR0,0x80);
  if (PROTIMER_CCTimerIsEnabled(3) != false) 
  {
    PROTIMER_CCTimerStop(3);
    PROTIMER_CCTimerStop(4);
  }
  PROTIMER_ClearRxEnable();
  PROTIMER_ClearTxEnable();
  GENERIC_PHY_SeqAtomicLock();
  SEQ->REG000 |= 0x40;
  BUS_RegMaskedClear(&RAC->RXENSRCEN,RAC_RXENSRCEN_SWRXEN_Msk);
  RAC->CMD = 0x100;
  BUS_RegMaskedClear(&RAC->SR0,4);
  if (param_1 != 0) 
  {
    RADIO_RACRxAbort();
    RAC->CMD = RAC_CMD_TXDIS_Msk; //0x20;
    PROTIMER_LBTStop();
    PROTIMER_CCTimerStop(4);
  }
  if (param_2 != 0) 
  {
    BUFC_RxBufferReset();
    BUS_RegMaskedClear(&RAC->CTRL,RAC_CTRL_FORCEDISABLE_Msk); //1);
    if (param_3 != 0) 
	{
      FRC->IFC = FRC->IEN;
      RAC->IFC = RAC->IEN;
      MODEM->IFC = MODEM->IEN;
      SYNTH->IFC = SYNTH->IEN;
      BUFC->IFC = BUFC->IEN;
      AGC->IFC = AGC->IEN;
      PROTIMER->IFC = 0x2f00050;
      pendedRxWindowEnd = 0;
    }
  }
  CORE_ExitCritical(irqState);
}



void GENERIC_PHY_FRC_IRQCallback(void)

{
  uint uVar1;
  uint16_t uVar2;
  CORE_irqState_t irqState;
  int iVar3;
  RAC_SET *pRVar4;
  uint32_t flags;
  
  irqState = CORE_EnterCritical();
  GENERIC_PHY_SeqAtomicLock();
  SEQ->REG068 |= FRC->IF;
  BUS_RegMaskedClear(&RAC->SR0,4);
  CORE_ExitCritical(irqState);
  flags = FRC->IF & FRC->IEN;
  FRC->IFC = flags;
  if (flags & 0x10) 
  {
    (*currentCallbacks[2])();
    if (BUFC_RxBufferPacketAvailable() != 0) FRC->IFS = 0x10;
  }
  else 
  {
    if (flags & 0x40) 
	{
      if ((FRC->IF & 0x10) && (BUFC_RxBufferBytesAvailable() != 0)) &&(FRC->RXCTRL & 0x02)) bufcPendRxFrameError = 1;
      else 
	  {
        if (enabledCallbacks & 0x08) (*currentCallbacks[3])();
      }
    }
  }
  if ((flags & 3 != 0) && (enabledCallbacks & 0x01)) (**currentCallbacks)();
  if ((flags & 0x100) && (RAC->STATUS & 0xf000000 == 0x6000000)) 
  {
    if (enabledCallbacks & 0x10) (*currentCallbacks[4])();
    if (BUFC_RxBufferPacketAvailable() == 0) 
	{
      if ((RAC->SR0 & 0x40) == 0) RADIO_FRCErrorHandle();
      if (-1 < (int)(RAC->SR0 << 0x18)) 
	  {
        RAC->CMD = 8;
        if ((SEQ->REG00C & 0x200) == 0) BUS_RegMaskedClear(&RAC->RXENSRCEN,2);
        else BUS_RegMaskedSet(&RAC->RXENSRCEN,2);
      }
      RAC->CMD = 0x40;
    }
    else FRC->IFS = 0x100;
  }
  if ((flags & 0x04) && (!FRC->CTRL & 0x01)) (*currentCallbacks[1])(8);
  if (flags & 0x08) (*currentCallbacks[1])(2);
  if (flags & 0x4000) (*currentCallbacks[7])();
  if (flags & 0x2000) (*currentCallbacks[8])();
  if (((pendedRxWindowEnd != '\0') && (BUFC_RxBufferPacketAvailable() == 0) && (pendedRxWindowEnd = '\0', (int)((uint)enabledCallbacks << 0x19) < 0)) (*currentCallbacks[6])(1);
  if (!(flags & 0x20)) return;
                    // WARNING: Could not recover jumptable at 0x000123d8. Too many branches
                    // WARNING: Treating indirect jump as call
  (*currentCallbacks[5])();
}




void GENERIC_PHY_SeqAtomicUnlock(void)

{
  BUS_RegMaskedClear(&RAC->.SR0,4);
}



void GENERIC_PHY_TxDisable(void)

{
  RAC->CMD = RAC_CMD_TXDIS_Msk; //0x20;
}



uint32_t GENERIC_PHY_PreviousTxTime(void)

{
  return PROTIMER->CC1_WRAP;
}



void GENERIC_PHY_RACConfig(void)

{
  RADIO_SeqInit(&genericSeqProg,0x3bb);
  memset(&SEQ,0,100);
  RAC->SR0 = 0;
  RAC->SR1 = 0;
  RAC->SR2 = 0;
  TEMPCAL_Init();
}


void GENERIC_PHY_FrameConfig(void)

{
  RADIO_Config(); //???
}



void GENERIC_PHY_DirectModeConfig(uint8_t *param_1)

{
  uint32_t uVar1;
  
  if (param_1 != NULL) 
  {
    RADIOCMU_ClockEnable(0x67400,1);
    CMU_ClockEnable(cmuClock_GPIO,true);
    uVar1 = (uint32_t)*param_1;
    BUS_RegMaskedClear(&MODEM->CTRL2,0xc00);
    if (uVar1 == 0) BUS_RegMaskedSet(&MODEM->CTRL2,0);
    else 
	{
      uVar1 = (uint32_t)param_1[4];
      if (uVar1 == 0) BUS_RegMaskedSet(&MODEM->CTRL2,0x800);
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
      if (param_1[3] == 0) BUS_RegMaskedSet(&MODEM->CTRL2,0x200);
      else 
	  {
        BUS_RegMaskedSet(&MODEM->CTRL2,0);
        uVar1 = uVar1 | 4;
      }
      uVar1 = uVar1 | 2;
    }
    if (param_1[2] == 0) BUS_RegMaskedClear(&MODEM->CTRL2,0x100);
    else &MODEM->CTRL2 = 0x100; //????
    MODEM->ROUTELOC0 = (uint32_t)param_1[8] << 0x10 | (uint32_t)param_1[5] << 8 | (uint32_t)param_1[0xb];
    BUS_RegMaskedClear(&MODEM->ROUTEPEN,7);
    BUS_RegMaskedSet(&MODEM->ROUTEPEN,uVar1);
    if (uVar1 & 0x01) GPIO_PinModeSet(param_1[0xc],(uint)param_1[0xd],gpioModeInput,0);
    if (uVar1 & 0x02) GPIO_PinModeSet(param_1[6],(uint)param_1[7],gpioModePushPull,0);
    if (uVar1 & 0x04) GPIO_PinModeSet(param_1[9],(uint)param_1[10],gpioModePushPull,0);
  }
}



void GENERIC_PHY_PROTIMERConfig(void)

{
  BUS_RegMaskedClear(&PROTIMER->IEN,0x3f3fff7);
  PROTIMER->IFC = 0x3f3fff7;
  PROTIMER->CTRL = 0;
  PROTIMER->BASECNT = 0;
  PROTIMER->WRAPCNT = 0;
  PROTIMER->BASECNTTOP = 0xffff;
  PROTIMER->WRAPCNTTOP = 0xffffffff;
  PROTIMER->LBTCTRL = 0;
}



uint GENERIC_PHY_ChannelGet(void)

{
  return SYNTH->CHCTRL & 0xff;
}



void GENERIC_PHY_SYNTH_IRQHandler(void)

{
  SYNTH->IFC = SYNTH->IF & SYNTH->IEN;
}



void GENERIC_PHY_ResetPacketConfig(void)

{
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  SEQ->REG000 &= 0xfffffff8;
  CORE_ExitCritical(irqState);
  BUS_RegMaskedClear(&FRC->DFLCTRL,7);
  BUS_RegMaskedSet(&FRC->DFLCTRL,0);
}




void GENERIC_PHY_ConfigureVariableLength(uint param_1,uint param_2,int param_3,int param_4)

{
  uint32_t uVar1;
  
  GENERIC_PHY_ResetPacketConfig();
  FRC->WCNTCMP1 = param_1 & 0xfff;
  if ((param_2 & 0xf) < 9) uVar1 = 1;
  else 
  {
    if (param_4 == 0) uVar1 = 3;
    else uVar1 = 4;
  }
  FRC->MAXLENGTH = 0xfff;
  BUS_RegMaskedClear(&FRC->DFLCTRL,0xff07);
  BUS_RegMaskedSet(&FRC->DFLCTRL, (param_2 & 0xf) << 0xc | (param_3 - 1U & 0xf) << 8 | uVar1);
}



void GENERIC_PHY_ConfigureFixedLength(uint16_t length)

{
  GENERIC_PHY_ResetPacketConfig();
  FRC->WCNTCMP0 = length - 1U & 0xfff;
}



void GENERIC_PHY_ConfigureFrameType(RAIL_FrameType_t *frameType)

{
  char cVar1;
  CORE_irqState_t CVar2;
  uint uVar3;
  uint uVar4;
  
  if (frameType == NULL) 
  {
    CVar2 = CORE_EnterCritical();
	SEQ->REG000 &= 0xfffffff8;
    CORE_ExitCritical(CVar2);
    SEQ->REG05C = 0;
    SEQ->REG060 = 0;
    return;
  }
  GENERIC_PHY_ResetPacketConfig();
  SEQ->REG05C._0_1_ = frameType->offset;
  SEQ->REG05C._1_1_ = frameType->mask;
  uVar4 = 0;
  SEQ->REG05C._2_1_ = 0;
  SEQ->REG060 = (uint32_t)frameType->frameLen;
  uVar3 = 0;
  do 
  {
    if (frameType->isValid[uVar4] != '\0') uVar3 = uVar3 | 1 << (uVar4 & 0xff) & 0xffU;
    uVar4 = uVar4 + 1;
  } while (uVar4 != 8);
  SEQ->REG05C._3_1_ = (char)uVar3;
  uVar3 = (uint32_t)frameType->mask;
  if (uVar3 != 0) 
  {
    while (-1 < (int)(uVar3 << 0x1f)) 
	{
      cVar1 = SEQ->REG05C._2_1_;
      uVar3 = uVar3 >> 1;
      SEQ->REG05C._2_1_ = cVar1 + '\x01';
    }
  }
  FRC->WCNTCMP0 = frameType->offset + 1;
  CVar2 = CORE_EnterCritical();
  SEQ->REG000 |= 7;
  CORE_ExitCritical(CVar2);
}



bool GENERIC_PHY_EnableAddressFiltering(void)

{
  uint32_t tmp;
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  tmp = SEQ->REG000;
  SEQ->REG000 |= 0x10;
  CORE_ExitCritical(irqState);
  return (tmp << 0x1b) >> 0x1f;
}


bool GENERIC_PHY_DisableAddressFiltering(void)

{
  uint32_t tmp;
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  tmp = SEQ->REG000;
  SEQ->REG000 &= 0xffffffef;
  CORE_ExitCritical(irqState);
  return (tmp << 0x1b) >> 0x1f;
}



bool GENERIC_PHY_IsEnabledAddressFiltering(void)

{
  return (SEQ->REG000 << 0x1b) >> 0x1f;
}


void GENERIC_PHY_ResetAddressFiltering(void)

{
  memset(&SEQ->REG010,0,0x4c);
  addressFilterMatchTable = 0;
}


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
}



bool GENERIC_PHY_ConfigureAddressFiltering(RAIL_AddrConfig_t *addrConfig)

{
  GENERIC_PHY_ResetAddressFiltering();
  if (addrConfig == NULL) return true;
  SEQ->REG054._0_1_ = addrConfig->numFields;
  if (*(uint8_t *)&addrConfig->field_0x2 < 9) 
  {
    SEQ->REG054._2_1_ = *(uint8_t *)&addrConfig->field_0x2;
    SEQ->REG054._1_1_ = *(uint8_t *)&addrConfig->field_0x1;
    if (*(uint8_t *)&addrConfig->field_0x3 < 9) 
	{
      SEQ->REG054._3_1_ = *(uint8_t *)&addrConfig->field_0x3;
      SEQ->REG058._2_1_ = *(uint8_t *)&addrConfig->sizes;
      addressFilterMatchTable = addrConfig->offsets;
      GENERIC_PHY_SetAddressFilteringMatchTable();
      return true;
    }
  }
  return false;
}



bool GENERIC_PHY_EnableAddress(uint8_t field,uint8_t index)

{
  if ((field < 2) && (index < 4)) 
  {
    *(uint8_t *)((uint32_t)&SEQ->REG058 + field) = (uint8_t)(1 << (uint32_t)index) | *(uint8_t *)((uint32_t)&SEQ->REG058 + field);
    GENERIC_PHY_SetAddressFilteringMatchTable();
    return true;
  }
  return false;
}



bool GENERIC_PHY_DisableAddress(uint8_t field,uint8_t index)

{
  if ((field < 2) && (index < 4)) 
  {
    *(uint8_t *)((int)&SEQ->REG058 + field) = *(uint8_t *)((int)&SEQ->REG058 + field) & ~(uint8_t)(1 << (uint32_t)index);
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
  if ((((param_1 < 2) && (param_2 < 2)) && (param_4 < uVar2)) && (((uVar2 < 9 && (param_3 < 4)) && (param_6 != NULL)))) 
  {
    GENERIC_PHY_DisableAddress((uint8_t)param_1,(uint8_t)param_3);
    puVar1 = (uint *)((param_4 + 0x84003c5 + param_2 * 8) * 4);
    for (pbVar3 = param_6; (int)(pbVar3 + (param_4 - (int)param_6)) < (int)uVar2; pbVar3 = pbVar3 + 1) 
	{
      *puVar1 = (uint)*pbVar3 << (param_3 << 3 & 0xff) | *puVar1 & ~(0xff << (param_3 << 3 & 0xff));
      puVar1 = puVar1 + 1;
    }
    return 1;
  }
  return 0;
}


bool GENERIC_PHY_SetIeeePanId(uint param_1,undefined4 param_2)

{
  if (GENERIC_PHY_SetAddressData(0,0,param_1,0,2,param_2) != false) 
  {
    if (param_1 < 4) 
	{
	  SEQ->REG058_0_1_ |= (uint8_t)(1 << (param_1 & 0xff));
	  return true;
    }
  }
  return false;
}


bool GENERIC_PHY_SetIeeeShortAddress(uint16_t addr)

{
  uint uVar2;
  
  uVar2 = (uint32_t)addr;
  if (GENERIC_PHY_SetAddressData(1,0,uVar2,2,4) != false) 
  {
    if (uVar2 < 4) 
	{
      SEQ->REG058._1_1_ |= (uint8_t)(1 << (uVar2 & 0xff));
	  return true;
    }
  }
  return false;
}


bool GENERIC_PHY_SetIeeeLongAddress(uint param_1,undefined4 param_2)

{
  if (GENERIC_PHY_SetAddressData(1,1,param_1,0,8,param_2) != false) 
  {
    if (param_1 < 4) 
	{
	  SEQ->REG058._1_1_  |= (uint8_t)(1 << (param_1 & 0xff));
	  return true;
    }
  }
  return false;
}



bool GENERIC_PHY_SetAddress(uint8_t field,uint8_t index,uint8_t *value,bool enable)

{
  uint uVar2;
  
  uVar2 = (uint32_t)field;
  if ((enable != false) && (GENERIC_PHY_SetAddressData(uVar2,uVar2,index,0,*(undefined *)((int)&SEQ->REG054 + uVar2 + 2),value) != 0)) return GENERIC_PHY_EnableAddress(field,index);
  return false;
}



bool GENERIC_PHY_EnableIEEE802154(void)

{
  uint32_t uVar1;
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  uVar1 = SEQ->REG000;
  SEQ->REG000 |= 0x80;
  CORE_ExitCritical(irqState);
  return (bool)((byte)uVar1 >> 7);
}



uint32_t GENERIC_PHY_DisableIEEE802154(void)

{
  uint32_t uVar1;
  
  CORE_EnterCritical();
  uVar1 = SEQ->REG000;
  SEQ->REG000 &= 0xff7f;
  CORE_ExitCritical();
  return (uVar1 << 0x18) >> 0x1f;
}



bool GENERIC_PHY_IsEnabledIEEE802154(void)

{
  return (bool)((byte)SEQ->REG000 >> 7);
}



bool GENERIC_PHY_TimerStart(uint32_t time,RAIL_TimeMode_t mode)

{
  return  PROTIMER_CCTimerStart(2,time,mode);
}


void GENERIC_PHY_TimerStop(void)

{
  PROTIMER_CCTimerStop(2);
}



uint32_t GENERIC_PHY_TimerGetTimeout(void)

{
  return  PROTIMER_GetCCTime(2);
}



bool GENERIC_PHY_TimerExpired(void)

{
  return (PROTIMER->IF << 0x15) >> 0x1f;
}


bool GENERIC_PHY_TimerIsRunning(void)

{
  return PROTIMER_CCTimerIsEnabled(2);
}



bool GENERIC_PHY_CanModifyAck(void)

{
  uint32_t status;
  
  status = (RAC->STATUS << 4) >> 0x1c;
  if (1 < status - 2) return (status == 7);
  return true;
}


