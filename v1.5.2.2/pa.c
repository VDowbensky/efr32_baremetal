#include "pa.h"



void apcConfigure(int param_1)

{
  RAC_SET *pRVar1;
  
  if ((apcEnabled == '\0') || (param_1 < 0x79)) {
    pRVar1 = (RAC_SET *)&Peripherals::RAC_CLR;
  }
  else {
    BUS_RegMaskedClear(&RAC->PAPKDCTRL,0xdf01);
    BUS_RegMaskedClear(&RAC->SGPAPKDCTRL,0xdf01);
    BUS_RegMaskedSet(&RAC->PAPKDCTRL,0xd700);
    BUS_RegMaskedSet(&RAC->SGPAPKDCTRL,0xd700);
    pRVar1 = &Peripherals::RAC_SET;
  }
  ((RAC_CLR *)pRVar1)->SR3 = 8;
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
  
  uVar1 = (SEQ->REG0E4);
  write_volatile_4(SEQ->REG0E4,uVar1 & 0xbfffffe8 | 0x40000014);
  BUS_RegMaskedClear(&RAC->PACTRL0,7);
  BUS_RegMaskedSet(&RAC->PACTRL0,4);
  BUS_RegMaskedClear(&RAC->PABIASCTRL1,7);
  BUS_RegMaskedSet(&RAC->PABIASCTRL1,5);
  BUS_RegMaskedClear(&RAC->PABIASCTRL0,0xc0);
  BUS_RegMaskedSet(&RAC->PABIASCTRL0,0x81);
  return;
}



void PA_0dbmConfigSet(void)

{
  uint uVar1;
  
  uVar1 = (SEQ->REG0E4);
  write_volatile_4(SEQ->REG0E4,uVar1 & 0xbfffffe8 | 3);
  BUS_RegMaskedClear(&RAC->PACTRL0,7);
  BUS_RegMaskedSet(&RAC->PACTRL0,3);
  BUS_RegMaskedClear(&RAC->PABIASCTRL1,7);
  BUS_RegMaskedSet(&RAC->PABIASCTRL1,6);
  BUS_RegMaskedClear(&RAC->PABIASCTRL0,0x4000c1);
  BUS_RegMaskedClear(&RAC->PAPKDCTRL,0xc000);
  return;
}



void PA_SubGhz20dbmConfigSet(void)

