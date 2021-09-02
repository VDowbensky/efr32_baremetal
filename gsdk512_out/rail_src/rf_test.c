#include "rf_test.h"

//berSkipBytes[] = {0xf4,0x01,0,0};
//testModeRegisterState;
//berInfiniteMode;
//berStats;
//bufcCallbacks[16];

RAIL_BerStatus_t berStats;
RAIL_BerStatus_t berstatus;

uint32_t red_save[20]; //DAT_00010484

static const unsigned char nibblebits[16UL + 1] = {0x00, 0x01, 0x01, 0x02, 0x01, 0x02, 0x02, 0x03, 0x01, 0x02, 0x02, 0x03, 0x02, 0x03, 0x03, 0x04, 0x00};

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



void RFTEST_BerEmptyBufcAndUpdateStats(void)

{
  uint32_t i;
  uint32_t tmp;

  for (i = BUFC_RxBufferBytesAvailable(); i != 0; i--) 
  {
    tmp = BUFC_RxBufferReadByte();
    if (berSkipBytesLeft == 0) 
	{
      if ((berTotalBytesLeft != 0) || (berInfiniteMode != 0)) 
	  {
        berTotalBytesLeft -- ;
        berTotalErrors += (nibblebits[tmp & 0xf] + nibblebits[(tmp << 0x14) >> 0x18] & 0xff);
        berTotalBits = berTotalBits + 8;
        berStats->rssi = (int8_t)(RADIO_GetRSSI() >> 2);
      }
    }
    else berSkipBytesLeft --;
  }
  tmp = berTotalBits;
  if (berTotalBits < berStats->bitsTested) tmp = 0xffffffff;
  if (berTotalErrors < berStats->bitErrors) berStats->bitErrors = 0xffffffff;
  else berStats->bitErrors = berTotalErrors;
  berStats->bitsTested = tmp;
}



void RFTEST_StartRx(void)

{
  while ((RAC->STATUS & 0xf000000) != 0);
  BUFC_RxBufferReset();
  BUS_RegMaskedSet(&RAC->RXENSRCEN,2);
}



void RFTEST_StopRx(void)

{
  BUS_RegMaskedClear(&RAC->RXENSRCEN,0xff);
  CORE_EnterCritical();
  if ((RAC->STATUS << 4) >> 0x1c == 3) 
  {
	SEQ->REG06C &= 0xffffff0f;
	SEQ->REG06C |= 0xe0;
  }
  FRC->CMD = 1;
  CORE_ExitCritical();
  if ((RAC->STATUS << 4) >> 0x1c == 6) 
  {
    RAC->CMD = 0x40;
    BUFC_RxBufferReset();
  }
  while ((RAC->STATUS & 0xf000000) != 0);
}



void RFTEST_SaveRadioConfiguration(void)

{
  if (testModeRegisterState == 0) 
  {
    red_save[0] = MODEM->AFC;
    red_save[1] = MODEM->CTRL0;
    red_save[2] = MODEM->CTRL1;
    red_save[3] = MODEM->MODINDEX;
    red_save[4] = MODEM->PRE;
    red_save[5] = MODEM->TIMING;
    red_save[6] = FRC->DFLCTRL;
    red_save[7] = FRC->CTRL;
    red_save[8] = FRC->FECCTRL;
    red_save[9] = FRC->FCD0;
    red_save[10] = FRC->FCD1;
    red_save[11] = FRC->FCD2;
    red_save[12] = FRC->FCD3;
    red_save[13] = FRC->WHITECTRL;
    red_save[14] = FRC->WHITEPOLY;
    red_save[15] = FRC->WHITEINIT;
    red_save[16] = SEQ->SYNTHLPFCTRLTX;
    red_save[17] = FRC->SNIFFCTRL;
    red_save[18] = FRC->IEN;
    FRC->IEN = 0;
    testModeRegisterState = 1;
  }
}



void RFTEST_RestoreRadioConfiguration(void)

