#include "pti.h"

static uint32_t sniffBaudHz;
static uint8_t sniffMode;

typedef struct RADIO_PTIInit {
  * Packet Trace mode (UART or SPI)
  RADIO_PTIMode_t mode;
  uint32_t baud;
  uint8_t doutLoc;
  GPIO_Port_TypeDef doutPort;
  uint8_t doutPin;
  uint8_t dclkLoc;
  GPIO_Port_TypeDef dclkPort;
  uint8_t dclkPin;
  uint8_t dframeLoc;
  GPIO_Port_TypeDef dframePort;
  uint8_t dframePin;
} RADIO_PTIInit_t;
typedef enum RADIO_PTIMode
{
  * SPI mode.
  RADIO_PTI_MODE_SPI = 0U,
  * UART mode.
  RADIO_PTI_MODE_UART = 1U,
  * 9bit UART mode.
  RADIO_PTI_MODE_UART_ONEWIRE = 2U,
  RADIO_PTI_MODE_DISABLED = 3U,
} RADIO_PTIMode_t;

void RADIO_PTI_Init(RADIO_PTIInit_t *ptiInit)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  
  if (ptiInit == NULL) return;
  RADIOCMU_ClockEnable(0x63400,1);
  CMU_ClockEnable(0x82500,1);
  sniffBaudHz = *(undefined4 *)(ptiInit + 4);
  uVar4 = ptiInit->mode;
  FRC->SNIFFCTRL = 0xf8;
  FRC->ROUTELOC0 = (uint)ptiInit[0xe] << 0x10 | (uint)ptiInit[0xb] << 8 | (uint)ptiInit[8];
  if (ptiInit->mode == RADIO_PTI_MODE_SPI) 
  {
    sniffMode = 2;
    FRC->ROUTEPEN = FRC_ROUTEPEN_DFRAMEPEN_Msk | FRC_ROUTEPEN_DCLKPEN_Msk | FRC_ROUTEPEN_DOUTPEN_Msk; //7;
    GPIO_PinModeSet(ptiInit[0xc],ptiInit[0xd],4,0);
    bVar1 = ptiInit[0xf];
    bVar2 = ptiInit[0x10];
    uVar3 = uVar4;
  }
  else 
  {
    if (ptiInit->mode != RADIO_PTI_MODE_UART) 
	{
      if (ptiInit->mode == RADIO_PTI_MODE_UART_ONEWIRE) 
	  {
        sniffMode = 5;
        FRC->ROUTEPEN = FRC_ROUTEPEN_DOUTPEN_Msk;
      }
      else 
	  {
        if (ptiInit->mode == RADIO_PTI_MODE_DISABLED) 
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
  uint32_t uVar3;
  
  uVar3 = sniffBaudHz;
  if (sniffBaudHz != 0) uVar3 = ((RADIOCMU_ClockFreqGet(0x63400) + (sniffBaudHz >> 1)) / sniffBaudHz - 1) * 0x100;
  BUS_RegMaskedSet(&RAC->SR3,0x40000000);
  FRC->SNIFFCTRL &= 0xffff00fc ;
  FRC->SNIFFCTRL |= uVar3 | sniffMode;
}



void RADIO_PTI_Disable(void)

{
  FRC->SNIFFCTRL &= ~(FRC_SNIFFCTRL_SNIFFBR_Msk | FRC_SNIFFCTRL_SNIFFMODE_Msk); //0xfffffffc;
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
  if (RAC->SR3 & 0x80000000) FRC->AUXDATA = (uint32_t)data;
}



void RADIO_PTI_AuxdataEnable(void)

{
  BUS_RegMaskedSet(&RAC->SR3,0x80000000);
}



void RADIO_PTI_AuxdataDisable(void)

{
  BUS_RegMaskedClear(&RAC->SR3,0x80000000);
}


