#ifndef _MYI2C_H_
#define _MYI2C_H_

#include "em_i2c.h"
#include "em_gpio.h"
#include "em_cmu.h"
#include "bsp.h"

#define I2CSPM_TRANSFER_TIMEOUT 300000

void init_i2c(void);
I2C_TransferReturn_TypeDef I2CSPM_Transfer(I2C_TypeDef *i2c, I2C_TransferSeq_TypeDef *seq);

#endif