#include "aux_pll.h"

static const uint8_t lodivvalues[26UL + 1] = {
  0xFF, 0xFF, 0x01, 0x02, 0x03, 0x00, 0x06, 0x00, 0x07, 0x0A, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x1A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1B, 0x00, 0x00
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



uint8_t AUXPLL_ConvertAuxLoDivToRegVal(int auxlodiv)

{
  if (auxlodiv - 2U < 0x17) return lodivvalues[auxlodiv]; //*(undefined *)(auxlodiv + 0x101b8); //table 
  else return 0;
}



void AUXPLL_Configure(uint32_t param_1,undefined4 auxlodiv,int param_3,int param_4)

{
  BUS_RegMaskedClear(&RAC->AUXENCTRL,RAC_AUXENCTRL_LDOEN_Msk);
  RAC->AUXCTRL &= ~(RAC_AUXCTRL_FPLLDIGEN_Msk | RAC_AUXCTRL_LDOVREFTRIM_Msk | RAC_AUXCTRL_CHPCURR_Msk); //0xff01ffcf;
  RAC->AUXCTRL |= 0xe80030;
  SYNTH->DIVCTRL &= ~SYNTH_DIVCTRL_AUXLODIVFREQCTRL_Msk; //0xffc0ffff;
  SYNTH->DIVCTRL |= AUXPLL_ConvertAuxLoDivToRegVal(auxlodiv) << SYNTH_DIVCTRL_AUXLODIVFREQCTRL_Pos;
  RAC->AUXCTRL &= ~(RAC_AUXCTRL_RXAMP_Msk | RAC_AUXCTRL_LODIVSEL_Msk); //0xfffe00ff;
  RAC->AUXCTRL |= param_4 << RAC_AUXCTRL_RXAMP_Pos | param_3 << RAC_AUXCTRL_LODIVSEL_Pos;
  SYNTH->AUXFREQ &= ~SYNTH_AUXFREQ_MMDDENOM_Msk; //0xffffff80;
  SYNTH->AUXFREQ |= param_1;
  BUS_RegMaskedSet(&RAC->AUXCTRL,RAC_AUXCTRL_LODIVEN_Msk | RAC_AUXCTRL_CHPEN_Msk | RAC_AUXCTRL_VCOEN_Msk); //(&RAC->AUXCTRL,0x4a); RAC_AUXCTRL_LODIVEN_Msk | RAC_AUXCTRL_CHPEN_Msk | RAC_AUXCTRL_VCOEN_Msk
  BUS_RegMaskedSet (&RAC->AUXENCTRL,RAC_AUXENCTRL_LDOEN_Msk); //(&RAC->AUXENCTRL,1);
  BUS_RegMaskedSet(&RAC->AUXCTRL,RAC_AUXCTRL_AUXSYNTHCLKEN_Msk); //(&RAC->AUXCTRL,0x80);
  BUS_RegMaskedSet(&RAC->AUXCTRL,RAC_AUXCTRL_FPLLDIGEN_Msk); //(&RAC->AUXCTRL,0x800000);
  BUS_RegMaskedSet(&SYNTH->AUXVCDACCTRL,SYNTH_AUXVCDACCTRL_EN_Msk); //(&SYNTH->AUXVCDACCTRL,0x10); 
  BUS_RegMaskedClear(&RAC->AUXCTRL,RAC_AUXCTRL_CHPEN_Msk); //(&RAC->AUXCTRL,8);
  BUS_RegMaskedSet(&RAC->AUXCTRL,RAC_AUXCTRL_FPLLDIGEN_Msk | RAC_AUXCTRL_VCOSTARTUP_Msk); //(&RAC->AUXCTRL,0x800004);
  PHY_UTILS_DelayUs(1000);
  while (SYNTH->STATUS & SYNTH_STATUS_CAPCALERROR_Msk) //(SYNTH->STATUS & 0x4000) //do 
  {
    SYNTH->CMD = SYNTH_CMD_AUXSTOP_Msk; // 0x80; 
    SYNTH->CMD = SYNTH_CMD_AUXCAPCALSTART_Msk; //  0x100;
    while (SYNTH->STATUS & SYNTH_STATUS_AUXCAPCALRUNNING_Msk);//(SYNTH->STATUS & 0x800); //
  } //while (SYNTH->STATUS << & 0x4000);
  BUS_RegMaskedSet(&RAC->AUXCTRL,RAC_AUXCTRL_CHPEN_Msk);//(&RAC->AUXCTRL,8);
  BUS_RegMaskedClear(&SYNTH->AUXVCDACCTRL,SYNTH_AUXVCDACCTRL_EN_Msk); //(&SYNTH->AUXVCDACCTRL,0x10); //
  SYNTH->CMD = SYNTH_CMD_AUXSTART_Msk; //0x40; 
  RAC->AUXCTRL &= ~(RAC_AUXCTRL_FPLLDIGEN_Msk | RAC_AUXCTRL_VCOSTARTUP_Msk); //0xff7ffffb;
  RAC->AUXCTRL |= RAC_AUXCTRL_FPLLDIGEN_Msk; //0x800000;
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
  return tmp;
}


