#ifndef _CTUNE_H_
#define _CTUNE_H_

#include "em_device.h"
#include "em_cmu.h"
#include "bsp.h"

void Radio_SetCtune(uint32_t tune);
uint32_t Radio_GetCtune(void);

#endif