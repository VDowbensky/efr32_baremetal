#include "ir_cal.h"

uint8_t globalCalType; //???

uint32_t regbuf[];

uint8_t IRCAL_Configure(uint8_t cal)

{
  switch(cal) 
  {
  case 0:
    if (rcIrCalData[8] == 1) 
	{
      if (rcIrCalData[5] == 0) return 0;
    }
    else 
	{
      if (rcIrCalData[8] == 2) 
	  {
        if (rcIrCalData[6] == 0) return 0;
      }
      else 
	  {
        if (rcIrCalData[8] != 3) return 0;
        if (rcIrCalData[7] == 0) return 0;
      }
    }
    break;
  case 1:
    if (rcIrCalData[5] == '\0') return 0;
    globalCalType = 1;
    break;
  case 2:
    if (rcIrCalData[6] == '\0') return 0;
    globalCalType = 2;
    break;
  case 3:
    if (rcIrCalData[7] == '\0') return 0;
    globalCalType = 3;
    break;
  default:
    return 0;
  }
  globalCalType = rcIrCalData[8];
  return 1;
}



void IRCAL_SetGlobalCalType(uint8_t cal)

{
  globalCalType = cal;
}



uint8_t IRCAL_GetGlobalCalType(void)

{
  IRCAL_Configure(globalCalType);
  return globalCalType;
}



void IRCAL_Set(uint32_t cal)

{
  if (cal != 0xffffffff) 
  {
	RAC->IFPGACAL &= 0xffff0000;
	RAC->IFPGACAL |= cal & 0xffff;
  }
}



uint8_t IRCAL_Init(uint8_t *caldata)

{
  byte bVar1;
  byte bVar2;
  
  if ((caldata != (byte *)0x0) && (0x11 < *caldata)) 
  {
    rcIrCalData[5] = caldata[6];
    if (rcIrCalData[5] != 0) rcIrCalData[5] = 1;
    rcIrCalData[6] = caldata[7];
    if (rcIrCalData[6] != 0) rcIrCalData[6] = 1;
    rcIrCalData[7] = caldata[8];
    if (rcIrCalData[7] != 0) rcIrCalData[7] = 1;
    if (*caldata < 0x18) 
	{
      rcIrCalData[9] = caldata[10];
      if (rcIrCalData[9] != 0) rcIrCalData[9] = 1;
      rcIrCalData[10] = caldata[0xb];
      rcIrCalData[11] = caldata[0xc];
      rcIrCalData._12_2_ = CONCAT11(caldata[0xe],caldata[0xd]);
      bVar1 = caldata[0x10];
      bVar2 = caldata[0xf];
    }
    else 
	{
      rcIrCalData[9] = caldata[0x12];
      if (rcIrCalData[9] != 0) rcIrCalData[9] = 1;
      rcIrCalData[10] = caldata[0x13];
      rcIrCalData[11] = caldata[0x14];
      rcIrCalData._12_2_ = CONCAT11(caldata[0x16],caldata[0x15]);
      bVar1 = caldata[0x18];
      bVar2 = caldata[0x17];
    }
    rcIrCalData[0] = caldata[1];
    rcIrCalData[1] = caldata[2];
    rcIrCalData[2] = caldata[3];
    rcIrCalData[3] = caldata[4];
    rcIrCalData[4] = caldata[5];
    rcIrCalData[8] = caldata[9];
    rcIrCalData._14_2_ = CONCAT11(bVar1,bVar2);
    rcIrCalData[16] = caldata[0x11];
    return 0;
  }
  IRCAL_Set(0);
  return 1;
}



void IRCAL_SaveRegStates(void)

