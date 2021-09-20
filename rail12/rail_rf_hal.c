#include "rail_rf_hal.h"



int INT_Disable(void)

{
  disableIRQinterrupts();
  if (INT_LockCnt != -1) INT_LockCnt = INT_LockCnt ++;
  return INT_LockCnt;
}



void INT_Enable(void)

{
  if ((INT_LockCnt != 0) && (INT_LockCnt-- == 0)) enableIRQinterrupts();
}



void pktTxDoneEvt(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_c;
  undefined4 uStack8;
  
  local_c = param_2;
  uStack8 = param_3;
  GENERIC_PHY_PreviousTxTime();
  local_c = PROTIMER_PrecntOverflowToUs();
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
  if (param_1 & 100000) RAILCb_RxRadioStatus(0x40);
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
  RAILCb_RadioStateChanged((RAC->STATUS & RAC_STATUS_STATE_Msk) >> RAC_STATUS_STATE_Pos);
}



bool softwareTimerExpired(void)

{
  timerExpired = 1;
  GENERIC_PHY_TimerStop();
  return RAILCb_TimerExpired();
}



void racCalRequest(void)

{
  RAIL_RfHalCalibrationPend(1);
}



void protmrLbtEvt(int param_1)

{
  PROTIMER_CCTimerStop(4);
  if (param_1 & 0x400000) 
  {
    RADIO_PTI_AuxdataOutput(0x27);
    GENERIC_PHY_FlushTxPacketBuffer();
    if ((SEQ->REG000 & 0xff000000) == 0x2000000) _DAT_43080004 = 1;
LAB_000100fc:
    RAILCb_TxRadioStatus(4);
    return;
  }
  if (param_1 & 0x100000) 
  {
    RADIO_PTI_AuxdataOutput(0x28);
    return;
  }
  if (param_1 & 0x1000) 
  {
    PROTIMER_LBTStop();
    if ((PROTIMER->IF & 0x500000) == 0) 
	{
      RADIO_PTI_AuxdataOutput(0x2a);
      GENERIC_PHY_FlushTxPacketBuffer();
      goto LAB_000100fc;
    }
  }
}




void pktRxDoneEvt(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint local_38;
  undefined auStack52 [5];
  undefined local_2f;
  byte local_2e;
  undefined4 local_28;
  
  iVar1 = RADIO_RxTrailDataLength();
  iVar2 = RADIO_RxLengthReadNext();
  if (iVar2 != 0xffff) 
  {
    uVar9 = iVar2 - iVar1 & 0xffff;
    uVar3 = RAILCb_AllocateMemory(uVar9 + 0xc);
    uVar7 = 0;
    while (uVar7 < uVar9) 
	{
      local_38 = uVar9 - uVar7;
      uVar4 = RAILCb_BeginWriteMemory(uVar3,uVar7 + 10,&local_38);
      if (local_38 == 0) 
	  {
        uVar4 = local_38;
        local_38 = uVar9 - uVar7;
      }
      iVar2 = GENERIC_PHY_PacketRxDataHelper(uVar4,local_38 & 0xffff);
      uVar8 = uVar7 + iVar2;
      if (uVar4 == 0) iVar2 = 0;
      RAILCb_EndWriteMemory(uVar3,uVar7 + 10,iVar2);
      uVar7 = uVar8 & 0xffff;
    }
    GENERIC_PHY_PacketRxAppendedInfoHelper(iVar1,auStack52);
    local_38 = 0xc;
    puVar5 = (undefined4 *)RAILCb_BeginWriteMemory(uVar3,0,&local_38);
    if ((puVar5 == NULL) || (local_38 < 0xc)) uVar6 = 0;
    else 
	{
      *(short *)(puVar5 + 2) = (short)uVar9;
      read_volatile(FRC->IEN._0_1_);
      uVar7 = (FRC->IF);
      *(byte *)(puVar5 + 1) =  *(byte *)(puVar5 + 1) & 0xfd | (byte)((((uVar7 ^ 0x80) << 0x18) >> 0x1f) << 1);
      _DAT_43000d1c = 1;
      if (local_2e != 0) local_2e = 1;
      *(byte *)(puVar5 + 1) = *(byte *)(puVar5 + 1) & 0xfe | local_2e & 1;
      *(undefined *)((int)puVar5 + 5) = local_2f;
      *(undefined *)((int)puVar5 + 6) = 0;
      uVar6 = PROTIMER_PrecntOverflowToUs(local_28);
      *(undefined *)((int)puVar5 + 7) = 0;
      *puVar5 = uVar6;
      uVar6 = 0xc;
    }
    RAILCb_EndWriteMemory(uVar3,0,uVar6);
    RAILCb_RxPacketReceived(uVar3);
    RAILCb_FreeMemory(uVar3);
  }
}




