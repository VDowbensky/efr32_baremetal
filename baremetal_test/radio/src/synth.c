#include "synth.h"
#include <stdbool.h>
#include "em_bus.h"
#include "em_assert.h"
#include "em_emu.h"
#include "nibblebits.h"

uint32_t currRfFrequency;
uint32_t currIfFrequency;
uint32_t currChSpacing;
uint8_t vcoGainPte;

uint8_t Channel = 0;

uint32_t dcdcRetimeClkTarget;


uint32_t SYNTH_RfFreqGet(void)

{
  return currRfFrequency;
}



uint32_t SYNTH_ChSpacingGet(void)

{
  return currChSpacing;
}



uint32_t SYNTH_IfFreqGet(void)

{
  return currIfFrequency;
}



uint32_t SYNTH_IfFreqCompute(void)

{
  uint32_t uVar2;
	uint32_t param_1;
  //uVar1 = (MODEM->CF << 6) >> 0x1d; //CFOSR
  //uVar1 = (MODEM->CF & MODEM_CF_CFOSR_Msk) >> MODEM_CF_CFOSR_Pos;
  //uVar2 = uVar1 - 1;
	uVar2 = ((MODEM->CF & MODEM_CF_CFOSR_Msk) >> MODEM_CF_CFOSR_Pos) - 1;
	
  //if (uVar2 < 4) param_1 = (uint32_t)(uint8_t)(&DAT_000103c0)[uVar1];
	//param_1 = (uint)(byte)(&CSWTCH.14)[uVar2];
	if (uVar2 < 4) param_1 = (uint32_t)nibblebits[24 + uVar2 + 1];
  if (3 < uVar2) param_1 = 7;
		switch(MODEM->CF & MODEM_CF_DEC0_Msk)
		{
    case 0:
      param_1 = param_1 * 3;
      break;

    case 3:
    case 4:
      param_1 = param_1 << 3;
		  break;
		
		 default:
     param_1 = param_1 << 2;
		 break;
    }
  return SystemHFXOClockGet() / param_1;
}



uint32_t SYNTH_LoDivGet(void)

{
	uint32_t div;
	uint32_t tmp;
	
  div = SYNTH->DIVCTRL & 7;
  tmp = (SYNTH->DIVCTRL & 0x1FF)/8 & 7;
  if (tmp != 0) div = div * tmp;
  tmp = (SYNTH->DIVCTRL & 0x1FF)/64;
  if (tmp != 0) div = div * tmp;
  return div;
}



uint8_t SYNTH_Is2p4GHz(void)

{
  return ((RAC->IFPGACTRL ^ RAC_IFPGACTRL_BANDSEL_Msk) >> RAC_IFPGACTRL_BANDSEL_Pos);
}



bool SYNTH_VcoRangeIsValid(uint32_t freq)

{
  uint32_t div;
  div = SYNTH_LoDivGet();
  if((freq * div < VCO_MIN_FREQ) || (freq * div > VCO_MAX_FREQ)) return false;
  else return true;
}



void SYNTH_RetimeLimitsConfig(uint32_t freq)

{
  uint32_t liml;
  uint32_t limh;
	BUS_RegMaskedClear(&RAC->HFXORETIMECTRL, (RAC_HFXORETIMECTRL_LIMITH_Msk | RAC_HFXORETIMECTRL_LIMITL_Msk));
  liml = freq / (SystemHFXOClockGet() * 2);
  limh = liml - 1;
  if (6 < liml) liml = 7;
  if (6 < limh) limh = 7;
	RAC->HFXORETIMECTRL |= (liml << RAC_HFXORETIMECTRL_LIMITL_Pos) | (limh << RAC_HFXORETIMECTRL_LIMITH_Pos);
}


void SYNTH_RetimeClkConfig(void)

