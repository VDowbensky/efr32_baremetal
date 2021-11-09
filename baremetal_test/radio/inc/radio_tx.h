#ifndef _RADIO_TX_H_
#define _RADIO_TX_H_

#include "radio_proc.h"

bool radio_sendpacket(void);
void radio_startCW(void);
void radio_setupPN9(void);
void radio_startPN9(void);
void radio_stoptx(void);

#endif