void pktRxFrmErr(void)

{
  _DAT_43000d1c = 1;
  RAILCb_RxRadioStatus(0x10);
}



RAIL_Status_t RAIL_RfHalInit(uint32_t *settings)

{
  if (SystemHFXOClockGet() == settings[1]) 
  {
    GENERIC_PHY_Init();
    _enabledCallbacks = _enabledCallbacks & 0xff000000 | (uint)(uint3)((uint3)_enabledCallbacks | 7) | 0x80000;
    if (RAIL_RfHalCalibrationEnableGet() & 0x01) _enabledCallbacks = _enabledCallbacks | 0x10000;
    GENERIC_PHY_SetCallbacks((RAIL_CalMask_t)&callbacks);
    GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
    RAILCb_RfReady();
    return RAIL_STATUS_NO_ERROR;
  }
  return RAIL_STATUS_INVALID_PARAMETER;
}



void RAIL_RfHalIdleStart(void)

{
  GENERIC_PHY_RadioEnable(false);
}



RAIL_RadioState_t RAIL_RfHalStateGet(void)

{
  bool bVar1;
  uint32_t state;

  state = RAC->STATUS & 0xf000000;
  if (state != 0x6000000) 
  {
    if (0x6000000 < state) 
	{
      if (state != 0x9000000) 
	  {
        if (state < 0x9000001) 
		{
          if (state == 0x7000000) return RAIL_RF_STATE_RX;
          bVar1 = state == 0x8000000;
        }
        else 
		{
          if (state == 0xb000000) return RAIL_RF_STATE_TX;
          if (state == 0xc000000) return RAIL_RF_STATE_TX;
          bVar1 = state == 0xa000000;
        }
        if (!bVar1) return RAIL_RF_STATE_IDLE;
      }
      return RAIL_RF_STATE_TX;
    }
    if (state != 0x3000000) 
	{
      if (state < 0x3000001) 
	  {
        if (state == 0x1000000) return RAIL_RF_STATE_RX;
        bVar1 = state == 0x2000000;
      }
      else 
	  {
        if (state == 0x4000000) return RAIL_RF_STATE_RX;
        bVar1 = state == 0x5000000;
      }
      if (!bVar1) return RAIL_RF_STATE_IDLE;
    }
  }
  return RAIL_RF_STATE_RX;
}



bool RFHAL_HeadedToIdle(void)

{
  bool bVar1;
  uint32_t state;
  
  INT_Disable();
  bVar1 = PROTIMER_CCTimerIsEnabled('\x03');
  if ((bVar1 != false) || (bVar1 = PROTIMER_LBTIsActive(), bVar1 != false)) 
  {
    INT_Enable();
    return false;
  }
  state = RAC->STATUS;
  INT_Enable();
  if ((state & 0xc0000000) != 0) return false;
  state = state & 0xf000000;
  if (state == 0x6000000) return false;
  if (state < 0x6000001) bVar1 = state == 0x3000000;
  else 
  {
    if (state == 0x9000000) return false;
    bVar1 = state == 0xc000000;
  }
  if (bVar1) return false;
  return true;
}



uint8_t RAIL_RfHalTxDataLoad(RAIL_TxData_t *txData)

