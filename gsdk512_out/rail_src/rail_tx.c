#include "rail_tx.h"



uint32_t RAIL_TxConfig(uint32_t cbToEnable)

{
  return RFHAL_TxIntEnable(cbToEnable);
}



uint8_t RAIL_TxStartWithOptions(uint8_t channel,RAIL_TxOptions_t *options,RAIL_PreTxOp_t preTxOp,void *preTxOpParams)

{
  if (RFHAL_OkToTransmit() == false) return 2;
  else 
  {
    if (RAILInt_SetChannel(channel) == 0) return RFHAL_TxStart(channel,_options,preTxOp,*preTxOpParams);
  }
  return 2;
}



uint8_t RAIL_TxStart(uint8_t channel,uint32_t preTxOp,uint32_t *preTxOpParams)

{
  return RAIL_TxStartWithOptions(channel,0,preTxOp,*preTxOpParams);
}



uint8_t RAIL_TxToneStart(void)

{
  uint8_t tmp;
  
  tmp = RAILInt_SetChannel();
  if (tmp == 0) RFHAL_StartCWTestMode();
  return tmp;
}



uint8_t RAIL_TxToneStop(void)

{
  RFHAL_StopTestMode();
  return 0;
}



uint8_t RAIL_TxStreamStart(uint8_t channel, RAIL_StreamMode_t mode)

{
  int tmp;
  
  if (mode == 1) 
  {
    tmp = RAILInt_SetChannel(channel);
    if (tmp == 0) RFHAL_StartStreamTestMode();
    return (uint8_t)tmp;
  }
  return 1;
}



uint8_t RAIL_TxStreamStop(void)

{
  RFHAL_StopTestMode();
  return 0;
}



int32_t RAIL_TxPowerSet(int32_t powerLevel)

{
  return RFHAL_SetCurrPowerLevel(powerLevel);
}



int32_t RAIL_TxPowerGet(void)

{
  return RFHAL_GetCurrPowerLevel();
}


