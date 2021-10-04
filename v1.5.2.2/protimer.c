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
  write_volatile_4(Peripherals::PROTIMER.CTRL,0x11100);
  uVar2 = RADIOCMU_ClockFreqGet(0x60400);
  uVar2 = uVar2 / 1000;
  uVar3 = (uint)((ulonglong)uVar2 * 2000);
  uVar5 = uVar3 * 0x100;
  uVar6 = __aeabi_uldivmod(uVar5 + 500000,
                           ((int)((ulonglong)uVar2 * 2000 >> 0x20) << 8 | uVar3 >> 0x18) +
                           (uint)(0xfff85edf < uVar5),1000000,0);
  uVar3 = (uint)uVar6;
  write_volatile_4(Peripherals::PROTIMER.PRECNTTOP,uVar3 - 0x100);
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
  write_volatile_4(Peripherals::PROTIMER.WRAPCNTTOP,iVar4 - 1);
  precntRatioFrac = (int)uVar6;
  precntRatioInt = (int)((ulonglong)uVar6 >> 0x20);
  return;
}



void PROTIMER_Start(void)

{
  write_volatile_4(PROTIMER->CMD,1);
  _DAT_e000e100 = 0x10000000;
  _DAT_e000e280 = 0x10000000;
  return;
}



void PROTIMER_Stop(void)

{
  write_volatile_4(PROTIMER->CMD,4);
  _DAT_e000e180 = 0x10000000;
  _DAT_e000e280 = 0x10000000;
  return;
}



bool PROTIMER_IsRunning(void)

{
  uint uVar1;
  
  uVar1 = (PROTIMER->STATUS);
  return uVar1 & 1;
}



void PROTIMER_Reset(void)

{
  write_volatile_4(PROTIMER->PRECNT,0);
  write_volatile_4(PROTIMER->BASECNT,0);
  write_volatile_4(PROTIMER->WRAPCNT,0);
  return;
}



uint32_t PROTIMER_ElapsedTime(uint32_t begin,uint32_t end)

{
  uint uVar1;
  uint32_t uVar2;
  
  uVar1 = (PROTIMER->WRAPCNTTOP);
  uVar2 = end - begin;
  if (end < begin) {
    uVar2 = uVar2 + uVar1 + 1;
  }
  return uVar2;
}



void PROTIMER_TOUTTimerStop(int param_1)

{
  uint uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0x20;
  }
  else {
    uVar1 = 0x80;
  }
  write_volatile_4(Peripherals::PROTIMER.CMD,uVar1);
  return;
}



void PROTIMER_TOUTTimerStart(uint32_t timer)

{
  int in_r1;
  uint uVar1;
  
  if (in_r1 == 0) {
    write_volatile_4(Peripherals::PROTIMER.TOUT0CNTTOP,timer << 8);
    write_volatile_4(Peripherals::PROTIMER.IFC,0x50);
    uVar1 = 0x10;
  }
  else {
    write_volatile_4(Peripherals::PROTIMER.TOUT1CNTTOP,timer << 8);
    write_volatile_4(Peripherals::PROTIMER.IFC,0xa0);
    uVar1 = 0x40;
  }
  write_volatile_4(Peripherals::PROTIMER.CMD,uVar1);
  return;
}



uint32_t PROTIMER_TOUTTimerGet(uint32_t timer)

{
  uint uVar1;
  
  if (timer == 0) {
    uVar1 = read_volatile_4(Peripherals::PROTIMER.TOUT0CNT);
  }
  else {
    uVar1 = read_volatile_4(Peripherals::PROTIMER.TOUT1CNT);
  }
  return (uVar1 << 8) >> 0x10;
}



void PROTIMER_CCTimerStop(uint32_t timer)

