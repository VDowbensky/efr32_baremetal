#include "synth.h"



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



uint32_t SYNTH_IfFreqCompute(uint32_t freqval)

{
  uint32_t uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = MODEM->CF;
  uVar2 = (MODEM->CF << 6) >> 0x1d;
  uVar3 = uVar2 - 1;
  if (uVar3 < 4) freqval = (uint32_t)(byte)(&CSWTCH_14)[uVar2];
  uVar2 = MODEM->CF;
  if (3 < uVar3) freqval = 7;
  if (false) 
  {
switchD_00007366_caseD_1:
    uVar2 = freqval << 2;
  }
  else 
  {
    switch(uVar2 & 7) 
	{
    case 0:
      uVar2 = freqval * 3;
      break;
    default:
      goto switchD_00007366_caseD_1;
    case 3:
    case 4:
      uVar2 = freqval << 3;
    }
  }
  uVar1 = SystemHFXOClockGet();
  return uVar1 / uVar2;
}



uint32_t SYNTH_LoDivGet(void)

{
  uint32_t uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = (SYNTH->DIVCTRL);
  uVar1 = uVar3 & 7;
  uVar2 = (uVar3 << 0x17) >> 0x1a & 7;
  if (uVar2 != 0) uVar1 = uVar2 * uVar1;
  uVar3 = (uVar3 << 0x17) >> 0x1d;
  if (uVar3 != 0) uVar1 = uVar3 * uVar1;
  return uVar1;
}



bool SYNTH_Is2p4GHz(void)

{
  return SUB41(((RAC->IFPGACTRL ^ 0x10) << 0x1b) >> 0x1f,0);
}



bool SYNTH_VcoRangeIsValid(uint32_t freq)

{
  uint32_t div;
  div = SYNTH_LoDivGet();
  if((freq * div < VCO_MIN_FREQ) || (freq * div > VCO_MAX_FREQ)) return false;
  else return true;
}



void SYNTH_RetimeLimitsConfig(uint32_t val)

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
  uint uVar1;
  uint rxfreq;
  undefined4 in_r3;
  uint uVar3;
  undefined4 local_1c;
  undefined4 uStack24;
  undefined4 local_14;
  
  local_1c = 0x2010000;

  rxfreq = currChSpacing * SYNTH->CHCTRL + currIfFrequency + currRfFrequency;
  uVar3 = (uint)*(byte *)((int)&local_1c + rxfreq / 625000000 + 1);
  rxfreq = rxfreq >> uVar3;
  RAC->MMDCTRL &= ~(RAC_MMDCTRL_MMDDIVRSDCDC_Msk | RAC_MMDCTRL_MMDDIVDCDC_Msk); //0xffffc200;
  RAC->MMDCTRL |= uVar3 << RAC_MMDCTRL_MMDDIVRSDIG_Pos | ((rxfreq + (dcdcRetimeClkTarget >> 1)) / dcdcRetimeClkTarget - 1 | (uint)*(byte *)((int)&local_1c + rxfreq / 325000000 + 1)) << RAC_MMDCTRL_MMDDIVRSDCDC_Pos;
  SYNTH_RetimeLimitsConfig(rxfreq);
}



void SYNTH_Config(uint32_t freq,uint32_t spacing)

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


void SYNTH_ChannelSet(uint8_t channel,bool rxcal)

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



void SYNTH_DCDCRetimeClkSet(int32_t target)

{
  dcdcRetimeClkTarget = target;
  EMU_DCDCLnRcoBandSet(((target + 500000U) / 1000000) + ~EMU_DcdcLnRcoBand_5MHz);
  //EMU_DCDCLnRcoBandSet((target + 500000U) / 1000000 - 3 & 0xff);
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


