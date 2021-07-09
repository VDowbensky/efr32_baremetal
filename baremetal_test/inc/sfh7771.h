/*
 * sfh7771.h
 *
 *  Created on: 27 03 2020
 *      Author: Tiras12
 */

#ifndef USER_SFH7771_H_
#define USER_SFH7771_H_

#include <stdint.h>
#include <stdbool.h>
#include "myi2c.h"

/** I2C device address for SFH 7771 */
#define SFH7771_ADDR      (0x38<<1)
//#define SFH7771_ADDR      (0x38)
//static I2CSPM_Init_TypeDef i2cInit = I2CSPM_INIT_SENSOR;
//extern I2CSPM_Init_TypeDef i2cInit;


#define SYSTEM_CONTROL    0x40 // R/W System Control
#define MODE_CONTROL      0x41 // R/W ALS and PS General Control
#define ALS_PS_CONTROL    0x42 // R/W ALS Gain and PS current Control
#define PERSISTENCE       0x43 // R/W PS Interrupt Persistence Control
#define PS_DATA_LSB       0x44 // R   Output data of PS measurement, LSB
#define PS_DATA_MSB       0x45 // R   Output data of PS measurement, MSB
#define ALS_VIS_DATA_LSB  0x46 // R   Output data of ALS_VIS measurement, LSB
#define ALS_VIS_DATA_MSB  0x47 // R   Output data of ALS_VIS measurement, MSB
#define ALS_IR_DATA_LSB   0x48 // R   Output data of ALS_IR measurement, LSB
#define ALS_IR_DATA_MSB   0x49 // R   Output data of ALS_IR measurement, MSB
#define INTERRUPT_CONTROL 0x4A // R/W Interrupt Control
#define PS_TH_LSB         0x4B // R/W PS interrupt upper threshold level, LSB
#define PS_TH_MSB         0x4C // R/W PS interrupt upper threshold level, MSB
#define PS_TL_LSB         0x4D // R/W PS interrupt lower threshold level, LSB
#define PS_TL_MSB         0x4E // R/W PS interrupt lower threshold level, MSB
#define ALS_VIS_TH_LSB    0x4F // R/W ALS_VIS interrupt upper threshold level, LSB
#define ALS_VIS_TH_MSB    0x50 // R/W ALS_VIS interrupt upper threshold level, MSB
#define ALS_VIS_TL_LSB    0x51 // R/W ALS_VIS interrupt lower threshold level, LSB
#define ALS_VIS_TL_MSB    0x52 // R/W ALS_VIS interrupt lower threshold level, MSB

bool sfh7771_Standby(void);
bool sfh7771_Data_(uint8_t *buf);
bool sfh7771_Data_2(uint8_t *buf);
bool sfh7771_SensorStart(void);
bool sfh7771_SensorDataBuf(uint8_t *buf);//debug

extern bool piron;


#endif /* USER_SFH7771_H_ */
