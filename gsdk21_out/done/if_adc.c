#include "if_adc.h"



void IF_ADC_Calibrate(void)

{
  int32_t i;
  uint32_t tune;
  
  BUS_RegMaskedSet(&RAC->RFENCTRL,RAC_RFENCTRL_ENLDOCLK_Msk | RAC_RFENCTRL_IFADCCLKEN_Msk | RAC_RFENCTRL_IFADCEN_Msk);//0x8050);
  BUS_RegMaskedSet(&RAC->IFADCCTRL,RAC_IFADCCTRL_ENABLECLK_Msk);
  RAC->IFADCCAL = RAC_IFADCCAL_CALEN_Msk;
  PROTIMER_DelayUs(100);
  RAC->RCTUNE = 0;
  tune = 0x200020;
  for (i = 6; i != 0; i--)
  {
    BUS_RegMaskedSet(&RAC->RCTUNE,tune);
    PROTIMER_DelayUs(100);
    if (!(RAC->IFADCCAL & RAC_IFADCCAL_RCCALOUT_Msk)) BUS_RegMaskedClear(&RAC->RCTUNE,tune);
    tune >>= 1;
  } 
  RAC->RCTUNE = RAC->RCTUNE + 0x10004;
  RAC->IFADCCAL = 0;
  BUS_RegMaskedClear(&RAC->IFADCCTRL,RAC_IFADCCTRL_ENABLECLK_Msk);
  BUS_RegMaskedClear(&RAC->RFENCTRL,RAC_RFENCTRL_ENLDOCLK_Msk | RAC_RFENCTRL_IFADCCLKEN_Msk | RAC_RFENCTRL_IFADCEN_Msk);
}