{
  uint uVar1;
  
  uVar1 = (SEQ->REG0E4);
  write_volatile_4(SEQ->REG0E4,uVar1 & 0xbfffffe8 | 0x40000020);
  BUS_RegMaskedClear(&RAC->SGPABIASCTRL1,0x7700);
  BUS_RegMaskedSet(&RAC->SGPABIASCTRL1,0x4500);
  BUS_RegMaskedSet(&RAC->SGPABIASCTRL0,1);
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



uint16_t PA_PowerLevelSet(uint8_t pwrLevel,uint8_t boostMode)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  uVar2 = (uint)boostMode;
  uVar1 = (uint)pwrLevel;
  if (gPaConfig.paSel == PA_SEL_INVALID) {
    return 0;
  }
  if (gPaConfig.paSel != PA_SEL_2P4_LP) {
    uVar5 = (SEQ->REG0E4);
    uVar3 = uVar5 & 0xe0c03fff | 0x3fc8;
    write_volatile_4(SEQ->REG0E4,uVar3);
    uVar5 = (CMU->RFLOCK0);
    iVar4 = count_leading_zeroes(~uVar5 & 0x1fc000);
    uVar5 = (0x13 - iVar4) * 0x1f & 0xff;
    if (uVar5 <= uVar1) {
      uVar1 = uVar5;
    }
    if (uVar1 == 0) {
      write_volatile_4(RAC->APC,0x700002c);
      uVar5 = uVar1;
      uVar2 = uVar1;
    }
    else {
      write_volatile_4(RAC->APC,0x7000000);
      uVar5 = uVar1 - 1 & 0xff;
    }
    write_volatile_4(SEQ->REG0E4,
                     uVar3 | (uVar5 % 0x1f) * 0x1000000 + 0x1000000 |
                     ((1 << uVar5 / 0x1f + 1) - 1U & 0xff) << 0xe);
    if ((uVar2 == 0) || (gPaConfig.paSel != PA_SEL_2P4_HP)) {
      BUS_RegMaskedClear(&RAC->PABIASCTRL0,0x400000);
    }
    else {
      uVar1 = uVar1 | 0x100;
      BUS_RegMaskedSet(&RAC->PABIASCTRL0,0x400000);
    }
    apcConfigure(200);
    return (uint16_t)uVar1;
  }
  if (uVar1 < 8) {
    if (uVar1 == 0) {
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 7;
  }
  uVar2 = (SEQ->REG0E4);
  write_volatile_4(SEQ->REG0E4,uVar2 & 0xe0c0003f | uVar1 << 0x18);
  return (uint16_t)uVar1;
}



uint32_t PA_StripesAndSlicesSet(uint32_t level)

{
  uint8_t pwrLevel;
  uint16_t uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = (level & 0x1f) + (((int)(level & 0xffff7fff) >> 5) + -1) * 0x1f;
  if (iVar2 < 1) {
    pwrLevel = '\x01';
  }
  else {
    if (0xfe < iVar2) {
      iVar2 = 0xff;
    }
    pwrLevel = (uint8_t)iVar2;
  }
  uVar1 = PA_PowerLevelSet(pwrLevel,(byte)((level << 0x10) >> 0x1f));
  if ((uVar1 & 0xff00) == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = 0x8000;
  }
  return (uVar1 & 0xffff00ff) % 0x1f | ((uVar1 & 0xffff00ff) / 0x1f + 1) * 0x20 | uVar3;
}



uint32_t PA_StripesAndSlicesCommonCalc(int32_t power,uint16_t *table)

{
  uint32_t uVar1;
  int iVar2;
  uint uVar3;
  
  if ((short)*table <= power) {
    power = (int)(short)*table;
  }
  iVar2 = -((power - 200U) / 0x28);
  if (6 < iVar2) {
    iVar2 = 7;
  }
  uVar3 = power * (short)(table + iVar2 * 4)[3] + *(int *)(table + iVar2 * 4 + 4);
  if (0 < power) {
    uVar3 = uVar3 + 500;
  }
  uVar1 = uVar3 / 1000;
  if ((iVar2 != 7) && (gPaConfig.paSel != PA_SEL_SUBGIG)) {
    uVar1 = uVar1 | 0x8000;
  }
  return uVar1;
}



uint32_t PA_PowerFromStripesAndSlicesCommonCalc(uint32_t stripe,uint32_t slice)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 1;
  do {
    if (*(ushort *)(slice + iVar2 * 8) < stripe) break;
    iVar2 = iVar2 + 1;
  } while (iVar2 != 8);
  iVar2 = slice + (iVar2 + -1) * 8;
  uVar1 = (stripe & 0xffff7fff) * 1000 - *(int *)(iVar2 + 4);
  if (0 < (int)uVar1) {
    uVar1 = uVar1 + 500;
  }
  return uVar1 / (uint)(int)*(short *)(iVar2 + 2);
}



void PA_PowerLevelOptimize(int param_1)

{
  uint uVar1;
  RAC_CLR *pRVar2;
  
  if (gPaConfig.paSel == PA_SEL_INVALID) {
    return;
  }
  uVar1 = (SEQ->REG0E4);
  if (param_1 < 0x83) {
    write_volatile_4(SEQ->REG0E4,uVar1 & 0xffffc037 | ((uVar1 << 10) >> 0x18) << 6);
    if (param_1 < 0x1f) {
      pRVar2 = &Peripherals::RAC_CLR;
      goto LAB_0000d2da;
    }
  }
  else {
    write_volatile_4(SEQ->REG0E4,uVar1 & 0xffffc037 | 0x3fc8);
  }
  pRVar2 = (RAC_CLR *)&Peripherals::RAC_SET;
LAB_0000d2da:
  pRVar2->PABIASCTRL0 = 1;
  (&pRVar2->PABIASCTRL0)[6] = 1;
  apcConfigure();
  return;
}



void PA_StripesAndSlicesCalc(int32_t power)

