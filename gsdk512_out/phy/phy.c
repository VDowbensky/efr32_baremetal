#include "phy.h"

bool forceIrCal;

uint8_t RAIL_RadioConfig(undefined *radioConfig)

{
  RADIO_Config(*radioConfig);
  forceIrCal = 1;
  return 0;
}

RAIL_Status_t RAIL_DebugFrequencyOverride(uint32_t freq)

{
  SYNTH_Config(freq,0);
  return RAIL_STATUS_NO_ERROR;
}



void RAIL_PacketLengthConfigFrameType(const RAIL_FrameType_t *frameType);
{
  GENERIC_PHY_ConfigureFrameType(*frameType);
}



RAIL_Status_t RAIL_SetCcaThreshold(int8_t ccaThresholdDbm);

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
  BUS_RegMaskedClear(&CMU->HFXOSTEADYSTATECTRL,0xff800);
  BUS_RegMaskedSet(&CMU->HFXOSTEADYSTATECTRL,(tune & 0x1ff) << 0xb);
  CMU_OscillatorEnable(2,1,1);
  CMU_ClockSelectSet(0x11,4);
}



uint32_t RAIL_GetTune(void)

{
  return (CMU->HFXOSTEADYSTATECTRL << 0xc) >> 0x17;
}



uint32_t RAIL_GetTime(void)

{
  return PROTIMER_PrecntOverflowToUs(PROTIMER_GetTime());
}



RAIL_Status_t RAIL_SetTime(uint32_t time);

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
  SEQ->REG058._2_1_ = validFrames;
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
  return RFRAND_GetRadioEntropy(_buffer,bytes);
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
}

uint8_t RAIL_ChannelConfig(int *config)

{
  RAILInt_TrackChannelConfig();
  SYNTH_Config(*(undefined4 *)(*config + 8),*(undefined4 *)(*config + 4));
  if (SYNTH_Is2p4GHz() == 0) SYNTH_DCDCRetimeClkSet(3500000);
  else SYNTH_DCDCRetimeClkSet(7000000); 
  if (forceIrCal == true) 
  {
    forceIrCal = false;
    RAILINT_CalibrationPend(0x10000);
  }
  return *(uint8_t *)*config;
}

RAIL_Status_t RAIL_SetStateTiming(RAIL_StateTiming_t *timings);

{
  undefined2 uVar1;
  undefined2 *puVar2;
  
  puVar2 = (undefined2 *)(uint)_timings;
  uVar1 = TIMING_RxWarmTimeSet(*puVar2);
  *puVar2 = uVar1;
  uVar1 = TIMING_TxToRxTimeSet(puVar2[1]);
  puVar2[1] = uVar1;
  uVar1 = TIMING_TxWarmTimeSet(puVar2[2]);
  puVar2[2] = uVar1;
  uVar1 = TIMING_RxFrameToTxTimeSet(puVar2[3]);
  puVar2[3] = uVar1;
  return RAIL_STATUS_NO_ERROR;
}

// WARNING: Could not reconcile some variable overlaps

//bool RAIL_AddressFilterConfig (byte *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
bool RAIL_AddressFilterConfig(RAIL_AddrConfig_t *addrConfig);

{
  byte bVar1;
  int iVar3;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  bVar1 = *param_1;
  if (bVar1 < 3)
  {
    local_1c = param_2;
    local_18 = param_3;
    local_14 = param_4;
    memset(&local_1c,0,0xc);
    for (iVar3 = 0; iVar3 < (int)(uint)bVar1; iVar3 = iVar3 + 1) 
	{
      *(undefined *)((int)&local_1c + iVar3) = *(undefined *)(*(int *)(param_1 + 4) + iVar3);
      *(undefined *)((int)&local_1c + iVar3 + 2) = *(undefined *)(*(int *)(param_1 + 8) + iVar3);
    }
    local_18 = *(undefined4 *)(param_1 + 0xc);
    local_14 = CONCAT31(local_14._1_3_,0xff);
    return GENERIC_PHY_ConfigureAddressFiltering(&local_1c);
  }
  else return false;
}



