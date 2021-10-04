#include "rail_diagnostic.h"



void RAIL_BerRxStop(void)

{
  RFHAL_StopBerRx();
  RAIL_RfIdle();
  return;
}



void RAIL_BerConfigSet(RAIL_BerConfig_t *berConfig)

{
  RAIL_BerRxStop();
  RFHAL_SetBerConfig(berConfig);
  berConfigGlobal = *berConfig;
  return;
}



void RAIL_BerRxStart(void)

{
  RAIL_BerRxStop();
  RFHAL_SetBerConfig(&berConfigGlobal);
  RFHAL_StartBerRx();
  return;
}



void RAIL_BerStatusGet(RAIL_BerStatus_t *status)

{
  RFHAL_GetBerStatus(status);
  return;
}


