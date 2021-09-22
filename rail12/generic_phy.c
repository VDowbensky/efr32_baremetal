#include "generic_phy.h"


/* void GENERIC_PHY_RAC_IRQCallback(void)

{
  uint32_t flags;

  flags = flags & uVar1;
  RAC->IFC = flags;
  if ((int)(flags << 0x1f) < 0) (**(code **)(currentCallbacks + 0x30))();
  if ((int)(flags << 0x1d) < 0) (**(code **)(currentCallbacks + 0x2c))();
  if ((int)(flags << 6) < 0) 
  {
    if ((int)((uint)DAT_00010db1 << 0x1a) < 0) (**(code **)(currentCallbacks + 0x34))();
    PA_PeakDetectorHighRun();
  }
  if ((int)(flags << 5) < 0) 
  {
    if ((int)((uint)DAT_00010db1 << 0x19) < 0) (**(code **)(currentCallbacks + 0x38))();
    PA_PeakDetectorLowRun();
  }
  if ((int)(flags << 4) < 0) 
  {
    if ((char)DAT_00010db1 < '\0') (**(code **)(currentCallbacks + 0x3c))();
    PA_BatHighRun();
  }
  if (flags & 0xff0000 != 0) 
  {
    if ((flags & 0x800000) != 0) 
	{
      if ((int)((uint)DAT_00010db2 << 0x1f) < 0) (**(code **)(currentCallbacks + 0x40))();
      //uVar1 = flags & 0x7f0000;
    }
    if ((*(code **)(currentCallbacks + 0x44) != (code *)0x0) && (flags & 0x7f0000 != 0)) 
	{
                    // WARNING: Could not recover jumptable at 0x000100c4. Too many branches
                    // WARNING: Treating indirect jump as call
      (**(code **)(currentCallbacks + 0x44))();
      return;
    }
  }
  return;
}
 */


/* void GENERIC_PHY_PROTIMER_IRQCallback(void)

{
  uint uVar1;
  uint32_t flags;

  flags = PROTIMER->IEN & PROTIMER->IF;
  write_volatile_4(PROTIMER->IFC = flags);
  if ((flags & 0x501000) != 0) (**(code **)(currentCallbacks + 0x4c))(uVar2);
  if ((int)(flags << 0x15) < 0) 
  {
                    // WARNING: Could not recover jumptable at 0x000100fe. Too many branches
                    // WARNING: Treating indirect jump as call
    (**(code **)(currentCallbacks + 0x50))();
    return;
  }
}
 */


/* void GENERIC_PHY_MODEM_IRQCallback(void)

{
  uint32_t flags;

  flags = MODEM->IEN & MODEM->IF;
  MODEM->IFC = flags;
  if ((int)(flags << 0x12) < 0) (**(code **)(currentCallbacks + 0x1c))();
  if ((int)(flags << 0x16) < 0) (**(code **)(currentCallbacks + 0x20))();
  if ((int)(flags << 0x15) < 0) (**(code **)(currentCallbacks + 0x24))();
  if ((int)(flags << 0x14) < 0) 
  {
                    // WARNING: Could not recover jumptable at 0x00010154. Too many branches
                    // WARNING: Treating indirect jump as call
    (**(code **)(currentCallbacks + 0x28))();
    return;
  }
} */



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

