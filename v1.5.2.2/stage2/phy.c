#include "phy.h"



uint8_t RAIL_RadioConfig(void *radioConfig)

{
  RADIO_Config(radioConfig);
  forceIrCal = 1;
  return 0;
}



uint8_t RAIL_ChannelConfig(RAIL_ChannelConfig_t *config)

{
  RAILInt_TrackChannelConfig(config);
  SYNTH_Config(config->configs->baseFrequency,config->configs->channelSpacing);
  if (SYNTH_Is2p4GHz() == false) SYNTH_DCDCRetimeClkSet(3500000);
  else SYNTH_DCDCRetimeClkSet(7000000);
  if (forceIrCal != 0) 
  {
    forceIrCal = 0;
    RAILINT_CalibrationPend(0x10000);
  }
  return *(uint8_t *)&config->configs->channelNumberStart;
}

void RAIL_DirectModeConfig(bool enable)
/**
 * Enable or disable direct mode for RAIL.
 *
 * @param[in] enable Whether to turn direct mode on or off. At some point this
 *  will include a configuration structure.
 * @warning This API configures fixed pins for tx data in, rx data out, rx clock
 *  out. There should be more control over these pins in the future but they are
 *  currently fixed.
 *
 * In this mode packets will be output and input directly to the radio via GPIO
 * and RAIL packet handling will be ignored. On the EFR32, the DIN pin in TX is
 * EFR32_PC10, which corresponds to EXP_HEADER15/WSTKP12, and the DOUT pin in
 * RX is EFR32_PC11, which corresponds to EXP_HEADER16/WSTKP13.
 */
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
  GENERIC_PHY_DirectModeConfig(&local_18); //ports settings
}




RAIL_Status_t RAIL_DebugFrequencyOverride(uint32_t freq)

{
  SYNTH_Config(freq,0);
  return RAIL_STATUS_NO_ERROR;
}




void RAIL_PacketLengthConfigFrameType(RAIL_FrameType_t *frameType)

{
  CORE_irqState_t irqState;
  uint32_t mask;
  uint32_t i;
  
  if (frameType == NULL) 
  {
    irqState = CORE_EnterCritical();
	SEQ->REG000 &= 0xfffffff8;
    CORE_ExitCritical(irqState);
    SEQ->REG05C = 0;
    SEQ->REG060 = 0;
    return;
  }
  GENERIC_PHY_ResetPacketConfig();
  SEQ->REG05C._0_1_ = frameType->offset;
  SEQ->REG05C._1_1_ = frameType->mask;
  SEQ->REG05C._2_1_ = 0;
  SEQ->REG060 = (uint32_t)frameType->frameLen;
  mask = 0;
  for(i = 0; i < 8; i++)
  {
    if (frameType->isValid[i] != 0) mask = mask | 1 << (i & 0xff) & 0xffU;
  }
  SEQ->REG05C._3_1_ = (uint8_t)mask;
  mask = (uint32_t)frameType->mask;
  if (mask != 0) 
  {
    while (!(mask & 0x01)) //(-1 < (int)(uVar3 << 0x1f)) 
	{
      mask >>= 1;
      SEQ->REG05C._2_1_ += 1;
    }
  }
  FRC->WCNTCMP0 = frameType->offset + 1;
  irqState = CORE_EnterCritical();
  SEQ->REG000 |= 7;
  CORE_ExitCritical(irqState);
}



void RAIL_SetCcaThreshold(void)

{
  RFHAL_SetCcaThreshold();
}



int16_t RAIL_RxGetRSSI(void)

{
  int16_t rssi;
  CORE_irqState_t irqState;
  uint32_t state_before;
  uint32_t state_after;
  
  do 
  {
    irqState = CORE_EnterCritical();
    state_before = (RAC->STATUS & RAC_STATUS_STATE_Msk) >> RAC_STATUS_STATE_Pos;
    rssi = (int16_t)(AGC->RSSI >> 6);
    state_after = (RAC->STATUS & RAC_STATUS_STATE_Msk) >> RAC_STATUS_STATE_Pos;
    CORE_ExitCritical(irqState);
    if (rssi != -0x200) 
	{
      if ((state_after == 2 || state_after == 3) && (state_before == 2 || state_before == 3)) return rssi;
      return -0x200;
    }
  } while ((state_after == 2 || state_after == 3) && (state_before == 2 || state_before == 3));
  return -0x200;
}




int16_t RAIL_PollAverageRSSI(uint32_t averageTimeUs)

