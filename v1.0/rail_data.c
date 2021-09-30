#include "rail_data.h"



void RAIL_TxDataLoad(void)

{
  RFHAL_TxDataLoad();
  return;
}



void RAIL_DataConfig(void)

{
  RFHAL_DataConfig();
  return;
}



void RAIL_WriteTxFifo(void)

{
  RFHAL_WriteTxFifo();
  return;
}



void RAIL_ReadRxFifo(void)

{
  RFHAL_ReadRxFifo();
  return;
}



void RAIL_ReadRxFifoAppendedInfo(void)

{
  RFHAL_ReadRxFifoAppendedInfo();
  return;
}



void RAIL_SetTxFifoThreshold(int param_1)

{
  if (param_1 != 0) {
    RFHAL_SetTxFifoThreshold();
    return;
  }
  RFHAL_GetTxFifoThreshold();
  return;
}



void RAIL_SetRxFifoThreshold(int param_1)

{
  if (param_1 != 0xffff) {
    RFHAL_SetRxFifoThreshold();
    return;
  }
  RFHAL_GetRxFifoThreshold();
  return;
}



void RAIL_GetTxFifoThreshold(void)

{
  RFHAL_GetTxFifoThreshold();
  return;
}



void RAIL_GetRxFifoThreshold(void)

{
  RFHAL_GetRxFifoThreshold();
  return;
}



void RAIL_EnableRxFifoThreshold(void)

{
  RFHAL_EnableRxFifoThreshold();
  return;
}



void RAIL_DisableRxFifoThreshold(void)

{
  RFHAL_DisableRxFifoThreshold();
  return;
}



void RAIL_GetTxFifoSpaceAvailable(void)

{
  RFHAL_GetTxFifoSpaceAvailable();
  return;
}



void RAIL_GetRxFifoBytesAvailable(void)

{
  RFHAL_GetRxFifoBytesAvailable();
  return;
}



void RAIL_ResetFifo(int param_1,int param_2)

{
  if (param_1 != 0) {
    RFHAL_ResetTxFifo();
  }
  if (param_2 != 0) {
    RFHAL_ResetRxFifo();
    return;
  }
  return;
}


