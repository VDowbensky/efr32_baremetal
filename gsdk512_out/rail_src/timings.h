#ifndef _TIMINGS_H_
#define _TIMINGS_H_


void TIMING_SeqTimingInit(void)
uint32_t TIMING_NsToStimerTickCalc(uint16_t ns);
void TIMING_InitStimer(void);
void TIMING_TxWarmTimeRecalculate(void);
uint16_t TIMING_TxWarmTimeSet(uint16_t time);
uint16_t TIMING_TxWarmTimeGet(void);
void TIMING_RxToTxTimeRecalculate(void);
uint16_t TIMING_RxToTxTimeSet(uint16_t time);
void TIMING_RxFrameToTxTimeRecalculate(void);
uint16_t TIMING_RxFrameToTxTimeSet(uint16_t time);
void TIMING_TxToTxTimeRecalculate(void);
uint16_t TIMING_TxToTxTimeSet(uint16_t time);
void TIMING_TxToRxTimeRecalculate(void);
uint16_t TIMING_TxToRxTimeSet(uint16_t time);
void TIMING_RxWarmTimeRecalculate(void);
uint16_t TIMING_RxWarmTimeSet(uint16_t time);
uint16_t TIMING_RxWarmTimeGet(void);
uint16_t TIMING_RxSearchTimeSet(uint16_t time);
uint16_t TIMING_RxSearchTimeGet(void);
uint16_t TIMING_TxToRxSearchTimeSet(uint16_t time);
void TIMING_RecalculateAll(void);
uint32_t TIMING_SetChainDelays(uint32_t rxdelay,uint32_t txdelay);

int32_t TIMING_GetRxTimestampUs(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
int32_t TIMING_GetTxTimestampUs(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);

#endif

