#include "phy.h"



uint16_t validateSetTiming(uint16_t *param_1)

{
  if (*param_1 < 60) *param_1 = 60;
  if (*param_1 > 13000) *param_1 = 13000;
  return *param_1;
}



uint8_t RAIL_RadioConfig(void *radioConfig)

{
  RADIO_Config(radioConfig);
  forceIrCal = 1;
  return 0;
}



uint8_t RAIL_ChannelConfig(RAIL_ChannelConfig_t *config)

{
  RAILInt_TrackChannelConfig((uint32_t)config);
  SYNTH_Config(config->configs->baseFrequency,config->configs->channelSpacing);
  if (SYNTH_Is2p4GHz() == false) SYNTH_DCDCRetimeClkSet(3500000);
  else SYNTH_DCDCRetimeClkSet(7000000);
  
  if (forceIrCal != 0) 
  {
    forceIrCal = 0;
    RAIL_RfHalCalibrationPend(0x10000);
  }
  return *(uint8_t *)&config->configs->channelNumberStart;
}



void RAIL_DirectModeConfig(bool enable)

{
  if (enable == false) GENERIC_PHY_DirectModeConfig(&directModeDisableConfig);
  else GENERIC_PHY_DirectModeConfig(&directModeEnableConfig);
}



uint8_t RAIL_TxToneStart(uint8_t channel)

{
  if ((char *)RAILInt_SetChannelConfig() != NULL) 
  {
    if (RAIL_DebugModeGet() != 1) GENERIC_PHY_ChannelSet(channel - *pcVar1);
    RFTEST_SaveRadioConfiguration();
    RFTEST_StartCwTx();
    return 0;
  }
  return 1;
}



uint8_t RAIL_TxToneStop(void)

{
  RFTEST_StopTx();
  RFTEST_RestoreRadioConfiguration();
  return 0;
}


uint8_t RAIL_TxStreamStart(uint8_t channel,int mode)

{
  char *pcVar1;
  uint32_t uVar2;
  
  if ((mode == 1) && (pcVar1 = (char *)RAILInt_SetChannelConfig(), pcVar1 != NULL)) 
  {
    RFTEST_SaveRadioConfiguration();
    RFTEST_StartStreamTx();
    if (RAIL_DebugModeGet() != 1) GENERIC_PHY_ChannelSet(channel - *pcVar1);
    return 0;
  }
  return 1;
}



uint8_t RAIL_TxStreamStop(void)

{
  RFTEST_StopTx();
  RFTEST_RestoreRadioConfiguration();
  return 0;
}



int32_t RAIL_TxPowerSet(int32_t powerLevel)

{
  return PA_OutputPowerSet(powerLevel);
}



int32_t RAIL_TxPowerGet(void)

{
  return PA_OutputPowerGet();
}



RAIL_Status_t RAIL_DebugFrequencyOverride(uint32_t freq)

{
  SYNTH_Config(freq,0);
  return RAIL_STATUS_NO_ERROR;
}



void RAIL_PacketLengthConfigFrameType(RAIL_FrameType_t *frameType)

{
	GENERIC_PHY_ConfigureFrameType(frameType);
}



int16_t RAIL_RxGetRSSI(void)
{
	return RADIO_GetRSSI();
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
  return (CMU->HFXOSTEADYSTATECTRL << 0xc) >> 0x17;
}



uint32_t RAIL_GetTime(void)

{
  return PROTIMER_PrecntOverflowToUs(PROTIMER_GetTime());
}



RAIL_Status_t RAIL_SetTime(uint32_t time)

{
  if (PROTIMER_SetTime() == false) return RAIL_STATUS_INVALID_STATE;
  else return RAIL_STATUS_NO_ERROR;
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
   uint8_t *in_r3;
  int iVar3;
  uint8_t local_1c [4];
  uint8_t *local_18;
  undefined4 local_14;
  
  if (addrConfig->numFields < 3) 
  {
    local_14 = in_r3;
    memset((RAIL_AddrConfig_t *)local_1c,0,0xc);
    for (iVar3 = 0; iVar3 < addrConfig->numFields; iVar3 ++) 
	{
      (&((RAIL_AddrConfig_t *)local_1c)->numFields)[iVar3] = addrConfig->offsets[iVar3];
      local_1c[iVar3 + 2] = addrConfig->sizes[iVar3];
    }
    local_18 = (uint8_t *)addrConfig->matchTable;
    local_14 = (uint8_t *)CONCAT31(local_14._1_3_,0xff);
    return GENERIC_PHY_ConfigureAddressFiltering((RAIL_AddrConfig_t *)local_1c);
  }
  else return false;
}



bool RAIL_AddressFilterByFrameType(uint8_t validFrames)

{
  SEQ->REG050._2_1_ = validFrames;
  return true;
}



bool RAIL_AddressFilterEnable(void)

{
  return GENERIC_PHY_EnableAddressFiltering();
}



bool RAIL_AddressFilterDisable(void)

{
  return GENERIC_PHY_DisableAddressFiltering();
}



bool RAIL_AddressFilterIsEnabled(void)

{
  return GENERIC_PHY_IsEnabledAddressFiltering();
}



void RAIL_AddressFilterReset(void)

{
  GENERIC_PHY_ResetAddressFiltering();
}



bool RAIL_AddressFilterSetAddress(uint8_t field,uint8_t index,uint8_t *value,bool enable)

{
	return GENERIC_PHY_SetAddress(field,index,value,enable);
}



bool RAIL_AddressFilterEnableAddress(uint8_t field,uint8_t index)

{
	return GENERIC_PHY_EnableAddress(field,index);
}



bool RAIL_AddressFilterDisableAddress(uint8_t field,uint8_t index)

{
  return GENERIC_PHY_DisableAddress(field,index);
}



uint16_t RAIL_GetRadioEntropy(uint8_t *buffer,uint16_t bytes)

{
  return RFRAND_GetRadioEntropy(buffer,bytes);
}


