#ifndef _RF_RAND_H_
#define _RF_RAND_H_

#include "em_device.h"
#include <stdint.h>
#include <stdbool.h>

uint16_t RFRAND_GetRadioEntropy(void);
uint32_t RFRAND_SeedProtimerRandom(uint32_t param_1,uint32_t param_2,uint32_t param_3,uint32_t param_4);
uint16_t RFRAND_GetProtimerRandom(void);

#endif

