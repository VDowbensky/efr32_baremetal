#ifndef _SYNTH_H_
#define _SYNTH_H_

uint32_t SYNTH_RfFreqGet(void);
uint32_t SYNTH_ChSpacingGet(void);
uint32_t SYNTH_IfFreqGet(void);
uint32_t SYNTH_LoDivGet(void);
bool SYNTH_Is2p4GHz(void);
bool SYNTH_VcoRangeIsValid(uint32_t freq);
void SYNTH_RetimeLimitsConfig(uint32_t freq);
void SYNTH_RetimeClkConfig(void);
void SYNTH_Config(uint32_t base_freg, uint32_t spacing);
void SYNTH_ChannelSet(uint16_t ch,int rxcal);
void SYNTH_DigRouteRetimeEnable(void);
void SYNTH_DigRouteRetimeDisable(void);
void SYNTH_DCDCRetimeEnable(void);
void SYNTH_DCDCRetimeClkSet(int target);
void SYNTH_DCDCRetimeDisable(void);
void SYNTH_KvnFreqCompensationEnable(void);
void SYNTH_KvnFreqCompensationDisable(void);

#endif
