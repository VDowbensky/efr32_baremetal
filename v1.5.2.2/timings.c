#include "rxchaindelay.h"



bool TIMING_SeqTimingInit(bool init)

{
  return init;
}


uint32_t TIMING_NsToStimerTickCalc(uint32_t ns)

{
  uint uVar1;
  
  if ((0 < (int)ns) && (uVar1 = (uint)((ulonglong)ns * (ulonglong)nsToStimerRatio), uVar1 = uVar1 + 0x1000000 >> 0x19 | (nsToStimerRatio * ((int)ns >> 0x1f) +
              (int)((ulonglong)ns * (ulonglong)nsToStimerRatio >> 0x20) + (uint)(0xfeffffff < uVar1)) * 0x80, 0x80 < uVar1)) return uVar1 - 0x80;
  else  return 0;
}




void TIMING_InitStimer(void)

{
  undefined4 in_r3;
  
  RAC->PRESC = 7;
  nsToStimerRatio = __aeabi_uldivmod(4000000,RADIOCMU_ClockFreqGet(0x75160) / 1000,8000000,0,in_r3);
  SEQ->REG0B8 = -(TIMING_NsToStimerTickCalc(60000));
}



void TIMING_TxWarmTimeRecalculate(void)

{
  SEQ->REG0A8 = TIMING_NsToStimerTickCalc((txwarmtime - PA_RampTimeGet()) * 1000);
}



uint16_t TIMING_TxWarmTimeSet(uint16_t time)

{
  if (time < 100) txwarmtime = 100;
  else 
  {
    txwarmtime = time;
    if (12999 < time) txwarmtime = 13000;
  }
  TIMING_TxWarmTimeRecalculate();
  return txwarmtime;
}



uint16_t TIMING_TxWarmTimeGet(void)

{
  return txwarmtime;
}



void TIMING_RxToTxTimeRecalculate(void)

{
  SEQ->REG0A0 = TIMING_NsToStimerTickCalc((txtorxtime - PA_RampTimeGet()) * 1000);
}



uint16_t TIMING_RxToTxTimeSet(uint16_t time)

{
  if (time < 100) txtorxtime = 100;
  else 
  {
    if (12999 < time) time = 13000;
    txtorxtime = (uint16_t)time;
  }
  TIMING_RxToTxTimeRecalculate();
  return txtorxtime;
}



void TIMING_RxFrameToTxTimeRecalculate(void)

{
  SEQ->REG0A4 = TIMING_NsToStimerTickCalc((rxframetotxtime - PA_RampTimeGet()) * 1000 - rxchaindelay);
}


uint16_t TIMING_RxFrameToTxTimeSet(uint16_t time)

{
  if (time < 100) rxframetotxtime = 100;
  else 
  {
    rxframetotxtime = time;
    if (12999 < time) rxframetotxtime = 13000;
  }
  TIMING_RxFrameToTxTimeRecalculate();
  return (uint16_t)rxframetotxtime;
}



void TIMING_TxToTxTimeRecalculate(void)

{
  SEQ->REG0B4 = TIMING_NsToStimerTickCalc((txtotxtime - PA_RampTimeGet()) * 1000 - txchaindelay);
}



uint16_t TIMING_TxToTxTimeSet(uint16_t time)

{
  uint32_t uVar1;
  uint uVar2;
  
  uVar1 = PA_RampTimeGet();
  uVar2 = time;
  if (12999 < time) uVar2 = 13000;
  if (uVar2 < uVar1) 
  {
    uVar1 = PA_RampTimeGet();
    time = uVar1 & 0xffff;
  }
  else 
  {
    if (12999 < time) time = 13000;
  }
  txtotxtime = time;
  TIMING_TxToTxTimeRecalculate();
  return txtotxtime;
}



void TIMING_TxToRxTimeRecalculate(void)

{
  SEQ->REG0AC = TIMING_NsToStimerTickCalc((uint)txtorxtime * 1000 + (-4000 - txchaindelay));
}


uint16_t TIMING_TxToRxTimeSet(uint16_t time)

{
  uint16_t uVar1;
  
  if (time < 100) txtorxtime = 100;
  else 
  {
    txtorxtime = time;
    if (12999 < time) txtorxtime = 13000;
  }
  uVar1 = txtorxtime;
  TIMING_TxToRxTimeRecalculate();
  return uVar1;
}



void TIMING_RxWarmTimeRecalculate(void)

{
  SEQ->REG098 = TIMING_NsToStimerTickCalc((uint)rxwarmtime * 1000 + -4000);
}




uint16_t TIMING_RxWarmTimeSet(uint16_t time)

{
  uint16_t uVar1;
  
  if (time < 100) rxwarmtime = 100;
  else 
  {
    rxwarmtime = time;
    if (12999 < time) rxwarmtime = 13000;
  }
  uVar1 = rxwarmtime;
  TIMING_RxWarmTimeRecalculate();
  return uVar1;
}



uint16_t TIMING_RxWarmTimeGet(void)

{
  return rxwarmtime;
}


uint32_t TIMING_RxSearchTimeSet(uint16_t time)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 13000;
  if (time < 0x32c9) uVar2 = time;
  SEQ->REG09C = TIMING_NsToStimerTickCalc(uVar2 * 1000);
  return uVar2;
}



uint32_t TIMING_RxSearchTimeGet(void)

{
  return SEQ->REG09C;
}



uint32_t TIMING_TxToRxSearchTimeSet(uint16_t time)

{
  uint uVar2;
  
  uVar2 = 13000;
  if (time < 0x32c9) uVar2 = time;
  SEQ->REG0B0 = TIMING_NsToStimerTickCalc(uVar2 * 1000);
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
}


uint32_t TIMING_SetChainDelays(uint32_t rxdelay,uint32_t txdelay)

{
  rxchaindelay = rxdelay;
  txchaindelay = txdelay;
  TIMING_RecalculateAll();
  return 0;
}



uint64_t TIMING_GetRxTimestampUs(uint32_t cnt)

{
  uint64_t uVar1;
  
  uVar1 = PROTIMER_PrecntOverflowToUs(cnt);
  return uVar1 & 0xffffffff00000000 | (uint64_t)((int)uVar1 - (rxchaindelay + 500U) / 1000);
}



uint64_t TIMING_GetTxTimestampUs(uint32_t cnt)

{
  uint64_t uVar1;
  
  uVar1 = PROTIMER_PrecntOverflowToUs(cnt);
  return uVar1 & 0xffffffff00000000 | (uint64_t)((int)uVar1 - (txchaindelay + 500U) / 1000);
}