{
  uint32_t local_10;
  uint8_t *local_c;
  
  local_10 = (uint32_t)txData & 0xffff0000 | (uint)txData->dataLength;
  local_c = txData->dataPtr;
  GENERIC_PHY_LoadTxPacketBuffer(&local_10);
  return 0;
}



uint8_t RAIL_CcaCsma(void *params)

{
  byte bVar1;
  ushort uVar2;
  longlong lVar3;
  bool bVar4;
  RAIL_Status_t RVar5;
  uint uVar6;
  uint32_t uVar7;
  uint uVar8;
  uint32_t uVar9;
  uint uVar10;
  uint uVar11;
  char *pcVar12;
  uint uVar13;
  int iVar14;
  byte bVar15;
  byte bVar16;
  byte bVar17;
  byte bVar18;
  PROTIMER *pPVar19;
  
  if (params != (void *)0x0) 
  {
    uVar2 = *(ushort *)((int)params + 6);
    uVar10 = (MODEM->CF);
    uVar8 = (MODEM->RXBR);
    bVar16 = *(byte *)((int)params + 3);
    uVar6 = (uVar8 << 0x16) >> 0x1b;
    iVar14 = (((uVar10 << 0xf) >> 0x12) * (uint)(byte)(&modemCfDec0Factors_8287)[uVar10 & 7] + (uint)(byte)(&modemCfDec0Factors_8287)[uVar10 & 7]) * 2000000;
    uVar7 = CMU_ClockFreqGet(cmuClock_HF);
    lVar3 = (ulonglong)uVar6 * (ulonglong)uVar2 * (ulonglong)uVar7;
    uVar8 = __aeabi_uldivmod((int)lVar3,(int)((ulonglong)lVar3 >> 0x20), (uVar6 * ((uVar8 << 0x13) >> 0x1d) + (uVar8 & 0x1f)) * (((uVar10 << 9) >> 0x1a) * iVar14 + iVar14),0);
    for (uVar10 = 0; (uint)(1 << (uVar10 & 0xff)) < uVar8; uVar10 = uVar10 + 1) 
	{
      if (uVar10 == 0x10) return 1;
    }
	AGC->CTRL1 &= 0xfffff000;
	AGC->CTRL1 |= bVar16 | uVar10 << 8;
    bVar16 = *(byte *)((int)params + 2);
                    // WARNING: Load size is inaccurate
    bVar1 = *params;
    bVar15 = *(byte *)((int)params + 1);
    bVar17 = bVar16;
    bVar18 = bVar16;
    if ((bVar16 != 0) && (bVar16 = bVar16 - 1, bVar17 = 1, bVar18 = bVar1, bVar15 < bVar1)) bVar15 = bVar1;
                    // WARNING: Load size is inaccurate
    uVar10 = count_leading_zeroes((uint)*params);
    pPVar19 = (PROTIMER *)0x7da1;
    uVar9 = PROTIMER_UsToPrecntOverflow((uint)*(ushort *)((int)params + 4));
    uVar8 = uVar9 & 0xffff;
    if (uVar10 >> 5 == 0) 
	{
      pcVar12 = (char *)(uint)(ushort)reseedRandom_8301;
      if (pcVar12 != "z,2=SubGHz,3=both) (and UART input)") 
	  {
        PROTIMER->RANDOM = (uint)pcVar12;
        reseedRandom_8301._0_2_ = 0xf804;
      }
    }
    else 
	{
      uVar13 = 0;
      uVar6 = uVar8;
      while( true ) 
	  {
        uVar11 = uVar13 & 0xff;
        uVar13 = uVar13 + 1;
        if (uVar6 < 0x100) break;
        uVar6 = uVar6 >> 1;
      }
      if ((uVar11 != 0) && (uVar6 != 0xff)) uVar6 = uVar6 + ((int)uVar8 >> (uVar11 - 1 & 0xff) & 1U) & 0xffff;
      uVar8 = (PROTIMER->RANDOM);
      reseedRandom_8301._0_2_ = (ushort)(char *)(uVar8 & 0xffff);
      if ((char *)(uVar8 & 0xffff) == "z,2=SubGHz,3=both) (and UART input)") reseedRandom_8301._0_2_ = 0xf805;
      PROTIMER->RANDOM = (1 << uVar11) - 1;
      bVar15 = 8;
      PROTIMER->LBTSTATE = 0x800000;
      bVar18 = 8;
      uVar8 = uVar6;
    }
    PROTIMER->BASECNTTOP = uVar8;
    PROTIMER_LBTCfgSet(bVar18,bVar15,bVar17,bVar16,0);
    if (uVar10 >> 5 != 0) 
	{
      _DAT_430a09d0 = 1;
	  PROTIMER->CTRL &= 0xff3fffff;
	  PROTIMER->CTRL |= 0x400000;
    }
    lbtTimeout_8300 = *(uint32_t *)((int)params + 8);
  }
  GENERIC_PHY_PacketTxCommon();
  uVar9 = lbtTimeout_8300;
  if (lbtTimeout_8300 != 0) 
  {
    if (PROTIMER_CCTimerIsEnabled(4) != false) PROTIMER_CCTimerStop(4);
    if (PROTIMER_CCTimerStart(4,PROTIMER_UsToPrecntOverflow(uVar9),1) == RAIL_STATUS_NO_ERROR) return 1;
  }
  PROTIMER_LBTStart();
  return 0;
}



