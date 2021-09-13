#include "rail_timer.h"



//void RAIL_GetTime(void)
uint32_t RAIL_GetTime(void)
{
  RFHAL_GetTime();
  return;
}



//void RAIL_SetTime(void)
RAIL_Status_t RAIL_SetTime(uint32_t time)
{
  RFHAL_SetTime();
  return;
}


