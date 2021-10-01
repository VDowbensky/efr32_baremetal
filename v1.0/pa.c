#include "pa.o.h"



void apcConfigure(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  if ((apcEnabled == '\0') || (param_1 < 0x79)) {
    uVar2 = read_volatile_4(Peripherals::RAC.SR3);
    uVar2 = uVar2 & 0xfffffff7;
  }
  else {
    uVar2 = read_volatile_4(Peripherals::RAC.PAPKDCTRL);
    write_volatile_4(Peripherals::RAC.PAPKDCTRL,uVar2 & 0xffff2082);
    uVar2 = read_volatile_4(Peripherals::RAC.SGPAPKDCTRL);
    write_volatile_4(Peripherals::RAC.SGPAPKDCTRL,uVar2 & 0xffff2082);
    uVar2 = read_volatile_4(Peripherals::RAC.PAPKDCTRL);
    uVar1 = ((param_1 - 0x93U) / 5 + 9) * 4;
    write_volatile_4(Peripherals::RAC.PAPKDCTRL,uVar2 | 0xd700 | uVar1);
    uVar2 = read_volatile_4(Peripherals::RAC.SGPAPKDCTRL);
    write_volatile_4(Peripherals::RAC.SGPAPKDCTRL,uVar1 | uVar2 | 0xd700);
    uVar2 = read_volatile_4(Peripherals::RAC.SR3);
    uVar2 = uVar2 | 8;
  }
  write_volatile_4(Peripherals::RAC.SR3,uVar2);
  return;
}



int32_t PA_OutputPowerGet(void)

{
  return (int)gPaConfig._2_2_;
}



void PA_PowerOffsetSet(undefined2 param_1)

{
  gPaConfig._4_2_ = param_1;
  return;
}



void PA_20dbmConfigSet(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::RAC.PACTRL0);
  write_volatile_4(Peripherals::RAC.PACTRL0,uVar1 & 0xfffffff9);
  uVar1 = read_volatile_4(Peripherals::RAC.PACTRL0);
  write_volatile_4(Peripherals::RAC.PACTRL0,uVar1 | 4);
  uVar1 = read_volatile_4(Peripherals::RAC.PABIASCTRL1);
  write_volatile_4(Peripherals::RAC.PABIASCTRL1,uVar1 & 0xfffffff8);
  uVar1 = read_volatile_4(Peripherals::RAC.PABIASCTRL1);
  write_volatile_4(Peripherals::RAC.PABIASCTRL1,uVar1 | 5);
  uVar1 = read_volatile_4(Peripherals::RAC.PABIASCTRL0);
  write_volatile_4(Peripherals::RAC.PABIASCTRL0,uVar1 & 0xffffff3f);
  uVar1 = read_volatile_4(Peripherals::RAC.PABIASCTRL0);
  write_volatile_4(Peripherals::RAC.PABIASCTRL0,uVar1 | 0x81);
  return;
}



void PA_0dbmConfigSet(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::RAC.PACTRL0);
  write_volatile_4(Peripherals::RAC.PACTRL0,uVar1 & 0xfffffff9);
  uVar1 = read_volatile_4(Peripherals::RAC.PACTRL0);
  write_volatile_4(Peripherals::RAC.PACTRL0,uVar1 | 2);
  uVar1 = read_volatile_4(Peripherals::RAC.PABIASCTRL1);
  write_volatile_4(Peripherals::RAC.PABIASCTRL1,uVar1 & 0xfffffff8);
  uVar1 = read_volatile_4(Peripherals::RAC.PABIASCTRL1);
  write_volatile_4(Peripherals::RAC.PABIASCTRL1,uVar1 | 6);
  uVar1 = read_volatile_4(Peripherals::RAC.PABIASCTRL0);
  write_volatile_4(Peripherals::RAC.PABIASCTRL0,uVar1 & 0xffbfff3e);
  uVar1 = read_volatile_4(Peripherals::RAC.PAPKDCTRL);
  write_volatile_4(Peripherals::RAC.PAPKDCTRL,uVar1 & 0xffff3fff);
  return;
}



