#include "radio.h"
#include <stdbool.h>
#include <string.h>
#include "em_bus.h"
#include "em_int.h"
#include "em_assert.h"
#include "tempcal.h"
#include "radio.h"
#include "radio_cmu.h"
#include "phy_utils.h"
#include "em_system.h"
#include "pa.h"
#include "rf_test.h"

uint32_t rxWarmTimeUs;

void RADIO_BUFCClear(int buf)

{
  *(uint32_t*)((buf * 0x30 + 0x42181028) * 0x20) = 1; //using bit-banding C081
}



void RADIO_WriteSync(uint32_t *addr,uint32_t data)

{
  *addr = data;
}



void RADIO_OrSync(uint32_t *addr,uint32_t data)

{
  *addr = data | *addr;
}



void RADIO_XorSync(uint32_t *addr,uint32_t data)

{
  *addr = data ^ *addr;
}



void RADIO_AndSync(uint32_t *addr,uint32_t data)

{
  *addr = data & *addr;
}



void RADIO_WaitForSetSync(uint32_t *addr,uint32_t data)

{
	INT_Disable();
	while ((*addr & data) != data);
	INT_Enable();
}



uint32_t RADIO_UsToStimerTickCalc(uint32_t us)

{
//  uint64_t lVar1;

//  us = us & ~((int)us >> 0x1f);
//  lVar1 = RADIOCMU_ClockFreqGet(0x75160) * (uint64_t)us;
  return ((uint64_t)us * RADIOCMU_ClockFreqGet(0x75160))/8000000;
  
 // __aeabi_uldivmod((int)lVar1,uVar2 * ((int)us >> 0x1f) + (int)((us)lVar1 >> 0x20),
 //                  8000000,0,param_4);
}



void RADIO_Delay(uint32_t us)

{
  PHY_UTILS_DelayUs(us);
}



void RADIO_BUFCWriteContSync_constprop_3(uint8_t *addr,int len)

{
  uint8_t *ptr;
  
  INT_Disable();
  ptr = addr;
  while (ptr != (addr + len))
  {
    BUFC->BUF0_WRITEDATA = (uint8_t)*ptr;
    ptr++;
  }
  INT_Enable();
}



void RADIO_ClrBitSync(int addr,int bit)

{
  *(uint32_t *)((bit + (addr + 0x2100000) * 8) * 4) = 0;
}



void RADIO_SetBitSync(int addr,int bit)

{
  *(uint32_t *)((addr + (bit + 0x2100000) * 8) * 4) = 1;
}



void RADIO_ModemConfigFixup(void)

{
  SEQ->SYNTHLPFCTRLTX = RAC->LPFCTRL;
  SEQ->SYNTHLPFCTRLRX = RAC->LPFCTRL & 0xfffffff0;
}



void RADIO_SetAndForgetWrite(void)

{
  SYSTEM_ChipRevision_TypeDef local_c;

  SYSTEM_ChipRevisionGet(&local_c);
  RAC->IFADCCTRL = 0x1153e6c0;
	
  RAC->IFPGACTRL = 0x87e6;
  RAC->LNAMIXCTRL1 = 0x880;
  RAC->VCOCTRL = 0xf00277a;
	if((local_c.major & 0x01) && (local_c.minor < 2)) SYNTH->VCOGAIN = 0x28;
  SYNTH->CTRL = 0xac3f;
  AGC->MANGAIN = 0x1800000;
  RAC->LNAMIXCTRL = 0;
  RAC->SYNTHREGCTRL = 0x3636d80;
}





void RADIO_SeqInit(void *src,uint32_t len)

{
  uint32_t t1, t2, t3;
  t1 = RAC->STATUS & RAC_RXENSRCEN_SWRXEN_Msk; //???
  RAC->VECTADDR = 0x21000000;
  RAC->SEQCTRL = 1;
  INT_Disable();
  //memcpy((void *)0x21000000,src,len << 2);
  memcpy((void *)0x21000000,src,len);
  INT_Enable();
  t3 = SEQ->REG0C8;
  t2 = SEQ->REG0C4;
  t1 = SEQ->REG0C0;
  RAC->R6 = 0x21000fcc;
  memset((void *)0x21000f6c,0,0x94);
  SEQ->REG0C0 = t1;
  SEQ->REG0C4 = t2;
  SEQ->REG0C8 = t3;
  SEQ->REG0BC = -(RADIO_UsToStimerTickCalc(0x3c));
}



