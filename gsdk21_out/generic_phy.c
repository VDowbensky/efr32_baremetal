#include "generic_phy.h"



void GENERIC_PHY_ConfigureRollbackReporting(void)

{
  uint *puVar1;
  
  CORE_EnterCritical();
  if ((overrideRxRollback == '\0') && ((enabledRailEvents & 0x1200) == 0)) {
    write_volatile_4(RAC_SR3_CLR,0x10);
LAB_00010022:
    if ((enabledRailEvents & 0x80) == 0) {
      puVar1 = &RAC_SR3_CLR;
      goto LAB_00010036;
    }
  }
  else {
    write_volatile_4(RAC_SR3_SET,0x10);
    if (overrideRxRollback == '\0') goto LAB_00010022;
  }
  puVar1 = &RAC_SR3_SET;
LAB_00010036:
  *puVar1 = 0x20;
  CORE_ExitCritical();
  return;
}



void GENERIC_PHY_ClearPendedRxWindowEnd(void)

{
  pendedRxWindowEnd = 0;
  if (overrideRxRollback != '\0') {
    overrideRxRollback = 0;
    GENERIC_PHY_ConfigureRollbackReporting();
    return;
  }
  pendedRxWindowEnd = 0;
  return;
}



void RADIO_RACRxAbort(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  uint uVar1;
  bool bVar2;
  
  CORE_EnterCritical();
  uVar1 = read_volatile_4(RAC_STATUS);
  uVar1 = (uVar1 << 4) >> 0x1c;
  bVar2 = uVar1 == 3;
  if (bVar2) {
    param_3 = &DAT_21000f7c;
    uVar1 = read_volatile_4(0x21000f80);
    uVar1 = uVar1 & 0xffffff0f | 0xe0;
  }
  if (bVar2) {
    param_3[1] = uVar1;
  }
  write_volatile_4(FRC_CMD,1);
  CORE_ExitCritical();
  return;
}



void GENERIC_PHY_IssueCallback(uint param_1,uint param_2,int param_3)

{
  if (((param_1 | param_2) != 0) || (param_3 != 0)) {
    inCallback = 1;
    GENERIC_PHY_EventCallback();
    inCallback = 0;
  }
  return;
}



void GENERIC_PHY_RxOverflowHook(void)

{
  uint uVar1;
  uint *puVar2;
  
  uVar1 = read_volatile_4(RAC_SR0);
  if (-1 < (int)(uVar1 << 0x18)) {
    write_volatile_4(RAC_CMD,8);
    uVar1 = read_volatile_4(DAT_21000f24);
    if ((uVar1 & 0x200) == 0) {
      puVar2 = &RAC_RXENSRCEN_CLR;
    }
    else {
      puVar2 = &RAC_RXENSRCEN_SET;
    }
    *puVar2 = 2;
  }
  return;
}



void GENERIC_PHY_CheckPendedRxWindowEnd(void)

{
  int iVar1;
  
  if ((pendedRxWindowEnd != '\0') && (iVar1 = BUFC_RxBufferBytesAvailable(), iVar1 == 0)) {
    GENERIC_PHY_ClearPendedRxWindowEnd();
    GENERIC_PHY_IssueCallback(enabledRailEvents & 0x800,0,0);
    return;
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void GENERIC_PHY_DisableRadioIrqs(void)

{
  CORE_EnterCritical();
  _DAT_e000e180 = 0x40000000;
  CORE_ExitCritical();
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void GENERIC_PHY_ConfigureEvents
               (uint param_1,uint param_2,uint param_3,uint param_4,uint param_5,uint param_6)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  param_3 = param_3 & param_1;
  param_4 = param_4 & param_2;
  param_6 = param_6 & param_5;
  if (param_5 == 0) {
    if (param_2 == 0 && param_1 == 1) {
      CORE_EnterCritical();
      DAT_000112fc = DAT_000112fc | param_4;
      enabledRailEvents = enabledRailEvents & 0xfffffffe | param_3;
      uVar3 = 1;
      if ((param_3 | param_4) == 0) {
        write_volatile_4(AGC_IEN_CLR,1);
        write_volatile_4(AGC_IFC,1);
        goto LAB_00010476;
      }
      write_volatile_4(AGC_IFC,1);
      puVar1 = &AGC_IEN_SET;
    }
    else {
      if (param_2 == 0 && param_1 == 0) {
        return;
      }
      if (param_2 != 0 || param_1 != 4) goto LAB_0001025a;
      CORE_EnterCritical();
      enabledRailEvents = enabledRailEvents & 0xfffffffb | param_3;
      DAT_000112fc = DAT_000112fc | param_4;
      if ((param_3 | param_4) == 0) {
        puVar1 = (uint *)&DAT_440810ec;
      }
      else {
        puVar1 = (uint *)&DAT_460810ec;
      }
      uVar3 = 0x400;
    }
  }
  else {
    if (((param_1 | param_2) != 0) || (param_5 != 4)) {
LAB_0001025a:
      GENERIC_PHY_DisableRadioIrqs();
      param_3 = enabledRailEvents & ~param_1 | param_3;
      param_4 = DAT_000112fc & ~param_2 | param_4;
      param_6 = enabledPhyEvents & ~param_5 | param_6;
      enabledPhyEvents = param_6;
      enabledRailEvents = param_3;
      DAT_000112fc = param_4;
      GENERIC_PHY_ConfigureRollbackReporting();
      uVar3 = read_volatile_4(FRC_IEN);
      uVar4 = 0x8002;
      if ((param_3 & 0x2a80000) == 0) {
        uVar4 = 0x8000;
      }
      if ((int)(param_6 << 0x1c) < 0) {
        uVar4 = uVar4 | 0x2000;
      }
      uVar2 = uVar3 & (uVar4 ^ uVar3);
      write_volatile_4(FRC_IEN_CLR,uVar2);
      write_volatile_4(FRC_IFC,uVar2);
      uVar4 = uVar4 & (uVar4 ^ uVar3);
      write_volatile_4(FRC_IFC,uVar4);
      write_volatile_4(FRC_IEN_SET,uVar4);
      if ((param_3 & 0x4000) == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = 0x1000;
      }
      if ((param_3 & 0x8000) != 0) {
        uVar3 = uVar3 | 0x100;
      }
      if ((int)(param_6 << 0x1f) < 0) {
        uVar3 = uVar3 | 0x2000;
      }
      if ((param_3 & 0x10) != 0) {
        uVar3 = uVar3 | 0x200;
      }
      if ((param_3 & 0x20) != 0) {
        uVar3 = uVar3 | 0x400;
      }
      uVar4 = read_volatile_4(MODEM_IEN);
      if ((param_3 & 0x40) != 0) {
        uVar3 = uVar3 | 0x800;
      }
      uVar2 = uVar4 & (uVar3 ^ uVar4);
      write_volatile_4(MODEM_IEN_CLR,uVar2);
      write_volatile_4(MODEM_IFC,uVar2);
      uVar3 = uVar3 & (uVar3 ^ uVar4);
      write_volatile_4(MODEM_IFC,uVar3);
      write_volatile_4(MODEM_IEN_SET,uVar3);
      if ((param_4 & 2) == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = 0x40000;
      }
      if ((param_3 & 0x400) != 0) {
        uVar3 = uVar3 | 0x10000;
      }
      if ((param_3 & 0x2000) != 0) {
        uVar3 = uVar3 | 0x100000;
      }
      if ((param_3 & 2) != 0) {
        uVar3 = uVar3 | 0x200000;
      }
      if ((param_3 & 0x10000) != 0) {
        uVar3 = uVar3 | 0x80000;
      }
      uVar4 = read_volatile_4(RAC_IEN);
      if ((int)(param_6 << 0x1b) < 0) {
        uVar3 = uVar3 | 4;
      }
      uVar2 = (uVar3 ^ uVar4) & 0xfffffffe;
      uVar4 = uVar4 & uVar2;
      write_volatile_4(RAC_IEN_CLR,uVar4);
      write_volatile_4(RAC_IFC,uVar4);
      uVar3 = uVar3 & uVar2;
      write_volatile_4(RAC_IFC,uVar3);
      write_volatile_4(RAC_IEN_SET,uVar3);
      _DAT_40085064 = 0x701800;
      if ((param_6 & 4) != 0) {
        _DAT_40085064 = 0x701c00;
      }
      if ((param_3 & 0x20000000) != 0) {
        _DAT_40085064 = _DAT_40085064 | 0x2000000;
      }
      _DAT_44085068 = _DAT_40085068 & (_DAT_40085064 ^ _DAT_40085068);
      _DAT_40085064 = _DAT_40085064 & (_DAT_40085064 ^ _DAT_40085068);
      uVar3 = read_volatile_4(AGC_IEN);
      uVar4 = uVar3 ^ param_3 & 1;
      uVar3 = uVar3 & uVar4;
      write_volatile_4(AGC_IEN_CLR,uVar3);
      write_volatile_4(AGC_IFC,uVar3);
      uVar4 = param_3 & 1 & uVar4;
      write_volatile_4(AGC_IFC,uVar4);
      write_volatile_4(AGC_IEN_SET,uVar4);
      _DAT_400810e8 = 0x90a0a09;
      if ((param_3 & 0x20000) != 0) {
        _DAT_400810e8 = 0x90a0a0d;
      }
      if ((param_3 & 4) != 0) {
        _DAT_400810e8 = _DAT_400810e8 | 0x400;
      }
      uVar3 = (_DAT_400810e8 ^ _DAT_400810ec) & 0xfffaffff;
      _DAT_440810ec = _DAT_400810ec & uVar3;
      _DAT_400810e8 = _DAT_400810e8 & uVar3;
      _DAT_460810ec = _DAT_400810e8;
      _DAT_46085068 = _DAT_40085064;
      CORE_EnterCritical();
      _DAT_e000e100 = 0x20;
      goto LAB_00010476;
    }
    CORE_EnterCritical();
    enabledPhyEvents = enabledPhyEvents & 0xfffffffb | param_6;
    uVar3 = 0x400;
    if (param_6 == 0) {
      _DAT_44085068 = 0x400;
      _DAT_40085064 = 0x400;
      goto LAB_00010476;
    }
    _DAT_40085064 = 0x400;
    puVar1 = (uint *)&DAT_46085068;
  }
  *puVar1 = uVar3;
LAB_00010476:
  CORE_ExitCritical();
  return;
}



void GENERIC_PHY_PacketTxCommon(void)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = read_volatile_4(FRC_DFLCTRL);
  if (((uVar1 & 7) == 0) && (iVar2 = read_volatile_4(DAT_21000f78), iVar2 != 0)) {
    iVar2 = BUFC_GetBytesAvailable();
    write_volatile_4(FRC_WCNTCMP0,iVar2 - 1);
  }
  write_volatile_4(RAC_SR0_SET,0x80);
  uVar1 = read_volatile_4(DAT_21000f14);
  write_volatile_4(DAT_21000f14,uVar1 & 0xffffffbf);
  return;
}



undefined4 GENERIC_PHY_PacketTx(void)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = CORE_EnterCritical();
  iVar2 = PROTIMER_CCTimerIsEnabled(3);
  if ((iVar2 == 0) && (iVar2 = PROTIMER_LBTIsActive(), iVar2 == 0)) {
    GENERIC_PHY_PacketTxCommon();
    write_volatile_4(RAC_CMD,1);
    CORE_ExitCritical(uVar1);
    return 0;
  }
  CORE_ExitCritical(uVar1);
  return 1;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined4
GENERIC_PHY_SchedulePacketRx
          (int param_1,undefined4 param_2,int param_3,int param_4,char param_5,char param_6,
          undefined param_7)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  
  uVar1 = CORE_EnterCritical();
  if (param_3 != 2) {
    iVar2 = PROTIMER_CCTimerIsEnabled(3);
    if (iVar2 != 0) goto LAB_00010624;
    PROTIMER_ClearRxEnable();
    PROTIMER_ClearTxEnable();
    scheduledRxLoop = param_6;
    uVar3 = read_volatile_4(DAT_21000f14);
    if (param_6 == '\0') {
      uVar3 = uVar3 & 0xffffffbf;
    }
    else {
      uVar3 = uVar3 | 0x40;
    }
    write_volatile_4(DAT_21000f14,uVar3);
    iVar2 = PROTIMER_ScheduleRxEnable(3,param_2,param_3);
    if (iVar2 == 0) {
      CORE_ExitCritical(uVar1);
      return 1;
    }
  }
  if (param_5 != '\x02') {
    iVar2 = PROTIMER_CCTimerIsEnabled(3);
    if ((iVar2 != 0) || (uVar3 = read_volatile_4(RAC_STATUS), (int)(uVar3 << 0x11) < 0)) {
      scheduledRxHardEnd = param_7;
      if ((param_5 == '\x01') && (param_3 != 2)) {
        param_4 = param_4 + PROTIMER_scheduledRxEnable;
        uVar4 = PROTIMER_UsToPrecntOverflow(*(undefined2 *)(param_1 + 0x38));
        param_4 = PROTIMER_WrapMultiple
                            ((int)uVar4 + param_4,(int)((ulonglong)uVar4 >> 0x20),_DAT_40085030 + 1,
                             0xfffffffe < _DAT_40085030);
        param_5 = '\0';
      }
      GENERIC_PHY_ClearPendedRxWindowEnd();
      iVar2 = PROTIMER_ScheduleRxDisable(4,param_4,param_5);
      if (iVar2 != 0) {
        if (param_6 != '\0') {
          overrideRxRollback = 1;
          write_volatile_4(RAC_SR3_SET,5);
        }
        goto LAB_0001063e;
      }
      PROTIMER_CCTimerStop(3);
      PROTIMER_ClearRxEnable();
    }
LAB_00010624:
    CORE_ExitCritical(uVar1);
    return 3;
  }
LAB_0001063e:
  CORE_ExitCritical(uVar1);
  return 0;
}



