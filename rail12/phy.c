#include "phy.h"



ushort validateSetTiming(ushort *param_1)

{
  ushort uVar1;
  
  if (*param_1 < 0x3c) 
  {
    uVar1 = 0x3c;
  }
  else 
  {
    uVar1 = 13000;
    if (*param_1 < 0x32c9) goto LAB_00010014;
  }
  *param_1 = uVar1;
LAB_00010014:
  return *param_1;
}



uint8_t RAIL_RadioConfig(void *radioConfig)

{
  RADIO_Config(radioConfig);
  forceIrCal = 1;
  return '\0';
}



uint8_t RAIL_ChannelConfig(RAIL_ChannelConfig_t *config)

{
  bool bVar1;
  int32_t target;
  
  RAILInt_TrackChannelConfig((uint32_t)config);
  SYNTH_Config(config->configs->baseFrequency,config->configs->channelSpacing);
  bVar1 = SYNTH_Is2p4GHz();
  if (bVar1 == false) 
  {
    target = 3500000;
  }
  else 
  {
    target = 7000000;
  }
  SYNTH_DCDCRetimeClkSet(target);
  if (forceIrCal != '\0') 
  {
    forceIrCal = '\0';
    RAIL_RfHalCalibrationPend(0x10000);
  }
  return *(uint8_t *)&config->configs->channelNumberStart;
}



void RAIL_DirectModeConfig(bool enable)

{
  uint8_t *config;
  
  if (enable == false) 
  {
    config = &directModeDisableConfig;
  }
  else 
  {
    config = &directModeEnableConfig;
  }
  GENERIC_PHY_DirectModeConfig(config);
  return;
}



uint8_t RAIL_TxToneStart(uint8_t channel)

{
  char *pcVar1;
  uint32_t uVar2;
  
  pcVar1 = (char *)RAILInt_SetChannelConfig();
  if (pcVar1 != (char *)0x0) 
  {
    uVar2 = RAIL_DebugModeGet();
    if (uVar2 != 1) 
	{
      GENERIC_PHY_ChannelSet(channel - *pcVar1);
    }
    RFTEST_SaveRadioConfiguration();
    RFTEST_StartCwTx();
    return '\0';
  }
  return '\x01';
}



uint8_t RAIL_TxToneStop(void)

{
  RFTEST_StopTx();
  RFTEST_RestoreRadioConfiguration();
  return '\0';
}


uint8_t RAIL_TxStreamStart(uint8_t channel,int mode)

{
  char *pcVar1;
  uint32_t uVar2;
  
  if ((mode == 1) && (pcVar1 = (char *)RAILInt_SetChannelConfig(), pcVar1 != (char *)0x0)) 
  {
    RFTEST_SaveRadioConfiguration();
    RFTEST_StartStreamTx();
    uVar2 = RAIL_DebugModeGet();
    if (uVar2 != 1) 
	{
      GENERIC_PHY_ChannelSet(channel - *pcVar1);
    }
    return '\0';
  }
  return '\x01';
}



uint8_t RAIL_TxStreamStop(void)

{
  RFTEST_StopTx();
  RFTEST_RestoreRadioConfiguration();
  return '\0';
}



int32_t RAIL_TxPowerSet(int32_t powerLevel)

{
  PA_StripesAndSlicesCalc(powerLevel);
  return (int)gPaConfig.power;
}



int32_t RAIL_TxPowerGet(void)

{
  return (int)gPaConfig.power;
}



RAIL_Status_t RAIL_DebugFrequencyOverride(uint32_t freq)

{
  SYNTH_Config(freq,0);
  return RAIL_STATUS_NO_ERROR;
}



void RAIL_PacketLengthConfigFrameType(RAIL_FrameType_t *frameType)

{
  uint uVar1;
  uint uVar2;
  
  GENERIC_PHY_ResetPacketConfig();
  if (frameType == (RAIL_FrameType_t *)0x0) 
  {
    memset(&SEQ->REG054,0,0x18);
    return;
  }
  write_volatile_4(SEQ->REG058,(uint)frameType->offset);
  write_volatile_4(SEQ->REG05C,(uint)frameType->mask);
  write_volatile_4(SEQ->REG060,0);
  write_volatile_4(SEQ->REG064,(uint)frameType->frameLen);
  write_volatile_4(SEQ->REG068,(uint)frameType->isValid);
  uVar2 = (uint)frameType->mask;
  if (uVar2 != 0) 
  {
    while (-1 < (int)(uVar2 << 0x1f)) 
	{
      uVar1 = (SEQ->REG060);
      uVar2 = uVar2 >> 1;
      write_volatile_4(SEQ->REG060,uVar1 + 1);
    }
  }
  write_volatile_4(FRC->WCNTCMP0,frameType->offset + 1);
  _DAT_21000efc = _DAT_21000efc | 7;
  return;
}



