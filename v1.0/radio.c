#include "radio.h"



void RADIO_WriteSync(uint32_t *addr,uint32_t mask)

{
  *addr = mask;
  return;
}



void RADIO_SetBitSync(uint32_t *addr,uint32_t bit)

{
  *(uint32_t *)(addr + 0x6000000) = 1 << (bit & 0xff);
  return;
}



void RADIO_ClrBitSync(uint32_t *addr,uint32_t bit)

{
  *(uint32_t *)(addr + 0x4000000) = 1 << (bit & 0xff);
  return;
}



/* void RADIO_OrSync(uint32_t *addr,uint32_t mask)

{
  *(uint32_t *)(addr + 0x6000000) = mask;
  return;
} */

void RADIO_OrSync(uint32_t *addr,uint32_t mask)

{
  *addr = mask | *addr;
  return;
}

void RADIO_XorSync(uint32_t *addr,uint32_t mask)

{
  *addr = mask ^ *addr;
  return;
}



void RADIO_AndSync(uint32_t *addr,uint32_t mask)

{
  *addr = mask & *addr;
  return;
}



void RADIO_WaitForSetSync(uint32_t *addr,uint32_t mask)

{
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  do {
  } while ((*addr & mask) != mask);
  CORE_ExitCritical(irqState);
  return;
}


void RADIO_Delay(uint32_t us)

{
  PHY_UTILS_DelayUs(us);
  return;
}



void RADIO_SetAndForgetWrite(void)

{
  uint uVar1;
  undefined4 in_r1;
  undefined2 local_c;
  
  local_c = (undefined2)((uint)in_r1 >> 8);
  SYSTEM_ChipRevisionGet((SYSTEM_ChipRevision_TypeDef *)&local_c);
  write_volatile_4(Peripherals::RAC.IFADCCTRL,0x5153e6c0);
  write_volatile_4(Peripherals::RAC.IFPGACTRL,0x87e6);
  write_volatile_4(Peripherals::RAC.LNAMIXCTRL1,0x880);
  write_volatile_4(Peripherals::RAC.VCOCTRL,0xf00277a);
  if ((local_c._1_1_ == '\x01') && ((byte)local_c < 2)) {
    write_volatile_4(Peripherals::SYNTH.VCOGAIN,0x28);
  }
  write_volatile_4(Peripherals::SYNTH.CTRL,0xac3f);
  write_volatile_4(Peripherals::AGC.MANGAIN,0x1800000);
  write_volatile_4(Peripherals::RAC.LNAMIXCTRL,0);
  write_volatile_4(Peripherals::RAC.SYNTHREGCTRL,0x3636d80);
  uVar1 = read_volatile_4(Peripherals::SYNTH.VCDACCTRL);
  write_volatile_4(Peripherals::SYNTH.VCDACCTRL,uVar1 & 0xffffff80);
  uVar1 = read_volatile_4(Peripherals::SYNTH.VCDACCTRL);
  write_volatile_4(Peripherals::SYNTH.VCDACCTRL,uVar1 | 0x23);
  return;
}


void RADIO_SeqInit(void *src,int32_t len)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  CORE_irqState_t irqState;
  int iVar4;
  
  read_volatile(Peripherals::RAC.STATUS._0_1_);
  write_volatile_4(Peripherals::RAC.VECTADDR,0x21000000);
  write_volatile_4(Peripherals::RAC.SEQCTRL,1);
  irqState = CORE_EnterCritical();
  memcpy((void *)0x21000000,src,len << 2);
  CORE_ExitCritical(irqState);
  write_volatile_4(Peripherals::RAC.R6,0x21000fc0);
  uVar1 = read_volatile_4(Peripherals::SEQ.REG0E8);
  uVar2 = read_volatile_4(Peripherals::SEQ.DYNAMIC_CHPWR_TABLE);
  uVar3 = read_volatile_4(Peripherals::SEQ.PHYINFO);
  memset(&Peripherals::SEQ.REG068,0,0x98);
  write_volatile_4(Peripherals::SEQ.REG0E8,uVar1);
  write_volatile_4(Peripherals::SEQ.DYNAMIC_CHPWR_TABLE,uVar2);
  write_volatile_4(Peripherals::SEQ.PHYINFO,uVar3);
  iVar4 = RADIO_UsToStimerTickCalc(0x3c);
  write_volatile_4(Peripherals::SEQ.REG0BC,-iVar4);
  return;
}