{
  uint uVar1;
  
  regbuf[0] = RAC->SGRFENCTRL0;
  regbuf[1] = RAC->RFENCTRL0;
  regbuf[2] = AGC->CTRL0;
  regbuf[3] = AGC->MANGAIN;
  regbuf[4] = AGC->GAINRANGE;
  regbuf[5] = AGC->GAININDEX;
  regbuf[6] = AGC->MININDEX;
  regbuf[7] = MODEM->MODINDEX;
  regbuf[8] = MODEM->CTRL0;
  regbuf[9] = FRC->DFLCTRL;
  regbuf[10] = RAC->SGPACTRL0;
  regbuf[11] = RAC->SGPAPKDCTRL;
  regbuf[12] = RAC->SGPABIASCTRL0;
  regbuf[13] = RAC->SGPABIASCTRL1;
  regbuf[14] = RAC->PACTUNECTRL;
  regbuf[15] = MODEM->RAMPCTRL;
  regbuf[16] = RAC->TESTCTRL;
  regbuf[17] = AGC->CTRL1;
  regbuf[18] = MODEM->AFC;
  regbuf[19] = SYNTH_RfFreqGet();
  regbuf[20] = SYNTH_ChSpacingGet();
  MODEM->AFC = 0;
  BUS_RegMaskedSet(&FRC->CTRL,FRC_CTRL_RANDOMTX_Msk); //1);
  BUS_RegMaskedSet(&RAC->CTRL,RAC_CTRL_TXPOSTPONE_Msk); //0x40);
  AGC->CTRL1 &= ~AGC_CTRL1_RSSIPERIOD_Msk;
  AGC->CTRL1 | (rcIrCalData[16] & 0xf) << 8;
}



uint32_t IRCAL_SetRxFrequency(uint32_t freq)

{
  int iffreq;

  if ((SYNTH->IFFREQ & 0x100000) != 0) iffreq = SYNTH_IfFreqGet() * -2;
  else iffreq = SYNTH_IfFreqGet() * 2;
  if (SYNTH_VcoRangeIsValid(freq + iffreq) == 0) 
  {
    IRCAL_Set();
    return 0xffffffff;
  }
  SYNTH_Config(freq + iffreq,0);
  return 0;
}



void IRCAL_StartRx(void)

{
  BUS_RegMaskedSet(&MODEM->CTRL0,MODEM_CTRL0_DETDIS_Msk);
  while ((RAC->STATUS & RAC_STATUS_STATE_Msk) != 0);
  BUFC_RxBufferReset();
  BUS_RegMaskedSet(&RAC->RXENSRCEN,8);
  while (((RAC->STATUS & RAC_STATUS_STATE_Msk) >> RAC_STATUS_STATE_Pos) != 2);
}



void IRCAL_StopRx(void)

{
  CORE_irqState_t irqState;
  
  BUS_RegMaskedClear(&RAC->RXENSRCEN,0xff);
  irqState = CORE_EnterCritical();
  if ((RAC->STATUS & RAC_STATUS_STATE_Msk) >> RAC_STATUS_STATE_Pos == 3) 
  {
	SEQ->REG06C &= 0xffffff0f;
	SEQ->REG06C |= 0xe0;
  }
  //if ((RAC->STATUS & RAC_STATUS_STATE_Msk) >> RAC_STATUS_STATE_Pos == 3) SEQ->REG06C = SEQ->REG06C;
  FRC->CMD = FRC_CMD_RXABORT_Msk; //1;
  CORE_ExitCritical(irqState);
  while ((RAC->STATUS & RAC_STATUS_STATE_Msk) != 0);
}



void IRCAL_SetSubGhzPllLoopback(void)

{
  AGC->MANGAIN &= 0x801001ff;
  AGC->MANGAIN |= 0x40009800;
  BUS_RegMaskedSet(&AGC->CTRL0,AGC_CTRL0_DISRESETCHPWR_Msk); //0x400000);
  BUS_RegMaskedSet(&RAC->SGRFENCTRL0,RAC_SGRFENCTRL0_TRSW_Msk); //0x80000);
  BUS_RegMaskedSet(&RAC->RFENCTRL0,RAC_RFENCTRL0_TRSW_Msk); //0x80000);
}



void IRCAL_SetSubGhzPaLoopback(void)

