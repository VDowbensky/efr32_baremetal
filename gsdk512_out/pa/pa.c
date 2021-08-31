#include "pa.h"



void apcConfigure(int param_1)

{
  RAC_SET *pRVar1;
  
  if ((apcEnabled == '\0') || (param_1 < 0x79)) {
    pRVar1 = (RAC_SET *)&Peripherals::RAC_CLR;
  }
  else {
    write_volatile_4(Peripherals::RAC_CLR.PAPKDCTRL,0xdf01);
    write_volatile_4(Peripherals::RAC_CLR.SGPAPKDCTRL,0xdf01);
    write_volatile_4(Peripherals::RAC_SET.PAPKDCTRL,0xd700);
    write_volatile_4(Peripherals::RAC_SET.SGPAPKDCTRL,0xd700);
    pRVar1 = &Peripherals::RAC_SET;
  }
  ((RAC_CLR *)pRVar1)->SR3 = 8;
  return;
}



int32_t PA_OutputPowerGet(void)

{
  return (int32_t)gPaConfig._2_2_;
}



void PA_PowerOffsetSet(undefined2 param_1)

{
  gPaConfig._4_2_ = param_1;
  return;
}



void PA_20dbmConfigSet(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::SEQ.REG0E4);
  write_volatile_4(Peripherals::SEQ.REG0E4,uVar1 & 0xbfffffe8 | 0x40000014);
  write_volatile_4(Peripherals::RAC_CLR.PACTRL0,7);
  write_volatile_4(Peripherals::RAC_SET.PACTRL0,4);
  write_volatile_4(Peripherals::RAC_CLR.PABIASCTRL1,7);
  write_volatile_4(Peripherals::RAC_SET.PABIASCTRL1,5);
  write_volatile_4(Peripherals::RAC_CLR.PABIASCTRL0,0xc0);
  write_volatile_4(Peripherals::RAC_SET.PABIASCTRL0,0x81);
  return;
}



void PA_0dbmConfigSet(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::SEQ.REG0E4);
  write_volatile_4(Peripherals::SEQ.REG0E4,uVar1 & 0xbfffffe8 | 3);
  write_volatile_4(Peripherals::RAC_CLR.PACTRL0,7);
  write_volatile_4(Peripherals::RAC_SET.PACTRL0,3);
  write_volatile_4(Peripherals::RAC_CLR.PABIASCTRL1,7);
  write_volatile_4(Peripherals::RAC_SET.PABIASCTRL1,6);
  write_volatile_4(Peripherals::RAC_CLR.PABIASCTRL0,0x4000c1);
  write_volatile_4(Peripherals::RAC_CLR.PAPKDCTRL,0xc000);
  return;
}



void PA_SubGhz20dbmConfigSet(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::SEQ.REG0E4);
  write_volatile_4(Peripherals::SEQ.REG0E4,uVar1 & 0xbfffffe8 | 0x40000020);
  write_volatile_4(Peripherals::RAC_CLR.SGPABIASCTRL1,0x7700);
  write_volatile_4(Peripherals::RAC_SET.SGPABIASCTRL1,0x4500);
  write_volatile_4(Peripherals::RAC_SET.SGPABIASCTRL0,1);
  return;
}



void PA_PowerModeConfigSet(void)

{
  if ((char)gPaConfig == '\x02') {
    PA_SubGhz20dbmConfigSet();
    return;
  }
  if ((char)gPaConfig == '\x01') {
    PA_0dbmConfigSet();
    return;
  }
  PA_20dbmConfigSet();
  return;
}



