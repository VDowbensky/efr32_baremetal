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
#include "radio_proc.h"

#if (MX || GN)
#include "myspi.h"
#endif
#if GN
#include "atten.h"
#endif
#if(XPAD || XSHIFT || XMOTION)
#include "myi2c.h"
#endif
#if (XSHIFT)
#include "si7210.h"
#endif
#if (XMOTION || XPAD)
#include "sfh7771.h"
#endif




void init_peripherals(void);

int main(void)
{
  CHIP_Init();
	EMU_DCDCInit_TypeDef dcdcInit = EMU_DCDCINIT_DEFAULT;
		
	dcdcInit.powerConfig = emuPowerConfig_DcdcToDvdd;
	dcdcInit.dcdcMode = emuDcdcMode_LowNoise;
	//dcdcInit.dcdcMode = emuDcdcMode_Bypass;
	dcdcInit.mVout = 1800;
	dcdcInit.em01LoadCurrent_mA = 50;
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
	RETARGET_SerialInit();
	printf("\r\nHello, Lamer!\r\n");
	init_peripherals();
	init_radio();
	printf("Let's crack EFR32 radio!\r\n");
	cli_init();


	while(1)
	{
		process_cli();
		//process_radio();
	}
}

void init_peripherals(void)
{
//GPIO
	CMU_ClockEnable(cmuClock_GPIO, true);
	leds_init();
//SPI
#if (MX || GN)
	init_spi();
#endif
#if GN
	init_atten();
#endif
//I2C
#if (XSHIFT || XPAD || XMOTION)
	init_i2c();
#endif
	
#if XSHIFT

    if(Si7210_SensorInit(&si7210adr))
    {
        //Si7210_Set_sw_op(SI7210_OP_DEFAULT);
        //Si7210_Set_sw_hyst(SI7210_HYST_DEFAULT);
        printf("SI7210 OK. I2CADDR = 0x%X\r\n", si7210adr >> 1);
    }
    else
     {
        printf("SI7210 fail. I2CADDR = 0x%X\r\n", si7210adr >> 1);
     }
#endif
#if (XMOTION || XPAD)
	if(sfh7771_SensorStart())
  {
      printf("SFH7771 OK.\r\n");
  }
  else
   {
      printf("SFH7771 fail.\r\n");
   }

#endif	
   initLETIMER();
	 initADC();	 
	 TEMPDRV_Init();
}

