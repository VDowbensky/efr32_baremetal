#include "pti.h"



void RADIO_PTI_Init(RADIO_PTIInit_t *pitInit)

{
  byte bVar1;
  GPIO_Port_TypeDef port;
  uint out;
  uint uVar2;
  
  if (pitInit == (RADIO_PTIInit_t *)0x0) 
  {
    return;
  }
  RADIOCMU_ClockEnable(0x63400,true);
  CMU_ClockEnable(cmuClock_GPIO,true);
  sniffBaudHz = pitInit->baud;
  uVar2 = (uint)pitInit->mode;
  write_volatile_4(FRC->SNIFFCTRL,0xf8);
  write_volatile_4(FRC->ROUTELOC0,
                   (uint)pitInit->dframeLoc << 0x10 | (uint)pitInit->dclkLoc << 8 | (uint)pitInit->doutLoc);
  if (uVar2 == 0) 
  {
    sniffMode = 2;
    write_volatile_4(FRC->ROUTEPEN,7);
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
        write_volatile_4(FRC->ROUTEPEN,1);
      }
      else 
	  {
        if (uVar2 == 3) 
		{
          write_volatile_4(FRC->ROUTEPEN,0);
          sniffMode = 0;
          return;
        }
      }
      goto LAB_000066d8;
    }
    port = pitInit->dframePort;
    write_volatile_4(FRC->ROUTEPEN,5);
    bVar1 = pitInit->dframePin;
    out = 0;
    sniffMode = uVar2;
  }
  GPIO_PinModeSet(port,(uint)bVar1,gpioModePushPull,out);
LAB_000066d8:
  GPIO_PinModeSet(pitInit->doutPort,(uint)pitInit->doutPin,gpioModePushPull,1);
  return;
}



void RADIO_PTI_AppendedInfoEnable(void)

{
  uint uVar1;
  
  uVar1 = (RAC->SR3);
  write_volatile_4(RAC->SR3,uVar1 | 0x40000000);
  return;
}



void RADIO_PTI_Enable(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (FRC->SNIFFCTRL);
  uVar2 = sniffBaudHz;
  if (sniffBaudHz != 0) 
  {
    uVar2 = RADIOCMU_ClockFreqGet(0x63400);
    uVar2 = ((uVar2 + (sniffBaudHz >> 1)) / sniffBaudHz - 1) * 0x100;
  }
  RADIO_PTI_AppendedInfoEnable();
  write_volatile_4(FRC->SNIFFCTRL,uVar2 | uVar1 & 0xffff00fc | sniffMode);
  return;
}



void RADIO_PTI_AppendedInfoDisable(void)

{
  uint uVar1;
  
  uVar1 = (RAC->SR3);
  write_volatile_4(RAC->SR3,uVar1 & 0xbfffffff);
  return;
}



void RADIO_PTI_Disable(void)

{
  uint uVar1;
  
  uVar1 = (FRC->SNIFFCTRL);
  write_volatile_4(FRC->SNIFFCTRL,uVar1 & 0xfffffffc);
  RADIO_PTI_AppendedInfoDisable();
  return;
}



void RADIO_PTI_AuxdataOutput(uint param_1)

{
  FRC *pFVar1;
  bool bVar2;
  
  pFVar1 = (FRC *)(RAC->SR3);
  bVar2 = (int)pFVar1 < 0;
  if (bVar2) 
  {
    pFVar1 = &Peripherals::FRC;
  }
  if (bVar2) 
  {
    pFVar1->AUXDATA = param_1;
  }
  return;
}



void RADIO_PTI_AuxdataEnable(void)

{
  uint uVar1;
  
  uVar1 = (RAC->SR3);
  write_volatile_4(RAC->SR3,uVar1 | 0x80000000);
  return;
}



void RADIO_PTI_AuxdataDisable(void)

{
  uint uVar1;
  
  uVar1 = (RAC->SR3);
  write_volatile_4(RAC->SR3,uVar1 & 0x7fffffff);
  return;
}


