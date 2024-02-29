#ifndef _RADIO_RX_H_
#define _RADIO_RX_H_

#include "radio_proc.h"

typedef struct BerStatus
{
  uint32_t bitsTotal;
  uint32_t bitsTested;
  uint32_t bitErrors;
  int8_t   rssi;
} BerStatus_t;

void radio_startrx(void);
void radio_startberrx(uint32_t bits);
void radio_stopberrx(void);
void radio_reportberstats(BerStatus_t *berstatus);
void radio_emptybufandupdatestats(void);
void radio_startiqrx(void);
void radio_stopiqrx(void);

extern bool berRx;
extern bool iqRx;

#endif