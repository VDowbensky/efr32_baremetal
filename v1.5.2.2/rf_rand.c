#include "rf_rand.h"



uint16_t RFRAND_GetRadioEntropy(uint8_t *buffer,uint16_t bytes)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  CORE_irqState_t irqState;
  uint __n;
  size_t __n_00;
  uint local_24;
  
  __n = (uint)bytes;
  uVar4 = (CMU->HFRADIOCLKEN0);
  local_24 = __n;
  memset(buffer,0,__n);
  if ((((uVar4 | 0xcc) == uVar4) &&
      (uVar4 = (RAC->CTRL), -1 < (int)(uVar4 << 0x1f))) &&
     (uVar4 = RADIOCMU_ClockPrescGet(0x75160), uVar4 == 0)) {
    irqState = CORE_EnterCritical();
    uVar3 = (MODEM->CTRL0);
    uVar2 = (FRC->RAWCTRL);
    BUS_RegMaskedClear(&MODEM->CTRL0,0x38000000);
    BUS_RegMaskedSet(&MODEM->CTRL0,0x8000000);
    write_volatile_4(FRC->RAWCTRL,0x24);
    BUS_RegMaskedSet(&RAC->RXENSRCEN,4);
    write_volatile_4(FRC->IFC,0x4000);
    write_volatile_4(FRC->CMD,0x1000);
    for (; uVar4 < __n; uVar4 = uVar4 + __n_00 & 0xffff) {
      do {
        do {
          uVar1 = (FRC->IF);
        } while (-1 < (int)(uVar1 << 0x11));
        uVar1 = (FRC->STATUS);
      } while (-1 < (int)(uVar1 << 0x17));
      __n_00 = __n - uVar4;
      write_volatile_4(FRC->IFC,0x4000);
      if (3 < (int)__n_00) {
        __n_00 = 4;
      }
      local_24 = (FRC->RXRAWDATA);
      memcpy(buffer + uVar4,&local_24,__n_00);
    }
    BUS_RegMaskedClear(&RAC->RXENSRCEN,4);
    write_volatile_4(FRC->RAWCTRL,uVar2);
    write_volatile_4(MODEM->CTRL0,uVar3);
    write_volatile_4(FRC->IFC,0x4000);
    CORE_ExitCritical(irqState);
  }
  else {
    bytes = 0;
  }
  return bytes;
}




bool RFRAND_SeedProtimerRandom(void)

{
  bool bVar1;
  uint16_t uVar2;
  undefined4 in_r1;
  ushort local_a [5];
  
  local_a[0] = (ushort)((uint)in_r1 >> 0x10);
  uVar2 = RFRAND_GetRadioEntropy((uint8_t *)local_a,2);
  if (uVar2 == 2) {
    if (local_a[0] == 0xf804) {
      local_a[0] = 0xf805;
    }
    write_volatile_4(PROTIMER->RANDOM,(uint)local_a[0]);
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}


uint16_t RFRAND_GetProtimerRandom(void)

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


