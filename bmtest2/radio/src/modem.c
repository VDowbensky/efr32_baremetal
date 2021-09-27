#include "modem.h"

void init_modem(void)
{
  MODEM->DCCOMP |= MODEM_DCCOMP_DCCOMPEN_Msk | MODEM_DCCOMP_DCESTIEN_Msk; //3; 
  RAC->SR3 = 0;
  //RADIO_DccalEnable();
	MODEM->MIXCTRL = MODEM_MIXCTRL_DIGIQSWAPEN_Msk;
  MODEM->CTRL0 = 0x04000000; //26 shaping
  MODEM->CTRL1 = 0x0001400F; //16,14,3,2,1,0 resync, compmode, syncbits (0f -> 16)
  MODEM->CTRL2 = 0x00002000; //13 DATAFILTER
  MODEM->CTRL3 = 0x00000000;
  MODEM->CTRL4 = 0x03000000; //24,25 ADCSATLEVEL
  MODEM->CTRL5 = 0x00000000;
	//bitrate
	MODEM->TXBR = 0x00FF5FA0;
  MODEM->RXBR = 0x00000820;
	//deviation
	MODEM->MODINDEX = 0x00230390;
	//baudrate tolerance
	//shaping filter
	//bt/r
  MODEM->SHAPING0 = 0x22140A04;
  MODEM->SHAPING1 = 0x504B4133;
  MODEM->SHAPING2	= 0x00000000;
	//FSK symbol mapping
	//direct mode
	//AFC
	MODEM->AFC = 0x00000000;
	MODEM->AFCADJLIM = 0x00000000;
	//symbol coding
	//encoding
	//dsss chipping code length
	//dsss SF
	//dsss chipping code base
	//diff.encoding
	//manchester mapping
	MODEM->DSSS0 = 0x00000000;
	//timings
  MODEM->TIMING	= 0x0220081F;
	//preamble base pattern
	//length
	//pattern length
	//syncword length
	//sync word tx skip
	MODEM->CF = 0x020200F8; 
  MODEM->PRE = 0x00140012;
	//syncword 0
	MODEM->SYNC0 = 0x00002BB4;
	//syncword 1
	MODEM->SYNC1 = 0x00000000;	
}