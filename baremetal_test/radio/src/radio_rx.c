#include "radio_rx.h"

void radio_configberrx(void);
void radio_resetberstats(uint32_t bytes);
void radio_reportberstats(RAIL_BerStatus_t *berstatus);
void radio_emptybufandupdatestats(void);

uint32_t berSkipBytesLeft;
uint32_t berTotalBytesLeft;
uint32_t berTotalErrors;
uint32_t berTotalBits;
bool berInfiniteMode;
uint32_t berSkipBytes;

RAIL_BerStatus_t berStats;

void radio_startrx(void)
{
	BUFC_RxBufferReset();	
	do 
		{ 
      if (RFHAL_HeadedToIdle() == 0) break;
    } while (RAC->STATUS & RAC_STATUS_STATE_Msk);
    INT_Disable();
		//SEQ_CONTROL_REG &= ~0x20; //SEQ_CONTROL_REG  & 0xffffffdf;
		INT_Enable();
		RAC->IFPGACTRL = 0x000087F6;
		//RAC->CMD = RAC_CMD_DEMODENSET_Msk;
  	BUS_RegMaskedSet(&RAC->RXENSRCEN, 2);
}

void radio_configberrx(void)

{
  FRC->DFLCTRL = 5;
  MODEM->SYNC0 = 0x1dd3d4a0;
  radio_setupPN9();
	BUS_RegMaskedClear(&MODEM->TIMING, MODEM_TIMING_TIMINGBASES_Msk); 
	BUS_RegMaskedSet(&MODEM->CTRL1, MODEM_CTRL1_SYNCBITS_Msk);
	BUS_RegMaskedClear(&MODEM->AFC, MODEM_AFC_AFCRXMODE_Msk);
  if ((MODEM->CTRL1 & MODEM_CTRL1_COMPMODE_Msk) == 0) BUS_RegMaskedSet(&MODEM->CTRL1, MODEM_CTRL1_COMPMODE_Msk);  
  FRC->TRAILRXDATA = 0;
	BUS_RegMaskedSet(&FRC->RXCTRL, FRC_RXCTRL_BUFCLEAR_Msk | FRC_RXCTRL_ACCEPTCRCERRORS_Msk);
  FRC->CTRL = FRC_CTRL_BITORDER_Msk;
}

void radio_startberrx(uint32_t bytes)
{
  radio_stopberrx();
  radio_configberrx();
  radio_resetberstats(bytes);
	while (RAC->STATUS & RAC_STATUS_STATE_Msk) {};
  BUFC_TxBufferReset();
	BUS_RegMaskedSet(&RAC->RXENSRCEN, 0x02);
}

/*
void RFTEST_StopRx(void)

{
	BUS_RegMaskedClear(&RAC->RXENSRCEN, RAC_RXENSRCEN_SWRXEN_Msk);
  FRC->CMD = 1;
	if((RAC->STATUS & RAC_STATUS_STATE_Msk) == 6)
  {
    RAC->CMD |= 0x40;
		RAC->CMD = RAC_CMD_CLEARRXOVERFLOW_Msk;
    BUFC_TxBufferReset();
  }
  while ((RAC->STATUS & RAC_STATUS_STATE_Msk) != 0);
}
*/

void radio_stopberrx(void)
{
	BUS_RegMaskedClear(&FRC->RXCTRL, FRC_RXCTRL_BUFRESTORERXABORTED_Msk);
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
	//RAC->IFPGACTRL = 0x000087F6; //!!!
	//RAIL_RfHalRxStart(Channel); //for test
	  if ((RAC->RXENSRCEN & 0xff) == 0) 
		{
			INT_Disable();
			BUFC->BUF1_CMD = 1;
			BUFC->BUF2_CMD = 1;
			FRC->IFC = 0x10;
			INT_Enable();
		}
			//RADIO_RxBufferReset();
    do 
		{ 
      if (RFHAL_HeadedToIdle() == 0) break;
    } while (RAC->STATUS & RAC_STATUS_STATE_Msk);
	//GENERIC_PHY_StartRx(0);

    INT_Disable();
		SEQ_CONTROL_REG &= ~0x20; //SEQ_CONTROL_REG  & 0xffffffdf;
		INT_Enable();
  	BUS_RegMaskedSet(&RAC->RXENSRCEN, 2);	
}

void radio_resetberstats(uint32_t bytes)

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

void radio_reportberstats(RAIL_BerStatus_t *berstatus)

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

void radio_emptybufandupdatestats(void)

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
