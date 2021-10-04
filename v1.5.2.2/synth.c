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
  uint32_t uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = read_volatile_4(Peripherals::SYNTH.DIVCTRL);
  uVar1 = uVar3 & 7;
  uVar2 = (uVar3 << 0x17) >> 0x1a & 7;
  if (uVar2 != 0) {
    uVar1 = uVar2 * uVar1;
  }
  uVar3 = (uVar3 << 0x17) >> 0x1d;
  if (uVar3 != 0) {
    uVar1 = uVar3 * uVar1;
  }
  return uVar1;
}



bool SYNTH_Is2p4GHz(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::RAC.IFPGACTRL);
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
    if (bVar5 == bVar6) {
      uVar3 = 1;
    }
    uVar1 = (undefined)uVar3;
    if (bVar5 != bVar6) {
      uVar1 = 0;
    }
    return (bool)uVar1;
  }
  return false;
}




void SYNTH_RetimeLimitsConfig(uint32_t freq)

{
  uint32_t uVar1;
  uint uVar2;
  
  uVar1 = SystemHFXOClockGet();
  uVar2 = freq / uVar1;
  if (((freq - uVar1 * uVar2) * 100) / uVar1 == 0) {
    uVar2 = uVar2 - 1;
  }
  write_volatile_4(Peripherals::RAC_CLR.HFXORETIMECTRL,0x770);
  write_volatile_4(Peripherals::RAC_SET.HFXORETIMECTRL,
                   ((uVar2 >> 1) - 1) * 0x10 | ((uVar2 + 1 >> 1) - 1) * 0x100);
  return;
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
  uVar3 = read_volatile_4(Peripherals::SYNTH.CHCTRL);
  uVar1 = read_volatile_4(Peripherals::SYNTH.IFFREQ);
  iVar2 = currIfFrequency;
  if ((uVar1 & 0x100000) == 0) {
    iVar2 = -currIfFrequency;
  }
  uVar1 = currChSpacing * uVar3 + currRfFrequency + iVar2;
  uVar3 = (uint)*(byte *)((int)&local_1c + uVar1 / 625000000 + 1);
  uVar1 = uVar1 >> uVar3;
  write_volatile_4(Peripherals::RAC_CLR.MMDCTRL,0x3dff);
  write_volatile_4(Peripherals::RAC_SET.MMDCTRL,
                   (uVar1 + (dcdcRetimeClkTarget >> 1)) / dcdcRetimeClkTarget - 1 | uVar3 << 0xc |
                   (uint)*(byte *)((int)&local_1c + uVar1 / 325000000 + 1) << 10);
  SYNTH_RetimeLimitsConfig(uVar1);
  return;
}



void SYNTH_Config(uint32_t freq,uint32_t spacing)

{
  longlong lVar1;
  RAC_SET *pRVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar3 = SYNTH_LoDivGet();
  SYNTH_VcoRangeIsValid(freq);
  if (uVar3 == 1) {
    pRVar2 = (RAC_SET *)&Peripherals::RAC_CLR;
  }
  else {
    pRVar2 = &Peripherals::RAC_SET;
  }
  ((RAC_CLR *)pRVar2)->IFPGACTRL = 0x10;
  uVar4 = SystemHFXOClockGet();
  uVar6 = uVar3 * freq;
  currRfFrequency = freq;
  uVar5 = __aeabi_uldivmod(uVar6 * 0x80000,uVar6 >> 0xd,uVar4,0);
  write_volatile_4(Peripherals::SYNTH.FREQ,uVar5);
  uVar5 = read_volatile_4(Peripherals::SYNTH.IFFREQ);
  lVar1 = (ulonglong)uVar4 * (ulonglong)(uVar5 & 0xfffff);
  currIfFrequency = __aeabi_uldivmod((int)lVar1,(int)((ulonglong)lVar1 >> 0x20),uVar3 << 0x13,0);
  lVar1 = (ulonglong)(spacing << 0x13) * (ulonglong)uVar3;
  currChSpacing = spacing;
  uVar5 = __aeabi_uldivmod((int)lVar1,uVar3 * (spacing >> 0xd) + (int)((ulonglong)lVar1 >> 0x20),
                           uVar4,0);
  write_volatile_4(Peripherals::SYNTH.CHSP,uVar5);
  if (vcoGainPte == 0) {
    uVar5 = read_volatile_4(Peripherals::SYNTH.VCOGAIN);
    vcoGainPte = (byte)uVar5 & 0x3f;
  }
  uVar5 = read_volatile_4(Peripherals::RAC.SR3);
  if ((int)(uVar5 << 0x1b) < 0) {
    uVar6 = uVar6 / 24000000;
    write_volatile_4(Peripherals::SYNTH.VCOGAIN,
                     ((uint)vcoGainPte * 10000000) /
                     (uVar6 * uVar6 * 0x553 + uVar6 * -0xc60c + 0x192d50));
  }
  SYNTH_RetimeClkConfig();
  return;
}



void SYNTH_ChannelSet(uint32_t channel,bool rxcal)

{
  uint uVar1;
  
  do {
    do {
      uVar1 = read_volatile_4(Peripherals::RAC.STATUS);
      uVar1 = (uVar1 << 4) >> 0x1c;
    } while (uVar1 == 4);
  } while (uVar1 == 10);
  write_volatile_4(Peripherals::SYNTH.CHCTRL,channel);
  if (rxcal != false) {
    write_volatile_4(Peripherals::RAC.CMD,0x80);
  }
  SYNTH_RetimeClkConfig();
  return;
}



void SYNTH_DigRouteRetimeEnable(void)

{
  write_volatile_4(Peripherals::RAC_SET.SR3,2);
  return;
}



void SYNTH_DigRouteRetimeDisable(void)

{
  write_volatile_4(Peripherals::RAC_CLR.SR3,2);
  return;
}



void SYNTH_DCDCRetimeEnable(void)

{
  write_volatile_4(Peripherals::RAC_SET.SR3,4);
  return;
}



void SYNTH_DCDCRetimeClkSet(uint32_t target)

{
  dcdcRetimeClkTarget = target;
  EMU_DCDCLnRcoBandSet((char)((target + 500000) / 1000000) + ~emuDcdcLnRcoBand_5MHz);
  return;
}



void SYNTH_DCDCRetimeDisable(void)

{
  write_volatile_4(Peripherals::RAC_CLR.SR3,4);
  return;
}



void SYNTH_KvnFreqCompensationEnable(void)

{
  write_volatile_4(Peripherals::RAC_SET.SR3,0x10);
  return;
}



void SYNTH_KvnFreqCompensationDisable(void)

{
  write_volatile_4(Peripherals::RAC_CLR.SR3,0x10);
  if (vcoGainPte != 0) {
    write_volatile_4(Peripherals::SYNTH.VCOGAIN,(uint)vcoGainPte);
  }
  return;
}


