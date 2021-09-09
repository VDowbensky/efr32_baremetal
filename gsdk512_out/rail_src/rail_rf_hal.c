#include "rail_rf_hal.h"

lbtTimeout.8944;
protChChngCB;
timerExpired;
rxConfigEvents;
saveRssiPeriodInCcap;
isRssiReady;
saveFrameDetDisable;
bufcEnabledCallbacks;
enabledCallbacks;
saveRssiPeriodPreCca;
saveRssiPeriod;

reseedRandom.8945[] = {0x04, 0xf8};
currentRssiAverage[] = {0x00,0xfe};
txConfigEvents[] = {0x1f,0,0,0};

static const unsigned char bufcCallbacks[16UL + 1] = {0xC8, 0x00, 0x01, 0x00, 0x8A, 0x00, 0x01, 0x00, 0xB8, 0x00, 0x01, 0x00, 0x72, 0x00, 0x01, 0x00, 0x00};
static const unsigned char callbacks[108UL + 1] = {
  0x00, 0x00, 0x01, 0x00, 0x68, 0x03, 0x01, 0x00, 0xE0, 0x00, 0x01, 0x00, 0x1C, 0x00, 0x01, 0x00, 0x2C, 0x00, 0x01, 0x00, 0x3C, 0x00, 0x01, 0x00, 0x08, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x32, 0x00, 0x01, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x01, 0x00, 0x66, 0x00, 0x01, 0x00, 0x6C, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x90, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xD8, 0x00, 0x01, 0x00,
  0x34, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xA0, 0x03, 0x01, 0x00, 0x7E, 0x00, 0x01, 0x00, 0x84, 0x00, 0x01, 0x00, 0xA0, 0x00, 0x01, 0x00, 0xC8, 0x02, 0x01, 0x00, 0x00
};
static const unsigned char CSWTCH_104[12UL + 1] = {
  0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x20, 0x00
};

void pktTxDoneEvt(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_c;
  undefined4 uStack8;
  
  local_c = param_2;
  uStack8 = param_3;
  GENERIC_PHY_PreviousTxTime();
  local_c = TIMING_GetTxTimestampUs();
  RAILCb_TxPacketSent(&local_c);
}



void pktRxFrmErr(void)

{
  FRC->IFC = 0x80;
  RAILCb_RxRadioStatusExt(0x10);
}



void pktRxOverflow(void)

{
  RAILCb_RxRadioStatusExt(0x20);
}



void filterPass(void)

{
  RAILCb_RxRadioStatusExt(0x800);
}



void pktRxAborted(void)

{
  uint32_t uVar1;

  tmp = RAC->SR0;
  BUS_RegMaskedClear(&RAC->SR0,0x1000000);
  if (tmp & 0x01000000) RAILCb_RxRadioStatusExt(0x40);
  else RAILCb_RxRadioStatusExt(0x400);
}



void preambleDetected(void)

{
  RAILCb_RxRadioStatusExt(2);
}



void frameDet0(void)

{
  RAILCb_RxRadioStatusExt(4);
}



void frameDet1(void)

{
  RAILCb_RxRadioStatusExt(8);
}



void rxFifoUnderflow(void)

{
  RAILCb_RxRadioStatusExt(1);
}



void RAIL_RFSENSE_Callback(void)

{
  RAILCb_RxRadioStatusExt(0x80);
}



void protmrRetry(void)

{
  RAILCb_TxRadioStatus(0x40);
}



void protmrStartCca(void)

{
  RAILCb_TxRadioStatus(0x80);
}



void txFifoOverflow(void)

{
  RAILCb_TxRadioStatus(1);
}



void racStateChange(void)

{
  RAILCb_RadioStateChanged(RAC->STATUS & RAC_STATUS_STATE_Msk);
}



void softwareTimerExpired(void)

{
  timerExpired = true;
  GENERIC_PHY_TimerStop();
  RAILCb_TimerExpired();
}



void rxFifoAlmostFull(void)

{
  BUFC_GetBytesAvailable(1);
  RAILCb_RxFifoAlmostFull();
}



void txFifoAlmostEmpty(void)

{
  BUFC_GetSpaceAvailable(0);
  RAILCb_TxFifoAlmostEmpty();
}



void racCalRequest(void)

{
  RAILINT_CalibrationPend(1);
}



void pktRxDoneEvt(void)

{
  uint8_t bVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint16_t local_3c;
  uint8_t local_3a;
  undefined local_39;
  uint local_38;
  undefined auStack52 [5];
  undefined local_2f;
  uint8_t local_2e;
  undefined4 local_28;
  
  BUFC_RxLengthReadNext(&local_3c);
  uVar8 = -((int)((uint)(uint8_t)bufcEnabledCallbacks << 0x1d) >> 0x1f);
  if (uVar8 == 0) 
  {
    iVar2 = RADIO_RxTrailDataLength();
    if (local_3c != 0xffff) 
	{
      uVar10 = (uint)local_3c - iVar2 & 0xffff;
      uVar3 = RAILCb_AllocateMemory(uVar10 + 0xc);
      while (uVar8 < uVar10) 
	  {
        local_38 = uVar10 - uVar8;
        uVar4 = RAILCb_BeginWriteMemory(uVar3,uVar8 + 10,&local_38);
        if (local_38 == 0) 
		{
          uVar4 = local_38;
          local_38 = uVar10 - uVar8;
        }
        iVar5 = GENERIC_PHY_PacketRxDataHelper(uVar4,local_38 & 0xffff);
        uVar9 = uVar8 + iVar5;
        if (uVar4 == 0) iVar5 = 0;
        RAILCb_EndWriteMemory(uVar3,uVar8 + 10,iVar5);
        uVar8 = uVar9 & 0xffff;
      }
      GENERIC_PHY_PacketRxAppendedInfoHelper(iVar2,auStack52);
      local_38 = 0xc;
      puVar6 = (undefined4 *)RAILCb_BeginWriteMemory(uVar3,0,&local_38);
      if ((puVar6 == (undefined4 *)0x0) || (local_38 < 0xc)) uVar7 = 0;
      else 
	  {
        read_volatile(FRC->IEN._0_1_);
        uVar8 = (FRC->IF);
        *(int16_t *)(puVar6 + 2) = (int16_t)uVar10;
        *(uint8_t *)(puVar6 + 1) = *(uint8_t *)(puVar6 + 1) & 0xfd | (uint8_t)((((uVar8 ^ 0x80) << 0x18) >> 0x1f) << 1);
        FRC->IFC = 0x80;
        bVar1 = *(uint8_t *)(puVar6 + 1);
        if (local_2e != 0) local_2e = 1;
        *(uint8_t *)(puVar6 + 1) = bVar1 & 0xfe | local_2e & 1;
        *(undefined *)((int)puVar6 + 5) = local_2f;
        *(undefined *)((int)puVar6 + 6) = local_39;
        *(uint8_t *)(puVar6 + 1) = bVar1 & 0xfa | local_2e & 1 | (uint8_t)((((uint)local_3a << 0x1c) >> 0x1f) << 2);
        uVar7 = TIMING_GetRxTimestampUs(local_28);
        *puVar6 = uVar7;
        *(undefined *)((int)puVar6 + 7) = 0;
        uVar7 = 0xc;
      }
      RAILCb_EndWriteMemory(uVar3,0,uVar7);
      RAILCb_RxPacketReceived(uVar3);
      RAILCb_FreeMemory(uVar3);
    }
  }
  else RAILCb_RxPacketReceived(0);
}



