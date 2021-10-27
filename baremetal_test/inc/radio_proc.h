#ifndef _RADIO_PROC_H_
#define _RADIO_PROC_H_

#define RADIO_BUFFER_SIZE 64

//#define TX_PACTUNE	8
//#define RX_PACTUNE	8

#include "bsp.h"
#include "synth.h"
#include "rf_test.h"
#include "pa.h"
#include "phy.h"
#include "rail_rf.h"

#include "em_device.h"
#include "em_cmu.h"
#include "radio.h"
#include "generic_seq.h"
#include "protimer.h"
#include "synth.h"
#include "phy_utils.h"
#include "mcu_memory.h"
#include "rail_rx.h"

void init_radio(void);

void BM_TxOn(void);
void BM_TxOff(void);

extern uint8_t txpactune;
extern uint8_t rxpactune;


#endif