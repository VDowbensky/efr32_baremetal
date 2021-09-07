#include "pti.h"

static uint32_t sniffBaudHz;
static uint8_t sniffMode;

//void RADIO_PTI_Init(byte *param_1)
void RADIO_PTI_Init(RADIO_PTIInit_t *ptiInit)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  
  if (ptiInit == (byte *)0x0) 
  {
    return;
  }
  RADIOCMU_ClockEnable(0x63400,1);
  CMU_ClockEnable(0x82500,1);
  sniffBaudHz = *(undefined4 *)(ptiInit + 4);
  uVar4 = (uint)*ptiInit;
  FRC->SNIFFCTRL = 0xf8;
  FRC->ROUTELOC0 = (uint)ptiInit[0xe] << 0x10 | (uint)ptiInit[0xb] << 8 | (uint)ptiInit[8];
  if (uVar4 == 0) 
  {
    sniffMode = 2;
    FRC->ROUTEPEN = 7;
    GPIO_PinModeSet(ptiInit[0xc],ptiInit[0xd],4,0);
    bVar1 = ptiInit[0xf];
    bVar2 = ptiInit[0x10];
    uVar3 = uVar4;
  }
  else 
  {
    if (uVar4 != 1) 
	{
      if (uVar4 == 2) 
	  {
        sniffMode = 5;
        FRC->ROUTEPEN = 1;
      }
      else 
	  {
        if (uVar4 == 3) 
		{
          FRC->ROUTEPEN = 0;
          sniffMode = 0;
          return;
        }
      }
      goto LAB_00010090;
    }
    bVar1 = ptiInit[0xf];
    FRC->ROUTEPEN = 5;
    bVar2 = ptiInit[0x10];
    uVar3 = 0;
    sniffMode = uVar4;
  }
  GPIO_PinModeSet(bVar1,bVar2,4,uVar3);
LAB_00010090:
  GPIO_PinModeSet(ptiInit[9],ptiInit[10],4,1);
}



void RADIO_PTI_Enable(void)

{
  int iVar2;
  uint uVar3;
  
  uVar3 = sniffBaudHz;
  if (sniffBaudHz != 0) 
  {
    iVar2 = RADIOCMU_ClockFreqGet(0x63400);
    uVar3 = ((iVar2 + (sniffBaudHz >> 1)) / sniffBaudHz - 1) * 0x100;
  }
  BUS_RegMaskedSet(&RAC->SR3,0x40000000);
  FRC->SNIFFCTRL &= 0xffff00fc ;
  FRC->SNIFFCTRL |= uVar3 | sniffMode;
}



void RADIO_PTI_Disable(void)

{
  FRC->SNIFFCTRL &= 0xfffffffc;
  BUS_RegMaskedClear(&RAC->SR3,0x40000000);
}



void RADIO_PTI_AppendedInfoEnable(void)

{
  BUS_RegMaskedSet(&RAC->SR3,0x40000000);
}



void RADIO_PTI_AppendedInfoDisable(void)

{
  BUS_RegMaskedClear(&RAC->SR3,0x40000000);
}



void RADIO_PTI_AuxdataOutput(uint16_t data)

{
  FRC *pFVar1;
  bool bVar2;
  
  pFVar1 = (FRC *)RAC->SR3;
  bVar2 = (int)pFVar1 < 0;
  if (bVar2) 
  {
    pFVar1 = &FRC;
  }
  if (bVar2) 
  {
    pFVar1->AUXDATA = (uint)data;
  }
}



void RADIO_PTI_AuxdataEnable(void)

{
  BUS_RegMaskedSet(&RAC->SR3,0x80000000);
}



void RADIO_PTI_AuxdataDisable(void)

{
  BUS_RegMaskedClear(&RAC->SR3,0x80000000);
}


