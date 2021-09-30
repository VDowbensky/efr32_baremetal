#include "protimer.h"



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void PROTIMER_Init(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  
  RADIOCMU_ClockEnable(0x60400,1,param_3,param_4,param_4);
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



uint PROTIMER_IsRunning(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::PROTIMER.STATUS);
  return uVar1 & 1;
}



void PROTIMER_Reset(void)

{
  write_volatile_4(PROTIMER->.PRECNT,0);
  write_volatile_4(PROTIMER->.BASECNT,0);
  write_volatile_4(PROTIMER->.WRAPCNT,0);
  return;
}


int PROTIMER_ElapsedTime(uint param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = read_volatile_4(Peripherals::PROTIMER.WRAPCNTTOP);
  iVar2 = param_2 - param_1;
  if (param_2 < param_1) {
    iVar2 = iVar2 + uVar1 + 1;
  }
  return iVar2;
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



void PROTIMER_TOUTTimerStart(int param_1,int param_2)

{
  uint uVar1;
  
  if (param_2 == 0) {
    write_volatile_4(Peripherals::PROTIMER.TOUT0CNTTOP,param_1 << 8);
    write_volatile_4(Peripherals::PROTIMER.IFC,0x50);
    uVar1 = 0x10;
  }
  else {
    write_volatile_4(Peripherals::PROTIMER.TOUT1CNTTOP,param_1 << 8);
    write_volatile_4(Peripherals::PROTIMER.IFC,0xa0);
    uVar1 = 0x40;
  }
  write_volatile_4(Peripherals::PROTIMER.CMD,uVar1);
  return;
}



uint PROTIMER_TOUTTimerGet(int param_1)

{
  uint uVar1;
  
  if (param_1 == 0) {
    uVar1 = read_volatile_4(Peripherals::PROTIMER.TOUT0CNT);
  }
  else {
    uVar1 = read_volatile_4(Peripherals::PROTIMER.TOUT1CNT);
  }
  return (uVar1 << 8) >> 0x10;
}



void PROTIMER_CCTimerStop(uint param_1)

{
  (&Peripherals::PROTIMER_CLR.CC0_CTRL)[param_1 * 4] = 1;
  write_volatile_4(Peripherals::PROTIMER.IFC,0x100 << (param_1 & 0xff));
  return;
}



undefined4 PROTIMER_CCTimerStart(uint param_1,uint param_2,int param_3)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  bool bVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  
  uVar6 = param_1;
  iVar8 = param_3;
  uVar2 = CORE_EnterCritical();
  PROTIMER_CCTimerStop(param_1);
  uVar1 = read_volatile_4(Peripherals::PROTIMER.WRAPCNT);
  if (param_3 == 1) {
    if (param_2 == 0) {
      param_2 = 1;
    }
    param_2 = param_2 + uVar1;
  }
  else {
    if (param_3 == 2) {
      return 1;
    }
  }
  uVar1 = read_volatile_4(Peripherals::PROTIMER.WRAPCNTTOP);
  if (uVar1 < param_2) {
    param_2 = (param_2 - uVar1) - 1;
  }
  iVar4 = 1;
  while( true ) {
    (&Peripherals::PROTIMER.CC0_WRAP)[param_1 * 4] = param_2;
    (&Peripherals::PROTIMER.CC0_CTRL)[param_1 * 4] = 0x11;
    uVar7 = read_volatile_4(Peripherals::PROTIMER.WRAPCNT);
    uVar3 = PROTIMER_ElapsedTime(param_2,uVar7,uVar7,param_1 * 0x10 + 0x40085070,uVar6,uVar7,iVar8);
    if (uVar1 >> 2 < uVar3) {
      bVar5 = false;
    }
    else {
      uVar3 = read_volatile_4(Peripherals::PROTIMER.IF);
      bVar5 = (0x100 << (param_1 & 0xff) & uVar3) == 0;
    }
    iVar4 = iVar4 + 1;
    param_2 = iVar4 + uVar7;
    if ((param_3 != 1) || (iVar4 == 7)) break;
    if (!bVar5) {
LAB_0001026a:
      CORE_ExitCritical(uVar2);
      return 1;
    }
  }
  if (bVar5) {
    PROTIMER_CCTimerStop(param_1);
    CORE_ExitCritical(uVar2);
    return 0;
  }
  goto LAB_0001026a;
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



uint PROTIMER_CCTimerIsEnabled(int param_1)

{
  return (&Peripherals::PROTIMER.CC0_CTRL)[param_1 * 4] & 1;
}



void PROTIMER_CCTimerCapture(int param_1,uint param_2)

{
  (&Peripherals::PROTIMER.CC0_CTRL)[param_1 * 4] = param_2 & 0xe00000 | 3;
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



uint PROTIMER_GetTime(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::PROTIMER.WRAPCNT);
  return uVar1;
}



uint PROTIMER_GetCCTime(int param_1)

{
  return (&Peripherals::PROTIMER.CC0_WRAP)[param_1 * 4];
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
  uVar6 = read_volatile_4(Peripherals::PROTIMER.WRAPCNT);
  uVar2 = read_volatile_4(Peripherals::PROTIMER.WRAPCNTTOP);
  iVar4 = PROTIMER_IsRunning();
  if (iVar4 != 0) {
    while( true ) {
      uVar7 = uVar3;
      if (uVar2 >> 1 <= uVar3) {
        uVar7 = uVar2 >> 1;
      }
      do {
        uVar1 = read_volatile_4(Peripherals::PROTIMER.WRAPCNT);
        uVar5 = PROTIMER_ElapsedTime(uVar6,uVar1);
      } while (uVar5 < uVar7);
      if (uVar3 <= uVar5) break;
      uVar3 = uVar3 - uVar5;
      uVar6 = uVar1;
    }
  }
  return;
}