void rxTimeout(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 1) 
  {
    if (rxConfigEvents & 0x200) RAILCb_RxRadioStatusExt(0x200);
  }
  else 
  {
    if (param_1 == 2) 
	{
      if (rxConfigEvents & 0x100) RAILCb_RxRadioStatusExt(0x100);
    }
  }
}



void sequencerInterrupt(int param_1)

{
  uint uVar1;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint8_t local_1c [2];
  undefined2 local_1a;
  
  if (param_1 & 0x8000) RAILCb_RxAckTimeout();
  if ((param_1 & 0x80000) && (GENERIC_PHY_CanModifyAck() != false)) 
  {
    uVar3 = RAC->SR1;
    uVar7 = (RAC->SR1 << 0x18) >> 0x1e;
    uVar8 = (0x40 << (BUF1_CTRL & 0xff)) - 1U & 0xffff;
    uVar1 = SEQ->REG004;
    local_1c[0] = (uint8_t)uVar3 >> 6;
    iVar4 = BUFC->BUF1_ADDR + 0x20000000;
    if (uVar7 == 3) 
	{
      iVar5 = 0;
      do 
	  {
        iVar6 = iVar5 + 1;
        *(undefined *)((int)&local_1a + iVar5) = *(undefined *)(iVar4 + (((uVar1 & 0xffff) - 8) + iVar5 & uVar8));
        iVar5 = iVar6;
      } while (iVar6 != 8);
    }
    else 
	{
      if (uVar7 != 2) return;
      local_1a = CONCAT11(*(undefined *)(iVar4 + ((uVar1 & 0xffff) - 1 & uVar8)), *(undefined *)(iVar4 + ((uVar1 & 0xffff) - 2 & uVar8)));
    }
    RAILCb_IEEE802154_DataRequestCommand(local_1c);
  }
}



void rssiAverageDone(void)

{
  _enabledCallbacks = _enabledCallbacks & 0xfbffffff;
  GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
  currentRssiAverage = RADIO_GetRSSI();
  RAIL_RfIdle();
  if (saveFrameDetDisable == '\0') BUS_RegMaskedClear(&MODEM->CTRL0, MODEM_CTRL0_DETDIS_Msk);
  else BUS_RegMaskedSet(&MODEM->CTRL0, MODEM_CTRL0_DETDIS_Msk); 
  RAILCb_RssiAverageDone((int)currentRssiAverage);
  BUS_RegMaskedClear(&AGC->CTRL1,0xffffff00);
  BUS_RegMaskedSet(&AGC->CTRL1,saveRssiPeriod & 0xffffff00);
  isRssiReady = 1;
}



bool userTransmitStarted(void)

{
  if (RAC->SR0 & 0x80 != 0) 
  {
    if (!(PROTIMER->STATUS & PROTIMER_STATUS_LBTRUNNING_Msk)) return PROTIMER->CC3_CTRL & PROTIMER_CC3_CTRL_ENABLE_Msk ^ 1;
  }
  return false;
}



void pktTxErrorEvt(uint param_1)

{
  int iVar1;
  
  if (((param_1 & 0x1c) != 0) && (userTransmitStarted() != 0)) 
  {
    BUS_RegMaskedClear(&RAC->SR0,0x80);
    BUS_RegMaskedClear(&RAC->RXENSRCEN,0x10);
  }
  if ((txConfigEvents & param_1) != 0) RAILCb_TxRadioStatus(txConfigEvents & param_1 & 0xff);
}



void protmrLbtEvt(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  PROTIMER_CCTimerStop(4);
  if (param_1 << 9 < 0) 
  {
    RADIO_PTI_AuxdataOutput(0x27);
    BUFC->BUF0_CMD = 1;
    if ((SEQ->REG00C & 0xff000000) == 0x2000000) BUS_RegMaskedSet(&RAC->RXENSRCEN,2);
LAB_000103fc:
    uVar2 = 4;
  }
  else 
  {
    if (-1 < param_1 << 0xb) 
	{
      if (-1 < param_1 << 0x13) goto LAB_00010402;
      PROTIMER_LBTStop();
      if ((PROTIMER->IF & 0x500000) != 0) goto LAB_00010402;
      RADIO_PTI_AuxdataOutput(0x2a);
      BUFC->BUF0_CMD = 1;
      goto LAB_000103fc;
    }
    RADIO_PTI_AuxdataOutput(0x28);
    uVar2 = 0x20;
  }
  pktTxErrorEvt(uVar2);
LAB_00010402:
  BUS_RegMaskedClear(&AGC->CTRL1,0xffffff00);
  BUS_RegMaskedSet(&AGC->CTRL1,saveRssiPeriodPreCca & 0xffffff00);
}



uint8_t RFHAL_Init(int param_1)

{
  if (SystemHFXOClockGet() == *(int *)(param_1 + 4)) 
  {
    GENERIC_PHY_Init();
    FRC->TRAILRXDATA = 0x1b;
    FRC->RXCTRL = 0x60;
	_enabledCallbacks &= 0xff000000;
	_enabledCallbacks |= (uint)(uint3)((uint3)_enabledCallbacks | 7) | 0x400000;
    if (RAILINT_CalibrationEnableGet() & 0x01) _enabledCallbacks = _enabledCallbacks | 0x80000;
    _enabledCallbacks = |= 0x100000;
    GENERIC_PHY_SetCallbacks(&callbacks);
    GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
    BUFC_SetCallbacks(&bufcCallbacks);
    bufcEnabledCallbacks = 0;
    BUFC_ConfigureCallbacks(0);
    RAILCb_RfReady();
    return 0;
  }
  return 1;
}



//uint RFHAL_SetPtiProtocol(uint param_1,undefined4 param_2,undefined4 param_3,uint param_4)
RAIL_Status_t RFHAL_SetPtiProtocol(RAIL_PtiProtocol_t protocol)
{
  uint uVar2;
  
  uVar2 = protocol & 0xfffffff0;
  if (uVar2 == 0) 
  {
    param_4 = SEQ->REG06C & 0xfffffff0 | protocol & 0xf;
    protocol = uVar2;
  }
  if (uVar2 == 0) SEQ->REG06C = param_4;
  else protocol = 1;
  return protocol;
}