{
  AGC->GAINRANGE &= 0xffffc000;
  AGC->GAINRANGE |= 0x383e;
  AGC->GAININDEX &= 0xfff00000;
  AGC->GAININDEX |= 0x25bc;
  AGC->MININDEX &= 0xff000000;
  AGC->MININDEX |= 0x6d8480;
  AGC->MANGAIN &= 0xffffff40;
  AGC->MANGAIN |= 0xa7;
  BUS_RegMaskedSet(&AGC->CTRL0,0x400000);
  MODEM->MODINDEX = 0;
  MODEM->CTRL0 &= 0xfffffe3f;
  MODEM->CTRL0 |= 0x100;
  FRC->DFLCTRL &= 0xfffffff8;
  FRC->DFLCTRL |= 5;
  BUS_RegMaskedClear(&RAC->SGRFENCTRL0,0x80000);
  RAC->SGPACTRL0 &= 0x3fffffff;
  RAC->SGPACTRL0 |= 0x40000000;
  BUS_RegMaskedClear(&RAC->SGPAPKDCTRL,0xc000);
  BUS_RegMaskedSet(&RAC->SGPAPKDCTRL,0xc000);
  RAC->SGPABIASCTRL0 &= 0xff3ff332;
  RAC->SGPABIASCTRL0 |= 0x445;
  RAC->SGPABIASCTRL1 &= 0xffffffc8;
  RAC->SGPABIASCTRL1 |= 0x20;
  RAC->SGPABIASCTRL1 &= 0xfff388ff;
  RAC->SGPABIASCTRL1 |= 0x84500;
  BUS_RegMaskedClear(&RAC->PACTUNECTRL,0x1f0);
  BUS_RegMaskedSet(&RAC->SGPACTRL0,8);
  BUS_RegMaskedSet(&RAC->SGRFENCTRL0,0x10000);
  PHY_UTILS_DelayUs(0x14);
  RAC->SGPACTRL0 &= 0xffffc03;
  RAC->SGPACTRL0 |= 0x40;
  BUS_RegMaskedSet(&RAC->SGRFENCTRL0,0x20000);
  PHY_UTILS_DelayUs(0x14);
  RAC->SGPACTRL0 &= 0xe0c03fff;
  RAC->SGPACTRL0 |= 0x1004000;
  PHY_UTILS_DelayUs(0x14);
  BUS_RegMaskedSet(&RAC->SGRFENCTRL0,0x40000);
  PHY_UTILS_DelayUs(0x14);
  BUS_RegMaskedSet(&RAC->TESTCTRL,9);
  PHY_UTILS_DelayUs(0x14);
  RAC->SGPACTRL0 &= 0xe0c03fff;
  RAC->SGPACTRL0 |= 0x1004000;
  PHY_UTILS_DelayUs(0x14);
  MODEM->RAMPCTRL &= 0x7fffff;
  MODEM->RAMPCTRL |= 0x800000 | (uint32_t)rcIrCalData[2] << 0x18;
  PHY_UTILS_DelayUs(0x14);
}



uint32_t IRCAL_Setup(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined uVar1;
  int iVar2;
  
  IRCAL_SaveRegStates();
  uVar1 = rcIrCalData[3];
  if (((param_1 == 2) || (uVar1 = rcIrCalData[4], param_1 == 3)) && (iVar2 = AUXPLL_Start(param_1,uVar1,rcIrCalData[0],rcIrCalData[1],param_4), iVar2 != -1)) 
  {
    IRCAL_StopRx();
    iVar2 = IRCAL_SetRxFrequency(iVar2);
    if (iVar2 != -1) 
	{
      IRCAL_StartRx();
      if (param_1 == 2) IRCAL_SetSubGhzPllLoopback();
      else 
	  {
        if (param_1 != 3) return 0xffffffff;
        IRCAL_SetSubGhzPaLoopback();
      }
      return 0;
    }
  }
  return 0xffffffff;
}



uint32_t IRCAL_TranslateToRssiIndex(uint32_t param_1)

{
  if (param_1 < 0x40) param_1 = 0x40 - param_1 & 0xff;
  return param_1;
}



int32_t IRCAL_ReadRssi(uint param_1,uint param_2,uint param_3,undefined4 param_4,undefined2 param_5)

