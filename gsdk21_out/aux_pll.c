#include "aux_pll.h"



void AUXPLL_AuxSettingsPllLoopback(void)

{
  RAC->AUXCTRL | 0x3000000;
  BUS_RegMaskedSet(&RAC->SGLNAMIXCTRL,0x4000000);
}



void AUXPLL_AuxSettingsPaLoopback(void)

{
  BUS_RegMaskedClear(&RAC->SYNTHCTRL,4);
  BUS_RegMaskedSet(&RAC->AUXENCTRL,4);
}



void AUXPLL_Stop(void)

{
  BUS_RegMaskedClear(&RAC->AUXCTRL,0x8007ca);
  BUS_RegMaskedClear(&RAC->AUXENCTRL,1);
  BUS_RegMaskedClear(&RAC->SGLNAMIXCTRL,0x4000000);
  BUS_RegMaskedClear(&RAC->AUXENCTRL,4);
}



undefined AUXPLL_ConvertAuxLoDivToRegVal(int param_1)

{
  if (param_1 - 2U < 0x17) uVar1 = *(undefined *)(param_1 + 0x101b8);
  else return 0;
}



void AUXPLL_Configure(uint param_1,undefined4 param_2,int param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  
  BUS_RegMaskedClear(&RAC->AUXENCTRL,1);
  uVar1 = (RAC->AUXCTRL);
  write_volatile_4(RAC->AUXCTRL,uVar1 & 0xff01ffcf | 0xe80030);
  uVar1 = (Peripherals::SYNTH.DIVCTRL);
  iVar2 = AUXPLL_ConvertAuxLoDivToRegVal(param_2);
  write_volatile_4(Peripherals::SYNTH.DIVCTRL,uVar1 & 0xffc0ffff | iVar2 << 0x10);
  uVar1 = (RAC->AUXCTRL);
  write_volatile_4(RAC->AUXCTRL,uVar1 & 0xfffe00ff | param_4 << 0xb | param_3 << 8);
  uVar1 = (Peripherals::SYNTH.AUXFREQ);
  write_volatile_4(Peripherals::SYNTH.AUXFREQ,uVar1 & 0xffffff80 | param_1);
  BUS_RegMaskedSet(&RAC->AUXCTRL,0x4a);
  BUS_RegMaskedSet(&RAC->AUXENCTRL,1);
  BUS_RegMaskedSet(&RAC->AUXCTRL,0x80);
  BUS_RegMaskedSet(&RAC->AUXCTRL,0x800000);
  write_volatile_4(Peripherals::SYNTH_SET.AUXVCDACCTRL,0x10);
  BUS_RegMaskedClear(&RAC->AUXCTRL,8);
  BUS_RegMaskedSet(&RAC->AUXCTRL,0x800004);
  PROTIMER_DelayUs(1000);
  do {
    write_volatile_4(Peripherals::SYNTH.CMD,0x80);
    write_volatile_4(Peripherals::SYNTH.CMD,0x100);
    do {
      uVar1 = (Peripherals::SYNTH.STATUS);
    } while ((int)(uVar1 << 0x14) < 0);
    uVar1 = (Peripherals::SYNTH.STATUS);
  } while ((int)(uVar1 << 0x11) < 0);
  BUS_RegMaskedSet(&RAC->AUXCTRL,8);
  write_volatile_4(Peripherals::SYNTH_CLR.AUXVCDACCTRL,0x10);
  write_volatile_4(Peripherals::SYNTH.CMD,0x40);
  uVar1 = (RAC->AUXCTRL);
  write_volatile_4(RAC->AUXCTRL,uVar1 & 0xff7ffffb | 0x800000);
  return;
}



int AUXPLL_Start(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = SystemHFXOClockGet();
  iVar2 = param_3 * (uVar1 / param_4);
  if (iVar2 != -1) {
    AUXPLL_Configure(param_3,param_4,param_1,param_2);
    if (param_1 == 2) {
      AUXPLL_AuxSettingsPllLoopback();
    }
    else {
      if (param_1 != 3) {
        AUXPLL_Stop();
        return -1;
      }
      AUXPLL_AuxSettingsPaLoopback();
    }
  }
  return iVar2;
}


