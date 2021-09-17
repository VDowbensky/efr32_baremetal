#include "rfsense.h"


void RFSENSE_Disable(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = em4Flag;
  RFSENSE_Cb = 0;
  write_volatile_4(RFSENSE->IEN,0);
  write_volatile_4(RFSENSE->EM4WUEN,0);
  write_volatile_4(RFSENSE->CTRL,0);
  write_volatile_4(RFSENSE->PERIODSEL,0xf);
  if (em4Flag != 0) {
    em4Flag = 0;
    INT_Disable();
    uVar1 = (EMU->EM4CTRL);
    write_volatile_4(EMU->EM4CTRL,uVar1 & ~uVar2);
    INT_Enable();
    return;
  }
  RFSENSE_Cb = 0;
  return;
}



int RFSENSE_CalcPeriod(uint param_1,uint param_2,char *param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  uint uVar4;
  
  switch(param_1 & 0xc) {
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
  if (uVar1 == 0) {
    return 0;
  }
  uVar4 = uVar1 >> 1;
  uVar2 = __aeabi_uldivmod(uVar4 + 0xa1200000,(0x5edfffff < uVar4) + '\a',uVar1,0,param_4);
  uVar1 = (uVar4 + 3000000) / uVar1;
  if (uVar1 < param_2) {
    param_2 = param_2 - uVar1;
  }
  else {
    param_2 = 0;
  }
  for (cVar3 = '\x0f'; (param_2 < uVar2 - (uVar2 >> 2) && (cVar3 != '\0')); cVar3 = cVar3 + -1) {
    uVar2 = uVar2 >> 1;
  }
  *param_3 = cVar3;
  return uVar2 + uVar1;
}



void RFSENSE_ReInit(void)

{
  RFSENSE_Disable();
  write_volatile_4(RFSENSE->IFC,1);
  _DAT_e000e184 = 1;
  _DAT_e000e284 = 1;
  return;
}


bool RFSENSE_Sensed(void)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = _DAT_43c81904;
  _DAT_43c81904 = 1;
  uVar3 = (RFSENSE->IF);
  if (uVar3 != 0) {
    uVar3 = 1;
  }
  if (uVar3 != 0) {
    INT_Disable();
    pcVar1 = RFSENSE_Cb;
    RFSENSE_Cb = FUN_00000000;
    INT_Enable();
    RFSENSE_Disable();
    if (pcVar1 != FUN_00000000) {
      (*pcVar1)();
    }
  }
  if (iVar2 == 0) {
    _DAT_43c81904 = iVar2;
  }
  return SUB41(uVar3,0);
}




bool RFSENSE_IRQHandler(void)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = _DAT_43c81904;
  _DAT_43c81904 = 1;
  uVar3 = (RFSENSE->IF);
  if (uVar3 != 0) {
    uVar3 = 1;
  }
  if (uVar3 != 0) {
    INT_Disable();
    pcVar1 = RFSENSE_Cb;
    RFSENSE_Cb = FUN_00000000;
    INT_Enable();
    RFSENSE_Disable();
    if (pcVar1 != FUN_00000000) {
      (*pcVar1)();
    }
  }
  if (iVar2 == 0) {
    _DAT_43c81904 = iVar2;
  }
  return SUB41(uVar3,0);
}



void RFSENSE_DeInit(void)

{
  RFSENSE_ReInit();
  _DAT_43c81904 = 0;
  return;
}



