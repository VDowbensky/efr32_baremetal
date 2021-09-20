#include "rf_test.h"



void setupPnForTest(void)

{
  FRC->FCD0 &= 0xffffbfff;
  FRC->FCD1 &= 0xffffbfff;
  FRC->FCD2 &= 0xffffbfff;
  FRC->FCD3 &= 0xffffbfff;
  FRC->FECCTRL = 1;
  FRC->WHITECTRL = 0x24;
  FRC->WHITEPOLY = 0x100;
  FRC->WHITEINIT = 0x138;
}



void RFTEST_StartRx(void)

{
  while ((RAC->STATUS & RAC_STATUS_STATE_Msk) != 0);
  RADIO_RxBufferReset();
  _DAT_43080004 = 1;
}



void RFTEST_StopRx(void)

{
  RAC->RXENSRCEN &= 0xffffff00;
  FRC->CMD = 1;
  if ((RAC->STATUS & RAC_STATUS_STATE_Msk) >> RAC_STATUS_STATE_Pos == 6) 
  {
	RAC->CMD |= 0x40;
    RADIO_RxBufferReset();
  }
  while ((RAC->STATUS & RAC_STATUS_STATE_Msk) != 0);
}



void RFTEST_SaveRadioConfiguration(void)

{
  if (testModeRegisterState == 0) 
  {
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
    FRC->IEN = 0;
    testModeRegisterState = 1;
  }
  return;
}



void RFTEST_RestoreRadioConfiguration(void)

{
  if (testModeRegisterState != 0) 
  {
    MODEM->AFC = DAT_00010404;
    MODEM->CTRL0 = DAT_00010408;
    MODEM->CTRL1 = DAT_0001040c;
    MODEM->MODINDEX = DAT_00010410;
    MODEM->PRE = DAT_00010414;
    FRC->DFLCTRL = DAT_0001041c;
    FRC->CTRL = DAT_00010420;
    FRC->FECCTRL = DAT_00010424;
    FRC->FCD0 = DAT_00010428;
    FRC->FCD1 = DAT_0001042c;
    FRC->FCD2 = DAT_00010430;
    FRC->FCD3 = DAT_00010434;
    FRC->WHITECTRL = DAT_00010438;
    FRC->WHITEPOLY = DAT_0001043c;
    FRC->WHITEINIT = DAT_00010440;
    SEQ->SYNTHLPFCTRLTX = DAT_00010444;
    FRC->SNIFFCTRL = DAT_00010448;
    FRC->IFC = 0x7ffff;
    FRC->IEN = DAT_0001044c;
    testModeRegisterState = 0;
  }
}



void RFTEST_StartCwTx(void)

{
  SEQ->SYNTHLPFCTRLTX &= 0xfffffff0;
  MODEM->MODINDEX = 0;
  MODEM->CTRL0 &= 0xfffffe3f;
  MODEM->CTRL0 |= 0x100;
  uVar1 = (MODEM->PRE);
  MODEM->PRE = ~(~(MODEM->PRE << 0x10) >> 0x10);
  FRC->DFLCTRL = 5;
  _DAT_43000800 = 1;
  _DAT_43080100 = 1;
}



void RFTEST_StartStreamTx(void)

{
  setupPnForTest();
  FRC->SNIFFCTRL = 0;
  FRC->DFLCTRL = 5;
  _DAT_43000800 = 1;
  _DAT_43080100 = 1;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void RFTEST_StartTx(void)

{
  _DAT_43080100 = 1;
}



void RFTEST_StopTx(void)

{
  uint uVar1;
  
  do 
  {
    if ((FRC->DFLCTRL & 7) != 5) 
	{
      _DAT_43080114 = 1;
      return;
    }
  } while (-1 < (int)(FRC->IF << 0x1d));
  _DAT_43080114 = 1;
}



void RFTEST_BerStop(void)

{
  FRC->RXCTRL &= 0xffffffbf;
  RFTEST_StopRx();
}



void RFTEST_BerEmptyBufcAndUpdateStats(void)

{
  byte bVar1;
  uint16_t uVar2;
  int16_t iVar3;
  uint uVar4;
  
  uVar2 = RADIO_RxBufferBytesAvailable();
  for (uVar4 = (uint)uVar2; uVar4 != 0; uVar4 = uVar4 - 1) 
  {
    bVar1 = RADIO_RxBufferReadByte();
    if (berSkipBytesLeft == 0) {
      if ((berTotalBytesLeft != 0) || (berInfiniteMode != '\0')) 
	  {
        berTotalBytesLeft = berTotalBytesLeft + -1;
        berTotalErrors = berTotalErrors + ((uint)(byte)(&nibblebits_6976)[bVar1 & 0xf] + (uint)(byte)(&nibblebits_6976)[((uint)bVar1 << 0x14) >> 0x18] & 0xff);
        berTotalBits = berTotalBits + 8;
        iVar3 = RADIO_GetRSSI();
        DAT_20002bd0._0_1_ = (undefined)(iVar3 >> 2);
      }
    }
    else berSkipBytesLeft --;
  }
  uVar4 = berTotalBits;
  if (berTotalBits < DAT_20002bc8) uVar4 = 0xffffffff;
  if (berTotalErrors < DAT_20002bcc) DAT_20002bcc = 0xffffffff;
  else DAT_20002bcc = berTotalErrors;
  DAT_20002bc8 = uVar4;
}



void RFTEST_ConfigBerRx(void)

{
  FRC->DFLCTRL = 5;
  MODEM->SYNC0 = 0x1dd3d4a0;
  setupPnForTest();
  MODEM->TIMING &= 0xfffff0ff;
  MODEM->CTRL1 |= 0x1f;
  MODEM->AFC &= 0xffffe3ff;
  uVar1 = (MODEM->CTRL1);
  if ((MODEM->CTRL1 & 0xc000) == 0) MODEM->CTRL1 |= 0xc000;
  FRC->TRAILRXDATA = 0;
  FRC->RXCTRL |= 0x12;
  FRC->CTRL = 4;
}



void RFTEST_ResetBerStats(uint32_t bytes)

{
  if (0x1ffffffe < bytes - 1) bytes = 0x1fffffff;
  berStats = bytes << 3;
  DAT_20002bc8 = 0;
  DAT_20002bcc = 0;
  DAT_20002bd0._0_1_ = 0;
  berInfiniteMode = 0;
  berTotalBits = 0;
  berTotalBytesLeft = bytes;
  berTotalErrors = 0;
  berSkipBytesLeft = berSkipBytes;
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
}



void RFTEST_StartBerRx(uint32_t bytes)

{
  RFTEST_BerStop();
  RFTEST_ConfigBerRx();
  RFTEST_ResetBerStats(bytes);
  RFTEST_StartRx();
}


