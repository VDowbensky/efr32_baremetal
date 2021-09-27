#include "rfsense.h"
#include <stdbool.h>
#include <stddef.h>
#include "em_bus.h"
#include "em_int.h"
#include "em_assert.h"

bool em4Flag;
uint32_t RFSENSE_RfOscFreqHz;

void RFSENSE_Disable(void)

{
  uint32_t uVar2;
  
  uVar2 = em4Flag;
  //RFSENSE_Cb = 0;
  RFSENSE->IEN = 0;
  RFSENSE->EM4WUEN = 0;
  RFSENSE->CTRL = 0;
  RFSENSE->PERIODSEL = 0xf;
  if (em4Flag != 0) 
  {
    em4Flag = 0;
    INT_Disable();
    EMU->EM4CTRL &= ~uVar2;
    INT_Enable();
    return;
  }
  //RFSENSE_Cb = 0;
  return;
}



int RFSENSE_CalcPeriod(uint32_t param_1,uint32_t param_2,char *param_3,uint32_t param_4)

{
	uint32_t freq;
	uint32_t uVar2;
  char cVar3;
  uint32_t uVar4;
  
  switch(param_1 & 0xc) {
  case 0:
    freq = RFSENSE_RfOscFreqHz;
    break;
  case 4:
    freq = SystemLFRCOClockGet();
    break;
  case 8:
    freq = SystemLFXOClockGet();
    break;
  case 0xc:
    freq = SystemULFRCOClockGet();
    break;
  default:
    return 0;
  }
  if (freq == 0) return 0;
 //uVar4 = freq >> 1;
//	uVar4 = freq/2;
//  uVar2 = __aeabi_uldivmod(uVar4 + 0xa1200000,(0x5edfffff < uVar4) + 10,uVar1,0,param_4);
//  uVar1 = (uVar4 + 3000000) / freq;
	
//  if (uVar1 < param_2) param_2 = param_2 - uVar1;
//  else param_2 = 0;
//  cVar3 = '\x0f';
//  while ((param_2 < uVar2 - (uVar2 >> 2) && (cVar3 != '\0')))
//  {
//    cVar3 = cVar3 + -1;
//    uVar2 = uVar2 >> 1;
//  }
//  *param_3 = cVar3;
//  return uVar2 + uVar1;
return 0;
}





void RFSENSE_ReInit(void)

{
  RFSENSE_Disable();
  RFSENSE->IFC = 1;
  NVIC_DisableIRQ(RFSENSE_IRQn);
  NVIC_ClearPendingIRQ(RFSENSE_IRQn);
}





bool RFSENSE_Sensed(void)

{
  //code *pcVar1;
  int iVar2;
  bool flag;
  
//  iVar2 = _DAT_43c81904;
//  _DAT_43c81904 = 1;
//  //uVar3 = RFSENSE->IF;
//  if (RFSENSE->IF != 0)
//  {
//	  flag = true;
//  }
//  if (flag != false)
//  {
//    INT_Disable();
//    pcVar1 = RFSENSE_Cb;
//    RFSENSE_Cb = NULL;
//    INT_Enable();
//    RFSENSE_Disable();
//    if (pcVar1 != NULL)
//	{
//      (*pcVar1)();
//    }
//  }
//  if (iVar2 == 0) _DAT_43c81904 = iVar2;
  return flag;
}





void RFSENSE_IRQHandler(void)

{
  //code *pcVar1;
//  int iVar2;
//  uint32_t uVar3;
//
//  iVar2 = _DAT_43c81904;
//  _DAT_43c81904 = 1;
//  uVar3 = RFSENSE->IF;
//  if (uVar3 != 0) uVar3 = 1;
//  if (uVar3 != 0)
//  {
//    INT_Disable();
//    pcVar1 = RFSENSE_Cb;
//    RFSENSE_Cb = NULL;
//    INT_Enable();
//    RFSENSE_Disable();
//    if (pcVar1 != NULL) (*pcVar1)();
//  }
//  if (iVar2 == 0) _DAT_43c81904 = iVar2;
 // return uVar3;
}





void RFSENSE_DeInit(void)

{
  RFSENSE_ReInit();
//  _DAT_43c81904 = 0;
}





uint32_t RFSENSE_Init(uint32_t *param_1,uint32_t param_2,uint32_t param_3)

