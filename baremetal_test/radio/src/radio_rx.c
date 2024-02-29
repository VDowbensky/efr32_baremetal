#include <string.h>
#include "radio_rx.h"

void radio_configberrx(void);
void radio_resetberstats(uint32_t bits);
static uint8_t countBits(uint8_t b);

bool berRx = false;
bool iqRx = false;

uint32_t berTotalBytesLeft;
uint32_t berTotalErrors;
uint32_t berTotalBits;

BerStatus_t berStats;

void radio_startrx(void)
{
	BUFC_RxBufferReset();	
	do 
		{ 
      if (radio_HeadedToIdle() == 0) break;
    } while (RAC->STATUS & RAC_STATUS_STATE_Msk);
    INT_Disable();
		SEQ_CONTROL_REG &= ~0x20; 
		INT_Enable();
		RAC->IFPGACTRL = 0x000087F6;
		//RAC->CMD = RAC_CMD_DEMODENSET_Msk;
  	BUS_RegMaskedSet(&RAC->RXENSRCEN, 2);
}

void radio_startberrx(uint32_t bits)
{
  //radio_stopberrx();
	//goto idle mode here
	radio_Enable(0);
	radio_resetberstats(bits);
	radio_saveconfig();
  radio_configberrx();
//	while (RAC->STATUS & RAC_STATUS_STATE_Msk) {};
  BUFC_RxBufferReset();
	//BUFC->BUF1_THRESHOLDCTRL |= BUFC_BUF1_THRESHOLDCTRL_THRESHOLDMODE_Msk; //!!!
	memset((void *)RADIO_rxBuffer,0xff,0x3f);
	BUFC_RXBufferEnableThrInt();
	NVIC_EnableIRQ(BUFC_IRQn);
	//RAC->IFPGACTRL = 0x000087F6;
	BUS_RegMaskedSet(&RAC->RXENSRCEN, 0x02);
}

void radio_configberrx(void)

{
  FRC->DFLCTRL = _FRC_DFLCTRL_DFLMODE_INFINITE; //5;
  MODEM->SYNC0 = 0x1dd3d4a0;
  //radio_setupPN9();
	FRC->WHITECTRL = 0x24;
  FRC->WHITEPOLY = 0x100;
  FRC->WHITEINIT = 0x138;
	//BUS_RegMaskedClear(&MODEM->TIMING, ~MODEM_TIMING_TIMINGBASES_Msk); 
	MODEM->TIMING = 0x022c003f;
	BUS_RegMaskedSet(&MODEM->CTRL1, MODEM_CTRL1_SYNCBITS_Msk);
	BUS_RegMaskedClear(&MODEM->AFC, MODEM_AFC_AFCRXMODE_Msk);
  //if ((MODEM->CTRL1 & MODEM_CTRL1_COMPMODE_Msk) == 0) BUS_RegMaskedSet(&MODEM->CTRL1, MODEM_CTRL1_COMPMODE_Msk); 
	MODEM->CTRL1 = 0x1001f;	
  FRC->TRAILRXDATA = 0; //0x1b
	BUS_RegMaskedSet(&FRC->RXCTRL, FRC_RXCTRL_BUFCLEAR_Msk | FRC_RXCTRL_ACCEPTCRCERRORS_Msk);
	FRC->RXCTRL |= 0x12;
	//FRC->RXCTRL = 0x60;
  //FRC->RXCTRL = 0;
	FRC->CTRL = 0x704;
	//FRC->CTRL = 0x4;
	//FRC->IEN = FRC_IEN_RXDONE_Msk | FRC_IEN_FRAMEERROR_Msk;
	FRC->IEN = 0;
	BUFC->IEN = BUFC_IEN_BUF1THR_Msk;
}


void radio_resetberstats(uint32_t bits)

{
  if (0x1ffffffe < bits - 1U)
  {
	  bits = 0x1fffffff;
  }
  berStats.bitsTotal = bits; // << 3;
  berStats.bitsTested = 0;
  berStats.bitErrors = 0;
  berStats.rssi = 0;

  berTotalBytesLeft = bits >> 3;
  berTotalErrors = 0;
  berTotalBits = 0;
}
/*
typedef struct RAIL_BerStatus
{
  uint32_t bitsTotal;
  uint32_t bitsTested;
  uint32_t bitErrors;
  int8_t   rssi;
} RAIL_BerStatus_t;
*/
void radio_reportberstats(BerStatus_t *berstatus)

{
  berstatus->bitsTotal = berStats.bitsTotal;
  berstatus->bitsTested = berStats.bitsTested;
  berstatus->bitErrors = berStats.bitErrors;
  berstatus->rssi =	berStats.rssi;
}

