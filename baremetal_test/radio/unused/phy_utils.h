#ifndef _PHY_UTILS_H_
#define _PHY_UTILS_H_

#include "em_device.h"
#include <stdint.h>
#include <stdbool.h>
uint8_t PHY_UTILS_ConvertHexToAscii(uint8_t value);
uint32_t PHY_UTILS_CheckParity(uint32_t value);
void PHY_UTILS_DelayUs(uint32_t us);

#endif
