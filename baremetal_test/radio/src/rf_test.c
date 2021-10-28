#include "rf_test.h"
#include <stdbool.h>
#include "em_bus.h"
#include "em_assert.h"
#include "radio.h"
#include "radio_proc.h"


uint32_t rfparamsfbuffer[20] = {};
uint8_t testModeRegisterState;

uint32_t berSkipBytesLeft;
uint32_t berTotalBytesLeft;
uint32_t berTotalErrors;
uint32_t berTotalBits;
bool berInfiniteMode;
uint32_t berSkipBytes;

BerStatus_t berStats;

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
	while (RAC->STATUS & RAC_STATUS_STATE_Msk) {};
  RADIO_RxBufferReset();
	BUS_RegMaskedSet(&RAC->RXENSRCEN, 0x02);
}



void RFTEST_StopRx(void)

{
	BUS_RegMaskedClear(&RAC->RXENSRCEN, RAC_RXENSRCEN_SWRXEN_Msk);
  FRC->CMD = 1;

  //if ((RAC->STATUS << 4) >> 0x1c == 6)
	if((RAC->STATUS & RAC_STATUS_STATE_Msk) == 6)
  {
    RAC->CMD |= 0x40;
		RAC->CMD = RAC_CMD_CLEARRXOVERFLOW_Msk;
    RADIO_RxBufferReset();
  }
  while ((RAC->STATUS & RAC_STATUS_STATE_Msk) != 0);
}



void RFTEST_SaveRadioConfiguration(void)

{
  if (testModeRegisterState == 0) 
  {
    rfparamsfbuffer[0] = MODEM->AFC;
    rfparamsfbuffer[1] = MODEM->CTRL0;
    rfparamsfbuffer[2] = MODEM->CTRL1;
    rfparamsfbuffer[3] = MODEM->MODINDEX;
    rfparamsfbuffer[4] = MODEM->PRE;
    rfparamsfbuffer[5] = MODEM->TIMING;
    rfparamsfbuffer[6] = FRC->DFLCTRL;
    rfparamsfbuffer[7] = FRC->CTRL;
    rfparamsfbuffer[8] = FRC->FECCTRL;
    rfparamsfbuffer[9] = FRC->FCD0;
    rfparamsfbuffer[10] = FRC->FCD1;
    rfparamsfbuffer[11] = FRC->FCD2;
    rfparamsfbuffer[12] = FRC->FCD3;
    rfparamsfbuffer[13] = FRC->WHITECTRL;
    rfparamsfbuffer[14] = FRC->WHITEPOLY;
    rfparamsfbuffer[15] = FRC->WHITEINIT;
    rfparamsfbuffer[16] = SEQ->SYNTHLPFCTRLTX;
    rfparamsfbuffer[17] = FRC->SNIFFCTRL;
    rfparamsfbuffer[18] = FRC->IEN;
    FRC->IEN = 0;
    testModeRegisterState = 1;
  }
}



void RFTEST_RestoreRadioConfiguration(void)

{
  if (testModeRegisterState != 0) 
  {
    MODEM->AFC = rfparamsfbuffer[0];
    MODEM->CTRL0 = rfparamsfbuffer[1];
    MODEM->CTRL1 = rfparamsfbuffer[2];
    MODEM->MODINDEX = rfparamsfbuffer[3];
    MODEM->PRE = rfparamsfbuffer[4];
    MODEM->TIMING = rfparamsfbuffer[5];
    FRC->DFLCTRL = rfparamsfbuffer[6];
    FRC->CTRL = rfparamsfbuffer[7];
    FRC->FECCTRL = rfparamsfbuffer[8];
    FRC->FCD0 = rfparamsfbuffer[9];
    FRC->FCD1 = rfparamsfbuffer[10];
    FRC->FCD2 = rfparamsfbuffer[11];
    FRC->FCD3 = rfparamsfbuffer[12];
    FRC->WHITECTRL = rfparamsfbuffer[13];
    FRC->WHITEPOLY = rfparamsfbuffer[14];
    FRC->WHITEINIT = rfparamsfbuffer[15];
    SEQ->SYNTHLPFCTRLTX = rfparamsfbuffer[16];
    FRC->SNIFFCTRL = rfparamsfbuffer[17];
    FRC->IFC = 0x7ffff;
    FRC->IEN = rfparamsfbuffer[18];
    testModeRegisterState = 0;
  }
}





