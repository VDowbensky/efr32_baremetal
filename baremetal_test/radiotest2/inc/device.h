#ifndef _RADIOTEST_H_
#define _RADIOTEST_H_

#include "version.h"

#define DEVICE_STRING_NAME "Radio test"
#define TX_PACKET_TEMPLATE {0, 0, 0, 0, -120, 0, 'T', 0, 0, 0, 0, 0, 0, 0, 0,'R', 'A', 'D', 'I', 'O',' ','T','E','S','T',' ',' '}
#define HW_VERSION 1
	
#define TX_PACTUNE 7
#define RX_PACTUNE 13
#define DEFAULT_TX_POWER 10
#define RSSI_OFFSET -6
	
#define DEFAULT_CAL_TEMP 25.0f
	
#define CTUNE_CORR_ON_THE_FLY   1
//#define CTUNE_CORR_ON_THE_FLY   0
#define CTUNE_PERIOD         1000

#define K_CTUNE_KHZ     0.25f //kHz/ctune - may be variable!!! 
	
#define K_CTUNE3_KHZ    0.00006f
#define K_CTUNE2_KHZ    -0.0012f
#define K_CTUNE1_KHZ    -0.18f
#define K_CTUNE0_KHZ    0.0f

#define K_CTUNE3    K_CTUNE3_KHZ/K_CTUNE_KHZ
#define K_CTUNE2    K_CTUNE2_KHZ/K_CTUNE_KHZ
#define K_CTUNE1    K_CTUNE1_KHZ/K_CTUNE_KHZ
#define K_CTUNE0    K_CTUNE0_KHZ/K_CTUNE_KHZ

#define K_CTUNE     K_CTUNE1                 //-0.28f

// USART0 TX on PD14
#define USART_TX_PORT           gpioPortA
#define USART_TX_PIN            0
#define USART_TX_LOC            0
// USART0 RX on PD13
#define USART_RX_PORT           gpioPortA
#define USART_RX_PIN            1
#define USART_RX_LOC            0

#define BTN0_PORT               gpioPortB
#define BTN0_PIN                13
#define BTN1_PORT               gpioPortB
#define BTN1_PIN                13

#define LED0		 								1
#define LED0_PORT               gpioPortB
#define LED0_PIN                14
#define LED1                    0
#define LED1_PORT               gpioPortB
#define LED1_PIN                15
#define LED_POLARITY						0

#define TAMPER_EN_PORT             gpioPortC
#define TAMPER_EN_PIN              11
#define TAMPER_PORT                gpioPortC
#define TAMPER_PIN                 10

#define EM4_EN_PORT                gpioPortF
#define EM4_EN_PIN                 3

#define SWD_PORT			gpioPortF
#define SWDIO_PIN			1
#define SWCLK_PIN			0

#define PM20	  1 //-20
#define PM19    2 //-19
#define PM18    3 //-18
#define PM17    3 //-17
#define PM16    3 //-16
#define PM15	  4 //-15
#define PM14    4 //-14
#define PM13    5 //-13
#define PM12    6 //-12
#define PM11    6 //-11
#define PM10    7 //-10
#define PM09    7 //-9
#define PM08    8 //-8
#define PM07    9 //-7
#define PM06    11 //-6
#define PM05    12 //-5
#define PM04    13 //-4
#define PM03    15 //-3
#define PM02    17 //-2
#define PM01    20 //-1
#define P000    22 //0
#define PP01    25 //1
#define PP02    28 //2
#define PP03    31 //3
#define PP04    35 //4
#define PP05    39 //5
#define PP06    44 //6
#define PP07    50 //7
#define PP08    56 //8
#define PP09    63 //9
#define PP10    71 //10
#define PP11    81 //11
#define PP12    93 //12
#define PP13    110 //13
#define PP14    134 //14
#define PP15    144 //15
#define PP16    150 //16
#define PP17    150 //17
#define PP18    150 //18
#define PP19    150 //19
#define PP20    150 //20

#endif
