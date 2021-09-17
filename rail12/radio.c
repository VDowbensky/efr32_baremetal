#include "radio.h"


void RADIO_BUFCClear(uint32_t buf)

{
  *(undefined4 *)((buf * 0x30 + 0x42181028) * 0x20) = 1;
  return;
}



void RADIO_WriteSync(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  return;
}



void RADIO_OrSync(uint *param_1,uint param_2)

{
  *param_1 = param_2 | *param_1;
  return;
}



void RADIO_XorSync(uint *param_1,uint param_2)

{
  *param_1 = param_2 ^ *param_1;
  return;
}



void RADIO_AndSync(uint *param_1,uint param_2)

{
  *param_1 = param_2 & *param_1;
  return;
}



void RADIO_WaitForSetSync(uint *param_1,uint param_2)

{
  INT_Disable();
  do {
  } while ((*param_1 & param_2) != param_2);
  INT_Enable();
  return;
}



void RADIO_UsToStimerTickCalc(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  longlong lVar1;
  uint uVar2;
  
  uVar2 = RADIOCMU_ClockFreqGet(0x75160);
  param_1 = param_1 & ~((int)param_1 >> 0x1f);
  lVar1 = (ulonglong)uVar2 * (ulonglong)param_1;
  __aeabi_uldivmod((int)lVar1,uVar2 * ((int)param_1 >> 0x1f) + (int)((ulonglong)lVar1 >> 0x20),
                   8000000,0,param_4);
  return;
}



void RADIO_Delay(undefined4 param_1,uint32_t us)

{
  PHY_UTILS_DelayUs(us);
  return;
}



void RADIO_BUFCWriteContSync_constprop_3(uint8_t *addr,uint16_t len)

{
  byte *pbVar1;
  
  INT_Disable();
  pbVar1 = addr;
  while (pbVar1 != addr + len) {
    write_volatile_4(BUFC->BUF0_WRITEDATA,(uint)*pbVar1);
    pbVar1 = pbVar1 + 1;
  }
  INT_Enable();
  return;
}



void RADIO_ClrBitSync(int param_1,int param_2)

{
  *(undefined4 *)((param_2 + (param_1 + 0x2100000) * 8) * 4) = 0;
  return;
}



void RADIO_SetBitSync(int param_1,int param_2)

{
  *(undefined4 *)((param_2 + (param_1 + 0x2100000) * 8) * 4) = 1;
  return;
}



void RADIO_ModemConfigFixup(void)

{
  uint uVar1;
  
  uVar1 = (RAC->LPFCTRL);
  write_volatile_4(SEQ->SYNTHLPFCTRLTX,uVar1);
  uVar1 = (RAC->LPFCTRL);
  write_volatile_4(SEQ->SYNTHLPFCTRLRX,uVar1 & 0xfffffff0);
  return;
}



void RADIO_SetAndForgetWrite(undefined4 param_1,uint param_2,undefined4 param_3)

{
  undefined4 in_r1;
  undefined2 local_c;
  
  local_c = (undefined2)((uint)in_r1 >> 8);
  SYSTEM_ChipRevisionGet((SYSTEM_ChipRevision_TypeDef *)&local_c);
  write_volatile_4(RAC->IFADCCTRL,0x1153e6c0);
  write_volatile_4(RAC->IFPGACTRL,0x87e6);
  write_volatile_4(RAC->LNAMIXCTRL1,0x880);
  write_volatile_4(RAC->VCOCTRL,0xf00277a);
  if ((local_c._1_1_ == '\x01') && ((byte)local_c < 2)) {
    write_volatile_4(SYNTH->VCOGAIN,0x28);
  }
  write_volatile_4(SYNTH->CTRL,0xac3f);
  write_volatile_4(AGC->MANGAIN,0x1800000);
  write_volatile_4(RAC->LNAMIXCTRL,0);
  write_volatile_4(RAC->SYNTHREGCTRL,0x3636d80);
  return;
}