/* void GENERIC_PHY_FRC_IRQCallback(void)

{
  uint uVar1;
  int iVar2;
  uint32_t flags;
  
  flags = FRC->IEN & FRC->IEN;
  SEQ->REG004 = uVar3;
  FRC->IFC = uVar3;
  if ((int)(uVar3 << 0x1b) < 0) 
  {
    (*currentCallbacks[2])();
    if (RADIO_RxBufferPacketAvailable() != 0) FRC->IFS = 0x10;
  }
  else 
  {
    if ((int)(flags << 0x19) < 0) (*currentCallbacks[3])();
  }
  if (((flags & 3) != 0) && (PROTIMER_CCTimerStop(3), (int)((uint)enabledCallbacks << 0x1f) < 0)) (**currentCallbacks)();
  if (((int)(flags << 0x17) < 0) && (uVar1 = (RAC->STATUS), (uVar1 & 0xf000000) == 0x6000000)) 
  {
    if ((int)((uint)enabledCallbacks << 0x1b) < 0) (*currentCallbacks[4])();
    if ((int)(FRC->IF << 0x1b) < 0) FRC->IFS |= 0x100;
    else 
	{
      RADIO_FRCErrorHandle();
      _DAT_4308010c = 1;
      _DAT_43080004 = SEQ->REG000;
      _DAT_43080004 = _DAT_43080004 & 0x200;
      if (_DAT_43080004 != 0) _DAT_43080004 = 1;
      _DAT_43080118 = 1;
    }
  }
  if (((int)(flags << 0x1d) < 0) && (uVar1 = (FRC->CTRL), -1 < (int)(uVar1 << 0x1f))) (*currentCallbacks[1])();
  if ((int)(flags << 0x1c) < 0) (*currentCallbacks[1])();
  if ((int)(flags << 0x11) < 0) (*currentCallbacks[5])();
  if ((int)(flags << 0x12) < 0) 
  {
                    // WARNING: Could not recover jumptable at 0x0001023c. Too many branches
                    // WARNING: Treating indirect jump as call
    (*currentCallbacks[6])();
    return;
  }
}
 */


void GENERIC_PHY_SetAddressFilteringMatchTable(void)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint *puVar11;
  uint uVar12;
  uint local_38;
  uint local_34;
  
  uVar5 = 0;
  local_34 = 0;
  uVar3 = 0;
  do 
  {
    uVar6 = uVar3 + 1;
    uVar1 = uVar6 * 5;
    uVar12 = addressFilterMatchTable >> (uVar1 & 0xff) & 0x1f;
    uVar7 = addressFilterMatchTable >> (uVar6 & 0xff) & 0x108421;
    uVar9 = uVar6 * 8;
    local_38 = uVar1;
    for (uVar8 = uVar6; local_38 = local_38 + 5, uVar8 != 4; uVar8 = uVar8 + 1) 
	{
      puVar11 = &SEQ->REG008;
      bVar2 = SEQ->REG050._0_1_;
      uVar4 = 1 << (uVar8 & 0xff) | 1 << (uVar3 & 0xff);
      if ((uVar4 & bVar2) == uVar4) 
	  {
        bVar2 = SEQ->REG04C._2_1_;
        for (iVar10 = 0; iVar10 < (int)(uint)bVar2; iVar10 = iVar10 + 1) 
		{
          puVar11 = puVar11 + 1;
          if (((*puVar11 >> (uVar9 & 0xff) ^ *puVar11 >> (uVar5 & 0xff)) & 0xff) != 0)
          goto LAB_00009826;
        }
        uVar12 = uVar12 | addressFilterMatchTable >> (local_38 & 0xff) & 0x1f;
      }
LAB_00009826:
      bVar2 = SEQ->REG050._1_1_;
      if ((uVar4 & bVar2) == uVar4) 
	  {
        bVar2 = SEQ->REG04C._3_1_;
        puVar11 = &SEQ->REG028;
        for (iVar10 = 0; iVar10 < (int)(uint)bVar2; iVar10 = iVar10 + 1) 
		{
          puVar11 = puVar11 + 1;
          if (((*puVar11 >> (uVar9 & 0xff) ^ *puVar11 >> (uVar5 & 0xff)) & 0xff) != 0)
          goto LAB_0000986e;
        }
        uVar7 = uVar7 | addressFilterMatchTable >> (uVar8 + 1 & 0xff) & 0x108421;
      }
LAB_0000986e:
      uVar9 = uVar9 + 8;
    }
    local_34 = local_34 | uVar7 << (uVar6 & 0xff) | uVar12 << (uVar1 & 0xff);
    uVar5 = uVar5 + 8;
    uVar3 = uVar6;
    if (uVar6 == 4) 
	{
      SEQ->REG008 = local_34;
      return;
    }
  } while( true );
}



void GENERIC_PHY_ConfigureCallbacks(RAIL_CalMask_t callbacks)

