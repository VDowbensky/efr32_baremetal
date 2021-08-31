#ifndef _AUXPLL_H_
#define _AUXPLL_H_

void AUXPLL_AuxSettingsPllLoopback(void);
void AUXPLL_AuxSettingsPaLoopback(void);
void AUXPLL_Stop(void);
undefined AUXPLL_ConvertAuxLoDivToRegVal(int param_1);
void AUXPLL_Configure(uint param_1,undefined4 param_2,int param_3,int param_4);
int32_t AUXPLL_Start(int param_1,undefined4 param_2,int param_3,uint param_4);

#endif