void RADIO_SeqInit(void *seqprogstart,int seqprogsize)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  read_volatile(RAC->STATUS._0_1_);
  write_volatile_4(RAC->VECTADDR,0x21000000);
  write_volatile_4(RAC->SEQCTRL,1);
  INT_Disable();
  memcpy((void *)0x21000000,seqprogstart,seqprogsize << 2);
  INT_Enable();
  write_volatile_4(RAC->R6,0x21000fcc);
  uVar1 = (SEQ->REG0C0);
  uVar2 = (SEQ->REG0C4);
  uVar3 = (SEQ->REG0C8);
  memset(&SEQ->REG06C,0,0x94);
  write_volatile_4(SEQ->REG0C0,uVar1);
  write_volatile_4(SEQ->REG0C4,uVar2);
  write_volatile_4(SEQ->REG0C8,uVar3);
  iVar4 = RADIO_UsToStimerTickCalc(0x3c);
  write_volatile_4(SEQ->REG0BC,-iVar4);
  return;
}



void RADIO_CLKEnable(void)

{
  RADIOCMU_ClockEnable(0x63400,true);
  RADIOCMU_ClockEnable(0x60400,true);
  RADIOCMU_ClockEnable(0x64400,true);
  RADIOCMU_ClockEnable(0x67400,true);
  RADIOCMU_ClockEnable(0x66400,true);
  RADIOCMU_ClockEnable(0x65400,true);
  RADIOCMU_ClockEnable(0x62400,true);
  RADIOCMU_ClockEnable(0x68400,true);
  return;
}


void RADIO_Config(void *config)

{
  uint uVar1;
  int iVar2;
  void *__dest;
  uint uVar3;
  void *__src;
  
  iVar2 = (int)config + 8;
  while( true ) {
    uVar1 = *(uint *)(iVar2 + -8);
    if (uVar1 == 0xffffffff) break;
    uVar3 = (uVar1 << 8) >> 0x18;
    __dest = (void *)(uVar1 & 0xffff | (uint)(&regBases)[(uVar1 << 4) >> 0x1c]);
    if (uVar3 < 2) {
      (**(code **)(&EFRDRV_actionFunc + (uVar1 >> 0x1c) * 4))(__dest,*(undefined4 *)(iVar2 + -4));
    }
    else {
      __src = *(void **)(iVar2 + -4);
      INT_Disable();
      memcpy(__dest,__src,uVar3 << 2);
      INT_Enable();
    }
    iVar2 = iVar2 + 8;
  }
  PA_BandSelect();
  return;
}



void RADIO_RegisterIrqCallback(uint32_t cbnumber,uint32_t address)

{
  (&EFRDRV_irqClbk)[cbnumber] = address;
  return;
}



void FRC_PRI_IRQHandler(void)

{
                    // WARNING: Could not recover jumptable at 0x000102e0. Too many branches
                    // WARNING: Treating indirect jump as call
  (*EFRDRV_irqClbk)();
  return;
}



void FRC_IRQHandler(void)

{
                    // WARNING: Could not recover jumptable at 0x000102ec. Too many branches
                    // WARNING: Treating indirect jump as call
  (*DAT_000109d0)();
  return;
}



void RAC_RSM_IRQHandler(void)

{
                    // WARNING: Could not recover jumptable at 0x000102f8. Too many branches
                    // WARNING: Treating indirect jump as call
  (*DAT_000109e0)();
  return;
}



void RAC_SEQ_IRQHandler(void)

{
                    // WARNING: Could not recover jumptable at 0x00010304. Too many branches
                    // WARNING: Treating indirect jump as call
  (*DAT_000109e0)();
  return;
}



void AGC_IRQHandler(void)

{
                    // WARNING: Could not recover jumptable at 0x00010310. Too many branches
                    // WARNING: Treating indirect jump as call
  (*DAT_000109f0)();
  return;
}



void PROTIMER_IRQHandler(void)

{
                    // WARNING: Could not recover jumptable at 0x0001031c. Too many branches
                    // WARNING: Treating indirect jump as call
  (*DAT_000109e8)();
  return;
}



void BUFC_IRQHandler(void)

{
                    // WARNING: Could not recover jumptable at 0x00010328. Too many branches
                    // WARNING: Treating indirect jump as call
  (*DAT_000109d8)();
  return;
}



void MODEM_IRQHandler(void)

{
                    // WARNING: Could not recover jumptable at 0x00010334. Too many branches
                    // WARNING: Treating indirect jump as call
  (*DAT_000109d4)();
  return;
}



void RADIO_BUFCConfig(int param_1,undefined4 param_2,uint param_3,uint param_4,uint param_5)