void RADIO_CLKEnable(void)

{
  RADIOCMU_ClockEnable(0x63400,1);
  RADIOCMU_ClockEnable(0x60400,1); //PROTIMER
  RADIOCMU_ClockEnable(0x64400,1);
  RADIOCMU_ClockEnable(0x67400,1);
  RADIOCMU_ClockEnable(0x66400,1);
  RADIOCMU_ClockEnable(0x65400,1);
  RADIOCMU_ClockEnable(0x62400,1);
  RADIOCMU_ClockEnable(0x68400,1);
}



void RADIO_Config(void *radioConfig) //omitted
{
  uint32_t uVar1;
  void *__dest;
  uint32_t uVar2;
  void *__src;
  
  radioConfig = radioConfig + 8;
	//copy config parameters to RF registers
  while( true )
  {
    uVar1 = *(uint32_t *)(radioConfig - 8);
    if (uVar1 == 0xffffffff) break;
    //uVar2 = (uVar1 << 8) >> 0x18;
    uVar2 = uVar1 & 0xff;;
//    __dest = (void *)((uVar1 & 0xffff) | *(uint *)(&regBases + ((uVar1 << 4) >> 0x1c) * 4));
//    __dest = (void *)((uVar1 & 0xffff) | *(uint *)(&regBases + (uVar1 & 0x0f) * 4)); //!!!!!!!!!!!!!!!!!!!!!!!!!!!
//    if (uVar2 < 2)
//    {
//      (*(code *)(&EFRDRV_actionFunc)[uVar1 >> 0x1c])
//                (__dest,*(uint32_t *)(radioConfig + -4),&EFRDRV_actionFunc,
//                 (&EFRDRV_actionFunc)[uVar1 >> 0x1c],param_4);
//    }
//    else
//    {
//      __src = *(void **)(radioConfig + -4);
//      INT_Disable();
//      memcpy(__dest,__src,uVar2 << 2);
//      INT_Enable();
//    }
    radioConfig = radioConfig + 8;
  }
  PA_BandSelect();
  return;
}




void RADIO_RegisterIrqCallback(int irqN,void *func)

{
  //(&EFRDRV_irqClbk)[irqN] = func;
}



void FRC_PRI_IRQHandler(void)

{
                    // WARNING: Could not recover jumptable at 0x000102e0. Too many branches
                    // WARNING: Treating indirect jump as call
//  (*EFRDRV_irqClbk)();
}



void FRC_IRQHandler(void)

{
                    // WARNING: Could not recover jumptable at 0x000102ec. Too many branches
                    // WARNING: Treating indirect jump as call
//  (*DAT_000109d0)();
}



void RAC_RSM_IRQHandler(void)

{
                    // WARNING: Could not recover jumptable at 0x000102f8. Too many branches
                    // WARNING: Treating indirect jump as call
//  (*DAT_000109e0)();
}



void RAC_SEQ_IRQHandler(void)

{
                    // WARNING: Could not recover jumptable at 0x00010304. Too many branches
                    // WARNING: Treating indirect jump as call
 // (*DAT_000109e0)();
}



void AGC_IRQHandler(void)

{
                    // WARNING: Could not recover jumptable at 0x00010310. Too many branches
                    // WARNING: Treating indirect jump as call
//  (*DAT_000109f0)();
}



void PROTIMER_IRQHandler(void)

{
  PROTIMER->IFC = 0xffffffff;   //temporary
}



void BUFC_IRQHandler(void)

{
                    // WARNING: Could not recover jumptable at 0x00010328. Too many branches
                    // WARNING: Treating indirect jump as call
//  (*DAT_000109d8)();
}



void MODEM_IRQHandler(void)

{
                    // WARNING: Could not recover jumptable at 0x00010334. Too many branches
                    // WARNING: Treating indirect jump as call
//  (*DAT_000109d4)();
}



void RADIO_BUFCConfig(int param_1,uint32_t param_2,uint32_t param_3,uint32_t param_4,uint32_t param_5)

