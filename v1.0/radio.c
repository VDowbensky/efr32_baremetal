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



void RADIO_SetAndForgetWrite(undefined4 param_1,uint param_2,undefined4 param_3)

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



void RADIO_SeqInit(void *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  
  read_volatile(Peripherals::RAC.STATUS._0_1_);
  write_volatile_4(Peripherals::RAC.VECTADDR,0x21000000);
  write_volatile_4(Peripherals::RAC.SEQCTRL,1);
  uVar4 = CORE_EnterCritical();
  memcpy((void *)0x21000000,param_1,param_2 << 2);
  CORE_ExitCritical(uVar4);
  write_volatile_4(Peripherals::RAC.R6,0x21000fbc);
  uVar1 = read_volatile_4(Peripherals::SEQ.REG0E4);
  uVar2 = read_volatile_4(Peripherals::SEQ.REG0E8);
  uVar3 = read_volatile_4(Peripherals::SEQ.DYNAMIC_CHPWR_TABLE);
  memset(&Peripherals::SEQ.REG064,0,0x9c);
  write_volatile_4(Peripherals::SEQ.REG0E4,uVar1);
  write_volatile_4(Peripherals::SEQ.REG0E8,uVar2);
  write_volatile_4(Peripherals::SEQ.DYNAMIC_CHPWR_TABLE,uVar3);
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



void RADIO_Config(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  void *__dest;
  uint uVar3;
  void *__src;
  
  if (param_1 != 0) {
    param_1 = param_1 + 8;
    while( true ) {
      uVar2 = *(uint *)(param_1 + -8);
      if (uVar2 == 0xffffffff) break;
      uVar3 = (uVar2 << 8) >> 0x18;
      __dest = (void *)(uVar2 & 0xffff | *(uint *)(&regBases + ((uVar2 << 4) >> 0x1c) * 4));
      if (uVar3 < 2) {
        (*(code *)(&EFRDRV_actionFunc)[uVar2 >> 0x1c])(__dest,*(undefined4 *)(param_1 + -4));
      }
      else {
        __src = *(void **)(param_1 + -4);
        uVar1 = CORE_EnterCritical();
        memcpy(__dest,__src,uVar3 << 2);
        CORE_ExitCritical(uVar1);
      }
      param_1 = param_1 + 8;
    }
  }
  PA_UpdateConfig();
  TIMING_SeqTimingInit();
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



int RADIO_RxTrailDataLength(void)

{
  uint uVar1;
  int iVar2;
  
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



void RADIO_FrameControlDescrBufferIdSet(int param_1,int param_2)

{
  (&Peripherals::FRC_CLR.FCD0)[param_1] = 0x300;
  (&Peripherals::FRC_SET.FCD0)[param_1] = param_2 << 8;
  return;
}



void RADIO_FrameControlDescrConfigSet
               (int param_1,uint param_2,int param_3,int param_4,byte param_5,byte param_6)

{
  (&Peripherals::FRC_CLR.FCD0)[param_1] = 31999;
  (&Peripherals::FRC_SET.FCD0)[param_1] =
       param_2 | (uint)param_6 << 10 | (uint)param_5 << 0xb | param_4 << 0xc | param_3 << 0xe;
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



uint RADIO_ComputeTxBaudrate(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = CMU_ClockFreqGet(0x11);
  uVar1 = read_volatile_4(Peripherals::MODEM.TXBR);
  return (((uVar1 << 8) >> 0x18) * (uVar2 >> 3)) / (uVar1 & 0xffff);
}



uint RADIO_ComputeRxBaudrate(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  uVar2 = read_volatile_4(Peripherals::MODEM.CF);
  uVar1 = read_volatile_4(Peripherals::MODEM.RXBR);
  uVar6 = (uVar1 << 0x16) >> 0x1b;
  uVar4 = (uint)*(byte *)((int)&modemCfDec0Factors + (uVar2 & 7));
  iVar5 = (((uVar2 << 0xf) >> 0x12) * uVar4 + uVar4) * 2;
  iVar3 = CMU_ClockFreqGet(0x11);
  return (uVar6 * iVar3) /
         ((((uVar2 << 9) >> 0x1a) * iVar5 + iVar5) *
         (uVar6 * ((uVar1 << 0x13) >> 0x1d) + (uVar1 & 0x1f)));
}



uint RADIO_ComputeTxSymbolRate(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = RADIO_ComputeTxBaudrate();
  uVar1 = read_volatile_4(Peripherals::MODEM.CTRL0);
  if ((uVar1 & 0x30) == 0x20) {
    uVar2 = uVar2 / (((uVar1 << 0x10) >> 0x1b) + 1);
  }
  return uVar2;
}



int RADIO_ComputeTxBitRate(void)

{
  uint uVar1;
  int iVar2;
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
  iVar2 = RADIO_ComputeTxSymbolRate();
  return uVar3 * iVar2;
}



int RADIO_GetRSSI(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  short sVar4;
  
  do {
    CORE_EnterCritical();
    uVar2 = read_volatile_4(Peripherals::RAC.STATUS);
    uVar2 = uVar2 & 0xf000000;
    uVar1 = read_volatile_4(Peripherals::AGC.RSSI);
    uVar3 = read_volatile_4(Peripherals::RAC.STATUS);
    uVar3 = uVar3 & 0xf000000;
    sVar4 = (short)uVar1 >> 6;
    CORE_ExitCritical();
    if (sVar4 != -0x200) {
      if (uVar3 != 0x2000000 && uVar3 != 0x3000000 || uVar2 != 0x2000000 && uVar2 != 0x3000000) {
        sVar4 = -0x200;
      }
      break;
    }
  } while ((uVar3 == 0x2000000 || uVar3 == 0x3000000) && (uVar2 == 0x2000000 || uVar2 == 0x3000000))
  ;
  return (int)sVar4;
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
  write_volatile_4(Peripherals::AGC_CLR.CTRL1,0xf00);
  write_volatile_4(Peripherals::AGC_SET.CTRL1,uVar2 << 8);
  uVar2 = read_volatile_4(Peripherals::AGC.CTRL1);
  if ((uVar2 & 0xff) == 0x80) {
    return 2;
  }
  write_volatile_4(Peripherals::AGC_CLR.CTRL1,0xff);
  write_volatile_4(Peripherals::AGC_SET.CTRL1,param_2 & 0xff);
  return 0;
}



undefined4 RADIO_AGCCCAThresholdSet(byte param_1)

{
  write_volatile_4(Peripherals::AGC_CLR.CTRL1,0xff);
  write_volatile_4(Peripherals::AGC_SET.CTRL1,(uint)param_1);
  return 0;
}



undefined4 RADIO_CalcRssiPeriod(uint param_1)

{
  undefined uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  undefined8 uVar9;
  ulonglong uVar10;
  
  write_volatile_4(Peripherals::AGC_SET.CTRL1,0x8000);
  uVar3 = read_volatile_4(Peripherals::MODEM.CF);
  uVar4 = read_volatile_4(Peripherals::MODEM.CF);
  uVar5 = read_volatile_4(Peripherals::MODEM.CF);
  uVar1 = *(undefined *)((int)&modemCfDec0Factors + (uVar3 & 7));
  uVar3 = CMU_ClockFreqGet(0x11);
  uVar9 = __aeabi_uldivmod((int)((ulonglong)uVar3 * 1000),(int)((ulonglong)uVar3 * 1000 >> 0x20),
                           uVar1,0);
  uVar9 = __aeabi_uldivmod((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),((uVar4 << 0xf) >> 0x12) + 1,0
                          );
  uVar10 = __aeabi_uldivmod((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),((uVar5 << 9) >> 0x1a) + 1,0)
  ;
  iVar7 = (int)(uVar10 >> 0x20);
  uVar3 = __aeabi_uldivmod(0xdb000000,0x7558b,(int)uVar10,iVar7);
  if (uVar3 < param_1) {
    return 1;
  }
  lVar2 = (uVar10 & 0xffffffff) * (ulonglong)param_1;
  uVar6 = (undefined4)lVar2;
  iVar7 = param_1 * iVar7 + (int)((ulonglong)lVar2 >> 0x20);
  uVar4 = __aeabi_uldivmod(uVar6,iVar7,1000000000,0);
  iVar8 = 1;
  uVar3 = 0;
  do {
    uVar5 = uVar3 + 1;
    if (uVar4 <= (uint)(1 << (uVar5 & 0xff))) {
LAB_000106a4:
      write_volatile_4(Peripherals::AGC_CLR.CTRL1,0xf00);
      write_volatile_4(Peripherals::AGC_SET.CTRL1,uVar3 << 8);
      uVar9 = __aeabi_uldivmod(uVar6,iVar7,10000000,0);
      uVar9 = __aeabi_uldivmod((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),iVar8,0);
      iVar7 = __aeabi_uldivmod((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),100,0);
      uVar3 = ((int)uVar9 + iVar7 * -100 & 0xffU) / 3;
      if (uVar3 < 0x20) {
        if (uVar3 == 0) {
          uVar3 = read_volatile_4(Peripherals::AGC.CTRL1);
          write_volatile_4(Peripherals::AGC.CTRL1,uVar3 & 0xffe0ffff | 0x10000);
          uVar3 = read_volatile_4(Peripherals::AGC.CTRL1);
          write_volatile_4(Peripherals::AGC.CTRL1,uVar3 & 0xfc1fffff | 0x200000);
          return 0;
        }
      }
      else {
        uVar3 = 0x1f;
      }
      uVar4 = read_volatile_4(Peripherals::AGC.CTRL1);
      write_volatile_4(Peripherals::AGC.CTRL1,uVar4 & 0x3ffffff | iVar7 << 0x1a);
      uVar4 = read_volatile_4(Peripherals::AGC.CTRL1);
      write_volatile_4(Peripherals::AGC.CTRL1,uVar4 & 0xffe0ffff | uVar3 << 0x10);
      uVar3 = read_volatile_4(Peripherals::AGC.CTRL1);
      write_volatile_4(Peripherals::AGC.CTRL1,uVar3 | 0x3e00000);
      return 0;
    }
    if (uVar5 == 0x10) {
      uVar3 = 0xf;
      goto LAB_000106a4;
    }
    iVar8 = iVar8 << 1;
    uVar3 = uVar5;
  } while( true );
}



void RADIO_SetCRCInitVal(uint param_1)

{
  write_volatile_4(Peripherals::CRC.INIT,param_1);
  write_volatile_4(Peripherals::CRC.CMD,1);
  return;
}


