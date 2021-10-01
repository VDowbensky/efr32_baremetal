#include "protimer.h"



void PROTIMER_Init(void)

{
  uint uVar1;
  uint uVar2;
  
  RADIOCMU_ClockEnable(0x60400,1);
  write_volatile_4(Peripherals::PROTIMER.CTRL,(uint)"Variance:%f");
  uVar1 = RADIOCMU_ClockFreqGet(0x60400);
  uVar2 = ((uVar1 / 1000) * 0x200 + 500) / 1000;
  write_volatile_4(Peripherals::PROTIMER.PRECNTTOP,uVar2 & 0xff | (uVar2 & 0xffffff00) - 0x100);
  write_volatile_4(Peripherals::PROTIMER.WRAPCNTTOP,0x7fffffff);
  proTimerClockkHz = uVar1 / 1000;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void PROTIMER_Start(void)

{
  _DAT_430a0080 = 1;
  _DAT_e000e100 = 0x10000000;
  _DAT_e000e280 = 0x10000000;
  return;
}




// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void PROTIMER_Stop(void)

{
  _DAT_430a0088 = 1;
  _DAT_e000e180 = 0x10000000;
  _DAT_e000e280 = 0x10000000;
  return;
}



bool PROTIMER_IsRunning(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::PROTIMER.STATUS);
  return (bool)((byte)uVar1 & 1);
}



void PROTIMER_Reset(void)

{
  write_volatile_4(PROTIMER->.PRECNT,0);
  write_volatile_4(PROTIMER->.BASECNT,0);
  write_volatile_4(PROTIMER->.WRAPCNT,0);
  return;
}


uint32_t PROTIMER_ElapsedTime(uint32_t start,uint32_t stop)

{
  uint uVar1;
  uint32_t uVar2;
  
  uVar1 = read_volatile_4(Peripherals::PROTIMER.WRAPCNTTOP);
  uVar2 = stop - start;
  if (stop < start) {
    uVar2 = uVar2 + uVar1 + 1;
  }
  return uVar2;
}



void PROTIMER_TOUTTimerStop(uint32_t timer)

{
  uint uVar1;
  
  if (timer == 0) {
    uVar1 = 0x20;
  }
  else {
    uVar1 = 0x80;
  }
  write_volatile_4(Peripherals::PROTIMER.CMD,uVar1);
  return;
}



void PROTIMER_TOUTTimerStart(uint32_t time,uint32_t timer)

{
  uint uVar1;
  
  if (timer == 0) {
    write_volatile_4(Peripherals::PROTIMER.TOUT0CNTTOP,time << 8);
    write_volatile_4(Peripherals::PROTIMER.IFC,0x50);
    uVar1 = 0x10;
  }
  else {
    write_volatile_4(Peripherals::PROTIMER.TOUT1CNTTOP,time << 8);
    write_volatile_4(Peripherals::PROTIMER.IFC,0xa0);
    uVar1 = 0x40;
  }
  write_volatile_4(Peripherals::PROTIMER.CMD,uVar1);
  return;
}



uint32_t PROTIMER_TOUTTimerGet(uint32_tint timer)

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
  *(undefined4 *)(timer * 0x200 + 0x430a0e80) = 0;
  write_volatile_4(Peripherals::PROTIMER.IFC,0x100 << (timer & 0xff));
  return;
}



bool PROTIMER_CCTimerStart(uint32_t timer,uint32_t time,RAIL_TimeMode_t mode)

{
  uint uVar1;
  uint stop;
  uint uVar2;
  CORE_irqState_t irqState;
  uint32_t uVar3;
  int iVar4;
  bool bVar5;
  
  irqState = CORE_EnterCritical();
  PROTIMER_CCTimerStop(timer);
  if (mode == RAIL_TIME_DELAY) {
    uVar1 = read_volatile_4(Peripherals::PROTIMER.WRAPCNT);
    time = time + uVar1 + 1;
  }
  else {
    if (mode == RAIL_TIME_DISABLED) {
      return true;
    }
  }
  uVar1 = read_volatile_4(Peripherals::PROTIMER.WRAPCNTTOP);
  if (uVar1 < time) {
    time = (time - uVar1) - 1;
  }
  iVar4 = 0;
  while( true ) {
    (&Peripherals::PROTIMER.CC0_WRAP)[timer * 4] = time;
    (&Peripherals::PROTIMER.CC0_CTRL)[timer * 4] = 0x11;
    stop = read_volatile_4(Peripherals::PROTIMER.WRAPCNT);
    uVar3 = PROTIMER_ElapsedTime(time,stop);
    if (uVar1 >> 2 < uVar3) {
      bVar5 = false;
    }
    else {
      uVar2 = read_volatile_4(Peripherals::PROTIMER.IFS);
      bVar5 = (0x100 << (timer & 0xff) & uVar2) == 0;
    }
    iVar4 = iVar4 + 1;
    time = iVar4 + stop;
    if ((mode != RAIL_TIME_DELAY) || (iVar4 == 6)) break;
    if (!bVar5) {
LAB_0000ab38:
      CORE_ExitCritical(irqState);
      return true;
    }
  }
  if (bVar5) {
    PROTIMER_CCTimerStop(timer);
    CORE_ExitCritical(irqState);
    return false;
  }
  goto LAB_0000ab38;
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
  return (&Peripherals::PROTIMER.CC0_CTRL)[timer * 4] & 1;
}



void PROTIMER_CCTimerCapture(uint32_t timer,uint32_t time)

{
  (&Peripherals::PROTIMER.CC0_CTRL)[timer * 4] = time & 0xe00000 | 3;
  return;
}



bool PROTIMER_ScheduleTxEnable(void)

