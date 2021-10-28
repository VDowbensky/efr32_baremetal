#include "generic_phy.h"
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include "em_bus.h"
#include "em_int.h"
#include "em_assert.h"
#include "protimer.h"
#include "pa.h"
#include "radio.h"
//#include "RADIO_pti.h"
#include "generic_seq.h"
//#include "tempcal.h"
#include "synth.h"
//#include "rf_rand.h"
#include "em_cmu.h"
//#include "radio_cmu.h"


uint32_t currentCallbacks[] = {};
uint32_t availableCallbacks;

	
uint32_t _enabledCallbacks;	

void GENERIC_PHY_RAC_IRQCallback(void)

{
	uint32_t uVar1;
	uint32_t flags;

  flags = RAC->IEN & RAC->IF;
  RAC->IFC = flags;

  if(flags & RAC_IEN_STATECHANGE_Msk) //STATECHANGE
  {
  //  (**(code **)(currentCallbacks + 0x30))();
  }
  if(flags & RAC_IEN_BUSERROR_Msk) //BUSERROR
  {
  //  (**(code **)(currentCallbacks + 0x2c))(); 
  }
  if(flags & RAC_IEN_PAVHIGH_Msk) //25 - PAVHIGH
  {
    //if ((uint32_t)DAT_00010db1 & 0x20)
    //{
   //  (**(code **)(currentCallbacks + 0x34))();
    //}
    PA_PeakDetectorHighRun();
  }
  if(flags & RAC_IEN_PAVLOW_Msk) //26 - PAVLOW
  {
    //if ((int)((uint32_t)DAT_00010db1 << 0x19) < 0)
   // if((uint32_t)enabledCallbacks & 0x40)
   // {
    //  (**(code **)(currentCallbacks + 0x38))();
   // }
    PA_PeakDetectorLowRun();
  }
  if(flags & RAC_IEN_PABATHIGH_Msk) //27 - PABATHIGH
  {
   // if ((char)enabledCallbacks < 0x30)
    //{
    //  (**(code **)(currentCallbacks + 0x3c))(); 
   // }
    PA_BatHighRun();
  }
  flags &= RAC_IEN_SEQ_Msk;
  if (flags != 0) 
		{
    if ((flags & 0x800000) != 0) //bit 19 seq. interrupt
    {
      //if ((uint32_t)DAT_00010db2 & 0x80000000) //enabledCallbacks +2
      //{
      //(**(code **)(currentCallbacks + 0x40))(); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
      //}
      flags &= 0x7f0000; //16...22 sequencer interrupts
    }
//    if ((*(code **)(currentCallbacks + 0x44) != NULL) && (uVar1 != 0))
//    {
//     // (**(code **)(currentCallbacks + 0x44))(); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//      return;
   }
//  }
  return;
}



void GENERIC_PHY_PROTIMER_IRQCallback(void)

