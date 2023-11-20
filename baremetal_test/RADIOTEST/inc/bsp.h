#ifndef _BSP_H_
#define _BSP_H_

#include <stdint.h>
#include "mcu_memory.h"
#include "device.h"
#include "em_device.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "timer1.h"

void init_power_clk(void);
void init_board_specific(void);
void init_radio_specific(void);
void mic_on(void);
void mic_off(void);

#endif //_BSP_H_
