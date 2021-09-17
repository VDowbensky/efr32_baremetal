#include "rf_test.h"



void setupPnForTest(void)

{
  uint uVar1;
  
  uVar1 = (FRC->FCD0);
  write_volatile_4(FRC->FCD0,uVar1 & 0xffffbfff);
  uVar1 = (FRC->FCD1);
  write_volatile_4(FRC->FCD1,uVar1 & 0xffffbfff);
  uVar1 = (FRC->FCD2);
  write_volatile_4(FRC->FCD2,uVar1 & 0xffffbfff);
  uVar1 = (FRC->FCD3);
  write_volatile_4(FRC->FCD3,uVar1 & 0xffffbfff);
  write_volatile_4(FRC->FECCTRL,1);
  write_volatile_4(FRC->WHITECTRL,0x24);
  write_volatile_4(FRC->WHITEPOLY,0x100);
  write_volatile_4(FRC->WHITEINIT,0x138);
  return;
}



void RFTEST_StartRx(void)

{
  uint uVar1;
  
  do {
    uVar1 = (RAC->STATUS);
  } while ((uVar1 & 0xf000000) != 0);
  RADIO_RxBufferReset();
  _DAT_43080004 = 1;
  return;
}



void RFTEST_StopRx(void)

{
  uint uVar1;
  
  uVar1 = (RAC->RXENSRCEN);
  write_volatile_4(RAC->RXENSRCEN,uVar1 & 0xffffff00);
  write_volatile_4(FRC->CMD,1);
  uVar1 = (RAC->STATUS);
  if ((uVar1 << 4) >> 0x1c == 6) {
    uVar1 = (RAC->CMD);
    write_volatile_4(RAC->CMD,uVar1 | 0x40);
    RADIO_RxBufferReset();
  }
  do {
    uVar1 = (RAC->STATUS);
  } while ((uVar1 & 0xf000000) != 0);
  return;
}



void RFTEST_SaveRadioConfiguration(void)

{
  if (testModeRegisterState == '\0') {
    DAT_20002bdc = (MODEM->AFC);
    DAT_20002be0 = (MODEM->CTRL0);
    DAT_20002be4 = (MODEM->CTRL1);
    DAT_20002be8 = (MODEM->MODINDEX);
    DAT_20002bec = (MODEM->PRE);
    DAT_20002bf0 = (MODEM->TIMING);
    DAT_20002bf4 = (FRC->DFLCTRL);
    DAT_20002bf8 = (FRC->CTRL);
    DAT_20002bfc = (FRC->FECCTRL);
    DAT_20002c00 = (FRC->FCD0);
    DAT_20002c04 = (FRC->FCD1);
    DAT_20002c08 = (FRC->FCD2);
    DAT_20002c0c = (FRC->FCD3);
    DAT_20002c10 = (FRC->WHITECTRL);
    DAT_20002c14 = (FRC->WHITEPOLY);
    DAT_20002c18 = (FRC->WHITEINIT);
    DAT_20002c1c = (SEQ->SYNTHLPFCTRLTX);
    DAT_20002c20 = (FRC->SNIFFCTRL);
    DAT_20002c24 = (FRC->IEN);
    write_volatile_4(FRC->IEN,0);
    testModeRegisterState = '\x01';
  }
  return;
}



void RFTEST_RestoreRadioConfiguration(void)

{
  if (testModeRegisterState != '\0') {
    write_volatile_4(MODEM->AFC,DAT_00010404);
    write_volatile_4(MODEM->CTRL0,DAT_00010408);
    write_volatile_4(MODEM->CTRL1,DAT_0001040c);
    write_volatile_4(MODEM->MODINDEX,DAT_00010410);
    write_volatile_4(MODEM->PRE,DAT_00010414);
    write_volatile_4(FRC->DFLCTRL,DAT_0001041c);
    write_volatile_4(FRC->CTRL,DAT_00010420);
    write_volatile_4(FRC->FECCTRL,DAT_00010424);
    write_volatile_4(FRC->FCD0,DAT_00010428);
    write_volatile_4(FRC->FCD1,DAT_0001042c);
    write_volatile_4(FRC->FCD2,DAT_00010430);
    write_volatile_4(FRC->FCD3,DAT_00010434);
    write_volatile_4(FRC->WHITECTRL,DAT_00010438);
    write_volatile_4(FRC->WHITEPOLY,DAT_0001043c);
    write_volatile_4(FRC->WHITEINIT,DAT_00010440);
    write_volatile_4(SEQ->SYNTHLPFCTRLTX,DAT_00010444);
    write_volatile_4(FRC->SNIFFCTRL,DAT_00010448);
    write_volatile_4(FRC->IFC,0x7ffff);
    write_volatile_4(FRC->IEN,DAT_0001044c);
    testModeRegisterState = '\0';
  }
  return;
}



void RFTEST_StartCwTx(void)

{
  uint uVar1;
  
  uVar1 = (SEQ->SYNTHLPFCTRLTX);
  write_volatile_4(SEQ->SYNTHLPFCTRLTX,uVar1 & 0xfffffff0);
  write_volatile_4(MODEM->MODINDEX,0);
  uVar1 = (MODEM->CTRL0);
  write_volatile_4(MODEM->CTRL0,uVar1 & 0xfffffe3f | 0x100);
  uVar1 = (MODEM->PRE);
  write_volatile_4(MODEM->PRE,~(~(uVar1 << 0x10) >> 0x10));
  write_volatile_4(FRC->DFLCTRL,5);
  _DAT_43000800 = 1;
  _DAT_43080100 = 1;
  return;
}



