#include "rfsense.h"

em4Flag;
RFSENSE_Cb;
RFSENSE_RfOscFreqHz = 0x00003a34;

void RFSENSE_Disable(void)

{
  uint32_t flag;
  uint32_t tmp; 
  
  flag = em4Flag;
  RFSENSE_Cb = 0;
  RFSENSE->IEN = 0;
  RFSENSE->EM4WUEN = 0;
  RFSENSE->CTRL = 0;
  RFSENSE->PERIODSEL = 0xf;
  if (em4Flag != 0) 
  {
    em4Flag = 0;
    tmp = CORE_EnterCritical();
	EMU->EM4CTRL &= ~flag;
    CORE_ExitCritical(tmp);
    return;
  }
  RFSENSE_Cb = 0;
}



int RFSENSE_CalcPeriod(uint param_1,uint param_2,char *param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  uint uVar4;
  
  switch(param_1 & 0xc) 
  {
  case 0:
    uVar1 = RFSENSE_RfOscFreqHz;
    break;
  case 4:
    uVar1 = SystemLFRCOClockGet();
    break;
  case 8:
    uVar1 = SystemLFXOClockGet();
    break;
  case 0xc:
    uVar1 = SystemULFRCOClockGet();
    break;
  default:
    return 0;
  }
  if (uVar1 == 0) return 0;
  uVar4 = uVar1 >> 1;
  uVar2 = __aeabi_uldivmod(uVar4 + 0xa1200000,(0x5edfffff < uVar4) + '\a',uVar1,0,param_4);
  uVar1 = (uVar4 + 3000000) / uVar1;
  if (uVar1 < param_2) param_2 = param_2 - uVar1;
  else param_2 = 0;
  for (cVar3 = '\x0f'; (param_2 < uVar2 - (uVar2 >> 2) && (cVar3 != '\0')); cVar3 = cVar3 + -1) uVar2 = uVar2 >> 1;
  *param_3 = cVar3;
  return uVar2 + uVar1;
}


void RFSENSE_ReInit(void)

{
  RFSENSE_Disable();
  RFSENSE->IFC = 1;
  _DAT_e000e184 = 1;
  _DAT_e000e284 = 1;
}


bool RFSENSE_Sensed(void)

{
  code *pcVar1;
  int32_t iVar2;
  uint32_t uVar3;
  
  iVar2 = _DAT_43c81904;
  BUS_RegMaskedSet(&CMU->HFRADIOCLKEN0,2);
  if (RFSENSE->IF != 0) uVar3 = 1;
  if (uVar3 != 0) 
  {
    CORE_EnterCritical();
    pcVar1 = RFSENSE_Cb;
    RFSENSE_Cb = NULL;
    CORE_ExitCritical();
    RFSENSE_Disable();
    if (pcVar1 != NULL) (*pcVar1)();
  }
  if (iVar2 == 0) BUS_RegMaskedClear(&CMU->HFRADIOCLKEN0,2);
  return uVar3;
}


uint32_t RFSENSE_IRQHandler(void)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = _DAT_43c81904;
  BUS_RegMaskedSet(&CMU->HFRADIOCLKEN0,2);
  if (RFSENSE->IF != 0) uVar3 = 1;
  if (uVar3 != 0) 
  {
    CORE_EnterCritical();
    pcVar1 = RFSENSE_Cb;
    RFSENSE_Cb = NULL;
    CORE_ExitCritical();
    RFSENSE_Disable();
    if (pcVar1 != NULL)(*pcVar1)();
  }
  if (iVar2 == 0) BUS_RegMaskedClear(&CMU->HFRADIOCLKEN0,2);
  return uVar3;
}



void RFSENSE_DeInit(void)

{
  RFSENSE_ReInit();
  BUS_RegMaskedClear(&CMU->HFRADIOCLKEN0,2);
}


