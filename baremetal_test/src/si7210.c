#include "bsp.h"

#include "si7210.h"

bool Si7210_Stop(void);
bool Si7210_Data_(int16_t *value);
bool Si7210_Set_sw_op(uint8_t value);
bool Si7210_Set_sw_hyst(uint8_t value);
bool Si7210_Get_sw_op(uint8_t * value);
bool Si7210_Get_sw_hyst(uint8_t * value);
bool Si7210_SensorInit(uint8_t *addr);
bool Si7210_SensorDataBuf(uint8_t *buf);//debug
I2C_TransferReturn_TypeDef Si72xx_WakeUp(I2C_TypeDef *i2c, uint8_t i2cAddr);
uint32_t Si72xx_Write_Register(I2C_TypeDef *i2c,uint8_t addr, uint8_t reg, uint8_t data);
I2C_TransferReturn_TypeDef Si72xx_Read_Register(I2C_TypeDef *i2c,uint8_t addr, uint8_t reg, uint8_t *data);
uint32_t Si72xx_Read_Data(I2C_TypeDef *i2c,uint8_t addr,int16_t *data);
uint32_t Si72xx_Sleep (I2C_TypeDef *i2c, uint8_t addr);
uint32_t Si72xx_Set_200mT_Range (I2C_TypeDef *i2c,uint8_t addr);
float Si72xx_ReadFieldValue(I2C_TypeDef *i2c, uint8_t i2cAddr, uint8_t range200mT);
bool Si7210_Detect(I2C_TypeDef *i2c, uint8_t *addr);
uint32_t Si72xx_Read_OTP (I2C_TypeDef *i2c,uint8_t addr, uint8_t otpAddr, uint8_t *data);
void ReadField(void);
void cbAlertIrq(void);
uint8_t si7210phase = 0;

uint8_t si7210adr = SI7210_ADDR;
float FieldValue;

bool Si7210_Stop(void)
{
  //I2C_TypeDef *i2c = SL_I2CSPM_INST_PERIPHERAL;
  I2C_TransferReturn_TypeDef ret;
  //uint8_t i2cAddr = (si7210adr << 1);

  //wake up the si7200
  ret = Si72xx_WakeUp(I2C_PER, si7210adr);
  ret |= Si72xx_Write_Register(I2C_PER, si7210adr, SI72XX_CTRL3, 0x00);
  ret |= Si72xx_Write_Register(I2C_PER, si7210adr, SI72XX_POWER_CTRL, USESTORE_MASK|STOP_MASK|SLEEP_MASK);
  if (ret != i2cTransferDone) {
    return false;
  }
  return true;
}

bool Si7210_Data_(int16_t *value)
{
  //I2C_TypeDef *i2c = i2cInit.port;
  I2C_TransferReturn_TypeDef ret;
  //uint8_t i2cAddr = (si7210adr << 1);
  uint8_t read;
  uint8_t flag;

  ret = Si72xx_WakeUp(I2C_PER, si7210adr);
  ret |= Si72xx_Write_Register(I2C_PER, si7210adr, SI72XX_POWER_CTRL, ONEBURST_MASK);
  //ret |= Si72xx_Read_Data(i2c, i2cAddr, value);

  ret |= Si72xx_Read_Register(I2C_PER,si7210adr,SI72XX_DSPSIGM,&read);
  flag = read>>7;
  *value = (((uint16_t)read)&0x7f)<<8;
  ret |= Si72xx_Read_Register(I2C_PER,si7210adr,SI72XX_DSPSIGL,&read);
  *value |= read;
  *value = *value - 16384;

  ret |= Si72xx_Sleep(I2C_PER, si7210adr);

  if (flag == 0) {
    //*value = 0xFFFF;
    return false;
  }
  if (ret != i2cTransferDone) {
    *value = 0xFFFF;
    return false;
  }
  return true;
}

bool Si7210_Set_sw_op(uint8_t value)
{
  //I2C_TypeDef *i2c = i2cInit.port;
  I2C_TransferReturn_TypeDef ret;
  //uint8_t i2cAddr = (si7210adr << 1);
  uint8_t read;

  ret = Si72xx_WakeUp(I2C_PER, si7210adr);
  //ret |= Si72xx_Read_Register(SL_I2CSPM_INST_PERIPHERAL,si7210adr,SI72XX_CTRL1,&read);
  //read &= 0x80;
  //read |= (value&0x7F);
  //ret |= Si72xx_Write_Register(SL_I2CSPM_INST_PERIPHERAL, si7210adr, SI72XX_CTRL1, read);
  ret |= Si72xx_Write_Register(I2C_PER, si7210adr, SI72XX_CTRL1, value);
  ret |= Si72xx_Sleep(I2C_PER, si7210adr);

  if (ret != i2cTransferDone) {
    return false;
  }
  return true;
}

