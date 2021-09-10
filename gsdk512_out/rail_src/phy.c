#include "phy.h"

bool forceIrCal;

uint8_t RAIL_RadioConfig(undefined *radioConfig)

{
  RADIO_Config(*radioConfig);
  forceIrCal = true;
  return 0;
}

RAIL_Status_t RAIL_DebugFrequencyOverride(uint32_t freq)

{
  SYNTH_Config(freq,0);
  return RAIL_STATUS_NO_ERROR;
}



void RAIL_PacketLengthConfigFrameType(const RAIL_FrameType_t *frameType)
{
  GENERIC_PHY_ConfigureFrameType(*frameType);
}



RAIL_Status_t RAIL_SetCcaThreshold(int8_t ccaThresholdDbm)

{
  return RFHAL_SetCcaThreshold(ccaThresholdDbm);
}



int16_t RAIL_RxGetRSSI(void)

{
  return RADIO_GetRSSI();
}



int16_t RAIL_PollAverageRSSI(uint32_t averageTimeUs)

{
  return RFHAL_PollAverageRSSI(averageTimeUs);
}



void RAIL_StartAverageRSSI(uint8_t channel,uint32_t averagingTimeUs)

{
  RFHAL_StartAverageRSSI(channel,averagingTimeUs);
}



int16_t RAIL_GetAverageRSSI(void)

{
  return RFHAL_GetAverageRSSI();
}



bool RAIL_AverageRSSIReady(void)

{
  return RFHAL_AverageRSSIReady();
}



void RAIL_SetTune(uint32_t tune)

{
  CMU_ClockSelectSet(0x11,5);
  CMU_OscillatorEnable(2,0,0);
  BUS_RegMaskedClear(&CMU->HFXOSTEADYSTATECTRL,_CMU_HFXOSTEADYSTATECTRL_CTUNE_MASK);
  BUS_RegMaskedSet(&CMU->HFXOSTEADYSTATECTRL,(tune & 0x1ff) << _CMU_HFXOSTEADYSTATECTRL_CTUNE_SHIFT);
  CMU_OscillatorEnable(2,1,1);
  CMU_ClockSelectSet(0x11,4);
}



uint32_t RAIL_GetTune(void)

{
  return (CMU->HFXOSTEADYSTATECTRL & _CMU_HFXOSTEADYSTATECTRL_CTUNE_MASK) >> _CMU_HFXOSTEADYSTATECTRL_CTUNE_SHIFT;
}



uint32_t RAIL_GetTime(void)

{
  return PROTIMER_PrecntOverflowToUs(PROTIMER_GetTime());
}



RAIL_Status_t RAIL_SetTime(uint32_t time)

{
  if (PROTIMER_SetTime(time) == 0) return RAIL_STATUS_INVALID_STATE;
  else return RAIL_STATUS_NO_ERROR;
}



void RAILInt_CompensateForDelay(void)

{
  TIMING_SetChainDelays();
}


bool RAIL_AddressFilterByFrameType(uint8_t validFrames)

{
  //SEQ->REG058._2_1_ = validFrames;
  SEQ->REG058 |= validFrames << 16;
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



bool RAIL_AddressFilterSetAddress(uint8_t field,uint8_t index,uint8_t _value,bool enable)

{
  return GENERIC_PHY_SetAddress(field,index,_value,enable);
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
  return RFRAND_GetRadioEntropy(*buffer,bytes);
}

void RAIL_DirectModeConfig(bool enable)

{
  uint in_r3;
  uint local_18;
  undefined4 local_14;
  undefined4 local_10;
  uint local_c;
  
  local_18 = (uint32_t)CONCAT11(enable,enable);
  local_14 = 0xb020e00;
  local_10 = 0xe09020e;
  local_c = in_r3 & 0xffff0000 | 0xa02;
  GENERIC_PHY_DirectModeConfig(&local_18);
}


uint8_t RAIL_ChannelConfig(const RAIL_ChannelConfig_t * config)

{
  RAILInt_TrackChannelConfig();
  SYNTH_Config(config->configs->baseFrequency, config->configs->channelSpacing);
  if (SYNTH_Is2p4GHz() == false) SYNTH_DCDCRetimeClkSet(3500000);
  else SYNTH_DCDCRetimeClkSet(7000000); 
  if (forceIrCal == true) 
  {
    forceIrCal = false;
    RAILINT_CalibrationPend(0x10000);
  }
  return config->configs->channelNumberStart;
}

RAIL_Status_t RAIL_SetStateTiming(RAIL_StateTiming_t *timings)

{
  timings->idleToRx = TIMING_RxWarmTimeSet(timings->idleToRx);
  timings->txToRx = TIMING_TxToRxTimeSet(timings->txToRx);
  timings->idleToTx = TIMING_TxWarmTimeSet(timings->idleToTx);
  timings->rxToTx = TIMING_RxFrameToTxTimeSet(timings->rxToTx);
  return RAIL_STATUS_NO_ERROR;
}

//typedef struct RAIL_AddrConfig {
  /** The number of fields to configure. You cannot have more than 2. */
//  uint8_t numFields;
//  uint8_t *offsets;
//  uint8_t *sizes;
//  uint32_t matchTable;
//} RAIL_AddrConfig_t;

//bool RAIL_AddressFilterConfig (byte *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
bool RAIL_AddressFilterConfig(RAIL_AddrConfig_t *addrConfig)

{
/*   uint8_t numfields;
  int i;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  numfields = addrConfig->numFields;
  if (numfields < 3)
  {
    
	//local_1c = param_2;
	local_1c = addrConfig->offsets;
    //local_18 = param_3;
	local_18 = addrConfig->sizes;
    //local_14 = param_4;
	local_14 = addrConfig->matchTable;
	
    memset(&local_1c,0,0xc);
    for (i = 0; i < (int)(uint)numfields; i++) 
	{
      *(undefined *)((int)&local_1c + i) = *(undefined *)(*(addrConfig->offsets) + i);
      *(undefined *)((int)&local_1c + i + 2) = *(undefined *)(*(int *)(addrConfig->sizes) + i);
    }
    local_18 = *(undefined4 *)(addrconfig->matchtable);
    local_14 = CONCAT31(local_14._1_3_,0xff);
    return GENERIC_PHY_ConfigureAddressFiltering(&local_1c);
  }
  else return false;
   */
  if(addrConfig->numFields < 3) return GENERIC_PHY_ConfigureAddressFiltering(&addrConfig);
  else return false;
  
}



