#ifndef _PROTIMER_H_
#define _PROTIMER_H_

void PROTIMER_Init(void);
void PROTIMER_Start(void);
void PROTIMER_Stop(void);
bool PROTIMER_IsRunning(void);
void PROTIMER_Reset(void);
uint32_t PROTIMER_ElapsedTime(uint32_t time,uint32_t cnt);
void PROTIMER_TOUTTimerStop(uint8_t tout);
void PROTIMER_TOUTTimerStart(uint32_t time,uint8_t tout);
uint32_t PROTIMER_TOUTTimerGet(uint8_t tout);
void PROTIMER_CCTimerStop(uint8_t channel);
bool PROTIMER_CCTimerStart(uint8_t param_1,uint param_2,int param_3);
void PROTIMER_WrapMultiple(uint param_1,undefined4 param_2,uint param_3,int param_4);
bool PROTIMER_CCTimerIsEnabled(uint8_t channel);
void PROTIMER_CCTimerCapture(uint8_t channel,uint param_2);
void PROTIMER_ClearTxEnable(void);
bool PROTIMER_ScheduleRxDisable(uint param_1,uint param_2,int param_3);
void PROTIMER_ClearRxEnable(void);
uint32_t PROTIMER_GetTime(void);
uint32_t PROTIMER_GetCCTime(uint32_t ch);
void PROTIMER_LBTUseLastConfig(void);
void PROTIMER_LBTStart(void);
void PROTIMER_LBTPause(void);
void PROTIMER_LBTStop(void);
uint32_t PROTIMER_LBTStateGet(void);
void PROTIMER_LBTStateSet(uint32_t state);
bool PROTIMER_LBTIsActive(void);
uint32_t PROTIMER_PrecntOverflowToUs(uint32_t param_1);
uint32_t PROTIMER_UsToPrecntOverflow(uint32_t us);
bool PROTIMER_ScheduleTxEnable(uint param_1,uint param_2,int param_3);
bool PROTIMER_ScheduleRxEnable(uint param_1,uint param_2,int param_3);
bool PROTIMER_SetTime(uint32_t time);
void PROTIMER_LBTCfgSet(uint param_1,int param_2,uint param_3,int param_4,byte param_5);
void PROTIMER_DelayUs(uint32_t us);

#endif