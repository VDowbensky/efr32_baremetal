#include "rail_diagnostic.h"

RAIL_BerConfig_t *berConfigGlobal;

void RAIL_BerRxStop(void)

{
  RFHAL_StopBerRx();
  RAIL_RfIdle();
}



void RAIL_BerConfigSet(RAIL_BerConfig_t *berConfig)

{
  RAIL_BerRxStop();
  RFHAL_SetBerConfig(*berConfig);
  berConfigGlobal = berConfig;
}



void RAIL_BerRxStart(void)

{
  RAIL_BerRxStop();
  RFHAL_SetBerConfig(&berConfigGlobal);
  RFHAL_StartBerRx();
}



void RAIL_BerStatusGet(RAIL_BerStatus_t *status)

{
  RFHAL_GetBerStatus(*status);
}


