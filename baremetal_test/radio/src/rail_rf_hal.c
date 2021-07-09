#include "rail.h"
#include "rail_rf_hal.h"
#include <stdbool.h>
#include <stddef.h>
#include "em_bus.h"
#include "em_int.h"
#include "em_assert.h"
#include "rail_rf_hal.h"
#include "rf_test.h"
#include "ir_cal.h"
#include "generic_phy.h"
#include "protimer.h"
#include "tempcal.h"
#include "rfsense.h"
#include "pa.h"
#include "radio.h"
#include "radio_pti.h"
#include "synth.h"
#include "rail_calibration.h"

void pktTxDoneEvt(uint32_t param_1,RAIL_TxPacketInfo_t param_2,uint32_t param_3)

{
	RAIL_TxPacketInfo_t local_c;
	uint32_t uStack8;
  
  local_c = param_2;
  uStack8 = param_3;
  GENERIC_PHY_PreviousTxTime();
  local_c.timeUs = PROTIMER_PrecntOverflowToUs(GENERIC_PHY_PreviousTxTime());
  RAILCb_TxPacketSent(&local_c);
}



void pktRxOverflow(void)

{
  RAILCb_RxRadioStatus(0x20);
}



void preambleDetected(void)

{
  RAILCb_RxRadioStatus(2);
}



void frameDet0(void)

{
  RAILCb_RxRadioStatus(4);
}



void sequencerInterrupt(int param_1)

{
  //if (param_1 << 0xb < 0)
  if(param_1 & 0x00100000)
  {
    RAILCb_RxRadioStatus(0x40);
    return;
  }
  return;
}



void RAIL_RFSENSE_Callback(void)

{
  RAILCb_RxRadioStatus(0x80);
}



void pktTxErrorEvt(void)

{
  RAILCb_TxRadioStatus(2);
}



void racStateChange(void)

{
  RAILCb_RadioStateChanged((RAC->STATUS << 4) >> 0x1c);
}



void softwareTimerExpired(void)

{
//  timerExpired = 1; //!!!!!!!!!!!!!!!!!!!!
  GENERIC_PHY_TimerStop();
  RAILCb_TimerExpired();
}



void racCalRequest(void)

{
  RAIL_RfHalCalibrationPend(1);
}





void protmrLbtEvt(int param_1)

{
  uint32_t uVar1;
  
  PROTIMER_CCTimerStop(4);
  //if (param_1 << 9 < 0)
  if(param_1 & 0x00400000)
  {
    RADIO_PTI_AuxdataOutput(0x27);
    GENERIC_PHY_FlushTxPacketBuffer();
    if ((SEQ->REG000 & 0xff000000) == 0x2000000)
    {
  //    _DAT_43080004 = 1; //FRC status - ??? !!!!!!!!!!!!!!!
    }
LAB_000100fc:
    RAILCb_TxRadioStatus(4);
    return;
  }
  //if (param_1 << 0xb < 0)
	  if(param_1 & 0x00100000)
  {
    RADIO_PTI_AuxdataOutput(0x28);
    return;
  }
  //if (param_1 << 0x13 < 0)
	  if(param_1 & 0x00001000)
  {
    PROTIMER_LBTStop();
    if ((PROTIMER->IF & 0x500000) == 0)
    {
      RADIO_PTI_AuxdataOutput(0x2a);
      GENERIC_PHY_FlushTxPacketBuffer();
      goto LAB_000100fc;
    }
  }
  return;
}





void pktRxDoneEvt(void)

