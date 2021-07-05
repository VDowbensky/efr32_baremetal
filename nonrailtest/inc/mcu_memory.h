#ifndef _MCU_MEM_
#define _MCU_MEM_

#include "em_chip.h"
#include "em_msc.h"
#include "em_core.h"

#define DEVID_ADDR 0x0FE00000 

void storedevid(uint32_t id);

#endif