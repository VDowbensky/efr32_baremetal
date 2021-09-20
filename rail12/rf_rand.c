#include "rf_rand.h"



uint16_t RFRAND_GetRadioEntropy(uint8_t *buffer,uint16_t bytes)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint32_t uVar4;
  uint __n;
  size_t __n_00;
  uint uVar5;
  uint local_24;
  
  __n = (uint)bytes;
  uVar2 = (CMU->HFRADIOCLKEN0);
  local_24 = __n;
  memset(buffer,0,__n);
  if ((((uVar2 | 0xcc) == uVar2) && (-1 < (int)(RAC->CTRL << 0x1f)) && (RADIOCMU_ClockPrescGet(0x75160) == 0)) 
  {
    disableIRQinterrupts();
    if (INT_LockCnt != 0xffffffff) INT_LockCnt = INT_LockCnt + 1;
    uVar3 = MODEM->CTRL0;
    uVar2 = FRC->RAWCTRL;
	MODEM->CTRL0 &= 0xc7ffffff;
	MODEM->CTRL0 |= 0x8000000;
    FRC->RAWCTRL = 0x24;
    _DAT_43080008 = 1;
    FRC->IFC = 0x4000;
    FRC->CMD = 0x1000;
    for (uVar5 = 0; uVar5 < __n; uVar5 = __n_00 + uVar5 & 0xffff) 
	{
      do 
	  {
		while (-1 < (int)(FRC->IF << 0x11));
      } while (-1 < (int)(FRC->STATUS << 0x17));
      __n_00 = __n - uVar5;
      FRC->IFC = 0x4000;
      if (3 < (int)__n_00) __n_00 = 4;
      local_24 = (FRC->RXRAWDATA);
      memcpy(buffer + uVar5,&local_24,__n_00);
    }
    _DAT_43080008 = 0;
    FRC->RAWCTRL = uVar2;
    MODEM->CTRL0 = uVar3;
    write_volatile_4(FRC->IFC = 0x4000);
    if ((INT_LockCnt != 0) && (INT_LockCnt = INT_LockCnt - 1, INT_LockCnt == 0)) enableIRQinterrupts();
  }
  else bytes = 0;
  return bytes;
}



bool RFRAND_SeedProtimerRandom(undefined4 param_1,uint param_2,undefined4 param_3)

{
  bool bVar1;
  uint16_t uVar2;
  undefined4 uStack12;
  undefined4 uStack8;
  
  uStack12 = param_2;
  uStack8 = param_3;
  uVar2 = RFRAND_GetRadioEntropy((uint8_t *)((int)&uStack12 + 2),2);
  if (uVar2 == 2) 
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


