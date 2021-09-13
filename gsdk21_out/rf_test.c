#include "rf_test.h"



void RFTEST_SaveRadioConfiguration(void)

{
  if (testModeRegisterState == '\0') {
    DAT_000101e0 = read_volatile_4(Peripherals::MODEM.CTRL0);
    DAT_000101e4 = read_volatile_4(Peripherals::MODEM.MODINDEX);
    DAT_000101e8 = read_volatile_4(Peripherals::MODEM.PRE);
    DAT_000101ec = read_volatile_4(Peripherals::FRC.DFLCTRL);
    DAT_000101f0 = read_volatile_4(Peripherals::FRC.FECCTRL);
    DAT_000101f4 = read_volatile_4(Peripherals::FRC.FCD0);
    DAT_000101f8 = read_volatile_4(Peripherals::FRC.FCD1);
    DAT_000101fc = read_volatile_4(Peripherals::FRC.WHITECTRL);
    DAT_00010200 = read_volatile_4(Peripherals::FRC.WHITEPOLY);
    DAT_00010204 = read_volatile_4(Peripherals::FRC.WHITEINIT);
    DAT_00010208 = read_volatile_4(Peripherals::SEQ.SYNTHLPFCTRLTX);
    testModeRegisterState = '\x01';
  }
  return;
}



void RFTEST_StartCwTx(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = read_volatile_4(Peripherals::SEQ.SYNTHLPFCTRLTX);
  write_volatile_4(Peripherals::SEQ.SYNTHLPFCTRLTX,uVar1 & 0xfffffff0);
  uVar1 = read_volatile_4(Peripherals::MODEM.CTRL0);
  uVar2 = uVar1 & 0x1c0;
  if (uVar2 == 0xc0) {
    write_volatile_4(Peripherals::MODEM.CTRL0,uVar1 & 0xfffffe3f | 0x80);
  }
  else {
    if ((uVar2 != 0x180) && (uVar2 != 0x80)) {
      write_volatile_4(Peripherals::MODEM.MODINDEX,0);
    }
  }
  write_volatile_4(Peripherals::MODEM_SET.PRE,0xffff000f);
  write_volatile_4(Peripherals::MODEM_CLR.PRE,0x30);
  write_volatile_4(Peripherals::FRC.DFLCTRL,5);
  write_volatile_4(Peripherals::FRC_SET.CTRL,1);
  write_volatile_4(Peripherals::RAC.CMD,1);
  return;
}



void RFTEST_StartStreamTx(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::FRC.FCD0);
  write_volatile_4(Peripherals::FRC.FCD0,uVar1 & 0xffffbfff);
  uVar1 = read_volatile_4(Peripherals::FRC.FCD1);
  write_volatile_4(Peripherals::FRC.FCD1,uVar1 & 0xffffbfff);
  write_volatile_4(Peripherals::FRC.FECCTRL,1);
  write_volatile_4(Peripherals::FRC.WHITECTRL,0x24);
  write_volatile_4(Peripherals::FRC.WHITEPOLY,0x100);
  write_volatile_4(Peripherals::FRC.WHITEINIT,0x138);
  write_volatile_4(Peripherals::FRC_CLR.SNIFFCTRL,0x10);
  write_volatile_4(Peripherals::FRC.DFLCTRL,5);
  write_volatile_4(Peripherals::FRC_SET.CTRL,1);
  write_volatile_4(Peripherals::RAC.CMD,1);
  return;
}



void RFTEST_StartTx(void)

{
  write_volatile_4(Peripherals::RAC.CMD,1);
  return;
}



void RFTEST_StopTx(void)

{
  uint uVar1;
  int iVar2;
  
  CORE_EnterCritical();
  uVar1 = read_volatile_4(Peripherals::RAC.STATUS);
  if ((uVar1 & 0x9000000) != 0) {
    write_volatile_4(Peripherals::RAC.CMD,0x20);
    uVar1 = read_volatile_4(Peripherals::FRC.DFLCTRL);
    if ((uVar1 & 7) == 5) {
      iVar2 = 0;
      do {
        uVar1 = read_volatile_4(Peripherals::FRC.IF);
        if ((int)(uVar1 << 0x1d) < 0) break;
        iVar2 = iVar2 + 1;
      } while (iVar2 != 0x10000);
    }
    write_volatile_4(Peripherals::FRC_SET.IFC,4);
  }
  CORE_ExitCritical();
  return;
}



void RFTEST_RestoreRadioConfiguration(void)

{
  if (testModeRegisterState != '\0') {
    RFTEST_StopTx();
    write_volatile_4(Peripherals::MODEM.CTRL0,DAT_000101e0);
    write_volatile_4(Peripherals::MODEM.MODINDEX,DAT_000101e4);
    write_volatile_4(Peripherals::MODEM.PRE,DAT_000101e8);
    write_volatile_4(Peripherals::FRC.DFLCTRL,DAT_000101ec);
    write_volatile_4(Peripherals::FRC.FECCTRL,DAT_000101f0);
    write_volatile_4(Peripherals::FRC.FCD0,DAT_000101f4);
    write_volatile_4(Peripherals::FRC.FCD1,DAT_000101f8);
    write_volatile_4(Peripherals::FRC.WHITECTRL,DAT_000101fc);
    write_volatile_4(Peripherals::FRC.WHITEPOLY,DAT_00010200);
    write_volatile_4(Peripherals::FRC.WHITEINIT,DAT_00010204);
    write_volatile_4(Peripherals::SEQ.SYNTHLPFCTRLTX,DAT_00010208);
    write_volatile_4(Peripherals::FRC_CLR.CTRL,1);
    write_volatile_4(Peripherals::FRC_SET.SNIFFCTRL,0x10);
    testModeRegisterState = '\0';
  }
  return;
}