{
  int iVar1;
  int iVar2;
  void * uVar3;
  uint32_t uVar4;
  int iVar5;
  uint32_t *puVar6;
  uint32_t uVar7;
  uint32_t uVar8;
  uint32_t uVar9;
  uint32_t local_38;
  uint32_t auStack52 [5];
  uint32_t local_2f;
  uint8_t local_2e;
  uint32_t local_28;
  
  iVar1 = RADIO_RxTrailDataLength();
//  iVar2 = RADIO_RxLengthReadNext(); //@!!!!!!!!!!!!!!
  if (iVar2 != 0xffff)
  {
    uVar9 = iVar2 - iVar1 & 0xffff;
    uVar3 = RAILCb_AllocateMemory(uVar9 + 0xc);
    uVar8 = 0;
    while (uVar8 < uVar9)
    {
      iVar2 = uVar8 + 10;
      local_38 = uVar9 - uVar8;
      RAILCb_BeginWriteMemory((void*)uVar3,iVar2,&local_38);
			//void *RAILCb_BeginWriteMemory(void *handle,uint32_t offset,uint32_t *available);
      if (local_38 == 0)
      {
        uVar4 = local_38;
        local_38 = uVar9 - uVar8;
      }
      iVar5 = GENERIC_PHY_PacketRxDataHelper(uVar4,local_38 & 0xffff);
      uVar8 = uVar8 + iVar5;
      if (uVar4 == 0)
      {
        iVar5 = 0;
      }
      uVar8 = uVar8 & 0xffff;
      RAILCb_EndWriteMemory((void*)uVar3,iVar2,iVar5);
    }
    GENERIC_PHY_PacketRxAppendedInfoHelper(iVar1,auStack52);
    local_38 = 0xc;
    puVar6 = (uint32_t *)RAILCb_BeginWriteMemory((void*)uVar3,0,&local_38);
    if ((puVar6 == NULL) || (local_38 < 0xc))
    {
      uVar7 = 0;
    }
    else
    {
      *(int16_t *)(puVar6 + 2) = (short)uVar9;
//      FRC->IEN._0_1_;
      uVar8 = FRC->IF;
      *(uint8_t *)(puVar6 + 1) = *(uint8_t *)(puVar6 + 1) & 0xfd | (uint8_t)((((uVar8 ^ 0x80) << 0x18) >> 0x1f) << 1);
      //_DAT_43000d1c = 1; //FRC 0068 bit 7
      FRC->IFC |= 0x80; //BLOCKERROR
      if (local_2e != 0)
      {
        local_2e = 1;
      }
      *(uint8_t *)(puVar6 + 1) = *(uint8_t *)(puVar6 + 1) & 0xfe | local_2e & 1;
      *(uint8_t *)((int)puVar6 + 5) = local_2f;
      *(uint8_t *)((int)puVar6 + 6) = 0;
      uVar7 = PROTIMER_PrecntOverflowToUs(local_28);
      *(uint8_t *)((int)puVar6 + 7) = 0;
      *puVar6 = uVar7;
      uVar7 = 0xc;
    }
    RAILCb_EndWriteMemory((void*)uVar3,0,uVar7);
    RAILCb_RxPacketReceived((void*)uVar3);
    RAILCb_FreeMemory((void*)uVar3);
  }
  return;
}





void pktRxFrmErr(void)

{
  //_DAT_43000d1c = 1;
	//FRC->IFC |= 0x80; //BLOCKERROR
	BUS_RegMaskedSet(&FRC->IFC, FRC_IFC_BLOCKERROR_Msk);
  RAILCb_RxRadioStatus(0x10);
}




//typedef struct RAIL_Init {
//  uint16_t maxPacketLength; /**< The maximum number of bytes in a packet. UNUSED! */
//  const uint32_t rfXtalFreq; /**< The xtal frequency of the radio. */
//  RAIL_CalMask_t calEnable; /**< Mask that defines calibrations to perform in RAIL. */
//} RAIL_Init_t;
uint8_t RAIL_RfHalInit(const RAIL_Init_t *railInit)

{
  int iVar1;
  
  iVar1 = SystemHFXOClockGet();
  if (iVar1 != *(int *)(railInit + 4)) return 1;
  GENERIC_PHY_Init();
  //_enabledCallbacks = _enabledCallbacks & 0xff000000 | (uint)(uint3)((uint3)_enabledCallbacks | 7) | 0x80000;
	_enabledCallbacks = _enabledCallbacks & 0xff000000 | (uint32_t) (_enabledCallbacks | 7) | 0x80000;
  iVar1 = RAIL_RfHalCalibrationEnableGet();
  if (iVar1 << 0x1f < 0) _enabledCallbacks = _enabledCallbacks | 0x10000;
//  GENERIC_PHY_SetCallbacks(&_enabledCallbacks);
//  GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
  RAILCb_RfReady();
  return 0;
}



void RAIL_RfHalIdleStart(void)

{
  GENERIC_PHY_RadioEnable(0);
}