{
  uint8_t bVar1;
  uint32_t uVar2;
//  uint uVar3;
//  uint uVar4;
//  uint uVar5;
//  uint uVar6;
//  undefined4 *puVar7;
//  undefined4 uStack24;
//
//  _DAT_43c81904 = 1;
//  puVar7 = param_1;
//  uStack24 = param_3;
//  RFSENSE_ReInit();
//  if (param_1 == (undefined4 *)0x0) {
//LAB_00010196:
//    RFSENSE_DeInit();
//    return 0;
//  }
//  bVar1 = *(byte *)(param_1 + 2);
//  uVar5 = (uint)bVar1;
//  if ((((bVar1 & 3) == 0) || (param_1[1] == 0)) ||
//     (uVar2 = RFSENSE_CalcPeriod(uVar5,param_1[1],&stack0xffffffe6), uVar2 == 0)) goto LAB_00010196;
//  if (((bVar1 & 0xc) == 0) && (uVar3 = param_1[1], 100000 < uVar3)) {
//    if (uVar3 < uVar2) uVar6 = uVar2 - uVar3; 
//    else uVar6 = uVar3 - uVar2; 
//    if ((uVar6 != 0) &&
//       (uVar3 = RFSENSE_CalcPeriod(0xc,uVar3,&stack0xffffffe7,100000,puVar7,param_2), uVar3 != 0)) {
//      uVar4 = param_1[1];
//      if (uVar4 < uVar3) uVar4 = uVar3 - uVar4; 
//      else uVar4 = uVar4 - uVar3;
//      if (uVar4 < uVar6) 
//			{
//        param_2 = (param_2 >> 0x18) << 0x10;
//        uVar5 = uVar5 | 0xc;
//        uVar2 = uVar3;
//      }
//    }
//  }
//  RFSENSE->PERIODSEL = param_2 >> 0x10 & 0xff;
//  if (*(char *)((int)param_1 + 9) == '\0') goto LAB_00010230;
//  RFSENSE->EM4WUEN = 1;
//  uVar3 = uVar5 & 0xc;
//  if (uVar3 == 8) {
//    uVar3 = EMU->EM4CTRL;
//    if (-1 < (int)(uVar3 << 0x1d))
//		{
//      uVar3 = 4;
//      goto LAB_00010254;
//    }
//  }
//  else 
//		{
//    if (uVar3 == 0xc) 
//		{
//      uVar3 = EMU->EM4CTRL;
//      if (-1 < (int)(uVar3 << 0x1c))
//	  	{
//        uVar3 = 8;
//        goto LAB_00010254;
//      }
//    }
//    else 
//		{
//      if ((uVar3 == 4) && (-1 < (int)(EMU->EM4CTRL << 0x1e))) 
//			{
//        uVar3 = 2;
//LAB_00010254:
//        INT_Disable();
//        EMU->EM4CTRL |= uVar3;
//        INT_Enable();
//        em4Flag = uVar3;
//        goto LAB_00010230;
//      }
//    }
//  }
//  em4Flag = 0;
//LAB_00010230:
//  RFSENSE->IEN = 1;
//  RFSENSE->CTRL = uVar5 & 0x2f;
//  RFSENSE_Cb = *param_1;
//  //_DAT_e000e104 = 1;
//  NVIC_EnableIRQ(RFSENSE_IRQn);
  return uVar2;
}





int RFSENSE_CalRfOscFreq(int param_1)

{
  uint32_t uVar1;
  int iVar2;
//  undefined4 *puVar3;
//
//  if (param_1 - 8U < 4)
//  {
//    _DAT_43c81904 = 1;
//    RFSENSE_ReInit();
//    RFSENSE->PERIODSEL = 0xf;
//    RFSENSE->CTRL = 3;
//    _DAT_43c8160c = 1;
//    puVar3 = (undefined4 *)((param_1 + 0x10f30040) * 4);
//    (&PRS->CH0_CTRL)[param_1] = 0x3b02;
//    *puVar3 = 1;
//    CMU->CALCTRL = param_1 << 0x10 | 0x25;
//    CMU->CALCNT = SystemLFXOClockGet() - 1;
//    _DAT_43c81594 = 0;
//    CMU->CMD = 1;
//    while (_DAT_43c81414 == 0);
//    uVar1 = CMU->CALCNT;
//
//    CMU->CMD = 2;
//    CMU->CALCTRL = 0;
//    _DAT_43c81514 = 1;
//    *puVar3 = 0;
//    (&PRS->CH0_CTRL)[param_1] = 0;
//    iVar2 = uVar1 + 1;
//    RFSENSE_DeInit();
//  }
//  else iVar2 = 0;
  return iVar2;
}