bool Si7210_Set_sw_hyst(uint8_t value)
{
  //I2C_TypeDef *i2c = i2cInit.port;
  I2C_TransferReturn_TypeDef ret;
  //uint8_t i2cAddr = (si7210adr << 1);
  uint8_t read;

  ret = Si72xx_WakeUp(I2C_PER, si7210adr);
  ret |= Si72xx_Read_Register(I2C_PER,si7210adr,SI72XX_CTRL2,&read);
  read &= 0xC0;
  read |= (value&0x3F);
  ret |= Si72xx_Write_Register(I2C_PER, si7210adr, SI72XX_CTRL2, read);
  ret |= Si72xx_Sleep(I2C_PER, si7210adr);

  if (ret != i2cTransferDone) {
    return false;
  }
  return true;
}

bool Si7210_Get_sw_op(uint8_t * value)
{
  //I2C_TypeDef *i2c = i2cInit.port;
  I2C_TransferReturn_TypeDef ret;
  //uint8_t i2cAddr = (si7210adr << 1);
  uint8_t read;

  ret = Si72xx_WakeUp(I2C_PER, si7210adr);
  ret |= Si72xx_Read_Register(I2C_PER,si7210adr,SI72XX_CTRL1,&read);
  ret |= Si72xx_Sleep(I2C_PER, si7210adr);
  *value = read&0x7F;

  if (ret != i2cTransferDone) {
    return false;
  }
  return true;
}

bool Si7210_Get_sw_hyst(uint8_t * value)
{
  //I2C_TypeDef *i2c = i2cInit.port;
  I2C_TransferReturn_TypeDef ret;
  //uint8_t i2cAddr = (si7210adr << 1);
  uint8_t read;

  ret = Si72xx_WakeUp(I2C_PER, si7210adr);
  ret |= Si72xx_Read_Register(I2C_PER,si7210adr,SI72XX_CTRL2,&read);
  ret |= Si72xx_Sleep(I2C_PER, si7210adr);
  *value = read&0x3F;

  if (ret != i2cTransferDone) {
    return false;
  }
  return true;
}

bool Si7210_SensorInit(uint8_t *addr)
{
  //CMU_ClockEnable(cmuClock_GPIO, true);
  //I2CSPM_Init(&i2cInit);
  //configure ALERT input line
  GPIO_PinModeSet(SI7210_ALERT_PORT, SI7210_ALERT_PIN, gpioModeInput, 1);
  //configure alert interrupt
  //GPIO_ExtIntConfig(SI7210_ALERT_PORT, SI7210_ALERT_PIN,  SI7210_ALERT_INT_NO, true, false, false);
  //NVIC_ClearPendingIRQ(GPIO_EVEN_IRQn);
  //NVIC_EnableIRQ(GPIO_EVEN_IRQn);
  //NVIC_ClearPendingIRQ(GPIO_ODD_IRQn);
  //NVIC_EnableIRQ(GPIO_ODD_IRQn);
  //GPIOINT_CallbackRegister(SI7210_ALERT_INT_NO, (GPIOINT_IrqCallbackPtr_t)cbAlertIrq);
  return Si7210_Detect(I2C_PER, addr);
}

bool Si7210_SensorDataBuf(uint8_t *buf)//debug
{
  I2C_TransferReturn_TypeDef ret;
  //uint8_t i2cAddr = (si7210adr << 1);

  ret = Si72xx_WakeUp(I2C_PER, si7210adr);
  for (uint8_t a = 0xC0, i=0; a <= 0xD0; ++a, ++i) {
    ret |= Si72xx_Read_Register(I2C_PER, si7210adr, a, &buf[i]);
  }
  ret |= Si72xx_Sleep(I2C_PER, si7210adr);
  if (ret != i2cTransferDone) {
    return false;
  }
  return true;
}

I2C_TransferReturn_TypeDef Si72xx_WakeUp(I2C_TypeDef *i2c, uint8_t i2cAddr)
{
  I2C_TransferSeq_TypeDef seq;
  I2C_TransferReturn_TypeDef ret;
  uint8_t i2c_write_data[1];
  uint8_t i2c_read_data[1];
  seq.addr = i2cAddr;
  seq.flags = I2C_FLAG_WRITE;
  /* Select register and data to write */
  seq.buf[0].data = i2c_write_data;
  seq.buf[0].len = 0;
  seq.buf[1].data = i2c_read_data;
  seq.buf[1].len = 0;
  ret = I2CSPM_Transfer(i2c, &seq);
  return ret;
}

