#include "rf_test.h"

//berSkipBytes[] = {0xf4,0x01,0,0};
//testModeRegisterState;
//berInfiniteMode;
//berStats;
//bufcCallbacks[16];

void setupPnForTest(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::FRC.FCD0);
  write_volatile_4(Peripherals::FRC.FCD0,uVar1 & 0xffffbfff);
  uVar1 = read_volatile_4(Peripherals::FRC.FCD1);
  write_volatile_4(Peripherals::FRC.FCD1,uVar1 & 0xffffbfff);
  uVar1 = read_volatile_4(Peripherals::FRC.FCD2);
  write_volatile_4(Peripherals::FRC.FCD2,uVar1 & 0xffffbfff);
  uVar1 = read_volatile_4(Peripherals::FRC.FCD3);
  write_volatile_4(Peripherals::FRC.FCD3,uVar1 & 0xffffbfff);
  write_volatile_4(Peripherals::FRC.FECCTRL,1);
  write_volatile_4(Peripherals::FRC.WHITECTRL,0x24);
  write_volatile_4(Peripherals::FRC.WHITEPOLY,0x100);
  write_volatile_4(Peripherals::FRC.WHITEINIT,0x138);
  return;
}



void RFTEST_BerEmptyBufcAndUpdateStats(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  for (iVar1 = BUFC_RxBufferBytesAvailable(); iVar1 != 0; iVar1 = iVar1 + -1) {
    uVar2 = BUFC_RxBufferReadByte();
    if (berSkipBytesLeft == 0) {
      if ((berTotalBytesLeft != 0) || (berInfiniteMode != '\0')) {
        berTotalBytesLeft = berTotalBytesLeft + -1;
        berTotalErrors =
             berTotalErrors +
             ((uint)(byte)nibblebits_7220[uVar2 & 0xf] +
              (uint)(byte)nibblebits_7220[(uVar2 << 0x14) >> 0x18] & 0xff);
        berTotalBits = berTotalBits + 8;
        iVar3 = RADIO_GetRSSI();
        DAT_00010468._0_1_ = (undefined)(iVar3 >> 2);
      }
    }
    else {
      berSkipBytesLeft = berSkipBytesLeft + -1;
    }
  }
  uVar2 = berTotalBits;
  if (berTotalBits < DAT_00010460) {
    uVar2 = 0xffffffff;
  }
  if (berTotalErrors < DAT_00010464) {
    DAT_00010464 = 0xffffffff;
  }
  else {
    DAT_00010464 = berTotalErrors;
  }
  DAT_00010460 = uVar2;
  return;
}



void RFTEST_StartRx(void)

{
  uint uVar1;
  
  do {
    uVar1 = read_volatile_4(Peripherals::RAC.STATUS);
  } while ((uVar1 & 0xf000000) != 0);
  BUFC_RxBufferReset();
  write_volatile_4(Peripherals::RAC_SET.RXENSRCEN,2);
  return;
}



void RFTEST_StopRx(void)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  
  iVar1 = 0xff;
  write_volatile_4(Peripherals::RAC_CLR.RXENSRCEN,0xff);
  CORE_EnterCritical();
  uVar2 = read_volatile_4(Peripherals::RAC.STATUS);
  uVar2 = (uVar2 << 4) >> 0x1c;
  bVar3 = uVar2 == 3;
  if (bVar3) {
    iVar1 = 0x21000f64;
    uVar2 = read_volatile_4(Peripherals::SEQ.REG06C);
    uVar2 = uVar2 & 0xffffff0f | 0xe0;
  }
  if (bVar3) {
    *(uint *)(iVar1 + 8) = uVar2;
  }
  write_volatile_4(Peripherals::FRC.CMD,1);
  CORE_ExitCritical();
  uVar2 = read_volatile_4(Peripherals::RAC.STATUS);
  if ((uVar2 << 4) >> 0x1c == 6) {
    write_volatile_4(Peripherals::RAC.CMD,0x40);
    BUFC_RxBufferReset();
  }
  do {
    uVar2 = read_volatile_4(Peripherals::RAC.STATUS);
  } while ((uVar2 & 0xf000000) != 0);
  return;
}