int16_t RAIL_RxGetRSSI(void)

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
    if (uVar5 != 0xfe00) 
	{
      if (bVar6 && bVar1) 
	  {
        return iVar4;
      }
      return -0x200;
    }
  } while (bVar6 && bVar1);
  return iVar4;
}



void RAIL_SetTune(uint32_t tune)

{
  uint uVar1;
  
  CMU_ClockSelectSet(cmuClock_HF,cmuSelect_HFRCO);
  CMU_OscillatorEnable(cmuOsc_HFXO,false,false);
  uVar1 = (CMU->HFXOSTEADYSTATECTRL);
  write_volatile_4(CMU->HFXOSTEADYSTATECTRL,uVar1 & 0xfff007ff);
  uVar1 = (CMU->HFXOSTEADYSTATECTRL);
  write_volatile_4(CMU->HFXOSTEADYSTATECTRL,(tune & 0x1ff) << 0xb | uVar1);
  CMU_OscillatorEnable(cmuOsc_HFXO,true,true);
  CMU_ClockSelectSet(cmuClock_HF,cmuSelect_HFXO);
  return;
}



uint32_t RAIL_GetTune(void)

{
  uint uVar1;
  
  uVar1 = (CMU->HFXOSTEADYSTATECTRL);
  return (uVar1 << 0xc) >> 0x17;
}



uint32_t RAIL_GetTime(void)

{
  uint32_t uVar1;
  
  uVar1 = PROTIMER_GetTime();
  uVar1 = PROTIMER_PrecntOverflowToUs(uVar1);
  return uVar1;
}



RAIL_Status_t RAIL_SetTime(uint32_t time)

{
  RAIL_Status_t RVar1;
  int iVar2;
  bool bVar3;
  
  iVar2 = PROTIMER_SetTime();
  bVar3 = iVar2 == 0;
  if (bVar3) 
  {
    iVar2 = 2;
  }
  RVar1 = (RAIL_Status_t)iVar2;
  if (!bVar3) 
  {
    RVar1 = RAIL_STATUS_NO_ERROR;
  }
  return RVar1;
}



RAIL_Status_t RAIL_SetStateTiming(RAIL_StateTiming_t *timings)

{
  validateSetTiming();
  RADIO_RxWarmTimeSet();
  validateSetTiming(&timings->txToRx);
  RADIO_TxToRxTimeSet();
  validateSetTiming(&timings->idleToTx);
  RADIO_TxWarmTimeSet();
  validateSetTiming(&timings->rxToTx);
  RADIO_RxFrameToTxTimeSet();
  return RAIL_STATUS_NO_ERROR;
}



bool RAIL_AddressFilterConfig(RAIL_AddrConfig_t *addrConfig)

{
  byte bVar1;
  undefined uVar2;
  uint8_t *in_r3;
  int iVar3;
  uint8_t local_1c [4];
  uint8_t *local_18;
  undefined4 local_14;
  
  bVar1 = addrConfig->numFields;
  if (bVar1 < 3) 
  {
    local_14 = in_r3;
    memset((RAIL_AddrConfig_t *)local_1c,0,0xc);
    for (iVar3 = 0; iVar3 < (int)(uint)bVar1; iVar3 = iVar3 + 1) 
	{
      (&((RAIL_AddrConfig_t *)local_1c)->numFields)[iVar3] = addrConfig->offsets[iVar3];
      local_1c[iVar3 + 2] = addrConfig->sizes[iVar3];
    }
    local_18 = (uint8_t *)addrConfig->matchTable;
    local_14 = (uint8_t *)CONCAT31(local_14._1_3_,0xff);
    uVar2 = GENERIC_PHY_ConfigureAddressFiltering((RAIL_AddrConfig_t *)local_1c);
  }
  else 
  {
    uVar2 = 0;
  }
  return (bool)uVar2;
}



bool RAIL_AddressFilterByFrameType(uint8_t validFrames)

{
  write_volatile_1(SEQ->REG050._2_1_,validFrames);
  return true;
}



bool RAIL_AddressFilterEnable(void)

{
  int iVar1;
  
  iVar1 = _DAT_21000efc << 0x1b;
  _DAT_21000efc = _DAT_21000efc | 0x10;
  return SUB41((uint)iVar1 >> 0x1f,0);
}



bool RAIL_AddressFilterDisable(void)

