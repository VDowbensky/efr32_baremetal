#ifndef _RADIO_RX_H_
#define _RADIO_RX_H_

#include "radio_proc.h"

void radio_startrx(void);
void radio_startberrx(uint32_t bytes);
void radio_stopberrx(void);

#endif