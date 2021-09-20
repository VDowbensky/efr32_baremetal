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
  if (uVar2 != 0) 
  {
    uVar1 = uVar2 * uVar1;
  }
  uVar3 = (uVar3 << 0x17) >> 0x1d;
  if (uVar3 != 0) 
  {
    uVar1 = uVar3 * uVar1;
  }
  return uVar1;
}



bool SYNTH_Is2p4GHz(void)

{
  uint uVar1;
  
  uVar1 = (RAC->IFPGACTRL);
  return SUB41(((uVar1 ^ 0x10) << 0x1b) >> 0x1f,0);
}



bool SYNTH_VcoRangeIsValid(uint32_t freq)

{
  undefined uVar1;
  uint32_t uVar2;
  uint uVar3;
  int iVar4;
  bool bVar5;
  bool bVar6;
  longlong lVar7;
  
  uVar2 = SYNTH_LoDivGet();
  lVar7 = __aeabi_ldivmod(2300000000,0,uVar2,0);
  uVar3 = (uint)((ulonglong)lVar7 >> 0x20);
  bVar5 = (uint)lVar7 <= freq;
  if ((int)(-(uint)!bVar5 - uVar3) < 0 == (lVar7 < 0 && (int)(~uVar3 + (uint)bVar5) < 0)) {
    lVar7 = __aeabi_ldivmod(2900000000,0,uVar2,0);
    iVar4 = (int)((ulonglong)lVar7 >> 0x20);
    uVar3 = (uint)lVar7;
    bVar6 = lVar7 < 0 && (int)(iVar4 + -1 + (uint)(freq <= uVar3)) < 0 != lVar7 < 0;
    bVar5 = (int)(iVar4 - (uint)(freq > uVar3)) < 0;
    if (bVar5 == bVar6) 
	{
      uVar3 = 1;
    }
    uVar1 = (undefined)uVar3;
    if (bVar5 != bVar6) 
	{
      uVar1 = 0;
    }
    return (bool)uVar1;
  }
  return false;
}



void SYNTH_RetimeLimitsConfig(uint32_t val)

{
  uint uVar1;
  uint32_t uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = SystemHFXOClockGet();
  uVar1 = (RAC->HFXORETIMECTRL);
  write_volatile_4(RAC->HFXORETIMECTRL,uVar1 & 0xfffff88f);
  uVar1 = (RAC->HFXORETIMECTRL);
  uVar3 = val / (uVar2 << 1);
  uVar4 = uVar3 - 1;
  if (6 < uVar3) 
  {
    uVar3 = 7;
  }
  if (6 < uVar4) 
  {
    uVar4 = 7;
  }
  write_volatile_4(RAC->HFXORETIMECTRL,uVar1 | uVar3 << 8 | uVar4 << 4);
}


void SYNTH_RetimeClkConfig(void)

{
  uint uVar1;
  uint uVar2;
  undefined4 in_r3;
  uint uVar3;
  undefined4 local_1c;
  undefined4 uStack24;
  undefined4 local_14;
  
  local_1c = 0x2010000;
  uStack24 = 0x3030302;
  local_14 = CONCAT31((int3)((uint)in_r3 >> 8),3);
  uVar1 = (SYNTH->CHCTRL);
  uVar2 = currChSpacing * uVar1 + currIfFrequency + currRfFrequency;
  uVar3 = (uint)*(byte *)((int)&local_1c + uVar2 / 625000000 + 1);
  uVar2 = uVar2 >> uVar3;
  uVar1 = (RAC->MMDCTRL);
  write_volatile_4(RAC->MMDCTRL,uVar1 & 0xffffc200);
  uVar1 = (RAC->MMDCTRL);
  write_volatile_4(RAC->MMDCTRL,
                   uVar1 | uVar3 << 0xc |
                   (uVar2 + (dcdcRetimeClkTarget >> 1)) / dcdcRetimeClkTarget - 1 |
                   (uint)*(byte *)((int)&local_1c + uVar2 / 325000000 + 1) << 10);
  SYNTH_RetimeLimitsConfig(uVar2);
}



void SYNTH_Config(uint32_t freq,uint32_t spacing)

