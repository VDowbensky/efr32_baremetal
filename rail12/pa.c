#include "pa.h"



void apcConfigure(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  if ((apcEnabled == '\0') || (param_1 < 0x79)) {
    uVar2 = (RAC->SR3);
    uVar2 = uVar2 & 0xfffffff7;
  }
  else {
    uVar2 = (RAC->PAPKDCTRL);
    write_volatile_4(RAC->PAPKDCTRL,uVar2 & 0xffff2082);
    uVar2 = (RAC->SGPAPKDCTRL);
    write_volatile_4(RAC->SGPAPKDCTRL,uVar2 & 0xffff2082);
    uVar2 = (RAC->PAPKDCTRL);
    uVar1 = ((param_1 - 0x93U) / 5 + 9) * 4;
    write_volatile_4(RAC->PAPKDCTRL,uVar2 | 0xd700 | uVar1);
    uVar2 = (RAC->SGPAPKDCTRL);
    write_volatile_4(RAC->SGPAPKDCTRL,uVar1 | uVar2 | 0xd700);
    uVar2 = (RAC->SR3);
    uVar2 = uVar2 | 8;
  }
  write_volatile_4(RAC->SR3,uVar2);
  return;
}



int32_t PA_OutputPowerGet(void)

{
  return (int)gPaConfig.power;
}



void PA_PowerOffsetSet(undefined2 param_1)

{
  gPaConfig._4_2_ = param_1;
  return;
}



void PA_20dbmConfigSet(void)

{
  uint uVar1;
  
  uVar1 = (RAC->PACTRL0);
  write_volatile_4(RAC->PACTRL0,uVar1 & 0xfffffff9);
  uVar1 = (RAC->PACTRL0);
  write_volatile_4(RAC->PACTRL0,uVar1 | 4);
  uVar1 = (RAC->PABIASCTRL1);
  write_volatile_4(RAC->PABIASCTRL1,uVar1 & 0xfffffff8);
  uVar1 = (RAC->PABIASCTRL1);
  write_volatile_4(RAC->PABIASCTRL1,uVar1 | 5);
  uVar1 = (RAC->PABIASCTRL0);
  write_volatile_4(RAC->PABIASCTRL0,uVar1 & 0xffffff3f);
  uVar1 = (RAC->PABIASCTRL0);
  write_volatile_4(RAC->PABIASCTRL0,uVar1 | 0x81);
  return;
}



void PA_0dbmConfigSet(void)

{
  uint uVar1;
  
  uVar1 = (RAC->PACTRL0);
  write_volatile_4(RAC->PACTRL0,uVar1 & 0xfffffff9);
  uVar1 = (RAC->PACTRL0);
  write_volatile_4(RAC->PACTRL0,uVar1 | 2);
  uVar1 = (RAC->PABIASCTRL1);
  write_volatile_4(RAC->PABIASCTRL1,uVar1 & 0xfffffff8);
  uVar1 = (RAC->PABIASCTRL1);
  write_volatile_4(RAC->PABIASCTRL1,uVar1 | 6);
  uVar1 = (RAC->PABIASCTRL0);
  write_volatile_4(RAC->PABIASCTRL0,uVar1 & 0xffbfff3e);
  uVar1 = (RAC->PAPKDCTRL);
  write_volatile_4(RAC->PAPKDCTRL,uVar1 & 0xffff3fff);
  return;
}



void PA_SubGhz20dbmConfigSet(void)

{
  uint uVar1;
  
  uVar1 = (RAC->SGPABIASCTRL1);
  write_volatile_4(RAC->SGPABIASCTRL1,uVar1 & 0xffff88ff);
  uVar1 = (RAC->SGPABIASCTRL1);
  write_volatile_4(RAC->SGPABIASCTRL1,uVar1 | 0x4500);
  uVar1 = (RAC->SGPABIASCTRL0);
  write_volatile_4(RAC->SGPABIASCTRL0,uVar1 | 1);
  return;
}



void PA_PowerModeConfigSet(void)

{
  if (gPaConfig.paSel == PA_SEL_SUBGIG) {
    PA_SubGhz20dbmConfigSet();
    return;
  }
  if (gPaConfig.paSel == PA_SEL_2P4_LP) {
    PA_0dbmConfigSet();
    return;
  }
  PA_20dbmConfigSet();
  return;
}