{
  uint uVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  if ((param_1 & 0x80) != 0) param_1 = 0x7f;
  if ((param_2 & 0x80) != 0) param_2 = 0x7f;
  if (param_3 < 0xf) 
  {
	RAC->IFPGACAL &= ~(RAC_IFPGACAL_IRPHASE_Msk | RAC_IFPGACAL_IRAMP_Msk); //0xffff8080;
	RAC->IFPGACAL |= param_1 << RAC_IFPGACAL_IRPHASE_Pos | param_2;
    PHY_UTILS_DelayUs(param_4);
    if (rcIrCalData[9] == '\0') AGC->IFC = AGC_IFC_RSSIDONE_Msk;
    uVar5 = 0;
    uVar4 = 0;
    for (uVar6 = 0; uVar6 >> (param_3 & 0xff) == 0; uVar6 = uVar6 + 1) 
	{
      PHY_UTILS_DelayUs(param_5);
      if (rcIrCalData[9] == '\0') 
	  {
        AGC->CMD = AGC_CMD_RSSISTART_Msk;
		while (!(AGC->IF & AGC_IF_RSSIDONE_Msk));
      }
      if (rcIrCalData[11] <= uVar6) 
	  {
        uVar5 = uVar5 + 1;
        uVar4 = uVar4 + RADIO_GetRSSI();
      }
      if (rcIrCalData[9] == '\0') AGC->IFC = AGC_IFC_RSSIDONE_Msk;
    }
    if (uVar5 == 0) uVar5 = 1;
    sVar2 = (int16_t)(uVar4 / uVar5);
  }
  else sVar2 = -1;
  return (int32_t)sVar2;
}



uint32_t IRCAL_SearchLinear2Stage(uint param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined2 param_5)

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
  do 
  {
    uVar3 = 0x40 - uVar6 & 0xff;
    do 
	{
      uVar7 = param_1;
      if (param_2 != 0) 
	  {
        uVar7 = uVar3;
        uVar3 = param_1;
      }
      sVar1 = IRCAL_ReadRssi(uVar7,uVar3,param_3,param_4,param_5);
      uVar3 = uVar6 + 10 & 0xff;
      if (sVar1 < sVar5) 
	  {
        uVar8 = uVar6;
        sVar5 = sVar1;
      }
      if (uVar3 == 0x87) 
	  {
        uVar3 = uVar8 - 5;
        uVar7 = 0x45 - uVar8;
        uVar6 = 0;
        sVar5 = 0x7fff;
        while( true ) 
		{
          uVar3 = uVar3 & 0xff;
          if ((uVar8 + 5 < uVar3) || ((int)(uVar3 << 0x18) < 0)) break;
          if (uVar3 != 0) 
		  {
            uVar4 = uVar3;
            if (uVar3 < 0x40) uVar4 = uVar7 & 0xff;
            uVar2 = param_1;
            if (param_2 != 0) 
			{
              uVar2 = uVar4;
              uVar4 = param_1;
            }
            sVar1 = IRCAL_ReadRssi(uVar2,uVar4,param_3,param_4,param_5);
            if (sVar1 < sVar5) 
			{
              uVar6 = uVar3;
              sVar5 = sVar1;
            }
          }
          uVar3 = uVar3 + 1;
          uVar7 = (uVar7 & 0xff) - 1;
        }
        if (uVar6 < 0x40) uVar6 = 0x40 - uVar6 & 0xff;
        return uVar6;
      }
      uVar6 = uVar3;
    } while (0x3f < uVar3);
  } while( true );
}



uint32_t IRCAL_Search(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  if (param_1 == 2) 
  {
    uVar1 = IRCAL_SearchLinear2Stage(0,1,param_2,param_3,param_4,param_2,param_3);
    uVar2 = IRCAL_SearchLinear2Stage(uVar1,0,param_2,param_3,param_4);
    iVar3 = IRCAL_SearchLinear2Stage(uVar2,1,param_2,param_3,param_4);
    uVar2 = uVar2 | iVar3 << 8;
  }
  else uVar2 = 0xffffffff;
  return uVar2;
}



void IRCAL_Teardown(void)

