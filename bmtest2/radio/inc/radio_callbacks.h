#ifndef _RADIOCALLBACKS_H_
#define _RADIOCALLBACKS_H_

#include "bsp.h"

void RAILCb_RadioStateChanged(uint8_t state);
void RAILCb_RfReady(void);
void RAILCb_RxRadioStatus(uint8_t status);
uint32_t RAILCb_TimerExpired(void);
void RAILCb_TxPacketSent(void);
void RAILCb_TxRadioStatus(uint8_t status);
void RAILCb_CalNeeded(void);

#endif