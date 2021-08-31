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
  
  uVar1 = read_volatile_4(RAC->SR0);
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
  
  uVar1 = read_volatile_4(RAC->STATUS);
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
    uVar3 = read_volatile_4(RAC->SR1);
    uVar7 = (uVar3 << 0x18) >> 0x1e;
    uVar8 = (0x40 << (uVar1 & 0xff)) - 1U & 0xffff;
    uVar1 = read_volatile_4(SEQ->REG004);
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
  
  uVar1 = read_volatile_4(RAC->SR0);
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
    uVar1 = read_volatile_4(SEQ->REG00C);
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

undefined4 RFHAL_Init(int param_1)

{
  int iVar1;
  
  iVar1 = SystemHFXOClockGet();
  if (iVar1 == *(int *)(param_1 + 4)) {
    GENERIC_PHY_Init();
    write_volatile_4(Peripherals::FRC.TRAILRXDATA,0x1b);
    write_volatile_4(Peripherals::FRC.RXCTRL,0x60);
    _enabledCallbacks =
         _enabledCallbacks & 0xff000000 | (uint)(uint3)((uint3)_enabledCallbacks | 7) | 0x400000;
    iVar1 = RAILINT_CalibrationEnableGet();
    if (iVar1 << 0x1f < 0) {
      _enabledCallbacks = _enabledCallbacks | 0x80000;
    }
    _enabledCallbacks = _enabledCallbacks | 0x100000;
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
  uint uVar1;
  uint uVar2;
  int unaff_r4;
  
  uVar2 = param_1 & 0xfffffff0;
  if (uVar2 == 0) {
    unaff_r4 = 0x21000f64;
    uVar1 = read_volatile_4(SEQ->REG06C);
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



//void RFHAL_IdleExt(undefined4 param_1)
void RFHAL_IdleExt(RAIL_RfIdleMode_t mode)
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
  
  uVar1 = read_volatile_4(RAC->STATUS);
  uVar1 = uVar1 & 0xf000000;
  if (uVar1 != 0x7000000) {
    if (0x7000000 < uVar1) {
      if (uVar1 != 0xa000000) {
        if (uVar1 < 0xa000001) {
          if (uVar1 == 0x8000000) {
            return 2;
          }
          bVar2 = uVar1 == 0x9000000;
        }
        else {
          if (uVar1 == 0xb000000) {
            return 2;
          }
          bVar2 = uVar1 == 0xc000000;
        }
        if (!bVar2) {
          return 0;
        }
      }
      return 2;
    }
    if (uVar1 != 0x3000000) {
      if (uVar1 < 0x3000001) {
        if (uVar1 == 0x1000000) {
          return 1;
        }
        bVar2 = uVar1 == 0x2000000;
      }
      else {
        if (uVar1 == 0x4000000) {
          return 1;
        }
        bVar2 = uVar1 == 0x5000000;
      }
      if (!bVar2) {
        return 0;
      }
    }
  }
  return 1;
}



bool RFHAL_OkToTransmit(void)

{
  return ((RAC->SR0 ^ 0x80) << 0x18) >> 0x1f;
}



int RFHAL_HeadedToIdle(void)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  bool bVar5;
  
  uVar2 = CORE_EnterCritical();
  iVar3 = PROTIMER_CCTimerIsEnabled(3);
  if ((iVar3 == 0) && (iVar3 = PROTIMER_LBTIsActive(), iVar3 == 0)) {
    uVar4 = read_volatile_4(RAC->STATUS);
    uVar1 = read_volatile_4(RAC->SR0);
    CORE_ExitCritical(uVar2);
    if ((((uVar4 & 0xc0000000) == 0) && (-1 < (int)(uVar1 << 0x18))) &&
       (uVar4 = uVar4 & 0xf000000, uVar4 != 0x6000000)) {
      if (uVar4 < 0x6000001) {
        bVar5 = uVar4 == 0x3000000;
      }
      else {
        if (uVar4 == 0x9000000) {
          return 0;
        }
        bVar5 = uVar4 == 0xc000000;
      }
      if (!bVar5) {
        iVar3 = 1;
      }
    }
  }
  else {
    CORE_ExitCritical(uVar2);
    iVar3 = 0;
  }
  return iVar3;
}



//undefined4 RFHAL_TxDataLoad(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
uint8_t RFHAL_TxDataLoad(RAIL_TxData_t *txData)
{
  undefined4 uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar1 = CORE_EnterCritical();
  uVar2 = read_volatile_4(RAC->STATUS);
  uVar2 = (uVar2 << 4) >> 0x1c;
  if (((uVar2 - 7 < 3) || (uVar2 == 0xc)) &&
     (uVar2 = read_volatile_4(RAC->SR0), (int)(uVar2 << 0xf) < 0)) {
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



undefined4 RAIL_CcaCsma(ushort *param_1,undefined4 param_2)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  byte bVar9;
  uint uVar10;
  byte bVar11;
  byte bVar12;
  byte bVar13;
  PROTIMER *pPVar14;
  uint uVar15;
  
  saveRssiPeriodPreCca = read_volatile_4(Peripherals::AGC.CTRL1);
  if (param_1 == (ushort *)0x0) {
    write_volatile_4(Peripherals::AGC_CLR.CTRL1,0xffffff00);
    write_volatile_4(Peripherals::AGC_SET.CTRL1,saveRssiPeriodInCca & 0xffffff00);
    PROTIMER_LBTUseLastConfig();
  }
  else {
    RADIO_SetAgcCcaParams
              (param_1[3],(int)*(char *)((int)param_1 + 3),saveRssiPeriodPreCca,
               &saveRssiPeriodPreCca,param_1,param_2);
    saveRssiPeriodInCca = read_volatile_4(Peripherals::AGC.CTRL1);
    bVar13 = *(byte *)(param_1 + 1);
    bVar1 = *(byte *)param_1;
    bVar12 = *(byte *)((int)param_1 + 1);
    bVar11 = bVar13;
    bVar9 = bVar13;
    if (bVar13 != 0) {
      bVar9 = bVar13 - 1;
      bVar13 = bVar1;
      if (bVar12 < bVar1) {
        bVar12 = bVar1;
        bVar11 = 1;
      }
      else {
        bVar11 = 1;
      }
    }
    uVar10 = count_leading_zeroes((uint)*param_1);
    pPVar14 = (PROTIMER *)0x10683;
    uVar2 = PROTIMER_UsToPrecntOverflow(param_1[2]);
    uVar3 = (uint)uVar2;
    if (uVar10 >> 5 == 0) {
      uVar7 = (uint)reseedRandom_8945;
      if (uVar7 != 0xf804) {
        pPVar14 = &Peripherals::PROTIMER;
      }
      if (uVar7 != 0xf804) {
        pPVar14->RANDOM = uVar7;
        reseedRandom_8945 = 0xf804;
      }
    }
    else {
      uVar8 = 0;
      uVar7 = uVar3;
      while( true ) {
        uVar15 = uVar8 & 0xff;
        uVar8 = uVar8 + 1;
        if (uVar7 < 0x100) break;
        uVar7 = uVar7 >> 1;
      }
      if ((uVar15 != 0) && (uVar7 != 0xff)) {
        uVar7 = (uint)(ushort)(((ushort)((int)uVar3 >> (uVar15 - 1 & 0xff)) & 1) + (short)uVar7);
      }
      uVar3 = uVar7;
      uVar7 = read_volatile_4(Peripherals::PROTIMER.RANDOM);
      reseedRandom_8945 = (ushort)(uVar7 & 0xffff);
      if ((uVar7 & 0xffff) == 0xf804) {
        reseedRandom_8945 = 0xf805;
      }
      write_volatile_4(Peripherals::PROTIMER.RANDOM,(1 << uVar15) - 1);
      bVar12 = 8;
      write_volatile_4(Peripherals::PROTIMER.LBTSTATE,0x800000);
      bVar13 = 8;
    }
    if (uVar3 < 0x100) {
      uVar3 = uVar3 - 1;
    }
    else {
      uVar3 = 0xff;
    }
    write_volatile_4(Peripherals::PROTIMER.BASECNTTOP,uVar3);
    PROTIMER_LBTCfgSet(bVar13,bVar12,bVar11,bVar9,0);
    if (uVar10 >> 5 != 0) {
      write_volatile_4(Peripherals::PROTIMER_SET.LBTCTRL,0x100000);
      uVar3 = read_volatile_4(Peripherals::PROTIMER.CTRL);
      write_volatile_4(Peripherals::PROTIMER.CTRL,uVar3 & 0xff3fffff | 0x400000);
    }
    lbtTimeout_8944 = *(int *)(param_1 + 4);
  }
  GENERIC_PHY_PacketTxCommon();
  iVar6 = lbtTimeout_8944;
  if (lbtTimeout_8944 != 0) {
    iVar4 = PROTIMER_CCTimerIsEnabled(4);
    if (iVar4 != 0) {
      PROTIMER_CCTimerStop(4);
    }
    uVar5 = PROTIMER_UsToPrecntOverflow(iVar6);
    iVar6 = PROTIMER_CCTimerStart(4,uVar5,1);
    if (iVar6 == 0) {
      return 1;
    }
  }
  PROTIMER_LBTStart();
  return 0;
}



// WARNING: Could not reconcile some variable overlaps

void RAIL_CcaLbt(uint *param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  byte bVar2;
  undefined4 local_14;
  undefined4 local_10;
  uint uStack12;
  
  local_14 = param_2;
  local_10 = param_3;
  uStack12 = param_4;
  if ((param_1 != (uint *)0x0) && (*(short *)param_1 != 0)) {
    local_14 = *param_1;
    local_10._2_2_ = (ushort)(param_1[1] >> 0x10);
    uStack12 = param_1[2];
    bVar2 = *(byte *)param_1;
    if (bVar2 != 0) {
      local_10._2_2_ = *(short *)(param_1 + 1) * (ushort)bVar2 + local_10._2_2_;
      local_14._1_1_ = (char)(local_14 >> 8);
      local_14._2_2_ = (undefined2)(local_14 >> 0x10);
      local_14 = (uint)CONCAT21(local_14._2_2_,local_14._1_1_ - bVar2) << 8;
    }
    uVar1 = local_14 >> 8 & 0xff;
    for (bVar2 = 1; (uint)(1 << (uint)bVar2) < uVar1; bVar2 = bVar2 + 1) {
    }
    local_10 = uVar1 * *(ushort *)(param_1 + 1) + ((uint)(1 << (uint)bVar2) >> 1) >> (uint)bVar2 &
               0xffff | (uint)local_10._2_2_ << 0x10;
    local_14._0_2_ = CONCAT11(bVar2,bVar2);
    local_14 = local_14 & 0xffff0000 | (uint)(ushort)local_14;
    param_1 = &local_14;
  }
  RAIL_CcaCsma(param_1);
  return;
}



void RFHAL_SetCcaThreshold(void)

{
  RADIO_AGCCCAThresholdSet();
  return;
}



int RFHAL_PollAverageRSSI(int param_1)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  bool bVar10;
  
  if (param_1 == 0) {
    iVar2 = RADIO_GetRSSI();
    return iVar2;
  }
  uVar3 = PROTIMER_GetTime();
  uVar4 = PROTIMER_UsToPrecntOverflow(param_1);
  iVar2 = 0;
  uVar8 = 0;
  iVar9 = 0;
  while( true ) {
    uVar5 = PROTIMER_GetTime();
    uVar6 = PROTIMER_ElapsedTime(uVar3,uVar5);
    if (uVar4 <= uVar6) break;
    iVar7 = RADIO_GetRSSI();
    if (iVar7 != -0x200) {
      uVar6 = SEXT24((short)iVar7);
      bVar10 = CARRY4(uVar8,uVar6);
      uVar8 = uVar8 + uVar6;
      iVar9 = iVar9 + ((int)uVar6 >> 0x1f) + (uint)bVar10;
      iVar2 = iVar2 + 1;
    }
  }
  if (iVar2 == 0) {
    sVar1 = -0x200;
  }
  else {
    sVar1 = __aeabi_ldivmod(uVar8,iVar9,iVar2,iVar2 >> 0x1f);
  }
  return (int)sVar1;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

int RFHAL_StartAverageRSSI(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  isRssiReady = 0;
  saveRssiPeriod = read_volatile_4(Peripherals::AGC.CTRL1);
  iVar1 = RADIO_CalcRssiPeriod(param_2);
  if (iVar1 == 0) {
    iVar2 = _DAT_430c0354;
    if (_DAT_430c0354 != 0) {
      iVar2 = 1;
    }
    saveFrameDetDisable = (undefined)iVar2;
    write_volatile_4(Peripherals::MODEM_SET.CTRL0,0x200000);
    iVar2 = RAIL_RxStart(param_1);
    if (iVar2 == 0) {
      _enabledCallbacks = _enabledCallbacks | 0x4000000;
      GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
    }
    else {
      iVar1 = 2;
    }
  }
  else {
    iVar1 = 1;
  }
  return iVar1;
}



int RFHAL_GetAverageRSSI(void)

{
  return (int)currentRssiAverage;
}



undefined RFHAL_AverageRSSIReady(void)

{
  return isRssiReady;
}



//void RFHAL_ScheduleRx(undefined4 param_1,undefined4 *param_2)
uint8_t RFHAL_ScheduleRx(uint8_t channel, RAIL_ScheduleRxConfig_t *cfg)
{
  undefined4 uVar1;
  undefined4 uVar2;
  char cVar3;
  uint uVar4;
  char cVar5;
  char cVar6;
  
  cVar6 = *(char *)(param_2 + 1);
  if (cVar6 == '\x02') {
    uVar1 = 0;
  }
  else {
    uVar1 = PROTIMER_UsToPrecntOverflow(*param_2);
    cVar6 = *(char *)(param_2 + 1);
    if (cVar6 != '\0') {
      cVar6 = '\x01';
    }
  }
  cVar5 = *(char *)(param_2 + 3);
  if (cVar5 == '\x02') {
    uVar2 = 0;
  }
  else {
    uVar2 = PROTIMER_UsToPrecntOverflow(param_2[2]);
    cVar5 = *(char *)(param_2 + 3);
    if (cVar5 != '\0') {
      cVar5 = '\x01';
    }
  }
  uVar4 = count_leading_zeroes((uint)*(byte *)((int)param_2 + 0xd));
  cVar3 = *(char *)((int)param_2 + 0xe);
  if (cVar3 != '\0') {
    cVar3 = '\x01';
  }
  GENERIC_PHY_SchedulePacketRx(uVar1,cVar6,uVar2,cVar5,uVar4 >> 5,cVar3);
  return;
}



void RAIL_ScheduleTx(undefined4 *param_1)

{
  undefined4 uVar1;
  char cVar2;
  
  cVar2 = *(char *)(param_1 + 1);
  if (cVar2 != '\0') {
    cVar2 = '\x01';
  }
  uVar1 = PROTIMER_UsToPrecntOverflow(*param_1);
  GENERIC_PHY_SchedulePacketTx(uVar1,cVar2);
  return;
}



//undefined4 RFHAL_RxStart(void)
uint8_t RFHAL_RxStart(uint8_t channel)
{
  uint uVar1;
  
  uVar1 = read_volatile_4(RAC->RXENSRCEN);
  if ((uVar1 & 0xff) == 0) 
  {
    BUFC_RxBufferReset();
  }
  GENERIC_PHY_StartRx(channel);
  return 0;
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

//undefined4 RFHAL_RxIntEnable(uint param_1)
uint32_t RFHAL_RxIntEnable(uint32_t cbToEnable);
{
  _enabledCallbacks =
       CONCAT11(DAT_000113b1 & 0xc5 | (byte)(((cbToEnable << 0x1e) >> 0x1f) << 3) |
                (byte)(((cbToEnable << 0x1d) >> 0x1f) << 4) | (byte)(((cbToEnable << 0x1c) >> 0x1f) << 5)
                | (byte)(((cbToEnable << 0x14) >> 0x1f) << 1),
                enabledCallbacks & 0x87 | (byte)(((cbToEnable << 0x1b) >> 0x1f) << 3) |
                (byte)(((cbToEnable << 0x1a) >> 0x1f) << 4) | (byte)(((cbToEnable << 0x15) >> 0x1f) << 5)
                | ((cbToEnable & 0x300) != 0) << 6);
  _enabledCallbacks = _enabledCallbacks & 0xffff0000 | (uint)_enabledCallbacks;
  bufcEnabledCallbacks =
       bufcEnabledCallbacks & 0xffffff00 |
       (uint)((byte)bufcEnabledCallbacks & 0xf7 | (byte)(cbToEnable << 3) & 8);
  rxConfigEvents = cbToEnable;
  GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
  BUFC_ConfigureCallbacks(bufcEnabledCallbacks);
  return 0;
}



//uint RFHAL_SetRxOptions(uint param_1)
RAIL_Status_t RFHAL_SetRxOptions(uint32_t options)
{
  uint uVar1;
  
  uVar1 = read_volatile_4(RAC->STATUS);
  if ((uVar1 << 4) >> 0x1c == 3) 
  {
    return 2;
  }
  param_1 = param_1 & 1;
  if (param_1 == 0) 
  {
    write_volatile_4(Peripherals::FRC_CLR.RXCTRL,1);
  }
  else 
  {
    param_1 = 0;
    write_volatile_4(Peripherals::FRC_SET.RXCTRL,1);
  }
  return param_1;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

//undefined4 RFHAL_TxIntEnable(uint param_1)
uint32_t RFHAL_TxIntEnable(uint32_t cbToEnable)
{
  _enabledCallbacks =
       CONCAT12(DAT_000113b2 & 0x7f | 0x40 | (byte)(((cbToEnable << 0x19) >> 0x1f) << 7),
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
  return 0;
}



//undefined4 RFHAL_ErrorConfig(uint param_1)
RAIL_Status_t RFHAL_ErrorConfig(uint8_t ignoreErrors)
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
  _enabledCallbacks = _enabledCallbacks & 0xfdffffff;
  GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks,extraout_r1,DAT_000113b3 & 0xfd,in_r3);
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



void RAIL_SymbolRateGet(void)

{
  RADIO_ComputeTxSymbolRate();
  return;
}



void RAIL_BitRateGet(void)

{
  RADIO_ComputeTxBitRate();
  return;
}



// WARNING: Could not reconcile some variable overlaps

void RAIL_RfSense(undefined param_1,undefined4 param_2,int param_3,uint param_4)

{
  code *local_14;
  undefined4 local_10;
  uint local_c;
  
  local_14 = RAIL_RFSENSE_Callback;
  if (param_3 == 0) {
    local_14 = (code *)0x0;
  }
  local_c._0_2_ = CONCAT11(1,param_1);
  local_c = param_4 & 0xffff0000 | (uint)(ushort)local_c;
  local_10 = param_2;
  RFSENSE_Init(&local_14);
  return;
}



void RAIL_RfSensed(void)

{
  RFSENSE_Sensed();
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void RAIL_DebugCbConfig(int param_1)

{
  _enabledCallbacks =
       CONCAT11(DAT_000113b1 & 0x7f | (byte)(((uint)(param_1 << 0x1e) >> 0x1f) << 7),
                enabledCallbacks);
  _enabledCallbacks = _enabledCallbacks & 0xffff0000 | (uint)_enabledCallbacks;
  GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
  return;
}



void RFHAL_CalibrationInit(int param_1)

{
  IRCAL_Init(*(undefined4 *)(param_1 + 4));
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



//undefined4 RFHAL_SetTxTransitions(int param_1,int param_2)
RAIL_Status_t RFHAL_SetTxTransitions(RAIL_RadioState_t success,RAIL_RadioState_t error);
{
  ushort uVar1;
  
  uVar1 = read_volatile_2(SEQ->REG00C._0_2_);
  write_volatile_4(SEQ->REG00C,
                   1 << (param_1 + 0x10U & 0xff) | (uint)uVar1 | 1 << (param_2 + 0x18U & 0xff));
  return 0;
}



undefined4 RFHAL_SetRxTransitions(uint param_1,int param_2)
RAIL_Status_t RFHAL_SetRxTransitions(RAIL_RadioState_t success,RAIL_RadioState_t error);
{
  ushort uVar1;
  
  uVar1 = read_volatile_2(SEQ->REG00C._2_2_);
  write_volatile_4(SEQ->REG00C,
                   1 << (param_2 + 8U & 0xff) | 1 << (param_1 & 0xff) | (uint)uVar1 << 0x10);
  return 0;
}



//void RFHAL_SetBerConfig(undefined4 *param_1)
void RFHAL_SetBerConfig(RAIL_BerConfig_t *berConfig);
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
  PTR_rxFifoAlmostFull_00011398 = &RFTEST_BerEmptyBufcAndUpdateStats;
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
  //bufcEnabledCallbacks = bufcEnabledCallbacks & 0xffffff00 | (uint)((byte)bufcEnabledCallbacks & 0xfb);
  bufcEnabledCallbacks &= 0xffffff00;
  bufcEnabledCallbacks |= (uint)((byte)bufcEnabledCallbacks & 0xfb);
  BUFC_ConfigureCallbacks(bufcEnabledCallbacks);
  BUS_RegMaskedClear(&BUFC->IEN,0x400);
  RFTEST_RestoreRadioConfiguration();
}



// WARNING: Could not reconcile some variable overlaps

//void RFHAL_GetBerStatus(int *param_1,int param_2,int param_3,undefined4 param_4)
void RFHAL_GetBerStatus(RAIL_BerStatus_t *status)
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



void RFHAL_SetCRCInitVal(uint16_t val)

{
  RADIO_SetCRCInitVal(val);
}



int32_t RFHAL_GetCurrPowerLevel(void)

{
  return PA_OutputPowerGet();
}



//undefined4 RFHAL_SetCurrPowerLevel(void)
int32_t RFHAL_SetCurrPowerLevel(int32_t powerLevel)
{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar2 = PA_OutputPowerSet(powerLevel);
  pcVar1 = protChChngCB;
  if (protChChngCB != (code *)0x0) 
  {
    uVar3 = RAILInt_GetChannel();
    (*pcVar1)(uVar3,1);
  }
  return uVar2;
}



void RFHAL_SetProtocolSpecificChCheckCB(undefined4 param_1)

{
  protChChngCB = param_1;
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



undefined4 RFHAL_SetChannel(int param_1,byte *param_2,int param_3)

{
  if (RAIL_DebugModeGet() != 1) 
  {
    do 
	{
      if (RFHAL_HeadedToIdle() == 0) break;
    } while ((RAC->STATUS & 0xf000000) != 0);
    if ((RAC->STATUS & 0xf000000) != 0) return 2;
    if (protChChngCB != (code *)0x0) (*protChChngCB)(param_1);
    if (param_3 != 0) SYNTH_Config(*(undefined4 *)(param_2 + 8),*(undefined4 *)(param_2 + 4));
    GENERIC_PHY_ChannelSet(param_1 - (uint)*param_2 & 0xff);
  }
  return 0;
}



uint32_t RFHAL_AutoAckEnable(void)

{
  uint uVar1;
  uint uVar2;
  uVar1 = CORE_EnterCritical();
  uVar2 = SEQ->REG000;
  SEQ->REG000 |= 0x20;
  CORE_ExitCritical(uVar1);
  return (uVar2 << 0x1a) >> 0x1f;
}



uint RFHAL_AutoAckDisable(void)

{
  uint uVar1;
  
  CORE_EnterCritical();
  uVar1 = read_volatile_4(SEQ->REG000);
  write_volatile_4(SEQ->REG000,uVar1 & 0xffffffdf);
  CORE_ExitCritical();
  return (uVar1 << 0x1a) >> 0x1f;
}



bool RFHAL_AutoAckIsEnabled(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(SEQ->REG000);
  return (uVar1 << 0x1a) >> 0x1f;
}



//undefined4 RFHAL_AutoAckConfig(int param_1)
void RFHAL_AutoAckConfig(RAIL_AutoAckConfig_t *config)
{
  int iVar1;
  
  iVar1 = PROTIMER_UsToPrecntOverflow(*(undefined2 *)(param_1 + 6));
  write_volatile_4(SEQ->REG008,-iVar1);
}



//undefined4 RFHAL_AutoAckLoadBuffer(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
RAIL_Status_t RFHAL_AutoAckLoadBuffer(RAIL_AutoAckData_t *ackData)
{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  RAC *pRVar4;
  undefined4 uVar5;
  
  uVar2 = CORE_EnterCritical();
  write_volatile_4(Peripherals::RAC_SET.SR0,2);
  pRVar4 = &Peripherals::RAC;
  uVar3 = read_volatile_4(RAC->STATUS);
  uVar3 = (uVar3 << 4) >> 0x1c;
  if (((uVar3 - 7 < 3) || (uVar3 == 0xc)) &&
     (uVar1 = read_volatile_4(RAC->SR0), pRVar4 = (RAC *)(uVar1 << 0xe), (int)pRVar4 < 0
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
  uVar1 = read_volatile_4(SEQ->REG000);
  write_volatile_4(SEQ->REG000,uVar1 | 8);
  CORE_ExitCritical();
  return;
}



void RFHAL_AutoAckRxResume(void)

{
  uint uVar1;
  
  CORE_EnterCritical();
  uVar1 = read_volatile_4(SEQ->REG000);
  write_volatile_4(SEQ->REG000,uVar1 & 0xfffffff7);
  CORE_ExitCritical();
  return;
}



void RFHAL_AutoAckTxPause(void)

{
  uint uVar1;
  
  CORE_EnterCritical();
  uVar1 = read_volatile_4(SEQ->REG000);
  write_volatile_4(SEQ->REG000,uVar1 | 0x100);
  CORE_ExitCritical();
  return;
}



void RFHAL_AutoAckTxResume(void)

{
  uint uVar1;
  
  CORE_EnterCritical();
  uVar1 = read_volatile_4(SEQ->REG000);
  write_volatile_4(SEQ->REG000,uVar1 & 0xfffffeff);
  CORE_ExitCritical();
  return;
}



bool RFHAL_AutoAckRxIsPaused(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(SEQ->REG000);
  return (uVar1 << 0x1c) >> 0x1f;
}



bool RFHAL_AutoAckTxIsPaused(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(SEQ->REG000);
  return (uVar1 << 0x17) >> 0x1f;
}



bool RFHAL_AutoAckUseTxBuffer(void)

{
  undefined4 uVar1;
  uint uVar2;
  bool bVar3;
  
  uVar1 = CORE_EnterCritical();
  uVar2 = GENERIC_PHY_CanModifyAck();
  if (uVar2 != 0) {
    write_volatile_4(Peripherals::RAC_SET.SR0,2);
    uVar2 = read_volatile_4(RAC->SR0);
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



bool RFHAL_AutoAckCancelAck(void)

{
  undefined4 uVar1;
  uint uVar2;
  bool bVar3;
  
  uVar1 = CORE_EnterCritical();
  uVar2 = GENERIC_PHY_CanModifyAck();
  if (uVar2 != 0) {
    write_volatile_4(Peripherals::RAC_SET.SR0,2);
    uVar2 = read_volatile_4(RAC->SR0);
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
//uint8_t RAIL_TxStartWithOptions(uint8_t channel,RAIL_TxOptions_t *options,RAIL_PreTxOp_t preTxOp,void *preTxOpParams);

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



bool RFHAL_AutoAckWaitingForAck(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(RAC->SR1);
  return (uVar1 << 0x1c) >> 0x1f;
}



//uint RFHAL_WriteTxFifo(undefined4 param_1,uint param_2)
uint16_t RFHAL_WriteTxFifo(uint8_t *dataPtr, uint16_t writeLength)
{
  uint uVar1;
  
  uVar1 = BUFC_GetSpaceAvailable(0);
  if (uVar1 <= param_2) {
    param_2 = BUFC_GetSpaceAvailable(0);
  }
  BUFC_WriteBuffer(0,param_1,param_2);
  return param_2;
}



//uint RFHAL_ReadRxFifo(undefined4 param_1,uint param_2)
uint16_t RFHAL_ReadRxFifo(uint8_t *dataPtr, uint16_t readLength)
{
  uint uVar1;
  
  uVar1 = BUFC_GetBytesAvailable(1);
  if (uVar1 <= param_2) {
    param_2 = BUFC_GetBytesAvailable(1);
  }
  BUFC_ReadBuffer(1,param_1,param_2);
  return param_2;
}



//void RFHAL_ReadRxFifoAppendedInfo(undefined4 *param_1)
void RFHAL_ReadRxFifoAppendedInfo(RAIL_AppendedInfo_t *appendedInfo)
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



//uint RFHAL_SetRxFifoThreshold(uint param_1)
uint16_t RFHAL_SetRxFifoThreshold(uint16_t rxThreshold)
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



uint16_t RFHAL_GetTxFifoThreshold(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::BUFC.BUF0_THRESHOLDCTRL);
  return (uVar1 & 0xfff) + 1;
}



//void RFHAL_SetTxFifoThreshold(uint param_1)
uint16_t RFHAL_SetTxFifoThreshold(uint16_t txThreshold)
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



uint16_t RFHAL_GetRxFifoThreshold(void)

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
}



//undefined4 RFHAL_DataConfig(int param_1)
RAIL_Status_t RFHAL_DataConfig(RAIL_DataConfig_t *dataConfig)
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
uint16_t RAIL_SetFixedLength(uint16_t length)
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


