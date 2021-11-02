#ifndef _RADIO_TIMING_H_
#define _RADIO_TIMING_H_
#include "radio_proc.h"
void RADIO_TxWarmTimeSet(uint16_t us);
void RADIO_RxToTxTimeSet(uint16_t us);
void RADIO_RxFrameToTxTimeSet(uint16_t us);
void RADIO_TxToTxTimeSet(uint16_t us);
void RADIO_TxToRxTimeSet(uint16_t us);
void RADIO_RxWarmTimeSet(uint16_t us);
uint16_t RADIO_RxWarmTimeGet(void);
void RADIO_RxSearchTimeSet(uint32_t us);
void RADIO_TxToRxSearchTimeSet(uint32_t us);
uint32_t RADIO_UsToStimerTickCalc(uint32_t us);
void Timing_DelayUs(uint32_t us);
#endif
