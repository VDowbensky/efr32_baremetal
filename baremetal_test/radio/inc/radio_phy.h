#ifndef _RADIO_PHY_H_
#define _RADIO_PHY_H_

#include "radio_proc.h"

void radio_SetCtune(uint32_t tune);
uint32_t radio_GetCtune(void);
RAIL_Status_t radio_SetTxTransitions(RAIL_RadioState_t success,RAIL_RadioState_t error);
RAIL_Status_t radio_SetRxTransitions(RAIL_RadioState_t success,RAIL_RadioState_t error);
uint32_t radio_HeadedToIdle(void);
void radio_Enable(uint32_t enable);
void radio_SeqAtomicLock(void);
void radio_SeqAtomicUnlock(void);

#endif