undefined4 GENERIC_PHY_SchedulePacketTx(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  char cVar4;
  
  uVar1 = PROTIMER_UsToPrecntOverflow(*param_1);
  uVar2 = CORE_EnterCritical();
  iVar3 = PROTIMER_CCTimerIsEnabled(3);
  if ((iVar3 != 0) || (iVar3 = PROTIMER_LBTIsActive(), iVar3 != 0)) {
    CORE_ExitCritical(uVar2);
    return 3;
  }
  GENERIC_PHY_PacketTxCommon();
  PROTIMER_ClearRxEnable();
  PROTIMER_ClearTxEnable();
  RFHAL_SetAbortScheduledTxDuringRx(*(char *)((int)param_1 + 5) == '\x01');
  cVar4 = *(char *)(param_1 + 1);
  if (cVar4 != '\0') {
    cVar4 = '\x01';
  }
  iVar3 = PROTIMER_ScheduleTxEnable(3,uVar1,cVar4);
  if (iVar3 == 0) {
    write_volatile_4(RAC_SR0_CLR,0x80);
    CORE_ExitCritical(uVar2);
    return 1;
  }
  CORE_ExitCritical(uVar2);
  return 0;
}



void GENERIC_PHY_StopTx(void)

{
  write_volatile_4(RAC_CMD,8);
  return;
}



void GENERIC_PHY_StartRx(int param_1)

{
  uint uVar1;
  
  if (param_1 != 0) {
    write_volatile_4(FRC_WCNTCMP0,param_1 - 1);
  }
  CORE_EnterCritical();
  uVar1 = read_volatile_4(DAT_21000f14);
  write_volatile_4(DAT_21000f14,uVar1 & 0xffffffbf);
  CORE_ExitCritical();
  write_volatile_4(RAC_RXENSRCEN_SET,2);
  return;
}



void GENERIC_PHY_ChannelSet(undefined4 param_1)

{
  SYNTH_ChannelSet(param_1,1);
  return;
}



void GENERIC_PHY_SeqAtomicLock(void)

{
  uint uVar1;
  
  write_volatile_4(RAC_SR0_SET,4);
  while (uVar1 = read_volatile_4(RAC_SR0), (int)(uVar1 << 0xd) < 0) {
    write_volatile_4(RAC_SR0_CLR,4);
    PROTIMER_DelayUs(2);
    write_volatile_4(RAC_SR0_SET,4);
  }
  return;
}



void GENERIC_PHY_SeqAtomicUnlock(void)

{
  write_volatile_4(RAC_SR0_CLR,4);
  return;
}



void GENERIC_PHY_TxDisable(void)

