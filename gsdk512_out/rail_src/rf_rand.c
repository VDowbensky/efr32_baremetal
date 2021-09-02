#include "rf_rand.h"


//seed0 = 0xbeef;
//seed1 = 0xface;
//pseudoRandomSeeded;

uint32_t RFRAND_GetRadioEntropy(void *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  size_t __n;
  uint local_24;
  
  uVar4 = CMU->HFRADIOCLKEN0;
  local_24 = param_2;
  memset(param_1,0,param_2);
  if ((((uVar4 | 0xcc) == uVar4) && (-1 < (int)(RAC->CTRL << 0x1f))) && (RADIOCMU_ClockPrescGet(0x75160) == 0)) 
  {
    uVar5 = CORE_EnterCritical();
    uVar3 = MODEM->CTRL0;
    uVar2 = FRC->RAWCTRL;
    BUS_RegMaskedClear(&MODEM->CTRL0,0x38000000);
    BUS_RegMaskedSet(&MODEM->CTRL0,0x8000000);
    FRC->RAWCTRL = 0x24;
    BUS_RegMaskedSet(&RAC->RXENSRCEN,4);
    FRC->IFC = 0x4000;
    FRC->CMD,0x1000;
    for (; uVar4 < param_2; uVar4 = uVar4 + __n & 0xffff) 
	{
      do 
	  {
        while (-1 < (int)(FRC->IF << 0x11));
      } while (-1 < (int)(FRC->STATUS << 0x17));
      __n = param_2 - uVar4;
      FRC->IFC = 0x4000;
      if (3 < (int)__n) __n = 4;
      local_24 = FRC->RXRAWDATA;
      memcpy((void *)((int)param_1 + uVar4),&local_24,__n);
    }
    BUS_RegMaskedClear(&RAC->RXENSRCEN,4);
    FRC->RAWCTRL = uVar2;
    MODEM->CTRL0 = uVar3;
    FRC->IFC = 0x4000;
    CORE_ExitCritical(uVar5);
  }
  else param_2 = 0;
  return param_2;
}


bool RFRAND_SeedProtimerRandom(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack12;
  
  uStack12 = param_2;
  if (RFRAND_GetRadioEntropy((int)&uStack12 + 2,2,param_3,param_4,param_1) == 2) 
  {
    if (uStack12._2_2_ == -0x7fc) uStack12 = 0xf8050000;
    PROTIMER->RANDOM = uStack12 >> 0x10;
    return true;
  }
  else return false;
}



uint32_t RFRAND_GetProtimerRandom(void)

{
  return PROTIMER->RANDOM & 0xffff;
}



void RFRAND_SeedPseudoRandom(void)

{
  if (RFRAND_SeedProtimerRandom() != 0) 
  {
    seed0 = (uint16_t)PROTIMER->RANDOM;
    seed1 = (uint16_t)PROTIMER->RANDOM;
    pseudoRandomSeeded = 1;
  }
}



uint16_t RFRAND_GetPseudoRandom(void)

{
  uint32_t uVar1;
  uint32_t uVar2;
  
  if (pseudoRandomSeeded == 0) RFRAND_SeedPseudoRandom();
  uVar1 = (uint32_t)seed0;
  if ((int)(uVar1 << 0x10) < 0) uVar1 = uVar1 ^ 0x62;
  uVar2 = (uint32_t)seed1;
  if ((int)(uVar2 << 0x10) < 0) uVar2 = uVar2 ^ 0x100b;
  seed0 = (uint16_t)(uVar1 << 1);
  seed1 = (uint16_t)(uVar2 << 1);
  return uVar1 ^ uVar2;
}


