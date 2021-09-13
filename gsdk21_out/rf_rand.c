#include "rf_rand.h"



uint RFRAND_GetRadioEntropy(void *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  size_t __n;
  uint local_24;
  
  uVar4 = read_volatile_4(Peripherals::CMU.HFRADIOCLKEN0);
  local_24 = param_2;
  memset(param_1,0,param_2);
  if ((((uVar4 | 0xcc) == uVar4) &&
      (uVar4 = read_volatile_4(Peripherals::RAC.CTRL), -1 < (int)(uVar4 << 0x1f))) &&
     (uVar4 = RADIOCMU_ClockPrescGet(0x75160), uVar4 == 0)) {
    uVar5 = CORE_EnterCritical();
    uVar3 = read_volatile_4(Peripherals::MODEM.CTRL0);
    uVar2 = read_volatile_4(Peripherals::FRC.RAWCTRL);
    write_volatile_4(Peripherals::MODEM_CLR.CTRL0,0x38000000);
    write_volatile_4(Peripherals::MODEM_SET.CTRL0,0x8000000);
    write_volatile_4(Peripherals::FRC.RAWCTRL,0x24);
    write_volatile_4(Peripherals::RAC_SET.RXENSRCEN,4);
    write_volatile_4(Peripherals::FRC.IFC,0x4000);
    write_volatile_4(Peripherals::FRC.CMD,0x1000);
    for (; uVar4 < param_2; uVar4 = uVar4 + __n & 0xffff) {
      do {
        do {
          uVar1 = read_volatile_4(Peripherals::FRC.IF);
        } while (-1 < (int)(uVar1 << 0x11));
        uVar1 = read_volatile_4(Peripherals::FRC.STATUS);
      } while (-1 < (int)(uVar1 << 0x17));
      __n = param_2 - uVar4;
      write_volatile_4(Peripherals::FRC.IFC,0x4000);
      if (3 < (int)__n) {
        __n = 4;
      }
      local_24 = read_volatile_4(Peripherals::FRC.RXRAWDATA);
      memcpy((void *)((int)param_1 + uVar4),&local_24,__n);
    }
    write_volatile_4(Peripherals::RAC_CLR.RXENSRCEN,4);
    write_volatile_4(Peripherals::FRC.RAWCTRL,uVar2);
    write_volatile_4(Peripherals::MODEM.CTRL0,uVar3);
    write_volatile_4(Peripherals::FRC.IFC,0x4000);
    CORE_ExitCritical(uVar5);
  }
  else {
    param_2 = 0;
  }
  return param_2;
}



// WARNING: Could not reconcile some variable overlaps

undefined4
RFRAND_SeedProtimerRandom(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack12;
  undefined4 uStack8;
  
  uStack12 = param_2;
  uStack8 = param_3;
  iVar1 = RFRAND_GetRadioEntropy((int)&uStack12 + 2,2,param_3,param_4,param_1);
  if (iVar1 == 2) {
    if (uStack12._2_2_ == -0x7fc) {
      uStack12 = 0xf8050000;
    }
    write_volatile_4(Peripherals::PROTIMER.RANDOM,uStack12 >> 0x10);
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



uint RFRAND_GetProtimerRandom(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::PROTIMER.RANDOM);
  return uVar1 & 0xffff;
}



void RFRAND_SeedPseudoRandom(void)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = RFRAND_SeedProtimerRandom();
  if (iVar2 != 0) {
    uVar1 = read_volatile_4(Peripherals::PROTIMER.RANDOM);
    seed0 = (undefined2)uVar1;
    uVar1 = read_volatile_4(Peripherals::PROTIMER.RANDOM);
    seed1 = (undefined2)uVar1;
    pseudoRandomSeeded = 1;
  }
  return;
}



uint RFRAND_GetPseudoRandom(void)

{
  uint uVar1;
  uint uVar2;
  
  if (pseudoRandomSeeded == '\0') {
    RFRAND_SeedPseudoRandom();
  }
  uVar1 = (uint)seed0;
  if ((int)(uVar1 << 0x10) < 0) {
    uVar1 = uVar1 ^ 0x62;
  }
  uVar2 = (uint)seed1;
  if ((int)(uVar2 << 0x10) < 0) {
    uVar2 = uVar2 ^ 0x100b;
  }
  seed0 = (short)(uVar1 << 1);
  seed1 = (short)(uVar2 << 1);
  return uVar1 ^ uVar2;
}