{
  int iVar1;
  
  iVar1 = count_leading_zeroes(param_2);
  (&BUFC->BUF0_CTRL)[param_1 * 0xc] = 0x19 - iVar1;
  (&BUFC->BUF0_ADDR)[param_1 * 0xc] = param_3;
  (&BUFC->BUF0_THRESHOLDCTRL)[param_1 * 0xc] = param_4 | param_5;
  return;
}



uint RADIO_BUFCBytesAvailable(int param_1)

{
  return (&BUFC->BUF0_STATUS)[param_1 * 0xc] & 0x1fff;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void RADIO_TxBufferSet(undefined4 param_1,int param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  
  RADIO_BUFCClear(0);
  RADIO_BUFCWriteContSync_constprop_3(param_1,param_2);
  if (param_4 == 0) {
    return;
  }
  uVar1 = 0x100U - param_2 & 0xffff;
  bufcTxStreaming = (undefined2)param_2;
  DAT_00010b82 = (undefined2)param_4;
  DAT_00010b8c = (undefined2)uVar1;
  DAT_00010b84 = param_1;
  DAT_00010b88 = param_3;
  if (uVar1 < param_4) {
    RADIO_BUFCWriteContSync_constprop_3(param_3);
    _DAT_43021d90 = 1;
    return;
  }
  RADIO_BUFCWriteContSync_constprop_3(param_3,param_4);
  return;
}



void RADIO_TxBufferReset(void)

{
  RADIO_TxBufferSet(0,0,0,0);
  return;
}



void RADIO_RXBufferEnableThrInt(void)

{
  uint uVar1;
  
  uVar1 = (BUFC->IEN);
  write_volatile_4(BUFC->IEN,uVar1 | 0x400);
  return;
}



void RADIO_RXBufferDisableThrInt(void)

{
  uint uVar1;
  
  uVar1 = (BUFC->IEN);
  write_volatile_4(BUFC->IEN,uVar1 & 0xfffffbff);
  return;
}



bool RADIO_IsRxActive(void)

{
  uint uVar1;
  
  uVar1 = (RAC->STATUS);
  uVar1 = (uVar1 << 4) >> 0x1c;
  if ((uVar1 != 3) && (uVar1 != 7)) {
    return uVar1 == 4;
  }
  return true;
}



void RADIO_RxBufferSet(int addr)

{
  if (param_1 != 0) {
    _DAT_43022d80 = 1;
  }
  bufcRxStreaming = 0;
  DAT_20002bb0 = param_1;
  return;
}



uint32_t RADIO_RxBufferGet(void)

{
  return DAT_20002bb0;
}



void RADIO_RxBufferReset(void)

{
  bufcRxStreaming = 0;
  RADIO_BUFCClear(1);
  RADIO_BUFCClear(2);
  return;
}



void RADIO_BUFCIrqHandler(void)

{
  ushort uVar1;
  uint uVar2;
  uint8_t *addr;
  uint uVar3;
  uint uVar4;
  
  uVar3 = (BUFC->IF);
  uVar2 = (BUFC->IEN);
  write_volatile_4(BUFC->IFC,uVar3 & uVar2);
  uVar4 = (BUFC->IEN);
  uVar4 = uVar4 & uVar3 & uVar2;
  if ((int)(uVar4 << 0x1d) < 0) {
    uVar3 = (uint)DAT_20002bb6 - (uint)DAT_20002bc0 & 0xffff;
    addr = (uint8_t *)(DAT_20002bbc + (uint)DAT_20002bc0);
    if (uVar3 < 0xe1) {
      RADIO_BUFCWriteContSync_constprop_3(addr,(uint16_t)uVar3);
      _DAT_43021d90 = 0;
    }
    else {
      uVar1 = DAT_20002bc0 + 0xe0;
      RADIO_BUFCWriteContSync_constprop_3(addr,0xe0);
      DAT_20002bc0 = uVar1;
    }
  }
  if ((int)(uVar4 << 0x15) < 0) {
    RFTEST_BerEmptyBufcAndUpdateStats();
  }
  if ((uVar4 & 0xa0a00) != 0) {
    RADIO_RxBufferReset();
  }
  if ((uVar4 & 9) != 0) {
    _DAT_43080114 = 1;
    RADIO_TxBufferReset();
  }
  if ((int)(uVar4 << 0x1e) < 0) {
    RADIO_TxBufferReset();
    return;
  }
  return;
}



uint32_t RADIO_RxTrailDataLength(void)

{
  uint uVar1;
  uint32_t uVar2;
  
  uVar1 = (FRC->TRAILRXDATA);
  if ((uVar1 & 0x20) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 4;
  }
  if ((int)(uVar1 << 0x1b) < 0) {
    uVar2 = uVar2 + 2;
  }
  if ((int)(uVar1 << 0x1c) < 0) {
    uVar2 = uVar2 + 2;
  }
  if ((int)(uVar1 << 0x1d) < 0) {
    uVar2 = uVar2 + 2;
  }
  if ((int)(uVar1 << 0x1e) < 0) {
    uVar2 = uVar2 + 1;
  }
  if ((int)(uVar1 << 0x1f) < 0) {
    uVar2 = uVar2 + 1;
  }
  return uVar2;
}



bool RADIO_RxBufferPacketAvailable(void)

{
  uint uVar1;
  
  uVar1 = (BUFC->BUF2_STATUS);
  return 1 < (uVar1 & 0x1fff);
}




uint16_t RADIO_RxBufferBytesAvailable(void)

{
  uint uVar1;
  
  uVar1 = (BUFC->BUF1_STATUS);
  return uVar1 & 0x1fff;
}



uint16_t RADIO_TxBufferBytesAvailable(void)

{
  uint uVar1;
  
  uVar1 = (BUFC->BUF0_STATUS);
  return uVar1 & 0x1fff;
}



uint16_t RADIO_RxLengthBufferBytesAvailable(void)

{
  uint uVar1;
  
  uVar1 = (BUFC->BUF2_STATUS);
  return uVar1 & 0x1fff;
}



uint8_t RADIO_RxBufferReadByte(void)

{
  uint uVar1;
  
  uVar1 = (BUFC->BUF1_READDATA);
  return (uint8_t)uVar1;
}



void RADIO_FrameControlDescrBufferIdSet(int32_t buf,int32_t id)

{
  (&FRC->FCD0)[buf] = (&FRC->FCD0)[buf] & 0xfffffcff;
  (&FRC->FCD0)[buf] = (&FRC->FCD0)[buf] | id << 8;
  return;
}



void RADIO_FrameControlDescrConfigSet
               (int param_1,uint param_2,int param_3,int param_4,byte param_5,byte param_6)

{
  (&FRC->FCD0)[param_1] = (&FRC->FCD0)[param_1] & 0xffff8300;
  (&FRC->FCD0)[param_1] =
       param_2 | (uint)param_6 << 10 | (uint)param_5 << 0xb | param_4 << 0xc | param_3 << 0xe |
       (&FRC->FCD0)[param_1];
  return;
}



void RADIO_FrameDescsConfig
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  RADIO_FrameControlDescrConfigSet(0,0xff,param_1,param_2,param_3,param_4,param_3);
  RADIO_FrameControlDescrConfigSet(2,0xff,param_1,param_2,param_3,param_4);
  return;
}



