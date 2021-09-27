#ifndef _PHY_H_
#define _PHY_H_

#include "em_device.h"
#include <stdint.h>
#include <stdbool.h>
#include "rail_types.h"


uint16_t validateSetTiming(uint16_t *timing);
uint8_t RAIL_RadioConfig(void *radioConfig);
uint8_t RAIL_ChannelConfig(const RAIL_ChannelConfig_t * config);
void RAIL_DirectModeConfig(bool enable);
uint8_t RAIL_TxToneStart(uint8_t channel);
uint8_t RAIL_TxToneStop(void);
uint8_t RAIL_TxStreamStart(uint8_t channel, RAIL_StreamMode_t mode);
uint8_t RAIL_TxStreamStop(void);
int32_t RAIL_TxPowerSet(int32_t powerLevel);
int32_t RAIL_TxPowerGet(void);
RAIL_Status_t RAIL_DebugFrequencyOverride(uint32_t freq);
void RAIL_PacketLengthConfigFrameType(const RAIL_FrameType_t *frameType);
int16_t RAIL_RxGetRSSI(void);
void RAIL_SetTune(uint32_t tune);
uint32_t RAIL_GetTune(void);
uint32_t RAIL_GetTime(void);
RAIL_Status_t RAIL_SetTime(uint32_t time);

RAIL_Status_t RAIL_SetStateTiming(RAIL_StateTiming_t *timings);
bool RAIL_AddressFilterConfig(RAIL_AddrConfig_t *addrConfig);
bool RAIL_AddressFilterByFrameType(uint8_t validFrames);
bool RAIL_AddressFilterEnable(void);
bool RAIL_AddressFilterDisable(void);
bool RAIL_AddressFilterIsEnabled(void);

void RAIL_AddressFilterReset(void);
bool RAIL_AddressFilterSetAddress(uint8_t field,uint8_t index,uint8_t *value,bool enable);
bool RAIL_AddressFilterEnableAddress(uint8_t field, uint8_t index);
bool RAIL_AddressFilterDisableAddress(uint8_t field, uint8_t index);
uint16_t RAIL_GetRadioEntropy(uint8_t *buffer, uint16_t bytes);


#endif
