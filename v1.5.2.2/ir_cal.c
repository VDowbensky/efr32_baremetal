#include "ir_cal.h"



undefined4 IRCAL_Configure(undefined4 param_1)

{
  char cVar1;
  
  switch(param_1) {
  case 0:
    cVar1 = rcIrCalData[8];
    if (rcIrCalData[8] == '\x01') {
      if (rcIrCalData[5] == '\0') {
        return 0;
      }
    }
    else {
      if (rcIrCalData[8] == '\x02') {
        if (rcIrCalData[6] == '\0') {
          return 0;
        }
      }
      else {
        if (rcIrCalData[8] != '\x03') {
          return 0;
        }
        if (rcIrCalData[7] == '\0') {
          return 0;
        }
      }
    }
    break;
  case 1:
    if (rcIrCalData[5] == '\0') {
      return 0;
    }
    cVar1 = '\x01';
    break;
  case 2:
    if (rcIrCalData[6] == '\0') {
      return 0;
    }
    cVar1 = '\x02';
    break;
  case 3:
    if (rcIrCalData[7] == '\0') {
      return 0;
    }
    cVar1 = '\x03';
    break;
  default:
    return 0;
  }
  globalCalType = cVar1;
  return 1;
}



void IRCAL_SetGlobalCalType(undefined param_1)

{
  globalCalType = param_1;
  return;
}



undefined IRCAL_GetGlobalCalType(void)

{
  IRCAL_Configure(globalCalType);
  return globalCalType;
}




void IRCAL_Set(uint param_1)

{
  uint uVar1;
  
  if (param_1 != 0xffffffff) {
    uVar1 = (RAC->IFPGACAL);
    write_volatile_4(RAC->IFPGACAL,uVar1 & 0xffff0000 | param_1 & 0xffff);
  }
  return;
}


uint8_t IRCAL_Init(uint8_t *settings)

{
  uint8_t uVar1;
  uint8_t uVar2;
  
  if ((settings != (uint8_t *)0x0) && (0x11 < *settings)) {
    rcIrCalData[5] = settings[6];
    if (rcIrCalData[5] != '\0') {
      rcIrCalData[5] = '\x01';
    }
    rcIrCalData[6] = settings[7];
    if (rcIrCalData[6] != '\0') {
      rcIrCalData[6] = '\x01';
    }
    rcIrCalData[7] = settings[8];
    if (rcIrCalData[7] != '\0') {
      rcIrCalData[7] = '\x01';
    }
    if (*settings < 0x18) {
      rcIrCalData[9] = settings[10];
      if (rcIrCalData[9] != '\0') {
        rcIrCalData[9] = '\x01';
      }
      rcIrCalData[10] = settings[0xb];
      rcIrCalData[11] = settings[0xc];
      rcIrCalData._12_2_ = CONCAT11(settings[0xe],settings[0xd]);
      uVar1 = settings[0x10];
      uVar2 = settings[0xf];
    }
    else {
      rcIrCalData[9] = settings[0x12];
      if (rcIrCalData[9] != '\0') {
        rcIrCalData[9] = '\x01';
      }
      rcIrCalData[10] = settings[0x13];
      rcIrCalData[11] = settings[0x14];
      rcIrCalData._12_2_ = CONCAT11(settings[0x16],settings[0x15]);
      uVar1 = settings[0x18];
      uVar2 = settings[0x17];
    }
    rcIrCalData[0] = settings[1];
    rcIrCalData[1] = settings[2];
    rcIrCalData[2] = settings[3];
    rcIrCalData[3] = settings[4];
    rcIrCalData[4] = settings[5];
    rcIrCalData[8] = settings[9];
    rcIrCalData._14_2_ = CONCAT11(uVar1,uVar2);
    rcIrCalData[16] = settings[0x11];
    return '\0';
  }
  IRCAL_Set(0);
  return '\x01';
}



void IRCAL_SaveRegStates(void)

