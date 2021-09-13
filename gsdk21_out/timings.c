#include "timings.h"



int TIMING_PreambleSyncBits(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = read_volatile_4(Peripherals::MODEM.PRE);
  uVar3 = ((uVar3 << 0x1a) >> 0x1e) * (uVar3 >> 0x10) + (uVar3 >> 0x10);
  if (uVar3 < 0x2711) {
    uVar1 = read_volatile_4(Peripherals::MODEM.CTRL1);
    iVar2 = (uVar1 & 0x1f) + 1 + uVar3;
  }
  else {
    iVar2 = -1;
  }
  return iVar2;
}



undefined4 TIMING_CalcAdjustUs(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = RADIO_ComputeTxBitRate();
  return (int)((ulonglong)((param_1 + param_2) * 100000 + uVar1 / 0x14) / ((ulonglong)uVar1 / 10));
}



void TIMING_SeqTimingInit(void)

{
  return;
}



int TIMING_NsToStimerTickCalcSigned(uint param_1)

{
  uint uVar1;
  
  uVar1 = (uint)((ulonglong)param_1 * (ulonglong)nsToStimerRatio);
  return (uVar1 + 0x1000000 >> 0x19 |
         (nsToStimerRatio * ((int)param_1 >> 0x1f) +
          (int)((ulonglong)param_1 * (ulonglong)nsToStimerRatio >> 0x20) +
         (uint)(0xfeffffff < uVar1)) * 0x80) - 0x80;
}



uint TIMING_NsToStimerTickCalc(void)

{
  uint uVar1;
  
  uVar1 = TIMING_NsToStimerTickCalcSigned();
  return uVar1 & ~((int)uVar1 >> 0x1f);
}



void TIMING_InitStimer(void)

{
  uint uVar1;
  int iVar2;
  undefined4 in_r3;
  
  write_volatile_4(Peripherals::RAC.PRESC,7);
  uVar1 = RADIOCMU_ClockFreqGet(0x75160);
  nsToStimerRatio = __aeabi_uldivmod(4000000,uVar1 / 1000,8000000,0,in_r3);
  iVar2 = TIMING_NsToStimerTickCalc(60000);
  write_volatile_4(Peripherals::SEQ.REG0B0,-iVar2);
  return;
}



void TIMING_TxWarmTimeRecalculate(int param_1)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = *(ushort *)(param_1 + 0x16);
  iVar2 = PA_GetRampTime();
  uVar3 = TIMING_NsToStimerTickCalc(((uint)uVar1 - iVar2) * 1000 + (-0x9c4 - *(int *)(param_1 + 8)))
  ;
  write_volatile_4(Peripherals::SEQ.REG0A0,uVar3);
  return;
}



uint TIMING_TxWarmTimeSet(int param_1,uint param_2)

{
  if (param_2 < 100) {
    param_2 = 100;
  }
  else {
    if (12999 < param_2) {
      param_2 = 13000;
    }
  }
  *(short *)(param_1 + 0x16) = (short)param_2;
  return param_2;
}



undefined2 TIMING_TxWarmTimeGet(int param_1)

{
  return *(undefined2 *)(param_1 + 0x16);
}



void TIMING_RxToTxTimeRecalculate(int param_1)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = *(ushort *)(param_1 + 0x12);
  iVar2 = PA_GetRampTime();
  uVar3 = TIMING_NsToStimerTickCalc(((uint)uVar1 - iVar2) * 1000 + (-0x9c4 - *(int *)(param_1 + 8)))
  ;
  write_volatile_4(Peripherals::SEQ.REG098,uVar3);
  return;
}



uint TIMING_RxToTxTimeSet(int param_1,uint param_2)

{
  if (param_2 < 100) {
    param_2 = 100;
  }
  else {
    if (12999 < param_2) {
      param_2 = 13000;
    }
  }
  *(short *)(param_1 + 0x12) = (short)param_2;
  return param_2;
}



void TIMING_RxFrameToTxTimeRecalculate(int param_1)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = *(ushort *)(param_1 + 0x14);
  iVar2 = PA_GetRampTime();
  uVar3 = TIMING_NsToStimerTickCalcSigned
                    ((((uint)uVar1 - iVar2) * 1000 + (-0x9c4 - *(int *)(param_1 + 8))) -
                     *(int *)(param_1 + 4));
  write_volatile_4(Peripherals::SEQ.REG09C,uVar3);
  return;
}



