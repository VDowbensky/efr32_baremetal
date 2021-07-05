#ifndef _SPIRAM_H_
#define _SPIRAM_H_

#include "stdint.h"
#include "em_usart.h"
#include "em_gpio.h"
#include "em_cmu.h"
#include "device_specific.h"

#if MWRL
#define MAX_RAM_ADDR      0x7FFF
#define SPIRAM_BAUDRATE   9600000UL

#define SCK_PORT    (gpioPortB)
#define SCK_PIN     (14U)
#define MOSI_PORT   (gpioPortB)
#define MOSI_PIN    (15U)
#define MISO_PORT   (gpioPortB)
#define MISO_PIN    (13U)
#define CS_PORT     (gpioPortB)
#define CS_PIN      (12U)

#define SCK_LOC USART_ROUTELOC0_CLKLOC_LOC7 //PB14
#define CS_LOC USART_ROUTELOC0_CSLOC_LOC4 //PB12 - not used
#define MOSI_LOC USART_ROUTELOC0_TXLOC_LOC10 //PB15
#define MISO_LOC USART_ROUTELOC0_RXLOC_LOC7 //PB13

#define SPI_USART USART1
#define SPI_CLOCK cmuClock_USART1

//23x256 commands
#define READ_COMMAND    0x03 //00000011b
#define WRITE_COMMAND   0x02 //00000010b
#define RDSR_COMMAND    0x05 //00000101b
#define WRSR_COMMAND    0x01 //00000001b

void init_ram(void);
void spiram_writebyte(uint32_t addr, uint8_t data);
uint8_t spiram_readbyte(uint32_t addr);
bool testram(uint8_t testbyte);

extern uint16_t ramtest_addr;
extern uint8_t ramtest_val;

#endif

#endif