{
  uint uVar1;
  
  BUFC_RxBuffer._0_4_ = (RAC->SGRFENCTRL0);
  BUFC_RxBuffer._4_4_ = (RAC->RFENCTRL0);
  BUFC_RxBuffer._8_4_ = (AGC->CTRL0);
  BUFC_RxBuffer._12_4_ = (AGC->MANGAIN);
  BUFC_RxBuffer._16_4_ = (AGC->GAINRANGE);
  BUFC_RxBuffer._20_4_ = (AGC->GAININDEX);
  BUFC_RxBuffer._24_4_ = (AGC->MININDEX);
  BUFC_RxBuffer._28_4_ = (MODEM->MODINDEX);
  BUFC_RxBuffer._32_4_ = (MODEM->CTRL0);
  BUFC_RxBuffer._36_4_ = (FRC->DFLCTRL);
  BUFC_RxBuffer._40_4_ = (RAC->SGPACTRL0);
  BUFC_RxBuffer._44_4_ = (RAC->SGPAPKDCTRL);
  BUFC_RxBuffer._48_4_ = (RAC->SGPABIASCTRL0);
  BUFC_RxBuffer._52_4_ = (RAC->SGPABIASCTRL1);
  BUFC_RxBuffer._56_4_ = (RAC->PACTUNECTRL);
  BUFC_RxBuffer._60_4_ = (MODEM->RAMPCTRL);
  BUFC_RxBuffer._64_4_ = (RAC->TESTCTRL);
  BUFC_RxBuffer._68_4_ = (AGC->CTRL1);
  BUFC_RxBuffer._72_4_ = (MODEM->AFC);
  BUFC_RxBuffer._76_4_ = SYNTH_RfFreqGet();
  BUFC_RxBuffer._80_4_ = SYNTH_ChSpacingGet();
  write_volatile_4(MODEM->AFC,0);
  BUS_RegMaskedSet(&FRC->CTRL,1);
  BUS_RegMaskedSet(&RAC->CTRL,0x40);
  uVar1 = (AGC->CTRL1);
  write_volatile_4(AGC->CTRL1,uVar1 & 0xfffff0ff | (rcIrCalData[16] & 0xf) << 8);
  return;
}



undefined4 IRCAL_SetRxFrequency(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = SYNTH_IfFreqGet();
  uVar1 = (SYNTH->IFFREQ);
  iVar3 = iVar2 * 2;
  if ((uVar1 & 0x100000) != 0) {
    iVar3 = iVar2 * -2;
  }
  iVar2 = SYNTH_VcoRangeIsValid(param_1 + iVar3);
  if (iVar2 == 0) {
    IRCAL_Set();
    return 0xffffffff;
  }
  SYNTH_Config(param_1 + iVar3,0);
  return 0;
}



void IRCAL_StartRx(void)

{
  uint uVar1;
  
  BUS_RegMaskedSet(&MODEM->CTRL0,0x200000);
  do {
    uVar1 = (RAC->STATUS);
  } while ((uVar1 & 0xf000000) != 0);
  BUFC_RxBufferReset();
  BUS_RegMaskedSet(&RAC->RXENSRCEN,8);
  do {
    uVar1 = (RAC->STATUS);
  } while ((uVar1 << 4) >> 0x1c != 2);
  return;
}



void IRCAL_StopRx(void)

{
  CORE_irqState_t irqState;
  int iVar1;
  uint uVar2;
  bool bVar3;
  
  iVar1 = 0xff;
  BUS_RegMaskedClear(&RAC->RXENSRCEN,0xff);
  irqState = CORE_EnterCritical();
  uVar2 = (RAC->STATUS);
  uVar2 = (uVar2 << 4) >> 0x1c;
  bVar3 = uVar2 == 3;
  if (bVar3) {
    iVar1 = 0x21000f64;
    uVar2 = (SEQ->REG06C);
    uVar2 = uVar2 & 0xffffff0f | 0xe0;
  }
  if (bVar3) {
    *(uint *)(iVar1 + 8) = uVar2;
  }
  write_volatile_4(FRC->CMD,1);
  CORE_ExitCritical(irqState);
  do {
    uVar2 = (RAC->STATUS);
  } while ((uVar2 & 0xf000000) != 0);
  return;
}



void IRCAL_SetSubGhzPllLoopback(void)

{
  uint uVar1;
  
  uVar1 = (AGC->MANGAIN);
  write_volatile_4(AGC->MANGAIN,uVar1 & 0x801001ff | 0x40009800);
  BUS_RegMaskedSet(&AGC->CTRL0,0x400000);
  BUS_RegMaskedSet(&RAC->SGRFENCTRL0,0x80000);
  BUS_RegMaskedSet(&RAC->RFENCTRL0,0x80000);
  return;
}



void IRCAL_SetSubGhzPaLoopback(void)