void RFHAL_IdleExt(RAIL_RfIdleMode_t mode)
{
  switch(mode) 
  {
  case RAIL_IDLE:
	GENERIC_PHY_RadioIdle(0,0,0);
    break;
  case RAIL_IDLE_ABORT:
	GENERIC_PHY_RadioIdle(1,0,0);
    break;
  case RAIL_IDLE_FORCE_SHUTDOWN:
	GENERIC_PHY_RadioIdle(1,1,0);
    break;
  case RAIL_IDLE_FORCE_SHUTDOWN_CLEAR_FLAGS:
    GENERIC_PHY_RadioIdle(1,1,1);
	break;
  default:
    break;
  }
}


RAIL_RadioState_t RFHAL_StateGet(void)

{
  uint32_t state;
  bool bVar2;

  state = RAC->STATUS & 0xf000000;
  if (state != 0x7000000) 
  {
    if (0x7000000 < state) 
	{
      if (state != 0xa000000) 
	  {
        if (state < 0xa000001) 
		{
          if (state == 0x8000000) return RAIL_RF_STATE_TX; 
	      bVar2 = state == 0x9000000;
        }
        else 
		{
          if (state == 0xb000000) return RAIL_RF_STATE_TX;
          bVar2 = state == 0xc000000;
        }
        if (!bVar2) return RAIL_RF_STATE_IDLE;
      }
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



bool RFHAL_OkToTransmit(void)

{
  return ((RAC->SR0 ^ 0x80) << 0x18) >> 0x1f;
}



int RFHAL_HeadedToIdle(void)

{
  uint uVar1;
  CORE_irqState_t irqState;
  int iVar3;
  uint uVar4;
  bool bVar5;
  uint32_t state;
    
  irqState = CORE_EnterCritical();
  iVar3 = PROTIMER_CCTimerIsEnabled(3);
  if ((iVar3 == 0) && (iVar3 = PROTIMER_LBTIsActive(), iVar3 == 0)) 
  {
    uVar4 = (RAC->STATUS);
    uVar1 = (RAC->SR0);
    CORE_ExitCritical(irqState);
    if ((((RAC->STATUS & 0xc0000000) == 0) && (RAC->SR0 & 0x80) && (RAC->STATUS & RAC_STATUS_STATE_Msk != 0x6000000)) 
	{
      if (RAC->STATUS < 0x6000001) bVar5 = uVar4 == 0x3000000;
      else 
	  {
        if (RAC->STATUS == 0x9000000) return 0;
        bVar5 = uVar4 == 0xc000000;
      }
      if (!bVar5) iVar3 = 1;
    }
  }
  else 
  {
    CORE_ExitCritical(irqState);
    iVar3 = 0;
  }
  return iVar3;
}


uint8_t RFHAL_TxDataLoad(RAIL_TxData_t *txData)
{
  CORE_irqState_t irqState;
  uint32_t status;
  
  irqState = CORE_EnterCritical();
  status = (RAC->STATUS & RAC_STATUS_STATE_Msk) >> RAC_STATUS_STATE_Pos;
  if (((status - 7 < 3) || (status == 0xc)) && ((RAC->SR0 & 0x10000)) 
  {  
	CORE_ExitCritical(irqState);
	return 3;
  }
  else 
  {
    BUFC->BUF0_CMD = 1;
    BUFC_WriteBuffer(0,*txData->dataPtr,txData->dataLength,txData->dataLength);
	CORE_ExitCritical(irqState);
    return 0;
  }
}


uint8_t RAIL_CcaCsma(void *params)
//undefined4 RAIL_CcaCsma(uint16_t *param_1,undefined4 param_2)
{
  uint8_t bVar1;
  uint16_t uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint8_t bVar9;
  uint uVar10;
  uint8_t bVar11;
  uint8_t bVar12;
  uint8_t bVar13;
  PROTIMER *pPVar14;
  uint uVar15;
  
  saveRssiPeriodPreCca = AGC->CTRL1;
  if (params == NULL) 
  {
    BUS_RegMaskedClear(&AGC->CTRL1,0xffffff00);
    BUS_RegMaskedSet(&AGC->CTRL1,saveRssiPeriodInCca & 0xffffff00);
    PROTIMER_LBTUseLastConfig();
  }
  else 
  {
    RADIO_SetAgcCcaParams(params[3],(int)*(char *)((int)params + 3),saveRssiPeriodPreCca,&saveRssiPeriodPreCca,params,param_2);
    saveRssiPeriodInCca = (AGC->CTRL1);
    bVar13 = *(uint8_t *)(params + 1);
    bVar1 = *(uint8_t *)params;
    bVar12 = *(uint8_t *)((int)params + 1);
    bVar11 = bVar13;
    bVar9 = bVar13;
    if (bVar13 != 0) 
	{
      bVar9 = bVar13 - 1;
      bVar13 = bVar1;
      if (bVar12 < bVar1) 
	  {
        bVar12 = bVar1;
        bVar11 = 1;
      }
      else bVar11 = 1;
    }
    uVar10 = count_leading_zeroes((uint)*params);
    pPVar14 = (PROTIMER *)0x10683;
    uVar2 = PROTIMER_UsToPrecntOverflow(params[2]);
    uVar3 = (uint)uVar2;
    if (uVar10 >> 5 == 0) 
	{
      uVar7 = (uint)reseedRandom_8945;
      if (uVar7 != 0xf804) 
	  {
        PROTIMER->RANDOM = uVar7;
        reseedRandom_8945 = 0xf804;
      }
    }
    else 
	{
      uVar8 = 0;
      uVar7 = uVar3;
      while( true ) 
	  {
        uVar15 = uVar8 & 0xff;
        uVar8 = uVar8 + 1;
        if (uVar7 < 0x100) break;
        uVar7 = uVar7 >> 1;
      }
      if ((uVar15 != 0) && (uVar7 != 0xff)) uVar7 = (uint)(uint16_t)(((uint16_t)((int)uVar3 >> (uVar15 - 1 & 0xff)) & 1) + (int16_t)uVar7);
      uVar3 = uVar7;
      uVar7 = PROTIMER->RANDOM;
      reseedRandom_8945 = (uint16_t)(uVar7 & 0xffff);
      if ((uVar7 & 0xffff) == 0xf804) reseedRandom_8945 = 0xf805;
      PROTIMER->RANDOM = (1 << uVar15) - 1;
      bVar12 = 8;
      PROTIMER->LBTSTATE = 0x800000;
      bVar13 = 8;
    }
    if (uVar3 < 0x100) uVar3 --;
    else uVar3 = 0xff;
    PROTIMER->BASECNTTOP = uVar3;
    PROTIMER_LBTCfgSet(bVar13,bVar12,bVar11,bVar9,0);
    if (uVar10 >> 5 != 0) 
	{
      BUS_RegMaskedSet(&PROTIMER->LBTCTRL,0x100000);
	  PROTIMER->CTRL &= 0xff3fffff;
	  PROTIMER->CTRL |= 0x400000;
    }
    lbtTimeout_8944 = *(int *)(params + 4);
  }
  GENERIC_PHY_PacketTxCommon();
  iVar6 = lbtTimeout_8944;
  if (lbtTimeout_8944 != 0) 
  {
    if (PROTIMER_CCTimerIsEnabled(4) != 0) PROTIMER_CCTimerStop(4);
    if (PROTIMER_CCTimerStart(4,PROTIMER_UsToPrecntOverflow(iVar6),1) == 0) return 1;
  }
  PROTIMER_LBTStart();
  return 0;
}


//void RAIL_CcaLbt(uint *param_1,uint param_2,uint param_3,uint param_4)
uint8_t RAIL_CcaLbt(void *params)

{
  uint uVar1;
  uint8_t bVar2;
  undefined4 local_14;
  undefined4 local_10;
  uint uStack12;
  
  local_14 = param_2;
  local_10 = param_3;
  uStack12 = param_4;
  if ((params != NULL) && (*(int16_t *)params != 0)) 
  {
    local_14 = *params;
    local_10._2_2_ = (uint16_t)(params[1] >> 0x10);
    uStack12 = params[2];
    bVar2 = *(uint8_t *)params;
    if (bVar2 != 0) 
	{
      local_10._2_2_ = *(int16_t *)(params + 1) * (uint16_t)bVar2 + local_10._2_2_;
      local_14._1_1_ = (char)(local_14 >> 8);
      local_14._2_2_ = (undefined2)(local_14 >> 0x10);
      local_14 = (uint)CONCAT21(local_14._2_2_,local_14._1_1_ - bVar2) << 8;
    }
    uVar1 = local_14 >> 8 & 0xff;
    for (bVar2 = 1; (uint)(1 << (uint)bVar2) < uVar1; bVar2 = bVar2 + 1) 
	{
    }
    local_10 = uVar1 * *(uint16_t *)(params + 1) + ((uint)(1 << (uint)bVar2) >> 1) >> (uint)bVar2 & 0xffff | (uint)local_10._2_2_ << 0x10;
    local_14._0_2_ = CONCAT11(bVar2,bVar2);
    local_14 = local_14 & 0xffff0000 | (uint)(uint16_t)local_14;
    params = &local_14;
  }
  RAIL_CcaCsma(params);
}



void RFHAL_SetCcaThreshold(void)

{
  RADIO_AGCCCAThresholdSet();
}



int16_t RFHAL_PollAverageRSSI(int32_t time)

{
  int16_t sVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  bool bVar10;
  
  if (time == 0) return RADIO_GetRSSI();

  uVar3 = PROTIMER_GetTime();
  uVar4 = PROTIMER_UsToPrecntOverflow(time);
  iVar2 = 0;
  uVar8 = 0;
  iVar9 = 0;
  while(true) 
  {
    uVar5 = PROTIMER_GetTime();
    uVar6 = PROTIMER_ElapsedTime(uVar3,uVar5);
    if (PROTIMER_GetTime() <= PROTIMER_ElapsedTime(uVar3,uVar5)) break;
    iVar7 = RADIO_GetRSSI();
    if (iVar7 != -0x200) 
	{
      uVar6 = SEXT24((int16_t)iVar7);
      bVar10 = CARRY4(uVar8,uVar6);
      uVar8 = uVar8 + uVar6;
      iVar9 = iVar9 + ((int)uVar6 >> 0x1f) + (uint)bVar10;
      iVar2 = iVar2 + 1;
    }
  }
  if (iVar2 == 0) return -0x200;
  else return (int)(__aeabi_ldivmod(uVar8,iVar9,iVar2,iVar2 >> 0x1f));
}



int RFHAL_StartAverageRSSI(undefined4 param_1,undefined4 param_2)

{
  int iVar2;
  
  isRssiReady = 0;
  saveRssiPeriod = AGC->CTRL1;
  if (RADIO_CalcRssiPeriod(param_2) == 0) 
  {
    //if (_DAT_430c0354 != 0) iVar2 = 1;
	if (MODEM->CTRL0 & MODEM_CTRL0_DETDIS_Msk) iVar2 = 1;
    saveFrameDetDisable = (uint8_t)iVar2;
    BUS_RegMaskedSet(&MODEM->CTRL0,0x200000);
    if (RAIL_RxStart(param_1) == 0) 
	{
      _enabledCallbacks = _enabledCallbacks | 0x4000000;
      GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
	  return 0;
    }
    else return 2;
  }
  else return 1;
}



int16_t RFHAL_GetAverageRSSI(void)

{
  return (int16_t)currentRssiAverage;
}



bool RFHAL_AverageRSSIReady(void)

{
  return isRssiReady;
}

/* typedef struct RAIL_ScheduleRxConfig {
  uint32_t start;
  RAIL_TimeMode_t startMode;
  uint32_t end;
  RAIL_TimeMode_t endMode;
  uint8_t rxTransitionEndSchedule;
  uint8_t hardWindowEnd;
} RAIL_ScheduleRxConfig_t; */



//void RFHAL_ScheduleRx(undefined4 param_1,undefined4 *param_2)
uint8_t RFHAL_ScheduleRx(uint8_t channel, RAIL_ScheduleRxConfig_t *cfg)
{
  undefined4 uVar1;
  undefined4 uVar2;
  char cVar3;
  uint uVar4;
  char cVar5;
  char cVar6;
  
  cVar6 = *(char *)(cfg + 1);
  if (cVar6 == 2) uVar1 = 0;
  else 
  {
    uVar1 = PROTIMER_UsToPrecntOverflow(cfg->start);
    cVar6 = *(char *)(cfg + 1);
    if (cVar6 != 0) cVar6 = 1;
  }
  cVar5 = *(char *)(cfg + 3);
  if (cVar5 == 2) uVar2 = 0;
  else 
  {
    uVar2 = PROTIMER_UsToPrecntOverflow(cfg[2]);
    cVar5 = *(char *)(cfg + 3);
    if (cVar5 != 1) cVar5 = 1;
  }
  uVar4 = count_leading_zeroes((uint)*(uint8_t *)((int)cfg + 0xd));
  cVar3 = *(char *)((int)cfg + 0xe);
  if (cVar3 != 0) cVar3 = 1;
  GENERIC_PHY_SchedulePacketRx(uVar1,cVar6,uVar2,cVar5,uVar4 >> 5,cVar3);
}



void RAIL_ScheduleTx(undefined4 *param_1)

{
  undefined4 uVar1;
  char cVar2;
  
  cVar2 = *(char *)(param_1 + 1);
  if (cVar2 != 0) cVar2 = 1;
  GENERIC_PHY_SchedulePacketTx(PROTIMER_UsToPrecntOverflow(*param_1),cVar2);
}



//undefined4 RFHAL_RxStart(void)
uint8_t RFHAL_RxStart(uint8_t channel)
{
  if ((RAC->RXENSRCEN & 0xff) == 0) BUFC_RxBufferReset();
  GENERIC_PHY_StartRx(channel);
  return 0;
}



undefined4 RFHAL_EnableRxRawCapture(int param_1,uint param_2)

{
  if (param_1 - 1U & 0xff < 3) param_2 = *(uint *)(&CSWTCH_104 + (param_1 - 1U & 0xff) * 4);
  if (2 < uVar2) param_2 = 0;
  MODEM->CTRL0 &= ~MODEM_CTRL0_DEMODRAWDATASEL_Msk;
  MODEM->CTRL0 |= param_2;
  BUS_RegMaskedSet(&MODEM->CTRL0,MODEM_CTRL0_DETDIS_Msk);
  FRC->BUFFERMODE &= ~FRC_BUFFERMODE_RXBUFFERMODE_Msk; //0xfffffff9;
  FRC->BUFFERMODE |= 4;
  BUS_RegMaskedSet(&RAC->SR3,0x10000000);
  FRC->RAWCTRL = 4;
  return 0;
}



void RFHAL_DisableRxRawCapture(void)

{
  BUS_RegMaskedClear(&FRC->BUFFERMODE,FRC_BUFFERMODE_RXBUFFERMODE_Msk);
  FRC->RAWCTRL = 0;
  BUS_RegMaskedClear(&RAC->SR3,0x10000000);
  BUS_RegMaskedClear(&MODEM->CTRL0,MODEM_CTRL0_DETDIS_Msk);
  BUS_RegMaskedClear(&MODEM->CTRL0,MODEM_CTRL0_DEMODRAWDATASEL_Msk);
}



void RFHAL_EnableRxAppendedInfo(void)

{
  FRC->TRAILRXDATA = FRC_TRAILRXDATA_PROTIMERCC0WRAPH_Msk | FRC_TRAILRXDATA_PROTIMERCC0WRAPL_Msk | FRC_TRAILRXDATA_CRCOK_Msk | FRC_TRAILRXDATA_RSSI_Msk; //0x1b;
}



void RFHAL_DisableRxAppendedInfo(void)

{
  FRC->TRAILRXDATA = 0;
}

//undefined4 RFHAL_RxIntEnable(uint param_1)
uint32_t RFHAL_RxIntEnable(uint32_t cbToEnable)
{
  _enabledCallbacks =
       CONCAT11(DAT_000113b1 & 0xc5 | (uint8_t)(((cbToEnable << 0x1e) >> 0x1f) << 3) |
                (uint8_t)(((cbToEnable << 0x1d) >> 0x1f) << 4) | (uint8_t)(((cbToEnable << 0x1c) >> 0x1f) << 5)
                | (uint8_t)(((cbToEnable << 0x14) >> 0x1f) << 1),
                enabledCallbacks & 0x87 | (uint8_t)(((cbToEnable << 0x1b) >> 0x1f) << 3) |
                (uint8_t)(((cbToEnable << 0x1a) >> 0x1f) << 4) | (uint8_t)(((cbToEnable << 0x15) >> 0x1f) << 5)
                | ((cbToEnable & 0x300) != 0) << 6);
  _enabledCallbacks = _enabledCallbacks & 0xffff0000 | (uint)_enabledCallbacks;
  bufcEnabledCallbacks =
       bufcEnabledCallbacks & 0xffffff00 |
       (uint)((uint8_t)bufcEnabledCallbacks & 0xf7 | (uint8_t)(cbToEnable << 3) & 8);
  rxConfigEvents = cbToEnable;
  GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
  BUFC_ConfigureCallbacks(bufcEnabledCallbacks);
  return 0;
}


RAIL_Status_t RFHAL_SetRxOptions(uint32_t options)
{
  if ((RAC->STATUS & RAC_STATUS_STATE_Msk) >> RAC_STATUS_STATE_Pos == 3) return RAIL_STATUS_INVALID_STATE;
  options &= 1;
  if (options == 0) BUS_RegMaskedClear(&FRC->RXCTRL,FRC_RXCTRL_STORECRC_Msk);
  else 
  {
    options = 0;
    BUS_RegMaskedSet(&FRC->RXCTRL,FRC_RXCTRL_STORECRC_Msk);
  }
  return (RAIL_Status_t)options;
}


uint32_t RFHAL_TxIntEnable(uint32_t cbToEnable)
{
  _enabledCallbacks =
       CONCAT12(DAT_000113b2 & 0x7f | 0x40 | (uint8_t)(((cbToEnable << 0x19) >> 0x1f) << 7),
                _enabledCallbacks);
  _enabledCallbacks =
       _enabledCallbacks & 0xffffff00 |
       (uint)(uint8_t)((uint8_t)(_enabledCallbacks >> 0x18) & 0xfe | (uint8_t)cbToEnable >> 7) << 0x18 |
       (uint)(uint8_t)(enabledCallbacks & 0xfd | ((cbToEnable & 0x1b) != 0) << 1);
  bufcEnabledCallbacks =
       bufcEnabledCallbacks & 0xffffff00 |
       (uint)((uint8_t)bufcEnabledCallbacks & 0xfd | (uint8_t)(cbToEnable << 1) & 2);
  txConfigEvents = cbToEnable;
  GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
  BUFC_ConfigureCallbacks(bufcEnabledCallbacks);
  return 0;
}



RAIL_Status_t RFHAL_ErrorConfig(uint8_t ignoreErrors)
{
  if ((ignoreErrors & 1) == 0) BUS_RegMaskedClear(&FRC->RXCTRL,FRC_RXCTRL_ACCEPTCRCERRORS_Msk);
  else BUS_RegMaskedSet(&FRC->RXCTRL,FRC_RXCTRL_ACCEPTCRCERRORS_Msk);
  return RAIL_STATUS_NO_ERROR;
}



RAIL_Status_t RAIL_PaCtuneSet(uint8_t txPaCtuneValue, uint8_t rxPaCtuneValue)

{
  return PA_CTuneSet(txPaCtuneValue, rxPaCtuneValue);
}


uint32_t RAIL_TimerGet(void)

{
  return PROTIMER_PrecntOverflowToUs(GENERIC_PHY_TimerGetTimeout());
}



void RAIL_TimerCancel(void)

{
  undefined4 extraout_r1;
  undefined4 in_r3;
  
  GENERIC_PHY_TimerStop();
  _enabledCallbacks = _enabledCallbacks & 0xfdffffff;
  GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks,extraout_r1,DAT_000113b3 & 0xfd,in_r3);
}


RAIL_Status_t RAIL_TimerSet(uint32_t time, RAIL_TimeMode_t mode)
{
  RAIL_Status_t result;

  CORE_irqState_t irqState;
  if (mode == RAIL_TIME_DISABLED) 
  {
    RAIL_TimerCancel();
    return RAIL_STATUS_NO_ERROR;
  }
  else 
  {
	irqState = CORE_EnterCritical();
	_enabledCallbacks = _enabledCallbacks | 0x2000000;
	GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
	timerExpired = 0;
	if (GENERIC_PHY_TimerStart(PROTIMER_UsToPrecntOverflow(time),mode)==true) result = RAIL_STATUS_NO_ERROR;
	else result = RAIL_STATUS_INVALID_STATE; //not sure but maybe
	CORE_ExitCritical(irqState);
	return result;
  }
}



bool RAIL_TimerExpired(void)

{
  if (GENERIC_PHY_TimerExpired() != 0) return true;
  else return timerExpired & 1;
}



bool RAIL_TimerIsRunning(void)

{
  return GENERIC_PHY_TimerIsRunning();
}


uint32_t RAIL_SymbolRateGet(void)

{
  return RADIO_ComputeTxSymbolRate();
}



uint32_t RAIL_BitRateGet(void)

{
  return RADIO_ComputeTxBitRate();
}


//void RAIL_RfSense(undefined param_1,undefined4 param_2,int param_3,uint param_4)
uint32_t RAIL_RfSense(RAIL_RfSenseBand_t band, uint32_t senseTime, bool enableCb)
{
  code *local_14;
  undefined4 local_10;
  uint local_c;
  
  local_14 = RAIL_RFSENSE_Callback;
  if (param_3 == 0) local_14 = NULL;
  local_c._0_2_ = CONCAT11(1,param_1);
  local_c = param_4 & 0xffff0000 | (uint)(uint16_t)local_c;
  local_10 = param_2;
  RFSENSE_Init(&local_14);
}


bool RAIL_RfSensed(void)

{
  return RFSENSE_Sensed();
}


//void RAIL_DebugCbConfig(int param_1)
void RAIL_DebugCbConfig(uint32_t cbToEnable)
{
  _enabledCallbacks = CONCAT11(DAT_000113b1 & 0x7f | (uint8_t)(((uint)(cbToEnable << 0x1e) >> 0x1f) << 7),enabledCallbacks);
  _enabledCallbacks = _enabledCallbacks & 0xffff0000 | (uint)_enabledCallbacks;
  GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
}


void RFHAL_CalibrationInit(int param_1)

{
  IRCAL_Init(*(undefined4 *)(param_1 + 4));
}



void RFHAL_CalibrationRun(int *param_1,int param_2)

{
  int iVar1;
  
  if (param_2 << 0x1f < 0) TEMPCAL_Perform();
  if (param_2 << 0xf < 0) 
  {
    if (*param_1 == -1) 
	{
      iVar1 = IRCAL_Perform();
      *param_1 = iVar1;
      return;
    }
    IRCAL_Set();
    return;
  }
  return;
}


RAIL_Status_t RFHAL_SetTxTransitions(RAIL_RadioState_t success,RAIL_RadioState_t error)
{
  SEQ->REG00C &= 0x0000ffff;
  SEQ->REG00C |= (1 << (success + 0x10U & 0xff)) | (1 << (error + 0x18U & 0xff));
  return RAIL_STATUS_NO_ERROR;
}


RAIL_Status_t RFHAL_SetRxTransitions(RAIL_RadioState_t success,RAIL_RadioState_t error)
{
  SEQ->REG00C &= 0xffff0000;
  SEQ->REG00C  |= (1 << (error + 8U & 0xff) | 1 << (success & 0xff));
  return RAIL_STATUS_NO_ERROR;
}



//void RFHAL_SetBerConfig(undefined4 *param_1)
void RFHAL_SetBerConfig(RAIL_BerConfig_t *berConfig)
{
  RFTEST_ResetBerStats(*berConfig);
}



void RFHAL_StartBerRx(void)

{
  RFTEST_SaveRadioConfiguration();
  FRC->SNIFFCTRL = 0;
  FRC->DFLCTRL = 5;
  BUS_RegMaskedClear(&MODEM->TIMING,MODEM_TIMING_TIMINGBASES_Msk);
  PTR_rxFifoAlmostFull_00011398 = &RFTEST_BerEmptyBufcAndUpdateStats;
  BUFC_SetCallbacks();
  bufcEnabledCallbacks &= 0xffffff00;
  bufcEnabledCallbacks |= 4;
  BUFC_ConfigureCallbacks(bufcEnabledCallbacks);
  BUFC->BUF1_THRESHOLDCTRL &= 0xfffff000;
  BUFC->BUF1_THRESHOLDCTRL |= 100;
  BUS_RegMaskedSet(&BUFC->IEN,BUFC_IEN_BUF1THR_Msk);
  RFTEST_StartRx();
}



void RFHAL_StopBerRx(void)

{
  RFTEST_BerStop();
  bufcEnabledCallbacks &= 0xffffff00;
  bufcEnabledCallbacks |= bufcEnabledCallbacks & 0xfb);
  BUFC_ConfigureCallbacks(bufcEnabledCallbacks);
  BUS_RegMaskedClear(&BUFC->IEN,BUFC_IEN_BUF1THR_Msk);
  RFTEST_RestoreRadioConfiguration();
}


void RFHAL_GetBerStatus(RAIL_BerStatus_t *status)
{
  RFTEST_ReportBerStats(&status);
}



void RFHAL_SetCRCInitVal(uint16_t val)

{
  RADIO_SetCRCInitVal(val);
}



int32_t RFHAL_GetCurrPowerLevel(void)

{
  return PA_OutputPowerGet();
}

int32_t RFHAL_SetCurrPowerLevel(int32_t powerLevel)
{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar2 = PA_OutputPowerSet(powerLevel);
  pcVar1 = protChChngCB;
  if (protChChngCB != NULL) 
  {
    uVar3 = RAILInt_GetChannel();
    (*pcVar1)(uVar3,1);
  }
  return uVar2;
}



void RFHAL_SetProtocolSpecificChCheckCB(uint32_t cb)

{
  protChChngCB = cb;
}



void RFHAL_StopTestMode(void)

{
  RFTEST_StopTx();
  RFTEST_RestoreRadioConfiguration();
}



void RFHAL_StartCWTestMode(void)

{
  RFTEST_SaveRadioConfiguration();
  RFTEST_StartCwTx();
}



void RFHAL_StartStreamTestMode(void)

{
  RFTEST_SaveRadioConfiguration();
  RFTEST_StartStreamTx();
}



uint32_t RFHAL_SetChannel(int param_1,uint8_t *cfg,int param_3)

{
  if (RAIL_DebugModeGet() != 1) 
  {
    do 
	{
      if (RFHAL_HeadedToIdle() == 0) break;
    } while ((RAC->STATUS & RAC_STATUS_STATE_Pos) != 0);
    if ((RAC->STATUS & RAC_STATUS_STATE_Pos) != 0) return 2;
    if (protChChngCB != NULL) (*protChChngCB)(param_1);
    if (param_3 != 0) SYNTH_Config(*(uint32_t *)(cfg + 8),*(uint32_t *)(cfg + 4));
    GENERIC_PHY_ChannelSet(param_1 - (uint)*cfg & 0xff);
  }
  return 0;
}



bool RFHAL_AutoAckEnable(void)

{
  CORE_irqState_t irqState;
  uint32_t reg;
  
  irqState = CORE_EnterCritical();
  reg = SEQ->REG000;
  SEQ->REG000 |= 0x20;
  CORE_ExitCritical(irqState);
  return (reg << 0x1a) >> 0x1f;
}



bool RFHAL_AutoAckDisable(void)

{
  CORE_irqState_t irqState;
  uint32_t reg;
  
  irqState = CORE_EnterCritical();
  reg = SEQ->REG000;
  SEQ->REG000 &= 0xffffffdf;
  CORE_ExitCritical(irqState);
  return (reg << 0x1a) >> 0x1f;
}



bool RFHAL_AutoAckIsEnabled(void)

{
  return (SEQ->REG000 << 0x1a) >> 0x1f;
}


void RFHAL_AutoAckConfig(RAIL_AutoAckConfig_t *config)
{
  SEQ->REG008 = -(PROTIMER_UsToPrecntOverflow(*(uint16_t *)(config + 6)));
}


RAIL_Status_t RFHAL_AutoAckLoadBuffer(RAIL_AutoAckData_t *ackData)
{
  CORE_irqState_t irqState;
  uint32_t state;
  
  irqState = CORE_EnterCritical();
  BUS_RegMaskedSet(&RAC->SR0,2);
  state = (RAC->STATUS & RAC_STATUS_STATE_Msk) >> RAC_STATUS_STATE_Pos;
  if (((state - 7 < 3) || (state == 0xc)) && (RAC->SR0 & 0x20000)) 
  {
	BUS_RegMaskedClear(&RAC->SR0,2);
	CORE_ExitCritical(irqState);
	return RAIL_STATUS_INVALID_CALL;
  }
  
  else 
  {
    BUFC_TxAckBufferSet(*ackData->dataPtr,ackData->dataLength);
	BUS_RegMaskedClear(&RAC->SR0,2);
	CORE_ExitCritical(irqState);
	return RAIL_STATUS_NO_ERROR;
  }
}



void RFHAL_AutoAckRxPause(void)

{
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  SEQ->REG000 |= 8;
  CORE_ExitCritical(irqState);
}



void RFHAL_AutoAckRxResume(void)

{
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  SEQ->REG000 &= 0xfffffff7;
  CORE_ExitCritical(irqState);
}



void RFHAL_AutoAckTxPause(void)

{
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  SEQ->REG000 |= 0x100;
  CORE_ExitCritical(irqState);
}



void RFHAL_AutoAckTxResume(void)

{
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  SEQ->REG000 &= 0xfffffeff;
  CORE_ExitCritical(irqState);
}



bool RFHAL_AutoAckRxIsPaused(void)

{
  return (SEQ->REG000 << 0x1c) >> 0x1f;
}



bool RFHAL_AutoAckTxIsPaused(void)

{
  return (SEQ->REG000 << 0x17) >> 0x1f;
}



bool RFHAL_AutoAckUseTxBuffer(void)

{
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  if (GENERIC_PHY_CanModifyAck() != 0) 
  {
    BUS_RegMaskedSet(&RAC->SR0,2);
    if (RAC->SR0 & 0x20000) BUS_RegMaskedSet(&RAC->SR2,0x40);
    BUS_RegMaskedClear(&RAC->SR0,2);
	CORE_ExitCritical(irqState);
	return RAC->SR0 & 0x20000;
  }
  else
  {
	CORE_ExitCritical(irqState);
	return false;
  }
}



bool RFHAL_AutoAckCancelAck(void)

{
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  if (GENERIC_PHY_CanModifyAck() == 0) 
  {
	CORE_ExitCritical(irqState);
	return false;
  }
  else
  {
    BUS_RegMaskedSet(&RAC->SR0,2);
    if (RAC->SR0 & 0x20000) BUS_RegMaskedSet(&RAC->SR2,0x20);
    BUS_RegMaskedClear(&RAC->SR0,2);
	CORE_ExitCritical(irqState);
	return RAC->SR0 & 0x20000;
  }
}



void RFHAL_AutoAckWaitForAck(int enable)

{
  if (enable == 0) BUS_RegMaskedSet(&RAC->SR0,0x100);
  else BUS_RegMaskedClear(&RAC->SR0,0x100);
}



//code * RFHAL_TxStart(undefined4 param_1,undefined *param_2,code *param_3,undefined4 param_4)
//uint8_t RAIL_TxStartWithOptions(uint8_t channel,RAIL_TxOptions_t *options,RAIL_PreTxOp_t preTxOp,void *preTxOpParams);
uint8_t RFHAL_TxStart(uint8_t channel,RAIL_TxOptions_t *options,code void *preTxOpParams,RAIL_PreTxOp_t preTxOp)

{
  if ((preTxOpParams != NULL) && (RFHAL_AutoAckIsEnabled() != 0)) RFHAL_AutoAckWaitForAck(*options);
  if (preTxOpParams == NULL) GENERIC_PHY_PacketTx();
  else 
  {
    preTxOpParams = (code *)(*preTxOpParams)(preTxOp);
    if (preTxOpParams != NULL) 
	{
      BUS_RegMaskedClear(&RAC->SR0,0x100);
      return preTxOpParams;
    }
  }
  return preTxOpParams;
}



bool RFHAL_AutoAckWaitingForAck(void)

{
  return (RAC->SR1 << 0x1c) >> 0x1f;
}


uint16_t RFHAL_WriteTxFifo(uint8_t *dataPtr, uint16_t writeLength)
{
  if (BUFC_GetSpaceAvailable(0) <= writeLength) writeLength = BUFC_GetSpaceAvailable(0);
  BUFC_WriteBuffer(0,dataPtr,writeLength);
  return writeLength;
}


uint16_t RFHAL_ReadRxFifo(uint8_t *dataPtr, uint16_t readLength)
{
  if (BUFC_GetBytesAvailable(1) <= readLength) readLength = BUFC_GetBytesAvailable(1);
  BUFC_ReadBuffer(1,dataPtr,readLength);
  return readLength;
}

//typedef struct RAIL_AppendedInfo {
//  uint32_t timeUs;
//  bool crcStatus:1;
//  bool frameCodingStatus:1;
//  bool isAck:1;
//  int8_t rssiLatch;
//  uint8_t lqi;
//  uint8_t syncWordId;
//} RAIL_AppendedInfo_t;

//void RFHAL_ReadRxFifoAppendedInfo(undefined4 *param_1)
void RFHAL_ReadRxFifoAppendedInfo(RAIL_AppendedInfo_t *appendedInfo)
{
  undefined auStack28 [5];
  undefined local_17;
  uint8_t local_16;
  undefined4 local_10;
  
  GENERIC_PHY_PacketRxAppendedInfoHelper(RADIO_RxTrailDataLength(),auStack28);
  FRC->IEN._0_1_;
  
  *(uint8_t *)(appendedInfo + 1) = *(uint8_t *)(appendedInfo + 1) & 0xfd | (uint8_t)((((FRC->IF ^ FRC_IFS_BLOCKERROR_Msk) << 0x18) >> 0x1f) << 1);
  FRC->IFC = FRC_IFC_BLOCKERROR_Msk; //0x80;
  if (local_16 != 0) local_16 = 1;
  *(undefined *)((int)appendedInfo + 5) = local_17;
  *(uint8_t *)(appendedInfo + 1) = *(uint8_t *)(appendedInfo + 1) & 0xfe | local_16 & 1;
  *appendedInfo = TIMING_GetRxTimestampUs(local_10);
  *(undefined *)((int)appendedInfo + 7) = 0;
}


uint16_t RFHAL_SetRxFifoThreshold(uint16_t rxThreshold)
{
  if (rxThreshold < 0x201) rxThreshold = 0x200;
  BUFC->BUF1_THRESHOLDCTRL &= ~BUFC_BUF1_THRESHOLDCTRL_THRESHOLD_Msk;
  BUFC->BUF1_THRESHOLDCTRL = rxThreshold;
  return BUFC->BUF1_THRESHOLDCTRL & BUFC_BUF1_THRESHOLDCTRL_THRESHOLD_Msk;
}



uint16_t RFHAL_GetTxFifoThreshold(void)

{
  return (BUFC->BUF0_THRESHOLDCTRL & BUFC_BUF1_THRESHOLDCTRL_THRESHOLD_Msk) + 1;
}

uint16_t RFHAL_SetTxFifoThreshold(uint16_t txThreshold)
{
  if (0x1ff < txThreshold) txThreshold = 0x200;
  BUFC->BUF0_THRESHOLDCTRL &= ~BUFC_BUF0_THRESHOLDCTRL_THRESHOLD_Msk;
  BUFC->BUF0_THRESHOLDCTRL |= (txThreshold - 1) & BUFC_BUF0_THRESHOLDCTRL_THRESHOLD_Msk;
  return RFHAL_GetTxFifoThreshold();
}



uint16_t RFHAL_GetRxFifoThreshold(void)

{
  return BUFC->BUF1_THRESHOLDCTRL & BUFC_BUF1_THRESHOLDCTRL_THRESHOLD_Msk;
}



void RFHAL_EnableRxFifoThreshold(void)

{
  BUS_RegMaskedSet(&BUFC->IEN,BUFC_IEN_BUF1THR_Msk);
}



void RFHAL_DisableRxFifoThreshold(void)

{
  BUS_RegMaskedClear(&BUFC->IEN,BUFC_IEN_BUF1THR_Msk);
}



uint16_t RFHAL_GetTxFifoSpaceAvailable(void)

{
  return BUFC_GetSpaceAvailable(0);
}



uint16_t RFHAL_GetRxFifoBytesAvailable(void)

{
  return BUFC_GetBytesAvailable(1);
}



void RFHAL_ResetTxFifo(void)

{
  BUS_RegMaskedClear(&BUFC->IEN,BUFC_IEN_BUF0THR_Msk);
  BUFC->BUF0_CMD = BUFC_BUF0_CMD_CLEAR_Msk;
  BUS_RegMaskedClear(&BUFC->BUF0_THRESHOLDCTRL,BUFC_BUF0_THRESHOLDCTRL_THRESHOLDMODE_Msk);
  BUS_RegMaskedSet(&BUFC->IEN,BUFC_IEN_BUF0THR_Msk);
}



void RFHAL_ResetRxFifo(void)

{
  BUS_RegMaskedClear(&BUFC->IEN,BUFC_IF_BUF1THR_Msk);
  BUFC->BUF1_CMD = BUFC_BUF1_CMD_CLEAR_Msk;
  BUS_RegMaskedClear(&BUFC->BUF1_THRESHOLDCTRL,BUFC_BUF1_THRESHOLDCTRL_THRESHOLDMODE_Msk);
  BUS_RegMaskedSet(&BUFC->IEN,BUFC_IF_BUF1THR_Msk);
}


typedef struct {
  RAIL_TxDataSource_t txSource; /**< Source of TX Data */
  RAIL_RxDataSource_t rxSource; /**< Source of RX Data */
  RAIL_DataMethod_t txMethod; /**< Method of providing transmit data */
  RAIL_DataMethod_t rxMethod; /**< Method of retrieving receive data */
} RAIL_DataConfig_t;

typedef enum{
  TX_PACKET_DATA, /**< Use the frame hardware to packetize data */
} RAIL_TxDataSource_t;


RAIL_Status_t RFHAL_DataConfig(RAIL_DataConfig_t *dataConfig)
{
  //if (*(char *)(dataConfig + 2) == *(char *)(dataConfig + 3)) 
  if(dataConfig->txMethod == dataConfig->rxMethod)
  {
    if (dataConfig->rxSource == RX_PACKET_DATA) RFHAL_DisableRxRawCapture();
    else RFHAL_EnableRxRawCapture();
    if (dataConfig->txMethod == PACKET_MODE) bufcEnabledCallbacks = bufcEnabledCallbacks & 0xffffff00 | (uint)((uint8_t)bufcEnabledCallbacks & 0xfe);
    else 
	{
      bufcEnabledCallbacks = bufcEnabledCallbacks & 0xffffff00 | (uint)((uint8_t)bufcEnabledCallbacks | 1);
      RFHAL_ResetTxFifo();
    }
    if (dataConfig->rxMethod == PACKET_MODE) 
	{
      bufcEnabledCallbacks = bufcEnabledCallbacks & 0xffffff00 | (uint)((uint8_t)bufcEnabledCallbacks & 0xfb);
      BUS_RegMaskedSet(&FRC->RXCTRL,FRC_RXCTRL_BUFRESTORERXABORTED_Msk | FRC_RXCTRL_BUFRESTOREFRAMEERROR_Msk); //0x60);
      BUS_RegMaskedClear(&RAC->SR0,0x40);
      BUS_RegMaskedClear(&FRC->RXCTRL,FRC_RXCTRL_ACCEPTCRCERRORS_Msk); //2);
    }
    else 
	{
      bufcEnabledCallbacks = bufcEnabledCallbacks | 4;
      BUS_RegMaskedClear(&FRC->RXCTRL,FRC_RXCTRL_BUFRESTORERXABORTED_Msk | FRC_RXCTRL_BUFRESTOREFRAMEERROR_Msk);
      RFHAL_ResetRxFifo();
      BUS_RegMaskedSet(&RAC->SR0,0x40);
      BUS_RegMaskedSet(&FRC->RXCTRL,FRC->RXCTRL,FRC_RXCTRL_ACCEPTCRCERRORS_Msk);
    }
    BUFC_ConfigureCallbacks(bufcEnabledCallbacks);
    return RAIL_STATUS_NO_ERROR;
  }
  return RAIL_STATUS_INVALID_PARAMETER;
}


uint16_t RFHAL_SetFixedLength(uint16_t length)

{
  if (((FRC->DFLCTRL & FRC_DFLCTRL_DFLMODE_Msk) != 0) && ((FRC->DFLCTRL & FRC_DFLCTRL_DFLMODE_Msk) != 5)) return 0xffff;
  if (length == 0) 
  {
	FRC->DFLCTRL &= ~FRC_DFLCTRL_DFLMODE_Msk;
	FRC->DFLCTRL |= 5;
    return 0;
  }
  BUS_RegMaskedClear(&FRC->DFLCTRL,FRC_DFLCTRL_DFLMODE_Msk);
  if (0xfff < length) length = 0x1000;
  FRC->WCNTCMP0 = length - 1;
  return length;
}