{
  undefined4 in_r3;
  
  IRCAL_StopRx();
  AUXPLL_Stop();
  RAC->SGRFENCTRL0 = regbuf[0];
  RAC->RFENCTRL0 = regbuf[1];
  AGC->CTRL0 = regbuf[2];
  AGC->MANGAIN = regbuf[3];
  AGC->GAINRANGE = regbuf[4];
  AGC->GAININDEX = regbuf[5];
  AGC->MININDEX = regbuf[6];
  MODEM->MODINDEX = regbuf[7];
  MODEM->CTRL0 = regbuf[8];
  FRC->DFLCTRL = regbuf[9];
  RAC->SGPACTRL0 = regbuf[10];
  RAC->SGPAPKDCTRL = regbuf[11];
  RAC->SGPABIASCTRL0 = regbuf[12];
  RAC->SGPABIASCTRL1 = regbuf[13];
  RAC->PACTUNECTRL = regbuf[14];
  MODEM->RAMPCTRL = regbuf[15];
  RAC->TESTCTRL = regbuf[16];
  AGC->CTRL1 = regbuf[17];
  MODEM->AFC = regbuf[18];
  SYNTH_Config(regbuf[19],regbuf[20]);
  BUFC_RxBufferReset();
  BUS_RegMaskedClear(&FRC->CTRL,FRC_CTRL_RANDOMTX_Msk);
  BUS_RegMaskedClear(&RAC->CTRL,RAC_CTRL_TXPOSTPONE_Msk);
}



uint32_t IRCAL_Get(void)

{
  return RAC->IFPGACAL & 0xffff;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

uint32_t IRCAL_GetDiValue(void)

{
  uint uVar2;
  
  if (SYNTH_RfFreqGet() == 0) uVar2 = 0xffffffff;
  else 
  {
    uVar2 = _DAT_0fe081c8;
    if ((999999999 < SYNTH_RfFreqGet()) && (uVar2 = _DAT_0fe081c4,(MODEM->CTRL0 & MODEM_CTRL0_MODFORMAT_Msk) >> MODEM_CTRL0_MODFORMAT_Pos != 4)) uVar2 = _DAT_0fe081c0;
    if (uVar2 != 0xffffffff) return uVar2 & 0xffff;
  }
  return uVar2;
}



int32_t IRCAL_PerformSubfunction(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined2 param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  longlong lVar5;
  longlong lVar6;
  undefined8 uVar7;
  
  lVar5 = PROTIMER_PrecntOverflowToUs(PROTIMER->WRAPCNT,0);
  if (param_1 == 1) 
  {
    uVar2 = IRCAL_GetDiValue();
    BUFC_RxBufferReset();
  }
  else 
  {
    if ((param_1 == 0) || (3 < param_1)) uVar2 = 0xffffffff;
    else 
	{
      if (IRCAL_Setup(param_1) != 0xffffffff) uVar2 = IRCAL_Search(param_2,param_3,param_4,param_5);
      IRCAL_Teardown();
    }
  }
  lVar6 = PROTIMER_PrecntOverflowToUs(PROTIMER->WRAPCNT);
  uVar7 = __aeabi_uldivmod((int)(lVar6 - lVar5),(int)((ulonglong)(lVar6 - lVar5) >> 0x20),1000,0);
  iVar1 = (int)((ulonglong)uVar7 >> 0x20);
  bVar4 = iVar1 == 0;
  if (iVar1 == 0) bVar4 = (uint)uVar7 < 0xffff;
  if (bVar4) uVar3 = (uint)uVar7 & 0xfffe;
  else uVar3 = 0;
  if (uVar2 != 0xffffffff) 
  {
    IRCAL_Set(uVar2);
    uVar2 = uVar2 | uVar3 << 0x10;
  }
  return uVar2;
}



int32_t IRCAL_Perform(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  if (IRCAL_GetGlobalCalType() == 0xff) return -1;
  else return IRCAL_PerformSubfunction(iVar1,2,rcIrCalData[10],rcIrCalData._12_2_,rcIrCalData._14_2_,param_2,param_3);
}


