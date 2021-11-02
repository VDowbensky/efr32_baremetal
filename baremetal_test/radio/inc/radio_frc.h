#ifndef _RADIO_FRC_H_
#define _RADIO_FRC_H_

#include "radio_proc.h"

void FRC_init(void);
void FRC_FrameControlDescrBufferIdSet(int buf,int fcd);
void FRC_FrameControlDescrConfigSet(int param_1,uint32_t param_2,int param_3,int param_4,uint8_t param_5,uint8_t param_6);
void FRC_FrameDescsConfig (uint32_t param_1,uint32_t param_2,uint32_t param_3,uint32_t param_4);
void FRC_ErrorHandle(void);
int FRC_RxTrailDataLength(void);

#endif
