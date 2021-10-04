#include "timings.h"



bool TIMING_SeqTimingInit(bool init)

{
  return init;
}


uint32_t TIMING_NsToStimerTickCalc(uint32_t ns)

{
  uint uVar1;
  
  if ((0 < (int)ns) &&
     (uVar1 = (uint)((ulonglong)ns * (ulonglong)nsToStimerRatio),
     uVar1 = uVar1 + 0x1000000 >> 0x19 |
             (nsToStimerRatio * ((int)ns >> 0x1f) +
              (int)((ulonglong)ns * (ulonglong)nsToStimerRatio >> 0x20) + (uint)(0xfeffffff < uVar1)
             ) * 0x80, 0x80 < uVar1)) {
    return uVar1 - 0x80;
  }
  return 0;
}




void TIMING_InitStimer(void)

{
  uint uVar1;
  int iVar2;
  undefined4 in_r3;
  
  write_volatile_4(RAC->PRESC,7);
  uVar1 = RADIOCMU_ClockFreqGet(0x75160);
  nsToStimerRatio = __aeabi_uldivmod(4000000,uVar1 / 1000,8000000,0,in_r3);
  iVar2 = TIMING_NsToStimerTickCalc(60000);
  write_volatile_4(SEQ->REG0B8,-iVar2);
  return;
}



void TIMING_TxWarmTimeRecalculate(void)

{
  uint32_t uVar1;
  uint uVar2;
  
  uVar2 = (uint)DAT_20002de6;
  uVar1 = PA_RampTimeGet();
  uVar2 = TIMING_NsToStimerTickCalc((uVar2 - uVar1) * 1000);
  write_volatile_4(SEQ->REG0A8,uVar2);
  return;
}



uint16_t TIMING_TxWarmTimeSet(uint16_t time)

{
  if (tme < 100) {
    DAT_20002de6 = 100;
  }
  else {
    DAT_20002de6 = time;
    if (12999 < time) {
      DAT_20002de6 = 13000;
    }
  }
  TIMING_TxWarmTimeRecalculate();
  return DAT_20002de6;
}



uint16_t TIMING_TxWarmTimeGet(void)

{
  return DAT_20002de6;
}



void TIMING_RxToTxTimeRecalculate(void)

{
  uint32_t uVar1;
  uint uVar2;
  
  uVar2 = (uint)DAT_20002de2;
  uVar1 = PA_RampTimeGet();
  uVar2 = TIMING_NsToStimerTickCalc((uVar2 - uVar1) * 1000);
  write_volatile_4(SEQ->REG0A0,uVar2);
  return;
}



uint16_t TIMING_RxToTxTimeSet(uint16_t time)

{
  if (time < 100) {
    DAT_20002de2 = 100;
  }
  else {
    if (12999 < time) {
      time = 13000;
    }
    DAT_20002de2 = (uint16_t)time;
  }
  TIMING_RxToTxTimeRecalculate();
  return DAT_20002de2;
}



void TIMING_RxFrameToTxTimeRecalculate(void)

{
  uint32_t uVar1;
  uint uVar2;
  
  uVar2 = (uint)DAT_20002de4;
  uVar1 = PA_RampTimeGet();
  uVar2 = TIMING_NsToStimerTickCalc((uVar2 - uVar1) * 1000 - timings);
  write_volatile_4(SEQ->REG0A4,uVar2);
  return;
}


uint16_t TIMING_RxFrameToTxTimeSet(uint16_t time)

{
  if (time < 100) {
    DAT_20002de4 = 100;
  }
  else {
    DAT_20002de4 = time;
    if (12999 < time) {
      DAT_20002de4 = 13000;
    }
  }
  TIMING_RxFrameToTxTimeRecalculate();
  return (uint16_t)DAT_20002de4;
}



void TIMING_TxToTxTimeRecalculate(void)

{
  uint32_t uVar1;
  uint uVar2;
  
  uVar2 = (uint)DAT_20002dea;
  uVar1 = PA_RampTimeGet();
  uVar2 = TIMING_NsToStimerTickCalc((uVar2 - uVar1) * 1000 - DAT_20002ddc);
  write_volatile_4(SEQ->REG0B4,uVar2);
  return;
}