void PA_SubGhz20dbmConfigSet(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::RAC.SGPABIASCTRL1);
  write_volatile_4(Peripherals::RAC.SGPABIASCTRL1,uVar1 & 0xffff88ff);
  uVar1 = read_volatile_4(Peripherals::RAC.SGPABIASCTRL1);
  write_volatile_4(Peripherals::RAC.SGPABIASCTRL1,uVar1 | 0x4500);
  uVar1 = read_volatile_4(Peripherals::RAC.SGPABIASCTRL0);
  write_volatile_4(Peripherals::RAC.SGPABIASCTRL0,uVar1 | 1);
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



uint PA_StripesAndSlicesSet(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = read_volatile_4(Peripherals::CMU.RFLOCK0);
  uVar1 = read_volatile_4(Peripherals::SEQ.REG0C0);
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
  write_volatile_4(Peripherals::SEQ.REG0C0,
                   uVar1 & 0xe0c03fff | 0x3fc8 | uVar2 << 0x18 |
                   ((1 << (uVar3 & 0xff)) - 1U & 0xff) << 0xe);
  uVar2 = uVar2 | uVar3 << 5;
  uVar1 = read_volatile_4(Peripherals::RAC.PABIASCTRL0);
  if ((param_1 & 0x8000) == 0) {
    write_volatile_4(Peripherals::RAC.PABIASCTRL0,uVar1 & 0xffbfffff);
    return uVar2;
  }
  write_volatile_4(Peripherals::RAC.PABIASCTRL0,uVar1 | 0x400000);
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
    uVar1 = read_volatile_4(Peripherals::SEQ.REG0C0);
    write_volatile_4(Peripherals::SEQ.REG0C0,uVar1 & 0xe0c0003f | param_1 << 0x18);
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
  
  uVar1 = read_volatile_4(Peripherals::SEQ.REG0C0);
  if (param_1 < 0x83) {
    write_volatile_4(Peripherals::SEQ.REG0C0,uVar1 & 0xffffc037 | ((uVar1 << 10) >> 0x18) << 6);
    if (param_1 < 0x1f) {
      uVar1 = read_volatile_4(Peripherals::RAC.PABIASCTRL0);
      write_volatile_4(Peripherals::RAC.PABIASCTRL0,uVar1 & 0xfffffffe);
      uVar1 = read_volatile_4(Peripherals::RAC.SGPABIASCTRL0);
      uVar1 = uVar1 & 0xfffffffe;
      goto LAB_0001037a;
    }
  }
  else {
    write_volatile_4(Peripherals::SEQ.REG0C0,uVar1 & 0xffffc037 | 0x3fc8);
  }
  uVar1 = read_volatile_4(Peripherals::RAC.PABIASCTRL0);
  write_volatile_4(Peripherals::RAC.PABIASCTRL0,uVar1 | 1);
  uVar1 = read_volatile_4(Peripherals::RAC.SGPABIASCTRL0);
  uVar1 = uVar1 | 1;
LAB_0001037a:
  write_volatile_4(Peripherals::RAC.SGPABIASCTRL0,uVar1);
  apcConfigure();
  return;
}