uint8_t RADIO_BUFCRead(uint32_t buf)

{
  return (&BUFC->BUF0_READDATA)[param_1 * 0xc] & 0xff;
}



void RADIO_BUFCReadContASync(int buf,uint8_t *addr,int16_t len)

{
  uint8_t *puVar1;
  
  puVar1 = addr + len;
  for (; addr != puVar1; addr = addr + 1) {
    *addr = (uint8_t)(&BUFC->BUF0_READDATA)[buf * 0xc];
  }
  return;
}



void RADIO_RxBufferReadBytes(uint8_t *addr,int16_t len)

{
  RADIO_BUFCReadContASync(1,addr,len);
  return;
}



void RADIO_RxBufferDropBytes(uint param_1,undefined4 param_2)

{
  undefined4 uStack12;
  
  uStack12 = param_2;
  for (; param_1 != 0; param_1 = param_1 - 1 & 0xffff) {
    RADIO_RxBufferReadBytes((uint8_t *)((int)&uStack12 + 3),1);
  }
  return;
}



uint RADIO_RxLengthReadNext(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint local_c;
  undefined4 uStack8;
  
  local_c = param_2;
  uStack8 = param_3;
  iVar1 = RADIO_RxBufferPacketAvailable();
  if (iVar1 == 0) {
    local_c = 0xffff;
  }
  else {
    RADIO_BUFCReadContASync(2,&local_c,2,param_4,param_1);
    local_c = local_c & 0xff;
  }
  return local_c;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

int RADIO_RxBufferFinalizeAndGet
              (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = RADIO_RxLengthReadNext();
  iVar1 = DAT_00010b7c;
  if (iVar2 != 0xffff) {
    RADIO_BUFCReadContASync
              (1,DAT_00010b7c + (uint)bufcRxStreaming,iVar2 - (uint)bufcRxStreaming,0xffff,param_4);
    bufcRxStreaming = (ushort)iVar2;
    _DAT_43022d80 = 0;
    *param_1 = iVar1;
  }
  return iVar2;
}



void RADIO_FRCErrorHandle(void)

{
  bufcRxStreaming = 0;
  RADIO_BUFCClear(1);
  RADIO_BUFCClear(2);
  return;
}



void RADIO_DemodResetOnRxsearchEntryEnable(void)

{
  uint uVar1;
  
  uVar1 = (RAC->SR3);
  write_volatile_4(RAC->SR3,uVar1 | 0x100);
  return;
}



void RADIO_DemodResetOnRxsearchEntryDisable(void)

{
  uint uVar1;
  
  uVar1 = (RAC->SR3);
  write_volatile_4(RAC->SR3,uVar1 & 0xfffffeff);
  return;
}



void RADIO_DccalEnable(void)

{
  uint uVar1;
  
  uVar1 = (RAC->SR3);
  write_volatile_4(RAC->SR3,uVar1 | 1);
  return;
}



void RADIO_Init(void)

{
  uint uVar1;
  
  RADIO_CLKEnable();
  write_volatile_4(BUFC->BUF1_CTRL,2);
  write_volatile_4(BUFC->BUF1_ADDR,(uint)RADIO_rxBuffer);
  write_volatile_4(BUFC->BUF1_THRESHOLDCTRL,0xaf);
  write_volatile_4(BUFC->BUF0_CTRL,2);
  write_volatile_4(BUFC->BUF0_ADDR,(uint)&RADIO_txBuffer);
  write_volatile_4(BUFC->BUF0_THRESHOLDCTRL,0x2020);
  write_volatile_4(BUFC->BUF2_CTRL,0);
  write_volatile_4(BUFC->BUF2_ADDR,(uint)&RADIO_rxLengthBuffer);
  write_volatile_4(BUFC->BUF2_THRESHOLDCTR,0x3e);
  RADIO_FrameControlDescrBufferIdSet(0,0);
  RADIO_FrameControlDescrBufferIdSet(1,0);
  RADIO_FrameControlDescrBufferIdSet(2,1);
  RADIO_FrameControlDescrBufferIdSet(3,1);
  uVar1 = (FRC->CTRL);
  write_volatile_4(FRC->CTRL,uVar1 & 0xffffff0f);
  uVar1 = (FRC->CTRL);
  write_volatile_4(FRC->CTRL,uVar1 | 0xa0);
  DAT_20002a34 = 0x6b65;
  _DAT_e000e280 = 0x80;
  _DAT_e000e100 = 0x80;
  RADIO_BUFCClear(0);
  RADIO_BUFCClear(1);
  RADIO_BUFCClear(2);
  uVar1 = (BUFC->IEN);
  write_volatile_4(BUFC->IEN,uVar1 | 0xb0a0b);
  RADIO_RXBufferDisableThrInt();
  RADIO_SetAndForgetWrite();
  uVar1 = (MODEM->DCCOMP);
  write_volatile_4(MODEM->DCCOMP,uVar1 | 3);
  write_volatile_4(RAC->SR3,0);
  RADIO_DccalEnable();
  _DAT_4308019c = 1;
  _DAT_430801a0 = 1;
  _DAT_430801a4 = 1;
  return;
}



void RADIO_DccalDisable(void)

{
  uint uVar1;
  
  uVar1 = (RAC->SR3);
  write_volatile_4(RAC->SR3,uVar1 & 0xfffffffe);
  return;
}



void RADIO_TxWarmTimeSet(uint32_t time)

{
  undefined2 uVar1;
  uint32_t uVar2;
  
  uVar2 = PA_RampTimeGet();
  uVar1 = RADIO_UsToStimerTickCalc(time - uVar2);
  write_volatile_2(SEQ->REG0AC._0_2_,uVar1);
  uVar1 = RADIO_UsToStimerTickCalc((time - uVar2) + -0x14);
  write_volatile_2(SEQ->REG0AC._2_2_,uVar1);
  return;
}



void RADIO_RxToTxTimeSet(uint32_t time)

{
  undefined2 uVar1;
  uint32_t uVar2;
  
  uVar2 = PA_RampTimeGet();
  uVar1 = RADIO_UsToStimerTickCalc(time - uVar2);
  write_volatile_2(SEQ->REG0A4._0_2_,uVar1);
  uVar1 = RADIO_UsToStimerTickCalc((time - uVar2) + -0x14);
  write_volatile_2(SEQ->REG0A4._2_2_,uVar1);
  return;
}


void RADIO_RxFrameToTxTimeSet(int32_t time)

{
  undefined2 uVar1;
  uint32_t uVar2;
  
  uVar2 = PA_RampTimeGet();
  uVar1 = RADIO_UsToStimerTickCalc(time - uVar2);
  write_volatile_2(SEQ->REG0A8._0_2_,uVar1);
  uVar1 = RADIO_UsToStimerTickCalc((time - uVar2) + -0x14);
  write_volatile_2(SEQ->REG0A8._2_2_,uVar1);
  return;
}



void RADIO_TxToTxTimeSet(uint32_t time)

{
  undefined2 uVar1;
  uint32_t uVar2;
  
  uVar2 = PA_RampTimeGet();
  uVar1 = RADIO_UsToStimerTickCalc(time - uVar2);
  write_volatile_2(SEQ->REG0B8._0_2_,uVar1);
  uVar1 = RADIO_UsToStimerTickCalc((time - uVar2) + -0x14);
  write_volatile_2(SEQ->REG0B8._2_2_,uVar1);
  return;
}



void RADIO_TxToRxTimeSet(uint32_t time)

{
  uint uVar1;
  
  uVar1 = RADIO_UsToStimerTickCalc(time - 4);
  write_volatile_4(SEQ->REG0B0,uVar1);
  return;
}



void RADIO_RxWarmTimeSet(uint32_t time)

{
  uint uVar1;
  
  rxWarmTimeUs = (undefined2)time;
  uVar1 = RADIO_UsToStimerTickCalc(time - 4);
  write_volatile_4(SEQ->REG09C,uVar1);
  return;
}



uint16_t RADIO_RxWarmTimeGet(void)

{
  return rxWarmTimeUs;
}



void RADIO_RxSearchTimeSet(uint32_t time)

{
  RADIO_UsToStimerTickCalc(time);
  write_volatile_4(SEQ->REG0A0,time);
  return;
}



void RADIO_TxToRxSearchTimeSet(uint32_t time)

{
  RADIO_UsToStimerTickCalc(time);
  write_volatile_4(SEQ->REG0B4,time);
  return;
}



uint32_t RADIO_ComputeTxBaudrate(void)

{
  uint uVar1;
  uint32_t uVar2;
  
  uVar2 = CMU_ClockFreqGet(cmuClock_HF);
  uVar1 = (MODEM->TXBR);
  return (((uVar1 << 8) >> 0x18) * (uVar2 >> 3)) / (uVar1 & 0xffff);
}



uint32_t RADIO_ComputeTxSymbolRate(void)

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



uint32_t RADIO_ComputeTxBitRate(void)

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



int16_t RADIO_GetRSSI(void)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  int16_t iVar4;
  bool bVar6;
  uint uVar5;
  
  do {
    INT_Disable();
    uVar5 = (RAC->RXENSRCEN);
    uVar3 = (AGC->RSSI);
    uVar2 = (RAC->RXENSRCEN);
    bVar6 = (uVar2 & 0xff) != 0;
    bVar1 = (uVar5 & 0xff) != 0;
    uVar5 = (int)(uVar3 << 0x10) >> 0x16 & 0xffff;
    iVar4 = (int16_t)uVar5;
    INT_Enable();
    if (uVar5 != 0xfe00) {
      if (bVar6 && bVar1) {
        return iVar4;
      }
      return -0x200;
    }
  } while (bVar6 && bVar1);
  return iVar4;
}


