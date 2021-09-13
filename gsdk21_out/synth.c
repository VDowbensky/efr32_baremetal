#include "synth.h"



undefined4 SYNTH_RfFreqGet(void)

{
  return currRfFrequency;
}



undefined4 SYNTH_ChSpacingGet(void)

{
  return currChSpacing;
}



undefined4 SYNTH_IfFreqGet(void)

{
  return currIfFrequency;
}



uint SYNTH_LoDivGet(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = read_volatile_4(SYNTH_DIVCTRL);
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



uint SYNTH_Is2p4GHz(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(RAC_IFPGACTRL);
  return ((uVar1 ^ 0x10) << 0x1b) >> 0x1f;
}



uint SYNTH_VcoRangeIsValid(uint param_1)

{
  uint uVar1;
  
  uVar1 = SYNTH_LoDivGet();
  if (uVar1 != 0) {
    if (2300000000 / uVar1 <= param_1) {
      return (uint)(param_1 <= 2900000000 / uVar1);
    }
    uVar1 = 0;
  }
  return uVar1;
}



uint SYNTH_ChannelGet(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(SYNTH_CHCTRL);
  return uVar1 & 0x3f;
}



void SYNTH_RetimeLimitsConfig(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = SystemHFXOClockGet();
  if (uVar1 == 0) {
    RAILInt_Assert(0,0x2b);
    uVar1 = 1;
  }
  uVar2 = param_1 / uVar1;
  if (((param_1 - uVar1 * uVar2) * 100) / uVar1 == 0) {
    uVar2 = uVar2 - 1;
  }
  uVar3 = (uVar2 >> 1) - 1;
  uVar1 = (uVar2 + 1 >> 1) - 1;
  if (((7 < uVar3) || (7 < uVar1)) || ((uVar3 == 0 && (uVar1 == 0)))) {
    RAILInt_Assert(0,0x10,100,uVar2,param_4);
  }
  write_volatile_4(RAC_HFXORETIMECTRL_CLR,0x770);
  write_volatile_4(RAC_HFXORETIMECTRL_SET,uVar3 * 0x10 | uVar1 * 0x100);
  return;
}



void SYNTH_RetimeClkConfig(void)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 local_24;
  undefined4 uStack32;
  undefined local_1c;
  
  local_24 = 0x2010000;
  uStack32 = 0x3030302;
  local_1c = 3;
  uVar3 = read_volatile_4(SYNTH_CHCTRL);
  iVar2 = currChSpacing * uVar3 + currRfFrequency;
  uVar3 = read_volatile_4(SYNTH_IFFREQ);
  if ((uVar3 & 0x100000) == 0) {
    uVar3 = iVar2 - currIfFrequency;
  }
  else {
    uVar3 = iVar2 + currIfFrequency;
  }
  uVar4 = (uint)*(byte *)((int)&local_24 + uVar3 / 625000000 + 1);
  uVar3 = uVar3 >> uVar4;
  bVar1 = *(byte *)((int)&local_24 + uVar3 / 325000000 + 1);
  if (dcdcRetimeClkTarget == 0) {
    RAILInt_Assert(0,0x2b);
    dcdcRetimeClkTarget = 1;
  }
  write_volatile_4(RAC_MMDCTRL_CLR,0x3dff);
  write_volatile_4(RAC_MMDCTRL_SET,
                   (uVar3 + (dcdcRetimeClkTarget >> 1)) / dcdcRetimeClkTarget - 1 | uVar4 << 0xc |
                   (uint)bVar1 << 10);
  SYNTH_RetimeLimitsConfig(uVar3);
  return;
}