{
  int iVar1;
  uint32_t uVar2;
  uint uVar3;
  
  if (gPaConfig.paSel != PA_SEL_INVALID) {
    if (gPaConfig.paSel == PA_SEL_2P4_LP) {
      uVar3 = (SEQ->REG0E4);
      iVar1 = 6;
      do {
        if ((int)*(short *)(&power0dBmParams + iVar1 * 2) <= power + gPaConfig.offset) break;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
      uVar2 = SEXT24(*(short *)(&power0dBmParams + iVar1 * 2));
      write_volatile_4(SEQ->REG0E4,uVar3 & 0xe0c0003f | (iVar1 + 1) * 0x1000000);
    }
    else {
      uVar3 = (uint)gPaConfig.voltMode;
      if (gPaConfig.paSel != PA_SEL_2P4_HP) {
        uVar3 = uVar3 + 2;
      }
      iVar1 = uVar3 * 0x44;
      uVar2 = PA_StripesAndSlicesCommonCalc
                        (power + gPaConfig.offset,(uint16_t *)(&paParams + iVar1));
      uVar2 = PA_StripesAndSlicesSet(uVar2);
      if (uVar2 == 0x21) {
        uVar2 = SEXT24(*(short *)(&DAT_0001b55a + iVar1));
      }
      else {
        uVar2 = PA_PowerFromStripesAndSlicesCommonCalc(uVar2,(uint32_t)(&UNK_0001b55c + iVar1));
      }
    }
    PA_PowerLevelOptimize(uVar2);
    gPaConfig.power = (short)uVar2 - gPaConfig.offset;
  }
  return;
}



int32_t PA_OutputPowerSet(int32_t power)

{
  PA_StripesAndSlicesCalc(power);
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
  uint uVar2;
  int iVar3;
  
  iVar3 = SYNTH_Is2p4GHz();
  if (iVar3 == 0) {
    uVar1 = (RAC->SGPACTRL0);
    uVar2 = (RAC->SGPACTRL0);
    write_volatile_4(RAC->SGPACTRL0,uVar1 & 0xffc03fff | (uVar2 & 0x3f8000) >> 1);
  }
  else {
    uVar1 = (RAC->PACTRL0);
    uVar2 = (RAC->PACTRL0);
    write_volatile_4(RAC->PACTRL0,uVar1 & 0xffc03fff | (uVar2 & 0x3f8000) >> 1);
  }
  write_volatile_4(RAC->IFC,0x2000000);
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
  BUS_RegMaskedClear(&RAC->IEN,0x8000000);
  return;
}



uint32_t PA_RampTimeGet(void)

{
  return (uint)gPaConfig.rampTime;
}



void PA_RampConfigSet(uint *param_1)

{
  write_volatile_4(MODEM->RAMPLEV,param_1[1]);
  BUS_RegMaskedClear(&MODEM->RAMPCTRL,0xfff);
  BUS_RegMaskedSet(&MODEM->RAMPCTRL,*param_1);
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
  uint32_t uVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint32_t local_18;
  int local_14;
  
  uVar3 = (MODEM->CTRL0);
  gCurrentModulation = (byte)((uVar3 << 0x17) >> 0x1d);
  uVar3 = ((uVar3 << 0x17) >> 0x1d) - 2 & 0xff;
  if ((uVar3 < 5) && ((1 << uVar3 & 0x13U) != 0)) {
    uVar3 = 0;
  }
  else {
    if (gPaConfig.paSel == PA_SEL_SUBGIG) {
      uVar3 = 0x96;
    }
    else {
      if (gPaConfig.paSel == PA_SEL_2P4_LP) {
        uVar3 = 0x32;
      }
      else {
        uVar3 = 0xb4;
      }
    }
  }
  gDesiredRampTime = ramptime;
  local_18 = ramptime;
  uVar1 = SystemHFXOClockGet();
  cVar2 = -1;
  for (uVar4 = (((uVar1 / 1000) * ramptime) / uVar3 << 5) / 1000; uVar4 != 0; uVar4 = uVar4 >> 1) {
    cVar2 = cVar2 + '\x01';
  }
  iVar5 = (int)cVar2;
  if (iVar5 < 0x10) {
    if (iVar5 < 0) {
      iVar5 = 0;
    }
  }
  else {
    iVar5 = 0xf;
  }
  local_18 = iVar5 << 8;
  local_14 = uVar3 << 0x10;
  PA_RampConfigSet(&local_18);
  iVar5 = PA_RampTimeCalc();
  uVar1 = SystemHFXOClockGet();
  gPaConfig.rampTime = (uint16_t)((uint)(iVar5 * 10000) / (uVar1 / 100));
  TIMING_RecalculateAll();
  return (uint)gPaConfig.rampTime;
}



void PA_CTuneSet(uint8_t txPaCtuneValue,uint8_t rxPaCtuneValue)

{
  write_volatile_4(SEQ->DYNAMIC_CHPWR_TABLE,
                   txPaCtuneValue & 7 | (txPaCtuneValue & 0x1f) << 4);
  write_volatile_4(SEQ->REG0E8,rxPaCtuneValue & 7 | (rxPaCtuneValue & 0x1f) << 4);
  return;
}


void PA_BandSelect(void)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = SYNTH_LoDivGet();
  switch(uVar1) {
  case 1:
    uVar2 = 0x44;
    if (gPaConfig.paSel != PA_SEL_2P4_LP) {
      write_volatile_4(SEQ->DYNAMIC_CHPWR_TABLE,0);
      goto LAB_0000d59e;
    }
    break;
  default:
    uVar2 = 0xf7;
    goto LAB_0000d59a;
  case 3:
  case 4:
    uVar2 = 0;
    break;
  case 5:
  case 6:
    uVar2 = 0x33;
    break;
  case 7:
  case 8:
  case 9:
    uVar2 = 0;
LAB_0000d59a:
    write_volatile_4(SEQ->DYNAMIC_CHPWR_TABLE,uVar2);
    uVar2 = 0xa2;
    goto LAB_0000d59e;
  }
  write_volatile_4(SEQ->DYNAMIC_CHPWR_TABLE,uVar2);
LAB_0000d59e:
  write_volatile_4(SEQ->REG0E8,uVar2);
  return;
}