void RADIO_CLKEnable(void)

{
  RADIOCMU_ClockEnable(0x63400,1);
  RADIOCMU_ClockEnable(0x60400,1);
  RADIOCMU_ClockEnable(0x64400,1);
  RADIOCMU_ClockEnable(0x67400,1);
  RADIOCMU_ClockEnable(0x66400,1);
  RADIOCMU_ClockEnable(0x65400,1);
  RADIOCMU_ClockEnable(0x62400,1);
  RADIOCMU_ClockEnable(0x68400,1);
  return;
}



void RADIO_Init(void)

{
  RADIO_CLKEnable();
  BUFC_Init();
  RADIO_SetAndForgetWrite();
  write_volatile_4(Peripherals::MODEM_SET.DCCOMP,3);
  write_volatile_4(Peripherals::RAC.SR3,0);
  write_volatile_4(Peripherals::RAC_SET.SR3,1);
  SYNTH_KvnFreqCompensationEnable();
  SYNTH_DCDCRetimeEnable();
  write_volatile_4(Peripherals::RAC_SET.CTRL,0x380);
  return;
}

/* void RADIO_Init(void)

{
  uint uVar1;
  
  RADIO_CLKEnable();
  write_volatile_4(Peripherals::BUFC.BUF1_CTRL,2);
  write_volatile_4(Peripherals::BUFC.BUF1_ADDR,(uint)RADIO_rxBuffer);
  write_volatile_4(Peripherals::BUFC.BUF1_THRESHOLDCTRL,0xaf);
  write_volatile_4(Peripherals::BUFC.BUF0_CTRL,2);
  write_volatile_4(Peripherals::BUFC.BUF0_ADDR,(uint)&RADIO_txBuffer);
  write_volatile_4(Peripherals::BUFC.BUF0_THRESHOLDCTRL,0x2020);
  write_volatile_4(Peripherals::BUFC.BUF2_CTRL,0);
  write_volatile_4(Peripherals::BUFC.BUF2_ADDR,(uint)&RADIO_rxLengthBuffer);
  write_volatile_4(Peripherals::BUFC.BUF2_THRESHOLDCTR,0x3c);
  write_volatile_4(Peripherals::BUFC.BUF3_CTRL,0);
  write_volatile_4(Peripherals::BUFC.BUF3_ADDR,(uint)&RADIO_txAckBuffer);
  write_volatile_4(Peripherals::BUFC.BUF3_THRESHOLDCTRL,0x2020);
  RADIO_FrameControlDescrBufferIdSet(0,0);
  RADIO_FrameControlDescrBufferIdSet(1,0);
  RADIO_FrameControlDescrBufferIdSet(2,1);
  RADIO_FrameControlDescrBufferIdSet(3,1);
  uVar1 = read_volatile_4(Peripherals::FRC.CTRL);
  write_volatile_4(Peripherals::FRC.CTRL,uVar1 & 0xffffff0f);
  uVar1 = read_volatile_4(Peripherals::FRC.CTRL);
  write_volatile_4(Peripherals::FRC.CTRL,uVar1 | 0xa0);
  DAT_20002d20 = 0x7b05;
  _DAT_e000e280 = 0x80;
  _DAT_e000e100 = 0x80;
  RADIO_BUFCClear(0);
  RADIO_BUFCClear(1);
  RADIO_BUFCClear(2);
  RADIO_BUFCClear(3);
  uVar1 = read_volatile_4(Peripherals::BUFC.IEN);
  write_volatile_4(Peripherals::BUFC.IEN,uVar1 | 0xb0b0a0b);
  RADIO_RXBufferDisableThrInt();
  RADIO_SetAndForgetWrite();
  uVar1 = read_volatile_4(Peripherals::MODEM.DCCOMP);
  write_volatile_4(Peripherals::MODEM.DCCOMP,uVar1 | 3);
  write_volatile_4(Peripherals::RAC.SR3,0);
  _DAT_43081280 = 1;
  SYNTH_KvnFreqCompensationEnable();
  SYNTH_DCDCRetimeEnable();
  _DAT_4308019c = 1;
  _DAT_430801a0 = 1;
  _DAT_430801a4 = 1;
  return;
} */


