#ifndef _PIRADC_H_
#define _PIRADC_H_
#include "bsp.h"
#include "app_cli.h"

#define PIR_DEBUG 1
//#define PIR_DEBUG 0

// Init to max ADC clock for Series 1
#define ADCFREQ         16000000

#define TEMP_SLOPE -1.835f

#define PIR_P_TRESHOLD 100L
#define PIR_N_TRESHOLD -100L

//#define ADC_INPUT_POS adcPosSelAPORT2XCH9
#define ADC_INPUT_POS adcPosSelAPORT4XCH9 //main channel
#define ADC_REF_INPUT_POS adcPosSelAPORT3XCH8 //reference channel
#define ADCBUFFERSIZE 256
// Desired letimer interrupt frequency (in Hz)
#define LETIMERDESIRED  2000

extern volatile int32_t adcbuffer[ADCBUFFERSIZE];
void initLETIMER(void);
void initADC (void);
extern volatile float Temp;
extern volatile float Vcc;
extern volatile float Vref;
extern volatile float Dvdd;
extern volatile bool PIR_on;
extern volatile uint16_t PIRcount;
extern bool beeper;
#endif
