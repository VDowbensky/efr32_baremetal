#ifndef _PHY_H_
#define _PHY_H_

uint8_t RAIL_RadioConfig(undefined *radioConfig);
RAIL_Status_t RAIL_DebugFrequencyOverride(uint32_t freq);
void RAIL_PacketLengthConfigFrameType(const RAIL_FrameType_t *frameType);
RAIL_Status_t RAIL_SetCcaThreshold(int8_t ccaThresholdDbm);
int16_t RAIL_RxGetRSSI(void);
int16_t RAIL_PollAverageRSSI(uint32_t averageTimeUs);
void RAIL_StartAverageRSSI(uint8_t channel,uint32_t averagingTimeUs);
int16_t RAIL_GetAverageRSSI(void);
bool RAIL_AverageRSSIReady(void);
void RAIL_SetTune(uint32_t tune);
uint32_t RAIL_GetTune(void);
uint32_t RAIL_GetTime(void);
RAIL_Status_t RAIL_SetTime(uint32_t time);
void RAILInt_CompensateForDelay(void);
bool RAIL_AddressFilterByFrameType(uint8_t validFrames);
bool RAIL_AddressFilterEnable(void);
bool RAIL_AddressFilterDisable(void);
bool RAIL_AddressFilterIsEnabled(void);
void RAIL_AddressFilterReset(void);
bool RAIL_AddressFilterSetAddress(uint8_t field,uint8_t index,uint8_t _value,bool enable);
bool RAIL_AddressFilterEnableAddress(uint8_t field,uint8_t index);
bool RAIL_AddressFilterDisableAddress(uint8_t field,uint8_t index);
uint16_t RAIL_GetRadioEntropy(uint8_t *buffer,uint16_t bytes);
void RAIL_DirectModeConfig(bool enable);
uint8_t RAIL_ChannelConfig(const RAIL_ChannelConfig_t * config);
RAIL_Status_t RAIL_SetStateTiming(RAIL_StateTiming_t *timings);
bool RAIL_AddressFilterConfig(RAIL_AddrConfig_t *addrConfig);

#endif