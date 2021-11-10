#include "bsp.h"

#if (I2C_USED)

#include "myi2c.h"


void init_i2c(void)
{
	uint8_t i;
	I2C_Init_TypeDef i2cInit;
	CMU_ClockEnable(cmuClock_HFPER, true);
	CMU_ClockEnable(I2C_CLOCK, true);
	CMU_ClockEnable(cmuClock_GPIO, true);
  CMU_ClockEnable(cmuClock_HFLE, true);
	
	GPIO_PinModeSet(I2C_SCL_PORT, I2C_SCL_PIN, gpioModeWiredAndPullUp, 1);
  GPIO_PinModeSet(I2C_SDA_PORT, I2C_SDA_PIN, gpioModeWiredAndPullUp, 1);

  /* In some situations, after a reset during an I2C transfer, the slave
     device may be left in an unknown state. Send 9 clock pulses to
     set slave in a defined state. */
  for (i = 0; i < 9; i++) {
    GPIO_PinOutSet(I2C_SCL_PORT, I2C_SCL_PIN);
    GPIO_PinOutClear(I2C_SCL_PORT, I2C_SCL_PIN);
  }
	GPIO_PinOutSet(I2C_SCL_PORT, I2C_SCL_PIN);
  /* Enable pins and set location */
  I2C->ROUTEPEN  = I2C_ROUTEPEN_SDAPEN | I2C_ROUTEPEN_SCLPEN;
  I2C->ROUTELOC0 = (I2C_SDA_LOC << _I2C_ROUTELOC0_SDALOC_SHIFT) | (I2C_SCL_LOC << _I2C_ROUTELOC0_SCLLOC_SHIFT);
	
	//I2C0->ROUTEPEN = I2C_ROUTEPEN_SDAPEN | I2C_ROUTEPEN_SCLPEN;
  //I2C0->ROUTELOC0 = (I2C0->ROUTELOC0 & (~_I2C_ROUTELOC0_SDALOC_MASK)) | I2C_ROUTELOC0_SDALOC_LOC16;
  //I2C0->ROUTELOC0 = (I2C0->ROUTELOC0 & (~_I2C_ROUTELOC0_SCLLOC_MASK)) | I2C_ROUTELOC0_SCLLOC_LOC14;
	
	i2cInit.enable = true;
  i2cInit.master = true; /* master mode only */
  i2cInit.freq = I2C_FREQ_FAST_MAX;
  //i2cInit.refFreq = 0;
  //i2cInit.clhr = _I2C_CTRL_CLHR_STANDARD;

  I2C_Init(I2C, &i2cInit);
}

I2C_TransferReturn_TypeDef I2CSPM_Transfer(I2C_TypeDef *i2c, I2C_TransferSeq_TypeDef *seq)
{
  I2C_TransferReturn_TypeDef ret;
  uint32_t timeout = I2CSPM_TRANSFER_TIMEOUT;
  /* Do a polled transfer */
  ret = I2C_TransferInit(i2c, seq);
  while (ret == i2cTransferInProgress && timeout--) {
    ret = I2C_Transfer(i2c);
  }
  return ret;
}

#endif