{
  uint uVar1;
  
  uVar1 = (AGC->GAINRANGE);
  write_volatile_4(AGC->GAINRANGE,uVar1 & 0xffffc000 | 0x383e);
  uVar1 = (AGC->GAININDEX);
  write_volatile_4(AGC->GAININDEX,uVar1 & 0xfff00000 | 0x25bc);
  uVar1 = (AGC->MININDEX);
  write_volatile_4(AGC->MININDEX,uVar1 & 0xff000000 | 0x6d8480);
  uVar1 = (AGC->MANGAIN);
  write_volatile_4(AGC->MANGAIN,uVar1 & 0xffffff40 | 0xa7);
  BUS_RegMaskedSet(&AGC->CTRL0,0x400000);
  write_volatile_4(MODEM->MODINDEX,0);
  uVar1 = (MODEM->CTRL0);
  write_volatile_4(MODEM->CTRL0,uVar1 & 0xfffffe3f | 0x100);
  uVar1 = (FRC->DFLCTRL);
  write_volatile_4(FRC->DFLCTRL,uVar1 & 0xfffffff8 | 5);
  BUS_RegMaskedClear(&RAC->SGRFENCTRL0,0x80000);
  uVar1 = (RAC->SGPACTRL0);
  write_volatile_4(RAC->SGPACTRL0,uVar1 & 0x3fffffff | 0x40000000);
  BUS_RegMaskedClear(&RAC->SGPAPKDCTRL,0xc000);
  BUS_RegMaskedSet(&RAC->SGPAPKDCTRL,0xc000);
  uVar1 = (RAC->SGPABIASCTRL0);
  write_volatile_4(RAC->SGPABIASCTRL0,uVar1 & 0xff3ff332 | 0x445);
  uVar1 = (RAC->SGPABIASCTRL1);
  write_volatile_4(RAC->SGPABIASCTRL1,uVar1 & 0xffffffc8 | 0x20);
  uVar1 = (RAC->SGPABIASCTRL1);
  write_volatile_4(RAC->SGPABIASCTRL1,uVar1 & 0xfff388ff | 0x84500);
  BUS_RegMaskedClear(&RAC->PACTUNECTRL,0x1f0);
  BUS_RegMaskedSet(&RAC->SGPACTRL0,8);
  BUS_RegMaskedSet(&RAC->SGRFENCTRL0,0x10000);
  PHY_UTILS_DelayUs(0x14);
  uVar1 = (RAC->SGPACTRL0);
  write_volatile_4(RAC->SGPACTRL0,uVar1 & 0xffffc03f | 0x40);
  BUS_RegMaskedSet(&RAC->SGRFENCTRL0,0x20000);
  PHY_UTILS_DelayUs(0x14);
  uVar1 = (RAC->SGPACTRL0);
  write_volatile_4(RAC->SGPACTRL0,uVar1 & 0xe0c03fff | 0x1004000);
  PHY_UTILS_DelayUs(0x14);
  BUS_RegMaskedSet(&RAC->SGRFENCTRL0,0x40000);
  PHY_UTILS_DelayUs(0x14);
  BUS_RegMaskedSet(&RAC->TESTCTRL,9);
  PHY_UTILS_DelayUs(0x14);
  uVar1 = (RAC->SGPACTRL0);
  write_volatile_4(RAC->SGPACTRL0,uVar1 & 0xe0c03fff | 0x1004000);
  PHY_UTILS_DelayUs(0x14);
  uVar1 = (MODEM->RAMPCTRL);
  write_volatile_4(MODEM->RAMPCTRL,
                   uVar1 & 0x7fffff | 0x800000 | (uint)rcIrCalData[2] << 0x18);
  PHY_UTILS_DelayUs(0x14);
  return;
}



undefined4 IRCAL_Setup(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined uVar1;
  int iVar2;
  
  IRCAL_SaveRegStates();
  uVar1 = rcIrCalData[3];
  if (((param_1 == 2) || (uVar1 = rcIrCalData[4], param_1 == 3)) &&
     (iVar2 = AUXPLL_Start(param_1,uVar1,rcIrCalData[0],rcIrCalData[1],param_4), iVar2 != -1)) {
    IRCAL_StopRx();
    iVar2 = IRCAL_SetRxFrequency(iVar2);
    if (iVar2 != -1) {
      IRCAL_StartRx();
      if (param_1 == 2) {
        IRCAL_SetSubGhzPllLoopback();
      }
      else {
        if (param_1 != 3) {
          return 0xffffffff;
        }
        IRCAL_SetSubGhzPaLoopback();
      }
      return 0;
    }
  }
  return 0xffffffff;
}



uint IRCAL_TranslateToRssiIndex(uint param_1)

{
  if (param_1 < 0x40) {
    param_1 = 0x40 - param_1 & 0xff;
  }
  return param_1;
}



int IRCAL_ReadRssi(uint param_1,uint param_2,uint param_3,undefined4 param_4,undefined2 param_5)

