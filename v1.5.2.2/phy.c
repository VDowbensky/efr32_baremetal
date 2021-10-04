#include "phy.h"



uint8_t RAIL_RadioConfig(void *radioConfig)

{
  RADIO_Config(radioConfig);
  forceIrCal = 1;
  return '\0';
}



uint8_t RAIL_ChannelConfig(RAIL_ChannelConfig_t *config)

{
  int iVar1;
  undefined4 uVar2;
  
  RAILInt_TrackChannelConfig(config);
  SYNTH_Config(config->configs->baseFrequency,config->configs->channelSpacing);
  iVar1 = SYNTH_Is2p4GHz();
  if (iVar1 == 0) {
    uVar2 = 3500000;
  }
  else {
    uVar2 = 7000000;
  }
  SYNTH_DCDCRetimeClkSet(uVar2);
  if (forceIrCal != '\0') {
    forceIrCal = '\0';
    RAILINT_CalibrationPend(0x10000);
  }
  return *(uint8_t *)&config->configs->channelNumberStart;
}




void RAIL_DirectModeConfig(bool enable)

{
  uint in_r3;
  uint local_18;
  undefined4 local_14;
  undefined4 local_10;
  uint local_c;
  
  local_18 = (uint)CONCAT11(enable,enable);
  local_14 = 0xb020e00;
  local_10 = 0xe09020e;
  local_c = in_r3 & 0xffff0000 | 0xa02;
  GENERIC_PHY_DirectModeConfig(&local_18);
  return;
}




RAIL_Status_t RAIL_DebugFrequencyOverride(uint32_t freq)

{
  SYNTH_Config(freq,0);
  return RAIL_STATUS_NO_ERROR;
}




void RAIL_PacketLengthConfigFrameType(RAIL_FrameType_t *frameType)

{
  char cVar1;
  CORE_irqState_t CVar2;
  uint uVar3;
  uint uVar4;
  
  if (frameType == (RAIL_FrameType_t *)0x0) {
    CVar2 = CORE_EnterCritical();
    uVar3 = (SEQ->REG000);
    write_volatile_4(SEQ->REG000,uVar3 & 0xfffffff8);
    CORE_ExitCritical(CVar2);
    write_volatile_4(SEQ->REG05C,0);
    write_volatile_4(SEQ->REG060,0);
    return;
  }
  GENERIC_PHY_ResetPacketConfig();
  write_volatile_1(SEQ->REG05C._0_1_,frameType->offset);
  write_volatile_1(SEQ->REG05C._1_1_,frameType->mask);
  uVar4 = 0;
  write_volatile_1(SEQ->REG05C._2_1_,0);
  write_volatile_4(SEQ->REG060,(uint)frameType->frameLen);
  uVar3 = 0;
  do {
    if (frameType->isValid[uVar4] != '\0') {
      uVar3 = uVar3 | 1 << (uVar4 & 0xff) & 0xffU;
    }
    uVar4 = uVar4 + 1;
  } while (uVar4 != 8);
  write_volatile_1(SEQ->REG05C._3_1_,(char)uVar3);
  uVar3 = (uint)frameType->mask;
  if (uVar3 != 0) {
    while (-1 < (int)(uVar3 << 0x1f)) {
      cVar1 = read_volatile_1(SEQ->REG05C._2_1_);
      uVar3 = uVar3 >> 1;
      write_volatile_1(SEQ->REG05C._2_1_,cVar1 + '\x01');
    }
  }
  write_volatile_4(FRC->WCNTCMP0,frameType->offset + 1);
  CVar2 = CORE_EnterCritical();
  uVar3 = (SEQ->REG000);
  write_volatile_4(SEQ->REG000,uVar3 | 7);
  CORE_ExitCritical(CVar2);
  return;
}



void RAIL_SetCcaThreshold(void)

{
  RFHAL_SetCcaThreshold();
  return;
}



int16_t RAIL_RxGetRSSI(void)

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




int16_t RAIL_PollAverageRSSI(uint32_t averageTimeUs)

{
  int16_t iVar1;
  uint32_t begin;
  uint32_t uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  bool bVar7;
  uint64_t uVar8;
  
  if (averageTimeUs == 0) {
    iVar1 = RADIO_GetRSSI();
    return iVar1;
  }
  begin = PROTIMER_GetTime();
  uVar8 = PROTIMER_UsToPrecntOverflow(averageTimeUs);
  iVar4 = 0;
  uVar5 = 0;
  iVar6 = 0;
  while( true ) {
    uVar2 = PROTIMER_GetTime();
    uVar2 = PROTIMER_ElapsedTime(begin,uVar2);
    if ((uint)uVar8 <= uVar2) break;
    iVar1 = RADIO_GetRSSI();
    if (iVar1 != -0x200) {
      uVar3 = SEXT24(iVar1);
      bVar7 = CARRY4(uVar5,uVar3);
      uVar5 = uVar5 + uVar3;
      iVar6 = iVar6 + ((int)uVar3 >> 0x1f) + (uint)bVar7;
      iVar4 = iVar4 + 1;
    }
  }
  if (iVar4 == 0) {
    iVar1 = -0x200;
  }
  else {
    iVar1 = __aeabi_ldivmod(uVar5,iVar6,iVar4,iVar4 >> 0x1f);
  }
  return iVar1;
}



