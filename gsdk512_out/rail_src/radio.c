#include "radio.h"

//EFRDRV_irqClbk[];

static const unsigned char EFRDRV_actionFunc[32UL + 1] = {0x00, 0x00, 0x01, 0x00, 0x2C, 0x00, 0x01, 0x00, 0x24, 0x00, 0x01, 0x00, 0x1C, 0x00, 0x01, 0x00, 0x50, 0x00, 0x01, 0x00, 0x04, 0x00, 0x01, 0x00, 0x10, 0x00, 0x01, 0x00, 0x36, 0x00, 0x01, 0x00, 0x00};
static const unsigned char modemCfDec0Factors[5UL + 1] = {0x03, 0x04, 0x04, 0x08, 0x08, 0x00};
static const unsigned char regBases[8UL + 1] = {0x00, 0x00, 0x08, 0x40, 0x00, 0x00, 0x00, 0x21, 0x00};


void RADIO_WriteSync(undefined4 *addr,uint32_t sync)

{
  *addr = sync;
}



void RADIO_SetBitSync(uint32_t addr,uint32_t bitnumber)

{
  *(uint32_t *)(addr + 0x6000000) = 1 << (bitnumber & 0xff);
}



void RADIO_ClrBitSync(uint32_t addr,uint32_t bitnumber)

{
  *(uint32_t *)(addr + 0x4000000) = 1 << (bitnumber & 0xff);
}



void RADIO_OrSync(uint32_t addr,uint32_t sync)

{
  *(uint32_t *)(addr + 0x6000000) = sync;
}



void RADIO_XorSync(uint32_t *addr,uint32_t sync)

{
  *addr = sync ^ *addr;
}



void RADIO_AndSync(uint32_t addr,uint32_t sync)

{
  *(uint32_t *)(addr + 0x4000000) = ~sync;
}



void RADIO_WaitForSetSync(uint32_t *addr,uint32_t sync)

{
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  while ((*addr & sync) != sync);
  CORE_ExitCritical(irqState);
}



void RADIO_Delay(uint32_t us)

{
  PHY_UTILS_DelayUs(us);
}



void RADIO_SetAndForgetWrite(void)

