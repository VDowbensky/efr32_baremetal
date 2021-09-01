#include "protimer.h"

usRatioInt;
usRatioFrac;
uint16_t precntRatioInt;
uint8_t precntRatioFrac;
float ratio;

void PROTIMER_Init(void)

{
  float ratio;
  
  RADIOCMU_ClockEnable(0x60400);
  PROTIMER->CTRL = 0x11100;

  ratio = 2*((float)RADIOCMU_ClockFreqGet(0x60400))/1000000;
  
  precntRatioInt = (uint16_t)(ratio) - 1;
  precntRatioFrac = (uint8_t)((ratio - precntRatioInt - 1) * 256) - 1;
  PROTIMER->PRECNTTOP = precntRatioInt << 8;
  PROTIMER->PRECNTTOP |= precntRatioFrac;
  PROTIMER->WRAPCNTTOP = PROTIMER_UsToPrecntOverflow(0xffffffff) - 1;
}


void PROTIMER_Start(void)

{
  BUS_RegMaskedSet(&PROTIMER->CMD, PROTIMER_CMD_START_Msk);
  NVIC_EnableIRQ(PROTIMER_IRQn);
  NVIC_ClearPendingIRQ(PROTIMER_IRQn);
}


void PROTIMER_Stop(void)

{
  BUS_RegMaskedSet(&PROTIMER->CMD, PROTIMER_CMD_STOP_Msk);
  NVIC_DisableIRQ(PROTIMER_IRQn);
  NVIC_ClearPendingIRQ(PROTIMER_IRQn);
}



bool PROTIMER_IsRunning(void)

{
  return PROTIMER->STATUS & 1;
}



void PROTIMER_Reset(void)

{
  PROTIMER->PRECNT = 0;
  PROTIMER->BASECNT = 0;
  PROTIMER->WRAPCNT = 0;
}



uint32_t PROTIMER_ElapsedTime(uint32_t time,uint32_t cnt)

{
  uint32_t delta;
  delta = cnt - time;
  if (cnt < time) delta = delta + PROTIMER->WRAPCNTTOP + 1;
  return delta;
}

void PROTIMER_TOUTTimerStop(uint8_t tout)

{
	if (tout == 0) BUS_RegMaskedSet(&PROTIMER->CMD, PROTIMER_CMD_TOUT0STOP_Msk);
	else BUS_RegMaskedSet(&PROTIMER->CMD, PROTIMER_CMD_TOUT1STOP_Msk);
}


void PROTIMER_TOUTTimerStart(uint32_t time,uint8_t tout)

{
  if (tout == 0)
  {
	PROTIMER->TOUT0CNTTOP = time << 8;
	PROTIMER->IFC = PROTIMER_IF_TOUT0MATCH_Msk | PROTIMER_IF_TOUT0_Msk;
			BUS_RegMaskedSet(&PROTIMER->CMD, PROTIMER_CMD_TOUT0START_Msk);
  }
  else
  {
	PROTIMER->TOUT1CNTTOP = time << 8;
	PROTIMER->IFC = PROTIMER_IF_TOUT1MATCH_Msk | PROTIMER_IF_TOUT1_Msk;
	BUS_RegMaskedSet(&PROTIMER->CMD, PROTIMER_CMD_TOUT1START_Msk);
  }
}




uint32_t PROTIMER_TOUTTimerGet(uint8_t tout)

{
  if (tout == 0) return (PROTIMER->TOUT0CNT << 8) >> 0x10;
  else return (PROTIMER->TOUT1CNT << 8) >> 0x10;
  //if (tout == 0) return (PROTIMER->TOUT0CNT << 0x10) >> 0x18;
  //else return (PROTIMER->TOUT1CNT << 0x10) >> 0x18;
}



void PROTIMER_CCTimerStop(uint8_t channel)

{
  (&PROTIMER_CLR->CC0_CTRL)[(uint)channel * 4] = 1;
  PROTIMER->IFC = 0x100 << (uint)channel;
}