{
  int iVar1;
  
//  iVar1 = count_leading_zeroes(param_2);
  (&BUFC->BUF0_CTRL)[param_1 * 0xc] = 0x19 - iVar1;
  (&BUFC->BUF0_ADDR)[param_1 * 0xc] = param_3;
  (&BUFC->BUF0_THRESHOLDCTRL)[param_1 * 0xc] = param_4 | param_5;
}



uint32_t RADIO_BUFCBytesAvailable(uint8_t buf)

{
  return (&BUFC->BUF0_STATUS)[buf * 0xc] & 0x1fff;
}





void RADIO_TxBufferSet(uint8_t * param_1,int param_2,uint8_t * param_3,uint32_t param_4)

{
  uint32_t uVar1;
  
  RADIO_BUFCClear(0);
  RADIO_BUFCWriteContSync_constprop_3(param_1,param_2);
  if (param_4 == 0)
  {
    return;
  }
  uVar1 = 0x100U - param_2 & 0xffff;
//  bufcTxStreaming = (undefined2)param_2;
//  DAT_00010b82 = (undefined2)param_4;
//  DAT_00010b8c = (undefined2)uVar1;
//  DAT_00010b84 = param_1;
//  DAT_00010b88 = param_3;
  if (uVar1 < param_4) 
	{
//    RADIO_BUFCWriteContSync_constprop_3(param_3);
//    _DAT_43021d90 = 1;
		//BUS_RegMaskedSet(&BUFC->IEN, 0x10);
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
	BUFC->IEN |= 0x400;
}



void RADIO_RXBufferDisableThrInt(void)

{
	BUFC->IEN &= 0xfffffbff;
}



bool RADIO_IsRxActive(void)

{
  if (((RAC->STATUS & 0x0f) != 3) && ((RAC->STATUS & 0x0f) != 7)) return (RAC->STATUS & 0x0f) == 4;
  return true;
}





void RADIO_RxBufferSet(int param_1)

{
  if (param_1 != 0)
  {
//    _DAT_43022d80 = 1; //BUFC->REG16C (!!!) bit 0
  }
//  bufcRxStreaming = 0;
//  DAT_00010b7c = param_1;
}



uint32_t RADIO_RxBufferGet(void)

{
  //return DAT_00010b7c; //rx buffer address
	return 0x20001000;
}



void RADIO_RxBufferReset(void)

{
//  bufcRxStreaming = 0;
  RADIO_BUFCClear(1);
  RADIO_BUFCClear(2);
}





void RADIO_BUFCIrqHandler(void)

{
  uint16_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint8_t * iVar4;
  uint32_t flags;
  
  //uVar2 = read_volatile_4(BUFC->IF);
  //uVar3 = BUFC->IEN;
  //write_volatile_4(BUFC->IFC,uVar2 & uVar3);
	flags = BUFC->IEN & BUFC->IF;
  BUFC->IFC = flags;
  
  //if ((int)(uVar5 << 0x1d) < 0)
	  if(flags & 0x04)
    {
 //   iVar4 = DAT_00010b88 + (uint32_t)DAT_00010b8c;
 //   if (((uint)DAT_00010b82 - (uint32_t)DAT_00010b8c & 0xffff) < 0xe1) {
 //     RADIO_BUFCWriteContSync_constprop_3(iVar4);
      //_DAT_43021d90 = 0;  //BUFC->REG0EC bit 4 -
      BUFC->IEN &= ~0x10;
    }
    else
    {
 //     uVar1 = DAT_00010b8c + 0xe0;
      RADIO_BUFCWriteContSync_constprop_3(iVar4,0xe0);
 //     DAT_00010b8c = uVar1;
    }
  //if ((int)(uVar5 << 0x15) < 0)
  if(flags & 0x400) RFTEST_BerEmptyBufcAndUpdateStats();
  if (flags & 0xa0a00) RADIO_RxBufferReset();
  if(flags & 0x9)
  {
    //_DAT_43080114 = 1;
    RAC->CMD |= 0x20; //TXDIS
    RADIO_TxBufferReset();
  }
   if(flags & 0x02) RADIO_TxBufferReset();
}




int RADIO_RxTrailDataLength(void)

{
  uint32_t t1;
  uint16_t t2;
  
  t1 = FRC->TRAILRXDATA;
  if ((t1 & 0x20) == 0) t2 = 0;
  else t2 = 4;
  if(t1 & 0x08000000) t2 += 2;
  if(t1 & 0x10000000) t2 += 2;
  if(t1 & 0x20000000) t2 += 2;
  if(t1 & 0x40000000) t2 += 1;
  if(t1 & 0x80000000) t2 += 1;
  return t2;
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
  return BUFC->BUF1_READDATA & 0xff;
}



void RADIO_FrameControlDescrBufferIdSet(int buf,int fcd)

{
  (&FRC->FCD0)[buf] = (&FRC->FCD0)[buf] & 0xfffffcff; //bits 8,9
  (&FRC->FCD0)[buf] = (&FRC->FCD0)[buf] | fcd << 8;
}



void RADIO_FrameControlDescrConfigSet(int param_1,uint32_t param_2,int param_3,int param_4,uint8_t param_5,uint8_t param_6)

{
  (&FRC->FCD0)[param_1] = (&FRC->FCD0)[param_1] & 0xffff8300;
  (&FRC->FCD0)[param_1] =
       param_2 | (uint32_t)param_6 << 10 | (uint32_t)param_5 << 0xb | param_4 << 0xc | param_3 << 0xe |
       (&FRC->FCD0)[param_1];
}



void RADIO_FrameDescsConfig (uint32_t param_1,uint32_t param_2,uint32_t param_3,uint32_t param_4)

{
 // RADIO_FrameControlDescrConfigSet(0,0xff,param_1,param_2,param_3,param_4,param_3); //!!!!!!!!!!!!!!!!!!!
  RADIO_FrameControlDescrConfigSet(2,0xff,param_1,param_2,param_3,param_4);
}



uint8_t RADIO_BUFCRead(int buf)

{
  return (&BUFC->BUF0_READDATA)[buf * 12] & 0xff;
}



void RADIO_BUFCReadContASync(int buf,uint8_t *param_2,int param_3)

{
  uint8_t *puVar1;
  
  puVar1 = param_2;
  while (puVar1 != param_2 + param_3)
  {
    *puVar1 = (char)(&BUFC->BUF0_READDATA)[buf * 12];
    puVar1++;
  }
}



void RADIO_RxBufferReadBytes(uint8_t *param_1,uint32_t param_2)

{
  RADIO_BUFCReadContASync(1,param_1,param_2);
}



void RADIO_RxBufferDropBytes(uint32_t param_1,uint32_t param_2,uint32_t param_3,uint32_t param_4)

{
  uint32_t uVar1;
  
  uVar1 = param_1;
  while (param_1 != 0)
  {
    // RADIO_RxBufferReadBytes(&stack0xfffffff7,1,param_3,param_4,uVar1,param_2); //!!!!!!!!!!!!!!!!!
    param_1 = param_1 - 1 & 0xffff;
  }
}



uint32_t RADIO_RxLengthReadNext(uint32_t param_1,uint32_t param_2,uint32_t param_3,uint32_t param_4)

{
  uint32_t local_c;
  uint32_t uStack8;
  
  local_c = param_2;
  uStack8 = param_3;
  if (RADIO_RxBufferPacketAvailable() == 0) local_c = 0xffff;
  else
  {
//    RADIO_BUFCReadContASync(2,&local_c,2,param_4,param_1); //!!!!!!!!!!!!!!!!!!!!!
    local_c &= 0xff;
  }
  return local_c;
}





int RADIO_RxBufferFinalizeAndGet(int *param_1,uint32_t param_2,uint32_t param_3,uint32_t param_4)

{
  int iVar1;
  int iVar2;
  
//  iVar2 = RADIO_RxLengthReadNext();
//  iVar1 = DAT_00010b7c;
//  if (iVar2 != 0xffff) {
//    RADIO_BUFCReadContASync
//              (1,DAT_00010b7c + (uint)bufcRxStreaming,iVar2 - (uint)bufcRxStreaming,0xffff,param_4);
//    bufcRxStreaming = (ushort)iVar2;
//    _DAT_43022d80 = 0; //BUFC->REG16C bit 0

 //   *param_1 = iVar1;
 // }
  return iVar2;
}



void RADIO_FRCErrorHandle(void)

{
 // bufcRxStreaming = 0; //!!!!!!!!!!!!!!!
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
  BUFC->BUF1_CTRL = 2; //
//  BUFC->BUF1_ADDR = (uint32_t)&RADIO_rxBuffer;
  BUFC->BUF1_THRESHOLDCTRL = 0xaf;
  BUFC->BUF0_CTRL = 2;
//  BUFC->BUF0_ADDR = (uint32_t)&RADIO_txBuffer;
  BUFC->BUF0_THRESHOLDCTRL = 0x2020;
  BUFC->BUF2_CTRL = 0;
//  BUFC->BUF2_ADDR = (uint32_t)&RADIO_rxLengthBuffer;
  BUFC->BUF2_THRESHOLDCTR = 0x3e;
  RADIO_FrameControlDescrBufferIdSet(0,0);
  RADIO_FrameControlDescrBufferIdSet(1,0);
  RADIO_FrameControlDescrBufferIdSet(2,1);
  RADIO_FrameControlDescrBufferIdSet(3,1);
  //FRC->CTRL &= 0xffffff0f; //reset TXFCDMODE, RXFCDMODE
	BUS_RegMaskedClear(&FRC->CTRL, 0xf0);
  //FRC->CTRL |= 0xa0; //5, 7 - TXFCDMODE, RXFCDMODE
	BUS_RegMaskedSet(&FRC->CTRL, 0xa0);
 // DAT_000109d8 = RADIO_BUFCIrqHandler; //!!!!!!!

  NVIC_ClearPendingIRQ(FRC_IRQn);
  NVIC_EnableIRQ(FRC_IRQn);

  RADIO_BUFCClear(0);
  RADIO_BUFCClear(1);
  RADIO_BUFCClear(2);
  //BUFC->IEN |= 0xb0a0b; //
	BUS_RegMaskedSet(&BUFC->IEN, 0xb0a0b); 
  RADIO_RXBufferDisableThrInt();
  RADIO_SetAndForgetWrite();
  //MODEM->DCCOMP |= 3; //DCESTIEN, DCCOMPEN
	BUS_RegMaskedSet(&MODEM->DCCOMP, MODEM_DCCOMP_DCESTIEN_Msk | MODEM_DCCOMP_DCCOMPEN_Msk);
  RAC->SR3 = 0;
  RADIO_DccalEnable();
  //RAC->CTRL |= 0x80; //ACTIVEPOL
  //RAC->CTRL |= 0x00010000; //PAENPOL
  //RAC->CTRL |= 0x00040000; //PRSRXDIS
	//write_volatile_4(Peripherals::RAC_SET.CTRL,0x380);
	BUS_RegMaskedSet(&RAC->CTRL, RAC_CTRL_LNAENPOL_Msk | RAC_CTRL_PAENPOL_Msk | RAC_CTRL_ACTIVEPOL_Msk); 
}



void RADIO_DccalDisable(void)

{
	RAC->SR3 &= 0xfffffffe;
}





void RADIO_TxWarmTimeSet(uint16_t us)

{
  SEQ->REG0AC = RADIO_UsToStimerTickCalc(us - PA_RampTimeGet());
  SEQ->REG0AC += (RADIO_UsToStimerTickCalc((us - PA_RampTimeGet()) -20)) << 16;
}

void RADIO_RxToTxTimeSet(uint16_t us)

{
  SEQ->REG0A4 = RADIO_UsToStimerTickCalc(us - PA_RampTimeGet());
  SEQ->REG0A4 += (RADIO_UsToStimerTickCalc((us - PA_RampTimeGet()) - 20)) << 16;
}





void RADIO_RxFrameToTxTimeSet(uint16_t us)

{
  SEQ->REG0A8 = RADIO_UsToStimerTickCalc(us - PA_RampTimeGet());
  SEQ->REG0A8 += (RADIO_UsToStimerTickCalc((us - PA_RampTimeGet()) - 20)) << 16;
}





void RADIO_TxToTxTimeSet(uint16_t us)

{
  SEQ->REG0B8 = RADIO_UsToStimerTickCalc(us - PA_RampTimeGet());
  SEQ->REG0B8 += (RADIO_UsToStimerTickCalc((us - PA_RampTimeGet()) - 20)) << 16;
}





void RADIO_TxToRxTimeSet(uint16_t us)

{
  SEQ->REG0B0 = RADIO_UsToStimerTickCalc(us - 4);
}





void RADIO_RxWarmTimeSet(uint16_t us)

{
  rxWarmTimeUs = us;
  SEQ->REG09C = RADIO_UsToStimerTickCalc(us - 4);
}



uint16_t RADIO_RxWarmTimeGet(void)

{
  return rxWarmTimeUs;
}





void RADIO_RxSearchTimeSet(uint32_t us)

{
  SEQ->REG0A0 = RADIO_UsToStimerTickCalc(us);
}





void RADIO_TxToRxSearchTimeSet(uint32_t us)

{
  SEQ->REG0B4 = RADIO_UsToStimerTickCalc(us);
}



uint32_t RADIO_ComputeTxBaudrate(void)

{
  return ((MODEM->TXBR & 0xFF) * (CMU_ClockFreqGet(0x11) >> 3)) / (MODEM->TXBR & 0xffff);
}



uint32_t RADIO_ComputeTxSymbolRate(void)

{
  uint32_t tsr;
  tsr = RADIO_ComputeTxBaudrate();
  if ((MODEM->CTRL0 & MODEM_CTRL0_CODING_Msk) == 0x20) tsr /= (((MODEM->CTRL0 & MODEM_CTRL0_DSSSLEN_Msk) >> MODEM_CTRL0_DSSSLEN_Pos) + 1); //DSSS coding
  return tsr;
}



uint32_t RADIO_ComputeTxBitRate(void)

{
  uint32_t uVar3;
  if ((MODEM->CTRL0 & MODEM_CTRL0_CODING_Msk) == 0x20) //4,5 = bit 4 set - CODING
  {
    uVar3 = ((MODEM->CTRL0 << 0x10) >> 0x1b) / ((MODEM->CTRL0 << 0xd) >> 0x1d);
		//uVar3 = (MODEM->CTRL0 & MODEM_CTRL0_DSSSLEN_Msk) >> MODEM_CTRL0_DSSSLEN_Pos) / 
    //uVar3 = (MODEM->CTRL0 & 0x1F) / (MODEM->CTRL0 & 0x7); //not correct
    if (MODEM->CTRL0 & MODEM_CTRL0_DSSSDOUBLE_Msk) uVar3 = uVar3 << 1; //19, 20 - DSSSDOUBLE
    uVar3 = uVar3 >> 1;
    if (2 < uVar3) uVar3 = 4;
  }
  else
  {
    if (((MODEM->CTRL0 & MODEM_CTRL0_MODFORMAT_Msk) == 0x40) || ((MODEM->CTRL0 & MODEM_CTRL0_MODFORMAT_Msk) == 0x100)) uVar3 = 2;// bit 6 or bit  8 MODFORMAT
    else uVar3 = 1;
  }
  return uVar3 * RADIO_ComputeTxSymbolRate();
}



int16_t RADIO_GetRSSI(void)

{
  bool bVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  int16_t result;
  bool bVar6;
  uint32_t uVar5;
  
  do {
    INT_Disable();
    uVar5 = RAC->RXENSRCEN;
    uVar3 = AGC->RSSI;
    uVar2 = RAC->RXENSRCEN;
    bVar6 = (uVar2 & 0xff) == 0;
    bVar1 = (uVar5 & 0xff) == 0;
    //uVar5 = (int32_t)(uVar3 << 0x10) >> 0x16 & 0xffff;
    //uVar5 = (int32_t)(uVar3 & 0x03ff);
		uVar5 = (int32_t)(AGC->RSSI & 0x03ff);
    result = (int16_t)uVar5;
    INT_Enable();
    if (uVar5 != 0xfe00)
    {
      if (bVar6 || bVar1) result = -0x200; //-128 dBm
      break;
    }
  } while (!bVar6 && !bVar1);
  return (int)result;
}


