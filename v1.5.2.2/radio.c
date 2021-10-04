#include "radio.h"



void RADIO_WriteSync(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  return;
}



void RADIO_SetBitSync(int param_1,uint param_2)

{
  *(int *)(param_1 + 0x6000000) = 1 << (param_2 & 0xff);
  return;
}



void RADIO_ClrBitSync(int param_1,uint param_2)

{
  *(int *)(param_1 + 0x4000000) = 1 << (param_2 & 0xff);
  return;
}



void RADIO_OrSync(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x6000000) = param_2;
  return;
}



void RADIO_XorSync(uint *param_1,uint param_2)

{
  *param_1 = param_2 ^ *param_1;
  return;
}



void RADIO_AndSync(int param_1,uint param_2)

{
  *(uint *)(param_1 + 0x4000000) = ~param_2;
  return;
}



void RADIO_WaitForSetSync(uint *param_1,uint param_2)

{
  CORE_EnterCritical();
  do {
  } while ((*param_1 & param_2) != param_2);
  CORE_ExitCritical();
  return;
}



void RADIO_Delay(undefined4 param_1,undefined4 param_2)

{
  PHY_UTILS_DelayUs(param_2);
  return;
}



void RADIO_SetAndForgetWrite(void)

{
  undefined4 local_c;
  undefined4 uStack8;
  
  local_c = param_2;
  uStack8 = param_3;
  SYSTEM_ChipRevisionGet(&local_c);
  write_volatile_4(Peripherals::RAC.IFADCCTRL,0x5153e6c0);
  write_volatile_4(Peripherals::RAC.IFPGACTRL,0x87e6);
  write_volatile_4(Peripherals::RAC.LNAMIXCTRL1,0x880);
  write_volatile_4(Peripherals::RAC.VCOCTRL,0xf00277a);
  if ((local_c._1_1_ == '\x01') && ((local_c & 0xff) < 2)) {
    write_volatile_4(Peripherals::SYNTH.VCOGAIN,0x28);
  }
  write_volatile_4(Peripherals::SYNTH.CTRL,0xac3f);
  write_volatile_4(Peripherals::AGC.MANGAIN,0x1800000);
  write_volatile_4(Peripherals::RAC.LNAMIXCTRL,0);
  write_volatile_4(Peripherals::RAC.SYNTHREGCTRL,0x3636d80);
  write_volatile_4(Peripherals::SYNTH_CLR.VCDACCTRL,0x7f);
  write_volatile_4(Peripherals::SYNTH_SET.VCDACCTRL,0x23);
  return;
}



void RADIO_SeqInit(void *src,uint32_t len)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  CORE_irqState_t irqState;
  
  read_volatile(RAC->STATUS._0_1_);
  write_volatile_4(RAC->VECTADDR,0x21000000);
  write_volatile_4(RAC->SEQCTRL,1);
  irqState = CORE_EnterCritical();
  memcpy((void *)0x21000000,src,len << 2);
  CORE_ExitCritical(irqState);
  write_volatile_4(RAC->R6,0x21000fbc);
  uVar1 = (SEQ->REG0E4);
  uVar2 = (SEQ->REG0E8);
  uVar3 = (SEQ->DYNAMIC_CHPWR_TABLE);
  memset(&SEQ->REG064,0,0x9c);
  write_volatile_4(SEQ->REG0E4,uVar1);
  write_volatile_4(SEQ->REG0E8,uVar2);
  write_volatile_4(SEQ->DYNAMIC_CHPWR_TABLE,uVar3);
  return;
}



void RADIO_CLKEnable(void)

{
  undefined4 in_r2;
  undefined4 in_r3;
  
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
  BUS_RegMaskedSet(&MODEM->DCCOMP,3);
  write_volatile_4(RAC->SR3,0);
  BUS_RegMaskedSet(&RAC->SR3,1);
  SYNTH_KvnFreqCompensationEnable();
  SYNTH_DCDCRetimeEnable();
  BUS_RegMaskedSet(&RAC->CTRL,0x380);
  return;
}



void RADIO_Config(void *config)

