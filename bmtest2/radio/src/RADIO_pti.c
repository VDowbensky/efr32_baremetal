//#include "RADIO_pti.h"
#include <stdbool.h>
#include <stddef.h>
#include "em_bus.h"
#include "em_assert.h"
#include "radio_cmu.h"
#include "rail_types.h"
#include "pti.h"

uint32_t sniffBaudHz;
uint32_t sniffMode;


void RADIO_PTI_Init(RADIO_PTIInit_t *ptiInit)

{
  if (ptiInit == NULL) return;
  RADIOCMU_ClockEnable(0x63400,1);
  CMU_ClockEnable(0x82500,1);
  sniffBaudHz = ptiInit->baud;
  FRC->SNIFFCTRL = 0xf8;
  FRC->ROUTELOC0 = ptiInit->doutLoc | ptiInit->dclkLoc <<8 | ptiInit->dframeLoc << 0x10;
  if(ptiInit->mode == 0)
  {
    sniffMode = 2;
    FRC->ROUTEPEN = 7;

    GPIO_PinModeSet(ptiInit->dclkPort, ptiInit->dclkPin, gpioModePushPull,0);
  }
  else
  {
    if (ptiInit->mode != 1)
    {
      if (ptiInit->mode == 2)
      {
        sniffMode = 5;
        FRC->ROUTEPEN = 1;
      }
      else
      {
        if (ptiInit->mode == 3)
        {
          FRC->ROUTEPEN = 0;
          sniffMode = 0;
          return;
        }
      }
      GPIO_PinModeSet(ptiInit->doutPort, ptiInit->doutPin, gpioModePushPull,1);
      return;
    }
    FRC->ROUTEPEN = 5;
    sniffMode = ptiInit->mode;
  }
  GPIO_PinModeSet(ptiInit->dframePort, ptiInit->dframePin, gpioModePushPull, 0);
  GPIO_PinModeSet(ptiInit->doutPort, ptiInit->doutPin, gpioModePushPull, 1);
}



void RADIO_PTI_AppendedInfoEnable(void)

{
  RAC->SR3 |= 0x40000000;
}



void RADIO_PTI_Enable(void)

{
  uint32_t t;
  
  if (sniffBaudHz != 0) t = ((RADIOCMU_ClockFreqGet(0x63400) + (sniffBaudHz >> 1)) / sniffBaudHz - 1) * 0x100;
  RADIO_PTI_AppendedInfoEnable();
  FRC->SNIFFCTRL = t | (FRC->SNIFFCTRL & 0xffff00fc) | sniffMode;
}



void RADIO_PTI_AppendedInfoDisable(void)

{
	RAC->SR3 &= 0xbfffffff;
}



void RADIO_PTI_Disable(void)

{
  //FRC->SNIFFCTRL &= 0xfffffffc;
	BUS_RegMaskedClear(&FRC->SNIFFCTRL, FRC_SNIFFCTRL_SNIFFMODE_Msk);
  RADIO_PTI_AppendedInfoDisable();
}



void RADIO_PTI_AuxdataOutput(uint32_t data)

{
  if (RAC->SR3 & 0x80) FRC->AUXDATA = data;
}



void RADIO_PTI_AuxdataEnable(void)

{
	RAC->SR3 |= 0x80000000;
}



void RADIO_PTI_AuxdataDisable(void)

{
	RAC->SR3 &= 0x7fffffff;
}


