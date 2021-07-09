#include "pti.h"
#include <stdbool.h>
#include "em_bus.h"
#include "em_assert.h"


void RADIO_PTI_Init(byte *param_1)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_1 == (byte *)0x0) {
    return;
  }
  RADIOCMU_ClockEnable(0x63400,1); //10,12,13,17,18
  CMU_ClockEnable(0x82500,1); //8,10,13,19
  sniffBaudHz = *(undefined4 *)(param_1 + 4);
  uVar4 = (uint)*param_1;
  FRC->SNIFFCTRL = 0xf8;
  FRC->ROUTELOC0 = (uint)param_1[0xe] << 0x10 | (uint)param_1[0xb] << 8 | (uint)param_1[8];
  if (uVar4 == 0) {
    sniffMode = 2;
    FRC->ROUTEPEN = 7;
    GPIO_PinModeSet(param_1[0xc],param_1[0xd],4,0);
    bVar1 = param_1[0xf];
    bVar2 = param_1[0x10];
    uVar3 = uVar4;
  }
  else {
    if (uVar4 != 1) {
      if (uVar4 == 2) {
        sniffMode = 5;
        FRC->ROUTEPEN = 1;
      }
      else {
        if (uVar4 == 3) {
          FRC->ROUTEPEN = 0;
          sniffMode = 0;
          return;
        }
      }
      goto LAB_00010090;
    }
    bVar1 = param_1[0xf];
    FRC->ROUTEPEN = 5;
    bVar2 = param_1[0x10];
    uVar3 = 0;
    sniffMode = uVar4;
  }
  GPIO_PinModeSet(bVar1,bVar2,4,uVar3);
LAB_00010090:
  GPIO_PinModeSet(param_1[9],param_1[10],4,1);
  return;
}



void RADIO_PTI_AppendedInfoEnable(void)

{
  RAC->SR3 |= 0x40000000;
}



void RADIO_PTI_Enable(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = read_volatile_4(FRC->SNIFFCTRL);
  uVar3 = sniffBaudHz;
  if (sniffBaudHz != 0) 
  {
    //iVar2 = RADIOCMU_ClockFreqGet(0x63400);
    uVar3 = ((RADIOCMU_ClockFreqGet(0x63400) + (sniffBaudHz >> 1)) / sniffBaudHz - 1) * 0x100;
  }
  RADIO_PTI_AppendedInfoEnable();
  FRC->SNIFFCTRL = uVar3 | FRC->SNIFFCTRL & 0xffff00fc | sniffMode;
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



void RADIO_PTI_AuxdataOutput(uint param_1)

{
  FRC *pFVar1;
  bool bVar2;
  
  pFVar1 = (FRC *)RAC->SR3;
  bVar2 = (int)pFVar1 < 0;
  if (bVar2) {
    pFVar1 = &FRC;
  }
  if (bVar2) {
    pFVar1->AUXDATA = param_1;
  }
  return;
}



void RADIO_PTI_AuxdataEnable(void)

{
	RAC->SR3 |= 0x80000000;
}



void RADIO_PTI_AuxdataDisable(void)

{
	RAC->SR3 &= 0x7fffffff;
}