{
  bool init;
  CORE_irqState_t irqState;
  uint uVar1;
  int iVar2;
  void *__dest;
  uint uVar3;
  void *__src;
  
  if (config != (void *)0x0) {
    for (iVar2 = (int)config + 8; uVar1 = *(uint *)(iVar2 + -8), uVar1 != 0xffffffff;
        iVar2 = iVar2 + 8) {
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
    }
  }
  init = PA_UpdateConfig();
  TIMING_SeqTimingInit(init);
  return;
}


void RADIO_RegisterIrqCallback(int param_1,undefined4 param_2)

{
  (&EFRDRV_irqClbk)[param_1] = param_2;
  return;
}



void FRC_PRI_IRQHandler(void)

{
                    // WARNING: Could not recover jumptable at 0x00010278. Too many branches
                    // WARNING: Treating indirect jump as call
  (*EFRDRV_irqClbk)();
  return;
}



void RAC_RSM_IRQHandler(void)

{
                    // WARNING: Could not recover jumptable at 0x00010284. Too many branches
                    // WARNING: Treating indirect jump as call
  (*DAT_00010780)();
  return;
}



void RAC_SEQ_IRQHandler(void)

{
                    // WARNING: Could not recover jumptable at 0x00010290. Too many branches
                    // WARNING: Treating indirect jump as call
  (*DAT_00010780)();
  return;
}



void AGC_IRQHandler(void)

{
                    // WARNING: Could not recover jumptable at 0x0001029c. Too many branches
                    // WARNING: Treating indirect jump as call
  (*DAT_00010790)();
  return;
}



void PROTIMER_IRQHandler(void)

{
                    // WARNING: Could not recover jumptable at 0x000102a8. Too many branches
                    // WARNING: Treating indirect jump as call
  (*DAT_00010788)();
  return;
}



void BUFC_IRQHandler(void)

{
                    // WARNING: Could not recover jumptable at 0x000102b4. Too many branches
                    // WARNING: Treating indirect jump as call
  (*DAT_00010778)();
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
  (*DAT_00010770)();
  return;
}



void MODEM_IRQHandler(void)

{
                    // WARNING: Could not recover jumptable at 0x000102e4. Too many branches
                    // WARNING: Treating indirect jump as call
  (*DAT_00010774)();
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



void RADIO_FrameControlDescrBufferIdSet(uint32_t fcd,uint32_t id)

{
  (&Peripherals::FRC_CLR.FCD0)[fcd] = 0x300;
  (&Peripherals::FRC_SET.FCD0)[fcd] = id << 8;
  return;
}



void RADIO_FrameControlDescrConfigSet
               (uint32_t fcd,uint8_t words,uint8_t skipwhitening,uint8_t skipcrc,uint8_t calccrc,
               uint8_t includecrc)

{
  (&Peripherals::FRC_CLR.FCD0)[fcd] = 31999;
  (&Peripherals::FRC_SET.FCD0)[fcd] =
       (uint)words | (uint)includecrc << 10 | (uint)calccrc << 0xb | (uint)skipcrc << 0xc |
       (uint)skipwhitening << 0xe;
  return;
}



void RADIO_FrameDescsConfig
               (uint8_t skipwhitening,uint8_t skipcrc,uint8_t calccrc,uint8_t includecrc)

{
  RADIO_FrameControlDescrConfigSet(0,0xff,skipwhitening,skipcrc,calccrc,includecrc);
  RADIO_FrameControlDescrConfigSet(2,0xff,skipwhitening,skipcrc,calccrc,includecrc);
  return;
}



void RADIO_FRCErrorHandle(void)

{
  BUFC_RxBufferReset();
  return;
}

/* void RADIO_FRCErrorHandle(void)

{
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  bufcRxStreaming._0_2_ = 0;
  write_volatile_4(BUFC->BUF1_CMD,1);
  write_volatile_4(BUFC->BUF2_CMD,1);
  write_volatile_4(FRC->IFC,0x10);
  CORE_ExitCritical(irqState);
  return;
} */

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
  uVar1 = (MODEM->TXBR);
  return (((uVar1 << 8) >> 0x18) * (uVar2 >> 3)) / (uVar1 & 0xffff);
}



uint32_t RADIO_ComputeRxBaudrate(void)

