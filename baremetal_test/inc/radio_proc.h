#ifndef _RADIO_PROC_H_
#define _RADIO_PROC_H_



#include "em_int.h"
#include "bsp.h"
//#include "radio_synth.h"
#include "pa.h"
#include "em_device.h"
#include "em_cmu.h"
#include "app_cli.h"
#include "adc.h"
#include "generic_seq.h"
#include "protimer.h"
//#include "radio_synth.h"
#include "SYNTH.h"
#include "radio_frc.h"
//#include "radio_modem.h"
#include "radio_timing.h"
#include "AGC.h"
#include "BUFC.h"
#include "RFIF.h"
#include "RADIO_config.h"


#include "mcu_memory.h"
#include "radio_phy.h"
#include "radio_tx.h"
#include "radio_rx.h"

#define HIGH(x) ((x & 0xFF000000) >> 24)
#define HIGL(x) ((x & 0x00FF0000) >> 16)
#define LOWH(x) ((x & 0x0000FF00) >> 8)
#define LOWL(x)  (x & 0x000000FF)

#define RADIO_STATE_OFF										0
#define RADIO_STATE_RXWARM								1
#define RADIO_STATE_RXSEARCH							2
#define RADIO_STATE_RXFRAME								3
#define RADIO_STATE_RXPD									4
#define RADIO_STATE_RX2RX 								5
#define RADIO_STATE_RXOVERFLOW						6
#define RADIO_STATE_RX2TX									7
#define RADIO_STATE_TXWARM								8
#define RADIO_STATE_TX										9
#define RADIO_STATE_TXPD									10
#define RADIO_STATE_TX2RX									11
#define RADIO_STATE_TX2TX									12
#define RADIO_STATE_SHUTDOWN							13
#define RADIO_STATE_POR										14

void init_radio(void);
void process_radio(void);
void processHardEvents(void);
void processRxEvents(void);
void processTxEvents(void);
void printRxPacket(void);
void prepareTxPacket(void);
void prepareAnswerPacket(void);
void radio_startburst(void);
void radio_delayms(uint32_t ms);
void processiqdata(void);
void RADIO_CtuneCorrection(void);
uint8_t radio_GetRadioState(void);

extern volatile uint8_t RADIO_rxBuffer[];
extern volatile uint8_t RADIO_txBuffer[];
extern volatile uint8_t RADIO_rxLengthBuffer[];
extern volatile uint32_t iqbuffer[];

extern uint8_t rx_fifo[];
extern uint8_t tx_fifo[];
extern volatile uint32_t packetnumber;

extern volatile uint32_t RxEvents;
extern volatile uint32_t TxEvents;
extern volatile uint32_t HardEvents;

extern uint8_t txmode;
extern volatile uint32_t txpacketcount;
extern uint32_t inter_packet_delay;
extern bool master;
extern bool txpacket;
extern uint32_t slaveID;
extern uint32_t masterID;

extern bool rxc;
extern uint32_t rxpacketcount;
extern int32_t RssiAccum;

extern bool ctunecomp;

extern volatile bool sweepfreq;
extern uint32_t sweepdelay;
extern volatile bool sweeprx;
extern uint8_t minchan;
extern uint8_t maxchan;

void restoretxmode(void);

#endif