uint TIMING_RxFrameToTxTimeSet(int param_1,uint param_2)

{
  if (param_2 < 100) {
    param_2 = 100;
  }
  else {
    if (12999 < param_2) {
      param_2 = 13000;
    }
  }
  *(short *)(param_1 + 0x14) = (short)param_2;
  return param_2;
}



void TIMING_TxToTxTimeRecalculate(int param_1)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = *(ushort *)(param_1 + 0x1a);
  iVar2 = PA_GetRampTime();
  uVar3 = TIMING_NsToStimerTickCalc(((uint)uVar1 - iVar2) * 1000 + -0x9c4);
  write_volatile_4(Peripherals::SEQ.REG0AC,uVar3);
  return;
}



void TIMING_TxToTxTimeSet(int param_1,uint param_2)

{
  undefined2 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = PA_GetRampTime();
  uVar3 = param_2;
  if (12999 < param_2) {
    uVar3 = 13000;
  }
  if (uVar3 < uVar2) {
    uVar1 = PA_GetRampTime();
  }
  else {
    uVar1 = (undefined2)param_2;
    if (12999 < param_2) {
      uVar1 = 13000;
    }
  }
  *(undefined2 *)(param_1 + 0x1a) = uVar1;
  return;
}



void TIMING_TxToRxTimeRecalculate(int param_1)

{
  uint uVar1;
  
  uVar1 = TIMING_NsToStimerTickCalc
                    ((uint)*(ushort *)(param_1 + 0x18) * 1000 + *(int *)(param_1 + 8) + -0x20d0);
  write_volatile_4(Peripherals::SEQ.REG0A4,uVar1);
  return;
}



uint TIMING_TxToRxTimeSet(int param_1,uint param_2)

{
  if (param_2 < 100) {
    param_2 = 100;
  }
  else {
    if (12999 < param_2) {
      param_2 = 13000;
    }
  }
  *(short *)(param_1 + 0x18) = (short)param_2;
  return param_2;
}



void TIMING_RxWarmTimeRecalculate(int param_1)

{
  uint uVar1;
  
  uVar1 = TIMING_NsToStimerTickCalc((uint)*(ushort *)(param_1 + 0x10) * 1000 + -0x20d0);
  write_volatile_4(Peripherals::SEQ.REG090,uVar1);
  return;
}



uint TIMING_RxWarmTimeSet(int param_1,uint param_2)

{
  if (param_2 < 100) {
    param_2 = 100;
  }
  else {
    if (12999 < param_2) {
      param_2 = 13000;
    }
  }
  *(short *)(param_1 + 0x10) = (short)param_2;
  return param_2;
}



undefined2 TIMING_RxWarmTimeGet(int param_1)

{
  return *(undefined2 *)(param_1 + 0x10);
}



void TIMING_RxSearchTimeRecalculate(int *param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = (uint)*(ushort *)(param_1 + 3) * 1000;
  if (*(ushort *)(param_1 + 3) != 0) {
    iVar2 = iVar2 + *param_1 + 10000;
  }
  uVar1 = TIMING_NsToStimerTickCalc(iVar2);
  write_volatile_4(Peripherals::SEQ.REG094,uVar1);
  return;
}



uint TIMING_RxSearchTimeSet(int param_1,uint param_2)

{
  if (12999 < param_2) {
    param_2 = 13000;
  }
  *(short *)(param_1 + 0xc) = (short)param_2;
  return param_2;
}



void TIMING_TxToRxSearchTimeRecalculate(int *param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = (uint)*(ushort *)((int)param_1 + 0xe) * 1000;
  if (*(ushort *)((int)param_1 + 0xe) != 0) {
    iVar2 = iVar2 + *param_1 + 10000;
  }
  uVar1 = TIMING_NsToStimerTickCalc(iVar2);
  write_volatile_4(Peripherals::SEQ.REG0A8,uVar1);
  return;
}



uint TIMING_TxToRxSearchTimeSet(int param_1,uint param_2)

{
  if (12999 < param_2) {
    param_2 = 13000;
  }
  *(short *)(param_1 + 0xe) = (short)param_2;
  return param_2;
}



void TIMING_RecalculateAll(int param_1)

