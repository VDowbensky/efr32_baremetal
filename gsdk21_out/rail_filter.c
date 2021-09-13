#include "rail_filter.h"



//void RAIL_ResetAddressFilter(int param_1)
void RAIL_ResetAddressFilter(RAIL_Handle_t railHandle)
{
  RFHAL_ResetAddressFilter(param_1 + 0xc);
  return;
}



//void RAIL_SetAddressFilterAddress(int param_1)
RAIL_Status_t RAIL_SetAddressFilterAddress(RAIL_Handle_t railHandle,
                                           uint8_t field,
                                           uint8_t index,
                                           const uint8_t *value,
                                           bool enable)
{
  RFHAL_SetAddressFilterAddress(param_1 + 0xc);
  return;
}



//void RAIL_EnableAddressFilterAddress(int param_1)
RAIL_Status_t RAIL_EnableAddressFilterAddress(RAIL_Handle_t railHandle,
                                              bool enable,
                                              uint8_t field,
                                              uint8_t index)
{
  RFHAL_EnableAddressFilterAddress(param_1 + 0xc);
  return;
}



//void RAIL_EnableAddressFilter(int param_1)
RAIL_Status_t RAIL_EnableAddressFilterAddress(RAIL_Handle_t railHandle,
                                              bool enable,
                                              uint8_t field,
                                              uint8_t index)
{
  RFHAL_EnableAddressFilter(param_1 + 0xc);
  return;
}



void RAIL_ConfigAddressFilter(int param_1)
RAIL_Status_t RAIL_ConfigAddressFilter(RAIL_Handle_t railHandle,
                                       const RAIL_AddrConfig_t *addrConfig)
{
  RFHAL_ConfigAddressFilter(param_1 + 0xc);
  return;
}



//void RAIL_IsAddressFilterEnabled(int param_1)
bool RAIL_IsAddressFilterEnabled(RAIL_Handle_t railHandle)
{
  RFHAL_AddressFilterIsEnabled(param_1 + 0xc);
  return;
}


