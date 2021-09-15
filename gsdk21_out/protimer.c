#include "protimer.h"


void PROTIMER_Init(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  longlong lVar5;
  undefined8 uVar6;
  
  RADIOCMU_ClockEnable(0x60400,1);
  PROTIMER->CTRL = (1 << PROTIMER_CTRL_WRAPCNTSRC_Pos) | (1 << PROTIMER_CTRL_BASECNTSRC_Pos) | (1 << PROTIMER_CTRL_PRECNTSRC_Pos); //0x11100;

  uVar1 = RADIOCMU_ClockFreqGet(0x60400) / 1000;
  uVar2 = (uint)((ulonglong)uVar1 * 2000);
  uVar4 = uVar2 * 0x100;
  lVar5 = __aeabi_uldivmod(uVar4 + 500000,((int)((ulonglong)uVar1 * 2000 >> 0x20) << 8 | uVar2 >> 0x18) + (uint)(0xfff85edf < uVar4),1000000,0);
  uVar2 = (uint)lVar5;
  PROTIMER->PRECNTTOP = uVar2 - 0x100;
  uVar6 = __aeabi_uldivmod(500,uVar1,1000,0);
  if (lVar5 == 0) 
  {
    RAILInt_Assert(0,0x2b);
    uVar2 = 1;
  }
  uVar4 = (uint)uVar6 * 0x100;
  _usRatioFrac = __aeabi_uldivmod(uVar4 + (uVar2 >> 1),((int)((ulonglong)uVar6 >> 0x20) << 8 | (uint)uVar6 >> 0x18) + (uint)CARRY4(uVar4,uVar2 >> 1),uVar2,0);
  iVar3 = (int)_usRatioFrac;
  if (uVar1 == 0) 
  {
    RAILInt_Assert(0,0x2b);
    uVar1 = 1;
  }
  lVar5 = (ulonglong)(uVar2 << 0x18) * 1000;
  uVar4 = (uint)lVar5;
  uVar6 = __aeabi_uldivmod(uVar4 + (uVar1 >> 1),(uVar2 >> 8) * 1000 + (int)((ulonglong)lVar5 >> 0x20) + (uint)CARRY4(uVar4,uVar1 >> 1),uVar1,0);
  PROTIMER->WRAPCNTTOP = iVar3 - 1;
  precntRatioFrac = (int)uVar6;
  precntRatioInt = (int)((ulonglong)uVar6 >> 0x20);
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void PROTIMER_Start(void)

{
  PROTIMER->CMD = PROTIMER_CMD_START_Msk;
  _DAT_e000e100 = 0x10000000;
  _DAT_e000e280 = 0x10000000;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void PROTIMER_Stop(void)

{
  PROTIMER->CMD = PROTIMER_CMD_STOP_Msk;
  _DAT_e000e180 = 0x10000000; //PROTIMER_IRQn
  _DAT_e000e280 = 0x10000000;
}



uint PROTIMER_IsRunning(void)

{
  return PROTIMER->STATUS & PROTIMER_STATUS_RUNNING_Msk;
}



void PROTIMER_Reset(void)

{
  PROTIMER->PRECNT = 0;
  PROTIMER->BASECNT = 0;
  PROTIMER->WRAPCNT = 0;
}



int PROTIMER_ElapsedTime(uint param_1,uint param_2)

{
  int iVar2;
  
  iVar2 = param_2 - param_1;
  if (param_2 < param_1) iVar2 = iVar2 + PROTIMER->WRAPCNTTOP + 1;
  return iVar2;
}



void PROTIMER_TOUTTimerStop(int param_1)

{
  if (param_1 == 0) PROTIMER->CMD = PROTIMER_CMD_TOUT0STOP_Msk;
  else PROTIMER->CMD = PROTIMER_CMD_TOUT1STOP_Msk;
}



void PROTIMER_TOUTTimerStart(uint param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  RAILInt_Assert(param_1 < 0x100,0x15,param_3,param_4,param_4);
  if (param_2 == 0) 
  {
    PROTIMER->TOUT0CNTTOP = param_1 << 8;
    PROTIMER->IFC = PROTIMER_IFC_TOUT0MATCH_Msk | PROTIMER_IFC_TOUT0_Msk; //0x50;
    PROTIMER->CMD = PROTIMER_CMD_TOUT0START_Msk; //0x10;
  }
  else 
  {
    PROTIMER->TOUT1CNTTOP = param_1 << 8;
    PROTIMER->IFC = PROTIMER_IFC_TOUT1MATCH_Msk | PROTIMER_IFC_TOUT1_Msk; //0xa0;
    PROTIMER->CMD = PROTIMER_CMD_TOUT1START_Msk; //0x40;
  }
}



uint32_t PROTIMER_TOUTTimerGet(int param_1)

{
  if (param_1 == 0) return (PROTIMER->TOUT0CNT << 8) >> 0x10;
  else return (PROTIMER->TOUT1CNT << 8) >> 0x10;
}



void PROTIMER_CCTimerStop(uint param_1)

{
  (&PPROTIMER_CLR.CC0_CTRL)[param_1 * 4] = 1; //!!!
  PROTIMER->IFC = 0x100 << (param_1 & 0xff);
}



undefined4 PROTIMER_CCTimerStart(uint param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  uint *puVar8;
  RAC *pRVar9;
  uint uVar10;
  bool bVar11;
  int iVar12;
  CORE_irqState_t irqState;
  
  uVar6 = param_1;
  iVar12 = param_3;
  irqState = CORE_EnterCritical();
  PROTIMER_CCTimerStop(param_1);
  if (param_3 != 2) 
  {
    uVar5 = PROTIMER->WRAPCNT;
    uVar4 = PROTIMER->WRAPCNTTOP;
    if (param_3 == 1) param_2 = param_2 + uVar5 + 1;
    uVar10 = uVar4 + 1;
    uVar4 = (uint)(0xfffffffe < uVar4);
    while( true ) 
	{
      bVar11 = uVar4 == 0;
      if (uVar4 == 0) bVar11 = uVar10 <= param_2;
      if (!bVar11) break;
      param_2 = param_2 - uVar10;
    }
    uVar3 = PROTIMER_ElapsedTime(param_2,uVar5);
    if (uVar3 <= (uVar10 >> 2 | uVar4 << 0x1e)) 
	{
LAB_00010258:
      CORE_ExitCritical(irqState);
      return 0;
    }
    uVar10 = PROTIMER->TXCTRL;
    uVar4 = PROTIMER->RXCTRL;
    uVar3 = (param_1 + 9) * 0x100 | 1;
    if ((uVar10 & 0x1f1f) == uVar3) uVar10 = 4;
    else uVar10 = 0;
    uVar1 = PROTIMER->RXCTRL;
    if ((uVar4 & 0x1f1f0000) == ((param_1 + 9) * 0x1000000 | 0x10000)) uVar10 = uVar10 | 2;
    if ((uVar1 & 0x1f1f) == uVar3) uVar10 = uVar10 | 1;
    puVar7 = (uint *)(uVar10 & 1);
    puVar8 = puVar7;
    if (puVar7 != NULL) puVar8 = &PROTIMER_scheduledRxEnable;
    if (puVar7 != NULL) *puVar8 = param_2;
    (&PROTIMER->CC0_WRAP)[param_1 * 4] = param_2;
    (&PROTIMER->CC0_CTRL)[param_1 * 4] = 0x11;
    uVar4 = PROTIMER->WRAPCNT;
    uVar4 = PROTIMER_ElapsedTime(uVar5,uVar4,0x11,param_1 * 0x10 + 0x40085070,uVar6,puVar7,iVar12);
    uVar5 = PROTIMER_ElapsedTime(uVar5,param_2);
    uVar6 = PROTIMER->IF;
    if ((uVar5 <= uVar4) && (uVar5 = 0x100 << (param_1 & 0xff), (uVar5 & uVar6) == 0)) 
	{
      if (param_3 == 0) 
	  {
        PROTIMER_CCTimerStop(param_1);
        goto LAB_00010258;
      }
      PROTIMER->IFS = uVar5;
      if (puVar7 != NULL) {
        BUS_RegMaskedClear(&PROTIMER->RXCTRL,0x1f1f);
        BUS_RegMaskedSet(&PROTIMER->RXCTRL,0x101);
        BUS_RegMaskedClear(&PROTIMER->RXCTRL,0x1f1f);
      }
      uVar6 = uVar10 << 0x1e;
      if ((int)uVar6 < 0) 
	  {
        uVar6 = 0x1f1f0000;
        BUS_RegMaskedClear(&PROTIMER->RXCTRL,0x1f1f0000);
        BUS_RegMaskedSet(&PROTIMER->RXCTRL,0x1010000);
        BUS_RegMaskedClear(&PROTIMER->RXCTRL,0x1f1f0000);
      }
      pRVar9 = (RAC *)(uVar10 << 0x1d);
      bVar11 = (int)pRVar9 < 0;
      if (bVar11) 
	  {
        pRVar9 = &Peripherals::RAC;
        uVar6 = 1;
      }
      if (bVar11) 
	  {
        pRVar9->CMD = uVar6;
      }
    }
  }
  CORE_ExitCritical(irqState);
  return 1;
}



void PROTIMER_WrapMultiple(uint param_1,undefined4 param_2,uint param_3,int param_4)

{
  bool bVar1;
  
  while( true ) 
  {
    bVar1 = param_4 == 0;
    if (param_4 == 0) bVar1 = param_3 <= param_1;
    if (!bVar1) break;
    param_1 = param_1 - param_3;
  }
  return;
}



uint PROTIMER_CCTimerIsEnabled(int param_1)

{
  return (&PROTIMER->CC0_CTRL)[param_1 * 4] & 1;
}



void PROTIMER_CCTimerCapture(int param_1,uint param_2)

{
  (&PROTIMER->CC0_CTRL)[param_1 * 4] = param_2 & 0xe00000 | 3;
  return;
}



void PROTIMER_ScheduleTxEnable(int param_1,undefined4 param_2,undefined4 param_3)

{
  PROTIMER_CCTimerStop();
  PROTIMER->TXCTRL = (param_1 + 9) * 0x100 | 1;
  PROTIMER_CCTimerStart(param_1,param_2,param_3);
  return;
}



void PROTIMER_ClearTxEnable(void)

{
  PROTIMER->TXCTRL = 0;
}



void PROTIMER_ScheduleRxEnable(int param_1,undefined4 param_2,undefined4 param_3)

{
  PROTIMER_CCTimerStop();
  PROTIMER->RXCTRL = (param_1 + 9) * 0x100 | 0x10001;
  PROTIMER_CCTimerStart(param_1,param_2,param_3);
}



void PROTIMER_ScheduleRxDisable(int param_1,undefined4 param_2,undefined4 param_3)

{
  PROTIMER_CCTimerStop();
  PROTIMER->RXCTRL &= 0xe0e0ffff;
  PROTIMER->RXCTRL |= 0x10000 | (param_1 + 9) * 0x1000000;;
  PROTIMER_CCTimerStart(param_1,param_2,param_3);
}



void PROTIMER_ClearRxEnable(void)

{
  PROTIMER->RXCTRL = 0x1010000;
}



uint PROTIMER_GetTime(void)

{
  return PROTIMER->WRAPCNT;
}



uint PROTIMER_GetCCTime(int param_1)

{
  return (&PROTIMER->CC0_WRAP)[param_1 * 4];
}



void PROTIMER_LBTUseLastConfig(void)

{
  if (PROTIMER->TOUT0COMP == 0) BUS_RegMaskedSet(&RAC->RXENSRCEN,0x10);
  PROTIMER->RXCTRL = 0x18011b01;
  PROTIMER->TXCTRL = 0x1401;
}



void PROTIMER_LBTStart(void)

{
  PTI_AuxdataOutput(0x21);
  PROTIMER->CMD = 0x10000;
}



void PROTIMER_LBTPause(void)

{
  PTI_AuxdataOutput(0x23);
  PROTIMER->CMD = 0x20000;
}



void PROTIMER_LBTStop(void)

{
  PTI_AuxdataOutput(0x22);
  PROTIMER->CMD = 0x40000;
}



uint PROTIMER_LBTStateGet(void)

{
  PTI_AuxdataOutput(0x24);
  return PROTIMER->LBTSTATE;
}



void PROTIMER_LBTStateSet(uint param_1)

{
  PTI_AuxdataOutput(0x25);
  PROTIMER->LBTSTATE = param_1;
}



bool PROTIMER_LBTIsActive(void)

{
  return (PROTIMER->STATUS & 6) != 0;
}



undefined8 PROTIMER_PrecntOverflowToUs(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = precntRatioFrac * param_2 + (int)((ulonglong)param_1 * (ulonglong)precntRatioFrac >> 0x20) + (uint)(0x7fffffff < (uint)((ulonglong)param_1 * (ulonglong)precntRatioFrac));
  uVar1 = (uint)((ulonglong)param_1 * (ulonglong)precntRatioInt);
  return CONCAT44(precntRatioInt * param_2 + (int)((ulonglong)param_1 * (ulonglong)precntRatioInt >> 0x20) + (uint)CARRY4(uVar1,uVar2),uVar1 + uVar2);
}



longlong PROTIMER_UsToPrecntOverflow(uint param_1)

{
  return (ulonglong)usRatioInt * (ulonglong)param_1 + ((ulonglong)usRatioFrac * (ulonglong)param_1 + 0x80000000 >> 0x20);
}



undefined4 PROTIMER_SetTime(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = PROTIMER_IsRunning();
  if (PROTIMER_IsRunning() != 0) 
  {
    PROTIMER_Stop();
    iVar1 = 1;
  }
  PROTIMER_Reset();
  PROTIMER->WRAPCNT = PROTIMER_UsToPrecntOverflow(param_1);
  if (iVar1 != 0) PROTIMER_Start();
  return 1;
}



void PROTIMER_LBTCfgSet(int param_1,uint param_2,int param_3,uint param_4,byte param_5,byte param_6)

{
  uint uVar1;
  uint uVar2;
  
  PROTIMER->CTRL = uVar1 & 0xff0fffff | 0x900000;
  PROTIMER->CTRL &= 0xff0fffff;
  PROTIMER->CTRL |= 0x900000;
  if (param_4 == 0) 
  {
    PROTIMER->RXCTRL = 0;
    param_2 = param_4;
  }
  param_2 = (uint)param_6 << 8 | (uint)param_5 << 0x18 | param_3 << 4 | param_4 << 0x10 | param_2;
  PROTIMER->LBTCTRL = param_2;
  uVar1 = PROTIMER->BASECNTTOP;
  RAILInt_Assert(uVar1 < 0x100,0x18,param_2,param_5,param_4);
  PROTIMER->TOUT0CNTTOP = uVar1;
  if (param_4 != 0) 
  {
    uVar2 = PROTIMER_UsToPrecntOverflow(*(undefined2 *)(param_1 + 0x10));
    if (uVar1 < uVar2) 
	{
      BUS_RegMaskedSet(&RAC->RXENSRCEN,0x10);
      PROTIMER->TOUT0COMP = 0;
    }
    else PROTIMER->TOUT0COMP = uVar2;
    PROTIMER->RXCTRL = 0x18011b01;
  }
  PROTIMER->TXCTRL = 0x1401;
}



void PROTIMER_DelayUs(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar3 = PROTIMER_UsToPrecntOverflow();
  uVar6 = PROTIMER->WRAPCNT;
  uVar2 = PROTIMER->WRAPCNTTOP;
  if (PROTIMER_IsRunning() != 0) 
  {
    while( true ) 
	{
      uVar7 = uVar3;
      if (uVar2 >> 1 <= uVar3) uVar7 = uVar2 >> 1;
	  while (PROTIMER_ElapsedTime(uVar6,PROTIMER->WRAPCNT) < uVar7);
      if (uVar3 <= uVar5) break;
      uVar3 = uVar3 - uVar5;
      uVar6 = uVar1;
    }
  }
}



uint PROTIMER_CheckCcaReallyFailed(uint param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar3 = CORE_EnterAtomic();
  if ((param_1 & 0x600000) != 0) 
  {
    uVar5 = AGC->RSSI;
    uVar5 = AGC->RSSI << 0x10;
    uVar6 = uVar5 >> 0x16;
    uVar1 = RAC->STATUS;
    uVar2 = AGC->CTRL1;
    if ((int)uVar5 < 0) uVar6 = ~(uVar5 & 0xffc00000);
    uVar4 = uVar2 & 0xff;
    if ((int)uVar5 < 0) uVar6 = ~(uVar6 >> 0x16);
    if ((int)(uVar2 << 0x18) < 0) uVar4 = uVar4 | 0xffffff00;
    uVar5 = PROTIMER->IF;
    if ((((((int)(uVar4 + 0x46) < 0 == SCARRY4(uVar4,0x46)) && (uVar6 != 0xfffffe00)) &&  (uVar6 == uVar4 * 4 || (int)(uVar6 + uVar4 * -4) < 0 != SBORROW4(uVar6,uVar4 * 4))) && (((uVar1 & 0xf000000) == 0x4000000 || ((uVar1 & 0xd000000) == 0)))) &&  (-1 < (int)(uVar5 << 0xb))) 
	{
      PROTIMER_LBTStop();
      if (-1 < (int)(PROTIMER->IF << 0xb)) 
	  {
        RAC->CMD = 1;
        uVar1 = PROTIMER->RXCTRL;
        PROTIMER->RXCTRL = 0x1010000;
        PROTIMER->RXCTRL = uVar1;
        PROTIMER->IFC = 0x700000;
        if (((int)(param_1 << 10) < 0) && (uVar1 = (PROTIMER->LBTSTATE), (uVar1 & 0xf000000) != 0)) PROTIMER->LBTSTATE = PROTIMER->LBTSTATE - 0x1000000;
        param_1 = param_1 & 0xff9fffff | 0x100000;
        PTI_AuxdataOutput(0x2c);
      }
    }
  }
  CORE_ExitAtomic(uVar3);
  return param_1;
}


