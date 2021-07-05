/*
 * sfh7771.h
 *
 *  Created on: 27 03 2020
 *      Author: Tiras12
 */

#ifndef USER_SFH7771_H_
#define USER_SFH7771_H_

/*
ALS - Ambient Light Sensor
PS  - Proximity Sensor
 */

bool sfh7771_Standby(void);
bool sfh7771_Data_(uint8_t *buf);
bool sfh7771_Data_2(uint8_t *buf);
bool sfh7771_SensorStart(void);
void sfh7771_i2cInit(void);
bool sfh7771_SensorDataBuf(uint8_t *buf);//debug


#endif /* USER_SFH7771_H_ */
