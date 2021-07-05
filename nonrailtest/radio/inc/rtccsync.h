#ifndef _RTCSYNC_H_
#define _RTCSYNC_H_

#include "em_device.h"
#include <stdint.h>
#include <stdbool.h>

uint32_t RTCCSYNC_RTCCClockFreqGet(void);
void RTCCSYNC_Init(void);
uint32_t RTCCSYNC_PreSleep(int param_1,uint32_t param_2,uint32_t param_3);
void RTCCSYNC_PostWakeUp(void);

#endif


