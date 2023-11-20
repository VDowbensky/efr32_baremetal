#include "radio_phy.h"

void radio_SetCtune(uint32_t tune)

{
  CMU_ClockSelectSet(0x11,5);
  CMU_OscillatorEnable(2,0,0);
	BUS_RegMaskedClear(&CMU->HFXOSTEADYSTATECTRL, _CMU_HFXOSTEADYSTATECTRL_CTUNE_MASK);
	CMU->HFXOSTEADYSTATECTRL |= (tune & 0x1ff) << _CMU_HFXOSTEADYSTATECTRL_CTUNE_SHIFT;
  CMU_OscillatorEnable(2,1,1);
  CMU_ClockSelectSet(0x11,4);
}


uint32_t radio_GetCtune(void)

{
	return (CMU->HFXOSTEADYSTATECTRL & _CMU_HFXOSTEADYSTATECTRL_CTUNE_MASK) >> _CMU_HFXOSTEADYSTATECTRL_CTUNE_SHIFT;
}

RAIL_Status_t radio_SetTxTransitions(RAIL_RadioState_t success,RAIL_RadioState_t error)

{
  RADIO_TRANSITIONS = 1 << (success + 0x10U & 0xff) | (uint32_t)RADIO_TRANSITIONS | 1 << (error + 0x18U & 0xff);
  return RAIL_STATUS_NO_ERROR;
}


RAIL_Status_t radio_SetRxTransitions(RAIL_RadioState_t success,RAIL_RadioState_t error)

{
	RADIO_TRANSITIONS = 1 << (error + 8U & 0xff) | 1 << (success & 0xff) | RADIO_TRANSITIONS & 0xffff0000;
  return RAIL_STATUS_NO_ERROR;
}

uint32_t radio_HeadedToIdle(void)

{
  uint32_t state;
  
  INT_Disable();
  if ((PROTIMER_CCTimerIsEnabled(3) == false) && (PROTIMER_LBTIsActive() == false)) 
  {
	state = (RAC->STATUS & RAC_STATUS_STATE_Msk) >> RAC_STATUS_STATE_Pos;
  INT_Enable();
	if ((RAC->STATUS & (RAC_STATUS_RXENS_Msk | RAC_STATUS_TXENS_Msk)) || (state == 0x3) || (state == 0x6) || (state == 0x9) || (state == 0xc)) return 0;
	else return 1;
  }
  else 
  {
    INT_Enable();
    return 0;
  }
}

void radio_Enable(uint32_t enable)

{
  if (enable == 0)
  {
    radio_SeqAtomicLock();
    SEQ_CONTROL_REG = SEQ_CONTROL_REG | 0x20;
		BUS_RegMaskedClear(&RAC->RXENSRCEN, RAC_RXENSRCEN_SWRXEN_Msk);
		FRC->CMD = FRC_CMD_RXABORT_Msk; 
		BUS_RegMaskedSet(&RAC->CMD, RAC_CMD_TXDIS_Msk);
		BUS_RegMaskedClear(&RAC->SR0,4);
  }
  else
  {
    if (RAC->CTRL & RAC_CTRL_FORCEDISABLE_Msk) BUS_RegMaskedClear(&RAC->CTRL, RAC_CTRL_FORCEDISABLE_Msk);
  }
}


void radio_SeqAtomicLock(void)

{
  uint32_t dummy;
	
	dummy = RAC->SR0 & 0xff;
  while (RAC->SR0 & 0x01)
  {
		BUS_RegMaskedClear(&RAC->SR0, 2);
    PROTIMER_DelayUs(2);
  }
  BUS_RegMaskedSet(&RAC->SR0, 2);
}

void radio_SeqAtomicUnlock(void)

{
	BUS_RegMaskedClear(&RAC->SR0, 2);
}

void RAC_RSM_IRQHandler(void)
{
	RAC_SEQ_IRQHandler();
}

void RAC_SEQ_IRQHandler(void)
{
	uint32_t flags;
	flags = RAC->IF & RAC->IEN;
	RAC->IFC = flags;	
    //if (rac_flags & RAC_IF_PAVHIGH_Msk) phy_events |= 0x20;
    //if (rac_flags & RAC_IF_PAVLOW_Msk) phy_events |= 0x40;
    //if (rac_flags & RAC_IF_PABATHIGH_Msk) phy_events |= 0x80;
    //if (rac_flags & 0x40000) uVar5 = 2;
    //if (rac_flags & 0x10000) rail_events |= 0x400;
    //if (rac_flags & 0x100000) rail_events |= 0x2000;
    //if (rac_flags & 0x200000) rail_events |= 2;
    //if (rac_flags & 0x80000) && (GENERIC_PHY_CanModifyAck() != false)) rail_events |= 0x10000;
  if (flags & RAC_IF_PAVHIGH_Msk) PA_PeakDetectorHighRun();
  if (flags & RAC_IF_PAVLOW_Msk) PA_PeakDetectorLowRun();
  if (flags & RAC_IF_PABATHIGH_Msk) PA_BatHighRun();	
}