{
  uint uVar1;
  uint uVar2;
  uint32_t uVar3;
  int iVar4;
  uint uVar5;
  
  uVar2 = (MODEM->CF);
  uVar1 = (MODEM->RXBR);
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
  short sVar1;
  uint uVar2;
  CORE_irqState_t irqState;
  uint uVar3;
  uint uVar4;
  
  do {
    irqState = CORE_EnterCritical();
    uVar3 = (RAC->STATUS);
    uVar3 = uVar3 & 0xf000000;
    uVar2 = (AGC->RSSI);
    uVar4 = (RAC->STATUS);
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



undefined4 RADIO_SetAgcCcaParams(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = RADIO_ComputeRxBaudrate();
  for (uVar2 = 0; (uint)(1 << (uVar2 & 0xff)) < (uint)(param_1 * iVar1) / 1000000; uVar2 = uVar2 + 1
      ) {
    if (uVar2 == 0x10) {
      return 1;
    }
  }
  BUS_RegMaskedClear(&AGC->CTRL1,0xf00);
  BUS_RegMaskedSet(&AGC->CTRL1,uVar2 << 8);
  uVar2 = (AGC->CTRL1);
  if ((uVar2 & 0xff) == 0x80) {
    return 2;
  }
  BUS_RegMaskedClear(&AGC->CTRL1,0xff);
  BUS_RegMaskedSet(&AGC->CTRL1,param_2 & 0xff);
  return 0;
}




undefined4 RADIO_AGCCCAThresholdSet(byte param_1)

{
  write_volatile_4(Peripherals::AGC_CLR.CTRL1,0xff);
  write_volatile_4(Peripherals::AGC_SET.CTRL1,(uint)param_1);
  return 0;
}



RAIL_Status_t RADIO_CalcRssiPeriod(uint32_t us)

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
  
  BUS_RegMaskedSet(&AGC->CTRL1,0x8000);
  uVar4 = (MODEM->CF);
  uVar5 = (MODEM->CF);
  uVar6 = (MODEM->CF);
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
  if (uVar4 < us) {
    return RAIL_STATUS_INVALID_PARAMETER;
  }
  lVar2 = (uVar11 & 0xffffffff) * (ulonglong)us;
  uVar7 = (undefined4)lVar2;
  iVar8 = us * iVar8 + (int)((ulonglong)lVar2 >> 0x20);
  uVar5 = __aeabi_uldivmod(uVar7,iVar8,1000000000,0);
  iVar9 = 1;
  uVar4 = 0;
  do {
    uVar6 = uVar4 + 1;
    if (uVar5 <= (uint)(1 << (uVar6 & 0xff))) {
LAB_0000ddbc:
      BUS_RegMaskedClear(&AGC->CTRL1,0xf00);
      BUS_RegMaskedSet(&AGC->CTRL1,uVar4 << 8);
      uVar10 = __aeabi_uldivmod(uVar7,iVar8,10000000,0);
      uVar10 = __aeabi_uldivmod((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),iVar9,0);
      iVar8 = __aeabi_uldivmod((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),100,0);
      uVar4 = ((int)uVar10 + iVar8 * -100 & 0xffU) / 3;
      if (uVar4 < 0x20) {
        if (uVar4 == 0) {
          uVar4 = (AGC->CTRL1);
          write_volatile_4(AGC->CTRL1,uVar4 & 0xffe0ffff | 0x10000);
          uVar4 = (AGC->CTRL1);
          write_volatile_4(AGC->CTRL1,uVar4 & 0xfc1fffff | 0x200000);
          return RAIL_STATUS_NO_ERROR;
        }
      }
      else {
        uVar4 = 0x1f;
      }
      uVar5 = (AGC->CTRL1);
      write_volatile_4(AGC->CTRL1,uVar5 & 0x3ffffff | iVar8 << 0x1a);
      uVar5 = (AGC->CTRL1);
      write_volatile_4(AGC->CTRL1,uVar5 & 0xffe0ffff | uVar4 << 0x10);
      uVar4 = (AGC->CTRL1);
      write_volatile_4(AGC->CTRL1,uVar4 | 0x3e00000);
      return RAIL_STATUS_NO_ERROR;
    }
    if (uVar6 == 0x10) {
      uVar4 = 0xf;
      goto LAB_0000ddbc;
    }
    iVar9 = iVar9 << 1;
    uVar4 = uVar6;
  } while( true );
}


void RADIO_SetCRCInitVal(uint32_t value)

{
  write_volatile_4(Peripherals::CRC.INIT,value);
  write_volatile_4(Peripherals::CRC.CMD,1);
  return;
}


