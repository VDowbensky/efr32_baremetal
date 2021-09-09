#ifndef _RADIO_H_
#define _RADIO_H_

#include "radio.h"

void RADIO_WriteSync(undefined4 *addr,uint32_t sync);
void RADIO_SetBitSync(uint32_t addr,uint32_t bitnumber);
void RADIO_ClrBitSync(uint32_t addr,uint32_t bitnumber);
void RADIO_OrSync(uint32_t addr,uint32_t sync);
void RADIO_XorSync(uint32_t *addr,uint32_t sync);
void RADIO_AndSync(uint32_t addr,uint32_t sync);
void RADIO_WaitForSetSync(uint32_t *addr,uint32_t sync);
void RADIO_Delay(uint32_t us);
void RADIO_SetAndForgetWrite(void);
void RADIO_SeqInit(uint32_t src,uint32_t len);
void RADIO_CLKEnable(void);
void RADIO_Init(void);

void RADIO_Config(int param_1);
void RADIO_RegisterIrqCallback(int param_1,undefined4 param_2);

//void FRC_PRI_IRQHandler(void);
//void RAC_RSM_IRQHandler(void);
//void RAC_SEQ_IRQHandler(void);
//void AGC_IRQHandler(void);
//void PROTIMER_IRQHandler(void);
//void BUFC_IRQHandler(void);
//void FRC_IRQHandler(void);
//void MODEM_IRQHandler(void);

bool RADIO_IsRxActive(void);
uint32_t RADIO_RxTrailDataLength(void);

void RADIO_FrameControlDescrBufferIdSet(int param_1,int param_2);
void RADIO_FrameControlDescrConfigSet(int param_1,uint param_2,int param_3,int param_4,byte param_5,byte param_6);
void RADIO_FrameDescsConfig(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);

void RADIO_FRCErrorHandle(void);
void RADIO_DemodResetOnRxsearchEntryEnable(void);
void RADIO_DemodResetOnRxsearchEntryDisable(void);
void RADIO_DccalEnable(void);
void RADIO_DccalDisable(void);
void RADIO_TxHoldOffEnable(void);
void RADIO_TxHoldOffDisable(void);
void RADIO_VcoFineCalEnable(void);
void RADIO_VcoFineCalDisable(void);
uint32_t RADIO_ComputeTxBaudrate(void);
uint32_t RADIO_ComputeRxBaudrate(void);
uint32_t RADIO_ComputeTxSymbolRate(void);
uint32_t RADIO_ComputeTxBitRate(void);
int32_t RADIO_GetRSSI(void);

uint32_t RADIO_SetAgcCcaParams(int32_t param_1,int8_t threshold);
bool RADIO_AGCCCAThresholdSet(int8_t threshold);
uint32_t RADIO_CalcRssiPeriod(uint param_1);

void RADIO_SetCRCInitVal(uint32_t val);

#endif