#include "rail_rf_hal.h"



void eventDefault(void)

{
  return;
}



void radioConfigChangedDefault(void)

{
  return;
}



void setRssiPeriod(uint32_t param_1)

{
  if (param_1 != 0) {
    BUS_RegMaskedClear(&AGC->CTRL1,0xffffff00);
    BUS_RegMaskedSet(&AGC->CTRL1,param_1 & 0xffffff00);
  }
  return;
}



void callRailGenericCb_isra_1(uint32_t *param_1,undefined4 param_2,uint32_t param_3,uint32_t param_4)

{
  RAILInt_GetActiveConfig();
  if ((*param_1 & param_3 | param_1[1] & param_4) != 0) {
                    // WARNING: Could not recover jumptable at 0x0001003e. Too many branches
                    // WARNING: Treating indirect jump as call
    (*(code *)eventCb)();
    return;
  }
  return;
}



void RFHAL_NotifyUserOfIrCal(uint8_t *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  if ((-1 < (int)((uint32_t)*param_1 << 0x1e)) || (*(int *)(param_1 + 0x24) == 0)) {
    return;
  }
  *param_1 = *param_1 & 0xfd;
  piVar1 = (int *)(SEQ->PHYINFO);
  if ((piVar1 != (int *)0x0) && (*piVar1 != 0)) {
    IRCAL_Init(piVar1[3]);
  }
  if (**(int **)(*(int *)(param_1 + 0x24) + 0x14) != -1) {
    IRCAL_Set();
    return;
  }
  if ((*(uint32_t *)(param_1 + 0x4c) & 2) == 0) {
    *param_1 = *param_1 | 2;
    return;
  }
  uVar3 = RAILInt_PendCal(param_1,0x10000);
  uVar2 = (undefined4)((ulonglong)uVar3 >> 0x20);
  callRailGenericCb_isra_1(param_1 + 0x48,uVar2,(int)uVar3,uVar2);
  return;
}



void RFHAL_SetRadioConfigChangedCallback(undefined4 param_1,code *param_2)

{
  if (param_2 == NULL) {
    param_2 = radioConfigChangedDefault;
  }
  radioConfigChangedCb = param_2;
  return;
}



void RFHAL_IssueRadioConfigChangedCallback(undefined4 param_1)

{
  undefined *UNRECOVERED_JUMPTABLE;
  undefined4 uVar1;
  
  UNRECOVERED_JUMPTABLE = radioConfigChangedCb;
  uVar1 = RAILInt_GetActiveConfig();
                    // WARNING: Could not recover jumptable at 0x000100e4. Too many branches
                    // WARNING: Treating indirect jump as call
  (*(code *)UNRECOVERED_JUMPTABLE)(uVar1,param_1);
  return;
}



void GENERIC_PHY_EventCallback(uint32_t param_1,uint32_t param_2,int param_3)

{
  MODEM_SET *pMVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined2 uVar2;
  int iVar3;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  uint32_t uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  uint32_t uVar8;
  uint32_t uVar9;
  int iVar10;
  
  uVar8 = param_1;
  uVar9 = param_2;
  iVar10 = param_3;
  uVar5 = RAILInt_GetActiveConfig();
  uVar4 = (uint32_t)(uVar5 >> 0x20);
  uVar6 = uVar5 & 0xffffffff00000000 | (ulonglong)lastTxPacketTimeTicks;
  iVar3 = (int)uVar5;
  if ((param_2 & 2 | param_1 & 0xc0c0001) == 0) {
LAB_000101e8:
    uVar6 = CONCAT44(uVar4,lastTxPacketTimeTicks);
    if ((param_1 | param_2) == 0) goto LAB_00010218;
  }
  else {
    if ((param_1 & 0x40000) != 0) {
      uVar6 = GENERIC_PHY_PreviousTxTime();
    }
    lastTxPacketTimeTicks = (uint32_t)uVar6;
    if ((param_1 & 0x80000) != 0) {
      uVar5 = GENERIC_PHY_PreviousTxTime();
      uVar6 = uVar5 & 0xffffffff00000000 | (ulonglong)lastTxPacketTimeTicks;
      lastTxAckPacketTimeTicks = (undefined4)uVar5;
    }
    lastTxPacketTimeTicks = (uint32_t)uVar6;
    if (((param_1 & 0x8000000) != 0) &&
       (uVar4 = (SEQ->REG024), (uVar4 & 0xff000000) == 0x2000000)) {
      BUS_RegMaskedSet(&RAC->RXENSRCEN,2);
    }
    if ((param_1 & 0xc000000) != 0) {
      setRssiPeriod(saveRssiPeriodPreCca);
      uVar6 = CONCAT44(extraout_r1,lastTxPacketTimeTicks);
      saveRssiPeriodPreCca = 0;
    }
    lastTxPacketTimeTicks = (uint32_t)uVar6;
    if ((param_1 & 1) != 0) {
      uVar8 = 0;
      uVar9 = 0;
      GENERIC_PHY_ConfigureEvents(1,0,0,0,0,0,iVar10);
      uVar2 = RADIO_GetRssi(1);
      *(undefined2 *)(iVar3 + 0x12) = uVar2;
      RAILCore_Idle(1,0);
      if (saveFrameDetDisable == '\0') {
        pMVar1 = (MODEM_SET *)&Peripherals::MODEM_CLR;
      }
      else {
        pMVar1 = &Peripherals::MODEM_SET;
      }
      ((MODEM_CLR *)pMVar1)->CTRL0 = 0x200000;
      setRssiPeriod(saveRssiPeriod);
      saveRssiPeriod = 0;
      *(uint8_t *)(iVar3 + 0xc) = *(uint8_t *)(iVar3 + 0xc) | 8;
      uVar6 = CONCAT44(extraout_r1_00,lastTxPacketTimeTicks);
    }
    lastTxPacketTimeTicks = (uint32_t)uVar6;
    if ((param_2 & 2) != 0) {
      uVar7 = RAILInt_PendCal(iVar3 + 0xc,1);
      uVar4 = (uint32_t)((ulonglong)uVar7 >> 0x20);
      param_1 = param_1 | (uint32_t)uVar7;
      param_2 = param_2 & 0xfffffffd | uVar4;
      goto LAB_000101e8;
    }
  }
  lastTxPacketTimeTicks = (uint32_t)uVar6;
  callRailGenericCb_isra_1(iVar3 + 0x54,(int)(uVar6 >> 0x20),param_1,param_2,uVar8,uVar9);
  lastTxPacketTimeTicks = 0xffffffff;
  lastTxAckPacketTimeTicks = 0xffffffff;
  if ((param_1 & 8) != 0) {
    cachedPacketHandle = 0;
  }
LAB_00010218:
  UNRECOVERED_JUMPTABLE = timerExpiredCb;
  if (param_3 << 0x1d < 0) {
    timerExpiredCb = NULL;
    timerExpired = 1;
    if (UNRECOVERED_JUMPTABLE != NULL) {
                    // WARNING: Could not recover jumptable at 0x00010236. Too many branches
                    // WARNING: Treating indirect jump as call
      (*UNRECOVERED_JUMPTABLE)(timerExpiredCbArg);
      return;
    }
  }
  return;
}



undefined4 RFHAL_IEEE802154GetAddress(uint16_t *param_1)

{
  uint8_t bVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  int iVar7;
  int iVar8;
  
  if (param_1 == NULL) {
    return 1;
  }
  uVar3 = (BUFC->BUF1_ADDR);
  uVar2 = (BUFC->BUF1_CTRL);
  uVar4 = (RAC->SR1);
  uVar5 = (uVar4 << 0x18) >> 0x1e;
  uVar6 = (0x40 << (uVar2 & 0xff)) - 1U & 0xffff;
  iVar7 = uVar3 + 0x20000000;
  uVar2 = (SEQ->REG018);
  if (uVar5 == 3) {
    iVar8 = 0;
    do {
      *(undefined *)((int)param_1 + iVar8) =
           *(undefined *)(iVar7 + (((uVar2 & 0xffff) - 8) + iVar8 & uVar6));
      iVar8 = iVar8 + 1;
    } while (iVar8 != 8);
  }
  else {
    if (uVar5 != 2) {
      return 2;
    }
    bVar1 = *(uint8_t *)(iVar7 + ((uVar2 & 0xffff) - 2 & uVar6));
    *param_1 = (uint16_t)bVar1;
    *param_1 = CONCAT11(*(undefined *)(iVar7 + ((uVar2 & 0xffff) - 1 & uVar6)),bVar1);
  }
  *(uint8_t *)(param_1 + 4) = (uint8_t)uVar4 >> 6;
  return 0;
}



undefined4 RFHAL_GetTxPacketDetails(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  
  if (param_2 == 0) {
    return 1;
  }
  if (*(char *)(param_2 + 0xc) == '\0') {
    piVar1 = &lastTxPacketTimeTicks;
  }
  else {
    piVar1 = &lastTxAckPacketTimeTicks;
  }
  iVar2 = *piVar1 + 1;
  if (iVar2 != 0) {
    TIMING_CalcTxTimeStampUs(param_1 + 0x28,*piVar1,param_2,iVar2,param_4);
    return 0;
  }
  return 2;
}



undefined4
RFHAL_IntEnable(int param_1,undefined4 param_2,uint32_t param_3,uint32_t param_4,uint32_t param_5,uint32_t param_6)