uint32_t Si72xx_Write_Register(I2C_TypeDef *i2c,uint8_t addr, uint8_t reg, uint8_t data)
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

I2C_TransferReturn_TypeDef Si72xx_Read_Register(I2C_TypeDef *i2c,uint8_t addr, uint8_t reg, uint8_t *data)
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

//To read the output data:
uint32_t Si72xx_Read_Data(I2C_TypeDef *i2c,uint8_t addr,int16_t *data)
{
  uint8_t read;
  uint8_t flag;
  uint32_t result;
  //int32_t field;
  result = Si72xx_Read_Register(i2c,addr,SI72XX_DSPSIGM,&read);
  flag = read>>7;
  *data = (((uint16_t)read)&0x7f)<<8;
  result |= Si72xx_Read_Register(i2c,addr,SI72XX_DSPSIGL,&read);
  *data |= read;
  *data = *data - 16384;
  if (flag == 0)
  {
    result = SI72XX_ERROR_NODATA;
  }
  return result;
}

uint32_t Si72xx_Sleep (I2C_TypeDef *i2c, uint8_t addr)
{
  uint32_t result=0;
  uint8_t read;
  result = Si72xx_Read_Register(i2c, addr, SI72XX_CTRL3, &read);//0xC9
  //read = read & 0xFC;//slFast=0, slTimeena=0;
  read = read | (1<<0);//slTimeena=1;
  //read = (15<<2) | (1<<0);//sw_tamper = 3968, slTimeena=1;
  //read = (0<<2) | (1<<0);//sw_tamper = 2048, slTimeena=1;
  result = Si72xx_Write_Register(i2c, addr, SI72XX_CTRL3, read);
  result |= Si72xx_Read_Register(i2c, addr, SI72XX_POWER_CTRL, &read);//0xC4
  read = read & 0x89;
  read = read | USESTORE_MASK | (0<<0);//Usestore<<3 | sleep<<0;
  result |= Si72xx_Write_Register(i2c, addr, SI72XX_POWER_CTRL, read);
  return result;
}

uint32_t Si72xx_Set_200mT_Range (I2C_TypeDef *i2c,uint8_t addr)
{
  uint8_t data;
  uint32_t result;
  uint8_t srcAddr = 0x27;
  result = Si72xx_Read_OTP(i2c, addr, srcAddr++, &data);
  result |= Si72xx_Write_Register(i2c, addr, SI72XX_A0, data);
  result |= Si72xx_Read_OTP(i2c, addr, srcAddr++, &data);
  result |= Si72xx_Write_Register(i2c, addr, SI72XX_A1, data);
  result |= Si72xx_Read_OTP(i2c, addr, srcAddr++, &data);
  result |= Si72xx_Write_Register(i2c, addr, SI72XX_A2, data);
  result |= Si72xx_Read_OTP(i2c, addr, srcAddr++, &data);
  result |= Si72xx_Write_Register(i2c, addr, SI72XX_A3, data);
  result |= Si72xx_Read_OTP(i2c, addr, srcAddr++, &data);
  result |= Si72xx_Write_Register(i2c, addr, SI72XX_A4, data);
  result |= Si72xx_Read_OTP(i2c, addr, srcAddr++, &data);
  result |= Si72xx_Write_Register(i2c, addr, SI72XX_A5, data);
  return result;
}

float Si72xx_ReadFieldValue(I2C_TypeDef *i2c, uint8_t i2cAddr, uint8_t range200mT)
{
  //int32_t mT;
  float mT;
  int16_t data;
  uint32_t result;
  //uint8_t flag;
  //wake up the si7200
  result = Si72xx_WakeUp(i2c, i2cAddr);
  result |= Si72xx_Write_Register(i2c, i2cAddr, SI72XX_POWER_CTRL, ONEBURST_MASK);
  if (range200mT) {
    //result |= Si72xx_Set_200mT_Range(i2c, i2cAddr);
  }
  result |= Si72xx_Read_Data(i2c, i2cAddr, &data);
  if (range200mT == 0) {
    //mT = data * 125 / 10; //convert to mT*1000
      mT = data*0.00125f;
  } else {
    //mT = data * 125 / 100; //convert to mT*1000
      mT = data*0.0125f;
  }
  //go back to sleep
  result |= Si72xx_Sleep(i2c, i2cAddr);
  return mT;
}

