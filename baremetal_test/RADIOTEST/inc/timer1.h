#ifndef _TIMER1_H_
#define _TIMER1_H_
#include "bsp.h"

#define TIMER1_PRESCALE timerPrescale1//timerPrescale1

void initTimer1(uint32_t freq);
void startTimer1(void);
void stopTimer1(void);

#endif


