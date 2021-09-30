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
  berConfigGlobal = berConfig->bytesToTest;
  return;
}



void RAIL_BerRxStart(void)

{
  RAIL_BerRxStop();
  RFHAL_SetBerConfig((RAIL_BerConfig_t *)&berConfigGlobal);
  RFHAL_StartBerRx();
  return;
}



void RAIL_BerStatusGet(RAIL_BerStatus_t *berstatus)

{
  uint32_t in_r1;
  uint32_t in_r2;
  int8_t in_r3;
  RAIL_BerStatus_t RStack24;
  
  RStack24.bitsTotal = (uint32_t)berstatus;
  RStack24.bitsTested = in_r1;
  RStack24.bitErrors = in_r2;
  RStack24.rssi = in_r3;
  RFTEST_ReportBerStats(&RStack24);
  berstatus->bitsTotal = RStack24.bitsTotal;
  berstatus->bitsTested = RStack24.bitsTested;
  berstatus->bitErrors = RStack24.bitErrors;
  berstatus->rssi = RStack24.rssi;
  return;
}



