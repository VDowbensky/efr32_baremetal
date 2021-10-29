#ifndef _RADIO_PROC_H_
#define _RADIO_PROC_H_

#define RADIO_BUFFER_SIZE 64

//#define TX_PACTUNE	8
//#define RX_PACTUNE	8
#include "em_int.h"
#include "bsp.h"
#include "synth.h"
#include "rf_test.h"
#include "pa.h"
#include "phy.h"
#include "generic_phy.h"
//#include "rail_rf.h"

#include "em_device.h"
#include "em_cmu.h"
#include "radio.h"
#include "generic_seq.h"
#include "protimer.h"
#include "synth.h"
//#include "phy_utils.h"
#include "mcu_memory.h"
#include "rail_rf_hal.h"

void init_radio(void);

bool RADIO_SendPacket(void);

extern uint8_t txpactune;
extern uint8_t rxpactune;

extern volatile uint8_t RADIO_rxBuffer[];
extern volatile uint8_t RADIO_txBuffer[];
extern volatile uint8_t RADIO_rxLengthBuffer[];

extern RAIL_TxData_t transmitPayload;

#endif