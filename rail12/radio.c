#include "radio.h"


void RADIO_BUFCClear(uint32_t buf)

{
  *(undefined4 *)((buf * 0x30 + 0x42181028) * 0x20) = 1;
}



void RADIO_WriteSync(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
}



void RADIO_OrSync(uint *param_1,uint param_2)

{
  *param_1 = param_2 | *param_1;
}



void RADIO_XorSync(uint *param_1,uint param_2)

{
  *param_1 = param_2 ^ *param_1;
}



void RADIO_AndSync(uint *param_1,uint param_2)

{
  *param_1 = param_2 & *param_1;
}



void RADIO_WaitForSetSync(uint *param_1,uint param_2)

{
  INT_Disable();
  do {
  } while ((*param_1 & param_2) != param_2);
  INT_Enable();
}



void RADIO_UsToStimerTickCalc(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  longlong lVar1;
  uint uVar2;
  
  uVar2 = RADIOCMU_ClockFreqGet(0x75160);
  param_1 = param_1 & ~((int)param_1 >> 0x1f);
  lVar1 = (ulonglong)uVar2 * (ulonglong)param_1;
  __aeabi_uldivmod((int)lVar1,uVar2 * ((int)param_1 >> 0x1f) + (int)((ulonglong)lVar1 >> 0x20),8000000,0,param_4);
}



void RADIO_Delay(undefined4 param_1,uint32_t us)

{
  PHY_UTILS_DelayUs(us);
}



void RADIO_BUFCWriteContSync_constprop_3(uint8_t *addr,uint16_t len)

{
  byte *addr;
  
  INT_Disable();
  pbVar1 = addr;
  while (pbVar1 != addr + len) 
  {
    BUFC->BUF0_WRITEDATA = (uint)*pbVar1;
    pbVar1 ++;
  }
  INT_Enable();
}



void RADIO_ClrBitSync(int param_1,int param_2)

{
  *(undefined4 *)((param_2 + (param_1 + 0x2100000) * 8) * 4) = 0;
}



void RADIO_SetBitSync(int param_1,int param_2)

{
  *(undefined4 *)((param_2 + (param_1 + 0x2100000) * 8) * 4) = 1;
}



void RADIO_ModemConfigFixup(void)

{
  SEQ->SYNTHLPFCTRLTX = RAC->LPFCTRL;
  SEQ->SYNTHLPFCTRLRX = RAC->LPFCTRL & 0xfffffff0;
}



void RADIO_SetAndForgetWrite(undefined4 param_1,uint param_2,undefined4 param_3)

{
  undefined4 in_r1;
  undefined2 local_c;
  
  local_c = (undefined2)((uint)in_r1 >> 8);
  SYSTEM_ChipRevisionGet((SYSTEM_ChipRevision_TypeDef *)&local_c);
  RAC->IFADCCTRL = 0x1153e6c0;
  RAC->IFPGACTRL = 0x87e6;
  RAC->LNAMIXCTRL1 = 0x880;
  RAC->VCOCTRL = 0xf00277a;
  if ((local_c._1_1_ == '\x01') && ((byte)local_c < 2)) SYNTH->VCOGAIN = 0x28;
  SYNTH->CTRL = 0xac3f;
  AGC->MANGAIN = 0x1800000;
  RAC->LNAMIXCTRL = 0;
  RAC->SYNTHREGCTRL = 0x3636d80;
}



void RADIO_SeqInit(void *seqprogstart,int seqprogsize)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  RAC->STATUS._0_1_;
  RAC->VECTADDR = 0x21000000;
  RAC->SEQCTRL = 1;
  INT_Disable();
  memcpy((void *)0x21000000,seqprogstart,seqprogsize << 2);
  INT_Enable();
  RAC->R6 = 0x21000fcc;
  uVar1 = SEQ->REG0C0;
  uVar2 = SEQ->REG0C4;
  uVar3 = SEQ->REG0C8;
  memset(&SEQ->REG06C,0,0x94);
  SEQ->REG0C0 = uVar1;
  SEQ->REG0C4 = uVar2;
  SEQ->REG0C8 = uVar3;
  SEQ->REG0BC = -i(RADIO_UsToStimerTickCalc(0x3c)); 
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
}


void RADIO_Config(void *config)

