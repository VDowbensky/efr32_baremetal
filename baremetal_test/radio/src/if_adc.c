#include "if_adc.h"
#include <stdbool.h>
#include "em_bus.h"
#include "em_assert.h"
#include "phy_utils.h"



void IF_ADC_Calibrate(void)

{
  int i;
  uint32_t j= 0x200020;
  
	BUS_RegMaskedSet(&RAC->RFENCTRL, RAC_RFENCTRL_ENLDOCLK_Msk | RAC_RFENCTRL_IFADCCLKEN_Msk | RAC_RFENCTRL_IFADCEN_Msk);
	BUS_RegMaskedSet(&RAC->IFADCCTRL, RAC_IFADCCTRL_ENABLECLK_Msk);
  //RAC->IFADCCAL = 0x10; //CALEN
	RAC->IFADCCAL = RAC_IFADCCAL_CALEN_Msk;
  PHY_UTILS_DelayUs(100);
  RAC->RCTUNE = 0;
//  do 
//  {
//    RAC->RCTUNE |= uVar3;
//    PHY_UTILS_DelayUs(100);
//    if(!(RAC->IFADCCAL & 0x20)) RAC->RCTUNE &= ~uVar3;
//    i--;
//    uVar3 >>= 1;
//  } while (i != 0);
	for (i = 6; i != 0; i--)
	{
		RAC->RCTUNE |= j;
    PHY_UTILS_DelayUs(100);
		if(!(RAC->IFADCCAL & RAC_IFADCCAL_RCCALOUT_Msk)) BUS_RegMaskedClear(&RAC->RCTUNE, j);
		j >>= 1;
	}
  RAC->RCTUNE += 0x10004;
  RAC->IFADCCAL = 0;
	BUS_RegMaskedClear(&RAC->IFADCCTRL, RAC_IFADCCTRL_ENABLECLK_Msk);
	BUS_RegMaskedClear(&RAC->RFENCTRL, RAC_RFENCTRL_ENLDOCLK_Msk | RAC_RFENCTRL_IFADCCLKEN_Msk | RAC_RFENCTRL_IFADCEN_Msk);
}


