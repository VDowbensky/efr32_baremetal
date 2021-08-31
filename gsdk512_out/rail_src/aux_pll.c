#include "aux_pll.h"

static const unsigned char cswtch10[23UL + 1] = 
{
  0x01, 0x02, 0x03, 0x00, 0x06, 0x00, 0x07, 0x0A, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x1A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1B, 0x00
};

void AUXPLL_AuxSettingsPllLoopback(void)

{
  RAC->AUXCTRL |= RAC_AUXCTRL_LPFRES_Msk;
  BUS_RegMaskedSet(&RAC->SGLNAMIXCTRL,RAC_SGLNAMIXCTRL_LNAMIXAUXSYNTHINPUTEN_Msk);
}



void AUXPLL_AuxSettingsPaLoopback(void)

{
  BUS_RegMaskedClear(&RAC->SYNTHCTRL,RAC_SYNTHCTRL_LODIVTXEN_Msk);
  BUS_RegMaskedSet(&RAC->AUXENCTRL,RAC_AUXENCTRL_LODIVAUXEN_Msk);
}



void AUXPLL_Stop(void)

{
  BUS_RegMaskedClear(&RAC->AUXCTRL,0x8007ca); //RAC_AUXCTRL_FPLLDIGEN_Msk | 
  BUS_RegMaskedClear(&RAC->AUXENCTRL,RAC_AUXENCTRL_LDOEN_Msk);
  BUS_RegMaskedClear(&RAC->SGLNAMIXCTRL,RAC_SGLNAMIXCTRL_LNAMIXAUXSYNTHINPUTEN_Msk);
  BUS_RegMaskedClear(&RAC->AUXENCTRL,RAC_AUXENCTRL_LODIVAUXEN_Msk);
}



undefined AUXPLL_ConvertAuxLoDivToRegVal(int param_1)

{
  if (param_1 - 2U < 0x17) return *(undefined *)(param_1 + 0x101b8);
  else return 0;
}



void AUXPLL_Configure(uint param_1,undefined4 param_2,int param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  
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
  } while (SYNTH->STATUS << & 0x4000);
  BUS_RegMaskedSet(&RAC->AUXCTRL,8);
  BUS_RegMaskedClear(&SYNTH->AUXVCDACCTRL,0x10);
  SYNTH->CMD = 0x40;
  RAC->AUXCTRL &= 0xff7ffffb;
  RAC->AUXCTRL |= 0x800000;
}



int32_t AUXPLL_Start(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  int32_t tmp;
  
  tmp = param_3 * (SystemHFXOClockGet() / param_4);
  if (tmp != -1) 
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


