#ifndef _ATTEN_H_
#define _ATTEN_H_



#include "stdint.h"
#include "em_usart.h"
#include "em_gpio.h"
#include "em_cmu.h"
#include "device_specific.h"

#define ATT_ADDRESS 0


#define SCK_LOC USART_ROUTELOC0_CLKLOC_LOC20 //PD14
#define CS_LOC USART_ROUTELOC0_CSLOC_LOC20 //PD15 - not used
#define MOSI_LOC USART_ROUTELOC0_TXLOC_LOC21 //PD13
#define MISO_LOC USART_ROUTELOC0_RXLOC_LOC25 //PF2 - not used

#define EXT_SCK_LOC USART_ROUTELOC0_CLKLOC_LOC5 //PB12
#define EXT_CS_LOC USART_ROUTELOC0_CSLOC_LOC3 //PB11 - not used
#define EXT_MOSI_LOC USART_ROUTELOC0_TXLOC_LOC8 //PB13
#define EXT_MISO_LOC USART_ROUTELOC0_RXLOC_LOC25 //PF2 - not used

#define SPI_USART USART1

#define SPI_CLOCK cmuClock_USART1


extern void init_atten(void);
extern void setattenuation(uint8_t att);
extern void setextattenuation(uint8_t att);

#endif



