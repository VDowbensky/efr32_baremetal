#include "atten.h"
#if GOLDENNODE
void init_atten(void);
void setattenuation(uint8_t att);
void setextattenuation(uint8_t att);

void init_atten(void)
{

  USART_InitSync_TypeDef spi_initstruct = USART_INITSYNC_DEFAULT;
  CMU_ClockEnable(cmuClock_HFPER, true);
  CMU_ClockEnable(SPI_CLOCK, true);
  CMU_ClockEnable(cmuClock_GPIO,true);

  spi_initstruct.refFreq = 0;
  spi_initstruct.baudrate = 1000000;
  spi_initstruct.databits = usartDatabits8;
  spi_initstruct.master = true;
  spi_initstruct.msbf = false;
  //spi_initstruct.msbf = true;
  spi_initstruct.clockMode = usartClockMode0;
  spi_initstruct.enable = usartDisable;
  USART_InitSync(SPI_USART, &spi_initstruct);
  //main SPI port
  GPIO_PinModeSet(MOSI_PORT, MOSI_PIN, gpioModePushPull,0);/* Data */
  GPIO_PinModeSet(SCK_PORT,  SCK_PIN,  gpioModePushPull,0);/* Clock */
  GPIO_PinModeSet(LE_PORT,   LE_PIN,   gpioModePushPull,0);/* CS */
  GPIO_PinModeSet(EXT_MOSI_PORT, EXT_MOSI_PIN, gpioModePushPull,0);/*ext Data */
  GPIO_PinModeSet(EXT_SCK_PORT,  EXT_SCK_PIN,  gpioModePushPull,0);/*ext Clock */
  GPIO_PinModeSet(EXT_LE_PORT,   EXT_LE_PIN,   gpioModePushPull,0);/*ext CS */
  //aux SPI port

  SPI_USART->ROUTELOC0 = (SCK_LOC) | (MOSI_LOC);
  // Enable USART pins
  SPI_USART->ROUTEPEN = USART_ROUTEPEN_CLKPEN  | USART_ROUTEPEN_TXPEN;
  USART_Enable(SPI_USART, usartEnable);
  setattenuation(0);
  setextattenuation(0);
}

void setattenuation(uint8_t att)
{
  //LE low
  GPIO_PinModeSet(LE_PORT, LE_PIN, gpioModePushPull, 0);
  //data
  USART_SpiTransfer(SPI_USART, att << 1);
  //address
  USART_SpiTransfer(SPI_USART, ATT_ADDRESS);
  //LE high
  GPIO_PinModeSet(LE_PORT, LE_PIN, gpioModePushPull, 1);
  //LE low
  GPIO_PinModeSet(LE_PORT, LE_PIN, gpioModePushPull, 0);
}

void setextattenuation(uint8_t att)
{
  //remap SPI
  USART_Enable(SPI_USART, usartDisable);
  SPI_USART->ROUTELOC0 = (EXT_SCK_LOC) | (EXT_MOSI_LOC);
  // Enable USART pins
  SPI_USART->ROUTEPEN = USART_ROUTEPEN_CLKPEN  | USART_ROUTEPEN_TXPEN;
  USART_Enable(SPI_USART, usartEnable);
  //LE low
  GPIO_PinModeSet(EXT_LE_PORT, EXT_LE_PIN, gpioModePushPull, 0);
  //data
  USART_SpiTransfer(SPI_USART, att << 1);
  //address
  USART_SpiTransfer(SPI_USART, ATT_ADDRESS);
  //LE high
  GPIO_PinModeSet(EXT_LE_PORT, EXT_LE_PIN, gpioModePushPull, 1);
  //LE low
  GPIO_PinModeSet(EXT_LE_PORT, EXT_LE_PIN, gpioModePushPull, 0);
  //remap SPI back
  USART_Enable(SPI_USART, usartDisable);
  SPI_USART->ROUTELOC0 = (SCK_LOC) | (MOSI_LOC);
  // Enable USART pins
  SPI_USART->ROUTEPEN = USART_ROUTEPEN_CLKPEN  | USART_ROUTEPEN_TXPEN;
  USART_Enable(SPI_USART, usartEnable);
}

#endif



