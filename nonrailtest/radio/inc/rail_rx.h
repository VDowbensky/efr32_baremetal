#ifndef _RAIL_RX_H_
#define _RAIL_RX_H_

#include "em_device.h"
#include <stdint.h>
#include <stdbool.h>

uint8_t RAIL_RxConfig(uint8_t cbToEnable, bool appendedInfoEnable);
uint8_t RAIL_RxStart(uint8_t channel);

#endif