{
  uint32_t rxfreq;
  uint32_t uVar3;
//  uint32_t local_1c;
//  uint32_t uStack24;
//  uint32_t local_14;
//
//  local_1c = 0x2010000;
//  uStack24 = 0x3030302;
  //local_14 = CONCAT31((int3)((uint)in_r3 >> 8),3);
	//local_14 = 3;
  rxfreq = currChSpacing * SYNTH->CHCTRL + currIfFrequency + currRfFrequency;
  uVar3 = 0x1c + rxfreq / 625000000 + 1;
  rxfreq = rxfreq >> uVar3;
//  RAC->MMDCTRL &= 0xffffc200;
		BUS_RegMaskedClear(&RAC->MMDCTRL, 0x3dff);
		//RAC->MMDCTRL |= uVar3 << 0xc | (rxfreq + (dcdcRetimeClkTarget >> 1)) / dcdcRetimeClkTarget - 1 |(uint32_t)*(uint8_t *)((int)&local_1c + rxfreq / 325000000 + 1) << 10;
	RAC->MMDCTRL |= uVar3 << 0xc | (rxfreq + (dcdcRetimeClkTarget >> 1)) / dcdcRetimeClkTarget - 1 |(0x1c + rxfreq / 325000000 + 1) << 10;
	//MMDDIVRSDIG, MMDDIVRSDCDC
  //SYNTH_RetimeLimitsConfig(3); //unknown argument
	SYNTH_RetimeLimitsConfig(rxfreq); //unknown argument
}



void SYNTH_Config(uint32_t base_freg, uint32_t spacing)

{
  uint32_t lodiv;
  uint32_t vcofreq;
  uint32_t xofreq;
  uint32_t k_ifreq;
  
  lodiv = SYNTH_LoDivGet();
  SYNTH_VcoRangeIsValid(base_freg);

  if (lodiv == 1) RAC->IFPGACTRL |= RAC_IFPGACTRL_BANDSEL_Msk;//&= 0xffffffef;
  else RAC->IFPGACTRL &= ~RAC_IFPGACTRL_BANDSEL_Msk;//|= 0x10;

  xofreq = SystemHFXOClockGet();
  currRfFrequency = base_freg;
  vcofreq = currRfFrequency * lodiv;
  SYNTH->FREQ = ((uint64_t)vcofreq * 524288)/xofreq;
  currIfFrequency = SYNTH_IfFreqCompute();
  k_ifreq = ((uint64_t)currIfFrequency * lodiv * 524288)/xofreq;
  SYNTH->IFFREQ &= SYNTH_IFFREQ_LOSIDE_Msk;
  SYNTH->IFFREQ |= (k_ifreq & SYNTH_IFFREQ_IFFREQ_Msk);

  currChSpacing = spacing;
  SYNTH->CHSP = ((uint64_t)currChSpacing * lodiv * 524288)/xofreq;

  if (vcoGainPte == 0) vcoGainPte = (uint8_t)SYNTH->VCOGAIN & SYNTH_VCOGAIN_VCOGAIN_Msk;
  if(RAC->SR3 & 0x10)
  {
	  vcofreq = vcofreq / 24000000;
    //SYNTH->VCOGAIN = ((uint64_t)vcoGainPte * 10000000) / (vcofreq * vcofreq * 0x553 + vcofreq * -0xc60c + 0x192d50);
    SYNTH->VCOGAIN = ((uint64_t)vcoGainPte * 10000000) / (1363*(vcofreq*vcofreq) - 50700*vcofreq + 1650000);
  }
  SYNTH_RetimeClkConfig();
}



void SYNTH_ChannelSet(uint16_t ch,int rxcal)

{
  do {
				while ((RAC->STATUS & RAC_STATUS_STATE_Msk) >> RAC_STATUS_STATE_Pos == 4);
  	 } 	while ((RAC->STATUS & RAC_STATUS_STATE_Msk) >> RAC_STATUS_STATE_Pos == 10);

  SYNTH->CHCTRL = ch;
  if (rxcal != 0) RAC->CMD = RAC_CMD_RXCAL_Msk;
  SYNTH_RetimeClkConfig();
}



void SYNTH_DigRouteRetimeEnable(void)

{
	RAC->SR3 |= 2;
}



void SYNTH_DigRouteRetimeDisable(void)

{
	RAC->SR3 &= 0xfffffffd;
}



void SYNTH_DCDCRetimeEnable(void)

{
	RAC->SR3 |= 4;
}



void SYNTH_DCDCRetimeClkSet(int target)

{
  dcdcRetimeClkTarget = target;
  EMU_DCDCLnRcoBandSet((target + 500000U) / 1000000 - 3 & 0xff);
}



void SYNTH_DCDCRetimeDisable(void)

{
	RAC->SR3 &= 0xfffffffb;
}



void SYNTH_KvnFreqCompensationEnable(void)

{
	RAC->SR3 |= 0x10;
}



void SYNTH_KvnFreqCompensationDisable(void)

{
  RAC->SR3 &= 0xffffffef;
  if (vcoGainPte != 0) SYNTH->VCOGAIN = (uint32_t)vcoGainPte;
}