uint PA_PowerLevelSet(uint param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  if ((char)gPaConfig == '\x03') {
    return 0;
  }
  if ((char)gPaConfig != '\x01') {
    uVar3 = read_volatile_4(Peripherals::SEQ.REG0E4);
    uVar1 = uVar3 & 0xe0c03fff | 0x3fc8;
    write_volatile_4(Peripherals::SEQ.REG0E4,uVar1);
    uVar3 = read_volatile_4(Peripherals::CMU.RFLOCK0);
    iVar2 = count_leading_zeroes(~uVar3 & 0x1fc000);
    uVar3 = (0x13 - iVar2) * 0x1f & 0xff;
    if (uVar3 <= param_1) {
      param_1 = uVar3;
    }
    uVar3 = param_1 & 0xffff;
    if (param_1 == 0) {
      write_volatile_4(Peripherals::RAC.APC,0x700002c);
      param_2 = param_1;
    }
    else {
      write_volatile_4(Peripherals::RAC.APC,0x7000000);
      param_1 = param_1 - 1 & 0xff;
    }
    write_volatile_4(Peripherals::SEQ.REG0E4,
                     uVar1 | (param_1 % 0x1f) * 0x1000000 + 0x1000000 |
                     ((1 << ((param_1 / 0x1f & 0xff) + 1 & 0xff)) - 1U & 0xff) << 0xe);
    if ((param_2 == 0) || ((char)gPaConfig != '\0')) {
      write_volatile_4(Peripherals::RAC_CLR.PABIASCTRL0,0x400000);
    }
    else {
      uVar3 = uVar3 | 0x100;
      write_volatile_4(Peripherals::RAC_SET.PABIASCTRL0,0x400000);
    }
    apcConfigure(200);
    return uVar3;
  }
  if (param_1 < 8) {
    if (param_1 == 0) {
      param_1 = 1;
    }
  }
  else {
    param_1 = 7;
  }
  uVar3 = read_volatile_4(Peripherals::SEQ.REG0E4);
  write_volatile_4(Peripherals::SEQ.REG0E4,uVar3 & 0xe0c0003f | param_1 << 0x18);
  return param_1 & 0xffff;
}



uint PA_StripesAndSlicesSet(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  iVar1 = (((int)(param_1 & 0xffff7fff) >> 5) + -1) * 0x1f;
  iVar3 = (param_1 & 0x1f) + iVar1;
  if (iVar3 < 1) {
    uVar2 = 1;
  }
  else {
    if (0xfe < iVar3) {
      iVar3 = 0xff;
    }
    uVar2 = (undefined)iVar3;
  }
  uVar4 = PA_PowerLevelSet(uVar2,(param_1 << 0x10) >> 0x1f,param_3,iVar1,param_4);
  if ((uVar4 & 0xff00) == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = 0x8000;
  }
  return (uVar4 & 0xffff00ff) % 0x1f | ((uVar4 & 0xffff00ff) / 0x1f + 1) * 0x20 | uVar5;
}



uint PA_StripesAndSlicesCommonCalc(int param_1,short *param_2)

{
  int iVar1;
  uint uVar2;
  
  if (*param_2 <= param_1) {
    param_1 = (int)*param_2;
  }
  iVar1 = -((param_1 - 200U) / 0x28);
  if (6 < iVar1) {
    iVar1 = 7;
  }
  uVar2 = param_1 * (param_2 + iVar1 * 4)[3] + *(int *)(param_2 + iVar1 * 4 + 4);
  if (0 < param_1) {
    uVar2 = uVar2 + 500;
  }
  uVar2 = uVar2 / 1000;
  if ((iVar1 != 7) && ((char)gPaConfig != '\x02')) {
    uVar2 = uVar2 | 0x8000;
  }
  return uVar2;
}



uint PA_PowerFromStripesAndSlicesCommonCalc(uint param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 1;
  do {
    if (*(ushort *)(param_2 + iVar2 * 8) < param_1) break;
    iVar2 = iVar2 + 1;
  } while (iVar2 != 8);
  param_2 = param_2 + (iVar2 + -1) * 8;
  uVar1 = (param_1 & 0xffff7fff) * 1000 - *(int *)(param_2 + 4);
  if (0 < (int)uVar1) {
    uVar1 = uVar1 + 500;
  }
  return uVar1 / (uint)(int)*(short *)(param_2 + 2);
}



