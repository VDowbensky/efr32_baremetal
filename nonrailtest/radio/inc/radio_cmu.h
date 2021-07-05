#ifndef _RADIOCMU_H_
#define _RADIOCMU_H_

#include "em_device.h"
#include <stdint.h>
#include <stdbool.h>
#include "em_cmu.h"

void RADIOCMU_ClockEnable(CMU_Clock_TypeDef clock, bool enable);
uint32_t RADIOCMU_ClockFreqGet(CMU_Clock_TypeDef clock);
uint32_t RADIOCMU_ClockPrescGet(CMU_Clock_TypeDef clock);
void RADIOCMU_ClockPrescSet(CMU_Clock_TypeDef clock, uint32_t presc);


#endif
