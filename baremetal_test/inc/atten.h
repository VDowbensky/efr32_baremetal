#ifndef _ATTEN_H_
#define _ATTEN_H_



#include "stdint.h"
#include "em_usart.h"
#include "em_gpio.h"
#include "em_cmu.h"
#include "bsp.h"

#define ATT_ADDRESS 0

void init_atten(void);
void setattenuation(uint8_t att);
void setextattenuation(uint8_t att);

extern float i_att;
extern float i_extatt;

#endif



