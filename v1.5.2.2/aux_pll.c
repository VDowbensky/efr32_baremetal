#include "aux_pll.h"



void AUXPLL_AuxSettingsPllLoopback(void)

{
  RAC->AUXCTRL |= 0x3000000;
  BUS_RegMaskedSet(&RAC->SGLNAMIXCTRL,0x4000000);
}



void AUXPLL_AuxSettingsPaLoopback(void)

{
  BUS_RegMaskedClear(&RAC->SYNTHCTRL,4);
  BUS_RegMaskedSet(&RAC->AUXENCTRL,4);
}



void AUXPLL_Stop(void)

{
  BUS_RegMaskedClear(&RAC->AUXCTRL,0x8007ca);
  BUS_RegMaskedClear(&RAC->AUXENCTRL,1);
  BUS_RegMaskedClear(&RAC->SGLNAMIXCTRL,0x4000000);
  BUS_RegMaskedClear(&RAC->AUXENCTRL,4);
}



uint8_t AUXPLL_ConvertAuxLoDivToRegVal(int auxlodiv)

{
  if (auxlodiv - 2U < 0x17) return  *(uint8_t *)(auxlodiv + 0x101b8);
  else return 0;
}

/* undefined AUXPLL_ConvertAuxLoDivToRegVal(int param_1)

{
  undefined uVar1;
  
  if (param_1 - 2U < 0x17) {
    uVar1 = (&UNK_0001cbc2)[param_1];
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
} */


void AUXPLL_Configure(uint param_1,undefined4 param_2,int param_3,int param_4)

{
  BUS_RegMaskedClear(&RAC->AUXENCTRL,1);
  RAC->AUXCTRL &= 0xff01ffcf;
  RAC->AUXCTRL |= 0xe80030;
  SYNTH->DIVCTRL &= 0xffc0ffff;
  SYNTH->DIVCTRL |= AUXPLL_ConvertAuxLoDivToRegVal(param_2) << 0x10;
  RAC->AUXCTRL &= 0xfffe00ff;
  RAC->AUXCTRL |= param_4 << 0xb | param_3 << 8; 
  SYNTH->AUXFREQ &= 0xffffff80;
  SYNTH->AUXFREQ |= param_1;
  BUS_RegMaskedSet(&RAC->AUXCTRL,0x4a);
  BUS_RegMaskedSet(&RAC->AUXENCTRL,1);
  BUS_RegMaskedSet(&RAC->AUXCTRL,0x80);
  BUS_RegMaskedSet(&RAC->AUXCTRL,0x800000);
  BUS_RegMaskedSet(&SYNTH->AUXVCDACCTRL,0x10);
  BUS_RegMaskedClear(&RAC->AUXCTRL,8);
  BUS_RegMaskedSet(&RAC->AUXCTRL,0x800004);
  PHY_UTILS_DelayUs(1000);
  do 
  {
    SYNTH->CMD = 0x80;
    SYNTH->CMD = 0x100;
	while (SYNTH->STATUS & 0x800);
  } while (SYNTH->STATUS & 0x4000);
  BUS_RegMaskedSet(&RAC->AUXCTRL,8);
  BUS_RegMaskedClear(&SYNTH->AUXVCDACCTRL,0x10);
  SYNTH->CMD = 0x40;
  RAC->AUXCTRL &= 0xff7ffffb;
  RAC->AUXCTRL |= 0x800000;
}



int AUXPLL_Start(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  uint32_t uVar1;
  int iVar2;
  
  uVar1 = SystemHFXOClockGet();
  iVar2 = param_3 * (uVar1 / param_4);
  if (iVar2 != -1) 
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
      AUXPLL_AuxSettingsPaLoopback();
    }
  }
  return iVar2;
}