RAIL_Status_t RAIL_StartAverageRSSI(uint8_t channel,uint32_t averagingTimeUs)

{
  RAIL_Status_t RVar1;
  uint8_t uVar2;
  int iVar3;
  
  isRssiReady = 0;
  saveRssiPeriod = (AGC->CTRL1);
  RVar1 = RADIO_CalcRssiPeriod(averagingTimeUs);
  if (RVar1 == RAIL_STATUS_NO_ERROR) {
    iVar3 = _DAT_430c0354;
    if (_DAT_430c0354 != 0) {
      iVar3 = 1;
    }
    saveFrameDetDisable = (undefined)iVar3;
    BUS_RegMaskedSet(&MODEM->CTRL0,0x200000);
    uVar2 = RAIL_RxStart(channel);
    if (uVar2 == '\0') {
      _enabledCallbacks = _enabledCallbacks | 0x4000000;
      GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
    }
    else {
      RVar1 = RAIL_STATUS_INVALID_STATE;
    }
  }
  else {
    RVar1 = RAIL_STATUS_INVALID_PARAMETER;
  }
  return RVar1;
}



int16_t RAIL_GetAverageRSSI(void)

{
  return currentRssiAverage;
}




void RAIL_AverageRSSIReady(void)

{
  RFHAL_AverageRSSIReady();
  return;
}



void RAIL_SetTune(uint32_t tune)

{
  CMU_ClockSelectSet(cmuClock_HF,cmuSelect_HFRCO);
  CMU_OscillatorEnable(cmuOsc_HFXO,false,false);
  BUS_RegMaskedClear(&CMU->HFXOSTEADYSTATECTRL,0xff800);
  BUS_RegMaskedSet(&CMU->HFXOSTEADYSTATECTRL,(tune & 0x1ff) << 0xb);
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
  uint32_t cnt;
  uint64_t uVar1;
  
  cnt = PROTIMER_GetTime();
  uVar1 = PROTIMER_PrecntOverflowToUs(cnt);
  return (uint32_t)uVar1;
}


RAIL_Status_t RAIL_SetTime(uint32_t time)

{
  bool bVar1;
  RAIL_Status_t RVar2;
  
  bVar1 = PROTIMER_SetTime(time);
  if (bVar1 == false) {
    RVar2 = RAIL_STATUS_INVALID_STATE;
  }
  else {
    RVar2 = RAIL_STATUS_NO_ERROR;
  }
  return RVar2;
}


uint32_t RAILInt_CompensateForDelay(uint32_t param_1,uint32_t param_2)

{
  timings = param_1;
  DAT_20002ddc = param_2;
  TIMING_RecalculateAll();
  return 0;
}



RAIL_Status_t RAIL_SetStateTiming(RAIL_StateTiming_t *timings)

{
  uint16_t uVar1;
  
  uVar1 = TIMING_RxWarmTimeSet(timings->idleToRx);
  timings->idleToRx = uVar1;
  uVar1 = TIMING_TxToRxTimeSet(timings->txToRx);
  timings->txToRx = uVar1;
  uVar1 = TIMING_TxWarmTimeSet(timings->idleToTx);
  timings->idleToTx = uVar1;
  uVar1 = TIMING_RxFrameToTxTimeSet(timings->rxToTx);
  timings->rxToTx = uVar1;
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
  if (bVar1 < 3) {
    local_14 = in_r3;
    memset((RAIL_AddrConfig_t *)local_1c,0,0xc);
    for (iVar3 = 0; iVar3 < (int)(uint)bVar1; iVar3 = iVar3 + 1) {
      (&((RAIL_AddrConfig_t *)local_1c)->numFields)[iVar3] = addrConfig->offsets[iVar3];
      local_1c[iVar3 + 2] = addrConfig->sizes[iVar3];
    }
    local_18 = (uint8_t *)addrConfig->matchTable;
    local_14 = (uint8_t *)CONCAT31(local_14._1_3_,0xff);
    uVar2 = GENERIC_PHY_ConfigureAddressFiltering((RAIL_AddrConfig_t *)local_1c);
  }
  else {
    uVar2 = 0;
  }
  return (bool)uVar2;
}



