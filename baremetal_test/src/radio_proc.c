#include "radio_proc.h"
#include "radio_rx.h"
#include "radio_tx.h"
#include <stdint.h>
#include <string.h>

volatile uint8_t RADIO_rxBuffer[RADIO_BUFFER_SIZE];
volatile uint8_t RADIO_txBuffer[RADIO_BUFFER_SIZE];
volatile uint8_t RADIO_rxLengthBuffer[RADIO_BUFFER_SIZE];

uint8_t RxDatabuffer[RADIO_BUFFER_SIZE];

volatile uint32_t RxEvents = 0;
volatile uint32_t TxEvents = 0;
volatile uint32_t HardEvents = 0;

uint16_t rbytes;

uint8_t txpactune;
uint8_t rxpactune;

RAIL_TxData_t transmitPayload = {&tx_fifo[0], 32};

//Radio events handler
void process_radio(void)
{
	processHardEvents();
	processRxEvents();
	processTxEvents();
}

void processHardEvents(void)
{
	
}
void processRxEvents(void)
{
	if(RxEvents & RXEVENT_DONE)
	{
  	uint16_t i;
		RxEvents &= ~RXEVENT_DONE;
		rbytes = BUFC_RxBufferBytesAvailable();
		INT_Disable();
		for(i = 0; i < rbytes; i++) RxDatabuffer[i] = RADIO_rxBuffer[i];
		//for(i = 0; i < rbytes; i++) RxDatabuffer[i] = BUFC->BUF1_READDATA & 0xff;
		BUFC_RxBufferReset();
		INT_Enable();
		printRxPacket();
		radio_startrx();
		return;
	}
	if(RxEvents & (RXEVENT_FRAMEERROR | RXEVENT_BLOCKERROR | RXEVENT_RXOVERFLOW))
	{
		RxEvents &= ~(RXEVENT_DONE | RXEVENT_FRAMEERROR | RXEVENT_BLOCKERROR | RXEVENT_RXOVERFLOW);
		FRC_ErrorHandle();
		printf("RPCK: FERR\r\n");
		radio_startrx();
	}
}

void processTxEvents(void)
{
	if(TxEvents & TXEVENT_DONE)
	{
		TxEvents &= ~TXEVENT_DONE;
		radio_startrx();
	}
}




void printRxPacket(void)
{
  uint8_t i = 0;
  uint64_t mcuid;
	uint32_t rpacknumber;
	int16_t Rssi;
	Rssi = (int16_t)AGC->FRAMERSSI/256;
	rbytes -= 6;
  rpacknumber = (*((int32_t*) RxDatabuffer));
      rpacknumber = (*((int32_t*) RxDatabuffer));
      //mcuid = (*((uint64_t*) rx_buffer[7]));
      mcuid = ((uint64_t)RxDatabuffer[7]) + (((uint64_t)RxDatabuffer[8])<<8) + (((uint64_t)RxDatabuffer[9])<<16) + (((uint64_t)RxDatabuffer[10])<<24) + (((uint64_t)RxDatabuffer[11])<<32) + \
          (((uint64_t)RxDatabuffer[12])<<40) + (((uint64_t)RxDatabuffer[13])<<48) + (((uint64_t)RxDatabuffer[14])<<56);
      printf("RPCK: %d,%d,%d,%c,", rpacknumber, Rssi, (signed char)RxDatabuffer[4], RxDatabuffer[6]);
      for (i = 15; i < rbytes; i++) 
			{
				if (RxDatabuffer[i] != 0) printf("%c", RxDatabuffer[i]);
			}
      printf("%llu", mcuid);
      printf("\r\n");

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