#include "radio_cmu.h"
#include <stdbool.h>
#include "em_device.h"
#include "em_bus.h"
#include "em_assert.h"
#include "em_cmu.h"

//#include "efr32fg1v_cmu.h"



void RADIOCMU_ClockEnable(CMU_Clock_TypeDef clock, bool enable)

{
   CMU_ClockEnable(clock, enable);
}



uint32_t RADIOCMU_ClockFreqGet(CMU_Clock_TypeDef clock)

{
  uint32_t freq;
  uint32_t presc;
  
  clock = clock & 0x3e0000;
  if (clock == 0x40000)
  {
	  freq = SystemHFClockGet();
	  presc = CMU->HFPERPRESC;
  }
  else
  {
    if (clock < 0x40001)
		{
      if (clock == 0)
      {
				freq = SystemHFClockGet();
				presc = (CMU->HFPRESC >> 8) & 0x1FF;
				return freq / (presc + 1);
      }
      if (clock != 0x20000) return CMU_ClockFreqGet(clock);
      freq = SystemHFClockGet();
      presc = CMU->HFCOREPRESC;
	}
    else 
	{
      if (clock == 0x80000) return SystemHFClockGet();
      if (clock == 0xa0000)
      {
    	  freq = SystemHFClockGet();
    	  presc = (CMU->HFEXPPRESC >> 8) & 0x1FF;
    	  return freq / (presc + 1);
      }
      if (clock != 0x60000) return CMU_ClockFreqGet(clock);
      freq = SystemHFClockGet();
      presc = CMU->HFRADIOPRESC;
    }
  }
  presc = (presc >> 8) & 0x1FF;
  return freq / (presc + 1);
}



uint32_t RADIOCMU_ClockPrescGet(CMU_Clock_TypeDef clock)

{
  if ((uint32_t)(clock << 0x18) >> 0x1c != 6)
  {
    return CMU_ClockPrescGet(clock);
  }
  return (CMU->HFRADIOPRESC >> 8) & 0x1FF;
//  return (uint32_t)(presc << 0xf) >> 0x17;
}



void RADIOCMU_ClockPrescSet(CMU_Clock_TypeDef clock, uint32_t presc)

{
  if ((uint32_t)(clock << 0x18) >> 0x1c == 6)
  {
		CMU->HFRADIOPRESC &= 0xfffe00ff;
		CMU->HFRADIOPRESC |= presc << 8;
    return;
  }
  CMU_ClockPrescSet(clock, presc);
}