bool RAIL_AddressFilterByFrameType(uint8_t validFrames)

{
  write_volatile_1(SEQ->REG058._2_1_,validFrames);
  return true;
}



bool RAIL_AddressFilterEnable(void)

{
  uint uVar1;
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  uVar1 = (SEQ->REG000);
  write_volatile_4(SEQ->REG000,uVar1 | 0x10);
  CORE_ExitCritical(irqState);
  return SUB41((uVar1 << 0x1b) >> 0x1f,0);
}



bool RAIL_AddressFilterDisable(void)

{
  uint uVar1;
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  uVar1 = (SEQ->REG000);
  write_volatile_4(SEQ->REG000,uVar1 & 0xffffffef);
  CORE_ExitCritical(irqState);
  return SUB41((uVar1 << 0x1b) >> 0x1f,0);
}



bool RAIL_AddressFilterIsEnabled(void)

{
  uint uVar1;
  
  uVar1 = (SEQ->REG000);
  return SUB41((uVar1 << 0x1b) >> 0x1f,0);
}



void RAIL_AddressFilterReset(void)

{
  memset(&SEQ->REG010,0,0x4c);
  addressFilterMatchTable = 0;
  return;
}



bool RAIL_AddressFilterSetAddress(uint8_t field,uint8_t index,uint8_t *value,bool enable)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = (uint)field;
  iVar3 = GENERIC_PHY_SetAddressData
                    (uVar2,uVar2,index,0,*(undefined *)((int)&SEQ->REG054 + uVar2 + 2),
                     value);
  if ((enable != false) && (iVar3 != 0)) {
    bVar1 = GENERIC_PHY_EnableAddress(field,index);
    return bVar1;
  }
  return SUB41(iVar3,0);
}


bool RAIL_AddressFilterEnableAddress(uint8_t field,uint8_t index)

{
  uint uVar1;
  
  uVar1 = (uint)field;
  if ((uVar1 < 2) && (index < 4)) {
    *(byte *)((int)&SEQ->REG058 + uVar1) =
         (byte)(1 << (uint)index) | *(byte *)((int)&SEQ->REG058 + uVar1);
    GENERIC_PHY_SetAddressFilteringMatchTable();
    return true;
  }
  return false;
}



bool RAIL_AddressFilterDisableAddress(uint8_t field,uint8_t index)

{
  uint uVar1;
  
  uVar1 = (uint)field;
  if ((uVar1 < 2) && (index < 4)) {
    *(byte *)((int)&SEQ->REG058 + uVar1) =
         *(byte *)((int)&SEQ->REG058 + uVar1) & ~(byte)(1 << (uint)index);
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
  uint uVar4;
  CORE_irqState_t irqState;
  uint __n;
  size_t __n_00;
  uint uStack36;
  
  __n = (uint)bytes;
  uVar4 = (CMU->HFRADIOCLKEN0);
  uStack36 = __n;
  memset(buffer,0,__n);
  if ((((uVar4 | 0xcc) == uVar4) &&
      (uVar4 = (RAC->CTRL), -1 < (int)(uVar4 << 0x1f))) &&
     (uVar4 = RADIOCMU_ClockPrescGet(0x75160), uVar4 == 0)) {
    irqState = CORE_EnterCritical();
    uVar3 = (MODEM->CTRL0);
    uVar2 = (FRC->RAWCTRL);
    BUS_RegMaskedClear(&MODEM->CTRL0,0x38000000);
    BUS_RegMaskedSet(&MODEM->CTRL0,0x8000000);
    write_volatile_4(FRC->RAWCTRL,0x24);
    BUS_RegMaskedSet(&RAC->RXENSRCEN,4);
    write_volatile_4(FRC->IFC,0x4000);
    write_volatile_4(FRC->CMD,0x1000);
    for (; uVar4 < __n; uVar4 = uVar4 + __n_00 & 0xffff) {
      do {
        do {
          uVar1 = (FRC->IF);
        } while (-1 < (int)(uVar1 << 0x11));
        uVar1 = (FRC->STATUS);
      } while (-1 < (int)(uVar1 << 0x17));
      __n_00 = __n - uVar4;
      write_volatile_4(FRC->IFC,0x4000);
      if (3 < (int)__n_00) {
        __n_00 = 4;
      }
      uStack36 = (FRC->RXRAWDATA);
      memcpy(buffer + uVar4,&uStack36,__n_00);
    }
    BUS_RegMaskedClear(&RAC->RXENSRCEN,4);
    write_volatile_4(FRC->RAWCTRL,uVar2);
    write_volatile_4(MODEM->CTRL0,uVar3);
    write_volatile_4(FRC->IFC,0x4000);
    CORE_ExitCritical(irqState);
  }
  else {
    bytes = 0;
  }
  return bytes;
}


