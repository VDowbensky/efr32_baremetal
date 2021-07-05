#include "spi_ram.h"

#if MX


uint16_t ramtest_addr;
uint8_t ramtest_val;


void spiram_writebyte(uint32_t addr, uint8_t data)
{
  //select chip
  GPIO_PinOutClear(CS_PORT, CS_PIN);
  //send write command
  USART_SpiTransfer(SPI_USART, WRITE_COMMAND);
  //send address
  USART_SpiTransfer(SPI_USART, (uint8_t)(addr >> 8));
  USART_SpiTransfer(SPI_USART, (uint8_t)(addr & 0x00FF));
  //send data byte
  USART_SpiTransfer(SPI_USART, data);
  //deselect chip
  GPIO_PinOutSet(CS_PORT, CS_PIN);
}

uint8_t spiram_readbyte(uint32_t addr)
{
  uint8_t v;
  //select chip
  GPIO_PinOutClear(CS_PORT, CS_PIN);
  //send read command
  USART_SpiTransfer(SPI_USART, READ_COMMAND);
  //send address
  USART_SpiTransfer(SPI_USART, (uint8_t)(addr >> 8));
  USART_SpiTransfer(SPI_USART, (uint8_t)(addr & 0x00FF));
  v = USART_SpiTransfer(SPI_USART, 0);
  //deselect chip
  GPIO_PinOutSet(CS_PORT, CS_PIN);
  return v;
}

bool testram(uint8_t testbyte)
{
  uint16_t i;
  ramtest_val = testbyte;
  for(i = 0; i < MAX_RAM_ADDR; i++)
    {
      ramtest_addr = i;
      spiram_writebyte(i, testbyte);
      ramtest_val = spiram_readbyte(i);
      if((ramtest_val) != testbyte) return false;
    }
  return true;
}

#endif

