#ifndef _RFSENSE_H_
#define _RFSENSE_H_

void RFSENSE_Disable(void);

int RFSENSE_CalcPeriod(uint param_1,uint param_2,char *param_3,undefined4 param_4);

void RFSENSE_ReInit(void);
bool RFSENSE_Sensed(void);
//uint32_t RFSENSE_IRQHandler(void);
void RFSENSE_DeInit(void);

uint32_t RFSENSE_Init(undefined4 *param_1,uint param_2);
uint32_t RFSENSE_CalRfOscFreq(uint param_1);

#endif