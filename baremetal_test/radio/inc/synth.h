#ifndef _SYNTH_H_
#define _SYNTH_H_

#include "em_device.h"
#include "em_bus.h"
#include <stdbool.h>
#include "RADIO_config.h"

  #define VCO_MAX_FREQ           2900000000
  #define VCO_MIN_FREQ           2300000000
	#define LO_INJECTION_HIGH_SIDE 0
	#define LO_INJECTION_LOW_SIDE  1
/*	
	typedef struct SYNTH_Init
	{
		uint32_t basefreq;
		uint32_t spacing;
		uint32_t iffreq;
		uint32_t loside;
	}SYNTH_Init_t;
*/
	
	void SYNTH_init(void);
	void SYNTH_SetChannel(uint8_t ch,bool rxcal);
	uint32_t SYNTH_GetChanSpacing(void);
	uint32_t  SYNTH_GetBaseFreq(void);
	uint32_t SYNTH_GetLodivValue(void);
	void SYNTH_OverrideIfFreqReg(uint32_t iffreq);
	
	extern uint8_t Channel;

#endif
