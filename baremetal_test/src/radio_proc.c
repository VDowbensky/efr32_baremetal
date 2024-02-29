#include "radio_proc.h"
#include "radio_rx.h"
#include "radio_tx.h"
#include "leds.h"
#include <stdint.h>
#include <string.h>

volatile uint32_t RxEvents = 0;
volatile uint32_t TxEvents = 0;
volatile uint32_t HardEvents = 0;
volatile uint32_t txpacketnumber = 0;

uint8_t minchan;
uint8_t maxchan;

#if CTUNE_CORR_ON_THE_FLY
bool ctunecomp = true;
#else
bool ctunecomp = false;
#endif

uint32_t slaveID;
uint32_t masterID;

uint16_t rbytes;
int16_t Rssi;
uint32_t rpacknumber;
bool noanswer = false;

bool rxc = false;
uint32_t rxpacketcount = 0;
int32_t RssiAccum = 0;

uint8_t txmode = 0;
volatile uint32_t txpacketcount = 1;
uint32_t inter_packet_delay = 50;
bool master = false;
bool txpacket = false;
uint32_t iqwritepointer = 0;

uint8_t rx_fifo[RADIO_BUFFER_SIZE];
uint8_t tx_fifo[RADIO_BUFFER_SIZE] = TX_PACKET_TEMPLATE; //{0, 0, 0, 0, -120, 0, 'T', 0, 0, 0, 0, 0, 0, 0, 0,'B', 'a', 'r', 'e', ' ','M','e','t','a','l',' ',' '};//max length of string - 16 bytes
volatile uint32_t iqbuffer[IQ_BUFFER_SIZE];

volatile bool sweepfreq = false;
uint32_t sweepdelay;
volatile bool sweeprx = false;
uint32_t rxsweepdelay;

//Radio events handler
void process_radio(void)
{
	processHardEvents();
	processRxEvents();
	processTxEvents();
	if(txpacket) 
	{
		prepareTxPacket();
		radio_sendpacket();
		PROTIMER_SetInterval(inter_packet_delay);
	}
	if(iqRx) processiqdata();
	//if(sweepfreq) sweep_freq();
}

void radio_startburst(void)
{
  master = true;
	txpacketnumber = 1;
	txpacket = true;
	noanswer = true;
}

void prepareTxPacket(void)
{
  uint64_t mcuid;
	
	*(uint32_t*)&tx_fifo[0] = txpacketnumber; 
  tx_fifo[4] = (int8_t)Temp;
  tx_fifo[6] = 'T';
	mcuid = masterID | ((uint64_t)slaveID) << 32;
	*(uint64_t*)&tx_fifo[7] = mcuid;
	noanswer = true;
}

void prepareAnswerPacket(void)
{
  uint64_t mcuid;

	*(uint32_t*)&tx_fifo[0] = rpacknumber; 
  tx_fifo[4] = Rssi; 
  tx_fifo[6] = 'R';
	mcuid = masterID | ((uint64_t)slaveID) << 32;
	*(uint64_t*)&tx_fifo[7] = mcuid;
}

