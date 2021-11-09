#ifndef _RADIO_PROC_H_
#define _RADIO_PROC_H_

#define RADIO_BUFFER_SIZE 64

//#define TX_PACTUNE	8
//#define RX_PACTUNE	8
#include "em_int.h"
#include "bsp.h"
#include "synth.h"
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
#include "radio_tx.h"
#include "radio_rx.h"

//RX events
//MODEM
#define RXEVENT_TIMDET					0x1
#define RXEVENT_TIMLOST					0x2
#define RXEVENT_PREDET					0x4
#define RXEVENT_PRELOST					0x8
#define RXEVENT_RXFRAMEDET0			0x10
#define RXEVENT_RXFRAMEDET1			0x20
#define RXEVENT_RXFRAMEDETOF		0x40
#define RXEVENT_RXTIMNF					0x80
//FRC
#define RXEVENT_DONE						0x100
#define RXEVENT_ABORTED					0x200
#define RXEVENT_FRAMEERROR			0x400
#define RXEVENT_BLOCKERROR			0x800
#define RXEVENT_RXOVERFLOW			0x1000
#define RXEVENT_RAWEVENT				0x2000
#define RXEVENT_FRAMEDETPAUSED	0x4000
#define RXEVENT_RXWORD					0x8000
//AGC
#define RXEVENT_RSSIVALID				0x10000
#define RXEVENT_CCA							0x20000
#define RXEVENT_RSSIPOSSTEP			0x40000
#define RXEVENT_RSSINEGSTEP			0x80000
#define RXEVENT_RSSIDONE				0x100000

//TX events
//MODEM
#define TXEVENT_PRESENT					0x1
#define TXEVENT_SYNCSENT				0x2
#define TXEVENT_FRAMESENT				0x4
//FRC
#define TXEVENT_DONE						0x8
#define TXEVENT_AFTERFRAMEDONE 	0x10
#define TXEVENT_ABORTED					0x20
#define TXEVENT_UNDERFLOW				0x40
#define TXEVENT_RAWEVENT				0x80
#define TXEVENT_TXSUBFRAMEPAUSED 0x100
#define TXEVENT_TXWORD					0x200


//HARD events
//FRC
#define HARDEVENT_WCNTCMP0			0x1
#define HARDEVENT_WCNTCMP1			0x2
#define HARDEVENT_WCNTCMP2			0x4
#define HARDEVENT_ADDRERROR			0x8
#define HARDEVENT_FRCBUSERROR		0x10
#define HARDEVENT_SNIFFOF				0x20
#define HARDEVENT_LVDSWILLERROR	0x40
#define HARDEVENT_LVDSERROR			0x80
#define HARDEVENT_INTERLEAVEWRITEPAUSED	0x100
#define HARDEVENT_INTERLEAVEREADPAUSED	0x200
#define HARDEVENT_CONVPAUSED		0x400
//PROTIMER
#define HARDEVENT_PRECNTOF			0x800
#define HARDEVENT_BASECNTOF			0x1000
#define HARDEVENT_WRAPCNTOF			0x2000
#define HARDEVENT_TOUT0					0x4000
#define HARDEVENT_TOUT1					0x8000
#define HARDEVENT_TOUT0MATCH		0x10000
#define HARDEVENT_TOUT1MATCH		0x20000
#define HARDEVENT_CC0						0x40000
#define HARDEVENT_CC1						0x80000
#define HARDEVENT_CC2						0x100000
#define HARDEVENT_CC3						0x200000
#define HARDEVENT_CC4						0x400000
#define HARDEVENT_COF0					0x800000
#define HARDEVENT_COF1					0x1000000
#define HARDEVENT_COF2					0x2000000
#define HARDEVENT_COF3					0x3000000
#define HARDEVENT_COF4					0x4000000





void init_radio(void);
void process_radio(void);
void processHardEvents(void);
void processRxEvents(void);
void processTxEvents(void);
void printRxPacket(void);

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

extern uint8_t RxDatabuffer[];

extern volatile uint32_t RxEvents;
extern volatile uint32_t TxEvents;
extern volatile uint32_t HardEvents;

extern RAIL_TxData_t transmitPayload;

#endif