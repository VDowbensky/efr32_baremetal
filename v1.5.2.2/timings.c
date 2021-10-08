#include "rxchaindelay.h"



void TIMING_SeqTimingInit(void)

{

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
  
  RAC->PRESC = 7 << RAC_PRESC_STIMER_Pos;
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
  if(time < 100) time = 100;
  if(time > 13000) time = 13000;
  txtorxtime = time;
  TIMING_RxToTxTimeRecalculate();
  return txtorxtime;
}



void TIMING_RxFrameToTxTimeRecalculate(void)

{
  SEQ->REG0A4 = TIMING_NsToStimerTickCalc((rxframetotxtime - PA_RampTimeGet()) * 1000 - rxchaindelay);
}


uint16_t TIMING_RxFrameToTxTimeSet(uint16_t time)

{
  if(time < 100) time = 100;
  if(time > 13000) time = 13000;
  txtorxtime = time;
  rxframetotxtime = time;
  TIMING_RxFrameToTxTimeRecalculate();
  return (uint16_t)rxframetotxtime;
}



void TIMING_TxToTxTimeRecalculate(void)

{
  SEQ->REG0B4 = TIMING_NsToStimerTickCalc((txtotxtime - PA_RampTimeGet()) * 1000 - txchaindelay);
}



uint16_t TIMING_TxToTxTimeSet(uint16_t time)

{
  if(time < PA_RampTimeGet()) time = PA_RampTimeGet();
  if(time > 13000) time = 13000;
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
  if(time < 100) time = 100;
  if(time > 13000) time = 13000;
  txtorxtime = time;
  TIMING_TxToRxTimeRecalculate();
  return txtorxtime;
}



void TIMING_RxWarmTimeRecalculate(void)

{
  SEQ->REG098 = TIMING_NsToStimerTickCalc((uint)rxwarmtime * 1000 + -4000);
}




uint16_t TIMING_RxWarmTimeSet(uint16_t time)

{
  if(time < 100) time = 100;
  if(time > 13000) time = 13000;
  rxwarmtime = time;
  TIMING_RxWarmTimeRecalculate();
  return rxwarmtime;
}



uint16_t TIMING_RxWarmTimeGet(void)

{
  return rxwarmtime;
}


uint32_t TIMING_RxSearchTimeSet(uint16_t time)

{
  if (time > 13000) time = 13000;
  SEQ->REG09C = TIMING_NsToStimerTickCalc(time * 1000);
  return time;
}



uint32_t TIMING_RxSearchTimeGet(void)

{
  return SEQ->REG09C;
}



uint32_t TIMING_TxToRxSearchTimeSet(uint16_t time)

{
  if (time > 13000) time = 13000;
  SEQ->REG0B0 = TIMING_NsToStimerTickCalc(time * 1000);
  return time;
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
  uint64_t tmp;
  
  tmp = PROTIMER_PrecntOverflowToUs(cnt);
  return tmp & 0xffffffff00000000 | (uint64_t)((int)tmp - (rxchaindelay + 500U) / 1000);
}



uint64_t TIMING_GetTxTimestampUs(uint32_t cnt)

{
  uint64_t tmp;
  
  tmp = PROTIMER_PrecntOverflowToUs(cnt);
  return tmp & 0xffffffff00000000 | (uint64_t)((int)tmp - (txchaindelay + 500U) / 1000);
}