{
  uint uVar1;
  int16_t iVar2;
  short sVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  if ((param_1 & 0x80) != 0) {
    param_1 = 0x7f;
  }
  if ((param_2 & 0x80) != 0) {
    param_2 = 0x7f;
  }
  if (param_3 < 0xf) {
    uVar5 = (RAC->IFPGACAL);
    write_volatile_4(RAC->IFPGACAL,uVar5 & 0xffff8080 | param_1 << 8 | param_2);
    PHY_UTILS_DelayUs(param_4);
    if (rcIrCalData[9] == '\0') {
      write_volatile_4(AGC->IFC,0x20);
    }
    uVar5 = 0;
    uVar4 = 0;
    for (uVar6 = 0; uVar6 >> (param_3 & 0xff) == 0; uVar6 = uVar6 + 1) {
      PHY_UTILS_DelayUs(param_5);
      if (rcIrCalData[9] == '\0') {
        write_volatile_4(AGC->CMD,1);
        do {
          uVar1 = (AGC->IF);
        } while (-1 < (int)(uVar1 << 0x1a));
      }
      if (rcIrCalData[11] <= uVar6) {
        iVar2 = RADIO_GetRSSI();
        uVar5 = uVar5 + 1;
        uVar4 = uVar4 + (int)iVar2;
      }
      if (rcIrCalData[9] == '\0') {
        write_volatile_4(AGC->IFC,0x20);
      }
    }
    if (uVar5 == 0) {
      uVar5 = 1;
    }
    sVar3 = (short)(uVar4 / uVar5);
  }
  else {
    sVar3 = -1;
  }
  return (int)sVar3;
}


uint IRCAL_SearchLinear2Stage
               (uint param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined2 param_5)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  short sVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar8 = 0;
  sVar5 = 0x7fff;
  uVar6 = 5;
  do {
    uVar3 = 0x40 - uVar6 & 0xff;
    do {
      uVar7 = param_1;
      if (param_2 != 0) {
        uVar7 = uVar3;
        uVar3 = param_1;
      }
      sVar1 = IRCAL_ReadRssi(uVar7,uVar3,param_3,param_4,param_5);
      uVar3 = uVar6 + 10 & 0xff;
      if (sVar1 < sVar5) {
        uVar8 = uVar6;
        sVar5 = sVar1;
      }
      if (uVar3 == 0x87) {
        uVar3 = uVar8 - 5;
        uVar7 = 0x45 - uVar8;
        uVar6 = 0;
        sVar5 = 0x7fff;
        while( true ) {
          uVar3 = uVar3 & 0xff;
          if ((uVar8 + 5 < uVar3) || ((int)(uVar3 << 0x18) < 0)) break;
          if (uVar3 != 0) {
            uVar4 = uVar3;
            if (uVar3 < 0x40) {
              uVar4 = uVar7 & 0xff;
            }
            uVar2 = param_1;
            if (param_2 != 0) {
              uVar2 = uVar4;
              uVar4 = param_1;
            }
            sVar1 = IRCAL_ReadRssi(uVar2,uVar4,param_3,param_4,param_5);
            if (sVar1 < sVar5) {
              uVar6 = uVar3;
              sVar5 = sVar1;
            }
          }
          uVar3 = uVar3 + 1;
          uVar7 = (uVar7 & 0xff) - 1;
        }
        if (uVar6 < 0x40) {
          uVar6 = 0x40 - uVar6 & 0xff;
        }
        return uVar6;
      }
      uVar6 = uVar3;
    } while (0x3f < uVar3);
  } while( true );
}



