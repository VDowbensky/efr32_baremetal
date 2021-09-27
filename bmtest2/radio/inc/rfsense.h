#ifndef _RFSENSE_H_
#define _RFSENSE_H_

#include "em_device.h"
#include <stdint.h>
#include <stdbool.h>

void RFSENSE_Disable(void);
int RFSENSE_CalcPeriod(uint32_t param_1,uint32_t param_2,char *param_3,uint32_t param_4);
void RFSENSE_ReInit(void);
bool RFSENSE_Sensed(void);
void RFSENSE_IRQHandler(void);
void RFSENSE_DeInit(void);
uint32_t RFSENSE_Init(uint32_t *param_1,uint32_t param_2,uint32_t param_3);
int RFSENSE_CalRfOscFreq(int param_1);


#endif
