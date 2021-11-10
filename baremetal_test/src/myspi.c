#include "myspi.h"
#if(SPI_USED)
void init_spi(void)
{

  USART_InitSync_TypeDef spi_initstruct = USART_INITSYNC_DEFAULT;
  CMU_ClockEnable(cmuClock_HFPER, true);
  CMU_ClockEnable(SPI_CLOCK, true);
  CMU_ClockEnable(cmuClock_GPIO,true);

  spi_initstruct.refFreq = 0;
  spi_initstruct.baudrate = SPI_BAUDRATE;
  spi_initstruct.databits = usartDatabits8;
  spi_initstruct.master = true;
  spi_initstruct.msbf = false;
  //spi_initstruct.msbf = true;
  spi_initstruct.clockMode = usartClockMode0;
  spi_initstruct.enable = usartDisable;
  USART_InitSync(SPI_USART, &spi_initstruct);
  //main SPI port
  GPIO_PinModeSet(MOSI_PORT, MOSI_PIN, gpioModePushPull,0);/* Data */
	GPIO_PinModeSet(MISO_PORT, MISO_PIN, gpioModeInput,0);/* Data */
  GPIO_PinModeSet(SCK_PORT,  SCK_PIN,  gpioModePushPull,0);/* Clock */
	GPIO_PinModeSet(CS_PORT,   CS_PIN,   gpioModePushPull,1);/* CS */

  SPI_USART->ROUTELOC0 = (SCK_LOC) | (MOSI_LOC | MISO_LOC);
	SPI_USART->ROUTEPEN = USART_ROUTEPEN_CLKPEN  | USART_ROUTEPEN_TXPEN | USART_ROUTEPEN_RXPEN;
  USART_Enable(SPI_USART, usartEnable);
}
#endif