undefined4 SYNTH_Config(int param_1,uint param_2)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  
  uVar2 = SYNTH_LoDivGet();
  iVar3 = SYNTH_VcoRangeIsValid(param_1);
  if (iVar3 == 0) {
    RAILInt_Assert(0,0xe);
  }
  else {
    if (uVar2 == 1) {
      puVar6 = &RAC_IFPGACTRL_CLR;
    }
    else {
      puVar6 = &RAC_IFPGACTRL_SET;
    }
    *puVar6 = 0x10;
    uVar4 = SystemHFXOClockGet();
    if ((uVar2 != 0) && (uVar4 != 0)) {
      uVar7 = uVar2 * param_1;
      currRfFrequency = param_1;
      uVar5 = __aeabi_uldivmod(uVar7 * 0x80000,uVar7 >> 0xd,uVar4,0);
      write_volatile_4(SYNTH_FREQ,uVar5);
      uVar5 = read_volatile_4(SYNTH_IFFREQ);
      lVar1 = (ulonglong)uVar4 * (ulonglong)(uVar5 & 0xfffff);
      currIfFrequency = __aeabi_uldivmod((int)lVar1,(int)((ulonglong)lVar1 >> 0x20),uVar2 << 0x13,0)
      ;
      lVar1 = (ulonglong)(param_2 << 0x13) * (ulonglong)uVar2;
      currChSpacing = param_2;
      uVar2 = __aeabi_uldivmod((int)lVar1,uVar2 * (param_2 >> 0xd) + (int)((ulonglong)lVar1 >> 0x20)
                               ,uVar4,0);
      write_volatile_4(SYNTH_CHSP,uVar2);
      if (vcoGainPte == 0) {
        uVar2 = read_volatile_4(SYNTH_VCOGAIN);
        vcoGainPte = (byte)uVar2 & 0x3f;
      }
      uVar2 = read_volatile_4(RAC_SR3);
      if ((int)(uVar2 << 0x19) < 0) {
        uVar7 = uVar7 / 24000000;
        uVar2 = uVar7 * uVar7 * 0x54d + uVar7 * -0xc60c + 0x192d50;
        if (uVar2 == 0) {
          RAILInt_Assert(0,0x2b);
          uVar2 = 1;
        }
        write_volatile_4(SYNTH_VCOGAIN,((uint)vcoGainPte * 10000000) / uVar2);
      }
      SYNTH_RetimeClkConfig();
      return 0;
    }
  }
  return 2;
}



void SYNTH_ChannelSet(uint param_1,int param_2)

{
  uint uVar1;
  
  do {
    do {
      uVar1 = read_volatile_4(RAC_STATUS);
      uVar1 = (uVar1 << 4) >> 0x1c;
    } while (uVar1 == 4);
  } while (uVar1 == 10);
  uVar1 = count_leading_zeroes(uVar1);
  RAILInt_Assert(uVar1 >> 5,0xf);
  write_volatile_4(SYNTH_CHCTRL,param_1);
  if (param_2 != 0) {
    write_volatile_4(RAC_CMD,0x80);
  }
  SYNTH_RetimeClkConfig();
  return;
}



void SYNTH_DigRouteRetimeEnable(void)

{
  write_volatile_4(RAC_SR3_SET,2);
  return;
}



void SYNTH_DigRouteRetimeDisable(void)

{
  write_volatile_4(RAC_SR3_CLR,2);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void SYNTH_DCDCRetimeClkSet(int param_1)

{
  uint uVar1;
  
  write_volatile_4(RAC_SR3_SET,0x80000);
  dcdcRetimeClkTarget = param_1;
  if (_DAT_43c60980 != 0) {
    uVar1 = (param_1 + 500000U) / 1000000 - 3 & 0xff;
    if ((_DAT_400e3070 & 7) != uVar1) {
      EMU_DCDCLnRcoBandSet(uVar1);
    }
    if (dcdcRetimeDesired != '\0') {
      write_volatile_4(RAC_SR3_CLR,0xf0000);
      write_volatile_4(RAC_SR3_SET,uVar1 << 0x10);
    }
  }
  return;
}



void SYNTH_DCDCRetimeEnable(void)

{
  dcdcRetimeDesired = 1;
  SYNTH_DCDCRetimeClkSet(dcdcRetimeClkTarget);
  return;
}



void SYNTH_DCDCRetimeDisable(void)

{
  write_volatile_4(RAC_SR3_SET,0x80000);
  dcdcRetimeDesired = 0;
  return;
}



void SYNTH_KvnFreqCompensationEnable(void)

{
  write_volatile_4(RAC_SR3_SET,0x40);
  return;
}



void SYNTH_KvnFreqCompensationDisable(void)

{
  write_volatile_4(RAC_SR3_CLR,0x40);
  if (vcoGainPte != 0) {
    write_volatile_4(SYNTH_VCOGAIN,(uint)vcoGainPte);
  }
  return;
}


