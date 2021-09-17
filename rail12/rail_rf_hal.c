#include "rail_rf_hal.h"



int INT_Disable(void)

{
  disableIRQinterrupts();
  if (INT_LockCnt != -1) {
    INT_LockCnt = INT_LockCnt + 1;
  }
  return INT_LockCnt;
}



void INT_Enable(void)

{
  if ((INT_LockCnt != 0) && (INT_LockCnt = INT_LockCnt + -1, INT_LockCnt == 0)) {
    enableIRQinterrupts();
  }
  return;
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
  return;
}



void pktRxOverflow(void)

{
  RAILCb_RxRadioStatus(0x20);
  return;
}



void preambleDetected(void)

{
  RAILCb_RxRadioStatus(2);
  return;
}



void frameDet0(void)

{
  RAILCb_RxRadioStatus(4);
  return;
}



void sequencerInterrupt(int param_1)

{
  if (param_1 << 0xb < 0) {
    RAILCb_RxRadioStatus(0x40);
    return;
  }
  return;
}



void RAIL_RFSENSE_Callback(void)

{
  RAILCb_RxRadioStatus(0x80);
  return;
}



void pktTxErrorEvt(void)

{
  RAILCb_TxRadioStatus(2);
  return;
}



void racStateChange(void)

{
  uint uVar1;
  
  uVar1 = (RAC->STATUS);
  RAILCb_RadioStateChanged((uVar1 << 4) >> 0x1c);
  return;
}



void softwareTimerExpired(void)

{
  timerExpired = 1;
  GENERIC_PHY_TimerStop();
  RAILCb_TimerExpired();
  return;
}



void racCalRequest(void)

