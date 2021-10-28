#include "aux_pll.h"
#include <stdbool.h>
#include "em_bus.h"
#include "em_assert.h"
#include "phy_utils.h"

const uint8_t CSWTCH_10[] = {0x01, 0x02, 0x03, 0x00, 0x06, 0x00, 0x07, 0x0a, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x1a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1b};

void AUXPLL_AuxSettingsPllLoopback(void)

{
	BUS_RegMaskedSet(&RAC->AUXCTRL, RAC_AUXCTRL_LPFRES_Msk);
	BUS_RegMaskedSet(&RAC->SGLNAMIXCTRL, RAC_SGLNAMIXCTRL_LNAMIXAUXSYNTHINPUTEN_Msk);
}



void AUXPLL_AuxSettingsPaLoopback(void)

{
	BUS_RegMaskedClear(&RAC->SYNTHCTRL, RAC_SYNTHCTRL_LODIVTXEN_Msk);
	BUS_RegMaskedSet(&RAC->AUXENCTRL, RAC_AUXENCTRL_LODIVAUXEN_Msk);
}



void AUXPLL_Stop(void)

{
	BUS_RegMaskedClear(&RAC->AUXCTRL, RAC_AUXCTRL_FPLLDIGEN_Msk | RAC_AUXCTRL_LODIVSEL_Msk | RAC_AUXCTRL_AUXSYNTHCLKEN_Msk | RAC_AUXCTRL_LODIVEN_Msk | RAC_AUXCTRL_CHPEN_Msk | RAC_AUXCTRL_VCOEN_Msk);
	BUS_RegMaskedClear(&RAC->AUXENCTRL, RAC_AUXENCTRL_LDOEN_Msk);
	BUS_RegMaskedClear(&RAC->SGLNAMIXCTRL, RAC_SGLNAMIXCTRL_LNAMIXAUXSYNTHINPUTEN_Msk);
	BUS_RegMaskedClear(&RAC->AUXENCTRL, RAC_AUXENCTRL_LODIVAUXEN_Msk);
}



uint8_t AUXPLL_ConvertAuxLoDivToRegVal(int param_1)

{
  uint8_t uVar1;
  
  if (param_1 - 2U < 0x17) uVar1 = *(uint8_t  *)(param_1 + 0x101f4); //!!!!
  else uVar1 = 0;
  return uVar1;
}



void AUXPLL_Configure(uint32_t param_1,uint32_t param_2,int param_3,int param_4)

{
	BUS_RegMaskedClear(&RAC->AUXENCTRL, RAC_AUXENCTRL_LDOEN_Msk);
	BUS_RegMaskedClear(&RAC->AUXCTRL, RAC_AUXCTRL_FPLLDIGEN_Msk | RAC_AUXCTRL_LDOVREFTRIM_Msk | RAC_AUXCTRL_LDOAMPCURR_Msk | RAC_AUXCTRL_CHPCURR_Msk);
	BUS_RegMaskedSet(&RAC->AUXCTRL, 0xe80030);

	BUS_RegMaskedClear(&SYNTH->DIVCTRL, SYNTH_DIVCTRL_AUXLODIVFREQCTRL_Msk);
	BUS_RegMaskedSet(&SYNTH->DIVCTRL, AUXPLL_ConvertAuxLoDivToRegVal(param_2) << SYNTH_DIVCTRL_AUXLODIVFREQCTRL_Pos);
	BUS_RegMaskedClear(&RAC->AUXCTRL, RAC_AUXCTRL_RXAMP_Msk | RAC_AUXCTRL_LODIVSEL_Msk);
	BUS_RegMaskedSet(&RAC->AUXCTRL, (param_4 << RAC_AUXCTRL_RXAMP_Pos) | (param_3 << RAC_AUXCTRL_LODIVSEL_Pos));
	BUS_RegMaskedClear(&SYNTH->AUXFREQ, SYNTH_AUXFREQ_MMDDENOM_Msk);
	BUS_RegMaskedSet(&SYNTH->AUXFREQ, param_1);
	BUS_RegMaskedSet(&RAC->AUXCTRL, RAC_AUXCTRL_LODIVEN_Msk | RAC_AUXCTRL_CHPEN_Msk | RAC_AUXCTRL_VCOEN_Msk);
	BUS_RegMaskedSet(&RAC->AUXENCTRL, RAC_AUXENCTRL_LDOEN_Msk);
	BUS_RegMaskedSet(&RAC->AUXCTRL, RAC_AUXCTRL_AUXSYNTHCLKEN_Msk);
	BUS_RegMaskedSet(&RAC->AUXCTRL, RAC_AUXCTRL_FPLLDIGEN_Msk);
	BUS_RegMaskedSet(&SYNTH->AUXVCDACCTRL, SYNTH_AUXVCDACCTRL_EN_Msk);
	BUS_RegMaskedClear(&RAC->AUXCTRL, RAC_AUXCTRL_CHPEN_Msk);
	BUS_RegMaskedSet(&RAC->AUXCTRL, RAC_AUXCTRL_FPLLDIGEN_Msk | RAC_AUXCTRL_VCOSTARTUP_Msk);
	
  PHY_UTILS_DelayUs(1000);
	
		do{
				SYNTH->CMD = SYNTH_CMD_AUXSTOP_Msk;
				SYNTH->CMD = SYNTH_CMD_AUXCAPCALSTART_Msk;
				while(SYNTH->STATUS & SYNTH_STATUS_AUXCAPCALRUNNING_Msk);
			} while (SYNTH->STATUS & SYNTH_STATUS_CAPCALERROR_Msk);
	BUS_RegMaskedSet(&RAC->AUXCTRL, RAC_AUXCTRL_CHPEN_Msk);		
	BUS_RegMaskedClear(&SYNTH->AUXVCDACCTRL, SYNTH_AUXVCDACCTRL_EN_Msk); 		
	SYNTH->CMD = SYNTH_CMD_AUXSTART_Msk;		
	BUS_RegMaskedClear(&RAC->AUXCTRL, RAC_AUXCTRL_FPLLDIGEN_Msk | RAC_AUXCTRL_VCOSTARTUP_Msk);		
	BUS_RegMaskedSet(&RAC->AUXCTRL, RAC_AUXCTRL_FPLLDIGEN_Msk);		
}



int32_t AUXPLL_Start(int param_1,uint32_t param_2,int param_3,uint32_t param_4)

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


