#include "device_specific.h"

#if KEYBOARD

#include "lp5024.h"
//#include "sl_component_catalog.h"


uint32_t i2c_Write_Register(I2C_TypeDef *i2c,uint8_t addr, uint8_t reg, uint8_t data);
I2C_TransferReturn_TypeDef i2c_Read_Register(I2C_TypeDef *i2c,uint8_t addr, uint8_t reg, uint8_t *data);

void dcdc_on(void);
void dcdc_off(void);
void lp5024_on(void);
void lp5024_off(void);
bool lp5024_init(void);

//extern I2CSPM_Init_TypeDef i2cInit;

bool lp5024_data_buf(uint8_t *buf);
bool lp5024_set_color(uint8_t led, uint8_t color);//led[0..23] color[0..255]
bool lp5024_set_all(uint8_t color);//color[0..255]
bool lp5024_set_all2(uint8_t *buf);
bool lp5024_set_BRIGHTNESS(uint8_t value);

bool buttons_get(uint8_t *buf);
void cbGpioIrq(void);

uint8_t ledbuf[32] = {0};
uint8_t btnbuf[8];

bool lp5024_init(void)
{
  I2C_TransferReturn_TypeDef ret=0;
  ret |= i2c_Write_Register(SL_I2CSPM_INST_PERIPHERAL, LP5024_ADDR, RESET_REG, 0xFF);
  ret |= i2c_Write_Register(SL_I2CSPM_INST_PERIPHERAL, LP5024_ADDR, DEVICE_CONFIG0, 0x40);//def=0x00
  ret |= i2c_Write_Register(SL_I2CSPM_INST_PERIPHERAL, LP5024_ADDR, DEVICE_CONFIG1, 0x3C);//def=0x3C
  //ret |= i2c_Write_Register(i2cInit.port, i2cAddr, LED_CONFIG0, 0xFF);//def=0x00

  if (ret != i2cTransferDone) {
    return false;
  }
  return true;
}

void lp5024_on(void)
{
  i2c_Write_Register(SL_I2CSPM_INST_PERIPHERAL, LP5024_ADDR, DEVICE_CONFIG0, 0x40);
}

void lp5024_off(void)
{
  i2c_Write_Register(SL_I2CSPM_INST_PERIPHERAL, LP5024_ADDR, DEVICE_CONFIG0, 0x00);
}

bool lp5024_data_buf(uint8_t *buf)
{
  I2C_TransferSeq_TypeDef seq;
  I2C_TransferReturn_TypeDef ret;
  uint8_t i2c_write_data[1];
  seq.addr = LP5024_ADDR;
  seq.flags = I2C_FLAG_WRITE_READ;
  /* Select register to start reading from */
  i2c_write_data[0] = 0x00;//reg;
  seq.buf[0].data = i2c_write_data;
  seq.buf[0].len = 1;
  /* Select length of data to be read */
  seq.buf[1].data = buf;
  seq.buf[1].len = 0x26;
  ret = I2CSPM_Transfer(SL_I2CSPM_INST_PERIPHERAL, &seq);
  if (ret != i2cTransferDone)
  {
    return false;
  }
  return true;
}

bool lp5024_set_color(uint8_t led, uint8_t color)//led[0..23] color[0..255]
{
  I2C_TransferReturn_TypeDef ret=0;
  led += OUT0_COLOR;
  ret |= i2c_Write_Register(SL_I2CSPM_INST_PERIPHERAL, LP5024_ADDR, led, color);
  //ret |= sfh7771_Sleep(i2cInit.port, i2cAddr);
  if (ret != i2cTransferDone) {
    return false;
  }
  return true;
}

bool lp5024_set_all(uint8_t color)//color[0..255]
{
  uint8_t buf[24];
  for (uint8_t a=0; a < 24; ++a)
    buf[a] = color;

  I2C_TransferSeq_TypeDef seq;
  I2C_TransferReturn_TypeDef ret;
  uint8_t i2c_write_data[1];
  seq.addr = LP5024_ADDR;
  seq.flags = I2C_FLAG_WRITE_WRITE;
  /* Select register to start reading from */
  i2c_write_data[0] = OUT0_COLOR;
  seq.buf[0].data = i2c_write_data;
  seq.buf[0].len = 1;
  /* Select length of data to be read */
  seq.buf[1].data = buf;
  seq.buf[1].len = 24;
  ret = I2CSPM_Transfer(SL_I2CSPM_INST_PERIPHERAL, &seq);
  if (ret != i2cTransferDone)
  {
    return false;
  }
  return true;
}

bool lp5024_set_all2(uint8_t *buf)
{
  I2C_TransferSeq_TypeDef seq;
  I2C_TransferReturn_TypeDef ret;
  uint8_t i2c_write_data[1];
  seq.addr = LP5024_ADDR;
  seq.flags = I2C_FLAG_WRITE_WRITE;
  /* Select register to start reading from */
  i2c_write_data[0] = OUT0_COLOR;
  seq.buf[0].data = i2c_write_data;
  seq.buf[0].len = 1;
  /* Select length of data to be read */
  seq.buf[1].data = buf;
  seq.buf[1].len = 24;
  ret = I2CSPM_Transfer(SL_I2CSPM_INST_PERIPHERAL, &seq);
  if (ret != i2cTransferDone)
  {
    return false;
  }
  return true;
}

