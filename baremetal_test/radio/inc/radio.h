#ifndef _RADIO_H_
#define _RADIO_H_

#include "em_device.h"
#include <stdint.h>
#include <stdbool.h>

void RADIO_BUFCClear(int buf);
//not used
void RADIO_WriteSync(uint32_t *addr,uint32_t data);
void RADIO_OrSync(uint32_t *addr,uint32_t data);
void RADIO_XorSync(uint32_t *addr,uint32_t data);
void RADIO_AndSync(uint32_t *addr,uint32_t data);
void RADIO_WaitForSetSync(uint32_t *addr,uint32_t data);
void RADIO_ClrBitSync(int addr,int bit);
void RADIO_SetBitSync(int addr,int bit);
//timings
uint32_t RADIO_UsToStimerTickCalc(uint32_t us);
void RADIO_Delay(uint32_t us);
void RADIO_ModemConfigFixup(void);
void RADIO_SeqInit(void *src,uint32_t len);
void RADIO_Config(void *radioConfig);
void RADIO_RegisterIrqCallback(int irqN,void *func);
void FRC_PRI_IRQHandler(void);
void FRC_IRQHandler(void);
void RAC_RSM_IRQHandler(void);
void RAC_SEQ_IRQHandler(void);
void AGC_IRQHandler(void);
void PROTIMER_IRQHandler(void);
void BUFC_IRQHandler(void);
void MODEM_IRQHandler(void);
void RADIO_BUFCIrqHandler(void);
void RADIO_FRCErrorHandle(void);
void RADIO_DemodResetOnRxsearchEntryEnable(void);
void RADIO_DemodResetOnRxsearchEntryDisable(void);
void RADIO_DccalEnable(void);
void RADIO_Init(void);
void RADIO_DccalDisable(void);
void RADIO_TxWarmTimeSet(uint16_t us);
void RADIO_RxToTxTimeSet(uint16_t us);
void RADIO_RxFrameToTxTimeSet(uint16_t us);
void RADIO_TxToTxTimeSet(uint16_t us);
void RADIO_TxToRxTimeSet(uint16_t us);
void RADIO_RxWarmTimeSet(uint16_t us);
uint16_t RADIO_RxWarmTimeGet(void);
void RADIO_RxSearchTimeSet(uint32_t us);
void RADIO_TxToRxSearchTimeSet(uint32_t us);
uint32_t RADIO_ComputeTxBaudrate(void);
uint32_t RADIO_ComputeTxSymbolRate(void);
uint32_t RADIO_ComputeTxBitRate(void);
int16_t RADIO_GetRSSI(void);
void RADIO_TxBufferReset(void);
void RADIO_RXBufferEnableThrInt(void);
void RADIO_RXBufferDisableThrInt(void);
bool RADIO_IsRxActive(void);
uint32_t RADIO_RxBufferGet(void);

void RADIO_RxBufferReset(void);
int RADIO_RxTrailDataLength(void);
bool RADIO_RxBufferPacketAvailable(void);
uint16_t RADIO_RxBufferBytesAvailable(void);
uint16_t RADIO_TxBufferBytesAvailable(void);
uint16_t RADIO_RxLengthBufferBytesAvailable(void);
uint8_t RADIO_RxBufferReadByte(void);
void RADIO_FrameControlDescrBufferIdSet(int buf,int fcd);
uint8_t RADIO_BUFCRead(int buf);
uint32_t RADIO_BUFCBytesAvailable(uint8_t buf);
void RADIO_CLKEnable(void);
void RADIO_BUFCWriteContSync_constprop_3(uint8_t *addr,int len);
void RADIO_SetAndForgetWrite(void);


void RADIO_RxBufferSet(int param_1);
void RADIO_BUFCConfig(int param_1,uint32_t param_2,uint32_t param_3,uint32_t param_4,uint32_t param_5);
void RADIO_TxBufferSet(uint8_t * param_1,int param_2,uint8_t * param_3,uint32_t param_4);
void RADIO_FrameControlDescrConfigSet(int param_1,uint32_t param_2,int param_3,int param_4,uint8_t param_5,uint8_t param_6);
void RADIO_FrameDescsConfig (uint32_t param_1,uint32_t param_2,uint32_t param_3,uint32_t param_4);
void RADIO_BUFCReadContASync(int buf,uint8_t *param_2,int param_3);
void RADIO_RxBufferReadBytes(uint8_t *param_1,uint32_t param_2);

void RADIO_RxBufferDropBytes(uint32_t param_1,uint32_t param_2,uint32_t param_3,uint32_t param_4);
uint32_t RADIO_RxLengthReadNext(uint32_t param_1,uint32_t param_2,uint32_t param_3,uint32_t param_4);

int RADIO_RxBufferFinalizeAndGet(int *param_1,uint32_t param_2,uint32_t param_3,uint32_t param_4);



#endif

