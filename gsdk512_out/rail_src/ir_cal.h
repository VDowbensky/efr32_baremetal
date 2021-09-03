#ifndef _IRCAL_H_
#define _IRCAL_H_

uint8_t IRCAL_Configure(uint8_t cal);
void IRCAL_SetGlobalCalType(uint8_t cal);
uint8_t IRCAL_GetGlobalCalType(void);
void IRCAL_Set(uint32_t cal);
uint8_t IRCAL_Init(uint8_t *caldata);
void IRCAL_SaveRegStates(void);
uint32_t IRCAL_SetRxFrequency(uint32_t freq);
void IRCAL_StartRx(void);
void IRCAL_StopRx(void);
void IRCAL_SetSubGhzPllLoopback(void);
void IRCAL_SetSubGhzPaLoopback(void);

uint32_t IRCAL_Setup(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
uint32_t IRCAL_TranslateToRssiIndex(uint32_t param_1);
int32_t IRCAL_ReadRssi(uint param_1,uint param_2,uint param_3,undefined4 param_4,undefined2 param_5);
uint32_t IRCAL_SearchLinear2Stage(uint param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined2 param_5);
uint32_t IRCAL_Search(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);

void IRCAL_Teardown(void);
uint32_t IRCAL_Get(void);
uint32_t IRCAL_GetDiValue(void);

int32_t IRCAL_PerformSubfunction(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined2 param_5);
int32_t IRCAL_Perform(undefined4 param_1,undefined4 param_2,undefined4 param_3);

#endif