void RFTEST_StartCwTx(void)

{
  SEQ->SYNTHLPFCTRLTX &= 0xfffffff0;
	MODEM->MODINDEX = 0;
	BUS_RegMaskedClear(&MODEM->CTRL0, MODEM_CTRL0_MODFORMAT_Msk);
	BUS_RegMaskedSet(&MODEM->CTRL0, 0x100);
	BUS_RegMaskedSet(&MODEM->CTRL0, MODEM_PRE_TXBASES_Msk);
  FRC->DFLCTRL = 5;
	BUS_RegMaskedSet(&FRC->CTRL, FRC_CTRL_RANDOMTX_Msk);
	RAC->IFPGACTRL = 0x000087F6; //!!!
	RAC->CMD = 0x01; //TXEN
	//RAC->SGPACTRL0 |= (bootstrap << 3) | (cascode << 6) | (stripe << 0x18) | (slice  << 0xe);
}

void RFTEST_StartStreamTx(void)

{
  setupPnForTest();
  FRC->SNIFFCTRL = 0;
  FRC->DFLCTRL = 5;
	BUS_RegMaskedSet(&FRC->CTRL, FRC_CTRL_RANDOMTX_Msk);
	RAC->IFPGACTRL = 0x000087F6; //!!!
  RAC->CMD = 0x01; //TXEN
	//BM_TxOn(); //for test only
}





void RFTEST_StartTx(void)

{
  RAC->CMD = 0x01; //TXEN
}





void RFTEST_StopTx(void)

{
//this for FRC-TXaborted, flag should be cleared in callcack  
 // do{
//				if ((FRC->DFLCTRL & 7) != 5) 
//			{
//				RAC->CMD = 0x20; //TXDIS
//				return;
//			}
//		} while(FRC->IF & 0x04);
	BUS_RegMaskedSet(&FRC->IFC, FRC_IFC_TXABORTED_Msk);
  RAC->CMD = 0x20; //TXDIS
	//BM_TxOff(); //for test only
}



void RFTEST_BerStop(void)

{
	BUS_RegMaskedClear(&FRC->RXCTRL, FRC_RXCTRL_BUFRESTORERXABORTED_Msk);
  RFTEST_StopRx();
}



void RFTEST_BerEmptyBufcAndUpdateStats(void)

{
//  int iVar1;
//  uint uVar2;
//  int iVar3;
//
//  iVar1 = RADIO_RxBufferBytesAvailable();
//  while (iVar1 != 0)
//  {
//    uVar2 = RADIO_RxBufferReadByte();
//    if (berSkipBytesLeft == 0)
//    {
//      if ((berTotalBytesLeft != 0) || (berInfiniteMode != '\0')) {
//        berTotalBytesLeft = berTotalBytesLeft + -1;
//        berTotalErrors =
//             berTotalErrors +
//             ((uint32_t)(uint8_t)nibblebits[uVar2 & 0xf] +
//              (uint32_t)(uint8_t)nibblebits[(uVar2 << 0x14) >> 0x18] & 0xff);
//        berTotalBits = berTotalBits + 8;
//        iVar3 = RADIO_GetRSSI();
//        berStats->rssi = (int8_t)(iVar3 >> 2);
//      }
//    }
//    else
//    {
//      berSkipBytesLeft = berSkipBytesLeft + -1;
//    }
//    iVar1 = iVar1 + -1;
//  }
//  uVar2 = berTotalBits;
//  //if (berTotalBits < DAT_000103f0)
//  if (berTotalBits < (berStats->bytesTotal << 3))
//  {
//    uVar2 = 0xffffffff;
//  }
//  //if (berTotalErrors < DAT_000103f4)
//  if (berTotalErrors < berStats->bitErrors)
//  {
//    //DAT_000103f4 = 0xffffffff;
//	  berStats->bytesTested = 0xffffffff;
//  }
//  else
//  {
//    //DAT_000103f4 = berTotalErrors;
//    berStats->bitErrors = berTotalErrors;
//  }
//  //DAT_000103f0 = uVar2;
//  berStats->bytesTested = uVar2;
  return;
}