void PA_StripesAndSlicesCalc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if ((char)gPaConfig == '\x01') {
    uVar3 = read_volatile_4(Peripherals::SEQ.REG0C0);
    iVar1 = 6;
    do {
      if ((int)*(short *)(&power0dBmParams + iVar1 * 2) <= param_1 + gPaConfig._4_2_) break;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    iVar2 = (int)*(short *)(&power0dBmParams + iVar1 * 2);
    write_volatile_4(Peripherals::SEQ.REG0C0,uVar3 & 0xe0c0003f | (iVar1 + 1) * 0x1000000);
  }
  else {
    uVar3 = (uint)gPaConfig._1_1_;
    if ((char)gPaConfig != '\0') {
      uVar3 = uVar3 + 2;
    }
    iVar2 = uVar3 * 0x44;
    PA_StripesAndSlicesCommonCalc
              (param_1 + gPaConfig._4_2_,&paParams + iVar2,&paParams,uVar3,param_4);
    iVar1 = PA_StripesAndSlicesSet();
    if (iVar1 == 0x21) {
      iVar2 = (int)*(short *)(&DAT_00010726 + iVar2);
    }
    else {
      iVar2 = PA_PowerFromStripesAndSlicesCommonCalc(iVar1,&UNK_00010728 + iVar2);
    }
  }
  PA_PowerLevelOptimize(iVar2);
  peakDetectorOldSlices = read_volatile_4(Peripherals::SEQ.REG0C0);
  gPaConfig._2_2_ = (short)iVar2 - gPaConfig._4_2_;
  return;
}



int PA_OutputPowerSet(void)

{
  PA_StripesAndSlicesCalc();
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
  int iVar2;
  uint uVar3;
  
  uVar1 = read_volatile_4(Peripherals::SEQ.REG0C0);
  uVar3 = uVar1 >> 1 & 0x1fc000;
  write_volatile_4(Peripherals::SEQ.REG0C0,uVar1 & 0xffc03fff | uVar3);
  iVar2 = SYNTH_Is2p4GHz();
  if (iVar2 == 0) {
    uVar1 = read_volatile_4(Peripherals::RAC.SGPACTRL0);
    write_volatile_4(Peripherals::RAC.SGPACTRL0,uVar1 & 0xffc03fff | uVar3);
  }
  else {
    uVar1 = read_volatile_4(Peripherals::RAC.PACTRL0);
    write_volatile_4(Peripherals::RAC.PACTRL0,uVar1 & 0xffc03fff | uVar3);
  }
  write_volatile_4(Peripherals::RAC.IFC,0x2000000);
  return;
}



void PA_PeakDetectorLowRun(void)

{
  uint uVar1;
  
  write_volatile_4(Peripherals::SEQ.REG0C0,peakDetectorOldSlices);
  uVar1 = read_volatile_4(Peripherals::RAC.IEN);
  write_volatile_4(Peripherals::RAC.IEN,uVar1 & 0xfbffffff);
  return;
}



void PA_BatHighRun(void)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = SYNTH_Is2p4GHz();
  if (iVar2 == 0) {
    uVar1 = read_volatile_4(Peripherals::RAC.SGPACTRL0);
    write_volatile_4(Peripherals::RAC.SGPACTRL0,uVar1 & 0x7fdfffff);
  }
  else {
    uVar1 = read_volatile_4(Peripherals::RAC.PACTRL0);
    write_volatile_4(Peripherals::RAC.PACTRL0,uVar1 & 0x7fdfffff);
  }
  uVar1 = read_volatile_4(Peripherals::RAC.IEN);
  write_volatile_4(Peripherals::RAC.IEN,uVar1 & 0xf7ffffff);
  return;
}



undefined2 PA_RampTimeGet(void)

{
  return gPaConfig._6_2_;
}



void PA_RampConfigSet(uint *param_1)