void RADIO_Config(void *radioconfig)

{
  CORE_irqState_t irqState;
  uint uVar1;
  int iVar2;
  void *__dest;
  uint uVar3;
  void *__src;
  
  iVar2 = (int)radioconfig + 8;
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
      irqState = CORE_EnterCritical();
      memcpy(__dest,__src,uVar3 << 2);
      CORE_ExitCritical(irqState);
    }
    iVar2 = iVar2 + 8;
  }
  PA_BandSelect();
  return;
}



void RADIO_RegisterIrqCallback(uint8_t intNo,void *callbackPtr)

{
  (&EFRDRV_irqClbk)[intNo] = callbackPtr;
  return;
}



void FRC_PRI_IRQHandler(void)

{
                    // WARNING: Could not recover jumptable at 0x00010278. Too many branches
                    // WARNING: Treating indirect jump as call
  (*EFRDRV_irqClbk)(); //20002d14
  return;
}



void RAC_RSM_IRQHandler(void)

{
                    // WARNING: Could not recover jumptable at 0x00010284. Too many branches
                    // WARNING: Treating indirect jump as call
  (*DAT_00010780)(); //DAT_20002d28 EFRDRV_irqClbk + 0x14
  return;
}



void RAC_SEQ_IRQHandler(void)

{
                    // WARNING: Could not recover jumptable at 0x00010290. Too many branches
                    // WARNING: Treating indirect jump as call
  (*DAT_00010780)(); //DAT_20002d28 EFRDRV_irqClbk + 0x14
  return;
}



void AGC_IRQHandler(void)

{
                    // WARNING: Could not recover jumptable at 0x0001029c. Too many branches
                    // WARNING: Treating indirect jump as call
  (*DAT_00010790)(); //DAT_20002d38 EFRDRV_irqClbk + 0x24
  return;
}



void PROTIMER_IRQHandler(void)

{
                    // WARNING: Could not recover jumptable at 0x000102a8. Too many branches
                    // WARNING: Treating indirect jump as call
  (*DAT_00010788)(); //DAT_20002d30 EFRDRV_irqClbk + 0x1C
  return;
}



void BUFC_IRQHandler(void)

{
                    // WARNING: Could not recover jumptable at 0x000102b4. Too many branches
                    // WARNING: Treating indirect jump as call
  (*DAT_00010778)(); //DAT_20002d20 EFRDRV_irqClbk + 0x0C
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FRC_IRQHandler(void)

{
  if (_DAT_e000e200 << 0x18 < 0) {
    BUFC_IRQHandler();
  }
                    // WARNING: Could not recover jumptable at 0x000102d4. Too many branches
                    // WARNING: Treating indirect jump as call
  (*DAT_00010770)(); //DAT_20002d18 EFRDRV_irqClbk + 0x04
  return;
}



void MODEM_IRQHandler(void)

{
                    // WARNING: Could not recover jumptable at 0x000102e4. Too many branches
                    // WARNING: Treating indirect jump as call
  (*DAT_00010774)(); //DAT_20002d1c EFRDRV_irqClbk + 0x08
  return;
}



bool RADIO_IsRxActive(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::RAC.STATUS);
  uVar1 = (uVar1 << 4) >> 0x1c;
  if ((uVar1 != 3) && (uVar1 != 7)) {
    return uVar1 == 4;
  }
  return true;
}



int32_t RADIO_RxTrailDataLength(void)

{
  uint uVar1;
  int32_t iVar2;
  
  uVar1 = read_volatile_4(Peripherals::FRC.TRAILRXDATA);
  if ((uVar1 & 0x20) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = 4;
  }
  if ((int)(uVar1 << 0x1b) < 0) {
    iVar2 = iVar2 + 2;
  }
  if ((int)(uVar1 << 0x1c) < 0) {
    iVar2 = iVar2 + 2;
  }
  if ((int)(uVar1 << 0x1d) < 0) {
    iVar2 = iVar2 + 2;
  }
  if ((int)(uVar1 << 0x1e) < 0) {
    iVar2 = iVar2 + 1;
  }
  if ((int)(uVar1 << 0x1f) < 0) {
    iVar2 = iVar2 + 1;
  }
  return iVar2;
}