{
  *(uint32_t *)(param_1 + 0x48) = *(uint32_t *)(param_1 + 0x48) & ~param_3 | param_3 & param_5;
  *(uint32_t *)(param_1 + 0x4c) = *(uint32_t *)(param_1 + 0x4c) & ~param_4 | param_4 & param_6;
  GENERIC_PHY_ConfigureEvents
            (param_3 & 0xfffffffe,param_4,param_3 & 0xfffffffe & param_5 | 0xc000000,
             param_4 & param_6 | 2,0,0);
  RFHAL_NotifyUserOfIrCal(param_1);
  return 0;
}



undefined8 RFHAL_GetEvents(int param_1)

{
  return *(undefined8 *)(param_1 + 0x48);
}



void RFHAL_SetActiveState(void)

{
  return;
}



void RFHAL_SetCallbackConfig(code **param_1)

{
  code *pcVar1;
  code *pcVar2;
  
  pcVar1 = *param_1;
  if (pcVar1 == NULL) {
    pcVar1 = eventDefault;
  }
  pcVar2 = param_1[9];
  if (pcVar2 == NULL) {
    pcVar2 = radioConfigChangedDefault;
  }
  eventCb = pcVar1;
  radioConfigChangedCb = pcVar2;
  return;
}



uint32_t RFHAL_PeekRxPacket(uint32_t param_1,uint32_t param_2,uint32_t param_3,int param_4)

{
  uint16_t uVar1;
  uint32_t uVar2;
  uint16_t local_2a;
  undefined auStack40 [2];
  uint16_t local_26;
  
  uVar2 = param_2;
  if (((param_2 != 0) && (uVar2 = param_3, param_3 != 0)) && (uVar2 = param_1, param_1 != 0)) {
    CORE_EnterCritical();
    uVar1 = cachedPacketBytes;
    if (param_1 == cachedPacketHandle) {
      local_2a = cachedPacketStartOffset;
      CORE_ExitCritical();
      local_26 = uVar1;
    }
    else {
      CORE_ExitCritical();
      uVar2 = BUFC_GetRxPacketInfo(param_1,auStack40,&local_2a);
      if (uVar2 == 0) {
        return 0;
      }
      CORE_EnterCritical();
      cachedPacketStartOffset = local_2a;
      cachedPacketBytes = local_26;
      cachedPacketHandle = uVar2;
      CORE_ExitCritical();
    }
    if ((int)(uint32_t)local_26 < (int)(param_4 + param_3)) {
      param_3 = (uint32_t)(uint16_t)(local_26 - (int16_t)param_4);
    }
    uVar2 = BUFC_Peek(1,param_2,param_3,(uint32_t)local_2a + param_4 & 0xffff);
  }
  return uVar2;
}



uint32_t RFHAL_GetPtiProtocol(void)

{
  uint32_t uVar1;
  
  uVar1 = (SEQ->REG080);
  return uVar1 & 0xf;
}



uint32_t RFHAL_SetPtiProtocol(undefined4 param_1,uint32_t param_2,int param_3,uint32_t param_4)

