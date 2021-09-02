#ifndef _RFRAND_H_
#define _RFRAND_H_

uint32_t RFRAND_GetRadioEntropy(void *param_1,uint param_2);
bool RFRAND_SeedProtimerRandom(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4);
uint32_t RFRAND_GetProtimerRandom(void);
void RFRAND_SeedPseudoRandom(void);
uint16_t RFRAND_GetPseudoRandom(void);

#endif
