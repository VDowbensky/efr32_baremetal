#include "protimer.h"

usRatioInt;
RatioFrac;
precntRatioInt;
precntRatioFrac;

// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void PROTIMER_Init(void)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  
  RADIOCMU_ClockEnable(0x60400);
  PROTIMER->CTRL = 0x11100;
  //uVar2 = RADIOCMU_ClockFreqGet(0x60400); //38 400 000
  uVar2 = RADIOCMU_ClockFreqGet(0x60400) / 1000; //in kHz 38 400
  uVar3 = (uint)((ulonglong)uVar2 * 2000); //in 0.5 Hz units //76 800 000
  uVar5 = uVar3 * 0x100; //*512 //39 321 600 000
  
  uVar6 = __aeabi_uldivmod(uVar5 + 500000,((int)((ulonglong)uVar2 * 2000 >> 0x20) << 8 | uVar3 >> 0x18) + (uint)(0xfff85edf < uVar5),1000000,0);
  uVar3 = (uint)uVar6;
  PROTIMER->PRECNTTOP = (uint)uVar6 - 0x100;
  uVar7 = __aeabi_uldivmod(500,uVar2,1000,0);
  uVar5 = (uint)uVar7 * 0x100;
  _usRatioFrac = __aeabi_uldivmod((uVar3 >> 1) + uVar5,((int)((ulonglong)uVar7 >> 0x20) << 8 | (uint)uVar7 >> 0x18) + (uint)CARRY4(uVar3 >> 1,uVar5),uVar3,(int)((ulonglong)uVar6 >> 0x20));
  iVar4 = (int)_usRatioFrac;
  lVar1 = (ulonglong)(uVar3 << 0x18) * 1000;
  uVar5 = (uint)lVar1;
  uVar6 = __aeabi_uldivmod(uVar5 + (uVar2 >> 1),(uVar3 >> 8) * 1000 + (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar5,uVar2 >> 1),uVar2,0);
  PROTIMER->WRAPCNTTOP = iVar4 - 1;

  precntRatioInt = (int)((ulonglong)uVar6 >> 0x20); //0x4B
  precntRatioInt = (uint32_t)(2000*(uint64_t)RADIOCMU_ClockFreqGet(0x60400))/1000000000 - 1;
  
  precntRatioFrac = (int)uVar6; //0xCC
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void PROTIMER_Start(void)

