#include "protimer.h"



void PROTIMER_Init(void)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  
  RADIOCMU_ClockEnable(0x60400,1);
  PROTIMER->CTRL = 0x11100;
  uVar2 = RADIOCMU_ClockFreqGet(0x60400);
  uVar2 = uVar2 / 1000;
  uVar3 = (uint)((ulonglong)uVar2 * 2000);
  uVar5 = uVar3 * 0x100;
  uVar6 = __aeabi_uldivmod(uVar5 + 500000,
                           ((int)((ulonglong)uVar2 * 2000 >> 0x20) << 8 | uVar3 >> 0x18) +
                           (uint)(0xfff85edf < uVar5),1000000,0);
  uVar3 = (uint)uVar6;
  PROTIMER->PRECNTTOP = uVar3 - 0x100;
  uVar7 = __aeabi_uldivmod(500,uVar2,1000,0);
  uVar5 = (uint)uVar7 * 0x100;
  _usRatioFrac = __aeabi_uldivmod((uVar3 >> 1) + uVar5,
                                  ((int)((ulonglong)uVar7 >> 0x20) << 8 | (uint)uVar7 >> 0x18) +
                                  (uint)CARRY4(uVar3 >> 1,uVar5),uVar3,
                                  (int)((ulonglong)uVar6 >> 0x20));
  iVar4 = (int)_usRatioFrac;
  lVar1 = (ulonglong)(uVar3 << 0x18) * 1000;
  uVar5 = (uint)lVar1;
  uVar6 = __aeabi_uldivmod(uVar5 + (uVar2 >> 1),
                           (uVar3 >> 8) * 1000 + (int)((ulonglong)lVar1 >> 0x20) +
                           (uint)CARRY4(uVar5,uVar2 >> 1),uVar2,0);
  PROTIMER->WRAPCNTTOP = iVar4 - 1;
  precntRatioFrac = (int)uVar6;
  precntRatioInt = (int)((ulonglong)uVar6 >> 0x20);
}



void PROTIMER_Start(void)

{
  PROTIMER->CMD = 1;
  _DAT_e000e100 = 0x10000000;
  _DAT_e000e280 = 0x10000000;
}



void PROTIMER_Stop(void)

