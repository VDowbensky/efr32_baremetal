#ifndef _IR_CAL_H_
#define _IR_CAL_H_

#include "em_device.h"
#include <stdint.h>
#include <stdbool.h>
#include "rail.h"

uint8_t IRCAL_Init(RAIL_CalInit_t *data);
void IRCAL_SaveRegStates(void);
void IRCAL_Teardown(void);
void IRCAL_StartRx(void);
void IRCAL_StopRx(void);
void IRCAL_SetSubGhzPllLoopback(void);
void IRCAL_SetSubGhzPaLoopback(void);
uint16_t IRCAL_Get(void);
uint16_t IRCAL_GetDiValue(void);
void IRCAL_SetGlobalCalType(uint8_t type);
uint8_t IRCAL_Configure(uint8_t type);
uint8_t IRCAL_GetGlobalCalType(void);
int32_t IRCAL_SetRxFrequency(uint32_t rxfreq);


void IRCAL_Set(uint32_t param_1);
int32_t IRCAL_Setup(int32_t param_1,uint32_t param_2,uint32_t param_3,uint32_t param_4);
uint32_t IRCAL_TranslateToRssiIndex(uint32_t param_1);
int16_t IRCAL_ReadRssi(uint32_t param_1,uint32_t param_2,uint32_t param_3,uint32_t param_4,uint16_t param_5); //some structure;
uint32_t IRCAL_SearchLinear2Stage(uint32_t param_1,int32_t param_2,uint32_t param_3,uint32_t param_4,uint16_t param_5);
uint32_t IRCAL_Search(int32_t param_1,uint32_t param_2,uint32_t param_3,uint32_t param_4);
uint32_t IRCAL_PerformSubfunction(uint32_t param_1,uint32_t param_2,uint32_t param_3,uint32_t param_4,uint16_t param_5);
uint32_t IRCAL_Perform(void);


#endif