void RFTEST_SaveRadioConfiguration(void)

{
  if (testModeRegisterState == '\0') {
    DAT_00010484 = read_volatile_4(Peripherals::MODEM.AFC);
    DAT_00010488 = read_volatile_4(Peripherals::MODEM.CTRL0);
    DAT_0001048c = read_volatile_4(Peripherals::MODEM.CTRL1);
    DAT_00010490 = read_volatile_4(Peripherals::MODEM.MODINDEX);
    DAT_00010494 = read_volatile_4(Peripherals::MODEM.PRE);
    DAT_00010498 = read_volatile_4(Peripherals::MODEM.TIMING);
    DAT_0001049c = read_volatile_4(Peripherals::FRC.DFLCTRL);
    DAT_000104a0 = read_volatile_4(Peripherals::FRC.CTRL);
    DAT_000104a4 = read_volatile_4(Peripherals::FRC.FECCTRL);
    DAT_000104a8 = read_volatile_4(Peripherals::FRC.FCD0);
    DAT_000104ac = read_volatile_4(Peripherals::FRC.FCD1);
    DAT_000104b0 = read_volatile_4(Peripherals::FRC.FCD2);
    DAT_000104b4 = read_volatile_4(Peripherals::FRC.FCD3);
    DAT_000104b8 = read_volatile_4(Peripherals::FRC.WHITECTRL);
    DAT_000104bc = read_volatile_4(Peripherals::FRC.WHITEPOLY);
    DAT_000104c0 = read_volatile_4(Peripherals::FRC.WHITEINIT);
    DAT_000104c4 = read_volatile_4(Peripherals::SEQ.SYNTHLPFCTRLTX);
    DAT_000104c8 = read_volatile_4(Peripherals::FRC.SNIFFCTRL);
    DAT_000104cc = read_volatile_4(Peripherals::FRC.IEN);
    write_volatile_4(Peripherals::FRC.IEN,0);
    testModeRegisterState = '\x01';
  }
  return;
}



void RFTEST_RestoreRadioConfiguration(void)

