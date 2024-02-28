#include "bsp.h"
#include "radio_phy.h"

void init_power_clk(void)
{
	EMU_DCDCInit_TypeDef dcdcInit = EMU_DCDCINIT_DEFAULT;
		
	dcdcInit.powerConfig = emuPowerConfig_DcdcToDvdd;
	dcdcInit.dcdcMode = emuDcdcMode_LowNoise;
	dcdcInit.mVout = 1800;
	dcdcInit.em01LoadCurrent_mA = 100;
	dcdcInit.em234LoadCurrent_uA = 10;
	dcdcInit.maxCurrent_mA = 200;
	dcdcInit.anaPeripheralPower = emuDcdcAnaPeripheralPower_DCDC;
	dcdcInit.reverseCurrentControl = 160;
  EMU_DCDCInit(&dcdcInit);

  CMU_ClockSelectSet(cmuClock_HF, cmuSelect_HFXO);
	radio_SetCtune(*(uint16_t *)CTUNE_ADDR);
}

void init_board_specific(void)
{

}

void init_radio_specific(void)
{
	
}