//typedef enum RAIL_RadioState {
//  RAIL_RF_STATE_IDLE,
//  RAIL_RF_STATE_RX,
//  RAIL_RF_STATE_TX,
//} RAIL_RadioState_t;

//typedef enum RAIL_Status {
//  RAIL_STATUS_NO_ERROR,
//  RAIL_STATUS_INVALID_PARAMETER,
//  RAIL_STATUS_INVALID_STATE,
//} RAIL_Status_t;

RAIL_RadioState_t RAIL_RfHalStateGet(void)

{
  uint32_t state;
  bool bVar2;
  
  //uVar1 = RAC->STATUS;
  //uVar1 = uVar1 & 0xf000000;
  state = RAC->STATUS & 0xf000000;
  if (state != 0x6000000) 
		{
    if (0x6000000 < state) 
		{
      if (state != 0x9000000) 
			{
        if (state < 0x9000001) 
				{
          if (state == 0x7000000) return RAIL_RF_STATE_RX; //1
          bVar2 = state == 0x8000000;
        }
        else 
				{
          if (state == 0xb000000) return RAIL_RF_STATE_TX;
          if (state == 0xc000000) return RAIL_RF_STATE_TX;
          bVar2 = state == 0xa000000;
        }
        if (!bVar2) return RAIL_RF_STATE_IDLE;
        return RAIL_RF_STATE_TX;
    }
    if (state != 0x3000000) 
		{
      if (state < 0x3000001) 
			{
        if (state == 0x1000000) return RAIL_RF_STATE_RX;
        bVar2 = state == 0x2000000;
      }
      else 
			{
        if (state == 0x4000000) return RAIL_RF_STATE_RX;
        bVar2 = state == 0x5000000;
      }
      if (!bVar2) return RAIL_RF_STATE_IDLE;
    }
  }
  return RAIL_RF_STATE_RX;
	}
	return RAIL_RF_STATE_RX; //?????
	}



int RFHAL_HeadedToIdle(void)

{
  int iVar1;
  uint32_t uVar2;
  bool bVar3;
  
  INT_Disable();
  iVar1 = PROTIMER_CCTimerIsEnabled(3);
  //if ((iVar1 == 0) && (iVar1 = PROTIMER_LBTIsActive(), iVar1 == 0))
  if ((PROTIMER_CCTimerIsEnabled(3) == 0) && (PROTIMER_LBTIsActive() == 0))
  {
    uVar2 = RAC->STATUS;
    INT_Enable();
    if (((uVar2 & 0xc0000000) == 0) && (uVar2 = uVar2 & 0xf000000, uVar2 != 0x6000000))
    {
      if (uVar2 < 0x6000001) bVar3 = uVar2 == 0x3000000;
      else 
			{
        if (uVar2 == 0x9000000) return 0;
        bVar3 = uVar2 == 0xc000000;
      }
      if (!bVar3) iVar1 = 1;
    }
  }
  else
  {
    INT_Enable();
    iVar1 = 0;
  }
  return iVar1;
}



//typedef struct RAIL_TxData {
//  uint8_t *dataPtr; /**< Pointer to data to transmit */
//  uint16_t dataLength; /**< Number of bytes to load into transmit buffer */
//} RAIL_TxData_t;
uint8_t RAIL_RfHalTxDataLoad(RAIL_TxData_t *txData)

{
  uint8_t *local_10;
  uint32_t local_c;
  uint32_t uStack8;
  
//  local_10 = ((uint16_t)*txData & 0xffff0000) | (uint16_t)txData[1]; //(uint)*(uint16_t *)(param_1 + 1);
//  local_c = *txData;
//  uStack8 = txData[2];
  GENERIC_PHY_LoadTxPacketBuffer(local_10); //buffer address - ???
  return 0;
}





