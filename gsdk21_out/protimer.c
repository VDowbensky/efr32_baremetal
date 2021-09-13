#include "protimer.h"



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void PROTIMER_Init(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  longlong lVar5;
  undefined8 uVar6;
  
  RADIOCMU_ClockEnable(0x60400,1,param_3,param_4,param_4);
  _DAT_40085000 = 0x11100;
  uVar1 = RADIOCMU_ClockFreqGet(0x60400);
  uVar1 = uVar1 / 1000;
  uVar2 = (uint)((ulonglong)uVar1 * 2000);
  uVar4 = uVar2 * 0x100;
  lVar5 = __aeabi_uldivmod(uVar4 + 500000,
                           ((int)((ulonglong)uVar1 * 2000 >> 0x20) << 8 | uVar2 >> 0x18) +
                           (uint)(0xfff85edf < uVar4),1000000,0);
  uVar2 = (uint)lVar5;
  _DAT_40085028 = uVar2 - 0x100;
  uVar6 = __aeabi_uldivmod(500,uVar1,1000,0);
  if (lVar5 == 0) {
    RAILInt_Assert(0,0x2b);
    uVar2 = 1;
  }
  uVar4 = (uint)uVar6 * 0x100;
  _usRatioFrac = __aeabi_uldivmod(uVar4 + (uVar2 >> 1),
                                  ((int)((ulonglong)uVar6 >> 0x20) << 8 | (uint)uVar6 >> 0x18) +
                                  (uint)CARRY4(uVar4,uVar2 >> 1),uVar2,0);
  iVar3 = (int)_usRatioFrac;
  if (uVar1 == 0) {
    RAILInt_Assert(0,0x2b);
    uVar1 = 1;
  }
  lVar5 = (ulonglong)(uVar2 << 0x18) * 1000;
  uVar4 = (uint)lVar5;
  uVar6 = __aeabi_uldivmod(uVar4 + (uVar1 >> 1),
                           (uVar2 >> 8) * 1000 + (int)((ulonglong)lVar5 >> 0x20) +
                           (uint)CARRY4(uVar4,uVar1 >> 1),uVar1,0);
  precntRatioFrac = (int)uVar6;
  precntRatioInt = (int)((ulonglong)uVar6 >> 0x20);
  _DAT_40085030 = iVar3 + -1;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void PROTIMER_Start(void)

{
  _DAT_40085004 = 1;
  _DAT_e000e100 = 0x10000000;
  _DAT_e000e280 = 0x10000000;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void PROTIMER_Stop(void)

{
  _DAT_40085004 = 4;
  _DAT_e000e180 = 0x10000000;
  _DAT_e000e280 = 0x10000000;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

uint PROTIMER_IsRunning(void)

{
  return _DAT_4008500c & 1;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void PROTIMER_Reset(void)

{
  _DAT_40085010 = 0;
  _DAT_40085014 = 0;
  _DAT_40085018 = 0;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

int PROTIMER_ElapsedTime(uint param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = param_2 - param_1;
  if (param_2 < param_1) {
    iVar1 = iVar1 + _DAT_40085030 + 1;
  }
  return iVar1;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void PROTIMER_TOUTTimerStop(int param_1)

{
  if (param_1 == 0) {
    _DAT_40085004 = 0x20;
  }
  else {
    _DAT_40085004 = 0x80;
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void PROTIMER_TOUTTimerStart(uint param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  RAILInt_Assert(param_1 < 0x100,0x15,param_3,param_4,param_4);
  if (param_2 == 0) {
    _DAT_40085064 = 0x50;
    _DAT_40085004 = 0x10;
    _DAT_40085038 = param_1 << 8;
  }
  else {
    _DAT_40085064 = 0xa0;
    _DAT_40085004 = 0x40;
    _DAT_40085044 = param_1 << 8;
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

uint PROTIMER_TOUTTimerGet(int param_1)

{
  int iVar1;
  
  iVar1 = _DAT_40085040;
  if (param_1 == 0) {
    iVar1 = _DAT_40085034;
  }
  return (uint)(iVar1 << 8) >> 0x10;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void PROTIMER_CCTimerStop(uint param_1)

{
  *(undefined4 *)(param_1 * 0x10 + 0x44085074) = 1;
  _DAT_40085064 = 0x100 << (param_1 & 0xff);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined4 PROTIMER_CCTimerStart(uint param_1,uint param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  uint *puVar8;
  uint uVar9;
  bool bVar10;
  int iVar11;
  
  uVar4 = param_1;
  iVar11 = param_3;
  uVar2 = CORE_EnterCritical();
  PROTIMER_CCTimerStop(param_1);
  iVar1 = _DAT_40085018;
  if (param_3 != 2) {
    if (param_3 == 1) {
      param_2 = param_2 + _DAT_40085018 + 1;
    }
    uVar9 = _DAT_40085030 + 1;
    uVar5 = (uint)(0xfffffffe < _DAT_40085030);
    while( true ) {
      bVar10 = uVar5 == 0;
      if (uVar5 == 0) {
        bVar10 = uVar9 <= param_2;
      }
      if (!bVar10) break;
      param_2 = param_2 - uVar9;
    }
    uVar3 = PROTIMER_ElapsedTime(param_2,_DAT_40085018);
    if (uVar3 <= (uVar9 >> 2 | uVar5 << 0x1e)) {
LAB_00010258:
      CORE_ExitCritical(uVar2);
      return 0;
    }
    uVar5 = (param_1 + 9) * 0x100 | 1;
    if ((_DAT_40085070 & 0x1f1f) == uVar5) {
      uVar9 = 4;
    }
    else {
      uVar9 = 0;
    }
    if ((_DAT_4008506c & 0x1f1f0000) == ((param_1 + 9) * 0x1000000 | 0x10000)) {
      uVar9 = uVar9 | 2;
    }
    if ((_DAT_4008506c & 0x1f1f) == uVar5) {
      uVar9 = uVar9 | 1;
    }
    puVar7 = (uint *)(uVar9 & 1);
    puVar8 = puVar7;
    if (puVar7 != (uint *)0x0) {
      puVar8 = &PROTIMER_scheduledRxEnable;
    }
    iVar6 = param_1 * 0x10;
    if (puVar7 != (uint *)0x0) {
      *puVar8 = param_2;
    }
    *(uint *)(iVar6 + 0x40085080) = param_2;
    *(undefined4 *)(iVar6 + 0x40085074) = 0x11;
    uVar4 = PROTIMER_ElapsedTime(iVar1,_DAT_40085018,0x11,&DAT_40085070 + iVar6,uVar4,puVar7,iVar11)
    ;
    uVar5 = PROTIMER_ElapsedTime(iVar1,param_2);
    if ((uVar5 <= uVar4) && (uVar4 = 0x100 << (param_1 & 0xff), (uVar4 & _DAT_4008505c) == 0)) {
      if (param_3 == 0) {
        PROTIMER_CCTimerStop(param_1);
        goto LAB_00010258;
      }
      if (puVar7 != (uint *)0x0) {
        _DAT_4608506c = 0x101;
        _DAT_4408506c = 0x1f1f;
      }
      uVar5 = uVar9 << 0x1e;
      if ((int)uVar5 < 0) {
        uVar5 = 0x1f1f0000;
        _DAT_4608506c = 0x1010000;
        _DAT_4408506c = 0x1f1f0000;
      }
      puVar8 = (uint *)(uVar9 << 0x1d);
      bVar10 = (int)puVar8 < 0;
      if (bVar10) {
        puVar8 = &RAC_RXENSRCEN;
        uVar5 = 1;
      }
      _DAT_40085060 = uVar4;
      if (bVar10) {
        puVar8[2] = uVar5;
      }
    }
  }
  CORE_ExitCritical(uVar2);
  return 1;
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
  return *(uint *)(param_1 * 0x10 + 0x40085074) & 1;
}



void PROTIMER_CCTimerCapture(int param_1,uint param_2)

{
  *(uint *)(param_1 * 0x10 + 0x40085074) = param_2 & 0xe00000 | 3;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void PROTIMER_ScheduleTxEnable(int param_1,undefined4 param_2,undefined4 param_3)

{
  PROTIMER_CCTimerStop();
  _DAT_40085070 = (param_1 + 9) * 0x100 | 1;
  PROTIMER_CCTimerStart(param_1,param_2,param_3);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void PROTIMER_ClearTxEnable(void)

{
  _DAT_40085070 = 0;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void PROTIMER_ScheduleRxEnable(int param_1,undefined4 param_2,undefined4 param_3)

{
  PROTIMER_CCTimerStop();
  _DAT_4008506c = (param_1 + 9) * 0x100 | 0x10001;
  PROTIMER_CCTimerStart(param_1,param_2,param_3);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void PROTIMER_ScheduleRxDisable(int param_1,undefined4 param_2,undefined4 param_3)

{
  PROTIMER_CCTimerStop();
  _DAT_4008506c = _DAT_4008506c & 0xe0e0ffff | 0x10000 | (param_1 + 9) * 0x1000000;
  PROTIMER_CCTimerStart(param_1,param_2,param_3);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void PROTIMER_ClearRxEnable(void)

{
  _DAT_4008506c = 0x1010000;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined4 PROTIMER_GetTime(void)

{
  return _DAT_40085018;
}



undefined4 PROTIMER_GetCCTime(int param_1)

{
  return *(undefined4 *)(param_1 * 0x10 + 0x40085080);
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void PROTIMER_LBTUseLastConfig(void)

{
  if (_DAT_4008503c == 0) {
    write_volatile_4(RAC_RXENSRCEN_SET,0x10);
  }
  _DAT_4008506c = 0x18011b01;
  _DAT_40085070 = 0x1401;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void PROTIMER_LBTStart(void)

{
  PTI_AuxdataOutput(0x21);
  _DAT_40085004 = 0x10000;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void PROTIMER_LBTPause(void)

{
  PTI_AuxdataOutput(0x23);
  _DAT_40085004 = 0x20000;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void PROTIMER_LBTStop(void)

{
  PTI_AuxdataOutput(0x22);
  _DAT_40085004 = 0x40000;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined4 PROTIMER_LBTStateGet(void)

{
  PTI_AuxdataOutput(0x24);
  return _DAT_40085054;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void PROTIMER_LBTStateSet(undefined4 param_1)

{
  PTI_AuxdataOutput(0x25);
  _DAT_40085054 = param_1;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

bool PROTIMER_LBTIsActive(void)

{
  return (_DAT_4008500c & 6) != 0;
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



longlong PROTIMER_UsToPrecntOverflow(uint param_1)

{
  return (ulonglong)usRatioInt * (ulonglong)param_1 +
         ((ulonglong)usRatioFrac * (ulonglong)param_1 + 0x80000000 >> 0x20);
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined4 PROTIMER_SetTime(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = PROTIMER_IsRunning();
  if (iVar1 != 0) {
    PROTIMER_Stop();
    iVar1 = 1;
  }
  PROTIMER_Reset();
  _DAT_40085018 = PROTIMER_UsToPrecntOverflow(param_1);
  if (iVar1 != 0) {
    PROTIMER_Start();
  }
  return 1;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void PROTIMER_LBTCfgSet(int param_1,uint param_2,int param_3,uint param_4,byte param_5,byte param_6)

{
  uint uVar1;
  
  uVar1 = _DAT_4008502c;
  _DAT_40085000 = _DAT_40085000 & 0xff0fffff | 0x900000;
  if (param_4 == 0) {
    param_2 = param_4;
    _DAT_4008506c = param_4;
  }
  _DAT_4008504c =
       (uint)param_6 << 8 | (uint)param_5 << 0x18 | param_3 << 4 | param_4 << 0x10 | param_2;
  RAILInt_Assert(_DAT_4008502c < 0x100,0x18,_DAT_4008504c,param_5,param_4);
  _DAT_40085038 = uVar1;
  if (param_4 != 0) {
    _DAT_4008503c = PROTIMER_UsToPrecntOverflow(*(undefined2 *)(param_1 + 0x10));
    if (uVar1 < _DAT_4008503c) {
      write_volatile_4(RAC_RXENSRCEN_SET,0x10);
      _DAT_4008503c = 0;
    }
    _DAT_4008506c = 0x18011b01;
  }
  _DAT_40085070 = 0x1401;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void PROTIMER_DelayUs(void)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  
  uVar3 = PROTIMER_UsToPrecntOverflow();
  uVar2 = _DAT_40085030;
  uVar6 = _DAT_40085018;
  iVar4 = PROTIMER_IsRunning();
  if (iVar4 != 0) {
    while( true ) {
      uVar7 = uVar3;
      if (uVar2 >> 1 <= uVar3) {
        uVar7 = uVar2 >> 1;
      }
      do {
        uVar1 = _DAT_40085018;
        uVar5 = PROTIMER_ElapsedTime(uVar6,_DAT_40085018);
      } while (uVar5 < uVar7);
      if (uVar3 <= uVar5) break;
      uVar3 = uVar3 - uVar5;
      uVar6 = uVar1;
    }
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

uint PROTIMER_CheckCcaReallyFailed(uint param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar3 = CORE_EnterAtomic();
  if ((param_1 & 0x600000) != 0) {
    uVar5 = read_volatile_4(AGC_RSSI);
    uVar5 = uVar5 << 0x10;
    uVar6 = uVar5 >> 0x16;
    uVar1 = read_volatile_4(RAC_STATUS);
    uVar2 = read_volatile_4(AGC_CTRL1);
    if ((int)uVar5 < 0) {
      uVar6 = ~(uVar5 & 0xffc00000);
    }
    uVar4 = uVar2 & 0xff;
    if ((int)uVar5 < 0) {
      uVar6 = ~(uVar6 >> 0x16);
    }
    if ((int)(uVar2 << 0x18) < 0) {
      uVar4 = uVar4 | 0xffffff00;
    }
    if ((((((int)(uVar4 + 0x46) < 0 == SCARRY4(uVar4,0x46)) && (uVar6 != 0xfffffe00)) &&
         (uVar6 == uVar4 * 4 || (int)(uVar6 + uVar4 * -4) < 0 != SBORROW4(uVar6,uVar4 * 4))) &&
        (((uVar1 & 0xf000000) == 0x4000000 || ((uVar1 & 0xd000000) == 0)))) &&
       ((-1 < _DAT_4008505c << 0xb && (PROTIMER_LBTStop(), -1 < _DAT_4008505c << 0xb)))) {
      write_volatile_4(RAC_CMD,1);
      _DAT_40085064 = 0x700000;
      if (((int)(param_1 << 10) < 0) && ((_DAT_40085054 & 0xf000000) != 0)) {
        _DAT_40085054 = _DAT_40085054 - 0x1000000;
      }
      param_1 = param_1 & 0xff9fffff | 0x100000;
      PTI_AuxdataOutput(0x2c);
    }
  }
  CORE_ExitAtomic(uVar3);
  return param_1;
}


