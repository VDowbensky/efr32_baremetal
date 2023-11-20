#ifndef _RADIO_RX_H_
#define _RADIO_RX_H_

#include "radio_proc.h"

void radio_startrx(void);
void radio_startberrx(uint32_t bits);
void radio_stopberrx(void);
void radio_reportberstats(RAIL_BerStatus_t *berstatus);
void radio_emptybufandupdatestats(void);
void radio_startiqrx(void);
void radio_stopiqrx(void);

extern bool berRx;
extern bool iqRx;

#endif