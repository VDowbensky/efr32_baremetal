#include "radio.h"



void RADIO_WriteSync(uint32_t *addr,uint32_t data)

{
  *addr = data;
}



void RADIO_SetBitSync(uint32_t addr,uint32_t bit)

{
  *(uint32_t *)(addr + 0x6000000) = 1 << (bit & 0xff);
}



void RADIO_ClrBitSync(uint32_t addr,uint32_t bit)

{
  *(uint32_t *)(addr + 0x4000000) = 1 << (bit & 0xff);
}



void RADIO_OrSync(uint32_t addr,uint32_t mask)

{
  *(uint32_t *)(addr + 0x6000000) = mask;
}



void RADIO_XorSync(uint32_t *addr,uint32_t mask)

{
  *addr = mask ^ *addr;
}



void RADIO_AndSync(uint32_t addr,uint32_t mask)

{
  *(uint32_t *)(addr + 0x4000000) = ~mask;
}



void RADIO_WaitForSetSync(uint32_t *addr,uint32_t mask)

{
  CORE_irqState_t irqState;
  irqState = CORE_EnterCritical();
  while ((*addr & mask) != mask);
  CORE_ExitCritical(irqState);
}



void RADIO_Delay(uint32_t us)

{
  PHY_UTILS_DelayUs(us);
}


void RADIO_SetAndForgetWrite(void)

{
  SYSTEM_ChipRevision_TypeDef revision;

  SYSTEM_ChipRevisionGet(&revision);
  RAC->IFADCCTRL = 0x5153e6c0;
  RAC->IFPGACTRL = 0x87e6;
  RAC->LNAMIXCTRL1 = 0x880;
  RAC->VCOCTRL = 0xf00277a;
  if((revision.major == 0x01) && (revision.minor < 2)) SYNTH->VCOGAIN = 0x28;	  
  SYNTH->CTRL = 0xac3f;
  AGC->MANGAIN = 0x1800000;
  RAC->LNAMIXCTRL = 0;
  RAC->SYNTHREGCTRL = 0x3636d80;
  BUS_RegMaskedClear(&SYNTH->VCDACCTRL,0x7f);
  BUS_RegMaskedSet(&SYNTH->VCDACCTRL,0x23);
}



void RADIO_SeqInit(void *src,uint32_t len)

{
  uint32_t t1, t2, t3;
  CORE_irqState_t irqState;
  
  //read_volatile(RAC->STATUS._0_1_);
  RAC->VECTADDR = 0x21000000;
  RAC->SEQCTRL = RAC_SEQCTRL_COMPACT_Msk; //1;
  irqState = CORE_EnterCritical();
  memcpy((void *)0x21000000,src,len << 2);
  CORE_ExitCritical(irqState);
  RAC->R6 = 0x21000fbc;
  t1 = SEQ->REG0E4;
  t2 = SEQ->REG0E8;
  t3 = SEQ->DYNAMIC_CHPWR_TABLE; //SEQ->REG0EC;
  memset(&SEQ->REG064,0,0x9c);
  SEQ->REG0E4 = t1;
  SEQ->REG0E8 = t2;
  SEQ->DYNAMIC_CHPWR_TABLE = t3; //SEQ->REG0EC;
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
}



void RADIO_Init(void)

{
  RADIO_CLKEnable();
  BUFC_Init();
  RADIO_SetAndForgetWrite();
  BUS_RegMaskedSet(&MODEM->DCCOMP,MODEM_DCCOMP_DCCOMPEN_Msk | MODEM_DCCOMP_DCESTIEN_Msk); //3);
  RAC->SR3 = 0;
  BUS_RegMaskedSet(&RAC->SR3,1);
  SYNTH_KvnFreqCompensationEnable();
  SYNTH_DCDCRetimeEnable();
  BUS_RegMaskedSet(&RAC->CTRL,RAC_CTRL_LNAENPOL_Msk | RAC_CTRL_PAENPOL_Msk | RAC_CTRL_ACTIVEPOL_Msk); //0x380);
}



