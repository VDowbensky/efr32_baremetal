#ifndef _RAIL_DIAG_H_
#define _RAIL_DIAG_H_

RAIL_BerConfig_t *berConfigGlobal;

void RAIL_BerRxStop(void);
void RAIL_BerConfigSet(RAIL_BerConfig_t *berConfig);
void RAIL_BerRxStart(void);
void RAIL_BerStatusGet(RAIL_BerStatus_t *status);

#endif
