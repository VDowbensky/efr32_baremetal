#include "radio_cmu.h"



void RADIOCMU_ClockEnable(CMU_Clock_TypeDef clock,bool enable)

{
  uint uVar1;
  CMU *pCVar2;
  
  uVar1 = (clock << 0x14) >> 0x1c;
  if (uVar1 == 1) 
  {
    pCVar2 = &Peripherals::CMU;
  }
  else 
  {
    if (uVar1 != 4) 
	{
      CMU_ClockEnable(clock,(_Bool)enable);
      return;
    }
    pCVar2 = (CMU *)&CMU->HFRADIOCLKEN0;
  }
  *(uint *)((((clock << 0xf) >> 0x1b) + (int)&pCVar2[0x114fb].RFLOCK0 * 8) * 4) = (uint)enable;
  return;
}



uint32_t RADIOCMU_ClockFreqGet(CMU_Clock_TypeDef clock)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = clock & 0x3e0000;
  if (uVar2 == 0x40000) 
  {
    uVar1 = SystemHFClockGet();
    uVar2 = (CMU->HFPERPRESC);
  }
  else 
  {
    if (uVar2 < 0x40001) 
	{
      if (uVar2 == 0) 
	  {
        uVar1 = SystemHFClockGet();
        uVar2 = (CMU->HFPRESC);
LAB_0000770c:
        uVar2 = (uVar2 << 0x13) >> 0x1b;
        goto LAB_00007710;
      }
      if (uVar2 != 0x20000) 
	  {
LAB_00007718:
        uVar2 = CMU_ClockFreqGet(clock);
        return uVar2;
      }
      uVar1 = SystemHFClockGet();
      uVar2 = (CMU->HFCOREPRESC);
    }
    else 
	{
      if (uVar2 == 0x80000) 
	  {
        uVar2 = SystemHFClockGet();
        return uVar2;
      }
      if (uVar2 == 0xa0000) 
	  {
        uVar1 = SystemHFClockGet();
        uVar2 = (CMU->HFEXPPRESC);
        goto LAB_0000770c;
      }
      if (uVar2 != 0x60000) goto LAB_00007718;
      uVar1 = SystemHFClockGet();
      uVar2 = (CMU->HFRADIOPRESC);
    }
  }
  uVar2 = (uVar2 << 0xf) >> 0x17;
LAB_00007710:
  return uVar1 / (uVar2 + 1);
}



uint32_t RADIOCMU_ClockPrescGet(CMU_Clock_TypeDef clock)

{
  uint uVar1;
  uint32_t uVar2;
  
  if ((clock << 0x18) >> 0x1c != 6) 
  {
    uVar2 = CMU_ClockPrescGet(clock);
    return uVar2;
  }
  uVar1 = (CMU->HFRADIOPRESC);
  return (uVar1 << 0xf) >> 0x17;
}



void RADIOCMU_ClockPrescSet(uint32_t clock,uint32_t presc)

{
  uint uVar1;
  
  if ((clock << 0x18) >> 0x1c == 6) 
  {
    uVar1 = (CMU->HFRADIOPRESC);
    write_volatile_4(CMU->HFRADIOPRESC,uVar1 & 0xfffe00ff | presc << 8);
    return;
  }
  CMU_ClockPrescSet();
  return;
}