{
  int16_t rssi;
  int32_t sum;
  uint32_t begin;
  uint32_t count;
  uint64_t avgtime;
  
  if (averageTimeUs == 0) return RADIO_GetRSSI();
  begin = PROTIMER_GetTime();
  avgtime = PROTIMER_UsToPrecntOverflow(averageTimeUs);
  while(1) 
  {
    if ((uint32_t)avgtime <= PROTIMER_ElapsedTime(begin,PROTIMER_GetTime())) break;
    rssi = RADIO_GetRSSI();
    if (rssi != -0x200) 
	{
      sum += rssi;
      count ++;
    }
  }
  if (count == 0) return = -0x200;
  else return (uint16_t)(sum/count);
}



RAIL_Status_t RAIL_StartAverageRSSI(uint8_t channel,uint32_t averagingTimeUs)

{
  isRssiReady = 0;
  saveRssiPeriod = AGC->CTRL1;
  if (RADIO_CalcRssiPeriod(averagingTimeUs) == RAIL_STATUS_NO_ERROR) 
  {
	if(MODEM->CTRL0 & MODEM_CTRL0_DETDIS_Msk) saveFrameDetDisable = 1; 
    BUS_RegMaskedSet(&MODEM->CTRL0,MODEM_CTRL0_DETDIS_Msk);
    if (RAIL_RxStart(channel) == 0) 
	{
      _enabledCallbacks = _enabledCallbacks | 0x4000000;
      GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
	  return RAIL_STATUS_NO_ERROR;
    }
    else return RAIL_STATUS_INVALID_STATE;
  }
  return RAIL_STATUS_INVALID_PARAMETER;
}



int16_t RAIL_GetAverageRSSI(void)

{
  return currentRssiAverage;
}


bool RAIL_AverageRSSIReady(void)

{
  return isRssiReady;
}

void RAIL_SetTune(uint32_t tune)

{
  CMU_ClockSelectSet(cmuClock_HF,cmuSelect_HFRCO);
  CMU_OscillatorEnable(cmuOsc_HFXO,false,false);
  BUS_RegMaskedClear(&CMU->HFXOSTEADYSTATECTRL,_CMU_HFXOSTEADYSTATECTRL_CTUNE_MASK);
  BUS_RegMaskedSet(&CMU->HFXOSTEADYSTATECTRL,(tune & 0x1ff) << _CMU_HFXOSTEADYSTATECTRL_CTUNE_SHIFT);
  CMU_OscillatorEnable(cmuOsc_HFXO,true,true);
  CMU_ClockSelectSet(cmuClock_HF,cmuSelect_HFXO);
}




uint32_t RAIL_GetTune(void)

{
  return (CMU->HFXOSTEADYSTATECTRL & _CMU_HFXOSTEADYSTATECTRL_CTUNE_MASK) >> _CMU_HFXOSTEADYSTATECTRL_CTUNE_SHIFT;
}




uint32_t RAIL_GetTime(void)

{
  return (uint32_t)PROTIMER_PrecntOverflowToUs(PROTIMER_GetTime());
}


RAIL_Status_t RAIL_SetTime(uint32_t time)

{
  if (PROTIMER_SetTime(time) == false) return RAIL_STATUS_INVALID_STATE;
  else return RAIL_STATUS_NO_ERROR;
}


uint32_t RAILInt_CompensateForDelay(uint32_t rxdelay,uint32_t txdelay) //chain delays

{
  rxchaindelay = rxdelay;
  txchaindelay = txdelay;
  TIMING_RecalculateAll();
  return 0;
}



RAIL_Status_t RAIL_SetStateTiming(RAIL_StateTiming_t *timings)

{
  timings->idleToRx = TIMING_RxWarmTimeSet(timings->idleToRx);
  timings->txToRx = TIMING_TxToRxTimeSet(timings->txToRx);
  timings->idleToTx = TIMING_TxWarmTimeSet(timings->idleToTx);
  timings->rxToTx = TIMING_RxFrameToTxTimeSet(timings->rxToTx);
  return RAIL_STATUS_NO_ERROR;
}


bool RAIL_AddressFilterConfig(RAIL_AddrConfig_t *addrConfig)

{
  byte bVar1;
  undefined uVar2;
  uint8_t *in_r3;
  uint32_t i; // iVar3;
  uint8_t local_1c [4];
  uint8_t *local_18;
  undefined4 local_14;
  
  bVar1 = addrConfig->numFields;
  if (addrConfig->numFields < 3) 
  {
    local_14 = in_r3;
    memset((RAIL_AddrConfig_t *)local_1c,0,0xc);
    for (i = 0; i < addrConfig->numFields; i++) 
	{
      (&((RAIL_AddrConfig_t *)local_1c)->numFields)[i] = addrConfig->offsets[i];
      local_1c[i + 2] = addrConfig->sizes[i];
    }
    local_18 = (uint8_t *)addrConfig->matchTable;
    local_14 = (uint8_t *)CONCAT31(local_14._1_3_,0xff);
    return GENERIC_PHY_ConfigureAddressFiltering((RAIL_AddrConfig_t *)local_1c);
  }
  else return false;
}



