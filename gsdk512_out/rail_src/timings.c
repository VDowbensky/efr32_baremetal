#include "timings.h"

//RxChainDelay; //00010358
//nsToStimerRatio; //00010354


uint16_t RxWarmTime;		//DAT_00010360
uint16_t RxToTxTime; 		//DAT_00010362
uint16_t RxFrameToTxTime; 	//DAT_00010364
uint16_t TxWarmTime; 		//DAT_00010366
uint16_t TxToRxTime;		//DAT_00010368
uint16_t TxToTxTime;		//DAT_0001036a
uint32_t TxChainDelay;		//DAT_0001035c

void TIMING_SeqTimingInit(void)

{

}



uint32_t TIMING_NsToStimerTickCalc(uint16_t ns)

{
  uint16_t uVar1;
  
  if ((0 < (int)ns) &&(uVar1 = (uint16_t)((ulonglong)ns * (ulonglong)nsToStimerRatio),uVar1 = uVar1 + 0x1000000 >> 0x19 |
             (nsToStimerRatio * ((int)ns >> 0x1f) + (int)((ulonglong)ns * (ulonglong)nsToStimerRatio >> 0x20) +
             (uint16_t)(0xfeffffff < uVar1)) * 0x80, 0x80 < uVar1))  return uVar1 - 0x80;
}



void TIMING_InitStimer(void)

{
  RAC->PRESC = 7;
  nsToStimerRatio = __aeabi_uldivmod(4000000,RADIOCMU_ClockFreqGet(0x75160) / 1000,8000000,0,in_r3);
  SEQ->REG0B8 = -(TIMING_NsToStimerTickCalc(60000));
}



void TIMING_TxWarmTimeRecalculate(void)

{
  SEQ->REG0A8 = TIMING_NsToStimerTickCalc((TxWarmTime - PA_RampTimeGet()) * 1000);
}



uint16_t TIMING_TxWarmTimeSet(uint16_t time)

{
  if (time < 100) TxWarmTime = 100;
  if (12999 < time) TxWarmTime = 13000;
  TIMING_TxWarmTimeRecalculate();
  return TxWarmTime;
}



uint16_t TIMING_TxWarmTimeGet(void)

{
  return TxWarmTime;
}



void TIMING_RxToTxTimeRecalculate(void)

{
  SEQ->REG0A0 = TIMING_NsToStimerTickCalc((RxToTxTime - PA_RampTimeGet()) * 1000);
}



uint16_t TIMING_RxToTxTimeSet(uint16_t time)

{
  if (time < 100) RxToTxTime = 100;
  if (12999 < time) RxToTxTime = 13000;
  TIMING_RxToTxTimeRecalculate();
  return RxToTxTime;
}



void TIMING_RxFrameToTxTimeRecalculate(void)

{
  SEQ->REG0A4 = TIMING_NsToStimerTickCalc((RxFrameToTxTime - PA_RampTimeGet()) * 1000 - RxChainDelay);
}



uint16_t TIMING_RxFrameToTxTimeSet(uint16_t time)

{
  if (time < 100) RxFrameToTxTime = 100;
  if (12999 < time) RxFrameToTxTime = 13000;
  TIMING_RxFrameToTxTimeRecalculate();
  return RxFrameToTxTime;
}



void TIMING_TxToTxTimeRecalculate(void)

{
  SEQ->REG0B4 = TIMING_NsToStimerTickCalc((TxToTxTime - PA_RampTimeGet()) * 1000 - TxChainDelay);
}



uint16_t TIMING_TxToTxTimeSet(uint16_t time)

{
  if (12999 < time) time = 13000;
  if (time < PA_RampTimeGet()) time = PA_RampTimeGet();
  TxToTxTime = (uint16_t)time;
  TIMING_TxToTxTimeRecalculate();
  return TxToTxTime;
}



void TIMING_TxToRxTimeRecalculate(void)

{
  SEQ->REG0AC = TIMING_NsToStimerTickCalc((uint16_t)TxToRxTime * 1000 + (-4000 - TxChainDelay)));
}



uint16_t TIMING_TxToRxTimeSet(uint16_t time)

{
  if (time < 100) time = 100;
  if (12999 < time) time = 13000;
  TxToRxTime = (uint16_t)time;
  TIMING_TxToRxTimeRecalculate();
  return TxToRxTime;
}



void TIMING_RxWarmTimeRecalculate(void)

{
  SEQ->REG098,TIMING_NsToStimerTickCalc((uint16_t)RxWarmTime * 1000 + -4000);
}



uint16_t TIMING_RxWarmTimeSet(uint16_t time)

{
  if (time < 100) time = 100;
  if (12999 < time) time = 13000;
  RxWarmTime = (uint16_t)time;
  TIMING_RxWarmTimeRecalculate();
  return RxWarmTime;
}



uint16_t TIMING_RxWarmTimeGet(void)

{
  return RxWarmTime;
}



uint16_t TIMING_RxSearchTimeSet(uint16_t time)

{
  if (time > 13000) time = 13000;
  SEQ->REG09C = TIMING_NsToStimerTickCalc(time * 1000);
  return time;
}



uint16_t TIMING_RxSearchTimeGet(void)

{
  return SEQ->REG09C;
}



uint16_t TIMING_TxToRxSearchTimeSet(uint16_t time)

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
  RxChainDelay = rxdelay;
  TxChainDelay = txdelay;
  TIMING_RecalculateAll();
  return 0;
}



int32_t TIMING_GetRxTimestampUs(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  return PROTIMER_PrecntOverflowToUs(param_1,0,param_3,param_4,param_4) - (RxChainDelay + 500U) / 1000;
}



int32_t TIMING_GetTxTimestampUs(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  return PROTIMER_PrecntOverflowToUs(param_1,0,param_3,param_4,param_4) - (TxChainDelay + 500U) / 1000;
}


