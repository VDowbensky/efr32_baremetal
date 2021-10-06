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




void RFTEST_BerEmptyBufcAndUpdateStats(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  for (iVar1 = BUFC_RxBufferBytesAvailable(); iVar1 != 0; iVar1 = iVar1 + -1) 
  {
    uVar2 = BUFC_RxBufferReadByte();
    if (berSkipBytesLeft == 0) 
	{
      if ((berTotalBytesLeft != 0) || (berInfiniteMode != '\0')) 
	  {
        berTotalBytesLeft = berTotalBytesLeft + -1;
        berTotalErrors = berTotalErrors + ((uint)(byte)nibblebits_7220[uVar2 & 0xf] + (uint)(byte)nibblebits_7220[(uVar2 << 0x14) >> 0x18] & 0xff);
        berTotalBits = berTotalBits + 8;
        iVar3 = RADIO_GetRSSI();
        DAT_00010468._0_1_ = (undefined)(iVar3 >> 2);
      }
    }
    else berSkipBytesLeft = berSkipBytesLeft + -1;
  }
  uVar2 = berTotalBits;
  if (berTotalBits < DAT_00010460) uVar2 = 0xffffffff;
  if (berTotalErrors < DAT_00010464) DAT_00010464 = 0xffffffff;
  else DAT_00010464 = berTotalErrors;
  DAT_00010460 = uVar2;
}



void RFTEST_StartRx(void)

{
  while ((RAC->STATUS & 0xf000000) != 0);
  BUFC_RxBufferReset();
  BUS_RegMaskedSet(&RAC->RXENSRCEN,2);
}



void RFTEST_StopRx(void)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  
  
  iVar1 = 0xff;
  BUS_RegMaskedClear(&RAC->RXENSRCEN,0xff);
  irqState = CORE_EnterCritical();
  uVar2 = (RAC->STATUS << 4) >> 0x1c;
  bVar3 = uVar2 == 3;
  if (bVar3) 
  {
    iVar1 = 0x21000f64;
    uVar2 = SEQ->REG06C;
    uVar2 = uVar2 & 0xffffff0f | 0xe0;
  }
  if (bVar3) 
  {
    *(uint *)(iVar1 + 8) = uVar2;
  }
  FRC->CMD = 1;
  CORE_ExitCritical(irqState);
  if ((RAC->STATUS << 4) >> 0x1c == 6) 
  {
    RAC->CMD = 0x40;
    BUFC_RxBufferReset();
  }
  do 
  while ((RAC->STATUS & 0xf000000) != 0);
}



void RFTEST_SaveRadioConfiguration(void)

{
  if (testModeRegisterState == false) 
  {
    DAT_200030d8 = MODEM->AFC;
    DAT_200030dc = MODEM->CTRL0;
    DAT_200030e0 = MODEM->CTRL1;
    DAT_200030e4 = MODEM->MODINDEX;
    DAT_200030e8 = MODEM->PRE;
    DAT_200030ec = MODEM->TIMING;
    DAT_200030f0 = FRC->DFLCTRL;
    DAT_200030f4 = FRC->CTRL;
    DAT_200030f8 = FRC->FECCTRL;
    DAT_200030fc = FRC->FCD0;
    DAT_20003100 = FRC->FCD1;
    DAT_20003104 = FRC->FCD2;
    DAT_20003108 = FRC->FCD3;
    DAT_2000310c = FRC->WHITECTRL;
    DAT_20003110 = FRC->WHITEPOLY;
    DAT_20003114 = FRC->WHITEINIT;
    DAT_20003118 = SEQ->SYNTHLPFCTRLTX;
    DAT_2000311c = FRC->SNIFFCTRL;
    DAT_20003120 = FRC->IEN;
    FRC->IEN = 0;
    testModeRegisterState = true;
  }
}



void RFTEST_RestoreRadioConfiguration(void)

{
  if (testModeRegisterState != false) 
  {
    MODEM->AFC = DAT_200030d8;
    MODEM->CTRL0 = DAT_200030dc;
    MODEM->CTRL1 = DAT_200030e0;
    MODEM->MODINDEX = DAT_200030e4;
    MODEM->PRE = DAT_200030e8;
    FRC->DFLCTRL = DAT_200030f0;
    FRC->CTRL = DAT_200030f4;
    FRC->FECCTRL = DAT_200030f8;
    FRC->FCD0 = DAT_200030fc;
    FRC->FCD1 = DAT_20003100;
    FRC->FCD2 = DAT_20003104;
    FRC->FCD3 = DAT_20003108;
    FRC->WHITECTRL = DAT_2000310c;
    FRC->WHITEPOLY = DAT_20003110;
    FRC->WHITEINIT = DAT_20003114;
    SEQ->SYNTHLPFCTRLTX = DAT_20003118;
    FRC->SNIFFCTRL = DAT_2000311c;
    FRC->IFC = 0x7ffff;
    FRC->IEN = DAT_20003120;
    testModeRegisterState = false;
  }
}



void RFTEST_StartCwTx(void)

{
  SEQ->SYNTHLPFCTRLTX &= 0xfffffff0;
  if ((MODEM->CTRL0 & 0x1c0) == 0xc0) 
  {
	MODEM->CTRL0 &= 0xfffffe3f;
	MODEM->CTRL0 |= 0x80;
  }
  else 
  {
    if (((MODEM->CTRL0 & 0x1c0) != 0x180) && ((MODEM->CTRL0 & 0x1c0) != 0x80)) MODEM->MODINDEX = 0; 
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
    if ((FRC->DFLCTRL & 7) != 5) return;
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
  BUFC_SetCallbacks(&bufcCallbacks);
  BUFC_ConfigureCallbacks(4);
  BUFC->BUF1_THRESHOLDCTRL &= 0xfffff000;
  BUFC->BUF1_THRESHOLDCTRL |= 100;
  FRC->DFLCTRL = 5;
  MODEM->SYNC0 = 0x1dd3d4a0;
  setupPnForTest();
  BUS_RegMaskedClear(&MODEM->TIMING,0xf00);
  MODEM->CTRL1 |= 0x1f;
  MODEM->AFC &= 0xffffe3ff;
  if ((MODEM->CTRL1 & 0xc000) == 0) BUS_RegMaskedSet(&MODEM->CTRL1,0xc000);
  FRC->TRAILRXDATA = 0;
  BUS_RegMaskedSet(&FRC->RXCTRL,0x12);
  FRC->CTRL = 4;
}



void RFTEST_ResetBerStats(int32_t bytes)

{
  if (0x1ffffffe < bytes - 1U) bytes = 0x1fffffff;
  berStats = bytes << 3;
  DAT_00010460 = 0;
  DAT_00010464 = 0;
  DAT_00010468._0_1_ = 0;
  berInfiniteMode = 0;
  berSkipBytesLeft = berSkipBytes;
  berTotalBytesLeft = bytes;
  berTotalErrors = 0;
  berTotalBits = 0;
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
}



void RFTEST_StartBerRx(undefined4 param_1)

{
  RFTEST_BerStop();
  RFTEST_ResetBerStats(param_1);
  BUS_RegMaskedSet(&BUFC->IEN,0x400);
  RFTEST_StartRx();
}


