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
  size_t __n;
  uint local_24;
  CORE_irqState_t irqState;
  
  uVar4 = CMU->HFRADIOCLKEN0;
  local_24 = param_2;
  memset(param_1,0,param_2);
  if ((((uVar4 | 0xcc) == uVar4) && (-1 < (int)(RAC->CTRL << 0x1f))) && (RADIOCMU_ClockPrescGet(0x75160) == 0)) 
  {
    irqState = CORE_EnterCritical();
    uVar3 = MODEM->CTRL0;
    uVar2 = FRC->RAWCTRL;
    BUS_RegMaskedClear(&MODEM->CTRL0,MODEM_CTRL0_DEMODRAWDATASEL_Msk);
    BUS_RegMaskedSet(&MODEM->CTRL0,0x8000000);
    FRC->RAWCTRL = 0x24;
    BUS_RegMaskedSet(&RAC->RXENSRCEN,4);
    FRC->IFC = FRC_IFC_RXRAWEVENT_Msk;
    FRC->CMD = FRC_CMD_RXRAWUNBLOCK_Msk;
    for (; uVar4 < param_2; uVar4 = uVar4 + __n & 0xffff) 
	{
      do 
	  {
		while (!(FRC->IF & FRC_IF_RXRAWEVENT_Msk));
      } while (!(FRC->STATUS & FRC_STATUS_RXRAWBLOCKED_Msk));
      __n = param_2 - uVar4;
      FRC->IFC = FRC_IFC_RXRAWEVENT_Msk;
      if (3 < (int)__n) __n = 4;
      local_24 = FRC->RXRAWDATA;
      memcpy((void *)((int)param_1 + uVar4),&local_24,__n);
    }
    BUS_RegMaskedClear(&RAC->RXENSRCEN,4);
    FRC->RAWCTRL = uVar2;
    MODEM->CTRL0 = uVar3;
    FRC->IFC = FRC_IFC_RXRAWEVENT_Msk;
    CORE_ExitCritical(irqState);
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
  return PROTIMER->RANDOM & PROTIMER_RANDOM_RANDOM_Msk;
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
  uint32_t s1;
  uint32_t s2;
  
  if (pseudoRandomSeeded == 0) RFRAND_SeedPseudoRandom();
  s1 = (uint32_t)seed0;
  if (s1 & 0x8000) s1 = s1 ^ 0x62;
  s2 = (uint32_t)seed1;
  if (s2 & 0x8000) < 0) s2 = s2 ^ 0x100b;
  seed0 = (uint16_t)(s1 << 1);
  seed1 = (uint16_t)(s2 << 1);
  return s1 ^ s2;
}