void RADIO_FrameControlDescrBufferIdSet(int32_t fcd,int32_t id)

{
  (&Peripherals::FRC.FCD0)[fcd] = (&Peripherals::FRC.FCD0)[fcd] & 0xfffffcff;
  (&Peripherals::FRC.FCD0)[fcd] = (&Peripherals::FRC.FCD0)[fcd] | id << FRC_FCD0_BUFFER_Pos; //8;
  return;
}



/* void RADIO_FrameControlDescrConfigSet
               (int param_1,uint param_2,int param_3,int param_4,byte param_5,byte param_6)

{
  (&Peripherals::FRC_CLR.FCD0)[param_1] = 31999;
  (&Peripherals::FRC_SET.FCD0)[param_1] =
       param_2 | (uint)param_6 << 10 | (uint)param_5 << 0xb | param_4 << 0xc | param_3 << 0xe;
  return;
} */

/* void RADIO_FrameControlDescrConfigSet
               (int param_1,uint param_2,int param_3,int param_4,byte param_5,byte param_6)

{
  (&Peripherals::FRC_CLR.FCD0)[param_1] = 0x7cff;//31999;
  (&Peripherals::FRC_SET.FCD0)[param_1] =
       param_2 | (uint)param_6 << FRC_FCD0_INCLUDECRC_Pos | (uint)param_5 << FRC_FCD0_CALCCRC_Pos | param_4 << FRC_FCD0_SKIPCRC_Pos | param_3 << FRC_FCD0_SKIPWHITE_Pos;
  return;
} */

void RADIO_FrameControlDescrConfigSet
               (int32_t fcd,uint8_t words,uint8_t skipwhite,uint8_t skipcrc,uint8_t calccrc,
               uint8_t includecrc)

{
  (&Peripherals::FRC.FCD0)[fcd] = (&Peripherals::FRC.FCD0)[fcd] & 0xffff8300;
  (&Peripherals::FRC.FCD0)[fcd] =
       (uint)words | (uint)includecrc << 10 | (uint)calccrc << 0xb | (uint)skipcrc << 0xc |
       (uint)skipwhite << 0xe | (&Peripherals::FRC.FCD0)[fcd];
  return;
}

void RADIO_FrameDescsConfig
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  RADIO_FrameControlDescrConfigSet(0,0xff,param_1,param_2,param_3,param_4,param_3);
  RADIO_FrameControlDescrConfigSet(2,0xff,param_1,param_2,param_3,param_4);
  return;
}



void RADIO_FRCErrorHandle(void)

{
  BUFC_RxBufferReset();
  return;
}



void RADIO_DemodResetOnRxsearchEntryEnable(void)

{
  write_volatile_4(Peripherals::RAC_SET.SR3,0x100);
  return;
}



void RADIO_DemodResetOnRxsearchEntryDisable(void)

{
  write_volatile_4(Peripherals::RAC_CLR.SR3,0x100);
  return;
}



void RADIO_DccalEnable(void)

{
  write_volatile_4(Peripherals::RAC_SET.SR3,1);
  return;
}



void RADIO_DccalDisable(void)

{
  write_volatile_4(Peripherals::RAC_CLR.SR3,1);
  return;
}



void RADIO_TxHoldOffEnable(void)

{
  write_volatile_4(Peripherals::RAC_SET.SR3,0x20000000);
  return;
}



void RADIO_TxHoldOffDisable(void)

{
  write_volatile_4(Peripherals::RAC_CLR.SR3,0x20000000);
  return;
}



void RADIO_VcoFineCalEnable(void)

{
  write_volatile_4(Peripherals::RAC_SET.SR3,0x20);
  return;
}



void RADIO_VcoFineCalDisable(void)

{
  write_volatile_4(Peripherals::RAC_CLR.SR3,0x20);
  return;
}



uint32_t RADIO_ComputeTxBaudrate(void)

{
  uint uVar1;
  uint32_t uVar2;
  
  uVar2 = CMU_ClockFreqGet(cmuClock_HF);
  uVar1 = read_volatile_4(Peripherals::MODEM.TXBR);
  return (((uVar1 << 8) >> 0x18) * (uVar2 >> 3)) / (uVar1 & 0xffff);
}