bool lp5024_set_BRIGHTNESS(uint8_t value)
{
  uint8_t buf[8];
  for (uint8_t a=0; a < 8; ++a)
    buf[a] = value;

  I2C_TransferSeq_TypeDef seq;
  I2C_TransferReturn_TypeDef ret;
  uint8_t i2c_write_data[1];
  seq.addr = LP5024_ADDR;
  seq.flags = I2C_FLAG_WRITE_WRITE;
  /* Select register to start reading from */
  i2c_write_data[0] = LED0_BRIGHTNESS;
  seq.buf[0].data = i2c_write_data;
  seq.buf[0].len = 1;
  /* Select length of data to be read */
  seq.buf[1].data = buf;
  seq.buf[1].len = 8;
  ret = I2CSPM_Transfer(SL_I2CSPM_INST_PERIPHERAL, &seq);
  if (ret != i2cTransferDone)
  {
    return false;
  }
  return true;
}

bool buttons_get(uint8_t *buf)
{
  I2C_TransferSeq_TypeDef seq;
  I2C_TransferReturn_TypeDef ret;
  uint8_t i2c_write_data[1];
  seq.addr = BUTTONS_ADDR;
  seq.flags = I2C_FLAG_WRITE_READ;//I2C_FLAG_WRITE_READ I2C_FLAG_READ
  /* Select register to start reading from */
  i2c_write_data[0] = 0x00;
  seq.buf[0].data = i2c_write_data;
  seq.buf[0].len = 1;
  /* Select length of data to be read */
  seq.buf[1].data = buf;
  seq.buf[1].len = 3;
  ret = I2CSPM_Transfer(SL_I2CSPM_INST_PERIPHERAL, &seq);
  if (ret != i2cTransferDone)
  {
    return false;
  }
  return true;
}


void dcdc_on(void)
{
#ifdef KB_OLD_VERSION
  //GPIO_PinModeSet(DCDC_PORT, DCDC_PIN, gpioModePushPull, 0);
  GPIO_PinOutClear(DCDC_PORT, DCDC_PIN);
#else
  //GPIO_PinModeSet(DCDC_PORT, DCDC_PIN, gpioModePushPull, 1);
  GPIO_PinOutSet(DCDC_PORT, DCDC_PIN);
#endif
}
void dcdc_off(void)
{
#ifdef KB_OLD_VERSION
  //GPIO_PinModeSet(DCDC_PORT, DCDC_PIN, gpioModePushPull, 1);
  GPIO_PinOutSet(DCDC_PORT, DCDC_PIN);
#else
  //GPIO_PinModeSet(DCDC_PORT, DCDC_PIN, gpioModePushPull, 0);
  GPIO_PinOutClear(DCDC_PORT, DCDC_PIN);
#endif
}


/**************************************************************************
* @brief
* Writes register in the xxx sensor.
* @param[in] i2c
* The I2C peripheral to use (not used).
* @param[in] addr
* The I2C address of the sensor.
* @param[in] data
* The data to write to the sensor.
* @param[in] reg
* The register address to write to in the sensor.
* @return
* Returns zero on success. Otherwise returns error codes based on the I2CDRV.
*****************************************************************************/
uint32_t i2c_Write_Register(I2C_TypeDef *i2c,uint8_t addr, uint8_t reg, uint8_t data)
{
  I2C_TransferSeq_TypeDef seq;
  I2C_TransferReturn_TypeDef ret;
  uint8_t i2c_write_data[2];
  uint8_t i2c_read_data[1];
  seq.addr = addr;
  seq.flags = I2C_FLAG_WRITE;
  /* Select register and data to write */
  i2c_write_data[0] = reg;
  i2c_write_data[1] = data;
  seq.buf[0].data = i2c_write_data;
  seq.buf[0].len = 2;
  seq.buf[1].data = i2c_read_data;
  seq.buf[1].len = 0;
  ret = I2CSPM_Transfer(i2c, &seq);
  if (ret != i2cTransferDone) {
    return (uint32_t) ret;
  }
  return (uint32_t) 0;
}
/**************************************************************************
* @brief
* Reads register from the xxx sensor.
* @param[in] i2c
* The I2C peripheral to use (not used).
* @param[in] addr
* The I2C address of the sensor.
* @param[out] data
* The data read from the sensor.
* @param[in] reg
* The register address to read from in the sensor.
* @return
* Returns number of bytes read on success. Otherwise returns error codes based on the I2CDRV.
*****************************************************************************/
I2C_TransferReturn_TypeDef i2c_Read_Register(I2C_TypeDef *i2c,uint8_t addr, uint8_t reg, uint8_t *data)
{
  I2C_TransferSeq_TypeDef seq;
  I2C_TransferReturn_TypeDef ret;
  uint8_t i2c_write_data[1];
  seq.addr = addr;
  seq.flags = I2C_FLAG_WRITE_READ;
  /* Select register to start reading from */
  i2c_write_data[0] = reg;
  seq.buf[0].data = i2c_write_data;
  seq.buf[0].len = 1;
  /* Select length of data to be read */
  seq.buf[1].data = data;
  seq.buf[1].len = 1;
  ret = I2CSPM_Transfer(i2c, &seq);
  if (ret != i2cTransferDone)
  {
    *data = 0xff;
  }
  return ret;
}

void cbGpioIrq(void)
{
  //GPIO_IntClear(0xFFFF);
  buttons_get(btnbuf);
  printf ("KEY_PRESS: 0x%X\r\n", btnbuf[0]);
}

#endif
