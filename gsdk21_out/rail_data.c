#include "rail_data.h"



//void RAIL_ConfigData(int param_1)
RAIL_Status_t RAIL_ConfigData(RAIL_Handle_t railHandle,const RAIL_DataConfig_t *dataConfig)

{
  return RFHAL_ConfigData(railHandle + 0xc, &dataConfig);
}



//void RAIL_WriteTxFifo(int param_1)
uint16_t RAIL_WriteTxFifo(RAIL_Handle_t railHandle,
                          const uint8_t *dataPtr,
                          uint16_t writeLength,
                          bool reset)
{
  return RFHAL_WriteTxFifo(railHandle + 0xc,&dataPtr,writeLength,reset);
}



//void RAIL_SetTxFifo(int param_1)
uint16_t RAIL_SetTxFifo(RAIL_Handle_t railHandle,
                        uint8_t *addr,
                        uint16_t initLength,
                        uint16_t size)

{
  return RFHAL_SetTxBuffer(railHandle + 0xc,&addr,initLength,size);
}



//void RAIL_ReadRxFifo(int param_1)
uint16_t RAIL_ReadRxFifo(RAIL_Handle_t railHandle,
                         uint8_t *dataPtr,
                         uint16_t readLength)

{
  return RFHAL_ReadRxFifo(railHandle + 0xc,&dataPtr,readLength);
}



//void RAIL_GetRxPacketInfo(undefined4 param_1,undefined4 param_2,undefined4 param_3)
RAIL_RxPacketHandle_t RAIL_GetRxPacketInfo(RAIL_Handle_t railHandle,
                                           RAIL_RxPacketHandle_t packetHandle,
                                           RAIL_RxPacketInfo_t *pPacketInfo)
{
  return RFHAL_GetRxPacketInfo(packetHandle,&pPacketInfo);
}



//void RAIL_GetRxPacketDetails(undefined4 param_1,undefined4 param_2,undefined4 param_3)
RAIL_Status_t RAIL_GetRxPacketDetails(RAIL_Handle_t railHandle,
                                      RAIL_RxPacketHandle_t packetHandle,
                                      RAIL_RxPacketDetails_t *pPacketDetails)
{
  return RFHAL_GetRxPacketDetails(packetHandle,&pPacketDetails);
}



//void RAIL_HoldRxPacket(void)
RAIL_RxPacketHandle_t RAIL_HoldRxPacket(RAIL_Handle_t railHandle)
{
  return RFHAL_HoldRxPacket();
}



//void RAIL_ReleaseRxPacket(undefined4 param_1,undefined4 param_2)
RAIL_Status_t RAIL_ReleaseRxPacket(RAIL_Handle_t railHandle,
                                   RAIL_RxPacketHandle_t packetHandle)
{
  return RFHAL_ReleaseRxPacket(packetHandle);
}



//void RAIL_SetTxFifoThreshold(int param_1)
uint16_t RAIL_SetTxFifoThreshold(RAIL_Handle_t railHandle,
                                 uint16_t txThreshold)
{
  return RFHAL_SetTxFifoThreshold(railHandle + 0xc);
}



//void RAIL_SetRxFifoThreshold(int param_1)
uint16_t RAIL_SetRxFifoThreshold(RAIL_Handle_t railHandle,
                                 uint16_t rxThreshold)
{
  return RFHAL_SetRxFifoThreshold(railHandle + 0xc,rxThreshold);
}



//void RAIL_GetTxFifoThreshold(int param_1)
uint16_t RAIL_GetTxFifoThreshold(RAIL_Handle_t railHandle)
{
  return RFHAL_GetTxFifoThreshold(railHandle + 0xc);
}



//void RAIL_GetRxFifoThreshold(int param_1)
uint16_t RAIL_GetRxFifoThreshold(RAIL_Handle_t railHandle)
{
  return RFHAL_GetRxFifoThreshold(railHandle + 0xc);
}



//void RAIL_GetTxFifoSpaceAvailable(int param_1)
uint16_t RAIL_GetTxFifoSpaceAvailable(RAIL_Handle_t railHandle)
{
  return RFHAL_GetTxFifoSpaceAvailable(railHandle + 0xc);
}



//void RAIL_GetRxFifoBytesAvailable(int param_1)
uint16_t RAIL_GetRxFifoBytesAvailable(RAIL_Handle_t railHandle)
{
  return RFHAL_GetRxFifoBytesAvailable(railHandle + 0xc);
}



//void RAIL_ResetFifo(int param_1,int param_2,int param_3)
void RAIL_ResetFifo(RAIL_Handle_t railHandle, bool txFifo, bool rxFifo)
{
  if (txFifo == true) RFHAL_ResetTxFifo();
  if (rxFifo == true) RFHAL_ResetRxFifo();
}



//void RAIL_PeekRxPacket(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
//                      undefined2 param_5)
uint16_t RAIL_PeekRxPacket(RAIL_Handle_t railHandle,
                           RAIL_RxPacketHandle_t packetHandle,
                           uint8_t *pDst,
                           uint16_t len,
                           uint16_t offset)
{
  return RFHAL_PeekRxPacket(packetHandle,&pDst,len,offset);
}