bool RAIL_AddressFilterByFrameType(uint8_t validFrames)

{
  SEQ->REG058._2_1_ = validFrames;
  return true;
}



bool RAIL_AddressFilterEnable(void)

{
  uint32_t tmp;
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  tmp = SEQ->REG000;
  SEQ->REG000 |= 0x10;
  CORE_ExitCritical(irqState);
  return tmp & 0x10;
}



bool RAIL_AddressFilterDisable(void)

{
  uint32_t tmp;
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  tmp = SEQ->REG000;
  SEQ->REG000 &= 0xffffffef;
  CORE_ExitCritical(irqState);
  return tmp & 0x10;
}



bool RAIL_AddressFilterIsEnabled(void)

{
  return SEQ->REG000 & 0x10;
}



void RAIL_AddressFilterReset(void)

{
  memset(&SEQ->REG010,0,0x4c);
  addressFilterMatchTable = 0;
}



bool RAIL_AddressFilterSetAddress(uint8_t field,uint8_t index,uint8_t *value,bool enable)

{
  if ((enable != false) && (GENERIC_PHY_SetAddressData(field,field,index,0,*(undefined *)((int)&SEQ->REG054 + field + 2),value) != 0)) return  GENERIC_PHY_EnableAddress(field,index);
  else return false;
}


bool RAIL_AddressFilterEnableAddress(uint8_t field,uint8_t index)

{
  uint uVar1;
  
  uVar1 = (uint32_t)field;
  if ((uVar1 < 2) && (index < 4)) 
  {
    *(byte *)((int)&SEQ->REG058 + uVar1) = (byte)(1 << (uint)index) | *(byte *)((int)&SEQ->REG058 + uVar1);
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
    *(byte *)((int)&SEQ->REG058 + uVar1) = *(byte *)((int)&SEQ->REG058 + uVar1) & ~(byte)(1 << (uint)index);
    GENERIC_PHY_SetAddressFilteringMatchTable();
    return true;
  }
  return false;
}


uint16_t RAIL_GetRadioEntropy(uint8_t *buffer,uint16_t bytes)

{
  uint32_t frc_save;
  uint32_t modem_save;
  uint uVar4;
  CORE_irqState_t irqState;
  uint __n;
  size_t __n_00;
  uint uStack36;
  
  __n = (uint32_t)bytes;
  uVar4 = (CMU->HFRADIOCLKEN0);
  uStack36 = __n;
  memset(buffer,0,__n);
  
  if (((CMU->HFRADIOCLKEN0 | 0xcc) == CMU->HFRADIOCLKEN0) && (RAC->CTRL & 0x01) && (RADIOCMU_ClockPrescGet(0x75160) == 0)) 
  {
    irqState = CORE_EnterCritical();
    modem_save = MODEM->CTRL0;
    frc_save = FRC->RAWCTRL;
    BUS_RegMaskedClear(&MODEM->CTRL0,MODEM_CTRL0_DEMODRAWDATASEL_Msk); //0x38000000);
    BUS_RegMaskedSet(&MODEM->CTRL0,0x8000000);
    FRC->RAWCTRL = FRC_RAWCTRL_RXRAWRANDOM_Msk | (1 << FRC_RAWCTRL_RXRAWMODE_Pos); //0x24;
    BUS_RegMaskedSet(&RAC->RXENSRCEN,4);
    FRC->IFC = FRC_IFC_RXRAWEVENT_Msk; //0x4000;
    FRC->CMD = FRC_CMD_RXRAWUNBLOCK_Msk; //0x1000;
    for (; uVar4 < __n; uVar4 = uVar4 + __n_00 & 0xffff) 
	{
      do 
	  {
        while (-1 < (int)(FRC->IF << 0x11));
      } while (-1 < (int)(FRC->STATUS << 0x17));
      __n_00 = __n - uVar4;
      FRC->IFC = 0x4000;
      if (3 < (int)__n_00) __n_00 = 4;
      uStack36 = FRC->RXRAWDATA;
      memcpy(buffer + uVar4,&uStack36,__n_00);
    }
    BUS_RegMaskedClear(&RAC->RXENSRCEN,4);
    FRC->RAWCTRL = frc_save;
    MODEM->CTRL0 = modem_save;
    FRC->IFC = FRC_IFC_RXRAWEVENT_Msk; //0x4000;
    CORE_ExitCritical(irqState);
  }
  else bytes = 0;
  return bytes;
}