{
  uint uVar1;
  uint cbs;
  uint uVar3;
  uint uVar4;
  char local_c;
  byte bStack11;
  byte bStack10;
  
  enabledCallbacks = callbacks & availableCallbacks;
  cbs = enabledCallbacks & 0xff;
  uVar4 = 0x101;
  if ((enabledCallbacks & 1) != 0) uVar4 = 0x103;
  if (cbs & 0x02) uVar4 = uVar4 | 0xc;
  if (cbs & 0x04) uVar4 = uVar4 | 0x10;
  if (cbs & 0x08) uVar4 = uVar4 | 0x40;
  if (cbs & 0x10) uVar4 = uVar4 | 0x120;
  if (cbs & 0x20) uVar4 = uVar4 | 0x4000;
  uVar1 = (FRC->IEN);
  if (cbs & 0x40) uVar4 = uVar4 | 0x2000;
  uVar3 = uVar1 & (uVar4 ^ uVar1);
  FRC->IFC = uVar3;
  uVar4 = uVar4 & (uVar4 ^ uVar1);
  FRC->IEN &= ~uVar3;
  FRC->IFC = uVar4;
  FRC->IEN |= uVar4;
  local_c = (char)enabledCallbacks;
  bStack11 = (byte)(enabledCallbacks >> 8);
  cbs = (uint)bStack11;
  if (local_c < 0) uVar4 = 0x2000;
  else uVar4 = 0;
  if (cbs & 0x01) uVar4 = uVar4 | 0x200;
  if (cbs & 0x02) uVar4 = uVar4 | 0x400;
  uVar1 = MODEM->IEN;
  if (cbs & 0x04) uVar4 = uVar4 | 0x800;
  uVar3 = uVar1 & (uVar4 ^ uVar1);
  MODEM->IFC = uVar3;
  uVar4 = uVar4 & (uVar4 ^ uVar1);
  MODEM->IEN &= ~uVar3;
  MODEM->IFC = uVar4;
  MODEM->IEN |= uVar4;
  if ((enabledCallbacks & 0x800) == 0) uVar2 = 0;
  else uVar2 = 4;
  bStack10 = (byte)(enabledCallbacks >> 0x10);
  if ((uint)bStack11 & 0x10) uVar2 = uVar2 | 1;
  if ((uint)bStack10 & 0x01) uVar2 = uVar2 | 0x800000;
  uVar4 = RAC->IEN;
  if ((uint)bStack10 & 0x02) uVar2 = uVar2 | 0xff0000;
  uVar3 = uVar4 & (uVar2 ^ uVar4);
  RAC->IFC = uVar3;
  uVar2 = uVar2 & (uVar2 ^ uVar4);
  RAC->IEN &= ~uVar3;
  RAC->IFC = uVar2;
  RAC->IEN |= uVar2;
  uVar2 = 0x501000;
  if ((enabledCallbacks & 0x80000) == 0) uVar2 = 0;
  uVar4 = PROTIMER->IEN;
  if ((uint)bStack10 & 0x10) uVar2 = uVar2 | 0x400;
  uVar3 = uVar4 & (uVar2 ^ uVar4);
  PROTIMER->IFC = uVar3;
  uVar2 = uVar2 & (uVar2 ^ uVar4);
  PROTIMER->IEN &= ~uVar3;
  PROTIMER->IFC = uVar2;
  PROTIMER->IEN |= uVar2;
}



void GENERIC_PHY_SetCallbacks(RAIL_CalMask_t callbacks)

{
  uint uVar1;
  uint uVar2;
  
  _DAT_e000e280 = 0x10000000;
  _DAT_e000e180 = 0x10000000;
  uVar2 = 0;
  availableCallbacks = 0;
  if (callbacks != 0) 
  {
    uVar1 = 0;
    do 
	{
      if (*(int *)(callbacks + uVar1 * 4) != 0) uVar2 = uVar2 | 1 << (uVar1 & 0xff);
      uVar1 = uVar1 + 1;
      availableCallbacks = uVar2;
    } while (uVar1 != 0x15);
  }
  currentCallbacks = callbacks;
  GENERIC_PHY_ConfigureCallbacks(0xffffffff);
  _DAT_e000e100 = 0x10000000;
  _DAT_e000e280 = 0x10000000;
}



void GENERIC_PHY_LoadTxPacketBuffer(undefined2 *param_1)

