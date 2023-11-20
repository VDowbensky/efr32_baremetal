#include <stdio.h>
#include "bsp.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_usart.h"
#include "retargetserial.h"
#include "command_interpreter.h"
#include "app_cli.h"
#include "tempdrv.h"
#include "adc.h"
#include "leds.h"
#include "radio_init.h"
#include "radio_proc.h"

void init_peripherals(void);

int main(void)
{
  CHIP_Init();
	init_power_clk(); //in bsp.c
	RETARGET_SerialInit();
	Timing_DelayUs(10000);
	//print reset cause
	printf("\r\nStarting. Reset cause: 0x%X\r\n", RMU->RSTCAUSE);
	printf("\r\n%s\r\n", DEVICE_STRING_NAME);
	printf("HW: %d SW: %d.%d\r\n", HW_VERSION, SW_VERSION, SW_SUBVERSION);
	RMU->CMD = 1; //clear reset cause bit
	init_peripherals();
	read_userpage();
	if(userdata_buf[0x42] != HW_MAGIC_NUMBER)
	{
		RADIO_InitConfigStructure();
		printf("Init user memory.\r\n");
	  store_config(); //this must be only one time!
		printf("User memory written.\r\n");
		NVIC_SystemReset();
	}
	read_config();
	RADIO_Config();
	init_radio_specific(); //in bsp.c
	cli_init();

	while(1)
	{
		process_cli();
		process_radio();
	}
}

void init_peripherals(void)
{
	 CMU_ClockEnable(cmuClock_GPIO, true);
	 leds_init();
   initLETIMER();
	 initADC();	 
	 TEMPDRV_Init();
	 init_board_specific(); //in bsp.c
}