void processHardEvents(void)
{
	static int8_t chan = 0;
	static uint8_t phase = 0;
	
	if(HardEvents & HARDEVENT_WRAPCNTOF)
	{
		HardEvents &= ~HARDEVENT_WRAPCNTOF;
		if(master)
		{
			txpacketnumber ++;
			if(txpacketnumber <= txpacketcount) 
			{	
				if(noanswer && (txpacketnumber > 1))
				{
					noanswer = false;
					if(master && (RadioConfig.printmode)) printf("NACK: %d,%d,%d\r\n", txpacketnumber, -128, -128);
				}
				txpacket = true;
			}
			else
			{
				txpacket = false;
				master = false;
				noanswer = false;
				txpacketnumber = 0;
				printf("SEND_PACKET: %d\r\n", txpacketcount);
			}
		}
		if(sweepfreq)
		{
			chan = SYNTH->CHCTRL;
			//if(sweeprx) printf("CH=%d,RSSI=%.1f dBm\r\n",chan,(float)AGC_GetRSSI() / 4);
			if(phase == 0)
			{
				chan++;
				if(chan > 63) 
				{
					chan = 63;
					phase = 1;
				}
			}
			else
			{
				chan--;
				if(chan < 0)
				{
					chan = 0;
					phase = 0;
				}
			}
			SYNTH->CHCTRL = chan;
			PROTIMER_SetInterval(sweepdelay);
		}
		if(sweeprx)
		{
			chan = SYNTH->CHCTRL;
			printf("CH=%d,RSSI=%.1f dBm\r\n",chan,(float)AGC_GetRSSI() / 4);
			chan++;
			if(chan > maxchan) chan = minchan;
			SYNTH->CHCTRL = chan;
			PROTIMER_SetInterval(sweepdelay);
		}
	}
}
void processRxEvents(void)
{
	if(RxEvents & RXEVENT_DONE)
	{
  	uint16_t i;
		RxEvents &= ~RXEVENT_DONE;
		
		noanswer = false;
		rbytes = BUFC_RxBufferBytesAvailable();
		INT_Disable();
		//for(i = 0; i < rbytes; i++) rx_fifo[i] = RADIO_rxBuffer[i];
		for(i = 0; i < rbytes; i++) rx_fifo[i] = BUFC->BUF1_READDATA & 0xff;
		BUFC_RxBufferReset();
		INT_Enable();
		Rssi = (int16_t)AGC->FRAMERSSI/256;
		rpacknumber = *(uint32_t*)&rx_fifo;
		if(rxc)
		{
			rxpacketcount ++;
			RssiAccum += Rssi;
		}
		if(RadioConfig.printmode) printRxPacket();
		if(!master) //answer
		{
			uint32_t id;
			id = *(uint32_t*)&rx_fifo[11];
			if ((RadioConfig.answermode != 0) || (id == masterID))
			{
				slaveID = *(uint32_t*)&rx_fifo[7];
				prepareAnswerPacket();
				radio_sendpacket();
				return;
			}
		}
		//RADIO_CtuneCorrection();
		radio_startrx();
		return;
	}

	if(RxEvents & (RXEVENT_FRAMEERROR | RXEVENT_BLOCKERROR | RXEVENT_RXOVERFLOW))
	{
		RxEvents &= ~(RXEVENT_DONE | RXEVENT_FRAMEERROR | RXEVENT_BLOCKERROR | RXEVENT_RXOVERFLOW);
		FRC_ErrorHandle();
		printf("RPCK: FERR\r\n");
		//RADIO_CtuneCorrection();
		radio_startrx();
	}
	
	if(RxEvents & RXEVENT_BERDONE)
	{
		BerStatus_t berstatus;
		float ber_percent;
		
		RxEvents &= ~RXEVENT_BERDONE;
		radio_stopberrx();
		berRx = false;
		radio_reportberstats(&berstatus);
		//if(berstatus.bitsTested != 0) ber_percent = ((float)berstatus.bitErrors/(berstatus.bitsTested))*100;
		//else ber_percent = 100.0;
		//printf("GET_BER: %.3f%%, RSSI: %d dBm\r\n", ber_percent, berstatus.rssi);
		//if(printmode) printf("Total: %d, Tested: %d, Errors: %d\r\n", berstatus.bitsTotal, berstatus.bitsTested, berstatus.bitErrors);	
	}
	
	if(RxEvents & RXEVENT_RAWEVENT)
	{
		RxEvents &= ~RXEVENT_RAWEVENT;
		if(iqRx == true)
		{
			//probably it's maybe atomic operation
			iqbuffer[iqwritepointer] = FRC->RXRAWDATA;
			iqwritepointer++;
			if(iqwritepointer >= IQ_BUFFER_SIZE) iqwritepointer = 0;
		}
	}
}

void processTxEvents(void)
{
	if(TxEvents & TXEVENT_DONE)
	{
		TxEvents &= ~TXEVENT_DONE;
		txpacket = false;
#if LED0
		led0_off();
#endif
		//RADIO_CtuneCorrection();
		radio_startrx();
	}
}

void printRxPacket(void)
{
  uint8_t i = 0;
  uint32_t id0;
	uint32_t id1;
	rbytes -= 6;
	id0 = *(uint32_t*)&rx_fifo[11];
	id1 = *(uint32_t*)&rx_fifo[7];
  printf("RPCK: %d,%d,%d,%c,", rpacknumber, Rssi, (signed char)rx_fifo[4],rx_fifo[6]);
  for (i = 15; i < rbytes; i++) 
  {
		if (rx_fifo[i] != 0) printf("%c", rx_fifo[i]);
	}
  printf("0x%08X,0x%08X\r\n", id0, id1);
}

void radio_delayms(uint32_t ms)
{
	PROTIMER_DelayUs(ms * 1000);
}

void processiqdata(void)
{
	//process iqbuffer
}

void RADIO_CtuneCorrection(void)
{
  uint16_t tune;
	float deltaCtune;
	float deltaT;
	
	deltaT = Temp - DEFAULT_CAL_TEMP;
	//deltaCtune = 0.00040135 * deltaT * deltaT * deltaT - 0.002056 * deltaT * deltaT - 1.12905 * deltaT + 2.7474;
	deltaCtune = K_CTUNE3 * deltaT * deltaT * deltaT + K_CTUNE2 * deltaT * deltaT + K_CTUNE1 * deltaT + K_CTUNE0;
  tune = *(uint16_t *)(DEVID_ADDR + 0x100) + (int16_t) deltaCtune;
	if(tune > 511) tune = 511;
	radio_Enable(0);
	radio_SetCtune(tune);
	restoretxmode();
}

//	if() 		RadioConfig.K_Ctune_Khz = (int32_t)(K_CTUNE_KHZ * 1000000);
//		RadioConfig.K_Ctune3_Khz = (int32_t)(K_CTUNE3_KHZ * 1000000);
//		RadioConfig.K_Ctune2_Khz = (int32_t)(K_CTUNE2_KHZ * 1000000); 
//		RadioConfig.K_Ctune1_Khz = (int32_t)(K_CTUNE1_KHZ * 1000000);
//		RadioConfig.K_Ctune0_Khz = (int32_t)(K_CTUNE0_KHZ * 1000000);

void restoretxmode(void)
{
	if(txmode == 1) radio_startCW();
	else if(txmode == 2) radio_startPN9();
	else if(txmode == 3) radio_start01();
	else radio_startrx();
}


uint8_t radio_GetRadioState(void)
{
	return (RAC->STATUS & RAC_STATUS_STATE_Msk) >> RAC_STATUS_STATE_Pos;
}