//undefined4 RAIL_CcaCsma(uint16_t *param_1,undefined4 param_2)
uint8_t RAIL_CcaCsma(void *params)
{
  uint8_t bVar1;
  int64_t lVar2;
  uint16_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  int iVar6;
  uint32_t uVar7;
  uint32_t uVar8;
  uint32_t uVar9;
  uint32_t uVar10;
  int iVar11;
  uint8_t bVar12;
  uint8_t bVar13;
  uint8_t bVar14;
  uint8_t bVar15;
  PROTIMER_Typedef *pPVar16;
  
//  if (param_1 != NULL)
//  {
//    uVar3 = param_1[3];
//    uVar9 = MODEM->CF;
//    uVar5 = MODEM->RXBR;
//    bVar13 = *(uint8_t *)((int)param_1 + 3);
//
//    uVar4 = (uVar5 << 0x16) >> 0x1b;
//    uVar8 = (uint32_t)*(uint8_t *)((int)&modemCfDec0Factors_8287 + (uVar9 & 7));
//    iVar11 = (((uVar9 << 0xf) >> 0x12) * uVar8 + uVar8) * 2000000;
//    uVar8 = CMU_ClockFreqGet(0x11,2000000,&modemCfDec0Factors_8287,iVar11,param_1,param_2);

 //   lVar2 = (uint64_t)uVar4 * (uint64_t)uVar3 * (uint64_t)uVar8;
 //   uVar5 = __aeabi_uldivmod((int)lVar2,(int)((uint64_t)lVar2 >> 0x20),
 //                            (uVar4 * ((uVar5 << 0x13) >> 0x1d) + (uVar5 & 0x1f)) *
 //                          (((uVar9 << 9) >> 0x1a) * iVar11 + iVar11),0);
 //   uVar9 = 0;
//    while ((uint32_t)(1 << (uVar9 & 0xff)) < uVar5)
//    {
//      if (uVar9 == 0x10) {
//        return 1;
//      }
//      uVar9 = uVar9 + 1;
//    }
//    //uVar5 = read_volatile_4(AGC->CTRL1);
//    AGC->CTRL1 &= 0xfffff000;
//    AGC->CTRL1 |= bVar13 | uVar9 << 8;
//    bVar13 = *(uint8_t *)(param_1 + 1);
//
//    bVar1 = *(uint8_t *)param_1;
//
//    bVar12 = *(uint8_t *)((int)param_1 + 1);
//
//    bVar14 = bVar13;
//    bVar15 = bVar13;
//    if ((bVar13 != 0) && (bVar13 = bVar13 - 1, bVar14 = 1, bVar15 = bVar1, bVar12 < bVar1))
//    {
//      bVar12 = bVar1;
//    }
//    uVar9 = count_leading_zeroes((uint)*param_1);
//
//    pPVar16 = (PROTIMER *)0x10421;
//    uVar3 = PROTIMER_UsToPrecntOverflow(param_1[2]);
//
//    uVar5 = (uint32_t)uVar3;
//    if (uVar9 >> 5 == 0)
//    {
//      uVar4 = (uint32_t)reseedRandom_8301;
//
//      if (uVar4 != 0xf804)
//      {
//        pPVar16 = &PROTIMER;
//      }
//      if (uVar4 != 0xf804)
//      {
//        pPVar16->RANDOM = uVar4;
//        reseedRandom_8301 = 0xf804;
//      }
//    }
//    else
//    {
//      uVar8 = 0;
//      uVar4 = uVar5;
//      while( true )
//      {
//        uVar10 = uVar8 & 0xff;
//        uVar8 = uVar8 + 1;
//        if (uVar4 < 0x100) break;
//        uVar4 = uVar4 >> 1;
//      }
//      if ((uVar10 != 0) && (uVar4 != 0xff))
//      {
//        uVar4 = uVar4 + ((int)uVar5 >> (uVar10 - 1 & 0xff) & 1U) & 0xffff;
//      }
//      uVar5 = PROTIMER->RANDOM;
//      reseedRandom_8301 = (ushort)(uVar5 & 0xffff);
//      if ((uVar5 & 0xffff) == 0xf804)
//      {
//        reseedRandom_8301 = 0xf805;
//      }
//      PROTIMER->RANDOM = (1 << uVar10) - 1;
//      bVar12 = 8;
//      PROTIMER->LBTSTATE = 0x800000;
//      bVar15 = 8;
//      uVar5 = uVar4;
//    }
//    PROTIMER->BASECNTTOP = uVar5;
//    PROTIMER_LBTCfgSet(bVar15,bVar12,bVar14,bVar13,0);
//    if (uVar9 >> 5 != 0)
//    {
//      _DAT_430a09d0 = 1;
//      //uVar5 = read_volatile_4(PROTIMER->CTRL);
//      //write_volatile_4(PROTIMER->CTRL,uVar5 & 0xff3fffff | 0x400000);
//	  PROTIMER->CTRL &= 0xff3fffff;
//	  PROTIMER->CTRL |= 0x400000;
//    }
//    lbtTimeout_8300 = *(int *)(param_1 + 4);
//  }
//  GENERIC_PHY_PacketTxCommon();
//  iVar11 = lbtTimeout_8300;
//  if (lbtTimeout_8300 != 0)
//  {
//    iVar6 = PROTIMER_CCTimerIsEnabled(4);
//    if (iVar6 != 0)
//    {
//      PROTIMER_CCTimerStop(4);
//    }
//    uVar7 = PROTIMER_UsToPrecntOverflow(iVar11);
//    iVar11 = PROTIMER_CCTimerStart(4,uVar7,1);
//    if (iVar11 == 0)
//    {
//      return 1;
//    }
//  }
//  PROTIMER_LBTStart();
  return 0;
}