{
  uint uVar1;
  int iVar2;
  void *__dest;
  uint uVar3;
  void *__src;
  
  iVar2 = (int)config + 8;
  while( true ) 
  {
    uVar1 = *(uint *)(iVar2 + -8);
    if (uVar1 == 0xffffffff) break;
    uVar3 = (uVar1 << 8) >> 0x18;
    __dest = (void *)(uVar1 & 0xffff | (uint)(&regBases)[(uVar1 << 4) >> 0x1c]);
    if (uVar3 < 2) (**(code **)(&EFRDRV_actionFunc + (uVar1 >> 0x1c) * 4))(__dest,*(undefined4 *)(iVar2 + -4));
    else 
	{
      __src = *(void **)(iVar2 + -4);
      INT_Disable();
      memcpy(__dest,__src,uVar3 << 2);
      INT_Enable();
    }
    iVar2 = iVar2 + 8;
  }
  PA_BandSelect();
}



void RADIO_RegisterIrqCallback(uint32_t cbnumber,uint32_t address)

{
  (&EFRDRV_irqClbk)[cbnumber] = address;
}



void FRC_PRI_IRQHandler(void)

{
	RADIO_IRQHandler();
    //(*EFRDRV_irqClbk)();
}



void FRC_IRQHandler(void)

{
	RADIO_IRQHandler();
    //(*DAT_000109d0)();
}



/* void RAC_RSM_IRQHandler(void)

{
                    // WARNING: Could not recover jumptable at 0x000102f8. Too many branches
                    // WARNING: Treating indirect jump as call
  (*DAT_000109e0)();
  return;
} */

void RAC_RSM_IRQHandler(void)

{
  uint32_t flags;

  flags = RAC->IEN & RAC->IF;
  RAC->IFC = flags & 0xffff;
  if (flags & RAC_IF_STATECHANGE_Msk) RAILCb_RadioStateChanged((RAC->STATUS & RAC_STATUS_STATE_Msk) >> RAC_STATUS_STATE_Pos);
  if (flags & RAC_IF_BUSERROR_Msk) GENERIC_PHY_IssueCallback(0,0,enabledPhyEvents & 0x10);
}

void RAC_SEQ_IRQHandler(void)

{
	RADIO_IRQHandler();
    //(*DAT_000109e0)();
}



/* void AGC_IRQHandler(void)

{
                    // WARNING: Could not recover jumptable at 0x00010310. Too many branches
                    // WARNING: Treating indirect jump as call
  (*DAT_000109f0)();
  return;
}
 */
void AGC_IRQHandler(void)

{
  uint32_t flags;
  undefined4 in_r3;
  
  flags = AGC->IEN & AGC->IF;
  AGC->IFC = flags;
  if (flags & AGC_IF_RSSIVALID_Msk) 
  {
    RAILInt_Assert((uint8_t)enabledRailEvents & 1,0x12);
    GENERIC_PHY_IssueCallback(1,0,0,in_r3);
  }
}

void PROTIMER_IRQHandler(void)

{
	RADIO_IRQHandler();
	//(*DAT_000109e8)();
}



void BUFC_IRQHandler(void)

{
	RADIO_IRQHandler();
	//(*DAT_000109d8)();
}



void MODEM_IRQHandler(void)

