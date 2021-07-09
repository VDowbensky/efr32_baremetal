#include "myspi.h"
#if(GN || MX)
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
#if GN
  spi_initstruct.msbf = false;
#else
	spi_initstruct.msbf = false;
#endif
  //spi_initstruct.msbf = true;
  spi_initstruct.clockMode = usartClockMode0;
  spi_initstruct.enable = usartDisable;
  USART_InitSync(SPI_USART, &spi_initstruct);
  //main SPI port
  GPIO_PinModeSet(MOSI_PORT, MOSI_PIN, gpioModePushPull,0);/* Data */
#if MX
	GPIO_PinModeSet(MISO_PORT, MISO_PIN, gpioModeInput,0);/* Data */
#endif
  GPIO_PinModeSet(SCK_PORT,  SCK_PIN,  gpioModePushPull,0);/* Clock */
#if GN
  GPIO_PinModeSet(CS_PORT,   CS_PIN,   gpioModePushPull,0);/* CS */
#else
	GPIO_PinModeSet(CS_PORT,   CS_PIN,   gpioModePushPull,1);/* CS */
#endif
#if GN
  GPIO_PinModeSet(EXT_MOSI_PORT, EXT_MOSI_PIN, gpioModePushPull,0);/*ext Data */
  GPIO_PinModeSet(EXT_SCK_PORT,  EXT_SCK_PIN,  gpioModePushPull,0);/*ext Clock */
  GPIO_PinModeSet(EXT_CS_PORT,   EXT_CS_PIN,   gpioModePushPull,0);/*ext CS */
  //aux SPI port
#endif
#if MX
  SPI_USART->ROUTELOC0 = (SCK_LOC) | (MOSI_LOC | MISO_LOC);
	SPI_USART->ROUTEPEN = USART_ROUTEPEN_CLKPEN  | USART_ROUTEPEN_TXPEN | USART_ROUTEPEN_RXPEN;
#else
	SPI_USART->ROUTELOC0 = (SCK_LOC) | (MOSI_LOC);
  SPI_USART->ROUTEPEN = USART_ROUTEPEN_CLKPEN  | USART_ROUTEPEN_TXPEN;
#endif
  USART_Enable(SPI_USART, usartEnable);
//  setattenuation(0);
//  setextattenuation(0);
}
#endif

