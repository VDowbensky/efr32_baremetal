#include "rf_test.h"

static uint32_t reg_save[16];

void RFTEST_SaveRadioConfiguration(void)

{
  if (testModeRegisterState == false) 
  {
    reg_save[0] = MODEM->CTRL0;
    reg_save[1] = MODEM->MODINDEX;
    reg_save[2] = MODEM->PRE;
    reg_save[3] = FRC->DFLCTRL;
    reg_save[4] = FRC->FECCTRL;
    reg_save[5] = FRC->FCD0;
    reg_save[6] = FRC->FCD1;
    reg_save[7] = FRC->WHITECTRL;
    reg_save[8] = FRC->WHITEPOLY;
    reg_save[9] = FRC->WHITEINIT;
    reg_save[10] = SEQ->SYNTHLPFCTRLTX;
    testModeRegisterState = true;
  }
}



void RFTEST_StartCwTx(void)

{
  uint32_t uVar1;
  uint32_t uVar2;
  
  uVar1 = (SEQ->SYNTHLPFCTRLTX);
  write_volatile_4(SEQ->SYNTHLPFCTRLTX,uVar1 & 0xfffffff0);
  uVar1 = (MODEM->CTRL0);
  uVar2 = uVar1 & 0x1c0;
  if (uVar2 == 0xc0) {
    write_volatile_4(MODEM->CTRL0,uVar1 & 0xfffffe3f | 0x80);
  }
  else {
    if ((uVar2 != 0x180) && (uVar2 != 0x80)) {
      write_volatile_4(MODEM->MODINDEX,0);
    }
  }
  BUS_RegMaskedSet(&MODEM->PRE,0xffff000f);
  BUS_RegMaskedClear(&MODEM->PRE,0x30);
  write_volatile_4(FRC->DFLCTRL,5);
  BUS_RegMaskedSet(&FRC->CTRL,1);
  write_volatile_4(RAC->CMD,1);
  return;
}



void RFTEST_StartStreamTx(void)

{
  uint32_t uVar1;
  
  uVar1 = (FRC->FCD0);
  write_volatile_4(FRC->FCD0,uVar1 & 0xffffbfff);
  uVar1 = (FRC->FCD1);
  write_volatile_4(FRC->FCD1,uVar1 & 0xffffbfff);
  write_volatile_4(FRC->FECCTRL,1);
  write_volatile_4(FRC->WHITECTRL,0x24);
  write_volatile_4(FRC->WHITEPOLY,0x100);
  write_volatile_4(FRC->WHITEINIT,0x138);
  BUS_RegMaskedClear(&FRC->SNIFFCTRL,0x10);
  write_volatile_4(FRC->DFLCTRL,5);
  BUS_RegMaskedSet(&FRC->CTRL,1);
  write_volatile_4(RAC->CMD,1);
  return;
}



void RFTEST_StartTx(void)

{
  write_volatile_4(RAC->CMD,1);
  return;
}



void RFTEST_StopTx(void)

{
  uint32_t uVar1;
  int iVar2;
  
  CORE_EnterCritical();
  uVar1 = (RAC->STATUS);
  if ((uVar1 & 0x9000000) != 0) {
    write_volatile_4(RAC->CMD,0x20);
    uVar1 = (FRC->DFLCTRL);
    if ((uVar1 & 7) == 5) {
      iVar2 = 0;
      do {
        uVar1 = (FRC->IF);
        if ((int)(uVar1 << 0x1d) < 0) break;
        iVar2 = iVar2 + 1;
      } while (iVar2 != 0x10000);
    }
    BUS_RegMaskedSet(&FRC->IFC,4);
  }
  CORE_ExitCritical();
  return;
}



void RFTEST_RestoreRadioConfiguration(void)

{
  if (testModeRegisterState != '\0') {
    RFTEST_StopTx();
    write_volatile_4(MODEM->CTRL0,DAT_000101e0);
    write_volatile_4(MODEM->MODINDEX,DAT_000101e4);
    write_volatile_4(MODEM->PRE,DAT_000101e8);
    write_volatile_4(FRC->DFLCTRL,DAT_000101ec);
    write_volatile_4(FRC->FECCTRL,DAT_000101f0);
    write_volatile_4(FRC->FCD0,DAT_000101f4);
    write_volatile_4(FRC->FCD1,DAT_000101f8);
    write_volatile_4(FRC->WHITECTRL,DAT_000101fc);
    write_volatile_4(FRC->WHITEPOLY,DAT_00010200);
    write_volatile_4(FRC->WHITEINIT,DAT_00010204);
    write_volatile_4(SEQ->SYNTHLPFCTRLTX,DAT_00010208);
    BUS_RegMaskedClear(&FRC->CTRL,1);
    BUS_RegMaskedSet(&FRC->SNIFFCTRL,0x10);
    testModeRegisterState = '\0';
  }
  return;
}