{
  longlong lVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t freqval;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar2 = SYNTH_LoDivGet();
  SYNTH_VcoRangeIsValid(freq);
  uVar5 = (RAC->IFPGACTRL);
  if (uVar2 == 1) 
  {
    uVar5 = uVar5 & 0xffffffef;
  }
  else 
  {
    uVar5 = uVar5 | 0x10;
  }
  write_volatile_4(RAC->IFPGACTRL,uVar5);
  uVar3 = SystemHFXOClockGet();
  uVar6 = uVar2 * freq;
  currRfFrequency = freq;
  freqval = __aeabi_uldivmod(uVar6 * 0x80000,uVar6 >> 0xd,uVar3,0);
  write_volatile_4(SYNTH->FREQ,freqval);
  currIfFrequency = SYNTH_IfFreqCompute(freqval);
  lVar1 = (ulonglong)(uVar2 << 0x13) * (ulonglong)currIfFrequency;
  uVar4 = __aeabi_uldivmod((int)lVar1,
                           currIfFrequency * (uVar2 >> 0xd) + (int)((ulonglong)lVar1 >> 0x20),uVar3,
                           0);
  uVar5 = (SYNTH->IFFREQ);
  write_volatile_4(SYNTH->IFFREQ,uVar4 & 0xfffff | uVar5 & 0x100000);
  lVar1 = (ulonglong)(spacing << 0x13) * (ulonglong)uVar2;
  currChSpacing = spacing;
  uVar5 = __aeabi_uldivmod((int)lVar1,uVar2 * (spacing >> 0xd) + (int)((ulonglong)lVar1 >> 0x20),
                           uVar3,0);
  write_volatile_4(SYNTH->CHSP,uVar5);
  if (vcoGainPte == 0) 
  {
    uVar5 = (SYNTH->VCOGAIN);
    vcoGainPte = (byte)uVar5 & 0x3f;
  }
  uVar5 = (RAC->SR3);
  if ((int)(uVar5 << 0x1b) < 0) 
  {
    uVar6 = uVar6 / 24000000;
    write_volatile_4(SYNTH->VCOGAIN,
                     ((uint)vcoGainPte * 10000000) /
                     (uVar6 * uVar6 * 0x553 + uVar6 * -0xc60c + 0x192d50));
  }
  SYNTH_RetimeClkConfig();
}


void SYNTH_ChannelSet(uint8_t channel,bool rxcal)

{
  uint uVar1;
  
  do {
    do 
	{
      uVar1 = (RAC->STATUS);
      uVar1 = (uVar1 << 4) >> 0x1c;
    } while (uVar1 == 4);
  } while (uVar1 == 10);
  write_volatile_4(SYNTH->CHCTRL,(uint)channel);
  if (rxcal != false) 
  {
    write_volatile_4(RAC->CMD,0x80);
  }
  SYNTH_RetimeClkConfig();
}


void SYNTH_DigRouteRetimeEnable(void)

{
  uint uVar1;
  
  uVar1 = (RAC->SR3);
  write_volatile_4(RAC->SR3,uVar1 | 2);
}



void SYNTH_DigRouteRetimeDisable(void)

{
  uint uVar1;
  
  uVar1 = (RAC->SR3);
  write_volatile_4(RAC->SR3,uVar1 & 0xfffffffd);
}



void SYNTH_DCDCRetimeEnable(void)

{
  uint uVar1;
  
  uVar1 = (RAC->SR3);
  write_volatile_4(RAC->SR3,uVar1 | 4);
}



void SYNTH_DCDCRetimeClkSet(int32_t target)

{
  dcdcRetimeClkTarget = target;
  EMU_DCDCLnRcoBandSet((char)((target + 500000U) / 1000000) + ~EMU_DcdcLnRcoBand_5MHz);
}



void SYNTH_DCDCRetimeDisable(void)

{
  uint uVar1;
  
  uVar1 = (RAC->SR3);
  write_volatile_4(RAC->SR3,uVar1 & 0xfffffffb);
}



void SYNTH_KvnFreqCompensationEnable(void)

{
  uint uVar1;
  
  uVar1 = (RAC->SR3);
  write_volatile_4(RAC->SR3,uVar1 | 0x10);
}



void SYNTH_KvnFreqCompensationDisable(void)

{
  uint uVar1;
  
  uVar1 = (RAC->SR3);
  write_volatile_4(RAC->SR3,uVar1 & 0xffffffef);
  if (vcoGainPte != 0) 
  {
    write_volatile_4(SYNTH->VCOGAIN,(uint)vcoGainPte);
  }
}