{
	RADIO_IRQHandler();
	//(*DAT_000109d4)();



void RADIO_BUFCConfig(int param_1,undefined4 param_2,uint param_3,uint param_4,uint param_5)

{
  int iVar1;
  
  iVar1 = count_leading_zeroes(param_2);
  (&BUFC->BUF0_CTRL)[param_1 * 0xc] = 0x19 - iVar1;
  (&BUFC->BUF0_ADDR)[param_1 * 0xc] = param_3;
  (&BUFC->BUF0_THRESHOLDCTRL)[param_1 * 0xc] = param_4 | param_5;
}



uint16_t RADIO_BUFCBytesAvailable(int32_t buf)

{
  return (&BUFC->BUF0_STATUS)[buf * 0xc] & 0x1fff;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void RADIO_TxBufferSet(undefined4 param_1,int param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  
  RADIO_BUFCClear(0);
  RADIO_BUFCWriteContSync_constprop_3(param_1,param_2);
  if (param_4 == 0) return;
  uVar1 = 0x100U - param_2 & 0xffff;
  bufcTxStreaming = (undefined2)param_2;
  DAT_00010b82 = (undefined2)param_4;
  DAT_00010b8c = (undefined2)uVar1;
  DAT_00010b84 = param_1;
  DAT_00010b88 = param_3;
  if (uVar1 < param_4) 
  {
    RADIO_BUFCWriteContSync_constprop_3(param_3);
    //_DAT_43021d90 = 1;
	BUS_RegMaskedSet(&BUFC->IEN,BUFC_IEN_BUF0THR_Msk);
    return;
  }
  RADIO_BUFCWriteContSync_constprop_3(param_3,param_4);
}



void RADIO_TxBufferReset(void)

{
  RADIO_TxBufferSet(0,0,0,0);
}



void RADIO_RXBufferEnableThrInt(void)

{
  BUFC->IEN | BUFC_IEN_BUF1THR_Msk;
}



void RADIO_RXBufferDisableThrInt(void)

{
  BUFC->IEN &= ~BUFC_IEN_BUF1THR_Msk; //0xfffffbff;
}



bool RADIO_IsRxActive(void)

{
  uint32_t state;
  
  state = (RAC->STATUS & RAC_STATUS_STATE_Msk) >> RAC_STATUS_STATE_Pos;
  if ((state != 3) && (state != 7)) return (state == 4);
  return true;
}



void RADIO_RxBufferSet(uint32_t addr)

{
  if (param_1 != 0) 
  {
    _DAT_43022d80 = 1; //???
  }
  bufcRxStreaming = 0;
  RxBuffer = addr;
}



uint32_t RADIO_RxBufferGet(void)

{
  return RxBuffer;
}



void RADIO_RxBufferReset(void)

{
  bufcRxStreaming = 0;
  RADIO_BUFCClear(1);
  RADIO_BUFCClear(2);
}



/* void RADIO_BUFCIrqHandler(void)

{
  ushort uVar1;
  uint uVar2;
  uint8_t *addr;
  uint uVar3;
  uint uVar4;
  
  uVar3 = (BUFC->IF);
  uVar2 = (BUFC->IEN);
  flags = BUFC->IEN & BUFC->IF;
  BUFC->IFC = flags;
  if (flags & BUFC_IEN_BUF0THR_Msk) 
  {
    uVar3 = (uint)DAT_20002bb6 - (uint)DAT_20002bc0 & 0xffff;
    addr = (uint8_t *)(DAT_20002bbc + (uint)DAT_20002bc0);
    if (uVar3 < 0xe1) 
	{
      RADIO_BUFCWriteContSync_constprop_3(addr,(uint16_t)uVar3);
      _DAT_43021d90 = 0;
    }
    else 
	{
      uVar1 = DAT_20002bc0 + 0xe0;
      RADIO_BUFCWriteContSync_constprop_3(addr,0xe0);
      DAT_20002bc0 = uVar1;
    }
  }
  if (flags & BUFC_IEN_BUF1THR_Msk) RFTEST_BerEmptyBufcAndUpdateStats();
  if (flags & (BUFC_IEN_BUF1CORR_Msk | BUFC_IEN_BUF1UF_Msk)) RADIO_RxBufferReset();
  if (flags & (BUFC_IEN_BUF0CORR_Msk | BUFC_IEN_BUF0OF_Msk)) 
  {
    _DAT_43080114 = 1;
    RADIO_TxBufferReset();
  }
  if (flags & BUFC_IEN_BUF0UF_Msk) RADIO_TxBufferReset();
}
 */


uint32_t RADIO_RxTrailDataLength(void)

{
  uint32_t len;

  if (!(FRC->TRAILRXDATA & 0x20) == 0) len = 0;
  else len = 4;
  if (FRC->TRAILRXDATA & FRC_TRAILRXDATA_PROTIMERCC0WRAPH_Msk) len += 2;
  if (FRC->TRAILRXDATA & FRC_TRAILRXDATA_PROTIMERCC0WRAPL_Msk) len += 2;
  if (FRC->TRAILRXDATA & FRC_TRAILRXDATA_PROTIMERCC0BASE_Msk) len += 2;
  if (FRC->TRAILRXDATA & FRC_TRAILRXDATA_CRCOK_Msk) len ++;
  if (FRC->TRAILRXDATA & FRC_TRAILRXDATA_RSSI_Msk) len ++;
  return len;
}



bool RADIO_RxBufferPacketAvailable(void)

{
  return 1 < (BUFC->BUF2_STATUS & 0x1fff);
}




uint16_t RADIO_RxBufferBytesAvailable(void)

{
  return BUFC->BUF1_STATUS & 0x1fff;
}



uint16_t RADIO_TxBufferBytesAvailable(void)

{
  return BUFC->BUF0_STATUS & 0x1fff;
}



uint16_t RADIO_RxLengthBufferBytesAvailable(void)

{
  return BUFC->BUF2_STATUS & 0x1fff;
}



uint8_t RADIO_RxBufferReadByte(void)

{
  return (uint8_t)BUFC->BUF1_READDATA;
}



void RADIO_FrameControlDescrBufferIdSet(uint32_t buf,int32_t id)

{
  (&FRC->FCD0)[buf] = (&FRC->FCD0)[buf] & 0xfffffcff;
  (&FRC->FCD0)[buf] = (&FRC->FCD0)[buf] | id << 8;
}



void RADIO_FrameControlDescrConfigSet(int param_1,uint param_2,int param_3,int param_4,byte param_5,byte param_6)

{
  (&FRC->FCD0)[param_1] = (&FRC->FCD0)[param_1] & 0xffff8300;
  (&FRC->FCD0)[param_1] = param_2 | (uint)param_6 << 10 | (uint)param_5 << 0xb | param_4 << 0xc | param_3 << 0xe | (&FRC->FCD0)[param_1];
}



void RADIO_FrameDescsConfig(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  RADIO_FrameControlDescrConfigSet(0,0xff,param_1,param_2,param_3,param_4,param_3);
  RADIO_FrameControlDescrConfigSet(2,0xff,param_1,param_2,param_3,param_4);
}



uint8_t RADIO_BUFCRead(uint32_t buf)

{
  return (&BUFC->BUF0_READDATA)[buf * 0xc] & 0xff;
}



void RADIO_BUFCReadContASync(uint32_t buf,uint8_t *addr,uint16_t len)

{
  uint8_t *puVar1;
  
  puVar1 = addr + len;
  for (; addr != puVar1; addr = addr + 1) *addr = (uint8_t)(&BUFC->BUF0_READDATA)[buf * 0xc];
}



void RADIO_RxBufferReadBytes(uint8_t *addr,uint16_t len)

{
  RADIO_BUFCReadContASync(1,addr,len);
}



void RADIO_RxBufferDropBytes(uint param_1,undefined4 param_2)

{
  undefined4 uStack12;
  
  uStack12 = param_2;
  for (; param_1 != 0; param_1 = param_1 - 1 & 0xffff) RADIO_RxBufferReadBytes((uint8_t *)((int)&uStack12 + 3),1);
}



uint RADIO_RxLengthReadNext(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint local_c;
  undefined4 uStack8;
  
  local_c = param_2;
  uStack8 = param_3;
  iVar1 = RADIO_RxBufferPacketAvailable();
  if (iVar1 == 0) local_c = 0xffff;
  else 
  {
    RADIO_BUFCReadContASync(2,&local_c,2,param_4,param_1);
    local_c = local_c & 0xff;
  }
  return local_c;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

int RADIO_RxBufferFinalizeAndGet(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = RADIO_RxLengthReadNext();
  iVar1 = DAT_00010b7c;
  if (iVar2 != 0xffff) 
  {
    RADIO_BUFCReadContASync(1,DAT_00010b7c + (uint)bufcRxStreaming,iVar2 - (uint)bufcRxStreaming,0xffff,param_4);
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
}



void RADIO_DemodResetOnRxsearchEntryEnable(void)

{
  RAC->SR3 |= 0x100;
}



void RADIO_DemodResetOnRxsearchEntryDisable(void)

{
  RAC->SR3 &= 0xfffffeff;
}



void RADIO_DccalEnable(void)

{
  RAC->SR3 |= 1;
}



void RADIO_Init(void)

{
  RADIO_CLKEnable();
  BUFC->BUF1_CTRL = 2;
  BUFC->BUF1_ADDR = (uint)RADIO_rxBuffer;
  BUFC->BUF1_THRESHOLDCTRL = 0xaf;
  BUFC->BUF0_CTRL = 2;
  BUFC->BUF0_ADDR = (uint)&RADIO_txBuffer;
  BUFC->BUF0_THRESHOLDCTRL = 0x2020;
  BUFC->BUF2_CTRL = 0;
  BUFC->BUF2_ADDR = (uint)&RADIO_rxLengthBuffer;
  BUFC->BUF2_THRESHOLDCTR = 0x3e;
  RADIO_FrameControlDescrBufferIdSet(0,0);
  RADIO_FrameControlDescrBufferIdSet(1,0);
  RADIO_FrameControlDescrBufferIdSet(2,1);
  RADIO_FrameControlDescrBufferIdSet(3,1);
  FRC->CTRL &= 0xffffff0f;
  FRC->CTRL |= 0xa0;
  DAT_20002a34 = 0x6b65;
  _DAT_e000e280 = 0x80;
  _DAT_e000e100 = 0x80;
  RADIO_BUFCClear(0);
  RADIO_BUFCClear(1);
  RADIO_BUFCClear(2);
  BUFC->IEN |= 0xb0a0b;
  RADIO_RXBufferDisableThrInt();
  RADIO_SetAndForgetWrite();
  MODEM->DCCOMP |= 3;
  RAC->SR3 = 0;
  RADIO_DccalEnable();
  _DAT_4308019c = 1;
  _DAT_430801a0 = 1;
  _DAT_430801a4 = 1;
}



void RADIO_DccalDisable(void)

{
  RAC->SR3 &= 0xfffffffe;
}



void RADIO_TxWarmTimeSet(uint32_t time)

{
  SEQ->REG0AC._0_2_ = RADIO_UsToStimerTickCalc(time - PA_RampTimeGet());
  SEQ->REG0AC._2_2_ = RADIO_UsToStimerTickCalc((time - PA_RampTimeGet()) - 20);
}



void RADIO_RxToTxTimeSet(uint32_t time)

{
  SEQ->REG0A4._0_2_ = RADIO_UsToStimerTickCalc(time - PA_RampTimeGet());
  SEQ->REG0A4._2_2_ = RADIO_UsToStimerTickCalc((time - PA_RampTimeGet()) - 20);
}


void RADIO_RxFrameToTxTimeSet(int32_t time)

{
  SEQ->REG0A8._0_2_ = RADIO_UsToStimerTickCalc(time - PA_RampTimeGet());
  SEQ->REG0A8._2_2_ = RADIO_UsToStimerTickCalc((time - PA_RampTimeGet()) - 20);
}



void RADIO_TxToTxTimeSet(uint32_t time)

{
  SEQ->REG0B8._0_2_ = RADIO_UsToStimerTickCalc(time - PA_RampTimeGet());
  SEQ->REG0B8._2_2_ = RADIO_UsToStimerTickCalc((time - PA_RampTimeGet()) - 20);
}



void RADIO_TxToRxTimeSet(uint32_t time)

{
  SEQ->REG0B0 = RADIO_UsToStimerTickCalc(time - 4);
}



void RADIO_RxWarmTimeSet(uint32_t time)

{
  rxWarmTimeUs = (uint16_t)time;
  SEQ->REG09C = RADIO_UsToStimerTickCalc(time - 4);
}



uint16_t RADIO_RxWarmTimeGet(void)

{
  return rxWarmTimeUs;
}



void RADIO_RxSearchTimeSet(uint32_t time)

{
  SEQ->REG0A0 = RADIO_UsToStimerTickCalc(time);
}



void RADIO_TxToRxSearchTimeSet(uint32_t time)

{
   SEQ->REG0B4 = RADIO_UsToStimerTickCalc(time);
}



uint32_t RADIO_ComputeTxBaudrate(void)

{
  return (((MODEM->TXBR << 8) >> 0x18) * (CMU_ClockFreqGet(cmuClock_HF) >> 3)) / (MODEM->TXBR & 0xffff);
}



uint32_t RADIO_ComputeTxSymbolRate(void)

{
  uint32_t uVar2;
  
  uVar2 = RADIO_ComputeTxBaudrate();
  if ((MODEM->CTRL0 & 0x30) == 0x20) uVar2 = uVar2 / (((MODEM->CTRL0 << 0x10) >> 0x1b) + 1);
  return uVar2;
}



uint32_t RADIO_ComputeTxBitRate(void)

{
  uint32_t uVar3;
  
  if ((MODEM->CTRL0 & 0x30) == 0x20) 
  {
    uVar3 = ((MODEM->CTRL0 << 0x10) >> 0x1b) / ((MODEM->CTRL0 << 0xd) >> 0x1d);
    if ((MODEM->CTRL0 & 0x180000) != 0) uVar3 = uVar3 << 1;
    uVar3 = uVar3 >> 1;
    if (2 < uVar3) uVar3 = 4;
  }
  else 
  {
    if (((MODEM->CTRL0 & 0x1c0) == 0x40) || ((MODEM->CTRL0 & 0x1c0) == 0x100)) uVar3 = 2;
    else uVar3 = 1;
  }
  return uVar3 * RADIO_ComputeTxSymbolRate();
}



int16_t RADIO_GetRSSI(void)

{
  bool bVar1;
  int16_t iVar4;
  bool bVar6;
  uint uVar5;
  
  do 
  {
    INT_Disable();
    bVar6 = (RAC->RXENSRCEN & 0xff) != 0;
    bVar1 = (RAC->RXENSRCEN & 0xff) != 0;
    uVar5 = (int)(AGC->RSSI << 0x10) >> 0x16 & 0xffff;
    iVar4 = (int16_t)uVar5;
    INT_Enable();
    if (uVar5 != 0xfe00) 
	{
      if (bVar6 && bVar1) return iVar4;
      return -0x200;
    }
  } while (bVar6 && bVar1);
  return iVar4;
}