uint8_t RAIL_CcaLbt(void *params)

{
  uint8_t uVar1;
  uint uVar2;
  uint in_r1;
  byte bVar3;
  uint in_r2;
  undefined4 in_r3;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 uStack12;
  
  local_14 = in_r1;
  local_10 = in_r2;
  uStack12 = in_r3;
                    // WARNING: Load size is inaccurate
  if ((params != (void *)0x0) && (*params != 0)) {
                    // WARNING: Load size is inaccurate
    local_14 = *params;
    local_10._2_2_ = (ushort)((uint)*(undefined4 *)((int)params + 4) >> 0x10);
    uStack12 = *(undefined4 *)((int)params + 8);
                    // WARNING: Load size is inaccurate
    bVar3 = *params;
    if (bVar3 != 0) 
	{
      local_10._2_2_ = *(short *)((int)params + 4) * (ushort)bVar3 + local_10._2_2_;
      local_14._1_1_ = (char)(local_14 >> 8);
      local_14._2_2_ = (undefined2)(local_14 >> 0x10);
      local_14 = (uint)CONCAT21(local_14._2_2_,local_14._1_1_ - bVar3) << 8;
    }
    uVar2 = local_14 >> 8 & 0xff;
    for (bVar3 = 1; (uint)(1 << (uint)bVar3) < uVar2; bVar3 = bVar3 + 1) 
	{
    }
    local_10 = uVar2 * *(ushort *)((int)params + 4) + ((uint)(1 << (uint)bVar3) >> 1) >> (uint)bVar3 & 0xffff | (uint)local_10._2_2_ << 0x10;
    local_14._0_2_ = CONCAT11(bVar3,bVar3);
    local_14 = local_14 & 0xffff0000 | (uint)(ushort)local_14;
    params = &local_14;
  }
  return RAIL_CcaCsma(params);
}



uint8_t RAIL_ScheduleTx(void *params)

{
  char cVar2;
  
  cVar2 = *(char *)((int)params + 4);
                    // WARNING: Load size is inaccurate
  if (cVar2 != '\0') cVar2 = '\x01';
  GENERIC_PHY_SchedulePacketTx(PROTIMER_UsToPrecntOverflow(*params),cVar2);
  return '\0';
}




uint8_t RAIL_RfHalTxStart(uint8_t channel,RAIL_PreTxOp_t *pretxop,void *params)

