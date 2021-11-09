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
	EMU_DCDCInit_TypeDef dcdcInit = EMU_DCDCINIT_DEFAULT;
		
	dcdcInit.powerConfig = emuPowerConfig_DcdcToDvdd;
	dcdcInit.dcdcMode = emuDcdcMode_LowNoise;
	//dcdcInit.dcdcMode = emuDcdcMode_Bypass;
	dcdcInit.mVout = 1800;
	dcdcInit.em01LoadCurrent_mA = 100;
	dcdcInit.em234LoadCurrent_uA = 10;
	dcdcInit.maxCurrent_mA = 200;
	dcdcInit.anaPeripheralPower = emuDcdcAnaPeripheralPower_DCDC;
	dcdcInit.reverseCurrentControl = 160;
  EMU_DCDCInit(&dcdcInit);
	//EMU_DCDCPowerOff();
#if (MX || GN)
//  EMU_DCDCPowerOff();
#endif
  CMU_ClockSelectSet(cmuClock_HF, cmuSelect_HFXO);
	uint16_t t;
  t = *(uint16_t *)CTUNE_ADDR; 
	RADIO_SetCtune(t);
	RETARGET_SerialInit();
	Timing_DelayUs(10000);
	//print reset cause
	printf("\r\nStarting. Reset cause: 0x%X\r\n", RMU->RSTCAUSE);
	RMU->CMD = 1; //clear reset cause bit
	init_peripherals();
	init_radio();
	printf("RX on.\r\n");
	//stert receiving
	//RAIL_RfHalRxStart(0);
	//printf("Receiver on\r\n");
	cli_init();


	while(1)
	{
		process_cli();
		process_radio();
	}
}

void init_peripherals(void)
{
//GPIO
	CMU_ClockEnable(cmuClock_GPIO, true);
	leds_init();

   initLETIMER();
	 initADC();	 
	 TEMPDRV_Init();
}