{
  int iVar1;
  
  iVar1 = _DAT_21000efc << 0x1b;
  _DAT_21000efc = _DAT_21000efc & 0xffffffef;
  return SUB41((uint)iVar1 >> 0x1f,0);
}



bool RAIL_AddressFilterIsEnabled(void)

{
  return SUB41((uint)(_DAT_21000efc << 0x1b) >> 0x1f,0);
}



void RAIL_AddressFilterReset(void)

{
  GENERIC_PHY_ResetAddressFiltering();
  return;
}



bool RAIL_AddressFilterSetAddress(uint8_t field,uint8_t index,uint8_t *value,bool enable)

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
      if (value != (uint8_t *)0x0) 
	  {
        uVar5 = uVar5 | (uint)value[iVar4] << (uVar3 & 0xff);
      }
      *puVar2 = uVar5;
      puVar2 = puVar2 + 1;
    }
    if (enable != false) 
	{
      GENERIC_PHY_EnableAddress(field,index);
    }
    return true;
  }
  return false;
}



bool RAIL_AddressFilterEnableAddress(uint8_t field,uint8_t index)

{
  uint uVar1;
  
  uVar1 = (uint)field;
  if ((uVar1 < 2) && (index < 4)) 
  {
    *(byte *)((int)&SEQ->REG050 + uVar1) =
         (byte)(1 << (uint)index) | *(byte *)((int)&SEQ->REG050 + uVar1);
    GENERIC_PHY_SetAddressFilteringMatchTable();
    return true;
  }
  return false;
}



bool RAIL_AddressFilterDisableAddress(uint8_t field,uint8_t index)

{
  uint uVar1;
  
  uVar1 = (uint)field;
  if ((uVar1 < 2) && (index < 4)) 
  {
    *(byte *)((int)&SEQ->REG050 + uVar1) =
         *(byte *)((int)&SEQ->REG050 + uVar1) & ~(byte)(1 << (uint)index);
    GENERIC_PHY_SetAddressFilteringMatchTable();
    return true;
  }
  return false;
}



uint16_t RAIL_GetRadioEntropy(uint8_t *buffer,uint16_t bytes)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint32_t uVar4;
  uint __n;
  size_t __n_00;
  uint uVar5;
  uint uStack36;
  
  __n = (uint)bytes;
  uVar2 = (CMU->HFRADIOCLKEN0);
  uStack36 = __n;
  memset(buffer,0,__n);
  if ((((uVar2 | 0xcc) == uVar2) &&
      (uVar2 = (RAC->CTRL), -1 < (int)(uVar2 << 0x1f))) &&
     (uVar4 = RADIOCMU_ClockPrescGet(0x75160), uVar4 == 0)) {
    disableIRQinterrupts();
    if (INT_LockCnt != 0xffffffff) {
      INT_LockCnt = INT_LockCnt + 1;
    }
    uVar3 = (MODEM->CTRL0);
    uVar2 = (FRC->RAWCTRL);
    uVar5 = (MODEM->CTRL0);
    write_volatile_4(MODEM->CTRL0,uVar5 & 0xc7ffffff);
    uVar5 = (MODEM->CTRL0);
    write_volatile_4(MODEM->CTRL0,uVar5 | 0x8000000);
    write_volatile_4(FRC->RAWCTRL,0x24);
    _DAT_43080008 = 1;
    write_volatile_4(FRC->IFC,0x4000);
    write_volatile_4(FRC->CMD,0x1000);
    for (uVar5 = 0; uVar5 < __n; uVar5 = __n_00 + uVar5 & 0xffff) {
      do {
        do {
          uVar1 = (FRC->IF);
        } while (-1 < (int)(uVar1 << 0x11));
        uVar1 = (FRC->STATUS);
      } while (-1 < (int)(uVar1 << 0x17));
      __n_00 = __n - uVar5;
      write_volatile_4(FRC->IFC,0x4000);
      if (3 < (int)__n_00) {
        __n_00 = 4;
      }
      uStack36 = (FRC->RXRAWDATA);
      memcpy(buffer + uVar5,&uStack36,__n_00);
    }
    _DAT_43080008 = 0;
    write_volatile_4(FRC->RAWCTRL,uVar2);
    write_volatile_4(MODEM->CTRL0,uVar3);
    write_volatile_4(FRC->IFC,0x4000);
    if ((INT_LockCnt != 0) && (INT_LockCnt = INT_LockCnt - 1, INT_LockCnt == 0)) {
      enableIRQinterrupts();
    }
  }
  else {
    bytes = 0;
  }
  return bytes;
}


