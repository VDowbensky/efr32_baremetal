#include "rail_rf_hal.h"



void pktTxDoneEvt(undefined4 param_1,RAIL_TxPacketInfo_t param_2,undefined4 param_3)

{
  RAIL_TxPacketInfo_t local_c;
  undefined4 uStack8;
  
  local_c = (uint32_t)param_2;
  uStack8 = param_3;
  GENERIC_PHY_PreviousTxTime();
  local_c = TIMING_GetTxTimestampUs();
  RAILCb_TxPacketSent(&local_c);
  return;
}



void pktRxFrmErr(void)

{
  write_volatile_4(FRC->IFC,0x80);
  RAILCb_RxRadioStatusExt(0x10);
  return;
}



void pktRxOverflow(void)

{
  RAILCb_RxRadioStatusExt(0x20);
  return;
}



void filterPass(void)

{
  RAILCb_RxRadioStatusExt(0x800);
  return;
}



void pktRxAborted(void)

{
  uint uVar1;
  uint32_t status;
  
  uVar1 = (RAC->SR0);
  BUS_RegMaskedClear(&RAC->SR0,0x1000000);
  if ((int)(uVar1 << 7) < 0) {
    status = 0x40;
  }
  else {
    status = 0x400;
  }
  RAILCb_RxRadioStatusExt(status);
  return;
}



void preambleDetected(void)

{
  RAILCb_RxRadioStatusExt(2);
  return;
}




void frameDet0(void)

{
  RAILCb_RxRadioStatusExt(4);
  return;
}



void frameDet1(void)

{
  RAILCb_RxRadioStatusExt(8);
  return;
}



void rxFifoUnderflow(void)

{
  RAILCb_RxRadioStatusExt(1);
  return;
}




void RAIL_RFSENSE_Callback(void)

{
  RAILCb_RxRadioStatusExt(0x80);
  return;
}



void protmrRetry(void)

{
  RAILCb_TxRadioStatus('@');
  return;
}



void protmrStartCca(void)

{
  RAILCb_TxRadioStatus(0x80);
  return;
}


void txFifoOverflow(void)

{
  RAILCb_TxRadioStatus(1);
  return;
}



void racStateChange(void)

{
  uint uVar1;
  
  uVar1 = (RAC->STATUS);
  RAILCb_RadioStateChanged((byte)((uVar1 << 4) >> 0x1c));
  return;
}



void softwareTimerExpired(void)

{
  timerExpired = 1;
  GENERIC_PHY_TimerStop();
  RAILCb_TimerExpired();
  return;
}



void rxFifoAlmostFull(void)

{
  uint16_t bytesAvailable;
  
  bytesAvailable = BUFC_GetBytesAvailable(1);
  RAILCb_RxFifoAlmostFull(bytesAvailable);
  return;
}



void txFifoAlmostEmpty(void)

{
  uint16_t spaceAvailable;
  
  spaceAvailable = BUFC_GetSpaceAvailable(0);
  RAILCb_TxFifoAlmostEmpty(spaceAvailable);
  return;
}



void racCalRequest(void)

{
  RAILINT_CalibrationPend(1);
  return;
}


void pktRxDoneEvt(void)

{
  byte bVar1;
  uint16_t uVar2;
  uint32_t uVar3;
  void *handle;
  void *pvVar4;
  undefined4 *puVar5;
  uint size;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint64_t uVar9;
  ushort local_3c;
  byte local_3a;
  undefined local_39;
  void *local_38;
  undefined auStack52 [5];
  undefined local_2f;
  byte local_2e;
  uint32_t local_28;
  
  BUFC_RxLengthReadNext(&local_3c);
  uVar6 = -((int)((uint)(byte)bufcEnabledCallbacks << 0x1d) >> 0x1f);
  if (uVar6 == 0) {
    uVar3 = RADIO_RxTrailDataLength();
    if (local_3c != 0xffff) {
      uVar8 = local_3c - uVar3 & 0xffff;
      handle = RAILCb_AllocateMemory(uVar8 + 0xc);
      while (uVar6 < uVar8) {
        local_38 = (void *)(uVar8 - uVar6);
        pvVar4 = RAILCb_BeginWriteMemory(handle,uVar6 + 10,(uint32_t *)&local_38);
        if (local_38 == (void *)0x0) {
          pvVar4 = local_38;
          local_38 = (void *)(uVar8 - uVar6);
        }
        uVar2 = GENERIC_PHY_PacketRxDataHelper((int)pvVar4,(uint)local_38 & 0xffff);
        size = (uint)uVar2;
        uVar7 = uVar6 + size;
        if (pvVar4 == (void *)0x0) {
          size = 0;
        }
        RAILCb_EndWriteMemory(handle,uVar6 + 10,size);
        uVar6 = uVar7 & 0xffff;
      }
      GENERIC_PHY_PacketRxAppendedInfoHelper(uVar3,auStack52);
      local_38 = (void *)0xc;
      puVar5 = (undefined4 *)RAILCb_BeginWriteMemory(handle,0,(uint32_t *)&local_38);
      if ((puVar5 == (undefined4 *)0x0) || (local_38 < (void *)0xc)) {
        uVar3 = 0;
      }
      else {
        read_volatile(FRC->IEN._0_1_);
        uVar6 = (FRC->IF);
        *(short *)(puVar5 + 2) = (short)uVar8;
        *(byte *)(puVar5 + 1) =
             *(byte *)(puVar5 + 1) & 0xfd | (byte)((((uVar6 ^ 0x80) << 0x18) >> 0x1f) << 1);
        write_volatile_4(FRC->IFC,0x80);
        bVar1 = *(byte *)(puVar5 + 1);
        if (local_2e != 0) {
          local_2e = 1;
        }
        *(byte *)(puVar5 + 1) = bVar1 & 0xfe | local_2e & 1;
        *(undefined *)((int)puVar5 + 5) = local_2f;
        *(undefined *)((int)puVar5 + 6) = local_39;
        *(byte *)(puVar5 + 1) =
             bVar1 & 0xfa | local_2e & 1 | (byte)((((uint)local_3a << 0x1c) >> 0x1f) << 2);
        uVar9 = TIMING_GetRxTimestampUs(local_28);
        *puVar5 = (int)uVar9;
        *(undefined *)((int)puVar5 + 7) = 0;
        uVar3 = 0xc;
      }
      RAILCb_EndWriteMemory(handle,0,uVar3);
      RAILCb_RxPacketReceived(handle);
      RAILCb_FreeMemory(handle);
    }
  }
  else {
    RAILCb_RxPacketReceived((void *)0x0);
  }
  return;
}



void rxTimeout(int param_1)

{
  uint32_t status;
  
  if (param_1 == 1) {
    if (-1 < rxConfigEvents << 0x16) {
      return;
    }
    status = 0x200;
  }
  else {
    if ((param_1 != 2) || (-1 < rxConfigEvents << 0x17)) {
      return;
    }
    status = 0x100;
  }
  RAILCb_RxRadioStatusExt(status);
  return;
}



