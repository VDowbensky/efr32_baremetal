#ifndef _PROTIMER_H_
#define _PROTIMER_H_

#include "em_device.h"
#include <stdint.h>
#include <stdbool.h>
#include "rail_types.h"

void PROTIMER_Start(void);
void PROTIMER_Stop(void);
bool PROTIMER_IsRunning(void);
void PROTIMER_Reset(void);
RAIL_Status_t PROTIMER_CCTimerStart(int8_t timer,uint32_t time, RAIL_TimeMode_t mode);
uint32_t PROTIMER_ElapsedTime(uint32_t time,uint32_t cnt);
void PROTIMER_TOUTTimerStop(uint8_t num);
void PROTIMER_TOUTTimerStart(uint32_t time,uint8_t num);
uint32_t PROTIMER_TOUTTimerGet(uint8_t num);
void PROTIMER_CCTimerStop(uint8_t num);
RAIL_Status_t PROTIMER_CCTimerStart(int8_t timer,uint32_t time, RAIL_TimeMode_t mode);
bool PROTIMER_CCTimerIsEnabled(int num);
uint32_t PROTIMER_GetTime(void);
uint32_t PROTIMER_GetCCTime(int num);
void PROTIMER_LBTStart(void);
void PROTIMER_LBTPause(void);
void PROTIMER_LBTStop(void);
uint32_t PROTIMER_LBTStateGet(void);
void PROTIMER_LBTStateSet(uint32_t state);
bool PROTIMER_LBTIsActive(void);
bool PROTIMER_SetTime(uint32_t time);
void PROTIMER_DelayUs(uint32_t us);
uint32_t PROTIMER_PrecntOverflowToUs (uint32_t cnt);
void PROTIMER_CCTimerCapture(int num,uint32_t cnt);
void PROTIMER_ScheduleTxEnable(int timer,uint32_t time,uint32_t mode);
uint32_t PROTIMER_UsToPrecntOverflow(uint32_t us);

void PROTIMER_Init(void);
void PROTIMER_LBTCfgSet(uint32_t param_1,int param_2,uint32_t param_3,int param_4,uint8_t param_5);



#endif