bool PROTIMER_CCTimerStart(uint8_t param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint32_t uVar5;
  int iVar6;
  bool bVar7;
  
  uVar4 = CORE_EnterCritical();
  PROTIMER_CCTimerStop((uint8_t)param_1);
  uVar1 = PROTIMER->WRAPCNT;
  if (param_3 == 1) param_2 = param_2 + PROTIMER->WRAPCNT + 1;
  else 
  {
    if (param_3 == 2) return true;
  }
  uVar1 = read_volatile_4(PROTIMER->WRAPCNTTOP);
  if (PROTIMER->WRAPCNTTOP < param_2) param_2 = (param_2 - PROTIMER->WRAPCNTTOP) - 1;
  iVar6 = 0;
  while( true ) 
  {
    (&PROTIMER->CC0_WRAP)[param_1 * 4] = param_2;
    (&PROTIMER->CC0_CTRL)[param_1 * 4] = 0x11;
    uVar5 = PROTIMER_ElapsedTime(param_2,PROTIMER->WRAPCNT);
    if (uVar1 >> 2 < uVar5) bVar7 = false;
    else bVar7 = (0x100 << (param_1 & 0xff) & PROTIMER->IF) == 0;
    iVar6 = iVar6 + 1;
    param_2 = iVar6 + PROTIMER->WRAPCNT;
    if ((param_3 != 1) || (iVar6 == 6)) break;
    if (!bVar7) 
	{
      CORE_ExitCritical(uVar4);
      return true;
    }
  }
  if (bVar7) 
  {
    PROTIMER_CCTimerStop((uint8_t)param_1);
    CORE_ExitCritical(uVar4);
    return false;
  }
  CORE_ExitCritical(uVar4);
  return true;
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
}



bool PROTIMER_CCTimerIsEnabled(uint8_t channel)

{
  return (bool)((byte)(&PROTIMER->CC0_CTRL)[(uint)channel * 4] & 1);
}



void PROTIMER_CCTimerCapture(uint8_t channel,uint param_2)

{
  (&PROTIMER->CC0_CTRL)[(uint)channel * 4] = param_2 & 0xe00000 | 3;
}



void PROTIMER_ClearTxEnable(void)

{
  PROTIMER->TXCTRL = 0;
}



bool PROTIMER_ScheduleRxDisable(uint param_1,uint param_2,int param_3)

{
  PROTIMER_CCTimerStop((uint8_t)param_1);
  PROTIMER->RXCTRL & 0xe0e0ffff;
  PROTIMER->RXCTRL |= 0x10000 | (param_1 + 9) * 0x1000000;
  return PROTIMER_CCTimerStart(param_1,param_2,param_3);
}



void PROTIMER_ClearRxEnable(void)

{
  PROTIMER->RXCTRL = 0x1010000;
}



uint32_t PROTIMER_GetTime(void)

{
  return PROTIMER->WRAPCNT;
}



uint32_t PROTIMER_GetCCTime(uint32_t ch)

{
  return (&PROTIMER->CC0_WRAP)[ch * 4];
}



void PROTIMER_LBTUseLastConfig(void)

{
  if (PROTIMER->TOUT0COMP == 0) BUS_RegMaskedSet(&RAC->RXENSRCEN, 0x10);
  PROTIMER->RXCTRL = 0x18011b01;
  PROTIMER->TXCTRL = 0x1401;
}



void PROTIMER_LBTStart(void)

{
  RADIO_PTI_AuxdataOutput(0x21);
  PROTIMER->CMD = 0x10000;
}



void PROTIMER_LBTPause(void)

{
  RADIO_PTI_AuxdataOutput(0x23);
  PROTIMER->CMD = 0x20000;
}



void PROTIMER_LBTStop(void)

{
  RADIO_PTI_AuxdataOutput(0x22);
  PROTIMER->CMD = 0x40000;
}



uint32_t PROTIMER_LBTStateGet(void)

{
  return PROTIMER->LBTSTATE;
}



void PROTIMER_LBTStateSet(uint32_t state)

{
  PROTIMER->LBTSTATE,state;
}



bool PROTIMER_LBTIsActive(void)

{
  return (PROTIMER->STATUS & 6) != 0;
}



uint32_t PROTIMER_PrecntOverflowToUs(uint32_t param_1)

{
//  uint uVar1;
//  uint uVar2;
  
//  uVar2 = precntRatioFrac * param_2 + (int)((ulonglong)param_1 * (ulonglong)precntRatioFrac >> 0x20)
//          + (uint)(0x7fffffff < (uint)((ulonglong)param_1 * (ulonglong)precntRatioFrac));
//  uVar1 = (uint)((ulonglong)param_1 * (ulonglong)precntRatioInt);
//  return CONCAT44(precntRatioInt * param_2 +
//                  (int)((ulonglong)param_1 * (ulonglong)precntRatioInt >> 0x20) +
//                  (uint)CARRY4(uVar1,uVar2),uVar1 + uVar2);
				  
	return (uint32_t)(2*cnt/ratio);
}



