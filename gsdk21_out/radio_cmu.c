#include "radio_cmu.h"



void RADIOCMU_ClockEnable(int param_1,int param_2)

{
  uint uVar1;
  CMU *pCVar2;
  uint *puVar3;
  
  uVar1 = (uint)(param_1 << 0x14) >> 0x1c;
  if (uVar1 == 1) {
    pCVar2 = &Peripherals::CMU;
  }
  else {
    if (uVar1 != 4) {
      CMU_ClockEnable();
      return;
    }
    pCVar2 = (CMU *)0x400e40c8;
  }
  if (param_2 == 0) {
    puVar3 = &pCVar2[0x2192e].CALCTRL;
  }
  else {
    puVar3 = (uint *)&pCVar2[0x325c5].field_0x78;
  }
  *puVar3 = 1 << ((uint)(param_1 << 0xf) >> 0x1b);
  return;
}



uint RADIOCMU_ClockFreqGet(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  param_1 = param_1 & 0x3e0000;
  if (param_1 == 0x40000) {
    uVar1 = SystemHFClockGet();
    uVar2 = read_volatile_4(Peripherals::CMU.HFPERPRESC);
  }
  else {
    if (param_1 < 0x40001) {
      if (param_1 == 0) {
        uVar1 = SystemHFClockGet();
        uVar2 = read_volatile_4(Peripherals::CMU.HFPRESC);
LAB_000100b0:
        uVar2 = (uVar2 << 0x13) >> 0x1b;
        goto LAB_000100b4;
      }
      if (param_1 != 0x20000) {
LAB_000100bc:
        uVar2 = CMU_ClockFreqGet();
        return uVar2;
      }
      uVar1 = SystemHFClockGet();
      uVar2 = read_volatile_4(Peripherals::CMU.HFCOREPRESC);
    }
    else {
      if (param_1 == 0x80000) {
        uVar2 = SystemHFClockGet();
        return uVar2;
      }
      if (param_1 == 0xa0000) {
        uVar1 = SystemHFClockGet();
        uVar2 = read_volatile_4(Peripherals::CMU.HFEXPPRESC);
        goto LAB_000100b0;
      }
      if (param_1 != 0x60000) goto LAB_000100bc;
      uVar1 = SystemHFClockGet();
      uVar2 = read_volatile_4(Peripherals::CMU.HFRADIOPRESC);
    }
  }
  uVar2 = (uVar2 << 0xf) >> 0x17;
LAB_000100b4:
  return uVar1 / (uVar2 + 1);
}



uint RADIOCMU_ClockPrescGet(int param_1)

{
  uint uVar1;
  
  if ((uint)(param_1 << 0x18) >> 0x1c != 6) {
    uVar1 = CMU_ClockPrescGet();
    return uVar1;
  }
  uVar1 = read_volatile_4(Peripherals::CMU.HFRADIOPRESC);
  return (uVar1 << 0xf) >> 0x17;
}



void RADIOCMU_ClockPrescSet(int param_1,int param_2)

{
  uint uVar1;
  
  if ((uint)(param_1 << 0x18) >> 0x1c == 6) {
    uVar1 = read_volatile_4(Peripherals::CMU.HFRADIOPRESC);
    write_volatile_4(Peripherals::CMU.HFRADIOPRESC,uVar1 & 0xfffe00ff | param_2 << 8);
    return;
  }
  CMU_ClockPrescSet();
  return;
}