{
  if (RAIL_DebugModeGet() != 1) 
  {
    do 
	{
      if (RFHAL_HeadedToIdle() == false) break;
    } while ((RAC->STATUS & RAC_STATUS_STATE_Msk) != 0);
    if ((RAC->STATUS & RAC_STATUS_STATE_Msk) != 0) return 2;
    GENERIC_PHY_ChannelSet(channel);
  }
  if (pretxop != NULL) 
  {
                    // WARNING: Could not recover jumptable at 0x00007f68. Too many branches
                    // WARNING: Treating indirect jump as call
    return (uint8_t)(*pretxop)(params);
  }
  GENERIC_PHY_PacketTx();
  return 0;
}




RAIL_Status_t RAIL_RfHalRxStart(uint8_t channel)

{
  if ((RAC->RXENSRCEN & 0xff) == 0) 
  {
    
  }
  if (RAIL_DebugModeGet() != 1) RADIO_RxBufferReset();
  {
    do 
	{
      if (RFHAL_HeadedToIdle() == false) break;
    } while ((RAC->STATUS & RAC_STATUS_STATE_Msk) != 0);
    if ((RAC->STATUS & RAC_STATUS_STATE_Msk) != 0) return RAIL_STATUS_INVALID_STATE;
    GENERIC_PHY_ChannelSet(channel);
  }
  GENERIC_PHY_StartRx(0);
  return RAIL_STATUS_NO_ERROR;
}



RAIL_Status_t RAIL_RfHalRxIntEnable(int param_1)

{
  _enabledCallbacks = CONCAT12((byte)(_enabledCallbacks >> 0x10) & 0xfd | (byte)(((uint)(param_1 << 0x19) >> 0x1f) << 1),
							CONCAT11(DAT_20002c31 & 0xf8 | (byte)((uint)(param_1 << 0x1e) >> 0x1f) |
                         (byte)(((uint)(param_1 << 0x1d) >> 0x1f) << 1) |
                         (byte)(((uint)(param_1 << 0x1c) >> 0x1f) << 2),
                         enabledCallbacks & 0xe7 | (byte)(((uint)(param_1 << 0x1b) >> 0x1f) << 3) |
                         (byte)(((uint)(param_1 << 0x1a) >> 0x1f) << 4)));
  _enabledCallbacks = _enabledCallbacks & 0xff000000 | (uint)_enabledCallbacks;
  GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
  return RAIL_STATUS_NO_ERROR;
}



RAIL_Status_t RAIL_RfHalErrorConfig(bool errorconfig)

{
  _DAT_43000884 = errorconfig & 1;
  return RAIL_STATUS_NO_ERROR;
}


RAIL_Status_t RAIL_RfHalSetChannelConfig(RAIL_ChannelConfigEntry_t *config)

{
  if (RAIL_DebugModeGet() != 1) SYNTH_Config(config->baseFrequency,config->channelSpacing);
  return RAIL_STATUS_NO_ERROR;
}



RAIL_Status_t RAIL_PaCtuneSet(uint8_t txPaCtuneValue,uint8_t rxPaCtuneValue)

{
  PA_CTuneSet(txPaCtuneValue,rxPaCtuneValue);
  return RAIL_STATUS_NO_ERROR;
}



RAIL_Status_t RAIL_TimerSet(uint32_t time,RAIL_TimeMode_t mode)

{
  RAIL_Status_t RVal;

  INT_Disable();
  _enabledCallbacks = _enabledCallbacks | 0x100000;
  GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
  timerExpired = 0;
  if (mode != 0) mode = 1;
  RVal = GENERIC_PHY_TimerStart(PROTIMER_UsToPrecntOverflow(time),mode);
  INT_Enable();
  return RVal ^ RAIL_STATUS_INVALID_PARAMETER;
}



uint32_t RAIL_TimerGet(void)

{
  return PROTIMER_PrecntOverflowToUs(GENERIC_PHY_TimerGetTimeout());
}



void RAIL_TimerCancel(void)

{
  GENERIC_PHY_TimerStop();
  _enabledCallbacks = _enabledCallbacks & 0xffefffff;
  GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
}

bool RAIL_TimerExpired(void)

{
  if (GENERIC_PHY_TimerExpired() != false) return true;
  else return timerExpired;
}



bool RAIL_TimerIsRunning(void)