void sequencerInterrupt(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined local_1c [2];
  undefined2 local_1a;
  
  if (param_1 << 10 < 0) {
    RAILCb_RxAckTimeout();
  }
  if ((param_1 << 0xc < 0) && (iVar4 = GENERIC_PHY_CanModifyAck(), iVar4 != 0)) {
    uVar2 = (BUFC->BUF1_ADDR);
    uVar1 = (BUFC->BUF1_CTRL);
    uVar3 = (RAC->SR1);
    uVar7 = (uVar3 << 0x18) >> 0x1e;
    uVar8 = (0x40 << (uVar1 & 0xff)) - 1U & 0xffff;
    uVar1 = (SEQ->REG004);
    local_1c[0] = (byte)uVar3 >> 6;
    iVar4 = uVar2 + 0x20000000;
    if (uVar7 == 3) {
      iVar5 = 0;
      do {
        iVar6 = iVar5 + 1;
        *(undefined *)((int)&local_1a + iVar5) =
             *(undefined *)(iVar4 + (((uVar1 & 0xffff) - 8) + iVar5 & uVar8));
        iVar5 = iVar6;
      } while (iVar6 != 8);
    }
    else {
      if (uVar7 != 2) {
        return;
      }
      local_1a = CONCAT11(*(undefined *)(iVar4 + ((uVar1 & 0xffff) - 1 & uVar8)),
                          *(undefined *)(iVar4 + ((uVar1 & 0xffff) - 2 & uVar8)));
    }
    RAILCb_IEEE802154_DataRequestCommand((RAIL_IEEE802154_Address_t *)local_1c);
  }
  return;
}



void rssiAverageDone(void)

{
  MODEM_SET *pMVar1;
  
  _enabledCallbacks = _enabledCallbacks & 0xfbffffff;
  GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
  currentRssiAverage = RADIO_GetRSSI();
  RAIL_RfIdle();
  if (saveFrameDetDisable == '\0') {
    pMVar1 = (MODEM_SET *)&Peripherals::MODEM_CLR;
  }
  else {
    pMVar1 = &Peripherals::MODEM_SET;
  }
  ((MODEM_CLR *)pMVar1)->CTRL0 = 0x200000;
  RAILCb_RssiAverageDone(currentRssiAverage);
  BUS_RegMaskedClear(&AGC->CTRL1,0xffffff00);
  BUS_RegMaskedSet(&AGC->CTRL1,saveRssiPeriod & 0xffffff00);
  isRssiReady = 1;
  return;
}



uint userTransmitStarted(void)

{
  uint uVar1;
  
  uVar1 = (RAC->SR0);
  uVar1 = uVar1 & 0x80;
  if (uVar1 != 0) {
    uVar1 = (PROTIMER->STATUS);
    if (-1 < (int)(uVar1 << 0x1d)) {
      uVar1 = (PROTIMER->CC3_CTRL);
      return uVar1 & 1 ^ 1;
    }
    uVar1 = 0;
  }
  return uVar1;
}



void pktTxErrorEvt(uint param_1)

{
  int iVar1;
  
  if (((param_1 & 0x1c) != 0) && (iVar1 = userTransmitStarted(), iVar1 != 0)) {
    BUS_RegMaskedClear(&RAC->SR0,0x80);
    BUS_RegMaskedClear(&RAC->RXENSRCEN,0x10);
  }
  if ((txConfigEvents & param_1) != 0) {
    RAILCb_TxRadioStatus((uint8_t)(txConfigEvents & param_1));
    return;
  }
  return;
}



void protmrLbtEvt(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  PROTIMER_CCTimerStop(4);
  if (param_1 << 9 < 0) {
    RADIO_PTI_AuxdataOutput(0x27);
    write_volatile_4(BUFC->BUF0_CMD,1);
    uVar1 = (SEQ->REG00C);
    if ((uVar1 & 0xff000000) == 0x2000000) {
      BUS_RegMaskedSet(&RAC->RXENSRCEN,2);
    }
LAB_0000eb78:
    uVar2 = 4;
  }
  else {
    if (-1 < param_1 << 0xb) {
      if (-1 < param_1 << 0x13) goto LAB_0000eb7e;
      PROTIMER_LBTStop();
      uVar1 = (PROTIMER->IF);
      if ((uVar1 & 0x500000) != 0) goto LAB_0000eb7e;
      RADIO_PTI_AuxdataOutput(0x2a);
      write_volatile_4(BUFC->BUF0_CMD,1);
      goto LAB_0000eb78;
    }
    RADIO_PTI_AuxdataOutput(0x28);
    uVar2 = 0x20;
  }
  pktTxErrorEvt(uVar2);
LAB_0000eb7e:
  BUS_RegMaskedClear(&AGC->CTRL1,0xffffff00);
  BUS_RegMaskedSet(&AGC->CTRL1,saveRssiPeriodPreCca & 0xffffff00);
  return;
}



uint8_t RFHAL_Init(RAIL_Init_t *railinit)

{
  uint32_t uVar1;
  RAIL_CalMask_t RVar2;
  
  uVar1 = SystemHFXOClockGet();
  if (uVar1 == railinit->rfXtalFreq) {
    GENERIC_PHY_Init();
    write_volatile_4(FRC->TRAILRXDATA,0x1b);
    write_volatile_4(FRC->RXCTRL,0x60);
    _enabledCallbacks =
         _enabledCallbacks & 0xff000000 | (uint)(uint3)((uint3)_enabledCallbacks | 7) | 0x400000;
    RVar2 = RAILINT_CalibrationEnableGet();
    if ((int)(RVar2 << 0x1f) < 0) {
      _enabledCallbacks = _enabledCallbacks | 0x80000;
    }
    _enabledCallbacks = _enabledCallbacks | 0x100000;
    GENERIC_PHY_SetCallbacks((uint32_t *)&callbacks);
    GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
    BUFC_SetCallbacks((uint32_t *)&bufcCallbacks);
    bufcEnabledCallbacks = 0;
    BUFC_ConfigureCallbacks(0);
    RAILCb_RfReady();
    return '\0';
  }
  return '\x01';
}



RAIL_Status_t RFHAL_SetPtiProtocol(RAIL_PtiProtocol_t protocol1)

{
  uint uVar1;
  uint in_r3;
  int unaff_r4;
  bool bVar2;
  
  bVar2 = (protocol1 & 0xf0) == 0;
  if (bVar2) {
    unaff_r4 = 0x21000f64;
    uVar1 = (SEQ->REG06C);
    in_r3 = uVar1 & 0xfffffff0 | protocol1 & 0xf;
    protocol1 = protocol1 & 0xf0;
  }
  if (bVar2) {
    *(uint *)(unaff_r4 + 8) = in_r3;
  }
  else {
    protocol1 = RAIL_STATUS_INVALID_PARAMETER;
  }
  return (RAIL_Status_t)protocol1;
}




void RFHAL_IdleExt(RAIL_RfIdleMode_t mode)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  switch(mode) {
  case 0:
    uVar2 = 0;
    uVar1 = uVar2;
    uVar3 = uVar2;
    goto LAB_0000ec7c;
  case 1:
    uVar1 = 0;
    break;
  case 2:
    uVar1 = 1;
    break;
  case 3:
    uVar2 = 1;
    uVar1 = uVar2;
    uVar3 = uVar2;
    goto LAB_0000ec7c;
  default:
    return;
  }
  uVar2 = 1;
  uVar3 = 0;
LAB_0000ec7c:
  GENERIC_PHY_RadioIdle(uVar2,uVar1,uVar3);
  return;
}



RAIL_RadioState_t RFHAL_StateGet(void)

