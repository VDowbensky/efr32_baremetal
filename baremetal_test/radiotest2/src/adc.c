#include <stdio.h>
#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_adc.h"
#include "em_gpio.h"
#include "em_letimer.h"
#include "adc.h"
#include "leds.h"
#include "tempdrv.h"


  // Declare init structs
  ADC_Init_TypeDef init = ADC_INIT_DEFAULT;
  ADC_InitSingle_TypeDef initSingle = ADC_INITSINGLE_DEFAULT;

volatile int32_t sample;

volatile uint8_t ADCphase = 0;

volatile float Temp = -100.0;
volatile float Vcc;
volatile float Dvdd;
volatile float V_hall;
//volatile float V_exthall;

void switch_to_temp(void);
void switch_to_VCC(void);
void switch_to_DVDD(void);
//void switch_to_hall(void);

volatile uint32_t blinkcnt = 0;

//void switch_to_exthall(void);

/**************************************************************************//**
 * @brief LETIMER initialization
 *****************************************************************************/
void initLETIMER(void)
{
  LETIMER_Init_TypeDef letimerInit = LETIMER_INIT_DEFAULT;

  // Enable clock to the LE modules interface
  CMU_ClockEnable(cmuClock_HFLE, true);

  // Select LFXO for the LETIMER
  CMU_ClockSelectSet(cmuClock_LFA, cmuSelect_LFRCO);
  CMU_ClockEnable(cmuClock_LETIMER0, true);

  // Reload COMP0 on underflow, idle output, and run in repeat mode
  letimerInit.comp0Top  = true;
  letimerInit.ufoa0     = letimerUFOANone;
  letimerInit.repMode   = letimerRepeatFree;

  // Need REP0 != 0 to pulse on underflow
  LETIMER_RepeatSet(LETIMER0, 0, 1);

  // calculate the topValue
  uint32_t topValue = CMU_ClockFreqGet(cmuClock_LETIMER0) / LETIMERDESIRED;

  // Compare on wake-up interval count
  LETIMER_CompareSet(LETIMER0, 0, topValue);

  // Initialize and enable LETIMER
  LETIMER_Init(LETIMER0, &letimerInit);

  // Enable LETIMER0 interrupts for COMP0
  LETIMER_IntEnable(LETIMER0, LETIMER_IEN_COMP0);

  // Enable LETIMER interrupts
  NVIC_ClearPendingIRQ(LETIMER0_IRQn);
  NVIC_EnableIRQ(LETIMER0_IRQn);
}

/**************************************************************************//**
 * @brief ADC initialization
 *****************************************************************************/
void initADC (void)
{
  // Enable clocks required
  CMU_ClockEnable(cmuClock_HFPER, true);
  CMU_ClockEnable(cmuClock_ADC0, true);
  CMU_AUXHFRCOFreqSet(cmuAUXHFRCOFreq_4M0Hz);
  CMU->ADCCTRL = CMU_ADCCTRL_ADC0CLKSEL_AUXHFRCO;
  ADC_Reset(ADC0);
  // Modify init structs
  init.ovsRateSel = adcOvsRateSel2;
  init.em2ClockConfig = adcEm2ClockOnDemand;
//  init.prescale   = ADC_PrescaleCalc(ADCFREQ, 0);
//  init.timebase   = ADC_TimebaseCalc(0);
  init.prescale   = ADC_PrescaleCalc(cmuAUXHFRCOFreq_16M0Hz, CMU_AUXHFRCOBandGet());
  init.timebase   = ADC_TimebaseCalc(CMU_AUXHFRCOBandGet());
  initSingle.diff       = false;       // single ended
  initSingle.reference  = adcRefVDD;   // internal 2.5V reference
  initSingle.resolution = adcRes12Bit; // 12-bit resolution
  initSingle.acqTime    = adcAcqTime4; // set acquisition time to meet minimum requirements
  initSingle.reference = adcRef1V25;
  initSingle.posSel = adcPosSelTEMP;
  initSingle.negSel = adcNegSelVSS;
  // Initialize ADC and Single conversions
  ADCphase = 0;
  ADC_Init(ADC0, &init);
  ADC_InitSingle(ADC0, &initSingle);
  // Enable ADC Single Conversion Complete interrupt
  ADC_IntEnable(ADC0, ADC_IEN_SINGLE);
  // Enable ADC interrupts
  NVIC_ClearPendingIRQ(ADC0_IRQn);
  NVIC_EnableIRQ(ADC0_IRQn);
}

