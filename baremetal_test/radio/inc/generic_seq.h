#ifndef _GENERIC_SEQ_H_
#define _GENERIC_SEQ_H_

#include "em_device.h"
#include <stdint.h>
#include <stdbool.h>
#include "radio_proc.h"

#define RAIL_VER 12

#if(RAIL_VER == 12)
#define GENERIC_SEQPROG_SIZE 3000
//sequencer variables
#define SEQ_CONTROL_REG  *(uint32_t*)0x21000efc
#define RADIO_TRANSITIONS SEQ->REG000

//timings
#define RX_WARMTIME SEQ->REG09C
#define RX_SEARCHTIME SEQ->REG0A0
#define RX_TX_TIME SEQ->REG0A4
#define RXFRAME_TX_TIME SEQ->REG0A8
#define TX_WARMTIME SEQ->REG0AC
#define TX_RX_TIME SEQ->REG0B0
#define TX_RX_SEARCHTIME SEQ->REG0B4
#define TX_TX_TIME SEQ->REG0B8
#define STIMER_VALUE SEQ->REG0BC
//PA
#define PA_SLICES SEQ->REG0C0
#define RX_PA_CTUNE SEQ->REG0C4
#define TX_PA_CTUNE SEQ->REG0C8

#elif(RAIL_VER == 13)
#define GENERIC_SEQPROG_SIZE 3820
//sequencer variables
#define SEQ_CONTROL_REG  *(uint32_t*)0x21000efc
#define RADIO_TRANSITIONS SEQ->REG000

//timings
#define RX_WARMTIME SEQ->REG09C
#define RX_SEARCHTIME SEQ->REG0A0
#define RX_TX_TIME SEQ->REG0A4
#define RXFRAME_TX_TIME SEQ->REG0A8
#define TX_WARMTIME SEQ->REG0AC
#define TX_RX_TIME SEQ->REG0B0
#define TX_RX_SEARCHTIME SEQ->REG0B4
#define TX_TX_TIME SEQ->REG0B8
#define STIMER_VALUE SEQ->REG0BC
//PA
#define PA_SLICES SEQ->REG0C0
#define RX_PA_CTUNE SEQ->REG0C4
#define TX_PA_CTUNE SEQ->REG0C8	
	
#endif

extern uint8_t genericSeqProg[];

#endif


