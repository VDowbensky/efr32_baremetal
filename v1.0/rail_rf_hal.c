#include "rail_rf_hal.h"



void pktTxDoneEvt(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_c;
  undefined4 uStack8;
  
  local_c = param_2;
  uStack8 = param_3;
  GENERIC_PHY_PreviousTxTime();
  local_c = TIMING_GetTxTimestampUs();
  RAILCb_TxPacketSent(&local_c);
  return;
}



void pktRxFrmErr(void)

{
  write_volatile_4(Peripherals::FRC.IFC,0x80);
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
  undefined4 uVar2;
  
  uVar1 = read_volatile_4(Peripherals::RAC.SR0);
  write_volatile_4(Peripherals::RAC_CLR.SR0,0x1000000);
  if ((int)(uVar1 << 7) < 0) {
    uVar2 = 0x40;
  }
  else {
    uVar2 = 0x400;
  }
  RAILCb_RxRadioStatusExt(uVar2);
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
  RAILCb_TxRadioStatus(0x40);
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
  
  uVar1 = read_volatile_4(Peripherals::RAC.STATUS);
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



void rxFifoAlmostFull(void)

{
  BUFC_GetBytesAvailable(1);
  RAILCb_RxFifoAlmostFull();
  return;
}



void txFifoAlmostEmpty(void)

{
  BUFC_GetSpaceAvailable(0);
  RAILCb_TxFifoAlmostEmpty();
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
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  ushort local_3c;
  byte local_3a;
  undefined local_39;
  uint local_38;
  undefined auStack52 [5];
  undefined local_2f;
  byte local_2e;
  undefined4 local_28;
  
  BUFC_RxLengthReadNext(&local_3c);
  uVar8 = -((int)((uint)(byte)bufcEnabledCallbacks << 0x1d) >> 0x1f);
  if (uVar8 == 0) {
    iVar2 = RADIO_RxTrailDataLength();
    if (local_3c != 0xffff) {
      uVar10 = (uint)local_3c - iVar2 & 0xffff;
      uVar3 = RAILCb_AllocateMemory(uVar10 + 0xc);
      while (uVar8 < uVar10) {
        local_38 = uVar10 - uVar8;
        uVar4 = RAILCb_BeginWriteMemory(uVar3,uVar8 + 10,&local_38);
        if (local_38 == 0) {
          uVar4 = local_38;
          local_38 = uVar10 - uVar8;
        }
        iVar5 = GENERIC_PHY_PacketRxDataHelper(uVar4,local_38 & 0xffff);
        uVar9 = uVar8 + iVar5;
        if (uVar4 == 0) {
          iVar5 = 0;
        }
        RAILCb_EndWriteMemory(uVar3,uVar8 + 10,iVar5);
        uVar8 = uVar9 & 0xffff;
      }
      GENERIC_PHY_PacketRxAppendedInfoHelper(iVar2,auStack52);
      local_38 = 0xc;
      puVar6 = (undefined4 *)RAILCb_BeginWriteMemory(uVar3,0,&local_38);
      if ((puVar6 == (undefined4 *)0x0) || (local_38 < 0xc)) {
        uVar7 = 0;
      }
      else {
        read_volatile(Peripherals::FRC.IEN._0_1_);
        uVar8 = read_volatile_4(Peripherals::FRC.IF);
        *(short *)(puVar6 + 2) = (short)uVar10;
        *(byte *)(puVar6 + 1) =
             *(byte *)(puVar6 + 1) & 0xfd | (byte)((((uVar8 ^ 0x80) << 0x18) >> 0x1f) << 1);
        write_volatile_4(Peripherals::FRC.IFC,0x80);
        bVar1 = *(byte *)(puVar6 + 1);
        if (local_2e != 0) {
          local_2e = 1;
        }
        *(byte *)(puVar6 + 1) = bVar1 & 0xfe | local_2e & 1;
        *(undefined *)((int)puVar6 + 5) = local_2f;
        *(undefined *)((int)puVar6 + 6) = local_39;
        *(byte *)(puVar6 + 1) =
             bVar1 & 0xfa | local_2e & 1 | (byte)((((uint)local_3a << 0x1c) >> 0x1f) << 2);
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
  else {
    RAILCb_RxPacketReceived(0);
  }
  return;
}



void rxTimeout(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 1) {
    if (rxConfigEvents << 0x16 < 0) {
      uVar1 = 0x200;
LAB_0001022a:
      RAILCb_RxRadioStatusExt(uVar1);
      return;
    }
  }
  else {
    if (param_1 == 2) {
      if (rxConfigEvents << 0x17 < 0) {
        uVar1 = 0x100;
        goto LAB_0001022a;
      }
    }
  }
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
  byte local_1c [2];
  undefined2 local_1a;
  
  if (param_1 << 10 < 0) {
    RAILCb_RxAckTimeout();
  }
  if ((param_1 << 0xc < 0) && (iVar4 = GENERIC_PHY_CanModifyAck(), iVar4 != 0)) {
    uVar2 = read_volatile_4(Peripherals::BUFC.BUF1_ADDR);
    uVar1 = read_volatile_4(Peripherals::BUFC.BUF1_CTRL);
    uVar3 = read_volatile_4(Peripherals::RAC.SR1);
    uVar7 = (uVar3 << 0x18) >> 0x1e;
    uVar8 = (0x40 << (uVar1 & 0xff)) - 1U & 0xffff;
    uVar1 = read_volatile_4(Peripherals::SEQ.REG004);
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
    RAILCb_IEEE802154_DataRequestCommand(local_1c);
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

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
  RAILCb_RssiAverageDone((int)currentRssiAverage);
  write_volatile_4(Peripherals::AGC_CLR.CTRL1,0xffffff00);
  write_volatile_4(Peripherals::AGC_SET.CTRL1,saveRssiPeriod & 0xffffff00);
  isRssiReady = 1;
  return;
}



uint userTransmitStarted(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::RAC.SR0);
  uVar1 = uVar1 & 0x80;
  if (uVar1 != 0) {
    uVar1 = read_volatile_4(Peripherals::PROTIMER.STATUS);
    if (-1 < (int)(uVar1 << 0x1d)) {
      uVar1 = read_volatile_4(Peripherals::PROTIMER.CC3_CTRL);
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
    write_volatile_4(Peripherals::RAC_CLR.SR0,0x80);
    write_volatile_4(Peripherals::RAC_CLR.RXENSRCEN,0x10);
  }
  if ((txConfigEvents & param_1) != 0) {
    RAILCb_TxRadioStatus(txConfigEvents & param_1 & 0xff);
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
    write_volatile_4(Peripherals::BUFC.BUF0_CMD,1);
    uVar1 = read_volatile_4(Peripherals::SEQ.REG00C);
    if ((uVar1 & 0xff000000) == 0x2000000) {
      write_volatile_4(Peripherals::RAC_SET.RXENSRCEN,2);
    }
LAB_000103fc:
    uVar2 = 4;
  }
  else {
    if (-1 < param_1 << 0xb) {
      if (-1 < param_1 << 0x13) goto LAB_00010402;
      PROTIMER_LBTStop();
      uVar1 = read_volatile_4(Peripherals::PROTIMER.IF);
      if ((uVar1 & 0x500000) != 0) goto LAB_00010402;
      RADIO_PTI_AuxdataOutput(0x2a);
      write_volatile_4(Peripherals::BUFC.BUF0_CMD,1);
      goto LAB_000103fc;
    }
    RADIO_PTI_AuxdataOutput(0x28);
    uVar2 = 0x20;
  }
  pktTxErrorEvt(uVar2);
LAB_00010402:
  write_volatile_4(Peripherals::AGC_CLR.CTRL1,0xffffff00);
  write_volatile_4(Peripherals::AGC_SET.CTRL1,saveRssiPeriodPreCca & 0xffffff00);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

uint8_t RFHAL_Init(RAIL_Init_t *railInit)

{
  uint32_t uVar1;
  int iVar2;
  
  uVar1 = SystemHFXOClockGet();
  if (uVar1 == railInit->rfXtalFreq) {
    GENERIC_PHY_Init();
    _enabledCallbacks =
         _enabledCallbacks & 0xff000000 | (uint)(uint3)((uint3)_enabledCallbacks | 7) | 0x200000;
    iVar2 = RFHAL_CalibrationEnableGet();
    if (iVar2 << 0x1f < 0) {
      _enabledCallbacks = _enabledCallbacks | 0x40000;
    }
    _enabledCallbacks = _enabledCallbacks | 0x80000;
    GENERIC_PHY_SetCallbacks(&callbacks);
    GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
    RAILCb_RfReady();
    return '\0';
  }
  return '\x01';
}



uint RFHAL_SetPtiProtocol(uint param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  int unaff_r4;
  
  uVar2 = param_1 & 0xfffffff0;
  if (uVar2 == 0) {
    unaff_r4 = 0x21000f64;
    uVar1 = read_volatile_4(Peripherals::SEQ.REG06C);
    param_4 = uVar1 & 0xfffffff0 | param_1 & 0xf;
    param_1 = uVar2;
  }
  if (uVar2 == 0) {
    *(uint *)(unaff_r4 + 8) = param_4;
  }
  else {
    param_1 = 1;
  }
  return param_1;
}



void RFHAL_IdleExt(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  switch(param_1) {
  case 0:
    uVar2 = 0;
    uVar1 = uVar2;
    uVar3 = uVar2;
    goto LAB_00010500;
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
    goto LAB_00010500;
  default:
    return;
  }
  uVar2 = 1;
  uVar3 = 0;
LAB_00010500:
  GENERIC_PHY_RadioIdle(uVar2,uVar1,uVar3);
  return;
}



RAIL_RadioState_t RFHAL_StateGet(void)

{
  uint uVar1;
  bool bVar2;
  
  uVar1 = read_volatile_4(RAC->.STATUS);
  uVar1 = uVar1 & 0xf000000;
  if (uVar1 != 0x6000000) {
    if (0x6000000 < uVar1) {
      if (uVar1 != 0x9000000) {
        if (uVar1 < 0x9000001) {
          if (uVar1 == 0x7000000) {
            return RAIL_RF_STATE_RX;
          }
          bVar2 = uVar1 == 0x8000000;
        }
        else {
          if (uVar1 == 0xb000000) {
            return RAIL_RF_STATE_TX;
          }
          if (uVar1 == 0xc000000) {
            return RAIL_RF_STATE_TX;
          }
          bVar2 = uVar1 == 0xa000000;
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



uint RFHAL_OkToTransmit(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::RAC.SR0);
  return ((uVar1 ^ 0x80) << 0x18) >> 0x1f;
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
    uVar3 = read_volatile_4(RAC->.STATUS);
    uVar1 = read_volatile_4(RAC->.SR0);
    CORE_ExitCritical(irqState);
    if (((uVar3 & 0xc0000000) == 0) &&
       ((-1 < (int)(uVar1 << 0x18) && (uVar3 = uVar3 & 0xf000000, uVar3 != 0x6000000)))) {
      if (uVar3 < 0x6000001) {
        bVar4 = uVar3 == 0x3000000;
      }
      else {
        if (uVar3 == 0x9000000) goto LAB_00009218;
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
LAB_00009218:
  return SUB41(iVar2,0);
}



undefined4
RFHAL_TxDataLoad(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar1 = CORE_EnterCritical();
  uVar2 = read_volatile_4(Peripherals::RAC.STATUS);
  uVar2 = (uVar2 << 4) >> 0x1c;
  if (((uVar2 - 7 < 3) || (uVar2 == 0xc)) &&
     (uVar2 = read_volatile_4(Peripherals::RAC.SR0), (int)(uVar2 << 0xf) < 0)) {
    uVar3 = 3;
  }
  else {
    write_volatile_4(Peripherals::BUFC.BUF0_CMD,1);
    BUFC_WriteBuffer(0,*param_1,*(undefined2 *)(param_1 + 1),&Peripherals::BUFC,param_4);
    uVar3 = 0;
  }
  CORE_ExitCritical(uVar1);
  return uVar3;
}



uint8_t RAIL_CcaCsma(void *params)

{
  byte bVar1;
  RAIL_RadioState_t RVar2;
  uint8_t uVar3;
  uint32_t uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  byte bVar10;
  byte bVar11;
  uint uVar12;
  byte bVar13;
  byte bVar14;
  
  if (params == (void *)0x0) {
    PROTIMER_LBTUseLastConfig();
LAB_0000937e:
    GENERIC_PHY_PacketTxCommon();
    uVar4 = lbtTimeout_8797;
    if (lbtTimeout_8797 != 0) {
      iVar5 = PROTIMER_CCTimerIsEnabled(4);
      if (iVar5 != 0) {
        PROTIMER_CCTimerStop(4);
      }
      uVar4 = PROTIMER_UsToPrecntOverflow(uVar4);
      iVar5 = PROTIMER_CCTimerStart(4,uVar4,1);
      if (iVar5 == 0) goto LAB_000092dc;
    }
    PROTIMER_LBTStart();
    uVar3 = '\0';
  }
  else {
    saveRssiPeriodPreCca = read_volatile_4(AGC->.CTRL1);
    RADIO_SetAgcCcaParams
              (*(undefined2 *)((int)params + 6),(int)*(char *)((int)params + 3),saveRssiPeriodPreCca
               ,&saveRssiPeriodPreCca,params);
    bVar13 = *(byte *)((int)params + 2);
                    // WARNING: Load size is inaccurate
    bVar1 = *params;
    bVar10 = *(byte *)((int)params + 1);
    bVar14 = bVar13;
    bVar11 = bVar13;
    if (bVar13 != 0) {
      bVar11 = bVar13 - 1;
      bVar14 = bVar1;
      if (bVar10 < bVar1) {
        bVar13 = 1;
        bVar10 = bVar1;
      }
      else {
        bVar13 = 1;
      }
    }
                    // WARNING: Load size is inaccurate
    uVar12 = count_leading_zeroes((uint)*params);
    uVar4 = PROTIMER_UsToPrecntOverflow((uint)*(ushort *)((int)params + 4));
    uVar8 = uVar4 & 0xffff;
    uVar4 = RADIO_RxWarmTimeGet();
    uVar4 = PROTIMER_UsToPrecntOverflow(uVar4);
    if ((uVar4 < uVar8) || (RVar2 = RAIL_RfStateGet(), RVar2 == RAIL_RF_STATE_RX)) {
      if (uVar12 >> 5 == 0) {
        if (reseedRandom_8798 != 0xf804) {
          write_volatile_4(PROTIMER->.RANDOM,(uint)reseedRandom_8798);
          reseedRandom_8798 = 0xf804;
        }
        if (uVar8 < 0x100) goto LAB_00009344;
        write_volatile_4(PROTIMER->.BASECNTTOP,0xff);
        PROTIMER_LBTCfgSet(bVar14,bVar10,bVar13,bVar11,0);
      }
      else {
        uVar7 = 0;
        uVar9 = uVar8;
        while( true ) {
          uVar6 = uVar7 & 0xff;
          uVar7 = uVar7 + 1;
          if (uVar9 < 0x100) break;
          uVar9 = uVar9 >> 1;
        }
        if ((uVar6 != 0) && (uVar9 != 0xff)) {
          uVar9 = uVar9 + ((int)uVar8 >> (uVar6 - 1 & 0xff) & 1U) & 0xffff;
        }
        uVar8 = read_volatile_4(PROTIMER->.RANDOM);
        reseedRandom_8798 = (ushort)(uVar8 & 0xffff);
        if ((uVar8 & 0xffff) == 0xf804) {
          reseedRandom_8798 = 0xf805;
        }
        write_volatile_4(PROTIMER->.RANDOM,(1 << uVar6) - 1);
        bVar10 = 8;
        write_volatile_4(PROTIMER->.LBTSTATE,0x800000);
        bVar14 = 8;
        uVar8 = uVar9;
LAB_00009344:
        write_volatile_4(PROTIMER->.BASECNTTOP,uVar8 - 1);
        PROTIMER_LBTCfgSet(bVar14,bVar10,bVar13,bVar11,0);
        if (uVar12 >> 5 != 0) {
          _DAT_430a09d0 = 1;
          uVar8 = read_volatile_4(PROTIMER->.CTRL);
          write_volatile_4(PROTIMER->.CTRL,uVar8 & 0xff3fffff | 0x400000);
        }
      }
      lbtTimeout_8797 = *(uint32_t *)((int)params + 8);
      goto LAB_0000937e;
    }
LAB_000092dc:
    uVar3 = '\x01';
  }
  return uVar3;
}



// WARNING: Could not reconcile some variable overlaps

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
  short sVar1;
  int16_t iVar2;
  undefined4 uVar3;
  uint32_t uVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  bool bVar10;
  
  if (averageTimeUs != 0) {
    uVar3 = PROTIMER_GetTime();
    uVar4 = PROTIMER_UsToPrecntOverflow(averageTimeUs);
    iVar7 = 0;
    uVar8 = 0;
    iVar9 = 0;
    while( true ) {
      uVar5 = PROTIMER_GetTime();
      uVar6 = PROTIMER_ElapsedTime(uVar3,uVar5);
      if (uVar4 <= uVar6) break;
      sVar1 = RADIO_GetRSSI();
      uVar6 = SEXT24(sVar1);
      bVar10 = CARRY4(uVar8,uVar6);
      uVar8 = uVar8 + uVar6;
      iVar9 = iVar9 + ((int)uVar6 >> 0x1f) + (uint)bVar10;
      iVar7 = iVar7 + 1;
    }
    if (iVar7 != 0) {
      iVar2 = __aeabi_ldivmod(uVar8,iVar9,iVar7,iVar7 >> 0x1f);
      return iVar2;
    }
  }
  iVar2 = RADIO_GetRSSI();
  return iVar2;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

RAIL_Status_t RFHAL_StartAverageRSSI(uint8_t channel,uint32_t averagingTimeUs)

{
  uint uVar1;
  uint8_t uVar2;
  int iVar3;
  
  saveRssiPeriod = read_volatile_4(AGC->.CTRL1);
  iVar3 = RADIO_CalcRssiPeriod(averagingTimeUs);
  if (iVar3 == 0) {
    frc_modem_ctrl0 = read_volatile_4(MODEM->.CTRL0);
    uVar1 = read_volatile_4(MODEM->.CTRL0);
    write_volatile_4(MODEM->.CTRL0,uVar1 | 0x200000);
    uVar2 = RAIL_RxStart(channel);
    if (uVar2 == '\0') {
      _enabledCallbacks = _enabledCallbacks | 0x2000000;
      GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
    }
    else {
      iVar3 = 2;
    }
  }
  else {
    iVar3 = 1;
  }
  return (RAIL_Status_t)iVar3;
}



int RFHAL_GetAverageRSSI(void)

{
  return (int)currentRssiAverage;
}




undefined RFHAL_AverageRSSIReady(void)

{
  return isRssiReady;
}



uint8_t RFHAL_ScheduleRx(uint8_t channel,RAIL_ScheduleRxConfig_t *cfg)

{
  uint8_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint8_t uVar4;
  uint uVar5;
  RAIL_TimeMode_t RVar6;
  RAIL_TimeMode_t RVar7;
  
  RVar7 = cfg->startMode;
  if (RVar7 == RAIL_TIME_DISABLED) {
    uVar2 = 0;
  }
  else {
    uVar2 = PROTIMER_UsToPrecntOverflow(cfg->start);
    RVar7 = cfg->startMode;
    if (RVar7 != RAIL_TIME_ABSOLUTE) {
      RVar7 = RAIL_TIME_DELAY;
    }
  }
  RVar6 = cfg->endMode;
  if (RVar6 == RAIL_TIME_DISABLED) {
    uVar3 = 0;
  }
  else {
    uVar3 = PROTIMER_UsToPrecntOverflow(cfg->end);
    RVar6 = cfg->endMode;
    if (RVar6 != RAIL_TIME_ABSOLUTE) {
      RVar6 = RAIL_TIME_DELAY;
    }
  }
  uVar5 = count_leading_zeroes((uint)cfg->rxTransitionEndSchedule);
  uVar4 = cfg->hardWindowEnd;
  if (uVar4 != '\0') {
    uVar4 = '\x01';
  }
  uVar1 = GENERIC_PHY_SchedulePacketRx(uVar2,RVar7,uVar3,RVar6,uVar5 >> 5,uVar4);
  return uVar1;
}



RAIL_Status_t RAIL_ScheduleTx(RAIL_ScheduleTxConfig_t *params)

{
  RAIL_Status_t RVar1;
  uint32_t when;
  RAIL_TimeMode_t mode;
  RAIL_TimeMode_t mode_00;
  
  mode_00 = params->mode;
  if (mode_00 != RAIL_TIME_ABSOLUTE) {
    mode_00 = RAIL_TIME_DELAY;
  }
  when = PROTIMER_UsToPrecntOverflow(params->when);
  RVar1 = GENERIC_PHY_SchedulePacketTx(when,mode_00);
  return RVar1;
}



uint8_t RFHAL_RxStart(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(RAC->.RXENSRCEN);
  if ((uVar1 & 0xff) == 0) {
    RADIO_RxBufferReset();
  }
  GENERIC_PHY_StartRx(0);
  return '\0';
}



undefined4 RFHAL_EnableRxRawCapture(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 - 1U & 0xff;
  if (uVar2 < 3) {
    param_2 = *(uint *)(&CSWTCH_104 + uVar2 * 4);
  }
  uVar1 = read_volatile_4(Peripherals::MODEM.CTRL0);
  if (2 < uVar2) {
    param_2 = 0;
  }
  write_volatile_4(Peripherals::MODEM.CTRL0,uVar1 & 0xc7ffffff | param_2);
  write_volatile_4(Peripherals::MODEM_SET.CTRL0,0x200000);
  uVar2 = read_volatile_4(Peripherals::FRC.BUFFERMODE);
  write_volatile_4(Peripherals::FRC.BUFFERMODE,uVar2 & 0xfffffff9 | 4);
  write_volatile_4(Peripherals::RAC_SET.SR3,0x10000000);
  write_volatile_4(Peripherals::FRC.RAWCTRL,4);
  return 0;
}



void RFHAL_DisableRxRawCapture(void)

{
  write_volatile_4(Peripherals::FRC_CLR.BUFFERMODE,6);
  write_volatile_4(Peripherals::FRC.RAWCTRL,0);
  write_volatile_4(Peripherals::RAC_CLR.SR3,0x10000000);
  write_volatile_4(Peripherals::MODEM_CLR.CTRL0,0x200000);
  write_volatile_4(Peripherals::MODEM_CLR.CTRL0,0x38000000);
  return;
}



void RFHAL_EnableRxAppendedInfo(void)

{
  write_volatile_4(Peripherals::FRC.TRAILRXDATA,0x1b);
  return;
}



void RFHAL_DisableRxAppendedInfo(void)

{
  write_volatile_4(Peripherals::FRC.TRAILRXDATA,0);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

uint8_t RFHAL_RxIntEnable(uint32_t cbToEnable,bool appendedInfoEnable)

{
  _enabledCallbacks =
       CONCAT11(DAT_20002f75 & 0xe3 | (byte)(((cbToEnable << 0x1e) >> 0x1f) << 2) |
                (byte)(((cbToEnable << 0x1d) >> 0x1f) << 3) |
                (byte)(((cbToEnable << 0x1c) >> 0x1f) << 4),enabledCallbacks);
  _enabledCallbacks =
       _enabledCallbacks & 0xffff0000 | _enabledCallbacks & 0xffffff00 |
       (uint)(byte)(enabledCallbacks & 0x87 | (byte)(((cbToEnable << 0x1b) >> 0x1f) << 3) |
                    (byte)(((cbToEnable << 0x1a) >> 0x1f) << 4) |
                    (byte)(((cbToEnable << 0x15) >> 0x1f) << 5) | ((cbToEnable & 0x300) != 0) << 6);
  rxConfigEvents = cbToEnable;
  GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
  return '\0';
}




uint RFHAL_SetRxOptions(uint param_1)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::RAC.STATUS);
  if ((uVar1 << 4) >> 0x1c == 3) {
    return 2;
  }
  param_1 = param_1 & 1;
  if (param_1 == 0) {
    write_volatile_4(Peripherals::FRC_CLR.RXCTRL,1);
  }
  else {
    param_1 = 0;
    write_volatile_4(Peripherals::FRC_SET.RXCTRL,1);
  }
  return param_1;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined4 RFHAL_TxIntEnable(uint param_1)

{
  _enabledCallbacks =
       CONCAT12(DAT_000113de & 0x7f | 0x40 | (byte)(((param_1 << 0x19) >> 0x1f) << 7),
                _enabledCallbacks);
  _enabledCallbacks =
       _enabledCallbacks & 0xffffff00 |
       (uint)(byte)((byte)(_enabledCallbacks >> 0x18) & 0xfe | (byte)param_1 >> 7) << 0x18 |
       (uint)(byte)(enabledCallbacks & 0xfd | ((param_1 & 0x1b) != 0) << 1);
  bufcEnabledCallbacks =
       bufcEnabledCallbacks & 0xffffff00 |
       (uint)((byte)bufcEnabledCallbacks & 0xfd | (byte)(param_1 << 1) & 2);
  txConfigEvents = param_1;
  GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
  BUFC_ConfigureCallbacks(bufcEnabledCallbacks);
  return 0;
}



undefined4 RFHAL_ErrorConfig(uint param_1)

{
  FRC_SET *pFVar1;
  
  if ((param_1 & 1) == 0) {
    pFVar1 = (FRC_SET *)&Peripherals::FRC_CLR;
  }
  else {
    pFVar1 = &Peripherals::FRC_SET;
  }
  ((FRC_CLR *)pFVar1)->RXCTRL = 2;
  return 0;
}



undefined4 RAIL_PaCtuneSet(void)

{
  PA_CTuneSet();
  return 0;
}



void RAIL_TimerGet(void)

{
  undefined4 uVar1;
  
  uVar1 = GENERIC_PHY_TimerGetTimeout();
  PROTIMER_PrecntOverflowToUs(uVar1,0);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void RAIL_TimerCancel(void)

{
  undefined4 extraout_r1;
  undefined4 in_r3;
  
  GENERIC_PHY_TimerStop();
  _enabledCallbacks = _enabledCallbacks & 0xfeffffff;
  GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks,extraout_r1,DAT_20002f77 & 0xfe,in_r3);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

byte RAIL_TimerSet(undefined4 param_1,int param_2)

{
  byte bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = param_2;
  if (param_2 != 0) {
    iVar4 = 1;
  }
  if (param_2 == 2) {
    RAIL_TimerCancel();
    return 0;
  }
  uVar2 = CORE_EnterCritical();
  _enabledCallbacks = _enabledCallbacks | 0x2000000;
  GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
  timerExpired = 0;
  uVar3 = PROTIMER_UsToPrecntOverflow(param_1);
  bVar1 = GENERIC_PHY_TimerStart(uVar3,iVar4);
  CORE_ExitCritical(uVar2);
  return bVar1 ^ 1;
}



byte RAIL_TimerExpired(void)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = GENERIC_PHY_TimerExpired();
  bVar1 = timerExpired;
  if (iVar2 != 0) {
    bVar1 = 1;
  }
  return bVar1 & 1;
}



void RAIL_TimerIsRunning(void)

{
  GENERIC_PHY_TimerIsRunning();
  return;
}



uint32_t RAIL_SymbolRateGet(void)

{
  uint uVar1;
  uint32_t uVar2;
  
  uVar2 = RADIO_ComputeTxBaudrate();
  uVar1 = read_volatile_4(MODEM->.CTRL0);
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
  
  uVar1 = read_volatile_4(MODEM->.CTRL0);
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
    uVar1 = read_volatile_4(MODEM->.CTRL0);
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
  
  local_14 = 0x8d61;
  if (enableCb == false) {
    local_14 = 0;
  }
  local_c._0_2_ = CONCAT11(1,band);
  local_c = in_r3 & 0xffff0000 | (uint)(ushort)local_c;
  local_10 = senseTime;
  uVar1 = RFSENSE_Init(&local_14);
  return uVar1;
}



bool RAIL_RfSensed(void)

{
  code *pcVar1;
  int iVar2;
  CORE_irqState_t irqState;
  uint uVar3;
  
  iVar2 = _DAT_43c81904;
  _DAT_43c81904 = 1;
  uVar3 = read_volatile_4(Peripherals::RFSENSE.IF);
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
    _DAT_43c81904 = iVar2;
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



void RFHAL_CalibrationInit(RAIL_CalMask_t calEnable)

{
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  RAIL_CalPend = 0;
  RAIL_CalEnable = calEnable;
  CORE_ExitCritical(irqState);
  return;
}


void RFHAL_CalibrationRun(int *param_1,int param_2)

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
    IRCAL_Set();
    return;
  }
  return;
}



RAIL_Status_t RFHAL_SetTxTransitions(RAIL_RadioState_t success,RAIL_RadioState_t error)

{
  ushort uVar1;
  
  uVar1 = read_volatile_2(Peripherals::SEQ.REG00C._0_2_);
  write_volatile_4(Peripherals::SEQ.REG00C,
                   1 << (success + 0x10 & 0xff) | (uint)uVar1 | 1 << (error + 0x18 & 0xff));
  return RAIL_STATUS_NO_ERROR;
}



RAIL_Status_t RFHAL_SetRxTransitions(RAIL_RadioState_t success,RAIL_RadioState_t error)

{
  ushort uVar1;
  
  uVar1 = read_volatile_2(Peripherals::SEQ.REG00C._2_2_);
  write_volatile_4(Peripherals::SEQ.REG00C,
                   1 << (error + 8 & 0xff) | 1 << success | (uint)uVar1 << 0x10);
  return RAIL_STATUS_NO_ERROR;
}



void RFHAL_SetBerConfig(RAIL_BerConfig_t *berconfig)

{
  RFTEST_ResetBerStats(berconfig->bytesToTest);
  return;
}



void RFHAL_StartBerRx(void)

{
  uint uVar1;
  
  RFTEST_SaveRadioConfiguration();
  write_volatile_4(FRC->.SNIFFCTRL,0);
  write_volatile_4(FRC->.DFLCTRL,5);
  uVar1 = read_volatile_4(MODEM->.TIMING);
  write_volatile_4(MODEM->.TIMING,uVar1 & 0xfffff0ff);
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

void RFHAL_GetBerStatus(RAIL_BerStatus_t *berstatus)

{
  uint32_t in_r1;
  uint32_t in_r2;
  int8_t in_r3;
  RAIL_BerStatus_t local_18;
  
  local_18.bitsTotal = (uint32_t)berstatus;
  local_18.bitsTested = in_r1;
  local_18.bitErrors = in_r2;
  local_18.rssi = in_r3;
  RFTEST_ReportBerStats(&local_18);
  berstatus->bitsTotal = local_18.bitsTotal;
  berstatus->bitsTested = local_18.bitsTested;
  berstatus->bitErrors = local_18.bitErrors;
  berstatus->rssi = local_18.rssi;
  return;
}




void RFHAL_SetCRCInitVal(void)

{
  RADIO_SetCRCInitVal();
  return;
}



void RFHAL_GetCurrPowerLevel(void)

{
  PA_OutputPowerGet();
  return;
}



undefined4 RFHAL_SetCurrPowerLevel(void)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar2 = PA_OutputPowerSet();
  pcVar1 = protChChngCB;
  if (protChChngCB != (code *)0x0) {
    uVar3 = RAILInt_GetChannel();
    (*pcVar1)(uVar3,1);
  }
  return uVar2;
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



undefined4 RFHAL_SetChannel(int param_1,byte *param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = RAIL_DebugModeGet();
  if (iVar2 != 1) {
    do {
      iVar2 = RFHAL_HeadedToIdle();
      if (iVar2 == 0) break;
      uVar1 = read_volatile_4(Peripherals::RAC.STATUS);
    } while ((uVar1 & 0xf000000) != 0);
    uVar1 = read_volatile_4(Peripherals::RAC.STATUS);
    if ((uVar1 & 0xf000000) != 0) {
      return 2;
    }
    if (protChChngCB != (code *)0x0) {
      (*protChChngCB)(param_1);
    }
    if (param_3 != 0) {
      SYNTH_Config(*(undefined4 *)(param_2 + 8),*(undefined4 *)(param_2 + 4));
    }
    GENERIC_PHY_ChannelSet(param_1 - (uint)*param_2 & 0xff);
  }
  return 0;
}



uint RFHAL_AutoAckEnable(void)

{
  uint uVar1;
  
  CORE_EnterCritical();
  uVar1 = read_volatile_4(Peripherals::SEQ.REG000);
  write_volatile_4(Peripherals::SEQ.REG000,uVar1 | 0x20);
  CORE_ExitCritical();
  return (uVar1 << 0x1a) >> 0x1f;
}



uint RFHAL_AutoAckDisable(void)

{
  uint uVar1;
  
  CORE_EnterCritical();
  uVar1 = read_volatile_4(Peripherals::SEQ.REG000);
  write_volatile_4(Peripherals::SEQ.REG000,uVar1 & 0xffffffdf);
  CORE_ExitCritical();
  return (uVar1 << 0x1a) >> 0x1f;
}



uint RFHAL_AutoAckIsEnabled(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::SEQ.REG000);
  return (uVar1 << 0x1a) >> 0x1f;
}



undefined4 RFHAL_AutoAckConfig(int param_1)

{
  int iVar1;
  
  iVar1 = PROTIMER_UsToPrecntOverflow(*(undefined2 *)(param_1 + 6));
  write_volatile_4(Peripherals::SEQ.REG008,-iVar1);
  return 0;
}



undefined4
RFHAL_AutoAckLoadBuffer
          (undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  RAC *pRVar4;
  undefined4 uVar5;
  
  uVar2 = CORE_EnterCritical();
  write_volatile_4(Peripherals::RAC_SET.SR0,2);
  pRVar4 = &Peripherals::RAC;
  uVar3 = read_volatile_4(Peripherals::RAC.STATUS);
  uVar3 = (uVar3 << 4) >> 0x1c;
  if (((uVar3 - 7 < 3) || (uVar3 == 0xc)) &&
     (uVar1 = read_volatile_4(Peripherals::RAC.SR0), pRVar4 = (RAC *)(uVar1 << 0xe), (int)pRVar4 < 0
     )) {
    uVar5 = 3;
  }
  else {
    BUFC_TxAckBufferSet(*param_1,*(undefined *)(param_1 + 1),uVar3,pRVar4,param_4);
    uVar5 = 0;
  }
  write_volatile_4(Peripherals::RAC_CLR.SR0,2);
  CORE_ExitCritical(uVar2);
  return uVar5;
}



void RFHAL_AutoAckRxPause(void)

{
  uint uVar1;
  
  CORE_EnterCritical();
  uVar1 = read_volatile_4(Peripherals::SEQ.REG000);
  write_volatile_4(Peripherals::SEQ.REG000,uVar1 | 8);
  CORE_ExitCritical();
  return;
}



void RFHAL_AutoAckRxResume(void)

{
  uint uVar1;
  
  CORE_EnterCritical();
  uVar1 = read_volatile_4(Peripherals::SEQ.REG000);
  write_volatile_4(Peripherals::SEQ.REG000,uVar1 & 0xfffffff7);
  CORE_ExitCritical();
  return;
}



void RFHAL_AutoAckTxPause(void)

{
  uint uVar1;
  
  CORE_EnterCritical();
  uVar1 = read_volatile_4(Peripherals::SEQ.REG000);
  write_volatile_4(Peripherals::SEQ.REG000,uVar1 | 0x100);
  CORE_ExitCritical();
  return;
}



void RFHAL_AutoAckTxResume(void)

{
  uint uVar1;
  
  CORE_EnterCritical();
  uVar1 = read_volatile_4(Peripherals::SEQ.REG000);
  write_volatile_4(Peripherals::SEQ.REG000,uVar1 & 0xfffffeff);
  CORE_ExitCritical();
  return;
}



uint RFHAL_AutoAckRxIsPaused(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::SEQ.REG000);
  return (uVar1 << 0x1c) >> 0x1f;
}



uint RFHAL_AutoAckTxIsPaused(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::SEQ.REG000);
  return (uVar1 << 0x17) >> 0x1f;
}



uint RFHAL_AutoAckUseTxBuffer(void)

{
  undefined4 uVar1;
  uint uVar2;
  bool bVar3;
  
  uVar1 = CORE_EnterCritical();
  uVar2 = GENERIC_PHY_CanModifyAck();
  if (uVar2 != 0) {
    write_volatile_4(Peripherals::RAC_SET.SR0,2);
    uVar2 = read_volatile_4(Peripherals::RAC.SR0);
    bVar3 = -1 < (int)(uVar2 << 0xe);
    if (bVar3) {
      write_volatile_4(Peripherals::RAC_SET.SR2,0x40);
    }
    uVar2 = (uint)bVar3;
    write_volatile_4(Peripherals::RAC_CLR.SR0,2);
  }
  CORE_ExitCritical(uVar1);
  return uVar2;
}



uint RFHAL_AutoAckCancelAck(void)

{
  undefined4 uVar1;
  uint uVar2;
  bool bVar3;
  
  uVar1 = CORE_EnterCritical();
  uVar2 = GENERIC_PHY_CanModifyAck();
  if (uVar2 != 0) {
    write_volatile_4(Peripherals::RAC_SET.SR0,2);
    uVar2 = read_volatile_4(Peripherals::RAC.SR0);
    bVar3 = -1 < (int)(uVar2 << 0xe);
    if (bVar3) {
      write_volatile_4(Peripherals::RAC_SET.SR2,0x20);
    }
    uVar2 = (uint)bVar3;
    write_volatile_4(Peripherals::RAC_CLR.SR0,2);
  }
  CORE_ExitCritical(uVar1);
  return uVar2;
}



void RFHAL_AutoAckWaitForAck(int param_1)

{
  RAC_SET *pRVar1;
  
  if (param_1 == 0) {
    pRVar1 = &Peripherals::RAC_SET;
  }
  else {
    pRVar1 = (RAC_SET *)&Peripherals::RAC_CLR;
  }
  ((RAC_CLR *)pRVar1)->SR0 = 0x100;
  return;
}



code * RFHAL_TxStart(undefined4 param_1,undefined *param_2,code *param_3,undefined4 param_4)

{
  int iVar1;
  
  if ((param_2 != (undefined *)0x0) && (iVar1 = RFHAL_AutoAckIsEnabled(), iVar1 != 0)) {
    RFHAL_AutoAckWaitForAck(*param_2);
  }
  if (param_3 == (code *)0x0) {
    GENERIC_PHY_PacketTx();
  }
  else {
    param_3 = (code *)(*param_3)(param_4);
    if (param_3 != (code *)0x0) {
      write_volatile_4(Peripherals::RAC_CLR.SR0,0x100);
      return param_3;
    }
  }
  return param_3;
}



uint RFHAL_AutoAckWaitingForAck(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::RAC.SR1);
  return (uVar1 << 0x1c) >> 0x1f;
}



uint RFHAL_WriteTxFifo(undefined4 param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = BUFC_GetSpaceAvailable(0);
  if (uVar1 <= param_2) {
    param_2 = BUFC_GetSpaceAvailable(0);
  }
  BUFC_WriteBuffer(0,param_1,param_2);
  return param_2;
}



uint RFHAL_ReadRxFifo(undefined4 param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = BUFC_GetBytesAvailable(1);
  if (uVar1 <= param_2) {
    param_2 = BUFC_GetBytesAvailable(1);
  }
  BUFC_ReadBuffer(1,param_1,param_2);
  return param_2;
}



void RFHAL_ReadRxFifoAppendedInfo(undefined4 *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined auStack28 [5];
  undefined local_17;
  byte local_16;
  undefined4 local_10;
  
  uVar2 = RADIO_RxTrailDataLength();
  GENERIC_PHY_PacketRxAppendedInfoHelper(uVar2,auStack28);
  read_volatile(Peripherals::FRC.IEN._0_1_);
  uVar1 = read_volatile_4(Peripherals::FRC.IF);
  *(byte *)(param_1 + 1) =
       *(byte *)(param_1 + 1) & 0xfd | (byte)((((uVar1 ^ 0x80) << 0x18) >> 0x1f) << 1);
  write_volatile_4(Peripherals::FRC.IFC,0x80);
  if (local_16 != 0) {
    local_16 = 1;
  }
  *(undefined *)((int)param_1 + 5) = local_17;
  *(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) & 0xfe | local_16 & 1;
  uVar2 = TIMING_GetRxTimestampUs(local_10);
  *param_1 = uVar2;
  *(undefined *)((int)param_1 + 7) = 0;
  return;
}



uint RFHAL_SetRxFifoThreshold(uint param_1)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::BUFC.BUF1_THRESHOLDCTRL);
  if (param_1 < 0x201) {
    param_1 = param_1 | uVar1 & 0xfffff000;
  }
  else {
    param_1 = uVar1 & 0xfffff000 | 0x200;
  }
  write_volatile_4(Peripherals::BUFC.BUF1_THRESHOLDCTRL,param_1);
  uVar1 = read_volatile_4(Peripherals::BUFC.BUF1_THRESHOLDCTRL);
  return uVar1 & 0xfff;
}



int RFHAL_GetTxFifoThreshold(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::BUFC.BUF0_THRESHOLDCTRL);
  return (uVar1 & 0xfff) + 1;
}



void RFHAL_SetTxFifoThreshold(uint param_1)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::BUFC.BUF0_THRESHOLDCTRL);
  if (0x1ff < param_1) {
    param_1 = 0x200;
  }
  write_volatile_4(Peripherals::BUFC.BUF0_THRESHOLDCTRL,uVar1 & 0xfffff000 | param_1 - 1 & 0xffff);
  RFHAL_GetTxFifoThreshold();
  return;
}



uint RFHAL_GetRxFifoThreshold(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::BUFC.BUF1_THRESHOLDCTRL);
  return uVar1 & 0xfff;
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



void RFHAL_GetTxFifoSpaceAvailable(void)

{
  BUFC_GetSpaceAvailable(0);
  return;
}



void RFHAL_GetRxFifoBytesAvailable(void)

{
  BUFC_GetBytesAvailable(1);
  return;
}



void RFHAL_ResetTxFifo(void)

{
  write_volatile_4(Peripherals::BUFC_CLR.IEN,4);
  write_volatile_4(Peripherals::BUFC.BUF0_CMD,1);
  write_volatile_4(Peripherals::BUFC_CLR.BUF0_THRESHOLDCTRL,0x2000);
  write_volatile_4(Peripherals::BUFC_SET.IEN,4);
  return;
}



void RFHAL_ResetRxFifo(void)

{
  write_volatile_4(Peripherals::BUFC_CLR.IEN,0x400);
  write_volatile_4(Peripherals::BUFC.BUF1_CMD,1);
  write_volatile_4(Peripherals::BUFC_CLR.BUF1_THRESHOLDCTRL,0x2000);
  write_volatile_4(Peripherals::BUFC_SET.IEN,0x400);
  return;
}



undefined4 RFHAL_DataConfig(int param_1)

{
  if (*(char *)(param_1 + 2) == *(char *)(param_1 + 3)) {
    if (*(char *)(param_1 + 1) == '\0') {
      RFHAL_DisableRxRawCapture();
    }
    else {
      RFHAL_EnableRxRawCapture();
    }
    if (*(char *)(param_1 + 2) == '\0') {
      bufcEnabledCallbacks =
           bufcEnabledCallbacks & 0xffffff00 | (uint)((byte)bufcEnabledCallbacks & 0xfe);
    }
    else {
      bufcEnabledCallbacks =
           bufcEnabledCallbacks & 0xffffff00 | (uint)((byte)bufcEnabledCallbacks | 1);
      RFHAL_ResetTxFifo();
    }
    if (*(char *)(param_1 + 3) == '\0') {
      bufcEnabledCallbacks =
           bufcEnabledCallbacks & 0xffffff00 | (uint)((byte)bufcEnabledCallbacks & 0xfb);
      write_volatile_4(Peripherals::FRC_SET.RXCTRL,0x60);
      write_volatile_4(Peripherals::RAC_CLR.SR0,0x40);
      write_volatile_4(Peripherals::FRC_CLR.RXCTRL,2);
    }
    else {
      bufcEnabledCallbacks = bufcEnabledCallbacks | 4;
      write_volatile_4(Peripherals::FRC_CLR.RXCTRL,0x60);
      RFHAL_ResetRxFifo();
      write_volatile_4(Peripherals::RAC_SET.SR0,0x40);
      write_volatile_4(Peripherals::FRC_SET.RXCTRL,2);
    }
    BUFC_ConfigureCallbacks(bufcEnabledCallbacks);
    return 0;
  }
  return 1;
}



uint RFHAL_SetFixedLength(uint param_1)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::FRC.DFLCTRL);
  if (((uVar1 & 7) != 0) && ((uVar1 & 7) != 5)) {
    return 0xffff;
  }
  if (param_1 == 0) {
    uVar1 = read_volatile_4(Peripherals::FRC.DFLCTRL);
    write_volatile_4(Peripherals::FRC.DFLCTRL,uVar1 & 0xfffffff8 | 5);
    return 0;
  }
  write_volatile_4(Peripherals::FRC_CLR.DFLCTRL,7);
  if (0xfff < param_1) {
    param_1 = 0x1000;
  }
  write_volatile_4(Peripherals::FRC.WCNTCMP0,param_1 - 1);
  return param_1;
}