{
  if (param_1 != 0) {
    TIMING_RxSearchTimeRecalculate();
    TIMING_TxToRxSearchTimeRecalculate(param_1);
    TIMING_RxWarmTimeRecalculate(param_1);
    TIMING_TxWarmTimeRecalculate(param_1);
    TIMING_RxFrameToTxTimeRecalculate(param_1);
    TIMING_RxToTxTimeRecalculate(param_1);
    TIMING_TxToTxTimeRecalculate(param_1);
    TIMING_TxToRxTimeRecalculate(param_1);
    return;
  }
  return;
}



void TIMING_RecalculatePaRampChanged(int param_1)

{
  if (param_1 != 0) {
    TIMING_TxWarmTimeRecalculate();
    TIMING_RxToTxTimeRecalculate(param_1);
    TIMING_RxFrameToTxTimeRecalculate(param_1);
    TIMING_TxToTxTimeRecalculate(param_1);
    return;
  }
  return;
}



void TIMING_RecalculateViterbiChanged(int param_1)

{
  if (param_1 != 0) {
    TIMING_TxToRxTimeRecalculate();
    TIMING_TxToRxSearchTimeRecalculate(param_1);
    return;
  }
  return;
}



undefined4 TIMING_SetChainDelays(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  param_1[2] = param_3;
  *param_1 = param_2;
  return 0;
}



undefined4 TIMING_SetRxDoneDelay(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 4) = param_2;
  return 0;
}



void TIMING_CalcRxTimeStampUs(int *param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  if (param_3 == (int *)0x0) {
    return;
  }
  bVar1 = *(byte *)(param_3 + 2);
  if (bVar1 == 0) {
    return;
  }
  iVar3 = bVar1 - 1;
  switch(bVar1) {
  case 1:
  case 5:
    *(undefined *)(param_3 + 2) = 4;
  case 4:
    iVar3 = 0;
    break;
  case 3:
    *(undefined *)(param_3 + 2) = 2;
  case 2:
    iVar3 = TIMING_PreambleSyncBits();
    if (iVar3 == -1) {
switchD_000103a6_caseD_7:
      iVar3 = 0;
      *(undefined *)(param_3 + 2) = 0;
    }
    else {
      iVar3 = TIMING_CalcAdjustUs(iVar3,0);
      iVar3 = -iVar3;
    }
    break;
  case 6:
    iVar3 = 7;
    *(undefined *)(param_3 + 2) = 7;
  case 7:
    iVar3 = TIMING_CalcAdjustUs(0,param_3[1] << 3,param_3,iVar3,param_4);
    break;
  default:
    goto switchD_000103a6_caseD_7;
  }
  if (*(char *)(param_3 + 2) != '\0') {
    iVar2 = PROTIMER_PrecntOverflowToUs(param_2,0);
    *param_3 = iVar2 + (iVar3 - (*param_1 + 500U) / 1000);
  }
  return;
}



void TIMING_CalcTxTimeStampUs(int param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_3 == (int *)0x0) {
    return;
  }
  switch(*(undefined *)(param_3 + 2)) {
  case 1:
  case 7:
    *(undefined *)(param_3 + 2) = 6;
  case 6:
    iVar2 = 0;
    goto LAB_00010458;
  case 2:
    *(undefined *)(param_3 + 2) = 3;
switchD_0001041e_caseD_3:
    iVar2 = TIMING_PreambleSyncBits();
    if (iVar2 == -1) {
switchD_0001041e_caseD_7:
      iVar2 = 0;
      *(undefined *)(param_3 + 2) = 0;
    }
    else {
      iVar1 = param_3[1];
LAB_00010448:
      iVar2 = TIMING_CalcAdjustUs(iVar2,iVar1 << 3);
      iVar2 = -iVar2;
    }
LAB_00010458:
    if (*(char *)(param_3 + 2) != '\0') {
      iVar1 = PROTIMER_PrecntOverflowToUs(param_2,0);
      *param_3 = iVar1 + iVar2 + (*(int *)(param_1 + 8) + 500U) / 1000;
    }
    return;
  case 3:
    goto switchD_0001041e_caseD_3;
  case 4:
    *(undefined *)(param_3 + 2) = 5;
  case 5:
    iVar1 = param_3[1];
    iVar2 = 0;
    goto LAB_00010448;
  default:
    return;
  case 0xbad1abe1:
    goto switchD_0001041e_caseD_7;
  }
}


