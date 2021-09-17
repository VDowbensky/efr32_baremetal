#include "aux_pll.h"



void AUXPLL_AuxSettingsPllLoopback(void)

{
  RAC->AUXCTRL |= 0x3000000;
  RAC->SGLNAMIXCTRL |= 0x4000000;
}



void AUXPLL_AuxSettingsPaLoopback(void)

{
  RAC->SYNTHCTRL &= 0xfffffffb;
  RAC->AUXENCTRL |= 4;
}



void AUXPLL_Stop(void)

{
  RAC->AUXCTRL &= 0xff7ff835;
  RAC->AUXENCTRL &= 0xfffffffe;
  RAC->SGLNAMIXCTRL &= 0xfbffffff;
  RAC->AUXENCTRL &= 0xfffffffb;
}



undefined AUXPLL_ConvertAuxLoDivToRegVal(int param_1)

{
  if (param_1 - 2U < 0x17) return *(undefined *)(param_1 + 0x101f4);
  else return 0;
}



void AUXPLL_Configure(uint param_1,undefined4 param_2,int param_3,int param_4)

{
  RAC->AUXENCTRL &= 0xfffffffe;
  RAC->AUXCTRL &= 0xff01ffcf;
  RAC->AUXCTRL |= 0xe80030;
  SYNTH->DIVCTRL &= 0xffc0ffff;
  SYNTH->DIVCTRL |= AUXPLL_ConvertAuxLoDivToRegVal(param_2) << 0x10;
  RAC->AUXCTRL &= 0xfffe00ff;
  RAC->AUXCTRL |= param_4 << 0xb | param_3 << 8;
  SYNTH->AUXFREQ &= 0xffffff80;
  SYNTH->AUXFREQ |= param_1;
  RAC->AUXCTRL |= 0x4a;
  RAC->AUXENCTRL |= 1;
  RAC->AUXCTRL |= 0x80;
  RAC->AUXCTRL |= 0x800000;
  SYNTH->AUXVCDACCTRL |= 0x10;
  RAC->AUXCTRL &= 0xfffffff7;
  RAC->AUXCTRL |= 0x800004;
  PHY_UTILS_DelayUs(1000);
  do 
  {
    SYNTH->CMD = 0x80;
    SYNTH->CMD = 0x100;
    while ((int)(SYNTH->STATUS << 0x14) < 0);
  } while ((int)(SYNTH->STATUS << 0x11) < 0);
  RAC->AUXCTRL |= 8);
  SYNTH->AUXVCDACCTRL &= 0xffffffef;
  SYNTH->CMD = 0x40;
  RAC->AUXCTRL &= 0xff7ffffb;
  RAC->AUXCTRL |= 0x800000;
}



int32_t AUXPLL_Start(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  if (param_3 * (SystemHFXOClockGet() / param_4) != -1) 
  {
    AUXPLL_Configure(param_3,param_4,param_1,param_2);
    if (param_1 == 2) AUXPLL_AuxSettingsPllLoopback();
    else 
	{
      if (param_1 != 3) 
	  {
        AUXPLL_Stop();
        return -1;
      }
      else AUXPLL_AuxSettingsPaLoopback();
    }
  }
  else return -1;
}