{
  INT_Disable();
  RADIO_TxBufferSet(*(undefined4 *)(param_1 + 2),*param_1,0,0);
  INT_Enable();
}



void GENERIC_PHY_FlushTxPacketBuffer(void)

{
  INT_Disable();
  RADIO_TxBufferReset();
  INT_Enable();
}




void GENERIC_PHY_PacketTxCommon(void)

{
  if ((FRC->DFLCTRL & 7) == 0) FRC->WCNTCMP0 = RADIO_TxBufferBytesAvailable() - 1;
  _DAT_21000efc = _DAT_21000efc & 0xffffffdf;
}



bool GENERIC_PHY_PacketTx(void)

{
  INT_Disable();
  if (PROTIMER_CCTimerIsEnabled(3) == false) 
  {
    if (PROTIMER_LBTIsActive() == false) 
	{
      GENERIC_PHY_PacketTxCommon();
      _DAT_43080100 = 1;
      INT_Enable();
      return false;
    }
  }
  INT_Enable();
  return true;
}




bool GENERIC_PHY_SchedulePacketTx(undefined4 param_1,undefined4 param_2)

{
  INT_Disable();
  if ((PROTIMER_CCTimerIsEnabled(3) == 0) && (PROTIMER_LBTIsActive() == 0)) 
  {
    GENERIC_PHY_PacketTxCommon();
    if (PROTIMER_ScheduleTxEnable(3,param_1,param_2) == 0) _DAT_43080100 = 1;
    INT_Enable();
    return false;
  }
  INT_Enable();
  return true;
}




void GENERIC_PHY_StopTx(void)

{
  //_DAT_4308010c = 1;
  BUS_RegMaskedSet(&RAC->CMD, RAC_CMD_CLEARTXEN_Msk);
  //RAC->CMD = RAC_CMD_CLEARTXEN_Msk;
}



uint16_t GENERIC_PHY_PacketRxDataHelper(uint8_t *addr,uint16_t len)

{
  RADIO_RxBufferBytesAvailable();
  if (addr == NULL) RADIO_RxBufferDropBytes(len);
  else RADIO_RxBufferReadBytes(addr,len & 0xff);
  return len;
}



uint GENERIC_PHY_PacketRxAppendedInfoHelper(uint param_1,void *param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  void *apvStack28 [3];
  
  uVar1 = (FRC->TRAILRXDATA);
  apvStack28[0] = param_2;
  apvStack28[1] = (void *)param_3;
  apvStack28[2] = (void *)param_4;
  if (param_2 == NULL) RADIO_RxBufferDropBytes();
  else 
  {
    RADIO_RxBufferReadBytes(apvStack28,param_1 & 0xff,param_3,&FRC->,param_1);
    uVar3 = 0x14;
    memset(param_2,0,0x14);
    //bVar6 = FRC->TRAILRXDATA & 0x20;
    uVar5 = param_1;
    if (FRC->TRAILRXDATA & FRC_TRAILRXDATA_RTCSTAMP_Msk) 
	{
      uVar5 = param_1 - 4 & 0xffff;
      uVar3 = *(undefined4 *)((int)apvStack28 + uVar5);
    }
    if (FRC->TRAILRXDATA & FRC_TRAILRXDATA_RTCSTAMP_Msk) *(undefined4 *)((int)param_2 + 0x10) = uVar3;
    if (FRC->TRAILRXDATA & FRC_TRAILRXDATA_PROTIMERCC0WRAPH_Msk) 
	{
      uVar5 = uVar5 - 2 & 0xffff;
      *(uint *)((int)param_2 + 0xc) = *(uint *)((int)param_2 + 0xc) | (uint)*(ushort *)((int)apvStack28 + uVar5) << 0x10;
    }
    uVar4 = //FRC->TRAILRXDATA << 0x1c;
    if (FRC->TRAILRXDATA & FRC_TRAILRXDATA_PROTIMERCC0WRAPH_Msk) 
	{
      uVar5 = uVar5 - 2 & 0xffff;
      uVar4 = (uint)*(ushort *)((int)apvStack28 + uVar5) | *(uint *)((int)param_2 + 0xc);
      *(uint *)((int)param_2 + 0xc) = uVar4;
    }
    uVar2 = (undefined2)uVar4;
    //bVar6 = FRC->TRAILRXDATA & 0x04;
    if (FRC->TRAILRXDATA & FRC_TRAILRXDATA_PROTIMERCC0BASE_Msk) 
	{
      uVar5 = uVar5 - 2 & 0xffff;
      uVar2 = *(undefined2 *)((int)apvStack28 + uVar5);
    }
    if (FRC->TRAILRXDATA & FRC_TRAILRXDATA_PROTIMERCC0BASE_Msk) *(undefined2 *)((int)param_2 + 8) = uVar2;
    if (FRC->TRAILRXDATA & FRC_TRAILRXDATA_CRCOK_Msk) 
	{
      uVar5 = uVar5 - 1 & 0xffff;
      *(byte *)((int)param_2 + 6) = *(byte *)((int)apvStack28 + uVar5) >> 7;
    }
    //bVar6 = FRC->TRAILRXDATA & 0x01;
    if (FRC->TRAILRXDATA & FRC_TRAILRXDATA_RSSI_Msk) uVar5 = (uint)*(byte *)((int)apvStack28 + (uVar5 - 1 & 0xffff));
    if (FRC->TRAILRXDATA & FRC_TRAILRXDATA_RSSI_Msk) *(char *)((int)param_2 + 5) = (char)uVar5;
  }
  return param_1;
}



