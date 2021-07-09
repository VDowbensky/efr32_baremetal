#ifndef _RADIO_PTI_H_
#define _RADIO_PTI_H_

#include "em_device.h"
#include <stdint.h>
#include <stdbool.h>
#include "rail_types.h"
#include "pti.h"

void RADIO_PTI_Init(RADIO_PTIInit_t *ptiInit);
void RADIO_PTI_AppendedInfoEnable(void);
void RADIO_PTI_Enable(void);
void RADIO_PTI_AppendedInfoDisable(void);
void RADIO_PTI_Disable(void);
void RADIO_PTI_AuxdataOutput(uint32_t data);
void RADIO_PTI_AuxdataEnable(void);
void RADIO_PTI_AuxdataDisable(void);


#endif
