#include "rail_data.h"



//void RAIL_ConfigData(int param_1)
RAIL_Status_t RAIL_ConfigData(RAIL_Handle_t railHandle,const RAIL_DataConfig_t *dataConfig);

{
  RFHAL_ConfigData(param_1 + 0xc);
  return;
}



//void RAIL_WriteTxFifo(int param_1)
uint16_t RAIL_WriteTxFifo(RAIL_Handle_t railHandle,
                          const uint8_t *dataPtr,
                          uint16_t writeLength,
                          bool reset);
{
  RFHAL_WriteTxFifo(param_1 + 0xc);
  return;
}



//void RAIL_SetTxFifo(int param_1)
uint16_t RAIL_SetTxFifo(RAIL_Handle_t railHandle,
                        uint8_t *addr,
                        uint16_t initLength,
                        uint16_t size);

{
  RFHAL_SetTxBuffer(param_1 + 0xc);
  return;
}



//void RAIL_ReadRxFifo(int param_1)
uint16_t RAIL_ReadRxFifo(RAIL_Handle_t railHandle,
                         uint8_t *dataPtr,
                         uint16_t readLength);

{
  RFHAL_ReadRxFifo(param_1 + 0xc);
  return;
}



//void RAIL_GetRxPacketInfo(undefined4 param_1,undefined4 param_2,undefined4 param_3)
RAIL_RxPacketHandle_t RAIL_GetRxPacketInfo(RAIL_Handle_t railHandle,
                                           RAIL_RxPacketHandle_t packetHandle,
                                           RAIL_RxPacketInfo_t *pPacketInfo);
{
  RFHAL_GetRxPacketInfo(param_2,param_3);
  return;
}



//void RAIL_GetRxPacketDetails(undefined4 param_1,undefined4 param_2,undefined4 param_3)
RAIL_Status_t RAIL_GetRxPacketDetails(RAIL_Handle_t railHandle,
                                      RAIL_RxPacketHandle_t packetHandle,
                                      RAIL_RxPacketDetails_t *pPacketDetails);
{
  RFHAL_GetRxPacketDetails(param_2,param_3);
  return;
}



//void RAIL_HoldRxPacket(void)
RAIL_RxPacketHandle_t RAIL_HoldRxPacket(RAIL_Handle_t railHandle);
{
  RFHAL_HoldRxPacket();
  return;
}



//void RAIL_ReleaseRxPacket(undefined4 param_1,undefined4 param_2)
RAIL_Status_t RAIL_ReleaseRxPacket(RAIL_Handle_t railHandle,
                                   RAIL_RxPacketHandle_t packetHandle);
{
  RFHAL_ReleaseRxPacket(param_2);
  return;
}



//void RAIL_SetTxFifoThreshold(int param_1)
uint16_t RAIL_SetTxFifoThreshold(RAIL_Handle_t railHandle,
                                 uint16_t txThreshold);
{
  RFHAL_SetTxFifoThreshold(param_1 + 0xc);
  return;
}



//void RAIL_SetRxFifoThreshold(int param_1)
uint16_t RAIL_SetRxFifoThreshold(RAIL_Handle_t railHandle,
                                 uint16_t rxThreshold);
{
  RFHAL_SetRxFifoThreshold(param_1 + 0xc);
  return;
}



//void RAIL_GetTxFifoThreshold(int param_1)
uint16_t RAIL_GetTxFifoThreshold(RAIL_Handle_t railHandle);
{
  RFHAL_GetTxFifoThreshold(param_1 + 0xc);
  return;
}



//void RAIL_GetRxFifoThreshold(int param_1)
uint16_t RAIL_GetRxFifoThreshold(RAIL_Handle_t railHandle);
{
  RFHAL_GetRxFifoThreshold(param_1 + 0xc);
  return;
}



//void RAIL_GetTxFifoSpaceAvailable(int param_1)
uint16_t RAIL_GetTxFifoSpaceAvailable(RAIL_Handle_t railHandle);
{
  RFHAL_GetTxFifoSpaceAvailable(param_1 + 0xc);
  return;
}



//void RAIL_GetRxFifoBytesAvailable(int param_1)
uint16_t RAIL_GetRxFifoBytesAvailable(RAIL_Handle_t railHandle);
{
  RFHAL_GetRxFifoBytesAvailable(param_1 + 0xc);
  return;
}



//void RAIL_ResetFifo(int param_1,int param_2,int param_3)
void RAIL_ResetFifo(RAIL_Handle_t railHandle, bool txFifo, bool rxFifo);
{
  if (param_2 != 0) {
    RFHAL_ResetTxFifo(param_1 + 0xc);
  }
  if (param_3 != 0) {
    RFHAL_ResetRxFifo(param_1 + 0xc);
  }
  return;
}



//void RAIL_PeekRxPacket(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
//                      undefined2 param_5)
uint16_t RAIL_PeekRxPacket(RAIL_Handle_t railHandle,
                           RAIL_RxPacketHandle_t packetHandle,
                           uint8_t *pDst,
                           uint16_t len,
                           uint16_t offset);
{
  RFHAL_PeekRxPacket(param_2,param_3,param_4,param_5);
  return;
}


