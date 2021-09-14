#include "pti.o.h"



//undefined4 PTI_Config(undefined4 *param_1)
RAIL_Status_t PTI_Config(const RAIL_PtiConfig_t *config)
{
  uint32_t uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if (param_1 == NULL) {
    return 1;
  }
  puVar3 = &ptiState;
  puVar4 = param_1;
  do {
    uVar2 = puVar4[1];
    *puVar3 = *puVar4;
    puVar3[1] = uVar2;
    puVar3 = puVar3 + 2;
    puVar4 = puVar4 + 2;
  } while (puVar4 != param_1 + 4);
  *puVar3 = *puVar4;
  RADIOCMU_ClockEnable(0x63400,1);
  CMU_ClockEnable(0x82500,1);
  write_volatile_4(FRC->SNIFFCTRL,0xf8);
  write_volatile_4(FRC->ROUTELOC0,
                   (uint32_t)*(uint8_t *)((int)param_1 + 0xe) << 0x10 |
                   (uint32_t)*(uint8_t *)((int)param_1 + 0xb) << 8 | (uint32_t)*(uint8_t *)(param_1 + 2));
  uVar1 = (uint32_t)*(uint8_t *)param_1;
  if (uVar1 == 1) {
    sniffMode = 2;
    write_volatile_4(FRC->ROUTEPEN,7);
    GPIO_PinModeSet(*(uint8_t *)(param_1 + 3),*(uint8_t *)((int)param_1 + 0xd),4,0);
  }
  else {
    if (uVar1 != 2) {
      if (uVar1 != 3) {
        if (uVar1 != 0) {
          return 1;
        }
        write_volatile_4(FRC->ROUTEPEN,0);
        sniffMode = uVar1;
        return 0;
      }
      sniffMode = 5;
      write_volatile_4(FRC->ROUTEPEN,1);
      goto LAB_000100a2;
    }
    sniffMode = 1;
    write_volatile_4(FRC->ROUTEPEN,5);
  }
  GPIO_PinModeSet(*(uint8_t *)((int)param_1 + 0xf),*(uint8_t *)(param_1 + 4),4,0);
LAB_000100a2:
  GPIO_PinModeSet(*(uint8_t *)((int)param_1 + 9),*(uint8_t *)((int)param_1 + 10),4,1);
  return 0;
}



//undefined4 PTI_GetConfig(undefined4 *param_1)
RAIL_Status_t PTI_GetConfig(RAIL_PtiConfig_t *ptiConfig)
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  puVar3 = &ptiState;
  do {
    uVar1 = *puVar3;
    uVar2 = puVar3[1];
    puVar3 = puVar3 + 2;
    *param_1 = uVar1;
    param_1[1] = uVar2;
    param_1 = param_1 + 2;
  } while (puVar3 != (undefined4 *)0x101c0);
  *param_1 = uRam000101c0;
  return 0;
}



void PTI_EnableAppendedInfo(int param_1)

{
  RAC_SET *pRVar1;
  
  if (param_1 == 0) {
    pRVar1 = (RAC_SET *)&Peripherals::RAC_CLR;
  }
  else {
    pRVar1 = &Peripherals::RAC_SET;
  }
  ((RAC_CLR *)pRVar1)->SR3 = 0x40000000;
  return;
}



//undefined4 PTI_Enable(int param_1)
RAIL_Status_t PTI_Enable(bool enable)
{
  int iVar1;
  uint32_t uVar2;
  
  if (param_1 == 0) {
    BUS_RegMaskedClear(&FRC->SNIFFCTRL,3);
  }
  else {
    uVar2 = DAT_000101b4;
    if (DAT_000101b4 != 0) {
      iVar1 = RADIOCMU_ClockFreqGet(0x63400);
      uVar2 = ((iVar1 + (DAT_000101b4 >> 1)) / DAT_000101b4 - 1) * 0x100;
    }
    BUS_RegMaskedClear(&FRC->SNIFFCTRL,0xff03);
    BUS_RegMaskedSet(&FRC->SNIFFCTRL,uVar2 | sniffMode);
  }
  PTI_EnableAppendedInfo(param_1);
  return 0;
}



void PTI_AuxdataOutput(uint32_t param_1)

{
  FRC *pFVar1;
  bool bVar2;
  
  pFVar1 = (FRC *)(RAC->SR3);
  bVar2 = (int)pFVar1 < 0;
  if (bVar2) {
    pFVar1 = &Peripherals::FRC;
  }
  if (bVar2) {
    pFVar1->AUXDATA = param_1;
  }
  return;
}



void PTI_EnableAuxdata(int param_1)

{
  RAC_SET *pRVar1;
  
  if (param_1 == 0) {
    pRVar1 = (RAC_SET *)&Peripherals::RAC_CLR;
  }
  else {
    pRVar1 = &Peripherals::RAC_SET;
  }
  ((RAC_CLR *)pRVar1)->SR3 = 0x80000000;
  return;
}



void PTI_EnableSyncword(int param_1)

{
  RAC_SET *pRVar1;
  
  if (param_1 == 0) {
    pRVar1 = (RAC_SET *)&Peripherals::RAC_CLR;
  }
  else {
    pRVar1 = &Peripherals::RAC_SET;
  }
  ((RAC_CLR *)pRVar1)->SR3 = 0x8000000;
  return;
}