{
  if (testModeRegisterState != '\0') {
    write_volatile_4(Peripherals::MODEM.AFC,DAT_00010484);
    write_volatile_4(Peripherals::MODEM.CTRL0,DAT_00010488);
    write_volatile_4(Peripherals::MODEM.CTRL1,DAT_0001048c);
    write_volatile_4(Peripherals::MODEM.MODINDEX,DAT_00010490);
    write_volatile_4(Peripherals::MODEM.PRE,DAT_00010494);
    write_volatile_4(Peripherals::FRC.DFLCTRL,DAT_0001049c);
    write_volatile_4(Peripherals::FRC.CTRL,DAT_000104a0);
    write_volatile_4(Peripherals::FRC.FECCTRL,DAT_000104a4);
    write_volatile_4(Peripherals::FRC.FCD0,DAT_000104a8);
    write_volatile_4(Peripherals::FRC.FCD1,DAT_000104ac);
    write_volatile_4(Peripherals::FRC.FCD2,DAT_000104b0);
    write_volatile_4(Peripherals::FRC.FCD3,DAT_000104b4);
    write_volatile_4(Peripherals::FRC.WHITECTRL,DAT_000104b8);
    write_volatile_4(Peripherals::FRC.WHITEPOLY,DAT_000104bc);
    write_volatile_4(Peripherals::FRC.WHITEINIT,DAT_000104c0);
    write_volatile_4(Peripherals::SEQ.SYNTHLPFCTRLTX,DAT_000104c4);
    write_volatile_4(Peripherals::FRC.SNIFFCTRL,DAT_000104c8);
    write_volatile_4(Peripherals::FRC.IFC,0x7ffff);
    write_volatile_4(Peripherals::FRC.IEN,DAT_000104cc);
    testModeRegisterState = '\0';
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
  setupPnForTest();
  write_volatile_4(Peripherals::FRC.SNIFFCTRL,0);
  write_volatile_4(Peripherals::FRC.DFLCTRL,5);
  write_volatile_4(Peripherals::FRC_SET.CTRL,1);
  write_volatile_4(Peripherals::RAC.CMD,1);
}



void RFTEST_StartTx(void)

{
  write_volatile_4(Peripherals::RAC.CMD,1);
  return;
}



void RFTEST_StopTx(void)

{
  uint uVar1;
  
  write_volatile_4(Peripherals::RAC.CMD,0x20);
  do {
    uVar1 = read_volatile_4(Peripherals::FRC.DFLCTRL);
    if ((uVar1 & 7) != 5) {
      return;
    }
    uVar1 = read_volatile_4(Peripherals::FRC.IF);
  } while (-1 < (int)(uVar1 << 0x1d));
  return;
}



void RFTEST_BerStop(void)

{
  write_volatile_4(Peripherals::FRC_CLR.RXCTRL,0x40);
  RFTEST_StopRx();
  write_volatile_4(Peripherals::BUFC_CLR.IEN,0x400);
  return;
}



void RFTEST_ConfigBerRx(void)

{
  uint uVar1;
  
  BUFC_SetCallbacks(&bufcCallbacks);
  BUFC_ConfigureCallbacks(4);
  uVar1 = read_volatile_4(Peripherals::BUFC.BUF1_THRESHOLDCTRL);
  write_volatile_4(Peripherals::BUFC.BUF1_THRESHOLDCTRL,uVar1 & 0xfffff000 | 100);
  write_volatile_4(Peripherals::FRC.DFLCTRL,5);
  write_volatile_4(Peripherals::MODEM.SYNC0,0x1dd3d4a0);
  setupPnForTest();
  write_volatile_4(Peripherals::MODEM_CLR.TIMING,0xf00);
  uVar1 = read_volatile_4(Peripherals::MODEM.CTRL1);
  write_volatile_4(Peripherals::MODEM.CTRL1,uVar1 | 0x1f);
  uVar1 = read_volatile_4(Peripherals::MODEM.AFC);
  write_volatile_4(Peripherals::MODEM.AFC,uVar1 & 0xffffe3ff);
  uVar1 = read_volatile_4(Peripherals::MODEM.CTRL1);
  if ((uVar1 & 0xc000) == 0) {
    write_volatile_4(Peripherals::MODEM_SET.CTRL1,0xc000);
  }
  write_volatile_4(Peripherals::FRC.TRAILRXDATA,0);
  write_volatile_4(Peripherals::FRC_SET.RXCTRL,0x12);
  write_volatile_4(Peripherals::FRC.CTRL,4);
  return;
}



void RFTEST_ResetBerStats(int param_1)

{
  if (0x1ffffffe < param_1 - 1U) {
    param_1 = 0x1fffffff;
  }
  berStats = param_1 << 3;
  DAT_00010460 = 0;
  DAT_00010464 = 0;
  DAT_00010468._0_1_ = 0;
  berInfiniteMode = 0;
  berSkipBytesLeft = berSkipBytes;
  berTotalBytesLeft = param_1;
  berTotalErrors = 0;
  berTotalBits = 0;
  return;
}



void RFTEST_ReportBerStats(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar3 = DAT_00010468;
  uVar2 = DAT_00010464;
  uVar1 = DAT_00010460;
  *param_1 = berStats;
  param_1[1] = uVar1;
  param_1[2] = uVar2;
  param_1[3] = uVar3;
  return;
}



void RFTEST_StartBerRx(undefined4 param_1)

{
  RFTEST_BerStop();
  RFTEST_ResetBerStats(param_1);
  write_volatile_4(Peripherals::BUFC_SET.IEN,0x400);
  RFTEST_StartRx();
  return;
}


