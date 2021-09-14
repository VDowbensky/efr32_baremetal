#include "generic_phy.h"



void GENERIC_PHY_ConfigureRollbackReporting(void)

{
  RAC_SET *pRVar1;
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  if ((overrideRxRollback == '\0') && ((enabledRailEvents & 0x1200) == 0)) 
  {
    BUS_RegMaskedClear(&RAC->SR3,0x10);
LAB_00010022:
    if ((enabledRailEvents & 0x80) == 0) 
	{
      pRVar1 = (RAC_SET *)&Peripherals::RAC_CLR;
      goto LAB_00010036;
    }
  }
  else 
  {
    BUS_RegMaskedSet(&RAC->SR3,0x10);
    if (overrideRxRollback == '\0') goto LAB_00010022;
  }
  pRVar1 = &Peripherals::RAC_SET;
LAB_00010036:
  ((RAC_CLR *)pRVar1)->SR3 = 0x20;
  CORE_ExitCritical(irqState);
}



void GENERIC_PHY_ClearPendedRxWindowEnd(void)

{
  pendedRxWindowEnd = 0;
  if (overrideRxRollback != '\0') 
  {
    overrideRxRollback = 0;
    GENERIC_PHY_ConfigureRollbackReporting();
    return;
  }
  pendedRxWindowEnd = 0;
  return;
}



void RADIO_RACRxAbort(undefined4 param_1,undefined4 param_2,int param_3)

{
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  if ((RAC->STATUS & RAC_STATUS_STATE_Msk) >> RAC_STATUS_STATE_Pos == 3) 
  {
	SEQ->REG080 &= 0xffffff0f;
	SEQ->REG080 |= 0xe0;
  }
  FRC->CMD = FRC_CMD_RXABORT_Msk;
  CORE_ExitCritical(irqState);
}



void GENERIC_PHY_IssueCallback(uint32_t param_1,uint32_t param_2,int param_3)

{
  if (((param_1 | param_2) != 0) || (param_3 != 0)) 
  {
    inCallback = 1;
    GENERIC_PHY_EventCallback();
    inCallback = 0;
  }
}



void GENERIC_PHY_RxOverflowHook(void)

{
  if (!(RAC->SR0 & 0x80)) 
  {
    RAC->CMD = RAC_CMD_CLEARTXEN_Msk;
    if ((SEQ->REG024 & 0x200) == 0) BUS_RegMaskedClear(&RAC->RXENSRCEN,2);
    else BUS_RegMaskedSet(&RAC->RXENSRCEN,2);
  }
}



void GENERIC_PHY_CheckPendedRxWindowEnd(void)

