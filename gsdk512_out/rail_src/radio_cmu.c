#include "radio_cmu.h"



void RADIOCMU_ClockEnable(uint32_t clock,bool enable)

{
  uint32_t uVar1;
  CMU *pCVar2;
  uint32_t *puVar3;
  
  uVar1 = (clock << 0x14) >> 0x1c;
  if (uVar1 == 1) pCVar2 = &CMU;
  else 
  {
    if (uVar1 != 4) 
	{
      CMU_ClockEnable(clock,enable);
      return;
    }
    pCVar2 = (CMU *)0x400e40c8;
  }
  if (enable == false) puVar3 = &pCVar2[0x2192e].CALCTRL;
  else puVar3 = (uint *)&pCVar2[0x325c5].field_0x78;
  *puVar3 = 1 << ((clock << 0xf) >> 0x1b);
}



uint32_t RADIOCMU_ClockFreqGet(uint32_t clock) //not exact

{
  uint32_t tmp;
  
  tmp = clock & 0x3e0000;
  if (tmp == 0x40000) return SystemHFClockGet() / (((CMU->HFPERPRESC << 0x13) >> 0x1b) + 1);
  else 
  {
    if (tmp < 0x40001) 
	{
      if (tmp == 0) return SystemHFClockGet() / (((CMU->HFPRESC << 0x13) >> 0x1b) + 1);

      if (tmp != 0x20000) return CMU_ClockFreqGet();
	  else return CMU_ClockFreqGet() / CMU->HFCOREPRESC;
    }
    else 
	{
      if (tmp == 0x80000) return SystemHFClockGet();
      if (tmp == 0xa0000) return SystemHFClockGet() / (((CMU->HFEXPPRESC << 0x13) >> 0x1b) + 1); 

      if (tmp != 0x60000) return CMU_ClockFreqGet();
	  else return SystemHFClockGet() / ((CMU->HFRADIOPRESC << 0xf) >> 0x17);
    }
  }
}



uint32_t RADIOCMU_ClockPrescGet(uint32_t clock)

{
  if ((clock << 0x18) >> 0x1c != 6) return CMU_ClockPrescGet();
  else return (CMU->HFRADIOPRESC << 0xf) >> 0x17;
}



void RADIOCMU_ClockPrescSet(uint32_t clock,uint32_t presc)

{
  if ((clock << 0x18) >> 0x1c == 6) 
  {
	CMU->HFRADIOPRESC &= 0xfffe00ff;
	CMU->HFRADIOPRESC |= presc << 8;
  }
  else CMU_ClockPrescSet(clock, presc);
}