void radio_emptybufandupdatestats(void)

{
  uint16_t numBytes;
  uint32_t currentbyte;

	for(numBytes = BUFC_RxBufferBytesAvailable(); numBytes > 0; numBytes --)
  {
    currentbyte = BUFC->BUF1_READDATA & 0xff;
      if (berTotalBytesLeft != 0) 
			{
        berTotalBytesLeft --;
        berTotalErrors += countBits(currentbyte); //((uint32_t)(uint8_t)nibblebits[currentbyte & 0xf] + (uint32_t)(uint8_t)nibblebits[(currentbyte << 0x14) >> 0x18] & 0xff);
        berTotalBits += 8;
        berStats.rssi = (int8_t)(AGC_GetRSSI()/4);
      }
		if (berStats.bitsTotal < berTotalBits) berStats.bitsTested = 0xffffffff;
		else berStats.bitsTested = berTotalBits;
    if (berTotalErrors < berStats.bitErrors) berStats.bitErrors = 0xffffffff;
    else berStats.bitErrors = berTotalErrors;
	}
	if(berStats.bitsTested >= berStats.bitsTotal) 
	{
		RxEvents |= RXEVENT_BERDONE;
	}
}

static uint8_t countBits(uint8_t b)
{
  uint8_t count = 0;
  static const uint8_t nibblebits[] = { 0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4 };
  count += nibblebits[b & 0x0F];
  count += nibblebits[b >> 4];
  return count;
}

void radio_stopberrx(void)
{
	//RFTEST_BerStop();
  FRC->RXCTRL &= ~FRC_RXCTRL_BUFRESTORERXABORTED_Msk; //0xffffffbf;
  //RFTEST_StopRx();
  RAC->RXENSRCEN &= 0xffffff00;
  FRC->CMD = FRC_CMD_RXABORT_Msk; //1;
  if ((RAC->STATUS & RAC_STATUS_STATE_Msk) >> RAC_STATUS_STATE_Pos == _RAC_STATUS_STATE_RXOVERFLOW) //6) 
	{
    RAC->CMD |= RAC_CMD_CLEARRXOVERFLOW_Msk; //0x40;
    BUFC_RxBufferReset();
  }
  while ((RAC->STATUS & RAC_STATUS_STATE_Msk) != 0);
	BUFC_RXBufferDisableThrInt();
	radio_restoreconfig();
	//goto idle mode here
	radio_Enable(0);
	//init_radio(); //
	BUS_RegMaskedSet(&RAC->RXENSRCEN, 0x02);
}

void radio_startiqrx(void)
{
//save configuration
	rfparamsfbuffer[0] = FRC->RXCTRL;
	rfparamsfbuffer[1] = FRC->BUFFERMODE;
	rfparamsfbuffer[2] = FRC->RAWCTRL;
	rfparamsfbuffer[3] = BUFC->BUF1_THRESHOLDCTRL;
	rfparamsfbuffer[4] = MODEM->CTRL0;
	rfparamsfbuffer[5] = RAC->SR3;
	rfparamsfbuffer[6] = FRC->IEN;
//reconfigure for IQ receiving	
	FRC->RXCTRL = 0;
	FRC->BUFFERMODE = 4;
	FRC->RAWCTRL = 4;
	BUFC->BUF1_THRESHOLDCTRL = 0x0fff;
	MODEM->CTRL0 |= MODEM_CTRL0_DETDIS_Msk | (1 << MODEM_CTRL0_DEMODRAWDATASEL_Pos); //???
	RAC->SR3 |= 0x10000000; //???
//enable FRC RX raw event interrupt only
	FRC->IEN = FRC_IEN_RXRAWEVENT_Msk;
	iqRx = true;
}

void radio_stopiqrx(void)
{
//disable FRC RX raw event interrupt
	FRC->IEN = rfparamsfbuffer[6];
//restore configuration
	FRC->RXCTRL = rfparamsfbuffer[0];
	FRC->BUFFERMODE = rfparamsfbuffer[1];
	FRC->RAWCTRL = rfparamsfbuffer[2];
	BUFC->BUF1_THRESHOLDCTRL = rfparamsfbuffer[3];
	MODEM->CTRL0 = rfparamsfbuffer[4];
	RAC->SR3 = rfparamsfbuffer[5];
//reconfigure for normal receiving
//restart RX
	radio_Enable(0);
	iqRx = false;
	BUS_RegMaskedSet(&RAC->RXENSRCEN, 0x02);	
}