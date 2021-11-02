#ifndef _RADIO_BUFC_H_
#define _RADIO_BUFC_H_

#include "radio_proc.h"

//void RADIO_BUFCIrqHandler(void);
void BUFC_init(void);
void BUFC_Config(uint32_t buf,uint32_t len,uint32_t address,uint32_t threshold,uint32_t tresholdmode);
uint32_t BUFC_BytesAvailable(uint8_t buf);
void BUFC_TxBufferSet(uint8_t * param_1,int param_2,uint8_t * param_3,uint32_t param_4);
void BUFC_TxBufferReset(void);
void BUFC_RXBufferEnableThrInt(void);
void BUFC_RXBufferDisableThrInt(void);
void BUFC_RxBufferSet(uint32_t address);
uint32_t BUFC_RxBufferGet(void);
void BUFC_RxBufferReset(void);
bool BUFC_RxBufferPacketAvailable(void);
uint16_t BUFC_RxBufferBytesAvailable(void);
uint16_t BUFC_TxBufferBytesAvailable(void);
uint16_t BUFC_RxLengthBufferBytesAvailable(void);
uint8_t BUFC_RxBufferReadByte(void);
uint8_t BUFC_Readbyte(uint32_t buf);
void BUFC_ReadContASync(uint32_t buf,uint8_t *dest,uint16_t len);
void BUFC_WriteContSync(uint8_t *addr,int len);
void BUFC_RxBufferReadBytes(uint8_t *dest,uint16_t len);
void BUFC_RxBufferDropBytes(uint16_t bytes);
uint32_t BUFC_RxLengthReadNext(uint32_t param_1,uint32_t param_2,uint32_t param_3,uint32_t param_4);
void BUFC_Clear(uint32_t buf);
int BUFC_RxBufferFinalizeAndGet(int *param_1,uint32_t param_2,uint32_t param_3,uint32_t param_4);

#endif