uint GENERIC_PHY_PacketRxHelper(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar2;
  
  uVar2 = param_1 - RADIO_RxTrailDataLength() & 0xffff;
  GENERIC_PHY_PacketRxDataHelper(param_2,uVar2);
  GENERIC_PHY_PacketRxAppendedInfoHelper(RADIO_RxTrailDataLength(),param_3);
  return uVar2;
}



void GENERIC_PHY_PacketRxGet(undefined2 *param_1)

{
  undefined2 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_24;
  undefined4 uStack32;
  undefined4 uStack28;
  undefined4 uStack24;
  undefined4 local_14;
  
  if (param_1 != (undefined2 *)0x0) 
  {
    uVar2 = RADIO_RxBufferGet();
    iVar3 = RADIO_RxLengthReadNext();
    if (iVar3 == 0xffff) 
	{
      *(undefined4 *)(param_1 + 2) = 0;
      *param_1 = 0;
    }
    else 
	{
      *(undefined4 *)(param_1 + 2) = uVar2;
      *param_1 = GENERIC_PHY_PacketRxHelper(iVar3,uVar2,&local_24);
      *(undefined4 *)(param_1 + 4) = local_24;
      *(undefined4 *)(param_1 + 6) = uStack32;
      *(undefined4 *)(param_1 + 8) = uStack28;
      *(undefined4 *)(param_1 + 10) = uStack24;
      *(undefined4 *)(param_1 + 0xc) = local_14;
      if (*(code **)(currentCallbacks + 0x48) != (code *)0x0) uVar2 = (**(code **)(currentCallbacks + 0x48))();
      RADIO_RxBufferSet(uVar2);
    }
  }
}




void GENERIC_PHY_StartRx(int param_1)

{
  if (param_1 != 0) FRC->WCNTCMP0 = param_1 - 1;
  if ((RADIO_RxBufferGet() == 0) && (*(code **)(currentCallbacks + 0x48) != (code *)0x0)) 
  {
    (**(code **)(currentCallbacks + 0x48))();
    RADIO_RxBufferSet();
  }
  _DAT_21000efc = _DAT_21000efc & 0xffffffdf;
  _DAT_43080004 = 1;
}



void GENERIC_PHY_ChannelSet(uint8_t channel)

{
  SYNTH_ChannelSet(channel,true);
}




void GENERIC_PHY_SeqAtomicLock(void)

{
  //read_volatile(RAC->SR0._0_1_);
  while (RAC->SR0 & 0x01) 
  {
    //_DAT_43081104 = 0;
	BUS_RegMaskedClear(&RAC->SR0,2);
    PROTIMER_DelayUs(2);
  }
  //_DAT_43081104 = 1;
  BUS_RegMaskedSet(&RAC->SR0,2);
}



void GENERIC_PHY_RadioEnable(bool enable)

