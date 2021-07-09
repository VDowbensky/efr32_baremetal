#include "atten.h"
#if GN

float i_att;
float i_extatt;

void init_atten(void)
{
  setattenuation(0);
  setextattenuation(0);
}

void setattenuation(uint8_t att)
{
  //LE low
  GPIO_PinOutClear(CS_PORT, CS_PIN);
  //data
  USART_SpiTransfer(SPI_USART, att << 1);
  //address
  USART_SpiTransfer(SPI_USART, ATT_ADDRESS);
  //LE high
  GPIO_PinOutSet(CS_PORT, CS_PIN);
  //LE low
  GPIO_PinOutClear(CS_PORT, CS_PIN);
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
  GPIO_PinOutClear(EXT_CS_PORT, EXT_CS_PIN);
  //data
  USART_SpiTransfer(SPI_USART, att << 1);
  //address
  USART_SpiTransfer(SPI_USART, ATT_ADDRESS);
  //LE high
  GPIO_PinOutSet(EXT_CS_PORT, EXT_CS_PIN);
  //LE low
  GPIO_PinOutClear(EXT_CS_PORT, EXT_CS_PIN);
  //remap SPI back
  USART_Enable(SPI_USART, usartDisable);
  SPI_USART->ROUTELOC0 = (SCK_LOC) | (MOSI_LOC);
  // Enable USART pins
  SPI_USART->ROUTEPEN = USART_ROUTEPEN_CLKPEN  | USART_ROUTEPEN_TXPEN;
  USART_Enable(SPI_USART, usartEnable);
}

#endif