{
  if ((pendedRxWindowEnd != 0) && (BUFC_RxBufferBytesAvailable() == 0)) 
  {
    GENERIC_PHY_ClearPendedRxWindowEnd();
    GENERIC_PHY_IssueCallback(enabledRailEvents & 0x800,0,0);
  }
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void GENERIC_PHY_DisableRadioIrqs(void)

{
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  _DAT_e000e180 = 0x40000000;
  CORE_ExitCritical(irqState);
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void GENERIC_PHY_ConfigureEvents(uint32_t param_1,uint32_t param_2,uint32_t param_3,uint32_t param_4,uint32_t param_5,uint32_t param_6)

{
  BUFC_SET *pBVar1;
  uint32_t *puVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  CORE_irqState_t irqState;
  
  param_3 = param_3 & param_1;
  param_4 = param_4 & param_2;
  param_6 = param_6 & param_5;
  if (param_5 == 0) 
  {
    if (param_2 == 0 && param_1 == 1) 
	{
      irqState = CORE_EnterCritical();
      DAT_000112fc = DAT_000112fc | param_4;
      enabledRailEvents = enabledRailEvents & 0xfffffffe | param_3;
      uVar4 = 1;
      if ((param_3 | param_4) == 0) 
	  {
        BUS_RegMaskedClear(&AGC->IEN,1);
        AGC->IFC = 1;
        CORE_ExitCritical(irqState);
		return;
      }
      AGC->IFC = 1;
      puVar2 = &Peripherals::AGC_SET.IEN;
    }
    else 
	{
      if (param_2 == 0 && param_1 == 0) return;
      if (param_2 != 0 || param_1 != 4) goto LAB_0001025a;
      CORE_EnterCritical();
      enabledRailEvents = enabledRailEvents & 0xfffffffb | param_3;
      DAT_000112fc = DAT_000112fc | param_4;
      if ((param_3 | param_4) == 0) pBVar1 = (BUFC_SET *)&Peripherals::BUFC_CLR;
      else pBVar1 = &Peripherals::BUFC_SET;
      puVar2 = &((BUFC_CLR *)pBVar1)->IEN;
      uVar4 = 0x400;
    }
	*puVar2 = uVar4;
  }
  else 
  {
    if (((param_1 | param_2) != 0) || (param_5 != 4)) 
	{
LAB_0001025a:
      GENERIC_PHY_DisableRadioIrqs();
      param_3 = enabledRailEvents & ~param_1 | param_3;
      param_4 = DAT_000112fc & ~param_2 | param_4;
      param_6 = enabledPhyEvents & ~param_5 | param_6;
      enabledPhyEvents = param_6;
      enabledRailEvents = param_3;
      DAT_000112fc = param_4;
      GENERIC_PHY_ConfigureRollbackReporting();
      uVar4 = FRC->IEN;
      uVar5 = 0x8002;
      if ((param_3 & 0x2a80000) == 0) uVar5 = 0x8000;
      if ((int)(param_6 << 0x1c) < 0) uVar5 = uVar5 | 0x2000;
      uVar3 = uVar4 & (uVar5 ^ uVar4);
      BUS_RegMaskedClear(&FRC->IEN,uVar3);
      FRC->IFC = uVar3;
      uVar5 = uVar5 & (uVar5 ^ uVar4);
      FRC->IFC = uVar5;
      BUS_RegMaskedSet(&FRC->IEN = uVar5);
      if ((param_3 & 0x4000) == 0) uVar4 = 0;
      else uVar4 = 0x1000;
      if ((param_3 & 0x8000) != 0) uVar4 = uVar4 | 0x100;
      if (param_6 & 0x01) uVar4 = uVar4 | 0x2000;
      if ((param_3 & 0x10) != 0) uVar4 = uVar4 | 0x200;
      if ((param_3 & 0x20) != 0) uVar4 = uVar4 | 0x400;
      uVar5 = MODEM->IEN;
      if ((param_3 & 0x40) != 0) uVar4 = uVar4 | 0x800;
      uVar3 = uVar5 & (uVar4 ^ uVar5);
      BUS_RegMaskedClear(&MODEM->IEN,uVar3);
      MODEM->IFC = uVar3;
      uVar4 = uVar4 & (uVar4 ^ uVar5);
      MODEM->IFC = uVar4;
      BUS_RegMaskedSet(&MODEM->IEN,uVar4);
      if ((param_4 & 2) == 0) uVar4 = 0;
      else uVar4 = 0x40000;
      if ((param_3 & 0x400) != 0) uVar4 = uVar4 | 0x10000;
      if ((param_3 & 0x2000) != 0) uVar4 = uVar4 | 0x100000;
      if ((param_3 & 2) != 0) uVar4 = uVar4 | 0x200000;
      if ((param_3 & 0x10000) != 0) uVar4 = uVar4 | 0x80000;
      uVar5 = RAC->IEN;
      if (param_6 & 0x10) uVar4 = uVar4 | 4;
      uVar3 = (uVar4 ^ uVar5) & 0xfffffffe;
      uVar5 = uVar5 & uVar3;
      BUS_RegMaskedClear(&RAC->IEN,uVar5);
      RAC->IFC = uVar5;
      uVar4 = uVar4 & uVar3;
      RAC->IFC = uVar4;
      BUS_RegMaskedSet(&RAC->IEN,uVar4);
      uVar4 = 0x701800;
      if (param_6 & 4) uVar4 = 0x701c00;
      uVar5 = (PROTIMER->IEN);
      if ((param_3 & 0x20000000) != 0) uVar4 = uVar4 | 0x2000000;
      uVar3 = uVar5 & (uVar4 ^ uVar5);
      BUS_RegMaskedClear(&PROTIMER->IEN,uVar3);
      uVar4 = uVar4 & (uVar4 ^ uVar5);
      PROTIMER->IFC = uVar3;
      PROTIMER->IFC = uVar4;
      BUS_RegMaskedSet(&PROTIMER->IEN,uVar4);
      uVar4 = AGC->IEN;
      uVar5 = uVar4 ^ param_3 & 1;
      uVar4 = uVar4 & uVar5;
      BUS_RegMaskedClear(&AGC->IEN,uVar4);
      AGC->IFC = uVar4;
      uVar5 = param_3 & 1 & uVar5;
      AGC->IFC = uVar5;
      BUS_RegMaskedSet(&AGC->IEN,uVar5);
      uVar4 = 0x90a0a09;
      if ((param_3 & 0x20000) != 0) uVar4 = 0x90a0a0d;
      uVar5 = BUFC->IEN;
      if ((param_3 & 4) != 0) uVar4 = uVar4 | 0x400;
      uVar3 = (uVar4 ^ uVar5) & 0xfffaffff;
      uVar5 = uVar5 & uVar3;
      BUS_RegMaskedClear(&BUFC->IEN,uVar5);
      BUFC->IFC = uVar5;
      uVar4 = uVar4 & uVar3;
      BUFC->IFC = uVar4;
      BUS_RegMaskedSet(&BUFC->IEN,uVar4);
      CORE_EnterCritical();
      _DAT_e000e100 = 0x20;
      CORE_ExitCritical(irqState);
	  return;
    }
    CORE_EnterCritical();
    enabledPhyEvents = enabledPhyEvents & 0xfffffffb | param_6;
    uVar4 = 0x400;
    if (param_6 == 0) 
	{
      BUS_RegMaskedClear(&PROTIMER->IEN,0x400);
      write_volatile_4(PROTIMER->IFC,0x400);
      CORE_ExitCritical(irqState);
      return;
    }
    PROTIMER->IFC = 0x400;
    puVar2 = &Peripherals::PROTIMER_SET.IEN;
	*puVar2 = uVar4;
  }
}



void GENERIC_PHY_PacketTxCommon(void)

{
  if (((FRC->DFLCTRL & 7) == 0) && (SEQ->REG078 != 0)) FRC->WCNTCMP0 = BUFC_GetBytesAvailable() - 1;
  BUS_RegMaskedSet(&RAC->SR0,0x80);
  SEQ->REG014 &= 0xffffffbf;
}



bool GENERIC_PHY_PacketTx(void)

{
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  if ((PROTIMER_CCTimerIsEnabled(3) == false) && (PROTIMER_LBTIsActive() == false)) 
  {
    GENERIC_PHY_PacketTxCommon();
    RAC->CMD = RAC_CMD_TXEN_Msk;
    CORE_ExitCritical(irqState);
    return false;
  }
  CORE_ExitCritical(irqState);
  return true;
}



undefined4 GENERIC_PHY_SchedulePacketRx
          (int param_1,undefined4 param_2,int param_3,int param_4,char param_5,char param_6,
          undefined param_7)

{
  int iVar2;
  uint32_t uVar3;
  undefined8 uVar4;
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  if (param_3 != 2) 
  {
    if (PROTIMER_CCTimerIsEnabled(3) != 0)
	{
		CORE_ExitCritical(irqState);
		return 3;
	}
    PROTIMER_ClearRxEnable();
    PROTIMER_ClearTxEnable();
    scheduledRxLoop = param_6;
    uVar3 = SEQ->REG014;
    if (param_6 == '\0') uVar3 = uVar3 & 0xffffffbf;
    else uVar3 = uVar3 | 0x40;
    SEQ->REG014 = uVar3;
    iVar2 = PROTIMER_ScheduleRxEnable(3,param_2,param_3);
    if (iVar2 == 0) 
	{
      CORE_ExitCritical(irqState);
      return 1;
    }
  }
  if (param_5 != '\x02') 
  {
    if ((PROTIMER_CCTimerIsEnabled(3) != false) || (RAC->STATUS & 0x4000) 
	{
      scheduledRxHardEnd = param_7;
      if ((param_5 == '\x01') && (param_3 != 2)) 
	  {
        param_4 = param_4 + PROTIMER_scheduledRxEnable;
        uVar4 = PROTIMER_UsToPrecntOverflow(*(undefined2 *)(param_1 + 0x38));
        param_4 = PROTIMER_WrapMultiple((int)uVar4 + param_4,(int)((ulonglong)uVar4 >> 0x20),PROTIMER->WRAPCNTTOP + 1,0xfffffffe < PROTIMER->WRAPCNTTOP);
        param_5 = '\0';
      }
      GENERIC_PHY_ClearPendedRxWindowEnd();
      if (PROTIMER_ScheduleRxDisable(4,param_4,param_5) != false) 
	  {
        if (param_6 != '\0') 
		{
          overrideRxRollback = 1;
          BUS_RegMaskedSet(&RAC->SR3,5);
        }
        CORE_ExitCritical(irqState);
		return 0;
      }
      PROTIMER_CCTimerStop(3);
      PROTIMER_ClearRxEnable();
    }
  }
}



undefined4 GENERIC_PHY_SchedulePacketTx(undefined4 *param_1)

{
  undefined4 uVar1;
  char cVar4;
  CORE_irqState_t irqState;
  
  uVar1 = PROTIMER_UsToPrecntOverflow(*param_1);
  irqState = CORE_EnterCritical();
  if ((PROTIMER_CCTimerIsEnabled(3) != false) || (PROTIMER_LBTIsActive() != false)) 
  {
    CORE_ExitCritical(irqState);
    return 3;
  }
  GENERIC_PHY_PacketTxCommon();
  PROTIMER_ClearRxEnable();
  PROTIMER_ClearTxEnable();
  RFHAL_SetAbortScheduledTxDuringRx(*(char *)((int)param_1 + 5) == '\x01');
  cVar4 = *(char *)(param_1 + 1);
  if (cVar4 != '\0') cVar4 = '\x01';
  if (PROTIMER_ScheduleTxEnable(3,uVar1,cVar4) == 0) 
  {
    BUS_RegMaskedClear(&RAC->SR0,0x80);
    CORE_ExitCritical(irqState);
    return 1;
  }
  CORE_ExitCritical(irqState);
  return 0;
}



void GENERIC_PHY_StopTx(void)

{
  RAC->CMD = RAC_CMD_CLEARTXEN_Msk;
}



void GENERIC_PHY_StartRx(int param_1)

{
  CORE_irqState_t irqState;
  
  if (param_1 != 0) FRC->WCNTCMP0 = param_1 - 1;
  irqState = CORE_EnterCritical();
  SEQ->REG014 &= 0xffffffbf;
  CORE_ExitCritical(irqState);
  BUS_RegMaskedSet(&RAC->RXENSRCEN,2);
}



void GENERIC_PHY_ChannelSet(undefined4 param_1)

{
  SYNTH_ChannelSet(param_1,1);
}



void GENERIC_PHY_SeqAtomicLock(void)

{
  BUS_RegMaskedSet(&RAC->SR0,4);
  while (RAC->SR0 & 0x40000) 
  {
    BUS_RegMaskedClear(&RAC->SR0,4);
    PROTIMER_DelayUs(2);
    BUS_RegMaskedSet(&RAC->SR0,4);
  }
}



void GENERIC_PHY_SeqAtomicUnlock(void)

{
  BUS_RegMaskedClear(&RAC->SR0,4);
}



void GENERIC_PHY_TxDisable(void)

{
  RAC->CMD = RAC_CMD_TXDIS_Msk;
}



uint32_t GENERIC_PHY_PreviousTxTime(void)

{
  return PROTIMER->CC1_WRAP;
}



void GENERIC_PHY_RACConfig(void)

{
  RADIO_SeqInit(&genericSeqProg,genericSeqProg_size);
  memset(&SEQ->REG014,0,0x68);
  RAC->SR0 = 0;
  RAC->SR1 = 0;
  RAC->SR2 = 0;
  TEMPCAL_Init();
}



void GENERIC_PHY_ConfigDirectMode(uint8_t *param_1)

{
  uint32_t uVar1;
  
  if (param_1 != NULL) 
  {
    RADIOCMU_ClockEnable(0x67400,1);
    CMU_ClockEnable(0x82500,1);
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
    else BUS_RegMaskedSet(&MODEM->CTRL2,0x100);
    MODEM->ROUTELOC0 = (uint32_t)param_1[8] << 0x10 | (uint32_t)param_1[5] << 8 | (uint32_t)param_1[0xb];
    BUS_RegMaskedClear(&MODEM->ROUTEPEN,7);
    BUS_RegMaskedSet(&MODEM->ROUTEPEN,uVar1);
    if ((int)(uVar1 << 0x1f) < 0) GPIO_PinModeSet(param_1[0xc],param_1[0xd],1,0);
    if ((int)(uVar1 << 0x1e) < 0) GPIO_PinModeSet(param_1[6],param_1[7],4,0);
    if ((int)(uVar1 << 0x1d) < 0) GPIO_PinModeSet(param_1[9],param_1[10],4,0);
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



uint32_t GENERIC_PHY_ChannelGet(void)

{
  return SYNTH->CHCTRL & 0xff;
}



int GENERIC_PHY_ReleaseRxPacket(void)

{
  int iVar1;
  CORE_irqState_t irqState;
  
  iVar1 = BUFC_ReleaseRxPacket();
  if ((inCallback == '\0') && (BUFC_ReleaseRxPacket() == 0)) 
  {
    irqState = CORE_EnterCritical();
    GENERIC_PHY_CheckPendedRxWindowEnd();
    CORE_ExitCritical(irqState);
  }
  return iVar1;
}



void GENERIC_PHY_ResetRxFifo(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  BUFC_RxBufferReset();
  if ((param_1 == 0) && (inCallback == 0)) GENERIC_PHY_CheckPendedRxWindowEnd();
  else GENERIC_PHY_ClearPendedRxWindowEnd();
  CORE_ExitCritical(irqState);
}



void GENERIC_PHY_RadioIdle(int param_1,int param_2,int param_3)

{
  uint32_t uVar1;
  undefined4 uVar2;
  int iVar3;
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  if ((param_1 != 0) || (param_2 != 0)) 
  {
    do 
	{
      if ((RAC->STATUS & RAC_STATUS_STATE_Msk) >> RAC_STATUS_STATE_Pos != 3) break;
    } while ((SEQ->REG07C & 0xf) != 3);
    if (param_2 != 0) 
	{
      GENERIC_PHY_SeqAtomicLock();
      BUS_RegMaskedSet(&RAC->CTRL,1);
      BUS_RegMaskedClear(&RAC->SR0,4);
      while (RAC->STATUS & RAC_STATUS_STATE_Msk != 0) RADIO_RACClearRxOverflow();
    }
  }
  BUS_RegMaskedClear(&RAC->SR0,0x80);
  if (PROTIMER_CCTimerIsEnabled(3) != 0) 
  {
    PROTIMER_CCTimerStop(3);
    PROTIMER_CCTimerStop(4);
  }
  PROTIMER_ClearRxEnable();
  PROTIMER_ClearTxEnable();
  GENERIC_PHY_SeqAtomicLock();
  SEQ->REG014 |= 0x40;
  BUS_RegMaskedClear(&RAC->RXENSRCEN,0xff);
  RAC->CMD = RAC_CMD_RXDIS_Msk;
  BUS_RegMaskedClear(&RAC->SR0,4);
  if (param_1 != 0) 
  {
    RADIO_RACRxAbort();
    PROTIMER_LBTStop();
    RAC->CMD = RAC_CMD_TXDIS_Msk;
    PROTIMER_CCTimerStop(4);
  }
  if (param_2 != 0) 
  {
    GENERIC_PHY_ResetRxFifo(param_3);
    BUS_RegMaskedClear(&RAC->CTRL,1);
    if (param_3 != 0) 
	{
      FRC->IFC = FRC->IEN;
      RAC->IFC = RAC->IEN;
      MODEM->IFC = MODEM->IEN;
      SYNTH->IFC = SYNTH->IEN;
      BUFC->IFC = BUFC->IEN;
      AGC->IFC = AGC->IEN;
      PROTIMER->IFC = 0x2f00050;
      GENERIC_PHY_ClearPendedRxWindowEnd();
    }
  }
  CORE_ExitCritical(irqState);
}



void RAILCb_RadioStateChanged(void)

{
  BUS_RegMaskedClear(&RAC->IEN,1);
  RAC->IFC = 1;
}



void RAC_RSM_IRQHandler(void)

{
  uint32_t flags;
  
  flags = RAC->IEN & RAC->IF;
  RAC->IFC = flags & 0xffff;
  if (flags & 0x01) RAILCb_RadioStateChanged((RAC->STATUS & RAC_STATUS_STATE_Msk) >> RAC_STATUS_STATE_Pos);
  if (flags & 0x04) GENERIC_PHY_IssueCallback(0,0,enabledPhyEvents & 0x10);
}



void AGC_IRQHandler(void)

{
  uint32_t flags;

  flags = AGC->IEN & AGC->IF;
  AGC->IFC = flags;
  if (flags & 0x01) 
  {
    RAILInt_Assert((uint8_t)enabledRailEvents & 1,0x12);
    GENERIC_PHY_IssueCallback(1,0,0);
  }
}



void SYNTH_IRQHandler(void)

{
  SYNTH->IFC = SYNTH->IEN & SYNTH->IF;
}



uint32_t GENERIC_PHY_SetFeatures(undefined4 param_1,uint32_t param_2,uint32_t param_3)

{
  uint32_t uVar1;
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  uVar1 = SEQ->REG014;
  //write_volatile_4(SEQ->REG014,param_3 & param_2 | uVar1 & ~param_2);
  SEQ->REG014 &= ~param_2;
  SEQ->REG014 |= param_3 & param_2;
  CORE_ExitCritical(irqState);
  return param_2 & uVar1;
}



void GENERIC_PHY_ConfigureFrameType(undefined4 param_1,uint32_t *param_2,undefined4 param_3)

{
  uint8_t bVar1;
  uint32_t *local_1c;
  undefined4 uStack24;
  
  uStack24 = param_3;
  if (param_2 == NULL) 
  {
    local_1c = param_2;
    GENERIC_PHY_SetFeatures(param_1,7,0);
    SEQ->REG074 = 0;
    SEQ->REG078 = 0;
  }
  else 
  {
    BUS_RegMaskedClear(&FRC->DFLCTRL,7);
    BUS_RegMaskedSet(&FRC->DFLCTRL,0);
    write_volatile_1(SEQ->REG074._0_1_,*(undefined *)(param_2 + 1));
    local_1c = (uint32_t *)(uint32_t)*(uint8_t *)((int)param_2 + 5);
    bVar1 = CORTEX_UTILS_BitsetLowestSetBit(&local_1c,1,0,local_1c,param_1);
    SEQ->REG074._1_1_ =  bVar1 & 0xf | (uint8_t)(((uint32_t)local_1c >> (uint32_t)bVar1) << 4));
    SEQ->REG074._2_1_ = *(undefined *)((int)param_2 + 6));
    SEQ->REG074._3_1_ = *(undefined *)((int)param_2 + 7));
    SEQ->REG078 = *param_2);
    FRC->WCNTCMP0 = *(uint8_t *)(param_2 + 1) + 1;
    GENERIC_PHY_SetFeatures(param_1,7,7);
  }
  return;
}



int GENERIC_PHY_EnableAddressFiltering(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  if (param_2 == 0) iVar1 = GENERIC_PHY_SetFeatures(param_1,0x10,0,param_4,param_4);//uVar2 = 0;
  else iVar1 = GENERIC_PHY_SetFeatures(param_1,0x10,0x10,param_4,param_4);//uVar2 = 0x10;
  if (iVar1 != 0) iVar1 = 1;
  return iVar1;
}



uint32_t GENERIC_PHY_IsEnabledAddressFiltering(void)

{
  return (SEQ->REG014 << 0x1b) >> 0x1f;
}



void GENERIC_PHY_ResetAddressFiltering(void)

{
  memset(&SEQ->REG028,0,0x4c);
}



void GENERIC_PHY_Init(int param_1)

{
  RADIO_Init();
  GENERIC_PHY_DisableRadioIrqs();
  GENERIC_PHY_RACConfig();
  PTI_Enable(1);
  BUFC_Init(GENERIC_PHY_RxOverflowHook);
  BUS_RegMaskedClear(&RAC->CTRL,1);
  GENERIC_PHY_ResetAddressFiltering(param_1);
  PROTIMER_Init();
  PROTIMER_Start();
  TIMING_InitStimer();
  TIMING_RecalculateAll(param_1 + 0x28);
  PROTIMER_CCTimerCapture(0,0xc00000);
  PROTIMER_CCTimerCapture(1,0x200000);
  SYNTH_DCDCRetimeDisable();
  if (RFRAND_SeedProtimerRandom() == 0) RAILInt_Assert(0,0x14);
  SYNTH_DCDCRetimeEnable();
}



bool GENERIC_PHY_ConfigureAddressFiltering(undefined4 param_1,undefined *param_2,int param_3)

{
  if (param_3 != 0) GENERIC_PHY_ResetAddressFiltering();
  if (param_2 == NULL) return 0;
  SEQ->REG06C._0_1_ = *param_2;
  if ((uint8_t)param_2[2] < 9) 
  {
    SEQ->REG06C._2_1_ = param_2[2];
    SEQ->REG06C._1_1_ = param_2[1];
    if ((uint8_t)param_2[3] < 9) 
	{
      SEQ->REG06C._3_1_ = param_2[3];
      SEQ->REG028 = *(uint32_t *)(param_2 + 4);
      return false;
    }
  }
  return true;
}



bool GENERIC_PHY_EnableAddress(undefined4 param_1,uint32_t param_2,uint32_t param_3,int param_4)

{
  uint8_t bVar1;
  uint8_t bVar2;
  
  if ((param_2 < 2) && (param_3 < 4)) 
  {
    bVar1 = *(uint8_t *)((int)&SEQ->REG070 + param_2);
    bVar2 = (uint8_t)(1 << (param_3 & 0xff));
    if (param_4 == 0) bVar2 = bVar1 & ~bVar2;
    else bVar2 = bVar2 | bVar1;
    *(uint8_t *)((int)&SEQ->REG070 + param_2) = bVar2;
    return false;
  }
  return true;
}



bool
GENERIC_PHY_SetAddressData
          (undefined4 param_1,uint32_t param_2,uint32_t param_3,uint32_t param_4,uint8_t param_5,uint8_t param_6,
          uint8_t *param_7)

{
  uint32_t *puVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint8_t *pbVar4;
  
  uVar3 = (uint32_t)param_5;
  uVar2 = (uint32_t)param_6;
  if ((((param_2 < 2) && (param_3 < 2)) && (uVar3 < uVar2)) && (((uVar2 < 9 && (param_4 < 4)) && (param_7 != NULL)))) 
  {
    GENERIC_PHY_EnableAddress(param_1,param_2,param_4,0);
    puVar1 = (uint32_t *)((uVar3 + 0x84003ca + param_3 * 8) * 4);
    for (pbVar4 = param_7; (int)(pbVar4 + (uVar3 - (int)param_7)) < (int)uVar2; pbVar4 = pbVar4 + 1)
    {
      puVar1 = puVar1 + 1;
      *puVar1 = (uint32_t)*pbVar4 << (param_4 << 3 & 0xff) | ~(0xff << (param_4 << 3 & 0xff)) & *puVar1;
    }
    return false;
  }
  return true;
}



int GENERIC_PHY_SetIeeePanId(undefined4 param_1,uint32_t param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  
  uVar4 = GENERIC_PHY_SetAddressData();
  iVar2 = (int)((ulonglong)uVar4 >> 0x20);
  iVar1 = (int)uVar4;
  iVar3 = iVar1;
  if (iVar1 == 0) 
  {
    if (param_2 < 4) iVar2 = 0x21000f28;
    iVar3 = 1;
    if (param_2 < 4) 
	{
      *(uint8_t *)(iVar2 + 0x48) = (uint8_t)(1 << (param_2 & 0xff)) | *(uint8_t *)(iVar2 + 0x48);
      iVar3 = iVar1;
    }
  }
  return iVar3;
}



int GENERIC_PHY_SetIeeeShortAddress
              (undefined4 param_1,uint32_t param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  
  uVar4 = GENERIC_PHY_SetAddressData(param_1,1,0,param_2,2,4,param_3,param_4);
  iVar2 = (int)((ulonglong)uVar4 >> 0x20);
  iVar1 = (int)uVar4;
  iVar3 = iVar1;
  if (iVar1 == 0) 
  {
    if (param_2 < 4) iVar2 = 0x21000f28;
    iVar3 = 1;
    if (param_2 < 4) 
	{
      *(uint8_t *)(iVar2 + 0x49) = (uint8_t)(1 << (param_2 & 0xff)) | *(uint8_t *)(iVar2 + 0x49);
      iVar3 = iVar1;
    }
  }
  return iVar3;
}



int GENERIC_PHY_SetIeeeLongAddress(undefined4 param_1,uint32_t param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  
  uVar4 = GENERIC_PHY_SetAddressData();
  iVar2 = (int)((ulonglong)uVar4 >> 0x20);
  iVar1 = (int)uVar4;
  iVar3 = iVar1;
  if (iVar1 == 0) 
  {
    if (param_2 < 4) iVar2 = 0x21000f28;
    iVar3 = 1;
    if (param_2 < 4) 
	{
      *(uint8_t *)(iVar2 + 0x49) = (uint8_t)(1 << (param_2 & 0xff)) | *(uint8_t *)(iVar2 + 0x49);
      iVar3 = iVar1;
    }
  }
  return iVar3;
}



void GENERIC_PHY_SetAddress
               (undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,char param_5)

{
  int iVar1;
  
  iVar1 = GENERIC_PHY_SetAddressData
                    (param_1,param_2,param_2,param_3,0,
                     *(undefined *)((int)&SEQ->REG06C + param_2 + 2),param_4);
  if ((param_5 != '\0') && (iVar1 == 0)) GENERIC_PHY_EnableAddress(param_1,param_2,param_3,1);
}



int GENERIC_PHY_EnableIEEE802154
              (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = GENERIC_PHY_SetFeatures(param_1,0x80,0x80,param_4,param_4);
  if (iVar1 != 0) iVar1 = 1;
  return iVar1;
}



int GENERIC_PHY_DisableIEEE802154
              (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = GENERIC_PHY_SetFeatures(param_1,0x80,0,param_4,param_4);
  if (iVar1 != 0) iVar1 = 1;
  return iVar1;
}



uint32_t GENERIC_PHY_IsEnabledIEEE802154(void)

{
  return (SEQ->REG014 << 0x18) >> 0x1f;
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



void GENERIC_PHY_GetTimerTimeout(void)

{
  return PROTIMER_GetCCTime(2);
}



bool GENERIC_PHY_IsTimerExpired(void)

{
  return (PROTIMER->IF << 0x15) >> 0x1f;
}



bool GENERIC_PHY_IsTimerRunning(void)

{
  return PROTIMER_CCTimerIsEnabled(2);
}



bool GENERIC_PHY_CanModifyAck(void)

{
  uint32_t state;
  
  state = (RAC->STATUS & RAC_STATUS_STATE_Msk) >> RAC_STATUS_STATE_Pos;
  if (1 < state - 2) return state == 7;
  return true;
}



void FRC_IRQHandler(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  uint32_t frc_flags;
  uint32_t bufc_flags; //uVar7
  uint32_t rac_flags; //uVar8;
  uint32_t protimer_flags; //uVar9;
  uint32_t modem_flags;//uVar10;
  CORE_irqState_t irqState;
  
  frc_flags = FRC->IEN & FRC->IF;
  FRC->IFC = frc_flags;

  bufc_flags = BUFC->IEN & BUFC->IF;
  BUFC->IFC = bufc_flags;
  
  modem_flags = MODEM->IEN & MODEM->IF;
  MODEM->IFC = modem_flags;
  
  rac_flags = RAC->IEN & RAC->IF;
  RAC->IFC = rac_flags & 0xffff0000;
  
  iVar1 = PROTIMER_LBTIsActive();
  
  protimer_flags = PROTIMER->IEN & PROTIMER->IF;
  PROTIMER->IFC = protimer_flags & 0xfffff7ff;
  
  if (frc_flags == 0) uVar4 = 0;
  else 
  {
    if ((int)(frc_flags << 0x10) < 0) 
	{
      uVar4 = RAC->SR0;
      BUS_RegMaskedClear(&RAC->SR0,uVar4 & 0x1c00);
      BUS_RegMaskedClear(&RAC->SR0,0x80);
      BUS_RegMaskedClear(&RAC->RXENSRCEN,0x10);
      if ((uVar4 & 0x1c00) == 0) uVar4 = 0x40000;
      else 
	  {
        if (uVar4 & 0x1000) uVar4 = 0x1000000;
        else 
		{
          if (uVar4 & 0x400) uVar4 = 0x100000;
          else uVar4 = 0x400000;
        }
      }
    }
    else uVar4 = 0;
    if (frc_flags & 0x02) 
	{
      uVar5 = RAC->SR0;
      BUS_RegMaskedClear(&RAC->SR0,uVar5 & 0xe000);
      if ((uVar5 & 0xe000) == 0) uVar4 = uVar4 | 0x80000;
      else 
	  {
        if(uVar5 & 0x8000) uVar4 = uVar4 | 0x2000000;
        else 
		{
          if (uVar5 & 0x2000) uVar4 = uVar4 | 0x200000;
          else uVar4 = uVar4 | 0x800000;
        }
      }
    }
    if ((frc_flags & 0x2000) == 0) frc_flags = 0;
    else frc_flags = 8;
  }
  uVar5 = 0;
  if ((bufc_flags & 0x90b0a09) != 0) 
  {
    if ((bufc_flags & 0xa00) != 0) 
	{
      GENERIC_PHY_ResetRxFifo(0);
      bufc_flags = bufc_flags & 0xfffbffff;
      RAILInt_Assert(0,6);
    }
    if ((bufc_flags & 9) != 0) 
	{
      RAC->CMD = 0x20;
      BUFC->BUF0_CMD = 1;
      RAILInt_Assert(0,8);
    }
    if ((bufc_flags & 0x9000000) != 0) 
	{
      RAC->CMD = 0x20;
      BUFC_TxAckBufferReset();
      RAILInt_Assert(0,9);
    }
    if ((bufc_flags & 0xa0000) != 0) 
	{
      GENERIC_PHY_ResetRxFifo(0);
      bufc_flags = bufc_flags & 0xfffbffff;
      RAILInt_Assert(0,7);
    }
    if ((int)(bufc_flags << 0xf) < 0) BUFC_HandleRxLenOvfEvent();
  }
  if (bufc_flags & 0x10000) 
  {
    if (_DAT_430204b4 == 0) BUS_RegMaskedSet(&BUFC->BUF0_THRESHOLDCTRL,0x2000);
    else 
	{
      uVar4 = uVar4 | 0x20000;
      BUS_RegMaskedClear(&BUFC->BUF0_THRESHOLDCTRL,0x2000);
    }
  }
  if (bufc_flags & 0x400) uVar4 = uVar4 | 4;
  if ((bufc_flags & 0x40000) != 0) 
  {
    switch(BUFC_StartRxLenThrEvent()) 
	{
    case 1:
    case 3:
      uVar4 = uVar4 | 0x1000;
      break;
    case 2:
      uVar4 = uVar4 | 0x200;
      break;
    case 4:
      uVar4 = uVar4 | 0x100;
      break;
    case 5:
      uVar4 = uVar4 | 0x80;
      break;
    case 6:
    case 7:
      uVar4 = uVar4 | 8;
      break;
    default:
      RAILInt_Assert(0,3);
    }
  }
  if (modem_flags != 0) 
  {
    if ((modem_flags & 0x1000) != 0) uVar4 = uVar4 | 0x4000;
    if ((modem_flags & 0x100) != 0) uVar4 = uVar4 | 0x8000;
    if ((modem_flags & 0x2000) != 0) frc_flags = frc_flags | 1;
    if ((modem_flags & 0x200) != 0) uVar4 = uVar4 | 0x10;
    if ((modem_flags & 0x400) != 0) uVar4 = uVar4 | 0x20; 
    if ((modem_flags & 0x800) != 0) uVar4 = uVar4 | 0x40;
  }
  if (rac_flags != 0) 
  {
    if ((rac_flags & 0x2000000) != 0) frc_flags = frc_flags | 0x20;
    if ((rac_flags & 0x4000000) != 0) frc_flags = frc_flags | 0x40;
    if ((rac_flags & 0x8000000) != 0) frc_flags = frc_flags | 0x80;
    if ((rac_flags & 0x40000) != 0) uVar5 = 2;
    if ((rac_flags & 0x10000) != 0) uVar4 = uVar4 | 0x400;
    if ((rac_flags & 0x100000) != 0) uVar4 = uVar4 | 0x2000;
    if ((rac_flags & 0x200000) != 0) uVar4 = uVar4 | 2;
    if (((rac_flags & 0x80000) != 0) && (iVar3 = GENERIC_PHY_CanModifyAck(), iVar3 != 0)) uVar4 = uVar4 | 0x10000;
  }
  if (protimer_flags == 0) goto LAB_0001126e;
  if ((protimer_flags & 0x800) != 0) 
  {
    PROTIMER_CCTimerStop(3);
    BUS_RegMaskedClear(&PROTIMER->RXCTRL,0x1f1f);
    PROTIMER->IFC = 0x800;
    PROTIMER_ClearTxEnable();
  }
  if ((protimer_flags & 0x2000000) != 0) 
  {
    PTI_AuxdataOutput(0x2b);
    uVar4 = uVar4 | 0x20000000;
  }
  if ((protimer_flags & 0x700000) == 0) 
  {
    if ((protimer_flags & 0x1000) != 0) 
	{
      if (iVar1 != 0) goto LAB_00011158;
      PROTIMER_CCTimerStop(4);
      PROTIMER_CCTimerStop(3);
      PROTIMER_ClearRxEnable();
      irqState = CORE_EnterCritical();
      if (scheduledRxHardEnd != 0) RADIO_RACRxAbort();
      iVar1 = BUFC_RxBufferBytesAvailable();
      if (((RAC->STATUS << 4) >> 0x1c == 3) || (BUFC_RxBufferBytesAvailable() != 0)) 
	  {
        iVar1 = 1;
        pendedRxWindowEnd = scheduledRxLoop;
      }
      CORE_ExitCritical(irqState);
      if (iVar1 == 0) 
	  {
        overrideRxRollback = 0;
        GENERIC_PHY_ConfigureRollbackReporting();
        uVar10 = 0x800;
      }
      else uVar10 = 0;
      uVar4 = uVar4 | uVar10;
    }
  }
  else 
  {
LAB_00011158:
    protimer_flags = PROTIMER_CheckCcaReallyFailed(protimer_flags);
    if ((protimer_flags & 0x200000) != 0) 
	{
      PTI_AuxdataOutput(0x29);
      uVar4 = uVar4 | 0x10000000;
    }
    if ((protimer_flags & 0x400000) == 0) 
	{
      if ((protimer_flags & 0x100000) == 0) 
	  {
        if ((protimer_flags & 0x1000) != 0) 
		{
          PROTIMER_CCTimerStop(4);
          PROTIMER_LBTStop();
          if ((PROTIMER->IF & 0x500000) == 0) 
		  {
            PTI_AuxdataOutput(0x2a);
            BUFC->BUF0_CMD = 1;
            goto LAB_000111f2;
          }
        }
      }
      else 
	  {
        PROTIMER_CCTimerStop(4);
        PTI_AuxdataOutput(0x28);
        uVar4 = uVar4 | 0x4000000;
      }
    }
    else 
	{
      PROTIMER_CCTimerStop(4);
      PTI_AuxdataOutput(0x27);
      BUS_RegMaskedClear(&RAC->SR0,0x80);
      BUS_RegMaskedClear(&RAC->RXENSRCEN,0x10);
LAB_000111f2:
      uVar4 = uVar4 | 0x8000000;
    }
  }
  if ((protimer_flags & 0x400) != 0) 
  {
    PROTIMER_CCTimerStop(2);
    frc_flags = frc_flags | 4;
  }
LAB_0001126e:
  GENERIC_PHY_IssueCallback(enabledRailEvents & uVar4,DAT_000112fc & uVar5,enabledPhyEvents & uVar6);
  if ((bufc_flags & 0x40000) != 0) 
  {
    BUFC_EndRxLenThrEvent();
    GENERIC_PHY_CheckPendedRxWindowEnd();
  }
  if (rac_flags != 0) 
  {
    if ((rac_flags & 0x2000000) != 0) PA_RunPeakDetectorHigh();
    if ((rac_flags & 0x4000000) != 0) PA_RunPeakDetectorLow();
    if ((rac_flags & 0x8000000) != 0) 
	{
      PA_RunBatHigh();
    }
  }
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FRC_PRI_IRQHandler(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  uint32_t uVar7;
  uint32_t uVar8;
  uint32_t uVar9;
  uint32_t uVar10;
  
  uVar4 = (FRC->IF);
  uVar6 = (FRC->IEN);
  uVar6 = uVar6 & uVar4;
  write_volatile_4(FRC->IFC,uVar6);
  uVar4 = (BUFC->IF);
  uVar7 = (BUFC->IEN);
  uVar7 = uVar7 & uVar4;
  write_volatile_4(BUFC->IFC,uVar7);
  uVar4 = (MODEM->IF);
  uVar10 = (MODEM->IEN);
  uVar10 = uVar10 & uVar4;
  write_volatile_4(MODEM->IFC,uVar10);
  uVar4 = (RAC->IF);
  uVar8 = (RAC->IEN);
  uVar8 = uVar8 & uVar4;
  write_volatile_4(RAC->IFC,uVar8 & 0xffff0000);
  iVar1 = PROTIMER_LBTIsActive();
  uVar4 = (PROTIMER->IF);
  uVar9 = (PROTIMER->IEN);
  uVar9 = uVar9 & uVar4;
  write_volatile_4(PROTIMER->IFC,uVar9 & 0xfffff7ff);
  if (uVar6 == 0) {
    uVar4 = 0;
  }
  else {
    if ((int)(uVar6 << 0x10) < 0) {
      uVar4 = (RAC->SR0);
      BUS_RegMaskedClear(&RAC->SR0,uVar4 & 0x1c00);
      BUS_RegMaskedClear(&RAC->SR0,0x80);
      BUS_RegMaskedClear(&RAC->RXENSRCEN,0x10);
      if ((uVar4 & 0x1c00) == 0) {
        uVar4 = 0x40000;
      }
      else {
        if ((int)(uVar4 << 0x13) < 0) {
          uVar4 = 0x1000000;
        }
        else {
          if ((int)(uVar4 << 0x15) < 0) {
            uVar4 = 0x100000;
          }
          else {
            uVar4 = 0x400000;
          }
        }
      }
    }
    else {
      uVar4 = 0;
    }
    if ((int)(uVar6 << 0x1e) < 0) {
      uVar5 = (RAC->SR0);
      BUS_RegMaskedClear(&RAC->SR0,uVar5 & 0xe000);
      if ((uVar5 & 0xe000) == 0) {
        uVar4 = uVar4 | 0x80000;
      }
      else {
        if ((int)(uVar5 << 0x10) < 0) {
          uVar4 = uVar4 | 0x2000000;
        }
        else {
          if ((int)(uVar5 << 0x12) < 0) {
            uVar4 = uVar4 | 0x200000;
          }
          else {
            uVar4 = uVar4 | 0x800000;
          }
        }
      }
    }
    if ((uVar6 & 0x2000) == 0) {
      uVar6 = 0;
    }
    else {
      uVar6 = 8;
    }
  }
  uVar5 = 0;
  if ((uVar7 & 0x90b0a09) != 0) {
    if ((uVar7 & 0xa00) != 0) {
      GENERIC_PHY_ResetRxFifo(0);
      uVar7 = uVar7 & 0xfffbffff;
      RAILInt_Assert(0,6);
    }
    if ((uVar7 & 9) != 0) {
      write_volatile_4(RAC->CMD,0x20);
      write_volatile_4(BUFC->BUF0_CMD,1);
      RAILInt_Assert(0,8);
    }
    if ((uVar7 & 0x9000000) != 0) {
      write_volatile_4(RAC->CMD,0x20);
      BUFC_TxAckBufferReset();
      RAILInt_Assert(0,9);
    }
    if ((uVar7 & 0xa0000) != 0) {
      GENERIC_PHY_ResetRxFifo(0);
      uVar7 = uVar7 & 0xfffbffff;
      RAILInt_Assert(0,7);
    }
    if ((int)(uVar7 << 0xf) < 0) {
      BUFC_HandleRxLenOvfEvent();
    }
  }
  if ((int)(uVar7 << 0x1d) < 0) {
    if (_DAT_430204b4 == 0) {
      BUS_RegMaskedSet(&BUFC->BUF0_THRESHOLDCTRL,0x2000);
    }
    else {
      uVar4 = uVar4 | 0x20000;
      BUS_RegMaskedClear(&BUFC->BUF0_THRESHOLDCTRL,0x2000);
    }
  }
  if ((int)(uVar7 << 0x15) < 0) {
    uVar4 = uVar4 | 4;
  }
  if ((uVar7 & 0x40000) != 0) {
    uVar2 = BUFC_StartRxLenThrEvent();
    switch(uVar2) {
    case 1:
    case 3:
      uVar4 = uVar4 | 0x1000;
      break;
    case 2:
      uVar4 = uVar4 | 0x200;
      break;
    case 4:
      uVar4 = uVar4 | 0x100;
      break;
    case 5:
      uVar4 = uVar4 | 0x80;
      break;
    case 6:
    case 7:
      uVar4 = uVar4 | 8;
      break;
    default:
      RAILInt_Assert(0,3);
    }
  }
  if (uVar10 != 0) {
    if ((uVar10 & 0x1000) != 0) {
      uVar4 = uVar4 | 0x4000;
    }
    if ((uVar10 & 0x100) != 0) {
      uVar4 = uVar4 | 0x8000;
    }
    if ((uVar10 & 0x2000) != 0) {
      uVar6 = uVar6 | 1;
    }
    if ((uVar10 & 0x200) != 0) {
      uVar4 = uVar4 | 0x10;
    }
    if ((uVar10 & 0x400) != 0) {
      uVar4 = uVar4 | 0x20;
    }
    if ((uVar10 & 0x800) != 0) {
      uVar4 = uVar4 | 0x40;
    }
  }
  if (uVar8 != 0) {
    if ((uVar8 & 0x2000000) != 0) {
      uVar6 = uVar6 | 0x20;
    }
    if ((uVar8 & 0x4000000) != 0) {
      uVar6 = uVar6 | 0x40;
    }
    if ((uVar8 & 0x8000000) != 0) {
      uVar6 = uVar6 | 0x80;
    }
    if ((uVar8 & 0x40000) != 0) {
      uVar5 = 2;
    }
    if ((uVar8 & 0x10000) != 0) {
      uVar4 = uVar4 | 0x400;
    }
    if ((uVar8 & 0x100000) != 0) {
      uVar4 = uVar4 | 0x2000;
    }
    if ((uVar8 & 0x200000) != 0) {
      uVar4 = uVar4 | 2;
    }
    if (((uVar8 & 0x80000) != 0) && (iVar3 = GENERIC_PHY_CanModifyAck(), iVar3 != 0)) {
      uVar4 = uVar4 | 0x10000;
    }
  }
  if (uVar9 == 0) goto LAB_0001126e;
  if ((uVar9 & 0x800) != 0) {
    PROTIMER_CCTimerStop(3);
    BUS_RegMaskedClear(&PROTIMER->RXCTRL,0x1f1f);
    write_volatile_4(PROTIMER->IFC,0x800);
    PROTIMER_ClearTxEnable();
  }
  if ((uVar9 & 0x2000000) != 0) {
    PTI_AuxdataOutput(0x2b);
    uVar4 = uVar4 | 0x20000000;
  }
  if ((uVar9 & 0x700000) == 0) {
    if ((uVar9 & 0x1000) != 0) {
      if (iVar1 != 0) goto LAB_00011158;
      PROTIMER_CCTimerStop(4);
      PROTIMER_CCTimerStop(3);
      PROTIMER_ClearRxEnable();
      uVar2 = CORE_EnterCritical();
      if (scheduledRxHardEnd != '\0') {
        RADIO_RACRxAbort();
      }
      iVar1 = BUFC_RxBufferBytesAvailable();
      uVar10 = (RAC->STATUS);
      if (((uVar10 << 4) >> 0x1c == 3) || (iVar1 != 0)) {
        iVar1 = 1;
        pendedRxWindowEnd = scheduledRxLoop;
      }
      CORE_ExitCritical(uVar2);
      if (iVar1 == 0) {
        overrideRxRollback = 0;
        GENERIC_PHY_ConfigureRollbackReporting();
        uVar10 = 0x800;
      }
      else {
        uVar10 = 0;
      }
      uVar4 = uVar4 | uVar10;
    }
  }
  else {
LAB_00011158:
    uVar9 = PROTIMER_CheckCcaReallyFailed(uVar9);
    if ((uVar9 & 0x200000) != 0) {
      PTI_AuxdataOutput(0x29);
      uVar4 = uVar4 | 0x10000000;
    }
    if ((uVar9 & 0x400000) == 0) {
      if ((uVar9 & 0x100000) == 0) {
        if ((uVar9 & 0x1000) != 0) {
          PROTIMER_CCTimerStop(4);
          PROTIMER_LBTStop();
          uVar10 = (PROTIMER->IF);
          if ((uVar10 & 0x500000) == 0) {
            PTI_AuxdataOutput(0x2a);
            write_volatile_4(BUFC->BUF0_CMD,1);
            goto LAB_000111f2;
          }
        }
      }
      else {
        PROTIMER_CCTimerStop(4);
        PTI_AuxdataOutput(0x28);
        uVar4 = uVar4 | 0x4000000;
      }
    }
    else {
      PROTIMER_CCTimerStop(4);
      PTI_AuxdataOutput(0x27);
      BUS_RegMaskedClear(&RAC->SR0,0x80);
      BUS_RegMaskedClear(&RAC->RXENSRCEN,0x10);
LAB_000111f2:
      uVar4 = uVar4 | 0x8000000;
    }
  }
  if ((uVar9 & 0x400) != 0) {
    PROTIMER_CCTimerStop(2);
    uVar6 = uVar6 | 4;
  }
LAB_0001126e:
  GENERIC_PHY_IssueCallback(enabledRailEvents & uVar4,DAT_000112fc & uVar5,enabledPhyEvents & uVar6)
  ;
  if ((uVar7 & 0x40000) != 0) {
    BUFC_EndRxLenThrEvent();
    GENERIC_PHY_CheckPendedRxWindowEnd();
  }
  if (uVar8 != 0) {
    if ((uVar8 & 0x2000000) != 0) {
      PA_RunPeakDetectorHigh();
    }
    if ((uVar8 & 0x4000000) != 0) {
      PA_RunPeakDetectorLow();
    }
    if ((uVar8 & 0x8000000) != 0) {
      PA_RunBatHigh();
      return;
    }
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void BUFC_IRQHandler(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  uint32_t uVar7;
  uint32_t uVar8;
  uint32_t uVar9;
  uint32_t uVar10;
  
  uVar4 = (FRC->IF);
  uVar6 = (FRC->IEN);
  uVar6 = uVar6 & uVar4;
  write_volatile_4(FRC->IFC,uVar6);
  uVar4 = (BUFC->IF);
  uVar7 = (BUFC->IEN);
  uVar7 = uVar7 & uVar4;
  write_volatile_4(BUFC->IFC,uVar7);
  uVar4 = (MODEM->IF);
  uVar10 = (MODEM->IEN);
  uVar10 = uVar10 & uVar4;
  write_volatile_4(MODEM->IFC,uVar10);
  uVar4 = (RAC->IF);
  uVar8 = (RAC->IEN);
  uVar8 = uVar8 & uVar4;
  write_volatile_4(RAC->IFC,uVar8 & 0xffff0000);
  iVar1 = PROTIMER_LBTIsActive();
  uVar4 = (PROTIMER->IF);
  uVar9 = (PROTIMER->IEN);
  uVar9 = uVar9 & uVar4;
  write_volatile_4(PROTIMER->IFC,uVar9 & 0xfffff7ff);
  if (uVar6 == 0) {
    uVar4 = 0;
  }
  else {
    if ((int)(uVar6 << 0x10) < 0) {
      uVar4 = (RAC->SR0);
      BUS_RegMaskedClear(&RAC->SR0,uVar4 & 0x1c00);
      BUS_RegMaskedClear(&RAC->SR0,0x80);
      BUS_RegMaskedClear(&RAC->RXENSRCEN,0x10);
      if ((uVar4 & 0x1c00) == 0) {
        uVar4 = 0x40000;
      }
      else {
        if ((int)(uVar4 << 0x13) < 0) {
          uVar4 = 0x1000000;
        }
        else {
          if ((int)(uVar4 << 0x15) < 0) {
            uVar4 = 0x100000;
          }
          else {
            uVar4 = 0x400000;
          }
        }
      }
    }
    else {
      uVar4 = 0;
    }
    if ((int)(uVar6 << 0x1e) < 0) {
      uVar5 = (RAC->SR0);
      BUS_RegMaskedClear(&RAC->SR0,uVar5 & 0xe000);
      if ((uVar5 & 0xe000) == 0) {
        uVar4 = uVar4 | 0x80000;
      }
      else {
        if ((int)(uVar5 << 0x10) < 0) {
          uVar4 = uVar4 | 0x2000000;
        }
        else {
          if ((int)(uVar5 << 0x12) < 0) {
            uVar4 = uVar4 | 0x200000;
          }
          else {
            uVar4 = uVar4 | 0x800000;
          }
        }
      }
    }
    if ((uVar6 & 0x2000) == 0) {
      uVar6 = 0;
    }
    else {
      uVar6 = 8;
    }
  }
  uVar5 = 0;
  if ((uVar7 & 0x90b0a09) != 0) {
    if ((uVar7 & 0xa00) != 0) {
      GENERIC_PHY_ResetRxFifo(0);
      uVar7 = uVar7 & 0xfffbffff;
      RAILInt_Assert(0,6);
    }
    if ((uVar7 & 9) != 0) {
      write_volatile_4(RAC->CMD,0x20);
      write_volatile_4(BUFC->BUF0_CMD,1);
      RAILInt_Assert(0,8);
    }
    if ((uVar7 & 0x9000000) != 0) {
      write_volatile_4(RAC->CMD,0x20);
      BUFC_TxAckBufferReset();
      RAILInt_Assert(0,9);
    }
    if ((uVar7 & 0xa0000) != 0) {
      GENERIC_PHY_ResetRxFifo(0);
      uVar7 = uVar7 & 0xfffbffff;
      RAILInt_Assert(0,7);
    }
    if ((int)(uVar7 << 0xf) < 0) {
      BUFC_HandleRxLenOvfEvent();
    }
  }
  if ((int)(uVar7 << 0x1d) < 0) {
    if (_DAT_430204b4 == 0) {
      BUS_RegMaskedSet(&BUFC->BUF0_THRESHOLDCTRL,0x2000);
    }
    else {
      uVar4 = uVar4 | 0x20000;
      BUS_RegMaskedClear(&BUFC->BUF0_THRESHOLDCTRL,0x2000);
    }
  }
  if ((int)(uVar7 << 0x15) < 0) {
    uVar4 = uVar4 | 4;
  }
  if ((uVar7 & 0x40000) != 0) {
    uVar2 = BUFC_StartRxLenThrEvent();
    switch(uVar2) {
    case 1:
    case 3:
      uVar4 = uVar4 | 0x1000;
      break;
    case 2:
      uVar4 = uVar4 | 0x200;
      break;
    case 4:
      uVar4 = uVar4 | 0x100;
      break;
    case 5:
      uVar4 = uVar4 | 0x80;
      break;
    case 6:
    case 7:
      uVar4 = uVar4 | 8;
      break;
    default:
      RAILInt_Assert(0,3);
    }
  }
  if (uVar10 != 0) {
    if ((uVar10 & 0x1000) != 0) {
      uVar4 = uVar4 | 0x4000;
    }
    if ((uVar10 & 0x100) != 0) {
      uVar4 = uVar4 | 0x8000;
    }
    if ((uVar10 & 0x2000) != 0) {
      uVar6 = uVar6 | 1;
    }
    if ((uVar10 & 0x200) != 0) {
      uVar4 = uVar4 | 0x10;
    }
    if ((uVar10 & 0x400) != 0) {
      uVar4 = uVar4 | 0x20;
    }
    if ((uVar10 & 0x800) != 0) {
      uVar4 = uVar4 | 0x40;
    }
  }
  if (uVar8 != 0) {
    if ((uVar8 & 0x2000000) != 0) {
      uVar6 = uVar6 | 0x20;
    }
    if ((uVar8 & 0x4000000) != 0) {
      uVar6 = uVar6 | 0x40;
    }
    if ((uVar8 & 0x8000000) != 0) {
      uVar6 = uVar6 | 0x80;
    }
    if ((uVar8 & 0x40000) != 0) {
      uVar5 = 2;
    }
    if ((uVar8 & 0x10000) != 0) {
      uVar4 = uVar4 | 0x400;
    }
    if ((uVar8 & 0x100000) != 0) {
      uVar4 = uVar4 | 0x2000;
    }
    if ((uVar8 & 0x200000) != 0) {
      uVar4 = uVar4 | 2;
    }
    if (((uVar8 & 0x80000) != 0) && (iVar3 = GENERIC_PHY_CanModifyAck(), iVar3 != 0)) {
      uVar4 = uVar4 | 0x10000;
    }
  }
  if (uVar9 == 0) goto LAB_0001126e;
  if ((uVar9 & 0x800) != 0) {
    PROTIMER_CCTimerStop(3);
    BUS_RegMaskedClear(&PROTIMER->RXCTRL,0x1f1f);
    write_volatile_4(PROTIMER->IFC,0x800);
    PROTIMER_ClearTxEnable();
  }
  if ((uVar9 & 0x2000000) != 0) {
    PTI_AuxdataOutput(0x2b);
    uVar4 = uVar4 | 0x20000000;
  }
  if ((uVar9 & 0x700000) == 0) {
    if ((uVar9 & 0x1000) != 0) {
      if (iVar1 != 0) goto LAB_00011158;
      PROTIMER_CCTimerStop(4);
      PROTIMER_CCTimerStop(3);
      PROTIMER_ClearRxEnable();
      uVar2 = CORE_EnterCritical();
      if (scheduledRxHardEnd != '\0') {
        RADIO_RACRxAbort();
      }
      iVar1 = BUFC_RxBufferBytesAvailable();
      uVar10 = (RAC->STATUS);
      if (((uVar10 << 4) >> 0x1c == 3) || (iVar1 != 0)) {
        iVar1 = 1;
        pendedRxWindowEnd = scheduledRxLoop;
      }
      CORE_ExitCritical(uVar2);
      if (iVar1 == 0) {
        overrideRxRollback = 0;
        GENERIC_PHY_ConfigureRollbackReporting();
        uVar10 = 0x800;
      }
      else {
        uVar10 = 0;
      }
      uVar4 = uVar4 | uVar10;
    }
  }
  else {
LAB_00011158:
    uVar9 = PROTIMER_CheckCcaReallyFailed(uVar9);
    if ((uVar9 & 0x200000) != 0) {
      PTI_AuxdataOutput(0x29);
      uVar4 = uVar4 | 0x10000000;
    }
    if ((uVar9 & 0x400000) == 0) {
      if ((uVar9 & 0x100000) == 0) {
        if ((uVar9 & 0x1000) != 0) {
          PROTIMER_CCTimerStop(4);
          PROTIMER_LBTStop();
          uVar10 = (PROTIMER->IF);
          if ((uVar10 & 0x500000) == 0) {
            PTI_AuxdataOutput(0x2a);
            write_volatile_4(BUFC->BUF0_CMD,1);
            goto LAB_000111f2;
          }
        }
      }
      else {
        PROTIMER_CCTimerStop(4);
        PTI_AuxdataOutput(0x28);
        uVar4 = uVar4 | 0x4000000;
      }
    }
    else {
      PROTIMER_CCTimerStop(4);
      PTI_AuxdataOutput(0x27);
      BUS_RegMaskedClear(&RAC->SR0,0x80);
      BUS_RegMaskedClear(&RAC->RXENSRCEN,0x10);
LAB_000111f2:
      uVar4 = uVar4 | 0x8000000;
    }
  }
  if ((uVar9 & 0x400) != 0) {
    PROTIMER_CCTimerStop(2);
    uVar6 = uVar6 | 4;
  }
LAB_0001126e:
  GENERIC_PHY_IssueCallback(enabledRailEvents & uVar4,DAT_000112fc & uVar5,enabledPhyEvents & uVar6)
  ;
  if ((uVar7 & 0x40000) != 0) {
    BUFC_EndRxLenThrEvent();
    GENERIC_PHY_CheckPendedRxWindowEnd();
  }
  if (uVar8 != 0) {
    if ((uVar8 & 0x2000000) != 0) {
      PA_RunPeakDetectorHigh();
    }
    if ((uVar8 & 0x4000000) != 0) {
      PA_RunPeakDetectorLow();
    }
    if ((uVar8 & 0x8000000) != 0) {
      PA_RunBatHigh();
      return;
    }
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void PROTIMER_IRQHandler(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  uint32_t uVar7;
  uint32_t uVar8;
  uint32_t uVar9;
  uint32_t uVar10;
  
  uVar4 = (FRC->IF);
  uVar6 = (FRC->IEN);
  uVar6 = uVar6 & uVar4;
  write_volatile_4(FRC->IFC,uVar6);
  uVar4 = (BUFC->IF);
  uVar7 = (BUFC->IEN);
  uVar7 = uVar7 & uVar4;
  write_volatile_4(BUFC->IFC,uVar7);
  uVar4 = (MODEM->IF);
  uVar10 = (MODEM->IEN);
  uVar10 = uVar10 & uVar4;
  write_volatile_4(MODEM->IFC,uVar10);
  uVar4 = (RAC->IF);
  uVar8 = (RAC->IEN);
  uVar8 = uVar8 & uVar4;
  write_volatile_4(RAC->IFC,uVar8 & 0xffff0000);
  iVar1 = PROTIMER_LBTIsActive();
  uVar4 = (PROTIMER->IF);
  uVar9 = (PROTIMER->IEN);
  uVar9 = uVar9 & uVar4;
  write_volatile_4(PROTIMER->IFC,uVar9 & 0xfffff7ff);
  if (uVar6 == 0) {
    uVar4 = 0;
  }
  else {
    if ((int)(uVar6 << 0x10) < 0) {
      uVar4 = (RAC->SR0);
      BUS_RegMaskedClear(&RAC->SR0,uVar4 & 0x1c00);
      BUS_RegMaskedClear(&RAC->SR0,0x80);
      BUS_RegMaskedClear(&RAC->RXENSRCEN,0x10);
      if ((uVar4 & 0x1c00) == 0) {
        uVar4 = 0x40000;
      }
      else {
        if ((int)(uVar4 << 0x13) < 0) {
          uVar4 = 0x1000000;
        }
        else {
          if ((int)(uVar4 << 0x15) < 0) {
            uVar4 = 0x100000;
          }
          else {
            uVar4 = 0x400000;
          }
        }
      }
    }
    else {
      uVar4 = 0;
    }
    if ((int)(uVar6 << 0x1e) < 0) {
      uVar5 = (RAC->SR0);
      BUS_RegMaskedClear(&RAC->SR0,uVar5 & 0xe000);
      if ((uVar5 & 0xe000) == 0) {
        uVar4 = uVar4 | 0x80000;
      }
      else {
        if ((int)(uVar5 << 0x10) < 0) {
          uVar4 = uVar4 | 0x2000000;
        }
        else {
          if ((int)(uVar5 << 0x12) < 0) {
            uVar4 = uVar4 | 0x200000;
          }
          else {
            uVar4 = uVar4 | 0x800000;
          }
        }
      }
    }
    if ((uVar6 & 0x2000) == 0) {
      uVar6 = 0;
    }
    else {
      uVar6 = 8;
    }
  }
  uVar5 = 0;
  if ((uVar7 & 0x90b0a09) != 0) {
    if ((uVar7 & 0xa00) != 0) {
      GENERIC_PHY_ResetRxFifo(0);
      uVar7 = uVar7 & 0xfffbffff;
      RAILInt_Assert(0,6);
    }
    if ((uVar7 & 9) != 0) {
      write_volatile_4(RAC->CMD,0x20);
      write_volatile_4(BUFC->BUF0_CMD,1);
      RAILInt_Assert(0,8);
    }
    if ((uVar7 & 0x9000000) != 0) {
      write_volatile_4(RAC->CMD,0x20);
      BUFC_TxAckBufferReset();
      RAILInt_Assert(0,9);
    }
    if ((uVar7 & 0xa0000) != 0) {
      GENERIC_PHY_ResetRxFifo(0);
      uVar7 = uVar7 & 0xfffbffff;
      RAILInt_Assert(0,7);
    }
    if ((int)(uVar7 << 0xf) < 0) {
      BUFC_HandleRxLenOvfEvent();
    }
  }
  if ((int)(uVar7 << 0x1d) < 0) {
    if (_DAT_430204b4 == 0) {
      BUS_RegMaskedSet(&BUFC->BUF0_THRESHOLDCTRL,0x2000);
    }
    else {
      uVar4 = uVar4 | 0x20000;
      BUS_RegMaskedClear(&BUFC->BUF0_THRESHOLDCTRL,0x2000);
    }
  }
  if ((int)(uVar7 << 0x15) < 0) {
    uVar4 = uVar4 | 4;
  }
  if ((uVar7 & 0x40000) != 0) {
    uVar2 = BUFC_StartRxLenThrEvent();
    switch(uVar2) {
    case 1:
    case 3:
      uVar4 = uVar4 | 0x1000;
      break;
    case 2:
      uVar4 = uVar4 | 0x200;
      break;
    case 4:
      uVar4 = uVar4 | 0x100;
      break;
    case 5:
      uVar4 = uVar4 | 0x80;
      break;
    case 6:
    case 7:
      uVar4 = uVar4 | 8;
      break;
    default:
      RAILInt_Assert(0,3);
    }
  }
  if (uVar10 != 0) {
    if ((uVar10 & 0x1000) != 0) {
      uVar4 = uVar4 | 0x4000;
    }
    if ((uVar10 & 0x100) != 0) {
      uVar4 = uVar4 | 0x8000;
    }
    if ((uVar10 & 0x2000) != 0) {
      uVar6 = uVar6 | 1;
    }
    if ((uVar10 & 0x200) != 0) {
      uVar4 = uVar4 | 0x10;
    }
    if ((uVar10 & 0x400) != 0) {
      uVar4 = uVar4 | 0x20;
    }
    if ((uVar10 & 0x800) != 0) {
      uVar4 = uVar4 | 0x40;
    }
  }
  if (uVar8 != 0) {
    if ((uVar8 & 0x2000000) != 0) {
      uVar6 = uVar6 | 0x20;
    }
    if ((uVar8 & 0x4000000) != 0) {
      uVar6 = uVar6 | 0x40;
    }
    if ((uVar8 & 0x8000000) != 0) {
      uVar6 = uVar6 | 0x80;
    }
    if ((uVar8 & 0x40000) != 0) {
      uVar5 = 2;
    }
    if ((uVar8 & 0x10000) != 0) {
      uVar4 = uVar4 | 0x400;
    }
    if ((uVar8 & 0x100000) != 0) {
      uVar4 = uVar4 | 0x2000;
    }
    if ((uVar8 & 0x200000) != 0) {
      uVar4 = uVar4 | 2;
    }
    if (((uVar8 & 0x80000) != 0) && (iVar3 = GENERIC_PHY_CanModifyAck(), iVar3 != 0)) {
      uVar4 = uVar4 | 0x10000;
    }
  }
  if (uVar9 == 0) goto LAB_0001126e;
  if ((uVar9 & 0x800) != 0) {
    PROTIMER_CCTimerStop(3);
    BUS_RegMaskedClear(&PROTIMER->RXCTRL,0x1f1f);
    write_volatile_4(PROTIMER->IFC,0x800);
    PROTIMER_ClearTxEnable();
  }
  if ((uVar9 & 0x2000000) != 0) {
    PTI_AuxdataOutput(0x2b);
    uVar4 = uVar4 | 0x20000000;
  }
  if ((uVar9 & 0x700000) == 0) {
    if ((uVar9 & 0x1000) != 0) {
      if (iVar1 != 0) goto LAB_00011158;
      PROTIMER_CCTimerStop(4);
      PROTIMER_CCTimerStop(3);
      PROTIMER_ClearRxEnable();
      uVar2 = CORE_EnterCritical();
      if (scheduledRxHardEnd != '\0') {
        RADIO_RACRxAbort();
      }
      iVar1 = BUFC_RxBufferBytesAvailable();
      uVar10 = (RAC->STATUS);
      if (((uVar10 << 4) >> 0x1c == 3) || (iVar1 != 0)) {
        iVar1 = 1;
        pendedRxWindowEnd = scheduledRxLoop;
      }
      CORE_ExitCritical(uVar2);
      if (iVar1 == 0) {
        overrideRxRollback = 0;
        GENERIC_PHY_ConfigureRollbackReporting();
        uVar10 = 0x800;
      }
      else {
        uVar10 = 0;
      }
      uVar4 = uVar4 | uVar10;
    }
  }
  else {
LAB_00011158:
    uVar9 = PROTIMER_CheckCcaReallyFailed(uVar9);
    if ((uVar9 & 0x200000) != 0) {
      PTI_AuxdataOutput(0x29);
      uVar4 = uVar4 | 0x10000000;
    }
    if ((uVar9 & 0x400000) == 0) {
      if ((uVar9 & 0x100000) == 0) {
        if ((uVar9 & 0x1000) != 0) {
          PROTIMER_CCTimerStop(4);
          PROTIMER_LBTStop();
          uVar10 = (PROTIMER->IF);
          if ((uVar10 & 0x500000) == 0) {
            PTI_AuxdataOutput(0x2a);
            write_volatile_4(BUFC->BUF0_CMD,1);
            goto LAB_000111f2;
          }
        }
      }
      else {
        PROTIMER_CCTimerStop(4);
        PTI_AuxdataOutput(0x28);
        uVar4 = uVar4 | 0x4000000;
      }
    }
    else {
      PROTIMER_CCTimerStop(4);
      PTI_AuxdataOutput(0x27);
      BUS_RegMaskedClear(&RAC->SR0,0x80);
      BUS_RegMaskedClear(&RAC->RXENSRCEN,0x10);
LAB_000111f2:
      uVar4 = uVar4 | 0x8000000;
    }
  }
  if ((uVar9 & 0x400) != 0) {
    PROTIMER_CCTimerStop(2);
    uVar6 = uVar6 | 4;
  }
LAB_0001126e:
  GENERIC_PHY_IssueCallback(enabledRailEvents & uVar4,DAT_000112fc & uVar5,enabledPhyEvents & uVar6)
  ;
  if ((uVar7 & 0x40000) != 0) {
    BUFC_EndRxLenThrEvent();
    GENERIC_PHY_CheckPendedRxWindowEnd();
  }
  if (uVar8 != 0) {
    if ((uVar8 & 0x2000000) != 0) {
      PA_RunPeakDetectorHigh();
    }
    if ((uVar8 & 0x4000000) != 0) {
      PA_RunPeakDetectorLow();
    }
    if ((uVar8 & 0x8000000) != 0) {
      PA_RunBatHigh();
      return;
    }
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void RAC_SEQ_IRQHandler(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  uint32_t uVar7;
  uint32_t uVar8;
  uint32_t uVar9;
  uint32_t uVar10;
  
  uVar4 = (FRC->IF);
  uVar6 = (FRC->IEN);
  uVar6 = uVar6 & uVar4;
  write_volatile_4(FRC->IFC,uVar6);
  uVar4 = (BUFC->IF);
  uVar7 = (BUFC->IEN);
  uVar7 = uVar7 & uVar4;
  write_volatile_4(BUFC->IFC,uVar7);
  uVar4 = (MODEM->IF);
  uVar10 = (MODEM->IEN);
  uVar10 = uVar10 & uVar4;
  write_volatile_4(MODEM->IFC,uVar10);
  uVar4 = (RAC->IF);
  uVar8 = (RAC->IEN);
  uVar8 = uVar8 & uVar4;
  write_volatile_4(RAC->IFC,uVar8 & 0xffff0000);
  iVar1 = PROTIMER_LBTIsActive();
  uVar4 = (PROTIMER->IF);
  uVar9 = (PROTIMER->IEN);
  uVar9 = uVar9 & uVar4;
  write_volatile_4(PROTIMER->IFC,uVar9 & 0xfffff7ff);
  if (uVar6 == 0) {
    uVar4 = 0;
  }
  else {
    if ((int)(uVar6 << 0x10) < 0) {
      uVar4 = (RAC->SR0);
      BUS_RegMaskedClear(&RAC->SR0,uVar4 & 0x1c00);
      BUS_RegMaskedClear(&RAC->SR0,0x80);
      BUS_RegMaskedClear(&RAC->RXENSRCEN,0x10);
      if ((uVar4 & 0x1c00) == 0) {
        uVar4 = 0x40000;
      }
      else {
        if ((int)(uVar4 << 0x13) < 0) {
          uVar4 = 0x1000000;
        }
        else {
          if ((int)(uVar4 << 0x15) < 0) {
            uVar4 = 0x100000;
          }
          else {
            uVar4 = 0x400000;
          }
        }
      }
    }
    else {
      uVar4 = 0;
    }
    if ((int)(uVar6 << 0x1e) < 0) {
      uVar5 = (RAC->SR0);
      BUS_RegMaskedClear(&RAC->SR0,uVar5 & 0xe000);
      if ((uVar5 & 0xe000) == 0) {
        uVar4 = uVar4 | 0x80000;
      }
      else {
        if ((int)(uVar5 << 0x10) < 0) {
          uVar4 = uVar4 | 0x2000000;
        }
        else {
          if ((int)(uVar5 << 0x12) < 0) {
            uVar4 = uVar4 | 0x200000;
          }
          else {
            uVar4 = uVar4 | 0x800000;
          }
        }
      }
    }
    if ((uVar6 & 0x2000) == 0) {
      uVar6 = 0;
    }
    else {
      uVar6 = 8;
    }
  }
  uVar5 = 0;
  if ((uVar7 & 0x90b0a09) != 0) {
    if ((uVar7 & 0xa00) != 0) {
      GENERIC_PHY_ResetRxFifo(0);
      uVar7 = uVar7 & 0xfffbffff;
      RAILInt_Assert(0,6);
    }
    if ((uVar7 & 9) != 0) {
      write_volatile_4(RAC->CMD,0x20);
      write_volatile_4(BUFC->BUF0_CMD,1);
      RAILInt_Assert(0,8);
    }
    if ((uVar7 & 0x9000000) != 0) {
      write_volatile_4(RAC->CMD,0x20);
      BUFC_TxAckBufferReset();
      RAILInt_Assert(0,9);
    }
    if ((uVar7 & 0xa0000) != 0) {
      GENERIC_PHY_ResetRxFifo(0);
      uVar7 = uVar7 & 0xfffbffff;
      RAILInt_Assert(0,7);
    }
    if ((int)(uVar7 << 0xf) < 0) {
      BUFC_HandleRxLenOvfEvent();
    }
  }
  if ((int)(uVar7 << 0x1d) < 0) {
    if (_DAT_430204b4 == 0) {
      BUS_RegMaskedSet(&BUFC->BUF0_THRESHOLDCTRL,0x2000);
    }
    else {
      uVar4 = uVar4 | 0x20000;
      BUS_RegMaskedClear(&BUFC->BUF0_THRESHOLDCTRL,0x2000);
    }
  }
  if ((int)(uVar7 << 0x15) < 0) {
    uVar4 = uVar4 | 4;
  }
  if ((uVar7 & 0x40000) != 0) {
    uVar2 = BUFC_StartRxLenThrEvent();
    switch(uVar2) {
    case 1:
    case 3:
      uVar4 = uVar4 | 0x1000;
      break;
    case 2:
      uVar4 = uVar4 | 0x200;
      break;
    case 4:
      uVar4 = uVar4 | 0x100;
      break;
    case 5:
      uVar4 = uVar4 | 0x80;
      break;
    case 6:
    case 7:
      uVar4 = uVar4 | 8;
      break;
    default:
      RAILInt_Assert(0,3);
    }
  }
  if (uVar10 != 0) {
    if ((uVar10 & 0x1000) != 0) {
      uVar4 = uVar4 | 0x4000;
    }
    if ((uVar10 & 0x100) != 0) {
      uVar4 = uVar4 | 0x8000;
    }
    if ((uVar10 & 0x2000) != 0) {
      uVar6 = uVar6 | 1;
    }
    if ((uVar10 & 0x200) != 0) {
      uVar4 = uVar4 | 0x10;
    }
    if ((uVar10 & 0x400) != 0) {
      uVar4 = uVar4 | 0x20;
    }
    if ((uVar10 & 0x800) != 0) {
      uVar4 = uVar4 | 0x40;
    }
  }
  if (uVar8 != 0) {
    if ((uVar8 & 0x2000000) != 0) {
      uVar6 = uVar6 | 0x20;
    }
    if ((uVar8 & 0x4000000) != 0) {
      uVar6 = uVar6 | 0x40;
    }
    if ((uVar8 & 0x8000000) != 0) {
      uVar6 = uVar6 | 0x80;
    }
    if ((uVar8 & 0x40000) != 0) {
      uVar5 = 2;
    }
    if ((uVar8 & 0x10000) != 0) {
      uVar4 = uVar4 | 0x400;
    }
    if ((uVar8 & 0x100000) != 0) {
      uVar4 = uVar4 | 0x2000;
    }
    if ((uVar8 & 0x200000) != 0) {
      uVar4 = uVar4 | 2;
    }
    if (((uVar8 & 0x80000) != 0) && (iVar3 = GENERIC_PHY_CanModifyAck(), iVar3 != 0)) {
      uVar4 = uVar4 | 0x10000;
    }
  }
  if (uVar9 == 0) goto LAB_0001126e;
  if ((uVar9 & 0x800) != 0) {
    PROTIMER_CCTimerStop(3);
    BUS_RegMaskedClear(&PROTIMER->RXCTRL,0x1f1f);
    write_volatile_4(PROTIMER->IFC,0x800);
    PROTIMER_ClearTxEnable();
  }
  if ((uVar9 & 0x2000000) != 0) {
    PTI_AuxdataOutput(0x2b);
    uVar4 = uVar4 | 0x20000000;
  }
  if ((uVar9 & 0x700000) == 0) {
    if ((uVar9 & 0x1000) != 0) {
      if (iVar1 != 0) goto LAB_00011158;
      PROTIMER_CCTimerStop(4);
      PROTIMER_CCTimerStop(3);
      PROTIMER_ClearRxEnable();
      uVar2 = CORE_EnterCritical();
      if (scheduledRxHardEnd != '\0') {
        RADIO_RACRxAbort();
      }
      iVar1 = BUFC_RxBufferBytesAvailable();
      uVar10 = (RAC->STATUS);
      if (((uVar10 << 4) >> 0x1c == 3) || (iVar1 != 0)) {
        iVar1 = 1;
        pendedRxWindowEnd = scheduledRxLoop;
      }
      CORE_ExitCritical(uVar2);
      if (iVar1 == 0) {
        overrideRxRollback = 0;
        GENERIC_PHY_ConfigureRollbackReporting();
        uVar10 = 0x800;
      }
      else {
        uVar10 = 0;
      }
      uVar4 = uVar4 | uVar10;
    }
  }
  else {
LAB_00011158:
    uVar9 = PROTIMER_CheckCcaReallyFailed(uVar9);
    if ((uVar9 & 0x200000) != 0) {
      PTI_AuxdataOutput(0x29);
      uVar4 = uVar4 | 0x10000000;
    }
    if ((uVar9 & 0x400000) == 0) {
      if ((uVar9 & 0x100000) == 0) {
        if ((uVar9 & 0x1000) != 0) {
          PROTIMER_CCTimerStop(4);
          PROTIMER_LBTStop();
          uVar10 = (PROTIMER->IF);
          if ((uVar10 & 0x500000) == 0) {
            PTI_AuxdataOutput(0x2a);
            write_volatile_4(BUFC->BUF0_CMD,1);
            goto LAB_000111f2;
          }
        }
      }
      else {
        PROTIMER_CCTimerStop(4);
        PTI_AuxdataOutput(0x28);
        uVar4 = uVar4 | 0x4000000;
      }
    }
    else {
      PROTIMER_CCTimerStop(4);
      PTI_AuxdataOutput(0x27);
      BUS_RegMaskedClear(&RAC->SR0,0x80);
      BUS_RegMaskedClear(&RAC->RXENSRCEN,0x10);
LAB_000111f2:
      uVar4 = uVar4 | 0x8000000;
    }
  }
  if ((uVar9 & 0x400) != 0) {
    PROTIMER_CCTimerStop(2);
    uVar6 = uVar6 | 4;
  }
LAB_0001126e:
  GENERIC_PHY_IssueCallback(enabledRailEvents & uVar4,DAT_000112fc & uVar5,enabledPhyEvents & uVar6)
  ;
  if ((uVar7 & 0x40000) != 0) {
    BUFC_EndRxLenThrEvent();
    GENERIC_PHY_CheckPendedRxWindowEnd();
  }
  if (uVar8 != 0) {
    if ((uVar8 & 0x2000000) != 0) {
      PA_RunPeakDetectorHigh();
    }
    if ((uVar8 & 0x4000000) != 0) {
      PA_RunPeakDetectorLow();
    }
    if ((uVar8 & 0x8000000) != 0) {
      PA_RunBatHigh();
      return;
    }
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void MODEM_IRQHandler(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  uint32_t uVar7;
  uint32_t uVar8;
  uint32_t uVar9;
  uint32_t uVar10;
  
  uVar4 = (FRC->IF);
  uVar6 = (FRC->IEN);
  uVar6 = uVar6 & uVar4;
  write_volatile_4(FRC->IFC,uVar6);
  uVar4 = (BUFC->IF);
  uVar7 = (BUFC->IEN);
  uVar7 = uVar7 & uVar4;
  write_volatile_4(BUFC->IFC,uVar7);
  uVar4 = (MODEM->IF);
  uVar10 = (MODEM->IEN);
  uVar10 = uVar10 & uVar4;
  write_volatile_4(MODEM->IFC,uVar10);
  uVar4 = (RAC->IF);
  uVar8 = (RAC->IEN);
  uVar8 = uVar8 & uVar4;
  write_volatile_4(RAC->IFC,uVar8 & 0xffff0000);
  iVar1 = PROTIMER_LBTIsActive();
  uVar4 = (PROTIMER->IF);
  uVar9 = (PROTIMER->IEN);
  uVar9 = uVar9 & uVar4;
  write_volatile_4(PROTIMER->IFC,uVar9 & 0xfffff7ff);
  if (uVar6 == 0) {
    uVar4 = 0;
  }
  else {
    if ((int)(uVar6 << 0x10) < 0) {
      uVar4 = (RAC->SR0);
      BUS_RegMaskedClear(&RAC->SR0,uVar4 & 0x1c00);
      BUS_RegMaskedClear(&RAC->SR0,0x80);
      BUS_RegMaskedClear(&RAC->RXENSRCEN,0x10);
      if ((uVar4 & 0x1c00) == 0) {
        uVar4 = 0x40000;
      }
      else {
        if ((int)(uVar4 << 0x13) < 0) {
          uVar4 = 0x1000000;
        }
        else {
          if ((int)(uVar4 << 0x15) < 0) {
            uVar4 = 0x100000;
          }
          else {
            uVar4 = 0x400000;
          }
        }
      }
    }
    else {
      uVar4 = 0;
    }
    if ((int)(uVar6 << 0x1e) < 0) {
      uVar5 = (RAC->SR0);
      BUS_RegMaskedClear(&RAC->SR0,uVar5 & 0xe000);
      if ((uVar5 & 0xe000) == 0) {
        uVar4 = uVar4 | 0x80000;
      }
      else {
        if ((int)(uVar5 << 0x10) < 0) {
          uVar4 = uVar4 | 0x2000000;
        }
        else {
          if ((int)(uVar5 << 0x12) < 0) {
            uVar4 = uVar4 | 0x200000;
          }
          else {
            uVar4 = uVar4 | 0x800000;
          }
        }
      }
    }
    if ((uVar6 & 0x2000) == 0) {
      uVar6 = 0;
    }
    else {
      uVar6 = 8;
    }
  }
  uVar5 = 0;
  if ((uVar7 & 0x90b0a09) != 0) {
    if ((uVar7 & 0xa00) != 0) {
      GENERIC_PHY_ResetRxFifo(0);
      uVar7 = uVar7 & 0xfffbffff;
      RAILInt_Assert(0,6);
    }
    if ((uVar7 & 9) != 0) {
      write_volatile_4(RAC->CMD,0x20);
      write_volatile_4(BUFC->BUF0_CMD,1);
      RAILInt_Assert(0,8);
    }
    if ((uVar7 & 0x9000000) != 0) {
      write_volatile_4(RAC->CMD,0x20);
      BUFC_TxAckBufferReset();
      RAILInt_Assert(0,9);
    }
    if ((uVar7 & 0xa0000) != 0) {
      GENERIC_PHY_ResetRxFifo(0);
      uVar7 = uVar7 & 0xfffbffff;
      RAILInt_Assert(0,7);
    }
    if ((int)(uVar7 << 0xf) < 0) {
      BUFC_HandleRxLenOvfEvent();
    }
  }
  if ((int)(uVar7 << 0x1d) < 0) {
    if (_DAT_430204b4 == 0) {
      BUS_RegMaskedSet(&BUFC->BUF0_THRESHOLDCTRL,0x2000);
    }
    else {
      uVar4 = uVar4 | 0x20000;
      BUS_RegMaskedClear(&BUFC->BUF0_THRESHOLDCTRL,0x2000);
    }
  }
  if ((int)(uVar7 << 0x15) < 0) {
    uVar4 = uVar4 | 4;
  }
  if ((uVar7 & 0x40000) != 0) {
    uVar2 = BUFC_StartRxLenThrEvent();
    switch(uVar2) {
    case 1:
    case 3:
      uVar4 = uVar4 | 0x1000;
      break;
    case 2:
      uVar4 = uVar4 | 0x200;
      break;
    case 4:
      uVar4 = uVar4 | 0x100;
      break;
    case 5:
      uVar4 = uVar4 | 0x80;
      break;
    case 6:
    case 7:
      uVar4 = uVar4 | 8;
      break;
    default:
      RAILInt_Assert(0,3);
    }
  }
  if (uVar10 != 0) {
    if ((uVar10 & 0x1000) != 0) {
      uVar4 = uVar4 | 0x4000;
    }
    if ((uVar10 & 0x100) != 0) {
      uVar4 = uVar4 | 0x8000;
    }
    if ((uVar10 & 0x2000) != 0) {
      uVar6 = uVar6 | 1;
    }
    if ((uVar10 & 0x200) != 0) {
      uVar4 = uVar4 | 0x10;
    }
    if ((uVar10 & 0x400) != 0) {
      uVar4 = uVar4 | 0x20;
    }
    if ((uVar10 & 0x800) != 0) {
      uVar4 = uVar4 | 0x40;
    }
  }
  if (uVar8 != 0) {
    if ((uVar8 & 0x2000000) != 0) {
      uVar6 = uVar6 | 0x20;
    }
    if ((uVar8 & 0x4000000) != 0) {
      uVar6 = uVar6 | 0x40;
    }
    if ((uVar8 & 0x8000000) != 0) {
      uVar6 = uVar6 | 0x80;
    }
    if ((uVar8 & 0x40000) != 0) {
      uVar5 = 2;
    }
    if ((uVar8 & 0x10000) != 0) {
      uVar4 = uVar4 | 0x400;
    }
    if ((uVar8 & 0x100000) != 0) {
      uVar4 = uVar4 | 0x2000;
    }
    if ((uVar8 & 0x200000) != 0) {
      uVar4 = uVar4 | 2;
    }
    if (((uVar8 & 0x80000) != 0) && (iVar3 = GENERIC_PHY_CanModifyAck(), iVar3 != 0)) {
      uVar4 = uVar4 | 0x10000;
    }
  }
  if (uVar9 == 0) goto LAB_0001126e;
  if ((uVar9 & 0x800) != 0) {
    PROTIMER_CCTimerStop(3);
    BUS_RegMaskedClear(&PROTIMER->RXCTRL,0x1f1f);
    write_volatile_4(PROTIMER->IFC,0x800);
    PROTIMER_ClearTxEnable();
  }
  if ((uVar9 & 0x2000000) != 0) {
    PTI_AuxdataOutput(0x2b);
    uVar4 = uVar4 | 0x20000000;
  }
  if ((uVar9 & 0x700000) == 0) {
    if ((uVar9 & 0x1000) != 0) {
      if (iVar1 != 0) goto LAB_00011158;
      PROTIMER_CCTimerStop(4);
      PROTIMER_CCTimerStop(3);
      PROTIMER_ClearRxEnable();
      uVar2 = CORE_EnterCritical();
      if (scheduledRxHardEnd != '\0') {
        RADIO_RACRxAbort();
      }
      iVar1 = BUFC_RxBufferBytesAvailable();
      uVar10 = (RAC->STATUS);
      if (((uVar10 << 4) >> 0x1c == 3) || (iVar1 != 0)) {
        iVar1 = 1;
        pendedRxWindowEnd = scheduledRxLoop;
      }
      CORE_ExitCritical(uVar2);
      if (iVar1 == 0) {
        overrideRxRollback = 0;
        GENERIC_PHY_ConfigureRollbackReporting();
        uVar10 = 0x800;
      }
      else {
        uVar10 = 0;
      }
      uVar4 = uVar4 | uVar10;
    }
  }
  else {
LAB_00011158:
    uVar9 = PROTIMER_CheckCcaReallyFailed(uVar9);
    if ((uVar9 & 0x200000) != 0) {
      PTI_AuxdataOutput(0x29);
      uVar4 = uVar4 | 0x10000000;
    }
    if ((uVar9 & 0x400000) == 0) {
      if ((uVar9 & 0x100000) == 0) {
        if ((uVar9 & 0x1000) != 0) {
          PROTIMER_CCTimerStop(4);
          PROTIMER_LBTStop();
          uVar10 = (PROTIMER->IF);
          if ((uVar10 & 0x500000) == 0) {
            PTI_AuxdataOutput(0x2a);
            write_volatile_4(BUFC->BUF0_CMD,1);
            goto LAB_000111f2;
          }
        }
      }
      else {
        PROTIMER_CCTimerStop(4);
        PTI_AuxdataOutput(0x28);
        uVar4 = uVar4 | 0x4000000;
      }
    }
    else {
      PROTIMER_CCTimerStop(4);
      PTI_AuxdataOutput(0x27);
      BUS_RegMaskedClear(&RAC->SR0,0x80);
      BUS_RegMaskedClear(&RAC->RXENSRCEN,0x10);
LAB_000111f2:
      uVar4 = uVar4 | 0x8000000;
    }
  }
  if ((uVar9 & 0x400) != 0) {
    PROTIMER_CCTimerStop(2);
    uVar6 = uVar6 | 4;
  }
LAB_0001126e:
  GENERIC_PHY_IssueCallback(enabledRailEvents & uVar4,DAT_000112fc & uVar5,enabledPhyEvents & uVar6)
  ;
  if ((uVar7 & 0x40000) != 0) {
    BUFC_EndRxLenThrEvent();
    GENERIC_PHY_CheckPendedRxWindowEnd();
  }
  if (uVar8 != 0) {
    if ((uVar8 & 0x2000000) != 0) {
      PA_RunPeakDetectorHigh();
    }
    if ((uVar8 & 0x4000000) != 0) {
      PA_RunPeakDetectorLow();
    }
    if ((uVar8 & 0x8000000) != 0) {
      PA_RunBatHigh();
      return;
    }
  }
  return;
}