uint32_t RADIO_ComputeRxBaudrate(void)

{
  uint uVar1;
  uint uVar2;
  uint32_t uVar3;
  int iVar4;
  uint uVar5;
  
  uVar2 = read_volatile_4(Peripherals::MODEM.CF);
  uVar1 = read_volatile_4(Peripherals::MODEM.RXBR);
  uVar5 = (uVar1 << 0x16) >> 0x1b;
  iVar4 = (((uVar2 << 0xf) >> 0x12) * (uint)(byte)(&modemCfDec0Factors)[uVar2 & 7] +
          (uint)(byte)(&modemCfDec0Factors)[uVar2 & 7]) * 2;
  uVar3 = CMU_ClockFreqGet(cmuClock_HF);
  return (uVar5 * uVar3) /
         ((((uVar2 << 9) >> 0x1a) * iVar4 + iVar4) *
         (uVar5 * ((uVar1 << 0x13) >> 0x1d) + (uVar1 & 0x1f)));
}



uint32_t RADIO_ComputeTxSymbolRate(void)

{
  uint uVar1;
  uint32_t uVar2;
  
  uVar2 = RADIO_ComputeTxBaudrate();
  uVar1 = read_volatile_4(Peripherals::MODEM.CTRL0);
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
  
  uVar1 = read_volatile_4(Peripherals::MODEM.CTRL0);
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
    uVar1 = read_volatile_4(Peripherals::MODEM.CTRL0);
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
  short sVar1;
  uint uVar2;
  CORE_irqState_t irqState;
  uint uVar3;
  uint uVar4;
  
  do {
    irqState = CORE_EnterCritical();
    uVar3 = read_volatile_4(Peripherals::RAC.STATUS);
    uVar3 = uVar3 & 0xf000000;
    uVar2 = read_volatile_4(Peripherals::AGC.RSSI);
    uVar4 = read_volatile_4(Peripherals::RAC.STATUS);
    uVar4 = uVar4 & 0xf000000;
    sVar1 = (short)uVar2 >> 6;
    CORE_ExitCritical(irqState);
    if (sVar1 != -0x200) {
      if ((uVar4 == 0x2000000 || uVar4 == 0x3000000) && (uVar3 == 0x2000000 || uVar3 == 0x3000000))
      {
        return sVar1;
      }
      return -0x200;
    }
  } while ((uVar4 == 0x2000000 || uVar4 == 0x3000000) && (uVar3 == 0x2000000 || uVar3 == 0x3000000))
  ;
  return -0x200;
}



RAIL_Status_t RADIO_SetAgcCcaParams(uint32_t period,uint8_t threshold)

{
  uint uVar1;
  RAIL_Status_t RVar2;
  uint32_t uVar3;
  uint uVar4;
  
  uVar3 = RADIO_ComputeRxBaudrate();
  for (uVar4 = 0; (uint)(1 << (uVar4 & 0xff)) < (period * uVar3) / 1000000; uVar4 = uVar4 + 1) {
    if (uVar4 == 0x10) {
      return RAIL_STATUS_INVALID_PARAMETER;
    }
  }
  uVar1 = read_volatile_4(Peripherals::AGC.CTRL1);
  write_volatile_4(Peripherals::AGC.CTRL1,uVar1 & 0xfffff0ff);
  uVar1 = read_volatile_4(Peripherals::AGC.CTRL1);
  write_volatile_4(Peripherals::AGC.CTRL1,uVar1 | uVar4 << 8);
  uVar4 = read_volatile_4(Peripherals::AGC.CTRL1);
  if ((uVar4 & 0xff) == 0x80) {
    return RAIL_STATUS_INVALID_STATE;
  }
  RVar2 = RADIO_AGCCCAThresholdSet(threshold);
  return RVar2;
}


RAIL_Status_t RADIO_AGCCCAThresholdSet(uint8_t threshold)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::AGC.CTRL1);
  write_volatile_4(Peripherals::AGC.CTRL1,uVar1 & 0xffffff00);
  uVar1 = read_volatile_4(Peripherals::AGC.CTRL1);
  write_volatile_4(Peripherals::AGC.CTRL1,uVar1 | threshold);
  return RAIL_STATUS_NO_ERROR;
}



