#ifndef _MODEM_MODEM_H_
#define _MODEM_MODEM_H_

#include "radio_proc.h"

typedef struct
{
	//FREQOFFEST
	uint32_t freqoffset:		8;
	uint32_t poe:						8;
	uint32_t corrval:				8;
	uint32_t softval:				8;
	//AFCADJRX,AFCADJRX
	uint32_t adjrx:					15;
	uint32_t adjtx:					15;
	//MIXCTRL
	uint32_t mixmode:				4;
	uint32_t digiqwrapen:		1;
	//CTRL0
	uint32_t fmoddifdis:		1;
	uint32_t mapfsk: 				3;
	uint32_t coding:				2;
	uint32_t modformat:			3;
	uint32_t dualcorroptdis: 1;
	uint32_t dssslen:				5;
	uint32_t dsssshifts:		3;
	uint32_t dsssdouble:		2;
	uint32_t detdis:				1; //will be excluded
	uint32_t diffencmode:		3;
	uint32_t shaping:				2;
	uint32_t demodrawdatasel: 3;
	uint32_t framedetdel:   2;
	//CTRL1
	uint32_t syncbits:			5;
	uint32_t syncerrors:		4;
	uint32_t dualsync:			1;
	uint32_t txsync:				1;
	uint32_t syncdata:			1;
	uint32_t sync1inv:			1;
	uint32_t compmode:			2;
	uint32_t resyncper:			4;
	uint32_t phasedemod:		2;
	uint32_t freqoffestper: 3;
	uint32_t freqoffestlim:	7;
	//CTRL2
	//CTRL3
	//CTRL4
	//CTRL5
	//TXBR, RXBR
	uint32_t baudrate;
	//CF
	//PRE
	uint32_t prepattern:		4; //PRE_BASE
	uint32_t prepatternlen:	2; //PREBASEBITS
	uint32_t prelen:				16; //TXBASES
	//SYNC0, SYNC1
	uint32_t sync0;
	uint32_t sync1;

}MODEMsettings_t;

//void MODEM_IRQHandler(void);
void MODEM_init(void);
void MODEM_ConfigFixup(void);
void MODEM_DemodResetOnRxsearchEntryEnable(void);
void MODEM_DemodResetOnRxsearchEntryDisable(void);
void MODEM_DccalEnable(void);
void MODEM_DccalDisable(void);
uint32_t MODEM_ComputeTxBaudrate(void);
uint32_t MODEM_ComputeTxSymbolRate(void);
uint32_t MODEM_ComputeTxBitRate(void);

#endif