uint PA_StripesAndSlicesSet(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = (CMU->RFLOCK0);
  uVar1 = (SEQ->REG0C0);
  uVar3 = (param_1 << 0x17) >> 0x1c;
  iVar4 = count_leading_zeroes(~uVar5 & 0x1fc000);
  uVar5 = 0x13 - iVar4;
  if (uVar5 < uVar3) {
    if (uVar5 != 0) {
      uVar2 = 0x1f;
      uVar3 = uVar5;
      goto LAB_000101c0;
    }
  }
  else {
    if (uVar3 != 0) {
      uVar2 = param_1 & 0x1f;
      if (uVar2 == 0) {
        uVar2 = 1;
      }
      goto LAB_000101c0;
    }
  }
  uVar2 = 1;
  uVar3 = uVar2;
LAB_000101c0:
  write_volatile_4(SEQ->REG0C0,
                   uVar1 & 0xe0c03fff | 0x3fc8 | uVar2 << 0x18 |
                   ((1 << (uVar3 & 0xff)) - 1U & 0xff) << 0xe);
  uVar2 = uVar2 | uVar3 << 5;
  uVar1 = (RAC->PABIASCTRL0);
  if ((param_1 & 0x8000) == 0) {
    write_volatile_4(RAC->PABIASCTRL0,uVar1 & 0xffbfffff);
    return uVar2;
  }
  write_volatile_4(RAC->PABIASCTRL0,uVar1 | 0x400000);
  return uVar2 | 0x8000;
}



uint PA_PowerLevelSet(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  if ((char)gPaConfig == '\x01') {
    if (param_1 < 8) {
      if (param_1 == 0) {
        param_1 = 1;
      }
    }
    else {
      param_1 = 7;
    }
    uVar1 = (SEQ->REG0C0);
    write_volatile_4(SEQ->REG0C0,uVar1 & 0xe0c0003f | param_1 << 0x18);
    return param_1 & 0xffff;
  }
  if (param_1 < 0xf9) {
    if (param_1 == 0) goto LAB_00010240;
  }
  else {
    param_1 = 0xf8;
  }
  param_1 = param_1 - 1 & 0xff;
LAB_00010240:
  uVar1 = param_1 % 0x1f + 1 | ((param_1 / 0x1f & 0xff) + 1) * 0x20;
  if (param_2 != 0) {
    uVar1 = uVar1 | 0x8000;
  }
  uVar1 = PA_StripesAndSlicesSet(uVar1);
  if ((uVar1 & 0x8000) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0x100;
  }
  apcConfigure(200);
  return (uVar1 & 0x1f) +
         (((uVar1 & 0xffff7fe0) - ((uVar1 & 0xffff7fff) >> 5)) - 0x1f & 0xffff | uVar2) & 0xffff;
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
  
  uVar1 = (SEQ->REG0C0);
  if (param_1 < 0x83) {
    write_volatile_4(SEQ->REG0C0,uVar1 & 0xffffc037 | ((uVar1 << 10) >> 0x18) << 6);
    if (param_1 < 0x1f) {
      uVar1 = (RAC->PABIASCTRL0);
      write_volatile_4(RAC->PABIASCTRL0,uVar1 & 0xfffffffe);
      uVar1 = (RAC->SGPABIASCTRL0);
      uVar1 = uVar1 & 0xfffffffe;
      goto LAB_0001037a;
    }
  }
  else {
    write_volatile_4(SEQ->REG0C0,uVar1 & 0xffffc037 | 0x3fc8);
  }
  uVar1 = (RAC->PABIASCTRL0);
  write_volatile_4(RAC->PABIASCTRL0,uVar1 | 1);
  uVar1 = (RAC->SGPABIASCTRL0);
  uVar1 = uVar1 | 1;
LAB_0001037a:
  write_volatile_4(RAC->SGPABIASCTRL0,uVar1);
  apcConfigure();
  return;
}



