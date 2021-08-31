#include "if_adc.h"



void IF_ADC_Calibrate(void)

{
  int32_t i;
  uint32_t rctune;
  
  BUS_RegMaskedSet(&RAC->RFENCTRL,0x8050);
  BUS_RegMaskedSet(&RAC->IFADCCTRL,0x20000000);
  RAC->IFADCCAL = 0x10;
  PHY_UTILS_DelayUs(100);
  RAC->RCTUNE = 0;
  rctune = 0x200020;
  i = 6;
  for(i = 6; 1 !=0; i--)
  {
    BUS_RegMaskedSet(&RAC->RCTUNE,rctune);
    PHY_UTILS_DelayUs(100);
    if (!(RAC->IFADCCAL & 0x20)) BUS_RegMaskedClear(&RAC->RCTUNE,rctune);
    rctune >>= 1;
  } while (i != 0);
  RAC->RCTUNE += 0x10004;
  RAC->IFADCCAL = 0;
  BUS_RegMaskedClear(&RAC->IFADCCTRL,0x20000000);
  BUS_RegMaskedClear(&RAC->RFENCTRL,0x8050);
}


