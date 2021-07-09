#ifndef _SPIRAM_H_
#define _SPIRAM_H_

#include "stdint.h"
#include "em_usart.h"
#include "em_gpio.h"
#include "em_cmu.h"
#include "bsp.h"

#if MX
#define MAX_RAM_ADDR      0x7FFF
#define SPIRAM_BAUDRATE   9600000UL



#define SPI_USART USART1
#define SPI_CLOCK cmuClock_USART1

//23x256 commands
#define READ_COMMAND    0x03 //00000011b
#define WRITE_COMMAND   0x02 //00000010b
#define RDSR_COMMAND    0x05 //00000101b
#define WRSR_COMMAND    0x01 //00000001b

void spiram_writebyte(uint32_t addr, uint8_t data);
uint8_t spiram_readbyte(uint32_t addr);
bool testram(uint8_t testbyte);

extern uint16_t ramtest_addr;
extern uint8_t ramtest_val;

#endif

#endif