void PA_StripesAndSlicesCalc(int32_t level)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if (gPaConfig.paSel == PA_SEL_2P4_LP) {
    uVar3 = (SEQ->REG0C0);
    iVar1 = 6;
    do {
      if ((int)*(short *)(&power0dBmParams + iVar1 * 2) <= level + gPaConfig.offset) break;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    iVar2 = (int)*(short *)(&power0dBmParams + iVar1 * 2);
    write_volatile_4(SEQ->REG0C0,uVar3 & 0xe0c0003f | (iVar1 + 1) * 0x1000000);
  }
  else {
    uVar3 = (uint)gPaConfig.voltMode;
    if (gPaConfig.paSel != PA_SEL_2P4_HP) {
      uVar3 = uVar3 + 2;
    }
    iVar2 = uVar3 * 0x44;
    PA_StripesAndSlicesCommonCalc(level + gPaConfig.offset,&paParams + iVar2);
    iVar1 = PA_StripesAndSlicesSet();
    if (iVar1 == 0x21) {
      iVar2 = (int)*(short *)(&DAT_00010d82 + iVar2);
    }
    else {
      iVar2 = PA_PowerFromStripesAndSlicesCommonCalc(iVar1,&UNK_00010d84 + iVar2);
    }
  }
  PA_PowerLevelOptimize(iVar2);
  peakDetectorOldSlices = (SEQ->REG0C0);
  gPaConfig.power = (short)iVar2 - gPaConfig.offset;
  return;
}



int32_t PA_OutputPowerSet(int32_t powerLevel)

{
  PA_StripesAndSlicesCalc(powerLevel);
  return (int)gPaConfig.power;
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
  bool bVar2;
  uint uVar3;
  
  uVar1 = (SEQ->REG0C0);
  uVar3 = uVar1 >> 1 & 0x1fc000;
  write_volatile_4(SEQ->REG0C0,uVar1 & 0xffc03fff | uVar3);
  bVar2 = SYNTH_Is2p4GHz();
  if (bVar2 == false) {
    uVar1 = (RAC->SGPACTRL0);
    write_volatile_4(RAC->SGPACTRL0,uVar1 & 0xffc03fff | uVar3);
  }
  else {
    uVar1 = (RAC->PACTRL0);
    write_volatile_4(RAC->PACTRL0,uVar1 & 0xffc03fff | uVar3);
  }
  write_volatile_4(RAC->IFC,0x2000000);
  return;
}



void PA_PeakDetectorLowRun(void)

{
  uint uVar1;
  
  write_volatile_4(SEQ->REG0C0,peakDetectorOldSlices);
  uVar1 = (RAC->IEN);
  write_volatile_4(RAC->IEN,uVar1 & 0xfbffffff);
  return;
}



void PA_BatHighRun(void)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = SYNTH_Is2p4GHz();
  if (iVar2 == 0) {
    uVar1 = (RAC->SGPACTRL0);
    write_volatile_4(RAC->SGPACTRL0,uVar1 & 0x7fdfffff);
  }
  else {
    uVar1 = (RAC->PACTRL0);
    write_volatile_4(RAC->PACTRL0,uVar1 & 0x7fdfffff);
  }
  uVar1 = (RAC->IEN);
  write_volatile_4(RAC->IEN,uVar1 & 0xf7ffffff);
  return;
}



uint32_t PA_RampTimeGet(void)

{
  return (uint)gPaConfig.rampTime;
}



void PA_RampConfigSet(uint32_t *rampconfig)

{
  uint uVar1;
  
  write_volatile_4(MODEM->RAMPLEV,rampconfig[1]);
  uVar1 = (MODEM->RAMPCTRL);
  write_volatile_4(MODEM->RAMPCTRL,uVar1 & 0xfffff000);
  uVar1 = (MODEM->RAMPCTRL);
  write_volatile_4(MODEM->RAMPCTRL,*rampconfig | uVar1);
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
  
  uVar4 = (MODEM->RAMPLEV);
  uVar6 = (MODEM->RAMPLEV);
  uVar5 = (MODEM->RAMPLEV);
  uVar1 = (MODEM->RAMPCTRL);
  uVar2 = (MODEM->RAMPCTRL);
  uVar3 = (MODEM->RAMPCTRL);
  uVar6 = (uVar6 << 0x10) >> 0x18;
  return ((int)(((uVar5 << 8) >> 0x18) - uVar6 << ((uVar3 << 0x14) >> 0x1c)) >> 5) +
         ((int)(uVar6 - (uVar4 & 0xff) << ((uVar2 << 0x18) >> 0x1c)) >> 5) +
         ((int)((uVar4 & 0xff) << (uVar1 & 0xf)) >> 5);
}



uint32_t PA_RampTimeSet(uint32_t ramptime)

