#include "radio.h"



void RADIO_SetAndForgetWrite(undefined4 param_1,uint32_t param_2,undefined4 param_3)

{
  undefined4 local_c;
  undefined4 uStack8;
  
  local_c = param_2;
  uStack8 = param_3;
  SYSTEM_ChipRevisionGet(&local_c);
  write_volatile_4(RAC->IFADCCTRL,0x5153e6c0);
  write_volatile_4(RAC->IFPGACTRL,0x87e6);
  write_volatile_4(RAC->LNAMIXCTRL1,0x880);
  write_volatile_4(RAC->VCOCTRL,0xf00277a);
  if ((local_c._1_1_ == '\x01') && ((local_c & 0xff) < 2)) {
    write_volatile_4(SYNTH->VCOGAIN,0x28);
  }
  write_volatile_4(SYNTH->CTRL,0xac3f);
  write_volatile_4(AGC->MANGAIN,0x1800000);
  write_volatile_4(RAC->LNAMIXCTRL,0);
  write_volatile_4(RAC->SYNTHREGCTRL,0x3636d80);
  BUS_RegMaskedClear(&SYNTH->VCDACCTRL,0x7f);
  BUS_RegMaskedSet(&SYNTH->VCDACCTRL,0x23);
  return;
}



void RADIO_RewriteCcTableData(void)

{
  undefined4 *puVar1;
  undefined *puVar2;
  
  puVar2 = (undefined *)0xfe08008;
  do {
    puVar1 = *(undefined4 **)(puVar2 + -8);
    if (puVar1 == NULL) {
      return;
    }
    if ((FRC *)((uint32_t)puVar1 & 0xffff0000) == &Peripherals::FRC) {
      *puVar1 = *(undefined4 *)(puVar2 + -4);
    }
    puVar2 = puVar2 + 8;
  } while (puVar2 != &UNK_0fe081b8);
  return;
}



void RADIO_SeqInit(void *param_1,int param_2)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  
  BUS_RegMaskedSet(&RAC->CTRL,1);
  do {
    uVar1 = (RAC->STATUS);
  } while ((uVar1 << 4) >> 0x1c != 0);
  write_volatile_4(RAC->VECTADDR,0x21000000);
  write_volatile_4(RAC->SEQCTRL,1);
  memcpy((void *)0x21000000,param_1,param_2 << 2);
  write_volatile_4(RAC->R6,0x21000fb8);
  uVar1 = (SEQ->REG0E0);
  uVar2 = (SEQ->REG0E4);
  uVar3 = (SEQ->REG0E8);
  memset(&SEQ->REG07C,0,0x84);
  write_volatile_4(SEQ->REG0E0,uVar1);
  write_volatile_4(SEQ->REG0E4,uVar2);
  write_volatile_4(SEQ->REG0E8,uVar3);
  return;
}



void RADIO_CLKEnable(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  RADIOCMU_ClockEnable(0x63400,1);
  RADIOCMU_ClockEnable(0x60400,1);
  RADIOCMU_ClockEnable(0x64400,1);
  RADIOCMU_ClockEnable(0x67400,1);
  RADIOCMU_ClockEnable(0x66400,1);
  RADIOCMU_ClockEnable(0x65400,1);
  RADIOCMU_ClockEnable(0x62400,1);
  RADIOCMU_ClockEnable(0x68400,1,param_3,param_4);
  return;
}



void RADIO_Init(void)

{
  RADIO_CLKEnable();
  RADIO_SetAndForgetWrite();
  BUS_RegMaskedSet(&MODEM->DCCOMP,3);
  write_volatile_4(RAC->SR3,0x80000);
  BUS_RegMaskedSet(&RAC->SR3,1);
  SYNTH_KvnFreqCompensationEnable();
  BUS_RegMaskedSet(&RAC->CTRL,0x380);
  return;
}



void RADIO_Config(undefined4 param_1,uint32_t *param_2)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t *puVar4;
  uint32_t *puVar5;
  
