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
    uVar1 = read_volatile_4(Peripherals::RAC.IFPGACAL);
    write_volatile_4(Peripherals::RAC.IFPGACAL,uVar1 & 0xffff0000 | param_1 & 0xffff);
  }
  return;
}



uint8_t IRCAL_Init(uint8_t *ircalsettings)

{
  if ((ircalsettings != (uint8_t *)0x0) && (0xf < *ircalsettings)) {
    rcIrCalData[5] = ircalsettings[6];
    if (rcIrCalData[5] != '\0') {
      rcIrCalData[5] = '\x01';
    }
    rcIrCalData[6] = ircalsettings[7];
    if (rcIrCalData[6] != '\0') {
      rcIrCalData[6] = '\x01';
    }
    rcIrCalData[7] = ircalsettings[8];
    if (rcIrCalData[7] != '\0') {
      rcIrCalData[7] = '\x01';
    }
    rcIrCalData[9] = ircalsettings[10];
    if (rcIrCalData[9] != '\0') {
      rcIrCalData[9] = '\x01';
    }
    rcIrCalData[0] = ircalsettings[1];
    rcIrCalData[1] = ircalsettings[2];
    rcIrCalData[2] = ircalsettings[3];
    rcIrCalData[3] = ircalsettings[4];
    rcIrCalData[4] = ircalsettings[5];
    rcIrCalData[8] = ircalsettings[9];
    rcIrCalData[10] = ircalsettings[0xb];
    rcIrCalData[11] = ircalsettings[0xc];
    rcIrCalData._12_2_ = CONCAT11(ircalsettings[0xe],ircalsettings[0xd]);
    rcIrCalData._14_2_ = *(undefined2 *)(ircalsettings + 0xf);
    return '\0';
  }
  IRCAL_Set(0);
  return '\x01';
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void IRCAL_SaveRegStates(void)

{
  uint uVar1;
  
  RADIO_rxBuffer = read_volatile_4(Peripherals::RAC.SGRFENCTRL0);
  _SYNTH_IfFreqGet = read_volatile_4(Peripherals::RAC.RFENCTRL0);
  _SYNTH_VcoRangeIsValid = read_volatile_4(Peripherals::AGC.CTRL0);
  _SYNTH_Config = read_volatile_4(Peripherals::AGC.MANGAIN);
  _RADIO_RxBufferReset = read_volatile_4(Peripherals::AGC.GAINRANGE);
  _PHY_UTILS_DelayUs = read_volatile_4(Peripherals::AGC.GAININDEX);
  _AUXPLL_Start = read_volatile_4(Peripherals::AGC.MININDEX);
  _RADIO_GetRSSI = read_volatile_4(Peripherals::MODEM.MODINDEX);
  _AUXPLL_Stop = read_volatile_4(Peripherals::MODEM.CTRL0);
  ___aeabi_uldivmod = read_volatile_4(Peripherals::FRC.DFLCTRL);
  _PROTIMER_PrecntOverflowToUs = read_volatile_4(Peripherals::RAC.SGPACTRL0);
  _DAT_00011044 = read_volatile_4(Peripherals::RAC.SGPAPKDCTRL);
  _DAT_00011048 = read_volatile_4(Peripherals::RAC.SGPABIASCTRL0);
  _DAT_0001104c = read_volatile_4(Peripherals::RAC.SGPABIASCTRL1);
  _DAT_00011050 = read_volatile_4(Peripherals::RAC.PACTUNECTRL);
  _DAT_00011054 = read_volatile_4(Peripherals::MODEM.RAMPCTRL);
  _DAT_00011058 = read_volatile_4(Peripherals::RAC.TESTCTRL);
  _DAT_0001105c = SYNTH_RfFreqGet();
  _DAT_00011060 = SYNTH_ChSpacingGet();
  uVar1 = read_volatile_4(Peripherals::FRC.CTRL);
  write_volatile_4(Peripherals::FRC.CTRL,uVar1 | 1);
  uVar1 = read_volatile_4(Peripherals::RAC.CTRL);
  write_volatile_4(Peripherals::RAC.CTRL,uVar1 | 0x40);
  return;
}



undefined4 IRCAL_SetRxFrequency(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = SYNTH_IfFreqGet();
  uVar1 = read_volatile_4(Peripherals::SYNTH.IFFREQ);
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
  
  uVar1 = read_volatile_4(Peripherals::MODEM.CTRL0);
  write_volatile_4(Peripherals::MODEM.CTRL0,uVar1 | 0x200000);
  do {
    uVar1 = read_volatile_4(Peripherals::RAC.STATUS);
  } while ((uVar1 & 0xf000000) != 0);
  RADIO_RxBufferReset();
  do {
    uVar1 = read_volatile_4(Peripherals::RAC.STATUS);
  } while ((uVar1 << 4) >> 0x1c != 2);
  _DAT_4308000c = 1;
  return;
}



void IRCAL_StopRx(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::RAC.RXENSRCEN);
  write_volatile_4(Peripherals::RAC.RXENSRCEN,uVar1 & 0xffffff00);
  write_volatile_4(Peripherals::FRC.CMD,1);
  do {
    uVar1 = read_volatile_4(Peripherals::RAC.STATUS);
  } while ((uVar1 & 0xf000000) != 0);
  return;
}