void RADIO_Config(void *config)

{
  CORE_irqState_t irqState;
  uint uVar1;
  int iVar2;
  void *__dest;
  uint uVar3;
  void *__src;
  
  if (config != NULL) 
  {
    for (iVar2 = (int)config + 8; uVar1 = *(uint *)(iVar2 + -8), uVar1 != 0xffffffff; iVar2 = iVar2 + 8) 
	{
      uVar3 = (uVar1 << 8) >> 0x18;
      __dest = (void *)(uVar1 & 0xffff | (uint)(&regBases)[(uVar1 << 4) >> 0x1c]);
      if (uVar3 < 2) (**(code **)(&EFRDRV_actionFunc + (uVar1 >> 0x1c) * 4))(__dest,*(undefined4 *)(iVar2 + -4));
      else 
	  {
        __src = *(void **)(iVar2 + -4);
        irqState = CORE_EnterCritical();
        memcpy(__dest,__src,uVar3 << 2);
        CORE_ExitCritical(irqState);
      }
    }
  }
  PA_UpdateConfig();
  TIMING_SeqTimingInit();
}


void RADIO_RegisterIrqCallback(uint32_t irqN,uint32_t address)

{
  (&EFRDRV_irqClbk)[irqN] = address;
}



void FRC_PRI_IRQHandler(void)

{
                    // WARNING: Could not recover jumptable at 0x00010278. Too many branches
                    // WARNING: Treating indirect jump as call
  (*EFRDRV_irqClbk)();
}



void RAC_RSM_IRQHandler(void)

{
                    // WARNING: Could not recover jumptable at 0x00010284. Too many branches
                    // WARNING: Treating indirect jump as call
  (*DAT_00010780)();
}



void RAC_SEQ_IRQHandler(void)

{
                    // WARNING: Could not recover jumptable at 0x00010290. Too many branches
                    // WARNING: Treating indirect jump as call
  (*DAT_00010780)();
}



void AGC_IRQHandler(void)

{
                    // WARNING: Could not recover jumptable at 0x0001029c. Too many branches
                    // WARNING: Treating indirect jump as call
  (*DAT_00010790)();
}



void PROTIMER_IRQHandler(void)

{
                    // WARNING: Could not recover jumptable at 0x000102a8. Too many branches
                    // WARNING: Treating indirect jump as call
  (*DAT_00010788)();
}



void BUFC_IRQHandler(void)

