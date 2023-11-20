#ifndef _MCU_MEM_
#define _MCU_MEM_

#include "em_chip.h"
#include "em_msc.h"
#include "em_core.h"
#include "em_device.h"
#include "RADIO_config.h"

#define DEVID_ADDR 0x0FE00000 
#define CTUNE_ADDR 0x0FE00100 

void storedevid(uint32_t id);
void read_userpage(void);
void write_userpage(void);
void store_config(void);
void read_config(void);

extern uint32_t userdata_buf[];

#endif