switchD_00010218_caseD_8:
  while( true ) {
    if ((param_2 == NULL) || (uVar2 = *param_2, uVar2 == 0xffffffff)) {
      PA_UpdateConfig(param_1);
      TIMING_SeqTimingInit();
      return;
    }
    uVar1 = (uVar2 << 8) >> 0x18;
    puVar4 = (uint32_t *)(uVar2 & 0xffff | *(uint32_t *)(&regBases + ((uVar2 << 4) >> 0x1c) * 4));
    uVar3 = uVar1;
    puVar5 = param_2;
    if (uVar1 < 2) break;
    do {
      uVar3 = uVar3 - 1;
      *(uint32_t *)(((int)puVar4 - (int)param_2) + (int)puVar5) = puVar5[1];
      puVar5 = puVar5 + 1;
    } while (uVar3 != 0);
    param_2 = param_2 + uVar1 + 1;
  }
  puVar5 = param_2 + 2;
  uVar3 = param_2[1];
  param_2 = puVar5;
  switch(uVar2 >> 0x1c) {
  case 0:
    break;
  case 1:
    uVar3 = ~uVar3;
    puVar4 = puVar4 + 0x1000000;
    break;
  case 2:
    uVar3 = uVar3 ^ *puVar4;
    break;
  case 3:
    puVar4 = puVar4 + 0x1800000;
    break;
  case 4:
    PROTIMER_DelayUs();
    goto switchD_00010218_caseD_8;
  case 5:
    puVar4 = puVar4 + 0x1800000;
    goto LAB_00010252;
  case 6:
    puVar4 = puVar4 + 0x1000000;
LAB_00010252:
    *puVar4 = 1 << (uVar3 & 0xff);
    goto switchD_00010218_caseD_8;
  case 7:
    do {
    } while ((*puVar4 & uVar3) != uVar3);
  default:
    goto switchD_00010218_caseD_8;
  }
  *puVar4 = uVar3;
  goto switchD_00010218_caseD_8;
}



bool RADIO_IsRxOnForRssi(void)

{
  uint32_t uVar1;
  
  uVar1 = (RAC->STATUS);
  return ((uVar1 << 4) >> 0x1c) - 2 < 2;
}



int RADIO_RxTrailDataLength(void)