{
  (&Peripherals::PROTIMER_CLR.CC0_CTRL)[timer * 4] = 1;
  write_volatile_4(Peripherals::PROTIMER.IFC,0x100 << (timer & 0xff));
  return;
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
  if (mode == RAIL_TIME_DELAY) {
    if (time == 0) {
      time = 1;
    }
    time = time + uVar1;
  }
  else {
    if (mode == RAIL_TIME_DISABLED) {
      return true;
    }
  }
  uVar1 = (PROTIMER->WRAPCNTTOP);
  if (uVar1 < time) {
    time = (time - uVar1) - 1;
  }
  iVar4 = 1;
  while( true ) {
    (&PROTIMER->CC0_WRAP)[timer * 4] = time;
    (&PROTIMER->CC0_CTRL)[timer * 4] = 0x11;
    end = (PROTIMER->WRAPCNT);
    uVar3 = PROTIMER_ElapsedTime(time,end);
    if (uVar1 >> 2 < uVar3) {
      bVar5 = false;
    }
    else {
      uVar2 = (PROTIMER->IF);
      bVar5 = (0x100 << (timer & 0xff) & uVar2) == 0;
    }
    iVar4 = iVar4 + 1;
    time = iVar4 + end;
    if ((mode != RAIL_TIME_DELAY) || (iVar4 == 7)) break;
    if (!bVar5) {
LAB_00010f96:
      CORE_ExitCritical(irqState);
      return true;
    }
  }
  if (bVar5) {
    PROTIMER_CCTimerStop(timer);
    CORE_ExitCritical(irqState);
    return false;
  }
  goto LAB_00010f96;
}




void PROTIMER_WrapMultiple(uint param_1,undefined4 param_2,uint param_3,int param_4)

{
  bool bVar1;
  
  while( true ) {
    bVar1 = param_4 == 0;
    if (param_4 == 0) {
      bVar1 = param_3 <= param_1;
    }
    if (!bVar1) break;
    param_1 = param_1 - param_3;
  }
  return;
}



bool PROTIMER_CCTimerIsEnabled(uint32_t timer)

{
  return (bool)((byte)(&PROTIMER->CC0_CTRL)[timer * 4] & 1);
}



void PROTIMER_CCTimerCapture(int param_1,uint param_2)

{
  (&PROTIMER->CC0_CTRL)[param_1 * 4] = param_2 & 0xe00000 | 3;
  return;
}



undefined PROTIMER_ScheduleTxEnable(uint32_t param_1,uint32_t param_2,RAIL_TimeMode_t param_3)

{
  bool bVar1;
  
  PROTIMER_CCTimerStop();
  write_volatile_4(PROTIMER->TXCTRL,(param_1 + 9) * 0x100 | 1);
  bVar1 = PROTIMER_CCTimerStart(param_1,param_2,param_3);
  return bVar1;
}



void PROTIMER_ClearTxEnable(void)

{
  write_volatile_4(PROTIMER->TXCTRL,0);
  return;
}



undefined PROTIMER_ScheduleRxEnable(uint32_t param_1,uint32_t param_2,RAIL_TimeMode_t param_3)

{
  bool bVar1;
  
  PROTIMER_CCTimerStop();
  write_volatile_4(PROTIMER->RXCTRL,(param_1 + 9) * 0x100 | 0x10001);
  bVar1 = PROTIMER_CCTimerStart(param_1,param_2,param_3);
  return bVar1;
}




undefined PROTIMER_ScheduleRxDisable(uint32_t param_1,uint32_t param_2,RAIL_TimeMode_t param_3)

{
  uint uVar1;
  bool bVar2;
  
  PROTIMER_CCTimerStop();
  uVar1 = (PROTIMER->RXCTRL);
  write_volatile_4(PROTIMER->RXCTRL,
                   uVar1 & 0xe0e0ffff | 0x10000 | (param_1 + 9) * 0x1000000);
  bVar2 = PROTIMER_CCTimerStart(param_1,param_2,param_3);
  return bVar2;
}



void PROTIMER_ClearRxEnable(void)

{
  write_volatile_4(PROTIMER->RXCTRL,0x1010000);
  return;
}