{
  if (enable == false) 
  {
    GENERIC_PHY_SeqAtomicLock();
    _DAT_21000efc = _DAT_21000efc | 0x20;
	RAC->RXENSRCEN &= 0xffffff00;
    FRC->CMD = 1;
    _DAT_43080114 = 1;
    _DAT_43081104 = (uint)enable;
  }
  else 
  {
    if (RAC->CTRL & 0x01) 
	{
      _DAT_43080180 = 0;
    }
  }
}




void GENERIC_PHY_SeqAtomicUnlock(void)

{
  _DAT_43081104 = 0;
}




void GENERIC_PHY_TxDisable(void)

{
  _DAT_43080114 = 1;
}



uint32_t GENERIC_PHY_PreviousTxTime(void)

{
  return PROTIMER_GetCCTime(1);
}



void GENERIC_PHY_RACConfig(void)

{
  RADIO_SeqInit(&genericSeqProg,genericSeqProg_size);
  memset(&DAT_21000efc,0,0x70);
  RAC->SR0 = 0;
  RAC->SR1 = 0;
  RAC->SR2 = 0;
  TEMPCAL_Init();
  RADIO_RxSearchTimeSet(0);
  RADIO_TxToRxSearchTimeSet(0);
  RADIO_RxWarmTimeSet(100);
  RADIO_TxToRxTimeSet(100);
  RADIO_TxToTxTimeSet(100);
  RADIO_RxToTxTimeSet(100);
  RADIO_TxWarmTimeSet(100);
}



void GENERIC_PHY_FrameConfig(void)

{
  RADIO_Config();
}


void GENERIC_PHY_DirectModeConfig(uint8_t *config)

{
  uint uVar1;
  uint uVar2;
  
  if (config != NULL) 
  {
    RADIOCMU_ClockEnable(0x67400,true);
    CMU_ClockEnable(cmuClock_GPIO,true);
	MODEM->CTRL2 &= 0xfffff3ff;
    if ((uint)*config == 0) MODEM->CTRL2 = MODEM->CTRL2;
    else 
	{
      uVar2 = (uint)config[4];
      if ((uint)config[4] == 0) MODEM->CTRL2 |= 0x800;
      else 
	  {
		MODEM->CTRL2 |= 0xc00;
        uVar2 = 4;
      }
      uVar2 = uVar2 | 1;
    }
    if (config[1] != '\0') 
	{
	  MODEM->CTRL2 &= 0xfffffdff;
      if (config[3] == '\0') MODEM->CTRL2 |= 0x200;
      else 
	  {
        MODEM->CTRL2 = MODEM->CTRL2;
        uVar2 = uVar2 | 4;
      }
      uVar2 = uVar2 | 2;
    }
	MODEM->CTRL2 &= 0xfffffeff;
    if (config[2] != '\0') MODEM->CTRL2 |= 0x100;
    MODEM->ROUTELOC0 = (uint)config[0xb] | (uint)config[8] << 0x10 | (uint)config[5] << 8;
	MODEM->ROUTEPEN &= 0xfffffff8;
	MODEM->ROUTEPEN |= uVar2;
    if (uVar2 & 0x01) GPIO_PinModeSet(config[0xc],(uint)config[0xd],gpioModeInput,0);
    if (uVar2 & 0x02) GPIO_PinModeSet(config[6],(uint)config[7],gpioModePushPull,0);
    if (uVar2 & 0x04) GPIO_PinModeSet(config[9],(uint)config[10],gpioModePushPull,0);
  }
}



void GENERIC_PHY_PROTIMERConfig(void)

{
  PROTIMER->IFC = 0x3f3fff7;
  PROTIMER->IEN &= 0xfc0c0008;
  PROTIMER->CTRL = 0;
  PROTIMER->BASECNT = 0;
  PROTIMER->WRAPCNT = 0;
  PROTIMER->BASECNTTOP = 0xffff;
  PROTIMER->WRAPCNTTOP = 0xffffffff;
  PROTIMER->LBTCTRL = 0;
}



uint8_t GENERIC_PHY_ChannelGet(void)

{
  return SYNTH->CHCTRL & 0xff;
}



void GENERIC_PHY_SYNTH_IRQHandler(void)

{
  SYNTH->IFC = SYNTH->IEN & SYNTH->IF;
}



