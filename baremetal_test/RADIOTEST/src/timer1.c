#include "timer1.h"
#include "em_timer.h"
#include "em_adc.h"

void initTimer1(uint32_t freq)
{
  // Enable clock for TIMER0 module
  CMU_ClockEnable(cmuClock_TIMER1, true);
  // Set Top value
  // Note each overflow event constitutes 1/2 the signal period
  uint32_t topValue = CMU_ClockFreqGet(cmuClock_HFPER) / (freq * (1 << TIMER1_PRESCALE))-1;
  TIMER_TopSet(TIMER1, topValue);
  // Initialize and start timer with defined prescale
  TIMER_Init_TypeDef timerInit = TIMER_INIT_DEFAULT;
  timerInit.prescale = TIMER1_PRESCALE;
  TIMER_Init(TIMER1, &timerInit);
  TIMER_IntEnable(TIMER1, TIMER_IEN_OF);
	NVIC_ClearPendingIRQ(TIMER1_IRQn);
  NVIC_EnableIRQ(TIMER1_IRQn);
  TIMER_Enable(TIMER1, true);
}


void startTimer1(void)
{
  TIMER_Enable(TIMER1, true);
}

void stopTimer1(void)
{
  TIMER_Enable(TIMER1, false);
}

void TIMER1_IRQHandler(void)
{
  // Acknowledge the interrupt
  uint32_t flags = TIMER_IntGet(TIMER1);
  TIMER_IntClear(TIMER1, flags);
	//kick ADC again
  if(micadc == true) ADC_Start(ADC0, adcStartSingle);
}