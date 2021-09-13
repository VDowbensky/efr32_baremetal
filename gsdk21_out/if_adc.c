#include "if_adc.h"



void IF_ADC_Calibrate(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  write_volatile_4(Peripherals::RAC_SET.RFENCTRL,0x8050);
  write_volatile_4(Peripherals::RAC_SET.IFADCCTRL,0x20000000);
  write_volatile_4(Peripherals::RAC.IFADCCAL,0x10);
  PROTIMER_DelayUs(100);
  write_volatile_4(Peripherals::RAC.RCTUNE,0);
  uVar3 = 0x200020;
  iVar2 = 6;
  do {
    write_volatile_4(Peripherals::RAC_SET.RCTUNE,uVar3);
    PROTIMER_DelayUs(100);
    uVar1 = read_volatile_4(Peripherals::RAC.IFADCCAL);
    if (-1 < (int)(uVar1 << 0x1a)) {
      write_volatile_4(Peripherals::RAC_CLR.RCTUNE,uVar3);
    }
    iVar2 = iVar2 + -1;
    uVar3 = uVar3 >> 1;
  } while (iVar2 != 0);
  uVar3 = read_volatile_4(Peripherals::RAC.RCTUNE);
  write_volatile_4(Peripherals::RAC.RCTUNE,uVar3 + 0x10004);
  write_volatile_4(Peripherals::RAC.IFADCCAL,0);
  write_volatile_4(Peripherals::RAC_CLR.IFADCCTRL,0x20000000);
  write_volatile_4(Peripherals::RAC_CLR.RFENCTRL,0x8050);
  return;
}