void GENERIC_PHY_ResetPacketConfig(void)

{
  FRC->DFLCTRL &= 0xfffffff8;
  FRC->DFLCTRL = FRC->DFLCTRL;
  _DAT_21000efc = _DAT_21000efc & 0xfffffff8;
}



void GENERIC_PHY_ConfigureVariableLength(uint param_1,uint param_2,int param_3,int param_4)

{
  uint32_t uVar2;
  
  GENERIC_PHY_ResetPacketConfig();
  FRC->WCNTCMP1 = param_1 & 0xfff;
  if ((param_2 & 0xf) < 9) uVar2 = 1;
  else 
  {
    if (param_4 == 0) uVar2 = 3;
    else uVar2 = 4;
  }
  FRC->MAXLENGTH = 0xfff;
  FRC->DFLCTRL &= 0xffff00f8;
  FRC->DFLCTRL |= (param_2 & 0xf) << 0xc | (param_3 - 1U & 0xf) << 8 | uVar2;
}



void GENERIC_PHY_ConfigureFixedLength(int param_1)

{
  GENERIC_PHY_ResetPacketConfig();
  FRC->WCNTCMP0 = param_1 - 1U & 0xfff;
}



void GENERIC_PHY_ConfigureFrameType(RAIL_FrameType_t *frameType)

{
  uint uVar1;
  uint uVar2;
  
  GENERIC_PHY_ResetPacketConfig();
  if (frameType == (RAIL_FrameType_t *)0x0) 
  {
    memset(&SEQ->REG054,0,0x18);
    return;
  }
  SEQ->REG058 = (uint)frameType->offset;
  SEQ->REG05C = (uint)frameType->mask;
  SEQ->REG060 = 0;
  SEQ->REG064 = (uint)frameType->frameLen;
  SEQ->REG068 = (uint)frameType->isValid;
  uVar2 = (uint)frameType->mask;
  if (uVar2 != 0) 
  {
    while (-1 < (int)(uVar2 << 0x1f)) 
	{
      uVar1 = (SEQ->REG060);
      uVar2 = uVar2 >> 1;
      SEQ->REG060 = uVar1 + 1;
    }
  }
  FRC->WCNTCMP0 = frameType->offset + 1;
  _DAT_21000efc = _DAT_21000efc | 7;
}



bool GENERIC_PHY_EnableAddressFiltering(void)

{
  int iVar1;
  
  iVar1 = _DAT_21000efc << 0x1b;
  _DAT_21000efc = _DAT_21000efc | 0x10;
  return SUB41((uint)iVar1 >> 0x1f,0);
}



bool GENERIC_PHY_DisableAddressFiltering(void)

{
  int iVar1;
  
  iVar1 = _DAT_21000efc << 0x1b;
  _DAT_21000efc = _DAT_21000efc & 0xffffffef;
  return SUB41((uint)iVar1 >> 0x1f,0);
}



bool GENERIC_PHY_IsEnabledAddressFiltering(void)

{
  return SUB41((uint)(_DAT_21000efc << 0x1b) >> 0x1f,0);
}



void GENERIC_PHY_ResetAddressFiltering(void)

{
  memset(&SEQ->REG008,0,0x4c);
  addressFilterMatchTable = 0;
}



void GENERIC_PHY_Init(void)

{
  uint uVar1;
  bool bVar2;
  undefined *puVar3;
  undefined8 uVar4;
  
  RADIO_Init();
  _DAT_e000e280 = 0x40000000;
  _DAT_e000e180 = 0x40000000;
  GENERIC_PHY_RACConfig();
  FRC->TRAILRXDATA = 0x1b;
  FRC->RXCTRL = 0x60;
  RADIO_PTI_Enable();
  if ((int)(RAC->CTRL << 0x1f) < 0) _DAT_43080180 = 0;
  RADIO_RegisterIrqCallback(1,0x9699);
  RADIO_RegisterIrqCallback(2,0x9649);
  RADIO_RegisterIrqCallback(5,0x9565);
  RADIO_RegisterIrqCallback(7,0x960d);
  GENERIC_PHY_ResetAddressFiltering();
  puVar3 = &DAT_21000efc;
  _DAT_21000efc = _DAT_21000efc | 8;
  PROTIMER_Init();
  PROTIMER_Start();
  PROTIMER_CCTimerCapture(0,0xc00000);
  uVar4 = PROTIMER_CCTimerCapture(1,0x200000);
  bVar2 = RFRAND_SeedProtimerRandom((int)uVar4,(uint)((ulonglong)uVar4 >> 0x20),puVar3);
  SYNTH_DCDCRetimeEnable(bVar2);
  SEQ->REG070 = 0;
}