{
  uint uVar1;
  
  write_volatile_4(Peripherals::MODEM.RAMPLEV,param_1[1]);
  uVar1 = read_volatile_4(Peripherals::MODEM.RAMPCTRL);
  write_volatile_4(Peripherals::MODEM.RAMPCTRL,uVar1 & 0xfffff000);
  uVar1 = read_volatile_4(Peripherals::MODEM.RAMPCTRL);
  write_volatile_4(Peripherals::MODEM.RAMPCTRL,*param_1 | uVar1);
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



undefined2 PA_RampTimeSet(int param_1,undefined4 param_2)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  int local_18;
  int local_14;
  
  if ((char)gPaConfig == '\x02') {
    iVar3 = 0x96;
  }
  else {
    if ((char)gPaConfig == '\x01') {
      iVar3 = 0x32;
    }
    else {
      iVar3 = 0xb4;
    }
  }
  if (param_1 != 0) {
    local_18 = param_1;
    local_14 = param_2;
    uVar1 = SystemHFXOClockGet();
    cVar2 = -1;
    for (uVar1 = (uint)(0x8000 / ((ulonglong)(uint)(iVar3 * 0x9c4000) /
                                 (ulonglong)(param_1 * (uVar1 / 100)))); uVar1 != 0;
        uVar1 = uVar1 >> 1) {
      cVar2 = cVar2 + '\x01';
    }
    local_18 = (int)cVar2;
    if (0xf < local_18) {
      local_18 = 0xf;
      goto LAB_000105e4;
    }
    if (-1 < local_18) goto LAB_000105e4;
  }
  local_18 = 1;
LAB_000105e4:
  local_18 = local_18 << 8;
  local_14 = iVar3 << 0x10;
  PA_RampConfigSet(&local_18);
  iVar3 = PA_RampTimeCalc();
  uVar1 = SystemHFXOClockGet();
  gPaConfig._6_2_ = (undefined2)((ulonglong)(uint)(iVar3 * 10000) / ((ulonglong)uVar1 / 100));
  return gPaConfig._6_2_;
}



void PA_CTuneSet(uint8_t txpactune,uint8_t rxpactune)

{
  write_volatile_4(Peripherals::SEQ.REG0C8,txpactune & 7 | (txpactune & 0x1f) << 4);
  write_volatile_4(Peripherals::SEQ.REG0C4,rxpactune & 7 | (rxpactune & 0x1f) << 4);
  return;
}



void PA_BandSelect(void)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = SYNTH_LoDivGet();
  if (false) {
switchD_0001064e_caseD_2:
    write_volatile_4(Peripherals::SEQ.REG0C8,0xf7);
    uVar2 = 0xa2;
  }
  else {
    switch(uVar1) {
    case 1:
      uVar2 = 0x44;
      if ((char)gPaConfig != '\x01') {
        write_volatile_4(Peripherals::SEQ.REG0C8,0);
        goto LAB_0001067a;
      }
      break;
    default:
      goto switchD_0001064e_caseD_2;
    default:
      uVar2 = 0;
      break;
    case 5:
    case 6:
      uVar2 = 0x33;
    }
    write_volatile_4(Peripherals::SEQ.REG0C8,uVar2);
  }
LAB_0001067a:
  write_volatile_4(Peripherals::SEQ.REG0C4,uVar2);
  return;
}



undefined4 RADIO_PA_Init(undefined4 *param_1)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  
  if (param_1 != (undefined4 *)0x0) {
    RADIO_CLKEnable();
    memset(&Peripherals::SEQ.REG0C0,0,0xc);
    if (*(char *)param_1 == '\x02') {
      uVar1 = read_volatile_4(Peripherals::CMU.RFLOCK0);
      bVar3 = (uVar1 & 0x200000) == 0;
    }
    else {
      if (*(char *)param_1 == '\x01') {
        uVar1 = read_volatile_4(Peripherals::CMU.RFLOCK0);
        bVar3 = (uVar1 & 0xc00000) == 0;
      }
      else {
        uVar1 = read_volatile_4(DAT_0fe081d4);
        uVar2 = read_volatile_4(Peripherals::CMU.RFLOCK0);
        bVar3 = (uVar1 & 1 ^ 1 | uVar2 & 0x400000) == 0;
      }
    }
    if (bVar3) {
      gPaConfig._0_4_ = *param_1;
      gPaConfig._4_4_ = param_1[1];
      PA_RampTimeSet(*(undefined2 *)((int)param_1 + 6));
      PA_PowerModeConfigSet();
      PA_OutputPowerSet((int)*(short *)((int)param_1 + 2));
      uVar1 = read_volatile_4(Peripherals::RAC.APC);
      write_volatile_4(Peripherals::RAC.APC,uVar1 & 0xfffffff8);
      PA_BandSelect();
      return 1;
    }
  }
  return 0;
}


