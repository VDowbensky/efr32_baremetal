#include "rail_filter.h"



//void RAIL_ResetAddressFilter(int param_1)
void RAIL_ResetAddressFilter(RAIL_Handle_t railHandle)
{
  RFHAL_ResetAddressFilter(railHandle + 0xc);
}



//void RAIL_SetAddressFilterAddress(int param_1)
RAIL_Status_t RAIL_SetAddressFilterAddress(RAIL_Handle_t railHandle,
                                           uint8_t field,
                                           uint8_t index,
                                           const uint8_t *value,
                                           bool enable)
{
  return RFHAL_SetAddressFilterAddress(railHandle + 0xc);
}



//void RAIL_EnableAddressFilterAddress(int param_1)
RAIL_Status_t RAIL_EnableAddressFilterAddress(RAIL_Handle_t railHandle,
                                              bool enable,
                                              uint8_t field,
                                              uint8_t index)
{
  return RFHAL_EnableAddressFilterAddress(enable,field,index);
}



//void RAIL_EnableAddressFilter(int param_1)
bool RAIL_EnableAddressFilter(RAIL_Handle_t railHandle, bool enable);
{
  return RFHAL_EnableAddressFilter(enable);
}



//void RAIL_ConfigAddressFilter(int param_1)
RAIL_Status_t RAIL_ConfigAddressFilter(RAIL_Handle_t railHandle,
                                       const RAIL_AddrConfig_t *addrConfig)
{
  return RFHAL_ConfigAddressFilter(&addrConfig);
}



//void RAIL_IsAddressFilterEnabled(int param_1)
bool RAIL_IsAddressFilterEnabled(RAIL_Handle_t railHandle)
{
  return RFHAL_AddressFilterIsEnabled();
}