/**************************************************************************//**
 * @brief LETIMER Handler
 *****************************************************************************/
void LETIMER0_IRQHandler(void)
{
  // Clear the interrupt flag
  LETIMER_IntClear(LETIMER0, LETIMER_IFC_COMP0);
  // Start next ADC conversion
  ADC_Start(ADC0, adcStartSingle);
#if LED0
  if(blink == true)
    {
      blinkcnt++;
      //toggle beeper pin
      if (blinkcnt >= blinkduration)
        {
         led0_off();
         blink = false;
        }
    }
#endif
}

/**************************************************************************//**
 * @brief ADC Handler
 *****************************************************************************/
void ADC0_IRQHandler(void)
{
  // Get ADC result
  sample = ADC_DataSingleGet(ADC0);
  switch(ADCphase)
  {
    case 0: //temperature
      {
        static uint32_t ct, cv;
        //uint32_t CAL_TEMP0 = ((DEVINFO->CAL & _DEVINFO_CAL_TEMP_MASK) >> _DEVINFO_CAL_TEMP_SHIFT);
        ct = ((DEVINFO->CAL & _DEVINFO_CAL_TEMP_MASK) >> _DEVINFO_CAL_TEMP_SHIFT);
        //uint32_t CAL_VALUE0 = ((DEVINFO->ADC0CAL3 & _DEVINFO_ADC0CAL3_TEMPREAD1V25_MASK) >> _DEVINFO_ADC0CAL3_TEMPREAD1V25_SHIFT);
        cv = ((DEVINFO->ADC0CAL3 & _DEVINFO_ADC0CAL3_TEMPREAD1V25_MASK) >> _DEVINFO_ADC0CAL3_TEMPREAD1V25_SHIFT);
        if ((ct == 0xFF) || (cv == 0xFFF)) Temp = -273.15f; /* The temperature sensor is not calibrated */
        else
        {
          //compute temperature
          Temp = ((float)cv - sample)*1250.0f;
          Temp /= (4096*TEMP_SLOPE);
          Temp = (float) ct - Temp;
        }
        switch_to_VCC();
        break;
      }

    case 1: //Vcc
      //compute Vcc
      Vcc = (sample*5000.0f)/4096;
      switch_to_DVDD();
      break;

    case 2: //DVDD
		default:
      //compute DVDD voltage
      Dvdd = (sample*5000.0f)/4096;
      switch_to_temp();
      break;
  }
}

void switch_to_temp(void)
{
  NVIC_DisableIRQ(ADC0_IRQn);
  //initSingle = ADC_INITSINGLE_DEFAULT;
  // Set input to temperature sensor. Reference must be 1.25V /
  //initSingle.acqTime = adcAcqTime8; // Minimum time for temperature sensor
  initSingle.reference = adcRef1V25;
  initSingle.posSel = adcPosSelTEMP;
  initSingle.negSel = adcNegSelVSS;
  ADC_InitSingle(ADC0, &initSingle);
  ADCphase = 0;
  NVIC_EnableIRQ(ADC0_IRQn);
}

void switch_to_VCC(void)
{
  NVIC_DisableIRQ(ADC0_IRQn);
  //initSingle.acqTime = adcAcqTime16;
  initSingle.reference = adcRef5VDIFF;
  initSingle.posSel = adcPosSelAVDD;
  initSingle.negSel = adcNegSelVSS;
  ADC_InitSingle(ADC0, &initSingle);
  ADCphase = 1;
  NVIC_EnableIRQ(ADC0_IRQn);
}

void switch_to_DVDD(void)
{
  NVIC_DisableIRQ(ADC0_IRQn);
  //initSingle.acqTime = adcAcqTime16;
  initSingle.reference = adcRef5VDIFF;
  initSingle.posSel = adcPosSelDVDD;
  initSingle.negSel = adcNegSelVSS;
  ADC_InitSingle(ADC0, &initSingle);
  ADCphase = 2;
  NVIC_EnableIRQ(ADC0_IRQn);
}

Ecode_t TEMPDRV_Init(void) //stub
{
	return 0;
}









