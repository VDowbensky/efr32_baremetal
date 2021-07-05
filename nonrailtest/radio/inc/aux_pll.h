#ifndef _AUX_PLL_H_
#define _AUX_PLL_H_

#include "em_device.h"
#include <stdint.h>
#include <stdbool.h>

void AUXPLL_AuxSettingsPllLoopback(void);
void AUXPLL_AuxSettingsPaLoopback(void);
void AUXPLL_Stop(void);
uint8_t AUXPLL_ConvertAuxLoDivToRegVal(int param_1);
void AUXPLL_Configure(uint32_t param_1,uint32_t param_2,int param_3,int param_4);
int AUXPLL_Start(int param_1,uint32_t param_2,int param_3,uint32_t param_4);

#endif