// WARNING: Could not reconcile some variable overlaps

//void RAIL_CcaLbt(uint *param_1,uint param_2,uint param_3,uint param_4)
uint8_t RAIL_CcaLbt(void *params)
{
//  uint32_t uVar1;
//  uint8_t bVar2;
//  uint32_t local_14;
//  uint32_t local_10;
//  uint32_t uStack12;
//
//  local_14 = param_2;
//  local_10 = param_3;
//  uStack12 = param_4;
//  if ((param_1 != (uint32_t *)0x0) && (*(int16_t *)param_1 != 0)) {
//    local_14 = *param_1;
//    local_10._2_2_ = (uint16_t)(param_1[1] >> 0x10);
//    uStack12 = param_1[2];
//    bVar2 = *(byte *)param_1;
//    if (bVar2 != 0) {
//      local_10._2_2_ = *(short *)(param_1 + 1) * (ushort)bVar2 + local_10._2_2_;
//      local_14._1_1_ = (char)(local_14 >> 8);
//      local_14._2_2_ = (undefined2)(local_14 >> 0x10);
//      local_14 = (uint)CONCAT21(local_14._2_2_,local_14._1_1_ - bVar2) << 8;
//    }
//    uVar1 = local_14 >> 8 & 0xff;
//    bVar2 = 1;
//    while ((uint)(1 << (uint)bVar2) < uVar1) {
//      bVar2 = bVar2 + 1;
//    }
//    local_10 = uVar1 * *(ushort *)(param_1 + 1) + ((uint)(1 << (uint)bVar2) >> 1) >> (uint)bVar2 &
//               0xffff | (uint)local_10._2_2_ << 0x10;
//    local_14._0_2_ = CONCAT11(bVar2,bVar2);
//    local_14 = local_14 & 0xffff0000 | (uint)(ushort)local_14;
//    param_1 = &local_14;
//  }
//  RAIL_CcaCsma(param_1);
  return 0;
}



uint8_t RAIL_ScheduleTx(void *params)

{
  uint32_t uVar1;
  char cVar2;

  cVar2 = *(char *)(params + 1);
  if (cVar2 != '\0') 
	{
    cVar2 = '\x01';
  }
  //uVar1 = PROTIMER_UsToPrecntOverflow(*param_1);
//  GENERIC_PHY_SchedulePacketTx(PROTIMER_UsToPrecntOverflow(*params),cVar2);
  return 0;
}



//undefined4 RAIL_RfHalTxStart(undefined4 param_1,code *UNRECOVERED_JUMPTABLE,undefined4 param_3)
uint8_t RAIL_RfHalTxStart(uint8_t channel, RAIL_PreTxOp_t preTxOp, void *preTxOpParams)
{
  if (RAIL_DebugModeGet() != 1) 
  {
    do 
		{
      if (RFHAL_HeadedToIdle() == 0) break;
    } while ((RAC->STATUS & 0xf000000) != 0);
    if ((RAC->STATUS & 0xf000000) != 0) return 2;
    GENERIC_PHY_ChannelSet(channel);
  }
 // if (UNRECOVERED_JUMPTABLE != NULL)
 // {
                    // WARNING: Could not recover jumptable at 0x000105e8. Too many branches
                    // WARNING: Treating indirect jump as call
 //   uVar3 = (*UNRECOVERED_JUMPTABLE)(param_3);
 //   return uVar3;
 // }
  GENERIC_PHY_PacketTx();
  return 0;
}