{
  RAIL_Version_t version;
 
  SYSTEM_ChipRevisionGet(&version);
  RAC->IFADCCTRL = 0x5153e6c0;
  RAC->IFPGACTRL = 0x87e6;
  RAC->LNAMIXCTRL1 = 0x880;
  RAC->VCOCTRL = 0xf00277a;
  if (version->major == 1) && (version->minor < 2) SYNTH->VCOGAIN = 0x28;
  SYNTH->CTRL = 0xac3f;
  AGC->MANGAIN = 0x1800000;
  RAC->LNAMIXCTRL = 0;
  RAC->SYNTHREGCTRL = 0x3636d80;
  BUS_RegMaskedClear(&SYNTH->VCDACCTRL,SYNTH_VCDACCTRL_EN_Msk | SYNTH_VCDACCTRL_VCDACVAL_Msk; //0x7f);
  BUS_RegMaskedSet(&SYNTH->VCDACCTRL,0x23);
}



void RADIO_SeqInit(uint32_t src,uint32_t len)

{
  uint32_t tmp1;
  uint32_t tmp2;
  uint32_t tmp3;
  CORE_irqState_t irqState;

  tmp1 = RAC->STATUS;
  RAC->VECTADDR = 0x21000000;
  RAC->SEQCTRL = 1;
  irqState = CORE_EnterCritical();
  memcpy(0x21000000,src,len << 2);
  CORE_ExitCritical(irqState);
  RAC->R6 = 0x21000fbc;
  tmp1 = SEQ->REG0E4;
  tmp2 = SEQ->REG0E8;
  tmp3 = SEQ->DYNAMIC_CHPWR_TABLE;
  memset(0x21000f64,0,0x9c);
  SEQ->REG0E4 = tmp1;
  SEQ->REG0E8 = tmp2;
  SEQ->DYNAMIC_CHPWR_TABLE = tmp3;
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



void RADIO_Config(int param_1)

{
  undefined4 tmp;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  
  if (param_1 != 0) 
  {
    param_1 = param_1 + 8;
    while( true ) 
	{
      uVar2 = *(uint *)(param_1 + -8);
      if (uVar2 == 0xffffffff) break;
      uVar4 = (uVar2 << 8) >> 0x18;
      uVar3 = uVar2 & 0xffff | *(uint *)(regBases + ((uVar2 << 4) >> 0x1c) * 4);
      if (uVar4 < 2) (**(code **)(EFRDRV_actionFunc + (uVar2 >> 0x1c) * 4))(uVar3,*(undefined4 *)(param_1 + -4));
      else 
	  {
        uVar5 = *(undefined4 *)(param_1 + -4);
        tmp = CORE_EnterCritical();
        memcpy(uVar3,uVar5,uVar4 << 2);
        CORE_ExitCritical(tmp);
      }
      param_1 = param_1 + 8;
    }
  }
  PA_UpdateConfig();
  TIMING_SeqTimingInit();
}



void RADIO_RegisterIrqCallback(int param_1,undefined4 param_2)

{
  (&EFRDRV_irqClbk)[param_1] = param_2;
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
  if (_DAT_e000e200 << 0x18 < 0) BUFC_IRQHandler();
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
  state = (RAC->STATUS & RAC_STATUS_STATE_Msk) >> RAC_STATUS_STATE_Pos;
  if (state != 3) && (state != 7)) return (state == 4);
  else return true;
}



uint32_t RADIO_RxTrailDataLength(void)

{
  uint32_t len;
  
  if ((FRC->TRAILRXDATA & FRC_TRAILRXDATA_RTCSTAMP_Msk) == 0) len = 0;
  else len = 4;
  if (FRC->TRAILRXDATA & FRC_TRAILRXDATA_PROTIMERCC0WRAPH_Msk) len += 2;
  if (FRC->TRAILRXDATA & FRC_TRAILRXDATA_PROTIMERCC0WRAPL_Msk) len += 2;
  if (FRC->TRAILRXDATA & FRC_TRAILRXDATA_PROTIMERCC0BASE_Msk) len += 2;
  if (FRC->TRAILRXDATA & FRC_TRAILRXDATA_CRCOK_Msk) len += 1;
  if (FRC->TRAILRXDATA & FRC_TRAILRXDATA_RSSI_Msk) len += 1;
  return len;
}



void RADIO_FrameControlDescrBufferIdSet(int param_1,int param_2)

{
  (&FRC_CLR->FCD0)[param_1] = 0x300;
  (&FRC_SET->FCD0)[param_1] = param_2 << 8;
}



void RADIO_FrameControlDescrConfigSet(int param_1,uint param_2,int param_3,int param_4,byte param_5,byte param_6)

{
  (&FRC_CLR->FCD0)[param_1] = 31999;
  (&FRC_SET->FCD0)[param_1] = param_2 | (uint)param_6 << 10 | (uint)param_5 << 0xb | param_4 << 0xc | param_3 << 0xe;
}



void RADIO_FrameDescsConfig(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  RADIO_FrameControlDescrConfigSet(0,0xff,param_1,param_2,param_3,param_4,param_3);
  RADIO_FrameControlDescrConfigSet(2,0xff,param_1,param_2,param_3,param_4);
}



void RADIO_FRCErrorHandle(void)

{
  BUFC_RxBufferReset();
}



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
  BUS_RegMaskedSet(&RAC->SR3,0x1);
}



void RADIO_DccalDisable(void)

{
  BUS_RegMaskedClear(&RAC->SR3,0x1);
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
  return (((MODEM->TXBR & MODEM_TXBR_TXBRDEN_Msk) >> MODEM_TXBR_TXBRDEN_Pos) * (CMU_ClockFreqGet(0x11) >> 3)) / (MODEM->TXBR & MODEM_TXBR_TXBRNUM_Msk);
}



