

void RADIO_IRQHandler(void)

{
  int iVar1;
  CORE_irqState_t irqState;
  uint railEvents;
  uint uVar5;
  uint frc_flags;
  uint bufc_flags;
  uint rac_flags;
  uint protimer_flags;
  uint modem_flags;
  uint32_t tmp;
  
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
  
  if (frc_flags == 0) railEvents = 0;
  else 
  {
    if (frc_flags & FRC_IF_TXRAWEVENT_Msk) 
	{
      tmp = RAC->SR0;
      BUS_RegMaskedClear(&RAC->SR0,tmp & 0x1c00);
      BUS_RegMaskedClear(&RAC->SR0,0x80);
      BUS_RegMaskedClear(&RAC->RXENSRCEN,0x10);
      if (!(tmp & 0x1c00)) railEvents = 0x40000;
      else 
	  {
        if (tmp & 0x1000) railEvents = 0x1000000;
        else 
		{
          if (tmp & 0x400) railEvents = 0x100000;
          else railEvents = 0x400000;
        }
      }
    }
    else railEvents = 0;
    if (frc_flags & FRC_IF_TXAFTERFRAMEDONE_Msk) 
	{
      tmp = RAC->SR0;
      BUS_RegMaskedClear(&RAC->SR0,tmp & 0xe000);
      if ((tmp & 0xe000) == 0) railEvents = railEvents | 0x80000;
      else 
	  {
        if ((int)(tmp << 0x10) < 0) railEvents = railEvents | 0x2000000;
        else 
		{
          if ((int)(tmp << 0x12) < 0) railEvents = railEvents | 0x200000;
          else railEvents = railEvents | 0x800000;
        }
      }
    }
    if ((frc_flags & FRC_IF_BUSERROR_Msk) == 0) phyEvents = 0;
    else phyEvents = 8;
  }
  uVar5 = 0;
  if (bufc_flags & 0x90b0a09) 
  {
    if (bufc_flags & 0xa00) 
	{
      GENERIC_PHY_ResetRxFifo(0);
      bufc_flags = bufc_flags & 0xfffbffff;
      RAILInt_Assert(0,6);
    }
    if (bufc_flags & (BUFC_IF_BUF0CORR_Msk | BUFC_IF_BUF0OF_Msk)) //9) != 0) 
	{
      RAC->CMD = RAC_CMD_TXDIS_Msk; //0x20;
      BUFC->BUF0_CMD = BUFC_BUF0_CMD_CLEAR_Msk; //1;
      RAILInt_Assert(0,8);
    }
    if (bufc_flags & (BUFC_IF_BUF3CORR_Msk | BUFC_IF_BUF3OF_Msk)) //0x9000000) != 0) 
	{
      RAC->CMD = RAC_CMD_TXDIS_Msk; //0x20;
      BUFC_TxAckBufferReset();
      RAILInt_Assert(0,9);
    }
    if (bufc_flags & (BUFC_IF_BUF2CORR_Msk | BUFC_IF_BUF2UF_Msk)) //0xa0000) != 0) 
	{
      GENERIC_PHY_ResetRxFifo(0);
      bufc_flags = bufc_flags & 0xfffbffff;
      RAILInt_Assert(0,7);
    }
    if (bufc_flags & BUFC_IF_BUF2OF_Msk) BUFC_HandleRxLenOvfEvent();
  }
  if (bufc_flags & BUFC_IF_BUF0THR_Msk) 
  {
    if (_DAT_430204b4 == 0) BUS_RegMaskedSet(&BUFC->BUF0_THRESHOLDCTRL,BUFC_BUF0_THRESHOLDCTRL_THRESHOLDMODE_Msk);
    else 
	{
      railEvents = railEvents | 0x20000;
      BUS_RegMaskedClear(&BUFC->BUF0_THRESHOLDCTRL,BUFC_BUF0_THRESHOLDCTRL_THRESHOLDMODE_Msk);
    }
  }
  if (bufc_flags & BUFC_IF_BUF1THR_Msk) railEvents = railEvents | 4;
  if (bufc_flags & BUFC_IF_BUF2THR_Msk) 
  {
    switch(BUFC_StartRxLenThrEvent()) 
	{
    case 1:
    case 3:
      railEvents = railEvents | 0x1000;
      break;
    case 2:
      railEvents = railEvents | 0x200;
      break;
    case 4:
      railEvents = railEvents | 0x100;
      break;
    case 5:
      railEvents = railEvents | 0x80;
      break;
    case 6:
    case 7:
      railEvents = railEvents | 8;
      break;
    default:
      RAILInt_Assert(0,3);
    }
  }
  if (modem_flags != 0) 
  {
    if (modem_flags & MODEM_IF_RXTIMLOST_Msk) railEvents = railEvents | 0x4000;
    if (modem_flags & MODEM_IF_RXTIMDET_Msk) railEvents = railEvents | 0x8000;
    if (modem_flags & MODEM_IF_RXPRELOST_Msk) phyEvents = phyEvents | 1;
    if (modem_flags & MODEM_IF_RXPREDET_Msk) railEvents = railEvents | 0x10;
    if (modem_flags & MODEM_IF_RXFRAMEDET0_Msk) railEvents = railEvents | 0x20;
    if (modem_flags & MODEM_IF_RXFRAMEDET1_Msk) railEvents = railEvents | 0x40;
  }
  if (rac_flags != 0) 
  {
    if (rac_flags & RAC_IF_PAVHIGH_Msk) phyEvents = phyEvents | 0x20;
    if (rac_flags & RAC_IF_PAVLOW_Msk) phyEvents = phyEvents | 0x40;
    if (rac_flags & RAC_IF_PABATHIGH_Msk) phyEvents = phyEvents | 0x80;
    if (rac_flags & 0x40000) uVar5 = 2;
    if (rac_flags & 0x10000) railEvents = railEvents | 0x400;
    if (rac_flags & 0x100000) railEvents = railEvents | 0x2000;
    if (rac_flags & 0x200000) railEvents = railEvents | 2;
    if ((rac_flags & 0x80000) && (GENERIC_PHY_CanModifyAck() == true)) railEvents = railEvents | 0x10000;
  }
  if (protimer_flags == 0) goto LAB_0000f236;
  if ((protimer_flags & 0x800) != 0) {
    PROTIMER_CCTimerStop(3);
    BUS_RegMaskedClear(&PROTIMER->RXCTRL,0x1f1f);
    write_volatile_4(PROTIMER->IFC,0x800);
    PROTIMER_ClearTxEnable();
  }
  if ((protimer_flags & 0x2000000) != 0) 
  {
    PTI_AuxdataOutput(0x2b);
    railEvents = railEvents | 0x20000000;
  }
  if ((protimer_flags & 0x700000) == 0) 
  {
    if (protimer_flags & PROTIMER_IF_CC4_Msk) //0x1000) 
	{
      if (iVar1 != 0) goto LAB_0000f120;
      PROTIMER_CCTimerStop(4);
      PROTIMER_CCTimerStop(3);
      PROTIMER_ClearRxEnable();
      irqState = CORE_EnterCritical();
      if (scheduledRxHardEnd != 0) RADIO_RACRxAbort();
      iVar1 = BUFC_RxBufferBytesAvailable();
      if (((RAC->STATUS & RAC_STATUS_STATE_Msk) >> RAC_STATUS_STATE_Pos == 3) || (BUFC_RxBufferBytesAvailable() != 0)) 
	  {
        iVar1 = 1;
        pendedRxWindowEnd = scheduledRxLoop;
      }
      CORE_ExitCritical(irqState);
      if (iVar1 == 0) 
	  {
        overrideRxRollback = 0;
        GENERIC_PHY_ConfigureRollbackReporting();
        tmp = 0x800;
      }
      else tmp = 0;
      railEvents = railEvents | tmp;
    }
  }
  else 
  {
LAB_0000f120:
    protimer_flags = PROTIMER_CheckCcaReallyFailed(protimer_flags);
    if ((protimer_flags & 0x200000) != 0) 
	{
      PTI_AuxdataOutput(0x29);
      railEvents = railEvents | 0x10000000;
    }
    if ((protimer_flags & 0x400000) == 0) 
	{
      if ((protimer_flags & PROTIMER_IF_COF4_Msk) == 0) 
	  {
        if (protimer_flags & PROTIMER_IF_CC4_Msk) 
		{
          PROTIMER_CCTimerStop(4);
          PROTIMER_LBTStop();
          if ((PROTIMER->IF & 0x500000) == 0) 
		  {
            PTI_AuxdataOutput(0x2a);
            BUFC->BUF0_CMD = BUFC_BUF0_CMD_CLEAR_Msk;
            goto LAB_0000f1ba;
          }
        }
      }
      else 
	  {
        PROTIMER_CCTimerStop(4);
        PTI_AuxdataOutput(0x28);
        railEvents = railEvents | 0x4000000;
      }
    }
    else 
	{
      PROTIMER_CCTimerStop(4);
      PTI_AuxdataOutput(0x27);
      BUS_RegMaskedClear(&RAC->SR0,0x80);
      BUS_RegMaskedClear(&RAC->RXENSRCEN,0x10);
LAB_0000f1ba:
      railEvents = railEvents | 0x8000000;
    }
  }
  if (protimer_flags & PROTIMER_IF_CC2_Msk) 
  {
    PROTIMER_CCTimerStop(2);
    phyEvents = phyEvents | 4;
  }
LAB_0000f236:
  GENERIC_PHY_IssueCallback(enabledRailEvents & railEvents,DAT_200044f4 & uVar5,enabledPhyEvents & phyEvents);
  if (bufc_flags & BUFC_IF_BUF2THR_Msk) 
  {
    BUFC_EndRxLenThrEvent();
    GENERIC_PHY_CheckPendedRxWindowEnd();
  }
  if (rac_flags != 0) 
  {
    if (rac_flags & RAC_IF_PAVHIGH_Msk) PA_RunPeakDetectorHigh();
    if (rac_flags & RAC_IF_PAVLOW_Msk) PA_RunPeakDetectorLow();
    if (rac_flags & RAC_IF_PABATHIGH_Msk) PA_RunBatHigh();
  }
}