{
  write_volatile_4(RAC_CMD,0x20);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined4 GENERIC_PHY_PreviousTxTime(void)

{
  return _DAT_40085090;
}



void GENERIC_PHY_RACConfig(void)

{
  RADIO_SeqInit(&genericSeqProg,genericSeqProg_size);
  memset(&DAT_21000f14,0,0x68);
  write_volatile_4(RAC_SR0,0);
  write_volatile_4(RAC_SR1,0);
  write_volatile_4(RAC_SR2,0);
  TEMPCAL_Init();
  return;
}



void GENERIC_PHY_ConfigDirectMode(byte *param_1)

{
  uint uVar1;
  
  if (param_1 != (byte *)0x0) {
    RADIOCMU_ClockEnable(0x67400,1);
    CMU_ClockEnable(0x82500,1);
    uVar1 = (uint)*param_1;
    write_volatile_4(MODEM_CTRL2_CLR,0xc00);
    if (uVar1 == 0) {
      write_volatile_4(MODEM_CTRL2_SET,0);
    }
    else {
      uVar1 = (uint)param_1[4];
      if (uVar1 == 0) {
        write_volatile_4(MODEM_CTRL2_SET,0x800);
      }
      else {
        write_volatile_4(MODEM_CTRL2_SET,0xc00);
        uVar1 = 4;
      }
      uVar1 = uVar1 | 1;
    }
    if (param_1[1] != 0) {
      write_volatile_4(MODEM_CTRL2_CLR,0x200);
      if (param_1[3] == 0) {
        write_volatile_4(MODEM_CTRL2_SET,0x200);
      }
      else {
        write_volatile_4(MODEM_CTRL2_SET,0);
        uVar1 = uVar1 | 4;
      }
      uVar1 = uVar1 | 2;
    }
    if (param_1[2] == 0) {
      write_volatile_4(MODEM_CTRL2_CLR,0x100);
    }
    else {
      write_volatile_4(MODEM_CTRL2_SET,0x100);
    }
    write_volatile_4(MODEM_ROUTELOC0,
                     (uint)param_1[8] << 0x10 | (uint)param_1[5] << 8 | (uint)param_1[0xb]);
    write_volatile_4(MODEM_ROUTEPEN_CLR,7);
    write_volatile_4(MODEM_ROUTEPEN_SET,uVar1);
    if ((int)(uVar1 << 0x1f) < 0) {
      GPIO_PinModeSet(param_1[0xc],param_1[0xd],1,0);
    }
    if ((int)(uVar1 << 0x1e) < 0) {
      GPIO_PinModeSet(param_1[6],param_1[7],4,0);
    }
    if ((int)(uVar1 << 0x1d) < 0) {
      GPIO_PinModeSet(param_1[9],param_1[10],4,0);
      return;
    }
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void GENERIC_PHY_PROTIMERConfig(void)

{
  _DAT_40085000 = 0;
  _DAT_40085014 = 0;
  _DAT_40085018 = 0;
  _DAT_4008502c = 0xffff;
  _DAT_40085030 = 0xffffffff;
  _DAT_4008504c = 0;
  _DAT_40085064 = 0x3f3fff7;
  _DAT_44085068 = 0x3f3fff7;
  return;
}



uint GENERIC_PHY_ChannelGet(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(SYNTH_CHCTRL);
  return uVar1 & 0xff;
}



int GENERIC_PHY_ReleaseRxPacket(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = BUFC_ReleaseRxPacket();
  if ((inCallback == '\0') && (iVar1 == 0)) {
    uVar2 = CORE_EnterCritical();
    GENERIC_PHY_CheckPendedRxWindowEnd();
    CORE_ExitCritical(uVar2);
  }
  return iVar1;
}



void GENERIC_PHY_ResetRxFifo(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 uVar2;
  
  uVar1 = CORE_EnterCritical();
  BUFC_RxBufferReset();
  if (param_1 == 0) {
    uVar2 = extraout_r1;
    if (inCallback == '\0') {
      GENERIC_PHY_CheckPendedRxWindowEnd();
      uVar2 = extraout_r1_01;
    }
  }
  else {
    GENERIC_PHY_ClearPendedRxWindowEnd();
    uVar2 = extraout_r1_00;
  }
  CORE_ExitCritical(uVar1,uVar2,param_3,param_4);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void GENERIC_PHY_RadioIdle(int param_1,int param_2,int param_3)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = CORE_EnterCritical();
  if ((param_1 != 0) || (param_2 != 0)) {
    do {
      uVar1 = read_volatile_4(RAC_STATUS);
      if ((uVar1 << 4) >> 0x1c != 3) break;
      uVar1 = read_volatile_4(DAT_21000f7c);
    } while ((uVar1 & 0xf) != 3);
    if (param_2 != 0) {
      GENERIC_PHY_SeqAtomicLock();
      write_volatile_4(RAC_CTRL_SET,1);
      write_volatile_4(RAC_SR0_CLR,4);
      while (uVar1 = read_volatile_4(RAC_STATUS), (uVar1 & 0xf000000) != 0) {
        RADIO_RACClearRxOverflow();
      }
    }
  }
  write_volatile_4(RAC_SR0_CLR,0x80);
  iVar3 = PROTIMER_CCTimerIsEnabled(3);
  if (iVar3 != 0) {
    PROTIMER_CCTimerStop(3);
    PROTIMER_CCTimerStop(4);
  }
  PROTIMER_ClearRxEnable();
  PROTIMER_ClearTxEnable();
  GENERIC_PHY_SeqAtomicLock();
  uVar1 = read_volatile_4(DAT_21000f14);
  write_volatile_4(DAT_21000f14,uVar1 | 0x40);
  write_volatile_4(RAC_RXENSRCEN_CLR,0xff);
  write_volatile_4(RAC_CMD,0x100);
  write_volatile_4(RAC_SR0_CLR,4);
  if (param_1 != 0) {
    RADIO_RACRxAbort();
    PROTIMER_LBTStop();
    write_volatile_4(RAC_CMD,0x20);
    PROTIMER_CCTimerStop(4);
  }
  if (param_2 != 0) {
    GENERIC_PHY_ResetRxFifo(param_3);
    write_volatile_4(RAC_CTRL_CLR,1);
    if (param_3 != 0) {
      uVar1 = read_volatile_4(FRC_IEN);
      write_volatile_4(FRC_IFC,uVar1);
      uVar1 = read_volatile_4(RAC_IEN);
      write_volatile_4(RAC_IFC,uVar1);
      uVar1 = read_volatile_4(MODEM_IEN);
      write_volatile_4(MODEM_IFC,uVar1);
      uVar1 = read_volatile_4(SYNTH_IEN);
      write_volatile_4(SYNTH_IFC,uVar1);
      _DAT_400810e8 = _DAT_400810ec;
      uVar1 = read_volatile_4(AGC_IEN);
      write_volatile_4(AGC_IFC,uVar1);
      _DAT_40085064 = 0x2f00050;
      GENERIC_PHY_ClearPendedRxWindowEnd();
    }
  }
  CORE_ExitCritical(uVar2);
  return;
}



void RAILCb_RadioStateChanged(void)

{
  write_volatile_4(RAC_IEN_CLR,1);
  write_volatile_4(RAC_IFC,1);
  return;
}



void RAC_RSM_IRQHandler(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = read_volatile_4(RAC_IF);
  uVar2 = read_volatile_4(RAC_IEN);
  uVar2 = uVar2 & uVar1;
  write_volatile_4(RAC_IFC,uVar2 & 0xffff);
  if ((int)(uVar2 << 0x1f) < 0) {
    uVar1 = read_volatile_4(RAC_STATUS);
    RAILCb_RadioStateChanged((uVar1 << 4) >> 0x1c);
  }
  if ((int)(uVar2 << 0x1d) < 0) {
    GENERIC_PHY_IssueCallback(0,0,enabledPhyEvents & 0x10);
    return;
  }
  return;
}



void AGC_IRQHandler(void)

{
  uint uVar1;
  uint uVar2;
  undefined4 in_r3;
  
  uVar1 = read_volatile_4(AGC_IF);
  uVar2 = read_volatile_4(AGC_IEN);
  write_volatile_4(AGC_IFC,uVar1 & uVar2);
  if ((int)((uVar1 & uVar2) << 0x1f) < 0) {
    RAILInt_Assert((byte)enabledRailEvents & 1,0x12);
    GENERIC_PHY_IssueCallback(1,0,0,in_r3);
    return;
  }
  return;
}



void SYNTH_IRQHandler(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = read_volatile_4(SYNTH_IF);
  uVar2 = read_volatile_4(SYNTH_IEN);
  write_volatile_4(SYNTH_IFC,uVar1 & uVar2);
  return;
}



uint GENERIC_PHY_SetFeatures(undefined4 param_1,uint param_2,uint param_3)

{
  uint uVar1;
  
  CORE_EnterCritical();
  uVar1 = read_volatile_4(DAT_21000f14);
  write_volatile_4(DAT_21000f14,param_3 & param_2 | uVar1 & ~param_2);
  CORE_ExitCritical();
  return param_2 & uVar1;
}



void GENERIC_PHY_ConfigureFrameType(undefined4 param_1,undefined4 *param_2,undefined4 param_3)

{
  byte bVar1;
  undefined4 *local_1c;
  undefined4 uStack24;
  
  uStack24 = param_3;
  if (param_2 == (undefined4 *)0x0) {
    local_1c = param_2;
    GENERIC_PHY_SetFeatures(param_1,7,0);
    write_volatile_4(DAT_21000f74,0);
    write_volatile_4(DAT_21000f78,0);
  }
  else {
    write_volatile_4(FRC_DFLCTRL_CLR,7);
    write_volatile_4(FRC_DFLCTRL_SET,0);
    write_volatile_1(DAT_21000f74._0_1_,*(undefined *)(param_2 + 1));
    local_1c = (undefined4 *)(uint)*(byte *)((int)param_2 + 5);
    bVar1 = CORTEX_UTILS_BitsetLowestSetBit(&local_1c,1,0,local_1c,param_1);
    write_volatile_1(DAT_21000f74._1_1_,bVar1 & 0xf | (byte)(((uint)local_1c >> (uint)bVar1) << 4));
    write_volatile_1(DAT_21000f74._2_1_,*(undefined *)((int)param_2 + 6));
    write_volatile_1(DAT_21000f74._3_1_,*(undefined *)((int)param_2 + 7));
    write_volatile_4(DAT_21000f78,*param_2);
    write_volatile_4(FRC_WCNTCMP0,*(byte *)(param_2 + 1) + 1);
    GENERIC_PHY_SetFeatures(param_1,7,7);
  }
  return;
}



int GENERIC_PHY_EnableAddressFiltering
              (undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0x10;
  }
  iVar1 = GENERIC_PHY_SetFeatures(param_1,0x10,uVar2,param_4,param_4);
  if (iVar1 != 0) {
    iVar1 = 1;
  }
  return iVar1;
}



uint GENERIC_PHY_IsEnabledAddressFiltering(void)

{
  int iVar1;
  
  iVar1 = read_volatile_4(DAT_21000f14);
  return (uint)(iVar1 << 0x1b) >> 0x1f;
}



void GENERIC_PHY_ResetAddressFiltering(void)

{
  memset(&DAT_21000f28,0,0x4c);
  return;
}



void GENERIC_PHY_Init(int param_1)

{
  int iVar1;
  
  RADIO_Init();
  GENERIC_PHY_DisableRadioIrqs();
  GENERIC_PHY_RACConfig();
  PTI_Enable(1);
  BUFC_Init(GENERIC_PHY_RxOverflowHook);
  write_volatile_4(RAC_CTRL_CLR,1);
  GENERIC_PHY_ResetAddressFiltering(param_1);
  PROTIMER_Init();
  PROTIMER_Start();
  TIMING_InitStimer();
  TIMING_RecalculateAll(param_1 + 0x28);
  PROTIMER_CCTimerCapture(0,0xc00000);
  PROTIMER_CCTimerCapture(1,0x200000);
  SYNTH_DCDCRetimeDisable();
  iVar1 = RFRAND_SeedProtimerRandom();
  if (iVar1 == 0) {
    RAILInt_Assert(0,0x14);
  }
  SYNTH_DCDCRetimeEnable();
  return;
}



undefined4 GENERIC_PHY_ConfigureAddressFiltering(undefined4 param_1,undefined *param_2,int param_3)

{
  if (param_3 != 0) {
    GENERIC_PHY_ResetAddressFiltering();
  }
  if (param_2 == (undefined *)0x0) {
    return 0;
  }
  write_volatile_1(DAT_21000f6c,*param_2);
  if ((byte)param_2[2] < 9) {
    write_volatile_1(DAT_21000f6e,param_2[2]);
    write_volatile_1(DAT_21000f6d,param_2[1]);
    if ((byte)param_2[3] < 9) {
      write_volatile_1(DAT_21000f6f,param_2[3]);
      write_volatile_4(DAT_21000f28,*(undefined4 *)(param_2 + 4));
      return 0;
    }
  }
  return 1;
}



undefined4 GENERIC_PHY_EnableAddress(undefined4 param_1,uint param_2,uint param_3,int param_4)

{
  byte bVar1;
  
  if ((param_2 < 2) && (param_3 < 4)) {
    bVar1 = (byte)(1 << (param_3 & 0xff));
    if (param_4 == 0) {
      bVar1 = (&DAT_21000f70)[param_2] & ~bVar1;
    }
    else {
      bVar1 = bVar1 | (&DAT_21000f70)[param_2];
    }
    (&DAT_21000f70)[param_2] = bVar1;
    return 0;
  }
  return 1;
}



undefined4
GENERIC_PHY_SetAddressData
          (undefined4 param_1,uint param_2,uint param_3,uint param_4,byte param_5,byte param_6,
          byte *param_7)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  
  uVar3 = (uint)param_5;
  uVar2 = (uint)param_6;
  if ((((param_2 < 2) && (param_3 < 2)) && (uVar3 < uVar2)) &&
     (((uVar2 < 9 && (param_4 < 4)) && (param_7 != (byte *)0x0)))) {
    GENERIC_PHY_EnableAddress(param_1,param_2,param_4,0);
    puVar1 = (uint *)((uVar3 + 0x84003ca + param_3 * 8) * 4);
    for (pbVar4 = param_7; (int)(pbVar4 + (uVar3 - (int)param_7)) < (int)uVar2; pbVar4 = pbVar4 + 1)
    {
      puVar1 = puVar1 + 1;
      *puVar1 = (uint)*pbVar4 << (param_4 << 3 & 0xff) | ~(0xff << (param_4 << 3 & 0xff)) & *puVar1;
    }
    return 0;
  }
  return 1;
}



int GENERIC_PHY_SetIeeePanId(undefined4 param_1,uint param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined8 uVar4;
  
  uVar4 = GENERIC_PHY_SetAddressData();
  puVar2 = (undefined4 *)((ulonglong)uVar4 >> 0x20);
  iVar1 = (int)uVar4;
  iVar3 = iVar1;
  if (iVar1 == 0) {
    if (param_2 < 4) {
      puVar2 = &DAT_21000f28;
    }
    iVar3 = 1;
    if (param_2 < 4) {
      *(byte *)(puVar2 + 0x12) = (byte)(1 << (param_2 & 0xff)) | *(byte *)(puVar2 + 0x12);
      iVar3 = iVar1;
    }
  }
  return iVar3;
}



int GENERIC_PHY_SetIeeeShortAddress
              (undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined8 uVar4;
  
  uVar4 = GENERIC_PHY_SetAddressData(param_1,1,0,param_2,2,4,param_3,param_4);
  puVar2 = (undefined4 *)((ulonglong)uVar4 >> 0x20);
  iVar1 = (int)uVar4;
  iVar3 = iVar1;
  if (iVar1 == 0) {
    if (param_2 < 4) {
      puVar2 = &DAT_21000f28;
    }
    iVar3 = 1;
    if (param_2 < 4) {
      *(byte *)((int)puVar2 + 0x49) = (byte)(1 << (param_2 & 0xff)) | *(byte *)((int)puVar2 + 0x49);
      iVar3 = iVar1;
    }
  }
  return iVar3;
}



int GENERIC_PHY_SetIeeeLongAddress(undefined4 param_1,uint param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined8 uVar4;
  
  uVar4 = GENERIC_PHY_SetAddressData();
  puVar2 = (undefined4 *)((ulonglong)uVar4 >> 0x20);
  iVar1 = (int)uVar4;
  iVar3 = iVar1;
  if (iVar1 == 0) {
    if (param_2 < 4) {
      puVar2 = &DAT_21000f28;
    }
    iVar3 = 1;
    if (param_2 < 4) {
      *(byte *)((int)puVar2 + 0x49) = (byte)(1 << (param_2 & 0xff)) | *(byte *)((int)puVar2 + 0x49);
      iVar3 = iVar1;
    }
  }
  return iVar3;
}



void GENERIC_PHY_SetAddress
               (undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,char param_5)

{
  int iVar1;
  
  iVar1 = GENERIC_PHY_SetAddressData
                    (param_1,param_2,param_2,param_3,0,(&DAT_21000f6e)[param_2],param_4);
  if ((param_5 != '\0') && (iVar1 == 0)) {
    GENERIC_PHY_EnableAddress(param_1,param_2,param_3,1);
    return;
  }
  return;
}



int GENERIC_PHY_EnableIEEE802154
              (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = GENERIC_PHY_SetFeatures(param_1,0x80,0x80,param_4,param_4);
  if (iVar1 != 0) {
    iVar1 = 1;
  }
  return iVar1;
}



int GENERIC_PHY_DisableIEEE802154
              (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = GENERIC_PHY_SetFeatures(param_1,0x80,0,param_4,param_4);
  if (iVar1 != 0) {
    iVar1 = 1;
  }
  return iVar1;
}



uint GENERIC_PHY_IsEnabledIEEE802154(void)

{
  int iVar1;
  
  iVar1 = read_volatile_4(DAT_21000f14);
  return (uint)(iVar1 << 0x18) >> 0x1f;
}



void GENERIC_PHY_TimerStart(undefined4 param_1,undefined4 param_2)

{
  PROTIMER_CCTimerStart(2,param_1,param_2);
  return;
}



void GENERIC_PHY_TimerStop(void)

{
  PROTIMER_CCTimerStop(2);
  return;
}



void GENERIC_PHY_GetTimerTimeout(void)

{
  PROTIMER_GetCCTime(2);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

uint GENERIC_PHY_IsTimerExpired(void)

{
  return (uint)(_DAT_4008505c << 0x15) >> 0x1f;
}



void GENERIC_PHY_IsTimerRunning(void)

{
  PROTIMER_CCTimerIsEnabled(2);
  return;
}



bool GENERIC_PHY_CanModifyAck(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(RAC_STATUS);
  uVar1 = (uVar1 << 4) >> 0x1c;
  if (1 < uVar1 - 2) {
    return uVar1 == 7;
  }
  return true;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FRC_IRQHandler(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  uVar9 = read_volatile_4(FRC_IF);
  uVar6 = read_volatile_4(FRC_IEN);
  uVar6 = uVar6 & uVar9;
  write_volatile_4(FRC_IFC,uVar6);
  uVar7 = _DAT_400810ec & _DAT_400810e0;
  uVar9 = read_volatile_4(MODEM_IF);
  uVar10 = read_volatile_4(MODEM_IEN);
  uVar10 = uVar10 & uVar9;
  write_volatile_4(MODEM_IFC,uVar10);
  uVar9 = read_volatile_4(RAC_IF);
  uVar8 = read_volatile_4(RAC_IEN);
  uVar8 = uVar8 & uVar9;
  write_volatile_4(RAC_IFC,uVar8 & 0xffff0000);
  _DAT_400810e8 = uVar7;
  iVar1 = PROTIMER_LBTIsActive();
  uVar9 = _DAT_40085068 & _DAT_4008505c;
  _DAT_40085064 = uVar9 & 0xfffff7ff;
  if (uVar6 == 0) {
    uVar4 = 0;
  }
  else {
    if ((int)(uVar6 << 0x10) < 0) {
      uVar4 = read_volatile_4(RAC_SR0);
      write_volatile_4(RAC_SR0_CLR,uVar4 & 0x1c00);
      write_volatile_4(RAC_SR0_CLR,0x80);
      write_volatile_4(RAC_RXENSRCEN_CLR,0x10);
      if ((uVar4 & 0x1c00) == 0) {
        uVar4 = 0x40000;
      }
      else {
        if ((int)(uVar4 << 0x13) < 0) {
          uVar4 = 0x1000000;
        }
        else {
          if ((int)(uVar4 << 0x15) < 0) {
            uVar4 = 0x100000;
          }
          else {
            uVar4 = 0x400000;
          }
        }
      }
    }
    else {
      uVar4 = 0;
    }
    if ((int)(uVar6 << 0x1e) < 0) {
      uVar5 = read_volatile_4(RAC_SR0);
      write_volatile_4(RAC_SR0_CLR,uVar5 & 0xe000);
      if ((uVar5 & 0xe000) == 0) {
        uVar4 = uVar4 | 0x80000;
      }
      else {
        if ((int)(uVar5 << 0x10) < 0) {
          uVar4 = uVar4 | 0x2000000;
        }
        else {
          if ((int)(uVar5 << 0x12) < 0) {
            uVar4 = uVar4 | 0x200000;
          }
          else {
            uVar4 = uVar4 | 0x800000;
          }
        }
      }
    }
    if ((uVar6 & 0x2000) == 0) {
      uVar6 = 0;
    }
    else {
      uVar6 = 8;
    }
  }
  uVar5 = 0;
  if ((uVar7 & 0x90b0a09) != 0) {
    if ((uVar7 & 0xa00) != 0) {
      GENERIC_PHY_ResetRxFifo(0);
      uVar7 = uVar7 & 0xfffbffff;
      RAILInt_Assert(0,6);
    }
    if ((uVar7 & 9) != 0) {
      write_volatile_4(RAC_CMD,0x20);
      _DAT_40081028 = 1;
      RAILInt_Assert(0,8);
    }
    if ((uVar7 & 0x9000000) != 0) {
      write_volatile_4(RAC_CMD,0x20);
      BUFC_TxAckBufferReset();
      RAILInt_Assert(0,9);
    }
    if ((uVar7 & 0xa0000) != 0) {
      GENERIC_PHY_ResetRxFifo(0);
      uVar7 = uVar7 & 0xfffbffff;
      RAILInt_Assert(0,7);
    }
    if ((int)(uVar7 << 0xf) < 0) {
      BUFC_HandleRxLenOvfEvent();
    }
  }
  if ((int)(uVar7 << 0x1d) < 0) {
    if (_DAT_430204b4 == 0) {
      _DAT_46081024 = 0x2000;
    }
    else {
      uVar4 = uVar4 | 0x20000;
      _DAT_44081024 = 0x2000;
    }
  }
  if ((int)(uVar7 << 0x15) < 0) {
    uVar4 = uVar4 | 4;
  }
  if ((uVar7 & 0x40000) != 0) {
    uVar2 = BUFC_StartRxLenThrEvent();
    switch(uVar2) {
    case 1:
    case 3:
      uVar4 = uVar4 | 0x1000;
      break;
    case 2:
      uVar4 = uVar4 | 0x200;
      break;
    case 4:
      uVar4 = uVar4 | 0x100;
      break;
    case 5:
      uVar4 = uVar4 | 0x80;
      break;
    case 6:
    case 7:
      uVar4 = uVar4 | 8;
      break;
    default:
      RAILInt_Assert(0,3);
    }
  }
  if (uVar10 != 0) {
    if ((uVar10 & 0x1000) != 0) {
      uVar4 = uVar4 | 0x4000;
    }
    if ((uVar10 & 0x100) != 0) {
      uVar4 = uVar4 | 0x8000;
    }
    if ((uVar10 & 0x2000) != 0) {
      uVar6 = uVar6 | 1;
    }
    if ((uVar10 & 0x200) != 0) {
      uVar4 = uVar4 | 0x10;
    }
    if ((uVar10 & 0x400) != 0) {
      uVar4 = uVar4 | 0x20;
    }
    if ((uVar10 & 0x800) != 0) {
      uVar4 = uVar4 | 0x40;
    }
  }
  if (uVar8 != 0) {
    if ((uVar8 & 0x2000000) != 0) {
      uVar6 = uVar6 | 0x20;
    }
    if ((uVar8 & 0x4000000) != 0) {
      uVar6 = uVar6 | 0x40;
    }
    if ((uVar8 & 0x8000000) != 0) {
      uVar6 = uVar6 | 0x80;
    }
    if ((uVar8 & 0x40000) != 0) {
      uVar5 = 2;
    }
    if ((uVar8 & 0x10000) != 0) {
      uVar4 = uVar4 | 0x400;
    }
    if ((uVar8 & 0x100000) != 0) {
      uVar4 = uVar4 | 0x2000;
    }
    if ((uVar8 & 0x200000) != 0) {
      uVar4 = uVar4 | 2;
    }
    if (((uVar8 & 0x80000) != 0) && (iVar3 = GENERIC_PHY_CanModifyAck(), iVar3 != 0)) {
      uVar4 = uVar4 | 0x10000;
    }
  }
  if (uVar9 == 0) goto LAB_0001126e;
  if ((uVar9 & 0x800) != 0) {
    PROTIMER_CCTimerStop(3);
    _DAT_4408506c = 0x1f1f;
    _DAT_40085064 = 0x800;
    PROTIMER_ClearTxEnable();
  }
  if ((uVar9 & 0x2000000) != 0) {
    PTI_AuxdataOutput(0x2b);
    uVar4 = uVar4 | 0x20000000;
  }
  if ((uVar9 & 0x700000) == 0) {
    if ((uVar9 & 0x1000) != 0) {
      if (iVar1 != 0) goto LAB_00011158;
      PROTIMER_CCTimerStop(4);
      PROTIMER_CCTimerStop(3);
      PROTIMER_ClearRxEnable();
      uVar2 = CORE_EnterCritical();
      if (scheduledRxHardEnd != '\0') {
        RADIO_RACRxAbort();
      }
      iVar1 = BUFC_RxBufferBytesAvailable();
      uVar10 = read_volatile_4(RAC_STATUS);
      if (((uVar10 << 4) >> 0x1c == 3) || (iVar1 != 0)) {
        iVar1 = 1;
        pendedRxWindowEnd = scheduledRxLoop;
      }
      CORE_ExitCritical(uVar2);
      if (iVar1 == 0) {
        overrideRxRollback = 0;
        GENERIC_PHY_ConfigureRollbackReporting();
        uVar10 = 0x800;
      }
      else {
        uVar10 = 0;
      }
      uVar4 = uVar4 | uVar10;
    }
  }
  else {
LAB_00011158:
    uVar9 = PROTIMER_CheckCcaReallyFailed(uVar9);
    if ((uVar9 & 0x200000) != 0) {
      PTI_AuxdataOutput(0x29);
      uVar4 = uVar4 | 0x10000000;
    }
    if ((uVar9 & 0x400000) == 0) {
      if ((uVar9 & 0x100000) == 0) {
        if ((uVar9 & 0x1000) != 0) {
          PROTIMER_CCTimerStop(4);
          PROTIMER_LBTStop();
          if ((_DAT_4008505c & 0x500000) == 0) {
            PTI_AuxdataOutput(0x2a);
            _DAT_40081028 = 1;
            goto LAB_000111f2;
          }
        }
      }
      else {
        PROTIMER_CCTimerStop(4);
        PTI_AuxdataOutput(0x28);
        uVar4 = uVar4 | 0x4000000;
      }
    }
    else {
      PROTIMER_CCTimerStop(4);
      PTI_AuxdataOutput(0x27);
      write_volatile_4(RAC_SR0_CLR,0x80);
      write_volatile_4(RAC_RXENSRCEN_CLR,0x10);
LAB_000111f2:
      uVar4 = uVar4 | 0x8000000;
    }
  }
  if ((uVar9 & 0x400) != 0) {
    PROTIMER_CCTimerStop(2);
    uVar6 = uVar6 | 4;
  }
LAB_0001126e:
  GENERIC_PHY_IssueCallback(enabledRailEvents & uVar4,DAT_000112fc & uVar5,enabledPhyEvents & uVar6)
  ;
  if ((uVar7 & 0x40000) != 0) {
    BUFC_EndRxLenThrEvent();
    GENERIC_PHY_CheckPendedRxWindowEnd();
  }
  if (uVar8 != 0) {
    if ((uVar8 & 0x2000000) != 0) {
      PA_RunPeakDetectorHigh();
    }
    if ((uVar8 & 0x4000000) != 0) {
      PA_RunPeakDetectorLow();
    }
    if ((uVar8 & 0x8000000) != 0) {
      PA_RunBatHigh();
      return;
    }
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FRC_PRI_IRQHandler(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  uVar9 = read_volatile_4(FRC_IF);
  uVar6 = read_volatile_4(FRC_IEN);
  uVar6 = uVar6 & uVar9;
  write_volatile_4(FRC_IFC,uVar6);
  uVar7 = _DAT_400810ec & _DAT_400810e0;
  uVar9 = read_volatile_4(MODEM_IF);
  uVar10 = read_volatile_4(MODEM_IEN);
  uVar10 = uVar10 & uVar9;
  write_volatile_4(MODEM_IFC,uVar10);
  uVar9 = read_volatile_4(RAC_IF);
  uVar8 = read_volatile_4(RAC_IEN);
  uVar8 = uVar8 & uVar9;
  write_volatile_4(RAC_IFC,uVar8 & 0xffff0000);
  _DAT_400810e8 = uVar7;
  iVar1 = PROTIMER_LBTIsActive();
  uVar9 = _DAT_40085068 & _DAT_4008505c;
  _DAT_40085064 = uVar9 & 0xfffff7ff;
  if (uVar6 == 0) {
    uVar4 = 0;
  }
  else {
    if ((int)(uVar6 << 0x10) < 0) {
      uVar4 = read_volatile_4(RAC_SR0);
      write_volatile_4(RAC_SR0_CLR,uVar4 & 0x1c00);
      write_volatile_4(RAC_SR0_CLR,0x80);
      write_volatile_4(RAC_RXENSRCEN_CLR,0x10);
      if ((uVar4 & 0x1c00) == 0) {
        uVar4 = 0x40000;
      }
      else {
        if ((int)(uVar4 << 0x13) < 0) {
          uVar4 = 0x1000000;
        }
        else {
          if ((int)(uVar4 << 0x15) < 0) {
            uVar4 = 0x100000;
          }
          else {
            uVar4 = 0x400000;
          }
        }
      }
    }
    else {
      uVar4 = 0;
    }
    if ((int)(uVar6 << 0x1e) < 0) {
      uVar5 = read_volatile_4(RAC_SR0);
      write_volatile_4(RAC_SR0_CLR,uVar5 & 0xe000);
      if ((uVar5 & 0xe000) == 0) {
        uVar4 = uVar4 | 0x80000;
      }
      else {
        if ((int)(uVar5 << 0x10) < 0) {
          uVar4 = uVar4 | 0x2000000;
        }
        else {
          if ((int)(uVar5 << 0x12) < 0) {
            uVar4 = uVar4 | 0x200000;
          }
          else {
            uVar4 = uVar4 | 0x800000;
          }
        }
      }
    }
    if ((uVar6 & 0x2000) == 0) {
      uVar6 = 0;
    }
    else {
      uVar6 = 8;
    }
  }
  uVar5 = 0;
  if ((uVar7 & 0x90b0a09) != 0) {
    if ((uVar7 & 0xa00) != 0) {
      GENERIC_PHY_ResetRxFifo(0);
      uVar7 = uVar7 & 0xfffbffff;
      RAILInt_Assert(0,6);
    }
    if ((uVar7 & 9) != 0) {
      write_volatile_4(RAC_CMD,0x20);
      _DAT_40081028 = 1;
      RAILInt_Assert(0,8);
    }
    if ((uVar7 & 0x9000000) != 0) {
      write_volatile_4(RAC_CMD,0x20);
      BUFC_TxAckBufferReset();
      RAILInt_Assert(0,9);
    }
    if ((uVar7 & 0xa0000) != 0) {
      GENERIC_PHY_ResetRxFifo(0);
      uVar7 = uVar7 & 0xfffbffff;
      RAILInt_Assert(0,7);
    }
    if ((int)(uVar7 << 0xf) < 0) {
      BUFC_HandleRxLenOvfEvent();
    }
  }
  if ((int)(uVar7 << 0x1d) < 0) {
    if (_DAT_430204b4 == 0) {
      _DAT_46081024 = 0x2000;
    }
    else {
      uVar4 = uVar4 | 0x20000;
      _DAT_44081024 = 0x2000;
    }
  }
  if ((int)(uVar7 << 0x15) < 0) {
    uVar4 = uVar4 | 4;
  }
  if ((uVar7 & 0x40000) != 0) {
    uVar2 = BUFC_StartRxLenThrEvent();
    switch(uVar2) {
    case 1:
    case 3:
      uVar4 = uVar4 | 0x1000;
      break;
    case 2:
      uVar4 = uVar4 | 0x200;
      break;
    case 4:
      uVar4 = uVar4 | 0x100;
      break;
    case 5:
      uVar4 = uVar4 | 0x80;
      break;
    case 6:
    case 7:
      uVar4 = uVar4 | 8;
      break;
    default:
      RAILInt_Assert(0,3);
    }
  }
  if (uVar10 != 0) {
    if ((uVar10 & 0x1000) != 0) {
      uVar4 = uVar4 | 0x4000;
    }
    if ((uVar10 & 0x100) != 0) {
      uVar4 = uVar4 | 0x8000;
    }
    if ((uVar10 & 0x2000) != 0) {
      uVar6 = uVar6 | 1;
    }
    if ((uVar10 & 0x200) != 0) {
      uVar4 = uVar4 | 0x10;
    }
    if ((uVar10 & 0x400) != 0) {
      uVar4 = uVar4 | 0x20;
    }
    if ((uVar10 & 0x800) != 0) {
      uVar4 = uVar4 | 0x40;
    }
  }
  if (uVar8 != 0) {
    if ((uVar8 & 0x2000000) != 0) {
      uVar6 = uVar6 | 0x20;
    }
    if ((uVar8 & 0x4000000) != 0) {
      uVar6 = uVar6 | 0x40;
    }
    if ((uVar8 & 0x8000000) != 0) {
      uVar6 = uVar6 | 0x80;
    }
    if ((uVar8 & 0x40000) != 0) {
      uVar5 = 2;
    }
    if ((uVar8 & 0x10000) != 0) {
      uVar4 = uVar4 | 0x400;
    }
    if ((uVar8 & 0x100000) != 0) {
      uVar4 = uVar4 | 0x2000;
    }
    if ((uVar8 & 0x200000) != 0) {
      uVar4 = uVar4 | 2;
    }
    if (((uVar8 & 0x80000) != 0) && (iVar3 = GENERIC_PHY_CanModifyAck(), iVar3 != 0)) {
      uVar4 = uVar4 | 0x10000;
    }
  }
  if (uVar9 == 0) goto LAB_0001126e;
  if ((uVar9 & 0x800) != 0) {
    PROTIMER_CCTimerStop(3);
    _DAT_4408506c = 0x1f1f;
    _DAT_40085064 = 0x800;
    PROTIMER_ClearTxEnable();
  }
  if ((uVar9 & 0x2000000) != 0) {
    PTI_AuxdataOutput(0x2b);
    uVar4 = uVar4 | 0x20000000;
  }
  if ((uVar9 & 0x700000) == 0) {
    if ((uVar9 & 0x1000) != 0) {
      if (iVar1 != 0) goto LAB_00011158;
      PROTIMER_CCTimerStop(4);
      PROTIMER_CCTimerStop(3);
      PROTIMER_ClearRxEnable();
      uVar2 = CORE_EnterCritical();
      if (scheduledRxHardEnd != '\0') {
        RADIO_RACRxAbort();
      }
      iVar1 = BUFC_RxBufferBytesAvailable();
      uVar10 = read_volatile_4(RAC_STATUS);
      if (((uVar10 << 4) >> 0x1c == 3) || (iVar1 != 0)) {
        iVar1 = 1;
        pendedRxWindowEnd = scheduledRxLoop;
      }
      CORE_ExitCritical(uVar2);
      if (iVar1 == 0) {
        overrideRxRollback = 0;
        GENERIC_PHY_ConfigureRollbackReporting();
        uVar10 = 0x800;
      }
      else {
        uVar10 = 0;
      }
      uVar4 = uVar4 | uVar10;
    }
  }
  else {
LAB_00011158:
    uVar9 = PROTIMER_CheckCcaReallyFailed(uVar9);
    if ((uVar9 & 0x200000) != 0) {
      PTI_AuxdataOutput(0x29);
      uVar4 = uVar4 | 0x10000000;
    }
    if ((uVar9 & 0x400000) == 0) {
      if ((uVar9 & 0x100000) == 0) {
        if ((uVar9 & 0x1000) != 0) {
          PROTIMER_CCTimerStop(4);
          PROTIMER_LBTStop();
          if ((_DAT_4008505c & 0x500000) == 0) {
            PTI_AuxdataOutput(0x2a);
            _DAT_40081028 = 1;
            goto LAB_000111f2;
          }
        }
      }
      else {
        PROTIMER_CCTimerStop(4);
        PTI_AuxdataOutput(0x28);
        uVar4 = uVar4 | 0x4000000;
      }
    }
    else {
      PROTIMER_CCTimerStop(4);
      PTI_AuxdataOutput(0x27);
      write_volatile_4(RAC_SR0_CLR,0x80);
      write_volatile_4(RAC_RXENSRCEN_CLR,0x10);
LAB_000111f2:
      uVar4 = uVar4 | 0x8000000;
    }
  }
  if ((uVar9 & 0x400) != 0) {
    PROTIMER_CCTimerStop(2);
    uVar6 = uVar6 | 4;
  }
LAB_0001126e:
  GENERIC_PHY_IssueCallback(enabledRailEvents & uVar4,DAT_000112fc & uVar5,enabledPhyEvents & uVar6)
  ;
  if ((uVar7 & 0x40000) != 0) {
    BUFC_EndRxLenThrEvent();
    GENERIC_PHY_CheckPendedRxWindowEnd();
  }
  if (uVar8 != 0) {
    if ((uVar8 & 0x2000000) != 0) {
      PA_RunPeakDetectorHigh();
    }
    if ((uVar8 & 0x4000000) != 0) {
      PA_RunPeakDetectorLow();
    }
    if ((uVar8 & 0x8000000) != 0) {
      PA_RunBatHigh();
      return;
    }
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void BUFC_IRQHandler(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  uVar9 = read_volatile_4(FRC_IF);
  uVar6 = read_volatile_4(FRC_IEN);
  uVar6 = uVar6 & uVar9;
  write_volatile_4(FRC_IFC,uVar6);
  uVar7 = _DAT_400810ec & _DAT_400810e0;
  uVar9 = read_volatile_4(MODEM_IF);
  uVar10 = read_volatile_4(MODEM_IEN);
  uVar10 = uVar10 & uVar9;
  write_volatile_4(MODEM_IFC,uVar10);
  uVar9 = read_volatile_4(RAC_IF);
  uVar8 = read_volatile_4(RAC_IEN);
  uVar8 = uVar8 & uVar9;
  write_volatile_4(RAC_IFC,uVar8 & 0xffff0000);
  _DAT_400810e8 = uVar7;
  iVar1 = PROTIMER_LBTIsActive();
  uVar9 = _DAT_40085068 & _DAT_4008505c;
  _DAT_40085064 = uVar9 & 0xfffff7ff;
  if (uVar6 == 0) {
    uVar4 = 0;
  }
  else {
    if ((int)(uVar6 << 0x10) < 0) {
      uVar4 = read_volatile_4(RAC_SR0);
      write_volatile_4(RAC_SR0_CLR,uVar4 & 0x1c00);
      write_volatile_4(RAC_SR0_CLR,0x80);
      write_volatile_4(RAC_RXENSRCEN_CLR,0x10);
      if ((uVar4 & 0x1c00) == 0) {
        uVar4 = 0x40000;
      }
      else {
        if ((int)(uVar4 << 0x13) < 0) {
          uVar4 = 0x1000000;
        }
        else {
          if ((int)(uVar4 << 0x15) < 0) {
            uVar4 = 0x100000;
          }
          else {
            uVar4 = 0x400000;
          }
        }
      }
    }
    else {
      uVar4 = 0;
    }
    if ((int)(uVar6 << 0x1e) < 0) {
      uVar5 = read_volatile_4(RAC_SR0);
      write_volatile_4(RAC_SR0_CLR,uVar5 & 0xe000);
      if ((uVar5 & 0xe000) == 0) {
        uVar4 = uVar4 | 0x80000;
      }
      else {
        if ((int)(uVar5 << 0x10) < 0) {
          uVar4 = uVar4 | 0x2000000;
        }
        else {
          if ((int)(uVar5 << 0x12) < 0) {
            uVar4 = uVar4 | 0x200000;
          }
          else {
            uVar4 = uVar4 | 0x800000;
          }
        }
      }
    }
    if ((uVar6 & 0x2000) == 0) {
      uVar6 = 0;
    }
    else {
      uVar6 = 8;
    }
  }
  uVar5 = 0;
  if ((uVar7 & 0x90b0a09) != 0) {
    if ((uVar7 & 0xa00) != 0) {
      GENERIC_PHY_ResetRxFifo(0);
      uVar7 = uVar7 & 0xfffbffff;
      RAILInt_Assert(0,6);
    }
    if ((uVar7 & 9) != 0) {
      write_volatile_4(RAC_CMD,0x20);
      _DAT_40081028 = 1;
      RAILInt_Assert(0,8);
    }
    if ((uVar7 & 0x9000000) != 0) {
      write_volatile_4(RAC_CMD,0x20);
      BUFC_TxAckBufferReset();
      RAILInt_Assert(0,9);
    }
    if ((uVar7 & 0xa0000) != 0) {
      GENERIC_PHY_ResetRxFifo(0);
      uVar7 = uVar7 & 0xfffbffff;
      RAILInt_Assert(0,7);
    }
    if ((int)(uVar7 << 0xf) < 0) {
      BUFC_HandleRxLenOvfEvent();
    }
  }
  if ((int)(uVar7 << 0x1d) < 0) {
    if (_DAT_430204b4 == 0) {
      _DAT_46081024 = 0x2000;
    }
    else {
      uVar4 = uVar4 | 0x20000;
      _DAT_44081024 = 0x2000;
    }
  }
  if ((int)(uVar7 << 0x15) < 0) {
    uVar4 = uVar4 | 4;
  }
  if ((uVar7 & 0x40000) != 0) {
    uVar2 = BUFC_StartRxLenThrEvent();
    switch(uVar2) {
    case 1:
    case 3:
      uVar4 = uVar4 | 0x1000;
      break;
    case 2:
      uVar4 = uVar4 | 0x200;
      break;
    case 4:
      uVar4 = uVar4 | 0x100;
      break;
    case 5:
      uVar4 = uVar4 | 0x80;
      break;
    case 6:
    case 7:
      uVar4 = uVar4 | 8;
      break;
    default:
      RAILInt_Assert(0,3);
    }
  }
  if (uVar10 != 0) {
    if ((uVar10 & 0x1000) != 0) {
      uVar4 = uVar4 | 0x4000;
    }
    if ((uVar10 & 0x100) != 0) {
      uVar4 = uVar4 | 0x8000;
    }
    if ((uVar10 & 0x2000) != 0) {
      uVar6 = uVar6 | 1;
    }
    if ((uVar10 & 0x200) != 0) {
      uVar4 = uVar4 | 0x10;
    }
    if ((uVar10 & 0x400) != 0) {
      uVar4 = uVar4 | 0x20;
    }
    if ((uVar10 & 0x800) != 0) {
      uVar4 = uVar4 | 0x40;
    }
  }
  if (uVar8 != 0) {
    if ((uVar8 & 0x2000000) != 0) {
      uVar6 = uVar6 | 0x20;
    }
    if ((uVar8 & 0x4000000) != 0) {
      uVar6 = uVar6 | 0x40;
    }
    if ((uVar8 & 0x8000000) != 0) {
      uVar6 = uVar6 | 0x80;
    }
    if ((uVar8 & 0x40000) != 0) {
      uVar5 = 2;
    }
    if ((uVar8 & 0x10000) != 0) {
      uVar4 = uVar4 | 0x400;
    }
    if ((uVar8 & 0x100000) != 0) {
      uVar4 = uVar4 | 0x2000;
    }
    if ((uVar8 & 0x200000) != 0) {
      uVar4 = uVar4 | 2;
    }
    if (((uVar8 & 0x80000) != 0) && (iVar3 = GENERIC_PHY_CanModifyAck(), iVar3 != 0)) {
      uVar4 = uVar4 | 0x10000;
    }
  }
  if (uVar9 == 0) goto LAB_0001126e;
  if ((uVar9 & 0x800) != 0) {
    PROTIMER_CCTimerStop(3);
    _DAT_4408506c = 0x1f1f;
    _DAT_40085064 = 0x800;
    PROTIMER_ClearTxEnable();
  }
  if ((uVar9 & 0x2000000) != 0) {
    PTI_AuxdataOutput(0x2b);
    uVar4 = uVar4 | 0x20000000;
  }
  if ((uVar9 & 0x700000) == 0) {
    if ((uVar9 & 0x1000) != 0) {
      if (iVar1 != 0) goto LAB_00011158;
      PROTIMER_CCTimerStop(4);
      PROTIMER_CCTimerStop(3);
      PROTIMER_ClearRxEnable();
      uVar2 = CORE_EnterCritical();
      if (scheduledRxHardEnd != '\0') {
        RADIO_RACRxAbort();
      }
      iVar1 = BUFC_RxBufferBytesAvailable();
      uVar10 = read_volatile_4(RAC_STATUS);
      if (((uVar10 << 4) >> 0x1c == 3) || (iVar1 != 0)) {
        iVar1 = 1;
        pendedRxWindowEnd = scheduledRxLoop;
      }
      CORE_ExitCritical(uVar2);
      if (iVar1 == 0) {
        overrideRxRollback = 0;
        GENERIC_PHY_ConfigureRollbackReporting();
        uVar10 = 0x800;
      }
      else {
        uVar10 = 0;
      }
      uVar4 = uVar4 | uVar10;
    }
  }
  else {
LAB_00011158:
    uVar9 = PROTIMER_CheckCcaReallyFailed(uVar9);
    if ((uVar9 & 0x200000) != 0) {
      PTI_AuxdataOutput(0x29);
      uVar4 = uVar4 | 0x10000000;
    }
    if ((uVar9 & 0x400000) == 0) {
      if ((uVar9 & 0x100000) == 0) {
        if ((uVar9 & 0x1000) != 0) {
          PROTIMER_CCTimerStop(4);
          PROTIMER_LBTStop();
          if ((_DAT_4008505c & 0x500000) == 0) {
            PTI_AuxdataOutput(0x2a);
            _DAT_40081028 = 1;
            goto LAB_000111f2;
          }
        }
      }
      else {
        PROTIMER_CCTimerStop(4);
        PTI_AuxdataOutput(0x28);
        uVar4 = uVar4 | 0x4000000;
      }
    }
    else {
      PROTIMER_CCTimerStop(4);
      PTI_AuxdataOutput(0x27);
      write_volatile_4(RAC_SR0_CLR,0x80);
      write_volatile_4(RAC_RXENSRCEN_CLR,0x10);
LAB_000111f2:
      uVar4 = uVar4 | 0x8000000;
    }
  }
  if ((uVar9 & 0x400) != 0) {
    PROTIMER_CCTimerStop(2);
    uVar6 = uVar6 | 4;
  }
LAB_0001126e:
  GENERIC_PHY_IssueCallback(enabledRailEvents & uVar4,DAT_000112fc & uVar5,enabledPhyEvents & uVar6)
  ;
  if ((uVar7 & 0x40000) != 0) {
    BUFC_EndRxLenThrEvent();
    GENERIC_PHY_CheckPendedRxWindowEnd();
  }
  if (uVar8 != 0) {
    if ((uVar8 & 0x2000000) != 0) {
      PA_RunPeakDetectorHigh();
    }
    if ((uVar8 & 0x4000000) != 0) {
      PA_RunPeakDetectorLow();
    }
    if ((uVar8 & 0x8000000) != 0) {
      PA_RunBatHigh();
      return;
    }
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void PROTIMER_IRQHandler(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  uVar9 = read_volatile_4(FRC_IF);
  uVar6 = read_volatile_4(FRC_IEN);
  uVar6 = uVar6 & uVar9;
  write_volatile_4(FRC_IFC,uVar6);
  uVar7 = _DAT_400810ec & _DAT_400810e0;
  uVar9 = read_volatile_4(MODEM_IF);
  uVar10 = read_volatile_4(MODEM_IEN);
  uVar10 = uVar10 & uVar9;
  write_volatile_4(MODEM_IFC,uVar10);
  uVar9 = read_volatile_4(RAC_IF);
  uVar8 = read_volatile_4(RAC_IEN);
  uVar8 = uVar8 & uVar9;
  write_volatile_4(RAC_IFC,uVar8 & 0xffff0000);
  _DAT_400810e8 = uVar7;
  iVar1 = PROTIMER_LBTIsActive();
  uVar9 = _DAT_40085068 & _DAT_4008505c;
  _DAT_40085064 = uVar9 & 0xfffff7ff;
  if (uVar6 == 0) {
    uVar4 = 0;
  }
  else {
    if ((int)(uVar6 << 0x10) < 0) {
      uVar4 = read_volatile_4(RAC_SR0);
      write_volatile_4(RAC_SR0_CLR,uVar4 & 0x1c00);
      write_volatile_4(RAC_SR0_CLR,0x80);
      write_volatile_4(RAC_RXENSRCEN_CLR,0x10);
      if ((uVar4 & 0x1c00) == 0) {
        uVar4 = 0x40000;
      }
      else {
        if ((int)(uVar4 << 0x13) < 0) {
          uVar4 = 0x1000000;
        }
        else {
          if ((int)(uVar4 << 0x15) < 0) {
            uVar4 = 0x100000;
          }
          else {
            uVar4 = 0x400000;
          }
        }
      }
    }
    else {
      uVar4 = 0;
    }
    if ((int)(uVar6 << 0x1e) < 0) {
      uVar5 = read_volatile_4(RAC_SR0);
      write_volatile_4(RAC_SR0_CLR,uVar5 & 0xe000);
      if ((uVar5 & 0xe000) == 0) {
        uVar4 = uVar4 | 0x80000;
      }
      else {
        if ((int)(uVar5 << 0x10) < 0) {
          uVar4 = uVar4 | 0x2000000;
        }
        else {
          if ((int)(uVar5 << 0x12) < 0) {
            uVar4 = uVar4 | 0x200000;
          }
          else {
            uVar4 = uVar4 | 0x800000;
          }
        }
      }
    }
    if ((uVar6 & 0x2000) == 0) {
      uVar6 = 0;
    }
    else {
      uVar6 = 8;
    }
  }
  uVar5 = 0;
  if ((uVar7 & 0x90b0a09) != 0) {
    if ((uVar7 & 0xa00) != 0) {
      GENERIC_PHY_ResetRxFifo(0);
      uVar7 = uVar7 & 0xfffbffff;
      RAILInt_Assert(0,6);
    }
    if ((uVar7 & 9) != 0) {
      write_volatile_4(RAC_CMD,0x20);
      _DAT_40081028 = 1;
      RAILInt_Assert(0,8);
    }
    if ((uVar7 & 0x9000000) != 0) {
      write_volatile_4(RAC_CMD,0x20);
      BUFC_TxAckBufferReset();
      RAILInt_Assert(0,9);
    }
    if ((uVar7 & 0xa0000) != 0) {
      GENERIC_PHY_ResetRxFifo(0);
      uVar7 = uVar7 & 0xfffbffff;
      RAILInt_Assert(0,7);
    }
    if ((int)(uVar7 << 0xf) < 0) {
      BUFC_HandleRxLenOvfEvent();
    }
  }
  if ((int)(uVar7 << 0x1d) < 0) {
    if (_DAT_430204b4 == 0) {
      _DAT_46081024 = 0x2000;
    }
    else {
      uVar4 = uVar4 | 0x20000;
      _DAT_44081024 = 0x2000;
    }
  }
  if ((int)(uVar7 << 0x15) < 0) {
    uVar4 = uVar4 | 4;
  }
  if ((uVar7 & 0x40000) != 0) {
    uVar2 = BUFC_StartRxLenThrEvent();
    switch(uVar2) {
    case 1:
    case 3:
      uVar4 = uVar4 | 0x1000;
      break;
    case 2:
      uVar4 = uVar4 | 0x200;
      break;
    case 4:
      uVar4 = uVar4 | 0x100;
      break;
    case 5:
      uVar4 = uVar4 | 0x80;
      break;
    case 6:
    case 7:
      uVar4 = uVar4 | 8;
      break;
    default:
      RAILInt_Assert(0,3);
    }
  }
  if (uVar10 != 0) {
    if ((uVar10 & 0x1000) != 0) {
      uVar4 = uVar4 | 0x4000;
    }
    if ((uVar10 & 0x100) != 0) {
      uVar4 = uVar4 | 0x8000;
    }
    if ((uVar10 & 0x2000) != 0) {
      uVar6 = uVar6 | 1;
    }
    if ((uVar10 & 0x200) != 0) {
      uVar4 = uVar4 | 0x10;
    }
    if ((uVar10 & 0x400) != 0) {
      uVar4 = uVar4 | 0x20;
    }
    if ((uVar10 & 0x800) != 0) {
      uVar4 = uVar4 | 0x40;
    }
  }
  if (uVar8 != 0) {
    if ((uVar8 & 0x2000000) != 0) {
      uVar6 = uVar6 | 0x20;
    }
    if ((uVar8 & 0x4000000) != 0) {
      uVar6 = uVar6 | 0x40;
    }
    if ((uVar8 & 0x8000000) != 0) {
      uVar6 = uVar6 | 0x80;
    }
    if ((uVar8 & 0x40000) != 0) {
      uVar5 = 2;
    }
    if ((uVar8 & 0x10000) != 0) {
      uVar4 = uVar4 | 0x400;
    }
    if ((uVar8 & 0x100000) != 0) {
      uVar4 = uVar4 | 0x2000;
    }
    if ((uVar8 & 0x200000) != 0) {
      uVar4 = uVar4 | 2;
    }
    if (((uVar8 & 0x80000) != 0) && (iVar3 = GENERIC_PHY_CanModifyAck(), iVar3 != 0)) {
      uVar4 = uVar4 | 0x10000;
    }
  }
  if (uVar9 == 0) goto LAB_0001126e;
  if ((uVar9 & 0x800) != 0) {
    PROTIMER_CCTimerStop(3);
    _DAT_4408506c = 0x1f1f;
    _DAT_40085064 = 0x800;
    PROTIMER_ClearTxEnable();
  }
  if ((uVar9 & 0x2000000) != 0) {
    PTI_AuxdataOutput(0x2b);
    uVar4 = uVar4 | 0x20000000;
  }
  if ((uVar9 & 0x700000) == 0) {
    if ((uVar9 & 0x1000) != 0) {
      if (iVar1 != 0) goto LAB_00011158;
      PROTIMER_CCTimerStop(4);
      PROTIMER_CCTimerStop(3);
      PROTIMER_ClearRxEnable();
      uVar2 = CORE_EnterCritical();
      if (scheduledRxHardEnd != '\0') {
        RADIO_RACRxAbort();
      }
      iVar1 = BUFC_RxBufferBytesAvailable();
      uVar10 = read_volatile_4(RAC_STATUS);
      if (((uVar10 << 4) >> 0x1c == 3) || (iVar1 != 0)) {
        iVar1 = 1;
        pendedRxWindowEnd = scheduledRxLoop;
      }
      CORE_ExitCritical(uVar2);
      if (iVar1 == 0) {
        overrideRxRollback = 0;
        GENERIC_PHY_ConfigureRollbackReporting();
        uVar10 = 0x800;
      }
      else {
        uVar10 = 0;
      }
      uVar4 = uVar4 | uVar10;
    }
  }
  else {
LAB_00011158:
    uVar9 = PROTIMER_CheckCcaReallyFailed(uVar9);
    if ((uVar9 & 0x200000) != 0) {
      PTI_AuxdataOutput(0x29);
      uVar4 = uVar4 | 0x10000000;
    }
    if ((uVar9 & 0x400000) == 0) {
      if ((uVar9 & 0x100000) == 0) {
        if ((uVar9 & 0x1000) != 0) {
          PROTIMER_CCTimerStop(4);
          PROTIMER_LBTStop();
          if ((_DAT_4008505c & 0x500000) == 0) {
            PTI_AuxdataOutput(0x2a);
            _DAT_40081028 = 1;
            goto LAB_000111f2;
          }
        }
      }
      else {
        PROTIMER_CCTimerStop(4);
        PTI_AuxdataOutput(0x28);
        uVar4 = uVar4 | 0x4000000;
      }
    }
    else {
      PROTIMER_CCTimerStop(4);
      PTI_AuxdataOutput(0x27);
      write_volatile_4(RAC_SR0_CLR,0x80);
      write_volatile_4(RAC_RXENSRCEN_CLR,0x10);
LAB_000111f2:
      uVar4 = uVar4 | 0x8000000;
    }
  }
  if ((uVar9 & 0x400) != 0) {
    PROTIMER_CCTimerStop(2);
    uVar6 = uVar6 | 4;
  }
LAB_0001126e:
  GENERIC_PHY_IssueCallback(enabledRailEvents & uVar4,DAT_000112fc & uVar5,enabledPhyEvents & uVar6)
  ;
  if ((uVar7 & 0x40000) != 0) {
    BUFC_EndRxLenThrEvent();
    GENERIC_PHY_CheckPendedRxWindowEnd();
  }
  if (uVar8 != 0) {
    if ((uVar8 & 0x2000000) != 0) {
      PA_RunPeakDetectorHigh();
    }
    if ((uVar8 & 0x4000000) != 0) {
      PA_RunPeakDetectorLow();
    }
    if ((uVar8 & 0x8000000) != 0) {
      PA_RunBatHigh();
      return;
    }
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void RAC_SEQ_IRQHandler(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  uVar9 = read_volatile_4(FRC_IF);
  uVar6 = read_volatile_4(FRC_IEN);
  uVar6 = uVar6 & uVar9;
  write_volatile_4(FRC_IFC,uVar6);
  uVar7 = _DAT_400810ec & _DAT_400810e0;
  uVar9 = read_volatile_4(MODEM_IF);
  uVar10 = read_volatile_4(MODEM_IEN);
  uVar10 = uVar10 & uVar9;
  write_volatile_4(MODEM_IFC,uVar10);
  uVar9 = read_volatile_4(RAC_IF);
  uVar8 = read_volatile_4(RAC_IEN);
  uVar8 = uVar8 & uVar9;
  write_volatile_4(RAC_IFC,uVar8 & 0xffff0000);
  _DAT_400810e8 = uVar7;
  iVar1 = PROTIMER_LBTIsActive();
  uVar9 = _DAT_40085068 & _DAT_4008505c;
  _DAT_40085064 = uVar9 & 0xfffff7ff;
  if (uVar6 == 0) {
    uVar4 = 0;
  }
  else {
    if ((int)(uVar6 << 0x10) < 0) {
      uVar4 = read_volatile_4(RAC_SR0);
      write_volatile_4(RAC_SR0_CLR,uVar4 & 0x1c00);
      write_volatile_4(RAC_SR0_CLR,0x80);
      write_volatile_4(RAC_RXENSRCEN_CLR,0x10);
      if ((uVar4 & 0x1c00) == 0) {
        uVar4 = 0x40000;
      }
      else {
        if ((int)(uVar4 << 0x13) < 0) {
          uVar4 = 0x1000000;
        }
        else {
          if ((int)(uVar4 << 0x15) < 0) {
            uVar4 = 0x100000;
          }
          else {
            uVar4 = 0x400000;
          }
        }
      }
    }
    else {
      uVar4 = 0;
    }
    if ((int)(uVar6 << 0x1e) < 0) {
      uVar5 = read_volatile_4(RAC_SR0);
      write_volatile_4(RAC_SR0_CLR,uVar5 & 0xe000);
      if ((uVar5 & 0xe000) == 0) {
        uVar4 = uVar4 | 0x80000;
      }
      else {
        if ((int)(uVar5 << 0x10) < 0) {
          uVar4 = uVar4 | 0x2000000;
        }
        else {
          if ((int)(uVar5 << 0x12) < 0) {
            uVar4 = uVar4 | 0x200000;
          }
          else {
            uVar4 = uVar4 | 0x800000;
          }
        }
      }
    }
    if ((uVar6 & 0x2000) == 0) {
      uVar6 = 0;
    }
    else {
      uVar6 = 8;
    }
  }
  uVar5 = 0;
  if ((uVar7 & 0x90b0a09) != 0) {
    if ((uVar7 & 0xa00) != 0) {
      GENERIC_PHY_ResetRxFifo(0);
      uVar7 = uVar7 & 0xfffbffff;
      RAILInt_Assert(0,6);
    }
    if ((uVar7 & 9) != 0) {
      write_volatile_4(RAC_CMD,0x20);
      _DAT_40081028 = 1;
      RAILInt_Assert(0,8);
    }
    if ((uVar7 & 0x9000000) != 0) {
      write_volatile_4(RAC_CMD,0x20);
      BUFC_TxAckBufferReset();
      RAILInt_Assert(0,9);
    }
    if ((uVar7 & 0xa0000) != 0) {
      GENERIC_PHY_ResetRxFifo(0);
      uVar7 = uVar7 & 0xfffbffff;
      RAILInt_Assert(0,7);
    }
    if ((int)(uVar7 << 0xf) < 0) {
      BUFC_HandleRxLenOvfEvent();
    }
  }
  if ((int)(uVar7 << 0x1d) < 0) {
    if (_DAT_430204b4 == 0) {
      _DAT_46081024 = 0x2000;
    }
    else {
      uVar4 = uVar4 | 0x20000;
      _DAT_44081024 = 0x2000;
    }
  }
  if ((int)(uVar7 << 0x15) < 0) {
    uVar4 = uVar4 | 4;
  }
  if ((uVar7 & 0x40000) != 0) {
    uVar2 = BUFC_StartRxLenThrEvent();
    switch(uVar2) {
    case 1:
    case 3:
      uVar4 = uVar4 | 0x1000;
      break;
    case 2:
      uVar4 = uVar4 | 0x200;
      break;
    case 4:
      uVar4 = uVar4 | 0x100;
      break;
    case 5:
      uVar4 = uVar4 | 0x80;
      break;
    case 6:
    case 7:
      uVar4 = uVar4 | 8;
      break;
    default:
      RAILInt_Assert(0,3);
    }
  }
  if (uVar10 != 0) {
    if ((uVar10 & 0x1000) != 0) {
      uVar4 = uVar4 | 0x4000;
    }
    if ((uVar10 & 0x100) != 0) {
      uVar4 = uVar4 | 0x8000;
    }
    if ((uVar10 & 0x2000) != 0) {
      uVar6 = uVar6 | 1;
    }
    if ((uVar10 & 0x200) != 0) {
      uVar4 = uVar4 | 0x10;
    }
    if ((uVar10 & 0x400) != 0) {
      uVar4 = uVar4 | 0x20;
    }
    if ((uVar10 & 0x800) != 0) {
      uVar4 = uVar4 | 0x40;
    }
  }
  if (uVar8 != 0) {
    if ((uVar8 & 0x2000000) != 0) {
      uVar6 = uVar6 | 0x20;
    }
    if ((uVar8 & 0x4000000) != 0) {
      uVar6 = uVar6 | 0x40;
    }
    if ((uVar8 & 0x8000000) != 0) {
      uVar6 = uVar6 | 0x80;
    }
    if ((uVar8 & 0x40000) != 0) {
      uVar5 = 2;
    }
    if ((uVar8 & 0x10000) != 0) {
      uVar4 = uVar4 | 0x400;
    }
    if ((uVar8 & 0x100000) != 0) {
      uVar4 = uVar4 | 0x2000;
    }
    if ((uVar8 & 0x200000) != 0) {
      uVar4 = uVar4 | 2;
    }
    if (((uVar8 & 0x80000) != 0) && (iVar3 = GENERIC_PHY_CanModifyAck(), iVar3 != 0)) {
      uVar4 = uVar4 | 0x10000;
    }
  }
  if (uVar9 == 0) goto LAB_0001126e;
  if ((uVar9 & 0x800) != 0) {
    PROTIMER_CCTimerStop(3);
    _DAT_4408506c = 0x1f1f;
    _DAT_40085064 = 0x800;
    PROTIMER_ClearTxEnable();
  }
  if ((uVar9 & 0x2000000) != 0) {
    PTI_AuxdataOutput(0x2b);
    uVar4 = uVar4 | 0x20000000;
  }
  if ((uVar9 & 0x700000) == 0) {
    if ((uVar9 & 0x1000) != 0) {
      if (iVar1 != 0) goto LAB_00011158;
      PROTIMER_CCTimerStop(4);
      PROTIMER_CCTimerStop(3);
      PROTIMER_ClearRxEnable();
      uVar2 = CORE_EnterCritical();
      if (scheduledRxHardEnd != '\0') {
        RADIO_RACRxAbort();
      }
      iVar1 = BUFC_RxBufferBytesAvailable();
      uVar10 = read_volatile_4(RAC_STATUS);
      if (((uVar10 << 4) >> 0x1c == 3) || (iVar1 != 0)) {
        iVar1 = 1;
        pendedRxWindowEnd = scheduledRxLoop;
      }
      CORE_ExitCritical(uVar2);
      if (iVar1 == 0) {
        overrideRxRollback = 0;
        GENERIC_PHY_ConfigureRollbackReporting();
        uVar10 = 0x800;
      }
      else {
        uVar10 = 0;
      }
      uVar4 = uVar4 | uVar10;
    }
  }
  else {
LAB_00011158:
    uVar9 = PROTIMER_CheckCcaReallyFailed(uVar9);
    if ((uVar9 & 0x200000) != 0) {
      PTI_AuxdataOutput(0x29);
      uVar4 = uVar4 | 0x10000000;
    }
    if ((uVar9 & 0x400000) == 0) {
      if ((uVar9 & 0x100000) == 0) {
        if ((uVar9 & 0x1000) != 0) {
          PROTIMER_CCTimerStop(4);
          PROTIMER_LBTStop();
          if ((_DAT_4008505c & 0x500000) == 0) {
            PTI_AuxdataOutput(0x2a);
            _DAT_40081028 = 1;
            goto LAB_000111f2;
          }
        }
      }
      else {
        PROTIMER_CCTimerStop(4);
        PTI_AuxdataOutput(0x28);
        uVar4 = uVar4 | 0x4000000;
      }
    }
    else {
      PROTIMER_CCTimerStop(4);
      PTI_AuxdataOutput(0x27);
      write_volatile_4(RAC_SR0_CLR,0x80);
      write_volatile_4(RAC_RXENSRCEN_CLR,0x10);
LAB_000111f2:
      uVar4 = uVar4 | 0x8000000;
    }
  }
  if ((uVar9 & 0x400) != 0) {
    PROTIMER_CCTimerStop(2);
    uVar6 = uVar6 | 4;
  }
LAB_0001126e:
  GENERIC_PHY_IssueCallback(enabledRailEvents & uVar4,DAT_000112fc & uVar5,enabledPhyEvents & uVar6)
  ;
  if ((uVar7 & 0x40000) != 0) {
    BUFC_EndRxLenThrEvent();
    GENERIC_PHY_CheckPendedRxWindowEnd();
  }
  if (uVar8 != 0) {
    if ((uVar8 & 0x2000000) != 0) {
      PA_RunPeakDetectorHigh();
    }
    if ((uVar8 & 0x4000000) != 0) {
      PA_RunPeakDetectorLow();
    }
    if ((uVar8 & 0x8000000) != 0) {
      PA_RunBatHigh();
      return;
    }
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void MODEM_IRQHandler(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  uVar9 = read_volatile_4(FRC_IF);
  uVar6 = read_volatile_4(FRC_IEN);
  uVar6 = uVar6 & uVar9;
  write_volatile_4(FRC_IFC,uVar6);
  uVar7 = _DAT_400810ec & _DAT_400810e0;
  uVar9 = read_volatile_4(MODEM_IF);
  uVar10 = read_volatile_4(MODEM_IEN);
  uVar10 = uVar10 & uVar9;
  write_volatile_4(MODEM_IFC,uVar10);
  uVar9 = read_volatile_4(RAC_IF);
  uVar8 = read_volatile_4(RAC_IEN);
  uVar8 = uVar8 & uVar9;
  write_volatile_4(RAC_IFC,uVar8 & 0xffff0000);
  _DAT_400810e8 = uVar7;
  iVar1 = PROTIMER_LBTIsActive();
  uVar9 = _DAT_40085068 & _DAT_4008505c;
  _DAT_40085064 = uVar9 & 0xfffff7ff;
  if (uVar6 == 0) {
    uVar4 = 0;
  }
  else {
    if ((int)(uVar6 << 0x10) < 0) {
      uVar4 = read_volatile_4(RAC_SR0);
      write_volatile_4(RAC_SR0_CLR,uVar4 & 0x1c00);
      write_volatile_4(RAC_SR0_CLR,0x80);
      write_volatile_4(RAC_RXENSRCEN_CLR,0x10);
      if ((uVar4 & 0x1c00) == 0) {
        uVar4 = 0x40000;
      }
      else {
        if ((int)(uVar4 << 0x13) < 0) {
          uVar4 = 0x1000000;
        }
        else {
          if ((int)(uVar4 << 0x15) < 0) {
            uVar4 = 0x100000;
          }
          else {
            uVar4 = 0x400000;
          }
        }
      }
    }
    else {
      uVar4 = 0;
    }
    if ((int)(uVar6 << 0x1e) < 0) {
      uVar5 = read_volatile_4(RAC_SR0);
      write_volatile_4(RAC_SR0_CLR,uVar5 & 0xe000);
      if ((uVar5 & 0xe000) == 0) {
        uVar4 = uVar4 | 0x80000;
      }
      else {
        if ((int)(uVar5 << 0x10) < 0) {
          uVar4 = uVar4 | 0x2000000;
        }
        else {
          if ((int)(uVar5 << 0x12) < 0) {
            uVar4 = uVar4 | 0x200000;
          }
          else {
            uVar4 = uVar4 | 0x800000;
          }
        }
      }
    }
    if ((uVar6 & 0x2000) == 0) {
      uVar6 = 0;
    }
    else {
      uVar6 = 8;
    }
  }
  uVar5 = 0;
  if ((uVar7 & 0x90b0a09) != 0) {
    if ((uVar7 & 0xa00) != 0) {
      GENERIC_PHY_ResetRxFifo(0);
      uVar7 = uVar7 & 0xfffbffff;
      RAILInt_Assert(0,6);
    }
    if ((uVar7 & 9) != 0) {
      write_volatile_4(RAC_CMD,0x20);
      _DAT_40081028 = 1;
      RAILInt_Assert(0,8);
    }
    if ((uVar7 & 0x9000000) != 0) {
      write_volatile_4(RAC_CMD,0x20);
      BUFC_TxAckBufferReset();
      RAILInt_Assert(0,9);
    }
    if ((uVar7 & 0xa0000) != 0) {
      GENERIC_PHY_ResetRxFifo(0);
      uVar7 = uVar7 & 0xfffbffff;
      RAILInt_Assert(0,7);
    }
    if ((int)(uVar7 << 0xf) < 0) {
      BUFC_HandleRxLenOvfEvent();
    }
  }
  if ((int)(uVar7 << 0x1d) < 0) {
    if (_DAT_430204b4 == 0) {
      _DAT_46081024 = 0x2000;
    }
    else {
      uVar4 = uVar4 | 0x20000;
      _DAT_44081024 = 0x2000;
    }
  }
  if ((int)(uVar7 << 0x15) < 0) {
    uVar4 = uVar4 | 4;
  }
  if ((uVar7 & 0x40000) != 0) {
    uVar2 = BUFC_StartRxLenThrEvent();
    switch(uVar2) {
    case 1:
    case 3:
      uVar4 = uVar4 | 0x1000;
      break;
    case 2:
      uVar4 = uVar4 | 0x200;
      break;
    case 4:
      uVar4 = uVar4 | 0x100;
      break;
    case 5:
      uVar4 = uVar4 | 0x80;
      break;
    case 6:
    case 7:
      uVar4 = uVar4 | 8;
      break;
    default:
      RAILInt_Assert(0,3);
    }
  }
  if (uVar10 != 0) {
    if ((uVar10 & 0x1000) != 0) {
      uVar4 = uVar4 | 0x4000;
    }
    if ((uVar10 & 0x100) != 0) {
      uVar4 = uVar4 | 0x8000;
    }
    if ((uVar10 & 0x2000) != 0) {
      uVar6 = uVar6 | 1;
    }
    if ((uVar10 & 0x200) != 0) {
      uVar4 = uVar4 | 0x10;
    }
    if ((uVar10 & 0x400) != 0) {
      uVar4 = uVar4 | 0x20;
    }
    if ((uVar10 & 0x800) != 0) {
      uVar4 = uVar4 | 0x40;
    }
  }
  if (uVar8 != 0) {
    if ((uVar8 & 0x2000000) != 0) {
      uVar6 = uVar6 | 0x20;
    }
    if ((uVar8 & 0x4000000) != 0) {
      uVar6 = uVar6 | 0x40;
    }
    if ((uVar8 & 0x8000000) != 0) {
      uVar6 = uVar6 | 0x80;
    }
    if ((uVar8 & 0x40000) != 0) {
      uVar5 = 2;
    }
    if ((uVar8 & 0x10000) != 0) {
      uVar4 = uVar4 | 0x400;
    }
    if ((uVar8 & 0x100000) != 0) {
      uVar4 = uVar4 | 0x2000;
    }
    if ((uVar8 & 0x200000) != 0) {
      uVar4 = uVar4 | 2;
    }
    if (((uVar8 & 0x80000) != 0) && (iVar3 = GENERIC_PHY_CanModifyAck(), iVar3 != 0)) {
      uVar4 = uVar4 | 0x10000;
    }
  }
  if (uVar9 == 0) goto LAB_0001126e;
  if ((uVar9 & 0x800) != 0) {
    PROTIMER_CCTimerStop(3);
    _DAT_4408506c = 0x1f1f;
    _DAT_40085064 = 0x800;
    PROTIMER_ClearTxEnable();
  }
  if ((uVar9 & 0x2000000) != 0) {
    PTI_AuxdataOutput(0x2b);
    uVar4 = uVar4 | 0x20000000;
  }
  if ((uVar9 & 0x700000) == 0) {
    if ((uVar9 & 0x1000) != 0) {
      if (iVar1 != 0) goto LAB_00011158;
      PROTIMER_CCTimerStop(4);
      PROTIMER_CCTimerStop(3);
      PROTIMER_ClearRxEnable();
      uVar2 = CORE_EnterCritical();
      if (scheduledRxHardEnd != '\0') {
        RADIO_RACRxAbort();
      }
      iVar1 = BUFC_RxBufferBytesAvailable();
      uVar10 = read_volatile_4(RAC_STATUS);
      if (((uVar10 << 4) >> 0x1c == 3) || (iVar1 != 0)) {
        iVar1 = 1;
        pendedRxWindowEnd = scheduledRxLoop;
      }
      CORE_ExitCritical(uVar2);
      if (iVar1 == 0) {
        overrideRxRollback = 0;
        GENERIC_PHY_ConfigureRollbackReporting();
        uVar10 = 0x800;
      }
      else {
        uVar10 = 0;
      }
      uVar4 = uVar4 | uVar10;
    }
  }
  else {
LAB_00011158:
    uVar9 = PROTIMER_CheckCcaReallyFailed(uVar9);
    if ((uVar9 & 0x200000) != 0) {
      PTI_AuxdataOutput(0x29);
      uVar4 = uVar4 | 0x10000000;
    }
    if ((uVar9 & 0x400000) == 0) {
      if ((uVar9 & 0x100000) == 0) {
        if ((uVar9 & 0x1000) != 0) {
          PROTIMER_CCTimerStop(4);
          PROTIMER_LBTStop();
          if ((_DAT_4008505c & 0x500000) == 0) {
            PTI_AuxdataOutput(0x2a);
            _DAT_40081028 = 1;
            goto LAB_000111f2;
          }
        }
      }
      else {
        PROTIMER_CCTimerStop(4);
        PTI_AuxdataOutput(0x28);
        uVar4 = uVar4 | 0x4000000;
      }
    }
    else {
      PROTIMER_CCTimerStop(4);
      PTI_AuxdataOutput(0x27);
      write_volatile_4(RAC_SR0_CLR,0x80);
      write_volatile_4(RAC_RXENSRCEN_CLR,0x10);
LAB_000111f2:
      uVar4 = uVar4 | 0x8000000;
    }
  }
  if ((uVar9 & 0x400) != 0) {
    PROTIMER_CCTimerStop(2);
    uVar6 = uVar6 | 4;
  }
LAB_0001126e:
  GENERIC_PHY_IssueCallback(enabledRailEvents & uVar4,DAT_000112fc & uVar5,enabledPhyEvents & uVar6)
  ;
  if ((uVar7 & 0x40000) != 0) {
    BUFC_EndRxLenThrEvent();
    GENERIC_PHY_CheckPendedRxWindowEnd();
  }
  if (uVar8 != 0) {
    if ((uVar8 & 0x2000000) != 0) {
      PA_RunPeakDetectorHigh();
    }
    if ((uVar8 & 0x4000000) != 0) {
      PA_RunPeakDetectorLow();
    }
    if ((uVar8 & 0x8000000) != 0) {
      PA_RunBatHigh();
      return;
    }
  }
  return;
}