void IRCAL_SetSubGhzPllLoopback(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::AGC.MANGAIN);
  write_volatile_4(Peripherals::AGC.MANGAIN,uVar1 & 0x801001ff | 0x40009800);
  uVar1 = read_volatile_4(Peripherals::AGC.CTRL0);
  write_volatile_4(Peripherals::AGC.CTRL0,uVar1 | 0x400000);
  uVar1 = read_volatile_4(Peripherals::RAC.SGRFENCTRL0);
  write_volatile_4(Peripherals::RAC.SGRFENCTRL0,uVar1 | 0x80000);
  uVar1 = read_volatile_4(Peripherals::RAC.RFENCTRL0);
  write_volatile_4(Peripherals::RAC.RFENCTRL0,uVar1 | 0x80000);
  return;
}



void IRCAL_SetSubGhzPaLoopback(void)

{
  uint uVar1;
  undefined4 extraout_r1;
  undefined4 in_r3;
  
  uVar1 = read_volatile_4(Peripherals::AGC.GAINRANGE);
  write_volatile_4(Peripherals::AGC.GAINRANGE,uVar1 & 0xffffc000 | 0x383e);
  uVar1 = read_volatile_4(Peripherals::AGC.GAININDEX);
  write_volatile_4(Peripherals::AGC.GAININDEX,uVar1 & 0xfff00000 | 0x25bc);
  uVar1 = read_volatile_4(Peripherals::AGC.MININDEX);
  write_volatile_4(Peripherals::AGC.MININDEX,uVar1 & 0xff000000 | 0x6d8480);
  uVar1 = read_volatile_4(Peripherals::AGC.MANGAIN);
  write_volatile_4(Peripherals::AGC.MANGAIN,uVar1 & 0xffffff40 | 0xa7);
  uVar1 = read_volatile_4(Peripherals::AGC.CTRL0);
  write_volatile_4(Peripherals::AGC.CTRL0,uVar1 | 0x400000);
  write_volatile_4(Peripherals::MODEM.MODINDEX,0);
  uVar1 = read_volatile_4(Peripherals::MODEM.CTRL0);
  write_volatile_4(Peripherals::MODEM.CTRL0,uVar1 & 0xfffffe3f | 0x100);
  uVar1 = read_volatile_4(Peripherals::FRC.DFLCTRL);
  write_volatile_4(Peripherals::FRC.DFLCTRL,uVar1 & 0xfffffff8 | 5);
  uVar1 = read_volatile_4(Peripherals::RAC.SGRFENCTRL0);
  write_volatile_4(Peripherals::RAC.SGRFENCTRL0,uVar1 & 0xfff7ffff);
  uVar1 = read_volatile_4(Peripherals::RAC.SGPACTRL0);
  write_volatile_4(Peripherals::RAC.SGPACTRL0,uVar1 & 0x3fffffff | 0x40000000);
  uVar1 = read_volatile_4(Peripherals::RAC.SGPAPKDCTRL);
  write_volatile_4(Peripherals::RAC.SGPAPKDCTRL,uVar1 | 0xc000);
  uVar1 = read_volatile_4(Peripherals::RAC.SGPABIASCTRL0);
  write_volatile_4(Peripherals::RAC.SGPABIASCTRL0,uVar1 & 0xff3ff332 | 0x445);
  uVar1 = read_volatile_4(Peripherals::RAC.SGPABIASCTRL1);
  write_volatile_4(Peripherals::RAC.SGPABIASCTRL1,uVar1 & 0xffffffc8 | 0x20);
  uVar1 = read_volatile_4(Peripherals::RAC.SGPABIASCTRL1);
  write_volatile_4(Peripherals::RAC.SGPABIASCTRL1,uVar1 & 0xfff388ff | 0x84500);
  uVar1 = read_volatile_4(Peripherals::RAC.PACTUNECTRL);
  write_volatile_4(Peripherals::RAC.PACTUNECTRL,uVar1 & 0xfffffe0f);
  uVar1 = read_volatile_4(Peripherals::RAC.SGPACTRL0);
  write_volatile_4(Peripherals::RAC.SGPACTRL0,uVar1 | 8);
  uVar1 = read_volatile_4(Peripherals::RAC.SGRFENCTRL0);
  write_volatile_4(Peripherals::RAC.SGRFENCTRL0,uVar1 | 0x10000);
  PHY_UTILS_DelayUs(0x14);
  uVar1 = read_volatile_4(Peripherals::RAC.SGPACTRL0);
  write_volatile_4(Peripherals::RAC.SGPACTRL0,uVar1 & 0xffffc03f | 0x40);
  uVar1 = read_volatile_4(Peripherals::RAC.SGRFENCTRL0);
  write_volatile_4(Peripherals::RAC.SGRFENCTRL0,uVar1 | 0x20000);
  PHY_UTILS_DelayUs(0x14);
  uVar1 = read_volatile_4(Peripherals::RAC.SGPACTRL0);
  write_volatile_4(Peripherals::RAC.SGPACTRL0,uVar1 & 0xe0c03fff | 0x1004000);
  PHY_UTILS_DelayUs(0x14);
  uVar1 = read_volatile_4(Peripherals::RAC.SGRFENCTRL0);
  write_volatile_4(Peripherals::RAC.SGRFENCTRL0,uVar1 | 0x40000);
  PHY_UTILS_DelayUs(0x14);
  uVar1 = read_volatile_4(Peripherals::RAC.TESTCTRL);
  write_volatile_4(Peripherals::RAC.TESTCTRL,uVar1 | 9);
  PHY_UTILS_DelayUs(0x14);
  uVar1 = read_volatile_4(Peripherals::RAC.SGPACTRL0);
  write_volatile_4(Peripherals::RAC.SGPACTRL0,uVar1 & 0xe0c03fff | 0x1004000);
  PHY_UTILS_DelayUs(0x14);
  uVar1 = read_volatile_4(Peripherals::MODEM.RAMPCTRL);
  write_volatile_4(Peripherals::MODEM.RAMPCTRL,
                   uVar1 & 0x7fffff | 0x800000 | (uint)rcIrCalData[2] << 0x18);
  PHY_UTILS_DelayUs(0x14,extraout_r1,rcIrCalData[2],in_r3);
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



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

int IRCAL_ReadRssi(uint param_1,uint param_2,uint param_3,undefined4 param_4,undefined2 param_5)

{
  uint uVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  if ((param_1 & 0x80) != 0) {
    param_1 = 0x7f;
  }
  if ((param_2 & 0x80) != 0) {
    param_2 = 0x7f;
  }
  if (param_3 < 0x10) {
    uVar4 = read_volatile_4(Peripherals::RAC.IFPGACAL);
    write_volatile_4(Peripherals::RAC.IFPGACAL,uVar4 & 0xffff8080 | param_1 << 8 | param_2);
    PHY_UTILS_DelayUs(param_4);
    uVar5 = (uint)rcIrCalData[9];
    uVar4 = uVar5;
    uVar6 = uVar5;
    if (uVar5 == 0) {
      for (; _DAT_430e0714 = 1, uVar6 >> (param_3 & 0xff) == 0; uVar6 = uVar6 + 1) {
        write_volatile_4(Peripherals::AGC.CMD,1);
        do {
          uVar1 = read_volatile_4(Peripherals::AGC.IF);
        } while (-1 < (int)(uVar1 << 0x1a));
        if (rcIrCalData[11] <= uVar6) {
          iVar3 = RADIO_GetRSSI();
          uVar4 = uVar4 + 1;
          uVar5 = uVar5 + iVar3;
        }
      }
    }
    else {
      uVar4 = 0;
      uVar5 = 0;
      for (uVar6 = 0; uVar6 >> (param_3 & 0xff) == 0; uVar6 = uVar6 + 1) {
        PHY_UTILS_DelayUs(param_5);
        if (rcIrCalData[11] <= uVar6) {
          iVar3 = RADIO_GetRSSI();
          uVar4 = uVar4 + 1;
          uVar5 = uVar5 + iVar3;
        }
      }
    }
    if (uVar4 == 0) {
      uVar4 = 1;
    }
    sVar2 = (short)(uVar5 / uVar4);
  }
  else {
    sVar2 = -1;
  }
  return (int)sVar2;
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



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void IRCAL_Teardown(void)

{
  uint uVar1;
  undefined4 in_r3;
  
  IRCAL_StopRx();
  AUXPLL_Stop();
  write_volatile_4(Peripherals::RAC.SGRFENCTRL0,RADIO_rxBuffer);
  write_volatile_4(Peripherals::RAC.RFENCTRL0,_SYNTH_IfFreqGet);
  write_volatile_4(Peripherals::AGC.CTRL0,_SYNTH_VcoRangeIsValid);
  write_volatile_4(Peripherals::AGC.MANGAIN,_SYNTH_Config);
  write_volatile_4(Peripherals::AGC.GAINRANGE,_RADIO_RxBufferReset);
  write_volatile_4(Peripherals::AGC.GAININDEX,_PHY_UTILS_DelayUs);
  write_volatile_4(Peripherals::AGC.MININDEX,_AUXPLL_Start);
  write_volatile_4(Peripherals::MODEM.MODINDEX,_RADIO_GetRSSI);
  write_volatile_4(Peripherals::MODEM.CTRL0,_AUXPLL_Stop);
  write_volatile_4(Peripherals::FRC.DFLCTRL,___aeabi_uldivmod);
  write_volatile_4(Peripherals::RAC.SGPACTRL0,_PROTIMER_PrecntOverflowToUs);
  write_volatile_4(Peripherals::RAC.SGPAPKDCTRL,_DAT_00011044);
  write_volatile_4(Peripherals::RAC.SGPABIASCTRL0,_DAT_00011048);
  write_volatile_4(Peripherals::RAC.SGPABIASCTRL1,_DAT_0001104c);
  write_volatile_4(Peripherals::RAC.PACTUNECTRL,_DAT_00011050);
  write_volatile_4(Peripherals::MODEM.RAMPCTRL,_DAT_00011054);
  write_volatile_4(Peripherals::RAC.TESTCTRL,_DAT_00011058);
  SYNTH_Config(_DAT_0001105c,_DAT_00011060,_DAT_00011058,&RADIO_rxBuffer,in_r3);
  RADIO_RxBufferReset();
  uVar1 = read_volatile_4(Peripherals::FRC.CTRL);
  write_volatile_4(Peripherals::FRC.CTRL,uVar1 & 0xfffffffe);
  uVar1 = read_volatile_4(Peripherals::RAC.CTRL);
  write_volatile_4(Peripherals::RAC.CTRL,uVar1 & 0xffffffbf);
  return;
}



uint IRCAL_Get(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::RAC.IFPGACAL);
  return uVar1 & 0xffff;
}



uint32_t IRCAL_GetDiValue(void)

{
  uint32_t uVar1;
  uint uVar2;
  uint *puVar3;
  
  uVar1 = SYNTH_RfFreqGet();
  if (uVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    if (uVar1 < 1000000000) {
      puVar3 = &DAT_0fe081c8;
    }
    else {
      uVar2 = read_volatile_4(Peripherals::MODEM.CTRL0);
      if ((uVar2 << 0x17) >> 0x1d == 4) {
        puVar3 = (uint *)&DAT_0fe081c4;
      }
      else {
        puVar3 = (uint *)&DAT_0fe081c0;
      }
    }
    uVar2 = *puVar3;
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
  longlong lVar5;
  longlong lVar6;
  undefined8 uVar7;
  
  uVar2 = read_volatile_4(Peripherals::PROTIMER.WRAPCNT);
  lVar5 = PROTIMER_PrecntOverflowToUs(uVar2);
  if (param_1 == 1) {
    uVar2 = IRCAL_GetDiValue();
    RADIO_RxBufferReset();
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
  uVar3 = read_volatile_4(Peripherals::PROTIMER.WRAPCNT);
  lVar6 = PROTIMER_PrecntOverflowToUs(uVar3);
  uVar7 = __aeabi_uldivmod((int)(lVar6 - lVar5),(int)((ulonglong)(lVar6 - lVar5) >> 0x20),1000,0);
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