{
  uint uVar1;
  bool bVar2;
  
  uVar1 = (RAC->STATUS);
  uVar1 = uVar1 & 0xf000000;
  if (uVar1 != 0x7000000) {
    if (0x7000000 < uVar1) {
      if (uVar1 != 0xa000000) {
        if (uVar1 < 0xa000001) {
          if (uVar1 == 0x8000000) {
            return RAIL_RF_STATE_TX;
          }
          bVar2 = uVar1 == 0x9000000;
        }
        else {
          if (uVar1 == 0xb000000) {
            return RAIL_RF_STATE_TX;
          }
          bVar2 = uVar1 == 0xc000000;
        }
        if (!bVar2) {
          return RAIL_RF_STATE_IDLE;
        }
      }
      return RAIL_RF_STATE_TX;
    }
    if (uVar1 != 0x3000000) {
      if (uVar1 < 0x3000001) {
        if (uVar1 == 0x1000000) {
          return RAIL_RF_STATE_RX;
        }
        bVar2 = uVar1 == 0x2000000;
      }
      else {
        if (uVar1 == 0x4000000) {
          return RAIL_RF_STATE_RX;
        }
        bVar2 = uVar1 == 0x5000000;
      }
      if (!bVar2) {
        return RAIL_RF_STATE_IDLE;
      }
    }
  }
  return RAIL_RF_STATE_RX;
}



bool RFHAL_OkToTransmit(void)

{
  uint uVar1;
  
  uVar1 = (RAC->SR0);
  return (bool)((byte)((byte)uVar1 ^ 0x80) >> 7);
}


bool RFHAL_HeadedToIdle(void)

{
  uint uVar1;
  CORE_irqState_t irqState;
  int iVar2;
  uint uVar3;
  bool bVar4;
  
  irqState = CORE_EnterCritical();
  iVar2 = PROTIMER_CCTimerIsEnabled(3);
  if ((iVar2 == 0) && (iVar2 = PROTIMER_LBTIsActive(), iVar2 == 0)) {
    uVar3 = read_volatile_4(Peripherals::RAC.STATUS);
    uVar1 = read_volatile_4(Peripherals::RAC.SR0);
    CORE_ExitCritical(irqState);
    if (((uVar3 & 0xc0000000) == 0) &&
       ((-1 < (int)(uVar1 << 0x18) && (uVar3 = uVar3 & 0xf000000, uVar3 != 0x6000000)))) {
      if (uVar3 < 0x6000001) {
        bVar4 = uVar3 == 0x3000000;
      }
      else {
        if (uVar3 == 0x9000000) goto LAB_0000ed58;
        bVar4 = uVar3 == 0xc000000;
      }
      if (!bVar4) {
        iVar2 = 1;
      }
    }
  }
  else {
    CORE_ExitCritical(irqState);
    iVar2 = 0;
  }
LAB_0000ed58:
  return SUB41(iVar2,0);
}



uint8_t RFHAL_TxDataLoad(RAIL_TxData_t *txData)

{
  CORE_irqState_t irqState;
  uint uVar1;
  uint8_t uVar2;
  
  irqState = CORE_EnterCritical();
  uVar1 = (RAC->STATUS);
  uVar1 = (uVar1 << 4) >> 0x1c;
  if (((uVar1 - 7 < 3) || (uVar1 == 0xc)) &&
     (uVar1 = (RAC->SR0), (int)(uVar1 << 0xf) < 0)) {
    uVar2 = '\x03';
  }
  else {
    write_volatile_4(BUFC->BUF0_CMD,1);
    BUFC_WriteBuffer(0,txData->dataPtr,txData->dataLength);
    uVar2 = '\0';
  }
  CORE_ExitCritical(irqState);
  return uVar2;
}



uint8_t RAIL_CcaCsma(void *params)