{
  uint uVar1;
  uint32_t uVar2;
  char cVar3;
  int iVar4;
  uint32_t local_18;
  int local_14;
  
  if (gPaConfig.paSel == PA_SEL_SUBGIG) {
    local_14 = 0x96;
  }
  else {
    if (gPaConfig.paSel == PA_SEL_2P4_LP) {
      local_14 = 0x32;
    }
    else {
      local_14 = 0xb4;
    }
  }
  if (ramptime != 0) {
    local_18 = ramptime;
    uVar2 = SystemHFXOClockGet();
    cVar3 = -1;
    for (uVar1 = (uint)(0x8000 / ((ulonglong)(uint)(local_14 * 0x9c4000) /
                                 (ulonglong)(ramptime * (uVar2 / 100)))); uVar1 != 0;
        uVar1 = uVar1 >> 1) {
      cVar3 = cVar3 + '\x01';
    }
    iVar4 = (int)cVar3;
    if (0xf < iVar4) {
      iVar4 = 0xf;
      goto LAB_0000650c;
    }
    if (-1 < iVar4) goto LAB_0000650c;
  }
  iVar4 = 1;
LAB_0000650c:
  local_18 = iVar4 << 8;
  local_14 = local_14 << 0x10;
  PA_RampConfigSet(&local_18);
  iVar4 = PA_RampTimeCalc();
  uVar2 = SystemHFXOClockGet();
  gPaConfig.rampTime = (uint16_t)((ulonglong)(uint)(iVar4 * 10000) / ((ulonglong)uVar2 / 100));
  return (uint)gPaConfig.rampTime;
}



void PA_CTuneSet(uint8_t txPaCtuneValue,uint8_t rxPaCtuneValue)

{
  write_volatile_4(SEQ->REG0C8,txPaCtuneValue & 7 | (txPaCtuneValue & 0x1f) << 4);
  write_volatile_4(SEQ->REG0C4,rxPaCtuneValue & 7 | (rxPaCtuneValue & 0x1f) << 4);
  return;
}



void PA_BandSelect(void)

{
  uint32_t uVar1;
  uint uVar2;
  
  uVar1 = SYNTH_LoDivGet();
  if (false) {
switchD_00006576_caseD_2:
    write_volatile_4(SEQ->REG0C8,0xf7);
    uVar2 = 0xa2;
  }
  else {
    switch(uVar1) {
    case 1:
      uVar2 = 0x44;
      if (gPaConfig.paSel != PA_SEL_2P4_LP) {
        write_volatile_4(SEQ->REG0C8,0);
        goto LAB_000065a2;
      }
      break;
    default:
      goto switchD_00006576_caseD_2;
    default:
      uVar2 = 0;
      break;
    case 5:
    case 6:
      uVar2 = 0x33;
    }
    write_volatile_4(SEQ->REG0C8,uVar2);
  }
LAB_000065a2:
  write_volatile_4(SEQ->REG0C4,uVar2);
  return;
}



bool RADIO_PA_Init(RADIO_PAInit_t *paInit)

{
  uint uVar1;
  uint uVar2;
  bool in_r1;
  bool bVar3;
  
  if (paInit != (RADIO_PAInit_t *)0x0) {
    RADIO_CLKEnable((uint32_t)paInit,in_r1);
    memset(&SEQ->REG0C0,0,0xc);
    if (paInit->paSel == PA_SEL_SUBGIG) {
      uVar1 = (CMU->RFLOCK0);
      bVar3 = (uVar1 & 0x200000) == 0;
    }
    else {
      if (paInit->paSel == PA_SEL_2P4_LP) {
        uVar1 = (CMU->RFLOCK0);
        bVar3 = (uVar1 & 0xc00000) == 0;
      }
      else {
        uVar1 = (DAT_0fe081d4);
        uVar2 = (CMU->RFLOCK0);
        bVar3 = (uVar1 & 1 ^ 1 | uVar2 & 0x400000) == 0;
      }
    }
    if (bVar3) {
      gPaConfig._0_4_ = *(undefined4 *)paInit;
      gPaConfig._4_4_ = *(undefined4 *)&paInit->offset;
      PA_RampTimeSet((uint)paInit->rampTime);
      PA_PowerModeConfigSet();
      PA_OutputPowerSet((int)paInit->power);
      uVar1 = (RAC->APC);
      write_volatile_4(RAC->APC,uVar1 & 0xfffffff8);
      PA_BandSelect();
      return true;
    }
  }
  return false;
}


