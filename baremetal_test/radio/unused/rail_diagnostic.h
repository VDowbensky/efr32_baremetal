#ifndef _RAIL_DIAGS_H_
#define _RAIL_DIAGS_H_

#include "em_device.h"
#include <stdint.h>
#include <stdbool.h>
#include "rail_types.h"

void RAIL_BerRxStop(void);
void RAIL_BerConfigSet(RAIL_BerConfig_t *berConfig);
void RAIL_BerRxStart(void);
void RAIL_BerStatusGet(RAIL_BerStatus_t *status);

extern RAIL_BerConfig_t berConfigGlobal;

#endif


