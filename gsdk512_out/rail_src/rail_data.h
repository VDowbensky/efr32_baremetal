#ifndef _RAIL_DATA_H_
#define _RAIL_DATA_H_

uint8_t RAIL_TxDataLoad(RAIL_TxData_t *txData);
RAIL_Status_t RAIL_DataConfig(RAIL_DataConfig_t *dataConfig);
uint16_t RAIL_WriteTxFifo(uint8_t *dataPtr, uint16_t writeLength);
uint16_t RAIL_ReadRxFifo(uint8_t *dataPtr, uint16_t readLength);
void RAIL_ReadRxFifoAppendedInfo(RAIL_AppendedInfo_t *appendedInfo);
uint16_t RAIL_SetTxFifoThreshold(uint16_t txThreshold);
uint16_t RAIL_SetRxFifoThreshold(uint16_t rxThreshold);
uint16_t RAIL_GetTxFifoThreshold(void);
uint16_t RAIL_GetRxFifoThreshold(void);
void RAIL_EnableRxFifoThreshold(void);
void RAIL_DisableRxFifoThreshold(void);
uint16_t RAIL_GetTxFifoSpaceAvailable(void);
uint16_t RAIL_GetRxFifoBytesAvailable(void);
void RAIL_ResetFifo(bool txFifo,bool rxFifo);

#endif