bool RADIO_PA_Init(RADIO_PAInit_t *paInit)

{
  RADIO_PASel_t RVar1;
  uint uVar2;
  bool bVar3;
  
  if (paInit == (RADIO_PAInit_t *)0x0) {
    return false;
  }
  RADIO_CLKEnable();
  memset(&SEQ->REG0E4,0,0xc);
  RVar1 = paInit->paSel;
  if (RVar1 == PA_SEL_SUBGIG) {
    uVar2 = (CMU->RFLOCK0);
    bVar3 = (uVar2 & 0x200000) == 0;
  }
  else {
    if (RVar1 == PA_SEL_2P4_LP) {
      uVar2 = (CMU->RFLOCK0);
      bVar3 = (uVar2 & 0xc00000) == 0;
    }
    else {
      if (RVar1 != PA_SEL_2P4_HP) goto LAB_0000d600;
      uVar2 = (CMU->RFLOCK0);
      bVar3 = (_DAT_0fe081d4 & 1 ^ 1 | uVar2 & 0x400000) == 0;
    }
  }
  if (bVar3) {
    gPaConfig._0_4_ = *(undefined4 *)paInit;
    gPaConfig._4_4_ = *(undefined4 *)&paInit->offset;
    PA_RampTimeSet((uint)paInit->rampTime);
    PA_PowerModeConfigSet();
    PA_OutputPowerSet((int)paInit->power);
    BUS_RegMaskedClear(&RAC->APC,3);
    PA_BandSelect();
    return true;
  }
LAB_0000d600:
  gPaConfig._0_4_ = CONCAT31(gPaConfig._1_3_,3);
  gPaConfig._0_4_ = CONCAT22(0x8000,gPaConfig._0_2_);
  return false;
}



bool PA_UpdateConfig(void)

{
  uint uVar1;
  
  PA_BandSelect();
  uVar1 = (MODEM->CTRL0);
  if ((uint)gCurrentModulation != (uVar1 << 0x17) >> 0x1d) {
    PA_RampTimeSet(gDesiredRampTime);
    return true;
  }
  return false;
}



