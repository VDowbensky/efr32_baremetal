#ifndef _AGC_H_
#define _AGC_H_

#include "em_device.h"
#include "math.h"
#include "globals.h"
#include "radio_proc.h"

	#define AGC_SPEED_NORMAL			0
	#define AGC_SPEED_FAST				1
	#define AGC_SPEED_SLOW				2
	
	#define RSSI_PERIOD_OPTIMAL 		3
	#define AGC_PERIOD_OPTIMAL			1
	#define AGC_HYST_OPTIMAL 			3
	

	void AGC_Init(void);
	int16_t AGC_GetRSSI(void);

#endif