{
  //return PROTIMER_CCTimerIsEnabled(2);
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



// WARNING: Could not reconcile some variable overlaps

uint32_t RAIL_RfSense(RAIL_RfSenseBand_t band,uint32_t senseTime,bool enableCb)

{
  uint in_r3;
  undefined4 local_14;
  uint32_t local_10;
  uint local_c;
  
  local_14 = RAIL_RFSENSE_Callback;
  if (enableCb == false) local_14 = NULL;
  local_c._0_2_ = CONCAT11(1,band);
  local_c = in_r3 & 0xffff0000 | (uint)(ushort)local_c;
  local_10 = senseTime;
  return RFSENSE_Init(&local_14,senseTime);
}




bool RAIL_RfSensed(void)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = _DAT_43c81904;
  _DAT_43c81904 = 1;
  uVar3 = RFSENSE->IF;
  if (RFSENSE->IF != 0) uVar3 = 1;
  if (uVar3 != 0) 
  {
    INT_Disable();
    pcVar1 = RFSENSE_Cb;
    RFSENSE_Cb = NULL;
    INT_Enable();
    RFSENSE_Disable();
    if (pcVar1 != NULL) (*pcVar1)();
  }
  if (iVar2 == 0) _DAT_43c81904 = iVar2;
  return SUB41(uVar3,0);
}



void RAIL_DebugCbConfig(int param_1)

{
  _enabledCallbacks = CONCAT11(DAT_000108e1 & 0xef | (byte)(((uint)(param_1 << 0x1e) >> 0x1f) << 4), enabledCallbacks);
  _enabledCallbacks = _enabledCallbacks & 0xffff0000 | (uint)_enabledCallbacks;
  GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
}



void RAIL_RfHalCalibrationRun(int *calvalues,bool calforce)

{
  int32_t iVar1;
  int iVar2;
  int extraout_r1;
  
  iVar2 = (uint)calforce << 0x1f;
  if (iVar2 < 0) 
  {
    TEMPCAL_Perform();
    iVar2 = extraout_r1;
  }
  if (false) 
  {
    if (*calvalues == -1) 
	{
      iVar1 = IRCAL_Perform(0xffffffff,iVar2,(uint)calforce << 0xf);
      *calvalues = iVar1;
      return;
    }
    IRCAL_Set();
    return;
  }
  return;
}


RAIL_Status_t RAIL_RfHalSetTxTransitions(RAIL_RadioState_t success,RAIL_RadioState_t error)

{
  ushort uVar1;
  
  uVar1 = (SEQ->REG000._0_2_);
  SEQ->REG000 = 1 << (success + 0x10 & 0xff) | (uint)uVar1 | 1 << (error + 0x18 & 0xff);
  return RAIL_STATUS_NO_ERROR;
}



RAIL_Status_t RAIL_RfHalSetRxTransitions(RAIL_RadioState_t success,RAIL_RadioState_t error)

{
  ushort uVar1;
  
  uVar1 = (SEQ->REG000._2_2_);
  SEQ->REG000 = 1 << (error + 8 & 0xff) | 1 << success | (uint)uVar1 << 0x10;
  return RAIL_STATUS_NO_ERROR;
}



void RFHAL_SetBerConfig(RAIL_BerConfig_t *berConfig)

{
  RFTEST_ResetBerStats(berConfig->bytesToTest);
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

void RFHAL_GetBerStatus(RAIL_BerStatus_t *status)

{
  uint32_t in_r1;
  uint32_t in_r2;
  int8_t in_r3;
  RAIL_BerStatus_t local_18;
  
  local_18.bitsTotal = (uint32_t)status;
  local_18.bitsTested = in_r1;
  local_18.bitErrors = in_r2;
  local_18.rssi = in_r3;
  RFTEST_ReportBerStats(&local_18);
  status->bitsTotal = local_18.bitsTotal;
  status->bitsTested = local_18.bitsTested;
  status->bitErrors = local_18.bitErrors;
  status->rssi = local_18.rssi;
}


