#ifndef _SI7210_H_
#define _SI7210_H_

//#include "em_device.h"
#include "em_cmu.h"
#include "em_gpio.h"
#include "gpiointerrupt.h"
#include "myi2c.h"
#include "stdlib.h"
#include "stdio.h"

#define SI7210_ADDR       (0x30 << 1)
//https://www.silabs.com/sensors/magnetic/si7210   Si7210-02-IV   IВІC Address=0x31   SOT23-5

//uint8_t si7210adr;

//static I2CSPM_Init_TypeDef i2cInit = I2CSPM_INIT_SENSOR;
//extern I2CSPM_Init_TypeDef i2cInit;

#define OTP_BUSY_MASK 1
#define OTP_READ_EN_MASK 2
#define NUM_HALL_DEVICES 3
#define STOP_MASK 2
#define SLTIMEENA_MASK 1
#define SW_TAMPER_MASK 0xFC
#define SL_FAST_MASK 2
#define SLEEP_MASK 1
#define ONEBURST_MASK 4
#define USESTORE_MASK 8

#define SI72XX_ERROR_BUSY 4
#define SI72XX_ERROR_NODATA 5

/** I2C registers for Si72xx */
#define SI72XX_HREVID 0xC0
#define SI72XX_DSPSIGM 0xC1
#define SI72XX_DSPSIGL 0xC2
#define SI72XX_DSPSIGSEL 0xC3
#define SI72XX_POWER_CTRL 0xC4
#define SI72XX_ARAUTOINC 0xC5
#define SI72XX_CTRL1 0xC6
#define SI72XX_CTRL2 0xC7
#define SI72XX_SLTIME 0xC8
#define SI72XX_CTRL3 0xC9
#define SI72XX_A0 0xCA
#define SI72XX_A1 0xCB
#define SI72XX_A2 0xCC
#define SI72XX_CTRL4 0xCD
#define SI72XX_A3 0xCE
#define SI72XX_A4 0xCF
#define SI72XX_A5 0xD0
#define SI72XX_OTP_ADDR 0xE1
#define SI72XX_OTP_DATA 0xE2
#define SI72XX_OTP_CTRL 0xE3

extern bool Si7210_Stop(void);
extern bool Si7210_Data_(int16_t *value);
extern bool Si7210_Set_sw_op(uint8_t value);
extern bool Si7210_Set_sw_hyst(uint8_t value);
extern bool Si7210_Get_sw_op(uint8_t * value);
extern bool Si7210_Get_sw_hyst(uint8_t * value);
extern bool Si7210_SensorInit(uint8_t *addr);
extern bool Si7210_SensorDataBuf(uint8_t *buf);//debug
extern void ReadField(void);

extern float FieldValue;

extern uint8_t si7210adr;

#endif