void RFTEST_StartStreamTx(void)

{
  setupPnForTest();
  write_volatile_4(FRC->SNIFFCTRL,0);
  write_volatile_4(FRC->DFLCTRL,5);
  _DAT_43000800 = 1;
  _DAT_43080100 = 1;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void RFTEST_StartTx(void)

{
  _DAT_43080100 = 1;
  return;
}



void RFTEST_StopTx(void)

{
  uint uVar1;
  
  do {
    uVar1 = (FRC->DFLCTRL);
    if ((uVar1 & 7) != 5) {
      _DAT_43080114 = 1;
      return;
    }
    uVar1 = (FRC->IF);
  } while (-1 < (int)(uVar1 << 0x1d));
  _DAT_43080114 = 1;
  return;
}



void RFTEST_BerStop(void)

{
  uint uVar1;
  
  uVar1 = (FRC->RXCTRL);
  write_volatile_4(FRC->RXCTRL,uVar1 & 0xffffffbf);
  RFTEST_StopRx();
  return;
}



void RFTEST_BerEmptyBufcAndUpdateStats(void)

{
  byte bVar1;
  uint16_t uVar2;
  int16_t iVar3;
  uint uVar4;
  
  uVar2 = RADIO_RxBufferBytesAvailable();
  for (uVar4 = (uint)uVar2; uVar4 != 0; uVar4 = uVar4 - 1) {
    bVar1 = RADIO_RxBufferReadByte();
    if (berSkipBytesLeft == 0) {
      if ((berTotalBytesLeft != 0) || (berInfiniteMode != '\0')) {
        berTotalBytesLeft = berTotalBytesLeft + -1;
        berTotalErrors =
             berTotalErrors +
             ((uint)(byte)(&nibblebits_6976)[bVar1 & 0xf] +
              (uint)(byte)(&nibblebits_6976)[((uint)bVar1 << 0x14) >> 0x18] & 0xff);
        berTotalBits = berTotalBits + 8;
        iVar3 = RADIO_GetRSSI();
        DAT_20002bd0._0_1_ = (undefined)(iVar3 >> 2);
      }
    }
    else {
      berSkipBytesLeft = berSkipBytesLeft + -1;
    }
  }
  uVar4 = berTotalBits;
  if (berTotalBits < DAT_20002bc8) {
    uVar4 = 0xffffffff;
  }
  if (berTotalErrors < DAT_20002bcc) {
    DAT_20002bcc = 0xffffffff;
  }
  else {
    DAT_20002bcc = berTotalErrors;
  }
  DAT_20002bc8 = uVar4;
  return;
}



void RFTEST_ConfigBerRx(void)

{
  uint uVar1;
  
  write_volatile_4(FRC->DFLCTRL,5);
  write_volatile_4(MODEM->SYNC0,0x1dd3d4a0);
  setupPnForTest();
  uVar1 = (MODEM->TIMING);
  write_volatile_4(MODEM->TIMING,uVar1 & 0xfffff0ff);
  uVar1 = (MODEM->CTRL1);
  write_volatile_4(MODEM->CTRL1,uVar1 | 0x1f);
  uVar1 = (MODEM->AFC);
  write_volatile_4(MODEM->AFC,uVar1 & 0xffffe3ff);
  uVar1 = (MODEM->CTRL1);
  if ((uVar1 & 0xc000) == 0) {
    uVar1 = (MODEM->CTRL1);
    write_volatile_4(MODEM->CTRL1,uVar1 | 0xc000);
  }
  write_volatile_4(FRC->TRAILRXDATA,0);
  uVar1 = (FRC->RXCTRL);
  write_volatile_4(FRC->RXCTRL,uVar1 | 0x12);
  write_volatile_4(FRC->CTRL,4);
  return;
}



void RFTEST_ResetBerStats(uint32_t bytes)

{
  if (0x1ffffffe < bytes - 1) {
    bytes = 0x1fffffff;
  }
  berStats = bytes << 3;
  DAT_20002bc8 = 0;
  DAT_20002bcc = 0;
  DAT_20002bd0._0_1_ = 0;
  berInfiniteMode = 0;
  berTotalBits = 0;
  berTotalBytesLeft = bytes;
  berTotalErrors = 0;
  berSkipBytesLeft = berSkipBytes;
  return;
}



void RFTEST_ReportBerStats(RAIL_BerStatus_t *berstatus)

{
  uint32_t uVar1;
  uint32_t uVar2;
  undefined4 uVar3;
  
  uVar3 = DAT_20002bd0;
  uVar2 = DAT_20002bcc;
  uVar1 = DAT_20002bc8;
  berstatus->bitsTotal = berStats;
  berstatus->bitsTested = uVar1;
  berstatus->bitErrors = uVar2;
  *(undefined4 *)&berstatus->rssi = uVar3;
  return;
}



void RFTEST_StartBerRx(undefined4 param_1)

{
  RFTEST_BerStop();
  RFTEST_ConfigBerRx();
  RFTEST_ResetBerStats(param_1);
  RFTEST_StartRx();
  return;
}