{
  if (testModeRegisterState != 0) 
  {
    MODEM->AFC = red_save[0];
    MODEM->CTRL0 = red_save[1];
    MODEM->CTRL1 = red_save[2];
    MODEM->MODINDEX = red_save[3];
    MODEM->PRE = red_save[4];
	//MODEM->TIMING = red_save[5]; 
    FRC->DFLCTRL = red_save[6];
    FRC->CTRL = red_save[7];
    FRC->FECCTRL = red_save[8];
    FRC->FCD0 = red_save[9];
    FRC->FCD1 = red_save[10];
    FRC->FCD2 = red_save[11];
    FRC->FCD3 = red_save[12];
    FRC->WHITECTRL = red_save[13];
    FRC->WHITEPOLY = red_save[14];
    FRC->WHITEINIT = red_save[15];
    SEQ->SYNTHLPFCTRLTX = red_save[16];
    FRC->SNIFFCTRL = red_save[17];
    FRC->IFC = 0x7ffff;
    FRC->IEN = red_save[18];
    testModeRegisterState = 0;
  }
}



void RFTEST_StartCwTx(void)

{
  SEQ->SYNTHLPFCTRLTX &= 0xfffffff0;
  if (MODEM->CTRL0 & 0x1c0 == 0xc0) 
  {
	MODEM->CTRL0 &= 0xfffffe3f;
	MODEM->CTRL0 |= 0x80;
  }
  else 
  {
    if ((MODEM->CTRL0 & 0x1c0 != 0x180) && (MODEM->CTRL0 & 0x1c0 != 0x80)) MODEM->MODINDEX = 0;
  }
  BUS_RegMaskedSet(&MODEM->PRE,0xffff000f);
  BUS_RegMaskedClear(&MODEM->PRE,0x30);
  FRC->DFLCTRL = 5;
  BUS_RegMaskedSet(&FRC->CTRL,1);
  RAC->CMD = 1;
}



void RFTEST_StartStreamTx(void)

{
  setupPnForTest();
  FRC->SNIFFCTRL = 0;
  FRC->DFLCTRL = 5;
  BUS_RegMaskedSet(&FRC->CTRL,1);
  RAC->CMD = 1;
}



void RFTEST_StartTx(void)

{
  RAC->CMD = 1;
}



void RFTEST_StopTx(void)

{
  RAC->CMD = 0x20;
  do 
  {
    if ((FRC->DFLCTRL & 7) != 5)  return;
  } while (-1 < (int)(FRC->IF << 0x1d));
}



void RFTEST_BerStop(void)

{
  BUS_RegMaskedClear(&FRC->RXCTRL,0x40);
  RFTEST_StopRx();
  BUS_RegMaskedClear(&BUFC->IEN,0x400);
}



void RFTEST_ConfigBerRx(void)

{
  uint uVar1;
  
  BUFC_SetCallbacks(&bufcCallbacks);
  BUFC_ConfigureCallbacks(4);
  BUFC->BUF1_THRESHOLDCTRL |= 100;
  FRC->DFLCTRL = 5;
  MODEM->SYNC0 = 0x1dd3d4a0;
  setupPnForTest();
  BUS_RegMaskedClear(&MODEM->TIMING,0xf00);
  MODEM->CTRL1 |= 0x1f;
  MODEM->AFC &= 0xffffe3ff;
  uVar1 = (MODEM->CTRL1);
  if ((MODEM->CTRL1 & 0xc000) == 0) BUS_RegMaskedSet(&MODEM->CTRL1,0xc000);
  FRC->TRAILRXDATA = 0;
  BUS_RegMaskedSet(&FRC->RXCTRL,0x12);
  FRC->CTRL = 4;
}



void RFTEST_ResetBerStats(uint32_t bytes)

{
  if (bytes > 0x1fffffff) bytes = 0x1fffffff;
  berStats->bitsTotal = bytes << 3;
  berStats->bitsTested = 0;
  berStats->bitErrors = 0;
  berStats->rssi = 0;
  berInfiniteMode = 0;
  berSkipBytesLeft = berSkipBytes;
  berTotalBytesLeft = bytes;
  berTotalErrors = 0;
  berTotalBits = 0;
}

void RFTEST_ReportBerStats(RAIL_BerStatus_t *berstatus)

{
  berstatus->bitsTotal = berStats->bitsTotal;
  berstatus->bitsTested = berStats->bitsTested;
  berstatus->bitErrors = berStats->bitErrors;
  berstatus->rssi = berStats->rssi;
}



void RFTEST_StartBerRx(uint32_t bytes)

{
  RFTEST_BerStop();
  RFTEST_ResetBerStats(bytes);
  BUS_RegMaskedSet(&BUFC->IEN,0x400);
  RFTEST_StartRx();
}


