#include "bsp.h"
#include "radio_phy.h"
//#include "ITDS.h"

void init_power_clk(void)
{
	EMU_DCDCInit_TypeDef dcdcInit = EMU_DCDCINIT_DEFAULT;
		
	dcdcInit.powerConfig = emuPowerConfig_DcdcToDvdd;
	dcdcInit.dcdcMode = emuDcdcMode_LowNoise;
	dcdcInit.dcdcMode = emuDcdcMode_Bypass;
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
	GPIO_PinModeSet(MIC_EN_PORT, MIC_EN_PIN, gpioModePushPull, 1); //mic off
	initTimer1(MICSAMPLEFREQ);
}

void init_radio_specific(void)
{
	
}

void mic_on(void)
{
  GPIO_PinOutSet(MIC_EN_PORT, MIC_EN_PIN);
}

void mic_off(void)
{
  GPIO_PinOutClear(MIC_EN_PORT, MIC_EN_PIN);
}