{
  undefined uVar1;
  int in_r0;
  
  RADIO_TxWarmTimeGet();
  PROTIMER_CCTimerStop();
  write_volatile_4(PROTIMER->.TXCTRL,(in_r0 + 9) * 0x100 | 1);
  uVar1 = PROTIMER_CCTimerStart();
  return (bool)uVar1;
}



void PROTIMER_ClearTxEnable(void)

{
  write_volatile_4(PROTIMER->.TXCTRL,0);
  return;
}



void PROTIMER_ScheduleRxEnable(int param_1,undefined4 param_2,undefined4 param_3)

{
  PROTIMER_CCTimerStop();
  write_volatile_4(Peripherals::PROTIMER.RXCTRL,(param_1 + 9) * 0x100 | 0x10001);
  PROTIMER_CCTimerStart(param_1,param_2,param_3);
  return;
}



void PROTIMER_ScheduleRxDisable(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  
  PROTIMER_CCTimerStop();
  uVar1 = read_volatile_4(Peripherals::PROTIMER.RXCTRL);
  write_volatile_4(Peripherals::PROTIMER.RXCTRL,
                   uVar1 & 0xe0e0ffff | 0x10000 | (param_1 + 9) * 0x1000000);
  PROTIMER_CCTimerStart(param_1,param_2,param_3);
  return;
}



void PROTIMER_ClearRxEnable(void)

{
  write_volatile_4(Peripherals::PROTIMER.RXCTRL,0x1010000);
  return;
}



uint32_t PROTIMER_GetTime(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::PROTIMER.WRAPCNT);
  return uVar1;



uint32_t PROTIMER_GetCCTime(uint32_t timer)

{
  return (&Peripherals::PROTIMER.CC0_WRAP)[timer * 4];
}



void PROTIMER_LBTUseLastConfig(void)

{
  write_volatile_4(PROTIMER->.RXCTRL,0x18011b01);
  write_volatile_4(PROTIMER->.TXCTRL,0x1401);
  return;
}



void PROTIMER_LBTStart(void)

{
  RADIO_PTI_AuxdataOutput(0x21);
  _DAT_430a00c0 = 1;
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
  write_volatile_4(Peripherals::PROTIMER.CMD,0x40000);
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
  
  uVar1 = read_volatile_4(Peripherals::PROTIMER.STATUS);
  return (uVar1 & 6) != 0;
}



uint32_t PROTIMER_PrecntOverflowToUs(uint32_t cnt)

{
  return cnt * 2;
}



uint32_t PROTIMER_UsToPrecntOverflow(uint32_t us)

{
  return (us & 1) + (us >> 1);
}


bool PROTIMER_SetTime(uint32_t time)

{
  int iVar1;
  
  iVar1 = PROTIMER_IsRunning();
  if (iVar1 != 0) {
    PROTIMER_Stop();
    iVar1 = 1;
  }
  PROTIMER_Reset();
  write_volatile_4(PROTIMER->.WRAPCNT,(time & 1) + (time >> 1));
  if (iVar1 != 0) {
    PROTIMER_Start();
  }
  return true;
}



void PROTIMER_LBTCfgSet(uint param_1,int param_2,uint param_3,int param_4,byte param_5)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = read_volatile_4(Peripherals::PROTIMER.CTRL);
  write_volatile_4(Peripherals::PROTIMER.CTRL,uVar1 & 0xff0fffff | 0x900000);
  if (param_3 == 0) {
    write_volatile_4(Peripherals::PROTIMER.RXCTRL,0);
    param_1 = param_3;
  }
  write_volatile_4(Peripherals::PROTIMER.LBTCTRL,
                   (uint)param_5 << 8 | param_4 << 0x18 | param_2 << 4 | param_3 << 0x10 | param_1);
  uVar1 = read_volatile_4(Peripherals::PROTIMER.BASECNTTOP);
  write_volatile_4(Peripherals::PROTIMER.TOUT0CNTTOP,uVar1);
  if (param_3 != 0) {
    TIMING_RxWarmTimeGet();
    uVar2 = PROTIMER_UsToPrecntOverflow();
    if (uVar1 < uVar2) {
      write_volatile_4(Peripherals::RAC_SET.RXENSRCEN,0x10);
      write_volatile_4(Peripherals::PROTIMER.TOUT0COMP,0);
    }
    else {
      write_volatile_4(Peripherals::PROTIMER.TOUT0COMP,uVar2);
    }
    write_volatile_4(Peripherals::PROTIMER.RXCTRL,0x18011b01);
  }
  write_volatile_4(Peripherals::PROTIMER.TXCTRL,0x1401);
  return;
}



void PROTIMER_DelayUs(uint32_t us)

{
  uint stop;
  uint uVar1;
  bool bVar2;
  uint32_t uVar3;
  uint uVar4;
  uint start;
  uint uVar5;
  
  start = read_volatile_4(Peripherals::PROTIMER.WRAPCNT);
  uVar1 = read_volatile_4(Peripherals::PROTIMER.WRAPCNTTOP);
  bVar2 = PROTIMER_IsRunning();
  if (bVar2 != false) {
    uVar4 = (us & 1) + (us >> 1);
    while( true ) {
      uVar5 = uVar4;
      if (uVar1 >> 1 <= uVar4) {
        uVar5 = uVar1 >> 1;
      }
      do {
        stop = read_volatile_4(Peripherals::PROTIMER.WRAPCNT);
        uVar3 = PROTIMER_ElapsedTime(start,stop);
      } while (uVar3 < uVar5);
      if (uVar4 <= uVar3) break;
      uVar4 = uVar4 - uVar3;
      start = stop;
    }
  }
  return;
}

