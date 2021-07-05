#ifndef _PHY_UTILS_H_
#define _PHY_UTILS_H_

#include "em_device.h"
#include <stdint.h>
#include <stdbool.h>
uint8_t PHY_UTILS_ConvertHexToAscii(uint8_t value);
uint32_t PHY_UTILS_CheckParity(uint32_t value);
uint32_t PHY_UTILS_BitsetIsSet(int param_1,uint32_t param_2);
void PHY_UTILS_BitsetClearAll(uint32_t *param_1,int param_2);
int PHY_UTILS_BitsetLowestSetBit(int param_1,int param_2);
int PHY_UTILS_BitsetHighestSetBit(int param_1,int param_2);
void PHY_UTILS_DelayUs(uint32_t us);
uint32_t PHY_UTILS_genPRBS9Data(uint8_t *param_1,uint32_t param_2,int param_3);

#endif