{
  RAIL_RfHalCalibrationPend(1);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void protmrLbtEvt(int param_1)

{
  uint uVar1;
  
  PROTIMER_CCTimerStop(4);
  if (param_1 << 9 < 0) {
    RADIO_PTI_AuxdataOutput(0x27);
    GENERIC_PHY_FlushTxPacketBuffer();
    uVar1 = (SEQ->REG000);
    if ((uVar1 & 0xff000000) == 0x2000000) {
      _DAT_43080004 = 1;
    }
LAB_000100fc:
    RAILCb_TxRadioStatus(4);
    return;
  }
  if (param_1 << 0xb < 0) {
    RADIO_PTI_AuxdataOutput(0x28);
    return;
  }
  if (param_1 << 0x13 < 0) {
    PROTIMER_LBTStop();
    uVar1 = (PROTIMER->IF);
    if ((uVar1 & 0x500000) == 0) {
      RADIO_PTI_AuxdataOutput(0x2a);
      GENERIC_PHY_FlushTxPacketBuffer();
      goto LAB_000100fc;
    }
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

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
  if (iVar2 != 0xffff) {
    uVar9 = iVar2 - iVar1 & 0xffff;
    uVar3 = RAILCb_AllocateMemory(uVar9 + 0xc);
    uVar7 = 0;
    while (uVar7 < uVar9) {
      local_38 = uVar9 - uVar7;
      uVar4 = RAILCb_BeginWriteMemory(uVar3,uVar7 + 10,&local_38);
      if (local_38 == 0) {
        uVar4 = local_38;
        local_38 = uVar9 - uVar7;
      }
      iVar2 = GENERIC_PHY_PacketRxDataHelper(uVar4,local_38 & 0xffff);
      uVar8 = uVar7 + iVar2;
      if (uVar4 == 0) {
        iVar2 = 0;
      }
      RAILCb_EndWriteMemory(uVar3,uVar7 + 10,iVar2);
      uVar7 = uVar8 & 0xffff;
    }
    GENERIC_PHY_PacketRxAppendedInfoHelper(iVar1,auStack52);
    local_38 = 0xc;
    puVar5 = (undefined4 *)RAILCb_BeginWriteMemory(uVar3,0,&local_38);
    if ((puVar5 == NULL) || (local_38 < 0xc)) {
      uVar6 = 0;
    }
    else {
      *(short *)(puVar5 + 2) = (short)uVar9;
      read_volatile(FRC->IEN._0_1_);
      uVar7 = (FRC->IF);
      *(byte *)(puVar5 + 1) =
           *(byte *)(puVar5 + 1) & 0xfd | (byte)((((uVar7 ^ 0x80) << 0x18) >> 0x1f) << 1);
      _DAT_43000d1c = 1;
      if (local_2e != 0) {
        local_2e = 1;
      }
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
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void pktRxFrmErr(void)

{
  _DAT_43000d1c = 1;
  RAILCb_RxRadioStatus(0x10);
  return;
}



RAIL_Status_t RAIL_RfHalInit(uint32_t *settings)

{
  uint32_t uVar1;
  RAIL_CalMask_t RVar2;
  
  uVar1 = SystemHFXOClockGet();
  if (uVar1 == settings[1]) {
    GENERIC_PHY_Init();
    _enabledCallbacks =
         _enabledCallbacks & 0xff000000 | (uint)(uint3)((uint3)_enabledCallbacks | 7) | 0x80000;
    RVar2 = RAIL_RfHalCalibrationEnableGet();
    if ((int)(RVar2 << 0x1f) < 0) {
      _enabledCallbacks = _enabledCallbacks | 0x10000;
    }
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
  return;
}



RAIL_RadioState_t RAIL_RfHalStateGet(void)

{
  bool bVar1;
  uint state;
  
  state = (RAC->STATUS);
  state = state & 0xf000000;
  if (state != 0x6000000) {
    if (0x6000000 < state) {
      if (state != 0x9000000) {
        if (state < 0x9000001) {
          if (state == 0x7000000) {
            return RAIL_RF_STATE_RX;
          }
          bVar1 = state == 0x8000000;
        }
        else {
          if (state == 0xb000000) {
            return RAIL_RF_STATE_TX;
          }
          if (state == 0xc000000) {
            return RAIL_RF_STATE_TX;
          }
          bVar1 = state == 0xa000000;
        }
        if (!bVar1) {
          return RAIL_RF_STATE_IDLE;
        }
      }
      return RAIL_RF_STATE_TX;
    }
    if (state != 0x3000000) {
      if (state < 0x3000001) {
        if (state == 0x1000000) {
          return RAIL_RF_STATE_RX;
        }
        bVar1 = state == 0x2000000;
      }
      else {
        if (state == 0x4000000) {
          return RAIL_RF_STATE_RX;
        }
        bVar1 = state == 0x5000000;
      }
      if (!bVar1) {
        return RAIL_RF_STATE_IDLE;
      }
    }
  }
  return RAIL_RF_STATE_RX;
}



bool RFHAL_HeadedToIdle(void)

{
  bool bVar1;
  uint uVar2;
  
  INT_Disable();
  bVar1 = PROTIMER_CCTimerIsEnabled('\x03');
  if ((bVar1 != false) || (bVar1 = PROTIMER_LBTIsActive(), bVar1 != false)) {
    INT_Enable();
    return false;
  }
  uVar2 = (RAC->STATUS);
  INT_Enable();
  if ((uVar2 & 0xc0000000) != 0) {
    return false;
  }
  uVar2 = uVar2 & 0xf000000;
  if (uVar2 == 0x6000000) {
    return false;
  }
  if (uVar2 < 0x6000001) {
    bVar1 = uVar2 == 0x3000000;
  }
  else {
    if (uVar2 == 0x9000000) {
      return false;
    }
    bVar1 = uVar2 == 0xc000000;
  }
  if (bVar1) {
    return false;
  }
  return true;
}



uint8_t RAIL_RfHalTxDataLoad(RAIL_TxData_t *txData)

{
  uint local_10;
  uint8_t *local_c;
  
  local_10 = (uint)txData & 0xffff0000 | (uint)txData->dataLength;
  local_c = txData->dataPtr;
  GENERIC_PHY_LoadTxPacketBuffer(&local_10);
  return '\0';
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
  
  if (params != (void *)0x0) {
    uVar2 = *(ushort *)((int)params + 6);
    uVar10 = (MODEM->CF);
    uVar8 = (MODEM->RXBR);
    bVar16 = *(byte *)((int)params + 3);
    uVar6 = (uVar8 << 0x16) >> 0x1b;
    iVar14 = (((uVar10 << 0xf) >> 0x12) * (uint)(byte)(&modemCfDec0Factors_8287)[uVar10 & 7] +
             (uint)(byte)(&modemCfDec0Factors_8287)[uVar10 & 7]) * 2000000;
    uVar7 = CMU_ClockFreqGet(cmuClock_HF);
    lVar3 = (ulonglong)uVar6 * (ulonglong)uVar2 * (ulonglong)uVar7;
    uVar8 = __aeabi_uldivmod((int)lVar3,(int)((ulonglong)lVar3 >> 0x20),
                             (uVar6 * ((uVar8 << 0x13) >> 0x1d) + (uVar8 & 0x1f)) *
                             (((uVar10 << 9) >> 0x1a) * iVar14 + iVar14),0);
    for (uVar10 = 0; (uint)(1 << (uVar10 & 0xff)) < uVar8; uVar10 = uVar10 + 1) {
      if (uVar10 == 0x10) {
        return '\x01';
      }
    }
    uVar8 = (AGC->CTRL1);
    write_volatile_4(AGC->CTRL1,uVar8 & 0xfffff000);
    uVar8 = (AGC->CTRL1);
    write_volatile_4(AGC->CTRL1,uVar8 | bVar16 | uVar10 << 8);
    bVar16 = *(byte *)((int)params + 2);
                    // WARNING: Load size is inaccurate
    bVar1 = *params;
    bVar15 = *(byte *)((int)params + 1);
    bVar17 = bVar16;
    bVar18 = bVar16;
    if ((bVar16 != 0) && (bVar16 = bVar16 - 1, bVar17 = 1, bVar18 = bVar1, bVar15 < bVar1)) {
      bVar15 = bVar1;
    }
                    // WARNING: Load size is inaccurate
    uVar10 = count_leading_zeroes((uint)*params);
    pPVar19 = (PROTIMER *)0x7da1;
    uVar9 = PROTIMER_UsToPrecntOverflow((uint)*(ushort *)((int)params + 4));
    uVar8 = uVar9 & 0xffff;
    if (uVar10 >> 5 == 0) {
      pcVar12 = (char *)(uint)(ushort)reseedRandom_8301;
      if (pcVar12 != "z,2=SubGHz,3=both) (and UART input)") {
        pPVar19 = &Peripherals::PROTIMER;
      }
      if (pcVar12 != "z,2=SubGHz,3=both) (and UART input)") {
        pPVar19->RANDOM = (uint)pcVar12;
        reseedRandom_8301._0_2_ = 0xf804;
      }
    }
    else {
      uVar13 = 0;
      uVar6 = uVar8;
      while( true ) {
        uVar11 = uVar13 & 0xff;
        uVar13 = uVar13 + 1;
        if (uVar6 < 0x100) break;
        uVar6 = uVar6 >> 1;
      }
      if ((uVar11 != 0) && (uVar6 != 0xff)) {
        uVar6 = uVar6 + ((int)uVar8 >> (uVar11 - 1 & 0xff) & 1U) & 0xffff;
      }
      uVar8 = (PROTIMER->RANDOM);
      reseedRandom_8301._0_2_ = (ushort)(char *)(uVar8 & 0xffff);
      if ((char *)(uVar8 & 0xffff) == "z,2=SubGHz,3=both) (and UART input)") {
        reseedRandom_8301._0_2_ = 0xf805;
      }
      write_volatile_4(PROTIMER->RANDOM,(1 << uVar11) - 1);
      bVar15 = 8;
      write_volatile_4(PROTIMER->LBTSTATE,0x800000);
      bVar18 = 8;
      uVar8 = uVar6;
    }
    write_volatile_4(PROTIMER->BASECNTTOP,uVar8);
    PROTIMER_LBTCfgSet(bVar18,bVar15,bVar17,bVar16,0);
    if (uVar10 >> 5 != 0) {
      _DAT_430a09d0 = 1;
      uVar8 = (PROTIMER->CTRL);
      write_volatile_4(PROTIMER->CTRL,uVar8 & 0xff3fffff | 0x400000);
    }
    lbtTimeout_8300 = *(uint32_t *)((int)params + 8);
  }
  GENERIC_PHY_PacketTxCommon();
  uVar9 = lbtTimeout_8300;
  if (lbtTimeout_8300 != 0) {
    bVar4 = PROTIMER_CCTimerIsEnabled('\x04');
    if (bVar4 != false) {
      PROTIMER_CCTimerStop('\x04');
    }
    uVar9 = PROTIMER_UsToPrecntOverflow(uVar9);
    RVar5 = PROTIMER_CCTimerStart(4,uVar9,1);
    if (RVar5 == RAIL_STATUS_NO_ERROR) {
      return '\x01';
    }
  }
  PROTIMER_LBTStart();
  return '\0';
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
    if (bVar3 != 0) {
      local_10._2_2_ = *(short *)((int)params + 4) * (ushort)bVar3 + local_10._2_2_;
      local_14._1_1_ = (char)(local_14 >> 8);
      local_14._2_2_ = (undefined2)(local_14 >> 0x10);
      local_14 = (uint)CONCAT21(local_14._2_2_,local_14._1_1_ - bVar3) << 8;
    }
    uVar2 = local_14 >> 8 & 0xff;
    for (bVar3 = 1; (uint)(1 << (uint)bVar3) < uVar2; bVar3 = bVar3 + 1) {
    }
    local_10 = uVar2 * *(ushort *)((int)params + 4) + ((uint)(1 << (uint)bVar3) >> 1) >> (uint)bVar3
               & 0xffff | (uint)local_10._2_2_ << 0x10;
    local_14._0_2_ = CONCAT11(bVar3,bVar3);
    local_14 = local_14 & 0xffff0000 | (uint)(ushort)local_14;
    params = &local_14;
  }
  uVar1 = RAIL_CcaCsma(params);
  return uVar1;
}



uint8_t RAIL_ScheduleTx(void *params)

{
  uint32_t uVar1;
  char cVar2;
  
  cVar2 = *(char *)((int)params + 4);
                    // WARNING: Load size is inaccurate
  if (cVar2 != '\0') {
    cVar2 = '\x01';
  }
  uVar1 = PROTIMER_UsToPrecntOverflow(*params);
  GENERIC_PHY_SchedulePacketTx(uVar1,cVar2);
  return '\0';
}




uint8_t RAIL_RfHalTxStart(uint8_t channel,RAIL_PreTxOp_t *pretxop,void *params)

{
  uint uVar1;
  bool bVar2;
  uint8_t uVar3;
  uint32_t uVar4;
  
  uVar4 = RAIL_DebugModeGet();
  if (uVar4 != 1) {
    do {
      bVar2 = RFHAL_HeadedToIdle();
      if (bVar2 == false) break;
      uVar1 = (RAC->STATUS);
    } while ((uVar1 & 0xf000000) != 0);
    uVar1 = (RAC->STATUS);
    if ((uVar1 & 0xf000000) != 0) {
      return '\x02';
    }
    GENERIC_PHY_ChannelSet(channel);
  }
  if (pretxop != FUN_00000000) {
                    // WARNING: Could not recover jumptable at 0x00007f68. Too many branches
                    // WARNING: Treating indirect jump as call
    uVar3 = (*pretxop)(params);
    return (uint8_t)uVar3;
  }
  GENERIC_PHY_PacketTx();
  return '\0';
}




RAIL_Status_t RAIL_RfHalRxStart(uint8_t channel)

{
  uint uVar1;
  bool bVar2;
  uint32_t uVar3;
  
  uVar1 = (RAC->RXENSRCEN);
  if ((uVar1 & 0xff) == 0) {
    RADIO_RxBufferReset();
  }
  uVar3 = RAIL_DebugModeGet();
  if (uVar3 != 1) {
    do {
      bVar2 = RFHAL_HeadedToIdle();
      if (bVar2 == false) break;
      uVar1 = (RAC->STATUS);
    } while ((uVar1 & 0xf000000) != 0);
    uVar1 = (RAC->STATUS);
    if ((uVar1 & 0xf000000) != 0) {
      return RAIL_STATUS_INVALID_STATE;
    }
    GENERIC_PHY_ChannelSet(channel);
  }
  GENERIC_PHY_StartRx(0);
  return RAIL_STATUS_NO_ERROR;
}



undefined4 RAIL_RfHalRxIntEnable(int param_1)

{
  _enabledCallbacks =
       CONCAT12((byte)(_enabledCallbacks >> 0x10) & 0xfd |
                (byte)(((uint)(param_1 << 0x19) >> 0x1f) << 1),
                CONCAT11(DAT_20002c31 & 0xf8 | (byte)((uint)(param_1 << 0x1e) >> 0x1f) |
                         (byte)(((uint)(param_1 << 0x1d) >> 0x1f) << 1) |
                         (byte)(((uint)(param_1 << 0x1c) >> 0x1f) << 2),
                         enabledCallbacks & 0xe7 | (byte)(((uint)(param_1 << 0x1b) >> 0x1f) << 3) |
                         (byte)(((uint)(param_1 << 0x1a) >> 0x1f) << 4)));
  _enabledCallbacks = _enabledCallbacks & 0xff000000 | (uint)_enabledCallbacks;
  GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
  return 0;
}



RAIL_Status_t RAIL_RfHalErrorConfig(bool errorconfig)

{
  _DAT_43000884 = errorconfig & 1;
  return RAIL_STATUS_NO_ERROR;
}


RAIL_Status_t RAIL_RfHalSetChannelConfig(RAIL_ChannelConfigEntry_t *config)

{
  uint32_t uVar1;
  
  uVar1 = RAIL_DebugModeGet();
  if (uVar1 != 1) {
    SYNTH_Config(config->baseFrequency,config->channelSpacing);
  }
  return RAIL_STATUS_NO_ERROR;
}



RAIL_Status_t RAIL_PaCtuneSet(uint8_t txPaCtuneValue,uint8_t rxPaCtuneValue)

{
  PA_CTuneSet(txPaCtuneValue,rxPaCtuneValue);
  return RAIL_STATUS_NO_ERROR;
}



RAIL_Status_t RAIL_TimerSet(uint32_t time,RAIL_TimeMode_t mode)

{
  RAIL_Status_t RVar1;
  uint32_t time_00;
  uint32_t mode_00;
  
  mode_00 = (uint32_t)mode;
  INT_Disable();
  _enabledCallbacks = _enabledCallbacks | 0x100000;
  GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
  timerExpired = 0;
  time_00 = PROTIMER_UsToPrecntOverflow(time);
  if (mode_00 != 0) {
    mode_00 = 1;
  }
  RVar1 = GENERIC_PHY_TimerStart(time_00,mode_00);
  INT_Enable();
  return RVar1 ^ RAIL_STATUS_INVALID_PARAMETER;
}



uint32_t RAIL_TimerGet(void)

{
  uint32_t uVar1;
  
  uVar1 = GENERIC_PHY_TimerGetTimeout();
  uVar1 = PROTIMER_PrecntOverflowToUs(uVar1);
  return uVar1;
}



void RAIL_TimerCancel(void)

{
  GENERIC_PHY_TimerStop();
  _enabledCallbacks = _enabledCallbacks & 0xffefffff;
  GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
  return;
}

bool RAIL_TimerExpired(void)

{
  bool bVar1;
  byte bVar2;
  
  bVar1 = GENERIC_PHY_TimerExpired();
  bVar2 = timerExpired;
  if (bVar1 != false) {
    bVar2 = 1;
  }
  return (bool)(bVar2 & 1);
}



bool RAIL_TimerIsRunning(void)

{
  bool bVar1;
  
  bVar1 = PROTIMER_CCTimerIsEnabled('\x02');
  return bVar1;
}



uint32_t RAIL_SymbolRateGet(void)

{
  uint uVar1;
  uint32_t uVar2;
  
  uVar2 = RADIO_ComputeTxBaudrate();
  uVar1 = (MODEM->CTRL0);
  if ((uVar1 & 0x30) == 0x20) {
    uVar2 = uVar2 / (((uVar1 << 0x10) >> 0x1b) + 1);
  }
  return uVar2;
}



uint32_t RAIL_BitRateGet(void)

{
  uint uVar1;
  uint32_t uVar2;
  uint uVar3;
  
  uVar1 = (MODEM->CTRL0);
  if ((uVar1 & 0x30) == 0x20) {
    uVar3 = ((uVar1 << 0x10) >> 0x1b) / ((uVar1 << 0xd) >> 0x1d);
    if ((uVar1 & 0x180000) != 0) {
      uVar3 = uVar3 << 1;
    }
    uVar3 = uVar3 >> 1;
    if (2 < uVar3) {
      uVar3 = 4;
    }
  }
  else {
    uVar1 = (MODEM->CTRL0);
    if (((uVar1 & 0x1c0) == 0x40) || ((uVar1 & 0x1c0) == 0x100)) {
      uVar3 = 2;
    }
    else {
      uVar3 = 1;
    }
  }
  uVar2 = RADIO_ComputeTxSymbolRate();
  return uVar3 * uVar2;
}



// WARNING: Could not reconcile some variable overlaps

uint32_t RAIL_RfSense(RAIL_RfSenseBand_t band,uint32_t senseTime,bool enableCb)

{
  uint32_t uVar1;
  uint in_r3;
  undefined4 local_14;
  uint32_t local_10;
  uint local_c;
  
  local_14 = 0x79e7;
  if (enableCb == false) {
    local_14 = 0;
  }
  local_c._0_2_ = CONCAT11(1,band);
  local_c = in_r3 & 0xffff0000 | (uint)(ushort)local_c;
  local_10 = senseTime;
  uVar1 = RFSENSE_Init(&local_14,senseTime);
  return uVar1;
}




bool RAIL_RfSensed(void)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = _DAT_43c81904;
  _DAT_43c81904 = 1;
  uVar3 = (RFSENSE->IF);
  if (uVar3 != 0) {
    uVar3 = 1;
  }
  if (uVar3 != 0) {
    INT_Disable();
    pcVar1 = RFSENSE_Cb;
    RFSENSE_Cb = FUN_00000000;
    INT_Enable();
    RFSENSE_Disable();
    if (pcVar1 != FUN_00000000) {
      (*pcVar1)();
    }
  }
  if (iVar2 == 0) {
    _DAT_43c81904 = iVar2;
  }
  return SUB41(uVar3,0);
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void RAIL_DebugCbConfig(int param_1)

{
  _enabledCallbacks =
       CONCAT11(DAT_000108e1 & 0xef | (byte)(((uint)(param_1 << 0x1e) >> 0x1f) << 4),
                enabledCallbacks);
  _enabledCallbacks = _enabledCallbacks & 0xffff0000 | (uint)_enabledCallbacks;
  GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
  return;
}



void RAIL_RfHalCalibrationRun(int *calvalues,bool calforce)

{
  int32_t iVar1;
  int iVar2;
  int extraout_r1;
  
  iVar2 = (uint)calforce << 0x1f;
  if (iVar2 < 0) {
    TEMPCAL_Perform();
    iVar2 = extraout_r1;
  }
  if (false) {
    if (*calvalues == -1) {
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
  write_volatile_4(SEQ->REG000,
                   1 << (success + 0x10 & 0xff) | (uint)uVar1 | 1 << (error + 0x18 & 0xff));
  return RAIL_STATUS_NO_ERROR;
}



RAIL_Status_t RAIL_RfHalSetRxTransitions(RAIL_RadioState_t success,RAIL_RadioState_t error)

{
  ushort uVar1;
  
  uVar1 = (SEQ->REG000._2_2_);
  write_volatile_4(SEQ->REG000,
                   1 << (error + 8 & 0xff) | 1 << success | (uint)uVar1 << 0x10);
  return RAIL_STATUS_NO_ERROR;
}



void RFHAL_SetBerConfig(RAIL_BerConfig_t *berConfig)

{
  RFTEST_ResetBerStats(berConfig->bytesToTest);
  return;
}



void RFHAL_StartBerRx(void)

{
  uint uVar1;
  
  RFTEST_SaveRadioConfiguration();
  write_volatile_4(FRC->DFLCTRL,5);
  uVar1 = (MODEM->TIMING);
  write_volatile_4(MODEM->TIMING,uVar1 & 0xfffff0ff);
  RADIO_RXBufferEnableThrInt();
  RFTEST_StartRx();
  return;
}



void RFHAL_StopBerRx(void)

{
  RFTEST_BerStop();
  RADIO_RXBufferDisableThrInt();
  RFTEST_RestoreRadioConfiguration();
  return;
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
  return;
}


