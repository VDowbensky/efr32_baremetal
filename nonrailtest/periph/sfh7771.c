/*
 * sfh7771.c
 *
 *  Created on: 27 03 2020
 *      Author: Tiras12
 */
#include "em_cmu.h"
#include "sl_i2cspm.h"
#include "stdlib.h"
#include "stdio.h"
//#include "system.h"
#include "sl_i2cspm_instances.h"
#include "sl_i2cspm_inst_config.h"


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


//This function is an example of how to send the wakeup to the sfh7771 on an EFM32 MCU. Only the address byte is sent.
I2C_TransferReturn_TypeDef sfh7771_WakeUp(I2C_TypeDef *i2c, uint8_t i2cAddr)
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
/**************************************************************************
* @brief
* Writes register in the sfh7771 sensor.
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
uint32_t sfh7771_Write_Register(I2C_TypeDef *i2c,uint8_t addr, uint8_t reg, uint8_t data)
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
* Reads register from the sfh7771 sensor.
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
I2C_TransferReturn_TypeDef sfh7771_Read_Register(I2C_TypeDef *i2c,uint8_t addr, uint8_t reg, uint8_t *data)
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

////To read the output data:
//uint32_t sfh7771_Read_Data(I2C_TypeDef *i2c,uint8_t addr,int16_t *data)
//{
////	uint8_t read;
////	uint8_t flag;
//	uint32_t result=0;
////	//int32_t field;
////	result = sfh7771_Read_Register(i2c,addr,sfh7771_DSPSIGM,&read);
////	flag = read>>7;
////	*data = (((uint16_t)read)&0x7f)<<8;
////	result |= sfh7771_Read_Register(i2c,addr,sfh7771_DSPSIGL,&read);
////	*data |= read;
////	*data = *data - 16384;
////	if (flag == 0)
////	{
////		result = sfh7771_ERROR_NODATA;
////	}
//	return result;
//}
bool sfh7771_Standby(void)
{
	I2C_TransferReturn_TypeDef ret;
	//standby
	ret = sfh7771_Write_Register(SL_I2CSPM_INST_PERIPHERAL, SFH7771_ADDR, MODE_CONTROL, 0x00);
	if (ret != i2cTransferDone) {
		return false;
	}
	return true;
}

bool sfh7771_Data_(uint8_t *buf)
{
	//for(uint8_t i=0x44,a=0; i<=0x49; ++i,++a){
	//	ret |= sfh7771_Read_Register(i2c,i2cAddr,i,&buf[a]);
	//}
	//iprintf(" SFH7771 s%d  PS=%d  ALS_VIS=%d  ALS_IR=%d", status, buf[0]|buf[1]<<8, buf[2]|buf[3]<<8, buf[4]|buf[5]<<8);

	I2C_TransferReturn_TypeDef ret;
	uint8_t i2cAddr = SFH7771_ADDR;

	ret = 0;//sfh7771_WakeUp(i2cInit.port, i2cAddr);
	for (uint8_t a = 0x44, i=0; a <= 0x49; ++a, ++i) {
		ret |= sfh7771_Read_Register(SL_I2CSPM_INST_PERIPHERAL, i2cAddr, a, &buf[i]);
	}
	//ret |= sfh7771_Sleep(i2cInit.port, i2cAddr);
	if (ret != i2cTransferDone) {
		return false;
	}
	return true;
}
bool sfh7771_Data_2(uint8_t *buf)//�������� ������ ����� �����
{
	I2C_TransferSeq_TypeDef seq;
	I2C_TransferReturn_TypeDef ret;
	uint8_t i2c_write_data[1];
	seq.addr = SFH7771_ADDR;
	seq.flags = I2C_FLAG_WRITE_READ;
	i2c_write_data[0] = PS_DATA_LSB;
	seq.buf[0].data = i2c_write_data;
	seq.buf[0].len = 1;
	seq.buf[1].data = buf;
	seq.buf[1].len = 7;
	ret = I2CSPM_Transfer(SL_I2CSPM_INST_PERIPHERAL, &seq);
	if (ret != i2cTransferDone) {
		return false;
	}
	return true;
}

bool sfh7771_SensorStart(void)
{
	//I2C_TypeDef *i2c = i2cInit.port;
	I2C_TransferReturn_TypeDef ret;
	uint8_t read;
	uint8_t i2cAddr = SFH7771_ADDR;
	//printf("Init SFH7771.\r\n");
	//ret = sfh7771_WakeUp(i2c, i2cAddr);
	ret = sfh7771_Read_Register(SL_I2CSPM_INST_PERIPHERAL, i2cAddr, SYSTEM_CONTROL, &read);
	//printf("ret0=%d\r\n", ret);
	if (ret == i2cTransferDone && ((read & 0x3F) == 0x09)) {
		ret |= sfh7771_Write_Register(SL_I2CSPM_INST_PERIPHERAL, i2cAddr, SYSTEM_CONTROL, 0x80);//�������� �� ����������� ���������
		ret |= sfh7771_Write_Register(SL_I2CSPM_INST_PERIPHERAL, i2cAddr, INTERRUPT_CONTROL, 0x02);
		ret |= sfh7771_Write_Register(SL_I2CSPM_INST_PERIPHERAL, i2cAddr, ALS_VIS_TH_LSB, 0);
		ret |= sfh7771_Write_Register(SL_I2CSPM_INST_PERIPHERAL, i2cAddr, ALS_VIS_TH_MSB, 0);
		//ret |= sfh7771_Write_Register(i2c, i2cAddr, ALS_PS_CONTROL, 0);//0x2B
		//������ ��������� ������������
		ret |= sfh7771_Write_Register(SL_I2CSPM_INST_PERIPHERAL, i2cAddr, MODE_CONTROL, 0x05);// 3-50ms 5-100ms A-400ms
	}
	if (ret != i2cTransferDone) {
	  //printf("ret1=%d\r\n", ret);
		return false;
	}
	return true;
}

void sfh7771_i2cInit(void)
{
  sl_i2cspm_init_instances();
}

bool sfh7771_SensorDataBuf(uint8_t *buf)//debug
{
	I2C_TransferReturn_TypeDef ret;
	uint8_t i2cAddr = SFH7771_ADDR;

	ret = 0;//sfh7771_WakeUp(i2cInit.port, i2cAddr);
	for (uint8_t a = 0x40, i=0; a <= 0x52; ++a, ++i) {
		ret |= sfh7771_Read_Register(SL_I2CSPM_INST_PERIPHERAL, i2cAddr, a, &buf[i]);
	}
	//ret |= sfh7771_Sleep(i2cInit.port, i2cAddr);
	if (ret != i2cTransferDone) {
		return false;
	}
	return true;
}



//	bool ret;
//	ret = sfh7771_SensorInit();
//	ret |= sfh7771_Standby();
//	emberAfCorePrintln("i2c %s", (ret ? "ok" : "error"));
//	if(ret)
//		emberEventControlSetActive(eventLight);
//	if(ret)
//	{
//		uint8_t buf[20];
//		sfh7771_SensorDataBuf(buf);
//		for (uint8_t a = 0x40, i=0; a <= 0x52; ++a, ++i)
//		{
//			emberAfCorePrintln("i2c adr0x%x=0x%x", a, buf[i]);
//		}
//		sfh7771_Standby();
//	}
