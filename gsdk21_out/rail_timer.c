#include "rail_timer.h"

uint32_t RAIL_GetTime(void)
{
  return RFHAL_GetTime();
}


RAIL_Status_t RAIL_SetTime(uint32_t time)
{
  return RFHAL_SetTime();
}