uint32_t RFSENSE_Init(undefined4 *param_1,uint32_t sensetime)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  
  _DAT_43c81904 = 1;
  puVar7 = param_1;
  RFSENSE_ReInit();
  if (param_1 == NULL) {
LAB_000092b6:
    RFSENSE_DeInit();
    return 0;
  }
  bVar1 = *(byte *)(param_1 + 2);
  uVar5 = (uint)bVar1;
  if ((((bVar1 & 3) == 0) || (param_1[1] == 0)) ||
     (uVar2 = RFSENSE_CalcPeriod(uVar5,param_1[1],&stack0xffffffe6), uVar2 == 0)) goto LAB_000092b6;
  if (((bVar1 & 0xc) == 0) && (uVar3 = param_1[1], 100000 < uVar3)) {
    if (uVar3 < uVar2) {
      uVar6 = uVar2 - uVar3;
    }
    else {
      uVar6 = uVar3 - uVar2;
    }
    if ((uVar6 != 0) &&
       (uVar3 = RFSENSE_CalcPeriod(0xc,uVar3,&stack0xffffffe7,100000,puVar7,sensetime), uVar3 != 0))
    {
      uVar4 = param_1[1];
      if (uVar4 < uVar3) {
        uVar4 = uVar3 - uVar4;
      }
      else {
        uVar4 = uVar4 - uVar3;
      }
      if (uVar4 < uVar6) {
        sensetime = (sensetime >> 0x18) << 0x10;
        uVar5 = uVar5 | 0xc;
        uVar2 = uVar3;
      }
    }
  }
  write_volatile_4(RFSENSE->PERIODSEL,sensetime >> 0x10 & 0xff);
  if (*(char *)((int)param_1 + 9) == '\0') goto LAB_00009350;
  write_volatile_4(RFSENSE->EM4WUEN,1);
  uVar3 = uVar5 & 0xc;
  if (uVar3 == 8) {
    uVar3 = (EMU->EM4CTRL);
    if (-1 < (int)(uVar3 << 0x1d)) {
      uVar3 = 4;
      goto LAB_00009374;
    }
  }
  else {
    if (uVar3 == 0xc) {
      uVar3 = (EMU->EM4CTRL);
      if (-1 < (int)(uVar3 << 0x1c)) {
        uVar3 = 8;
        goto LAB_00009374;
      }
    }
    else {
      if ((uVar3 == 4) &&
         (uVar3 = (EMU->EM4CTRL), -1 < (int)(uVar3 << 0x1e))) {
        uVar3 = 2;
LAB_00009374:
        INT_Disable();
        uVar6 = (EMU->EM4CTRL);
        write_volatile_4(EMU->EM4CTRL,uVar6 | uVar3);
        INT_Enable();
        em4Flag = uVar3;
        goto LAB_00009350;
      }
    }
  }
  em4Flag = 0;
LAB_00009350:
  write_volatile_4(RFSENSE->IEN,1);
  write_volatile_4(RFSENSE->CTRL,uVar5 & 0x2f);
  RFSENSE_Cb = *param_1;
  _DAT_e000e104 = 1;
  return uVar2;
}




// WARNING: Globals starting with '_' overlap smaller symbols at the same address

int RFSENSE_CalRfOscFreq(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (param_1 - 8U < 4) {
    _DAT_43c81904 = 1;
    RFSENSE_ReInit();
    write_volatile_4(RFSENSE->PERIODSEL,0xf);
    write_volatile_4(RFSENSE->CTRL,3);
    _DAT_43c8160c = 1;
    puVar3 = (undefined4 *)((param_1 + 0x10f30040) * 4);
    (&Peripherals::PRS.CH0_CTRL)[param_1] = 0x3b02;
    *puVar3 = 1;
    write_volatile_4(CMU->CALCTRL,param_1 << 0x10 | 0x25);
    iVar2 = SystemLFXOClockGet();
    write_volatile_4(CMU->CALCNT,iVar2 - 1);
    _DAT_43c81594 = 0;
    write_volatile_4(CMU->CMD,1);
    do {
    } while (_DAT_43c81414 == 0);
    uVar1 = (CMU->CALCNT);
    write_volatile_4(CMU->CMD,2);
    write_volatile_4(CMU->CALCTRL,0);
    _DAT_43c81514 = 1;
    *puVar3 = 0;
    (&Peripherals::PRS.CH0_CTRL)[param_1] = 0;
    iVar2 = uVar1 + 1;
    RFSENSE_DeInit();
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}