bool Si7210_Detect(I2C_TypeDef *i2c, uint8_t *addr)
{
  I2C_TransferReturn_TypeDef ret;
  uint8_t read;
  si7210adr = 0;

  for (uint8_t a = (SI7210_ADDR >> 1); a < ((SI7210_ADDR >> 1) + 4); ++a) {
    ret = Si72xx_WakeUp(i2c, (a << 1));
    ret |= Si72xx_Read_Register(i2c, (a << 1), SI72XX_HREVID, &read);
    if (ret == i2cTransferDone && (read & 0xf0) == 0x10) {
      si7210adr = a;
      *addr = si7210adr;
      //ret |= Si72xx_Write_Register(i2c, (a << 1), SI72XX_ARAUTOINC, 1);
      ret |= Si72xx_Read_Register(i2c, (a << 1), SI72XX_CTRL1, &read);//0xC6
      read &= 0x7F;  //sw_low4field=0; инвертировать состояние Out выхода
      ret |= Si72xx_Write_Register(i2c, (a << 1), SI72XX_CTRL1, read);
      //ret |= Si72xx_Write_Register(SL_I2CSPM_INST_PERIPHERAL, si7210adr, SI72XX_CTRL1, SI7210_OP_DEFAULT);
      //ret |= Si72xx_Write_Register(SL_I2CSPM_INST_PERIPHERAL, si7210adr, SI72XX_CTRL2, SI7210_HYST_DEFAULT);
      //read = (0<<6) | ((1<<3)|1);//sw_fieldpolsel=0, sw_hyst=0x9(+-72);
      //read = SI7210_HYST_DEFAULT;
      //ret |= Si72xx_Write_Register(i2c, (a << 1), SI72XX_CTRL2, read);
      ret |= Si72xx_Sleep(i2c, (a << 1));
      si7210adr <<= 1;
      break;
    }
  }
  if (si7210adr == 0) {
    return false;
  }
  if (ret != i2cTransferDone) {
    return false;
  }
  //ReadField();
  //GPIO_ExtIntConfig(SI7210_ALERT_PORT, SI7210_ALERT_PIN,  SI7210_ALERT_INT_NO, true, false, true);//rising
  return true;
}

//To read the OTP the part must be awake first then:
uint32_t Si72xx_Read_OTP (I2C_TypeDef *i2c,uint8_t addr, uint8_t otpAddr, uint8_t *data)
{
  uint8_t read;
  uint32_t result;
  result = Si72xx_Read_Register(i2c, addr, SI72XX_OTP_CTRL, &read);
  if (read & OTP_BUSY_MASK) {
    return SI72XX_ERROR_BUSY;
  }
  result |= Si72xx_Write_Register(i2c, addr, SI72XX_OTP_ADDR, otpAddr);
  result |= Si72xx_Write_Register(i2c, addr, SI72XX_OTP_CTRL,
      OTP_READ_EN_MASK);
  result |= Si72xx_Read_Register(i2c, addr, SI72XX_OTP_DATA, &read);
  *data = read;
  return result;
}

void ReadField(void)
{
  FieldValue = Si72xx_ReadFieldValue(I2C_PER, si7210adr, 0);
  if (si7210phase == 0)
    {
      //Si72xx_Write_Register(SL_I2CSPM_INST_PERIPHERAL, si7210adr, SI72XX_CTRL1, SI7210_OP_DEFAULT | 0x80);
      //Si7210_Set_sw_op(SI7210_OP_DEFAULT | 0x80);
      Si7210_Set_sw_op(SI7210_OP_DEFAULT & 0x7F);
      //GPIO_ExtIntConfig(SI7210_ALERT_PORT, SI7210_ALERT_PIN,  SI7210_ALERT_INT_NO, false, true, true);//falling
      si7210phase = 1;
    }
  else
    {
      //Si72xx_Write_Register(SL_I2CSPM_INST_PERIPHERAL, si7210adr, SI72XX_CTRL1, SI7210_OP_DEFAULT & 0x7F);
      //Si7210_Set_sw_op(SI7210_OP_DEFAULT & 0x7F);
      Si7210_Set_sw_op(SI7210_OP_DEFAULT | 0x80);
      //GPIO_ExtIntConfig(SI7210_ALERT_PORT, SI7210_ALERT_PIN,  SI7210_ALERT_INT_NO, true, false, true);//rising
      si7210phase = 0;
    }

}

//threshold = (16 + sw_op 3 : 0 ) × 2sw_op 6:4
//threshold = 0, when sw_op = 127

void cbAlertIrq(void)
{
  //uint8_t read;
  //clear flag
  GPIO_IntClear(0xFFFF);
  //read field value
  //FieldValue = ReadField();
  //invert alert interrupt
  //Si72xx_Read_Register(SL_I2CSPM_INST_PERIPHERAL, si7210adr, SI72XX_CTRL1, &read);//0xC6
  ReadField();
}

