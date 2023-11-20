#ifndef _PIRADC_H_
#define _PIRADC_H_
#include "bsp.h"
#include "app_cli.h"

// Init to max ADC clock for Series 1
#define ADCFREQ         16000000

#define TEMP_SLOPE -1.835f

// Desired letimer interrupt frequency (in Hz)
#define LETIMERDESIRED  2000

//extern volatile int32_t adcbuffer[ADCBUFFERSIZE];
void initLETIMER(void);
void initADC (void);
extern volatile float Temp;
extern volatile float Vcc;
extern volatile float Dvdd;
//extern volatile float V_hall;
//extern volatile float V_exthall;
#endif
