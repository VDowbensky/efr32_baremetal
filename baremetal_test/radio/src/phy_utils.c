#include "phy_utils.h"
#include <stdbool.h>
#include "em_bus.h"
#include "em_assert.h"

#include "protimer.h"



uint8_t PHY_UTILS_ConvertHexToAscii(uint8_t value)

{
	if ((value & 0xf) < 10) return (value & 0xf) + 0x30;
	else return (value & 0xf) + 0x37;
}



uint32_t PHY_UTILS_CheckParity(uint32_t value)

{
  value = value ^ value >> 0x10;
  value = value ^ value >> 8;
  return 0x6996 >> ((value ^ value >> 4) & 0xf) & 1;
}


void PHY_UTILS_DelayUs(uint32_t us)

{
  bool tmp; 
	
	tmp = PROTIMER_IsRunning();
	if (tmp == false) 
  {
    PROTIMER_Init();
    PROTIMER_Start();
  }
  PROTIMER_DelayUs(us);
  if (tmp == false)
  {
    PROTIMER_Stop();
    PROTIMER_Reset();
    return;
  }
}


