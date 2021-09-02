#ifndef _RADIOCMU_H_
#define _RADIOCMU_H_

void RADIOCMU_ClockEnable(uint32_t clock,bool enable);
uint32_t RADIOCMU_ClockFreqGet(uint32_t clock);
uint32_t RADIOCMU_ClockPrescGet(uint32_t clock);
void RADIOCMU_ClockPrescSet(uint32_t clock,uint32_t presc);

#endif