uint IRCAL_Search(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  if (param_1 == 2) {
    uVar1 = IRCAL_SearchLinear2Stage(0,1,param_2,param_3,param_4,param_2,param_3);
    uVar2 = IRCAL_SearchLinear2Stage(uVar1,0,param_2,param_3,param_4);
    iVar3 = IRCAL_SearchLinear2Stage(uVar2,1,param_2,param_3,param_4);
    uVar2 = uVar2 | iVar3 << 8;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



void IRCAL_Teardown(void)

{
  undefined4 in_r3;
  
  IRCAL_StopRx();
  AUXPLL_Stop();
  write_volatile_4(RAC->SGRFENCTRL0,BUFC_RxBuffer._0_4_);
  write_volatile_4(RAC->RFENCTRL0,BUFC_RxBuffer._4_4_);
  write_volatile_4(AGC->CTRL0,BUFC_RxBuffer._8_4_);
  write_volatile_4(AGC->MANGAIN,BUFC_RxBuffer._12_4_);
  write_volatile_4(AGC->GAINRANGE,BUFC_RxBuffer._16_4_);
  write_volatile_4(AGC->GAININDEX,BUFC_RxBuffer._20_4_);
  write_volatile_4(AGC->MININDEX,BUFC_RxBuffer._24_4_);
  write_volatile_4(MODEM->MODINDEX,BUFC_RxBuffer._28_4_);
  write_volatile_4(MODEM->CTRL0,BUFC_RxBuffer._32_4_);
  write_volatile_4(FRC->DFLCTRL,BUFC_RxBuffer._36_4_);
  write_volatile_4(RAC->SGPACTRL0,BUFC_RxBuffer._40_4_);
  write_volatile_4(RAC->SGPAPKDCTRL,BUFC_RxBuffer._44_4_);
  write_volatile_4(RAC->SGPABIASCTRL0,BUFC_RxBuffer._48_4_);
  write_volatile_4(RAC->SGPABIASCTRL1,BUFC_RxBuffer._52_4_);
  write_volatile_4(RAC->PACTUNECTRL,BUFC_RxBuffer._56_4_);
  write_volatile_4(MODEM->RAMPCTRL,BUFC_RxBuffer._60_4_);
  write_volatile_4(RAC->TESTCTRL,BUFC_RxBuffer._64_4_);
  write_volatile_4(AGC->CTRL1,BUFC_RxBuffer._68_4_);
  write_volatile_4(MODEM->AFC,BUFC_RxBuffer._72_4_);
  SYNTH_Config(BUFC_RxBuffer._76_4_,BUFC_RxBuffer._80_4_,BUFC_RxBuffer._72_4_,BUFC_RxBuffer,in_r3);
  BUFC_RxBufferReset();
  BUS_RegMaskedClear(&FRC->CTRL,1);
  BUS_RegMaskedClear(&RAC->CTRL,0x40);
  return;
}



uint IRCAL_Get(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::RAC.IFPGACAL);
  return uVar1 & 0xffff;
}



uint IRCAL_GetDiValue(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = SYNTH_RfFreqGet();
  if (uVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = _DAT_0fe081c8;
    if ((999999999 < uVar1) &&
       (uVar1 = (MODEM->CTRL0), uVar2 = _DAT_0fe081c4,
       (uVar1 << 0x17) >> 0x1d != 4)) {
      uVar2 = _DAT_0fe081c0;
    }
    if (uVar2 != 0xffffffff) {
      return uVar2 & 0xffff;
    }
  }
  return uVar2;
}




uint IRCAL_PerformSubfunction
               (uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined2 param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  uint64_t uVar5;
  uint64_t uVar6;
  undefined8 uVar7;
  
  uVar2 = (PROTIMER->WRAPCNT);
  uVar5 = PROTIMER_PrecntOverflowToUs(uVar2);
  if (param_1 == 1) {
    uVar2 = IRCAL_GetDiValue();
    BUFC_RxBufferReset();
  }
  else {
    if ((param_1 == 0) || (3 < param_1)) {
      uVar2 = 0xffffffff;
    }
    else {
      uVar2 = IRCAL_Setup(param_1);
      if (uVar2 != 0xffffffff) {
        uVar2 = IRCAL_Search(param_2,param_3,param_4,param_5);
      }
      IRCAL_Teardown();
    }
  }
  uVar3 = (PROTIMER->WRAPCNT);
  uVar6 = PROTIMER_PrecntOverflowToUs(uVar3);
  uVar7 = __aeabi_uldivmod((int)(uVar6 - uVar5),(int)(uVar6 - uVar5 >> 0x20),1000,0);
  iVar1 = (int)((ulonglong)uVar7 >> 0x20);
  bVar4 = iVar1 == 0;
  if (iVar1 == 0) {
    bVar4 = (uint)uVar7 < 0xffff;
  }
  if (bVar4) {
    uVar3 = (uint)uVar7 & 0xfffe;
  }
  else {
    uVar3 = 0;
  }
  if (uVar2 != 0xffffffff) {
    IRCAL_Set(uVar2);
    uVar2 = uVar2 | uVar3 << 0x10;
  }
  return uVar2;
}



undefined4 IRCAL_Perform(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = IRCAL_GetGlobalCalType();
  if (iVar1 == 0xff) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = IRCAL_PerformSubfunction
                      (iVar1,2,rcIrCalData[10],rcIrCalData._12_2_,rcIrCalData._14_2_,param_2,param_3
                      );
  }
  return uVar2;
}

