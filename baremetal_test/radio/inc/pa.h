#ifndef _RADIO_PA_H_
#define _RADIO_PA_H_

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

void PA_Init(uint8_t level, uint16_t ramptime);
void PA_SetPowerLevel(uint8_t level);
void PA_SetPowerDbm(int8_t dbm);
int8_t PA_GetPowerDbm(void);

uint32_t PA_RampTimeGet(void);
uint16_t PA_RampTimeSet(uint16_t ramptime);
void PA_CTuneSet(uint8_t txPaCtuneValue, uint8_t rxPaCtuneValue);


void PA_PeakDetectorHighRun(void);
void PA_PeakDetectorLowRun(void);
void PA_BatHighRun(void);

extern uint8_t PA_Powerlevel;
extern uint16_t PA_rampTime;
extern uint8_t txpactune;
extern uint8_t rxpactune;


#endif 
