#include "radio_proc.h"
#include <stdint.h>
#include <string.h>

volatile uint8_t RADIO_rxBuffer[RADIO_BUFFER_SIZE];
volatile uint8_t RADIO_txBuffer[RADIO_BUFFER_SIZE];
volatile uint8_t RADIO_rxLengthBuffer[RADIO_BUFFER_SIZE];

uint8_t txpactune;
uint8_t rxpactune;


RAIL_TxData_t transmitPayload = {&tx_fifo[0], 32};


bool RADIO_SendPacket(void)
{
	BUFC_TxBufferReset();
	BUFC_WriteContSync(tx_fifo ,32);
	//RAIL_RfHalTxStart(Channel, NULL,NULL);	
	  do 
		{
      if (RFHAL_HeadedToIdle() == 0) break;
    } while ((RAC->STATUS & 0xf000000) != 0);
    if ((RAC->STATUS & 0xf000000) != 0) return 2;
      INT_Disable();
  if ((PROTIMER_CCTimerIsEnabled(3) == 0) && (PROTIMER_LBTIsActive() == 0)) 
	{
  if ((FRC->DFLCTRL & FRC_DFLCTRL_DFLMODE_Msk) == 0) FRC->WCNTCMP0 = BUFC_TxBufferBytesAvailable() - 1; 
  SEQ_CONTROL_REG &= ~0x20; //0xffffffdf;
		BUS_RegMaskedSet(&RAC->IFPGACTRL, RAC_IFPGACTRL_BANDSEL_Msk);
		RAC->CMD = RAC_CMD_TXEN_Msk;
    INT_Enable();
    return true;
  }
  INT_Enable();
  return false;
}

void RADIO_SetCtune(uint32_t tune)

{
  CMU_ClockSelectSet(0x11,5);
  CMU_OscillatorEnable(2,0,0);
	BUS_RegMaskedClear(&CMU->HFXOSTEADYSTATECTRL, _CMU_HFXOSTEADYSTATECTRL_CTUNE_MASK);
	CMU->HFXOSTEADYSTATECTRL |= (tune & 0x1ff) << _CMU_HFXOSTEADYSTATECTRL_CTUNE_SHIFT;
  CMU_OscillatorEnable(2,1,1);
  CMU_ClockSelectSet(0x11,4);
}


uint32_t RADIO_GetCtune(void)

{
	return (CMU->HFXOSTEADYSTATECTRL & _CMU_HFXOSTEADYSTATECTRL_CTUNE_MASK) >> _CMU_HFXOSTEADYSTATECTRL_CTUNE_SHIFT;
}

RAIL_Status_t RAIL_RfHalSetTxTransitions(RAIL_RadioState_t success,RAIL_RadioState_t error)

{
  RADIO_TRANSITIONS = 1 << (success + 0x10U & 0xff) | (uint32_t)RADIO_TRANSITIONS | 1 << (error + 0x18U & 0xff);
  return RAIL_STATUS_NO_ERROR;
}


RAIL_Status_t RAIL_RfHalSetRxTransitions(RAIL_RadioState_t success,RAIL_RadioState_t error)

{
	RADIO_TRANSITIONS = 1 << (error + 8U & 0xff) | 1 << (success & 0xff) | RADIO_TRANSITIONS & 0xffff0000;
  return RAIL_STATUS_NO_ERROR;
}

uint32_t RFHAL_HeadedToIdle(void)

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

void GENERIC_PHY_RadioEnable(uint32_t enable)

{
  if (enable == 0)
  {
    GENERIC_PHY_SeqAtomicLock();
    SEQ_CONTROL_REG = SEQ_CONTROL_REG | 0x20;
		BUS_RegMaskedClear(&RAC->RXENSRCEN, RAC_RXENSRCEN_SWRXEN_Msk);
		FRC->CMD = FRC_CMD_RXABORT_Msk; 
		//RAC->CTRL |= RAC_CTRL_PRSCLR_Msk;
		BUS_RegMaskedSet(&RAC->CMD, RAC_CMD_TXDIS_Msk);
    //_DAT_43081104 = enable; //RAC->SR0 bit 2
		//if(enable == 1) BUS_RegMaskedSet(&RAC->SR0,4);
		//else BUS_RegMaskedClear(&RAC->SR0,4);
		BUS_RegMaskedClear(&RAC->SR0,4);
  }
  else
  {
    if (RAC->CTRL & RAC_CTRL_FORCEDISABLE_Msk) BUS_RegMaskedClear(&RAC->CTRL, RAC_CTRL_FORCEDISABLE_Msk);
  }
}


void GENERIC_PHY_SeqAtomicLock(void)

{
  uint32_t dummy;
	
	dummy = RAC->SR0 & 0xff;
  while (RAC->SR0 & 0x01)
  {
    //_DAT_43081104 = 0; //4088 bit 1
		BUS_RegMaskedClear(&RAC->SR0, 2);
    PROTIMER_DelayUs(2);
  }
  //_DAT_43081104 = 1;
  BUS_RegMaskedSet(&RAC->SR0, 2);
}

void RAC_RSM_IRQHandler(void)
{
	uint32_t flags;
	flags = RAC->IF & RAC->IEN;
	RAC->IFC = flags;		
}

void RAC_SEQ_IRQHandler(void)
{
	uint32_t flags;
	flags = RAC->IF & RAC->IEN;
	RAC->IFC = flags;		
}