uint32_t PROTIMER_UsToPrecntOverflow(uint32_t us)

{
  //return (uint64_t)((uint64_t)usRatioInt * us + ((uint64_t)usRatioFrac * us + 0x80000000 >> 0x20));
  return (uint32_t)(us * ratio/2);
}



bool PROTIMER_ScheduleTxEnable(uint param_1,uint param_2,int param_3)

{
  uint32_t us;
  uint64_t uVar2;
  
  us = TIMING_TxWarmTimeGet();
  uVar2 = PROTIMER_UsToPrecntOverflow(us);
  PROTIMER_CCTimerStop((uint8_t)param_1);
  if ((param_3 == 1) && (param_2 < (uint)uVar2)) param_2 = 0;
  else param_2 = param_2 - (uint)uVar2;
  PROTIMER->TXCTRL = (param_1 + 9) * 0x100 | 1;
  return PROTIMER_CCTimerStart(param_1,param_2,param_3);
}



bool PROTIMER_ScheduleRxEnable(uint param_1,uint param_2,int param_3)

{
  uint32_t us;
  uint64_t uVar2;
  
  PROTIMER_CCTimerStop((uint8_t)param_1);
  us = TIMING_RxWarmTimeGet();
  uVar2 = PROTIMER_UsToPrecntOverflow(us);
  if ((param_3 == 1) && (param_2 < (uint)uVar2)) param_2 = 0;
  else param_2 = param_2 - (uint)uVar2;
  PROTIMER->RXCTRL = (param_1 + 9) * 0x100 | 0x10001;
  return PROTIMER_CCTimerStart(param_1,param_2,param_3);
}



bool PROTIMER_SetTime(uint32_t time)

{
  int iVar1;
  uint64_t uVar2;
  
  iVar1 = PROTIMER_IsRunning();
  if (iVar1 != 0) {
    PROTIMER_Stop();
    iVar1 = 1;
  }
  PROTIMER_Reset();
  uVar2 = PROTIMER_UsToPrecntOverflow(time);
  write_volatile_4(PROTIMER->WRAPCNT,(uint)uVar2);
  if (iVar1 != 0) {
    PROTIMER_Start((uint)uVar2,(int)(uVar2 >> 0x20));
  }
  return true;
}



void PROTIMER_LBTCfgSet(uint param_1,int param_2,uint param_3,int param_4,byte param_5)

{
  uint uVar1;
  uint32_t us;
  uint64_t uVar2;
  
  PROTIMER->CTRL &= 0xff0fffff;
  PROTIMER->CTRL |= 0x900000;
  if (param_3 == 0) 
  {
    PROTIMER->RXCTRL = 0;
    param_1 = param_3;
  }
  PROTIMER->LBTCTRL = (uint)param_5 << 8 | param_4 << 0x18 | param_2 << 4 | param_3 << 0x10 | param_1;
  uVar1 = PROTIMER->BASECNTTOP;
  PROTIMER->TOUT0CNTTOP = uVar1;
  if (param_3 != 0) 
  {
    us = TIMING_RxWarmTimeGet();
    uVar2 = PROTIMER_UsToPrecntOverflow(us);
    if (uVar1 < (uint)uVar2) 
	{
      BUS_RegMaskedSet(&RAC->.RXENSRCEN,0x10);
      PROTIMER->TOUT0COMP = 0;
    }
    else PROTIMER->TOUT0COMP = (uint)uVar2;
    PROTIMER->RXCTRL = 0x18011b01;
  }
  PROTIMER->TXCTRL = 0x1401;
}



void PROTIMER_DelayUs(uint32_t us)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint32_t uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint64_t uVar8;
  
  uVar8 = PROTIMER_UsToPrecntOverflow(us);
  uVar5 = (uint)uVar8;
  uVar6 = PROTIMER->WRAPCNT;
  uVar2 = PROTIMER->WRAPCNTTOP;
  iVar3 = PROTIMER_IsRunning(uVar5,(int)(uVar8 >> 0x20));
  if (PROTIMER_IsRunning() != 0) 
  {
    while( true ) 
	{
      uVar7 = uVar5;
      if (uVar2 >> 1 <= uVar5) uVar7 = uVar2 >> 1;
	  while (PROTIMER_ElapsedTime(uVar6,uVar1) < uVar7);
      if (uVar5 <= uVar4) break;
      uVar5 = uVar5 - uVar4;
      uVar6 = uVar1;
    }
  }
}