uint32_t RADIO_ComputeRxBaudrate(void)

{
  uint32_t dec0factor;
  int iVar5;
  uint32_t uVar6;
  
  uVar6 = (MODEM->RXBR & MODEM_RXBR_RXBRDEN_Msk) >> MODEM_RXBR_RXBRDEN_Pos;
  dec0factor = (uint)*(byte *)((int)&modemCfDec0Factors + (MODEM->CF & MODEM_CF_DEC0_Msk));
  iVar5 = (((MODEM->CF & MODEM_CF_DEC1_Msk) >> MODEM_CF_DEC1_Pos) * (dec0factor + 1)) * 2;

  return (uVar6 * CMU_ClockFreqGet(0x11)) / ((((MODEM->CF << 9) >> 0x1a) * (iVar5 + 1)) * (uVar6 * ((MODEM->RXBR & MODEM_RXBR_RXBRINT_Msk) >> MODEM_RXBR_RXBRINT_Pos) + (MODEM->RXBR & 0x1f)));
}



uint32_t RADIO_ComputeTxSymbolRate(void)

{
  if ((MODEM->CTRL0 & MODEM_CTRL0_CODING_Msk) == 0x20) return RADIO_ComputeTxBaudrate() / (((MODEM->CTRL0 & MODEM_CTRL0_DSSSLEN_Msk) >> MODEM_CTRL0_DSSSLEN_Pos) + 1);
  else return RADIO_ComputeTxBaudrate();
}



uint32_t RADIO_ComputeTxBitRate(void)

{
  uint32_t factor;
  
  if ((MODEM->CTRL0 & MODEM_CTRL0_CODING_Msk) == 0x20) 
  {
    factor = ((MODEM->CTRL0 & MODEM_CTRL0_DSSSLEN_Msk) >> MODEM_CTRL0_DSSSLEN_Pos) / ((MODEM->CTRL0 & MODEM_CTRL0_DSSSSHIFTS_Msk) >> MODEM_CTRL0_DSSSSHIFTS_Pos);
    if ((MODEM->CTRL0 & MODEM_CTRL0_DSSSDOUBLE_Msk) != 0) factor <<= 1;
    factor >>= 1;
    if (2 < factor) factor = 4;
  }
  else 
  {
    if (((MODEM->CTRL0 & MODEM_CTRL0_MODFORMAT_Msk) == 0x40) || ((MODEM->CTRL0 & MODEM_CTRL0_MODFORMAT_Msk) == 0x100)) factor = 2;
    else factor = 1;
  }
  return factor * RADIO_ComputeTxSymbolRate();
}



int32_t RADIO_GetRSSI(void)

{
  int16_t rssi;
  uint32_t status_before;
  uint32_t status_after;
  CORE_irqState_t irqState;
  
  do 
  {
    irqState = CORE_EnterCritical();
	status_before = RAC->STATUS & 0xf000000;
    rssi = (int16_t)(AGC->RSSI >> 6);
	status_after = RAC->STATUS & 0xf000000;
    CORE_ExitCritical(irqState);
    if (rssi != -0x200) 
	{
	  if (((status_after != 0x2000000) && (status_after != 0x3000000)) || ((status_before != 0x2000000) && (status_before != 0x3000000))) rssi = -0x200;
      break;
    }
  } while ((status_after == 0x2000000 || status_after == 0x3000000) && (status_before == 0x2000000 || status_before == 0x3000000));
  return (int32_t)rssi;
}


uint32_t RADIO_SetAgcCcaParams(int32_t param_1,uint32_t param_2)

