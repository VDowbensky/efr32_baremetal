#ifndef _LEDS_H_
#define _LEDS_H_

#include "bsp.h"

void leds_init(void);
#if LED0
void led0_on(void);
void led0_off(void);
#endif

#if LED1
void led1_on(void);
void led1_off(void);
#endif

extern uint32_t blinkduration;
extern bool blink;


#endif


