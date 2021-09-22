#include "pti.h"



void RADIO_PTI_Init(RADIO_PTIInit_t *pitInit)

{
  byte bVar1;
  GPIO_Port_TypeDef port;
  uint out;
  uint uVar2;
  
  if (pitInit == NULL) return;
  RADIOCMU_ClockEnable(0x63400,true);
  CMU_ClockEnable(cmuClock_GPIO,true);
  sniffBaudHz = pitInit->baud;
  uVar2 = (uint)pitInit->mode;
  FRC->SNIFFCTRL = 0xf8;
  FRC->ROUTELOC0,(uint)pitInit->dframeLoc << 0x10 | (uint)pitInit->dclkLoc << 8 | (uint)pitInit->doutLoc;
  if (uVar2 == 0) 
  {
    sniffMode = 2;
    FRC->ROUTEPEN = 7;
    GPIO_PinModeSet(pitInit->dclkPort,(uint)pitInit->dclkPin,gpioModePushPull,0);
    port = pitInit->dframePort;
    bVar1 = pitInit->dframePin;
    out = uVar2;
  }
  else 
  {
    if (uVar2 != 1) 
	{
      if (uVar2 == 2) 
	  {
        sniffMode = 5;
        FRC->ROUTEPEN = 1;
      }
      else 
	  {
        if (uVar2 == 3) 
		{
          FRC->ROUTEPEN = 0;
          sniffMode = 0;
          return;
        }
      }
      goto LAB_000066d8;
    }
    port = pitInit->dframePort;
    FRC->ROUTEPEN = 5;
    bVar1 = pitInit->dframePin;
    out = 0;
    sniffMode = uVar2;
  }
  GPIO_PinModeSet(port,(uint)bVar1,gpioModePushPull,out);
LAB_000066d8:
  GPIO_PinModeSet(pitInit->doutPort,(uint)pitInit->doutPin,gpioModePushPull,1);
}



void RADIO_PTI_AppendedInfoEnable(void)

{
  RAC->SR3 |= 0x40000000;
}



void RADIO_PTI_Enable(void)

{
  uint32_t uVar2;
  
  uVar2 = sniffBaudHz;
  if (sniffBaudHz != 0) uVar2 = ((RADIOCMU_ClockFreqGet(0x63400) + (sniffBaudHz >> 1)) / sniffBaudHz - 1) * 0x100;
  RADIO_PTI_AppendedInfoEnable();
  FRC->SNIFFCTRL &= 0xffff00fc;
  FRC->SNIFFCTRL  |= sniffMode | uVar2;
}



void RADIO_PTI_AppendedInfoDisable(void)

{
  RAC->SR3 &= 0xbfffffff;
}



void RADIO_PTI_Disable(void)

{
  FRC->SNIFFCTRL &= 0xfffffffc;
  RADIO_PTI_AppendedInfoDisable();
}



void RADIO_PTI_AuxdataOutput(uint32_t param_1)

{
  if (RAC->SR3 & 0x80000000) FRC->AUXDATA = param_1;
}



void RADIO_PTI_AuxdataEnable(void)

{
  RAC->SR3 |= 0x80000000;
}



void RADIO_PTI_AuxdataDisable(void)

{
  RAC->SR3 &= 0x7fffffff;
}