void PA_PowerLevelOptimize(int param_1)

{
  uint uVar1;
  RAC_CLR *pRVar2;
  
  if ((char)gPaConfig == '\x03') {
    return;
  }
  uVar1 = read_volatile_4(Peripherals::SEQ.REG0E4);
  if (param_1 < 0x83) {
    write_volatile_4(Peripherals::SEQ.REG0E4,uVar1 & 0xffffc037 | ((uVar1 << 10) >> 0x18) << 6);
    if (param_1 < 0x1f) {
      pRVar2 = &Peripherals::RAC_CLR;
      goto LAB_0001035a;
    }
  }
  else {
    write_volatile_4(Peripherals::SEQ.REG0E4,uVar1 & 0xffffc037 | 0x3fc8);
  }
  pRVar2 = (RAC_CLR *)&Peripherals::RAC_SET;
LAB_0001035a:
  pRVar2->PABIASCTRL0 = 1;
  (&pRVar2->PABIASCTRL0)[6] = 1;
  apcConfigure();
  return;
}



//void PA_StripesAndSlicesCalc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
void PA_StripesAndSlicesCalc(int level)
{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if ((char)gPaConfig != '\x03') {
    if ((char)gPaConfig == '\x01') {
      uVar3 = read_volatile_4(Peripherals::SEQ.REG0E4);
      iVar1 = 6;
      do {
        if ((int)*(short *)(power0dBmParams + iVar1 * 2) <= param_1 + gPaConfig._4_2_) break;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
      iVar2 = (int)*(short *)(power0dBmParams + iVar1 * 2);
      write_volatile_4(Peripherals::SEQ.REG0E4,uVar3 & 0xe0c0003f | (iVar1 + 1) * 0x1000000);
    }
    else {
      uVar3 = (uint)gPaConfig._1_1_;
      if ((char)gPaConfig != '\0') {
        uVar3 = uVar3 + 2;
      }
      iVar2 = uVar3 * 0x44;
      PA_StripesAndSlicesCommonCalc
                (param_1 + gPaConfig._4_2_,paParams + iVar2,paParams,uVar3,param_4);
      iVar1 = PA_StripesAndSlicesSet();
      if (iVar1 == 0x21) {
        iVar2 = (int)*(short *)(paParams + iVar2 + 2);
      }
      else {
        iVar2 = PA_PowerFromStripesAndSlicesCommonCalc(iVar1,iVar2 + 0x1074c);
      }
    }
    PA_PowerLevelOptimize(iVar2);
    gPaConfig._2_2_ = (short)iVar2 - gPaConfig._4_2_;
  }
  return;
}



//int32_t PA_OutputPowerSet(void)
int32_t PA_OutputPowerSet(int32_t powerLevel)
{
  PA_StripesAndSlicesCalc(powerLevel);
  return (int)gPaConfig._2_2_;
}



int PA_MaxOutputPowerSet(void)

{
  PA_StripesAndSlicesCalc(200);
  return (int)gPaConfig._2_2_;
}



void PA_APCEnable(void)

{
  apcEnabled = 1;
  apcConfigure((int)gPaConfig._2_2_);
  return;
}



void PA_APCDisable(void)

{
  apcEnabled = 0;
  apcConfigure((int)gPaConfig._2_2_);
  return;
}



void PA_PeakDetectorHighRun(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = SYNTH_Is2p4GHz();
  if (iVar3 == 0) {
    uVar1 = read_volatile_4(Peripherals::RAC.SGPACTRL0);
    uVar2 = read_volatile_4(Peripherals::RAC.SGPACTRL0);
    write_volatile_4(Peripherals::RAC.SGPACTRL0,uVar1 & 0xffc03fff | (uVar2 & 0x3f8000) >> 1);
  }
  else {
    uVar1 = read_volatile_4(Peripherals::RAC.PACTRL0);
    uVar2 = read_volatile_4(Peripherals::RAC.PACTRL0);
    write_volatile_4(Peripherals::RAC.PACTRL0,uVar1 & 0xffc03fff | (uVar2 & 0x3f8000) >> 1);
  }
  write_volatile_4(Peripherals::RAC.IFC,0x2000000);
  return;
}



void PA_PeakDetectorLowRun(void)

{
  return;
}



void PA_BatHighRun(void)

{
  int iVar1;
  uint *puVar2;
  
  iVar1 = SYNTH_Is2p4GHz();
  if (iVar1 == 0) {
    puVar2 = &Peripherals::RAC_CLR.SGPACTRL0;
  }
  else {
    puVar2 = &Peripherals::RAC_CLR.PACTRL0;
  }
  *puVar2 = 0x200000;
  write_volatile_4(Peripherals::RAC_CLR.IEN,0x8000000);
  return;
}



undefined2 PA_RampTimeGet(void)

{
  return gPaConfig._6_2_;
}



void PA_RampConfigSet(uint *param_1)

{
  write_volatile_4(Peripherals::MODEM.RAMPLEV,param_1[1]);
  write_volatile_4(Peripherals::MODEM_CLR.RAMPCTRL,0xfff);
  write_volatile_4(Peripherals::MODEM_SET.RAMPCTRL,*param_1);
  return;
}



int PA_RampTimeCalc(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar4 = read_volatile_4(Peripherals::MODEM.RAMPLEV);
  uVar6 = read_volatile_4(Peripherals::MODEM.RAMPLEV);
  uVar5 = read_volatile_4(Peripherals::MODEM.RAMPLEV);
  uVar1 = read_volatile_4(Peripherals::MODEM.RAMPCTRL);
  uVar2 = read_volatile_4(Peripherals::MODEM.RAMPCTRL);
  uVar3 = read_volatile_4(Peripherals::MODEM.RAMPCTRL);
  uVar6 = (uVar6 << 0x10) >> 0x18;
  return ((int)(((uVar5 << 8) >> 0x18) - uVar6 << ((uVar3 << 0x14) >> 0x1c)) >> 5) +
         ((int)(uVar6 - (uVar4 & 0xff) << ((uVar2 << 0x18) >> 0x1c)) >> 5) +
         ((int)((uVar4 & 0xff) << (uVar1 & 0xf)) >> 5);
}



undefined2 PA_RampTimeSet(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  int local_18;
  int local_14;
  undefined4 uStack16;
  
  uVar4 = read_volatile_4(Peripherals::MODEM.CTRL0);
  gCurrentModulation = (byte)((uVar4 << 0x17) >> 0x1d);
  uVar4 = ((uVar4 << 0x17) >> 0x1d) - 2 & 0xff;
  if ((uVar4 < 5) && ((1 << uVar4 & 0x13U) != 0)) {
    uVar4 = 0;
  }
  else {
    if ((char)gPaConfig == '\x02') {
      uVar4 = 0x96;
    }
    else {
      if ((char)gPaConfig == '\x01') {
        uVar4 = 0x32;
      }
      else {
        uVar4 = 0xb4;
      }
    }
  }
  gDesiredRampTime = param_1;
  local_18 = param_1;
  local_14 = param_2;
  uStack16 = param_3;
  uVar1 = SystemHFXOClockGet();
  cVar3 = -1;
  for (uVar1 = (((uVar1 / 1000) * param_1) / uVar4 << 5) / 1000; uVar1 != 0; uVar1 = uVar1 >> 1) {
    cVar3 = cVar3 + '\x01';
  }
  local_18 = (int)cVar3;
  if (local_18 < 0x10) {
    if (local_18 < 0) {
      local_18 = 0;
    }
  }
  else {
    local_18 = 0xf;
  }
  local_18 = local_18 << 8;
  local_14 = uVar4 << 0x10;
  PA_RampConfigSet(&local_18);
  iVar2 = PA_RampTimeCalc();
  uVar4 = SystemHFXOClockGet();
  gPaConfig._6_2_ = (undefined2)((uint)(iVar2 * 10000) / (uVar4 / 100));
  TIMING_RecalculateAll();
  return gPaConfig._6_2_;
}



void PA_CTuneSet(uint param_1,uint param_2)

{
  write_volatile_4(Peripherals::SEQ.DYNAMIC_CHPWR_TABLE,param_1 & 7 | (param_1 & 0x1f) << 4);
  write_volatile_4(Peripherals::SEQ.REG0E8,param_2 & 7 | (param_2 & 0x1f) << 4);
  return;
}



void PA_BandSelect(void)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = SYNTH_LoDivGet();
  if (false) {
switchD_0001062e_caseD_2:
    uVar2 = 0xf7;
LAB_0001065e:
    write_volatile_4(Peripherals::SEQ.DYNAMIC_CHPWR_TABLE,uVar2);
    uVar2 = 0xa2;
  }
  else {
    switch(uVar1) {
    case 1:
      uVar2 = 0x44;
      if ((char)gPaConfig != '\x01') {
        write_volatile_4(Peripherals::SEQ.DYNAMIC_CHPWR_TABLE,0);
        goto LAB_00010662;
      }
      break;
    default:
      goto switchD_0001062e_caseD_2;
    case 3:
    case 4:
      uVar2 = 0;
      break;
    case 5:
    case 6:
      uVar2 = 0x33;
      break;
    default:
      uVar2 = 0;
      goto LAB_0001065e;
    }
    write_volatile_4(Peripherals::SEQ.DYNAMIC_CHPWR_TABLE,uVar2);
  }
LAB_00010662:
  write_volatile_4(Peripherals::SEQ.REG0E8,uVar2);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined4 RADIO_PA_Init(undefined4 *param_1)

{
  char cVar1;
  uint uVar2;
  bool bVar3;
  
  if (param_1 == (undefined4 *)0x0) {
    return 0;
  }
  RADIO_CLKEnable();
  memset(&Peripherals::SEQ.REG0E4,0,0xc);
  cVar1 = *(char *)param_1;
  if (cVar1 == '\x02') {
    uVar2 = read_volatile_4(Peripherals::CMU.RFLOCK0);
    bVar3 = (uVar2 & 0x200000) == 0;
  }
  else {
    if (cVar1 == '\x01') {
      uVar2 = read_volatile_4(Peripherals::CMU.RFLOCK0);
      bVar3 = (uVar2 & 0xc00000) == 0;
    }
    else {
      if (cVar1 != '\0') goto LAB_000106c4;
      uVar2 = read_volatile_4(Peripherals::CMU.RFLOCK0);
      bVar3 = (_DAT_0fe081d4 & 1 ^ 1 | uVar2 & 0x400000) == 0;
    }
  }
  if (bVar3) {
    gPaConfig._0_4_ = *param_1;
    gPaConfig._4_4_ = param_1[1];
    PA_RampTimeSet(*(undefined2 *)((int)param_1 + 6));
    PA_PowerModeConfigSet();
    PA_OutputPowerSet((int)*(short *)((int)param_1 + 2));
    write_volatile_4(Peripherals::RAC_CLR.APC,3);
    PA_BandSelect();
    return 1;
  }
LAB_000106c4:
  gPaConfig._0_4_ = CONCAT31(gPaConfig._1_3_,3);
  gPaConfig._0_4_ = CONCAT22(0x8000,(undefined2)gPaConfig);
  return 0;
}



undefined4 PA_UpdateConfig(void)

{
  uint uVar1;
  
  PA_BandSelect();
  uVar1 = read_volatile_4(Peripherals::MODEM.CTRL0);
  if ((uint)gCurrentModulation != (uVar1 << 0x17) >> 0x1d) {
    PA_RampTimeSet(gDesiredRampTime);
    return 1;
  }
  return 0;
}