{
  uint32_t i;
  
  for (i = 0; (uint32_t)(1 << (i & 0xff)) < (uint32_t)(param_1 * RADIO_ComputeRxBaudrate()) / 1000000; i++) 
  {
    if (i == 0x10) return 1;
  }
  BUS_RegMaskedClear(&AGC->CTRL1,0xf00);
  BUS_RegMaskedSet(&AGC->CTRL1,i << 8);
  if ((AGC->CTRL1 & 0xff) == 0x80) return 2;
  BUS_RegMaskedClear(&AGC->CTRL1,0xff);
  BUS_RegMaskedSet(&AGC->CTRL1,param_2 & 0xff);
  return 0;
}



bool RADIO_AGCCCAThresholdSet(uint8_t param_1)

{
  BUS_RegMaskedClear(&AGC->CTRL1,0xff);
  BUS_RegMaskedSet(&AGC->CTRL1,(uint32_t)param_1);
  return true;
}



uint32_t RADIO_CalcRssiPeriod(uint param_1)

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
  
  BUS_RegMaskedSet(&AGC->CTRL1,0x8000);
  uVar3 = MODEM->CF;
  uVar4 = MODEM->CF;
  uVar5 = MODEM->CF;
  uVar1 = *(undefined *)((int)&modemCfDec0Factors + (uVar3 & 7));
  uVar3 = CMU_ClockFreqGet(0x11);
  uVar9 = __aeabi_uldivmod((int)((ulonglong)uVar3 * 1000),(int)((ulonglong)uVar3 * 1000 >> 0x20),uVar1,0);
  uVar9 = __aeabi_uldivmod((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),((uVar4 << 0xf) >> 0x12) + 1,0);
  uVar10 = __aeabi_uldivmod((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),((uVar5 << 9) >> 0x1a) + 1,0);
  iVar7 = (int)(uVar10 >> 0x20);
  uVar3 = __aeabi_uldivmod(0xdb000000,0x7558b,(int)uVar10,iVar7);
  if (uVar3 < param_1) return 1;
  lVar2 = (uVar10 & 0xffffffff) * (ulonglong)param_1;
  uVar6 = (undefined4)lVar2;
  iVar7 = param_1 * iVar7 + (int)((ulonglong)lVar2 >> 0x20);
  uVar4 = __aeabi_uldivmod(uVar6,iVar7,1000000000,0);
  iVar8 = 1;
  uVar3 = 0;
  do 
  {
    uVar5 = uVar3 + 1;
    if (uVar4 <= (uint)(1 << (uVar5 & 0xff))) 
	{
LAB_000106a4:
      BUS_RegMaskedClear(&AGC->CTRL1,0xf00);
      BUS_RegMaskedSet(&AGC->CTRL1,uVar3 << 8);
      uVar9 = __aeabi_uldivmod(uVar6,iVar7,10000000,0);
      uVar9 = __aeabi_uldivmod((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),iVar8,0);
      iVar7 = __aeabi_uldivmod((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),100,0);
      uVar3 = ((int)uVar9 + iVar7 * -100 & 0xffU) / 3;
      if (uVar3 < 0x20) 
	  {
        if (uVar3 == 0) 
		{
		  AGC->CTRL1 &= 0xffe0ffff;
		  AGC->CTRL1 |= 0x10000;
		  AGC->CTRL1 &= 0xfc1fffff;
		  AGC->CTRL1 |= 0x200000;
          return 0;
        }
      }
      else uVar3 = 0x1f;
	  AGC->CTRL1 &= 0x3ffffff;
	  AGC->CTRL1 |= iVar7 << 0x1a;
	  AGC->CTRL1 &= 0xffe0ffff;
	  AGC->CTRL1 |= uVar3 << 0x10;
	  AGC->CTRL1 | 0x3e00000;
      return 0;
    }
    if (uVar5 == 0x10) 
	{
      uVar3 = 0xf;
      goto LAB_000106a4;
    }
    iVar8 = iVar8 << 1;
    uVar3 = uVar5;
  } while( true );
}



void RADIO_SetCRCInitVal(uint32_t val)

{
  CRC->INIT = val;
  CRC->CMD = 1;
}