{
  uint32_t uVar1;
  uint32_t uVar2;
  
  uVar2 = param_2 & 0xfffffff0;
  if (uVar2 == 0) {
    param_3 = 0x21000f7c;
    uVar1 = (SEQ->REG080);
    param_4 = uVar1 & 0xfffffff0 | param_2 & 0xf;
  }
  if (uVar2 == 0) {
    *(uint32_t *)(param_3 + 4) = param_4;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



void RFHAL_Idle(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  switch(param_1) {
  case 0:
    iVar1 = 0;
    iVar2 = iVar1;
    iVar3 = iVar1;
    break;
  case 1:
    iVar1 = 0;
    goto LAB_0001049e;
  case 2:
    iVar1 = 1;
LAB_0001049e:
    iVar2 = 0;
    iVar3 = 1;
    break;
  case 3:
    iVar1 = 1;
    iVar2 = iVar1;
    iVar3 = iVar1;
    break;
  default:
    goto switchD_00010492_caseD_4;
  }
  GENERIC_PHY_RadioIdle(iVar3,iVar1,iVar2);
  if (iVar3 != 0) {
    setRssiPeriod(saveRssiPeriodPreCca);
    saveRssiPeriodPreCca = 0;
  }
switchD_00010492_caseD_4:
  return;
}



undefined4 RFHAL_GetRadioState(void)

{
  int iVar1;
  uint32_t uVar2;
  bool bVar3;
  
  iVar1 = PROTIMER_LBTIsActive();
  if (iVar1 != 0) {
    return 4;
  }
  uVar2 = (RAC->STATUS);
  uVar2 = uVar2 & 0xf000000;
  if (uVar2 == 0x7000000) {
    return 2;
  }
  if (uVar2 < 0x7000001) {
    if (uVar2 == 0x3000000) {
      return 3;
    }
    if (uVar2 < 0x3000001) {
      if (uVar2 == 0x1000000) {
        return 2;
      }
      bVar3 = uVar2 == 0x2000000;
    }
    else {
      if (uVar2 == 0x4000000) {
        return 2;
      }
      bVar3 = uVar2 == 0x5000000;
    }
    if (bVar3) {
      return 2;
    }
  }
  else {
    if (uVar2 == 0xa000000) {
      return 4;
    }
    if (uVar2 < 0xa000001) {
      if (uVar2 == 0x8000000) {
        return 4;
      }
      if (uVar2 == 0x9000000) {
        return 5;
      }
    }
    else {
      if (uVar2 == 0xb000000) {
        return 4;
      }
      if (uVar2 == 0xc000000) {
        return 4;
      }
    }
  }
  return 1;
}



uint32_t RFHAL_OkToTransmit(void)

{
  uint32_t uVar1;
  
  uVar1 = (RAC->SR0);
  return ((uVar1 ^ 0x80) << 0x18) >> 0x1f;
}



undefined4 RFHAL_HeadedToIdle(void)

{
  uint32_t uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint32_t uVar5;
  bool bVar6;
  
  uVar2 = CORE_EnterCritical();
  iVar3 = PROTIMER_CCTimerIsEnabled(3);
  iVar4 = PROTIMER_LBTIsActive();
  if ((iVar3 == 0) && (iVar4 == 0)) {
    uVar5 = (RAC->STATUS);
    uVar1 = (RAC->SR0);
    CORE_ExitCritical(uVar2);
    if ((uVar5 & 0xc0000000) == 0) {
      if ((int)(uVar1 << 0x18) < 0) {
        return 0;
      }
      uVar5 = uVar5 & 0xf000000;
      if (uVar5 != 0x6000000) {
        if (uVar5 < 0x6000001) {
          bVar6 = uVar5 == 0x3000000;
        }
        else {
          if (uVar5 == 0x9000000) {
            return 0;
          }
          bVar6 = uVar5 == 0xc000000;
        }
        if (!bVar6) {
          return 1;
        }
      }
    }
  }
  else {
    CORE_ExitCritical(uVar2);
  }
  return 0;
}



void RFHAL_SetCcaThreshold(undefined4 param_1,undefined4 param_2)

{
  RADIO_AGCCCAThresholdSet(param_2);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

int RFHAL_StartAverageRssi(uint8_t *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  *param_1 = *param_1 & 0xf7;
  saveRssiPeriod = (AGC->CTRL1);
  iVar1 = RADIO_SetRssiPeriod(param_3);
  if (iVar1 == 0) {
    iVar1 = _DAT_430c0354;
    if (_DAT_430c0354 != 0) {
      iVar1 = 1;
    }
    saveFrameDetDisable = (char)iVar1;
    BUS_RegMaskedSet(&MODEM->CTRL0,0x200000);
    iVar1 = RAILCore_StartRx(param_1,param_2);
    if (iVar1 == 0) {
      GENERIC_PHY_ConfigureEvents(1,0,1,0,0,0);
    }
    else {
      if (saveFrameDetDisable == '\0') {
        BUS_RegMaskedClear(&MODEM->CTRL0,0x200000);
      }
      else {
        BUS_RegMaskedSet(&MODEM->CTRL0,0x200000);
      }
      setRssiPeriod(saveRssiPeriod);
      iVar1 = 2;
    }
  }
  else {
    iVar1 = 1;
  }
  return iVar1;
}



int RFHAL_GetAverageRssi(int param_1)

{
  return (int)*(int16_t *)(param_1 + 6);
}



uint32_t RFHAL_IsAverageRssiReady(uint8_t *param_1)

{
  return ((uint32_t)*param_1 << 0x1c) >> 0x1f;
}



void RFHAL_ScheduleRx(int param_1,undefined4 param_2,uint32_t *param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char cVar4;
  char cVar5;
  uint32_t uVar6;
  char cVar7;
  
  cVar7 = *(char *)(param_3 + 1);
  if (cVar7 == '\x01') {
    if ((uint32_t)*(uint16_t *)(param_1 + 0x38) <= *param_3) goto LAB_0001067a;
    iVar1 = 0;
  }
  else {
    if (cVar7 == '\x02') {
      uVar2 = 0;
      goto LAB_00010694;
    }
LAB_0001067a:
    iVar1 = *param_3 - (uint32_t)*(uint16_t *)(param_1 + 0x38);
  }
  uVar2 = PROTIMER_UsToPrecntOverflow(iVar1);
  cVar7 = *(char *)(param_3 + 1);
  if (cVar7 != '\0') {
    cVar7 = '\x01';
  }
LAB_00010694:
  cVar4 = *(char *)(param_3 + 3);
  if (cVar4 == '\x02') {
    uVar3 = 0;
  }
  else {
    uVar3 = PROTIMER_UsToPrecntOverflow(param_3[2]);
    cVar4 = *(char *)(param_3 + 3);
    if (cVar4 != '\0') {
      cVar4 = '\x01';
    }
  }
  uVar6 = count_leading_zeroes((uint32_t)*(uint8_t *)((int)param_3 + 0xd));
  cVar5 = *(char *)((int)param_3 + 0xe);
  if (cVar5 != '\0') {
    cVar5 = '\x01';
  }
  GENERIC_PHY_SchedulePacketRx(param_1,uVar2,cVar7,uVar3,cVar4,uVar6 >> 5,cVar5);
  return;
}



undefined4 RFHAL_StartRx(void)

{
  GENERIC_PHY_StartRx(0);
  return 0;
}



undefined4 RFHAL_EnableRxRawCapture(int param_1,uint32_t param_2)

{
  uint32_t uVar1;
  uint32_t uVar2;
  
  uVar2 = param_1 - 1U & 0xff;
  if (uVar2 < 3) {
    param_2 = *(uint32_t *)(&CSWTCH_140 + uVar2 * 4);
  }
  uVar1 = (MODEM->CTRL0);
  if (2 < uVar2) {
    param_2 = 0;
  }
  write_volatile_4(MODEM->CTRL0,uVar1 & 0xc7ffffff | param_2);
  BUS_RegMaskedSet(&MODEM->CTRL0,0x200000);
  uVar2 = (FRC->BUFFERMODE);
  write_volatile_4(FRC->BUFFERMODE,uVar2 & 0xfffffff9 | 4);
  BUS_RegMaskedSet(&RAC->SR3,0x10000000);
  write_volatile_4(FRC->RAWCTRL,4);
  return 0;
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



void RFHAL_AcceptCrcErrors(int param_1)

{
  FRC_SET *pFVar1;
  
  if (param_1 == 0) {
    pFVar1 = (FRC_SET *)&Peripherals::FRC_CLR;
  }
  else {
    pFVar1 = &Peripherals::FRC_SET;
  }
  ((FRC_CLR *)pFVar1)->RXCTRL = 2;
  return;
}



undefined4 RFHAL_ConfigRxOptions(undefined4 param_1,int param_2,uint32_t param_3)

{
  FRC_SET *pFVar1;
  MODEM_SET *pMVar2;
  uint32_t uVar3;
  
  if (param_2 << 0x1c < 0) {
    if ((param_3 & 8) == 0) {
      pFVar1 = (FRC_SET *)&Peripherals::FRC_CLR;
    }
    else {
      pFVar1 = &Peripherals::FRC_SET;
    }
    ((FRC_CLR *)pFVar1)->RXCTRL = 8;
  }
  if (param_2 << 0x1f < 0) {
    if ((param_3 & 1) == 0) {
      pFVar1 = (FRC_SET *)&Peripherals::FRC_CLR;
    }
    else {
      pFVar1 = &Peripherals::FRC_SET;
    }
    ((FRC_CLR *)pFVar1)->RXCTRL = 1;
  }
  if (param_2 << 0x1d < 0) {
    if ((param_3 & 4) == 0) {
      pMVar2 = (MODEM_SET *)&Peripherals::MODEM_CLR;
    }
    else {
      pMVar2 = &Peripherals::MODEM_SET;
    }
    ((MODEM_CLR *)pMVar2)->CTRL1 = 0x200;
  }
  if (param_2 << 0x1e < 0) {
    RFHAL_AcceptCrcErrors((param_3 << 0x1e) >> 0x1f);
  }
  if (param_2 << 0x1b < 0) {
    if ((param_3 & 0x10) == 0) {
      uVar3 = 0x1b;
    }
    else {
      uVar3 = 0;
    }
    write_volatile_4(FRC->TRAILRXDATA,uVar3);
  }
  return 0;
}



undefined4
RFHAL_SetPaCTune(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  PA_SetCTune(param_2,param_3,param_3,param_4,param_4);
  return 0;
}



void RFHAL_GetTimer(void)

{
  undefined4 uVar1;
  
  uVar1 = GENERIC_PHY_GetTimerTimeout();
  PROTIMER_PrecntOverflowToUs(uVar1,0);
  return;
}



void RFHAL_CancelTimer(void)

{
  GENERIC_PHY_ConfigureEvents(0,0,0,0,4,0);
  GENERIC_PHY_TimerStop();
  timerExpiredCb = 0;
  return;
}



undefined4 RFHAL_SetTimer(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_2 == 2) {
    RFHAL_CancelTimer();
  }
  else {
    uVar1 = CORE_EnterCritical();
    if ((timerExpiredCb == 0) || (timerExpiredCb == param_3)) {
      timerExpiredCb = param_3;
      timerExpiredCbArg = param_4;
      GENERIC_PHY_ConfigureEvents(0,0,0,0,4,4);
      timerExpired = 0;
      uVar2 = PROTIMER_UsToPrecntOverflow(param_1);
      if (param_2 != 0) {
        param_2 = 1;
      }
      iVar3 = GENERIC_PHY_TimerStart(uVar2,param_2);
    }
    else {
      iVar3 = 0;
    }
    CORE_ExitCritical(uVar1);
    if (iVar3 == 0) {
      timerExpiredCb = iVar3;
      return 1;
    }
  }
  return 0;
}



uint8_t RFHAL_IsTimerExpired(void)

{
  uint8_t bVar1;
  int iVar2;
  
  iVar2 = GENERIC_PHY_IsTimerExpired();
  bVar1 = timerExpired;
  if (iVar2 != 0) {
    bVar1 = 1;
  }
  return bVar1 & 1;
}



void RFHAL_IsTimerRunning(void)

{
  GENERIC_PHY_IsTimerRunning();
  return;
}



void RFHAL_GetSymbolRate(void)

{
  RADIO_ComputeTxSymbolRate();
  return;
}



void RFHAL_GetBitRate(void)

{
  RADIO_ComputeTxBitRate();
  return;
}



// WARNING: Could not reconcile some variable overlaps

void RFHAL_StartRfSense(undefined param_1,undefined4 param_2,undefined4 param_3,uint32_t param_4)

{
  undefined4 local_14;
  undefined4 local_10;
  uint32_t local_c;
  
  local_c._0_2_ = CONCAT11(1,param_1);
  local_c = param_4 & 0xffff0000 | (uint32_t)(uint16_t)local_c;
  local_14 = param_3;
  local_10 = param_2;
  RFSENSE_Init(&local_14);
  return;
}



void RFHAL_IsRfSensed(void)

{
  RFSENSE_Sensed();
  return;
}



void RFHAL_RunCal(int param_1,int *param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(param_1 + 0x24);
  if (piVar1 != (int *)0x0) {
    piVar1 = (int *)piVar1[5];
  }
  if (param_3 << 0x1f < 0) {
    TEMPCAL_Perform();
  }
  if (param_3 << 0xf < 0) {
    iVar2 = *param_2;
    if (iVar2 == -1) {
      iVar2 = IRCAL_Perform();
      *param_2 = iVar2;
    }
    else {
      IRCAL_Set(iVar2);
    }
    if (piVar1 != (int *)0x0) {
      *piVar1 = iVar2;
    }
  }
  return;
}



void RFHAL_EnablePaCal(void)

{
  PA_EnableCal();
  return;
}



undefined4 RFHAL_SetTxTransitions(undefined4 param_1,uint8_t *param_2)

{
  uint16_t uVar1;
  
  uVar1 = read_volatile_2(SEQ->REG024._0_2_);
  write_volatile_4(SEQ->REG024,
                   (uint32_t)param_2[1] << 0x18 | (uint32_t)*param_2 << 0x10 | (uint32_t)uVar1);
  return 0;
}



undefined4 RFHAL_SetRxTransitions(undefined4 param_1,uint8_t *param_2)

{
  uint16_t uVar1;
  
  uVar1 = read_volatile_2(SEQ->REG024._2_2_);
  write_volatile_4(SEQ->REG024,
                   (uint32_t)*param_2 | (uint32_t)uVar1 << 0x10 | (uint32_t)param_2[1] << 8);
  return 0;
}



void RFHAL_SetCRCInitVal(void)

{
  RADIO_SetCRCInitVal();
  return;
}



undefined4 RFHAL_ConfigTxPower(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = PA_Config(param_2);
  TIMING_RecalculatePaRampChanged(param_1 + 0x28);
  return uVar1;
}



undefined4 RFHAL_SetTxPower(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  if (*(char *)(param_1 + 0x60) != '\x03') {
    if (param_3 == 0) {
      PA_SetPowerLevel(param_2);
    }
    else {
      *(char *)(param_1 + 4) = (char)param_2;
      uVar1 = RAILInt_GetChannel();
      RAILInt_SetChannel(param_1,uVar1);
    }
    return 0;
  }
  return 2;
}



undefined4 RFHAL_GetTxPowerConfig(undefined4 param_1,undefined4 param_2)

{
  PA_GetTxPowerConfig(param_2);
  return 0;
}



void RFHAL_GetTxPower(void)

{
  PA_GetPowerLevel();
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



undefined4 RFHAL_SetChannel(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  
  if (*(int *)(param_1 + 0x10) != 1) {
    iVar1 = RAILCore_GetRadioState();
    if (iVar1 != 1) {
      RAILCore_Idle(1,1);
    }
    if (*(code **)(param_1 + 0x1c) != NULL) {
      (**(code **)(param_1 + 0x1c))(param_1,param_2);
    }
    iVar1 = *(int *)(param_3 + 4);
    uVar4 = param_2 - (uint32_t)*(uint16_t *)(param_3 + 0xc);
    uVar5 = uVar4 & 0xffff;
    if (0x3f < uVar5) {
      iVar1 = (uVar5 >> 6) * *(int *)(param_3 + 8) * 0x40 + iVar1;
      uVar5 = uVar4 & 0x3f;
    }
    iVar2 = SYNTH_RfFreqGet();
    if (((iVar2 != iVar1) || (iVar2 = SYNTH_ChSpacingGet(), iVar2 != *(int *)(param_3 + 8))) ||
       (param_4 != 0)) {
      iVar1 = SYNTH_Config(iVar1,*(undefined4 *)(param_3 + 8));
      if (iVar1 != 0) {
        return 2;
      }
      iVar1 = SYNTH_Is2p4GHz();
      if (iVar1 == 0) {
        uVar3 = 3500000;
      }
      else {
        uVar3 = 7000000;
      }
      SYNTH_DCDCRetimeClkSet(uVar3);
    }
    RFHAL_NotifyUserOfIrCal(param_1);
    GENERIC_PHY_ChannelSet(uVar5 & 0xff);
  }
  return 0;
}



uint32_t RFHAL_EnableAutoAck(undefined4 param_1,int param_2)

{
  uint32_t uVar1;
  
  CORE_EnterCritical();
  uVar1 = (SEQ->REG014);
  if (param_2 == 0) {
    uVar1 = uVar1 & 0xffffffdf;
  }
  else {
    uVar1 = uVar1 | 0x20;
  }
  write_volatile_4(SEQ->REG014,uVar1);
  CORE_ExitCritical();
  return (uVar1 << 0x1a) >> 0x1f;
}



uint32_t RFHAL_IsAutoAckEnabled(void)

{
  uint32_t uVar1;
  
  uVar1 = (SEQ->REG014);
  return (uVar1 << 0x1a) >> 0x1f;
}



undefined4 RFHAL_SetAutoAckTimeout(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = PROTIMER_UsToPrecntOverflow(param_2);
  write_volatile_4(SEQ->REG020,-iVar1);
  return 0;
}



undefined4 RFHAL_WriteAutoAckFifo(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  uint32_t uVar2;
  undefined4 uVar3;
  
  uVar1 = CORE_EnterCritical();
  BUS_RegMaskedSet(&RAC->SR0,2);
  uVar2 = (RAC->STATUS);
  uVar2 = (uVar2 << 4) >> 0x1c;
  if (((uVar2 - 7 < 3) || (uVar2 == 0xc)) &&
     (uVar2 = (RAC->SR0), (int)(uVar2 << 0xe) < 0)) {
    uVar3 = 3;
  }
  else {
    uVar3 = BUFC_TxAckBufferSet(param_2,param_3);
  }
  BUS_RegMaskedClear(&RAC->SR0,2);
  CORE_ExitCritical(uVar1);
  return uVar3;
}



void RFHAL_PauseRxAutoAck(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 8;
  }
  GENERIC_PHY_SetFeatures(param_1,8,uVar1);
  return;
}



void RFHAL_PauseTxAutoAck(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0x100;
  }
  GENERIC_PHY_SetFeatures(param_1,0x100,uVar1);
  return;
}



uint32_t RFHAL_IsRxAutoAckPaused(void)

{
  uint32_t uVar1;
  
  uVar1 = (SEQ->REG014);
  return (uVar1 << 0x1c) >> 0x1f;
}



uint32_t RFHAL_IsTxAutoAckPaused(void)

{
  uint32_t uVar1;
  
  uVar1 = (SEQ->REG014);
  return (uVar1 << 0x17) >> 0x1f;
}



uint32_t RFHAL_UseTxFifoForAutoAck(void)

{
  uint32_t uVar1;
  undefined4 uVar2;
  int iVar3;
  uint32_t uVar4;
  
  uVar2 = CORE_EnterCritical();
  iVar3 = GENERIC_PHY_CanModifyAck();
  uVar4 = 2;
  if (iVar3 != 0) {
    BUS_RegMaskedSet(&RAC->SR0,2);
    uVar1 = (RAC->SR0);
    if ((uVar1 & 0x20000) == 0) {
      BUS_RegMaskedSet(&RAC->SR2,0x40);
      uVar4 = uVar1 & 0x20000;
    }
    BUS_RegMaskedClear(&RAC->SR0,2);
  }
  CORE_ExitCritical(uVar2);
  return uVar4;
}



uint32_t RFHAL_CancelAutoAck(void)

{
  uint32_t uVar1;
  undefined4 uVar2;
  int iVar3;
  uint32_t uVar4;
  
  uVar2 = CORE_EnterCritical();
  iVar3 = GENERIC_PHY_CanModifyAck();
  uVar4 = 2;
  if (iVar3 != 0) {
    BUS_RegMaskedSet(&RAC->SR0,2);
    uVar1 = (RAC->SR0);
    if ((uVar1 & 0x20000) == 0) {
      BUS_RegMaskedSet(&RAC->SR2,0x20);
      uVar4 = uVar1 & 0x20000;
    }
    BUS_RegMaskedClear(&RAC->SR0,2);
  }
  CORE_ExitCritical(uVar2);
  return uVar4;
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



uint32_t preTxOps(undefined4 param_1,uint32_t param_2)

{
  FRC_SET *pFVar1;
  MODEM_SET *pMVar2;
  uint32_t uVar3;
  int iVar4;
  
  iVar4 = param_2 << 0x1e;
  if ((int)((uint32_t)fcds << 0x1f) < 0) {
    if (iVar4 < 0) {
      pFVar1 = (FRC_SET *)&Peripherals::FRC_CLR;
    }
    else {
      pFVar1 = &Peripherals::FRC_SET;
    }
    ((FRC_CLR *)pFVar1)->FCD0 = 0x400;
  }
  if ((int)((uint32_t)fcds << 0x1e) < 0) {
    if (iVar4 < 0) {
      pFVar1 = (FRC_SET *)&Peripherals::FRC_CLR;
    }
    else {
      pFVar1 = &Peripherals::FRC_SET;
    }
    ((FRC_CLR *)pFVar1)->FCD0 = 0x800;
  }
  if ((int)((uint32_t)fcds << 0x1d) < 0) {
    if (iVar4 < 0) {
      pFVar1 = (FRC_SET *)&Peripherals::FRC_CLR;
    }
    else {
      pFVar1 = &Peripherals::FRC_SET;
    }
    ((FRC_CLR *)pFVar1)->FCD1 = 0x400;
  }
  if ((int)((uint32_t)fcds << 0x1c) < 0) {
    if (iVar4 < 0) {
      pFVar1 = (FRC_SET *)&Peripherals::FRC_CLR;
    }
    else {
      pFVar1 = &Peripherals::FRC_SET;
    }
    ((FRC_CLR *)pFVar1)->FCD1 = 0x800;
  }
  if ((param_2 & 4) == 0) {
    pMVar2 = (MODEM_SET *)&Peripherals::MODEM_CLR;
  }
  else {
    pMVar2 = &Peripherals::MODEM_SET;
  }
  ((MODEM_CLR *)pMVar2)->CTRL1 = 0x400;
  uVar3 = (SEQ->REG014);
  if ((int)(uVar3 << 0x1a) < 0) {
    RFHAL_AutoAckWaitForAck(param_2 & 1);
  }
  uVar3 = GENERIC_PHY_IsEnabledIEEE802154(param_1);
  if (uVar3 != 0) {
    uVar3 = (SEQ->REG014);
    uVar3 = uVar3 & 0x20;
    if (uVar3 != 0) {
      uVar3 = BUFC_PeekByte(0,3);
      if (uVar3 != 0xffffffff) {
        write_volatile_4(SEQ->REG01C,uVar3);
        return 0;
      }
      uVar3 = 3;
    }
  }
  return uVar3;
}



int RFHAL_StartTx(void)

{
  int iVar1;
  
  iVar1 = preTxOps();
  if (iVar1 == 0) {
    GENERIC_PHY_PacketTx();
  }
  return iVar1;
}



// WARNING: Could not reconcile some variable overlaps

void RFHAL_StartScheduledTx(int param_1,undefined4 param_2,uint32_t *param_3)

{
  int local_18;
  uint32_t local_14;
  
  local_18 = param_1;
  local_14 = param_2;
  local_18 = preTxOps();
  if (local_18 == 0) {
    local_14 = param_3[1];
    if (((char)local_14 != '\x01') || ((uint32_t)*(uint16_t *)(param_1 + 0x3e) <= *param_3)) {
      local_18 = *param_3 - (uint32_t)*(uint16_t *)(param_1 + 0x3e);
    }
    GENERIC_PHY_SchedulePacketTx(&local_18);
  }
  return;
}



int RFHAL_StartCcaCsmaTx(undefined4 param_1,undefined4 param_2,uint16_t *param_3)

{
  uint8_t bVar1;
  uint16_t uVar2;
  int iVar3;
  uint32_t uVar4;
  int iVar5;
  undefined4 uVar6;
  uint32_t uVar7;
  uint8_t bVar8;
  uint32_t uVar9;
  uint8_t bVar10;
  uint8_t bVar11;
  uint8_t bVar12;
  uint32_t uVar13;
  PROTIMER *pPVar14;
  uint32_t uVar15;
  
  iVar3 = preTxOps();
  if (iVar3 == 0) {
    saveRssiPeriodPreCca = (AGC->CTRL1);
    if (param_3 == NULL) {
      setRssiPeriod(saveRssiPeriodInCca);
      PROTIMER_LBTUseLastConfig();
    }
    else {
      RADIO_SetAgcCcaParams
                (param_3[3],(int)*(char *)((int)param_3 + 3),saveRssiPeriodPreCca,
                 &saveRssiPeriodPreCca,param_1,param_2);
      saveRssiPeriodInCca = (AGC->CTRL1);
      bVar12 = *(uint8_t *)(param_3 + 1);
      bVar1 = *(uint8_t *)param_3;
      bVar11 = *(uint8_t *)((int)param_3 + 1);
      bVar10 = bVar12;
      bVar8 = bVar12;
      if (bVar12 != 0) {
        bVar8 = bVar12 - 1;
        bVar12 = bVar1;
        if (bVar11 < bVar1) {
          bVar11 = bVar1;
          bVar10 = 1;
        }
        else {
          bVar10 = 1;
        }
      }
      uVar9 = count_leading_zeroes((uint32_t)*param_3);
      pPVar14 = (PROTIMER *)0x10da7;
      uVar2 = PROTIMER_UsToPrecntOverflow(param_3[2]);
      uVar4 = (uint32_t)uVar2;
      if (uVar9 >> 5 == 0) {
        uVar15 = (uint32_t)reseedRandom_9523;
        if (uVar15 != 0xf804) {
          pPVar14 = &Peripherals::PROTIMER;
        }
        if (uVar15 != 0xf804) {
          pPVar14->RANDOM = uVar15;
          reseedRandom_9523 = 0xf804;
        }
      }
      else {
        uVar7 = 0;
        uVar15 = uVar4;
        while( true ) {
          uVar13 = uVar7 & 0xff;
          uVar7 = uVar7 + 1;
          if (uVar15 < 0x100) break;
          uVar15 = uVar15 >> 1;
        }
        if ((uVar13 != 0) && (uVar15 != 0xff)) {
          uVar15 = (uint32_t)(uint16_t)(((uint16_t)((int)uVar4 >> (uVar13 - 1 & 0xff)) & 1) + (int16_t)uVar15)
          ;
        }
        uVar4 = uVar15;
        uVar15 = (PROTIMER->RANDOM);
        reseedRandom_9523 = (uint16_t)(uVar15 & 0xffff);
        if ((uVar15 & 0xffff) == 0xf804) {
          reseedRandom_9523 = 0xf805;
        }
        bVar11 = 8;
        write_volatile_4(PROTIMER->RANDOM,(1 << uVar13) - 1);
        write_volatile_4(PROTIMER->LBTSTATE,0x800000);
        bVar12 = 8;
      }
      uVar4 = uVar4 - 1;
      if (0xfe < uVar4) {
        uVar4 = 0xff;
      }
      write_volatile_4(PROTIMER->BASECNTTOP,uVar4);
      iVar3 = RAILInt_GetActiveConfig();
      PROTIMER_LBTCfgSet(iVar3 + 0x34,bVar12,bVar11,bVar10,bVar8,0);
      if (uVar9 >> 5 != 0) {
        BUS_RegMaskedSet(&PROTIMER->LBTCTRL,0x100000);
        uVar4 = (PROTIMER->CTRL);
        write_volatile_4(PROTIMER->CTRL,uVar4 & 0xff3fffff | 0x400000);
      }
      lbtTimeout_9522 = *(int *)(param_3 + 4);
    }
    GENERIC_PHY_PacketTxCommon();
    iVar3 = lbtTimeout_9522;
    if (lbtTimeout_9522 != 0) {
      iVar5 = PROTIMER_CCTimerIsEnabled(4);
      if (iVar5 != 0) {
        PROTIMER_CCTimerStop(4);
      }
      uVar6 = PROTIMER_UsToPrecntOverflow(iVar3);
      iVar3 = PROTIMER_CCTimerStart(4,uVar6,1);
      if (iVar3 == 0) {
        return 1;
      }
    }
    PROTIMER_LBTStart();
    iVar3 = 0;
  }
  return iVar3;
}



// WARNING: Could not reconcile some variable overlaps

void RFHAL_StartCcaLbtTx(undefined4 param_1,uint32_t param_2,uint32_t *param_3,uint32_t param_4)

{
  uint32_t uVar1;
  uint8_t bVar2;
  uint32_t *puVar3;
  undefined4 local_1c;
  undefined4 local_18;
  uint32_t uStack20;
  
  puVar3 = param_3;
  local_1c = param_2;
  local_18 = param_3;
  uStack20 = param_4;
  if ((param_3 != NULL) && (*(int16_t *)param_3 != 0)) {
    local_1c = *param_3;
    local_18._2_2_ = (uint16_t)(param_3[1] >> 0x10);
    uStack20 = param_3[2];
    bVar2 = *(uint8_t *)param_3;
    if (bVar2 != 0) {
      local_18._2_2_ = *(int16_t *)(param_3 + 1) * (uint16_t)bVar2 + local_18._2_2_;
      local_1c._1_1_ = (char)(local_1c >> 8);
      local_1c._2_2_ = (undefined2)(local_1c >> 0x10);
      local_1c = (uint32_t)CONCAT21(local_1c._2_2_,local_1c._1_1_ - bVar2) << 8;
    }
    uVar1 = local_1c >> 8 & 0xff;
    for (bVar2 = 1; (uint32_t)(1 << (uint32_t)bVar2) < uVar1; bVar2 = bVar2 + 1) {
    }
    puVar3 = param_3 + 1;
    local_18 = (uint32_t *)(uVar1 * (int)(uint32_t *)(uint32_t)*(uint16_t *)puVar3 +
                        ((uint32_t)(1 << (uint32_t)bVar2) >> 1) >> (uint32_t)bVar2 & 0xffff |
                       (uint32_t)local_18._2_2_ << 0x10);
    local_1c._0_2_ = CONCAT11(bVar2,bVar2);
    local_1c = local_1c & 0xffff0000 | (uint32_t)(uint16_t)local_1c;
    param_3 = &local_1c;
    puVar3 = (uint32_t *)(uint32_t)*(uint16_t *)puVar3;
  }
  RFHAL_StartCcaCsmaTx(param_1,param_2,param_3,puVar3,param_1);
  return;
}



uint32_t RFHAL_IsAutoAckWaitingForAck(void)

{
  uint32_t uVar1;
  
  uVar1 = (RAC->SR1);
  return (uVar1 << 0x1b) >> 0x1f;
}



uint32_t RFHAL_ReadRxFifo(undefined4 param_1,undefined4 param_2,uint32_t param_3)

{
  uint32_t uVar1;
  uint32_t uVar2;
  undefined auStack32 [2];
  uint16_t local_1e;
  
  uVar1 = BUFC_GetRxPacketInfo(1,auStack32,0);
  uVar2 = uVar1;
  if (uVar1 != 0) {
    uVar2 = param_3;
    if (local_1e <= param_3) {
      uVar2 = (uint32_t)local_1e;
    }
    if (uVar1 == cachedPacketHandle) {
      cachedPacketHandle = 0;
    }
    BUFC_ReadBuffer(1,param_2,uVar2);
  }
  return uVar2;
}



// WARNING: Could not reconcile some variable overlaps

int RFHAL_GetRxPacketInfo(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uStack20;
  undefined4 uStack16;
  
  uStack20 = param_2;
  uStack16 = param_3;
  iVar1 = BUFC_GetRxPacketInfo(param_1,param_2,(int)&uStack20 + 2,param_4,param_1);
  if (iVar1 != 0) {
    CORE_EnterCritical();
    cachedPacketStartOffset = uStack20._2_2_;
    cachedPacketBytes = *(undefined2 *)(param_2 + 2);
    cachedPacketHandle = iVar1;
    CORE_ExitCritical();
  }
  return iVar1;
}



// WARNING: Could not reconcile some variable overlaps

undefined4 RFHAL_GetRxPacketDetails(int16_t *param_1,undefined4 *param_2,undefined4 param_3)

{
  int16_t sVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  char cVar4;
  undefined4 uVar5;
  int iVar6;
  uint32_t uVar7;
  uint32_t uVar8;
  undefined4 local_18;
  undefined4 *local_14;
  undefined4 uStack16;
  
  if (((param_1 == (int16_t *)0x0) || (param_2 == NULL)) ||
     ((local_18 = param_1, local_14 = param_2, uStack16 = param_3, param_1 < (int16_t *)0x3 &&
      (param_1 = (int16_t *)BUFC_GetRxPacketInfo(param_1,0,0), param_1 == (int16_t *)0x0)))) {
    uVar5 = 1;
  }
  else {
    sVar1 = *param_1;
    uVar7 = (uint32_t)*(uint8_t *)(param_1 + 1);
    if ((sVar1 < 0) || ((uVar7 & 7) < 6)) {
      uVar5 = 2;
    }
    else {
      *(uint8_t *)((int)param_2 + 0xd) = (uint8_t)((uVar7 << 0x1b) >> 0x1f);
      *(uint8_t *)((int)param_2 + 0x11) = (uint8_t)((uVar7 << 0x1a) >> 0x1f);
      *(bool *)(param_2 + 3) = (uVar7 & 7) == 7;
      *(uint8_t *)(param_2 + 4) = (uint8_t)((uVar7 << 0x19) >> 0x1f);
      cVar4 = RADIO_RxTrailDataLength();
      if (cVar4 == '\0') {
        *(undefined *)((int)param_2 + 0xf) = 0;
        *(undefined *)((int)param_2 + 0xe) = 0x80;
        *param_2 = 0;
        *(undefined *)(param_2 + 2) = 0;
      }
      else {
        if (*(char *)(param_2 + 2) == '\0') {
          cVar4 = '\x02';
        }
        BUFC_Peek(1,&local_18,cVar4,sVar1 + -6);
        *(char *)((int)param_2 + 0xf) = local_18._1_1_ << 1;
        *(undefined *)((int)param_2 + 0xe) = (undefined)local_18;
        if (*(char *)(param_2 + 2) != '\0') {
          uVar8 = (uint32_t)local_14 & 0xff;
          uVar7 = (uint32_t)local_18 >> 0x18;
          uVar2 = (uint32_t)local_18 >> 0x10;
          uVar3 = (uint32_t)local_14 >> 8;
          iVar6 = RAILInt_GetActiveConfig();
          TIMING_CalcRxTimeStampUs
                    (iVar6 + 0x34,uVar2 & 0xff | uVar8 << 0x10 | uVar7 << 8 | uVar3 << 0x18,param_2)
          ;
        }
      }
      uVar5 = 0;
    }
  }
  return uVar5;
}



void RFHAL_HoldRxPacket(void)

{
  BUFC_HoldRxPacket();
  return;
}



void RFHAL_ReleaseRxPacket(uint32_t param_1)

{
  if ((param_1 == cachedPacketHandle) || (param_1 < 3)) {
    cachedPacketHandle = 0;
  }
  GENERIC_PHY_ReleaseRxPacket();
  return;
}



uint32_t RFHAL_SetTxFifoThreshold(int param_1,uint32_t param_2)

{
  uint32_t uVar1;
  
  uVar1 = (BUFC->BUF0_CTRL);
  uVar1 = 1 << (uVar1 & 7) + 6 & 0xffff;
  if (uVar1 <= param_2) {
    param_2 = uVar1;
  }
  uVar1 = (BUFC->BUF0_THRESHOLDCTRL);
  write_volatile_4(BUFC->BUF0_THRESHOLDCTRL,uVar1 & 0xfffff000 | param_2 - 1 & 0xffff);
  *(int16_t *)(param_1 + 0x6c) = (int16_t)param_2;
  return param_2;
}



uint32_t RFHAL_SetRxFifoThreshold(int param_1,uint32_t param_2)

{
  uint32_t uVar1;
  
  uVar1 = (BUFC->BUF1_THRESHOLDCTRL);
  if (0x1ff < param_2) {
    param_2 = 0x200;
  }
  write_volatile_4(BUFC->BUF1_THRESHOLDCTRL,uVar1 & 0xfffff000 | param_2);
  *(int16_t *)(param_1 + 0x6e) = (int16_t)param_2;
  return param_2;
}



undefined2 RFHAL_GetTxFifoThreshold(int param_1)

{
  return *(undefined2 *)(param_1 + 0x6c);
}



undefined2 RFHAL_GetRxFifoThreshold(int param_1)

{
  return *(undefined2 *)(param_1 + 0x6e);
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



uint32_t RFHAL_SetTxBuffer(undefined4 param_1,undefined4 param_2,uint32_t param_3,undefined4 param_4)

{
  int iVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  
  iVar1 = count_leading_zeroes(param_4);
  uVar2 = 0x19 - iVar1;
  if ((iVar1 == 0x19) || (0 < (int)uVar2)) {
    if (5 < (int)uVar2) {
      uVar2 = 6;
    }
    uVar2 = uVar2 & 0xff;
  }
  else {
    uVar2 = 0;
  }
  uVar3 = 1 << (uVar2 + 6 & 0xff) & 0xffff;
  if (uVar3 <= param_3) {
    param_3 = uVar3;
  }
  BUFC_SetTxBuffer(param_2,param_3,uVar2);
  return uVar3;
}



void RFHAL_ResetTxFifo(void)

{
  uint32_t uVar1;
  
  uVar1 = (BUFC->IEN);
  write_volatile_4(BUFC->BUF0_CMD,1);
  BUS_RegMaskedClear(&BUFC->BUF0_THRESHOLDCTRL,0x2000);
  if ((int)(uVar1 << 0x1d) < 0) {
    BUS_RegMaskedSet(&BUFC->IEN,4);
  }
  return;
}



uint32_t RFHAL_WriteTxFifo(undefined4 param_1,undefined4 param_2,uint32_t param_3,int param_4)

{
  uint32_t uVar1;
  
  if (param_4 != 0) {
    RFHAL_ResetTxFifo();
  }
  uVar1 = BUFC_GetSpaceAvailable(0);
  if (param_3 <= uVar1) {
    uVar1 = param_3;
  }
  BUFC_WriteBuffer(0,param_2,uVar1 & 0xffff);
  return uVar1 & 0xffff;
}



void RFHAL_ResetRxFifo(void)

{
  uint32_t uVar1;
  
  uVar1 = (BUFC->IEN);
  BUS_RegMaskedClear(&BUFC->IEN,0x400);
  cachedPacketHandle = 0;
  GENERIC_PHY_ResetRxFifo();
  BUS_RegMaskedClear(&BUFC->BUF1_THRESHOLDCTRL,0x2000);
  if ((int)(uVar1 << 0x15) < 0) {
    BUS_RegMaskedSet(&BUFC->IEN,0x400);
  }
  return;
}



undefined4 RFHAL_ConfigData(undefined4 param_1,int param_2)

{
  if (*(char *)(param_2 + 2) != *(char *)(param_2 + 3)) {
    return 1;
  }
  if (*(char *)(param_2 + 1) == '\0') {
    RFHAL_DisableRxRawCapture();
  }
  else {
    RFHAL_EnableRxRawCapture();
  }
  if (*(char *)(param_2 + 2) == '\0') {
    write_volatile_4(BUFC->BUF0_THRESHOLDCTRL,0xfff);
  }
  else {
    RFHAL_ResetTxFifo(param_1);
  }
  if (*(char *)(param_2 + 3) == '\0') {
    write_volatile_4(BUFC->BUF1_THRESHOLDCTRL,0xfff);
    BUS_RegMaskedSet(&FRC->RXCTRL,0x60);
    BUS_RegMaskedClear(&RAC->SR0,0x40);
    return 0;
  }
  BUS_RegMaskedClear(&FRC->RXCTRL,0x60);
  RFHAL_ResetRxFifo(param_1);
  BUS_RegMaskedSet(&RAC->SR0,0x40);
  return 0;
}



undefined4 RFHAL_Init(int param_1,code *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  code *pcVar5;
  undefined4 local_1c;
  
  *(undefined4 *)(param_1 + 0x54) = 0;
  *(undefined4 *)(param_1 + 0x58) = 0;
  *(undefined2 *)(param_1 + 0x44) = 100;
  *(undefined2 *)(param_1 + 0x46) = 100;
  *(undefined2 *)(param_1 + 0x48) = 100;
  *(undefined2 *)(param_1 + 0x4a) = 100;
  *(undefined2 *)(param_1 + 0x4c) = 100;
  *(undefined2 *)(param_1 + 0x4e) = 100;
  *(undefined4 *)(param_1 + 0x90) = 0;
  *(undefined2 *)(param_1 + 0x40) = 0;
  *(undefined2 *)(param_1 + 0x42) = 0;
  *(undefined2 *)(param_1 + 0x7c) = 0xffff;
  iVar3 = param_1 + 0xc;
  local_1c = 0;
  iVar4 = param_1;
  pcVar5 = param_2;
  iVar1 = CMU_ClockSelectGet(0x11);
  if (iVar1 == 4) {
    GENERIC_PHY_Init(iVar3);
    write_volatile_4(FRC->RXCTRL,0x60);
    uVar2 = RFHAL_ConfigData(iVar3,&local_1c,0x60,&Peripherals::FRC,iVar4,pcVar5,param_3);
    RFHAL_ConfigRxOptions(iVar3,0xffffffff,*(undefined4 *)(param_1 + 0x90));
    GENERIC_PHY_ConfigureEvents(0xc000000,2,0xc000000,2,0,0);
  }
  else {
    uVar2 = 2;
  }
  if (param_2 != NULL) {
    (*param_2)(param_1);
  }
  return uVar2;
}



uint32_t RFHAL_SetFixedLength(int param_1,uint32_t param_2)

{
  uint32_t uVar1;
  uint16_t uVar2;
  bool bVar3;
  
  uVar1 = (FRC->DFLCTRL);
  if (((uVar1 & 7) == 0) || ((uVar1 & 7) == 5)) {
    uVar2 = *(uint16_t *)(param_1 + 0x70);
    if (param_2 == 0) {
      bVar3 = uVar2 == 0xffff;
      if (bVar3) {
        uVar1 = (FRC->WCNTCMP0);
        uVar2 = (uint16_t)uVar1 & 0xfff;
      }
      if (bVar3) {
        *(uint16_t *)(param_1 + 0x72) = uVar2;
      }
      *(undefined2 *)(param_1 + 0x70) = 0;
      uVar1 = (FRC->DFLCTRL);
      write_volatile_4(FRC->DFLCTRL,uVar1 & 0xfffffff8 | 5);
    }
    else {
      if (param_2 == 0xffff) {
        if (uVar2 != 0xffff) {
          BUS_RegMaskedClear(&FRC->DFLCTRL,7);
          uVar1 = (FRC->WCNTCMP0);
          param_2 = (uint32_t)*(uint16_t *)(param_1 + 0x72);
          write_volatile_4(FRC->WCNTCMP0,uVar1 & 0xfffff000 | param_2);
          *(undefined2 *)(param_1 + 0x70) = 0xffff;
        }
      }
      else {
        bVar3 = uVar2 == 0xffff;
        if (bVar3) {
          uVar1 = (FRC->WCNTCMP0);
          uVar2 = (uint16_t)uVar1;
        }
        *(int16_t *)(param_1 + 0x70) = (int16_t)param_2;
        if (bVar3) {
          uVar2 = uVar2 & 0xfff;
        }
        if (bVar3) {
          *(uint16_t *)(param_1 + 0x72) = uVar2;
        }
        BUS_RegMaskedClear(&FRC->DFLCTRL,7);
        if (0xfff < param_2) {
          param_2 = 0x1000;
        }
        write_volatile_4(FRC->WCNTCMP0,param_2 - 1);
      }
    }
  }
  else {
    param_2 = 0xffff;
  }
  return param_2;
}



void RFHAL_SetAbortScheduledTxDuringRx(int param_1)

{
  RAC_SET *pRVar1;
  
  if (param_1 == 0) {
    pRVar1 = (RAC_SET *)&Peripherals::RAC_CLR;
  }
  else {
    pRVar1 = &Peripherals::RAC_SET;
  }
  ((RAC_CLR *)pRVar1)->SR0 = 8;
  return;
}



int RFHAL_GetRxFreqOffset(void)

{
  longlong lVar1;
  int16_t sVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  int iVar5;
  uint32_t uVar6;
  uint32_t uVar7;
  bool bVar8;
  
  uVar4 = (SYNTH->CALOFFSET);
  uVar3 = uVar4 & 0x7fff;
  bVar8 = (int)(uVar4 << 0x11) < 0;
  uVar6 = (MODEM->AFC);
  if (bVar8) {
    uVar3 = ~(uVar4 << 0x11);
  }
  if (bVar8) {
    uVar3 = ~(uVar3 >> 0x11);
  }
  if ((uVar6 & 0x1c00) == 0) {
    uVar4 = (SEQ->PHYINFO);
    if (uVar4 == 0) {
      uVar4 = 0;
      iVar5 = 0;
    }
    else {
      uVar6 = (MODEM->FREQOFFEST);
      uVar7 = uVar6 & 0xff;
      if ((int)(uVar6 << 0x18) < 0) {
        uVar7 = uVar7 | 0xffffff00;
      }
      lVar1 = (longlong)*(int *)(uVar4 + 4) * (longlong)(int)uVar7 + 0x8000;
      uVar4 = (uint32_t)lVar1;
      iVar5 = (int)((ulonglong)lVar1 >> 0x20);
      if (lVar1 < 0) {
        bVar8 = 0xffff0000 < uVar4;
        uVar4 = uVar4 + 0xffff;
        iVar5 = iVar5 + (uint32_t)bVar8;
      }
      uVar4 = uVar4 >> 0x10 | iVar5 << 0x10;
      iVar5 = iVar5 >> 0x10;
    }
  }
  else {
    uVar6 = (MODEM->AFCADJRX);
    uVar4 = uVar6 & 0x7ffff;
    bVar8 = (int)(uVar6 << 0xd) < 0;
    if (bVar8) {
      uVar4 = ~(uVar6 << 0xd);
    }
    if (bVar8) {
      uVar4 = ~(uVar4 >> 0xd);
    }
    iVar5 = (int)uVar4 >> 0x1f;
  }
  uVar6 = uVar4 + uVar3;
  uVar7 = iVar5 + ((int)uVar3 >> 0x1f) + (uint32_t)CARRY4(uVar4,uVar3);
  if ((int)((uVar7 + 1) - (uint32_t)(0xffffbfff >= uVar6)) < 0 ==
      ((int)uVar7 >= 0 && (int)(uVar7 + (0xffffbfff < uVar6)) < 0 != (int)uVar7 < 0)) {
    if ((int)(-(uint32_t)(uVar6 >= 0x3fff) - uVar7) < 0 ==
        ((int)uVar7 < 0 && (int)(~uVar7 + (uint32_t)(uVar6 < 0x3fff)) < 0)) {
      sVar2 = (int16_t)uVar3 + (int16_t)uVar4;
    }
    else {
      sVar2 = 0x3fff;
    }
  }
  else {
    sVar2 = -0x4000;
  }
  return (int)sVar2;
}



undefined4 RFHAL_SetFreqOffset(undefined4 param_1,undefined4 param_2)

{
  uint32_t uVar1;
  
  uVar1 = SignedSaturate(param_2,0xe);
  SignedDoesSaturate(param_2,0xe);
  if (false) {
    write_volatile_4(SYNTH->CALOFFSET,uVar1 & 0x7fff);
  }
  return 1;
}



int RFHAL_ConfigRadio(uint8_t *param_1)

{
  uint16_t *puVar1;
  uint32_t uVar2;
  uint32_t **ppuVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  uint32_t uVar7;
  int iVar8;
  uint32_t **ppuVar9;
  uint32_t **ppuVar10;
  uint8_t *pbVar11;
  uint32_t **ppuVar12;
  uint32_t **ppuVar13;
  
  uVar4 = (FRC->FCD0);
  uVar2 = (SEQ->PHYINFO);
  uVar6 = (FRC->FCD1);
  pbVar11 = param_1 + 0x28;
  RADIO_Config(pbVar11);
  uVar5 = (FRC->FCD0);
  ppuVar3 = (uint32_t **)(SEQ->PHYINFO);
  uVar7 = (FRC->FCD1);
  if (uVar5 != uVar4) {
    fcds = fcds & 0xfc | (uint8_t)((uVar5 << 0x15) >> 0x1f) | (uint8_t)(((uVar5 << 0x14) >> 0x1f) << 1);
  }
  if (uVar7 != uVar6) {
    fcds = fcds & 0xf3 | (uint8_t)(((uVar7 << 0x15) >> 0x1f) << 2) |
           (uint8_t)(((uVar7 << 0x14) >> 0x1f) << 3);
  }
  if (*(int16_t *)(param_1 + 0x70) != -1) {
    RFHAL_SetFixedLength(param_1);
  }
  if (ppuVar3 != (uint32_t **)uVar2) {
    ppuVar9 = ppuVar3;
    if ((ppuVar3 != (uint32_t **)0x0) && (ppuVar9 = (uint32_t **)*ppuVar3, *ppuVar3 != NULL)) {
      ppuVar9 = (uint32_t **)ppuVar3[2];
    }
    GENERIC_PHY_ConfigureFrameType(param_1,ppuVar9);
    ppuVar9 = ppuVar3;
    ppuVar10 = ppuVar3;
    ppuVar12 = ppuVar3;
    ppuVar13 = ppuVar3;
    if (((ppuVar3 != (uint32_t **)0x0) &&
        (ppuVar9 = (uint32_t **)*ppuVar3, ppuVar10 = ppuVar9, ppuVar12 = ppuVar9, ppuVar13 = ppuVar9,
        ppuVar9 != (uint32_t **)0x0)) &&
       (ppuVar9 = (uint32_t **)ppuVar3[4], ppuVar10 = ppuVar9, ppuVar12 = ppuVar9, ppuVar13 = ppuVar9,
       ppuVar9 != (uint32_t **)0x0)) {
      ppuVar3 = ppuVar9 + 2;
      ppuVar13 = (uint32_t **)*ppuVar9;
      puVar1 = (uint16_t *)((int)ppuVar9 + 0xe);
      ppuVar9 = (uint32_t **)ppuVar9[1];
      ppuVar10 = (uint32_t **)(uint32_t)*puVar1;
      ppuVar12 = (uint32_t **)*ppuVar3;
    }
    iVar8 = TIMING_SetRxDoneDelay(pbVar11,ppuVar9);
    if (iVar8 != 0) {
      return iVar8;
    }
    iVar8 = TIMING_SetChainDelays(pbVar11,ppuVar13,ppuVar12);
    if (iVar8 != 0) {
      return iVar8;
    }
    TIMING_TxToRxSearchTimeSet(pbVar11,(uint32_t)ppuVar10 & 0xffff);
    TIMING_RecalculateAll(pbVar11);
  }
  *param_1 = *param_1 | 2;
  return 0;
}



void RFHAL_EnableDirectMode(undefined param_1,undefined4 param_2,undefined4 param_3,uint32_t param_4)

{
  uint32_t local_18;
  undefined4 local_14;
  undefined4 local_10;
  uint32_t local_c;
  
  local_18 = (uint32_t)CONCAT11(param_1,param_1);
  local_14 = 0xb020e00;
  local_10 = 0xe09020e;
  local_c = param_4 & 0xffff0000 | 0xa02;
  GENERIC_PHY_ConfigDirectMode(&local_18);
  return;
}



undefined4
RFHAL_OverrideDebugFrequency
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = SYNTH_Config(param_1,0,param_3,param_4,param_4);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 2;
  }
  return uVar2;
}



void RFHAL_ConfigFrameTypeLength(void)

{
  GENERIC_PHY_ConfigureFrameType();
  return;
}



void RFHAL_GetRssi(undefined4 param_1,undefined4 param_2)

{
  RADIO_GetRssi(param_2);
  return;
}



undefined4 RFHAL_SetTune(undefined4 param_1,uint32_t param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint32_t uVar2;
  
  iVar1 = RFHAL_GetRadioState();
  if (iVar1 == 1) {
    CMU_ClockSelectSet(0x11,5);
    CMU_OscillatorEnable(2,0,0);
    BUS_RegMaskedClear(&CMU->HFXOSTEADYSTATECTRL,0xff800);
    uVar2 = (param_2 & 0x1ff) << 0xb;
    BUS_RegMaskedSet(&CMU->HFXOSTEADYSTATECTRL,uVar2);
    CMU_OscillatorEnable(2,1,1,uVar2,param_4);
    CMU_ClockSelectSet(0x11,4);
    return 0;
  }
  return 2;
}



uint32_t RFHAL_GetTune(void)

{
  uint32_t uVar1;
  
  uVar1 = (CMU->HFXOSTEADYSTATECTRL);
  return (uVar1 << 0xc) >> 0x17;
}



void RFHAL_GetTime(void)

{
  undefined4 uVar1;
  
  uVar1 = PROTIMER_GetTime();
  PROTIMER_PrecntOverflowToUs(uVar1,0);
  return;
}



undefined4 RFHAL_SetTime(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = PROTIMER_SetTime();
  if (iVar1 == 0) {
    uVar2 = 2;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



void RFHAL_ConfigAddressFilter(undefined4 param_1,undefined4 param_2)

{
  GENERIC_PHY_ConfigureAddressFiltering(param_1,param_2,1);
  return;
}



void RFHAL_EnableAddressFilter(void)

{
  GENERIC_PHY_EnableAddressFiltering();
  return;
}



void RFHAL_AddressFilterIsEnabled(void)

{
  GENERIC_PHY_IsEnabledAddressFiltering();
  return;
}



void RFHAL_ResetAddressFilter(void)

{
  GENERIC_PHY_ResetAddressFiltering();
  return;
}



void RFHAL_SetAddressFilterAddress(void)

{
  GENERIC_PHY_SetAddress();
  return;
}



void RFHAL_EnableAddressFilterAddress
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  GENERIC_PHY_EnableAddress(param_1,param_3,param_4,param_2);
  return;
}



void RFHAL_GetRadioEntropy(void)

{
  RFRAND_GetRadioEntropy();
  return;
}



int RFHAL_CompensateForDelay(int param_1)

{
  int iVar1;
  
  iVar1 = TIMING_SetChainDelays(param_1 + 0x28);
  if (iVar1 == 0) {
    TIMING_RecalculateAll(param_1 + 0x28);
  }
  return iVar1;
}



undefined4
RFHAL_SetStateTiming(int param_1,undefined2 *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined2 uVar1;
  
  param_1 = param_1 + 0x28;
  uVar1 = TIMING_RxWarmTimeSet(param_1,*param_2,param_3,param_4,param_4);
  *param_2 = uVar1;
  uVar1 = TIMING_TxToRxTimeSet(param_1,param_2[1]);
  param_2[1] = uVar1;
  uVar1 = TIMING_TxWarmTimeSet(param_1,param_2[2]);
  param_2[2] = uVar1;
  uVar1 = TIMING_RxFrameToTxTimeSet(param_1,param_2[3]);
  param_2[3] = uVar1;
  uVar1 = TIMING_RxSearchTimeSet(param_1,param_2[4]);
  param_2[4] = uVar1;
  uVar1 = TIMING_TxToRxSearchTimeSet(param_1,param_2[5]);
  param_2[5] = uVar1;
  TIMING_RecalculateAll(param_1);
  return 0;
}



void RFHAL_ConfigPti(void)

{
  PTI_Config();
  return;
}



void RFHAL_GetPtiConfig(void)

{
  PTI_GetConfig();
  return;
}



void RFHAL_EnablePti(void)

{
  PTI_Enable();
  return;
}



void RFHAL_ShutdownConfig(int param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  
  uVar1 = (BUFC->BUF0_READOFFSET);
  uVar2 = (BUFC->BUF0_THRESHOLDCTRL);
  *(int16_t *)(param_1 + 0x66) = (int16_t)uVar1;
  *(uint8_t *)(param_1 + 0x58) =
       *(uint8_t *)(param_1 + 0x58) & 0xfb | (uint8_t)(((uVar2 << 0x12) >> 0x1f) << 2);
  return;
}



void RFHAL_StartupConfig(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint32_t uVar1;
  int iVar2;
  uint32_t *puVar3;
  uint32_t *puVar4;
  
  write_volatile_4(SEQ->REG024,*(uint32_t *)(param_1 + 0x7c));
  write_volatile_4(SEQ->REG020,*(uint32_t *)(param_1 + 0x88));
  write_volatile_4(SEQ->REG014,*(uint32_t *)(param_1 + 0x80));
  RAILInt_SetChannel(param_1,*(undefined2 *)(param_1 + 2),*(uint32_t *)(param_1 + 0x80),0x21000f24,
                     param_1,param_2,param_3);
  RFHAL_ConfigRxOptions(param_1,0xffffffff,*(undefined4 *)(param_1 + 0x84));
  GENERIC_PHY_ConfigureEvents
            (0xfffffffe,0xffffffff,*(uint32_t *)(param_1 + 0x48) | 0xc000000,
             *(uint32_t *)(param_1 + 0x4c) | 2,0,0);
  RADIO_AGCCCAThresholdSet((int)*(char *)(param_1 + 0x5c));
  RFHAL_ConfigData(param_1,param_1 + 0x76);
  PA_SetCTune(*(undefined *)(param_1 + 0x5a),*(undefined *)(param_1 + 0x5b));
  RFHAL_SetPtiProtocol(param_1,*(undefined *)(param_1 + 0x59));
  GENERIC_PHY_ConfigureAddressFiltering(param_1,*(undefined4 *)(param_1 + 0x90),0);
  RFHAL_ConfigTxPower(param_1,param_1 + 0x60);
  puVar4 = &SEQ->REG02C;
  RFHAL_SetTxPower(param_1,*(undefined *)(param_1 + 0x5e),0);
  RFHAL_SetFreqOffset(param_1,(int)*(int16_t *)(param_1 + 0x74));
  RADIO_TxHoldOffEnable(((uint32_t)*(uint8_t *)(param_1 + 0x58) << 0x1e) >> 0x1f);
  puVar3 = (uint32_t *)(param_1 + 0x98);
  do {
    uVar1 = puVar3[1];
    *puVar4 = *puVar3;
    puVar4[1] = uVar1;
    puVar4 = puVar4 + 2;
    puVar3 = puVar3 + 2;
  } while (puVar3 != (uint32_t *)(param_1 + 0xd8));
  write_volatile_1(SEQ->REG070._0_1_,*(uint8_t *)(param_1 + 0x5d) & 0xf);
  write_volatile_1(SEQ->REG070._1_1_,*(uint8_t *)(param_1 + 0x5d) >> 4);
  if (*(code **)(param_1 + 0x8c) != NULL) {
    (**(code **)(param_1 + 0x8c))(param_1,param_2);
  }
  if (*(uint32_t *)(param_1 + 0x14) != 0) {
    iVar2 = count_leading_zeroes((uint32_t)*(uint16_t *)(param_1 + 0x6a));
    if ((*(uint8_t *)(param_1 + 0x58) & 4) == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 0x2000;
    }
    write_volatile_4(BUFC->BUF0_CTRL,0x19 - iVar2);
    write_volatile_4(BUFC->BUF0_ADDR,*(uint32_t *)(param_1 + 0x14));
    write_volatile_4(BUFC->BUF0_WRITEOFFSET,(uint32_t)*(uint16_t *)(param_1 + 0x68));
    write_volatile_4(BUFC->BUF0_READOFFSET,(uint32_t)*(uint16_t *)(param_1 + 0x66));
    write_volatile_4(BUFC->BUF0_THRESHOLDCTRL,uVar1 | *(uint16_t *)(param_1 + 0x6c));
    write_volatile_4(BUFC->IFC,0xc);
    if ((uint32_t)*(uint16_t *)(param_1 + 0x68) != (uint32_t)*(uint16_t *)(param_1 + 0x66)) {
      write_volatile_4(BUFC->BUF0_CMD,2);
    }
  }
  RFHAL_SetTxFifoThreshold(param_1);
  RFHAL_SetRxFifoThreshold(param_1,*(undefined2 *)(param_1 + 0x6e));
  return;
}



undefined4 RFHAL_InitTimerSync(void)

{
  if (railTimerSync == (undefined **)0x0) {
    railTimerSync = &rtccSync;
    (*(code *)rtccSync)();
  }
  return 0;
}



undefined4 RFHAL_Wake(int param_1)

{
  int iVar1;
  
  if (enableRailTimerSync == '\0') {
    iVar1 = PROTIMER_GetTime();
    PROTIMER_SetTime(iVar1 + param_1);
    PROTIMER_Start();
  }
  else {
    if (railTimerSync == 0) {
      return 3;
    }
    (**(code **)(railTimerSync + 8))();
  }
  return 0;
}



undefined4 RFHAL_Sleep(int param_1,undefined4 param_2,undefined *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = CORE_EnterCritical();
  iVar2 = RFHAL_GetRadioState();
  if (iVar2 == 1) {
    enableRailTimerSync = (undefined)param_1;
    if (param_1 == 0) {
      PROTIMER_Stop();
    }
    else {
      if (railTimerSync == 0) goto LAB_0001192a;
      iVar2 = (**(code **)(railTimerSync + 4))(param_2);
    }
    if (param_3 != NULL) {
      *param_3 = (char)iVar2;
    }
    CORE_ExitCritical(uVar1);
    return 0;
  }
LAB_0001192a:
  CORE_ExitCritical(uVar1);
  return 3;
}



void RFHAL_SetEnableTimerSync(uint8_t *param_1,int param_2)

{
  *param_1 = *param_1 & 0xfb | (uint8_t)(param_2 << 2) & 4;
  return;
}



uint32_t RFHAL_GetEnableTimerSync(uint8_t *param_1)

{
  return ((uint32_t)*param_1 << 0x1d) >> 0x1f;
}



undefined4 RFHAL_EnableTxHoldOff(undefined4 param_1,undefined4 param_2)

{
  RADIO_TxHoldOffEnable(param_2);
  return 0;
}



void RFHAL_IsTxHoldOffEnabled(void)

{
  RADIO_IsTxHoldOffEnabled();
  return;
}



undefined4 RFHAL_EnableRadioStateChanged(int param_1)

{
  if (param_1 == 0) {
    BUS_RegMaskedClear(&RAC->IEN,1);
    write_volatile_4(RAC->IFC,1);
  }
  else {
    write_volatile_4(RAC->IFC,1);
    BUS_RegMaskedSet(&RAC->IEN,1);
  }
  return 0;
}


