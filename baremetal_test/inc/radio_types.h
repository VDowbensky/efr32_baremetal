#ifndef _RADIO_TYPES_H_
#define _RADIO_TYPES_H_
#include <stdint.h>

//Basic radio configuration

//Frequency settings
//--base frequency
//--channel spacing
//--channel count (or channel list)
//Injection side
//IF
typedef struct
	{
		uint32_t basefreq;
		uint32_t spacing;
		uint32_t chancount;
		uint32_t iffreq;
		uint8_t loside;
	}FreqSettings_t;

//Crystal frequency and tolerance - it's not mandatory because F_HFXO is already known

//Modulation type
//Deviation
//Shaping filter
//BT/R
//Mapping
//Direct mode
	typedef struct
	{
		uint32_t bitrate;
		uint8_t modtype;
		uint32_t deviation;
		uint8_t shaping;
		uint8_t bt;
		uint8_t mapping;
		uint8_t directmode;
	}ModSettings_t;
	


//Frame settings


//Symbol coding

//Channel coding (FEC)

//Timings

//AGC

//AFC

//IF/BW settings



#endif

