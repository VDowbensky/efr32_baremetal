#ifndef _PA_POWERTABLE_H_
#define _PA_POWERTABLE_H_
#include <stdint.h>
#include "bsp.h"

#define MIN_PWR_LEVEL -20
#define MAX_PWR_LEVEL 20
#define POWER_DBM_INVALID -127

uint8_t PA_powertable[41] = 
	{
		PM20,
		PM19,
		PM18,
		PM17,
		PM16,
		PM15,
		PM14,
		PM13,
		PM12,
		PM11,
		PM10,
		PM09,
		PM08,
		PM07,
		PM06,
		PM05,
		PM04,
		PM03,
		PM02,
		PM01,
		P000,
		PP01,
		PP02,
		PP03,
		PP04,
		PP05,
		PP06,
		PP07,
		PP08,
		PP09,
		PP10,
		PP11,
		PP12,
		PP13,
		PP14,
		PP15,
		PP16,
		PP17,
		PP18,
		PP19,
		PP20,
	};

#endif