uint16_t TIMING_TxToTxTimeSet(uint16_t time)

{
  uint32_t uVar1;
  uint uVar2;
  
  uVar1 = PA_RampTimeGet();
  uVar2 = time;
  if (12999 < time) {
    uVar2 = 13000;
  }
  if (uVar2 < uVar1) {
    uVar1 = PA_RampTimeGet();
    time = uVar1 & 0xffff;
  }
  else {
    if (12999 < time) {
      time = 13000;
    }
  }
  DAT_20002dea = time;
  TIMING_TxToTxTimeRecalculate();
  return DAT_20002dea;
}



void TIMING_TxToRxTimeRecalculate(void)

{
  uint uVar1;
  
  uVar1 = TIMING_NsToStimerTickCalc((uint)DAT_20002de8 * 1000 + (-4000 - DAT_20002ddc));
  write_volatile_4(SEQ->REG0AC,uVar1);
  return;
}


uint16_t TIMING_TxToRxTimeSet(uint16_t time)

{
  uint16_t uVar1;
  
  if (time < 100) {
    DAT_20002de8 = 100;
  }
  else {
    DAT_20002de8 = time;
    if (12999 < time) {
      DAT_20002de8 = 13000;
    }
  }
  uVar1 = DAT_20002de8;
  TIMING_TxToRxTimeRecalculate();
  return uVar1;
}



void TIMING_RxWarmTimeRecalculate(void)

{
  uint uVar1;
  
  uVar1 = TIMING_NsToStimerTickCalc((uint)DAT_20002de0 * 1000 + -4000);
  write_volatile_4(SEQ->REG098,uVar1);
  return;
}




uint16_t TIMING_RxWarmTimeSet(uint16_t time)

{
  uint16_t uVar1;
  
  if (time < 100) {
    DAT_20002de0 = 100;
  }
  else {
    DAT_20002de0 = time;
    if (12999 < time) {
      DAT_20002de0 = 13000;
    }
  }
  uVar1 = DAT_20002de0;
  TIMING_RxWarmTimeRecalculate();
  return uVar1;
}



uint16_t TIMING_RxWarmTimeGet(void)

{
  return DAT_20002de0;
}


uint32_t TIMING_RxSearchTimeSet(uint16_t time)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 13000;
  if (time < 0x32c9) {
    uVar2 = time;
  }
  uVar1 = TIMING_NsToStimerTickCalc(uVar2 * 1000);
  write_volatile_4(SEQ->REG09C,uVar1);
  return uVar2;
}



uint32_t TIMING_RxSearchTimeGet(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::SEQ.REG09C);
  return uVar1;
}



uint32_t TIMING_TxToRxSearchTimeSet(uint16_t time)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 13000;
  if (time < 0x32c9) {
    uVar2 = time;
  }
  uVar1 = TIMING_NsToStimerTickCalc(uVar2 * 1000);
  write_volatile_4(SEQ->REG0B0,uVar1);
  return uVar2;
}



void TIMING_RecalculateAll(void)

{
  TIMING_RxWarmTimeRecalculate();
  TIMING_TxWarmTimeRecalculate();
  TIMING_RxFrameToTxTimeRecalculate();
  TIMING_RxToTxTimeRecalculate();
  TIMING_TxToTxTimeRecalculate();
  TIMING_TxToRxTimeRecalculate();
  return;
}


uint32_t TIMING_SetChainDelays(uint32_t param_1,uint32_t param_2)

{
  timings = param_1;
  DAT_20002ddc = param_2;
  TIMING_RecalculateAll();
  return 0;
}



uint64_t TIMING_GetRxTimestampUs(uint32_t cnt)

{
  uint64_t uVar1;
  
  uVar1 = PROTIMER_PrecntOverflowToUs(cnt);
  return uVar1 & 0xffffffff00000000 | (uint64_t)((int)uVar1 - (timings + 500U) / 1000);
}



uint64_t TIMING_GetTxTimestampUs(uint32_t cnt)

{
  uint64_t uVar1;
  
  uVar1 = PROTIMER_PrecntOverflowToUs(cnt);
  return uVar1 & 0xffffffff00000000 | (uint64_t)((int)uVar1 - (DAT_20002ddc + 500U) / 1000);
}


