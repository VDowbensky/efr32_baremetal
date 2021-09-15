#include "rail_pti.h"



//void RAIL_ConfigPti(undefined4 param_1,undefined4 param_2)
RAIL_Status_t RAIL_ConfigPti(RAIL_Handle_t railHandle,
                                RAIL_PtiConfig_t *ptiConfig)
{
  return RFHAL_ConfigPti(&ptiConfig);
}



//void RAIL_GetPtiConfig(undefined4 param_1,undefined4 param_2)
RAIL_Status_t RAIL_GetPtiConfig(RAIL_Handle_t railHandle,
                                RAIL_PtiConfig_t *ptiConfig)
{
  return RFHAL_GetPtiConfig(&ptiConfig);
}



//void RAIL_EnablePti(undefined4 param_1,undefined4 param_2)
RAIL_Status_t RAIL_EnablePti(RAIL_Handle_t railHandle,
                             bool enable)
{
  return RFHAL_EnablePti(enable);
}