bool GENERIC_PHY_ConfigureAddressFiltering(RAIL_AddrConfig_t *addrconfig)

{
  GENERIC_PHY_ResetAddressFiltering();
  if (addrconfig == (RAIL_AddrConfig_t *)0x0) return true;
  SEQ->REG04C._0_1_ = addrconfig->numFields;
  if (*(byte *)&addrconfig->field_0x2 < 9) 
  {
    SEQ->REG04C._2_1_ = *(byte *)&addrconfig->field_0x2;
    SEQ->REG04C._1_1_ = *(undefined *)&addrconfig->field_0x1;
    if (*(byte *)&addrconfig->field_0x3 < 9) 
	{
      SEQ->REG04C._3_1_ = *(byte *)&addrconfig->field_0x3;
      SEQ->REG050._2_1_ = *(undefined *)&addrconfig->sizes;
      addressFilterMatchTable = addrconfig->offsets;
      GENERIC_PHY_SetAddressFilteringMatchTable();
      return true;
    }
  }
  return false;
}



bool GENERIC_PHY_EnableAddress(uint8_t field,uint8_t index)

{
  uint uVar1;
  
  uVar1 = (uint)field;
  if ((uVar1 < 2) && (index < 4)) 
  {
    *(byte *)((int)&SEQ->REG050 + uVar1) = (byte)(1 << (uint)index) | *(byte *)((int)&SEQ->REG050 + uVar1);
    GENERIC_PHY_SetAddressFilteringMatchTable();
    return true;
  }
  return false;
}



bool GENERIC_PHY_DisableAddress(uint8_t field,uint8_t index)

{
  uint uVar1;
  
  uVar1 = (uint)field;
  if ((uVar1 < 2) && (index < 4)) 
  {
    *(byte *)((int)&SEQ->REG050 + uVar1) = *(byte *)((int)&SEQ->REG050 + uVar1) & ~(byte)(1 << (uint)index);
    GENERIC_PHY_SetAddressFilteringMatchTable();
    return true;
  }
  return false;
}



bool GENERIC_PHY_SetAddress(uint8_t field,uint8_t index,uint8_t *value,bool enable)

{
  byte bVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = (uint)field;
  if ((uVar5 < 2) && (index < 4)) 
  {
    GENERIC_PHY_DisableAddress(field,index);
    uVar3 = (uint)index << 3;
    bVar1 = *(byte *)((int)&SEQ->REG04C + uVar5 + 2);
    puVar2 = &SEQ->REG00C + uVar5 * 8;
    for (iVar4 = 0; iVar4 < (int)(uint)bVar1; iVar4 = iVar4 + 1) 
	{
      uVar5 = *puVar2 & ~(0xff << (uVar3 & 0xff));
      if (value != NULL) uVar5 = uVar5 | (uint)value[iVar4] << (uVar3 & 0xff);
      *puVar2 = uVar5;
      puVar2 = puVar2 + 1;
    }
    if (enable != false) GENERIC_PHY_EnableAddress(field,index);
    return true;
  }
  return false;
}



RAIL_Status_t GENERIC_PHY_TimerStart(uint32_t time,uint32_t mode)

{
  return PROTIMER_CCTimerStart(2,time,mode);
}



void GENERIC_PHY_TimerStop(void)

{
  PROTIMER_CCTimerStop(2);
}



uint32_t GENERIC_PHY_TimerGetTimeout(void)

{
  return PROTIMER_GetCCTime(2);
}



bool GENERIC_PHY_TimerExpired(void)

{
  return SUB41((PROTIMER->IF << 0x15) >> 0x1f,0);
}



bool GENERIC_PHY_TimerIsRunning(void)

{
  return PROTIMER_CCTimerIsEnabled(2);
}