{
  uint32_t uVar1;
  int iVar2;
  
  uVar1 = (FRC->TRAILRXDATA);
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



void RADIO_FrameControlDescrBufferIdSet(int param_1,int param_2)

{
  (&Peripherals::FRC_CLR.FCD0)[param_1] = 0x300;
  (&Peripherals::FRC_SET.FCD0)[param_1] = param_2 << 8;
  return;
}



void RADIO_FrameControlDescrConfigSet
               (int param_1,uint32_t param_2,int param_3,int param_4,uint8_t param_5,uint8_t param_6)

{
  (&Peripherals::FRC_CLR.FCD0)[param_1] = 31999;
  (&Peripherals::FRC_SET.FCD0)[param_1] =
       param_2 | (uint32_t)param_6 << 10 | (uint32_t)param_5 << 0xb | param_4 << 0xc | param_3 << 0xe;
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
  BUS_RegMaskedSet(&RAC->SR3,0x100);
  return;
}



void RADIO_DemodResetOnRxsearchEntryDisable(void)

{
  BUS_RegMaskedClear(&RAC->SR3,0x100);
  return;
}



void RADIO_DccalEnable(void)

{
  BUS_RegMaskedSet(&RAC->SR3,1);
  return;
}



void RADIO_DccalDisable(void)

{
  BUS_RegMaskedClear(&RAC->SR3,1);
  return;
}



void RADIO_TxHoldOffEnable(int param_1)

{
  RAC_SET *pRVar1;
  
  if (param_1 == 0) {
    pRVar1 = (RAC_SET *)&Peripherals::RAC_CLR;
  }
  else {
    pRVar1 = &Peripherals::RAC_SET;
  }
  ((RAC_CLR *)pRVar1)->SR3 = 0x20000000;
  return;
}



bool RADIO_IsTxHoldOffEnabled(void)

{
  uint32_t uVar1;
  
  uVar1 = (RAC->SR3);
  return (uVar1 & 0x1d) != 0;
}



void RADIO_VcoFineCalEnable(void)

{
  BUS_RegMaskedSet(&RAC->SR3,0x80);
  return;
}



void RADIO_VcoFineCalDisable(void)

{
  BUS_RegMaskedClear(&RAC->SR3,0x80);
  return;
}



uint32_t RADIO_ComputeTxBaudrate(void)

{
  uint32_t uVar1;
  uint32_t uVar2;
  
  uVar2 = CMU_ClockFreqGet(0x11);
  uVar1 = (MODEM->TXBR);
  if ((uVar1 & 0xffff) != 0) {
    return (((uVar1 << 8) >> 0x18) * (uVar2 >> 3)) / (uVar1 & 0xffff);
  }
  return 0;
}



uint32_t RADIO_ComputeRxBaudrate(void)

{
  uint32_t uVar1;
  int iVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  
  uVar1 = (MODEM->CF);
  uVar3 = (MODEM->RXBR);
  iVar2 = ((uVar1 << 9) >> 0x1a) + 1;
  uVar4 = (uVar3 << 0x16) >> 0x1b;
  uVar3 = (((uVar1 << 0xf) >> 0x12) * iVar2 + iVar2) * 2 *
          (uVar4 * ((uVar3 << 0x13) >> 0x1d) + (uVar3 & 0x1f)) *
          (uint32_t)*(uint8_t *)((int)&modemCfDec0Factors + (uVar1 & 7));
  if (uVar3 != 0) {
    iVar2 = CMU_ClockFreqGet(0x11);
    return (uVar4 * iVar2) / uVar3;
  }
  return 0;
}



uint32_t RADIO_ComputeTxSymbolRate(void)

{
  uint32_t uVar1;
  uint32_t uVar2;
  
  uVar2 = RADIO_ComputeTxBaudrate();
  uVar1 = (MODEM->CTRL0);
  if ((uVar1 & 0x30) == 0x10) {
    return uVar2 >> 1;
  }
  if ((uVar1 & 0x30) != 0x20) {
    return uVar2;
  }
  return uVar2 / (((uVar1 << 0x10) >> 0x1b) + 1);
}



int RADIO_ComputeTxBitRate(void)

{
  uint32_t uVar1;
  int iVar2;
  uint32_t uVar3;
  
  uVar1 = (MODEM->CTRL0);
  if ((uVar1 & 0x30) == 0x20) {
    uVar3 = (uVar1 << 0xd) >> 0x1d;
    if (uVar3 != 0) {
      uVar3 = ((uVar1 << 0x10) >> 0x1b) / uVar3;
    }
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
  iVar2 = RADIO_ComputeTxSymbolRate();
  return uVar3 * iVar2;
}



int RADIO_GetRssi(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint32_t uVar3;
  int iVar5;
  int16_t sVar6;
  uint32_t uVar4;
  
  while( true ) {
    uVar1 = CORE_EnterCritical();
    iVar2 = RADIO_IsRxOnForRssi();
    uVar3 = (AGC->RSSI);
    uVar3 = uVar3 << 0x10;
    uVar4 = uVar3 >> 0x16;
    if ((int)uVar3 < 0) {
      uVar4 = ~(uVar3 & 0xffc00000);
    }
    if ((int)uVar3 < 0) {
      uVar4 = ~(uVar4 >> 0x16);
    }
    sVar6 = (int16_t)(uVar4 & 0xffff);
    iVar5 = RADIO_IsRxOnForRssi();
    if (iVar5 == 0) {
      iVar2 = 0;
    }
    CORE_ExitCritical(uVar1);
    if ((uVar4 & 0xffff) != 0xfe00) break;
    if ((iVar2 == 0) || (param_1 == 0)) goto LAB_00010514;
  }
  if (iVar2 == 0) {
    sVar6 = -0x200;
  }
LAB_00010514:
  return (int)sVar6;
}



undefined4 RADIO_SetAgcCcaParams(int param_1,uint32_t param_2)

{
  int iVar1;
  uint32_t uVar2;
  
  iVar1 = RADIO_ComputeRxBaudrate();
  for (uVar2 = 0; (uint32_t)(1 << (uVar2 & 0xff)) < (uint32_t)(param_1 * iVar1) / 1000000; uVar2 = uVar2 + 1
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



undefined4 RADIO_AGCCCAThresholdSet(uint8_t param_1)

{
  BUS_RegMaskedClear(&AGC->CTRL1,0xff);
  BUS_RegMaskedSet(&AGC->CTRL1,(uint32_t)param_1);
  return 0;
}



void RADIO_ComputeAgcSampleRate(void)

{
  undefined uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  undefined8 uVar5;
  
  uVar2 = (MODEM->CF);
  uVar3 = (MODEM->CF);
  uVar1 = *(undefined *)((int)&modemCfDec0Factors + (uVar2 & 7));
  uVar2 = (MODEM->CF);
  uVar4 = CMU_ClockFreqGet(0x11);
  uVar5 = __aeabi_uldivmod((int)((ulonglong)uVar4 * 1000),(int)((ulonglong)uVar4 * 1000 >> 0x20),
                           uVar1,0);
  uVar5 = __aeabi_uldivmod((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),((uVar3 << 0xf) >> 0x12) + 1,0
                          );
  __aeabi_uldivmod((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),((uVar2 << 9) >> 0x1a) + 1,0);
  return;
}



undefined4 RADIO_SetRssiPeriod(uint32_t param_1)

{
  longlong lVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  undefined4 uVar5;
  int iVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  
  uVar7 = RADIO_ComputeAgcSampleRate();
  if (uVar7 == 0) {
    RAILInt_Assert(0,0x2b);
    uVar7 = 1;
  }
  iVar6 = (int)(uVar7 >> 0x20);
  uVar2 = __aeabi_uldivmod(0xdb000000,0x7558b,(int)uVar7,iVar6);
  if (uVar2 < param_1) {
    return 1;
  }
  lVar1 = (uVar7 & 0xffffffff) * (ulonglong)param_1;
  uVar5 = (undefined4)lVar1;
  iVar6 = param_1 * iVar6 + (int)((ulonglong)lVar1 >> 0x20);
  uVar3 = __aeabi_uldivmod(uVar5,iVar6,1000000000,0);
  uVar2 = 1;
  do {
    uVar4 = uVar2 + 1;
    if (uVar3 <= (uint32_t)(1 << (uVar4 & 0xff))) goto LAB_00010642;
    uVar2 = uVar4;
  } while (uVar4 != 0x10);
  uVar2 = 0xf;
LAB_00010642:
  BUS_RegMaskedSet(&AGC->CTRL1,0x8000);
  BUS_RegMaskedClear(&AGC->CTRL1,0xf00);
  BUS_RegMaskedSet(&AGC->CTRL1,uVar2 << 8);
  __aeabi_uldivmod(uVar5,iVar6,10000000,0);
  uVar8 = __aeabi_uldivmod();
  iVar6 = __aeabi_uldivmod((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),100,0);
  uVar2 = ((int)uVar8 + iVar6 * -100 & 0xffU) / 3;
  if (uVar2 < 0x20) {
    if (uVar2 == 0) {
      uVar2 = (AGC->CTRL1);
      write_volatile_4(AGC->CTRL1,uVar2 & 0xffe0ffff | 0x10000);
      uVar2 = (AGC->CTRL1);
      write_volatile_4(AGC->CTRL1,uVar2 & 0xfc1fffff | 0x200000);
      return 0;
    }
  }
  else {
    uVar2 = 0x1f;
  }
  uVar3 = (AGC->CTRL1);
  write_volatile_4(AGC->CTRL1,uVar3 & 0x3ffffff | iVar6 << 0x1a);
  uVar3 = (AGC->CTRL1);
  write_volatile_4(AGC->CTRL1,uVar3 & 0xffe0ffff | uVar2 << 0x10);
  uVar2 = (AGC->CTRL1);
  write_volatile_4(AGC->CTRL1,uVar2 | 0x3e00000);
  return 0;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined4 RADIO_GetRssiPeriod(void)

{
  uint32_t uVar1;
  undefined4 uVar2;
  uint32_t uVar3;
  int iVar4;
  uint32_t uVar5;
  longlong lVar6;
  
  uVar3 = (AGC->CTRL1);
  iVar4 = 1 << ((uVar3 << 0x14) >> 0x1c);
  if (_DAT_430e033c != 0) {
    lVar6 = RADIO_ComputeAgcSampleRate();
    uVar1 = _DAT_430e0368;
    uVar3 = _DAT_430e0340;
    uVar5 = _DAT_430e0354 & 0xff;
    if (uVar5 == 0) {
      RAILInt_Assert(0,0x2b);
      uVar5 = 1;
    }
    if (lVar6 == 0) {
      RAILInt_Assert(0,0x2b);
      lVar6 = 1;
    }
    uVar2 = __aeabi_uldivmod(iVar4 * ((uVar1 & 0xff) * 1000000000 +
                                     ((uVar3 & 0xff) * 1000000000) / uVar5),0,(int)lVar6,
                             (int)((ulonglong)lVar6 >> 0x20));
    return uVar2;
  }
  uVar3 = RADIO_ComputeRxBaudrate();
  return (int)((ulonglong)(uint32_t)(iVar4 * 100000) / ((ulonglong)uVar3 / 10));
}



void RADIO_SetCRCInitVal(uint32_t param_1)

{
  write_volatile_4(Peripherals::CRC.INIT,param_1);
  write_volatile_4(Peripherals::CRC.CMD,1);
  return;
}



void RADIO_RACClearRxOverflow(void)

{
  uint32_t uVar1;
  
  do {
    uVar1 = (RAC->STATUS);
    if ((uVar1 & 0xf000000) != 0x6000000) break;
    uVar1 = (RAC->SEQSTATUS);
  } while (-1 < (int)(uVar1 << 0x1b));
  write_volatile_4(RAC->CMD,0x40);
  return;
}