{
  byte bVar1;
  uint32_t us;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  byte bVar6;
  uint uVar7;
  byte bVar8;
  byte bVar9;
  byte bVar10;
  PROTIMER *pPVar11;
  uint uVar12;
  uint64_t uVar13;
  
  saveRssiPeriodPreCca = (AGC->CTRL1);
  if (params == (void *)0x0) {
    BUS_RegMaskedClear(&AGC->CTRL1,0xffffff00);
    BUS_RegMaskedSet(&AGC->CTRL1,saveRssiPeriodInCca & 0xffffff00);
    PROTIMER_LBTUseLastConfig();
  }
  else {
    RADIO_SetAgcCcaParams
              (*(undefined2 *)((int)params + 6),(int)*(char *)((int)params + 3),saveRssiPeriodPreCca
               ,&saveRssiPeriodPreCca,params);
    saveRssiPeriodInCca = (AGC->CTRL1);
    bVar10 = *(byte *)((int)params + 2);
                    // WARNING: Load size is inaccurate
    bVar1 = *params;
    bVar9 = *(byte *)((int)params + 1);
    bVar8 = bVar10;
    bVar6 = bVar10;
    if (bVar10 != 0) {
      bVar6 = bVar10 - 1;
      bVar10 = bVar1;
      if (bVar9 < bVar1) {
        bVar9 = bVar1;
        bVar8 = 1;
      }
      else {
        bVar8 = 1;
      }
    }
                    // WARNING: Load size is inaccurate
    uVar7 = count_leading_zeroes((uint)*params);
    pPVar11 = (PROTIMER *)0xedff;
    uVar13 = PROTIMER_UsToPrecntOverflow((uint)*(ushort *)((int)params + 4));
    uVar3 = (uint)(ushort)uVar13;
    if (uVar7 >> 5 == 0) {
      uVar4 = (uint)reseedRandom_8945;
      if (uVar4 != 0xf804) {
        pPVar11 = &Peripherals::PROTIMER;
      }
      if (uVar4 != 0xf804) {
        pPVar11->RANDOM = uVar4;
        reseedRandom_8945 = 0xf804;
      }
    }
    else {
      uVar5 = 0;
      uVar4 = uVar3;
      while( true ) {
        uVar12 = uVar5 & 0xff;
        uVar5 = uVar5 + 1;
        if (uVar4 < 0x100) break;
        uVar4 = uVar4 >> 1;
      }
      if ((uVar12 != 0) && (uVar4 != 0xff)) {
        uVar4 = (uint)(ushort)(((ushort)((int)uVar3 >> (uVar12 - 1 & 0xff)) & 1) + (short)uVar4);
      }
      uVar3 = uVar4;
      uVar4 = (PROTIMER->RANDOM);
      reseedRandom_8945 = (ushort)(uVar4 & 0xffff);
      if ((uVar4 & 0xffff) == 0xf804) {
        reseedRandom_8945 = 0xf805;
      }
      write_volatile_4(PROTIMER->RANDOM,(1 << uVar12) - 1);
      bVar9 = 8;
      write_volatile_4(PROTIMER->LBTSTATE,0x800000);
      bVar10 = 8;
    }
    if (uVar3 < 0x100) {
      uVar3 = uVar3 - 1;
    }
    else {
      uVar3 = 0xff;
    }
    write_volatile_4(PROTIMER->BASECNTTOP,uVar3);
    PROTIMER_LBTCfgSet(bVar10,bVar9,bVar8,bVar6,0);
    if (uVar7 >> 5 != 0) {
      BUS_RegMaskedSet(&PROTIMER->LBTCTRL,0x100000);
      uVar3 = (PROTIMER->CTRL);
      write_volatile_4(PROTIMER->CTRL,uVar3 & 0xff3fffff | 0x400000);
    }
    lbtTimeout_8944 = *(uint32_t *)((int)params + 8);
  }
  GENERIC_PHY_PacketTxCommon();
  us = lbtTimeout_8944;
  if (lbtTimeout_8944 != 0) {
    bVar2 = PROTIMER_CCTimerIsEnabled(4);
    if (bVar2 != false) {
      PROTIMER_CCTimerStop(4);
    }
    uVar13 = PROTIMER_UsToPrecntOverflow(us);
    bVar2 = PROTIMER_CCTimerStart(4,(uint32_t)uVar13,RAIL_TIME_DELAY);
    if (bVar2 == false) {
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



void RFHAL_SetCcaThreshold(void)

{
  RADIO_AGCCCAThresholdSet();
  return;
}



int16_t RFHAL_PollAverageRSSI(uint32_t averageTimeUs)

{
  int16_t iVar1;
  uint32_t begin;
  uint32_t uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  bool bVar7;
  uint64_t uVar8;
  
  if (averageTimeUs == 0) {
    iVar1 = RADIO_GetRSSI();
    return iVar1;
  }
  begin = PROTIMER_GetTime();
  uVar8 = PROTIMER_UsToPrecntOverflow(averageTimeUs);
  iVar4 = 0;
  uVar5 = 0;
  iVar6 = 0;
  while( true ) {
    uVar2 = PROTIMER_GetTime();
    uVar2 = PROTIMER_ElapsedTime(begin,uVar2);
    if ((uint)uVar8 <= uVar2) break;
    iVar1 = RADIO_GetRSSI();
    if (iVar1 != -0x200) {
      uVar3 = SEXT24(iVar1);
      bVar7 = CARRY4(uVar5,uVar3);
      uVar5 = uVar5 + uVar3;
      iVar6 = iVar6 + ((int)uVar3 >> 0x1f) + (uint)bVar7;
      iVar4 = iVar4 + 1;
    }
  }
  if (iVar4 == 0) {
    iVar1 = -0x200;
  }
  else {
    iVar1 = __aeabi_ldivmod(uVar5,iVar6,iVar4,iVar4 >> 0x1f);
  }
  return iVar1;
}



RAIL_Status_t RFHAL_StartAverageRSSI(uint8_t channel,uint32_t averagingTimeUs)

{
  RAIL_Status_t RVar1;
  uint8_t uVar2;
  int iVar3;
  
  isRssiReady = 0;
  saveRssiPeriod = (AGC->CTRL1);
  RVar1 = RADIO_CalcRssiPeriod(averagingTimeUs);
  if (RVar1 == RAIL_STATUS_NO_ERROR) {
    iVar3 = _DAT_430c0354;
    if (_DAT_430c0354 != 0) {
      iVar3 = 1;
    }
    saveFrameDetDisable = (undefined)iVar3;
    BUS_RegMaskedSet(&MODEM->CTRL0,0x200000);
    uVar2 = RAIL_RxStart(channel);
    if (uVar2 == '\0') {
      _enabledCallbacks = _enabledCallbacks | 0x4000000;
      GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
    }
    else {
      RVar1 = RAIL_STATUS_INVALID_STATE;
    }
  }
  else {
    RVar1 = RAIL_STATUS_INVALID_PARAMETER;
  }
  return RVar1;
}



int16_t RFHAL_GetAverageRSSI(void)

{
  return currentRssiAverage;
}




bool RFHAL_AverageRSSIReady(void)

{
  return isRssiReady;
}



void RFHAL_ScheduleRx(uint8_t channel,RAIL_ScheduleRxConfig_t *config)

{
  uint uVar1;
  uint32_t us;
  uint8_t uVar2;
  undefined4 uVar3;
  RAIL_TimeMode_t RVar4;
  RAIL_TimeMode_t RVar5;
  undefined4 uVar6;
  uint64_t uVar7;
  
  uVar1 = TIMING_RxWarmTimeGet();
  RVar5 = config->startMode;
  if (RVar5 == RAIL_TIME_DELAY) {
    if (uVar1 <= config->start) goto LAB_0000f09a;
    us = 0;
  }
  else {
    if (RVar5 == RAIL_TIME_DISABLED) {
      uVar6 = 0;
      goto LAB_0000f0b4;
    }
LAB_0000f09a:
    us = config->start - uVar1;
  }
  uVar7 = PROTIMER_UsToPrecntOverflow(us);
  uVar6 = (undefined4)uVar7;
  RVar5 = config->startMode;
  if (RVar5 != RAIL_TIME_ABSOLUTE) {
    RVar5 = RAIL_TIME_DELAY;
  }
LAB_0000f0b4:
  RVar4 = config->endMode;
  if (RVar4 == RAIL_TIME_DISABLED) {
    uVar3 = 0;
  }
  else {
    uVar7 = PROTIMER_UsToPrecntOverflow(config->end);
    uVar3 = (undefined4)uVar7;
    RVar4 = config->endMode;
    if (RVar4 != RAIL_TIME_ABSOLUTE) {
      RVar4 = RAIL_TIME_DELAY;
    }
  }
  uVar1 = count_leading_zeroes((uint)config->rxTransitionEndSchedule);
  uVar2 = config->hardWindowEnd;
  if (uVar2 != '\0') {
    uVar2 = '\x01';
  }
  GENERIC_PHY_SchedulePacketRx(uVar6,RVar5,uVar3,RVar4,uVar1 >> 5,uVar2);
  return;
}



uint8_t RAIL_ScheduleTx(void *params)

{
  uint8_t uVar1;
  uint uVar2;
  uint32_t us;
  char cVar3;
  uint64_t uVar4;
  
  cVar3 = *(char *)((int)params + 4);
  if (cVar3 != '\0') {
    cVar3 = '\x01';
  }
  uVar2 = TIMING_TxWarmTimeGet();
                    // WARNING: Load size is inaccurate
  if ((*(char *)((int)params + 4) == '\x01') && (*params < uVar2)) {
    us = 0;
  }
  else {
    us = *params - uVar2;
  }
  uVar4 = PROTIMER_UsToPrecntOverflow(us);
  uVar1 = GENERIC_PHY_SchedulePacketTx((int)uVar4,cVar3);
  return uVar1;
}



uint8_t RFHAL_RxStart(uint8_t reset)

{
  uint uVar1;
  
  uVar1 = (RAC->RXENSRCEN);
  if ((uVar1 & 0xff) == 0) {
    BUFC_RxBufferReset(reset);
  }
  GENERIC_PHY_StartRx(0);
  return '\0';
}



void RFHAL_EnableRxRawCapture(void)

{
  uint uVar1;
  int in_r0;
  uint uVar2;
  uint in_r1;
  
  uVar2 = in_r0 - 1U & 0xff;
  if (uVar2 < 3) {
    in_r1 = *(uint *)(&CSWTCH_104 + uVar2 * 4);
  }
  uVar1 = (MODEM->CTRL0);
  if (2 < uVar2) {
    in_r1 = 0;
  }
  write_volatile_4(MODEM->CTRL0,uVar1 & 0xc7ffffff | in_r1);
  BUS_RegMaskedSet(&MODEM->CTRL0,0x200000);
  uVar2 = (FRC->BUFFERMODE);
  write_volatile_4(FRC->BUFFERMODE,uVar2 & 0xfffffff9 | 4);
  BUS_RegMaskedSet(&RAC->SR3,0x10000000);
  write_volatile_4(FRC->RAWCTRL,4);
  return;
}



void RFHAL_DisableRxRawCapture(void)

{
  BUS_RegMaskedClear(&FRC->BUFFERMODE,6);
  write_volatile_4(FRC->RAWCTRL,0);
  BUS_RegMaskedClear(&RAC->SR3,0x10000000);
  BUS_RegMaskedClear(&MODEM->CTRL0,0x200000);
  BUS_RegMaskedClear(&MODEM->CTRL0,0x38000000);
  return;
}



void RFHAL_EnableRxAppendedInfo(void)

{
  write_volatile_4(FRC->TRAILRXDATA,0x1b);
  return;
}



void RFHAL_DisableRxAppendedInfo(void)

{
  write_volatile_4(FRC->TRAILRXDATA,0);
  return;
}



uint8_t RFHAL_RxIntEnable(uint32_t cbtoenable)

{
  _enabledCallbacks =
       CONCAT11(DAT_20002df9 & 0xc5 | (byte)(((cbtoenable << 0x1e) >> 0x1f) << 3) |
                (byte)(((cbtoenable << 0x1d) >> 0x1f) << 4) |
                (byte)(((cbtoenable << 0x1c) >> 0x1f) << 5) |
                (byte)(((cbtoenable << 0x14) >> 0x1f) << 1),
                enabledCallbacks & 0x87 | (byte)(((cbtoenable << 0x1b) >> 0x1f) << 3) |
                (byte)(((cbtoenable << 0x1a) >> 0x1f) << 4) |
                (byte)(((cbtoenable << 0x15) >> 0x1f) << 5) | ((cbtoenable & 0x300) != 0) << 6);
  _enabledCallbacks = _enabledCallbacks & 0xffff0000 | (uint)_enabledCallbacks;
  bufcEnabledCallbacks =
       bufcEnabledCallbacks & 0xffffff00 |
       (uint)((byte)bufcEnabledCallbacks & 0xf7 | (byte)(cbtoenable << 3) & 8);
  rxConfigEvents = cbtoenable;
  GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
  BUFC_ConfigureCallbacks(bufcEnabledCallbacks);
  return '\0';
}


RAIL_Status_t RFHAL_SetRxOptions(uint32_t options)

{
  uint uVar1;
  RAIL_Status_t RVar2;
  
  uVar1 = (RAC->STATUS);
  if ((uVar1 << 4) >> 0x1c == 3) {
    return RAIL_STATUS_INVALID_STATE;
  }
  RVar2 = (RAIL_Status_t)(options & 1);
  if ((options & 1) == 0) {
    BUS_RegMaskedClear(&FRC->RXCTRL,1);
  }
  else {
    RVar2 = RAIL_STATUS_NO_ERROR;
    BUS_RegMaskedSet(&FRC->RXCTRL,1);
  }
  return RVar2;
}



RAIL_Status_t RFHAL_TxIntEnable(uint32_t cbToEnable)

{
  _enabledCallbacks =
       CONCAT12(DAT_20002dfa & 0x7f | 0x40 | (byte)(((cbToEnable << 0x19) >> 0x1f) << 7),
                _enabledCallbacks);
  _enabledCallbacks =
       _enabledCallbacks & 0xffffff00 |
       (uint)(byte)((byte)(_enabledCallbacks >> 0x18) & 0xfe | (byte)cbToEnable >> 7) << 0x18 |
       (uint)(byte)(enabledCallbacks & 0xfd | ((cbToEnable & 0x1b) != 0) << 1);
  bufcEnabledCallbacks =
       bufcEnabledCallbacks & 0xffffff00 |
       (uint)((byte)bufcEnabledCallbacks & 0xfd | (byte)(cbToEnable << 1) & 2);
  txConfigEvents = cbToEnable;
  GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
  BUFC_ConfigureCallbacks(bufcEnabledCallbacks);
  return RAIL_STATUS_NO_ERROR;
}



RAIL_Status_t RFHAL_ErrorConfig(uint8_t ignore)

{
  FRC_SET *pFVar1;
  
  if ((ignore & 1) == 0) {
    pFVar1 = (FRC_SET *)&Peripherals::FRC_CLR;
  }
  else {
    pFVar1 = &Peripherals::FRC_SET;
  }
  ((FRC_CLR *)pFVar1)->RXCTRL = 2;
  return RAIL_STATUS_NO_ERROR;
}




RAIL_Status_t RAIL_PaCtuneSet(uint8_t txPaCtuneValue,uint8_t rxPaCtuneValue)

{
  PA_CTuneSet(txPaCtuneValue,rxPaCtuneValue);
  return RAIL_STATUS_NO_ERROR;
}



uint32_t RAIL_TimerGet(void)

{
  uint32_t cnt;
  uint64_t uVar1;
  
  cnt = GENERIC_PHY_TimerGetTimeout();
  uVar1 = PROTIMER_PrecntOverflowToUs(cnt);
  return (uint32_t)uVar1;
}




void RAIL_TimerCancel(void)

{
  GENERIC_PHY_TimerStop();
  _enabledCallbacks = _enabledCallbacks & 0xfdffffff;
  GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
  return;
}



RAIL_Status_t RAIL_TimerSet(uint32_t time,RAIL_TimeMode_t mode)

{
  bool bVar1;
  CORE_irqState_t irqState;
  RAIL_TimeMode_t mode_00;
  uint64_t uVar2;
  
  mode_00 = mode;
  if (mode != RAIL_TIME_ABSOLUTE) {
    mode_00 = RAIL_TIME_DELAY;
  }
  if (mode == RAIL_TIME_DISABLED) {
    RAIL_TimerCancel();
    return RAIL_STATUS_NO_ERROR;
  }
  irqState = CORE_EnterCritical();
  _enabledCallbacks = _enabledCallbacks | 0x2000000;
  GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
  timerExpired = 0;
  uVar2 = PROTIMER_UsToPrecntOverflow(time);
  bVar1 = GENERIC_PHY_TimerStart((uint32_t)uVar2,mode_00);
  CORE_ExitCritical(irqState);
  return (RAIL_Status_t)(bVar1 ^ 1);
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




/* void RAIL_TimerIsRunning(void)

{
  GENERIC_PHY_TimerIsRunning();
  return;
}
 */
bool RAIL_TimerIsRunning(void)

{
  bool bVar1;
  
  bVar1 = PROTIMER_CCTimerIsEnabled(2);
  return bVar1;
}




/* void RAIL_SymbolRateGet(void)

{
  RADIO_ComputeTxSymbolRate();
  return;
} */

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

/* void RAIL_BitRateGet(void)

{
  RADIO_ComputeTxBitRate();
  return;
} */

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




uint32_t RAIL_RfSense(RAIL_RfSenseBand_t band,uint32_t senseTime,bool enableCb)

{
  uint32_t uVar1;
  uint in_r3;
  undefined4 local_14;
  uint32_t local_10;
  uint local_c;
  
  local_14 = 0xe7f5;
  if (enableCb == false) {
    local_14 = 0;
  }
  local_c._0_2_ = CONCAT11(1,band);
  local_c = in_r3 & 0xffff0000 | (uint)(ushort)local_c;
  local_10 = senseTime;
  uVar1 = RFSENSE_Init(&local_14);
  return uVar1;
}



/* void RAIL_RfSensed(void)

{
  RFSENSE_Sensed();
  return;
} */

bool RAIL_RfSensed(void)

{
  code *pcVar1;
  int iVar2;
  CORE_irqState_t irqState;
  uint uVar3;
  
  iVar2 = _DAT_43c81904;
  BUS_RegMaskedSet(&CMU->HFRADIOCLKEN0,2);
  uVar3 = (RFSENSE->IF);
  if (uVar3 != 0) {
    uVar3 = 1;
  }
  if (uVar3 != 0) {
    irqState = CORE_EnterCritical();
    pcVar1 = RFSENSE_Cb;
    RFSENSE_Cb = FUN_00000000;
    CORE_ExitCritical(irqState);
    RFSENSE_Disable();
    if (pcVar1 != FUN_00000000) {
      (*pcVar1)();
    }
  }
  if (iVar2 == 0) {
    BUS_RegMaskedClear(&CMU->HFRADIOCLKEN0,2);
  }
  return SUB41(uVar3,0);
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void RAIL_DebugCbConfig(int param_1)

{
  _enabledCallbacks =
       CONCAT11(DAT_000113dd & 0x7f | (byte)(((uint)(param_1 << 0x1e) >> 0x1f) << 7),
                enabledCallbacks);
  _enabledCallbacks = _enabledCallbacks & 0xffff0000 | (uint)_enabledCallbacks;
  GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
  return;
}



uint8_t RFHAL_CalibrationInit(RAIL_CalInit_t *railCalInit)

{
  uint8_t uVar1;
  
  uVar1 = IRCAL_Init(railCalInit->irCalSettings);
  return uVar1;
}


void RFHAL_CalibrationRun(int *calValues,RAIL_CalMask_t calForce)

{
  int iVar1;
  
  if ((int)(calForce << 0x1f) < 0) {
    TEMPCAL_Perform();
  }
  if ((int)(calForce << 0xf) < 0) {
    if (*calValues == -1) {
      iVar1 = IRCAL_Perform();
      *calValues = iVar1;
      return;
    }
    IRCAL_Set();
    return;
  }
  return;
}



RAIL_Status_t RFHAL_SetTxTransitions(RAIL_RadioState_t success,RAIL_RadioState_t error)

{
  ushort uVar1;
  
  uVar1 = read_volatile_2(SEQ->REG00C._0_2_);
  write_volatile_4(SEQ->REG00C,
                   1 << (success + 0x10 & 0xff) | (uint)uVar1 | 1 << (error + 0x18 & 0xff));
  return RAIL_STATUS_NO_ERROR;
}



RAIL_Status_t RFHAL_SetRxTransitions(RAIL_RadioState_t success,RAIL_RadioState_t error)

{
  ushort uVar1;
  
  uVar1 = read_volatile_2(SEQ->REG00C._2_2_);
  write_volatile_4(SEQ->REG00C,
                   1 << (error + 8 & 0xff) | 1 << success | (uint)uVar1 << 0x10);
  return RAIL_STATUS_NO_ERROR;
}



void RFHAL_SetBerConfig(undefined4 *param_1)

{
  RFTEST_ResetBerStats(*param_1);
  return;
}



void RFHAL_StartBerRx(void)

{
  uint uVar1;
  
  RFTEST_SaveRadioConfiguration();
  write_volatile_4(Peripherals::FRC.SNIFFCTRL,0);
  write_volatile_4(Peripherals::FRC.DFLCTRL,5);
  write_volatile_4(Peripherals::MODEM_CLR.TIMING,0xf00);
  PTR_rxFifoAlmostFull_000113c4 = &RFTEST_BerEmptyBufcAndUpdateStats;
  BUFC_SetCallbacks();
  bufcEnabledCallbacks =
       bufcEnabledCallbacks & 0xffffff00 | (uint)(byte)((byte)bufcEnabledCallbacks | 4);
  BUFC_ConfigureCallbacks(bufcEnabledCallbacks);
  uVar1 = read_volatile_4(Peripherals::BUFC.BUF1_THRESHOLDCTRL);
  write_volatile_4(Peripherals::BUFC.BUF1_THRESHOLDCTRL,uVar1 & 0xfffff000 | 100);
  write_volatile_4(Peripherals::BUFC_SET.IEN,0x400);
  RFTEST_StartRx();
  return;
}



void RFHAL_StopBerRx(void)

{
  RFTEST_BerStop();
  bufcEnabledCallbacks =
       bufcEnabledCallbacks & 0xffffff00 | (uint)((byte)bufcEnabledCallbacks & 0xfb);
  BUFC_ConfigureCallbacks(bufcEnabledCallbacks);
  write_volatile_4(Peripherals::BUFC_CLR.IEN,0x400);
  RFTEST_RestoreRadioConfiguration();
  return;
}



void RFHAL_GetBerStatus(int *param_1,int param_2,int param_3,undefined4 param_4)

{
  int local_18;
  int local_14;
  int local_10;
  undefined4 local_c;
  
  local_18 = (int)param_1;
  local_14 = param_2;
  local_10 = param_3;
  local_c = param_4;
  RFTEST_ReportBerStats(&local_18);
  *param_1 = local_18;
  param_1[1] = local_14;
  param_1[2] = local_10;
  *(undefined *)(param_1 + 3) = (undefined)local_c;
  return;
}



/* void RFHAL_SetCRCInitVal(void)

{
  RADIO_SetCRCInitVal();
  return;
} */

void RFHAL_SetCRCInitVal(uint32_t value)

{
  write_volatile_4(Peripherals::CRC.INIT,value);
  write_volatile_4(Peripherals::CRC.CMD,1);
  return;
}

/* void RFHAL_GetCurrPowerLevel(void)

{
  PA_OutputPowerGet();
  return;
} */

int32_t RFHAL_GetCurrPowerLevel(void)

{
  return (int)gPaConfig.power;
}


int32_t RFHAL_SetCurrPowerLevel(int32_t powerLevel)

{
  code *pcVar1;
  uint8_t uVar2;
  int32_t iVar3;
  
  iVar3 = PA_OutputPowerSet(powerLevel);
  pcVar1 = protChChngCB;
  if (protChChngCB != FUN_00000000) {
    uVar2 = RAILInt_GetChannel();
    (*pcVar1)(uVar2,1);
  }
  return iVar3;
}



void RFHAL_SetProtocolSpecificChCheckCB(undefined4 param_1)

{
  protChChngCB = param_1;
  return;
}



void RFHAL_StopTestMode(void)

{
  RFTEST_StopTx();
  RFTEST_RestoreRadioConfiguration();
  return;
}



void RFHAL_StartCWTestMode(void)

{
  RFTEST_SaveRadioConfiguration();
  RFTEST_StartCwTx();
  return;
}



void RFHAL_StartStreamTestMode(void)

{
  RFTEST_SaveRadioConfiguration();
  RFTEST_StartStreamTx();
  return;
}



RAIL_Status_t RFHAL_SetChannel(uint8_t channel,RAIL_ChannelConfig_t *config)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  int in_r2;
  
  iVar3 = RAIL_DebugModeGet();
  if (iVar3 != 1) {
    do {
      bVar2 = RFHAL_HeadedToIdle();
      if (bVar2 == false) break;
      uVar1 = read_volatile_4(Peripherals::RAC.STATUS);
    } while ((uVar1 & 0xf000000) != 0);
    uVar1 = read_volatile_4(Peripherals::RAC.STATUS);
    if ((uVar1 & 0xf000000) != 0) {
      return RAIL_STATUS_INVALID_STATE;
    }
    if (protChChngCB != FUN_00000000) {
      (*protChChngCB)(channel);
    }
    if (in_r2 != 0) {
      SYNTH_Config(config[1].configs,config->length);
    }
    GENERIC_PHY_ChannelSet(channel - *(char *)&config->configs);
  }
  return RAIL_STATUS_NO_ERROR;
}


bool RFHAL_AutoAckEnable(void)

{
  uint uVar1;
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  uVar1 = (SEQ->REG000);
  write_volatile_4(SEQ->REG000,uVar1 | 0x20);
  CORE_ExitCritical(irqState);
  return SUB41((uVar1 << 0x1a) >> 0x1f,0);
}



bool RFHAL_AutoAckDisable(void)

{
  uint uVar1;
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  uVar1 = (SEQ->REG000);
  write_volatile_4(SEQ->REG000,uVar1 & 0xffffffdf);
  CORE_ExitCritical(irqState);
  return SUB41((uVar1 << 0x1a) >> 0x1f,0);
}


bool RFHAL_AutoAckIsEnabled(void)

{
  uint uVar1;
  
  uVar1 = (SEQ->REG000);
  return SUB41((uVar1 << 0x1a) >> 0x1f,0);
}


RAIL_Status_t RFHAL_AutoAckConfig(RAIL_AutoAckConfig_t *config)

{
  uint64_t uVar1;
  
  uVar1 = PROTIMER_UsToPrecntOverflow((uint)config->ackTimeout);
  write_volatile_4(SEQ->REG008,-(int)uVar1);
  return RAIL_STATUS_NO_ERROR;
}



RAIL_Status_t RFHAL_AutoAckLoadBuffer(RAIL_AutoAckData_t *ackData)

{
  CORE_irqState_t irqState;
  uint uVar1;
  RAIL_Status_t RVar2;
  
  irqState = CORE_EnterCritical();
  BUS_RegMaskedSet(&RAC->SR0,2);
  uVar1 = (RAC->STATUS);
  uVar1 = (uVar1 << 4) >> 0x1c;
  if (((uVar1 - 7 < 3) || (uVar1 == 0xc)) &&
     (uVar1 = (RAC->SR0), (int)(uVar1 << 0xe) < 0)) {
    RVar2 = RAIL_STATUS_INVALID_CALL;
  }
  else {
    BUFC_TxAckBufferSet(ackData->dataPtr,(ushort)ackData->dataLength);
    RVar2 = RAIL_STATUS_NO_ERROR;
  }
  BUS_RegMaskedClear(&RAC->SR0,2);
  CORE_ExitCritical(irqState);
  return RVar2;
}



void RFHAL_AutoAckRxPause(void)

{
  uint uVar1;
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  uVar1 = (SEQ->REG000);
  write_volatile_4(SEQ->REG000,uVar1 | 8);
  CORE_ExitCritical(irqState);
  return;
}



void RFHAL_AutoAckRxResume(void)

{
  uint uVar1;
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  uVar1 = (SEQ->REG000);
  write_volatile_4(SEQ->REG000,uVar1 & 0xfffffff7);
  CORE_ExitCritical(irqState);
  return;
}



void RFHAL_AutoAckTxPause(void)

{
  uint uVar1;
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  uVar1 = (SEQ->REG000);
  write_volatile_4(SEQ->REG000,uVar1 | 0x100);
  CORE_ExitCritical(irqState);
  return;
}




void RFHAL_AutoAckTxResume(void)

{
  uint uVar1;
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  uVar1 = (SEQ->REG000);
  write_volatile_4(SEQ->REG000,uVar1 & 0xfffffeff);
  CORE_ExitCritical(irqState);
  return;
}



bool RFHAL_AutoAckRxIsPaused(void)

{
  uint uVar1;
  
  uVar1 = (SEQ->REG000);
  return SUB41((uVar1 << 0x1c) >> 0x1f,0);
}



bool RFHAL_AutoAckTxIsPaused(void)

{
  uint uVar1;
  
  uVar1 = (SEQ->REG000);
  return SUB41((uVar1 << 0x17) >> 0x1f,0);
}



bool RFHAL_AutoAckUseTxBuffer(void)

{
  CORE_irqState_t irqState;
  uint uVar1;
  bool bVar2;
  
  irqState = CORE_EnterCritical();
  uVar1 = GENERIC_PHY_CanModifyAck();
  if (uVar1 != 0) {
    BUS_RegMaskedSet(&RAC->SR0,2);
    uVar1 = (RAC->SR0);
    bVar2 = -1 < (int)(uVar1 << 0xe);
    if (bVar2) {
      BUS_RegMaskedSet(&RAC->SR2,0x40);
    }
    uVar1 = (uint)bVar2;
    BUS_RegMaskedClear(&RAC->SR0,2);
  }
  CORE_ExitCritical(irqState);
  return SUB41(uVar1,0);
}



bool RFHAL_AutoAckCancelAck(void)

{
  CORE_irqState_t irqState;
  uint uVar1;
  bool bVar2;
  
  irqState = CORE_EnterCritical();
  uVar1 = GENERIC_PHY_CanModifyAck();
  if (uVar1 != 0) {
    BUS_RegMaskedSet(&RAC->SR0,2);
    uVar1 = (RAC->SR0);
    bVar2 = -1 < (int)(uVar1 << 0xe);
    if (bVar2) {
      BUS_RegMaskedSet(&RAC->SR2,0x20);
    }
    uVar1 = (uint)bVar2;
    BUS_RegMaskedClear(&RAC->SR0,2);
  }
  CORE_ExitCritical(irqState);
  return SUB41(uVar1,0);
}




void RFHAL_AutoAckWaitForAck(bool wait)

{
  RAC_SET *pRVar1;
  
  if (wait == false) {
    pRVar1 = &Peripherals::RAC_SET;
  }
  else {
    pRVar1 = (RAC_SET *)&Peripherals::RAC_CLR;
  }
  ((RAC_CLR *)pRVar1)->SR0 = 0x100;
  return;
}



uint8_t RFHAL_TxStart(uint8_t channel,RAIL_TxOptions_t *options,RAIL_PreTxOp_t *preTxOp,
                     void *preTxOpParams)

{
  bool bVar1;
  byte bVar2;
  
  if ((options != (RAIL_TxOptions_t *)0x0) && (bVar1 = RFHAL_AutoAckIsEnabled(), bVar1 != false)) {
    RFHAL_AutoAckWaitForAck((bool)options->waitForAck);
  }
  if (preTxOp == FUN_00000000) {
    GENERIC_PHY_PacketTx();
  }
  else {
    bVar2 = (*preTxOp)(preTxOpParams);
    preTxOp = (RAIL_PreTxOp_t *)(uint)bVar2;
    if (preTxOp != FUN_00000000) {
      BUS_RegMaskedClear(&RAC->SR0,0x100);
      return (uint8_t)bVar2;
    }
  }
  return (uint8_t)preTxOp;
}




uint RFHAL_AutoAckWaitingForAck(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::RAC.SR1);
  return (uVar1 << 0x1c) >> 0x1f;
}



uint16_t RFHAL_WriteTxFifo(uint8_t *dataPtr,uint16_t writeLength)

{
  uint16_t uVar1;
  
  uVar1 = BUFC_GetSpaceAvailable(0);
  if (uVar1 <= writeLength) {
    writeLength = BUFC_GetSpaceAvailable(0);
  }
  BUFC_WriteBuffer(0,dataPtr,writeLength);
  return writeLength;
}



uint16_t RFHAL_ReadRxFifo(uint8_t *dataPtr,uint16_t readLength)

{
  uint16_t uVar1;
  
  uVar1 = BUFC_GetBytesAvailable(1);
  if (uVar1 <= readLength) {
    readLength = BUFC_GetBytesAvailable(1);
  }
  BUFC_ReadBuffer(1,dataPtr,readLength);
  return readLength;
}




void RFHAL_ReadRxFifoAppendedInfo(RAIL_AppendedInfo_t *appendedInfo)

{
  uint uVar1;
  uint32_t uVar2;
  uint64_t uVar3;
  undefined auStack28 [5];
  int8_t local_17;
  byte local_16;
  uint32_t local_10;
  
  uVar2 = RADIO_RxTrailDataLength();
  GENERIC_PHY_PacketRxAppendedInfoHelper(uVar2,auStack28);
  read_volatile(FRC->IEN._0_1_);
  uVar1 = (FRC->IF);
  *(byte *)&appendedInfo->field_0x4 =
       *(byte *)&appendedInfo->field_0x4 & 0xfd | (byte)((((uVar1 ^ 0x80) << 0x18) >> 0x1f) << 1);
  write_volatile_4(FRC->IFC,0x80);
  if (local_16 != 0) {
    local_16 = 1;
  }
  appendedInfo->rssiLatch = local_17;
  *(byte *)&appendedInfo->field_0x4 = *(byte *)&appendedInfo->field_0x4 & 0xfe | local_16 & 1;
  uVar3 = TIMING_GetRxTimestampUs(local_10);
  appendedInfo->timeUs = (uint32_t)uVar3;
  appendedInfo->syncWordId = '\0';
  return;
}



uint16_t RFHAL_SetRxFifoThreshold(uint16_t threshold)

{
  uint uVar1;
  
  uVar1 = (BUFC->BUF1_THRESHOLDCTRL);
  if (threshold < 0x201) {
    uVar1 = (uint)threshold | uVar1 & 0xfffff000;
  }
  else {
    uVar1 = uVar1 & 0xfffff000 | 0x200;
  }
  write_volatile_4(BUFC->BUF1_THRESHOLDCTRL,uVar1);
  uVar1 = (BUFC->BUF1_THRESHOLDCTRL);
  return (uint16_t)((uVar1 << 0x14) >> 0x14);
}



uint16_t RFHAL_GetTxFifoThreshold(void)

{
  uint uVar1;
  
  uVar1 = (BUFC->BUF0_THRESHOLDCTRL);
  return (uint16_t)((ushort)((uVar1 << 0x14) >> 0x14) + 1);
}




uint16_t RFHAL_SetTxFifoThreshold(uint16_t threshold)

{
  uint uVar1;
  uint16_t uVar2;
  
  uVar1 = (BUFC->BUF0_THRESHOLDCTRL);
  if (0x1ff < threshold) {
    threshold = 0x200;
  }
  write_volatile_4(BUFC->BUF0_THRESHOLDCTRL,
                   uVar1 & 0xfffff000 | (uint)(ushort)(threshold - 1));
  uVar2 = RFHAL_GetTxFifoThreshold();
  return uVar2;
}



uint16_t RFHAL_GetRxFifoThreshold(void)

{
  uint uVar1;
  
  uVar1 = (BUFC->BUF1_THRESHOLDCTRL);
  return (uint16_t)((uVar1 << 0x14) >> 0x14);
}



void RFHAL_EnableRxFifoThreshold(void)

{
  write_volatile_4(Peripherals::BUFC_SET.IEN,0x400);
  return;
}



void RFHAL_DisableRxFifoThreshold(void)

{
  write_volatile_4(Peripherals::BUFC_CLR.IEN,0x400);
  return;
}



uint16_t RFHAL_GetTxFifoSpaceAvailable(void)

{
  uint16_t uVar1;
  
  uVar1 = BUFC_GetSpaceAvailable(0);
  return uVar1;
}



uint16_t RFHAL_GetRxFifoBytesAvailable(void)

{
  uint16_t uVar1;
  
  uVar1 = BUFC_GetBytesAvailable(1);
  return (uint16_t)uVar1;
}


void RFHAL_ResetTxFifo(void)

{
  BUS_RegMaskedClear(&BUFC->IEN,4);
  write_volatile_4(BUFC->BUF0_CMD,1);
  BUS_RegMaskedClear(&BUFC->BUF0_THRESHOLDCTRL,0x2000);
  BUS_RegMaskedSet(&BUFC->IEN,4);
  return;
}



void RFHAL_ResetRxFifo(void)

{
  BUS_RegMaskedClear(&BUFC->IEN,0x400);
  write_volatile_4(BUFC->BUF1_CMD,1);
  BUS_RegMaskedClear(&BUFC->BUF1_THRESHOLDCTRL,0x2000);
  BUS_RegMaskedSet(&BUFC->IEN,0x400);
  return;
}



RAIL_Status_t RFHAL_DataConfig(RAIL_DataConfig_t *dataConfig)

{
  if (dataConfig->txMethod == dataConfig->rxMethod) {
    if (dataConfig->rxSource == RX_PACKET_DATA) {
      RFHAL_DisableRxRawCapture();
    }
    else {
      RFHAL_EnableRxRawCapture();
    }
    if (dataConfig->txMethod == PACKET_MODE) {
      bufcEnabledCallbacks =
           bufcEnabledCallbacks & 0xffffff00 | (uint)((byte)bufcEnabledCallbacks & 0xfe);
    }
    else {
      bufcEnabledCallbacks =
           bufcEnabledCallbacks & 0xffffff00 | (uint)((byte)bufcEnabledCallbacks | 1);
      RFHAL_ResetTxFifo();
    }
    if (dataConfig->rxMethod == PACKET_MODE) {
      bufcEnabledCallbacks =
           bufcEnabledCallbacks & 0xffffff00 | (uint)((byte)bufcEnabledCallbacks & 0xfb);
      BUS_RegMaskedSet(&FRC->RXCTRL,0x60);
      BUS_RegMaskedClear(&RAC->SR0,0x40);
      BUS_RegMaskedClear(&FRC->RXCTRL,2);
    }
    else {
      bufcEnabledCallbacks = bufcEnabledCallbacks | 4;
      BUS_RegMaskedClear(&FRC->RXCTRL,0x60);
      RFHAL_ResetRxFifo();
      BUS_RegMaskedSet(&RAC->SR0,0x40);
      BUS_RegMaskedSet(&FRC->RXCTRL,2);
    }
    BUFC_ConfigureCallbacks(bufcEnabledCallbacks);
    return RAIL_STATUS_NO_ERROR;
  }
  return RAIL_STATUS_INVALID_PARAMETER;
}



uint16_t RFHAL_SetFixedLength(uint16_t length)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (uint)length;
  uVar1 = (FRC->DFLCTRL);
  if (((uVar1 & 7) != 0) && ((uVar1 & 7) != 5)) {
    return 0xffff;
  }
  if (uVar2 == 0) {
    uVar1 = (FRC->DFLCTRL);
    write_volatile_4(FRC->DFLCTRL,uVar1 & 0xfffffff8 | 5);
    return length;
  }
  BUS_RegMaskedClear(&FRC->DFLCTRL,7);
  if (0xfff < uVar2) {
    uVar2 = 0x1000;
  }
  write_volatile_4(FRC->WCNTCMP0,uVar2 - 1);
  return (uint16_t)uVar2;
}