void RFTEST_ConfigBerRx(void)

{
  FRC->DFLCTRL = 5;
  MODEM->SYNC0 = 0x1dd3d4a0;
  setupPnForTest();
	BUS_RegMaskedClear(&MODEM->TIMING, MODEM_TIMING_TIMINGBASES_Msk); 
	BUS_RegMaskedSet(&MODEM->CTRL1, MODEM_CTRL1_SYNCBITS_Msk);
	BUS_RegMaskedClear(&MODEM->AFC, MODEM_AFC_AFCRXMODE_Msk);
  if ((MODEM->CTRL1 & MODEM_CTRL1_COMPMODE_Msk) == 0) BUS_RegMaskedSet(&MODEM->CTRL1, MODEM_CTRL1_COMPMODE_Msk);  
  FRC->TRAILRXDATA = 0;
	BUS_RegMaskedSet(&FRC->RXCTRL, FRC_RXCTRL_BUFCLEAR_Msk | FRC_RXCTRL_ACCEPTCRCERRORS_Msk);
  FRC->CTRL = FRC_CTRL_BITORDER_Msk;
}



void RFTEST_ResetBerStats(uint32_t bytes)

{
  if (0x1ffffffe < bytes - 1U)
  {
	  bytes = 0x1fffffff;
  }
  //berStats->bytesTotal = bytes << 3;
//  berStats->bytesTotal = bytes;
//  berStats->bytesTested = 0;
//  berStats->bitErrors = 0;
//  berStats->rssi = 0;
  berInfiniteMode = false;
  berSkipBytesLeft = berSkipBytes;
  berTotalBytesLeft = bytes;
  berTotalErrors = 0;
  berTotalBits = 0;
}


//typedef struct RAIL_BerStatus
//{
//  uint32_t bitsTotal; /**< Number of bits to receive */
//  uint32_t bitsTested; /**< Number of bits currently tested */
//  uint32_t bitErrors; /**< Number of bits errors detected */
//  int8_t   rssi; /**< Latched RSSI value at pattern detect */
//} RAIL_BerStatus_t;
/*
void RFTEST_ReportBerStats(RAIL_BerStatus_t *berstats)

{
  uint32_t uVar1;
  uint32_t uVar2;
  undefined4 uVar3;
  
  uVar3 = DAT_20002efc;
  uVar2 = DAT_20002ef8;
  uVar1 = DAT_20002ef4;
  berstats->bitsTotal = berStats;
  berstats->bitsTested = uVar1;
  berstats->bitErrors = uVar2;
  *(undefined4 *)&berstats->rssi = uVar3;
  return;
}
*/

void RFTEST_ReportBerStats(RAIL_BerStatus_t *berstatus)

{
  //undefined4 uVar1;
  //undefined4 uVar2;
  //undefined4 uVar3;
  
  //uVar3 = berStats->//DAT_000103f8;
  //uVar2 = berStats->//DAT_000103f4;
  //uVar1 = berStats->//DAT_000103f0;
  //*berstatus = berStats;
//  berstatus->bitsTotal = berStats->bytesTotal >> 3;
//  berstatus->bitsTested = berStats->bytesTested >> 3;
//  berstatus->bitErrors = berStats->bitErrors;
//  berstatus->rssi =	berStats->rssi;
  //param_1[1] = uVar1;
  //param_1[2] = uVar2;
  //param_1[3] = uVar3;
}



void RFTEST_StartBerRx(uint32_t bytes)

{
  RFTEST_BerStop();
  RFTEST_ConfigBerRx();
  RFTEST_ResetBerStats(bytes);
  RFTEST_StartRx();
}



