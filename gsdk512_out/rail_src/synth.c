#include "synth.h"

//vcoGainPte;
//currRfFrequency;
//currChSpacing;
//currIfFrequency;
//dcdcRetimeClkTarget = 0x006acfc0; 7000000

static const unsigned char DAT_00010328[9UL + 1] = {0x00, 0x00, 0x01, 0x02, 0x02, 0x03, 0x03, 0x03, 0x03, 0x00};

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
  uint32_t lodiv;

  lodiv = SYNTH->DIVCTRL & 7;
  if ((SYNTH->DIVCTRL << 0x17) >> 0x1a & 7 != 0) lodiv = ((SYNTH->DIVCTRL << 0x17) >> 0x1a & 7) * lodiv;
  if ((SYNTH->DIVCTRL << 0x17) >> 0x1d != 0) lodiv = ((SYNTH->DIVCTRL << 0x17) >> 0x1d) * lodiv;
  return lodiv;
}



bool SYNTH_Is2p4GHz(void)

{
  return ((RAC->IFPGACTRL ^ 0x10) << 0x1b) >> 0x1f;
}



bool SYNTH_VcoRangeIsValid(uint32_t freq)

{
  if (((freq * SYNTH_LoDivGet()) > 2300000000) && ((freq * SYNTH_LoDivGet()) < 2900000000)) return true;
  else return false;
}



void SYNTH_RetimeLimitsConfig(uint32_t freq)

{
  uint32_t res;

  res = freq / SystemHFXOClockGet();
  if (((freq - SystemHFXOClockGet() * (freq / SystemHFXOClockGet())) * 100) / SystemHFXOClockGet() == 0) res--;
  BUS_RegMaskedClear(&RAC->HFXORETIMECTRL,0x770);
  BUS_RegMaskedSet(&RAC->HFXORETIMECTRL,((res >> 1) - 1) * 0x10 | ((res + 1 >> 1) - 1) * 0x100;
}



void SYNTH_RetimeClkConfig(void)

{
  uint uVar1;
  int32_t iffreq;
  uint32_t channel;
  undefined4 local_1c;
  undefined4 uStack24;
  undefined local_14;
  
  local_1c = 0x2010000;
  uStack24 = 0x3030302;
  local_14 = 3;
  channel = SYNTH->CHCTRL;
  uVar1 = SYNTH->IFFREQ;
  iffreq = currIfFrequency;
  if ((SYNTH->IFFREQ & 0x100000) == 0) iffreq = -currIfFrequency;

  uVar1 = currChSpacing * channel + currRfFrequency + iffreq;
  
  uVar3 = (uint)*(byte *)((int)&local_1c + uVar1 / 625000000 + 1);
  uVar1 = uVar1 >> uVar3;
  BUS_RegMaskedClear(&RAC->MMDCTRL,0x3dff);
  BUS_RegMaskedSet(&RAC->MMDCTRL,(uVar1 + (dcdcRetimeClkTarget >> 1)) / dcdcRetimeClkTarget - 1 | uVar3 << 0xc |(uint)*(byte *)((int)&local_1c + uVar1 / 325000000 + 1) << 10);
  SYNTH_RetimeLimitsConfig();
}



/* void SYNTH_Config(int32_t freq,uint32_t step)

{
  longlong lVar1;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar3 = SYNTH_LoDivGet();
  SYNTH_VcoRangeIsValid(freq);
  if (SYNTH_LoDivGet() == 1) BUS_RegMaskedClear(&RAC->IFPGACTRL,0x10); 
  else BUS_RegMaskedSet(&RAC->IFPGACTRL,0x10);
  
  uVar4 = SystemHFXOClockGet();
  uVar6 = uVar3 * freq;
  currRfFrequency = freq;
  uVar5 = __aeabi_uldivmod(uVar6 * 0x80000,uVar6 >> 0xd,uVar4,0);
  SYNTH->FREQ = uVar5;
  uVar5 = SYNTH->IFFREQ;
  lVar1 = (ulonglong)uVar4 * (ulonglong)(uVar5 & 0xfffff);
  currIfFrequency = __aeabi_uldivmod((int)lVar1,(int)((ulonglong)lVar1 >> 0x20),uVar3 << 0x13,0);
  lVar1 = (ulonglong)(step << 0x13) * (ulonglong)uVar3;
  currChSpacing = step;
  uVar3 = __aeabi_uldivmod((int)lVar1,uVar3 * (step >> 0xd) + (int)((ulonglong)lVar1 >> 0x20),
                           uVar4,0);
  SYNTH->CHSP = uVar3;
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

void SYNTH_ChannelSet(uint16_t ch,int rxcal)

{
  do 
  {
	while ((RAC->STATUS & RAC_STATUS_STATE_Msk) >> RAC_STATUS_STATE_Pos == 4);
  } while ((RAC->STATUS & RAC_STATUS_STATE_Msk) >> RAC_STATUS_STATE_Pos == 10);
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



void SYNTH_DCDCRetimeClkSet(int target)

{
  dcdcRetimeClkTarget = target;
  EMU_DCDCLnRcoBandSet((target + 500000U) / 1000000 - 3 & 0xff);
}



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
  if (vcoGainPte != 0) SYNTH->VCOGAIN = vcoGainPte;
}