uint8_t RAIL_RfHalRxStart(uint8_t channel)
{
  if ((RAC->RXENSRCEN & 0xff) == 0) RADIO_RxBufferReset();
  if (RAIL_DebugModeGet() != 1) 
	{
    do 
		{ 
      if (RFHAL_HeadedToIdle() == 0) break;
    } while ((RAC->STATUS & 0xf000000) != 0);
    if ((RAC->STATUS & 0xf000000) != 0) return 2; 
    GENERIC_PHY_ChannelSet(channel);
  }
  GENERIC_PHY_StartRx(0);
  return 0;
}





uint8_t RAIL_RfHalRxIntEnable(uint8_t cbToEn)

{
//  _enabledCallbacks =
//       CONCAT12((uint8_t)(_enabledCallbacks >> 0x10) & 0xfd |
//                (uint8_t)(((uint)(cbToEn << 0x19) >> 0x1f) << 1),
//                CONCAT11(DAT_000108e1 & 0xf8 | (uint8_t)((uint)(cbToEn << 0x1e) >> 0x1f) |
//                         (uint8_t)(((uint)(cbToEn << 0x1d) >> 0x1f) << 1) |
//                         (uint8_t)(((uint)(cbToEn << 0x1c) >> 0x1f) << 2),
//                         enabledCallbacks & 0xe7 | (uint8_t)(((uint)(cbToEn << 0x1b) >> 0x1f) << 3) |
//                         (uint8_t)(((uint)(cbToEn << 0x1a) >> 0x1f) << 4)));
//  _enabledCallbacks = _enabledCallbacks & 0xff000000 | (uint)_enabledCallbacks;
//  GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
  return 0;
}





RAIL_Status_t RAIL_RfHalErrorConfig(RAIL_RadioState_t errors)

{
  //_DAT_43000884 = errors & 1; //FRC044 bit 1
	if (errors) BUS_RegMaskedSet(&FRC->RXCTRL, FRC_RXCTRL_ACCEPTCRCERRORS_Msk);
  return 0;
}



uint32_t RAIL_RfHalSetChannelConfig(int param_1)

{
  if (RAIL_DebugModeGet() != 1) SYNTH_Config(*(uint32_t *)(param_1 + 8),*(uint32_t *)(param_1 + 4));
  return 0;
}


/**
 * Set the PA capacitor tune value for transmit and receive
 *
 * @param[in] txPaCtuneValue PA Ctune value for TX mode
 * @param[in] rxPaCtuneValue PA Ctune value for RX mode
 *
 * @return returns RAIL_STATUS_NO_ERROR if successful
 *
 * Provides the ability to tune the impedance of the transmit
 * and receive modes by changing the amount of capacitance at
 * the PA output.
 */
RAIL_Status_t RAIL_PaCtuneSet(uint8_t txPaCtuneValue, uint8_t rxPaCtuneValue)

{
  PA_CTuneSet(txPaCtuneValue, rxPaCtuneValue);
  return 0;
}




/**
 * Set a timer via the RAIL timebase
 *
 * @param[in] time The time to delay for in the RAIL timebase.
 * @param[in] mode The timer mode can be relative to now or an absolute time.
 * @return Returns RAIL_STATUS_NO_ERROR on success and
 * RAIL_STATUS_INVALID_PARAMETER if the timer could not be scheduled.
 *
 * Configure a timer to fire after some period in the RAIL timebase. This timer
 * can be used to implement low level protocol features.
 */
RAIL_Status_t RAIL_TimerSet(uint32_t time, RAIL_TimeMode_t mode)

{
  RAIL_Status_t b;
  INT_Disable();
  _enabledCallbacks = _enabledCallbacks | 0x100000;
  GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
//  timerExpired = 0; //!!!!!!
  if (mode != 0) mode = 1;
  b = GENERIC_PHY_TimerStart(PROTIMER_UsToPrecntOverflow(time),mode);
  INT_Enable();
  return b ^ 1;
}


