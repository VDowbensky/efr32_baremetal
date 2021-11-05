#include "radio_timing.h"

uint32_t rxWarmTimeUs;

void Timing_DelayUs(uint32_t us)

{
  bool tmp; 
	
	tmp = PROTIMER_IsRunning();
	if (tmp == false) 
  {
    PROTIMER_Init();
    PROTIMER_Start();
  }
  PROTIMER_DelayUs(us);
  if (tmp == false)
  {
    PROTIMER_Stop();
    PROTIMER_Reset();
    return;
  }
}

void RADIO_TxWarmTimeSet(uint16_t us)

{
  TX_WARMTIME = RADIO_UsToStimerTickCalc(us - PA_RampTimeGet());
  TX_WARMTIME += (RADIO_UsToStimerTickCalc((us - PA_RampTimeGet()) - 20)) << 16;
}

void RADIO_RxToTxTimeSet(uint16_t us)

{
  RX_TX_TIME  = RADIO_UsToStimerTickCalc(us - PA_RampTimeGet());
  RX_TX_TIME  += (RADIO_UsToStimerTickCalc((us - PA_RampTimeGet()) - 20)) << 16;
}


void RADIO_RxFrameToTxTimeSet(uint16_t us)

{
  RXFRAME_TX_TIME  = RADIO_UsToStimerTickCalc(us - PA_RampTimeGet());
  RXFRAME_TX_TIME  += (RADIO_UsToStimerTickCalc((us - PA_RampTimeGet()) - 20)) << 16;
}

void RADIO_TxToTxTimeSet(uint16_t us)

{
  TX_TX_TIME  = RADIO_UsToStimerTickCalc(us - PA_RampTimeGet());
  TX_TX_TIME  += (RADIO_UsToStimerTickCalc((us - PA_RampTimeGet()) - 20)) << 16;
}

void RADIO_TxToRxTimeSet(uint16_t us)

{
  TX_RX_TIME  = RADIO_UsToStimerTickCalc(us - 4);
}

void RADIO_RxWarmTimeSet(uint16_t us)

{
  rxWarmTimeUs = us;
  RX_WARMTIME  = RADIO_UsToStimerTickCalc(us - 4);
}

uint16_t RADIO_RxWarmTimeGet(void)

{
  return rxWarmTimeUs;
}


void RADIO_RxSearchTimeSet(uint32_t us)

{
  RX_SEARCHTIME = RADIO_UsToStimerTickCalc(us);
}


void RADIO_TxToRxSearchTimeSet(uint32_t us)

{
  TX_RX_SEARCHTIME = RADIO_UsToStimerTickCalc(us);
}

uint32_t RADIO_UsToStimerTickCalc(uint32_t us)

{
//  uint64_t lVar1;

//  us = us & ~((int)us >> 0x1f);
//  lVar1 = CMU_ClockFreqGet(0x75160) * (uint64_t)us;
  //return ((uint64_t)us * CMU_ClockFreqGet(0x75160))/8000000;
  return ((uint64_t)us * SystemHFClockGet())/8000000;
 // __aeabi_uldivmod((int)lVar1,uVar2 * ((int)us >> 0x1f) + (int)((us)lVar1 >> 0x20),
 //                  8000000,0,param_4);
}