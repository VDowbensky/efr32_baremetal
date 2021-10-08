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



bool SYNTH_Is2p4GHz(void)

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
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 local_1c;
  undefined4 uStack24;
  undefined local_14;
  
  local_1c = 0x2010000;
  uStack24 = 0x3030302;
  local_14 = 3;
  uVar3 = SYNTH->CHCTRL;
  uVar1 = SYNTH->IFFREQ;
  iVar2 = currIfFrequency;
  if ((uVar1 & 0x100000) == 0) iVar2 = -currIfFrequency;
  uVar1 = currChSpacing * uVar3 + currRfFrequency + iVar2;
  uVar3 = (uint)*(byte *)((int)&local_1c + uVar1 / 625000000 + 1);
  uVar1 = uVar1 >> uVar3;
  BUS_RegMaskedClear(&RAC->MMDCTRL,0x3dff);
  BUS_RegMaskedSet(&RAC->MMDCTRL,(uVar1 + (dcdcRetimeClkTarget >> 1)) / dcdcRetimeClkTarget - 1 | uVar3 << 0xc | (uint)*(byte *)((int)&local_1c + uVar1 / 325000000 + 1) << 10);
  SYNTH_RetimeLimitsConfig(uVar1);
}

/* void SYNTH_RetimeClkConfig(void)

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
} */

/* void SYNTH_Config(uint32_t freq,uint32_t spacing)

{
  longlong lVar1;
  RAC_SET *pRVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar3 = SYNTH_LoDivGet();
  SYNTH_VcoRangeIsValid(freq);
  if (uVar3 == 1) BUS_RegMaskedClear(&RAC->IFPGACTRL,0x10);
  else BUS_RegMaskedSet(&RAC->IFPGACTRL,0x10);
  uVar4 = SystemHFXOClockGet();
  uVar6 = uVar3 * freq;
  currRfFrequency = freq;
  uVar5 = __aeabi_uldivmod(uVar6 * 0x80000,uVar6 >> 0xd,uVar4,0);
  SYNTH->FREQ = uVar5;
  uVar5 = read_volatile_4(SYNTH->IFFREQ);
  lVar1 = (ulonglong)uVar4 * (ulonglong)(uVar5 & 0xfffff);
  currIfFrequency = __aeabi_uldivmod((int)lVar1,(int)((ulonglong)lVar1 >> 0x20),uVar3 << 0x13,0);
  lVar1 = (ulonglong)(spacing << 0x13) * (ulonglong)uVar3;
  currChSpacing = spacing;
  uVar5 = __aeabi_uldivmod((int)lVar1,uVar3 * (spacing >> 0xd) + (int)((ulonglong)lVar1 >> 0x20),uVar4,0);
  SYNTH->CHSP = uVar5;
  if (vcoGainPte == 0) vcoGainPte = (byte)SYNTH->VCOGAIN & 0x3f;
  if ((int)(RAC->SR3 << 0x1b) < 0) 
  {
    uVar6 = uVar6 / 24000000;
    SYNTH->VCOGAIN = ((uint)vcoGainPte * 10000000) / (uVar6 * uVar6 * 0x553 + uVar6 * -0xc60c + 0x192d50);
  }
  SYNTH_RetimeClkConfig();
} */

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

void SYNTH_ChannelSet(uint32_t channel,bool rxcal)

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
  BUS_RegMaskedSet(&RAC->SR3,2);
}



void SYNTH_DigRouteRetimeDisable(void)

{
  BUS_RegMaskedClear(&RAC->SR3,2);
}



void SYNTH_DCDCRetimeEnable(void)

{
  BUS_RegMaskedSet(&RAC->SR3,4);
}



void SYNTH_DCDCRetimeClkSet(uint32_t target)

{
  dcdcRetimeClkTarget = target;
  EMU_DCDCLnRcoBandSet((char)((target + 500000) / 1000000) + ~emuDcdcLnRcoBand_5MHz);
}

/* void SYNTH_DCDCRetimeClkSet(int target)

{
  dcdcRetimeClkTarget = target;
  EMU_DCDCLnRcoBandSet((target + 500000U) / 1000000 - 3 & 0xff);
} */

void SYNTH_DCDCRetimeDisable(void)

{
  BUS_RegMaskedClear(&RAC->SR3,4);
}



void SYNTH_KvnFreqCompensationEnable(void)

{
  BUS_RegMaskedSet(&RAC->SR3,0x10);
}



void SYNTH_KvnFreqCompensationDisable(void)

{
  BUS_RegMaskedClear(&RAC->SR3,0x10);
  if (vcoGainPte != 0) SYNTH->VCOGAIN = (uint32_t)vcoGainPte;
}