/**
 * Return the absolute time that the RAIL timer is configured to fire at.
 *
 * @return The absolute time that this timer is set to go off at.
 *
 * This will give the absolute time regardless of the \ref RAIL_TimeMode_t that
 * was passed into \ref RAIL_TimerSet. The return value is undefined if the
 * timer was never set.
 */
uint32_t RAIL_TimerGet(void)

{
  uint32_t cnt;
  cnt = GENERIC_PHY_TimerGetTimeout();
  return PROTIMER_PrecntOverflowToUs(cnt);
}




/**
 * Stop the currently scheduled RAIL timer.
 *
 * @return void
 *
 * Cancels the timer. If this is called before the timer fires, then
 * RAILCb_TimerExpired will never be called.
 */
void RAIL_TimerCancel(void)

{
  uint32_t extraout_r1;
  uint32_t in_r3;
  
  GENERIC_PHY_TimerStop();
  _enabledCallbacks = _enabledCallbacks & 0xffefffff;
  GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
}


/**
 * Check to see if the RAIL timer has expired
 *
 * @return True if the previously scheduled timer has fired and false otherwise.
 *
 * This is cleared on RAIL_TimerSet() and will be set when the delay expires.
 * This function can be used as an alternative to RAILCb_TimerExpired using
 * polling. If this is the case, implement RAILCb_TimerExpired as a stub.
 */
bool RAIL_TimerExpired(void)

{
//  uint8_t bVar1;
//  int iVar2;
  
//  iVar2 = GENERIC_PHY_TimerExpired();
//  bVar1 = timerExpired;
//  if (GENERIC_PHY_TimerExpired() != 0) bVar1 = 1;
//  return bVar1 & 1;
	return (GENERIC_PHY_TimerExpired() != 0);
}


/**
 * See if the RAIL timer is currently running
 *
 * @return Returns true if the timer is running and false otherwise
 *
 * Will return false if the timer was never set or has expired.
 */
bool RAIL_TimerIsRunning(void)

{
  return GENERIC_PHY_TimerIsRunning();
}


/**
 * Return the symbol rate for the current PHY
 *
 * @return The symbol rate in symbols per second
 *
 * The symbol rate is the rate of symbol changes over the air. For non-DSSS
 * PHYs this is the same as the baudrate. For DSSS PHYs it is the baudrate
 * divided by the length of a chipping sequence. For more information on this
 * consult the modem calculator documentation.
 */
uint32_t RAIL_SymbolRateGet(void)

{
  return RADIO_ComputeTxSymbolRate();
}


/**
 * Return the bit rate for the current PHY
 *
 * @return The bit rate in bits per second
 *
 * The bit rate is the effective over the air data rate. It does not account
 * for extra spreading you may do for things like forward error correction, but
 * will account for modulation schemes, DSSS, and other configurations. For more
 * information on this consult the modem calculator documentation.
 */
uint32_t RAIL_BitRateGet(void)

{
  return RADIO_ComputeTxBitRate();
}



/**
 * Start/Stop RF Sense functionality for use during low-energy sleep modes.
 *
 * @param[in] band The frequency band(s) on which to sense RF energy.
 * To stop Rf Sense, specify \ref RAIL_RFSENSE_OFF.
 * @param[in] senseTime The time (in microseconds) RF energy must be
 * continually detected to be considered "sensed".
 * @param[in] enableCb Set true to enable \ref RAILCb_RxRadioStatus() callback
 * with status \ref RAIL_RX_CONFIG_RF_SENSED when Rf is sensed.  Set false if
 * prefer to poll via \ref RAIL_RfSensed().
 *
 * @return The actual senseTime utilized, which may be different than
 * requested due to limitations of the hardware.  If 0, RF sense was
 * disabled or it could not be enabled (no callback will be issued).
 *
 * The EFR32 has the ability to sense the presence of RF Energy above -20 dBm
 * within either or both the 2.4 GHz and Sub-GHz bands, and trigger an event
 * if that energy is continuously present for certain durations of time.
 *
 * @note After RF energy has been sensed, RF Sense is automatically disabled,
 * and RAIL_RfSense() must be called again to reactivate it.
 *
 * @warning RF Sense functionality is only guaranteed from 0 to
 *          85 degrees Celsius. RF Sense should be disabled
 *          outside this Temperature range.
 */
