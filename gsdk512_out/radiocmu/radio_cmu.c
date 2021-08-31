#include "radio_cmu.h"



void RADIOCMU_ClockEnable(uint32_t clock,bool enable)

{
  uint uVar1;
  CMU *pCVar2;
  uint *puVar3;
  
  uVar1 = (clock << 0x14) >> 0x1c;
  if (uVar1 == 1) pCVar2 = &Peripherals::CMU;
  else 
  {
    if (uVar1 != 4) 
	{
      CMU_ClockEnable();
      return;
    }
    pCVar2 = (CMU *)0x400e40c8;
  }
  if (enable == false) 
  {
    puVar3 = &pCVar2[0x2192e].CALCTRL;
  }
  else 
  {
    puVar3 = (uint *)&pCVar2[0x325c5].field_0x78;
  }
  *puVar3 = 1 << ((clock << 0xf) >> 0x1b);
  return;
}



uint32_t RADIOCMU_ClockFreqGet(uint32_t clock)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = clock & 0x3e0000;
  if (uVar2 == 0x40000) 
  {
    uVar1 = SystemHFClockGet();
    uVar2 = read_volatile_4(Peripherals::CMU.HFPERPRESC);
  }
  else 
  {
    if (uVar2 < 0x40001) 
	{
      if (uVar2 == 0) 
	  {
        uVar1 = SystemHFClockGet();
        uVar2 = read_volatile_4(Peripherals::CMU.HFPRESC);
LAB_000100b0:
        uVar2 = (uVar2 << 0x13) >> 0x1b;
        goto LAB_000100b4;
      }
      if (uVar2 != 0x20000) 
	  {
LAB_000100bc:
        uVar2 = CMU_ClockFreqGet();
        return uVar2;
      }
      uVar1 = SystemHFClockGet();
      uVar2 = read_volatile_4(Peripherals::CMU.HFCOREPRESC);
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
        uVar2 = read_volatile_4(Peripherals::CMU.HFEXPPRESC);
        goto LAB_000100b0;
      }
      if (uVar2 != 0x60000) goto LAB_000100bc;
      uVar1 = SystemHFClockGet();
      uVar2 = read_volatile_4(Peripherals::CMU.HFRADIOPRESC);
    }
  }
  uVar2 = (uVar2 << 0xf) >> 0x17;
LAB_000100b4:
  return uVar1 / (uVar2 + 1);
}



uint32_t RADIOCMU_ClockPrescGet(uint32_t clock)

{
  uint uVar1;
  uint32_t uVar2;
  
  if ((clock << 0x18) >> 0x1c != 6) 
  {
    uVar2 = CMU_ClockPrescGet();
    return uVar2;
  }
  uVar1 = read_volatile_4(Peripherals::CMU.HFRADIOPRESC);
  return (uVar1 << 0xf) >> 0x17;
}



void RADIOCMU_ClockPrescSet(uint32_t clock,uint32_t presc)

{
  uint uVar1;
  
  if ((clock << 0x18) >> 0x1c == 6) 
  {
    uVar1 = read_volatile_4(Peripherals::CMU.HFRADIOPRESC);
    write_volatile_4(Peripherals::CMU.HFRADIOPRESC,uVar1 & 0xfffe00ff | presc << 8);
    return;
  }
  CMU_ClockPrescSet();
  return;
}


