#include "pti.o.h"



void RADIO_PTI_Init(RADIO_PTIInit_t *ptiInit)

{
  byte bVar1;
  GPIO_Port_TypeDef port;
  uint out;
  uint uVar2;
  
  if (ptiInit == (RADIO_PTIInit_t *)0x0) return;
  RADIOCMU_ClockEnable(0x63400,1);
  CMU_ClockEnable(cmuClock_GPIO,true);
  sniffBaudHz = ptiInit->baud;
  uVar2 = (uint)ptiInit->mode;
  FRC->SNIFFCTRL = 0xf8;
  FRC->ROUTELOC0 = (uint)ptiInit->dframeLoc << 0x10 | (uint)ptiInit->dclkLoc << 8 | (uint)ptiInit->doutLoc;
  if (uVar2 == 0) 
  {
    sniffMode = 2;
    FRC->ROUTEPEN = 7;
    GPIO_PinModeSet(ptiInit->dclkPort,(uint)ptiInit->dclkPin,gpioModePushPull,0);
    port = ptiInit->dframePort;
    bVar1 = ptiInit->dframePin;
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
      goto LAB_0000d710;
    }
    port = ptiInit->dframePort;
    FRC->ROUTEPEN = 5;
    bVar1 = ptiInit->dframePin;
    out = 0;
    sniffMode = uVar2;
  }
  GPIO_PinModeSet(port,(uint)bVar1,gpioModePushPull,out);
LAB_0000d710:
  GPIO_PinModeSet(ptiInit->doutPort,(uint)ptiInit->doutPin,gpioModePushPull,1);
}



void RADIO_PTI_Enable(void)

{
  uint32_t sniffbaud;
  
  sniffbaud = sniffBaudHz;
  if (sniffBaudHz != 0) sniffbaud = ((RADIOCMU_ClockFreqGet(0x63400) + (sniffBaudHz >> 1)) / sniffBaudHz - 1) * 0x100;
  BUS_RegMaskedSet(&RAC->SR3,0x40000000);
  FRC->SNIFFCTRL &= 0xffff00fc;
  FRC->SNIFFCTRL |= sniffbaud | sniffMode;
}




void RADIO_PTI_Disable(void)

{
  FRC->SNIFFCTRL &= 0xfffffffc;
  BUS_RegMaskedClear(&RAC->SR3,0x40000000);
}



void RADIO_PTI_AppendedInfoEnable(void)

{
  BUS_RegMaskedSet(&RAC->SR3,0x40000000);
}



void RADIO_PTI_AppendedInfoDisable(void)

{
  BUS_RegMaskedClear(&RAC->SR3,0x40000000);
}



void RADIO_PTI_AuxdataOutput(uint32_t auxdata)

{
  if (RAC->SR3 & 0x80000000) FRC->AUXDATA = auxdata;
}



void RADIO_PTI_AuxdataEnable(void)

{
  BUS_RegMaskedSet(&RAC->SR3,0x80000000);
}



void RADIO_PTI_AuxdataDisable(void)

{
  BUS_RegMaskedClear(&RAC->SR3,0x80000000);
}


