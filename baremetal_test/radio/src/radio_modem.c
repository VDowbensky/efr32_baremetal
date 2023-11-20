#include "radio_modem.h"

void MODEM_IRQHandler(void)

{
	uint32_t flags;
	flags = MODEM->IF & MODEM->IEN;
	MODEM->IFC = flags;

	if(flags & MODEM_IF_TXFRAMESENT_Msk)
	{
		TxEvents |= TXEVENT_FRAMESENT;
	}
	
	if(flags & MODEM_IF_TXSYNCSENT_Msk)
	{
		TxEvents |= TXEVENT_SYNCSENT;
	}
	
	if(flags & MODEM_IF_TXPRESENT_Msk)
	{
		TxEvents |= TXEVENT_PRESENT;
	}
	
	if(flags & MODEM_IF_RXTIMDET_Msk)
	{
		RxEvents |= RXEVENT_TIMDET;
	}
	
	if(flags & MODEM_IF_RXPREDET_Msk)
	{
		RxEvents |= RXEVENT_PREDET;
	}
	
	if(flags & MODEM_IF_RXFRAMEDET0_Msk)
	{
		RxEvents |= RXEVENT_RXFRAMEDET0;
	}
	
	if(flags & MODEM_IF_RXFRAMEDET1_Msk)
	{
		RxEvents |= RXEVENT_RXFRAMEDET1;
	}
	
	if(flags & MODEM_IF_RXTIMLOST_Msk)
	{
		RxEvents |= RXEVENT_TIMLOST;
	}
	
	if(flags & MODEM_IF_RXPRELOST_Msk)
	{
		RxEvents |= RXEVENT_PRELOST;
	}
	
	if(flags & MODEM_IF_RXFRAMEDETOF_Msk)
	{
		RxEvents |= RXEVENT_RXFRAMEDETOF;
	}
	
	if(flags & MODEM_IF_RXTIMNF_Msk)
	{
		RxEvents |= RXEVENT_RXTIMNF;
	}
}

void MODEM_init(void)
{
	//MODEM
	//modulation type
	//MODEM->MIXCTRL = 0x00000010; //bit 4 - MODEM_MIXCTRL_DIGIQSWAPEN_Msk
	MODEM->DCCOMP |= MODEM_DCCOMP_DCCOMPEN_Msk | MODEM_DCCOMP_DCESTIEN_Msk; //3; 
	MODEM_DccalEnable();
	
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
	MODEM->CF = 0x020200F8; //!!! 
  MODEM->PRE = 0x00140012;
	//syncword 0
	MODEM->SYNC0 = SYNCWORD0; //0x00002BB4;
	//syncword 1
	MODEM->SYNC1 = 0x00000000;
}

void MODEM_ConfigFixup(void)

{
  SEQ->SYNTHLPFCTRLTX = RAC->LPFCTRL;
  SEQ->SYNTHLPFCTRLRX = RAC->LPFCTRL & 0xfffffff0;
}

void MODEM_DemodResetOnRxsearchEntryEnable(void)

{
  RAC->SR3 |= 0x100;
}



void MODEM_DemodResetOnRxsearchEntryDisable(void)

{
  RAC->SR3 &= 0xfffffeff;
}



void MODEM_DccalEnable(void)

{
  RAC->SR3 |= 1;
}




void MODEM_DccalDisable(void)

{
	RAC->SR3 &= 0xfffffffe;
}


uint32_t MODEM_ComputeTxBaudrate(void)

{
  return ((MODEM->TXBR & 0xFF) * (CMU_ClockFreqGet(0x11) >> 3)) / (MODEM->TXBR & 0xffff);
}



uint32_t MODEM_ComputeTxSymbolRate(void)

{
  uint32_t tsr;
  tsr = MODEM_ComputeTxBaudrate();
  if ((MODEM->CTRL0 & MODEM_CTRL0_CODING_Msk) == 0x20) tsr /= (((MODEM->CTRL0 & MODEM_CTRL0_DSSSLEN_Msk) >> MODEM_CTRL0_DSSSLEN_Pos) + 1); //DSSS coding
  return tsr;
}



uint32_t MODEM_ComputeTxBitRate(void)

{
  uint32_t uVar3;
  if ((MODEM->CTRL0 & MODEM_CTRL0_CODING_Msk) == 0x20) //4,5 = bit 4 set - CODING
  {
    uVar3 = ((MODEM->CTRL0 << 0x10) >> 0x1b) / ((MODEM->CTRL0 << 0xd) >> 0x1d);
		//uVar3 = (MODEM->CTRL0 & MODEM_CTRL0_DSSSLEN_Msk) >> MODEM_CTRL0_DSSSLEN_Pos) / 
    //uVar3 = (MODEM->CTRL0 & 0x1F) / (MODEM->CTRL0 & 0x7); //not correct
    if (MODEM->CTRL0 & MODEM_CTRL0_DSSSDOUBLE_Msk) uVar3 = uVar3 << 1; //19, 20 - DSSSDOUBLE
    uVar3 = uVar3 >> 1;
    if (2 < uVar3) uVar3 = 4;
  }
  else
  {
    if (((MODEM->CTRL0 & MODEM_CTRL0_MODFORMAT_Msk) == 0x40) || ((MODEM->CTRL0 & MODEM_CTRL0_MODFORMAT_Msk) == 0x100)) uVar3 = 2;// bit 6 or bit  8 MODFORMAT
    else uVar3 = 1;
  }
  return uVar3 * MODEM_ComputeTxSymbolRate();
}
