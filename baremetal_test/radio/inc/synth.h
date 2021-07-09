#ifndef _SYNTH_H_
#define _SYNTH_H_

#include "em_device.h"
#include <stdint.h>
#include <stdbool.h>

#define VCO_MIN_FREQ 2300000UL
#define VCO_MAX_FREQ 2900000UL

uint32_t SYNTH_RfFreqGet(void);
uint32_t SYNTH_ChSpacingGet(void);
uint32_t SYNTH_IfFreqGet(void);
uint32_t SYNTH_LoDivGet(void);
bool SYNTH_VcoRangeIsValid(uint32_t freq);
uint8_t SYNTH_Is2p4GHz(void);
void SYNTH_RetimeClkConfig(void);
void SYNTH_Config(uint32_t base_freg, uint32_t spacing);

void SYNTH_ChannelSet(uint16_t ch,int rxcal);
void SYNTH_DigRouteRetimeEnable(void);
void SYNTH_DigRouteRetimeDisable(void);
void SYNTH_DCDCRetimeEnable(void);
void SYNTH_DCDCRetimeDisable(void);
void SYNTH_KvnFreqCompensationEnable(void);
void SYNTH_KvnFreqCompensationDisable(void);


uint32_t SYNTH_IfFreqCompute(void);
void SYNTH_DCDCRetimeClkSet(int param_1);
void SYNTH_RetimeLimitsConfig(uint32_t param_1);

#endif

