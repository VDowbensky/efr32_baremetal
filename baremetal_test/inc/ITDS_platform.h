/**
 ***************************************************************************************************
 * This file is part of Sensors SDK:
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

#ifndef _WE_PLATTFORM_H
#define _WE_PLATTFORM_H

 /**         Includes         */

#include <stdint.h>
#include <stdbool.h>
#include "myi2c.h"


#define WE_SUCCESS   0
#define WE_FAIL     -1

/**         Functions definition         */



/* Initializes i2c periphheral for communicaiton with a sensor. either use I2CInit() or SpiInit(). */
int8_t I2CInit(int address);

/* Read a register's content */
//int8_t ReadReg(uint8_t RegAdr, int NumByteToRead, uint8_t *Data);
int8_t ReadReg(uint8_t RegAdr, uint32_t NumByteToRead, uint8_t *Data);
/* write a register's content */
//int8_t WriteReg(uint8_t RegAdr, int NumByteToWrite, uint8_t *Data);
int8_t WriteReg(uint8_t RegAdr, uint32_t NumByteToWrite, uint8_t *Data);


#endif /* _WE_PLATTFORM_H */
/**         EOF         */