uint32_t PROTIMER_GetTime(void)

{
  uint uVar1;
  
  uVar1 = (PROTIMER->WRAPCNT);
  return uVar1;
}



uint32_t PROTIMER_GetCCTime(uint32_t timer)

{
  return (&PROTIMER->CC0_WRAP)[timer * 4];
}



void PROTIMER_LBTUseLastConfig(void)

{
  uint uVar1;
  
  uVar1 = (PROTIMER->TOUT0COMP);
  if (uVar1 == 0) {
    BUS_RegMaskedSet(&RAC->RXENSRCEN,0x10);
  }
  write_volatile_4(PROTIMER->RXCTRL,0x18011b01);
  write_volatile_4(PROTIMER->TXCTRL,0x1401);
  return;
}




void PROTIMER_LBTStart(void)

{
  RADIO_PTI_AuxdataOutput(0x21);
  write_volatile_4(PROTIMER->CMD,0x10000);
  return;
}



void PROTIMER_LBTPause(void)

{
  RADIO_PTI_AuxdataOutput(0x23);
  write_volatile_4(Peripherals::PROTIMER.CMD,0x20000);
  return;
}



void PROTIMER_LBTStop(void)

{
  RADIO_PTI_AuxdataOutput(0x22);
  write_volatile_4(PROTIMER->CMD,0x40000);
  return;
}




uint PROTIMER_LBTStateGet(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::PROTIMER.LBTSTATE);
  return uVar1;
}



void PROTIMER_LBTStateSet(uint param_1)

{
  write_volatile_4(Peripherals::PROTIMER.LBTSTATE,param_1);
  return;
}



bool PROTIMER_LBTIsActive(void)

{
  uint uVar1;
  
  uVar1 = (PROTIMER->STATUS);
  return (uVar1 & 6) != 0;
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
  
  uVar1 = (PROTIMER->CTRL);
  write_volatile_4(PROTIMER->CTRL,uVar1 & 0xff0fffff | 0x900000);
  if (param_3 == 0) {
    write_volatile_4(PROTIMER->RXCTRL,0);
    param_1 = param_3;
  }
  write_volatile_4(PROTIMER->LBTCTRL,
                   (uint)param_5 << 8 | param_4 << 0x18 | param_2 << 4 | param_3 << 0x10 | param_1);
  uVar1 = (PROTIMER->BASECNTTOP);
  write_volatile_4(PROTIMER->TOUT0CNTTOP,uVar1);
  if (param_3 != 0) {
    us = TIMING_RxWarmTimeGet();
    uVar2 = PROTIMER_UsToPrecntOverflow(us);
    if (uVar1 < (uint)uVar2) {
      BUS_RegMaskedSet(&RAC->RXENSRCEN,0x10);
      write_volatile_4(PROTIMER->TOUT0COMP,0);
    }
    else {
      write_volatile_4(PROTIMER->TOUT0COMP,(uint)uVar2);
    }
    write_volatile_4(PROTIMER->RXCTRL,0x18011b01);
  }
  write_volatile_4(PROTIMER->TXCTRL,0x1401);
  return;
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
  begin = read_volatile_4(Peripherals::PROTIMER.WRAPCNT);
  uVar1 = read_volatile_4(Peripherals::PROTIMER.WRAPCNTTOP);
  iVar2 = PROTIMER_IsRunning(uVar4,(int)(uVar6 >> 0x20));
  if (iVar2 != 0) {
    while( true ) {
      uVar5 = uVar4;
      if (uVar1 >> 1 <= uVar4) {
        uVar5 = uVar1 >> 1;
      }
      do {
        end = read_volatile_4(Peripherals::PROTIMER.WRAPCNT);
        uVar3 = PROTIMER_ElapsedTime(begin,end);
      } while (uVar3 < uVar5);
      if (uVar4 <= uVar3) break;
      uVar4 = uVar4 - uVar3;
      begin = end;
    }
  }
  return;
}


