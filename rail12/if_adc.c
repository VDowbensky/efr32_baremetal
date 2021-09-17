#include "if_adc.h"



void IF_ADC_Calibrate(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = (RAC->RFENCTRL);
  write_volatile_4(RAC->RFENCTRL,uVar3 | 0x8050);
  uVar3 = (RAC->IFADCCTRL);
  write_volatile_4(RAC->IFADCCTRL,uVar3 | 0x20000000);
  write_volatile_4(RAC->IFADCCAL,0x10);
  PHY_UTILS_DelayUs(100);
  write_volatile_4(RAC->RCTUNE,0);
  iVar2 = 6;
  uVar3 = 0x200020;
  do {
    uVar1 = (RAC->RCTUNE);
    write_volatile_4(RAC->RCTUNE,uVar1 | uVar3);
    PHY_UTILS_DelayUs(100);
    uVar1 = (RAC->IFADCCAL);
    if (-1 < (int)(uVar1 << 0x1a)) {
      uVar1 = (RAC->RCTUNE);
      write_volatile_4(RAC->RCTUNE,uVar1 & ~uVar3);
    }
    iVar2 = iVar2 + -1;
    uVar3 = uVar3 >> 1;
  } while (iVar2 != 0);
  uVar3 = (RAC->RCTUNE);
  write_volatile_4(RAC->RCTUNE,uVar3 + 0x10004);
  write_volatile_4(RAC->IFADCCAL,0);
  uVar3 = (RAC->IFADCCTRL);
  write_volatile_4(RAC->IFADCCTRL,uVar3 & 0xdfffffff);
  uVar3 = (RAC->RFENCTRL);
  write_volatile_4(RAC->RFENCTRL,uVar3 & 0xffff7faf);
  return;
}


