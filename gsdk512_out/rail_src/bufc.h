#ifndef _BUFC_H_
#define _BUFC_H_

extern uint32_t currentCallbacks; //???

extern uint32_t enabledCallbacks; //???
extern uint32_t availableCallbacks;
extern uint32_t bufcPendRxFrameError;
extern uint8_t BUFC_TxAckBuffer[64];
extern uint8_t BUFC_TxBuffer[512];
extern uint8_t BUFC_RxLengthBuffer[64];

void BUFC_SetCallbacks(uint32_t cb);
void BUFC_ConfigureCallbacks(uint32_t cb);
void BUFC_WriteBuffer(uint32_t bufnum,uint8_t *src,uint32_t len )
void BUFC_ReadBuffer(uint32_t bufnum,uint8_t *dest,uint32_t len);
uint32_t BUFC_GetSpaceAvailable(int32_t bufnum);
uint32_t BUFC_GetBytesAvailable(int32_t bufnum);
void BUFC_TxAckBufferSet(uint8_t *src,uint32_t len);
void BUFC_TxAckBufferReset(void);
uint32_t BUFC_TxAckBufferBytesAvailable(void);
void BUFC_RxBufferSet(uint32_t addr);
uint32_t BUFC_RxBufferGet(void);
void BUFC_RxBufferReset(void);
void BUFC_Init(void);
//void BUFC_IrqHandler(void);
void BUFC_RxBufferReadBytes(undefined4 param_1,undefined4 param_2);
void BUFC_RxBufferDropBytes(uint32_t param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
bool BUFC_RxBufferPacketAvailable(void);
uint32_t BUFC_RxBufferBytesAvailable(void);
uint32_t BUFC_RxBufferReadByte(void);
uint32_t BUFC_RxLengthBufferBytesAvailable(void);
void BUFC_RxLengthReadNext(uint16_t *buf);
uint32_t BUFC_RxBufferFinalizeAndGet(int32_t *buf,uint32_t len);

#endif