{
                    // WARNING: Could not recover jumptable at 0x000102b4. Too many branches
                    // WARNING: Treating indirect jump as call
  (*DAT_00010778)();
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FRC_IRQHandler(void)

{
  if (_DAT_e000e200 << 0x18 < 0) 
  {
    BUFC_IRQHandler();
  }
                    // WARNING: Could not recover jumptable at 0x000102d4. Too many branches
                    // WARNING: Treating indirect jump as call
  (*DAT_00010770)();
}



void MODEM_IRQHandler(void)

{
                    // WARNING: Could not recover jumptable at 0x000102e4. Too many branches
                    // WARNING: Treating indirect jump as call
  (*DAT_00010774)();
}



bool RADIO_IsRxActive(void)

{
  uint32_t state;
  
  state = (RAC->STATUS << 4) >> 0x1c;
  if ((state != 3) && (state != 7)) return (state == 4);
  return true;
}



uint32_t RADIO_RxTrailDataLength(void)

{
  uint32_t len;
  
  if ((FRC->TRAILRXDATA & 0x20) == 0) len = 0;
  else len = 4;
  if ((int)(FRC->TRAILRXDATA << 0x1b) < 0) len = len + 2;
  if ((int)(FRC->TRAILRXDATA << 0x1c) < 0) len = len + 2;
  if ((int)(FRC->TRAILRXDATA << 0x1d) < 0) len = len + 2;
  if ((int)(FRC->TRAILRXDATA << 0x1e) < 0) len = len + 1;
  if ((int)(FRC->TRAILRXDATA << 0x1f) < 0) len = len + 1;
  return len;
}



void RADIO_FrameControlDescrBufferIdSet(uint32_t fcd,uint32_t id)

{
  //(&Peripherals::FRC_CLR.FCD0)[fcd] = 0x300;
  //(&Peripherals::FRC_SET.FCD0)[fcd] = id << 8;
  switch(fcd)
  {
	case 0:
	default:
	BUS_RegMaskedClear(&FRC->FCD0) = 0x300;
	BUS_RegMaskedSet(&FRC->FCD0,id << 8);
	break;
	
	case 1:
	BUS_RegMaskedClear(&FRC->FCD1) = 0x300;
	BUS_RegMaskedSet(&FRC->FCD1,id << 8);
	break;
	
	case 2:
	BUS_RegMaskedClear(&FRC->FCD2) = 0x300;
	BUS_RegMaskedSet(&FRC->FCD2,id << 8);
	break;
	
	case 3:
	BUS_RegMaskedClear(&FRC->FCD3) = 0x300;
	BUS_RegMaskedSet(&FRC->FCD3,id << 8);
	break;
  }
}



void RADIO_FrameControlDescrConfigSet(uint32_t fcd,uint8_t words,uint8_t skipwhitening,uint8_t skipcrc,uint8_t calccrc,uint8_t includecrc)

{
  //(&Peripherals::FRC_CLR.FCD0)[fcd] = 31999;
  //(&Peripherals::FRC_SET.FCD0)[fcd] = (uint32_t)words | (uint32_t)includecrc << 10 | (uint32_t)calccrc << 0xb | (uint32_t)skipcrc << 0xc | (uint32_t)skipwhitening << 0xe;
  switch(fcd)
  {
	case 0:
	default:
	BUS_RegMaskedClear(&FRC->FCD0,31999);
	BUS_RegMaskedSet(&FRC->FCD0,(uint32_t)words | (uint32_t)includecrc << 10 | (uint32_t)calccrc << 0xb | (uint32_t)skipcrc << 0xc | (uint32_t)skipwhitening << 0xe);
	
	case 1:
	BUS_RegMaskedClear(&FRC->FCD1,31999);
	BUS_RegMaskedSet(&FRC->FCD1,(uint32_t)words | (uint32_t)includecrc << 10 | (uint32_t)calccrc << 0xb | (uint32_t)skipcrc << 0xc | (uint32_t)skipwhitening << 0xe);

	case 2:
	BUS_RegMaskedClear(&FRC->FCD2,31999);
	BUS_RegMaskedSet(&FRC->FCD2,(uint32_t)words | (uint32_t)includecrc << 10 | (uint32_t)calccrc << 0xb | (uint32_t)skipcrc << 0xc | (uint32_t)skipwhitening << 0xe);

	case 3:
	BUS_RegMaskedClear(&FRC->FCD2,31999);
	BUS_RegMaskedSet(&FRC->FCD2,(uint32_t)words | (uint32_t)includecrc << 10 | (uint32_t)calccrc << 0xb | (uint32_t)skipcrc << 0xc | (uint32_t)skipwhitening << 0xe);	
  }
}



void RADIO_FrameDescsConfig(uint8_t skipwhitening,uint8_t skipcrc,uint8_t calccrc,uint8_t includecrc)

{
  RADIO_FrameControlDescrConfigSet(0,0xff,skipwhitening,skipcrc,calccrc,includecrc);
  RADIO_FrameControlDescrConfigSet(2,0xff,skipwhitening,skipcrc,calccrc,includecrc);
}



void RADIO_FRCErrorHandle(void)

{
  BUFC_RxBufferReset();
}

/* void RADIO_FRCErrorHandle(void)

{
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  bufcRxStreaming._0_2_ = 0;
  BUFC->BUF1_CMD = 1;
  BUFC->BUF2_CMD = 1;
  FRC->IFC = 0x10;
  CORE_ExitCritical(irqState);
  return;
} */

void RADIO_DemodResetOnRxsearchEntryEnable(void)

{
  BUS_RegMaskedSet(&RAC->SR3,0x100);
}



void RADIO_DemodResetOnRxsearchEntryDisable(void)

{
  BUS_RegMaskedClear(&RAC->SR3,0x100);
}



void RADIO_DccalEnable(void)

{
  BUS_RegMaskedSet(&RAC->SR3,1);
}



void RADIO_DccalDisable(void)

{
  BUS_RegMaskedClear(&RAC->SR3,1);
}



void RADIO_TxHoldOffEnable(void)

{
  BUS_RegMaskedSet(&RAC->SR3,0x20000000);
}



void RADIO_TxHoldOffDisable(void)

{
  BUS_RegMaskedClear(&RAC->SR3,0x20000000);
}



void RADIO_VcoFineCalEnable(void)

{
  BUS_RegMaskedSet(&RAC->SR3,0x20);
}



void RADIO_VcoFineCalDisable(void)

{
  BUS_RegMaskedClear(&RAC->SR3,0x20);
}



uint32_t RADIO_ComputeTxBaudrate(void)

{
  return (((MODEM->TXBR << 8) >> 0x18) * (CMU_ClockFreqGet(cmuClock_HF) >> 3)) / (MODEM->TXBR & 0xffff);
}



uint32_t RADIO_ComputeRxBaudrate(void)

{
  int iVar4;
  uint uVar5;
  
  uVar5 = (MODEM->RXBR << 0x16) >> 0x1b;
  iVar4 = (((MODEM->CF << 0xf) >> 0x12) * (uint)(byte)(&modemCfDec0Factors)[MODEM->CF & 7] + (uint)(byte)(&modemCfDec0Factors)[MODEM->CF & 7]) * 2;
  return (uVar5 * CMU_ClockFreqGet(cmuClock_HF)) / ((((MODEM->CF << 9) >> 0x1a) * iVar4 + iVar4) * (uVar5 * ((uVar1 << 0x13) >> 0x1d) + (uVar1 & 0x1f)));
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
  uint32_t k;
  
  if ((MODEM->CTRL0 & 0x30) == 0x20) 
  {
    k = ((MODEM->CTRL0 << 0x10) >> 0x1b) / ((MODEM->CTRL0 << 0xd) >> 0x1d);
    if ((MODEM->CTRL0 & 0x180000) != 0) k = k << 1;
    k = k >> 1;
    if (2 < k) k = 4;
  }
  else 
  {
    if (((MODEM->CTRL0 & 0x1c0) == 0x40) || ((MODEM->CTRL0 & 0x1c0) == 0x100)) k = 2;
    else k = 1;
  }
  return k * RADIO_ComputeTxSymbolRate();
}


int16_t RADIO_GetRSSI(void)

{
  int16_t rssi;
  uint uVar2;
  CORE_irqState_t irqState;
  uint32_t state_before;
  uint32_t state_after;
  
  do 
  {
    irqState = CORE_EnterCritical();
    state_before = RAC->STATUS & 0xf000000;
	rssi = (int16_t)AGC->RSSI >> 6;
    state_after = RAC->STATUS & 0xf000000;
    CORE_ExitCritical(irqState);
    if (rssi != -0x200) 
	{
      if ((state_after == 0x2000000 || state_after == 0x3000000) && (state_before == 0x2000000 || state_before == 0x3000000)) return rssi;
      return -0x200;
    }
  } while ((state_after == 0x2000000 || state_after == 0x3000000) && (state_before == 0x2000000 || state_before == 0x3000000));
  return -0x200;
}



undefined4 RADIO_SetAgcCcaParams(int param_1,uint param_2)

{
  uint32_t uVar2;
  
  for (uVar2 = 0; (uint)(1 << (uVar2 & 0xff)) < (uint)(param_1 * RADIO_ComputeRxBaudrate()) / 1000000; uVar2 = uVar2 + 1) 
  {
    if (uVar2 == 0x10) return 1;
  }
  BUS_RegMaskedClear(&AGC->CTRL1,0xf00);
  BUS_RegMaskedSet(&AGC->CTRL1,uVar2 << 8);
  if ((AGC->CTRL1 & 0xff) == 0x80) return 2;
  BUS_RegMaskedClear(&AGC->CTRL1,0xff);
  BUS_RegMaskedSet(&AGC->CTRL1,param_2 & 0xff);
  return 0;
}




RAIL_Status_t RADIO_AGCCCAThresholdSet(uint8_t threshold)

{
  BUS_RegMaskedClear(&AGC->CTRL1,0xff);
  BUS_RegMaskedSet(&AGC->CTRL1,(uint32_t)threshold);
  return RAIL_STATUS_NO_ERROR;
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
  uVar4 = MODEM->CF;
  uVar5 = MODEM->CF;
  uVar6 = MODEM->CF;
  uVar1 = (&modemCfDec0Factors)[uVar4 & 7];
  uVar3 = CMU_ClockFreqGet(cmuClock_HF);
  uVar10 = __aeabi_uldivmod((int)((ulonglong)uVar3 * 1000),(int)((ulonglong)uVar3 * 1000 >> 0x20),uVar1,0);
  uVar10 = __aeabi_uldivmod((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),((uVar5 << 0xf) >> 0x12) + 1,0);
  uVar11 = __aeabi_uldivmod((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),((uVar6 << 9) >> 0x1a) + 1,0);
  iVar8 = (int)(uVar11 >> 0x20);
  uVar4 = __aeabi_uldivmod(0xdb000000,0x7558b,(int)uVar11,iVar8);
  if (uVar4 < us) return RAIL_STATUS_INVALID_PARAMETER;
  lVar2 = (uVar11 & 0xffffffff) * (ulonglong)us;
  uVar7 = (undefined4)lVar2;
  iVar8 = us * iVar8 + (int)((ulonglong)lVar2 >> 0x20);
  uVar5 = __aeabi_uldivmod(uVar7,iVar8,1000000000,0);
  iVar9 = 1;
  uVar4 = 0;
  do 
  {
    uVar6 = uVar4 + 1;
    if (uVar5 <= (uint)(1 << (uVar6 & 0xff))) 
	{
LAB_0000ddbc:
      BUS_RegMaskedClear(&AGC->CTRL1,0xf00);
      BUS_RegMaskedSet(&AGC->CTRL1,uVar4 << 8);
      uVar10 = __aeabi_uldivmod(uVar7,iVar8,10000000,0);
      uVar10 = __aeabi_uldivmod((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),iVar9,0);
      iVar8 = __aeabi_uldivmod((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),100,0);
      uVar4 = ((int)uVar10 + iVar8 * -100 & 0xffU) / 3;
      if (uVar4 < 0x20) 
	  {
        if (uVar4 == 0) 
		{
		  AGC->CTRL1 &= 0xffe0ffff;
		  AGC->CTRL1 |= 0x10000;
		  AGC->CTRL1 &= 0xfc1fffff;
		  AGC->CTRL1 |= 0x200000;
          return RAIL_STATUS_NO_ERROR;
        }
      }
      else uVar4 = 0x1f;
	  AGC->CTRL1 &= 0x3ffffff;
	  AGC->CTRL1 |= iVar8 << 0x1a;	  
	  AGC->CTRL1 &= 0xffe0ffff;
	  AGC->CTRL1 |= uVar4 << 0x10;	
	  AGC->CTRL1 |= 0x3e00000;	
      return RAIL_STATUS_NO_ERROR;
    }
    if (uVar6 == 0x10) 
	{
      uVar4 = 0xf;
      goto LAB_0000ddbc;
    }
    iVar9 = iVar9 << 1;
    uVar4 = uVar6;
  } while( true );
}


void RADIO_SetCRCInitVal(uint32_t value)

{
  CRC->INIT = value;
  CRC->CMD = 1;
}


