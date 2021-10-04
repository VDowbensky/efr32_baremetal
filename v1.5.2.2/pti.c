#include "pti.o.h"



void RADIO_PTI_Init(RADIO_PTIInit_t *ptiInit)

{
  byte bVar1;
  GPIO_Port_TypeDef port;
  uint out;
  uint uVar2;
  
  if (ptiInit == (RADIO_PTIInit_t *)0x0) {
    return;
  }
  RADIOCMU_ClockEnable(0x63400,1);
  CMU_ClockEnable(cmuClock_GPIO,true);
  sniffBaudHz = ptiInit->baud;
  uVar2 = (uint)ptiInit->mode;
  write_volatile_4(FRC->SNIFFCTRL,0xf8);
  write_volatile_4(FRC->ROUTELOC0,
                   (uint)ptiInit->dframeLoc << 0x10 | (uint)ptiInit->dclkLoc << 8 |
                   (uint)ptiInit->doutLoc);
  if (uVar2 == 0) {
    sniffMode = 2;
    write_volatile_4(FRC->ROUTEPEN,7);
    GPIO_PinModeSet(ptiInit->dclkPort,(uint)ptiInit->dclkPin,gpioModePushPull,0);
    port = ptiInit->dframePort;
    bVar1 = ptiInit->dframePin;
    out = uVar2;
  }
  else {
    if (uVar2 != 1) {
      if (uVar2 == 2) {
        sniffMode = 5;
        write_volatile_4(FRC->ROUTEPEN,1);
      }
      else {
        if (uVar2 == 3) {
          write_volatile_4(FRC->ROUTEPEN,0);
          sniffMode = 0;
          return;
        }
      }
      goto LAB_0000d710;
    }
    port = ptiInit->dframePort;
    write_volatile_4(FRC->ROUTEPEN,5);
    bVar1 = ptiInit->dframePin;
    out = 0;
    sniffMode = uVar2;
  }
  GPIO_PinModeSet(port,(uint)bVar1,gpioModePushPull,out);
LAB_0000d710:
  GPIO_PinModeSet(ptiInit->doutPort,(uint)ptiInit->doutPin,gpioModePushPull,1);
  return;
}



void RADIO_PTI_Enable(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = (FRC->SNIFFCTRL);
  uVar3 = sniffBaudHz;
  if (sniffBaudHz != 0) {
    iVar2 = RADIOCMU_ClockFreqGet(0x63400);
    uVar3 = ((iVar2 + (sniffBaudHz >> 1)) / sniffBaudHz - 1) * 0x100;
  }
  BUS_RegMaskedSet(&RAC->SR3,0x40000000);
  write_volatile_4(FRC->SNIFFCTRL,uVar3 | uVar1 & 0xffff00fc | sniffMode);
  return;
}




void RADIO_PTI_Disable(void)

{
  uint uVar1;
  
  uVar1 = (FRC->SNIFFCTRL);
  write_volatile_4(FRC->SNIFFCTRL,uVar1 & 0xfffffffc);
  BUS_RegMaskedClear(&RAC->SR3,0x40000000);
  return;
}



void RADIO_PTI_AppendedInfoEnable(void)

{
  write_volatile_4(Peripherals::RAC_SET.SR3,0x40000000);
  return;
}



void RADIO_PTI_AppendedInfoDisable(void)

{
  write_volatile_4(Peripherals::RAC_CLR.SR3,0x40000000);
  return;
}



void RADIO_PTI_AuxdataOutput(uint32_t auxdata)

{
  FRC *pFVar1;
  bool bVar2;
  
  pFVar1 = (FRC *)read_volatile_4(Peripherals::RAC.SR3);
  bVar2 = (int)pFVar1 < 0;
  if (bVar2) {
    pFVar1 = &Peripherals::FRC;
  }
  if (bVar2) {
    pFVar1->AUXDATA = auxdata;
  }
  return;
}



void RADIO_PTI_AuxdataEnable(void)

{
  write_volatile_4(Peripherals::RAC_SET.SR3,0x80000000);
  return;
}



void RADIO_PTI_AuxdataDisable(void)

{
  write_volatile_4(Peripherals::RAC_CLR.SR3,0x80000000);
  return;
}