{
  write_volatile_4(PROTIMER->CMD,1);
  _DAT_e000e100 = 0x10000000;
  _DAT_e000e280 = 0x10000000;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void PROTIMER_Stop(void)

{
  write_volatile_4(PROTIMER->CMD,4);
  _DAT_e000e180 = 0x10000000;
  _DAT_e000e280 = 0x10000000;
  return;
}



uint PROTIMER_IsRunning(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(PROTIMER->STATUS);
  return uVar1 & 1;
}



void PROTIMER_Reset(void)

{
  write_volatile_4(PROTIMER->PRECNT,0);
  write_volatile_4(PROTIMER->BASECNT,0);
  write_volatile_4(PROTIMER->WRAPCNT,0);
  return;
}



uint32_t PROTIMER_ElapsedTime(uint32_t param_1,uint32_t param_2)

{
  uint uVar1;
  uint32_t uVar2;
  
  uVar1 = read_volatile_4(PROTIMER->WRAPCNTTOP);
  uVar2 = param_2 - param_1;
  if (param_2 < param_1) {
    uVar2 = uVar2 + uVar1 + 1;
  }
  return uVar2;
}



void PROTIMER_TOUTTimerStop(uint8_t tout)

{
  uint uVar1;
  
  if (tout == '\0') {
    uVar1 = 0x20;
  }
  else {
    uVar1 = 0x80;
  }
  write_volatile_4(PROTIMER->CMD,uVar1);
  return;
}



void PROTIMER_TOUTTimerStart(int32_t param_1,int8_t tout)

{
  uint uVar1;
  
  if (tout == '\0') {
    write_volatile_4(PROTIMER->TOUT0CNTTOP,param_1 << 8);
    write_volatile_4(PROTIMER->IFC,0x50);
    uVar1 = 0x10;
  }
  else {
    write_volatile_4(PROTIMER->TOUT1CNTTOP,param_1 << 8);
    write_volatile_4(PROTIMER->IFC,0xa0);
    uVar1 = 0x40;
  }
  write_volatile_4(PROTIMER->CMD,uVar1);
  return;
}



uint32_t PROTIMER_TOUTTimerGet(uint8_t tout)

{
  uint uVar1;
  
  if (tout == '\0') {
    uVar1 = read_volatile_4(PROTIMER->TOUT0CNT);
  }
  else {
    uVar1 = read_volatile_4(PROTIMER->TOUT1CNT);
  }
  return (uVar1 << 8) >> 0x10;
}



void PROTIMER_CCTimerStop(uint8_t channel)

{
  (&Peripherals::PROTIMER_CLR.CC0_CTRL)[(uint)channel * 4] = 1;
  write_volatile_4(PROTIMER->IFC,0x100 << (uint)channel);
  return;
}



bool PROTIMER_CCTimerStart(uint param_1,uint param_2,int param_3)

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
  uVar1 = read_volatile_4(PROTIMER->WRAPCNT);
  if (param_3 == 1) {
    param_2 = param_2 + uVar1 + 1;
  }
  else {
    if (param_3 == 2) {
      return true;
    }
  }
  uVar1 = read_volatile_4(PROTIMER->WRAPCNTTOP);
  if (uVar1 < param_2) {
    param_2 = (param_2 - uVar1) - 1;
  }
  iVar6 = 0;
  while( true ) {
    (&PROTIMER->CC0_WRAP)[param_1 * 4] = param_2;
    (&PROTIMER->CC0_CTRL)[param_1 * 4] = 0x11;
    uVar2 = read_volatile_4(PROTIMER->WRAPCNT);
    uVar5 = PROTIMER_ElapsedTime(param_2,uVar2);
    if (uVar1 >> 2 < uVar5) {
      bVar7 = false;
    }
    else {
      uVar3 = read_volatile_4(PROTIMER->IF);
      bVar7 = (0x100 << (param_1 & 0xff) & uVar3) == 0;
    }
    iVar6 = iVar6 + 1;
    param_2 = iVar6 + uVar2;
    if ((param_3 != 1) || (iVar6 == 6)) break;
    if (!bVar7) {
LAB_00010266:
      CORE_ExitCritical(uVar4);
      return true;
    }
  }
  if (bVar7) {
    PROTIMER_CCTimerStop((uint8_t)param_1);
    CORE_ExitCritical(uVar4);
    return false;
  }
  goto LAB_00010266;
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



bool PROTIMER_CCTimerIsEnabled(uint8_t channel)

{
  return (bool)((byte)(&PROTIMER->CC0_CTRL)[(uint)channel * 4] & 1);
}



void PROTIMER_CCTimerCapture(uint8_t channel,uint param_2)

{
  (&PROTIMER->CC0_CTRL)[(uint)channel * 4] = param_2 & 0xe00000 | 3;
  return;
}



void PROTIMER_ClearTxEnable(void)

{
  write_volatile_4(PROTIMER->TXCTRL,0);
  return;
}



undefined PROTIMER_ScheduleRxDisable(uint param_1,uint param_2,int param_3)

{
  uint uVar1;
  bool bVar2;
  
  PROTIMER_CCTimerStop((uint8_t)param_1);
  uVar1 = read_volatile_4(PROTIMER->RXCTRL);
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



uint PROTIMER_GetTime(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(PROTIMER->WRAPCNT);
  return uVar1;
}



uint PROTIMER_GetCCTime(int param_1)

{
  return (&PROTIMER->CC0_WRAP)[param_1 * 4];
}



void PROTIMER_LBTUseLastConfig(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(PROTIMER->TOUT0COMP);
  if (uVar1 == 0) {
    write_volatile_4(Peripherals::RAC_SET.RXENSRCEN,0x10);
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
  write_volatile_4(PROTIMER->CMD,0x20000);
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
  
  uVar1 = read_volatile_4(PROTIMER->LBTSTATE);
  return uVar1;
}



void PROTIMER_LBTStateSet(uint param_1)

{
  write_volatile_4(PROTIMER->LBTSTATE,param_1);
  return;
}



bool PROTIMER_LBTIsActive(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(PROTIMER->STATUS);
  return (uVar1 & 6) != 0;
}



undefined8 PROTIMER_PrecntOverflowToUs(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = precntRatioFrac * param_2 + (int)((ulonglong)param_1 * (ulonglong)precntRatioFrac >> 0x20)
          + (uint)(0x7fffffff < (uint)((ulonglong)param_1 * (ulonglong)precntRatioFrac));
  uVar1 = (uint)((ulonglong)param_1 * (ulonglong)precntRatioInt);
  return CONCAT44(precntRatioInt * param_2 +
                  (int)((ulonglong)param_1 * (ulonglong)precntRatioInt >> 0x20) +
                  (uint)CARRY4(uVar1,uVar2),uVar1 + uVar2);
}



uint64_t PROTIMER_UsToPrecntOverflow(uint32_t us)

{
  return (uint64_t)
         ((ulonglong)usRatioInt * (ulonglong)us +
         ((ulonglong)usRatioFrac * (ulonglong)us + 0x80000000 >> 0x20));
}



undefined PROTIMER_ScheduleTxEnable(uint param_1,uint param_2,int param_3)

{
  bool bVar1;
  uint32_t us;
  uint64_t uVar2;
  
  us = TIMING_TxWarmTimeGet();
  uVar2 = PROTIMER_UsToPrecntOverflow(us);
  PROTIMER_CCTimerStop((uint8_t)param_1);
  if ((param_3 == 1) && (param_2 < (uint)uVar2)) {
    param_2 = 0;
  }
  else {
    param_2 = param_2 - (uint)uVar2;
  }
  write_volatile_4(PROTIMER->TXCTRL,(param_1 + 9) * 0x100 | 1);
  bVar1 = PROTIMER_CCTimerStart(param_1,param_2,param_3);
  return bVar1;
}



undefined PROTIMER_ScheduleRxEnable(uint param_1,uint param_2,int param_3)

{
  bool bVar1;
  uint32_t us;
  uint64_t uVar2;
  
  PROTIMER_CCTimerStop((uint8_t)param_1);
  us = TIMING_RxWarmTimeGet();
  uVar2 = PROTIMER_UsToPrecntOverflow(us);
  if ((param_3 == 1) && (param_2 < (uint)uVar2)) {
    param_2 = 0;
  }
  else {
    param_2 = param_2 - (uint)uVar2;
  }
  write_volatile_4(PROTIMER->RXCTRL,(param_1 + 9) * 0x100 | 0x10001);
  bVar1 = PROTIMER_CCTimerStart(param_1,param_2,param_3);
  return bVar1;
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
  
  uVar1 = read_volatile_4(PROTIMER->CTRL);
  write_volatile_4(PROTIMER->CTRL,uVar1 & 0xff0fffff | 0x900000);
  if (param_3 == 0) {
    write_volatile_4(PROTIMER->RXCTRL,0);
    param_1 = param_3;
  }
  write_volatile_4(PROTIMER->LBTCTRL,
                   (uint)param_5 << 8 | param_4 << 0x18 | param_2 << 4 | param_3 << 0x10 | param_1);
  uVar1 = read_volatile_4(PROTIMER->BASECNTTOP);
  write_volatile_4(PROTIMER->TOUT0CNTTOP,uVar1);
  if (param_3 != 0) {
    us = TIMING_RxWarmTimeGet();
    uVar2 = PROTIMER_UsToPrecntOverflow(us);
    if (uVar1 < (uint)uVar2) {
      write_volatile_4(Peripherals::RAC_SET.RXENSRCEN,0x10);
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
  uVar6 = read_volatile_4(PROTIMER->WRAPCNT);
  uVar2 = read_volatile_4(PROTIMER->WRAPCNTTOP);
  iVar3 = PROTIMER_IsRunning(uVar5,(int)(uVar8 >> 0x20));
  if (iVar3 != 0) {
    while( true ) {
      uVar7 = uVar5;
      if (uVar2 >> 1 <= uVar5) {
        uVar7 = uVar2 >> 1;
      }
      do {
        uVar1 = read_volatile_4(PROTIMER->WRAPCNT);
        uVar4 = PROTIMER_ElapsedTime(uVar6,uVar1);
      } while (uVar4 < uVar7);
      if (uVar5 <= uVar4) break;
      uVar5 = uVar5 - uVar4;
      uVar6 = uVar1;
    }
  }
  return;
}


