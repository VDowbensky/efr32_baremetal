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
#include "generic_phy.h"
#include "protimer.h"
#include "synth.h"
#include "modem.h"
#include "ctune.h"
#include "phy_utils.h"
#include "mcu_memory.h"
#include "rail_rx.h"

void init_radio(void);
void set_defaults(void);
void init_buffers(void);

void init_frc(void);
void init_crc(void);
void init_agc(void);
void init_sequencer(void);
void init_synth(void);
void init_pa(void);
void init_protimer(void);


extern uint8_t txpactune;
extern uint8_t rxpactune;

extern uint8_t RADIO_rxBuffer[];
extern uint8_t RADIO_txBuffer[];


#endif