{
  _DAT_e000e180 = 0x10000000;
  _DAT_e000e280 = 0x10000000;
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



uint32_t PROTIMER_ElapsedTime(uint32_t begin,uint32_t end)

{
  uint32_t uVar2;
  
  uVar2 = end - begin;
  if (end < begin) uVar2 = uVar2 + PROTIMER->WRAPCNTTOP + 1;
  return uVar2;
}



void PROTIMER_TOUTTimerStop(uint32_t timer)

{
  if (timer == 0) PROTIMER->CMD = 0x20;
  else PROTIMER->CMD = 0x80;
}



void PROTIMER_TOUTTimerStart(uint32_t timer)

{
  if (timer == 0) 
  {
    PROTIMER->TOUT0CNTTOP = timer << 8;
    PROTIMER->IFC = 0x50;
	PROTIMER->CMD = 0x10;
  }
  else 
  {
    PROTIMER->TOUT1CNTTOP = timer << 8;
    PROTIMER->IFC = 0xa0;
	PROTIMER->CMD = 0x40;
  }
}



uint32_t PROTIMER_TOUTTimerGet(uint32_t timer)

{
  if (timer == 0) return (PROTIMER->TOUT0CNT << 8) >> 0x10;
  else return (PROTIMER->TOUT1CNT << 8) >> 0x10;
}



void PROTIMER_CCTimerStop(uint32_t timer)

{
  (&Peripherals::PROTIMER_CLR.CC0_CTRL)[timer * 4] = 1;
  PROTIMER->IFC = 0x100 << (timer & 0xff);
}



bool PROTIMER_CCTimerStart(uint32_t timer,uint32_t time,RAIL_TimeMode_t mode)

{
  uint uVar1;
  uint end;
  uint uVar2;
  CORE_irqState_t irqState;
  uint32_t uVar3;
  int iVar4;
  bool bVar5;
  
  irqState = CORE_EnterCritical();
  PROTIMER_CCTimerStop(timer);
  uVar1 = (PROTIMER->WRAPCNT);
  if (mode == RAIL_TIME_DELAY) 
  {
    if (time == 0) time = 1;
    time = time + uVar1;
  }
  else 
  {
    if (mode == RAIL_TIME_DISABLED) return true;
  }
  uVar1 = (PROTIMER->WRAPCNTTOP);
  if (uVar1 < time) time = (time - uVar1) - 1;
  iVar4 = 1;
  while( true ) 
  {
    (&PROTIMER->CC0_WRAP)[timer * 4] = time;
    (&PROTIMER->CC0_CTRL)[timer * 4] = 0x11;
    end = (PROTIMER->WRAPCNT);
    uVar3 = PROTIMER_ElapsedTime(time,end);
    if (uVar1 >> 2 < uVar3) bVar5 = false;
    else 
	{
      uVar2 = (PROTIMER->IF);
      bVar5 = (0x100 << (timer & 0xff) & uVar2) == 0;
    }
    iVar4 = iVar4 + 1;
    time = iVar4 + end;
    if ((mode != RAIL_TIME_DELAY) || (iVar4 == 7)) break;
    if (!bVar5) 
	{
LAB_00010f96:
      CORE_ExitCritical(irqState);
      return true;
    }
  }
  if (bVar5) 
  {
    PROTIMER_CCTimerStop(timer);
    CORE_ExitCritical(irqState);
    return false;
  }
  goto LAB_00010f96;
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



bool PROTIMER_CCTimerIsEnabled(uint32_t timer)

{
  return (bool)((byte)(&PROTIMER->CC0_CTRL)[timer * 4] & 1);
}



void PROTIMER_CCTimerCapture(uint32_t timer,uint32_t value)

{
  (&PROTIMER->CC0_CTRL)[timer * 4] = value & 0xe00000 | 3;
}



bool PROTIMER_ScheduleTxEnable(uint32_t timer,uint32_t time,RAIL_TimeMode_t mode)

{
  PROTIMER_CCTimerStop();
  PROTIMER->TXCTRL = (timer + 9) * 0x100 | 1;
  return PROTIMER_CCTimerStart(timer,time,mode);
}



void PROTIMER_ClearTxEnable(void)

{
  PROTIMER->TXCTRL = 0;
}



bool PROTIMER_ScheduleRxEnable(uint32_t timer,uint32_t time,RAIL_TimeMode_t mode)

{
  PROTIMER_CCTimerStop();
  PROTIMER->RXCTRL = (timer + 9) * 0x100 | 0x10001;
  return PROTIMER_CCTimerStart(timer,time,mode);
}




bool PROTIMER_ScheduleRxDisable(uint32_t timer,uint32_t time,RAIL_TimeMode_t mode)

{
  PROTIMER->RXCTRL &= 0xe0e0ffff;
  PROTIMER->RXCTRL |= 0x10000 | (timer + 9) * 0x1000000;
  return PROTIMER_CCTimerStart(timer,time,mode);
}



void PROTIMER_ClearRxEnable(void)

{
  PROTIMER->RXCTRL = 0x1010000;
}


uint32_t PROTIMER_GetTime(void)

{
  return PROTIMER->WRAPCNT;
}



uint32_t PROTIMER_GetCCTime(uint32_t timer)

{
  return (&PROTIMER->CC0_WRAP)[timer * 4];
}



void PROTIMER_LBTUseLastConfig(void)

{
  if (PROTIMER->TOUT0COMP == 0) BUS_RegMaskedSet(&RAC->RXENSRCEN,0x10);
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




uint PROTIMER_LBTStateGet(void)

{
  return PROTIMER->LBTSTATE;
}



void PROTIMER_LBTStateSet(uint32_t state)

{
  PROTIMER->LBTSTATE = state;
}



bool PROTIMER_LBTIsActive(void)

{
  return (PROTIMER->STATUS & 6) != 0;
}


uint64_t PROTIMER_PrecntOverflowToUs(uint32_t cnt)

{
  uint uVar1;
  int in_r1;
  uint uVar2;
  
  uVar2 = precntRatioFrac * in_r1 + (int)((ulonglong)cnt * (ulonglong)precntRatioFrac >> 0x20) +
          (uint)(0x7fffffff < (uint)((ulonglong)cnt * (ulonglong)precntRatioFrac));
  uVar1 = (uint)((ulonglong)cnt * (ulonglong)precntRatioInt);
  return CONCAT44(precntRatioInt * in_r1 + (int)((ulonglong)cnt * (ulonglong)precntRatioInt >> 0x20)
                  + (uint)CARRY4(uVar1,uVar2),uVar1 + uVar2);
}




uint64_t PROTIMER_UsToPrecntOverflow(uint32_t us)

{
  return (uint64_t)
         ((ulonglong)usRatioInt * (ulonglong)us +
         ((ulonglong)usRatioFrac * (ulonglong)us + 0x80000000 >> 0x20));
}



bool PROTIMER_SetTime(uint32_t time)

{
  int iVar1;
  uint64_t uVar2;
  
  if (PROTIMER_IsRunning() != false) 
  {
    PROTIMER_Stop();
    iVar1 = 1;
  }
  PROTIMER_Reset();
  uVar2 = PROTIMER_UsToPrecntOverflow(time);
  PROTIMER->WRAPCNT,(uint32_t)PROTIMER_UsToPrecntOverflow(time);
  if (iVar1 != 0) PROTIMER_Start((uint)uVar2,(int)(uVar2 >> 0x20));
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
  PROTIMER->TOUT0CNTTOP = PROTIMER->BASECNTTOP;
  if (param_3 != 0) 
  {
    us = TIMING_RxWarmTimeGet();
    uVar2 = PROTIMER_UsToPrecntOverflow(us);
    if (PROTIMER->BASECNTTOP < (uint)PROTIMER_UsToPrecntOverflow(us)) 
	{
      BUS_RegMaskedSet(&RAC->RXENSRCEN,0x10);
      PROTIMER->TOUT0COMP = 0;
    }
    else PROTIMER->TOUT0COMP = (uint)PROTIMER_UsToPrecntOverflow(us);
    PROTIMER->RXCTRL = 0x18011b01;
  }
  PROTIMER->TXCTRL = 0x1401;
}




void PROTIMER_DelayUs(uint32_t us)

{
  uint end;
  uint uVar1;
  int iVar2;
  uint32_t uVar3;
  uint uVar4;
  uint begin;
  uint uVar5;
  uint64_t uVar6;
  
  uVar6 = PROTIMER_UsToPrecntOverflow(us);
  uVar4 = (uint)uVar6;
  begin = read_volatile_4(PROTIMER->WRAPCNT);
  uVar1 = read_volatile_4(PROTIMER->WRAPCNTTOP);
  iVar2 = PROTIMER_IsRunning(uVar4,(int)(uVar6 >> 0x20));
  if (iVar2 != 0) 
  {
    while( true ) 
	{
      uVar5 = uVar4;
      if (uVar1 >> 1 <= uVar4) uVar5 = uVar1 >> 1;
      do 
	  {
        end = PROTIMER->WRAPCNT;
        uVar3 = PROTIMER_ElapsedTime(begin,PROTIMER->WRAPCNT);
      } while (uVar3 < uVar5);
      if (uVar4 <= uVar3) break;
      uVar4 = uVar4 - uVar3;
      begin = end;
    }
  }
}


