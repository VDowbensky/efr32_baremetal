#include "if_adc.h"



void IF_ADC_Calibrate(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  BUS_RegMaskedSet(&RAC->RFENCTRL,0x8050);
  BUS_RegMaskedSet(&RAC->IFADCCTRL,0x20000000);
  RAC->IFADCCAL = 0x10;
  PHY_UTILS_DelayUs(100);
  RAC->RCTUNE = 0;
  uVar3 = 0x200020;
  iVar2 = 6;
  do 
  {
    BUS_RegMaskedSet(&RAC->RCTUNE,uVar3);
    PHY_UTILS_DelayUs(100);
    if (-1 < (int)(RAC->IFADCCAL << 0x1a)) BUS_RegMaskedClear(&RAC->RCTUNE,uVar3);
    iVar2 = iVar2 + -1;
    uVar3 = uVar3 >> 1;
  } while (iVar2 != 0);
  uVar3 = (RAC->RCTUNE);
  RAC->RCTUNE = uVar3 + 0x10004;
  RAC->IFADCCAL = 0;
  BUS_RegMaskedClear(&RAC->IFADCCTRL,0x20000000);
  BUS_RegMaskedClear(&RAC->RFENCTRL,0x8050);
}


