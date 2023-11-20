/**
 ***************************************************************************************************
 * This file is part of WE sensors SDK:
 * https://www.we-online.com/sensors, https://github.com/WurthElektronik/Sensors-SDK
 *
 * THE SOFTWARE INCLUDING THE SOURCE CODE IS PROVIDED “AS IS”. YOU ACKNOWLEDGE THAT WÜRTH ELEKTRONIK
 * EISOS MAKES NO REPRESENTATIONS AND WARRANTIES OF ANY KIND RELATED TO, BUT NOT LIMITED
 * TO THE NON-INFRINGEMENT OF THIRD PARTIES’ INTELLECTUAL PROPERTY RIGHTS OR THE
 * MERCHANTABILITY OR FITNESS FOR YOUR INTENDED PURPOSE OR USAGE. WÜRTH ELEKTRONIK EISOS DOES NOT
 * WARRANT OR REPRESENT THAT ANY LICENSE, EITHER EXPRESS OR IMPLIED, IS GRANTED UNDER ANY PATENT
 * RIGHT, COPYRIGHT, MASK WORK RIGHT, OR OTHER INTELLECTUAL PROPERTY RIGHT RELATING TO ANY
 * COMBINATION, MACHINE, OR PROCESS IN WHICH THE PRODUCT IS USED. INFORMATION PUBLISHED BY
 * WÜRTH ELEKTRONIK EISOS REGARDING THIRD-PARTY PRODUCTS OR SERVICES DOES NOT CONSTITUTE A LICENSE
 * FROM WÜRTH ELEKTRONIK EISOS TO USE SUCH PRODUCTS OR SERVICES OR A WARRANTY OR ENDORSEMENT
 * THEREOF
 *
 * THIS SOURCE CODE IS PROTECTED BY A LICENSE.
 * FOR MORE INFORMATION PLEASE CAREFULLY READ THE LICENSE AGREEMENT FILE LOCATED
 * IN THE ROOT DIRECTORY OF THIS DRIVER PACKAGE.
 *
 * COPYRIGHT (c) 2020 Würth Elektronik eiSos GmbH & Co. KG
 *
 ***************************************************************************************************
 **/

#include "ITDS_platform.h"
//#include <wiringPiI2C.h>
//#include <wiringPiSPI.h>
#include <stdio.h>
#include <string.h>
//#include <pthread.h>
//#include <unistd.h>
#include "ITDS.h"

#define DUMMY 0x00


/**
* @brief  Initialize the I2C Interface
* @param  I2C address
* @retval Error Code
*/
int8_t I2CInit(int address)
{
//  if ((i2c_handle = wiringPiI2CSetup(address)) < 0)
//  {
//    fprintf(stdout, "wiringPiI2CSetup Error\n");
//    return WE_FAIL;
//  }

  return WE_SUCCESS;
}


/**
* @brief   Read data starting from the addressed register
* @param  -RegAdr : the register address to read from
*         -NumByteToRead : number of bytes to read
*         -pointer Data : the address store the data
* @retval Error Code
*/
//I2C_TransferReturn_TypeDef Si72xx_Read_Register(I2C_TypeDef *i2c,uint8_t addr, uint8_t reg, uint8_t *data)
//int8_t ReadReg(uint8_t RegAdr, int NumByteToRead, uint8_t *Data)
//{
//  int ret = 0;
//
//  if (NumByteToRead > 1)
//  {
//
//    /*Write the start address to initiate the read*/
//    ret = wiringPiI2CWrite(i2c_handle, RegAdr);
//    if (ret == -1)
//    {
//      return WE_FAIL;
//    }
//    else
//    {
//      /* Read the necessary number of bytes to an array */
//      read(i2c_handle, Data, NumByteToRead);
//    }
//  }
//  else
//  {
//    ret = wiringPiI2CReadReg8(i2c_handle, RegAdr);
//    if (ret == -1)
//    {
//      return WE_FAIL;
//    }
//    else
//    {
//      Data[0] = (uint8_t)ret;
//    }
//  }
//
//  return WE_SUCCESS;
//}

int8_t ReadReg(uint8_t RegAdr, uint32_t NumByteToRead, uint8_t *Data)
{
  I2C_TransferSeq_TypeDef seq;
  I2C_TransferReturn_TypeDef ret;
  uint8_t i2c_write_data[1];
  seq.addr = ITDS_ADDRESS;
  seq.flags = I2C_FLAG_WRITE_READ;
  /* Select register to start reading from */
  i2c_write_data[0] = RegAdr;
  seq.buf[0].data = i2c_write_data;
  seq.buf[0].len = 1;
  /* Select length of data to be read */
  seq.buf[1].data = Data;
  seq.buf[1].len = NumByteToRead;
  ret = I2CSPM_Transfer(I2C_PER, &seq);
  if (ret != i2cTransferDone)
  {
    *Data = 0xff;
    return WE_FAIL;
  }
  return WE_SUCCESS;
}

/**
* @brief  Write data starting from the addressed register
* @param  -RegAdr : Address to write in
*         -NumByteToWrite : number of bytes to write
*         -pointer Data : Address of the data to be written
* @retval Error Code
*/
//uint32_t Si72xx_Write_Register(I2C_TypeDef *i2c,uint8_t addr, uint8_t reg, uint8_t data)
//int8_t WriteReg(uint8_t RegAdr, int NumByteToWrite, uint8_t *Data)
//{
//  if (0x00 != wiringPiI2CWriteReg8(i2c_handle, RegAdr, Data[0]))
//  {
//    return WE_FAIL;
//  }
//  else
//  {
//    int i;
//    for (i = 1; i < NumByteToWrite; i++)
//    {
//      if (0x00 != wiringPiI2CWrite(i2c_handle, Data[i]))
//      {
//        return WE_FAIL;
//      }
//    }
//  }
//
//  return WE_SUCCESS;
//}

int8_t WriteReg(uint8_t RegAdr, uint32_t NumByteToWrite, uint8_t *Data)
{
  uint32_t i;
  I2C_TransferSeq_TypeDef seq;
  I2C_TransferReturn_TypeDef ret;
  uint8_t i2c_write_data[16];
  uint8_t i2c_read_data[16];

  seq.addr = ITDS_ADDRESS;
  seq.flags = I2C_FLAG_WRITE;
  /* Select register and data to write */
  i2c_write_data[0] = RegAdr;
  //i2c_write_data[1] = data;
  for(i = 1; i < (NumByteToWrite + 1); i++) i2c_write_data[i] = Data[i - 1];
  seq.buf[0].data = i2c_write_data;
  seq.buf[0].len = NumByteToWrite + 1; //2;
  seq.buf[1].data = i2c_read_data;
  seq.buf[1].len = 0;
  ret = I2CSPM_Transfer(I2C_PER, &seq);
  if (ret != i2cTransferDone) return WE_FAIL;
  return WE_SUCCESS;
}


/**         EOF         */
