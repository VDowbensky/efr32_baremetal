#include "radio_agc.h"

void AGC_IRQHandler(void)
{
	uint32_t flags;
	flags = AGC->IF & AGC->IEN;
	AGC->IFC = flags;
}

void AGC_init(void)
{
  AGC->CTRL0 = 0x000270FE;
  AGC->CTRL1 = 0x00001300;
  AGC->CTRL2 = 0x81D10060;
  AGC->MANGAIN = 0x00000000;
  AGC->GAINRANGE = 0x0000383E;
  AGC->GAININDEX = 0x000025BC;
  AGC->GAINSTEPLIM = 0x00020105;
  AGC->LOOPDEL = 0x00000113;
  AGC->MININDEX	= 0x006D8480;	
}

int16_t AGC_GetRSSI(void)

{
  bool bVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  int16_t result;
  bool bVar6;
  uint32_t uVar5;
  
  do {
    INT_Disable();
    uVar5 = RAC->RXENSRCEN;
    uVar3 = AGC->RSSI;
    uVar2 = RAC->RXENSRCEN;
    bVar6 = (uVar2 & 0xff) == 0;
    bVar1 = (uVar5 & 0xff) == 0;
    //uVar5 = (int32_t)(uVar3 << 0x10) >> 0x16 & 0xffff;
    //uVar5 = (int32_t)(uVar3 & 0x03ff);
		uVar5 = (int32_t)(AGC->RSSI & 0x03ff);
    result = (int16_t)uVar5;
    INT_Enable();
    if (uVar5 != 0xfe00)
    {
      if (bVar6 || bVar1) result = -0x200; //-128 dBm
      break;
    }
  } while (!bVar6 && !bVar1);
  return (int)result;
}