{
  uint32_t flags;
  flags = PROTIMER->IEN & PROTIMER->IF;
  PROTIMER->IFC = flags;
  //unfortunately bitfields missing
  if ((flags & 0x501000) != 0)
  {
    //(**(code **)(currentCallbacks + 0x4c))(flags); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  }
  if(flags & 0x0400) 
  {
   // (**(code **)(currentCallbacks + 0x50))(); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  }
}



void GENERIC_PHY_MODEM_IRQCallback(void)

{
  uint32_t flags;
  flags = MODEM->IEN & MODEM->IF;
  MODEM->IFC = flags;

  if(flags & MODEM_IF_RXPRELOST_Msk) //preamble lost
  {
 //   (**(code **)(currentCallbacks + 0x1c))(); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  }

  if(flags & MODEM_IF_RXPREDET_Msk) //preamble detected
  {
  //  (**(code **)(currentCallbacks + 0x20))(); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  }

  if(flags & MODEM_IF_RXFRAMEDET0_Msk) //frame 0 detected
  {
  //  (**(code **)(currentCallbacks + 0x24))(); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  }

  if(flags & MODEM_IF_RXFRAMEDET1_Msk)  //frame 1 detected
  {
   // (**(code **)(currentCallbacks + 0x28))(); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  }
}

void GENERIC_PHY_FRC_IRQCallback(void)

{
  uint32_t flags;

  flags = FRC->IEN & FRC->IF;
  FRC->IFC = flags;
  
  SEQ->REG004 = flags;
	if(flags & FRC_IF_RXDONE_Msk)
  {
   // (*currentCallbacks[2])(); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    if (RADIO_RxBufferPacketAvailable() != 0) FRC->IFS = 0x10;
  }
  else
  {
    if(flags & FRC_IF_FRAMEERROR_Msk)
    {
     // (*currentCallbacks[3])(); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    }
  }
  if ((flags & (FRC_IEN_TXDONE_Msk | FRC_IEN_TXAFTERFRAMEDONE_Msk)) != 0) //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  {
		PROTIMER_CCTimerStop(3);
	//	if(enabledCallbacks & 0x01)	(*currentCallbacks)(0);//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  } 

	if((flags & FRC_IF_RXOF_Msk) && ((RAC->STATUS & RAC_STATUS_STATE_Msk) == 0x6000000))
  {
    //if(enabledCallbacks & 0x10)
    //{
     // (*currentCallbacks[4])(); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //}
	  if(FRC->IF & FRC_IF_RXDONE_Msk)
    {
      FRC->IFS |= 0x100; //???FRC->IFS |= 0x10;
    }
    else
    {
      RADIO_FRCErrorHandle();
      //_DAT_4308010c = 1;
      //_DAT_43080004 = _DAT_21000f00 & 0x200;
      //if (_DAT_43080004 != 0)
      //{
      //  _DAT_43080004 = 1;
      //}
      //_DAT_43080118 = 1;
    }
  }

	if((flags & FRC_IF_TXABORTED_Msk) && (!(FRC->CTRL & FRC_CTRL_RANDOMTX_Msk)))
  {
//    (*currentCallbacks[1])();
  }

	if(flags & FRC_IF_TXUF_Msk) //tx underflow
  {
//    (*currentCallbacks[1])();
  }
	if(flags & FRC_IF_RXRAWEVENT_Msk)
  {
//    (*currentCallbacks[5])();
  }
	if(flags & FRC_IF_BUSERROR_Msk)
  {
//    (*currentCallbacks[6])();
  }
}

void GENERIC_PHY_SetAddressFilteringMatchTable(void)

{
//  uint uVar1;
//  uint uVar2;
//  uint uVar3;
//  uint uVar4;
//  uint uVar5;
//  uint uVar6;
//  uint uVar7;
//  uint uVar8;
//  int iVar9;
//  uint *puVar10;
//  uint uVar11;
//  uint local_38;
//  uint local_34;
//
//  uVar4 = 0;
//  local_34 = 0;
//  uVar2 = 0;
//  do {
//    uVar5 = uVar2 + 1;
//    uVar1 = uVar5 * 5;
//    uVar11 = addressFilterMatchTable >> (uVar1 & 0xff) & 0x1f;
//    uVar6 = addressFilterMatchTable >> (uVar5 & 0xff) & 0x108421;
//    uVar8 = uVar5 * 8;
//    uVar7 = uVar5;
//    local_38 = uVar1;
//    while (local_38 = local_38 + 5, uVar7 != 4)
//    {
//      puVar10 = (uint *)&DAT_21000f08;
//      uVar3 = 1 << (uVar7 & 0xff) | 1 << (uVar2 & 0xff);
//      if ((uVar3 & DAT_21000f50) == uVar3)
//      {
//        iVar9 = 0;
//        while (iVar9 < (int)(uint)DAT_21000f4e)
//        {
//          puVar10 = puVar10 + 1;
//          if (((*puVar10 >> (uVar8 & 0xff) ^ *puVar10 >> (uVar4 & 0xff)) & 0xff) != 0)
//          goto LAB_000102ee;
//          iVar9 = iVar9 + 1;
//        }
//        uVar11 = uVar11 | addressFilterMatchTable >> (local_38 & 0xff) & 0x1f;
//      }
//LAB_000102ee:
//      if ((uVar3 & DAT_21000f51) == uVar3)
//      {
//        iVar9 = 0;
//        puVar10 = (uint *)0x21000f28;
//        while (iVar9 < (int)(uint)DAT_21000f4f)
//        {
//          puVar10 = puVar10 + 1;
//          if (((*puVar10 >> (uVar8 & 0xff) ^ *puVar10 >> (uVar4 & 0xff)) & 0xff) != 0)
//          goto LAB_00010336;
//          iVar9 = iVar9 + 1;
//        }
//        uVar6 = uVar6 | addressFilterMatchTable >> (uVar7 + 1 & 0xff) & 0x108421;
//      }
//LAB_00010336:
//      uVar7 = uVar7 + 1;
//      uVar8 = uVar8 + 8;
//    }
//    local_34 = local_34 | uVar6 << (uVar5 & 0xff) | uVar11 << (uVar1 & 0xff);
//    uVar4 = uVar4 + 8;
//    uVar2 = uVar5;
//    if (uVar5 == 4) {
//     // _DAT_21000f08 = local_34;
//      SEQ->REG008 = local_34;
//      return;
//    }
//  } while( true );
}





void GENERIC_PHY_ConfigureCallbacks(uint32_t callbacks)

{
//  uint32_t tmp;
//  uint32_t cbs;
//  uint32_t uVar3;
//  uint32_t interrupts;
//  char local_c;
//  uint8_t bStack11;
//  uint8_t bStack10;
//
//  _enabledCallbacks = callbacks & availableCallbacks;
//  cbs = _enabledCallbacks & 0xff;
//  interrupts = 0x101;
//  if (_enabledCallbacks & 1) interrupts = 0x103;
//  if(cbs & 0x02) interrupts |= 0xc;
//  if(cbs & 0x04) interrupts |= 0x10;
//  if(cbs & 0x08) interrupts |= 0x40;
//  if(cbs & 0x10) interrupts |= 0x120;
//  if(cbs & 0x20) interrupts |= 0x4000;
//  if(cbs & 0x40) interrupts |= 0x2000;
//  tmp = FRC->IEN;
//  uVar3 = tmp & (interrupts ^ tmp);
//  FRC->IFC = uVar3;
// // uVar2 = FRC->IEN;
//  interrupts = interrupts & (interrupts ^ tmp);
//  FRC->IEN = FRC->IEN & ~uVar3;
//
//  FRC->IFC = interrupts;
//  uVar2 = FRC->IEN;
//
//  FRC->IEN = interrupts | uVar2;
//  local_c = (char)_enabledCallbacks;
//  bStack11 = (byte)(_enabledCallbacks >> 8);
//  uVar2 = (uint)bStack11;
//  if (local_c < 0) interrupts = 0x2000;
//  else interrupts = 0;
//  if(uVar2 & 0x01) interrupts |= 0x200;
//  if(uVar2 & 0x02) interrupts |= 0x400;
//  uVar1 = MODEM->IEN;
//  if(uVar2 & 04) uVar4 = uVar4 | 0x800;
//  uVar3 = uVar1 & (interrupts ^ uVar1);
//  MODEM->IFC = uVar3;
//  uVar2 = MODEM->IEN;
//  interrupts = interrupts & (interrupts ^ uVar1);
//  MODEM->IEN = uVar2 & ~uVar3;
//  MODEM->IFC= interrupts;
//  uVar2 = MODEM->IEN;
//  MODEM->IEN = interrupts | uVar2;
//  if ((_enabledCallbacks & 0x800) == 0) uVar2 = 0;
//  else uVar2 = 4; 
//  bStack10 = (byte)(_enabledCallbacks >> 0x10);
//  if(bStack11 & 0x10) uVar2 |= 1;
//  if(bStack10 & 0x01) uVar2 |= 0x800000;
//  uVar4 = RAC->IEN;
//  if(bStack10 & 0x02) uVar2 |= 0xff0000;
//  uVar3 = uVar4 & (uVar2 ^ uVar4);
//  RAC->IFC = uVar3;
//  uVar1 = RAC->IEN;
//  uVar2 = uVar2 & (uVar2 ^ uVar4);
//  RAC->IEN = uVar1 & ~uVar3;
//  RAC->IFC = uVar2;
//  uVar4 = RAC->IEN;
//  RAC->IEN = uVar2 | uVar4;
//  uVar2 = 0x501000;
//  if ((_enabledCallbacks & 0x80000) == 0) uVar2 = 0;
//  uVar4 = PROTIMER->IEN;
//  if(bStack10 & 0x10) uVar2 |= 0x400;
//  uVar3 = uVar4 & (uVar2 ^ uVar4);
//  PROTIMER->IFC = uVar3;
//  uVar1 = PROTIMER->IEN;
//  uVar2 = uVar2 & (uVar2 ^ uVar4);
//  PROTIMER->IEN = uVar1 & ~uVar3;
//  PROTIMER->IFC = uVar2;
//  uVar4 = PROTIMER->IEN;
//  PROTIMER->IEN = uVar2 | uVar4;
  return;
}

void GENERIC_PHY_SetCallbacks(int32_t param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;

  NVIC_ClearPendingIRQ(PROTIMER_IRQn);
  NVIC_DisableIRQ(PROTIMER_IRQn);
  uVar2 = 0;
  availableCallbacks = 0;
  if (param_1 != 0) 
	{
    uVar1 = 0;
    do {
      if (*(int *)(param_1 + uVar1 * 4) != 0) 
			{
        uVar2 = uVar2 | 1 << (uVar1 & 0xff);
      }
      uVar1 = uVar1 + 1;
      availableCallbacks = uVar2;
    } while (uVar1 != 0x15);
  }
  //currentCallbacks = param_1; //!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  GENERIC_PHY_ConfigureCallbacks(0xffffffff);
  NVIC_EnableIRQ(PROTIMER_IRQn);
  NVIC_ClearPendingIRQ(PROTIMER_IRQn);
}



void GENERIC_PHY_LoadTxPacketBuffer(uint8_t *buf)

{
  INT_Disable();
 // RADIO_TxBufferSet(*(uint32_t *)(buf + 2),*buf,0,0); //!!!!!!!!!!!!!!!!!!!!!!!!!
  INT_Enable();
}



void GENERIC_PHY_FlushTxPacketBuffer(void)

{
  INT_Disable();
  RADIO_TxBufferReset();
  INT_Enable();
}





void GENERIC_PHY_PacketTxCommon(void)

{
  if ((FRC->DFLCTRL & FRC_DFLCTRL_DFLMODE_Msk) == 0) FRC->WCNTCMP0 = RADIO_TxBufferBytesAvailable() - 1; 
  *(uint32_t*)0x21000efc = *(uint32_t*)0x21000efc & 0xffffffdf;
}





uint32_t GENERIC_PHY_PacketTx(void)

{
  INT_Disable();
  if ((PROTIMER_CCTimerIsEnabled(3) == 0) && (PROTIMER_LBTIsActive() == 0)) 
	{
    GENERIC_PHY_PacketTxCommon();
		RAC->CMD = RAC_CMD_TXEN_Msk;
    INT_Enable();
    return 0;
  }
  INT_Enable();
  return 1;
}





uint32_t GENERIC_PHY_SchedulePacketTx(uint32_t param_1,uint32_t param_2)

{
  INT_Disable();
  if ((PROTIMER_CCTimerIsEnabled(3) == 0) && (PROTIMER_LBTIsActive() == 0)) 
	{
    GENERIC_PHY_PacketTxCommon();
  //  if (PROTIMER_ScheduleTxEnable(3,param_1,param_2) == 0) //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    {
			RAC->CMD = RAC_CMD_TXEN_Msk;
    }
    INT_Enable();
    return 0;
  }
  INT_Enable();
  return 1;
}





void GENERIC_PHY_StopTx(void)

{
  RAC->CMD |= RAC_CMD_CLEARTXEN_Msk;
}



uint32_t GENERIC_PHY_PacketRxDataHelper(int32_t param_1,uint32_t param_2)

{
  RADIO_RxBufferBytesAvailable();
  if (param_1 == 0)
  {
 //   RADIO_RxBufferDropBytes(param_2);
  }
  else
  {
//    RADIO_RxBufferReadBytes(param_1,param_2 & 0xff);
  }
  return param_2;
}



uint32_t GENERIC_PHY_PacketRxAppendedInfoHelper(uint32_t param_1,void *param_2)

{
  uint16_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  bool bVar6;
  void *apvStack28 [3];
  
  apvStack28[0] = param_2;
//  apvStack28[1] = (void *)param_3;
//  apvStack28[2] = (void *)param_4;
  if (param_2 == NULL)
  {
//    RADIO_RxBufferDropBytes();
  }
  else
  {
   // RADIO_RxBufferReadBytes(apvStack28,(param_1 & 0xff),param_3,&FRC,param_1); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    uVar3 = 0x14;
    memset(param_2,0,0x14);
    uVar5 = param_1;
    if (FRC->TRAILRXDATA & FRC_TRAILRXDATA_RTCSTAMP_Msk)
    {
      uVar5 = param_1 - 4 & 0xffff;
      uVar3 = *(uint32_t *)((int)apvStack28 + uVar5);
    }
    if (FRC->TRAILRXDATA & FRC_TRAILRXDATA_RTCSTAMP_Msk) *(uint32_t *)((int)param_2 + 0x10) = uVar3;
		
    if (FRC->TRAILRXDATA & FRC_TRAILRXDATA_PROTIMERCC0WRAPH_Msk)
    {
      uVar5 = uVar5 - 2 & 0xffff;
      *(uint32_t *)((int)param_2 + 0xc) =
           *(uint32_t *)((int)param_2 + 0xc) | (uint32_t)*(uint16_t *)((int)apvStack28 + uVar5) << 0x10;
    }

    if (FRC->TRAILRXDATA & FRC_TRAILRXDATA_PROTIMERCC0WRAPL_Msk)
    {
      uVar5 = uVar5 - 2 & 0xffff;
      uVar4 = (uint32_t)*(uint16_t *)((int)apvStack28 + uVar5) | *(uint32_t *)((int)param_2 + 0xc);
      *(uint32_t *)((int)param_2 + 0xc) = uVar4;
    }
    uVar2 = (uint16_t)uVar4;
		
    if (FRC->TRAILRXDATA & FRC_TRAILRXDATA_PROTIMERCC0BASE_Msk)
    {
      uVar5 = uVar5 - 2 & 0xffff;
      uVar2 = *(uint16_t *)((int)apvStack28 + uVar5);
			*(uint16_t *)((int)param_2 + 8) = uVar2;
    }
//    if (FRC->TRAILRXDATA & FRC_TRAILRXDATA_PROTIMERCC0BASE_Msk) 
//		{
//      *(uint16_t *)((int)param_2 + 8) = uVar2;
//    }
		
    if (FRC->TRAILRXDATA & FRC_TRAILRXDATA_CRCOK_Msk)
    {
      uVar5 = uVar5 - 1 & 0xffff;
      *(uint8_t *)((int)param_2 + 6) = *(uint8_t *)((int)apvStack28 + uVar5) >> 7;
    }
		
    if (FRC->TRAILRXDATA & FRC_TRAILRXDATA_RSSI_Msk)
    {
      uVar5 = (uint32_t)*(uint8_t *)((int)apvStack28 + (uVar5 - 1 & 0xffff));
			*(char *)((int)param_2 + 5) = (char)uVar5;
    }
//    if (FRC->TRAILRXDATA & FRC_TRAILRXDATA_RSSI_Msk)
//    {
//      *(char *)((int)param_2 + 5) = (char)uVar5;
//    }
  }
  return param_1;
}



uint32_t GENERIC_PHY_PacketRxHelper(int param_1,uint32_t param_2,uint32_t param_3)

{
  uint32_t len;

  len = param_1 - RADIO_RxTrailDataLength()& 0xffff;
  GENERIC_PHY_PacketRxDataHelper(param_2,param_1 - RADIO_RxTrailDataLength()& 0xffff);
  //GENERIC_PHY_PacketRxAppendedInfoHelper(RADIO_RxTrailDataLength(),param_3); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  return len;
}



void GENERIC_PHY_PacketRxGet(uint16_t *param_1)

{
  uint16_t uVar1;
  uint32_t rxaddr;
  int iVar3;
  uint32_t local_24;
  uint32_t uStack32;
  uint32_t uStack28;
  uint32_t uStack24;
  uint32_t local_14;
  
  if (param_1 != NULL)
  {
    rxaddr = RADIO_RxBufferGet();
//    iVar3 = RADIO_RxLengthReadNext(); //!!!!!!!!!!!!!!!!!!!!
    if (iVar3 == 0xffff)
    {
      *(uint32_t *)(param_1 + 2) = 0;
      *param_1 = 0;
    }
    else
    {
//      uVar1 = GENERIC_PHY_PacketRxHelper(iVar3,uVar2,&local_24);//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
      *(uint32_t *)(param_1 + 2) = rxaddr;
      *param_1 = uVar1;
      *(uint32_t *)(param_1 + 4) = local_24;
      *(uint32_t *)(param_1 + 6) = uStack32;
      *(uint32_t *)(param_1 + 8) = uStack28;
      *(uint32_t *)(param_1 + 10) = uStack24;
      *(uint32_t *)(param_1 + 0xc) = local_14;
 //     if (*(code **)(currentCallbacks + 0x48) != NULL) //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 //     {
 //       uVar2 = (**(code **)(currentCallbacks + 0x48))();
 //     }
      RADIO_RxBufferSet(rxaddr);
    }
  }
  return;
}





void GENERIC_PHY_StartRx(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) FRC->WCNTCMP0 = param_1 - 1;

//  if ((RADIO_RxBufferGet() == 0) && (*(code **)(currentCallbacks + 0x48) != NULL) //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//		  {
//	  	  	  (**(code **)(currentCallbacks + 0x48))();
//	  	  	  	 RADIO_RxBufferSet();
//		  }
  *(uint32_t*)0x21000efc = *(uint32_t*)0x21000efc  & 0xffffffdf;
//	BUS_RegMaskedSet(&RAC->RXENSRCEN, 2);
}


void GENERIC_PHY_ChannelSet(uint16_t ch)

{
  SYNTH_ChannelSet(ch,1);
}


void GENERIC_PHY_SeqAtomicLock(void)

{
  uint32_t dummy;
	
	dummy = RAC->SR0 & 0xff;
  while (RAC->SR0 & 0x01)
  {
    //_DAT_43081104 = 0; //4088 bit 1
		BUS_RegMaskedClear(&RAC->SR0, 2);
    PROTIMER_DelayUs(2);
  }
  //_DAT_43081104 = 1;
  BUS_RegMaskedSet(&RAC->SR0, 2);
}


void GENERIC_PHY_RadioEnable(uint32_t enable)

{
  if (enable == 0)
  {
    GENERIC_PHY_SeqAtomicLock();
    *(uint32_t*)0x21000efc = *(uint32_t*)0x21000efc | 0x20;
		BUS_RegMaskedClear(&RAC->RXENSRCEN, RAC_RXENSRCEN_SWRXEN_Msk);
		FRC->CMD = FRC_CMD_RXABORT_Msk; 
		RAC->CTRL |= RAC_CTRL_PRSCLR_Msk;
    //_DAT_43081104 = enable; //RAC->SR0 bit 2
    //RAC->SR0 |= 0x04; //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    BUS_RegMaskedClear(&RAC->SR0, 2);
  }
  else
  {
    if (RAC->CTRL & RAC_CTRL_FORCEDISABLE_Msk) BUS_RegMaskedClear(&RAC->CTRL, RAC_CTRL_FORCEDISABLE_Msk);
  }
}





void GENERIC_PHY_SeqAtomicUnlock(void)

{
	BUS_RegMaskedClear(&RAC->SR0, 2);
}





void GENERIC_PHY_TxDisable(void)

{
	RAC->CMD = RAC_CMD_TXDIS_Msk;
}



uint32_t  GENERIC_PHY_PreviousTxTime(void)

{
	return PROTIMER_GetCCTime(1);
}



void GENERIC_PHY_RACConfig(void)

{
  RADIO_SeqInit(&genericSeqProg, GENERIC_SEQPROG_SIZE);
  memset((void*)0x21000efc,0,0x70); //clear sequencer variables
  RAC->SR0 = 0;
  RAC->SR1 = 0;
  RAC->SR2 = 0;
  //TEMPCAL_Init();
  RADIO_RxSearchTimeSet(0);
  RADIO_TxToRxSearchTimeSet(0);
  RADIO_RxWarmTimeSet(100);
  RADIO_TxToRxTimeSet(100);
  RADIO_TxToTxTimeSet(100);
  RADIO_RxToTxTimeSet(100);
  RADIO_TxWarmTimeSet(100);
}



void GENERIC_PHY_FrameConfig(void)

{
  //RADIO_Config(&currentConfig); //!!!!!!!!!!!!!!!!!!
  return;
}


void GENERIC_PHY_DirectModeConfig(uint8_t *param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  
  if (param_1 != NULL)
  {
    CMU_ClockEnable(0x67400,1);
    CMU_ClockEnable(0x82500,1);
    uVar2 = (uint32_t)*param_1;
    uVar1 = MODEM->CTRL2;
		BUS_RegMaskedClear(&MODEM->CTRL2, MODEM_CTRL2_TXPINMODE_Msk);
    if (uVar2 == 0) MODEM->CTRL2 = MODEM->CTRL2; 
    else
    {
      uVar2 = (uint32_t)param_1[4];
      if (uVar2 == 0) BUS_RegMaskedSet(&MODEM->CTRL2, 0x800);
      else 
			{
        BUS_RegMaskedSet(&MODEM->CTRL2, 0xc00);
        uVar2 = 4;
      }
      uVar2 = uVar2 | 1;
    }
    if (param_1[1] != 0)
    {
		BUS_RegMaskedClear(&MODEM->CTRL2, MODEM_CTRL2_RXPINMODE_Msk);
      if (param_1[3] == 0) BUS_RegMaskedSet(&MODEM->CTRL2, MODEM_CTRL2_RXPINMODE_Msk);
      else 
			{
				MODEM->CTRL2 = MODEM->CTRL2;
        uVar2 = uVar2 | 4;
      }
      uVar2 = uVar2 | 2;
    }
		BUS_RegMaskedClear(&MODEM->CTRL2, MODEM_CTRL2_RXFRCDIS_Msk);
    if (param_1[2] != 0) BUS_RegMaskedSet(&MODEM->CTRL2, MODEM_CTRL2_RXFRCDIS_Msk);
    MODEM->ROUTELOC0 = (uint32_t)param_1[0xb] | (uint32_t)param_1[8] << MODEM_ROUTELOC0_DCLKLOC_Pos | (uint32_t)param_1[5] << MODEM_ROUTELOC0_DOUTLOC_Pos;
		BUS_RegMaskedClear(&MODEM->ROUTEPEN, MODEM_ROUTEPEN_DCLKPEN_Msk | MODEM_ROUTEPEN_DOUTPEN_Msk | MODEM_ROUTEPEN_DINPEN_Msk);
		BUS_RegMaskedClear(&MODEM->ROUTEPEN, uVar2); 
    if (uVar2 & 1) GPIO_PinModeSet(param_1[0xc],param_1[0xd],1,0);
    if (uVar2 & 2) GPIO_PinModeSet(param_1[6],param_1[7],4,0);
    if (uVar2 & 4) GPIO_PinModeSet(param_1[9],param_1[10],4,0);
  }
}



void GENERIC_PHY_PROTIMERConfig(void)

{
  PROTIMER->IFC = 0x3f3fff7; 
	BUS_RegMaskedClear(&PROTIMER->IEN, 0x3f3fff7);
  PROTIMER->CTRL = 0;
  PROTIMER->BASECNT = 0;
  PROTIMER->WRAPCNT = 0;
  PROTIMER->BASECNTTOP = 0xffff;
  PROTIMER->WRAPCNTTOP = 0xffffffff;
  PROTIMER->LBTCTRL = 0;
}



uint16_t GENERIC_PHY_ChannelGet(void)

{
  return SYNTH->CHCTRL & 0xff;
}



void GENERIC_PHY_SYNTH_IRQHandler(void)

{
	SYNTH->IFC = SYNTH->IF & SYNTH->IEN; //clear flags only
}





void GENERIC_PHY_ResetPacketConfig(void)

{
	FRC_CLR->DFLCTRL = FRC_DFLCTRL_DFLMODE_Msk;
	BUS_RegMaskedClear(&FRC->DFLCTRL, FRC_DFLCTRL_DFLMODE_Msk);
  FRC->DFLCTRL = FRC->DFLCTRL;
  *(uint32_t*)0x21000efc &= 0xfffffff8;
}



void GENERIC_PHY_ConfigureVariableLength(uint32_t param_1,uint32_t param_2,int32_t param_3,int32_t param_4)

{
  uint32_t tmp;
  
  GENERIC_PHY_ResetPacketConfig();
  FRC->WCNTCMP1 = param_1 & 0xfff;
  if ((param_2 & 0xf) < 9) tmp = 1;
  else
  {
    if (param_4 == 0) tmp = 3;
    else tmp = 4;
  }
  FRC->MAXLENGTH = 0xfff;
	BUS_RegMaskedClear(&FRC->DFLCTRL, FRC_DFLCTRL_DFLBITS_Msk | FRC_DFLCTRL_DFLOFFSET_Msk | FRC_DFLCTRL_DFLMODE_Msk);
	BUS_RegMaskedClear(&FRC->DFLCTRL, (param_2 & 0xf) << 0xc | (param_3 - 1U & 0xf) << 8 | tmp | FRC->DFLCTRL);
}



void GENERIC_PHY_ConfigureFixedLength(uint16_t len)

{
  GENERIC_PHY_ResetPacketConfig();
  FRC->WCNTCMP0 = (len - 1U) & 0xfff;
}


void GENERIC_PHY_ConfigureFrameType(const RAIL_FrameType_t *frameType)

{
  uint32_t t;
  
  GENERIC_PHY_ResetPacketConfig();
  if (frameType == NULL)
  {
    memset((void *)0x21000f54,0,0x18);
    return;
  }
	SEQ->REG058 = frameType->offset;
	SEQ->REG05C = frameType->mask;
	SEQ->REG060 = 0;
	SEQ->REG064 = *(uint32_t *)(frameType->isValid);
	SEQ->REG068 = *(uint32_t *)(frameType->variableAddrLoc);
	
	  t = frameType->mask;
  if (t != 0)
  {
   	while (t & 0x01)
    {
      SEQ->REG060 = SEQ->REG060 + 1;
      t = t >> 1;
    }
  }
	FRC->WCNTCMP0 = frameType->offset + 1;
	*(uint32_t*)0x21000efc = *(uint32_t*)0x21000efc | 7;
}





bool GENERIC_PHY_EnableAddressFiltering(void)

{
  uint32_t t;
  //t = _DAT_21000efc << 0x1b;
  *(uint32_t*)0x21000efc = *(uint32_t*)0x21000efc | 0x10;
  return t >> 0x1f;
}





bool GENERIC_PHY_DisableAddressFiltering(void)

{
  uint32_t t;
  
  t = *(uint32_t*)0x21000efc << 0x1b;
  *(uint32_t*)0x21000efc = *(uint32_t*)0x21000efc & 0xffffffef;
  return t >> 0x1f;
}





bool GENERIC_PHY_IsEnabledAddressFiltering(void)

{
  return (*(uint32_t*)0x21000efc << 0x1b) >> 0x1f;
}



void GENERIC_PHY_ResetAddressFiltering(void)

{
  memset((void *)SEQ->REG008,0,0x4c);
  //addressFilterMatchTable = 0; //!!!!!!!!!!!!!!!!!!!!!!!!
  return;
}





void GENERIC_PHY_Init(void)

{
  RADIO_Init();
  NVIC_ClearPendingIRQ(SYNTH_IRQn);
  NVIC_DisableIRQ(SYNTH_IRQn);
  GENERIC_PHY_RACConfig();
  FRC->TRAILRXDATA = 0x1b;
  FRC->RXCTRL = 0x60;
  //RADIO_PTI_Enable();
  if (RAC->CTRL & 0x01) BUS_RegMaskedClear(&RAC->CTRL, 1);
  RADIO_RegisterIrqCallback(1,GENERIC_PHY_FRC_IRQCallback);
  RADIO_RegisterIrqCallback(2,GENERIC_PHY_MODEM_IRQCallback);
  RADIO_RegisterIrqCallback(5,GENERIC_PHY_RAC_IRQCallback);
  RADIO_RegisterIrqCallback(7,GENERIC_PHY_PROTIMER_IRQCallback);
  GENERIC_PHY_ResetAddressFiltering();
  *(uint32_t*)0x21000efc = *(uint32_t*)0x21000efc | 8;
  PROTIMER_Init();
  PROTIMER_Start();
  PROTIMER_CCTimerCapture(0,0xc00000);
  PROTIMER_CCTimerCapture(1,0x200000);
//  RFRAND_SeedProtimerRandom();
  SYNTH_DCDCRetimeEnable();
  SEQ->REG070 = 0;
}



uint32_t GENERIC_PHY_ConfigureAddressFiltering(uint8_t *param_1)

{
  uint8_t bVar1;
  
  GENERIC_PHY_ResetAddressFiltering();
  if (param_1 == NULL) return 1;
  SEQ->REG04C = *param_1; //!!!!!!!!!!!!!!!!!!!

  bVar1 = param_1[2];
  if (bVar1 < 9)
  {
    //DAT_21000f4d = param_1[1]; //!!!!!!!!!!!!!!!!!!!
    //DAT_21000f4e = bVar1;
    if ((uint8_t)param_1[3] < 9)
    {
      //DAT_21000f52 = param_1[8]; //!!!!!!!!!!!!!!!!!!!
      //addressFilterMatchTable = *(undefined4 *)(param_1 + 4);
      //DAT_21000f4f = param_1[3];
      GENERIC_PHY_SetAddressFilteringMatchTable();
      return 1;
    }
  }
  return 0;
}



uint32_t GENERIC_PHY_EnableAddress(uint32_t param_1,uint32_t param_2)

{
  if ((param_1 < 2) && (param_2 < 4))
  {
    (&SEQ->REG050)[param_1] = (uint8_t)(1 << (param_2 & 0xff)) | (&SEQ->REG050)[param_1]; //!!!!!!!!!!!!!!!!!!!!!!!!!!!
    GENERIC_PHY_SetAddressFilteringMatchTable();
    return 1;
  }
  return 0;
}



uint32_t GENERIC_PHY_DisableAddress(uint32_t param_1,uint32_t param_2)

{
  if ((param_1 < 2) && (param_2 < 4))
  {
    (&SEQ->REG050)[param_1] = (&SEQ->REG050)[param_1] & ~(uint8_t)(1 << (param_2 & 0xff)); //!!!!!!!!!!!!!!!!!!!!!!!!!!!
    GENERIC_PHY_SetAddressFilteringMatchTable();
    return 1;
  }
  return 0;
}



uint32_t GENERIC_PHY_SetAddress(uint32_t param_1,uint32_t param_2,int32_t param_3,int32_t param_4)

{
  uint8_t bVar1;
  uint32_t *puVar2;
  int32_t iVar3;
  uint32_t uVar4;
  
  if ((param_1 < 2) && (param_2 < 4))
  {
    //GENERIC_PHY_DisableAddress(); //!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //bVar1 = (&DAT_21000f4e)[param_1];
    //bVar1 = (&(SEQ->REG04C+0x2))[param_1]; //!!!!!!!!!!!!!!!!!!!!!!!!!!!
    iVar3 = 0;
    //puVar2 = (uint *)(&DAT_21000f0c + param_1 * 0x20);
   // puVar2 = (uint *)(&SEQ->REG00C + param_1 * 0x20); //!!!!!!!!!!!!!!!!!!!!!!!!!!!
    while (iVar3 < (int)(uint32_t)bVar1)
    {
      uVar4 = *puVar2 & ~(0xff << (param_2 << 3 & 0xff));
      if (param_3 != 0) {
        uVar4 = uVar4 | (uint32_t)*(uint8_t *)(param_3 + iVar3) << (param_2 << 3 & 0xff);
      }
      *puVar2 = uVar4;
      iVar3 = iVar3 + 1;
      puVar2 = puVar2 + 1;
    }
    if (param_4 != 0)
    {
      GENERIC_PHY_EnableAddress(param_1,param_2);
    }
    return 1;
  }
  return 0;
}



RAIL_Status_t GENERIC_PHY_TimerStart(uint32_t time, RAIL_TimeMode_t mode)

{
  return PROTIMER_CCTimerStart(2,time,mode);
}



void GENERIC_PHY_TimerStop(void)

{
  PROTIMER_CCTimerStop(2);
}



uint32_t GENERIC_PHY_TimerGetTimeout(void)

{
  return PROTIMER_GetCCTime(2);
}



bool GENERIC_PHY_TimerExpired(void)

{
  return PROTIMER->IF & 0x400;
}



bool GENERIC_PHY_TimerIsRunning(void)

{
  return PROTIMER_CCTimerIsEnabled(2);
}


