#include "spi_ram.h"

//#if MWRL


uint16_t ramtest_addr;
uint8_t ramtest_val;

void init_ram(void)
{

  USART_InitSync_TypeDef spi_initstruct = USART_INITSYNC_DEFAULT;
  CMU_ClockEnable(cmuClock_HFPER, true);
  CMU_ClockEnable(SPI_CLOCK, true);
  CMU_ClockEnable(cmuClock_GPIO,true);

  spi_initstruct.refFreq = 0;
  spi_initstruct.baudrate = SPIRAM_BAUDRATE;
  spi_initstruct.databits = usartDatabits8;
  spi_initstruct.master = true;
  //spi_initstruct.msbf = false;
  spi_initstruct.msbf = true;
  //spi_initstruct.msbf = true;
  spi_initstruct.clockMode = usartClockMode0;
  spi_initstruct.enable = usartDisable;
  USART_InitSync(SPI_USART, &spi_initstruct);
  //main SPI port
  GPIO_PinModeSet(MOSI_PORT, MOSI_PIN, gpioModePushPull,0);/* Data */
  GPIO_PinModeSet(MISO_PORT, MISO_PIN, gpioModeInputPull,1);/* Data */
  GPIO_PinModeSet(SCK_PORT,  SCK_PIN,  gpioModePushPull,0);/* Clock */
  GPIO_PinModeSet(CS_PORT,   CS_PIN,   gpioModePushPull,1);/* CS */

  SPI_USART->ROUTELOC0 = (SCK_LOC) | (MOSI_LOC) | (MISO_LOC);
  // Enable USART pins
  SPI_USART->ROUTEPEN = USART_ROUTEPEN_CLKPEN  | USART_ROUTEPEN_TXPEN | USART_ROUTEPEN_RXPEN;
  USART_Enable(SPI_USART, usartEnable);

}

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

//#endif