uint32_t RADIO_CalcRssiPeriod(uint32_t time)

{
  undefined uVar1;
  longlong lVar2;
  uint32_t uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  undefined8 uVar10;
  ulonglong uVar11;
  
  uVar4 = read_volatile_4(Peripherals::AGC.CTRL1);
  write_volatile_4(Peripherals::AGC.CTRL1,uVar4 | 0x8000);
  uVar4 = read_volatile_4(Peripherals::MODEM.CF);
  uVar5 = read_volatile_4(Peripherals::MODEM.CF);
  uVar6 = read_volatile_4(Peripherals::MODEM.CF);
  uVar1 = (&modemCfDec0Factors)[uVar4 & 7];
  uVar3 = CMU_ClockFreqGet(cmuClock_HF);
  uVar10 = __aeabi_uldivmod((int)((ulonglong)uVar3 * 1000),(int)((ulonglong)uVar3 * 1000 >> 0x20),
                            uVar1,0);
  uVar10 = __aeabi_uldivmod((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),
                            ((uVar5 << 0xf) >> 0x12) + 1,0);
  uVar11 = __aeabi_uldivmod((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),((uVar6 << 9) >> 0x1a) + 1,
                            0);
  iVar8 = (int)(uVar11 >> 0x20);
  uVar4 = __aeabi_uldivmod(0xdb000000,0x7558b,(int)uVar11,iVar8);
  if (uVar4 < time) {
    return 1;
  }
  lVar2 = (uVar11 & 0xffffffff) * (ulonglong)time;
  uVar7 = (undefined4)lVar2;
  iVar8 = time * iVar8 + (int)((ulonglong)lVar2 >> 0x20);
  uVar5 = __aeabi_uldivmod(uVar7,iVar8,1000000000,0);
  iVar9 = 1;
  uVar4 = 0;
  do {
    uVar6 = uVar4 + 1;
    if (uVar5 <= (uint)(1 << (uVar6 & 0xff))) {
LAB_00008302:
      uVar5 = read_volatile_4(Peripherals::AGC.CTRL1);
      write_volatile_4(Peripherals::AGC.CTRL1,uVar5 & 0xfffff0ff);
      uVar5 = read_volatile_4(Peripherals::AGC.CTRL1);
      write_volatile_4(Peripherals::AGC.CTRL1,uVar5 | uVar4 << 8);
      uVar10 = __aeabi_uldivmod(uVar7,iVar8,10000000,0);
      uVar10 = __aeabi_uldivmod((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),iVar9,0);
      iVar8 = __aeabi_uldivmod((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),100,0);
      uVar4 = ((int)uVar10 + iVar8 * -100 & 0xffU) / 3;
      if (uVar4 < 0x20) {
        if (uVar4 == 0) {
          uVar4 = read_volatile_4(Peripherals::AGC.CTRL1);
          write_volatile_4(Peripherals::AGC.CTRL1,uVar4 & 0xffe0ffff | 0x10000);
          uVar4 = read_volatile_4(Peripherals::AGC.CTRL1);
          write_volatile_4(Peripherals::AGC.CTRL1,uVar4 & 0xfc1fffff | 0x200000);
          return 0;
        }
      }
      else {
        uVar4 = 0x1f;
      }
      uVar5 = read_volatile_4(Peripherals::AGC.CTRL1);
      write_volatile_4(Peripherals::AGC.CTRL1,uVar5 & 0x3ffffff | iVar8 << 0x1a);
      uVar5 = read_volatile_4(Peripherals::AGC.CTRL1);
      write_volatile_4(Peripherals::AGC.CTRL1,uVar5 & 0xffe0ffff | uVar4 << 0x10);
      uVar4 = read_volatile_4(Peripherals::AGC.CTRL1);
      write_volatile_4(Peripherals::AGC.CTRL1,uVar4 | 0x3e00000);
      return 0;
    }
    if (uVar6 == 0x10) {
      uVar4 = 0xf;
      goto LAB_00008302;
    }
    iVar9 = iVar9 << 1;
    uVar4 = uVar6;
  } while( true );
}



void RADIO_SetCRCInitVal(uint32_t val)

{
  write_volatile_4(Peripherals::CRC.INIT,val);
  write_volatile_4(Peripherals::CRC.CMD,1);
  return;
}