uint32_t RFSENSE_Init(undefined4 *param_1,uint param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  
  BUS_RegMaskedSet(&CMU->HFRADIOCLKEN0,2);
  puVar7 = param_1;
  RFSENSE_ReInit();
  if (param_1 == (undefined4 *)0x0) 
  {
LAB_00010176:
    RFSENSE_DeInit();
    return 0;
  }
  bVar1 = *(byte *)(param_1 + 2);
  uVar5 = (uint)bVar1;
  if ((((bVar1 & 3) == 0) || (param_1[1] == 0)) || (RFSENSE_CalcPeriod(uVar5,param_1[1],&stack0xffffffe6) == 0)) goto LAB_00010176;
  if (((bVar1 & 0xc) == 0) && (uVar3 = param_1[1], 100000 < uVar3)) 
  {
    if (uVar3 < uVar2) uVar6 = uVar2 - uVar3;
    else uVar6 = uVar3 - uVar2;
    if ((uVar6 != 0) &&  (RFSENSE_CalcPeriod(0xc,uVar3,&stack0xffffffe7,100000,puVar7,param_2) != 0)) 
	{
      uVar4 = param_1[1];
      if (uVar4 < uVar3) uVar4 = uVar3 - uVar4;
      else uVar4 = uVar4 - uVar3;
      if (uVar4 < uVar6) 
	  {
        param_2 = (param_2 >> 0x18) << 0x10;
        uVar5 = uVar5 | 0xc;
        uVar2 = uVar3;
      }
    }
  }
  RFSENSE->PERIODSEL = param_2 >> 0x10 & 0xff;
  if (*(char *)((int)param_1 + 9) == '\0') goto LAB_00010210;
  RFSENSE->EM4WUEN = 1;
  uVar3 = uVar5 & 0xc;
  if (uVar3 == 8) 
  {
    uVar3 = EMU->EM4CTRL;
    if (-1 < (int)(EMU->EM4CTRL << 0x1d)) 
	{
      uVar3 = 4;
      goto LAB_00010234;
    }
  }
  else 
  {
    if (uVar3 == 0xc) 
	{
      uVar3 = EMU->EM4CTRL;
      if (-1 < (int)(EMU->EM4CTRL << 0x1c)) 
	  {
        uVar3 = 8;
        goto LAB_00010234;
      }
    }
    else 
	{
      if ((uVar3 == 4) &&  (-1 < (int)(EMU->EM4CTRL << 0x1e))) 
	  {
        uVar3 = 2;
LAB_00010234:
        CORE_EnterCritical();
		EMU->EM4CTRL |= uVar3;
        CORE_ExitCritical();
        em4Flag = uVar3;
        goto LAB_00010210;
      }
    }
  }
  em4Flag = 0;
LAB_00010210:
  RFSENSE->IEN = 1;
  RFSENSE->CTRL = uVar5 & 0x2f;
  RFSENSE_Cb = *param_1;
  _DAT_e000e104 = 1;
  return uVar2;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

uint32_t RFSENSE_CalRfOscFreq(uint param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 - 8 < 4) 
  {
    BUS_RegMaskedSet(&CMU->HFRADIOCLKEN0,2);
    RFSENSE_ReInit();
    RFSENSE->PERIODSEL = 0xf;
    RFSENSE->CTRL = 3;
    BUS_RegMaskedSet(&CMU->HFBUSCLKEN0,8);
    (&PRS->CH0_CTRL)[param_1] = 0x3b02;
    iVar3 = 1 << (param_1 & 0xff);
    CMU->CALCTRL = param_1 << 0x10 | 0x25;
    _DAT_460e6008 = iVar3;
    iVar2 = SystemLFXOClockGet();
    CMU->CALCNT = iVar2 - 1;
    BUS_RegMaskedClear(&CMU->IEN,0x20);
    CMU->IFC = 0x20;
    CMU->CMD = 1;
    while (_DAT_43c81414 == 0);
    uVar1 = CMU->CALCNT;
    CMU->CMD = 2;
    CMU->CALCTRL = 0;
    CMU->IFC = 0x20;
    _DAT_440e6008 = iVar3;
    (&PRS->CH0_CTRL)[param_1] = 0;
    iVar2 = uVar1 + 1;
    RFSENSE_DeInit();
  }
  else iVar2 = 0;
  return iVar2;
}