uint32_t RAIL_RfSense(RAIL_RfSenseBand_t band, uint32_t senseTime, bool enableCb)

{
 // code *local_14;
  //undefined4 local_10;
  //uint local_c;
  
//  local_14 = RAIL_RFSENSE_Callback;
  if (enableCb == false)
  {
//    local_14 = NULL;
  }
  //local_c._0_2_ = CONCAT11(1,band);
  //local_c = param_4 & 0xffff0000 | (uint)(ushort)local_c;
  //local_10 = senseTime;
//  RFSENSE_Init(&local_14);
  return 0;
}


/**
 * Check if RF was sensed.
 *
 * @return true if RF was sensed since last call to \ref RAIL_RfSense; false
 * otherwise.
 *
 * This function is useful if \ref RAIL_RfSense has been called with enableCb
 * set to false. It is generally used after EM4 reboot, but can be used any
 * time.
 */
bool RAIL_RfSensed(void)

{
  return RFSENSE_Sensed();
}




/**
 * Configure Debug callbacks (all are optional)
 *
 * @param[in] cbToEnable Define statuses that force TxRadioStatus callback
 */
void RAIL_DebugCbConfig(uint32_t cbToEnable)

{
//  _enabledCallbacks =
//       CONCAT11(DAT_000108e1 & 0xef | (byte)(((uint)(param_1 << 0x1e) >> 0x1f) << 4),
//                enabledCallbacks);
//  _enabledCallbacks = _enabledCallbacks & 0xffff0000 | (uint)_enabledCallbacks;
//  GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
  return;
}



void RAIL_RfHalCalibrationRun(int *param_1,int param_2)

{
  int iVar1;
  
  if (param_2 << 0x1f < 0) {
    TEMPCAL_Perform();
  }
  if (param_2 << 0xf < 0) {
    if (*param_1 == -1) {
      iVar1 = IRCAL_Perform();
      *param_1 = iVar1;
      return;
    }
//    IRCAL_Set();
		IRCAL_Set(0); //!!!!!!!!!!!!!!!!!!!!!!
    return;
  }
  return;
}





RAIL_Status_t RAIL_RfHalSetTxTransitions(RAIL_RadioState_t success,RAIL_RadioState_t error)

{
  SEQ->REG000 = 1 << (success + 0x10U & 0xff) | (uint32_t)SEQ->REG000 | 1 << (error + 0x18U & 0xff);
  return 0;
}





RAIL_Status_t RAIL_RfHalSetRxTransitions(RAIL_RadioState_t success,RAIL_RadioState_t error)

{
	SEQ->REG000 = 1 << (error + 8U & 0xff) | 1 << (success & 0xff) | SEQ->REG000 & 0xffff0000;
  return 0;
}

void RFHAL_SetBerConfig(RAIL_BerConfig_t *config)
{
	
}

void RFHAL_ResetBerStats(uint32_t bytes)

{
  RFTEST_ResetBerStats(bytes);
  return;
}



void RFHAL_StartBerRx(void)

{
  RFTEST_SaveRadioConfiguration();
  FRC->DFLCTRL = 5;
  MODEM->TIMING &= 0xfffff0ff;
  RADIO_RXBufferEnableThrInt();
  RFTEST_StartRx();
}



void RFHAL_StopBerRx(void)

{
  RFTEST_BerStop();
  RADIO_RXBufferDisableThrInt();
  RFTEST_RestoreRadioConfiguration();
}



// WARNING: Could not reconcile some variable overlaps

//void RFHAL_GetBerStatus(int *param_1,int param_2,int param_3,undefined4 param_4)
void RFHAL_GetBerStatus (RAIL_BerStatus_t *status)
{
//  int local_18;
//  int local_14;
// int local_10;
//  undefined4 local_c;
  
//  local_18 = (int)param_1;
//  local_14 = param_2;
//  local_10 = param_3;
//  local_c = param_4;
  RFTEST_ReportBerStats(status);
//  *param_1 = local_18;
//  param_1[1] = local_14;
//  param_1[2] = local_10;
//  *(undefined *)(param_1 + 3) = (undefined)local_c;
  return;
}


