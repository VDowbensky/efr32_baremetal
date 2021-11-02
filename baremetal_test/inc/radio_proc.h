#ifndef _RADIO_PROC_H_
#define _RADIO_PROC_H_

#define RADIO_BUFFER_SIZE 256

//#define TX_PACTUNE	8
//#define RX_PACTUNE	8
#include "em_int.h"
#include "bsp.h"
#include "synth.h"
#include "rf_test.h"
#include "pa.h"
//#include "phy.h"
//#include "rail_rf.h"

#include "em_device.h"
#include "em_cmu.h"
#include "generic_seq.h"
#include "protimer.h"
#include "synth.h"
#include "radio_frc.h"
#include "radio_bufc.h"
#include "radio_modem.h"
#include "radio_timing.h"
#include "radio_agc.h"
//#include "phy_utils.h"
#include "mcu_memory.h"

void init_radio(void);

bool RADIO_SendPacket(void);
void RADIO_SetCtune(uint32_t tune);
uint32_t RADIO_GetCtune(void);

RAIL_Status_t RAIL_RfHalSetTxTransitions(RAIL_RadioState_t success,RAIL_RadioState_t error);
RAIL_Status_t RAIL_RfHalSetRxTransitions(RAIL_RadioState_t success,RAIL_RadioState_t error);
uint32_t RFHAL_HeadedToIdle(void);
void GENERIC_PHY_RadioEnable(uint32_t enable);
void GENERIC_PHY_SeqAtomicLock(void);

extern uint8_t txpactune;
extern uint8_t rxpactune;

extern volatile uint8_t RADIO_rxBuffer[];
extern volatile uint8_t RADIO_txBuffer[];
extern volatile uint8_t RADIO_rxLengthBuffer[];

extern RAIL_TxData_t transmitPayload;

#endif