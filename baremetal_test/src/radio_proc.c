#include "radio_proc.h"
#include "radio_rx.h"
#include "radio_tx.h"
#include <stdint.h>
#include <string.h>

volatile uint8_t RADIO_rxBuffer[RADIO_BUFFER_SIZE];
volatile uint8_t RADIO_txBuffer[RADIO_BUFFER_SIZE];
volatile uint8_t RADIO_rxLengthBuffer[RADIO_BUFFER_SIZE];

volatile uint32_t RxEvents = 0;
volatile uint32_t TxEvents = 0;
volatile uint32_t HardEvents = 0;
uint32_t packetnumber = 0;
uint16_t rbytes;

uint8_t rx_fifo[RADIO_BUFFER_SIZE];
uint8_t tx_fifo[RADIO_BUFFER_SIZE] = {0, 0, 0, 0, -120, 0, 'T', 0, 0, 0, 0, 0, 0, 0, 0,'B', 'a', 'r', 'e', ' ','M','e','t','a','l',' ',' '};//max length of string - 16 bytes
//RAIL_TxData_t transmitPayload = {&tx_fifo[0], 32};

//Radio events handler
void process_radio(void)
{
	processHardEvents();
	processRxEvents();
	processTxEvents();
}

void prepareTxPacket(void)
{
  uint64_t mcuid;

	*(uint32_t*)&tx_fifo[0] = packetnumber; 
  tx_fifo[4] = (int8_t)Temp;
  tx_fifo[6] = 'T';
  //4 last bytes - ID
	*(uint64_t*)&tx_fifo[7] = SYSTEM_GetUnique();
  //ctune_correction();	
}

void prepareAnswerPacket(void)
{
  uint64_t mcuid;

	*(uint32_t*)&tx_fifo[0] = packetnumber; 
  tx_fifo[4] = (int8_t)Temp; //will be changed to previous RSSI
  tx_fifo[6] = 'R';
  //4 last bytes - ID
	*(uint64_t*)&tx_fifo[7] = SYSTEM_GetUnique();
  //ctune_correction();	
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
		for(i = 0; i < rbytes; i++) rx_fifo[i] = RADIO_rxBuffer[i];
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
  //rpacknumber = (*((int32_t*) rx_fifo));
	rpacknumber = *(uint32_t*)&rx_fifo;
	mcuid = *(uint64_t*)&rx_fifo[7];
  printf("RPCK: %d,%d,%d,%c,", rpacknumber, Rssi, (signed char)rx_fifo[4], rx_fifo[6]);
  for (i = 15; i < rbytes; i++) 
  {
		if (rx_fifo[i] != 0) printf("%c", rx_fifo[i]);
	}
  printf("%llu", mcuid);
  printf("\r\n");

}


