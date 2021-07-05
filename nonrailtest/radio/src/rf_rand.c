#include "rf_rand.h"
#include <stdbool.h>
#include "em_bus.h"
#include "em_assert.h"




uint16_t RFRAND_GetRadioEntropy(void)

{
//  uint uVar1;
//  uint uVar2;
//  uint uVar3;
//  int iVar4;
//  size_t __n;
//  uint uVar5;
//  uint local_24;
//
//  uVar2 = CMU->RADIOCLKEN0;
//
//  local_24 = param_2;
//  memset(param_1,0,param_2);
//  //if ((((uVar2 | 0xcc) == uVar2) && (-1 < (int)(RAC->CTRL << 0x1f))) &&(RADIOCMU_ClockPrescGet(0x75160) == 0))
//  if ((((CMU->RADIOCLKEN0 | 0xcc) == CMU->RADIOCLKEN0) && !(RAC->CTRL & 0x01) &&(RADIOCMU_ClockPrescGet(0x75160) == 0)))
//  {
//    disableIRQinterrupts();
//    if (INT_LockCnt != -1)
//    {
//      INT_LockCnt = INT_LockCnt + 1;
//    }
//    uVar3 = MODEM->CTRL0;
//    uVar2 = FRC->RAWCTRL;
//
//    MODEM->CTRL0 &= 0xc7ffffff;
//    MODEM->CTRL0 |= 0x8000000;
//    FRC->RAWCTRL = 0x24;
//    _DAT_43080008 = 1;
//    FRC->IFC = 0x4000;
//    FRC->CMD = 0x1000;
//    uVar5 = 0;
//    while (uVar5 < param_2)
//    {
//      do {
//       // do {
//       //   uVar1 = FRC->IF;
//       // } while (-1 < (int)(uVar1 << 0x11));
//        while(!(FRC->IF & 0x4000));
//        //uVar1 = FRC->STATUS;
//      } while(!(FRC->STATUS & ~0x100));// while (-1 < (int)(uVar1 << 0x17));
//      __n = param_2 - uVar5;
//      FRC->IFC = 0x4000;
//      if (3 < (int)__n)
//      {
//        __n = 4;
//      }
//      local_24 = FRC->RXRAWDATA;
//      memcpy((void *)((int)param_1 + uVar5),&local_24,__n);
//      uVar5 = __n + uVar5 & 0xffff;
//    }
//    _DAT_43080008 = 0;
//    FRC->RAWCTRL = uVar2;
//    MODEM->CTRL0 = uVar3;
//    FRC->IFC = 0x4000;
//    if ((INT_LockCnt != 0) && (INT_LockCnt = INT_LockCnt + -1, INT_LockCnt == 0))
//	{
//      enableIRQinterrupts();
//    }
//  }
//  else
//  {
//    param_2 = 0;
//  }
  //return param_2;
  return 0;
}



// WARNING: Could not reconcile some variable overlaps

uint32_t RFRAND_SeedProtimerRandom(uint32_t param_1,uint32_t param_2,uint32_t param_3,uint32_t param_4)

{
  int iVar1;
  uint32_t uVar2;
//  uint32_t uStack12;
//  uint32_t uStack8;
//
//  uStack12 = param_2;
//  uStack8 = param_3;
//  iVar1 = RFRAND_GetRadioEntropy((int)&uStack12 + 2,2,param_3,param_4,param_1);
//  if (iVar1 == 2) {
//    if (uStack12._2_2_ == -0x7fc) {
//      uStack12 = 0xf8050000;
//    }
//    PROTIMER->RANDOM = uStack12 >> 0x10;
//    uVar2 = 1;
//  }
//  else {
//    uVar2 = 0;
//  }
  return uVar2;
}



uint16_t RFRAND_GetProtimerRandom(void)

{
  return PROTIMER->RANDOM & 0xffff;
}


