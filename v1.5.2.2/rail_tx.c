#include "rail_tx.h"



/* void RAIL_TxConfig(void)

{
  RFHAL_TxIntEnable();
  return;
}
 */

RAIL_Status_t RAIL_TxConfig(uint32_t cbToEnable)

{
  _enabledCallbacks = CONCAT12(DAT_20002dfa & 0x7f | 0x40 | (byte)(((cbToEnable << 0x19) >> 0x1f) << 7),_enabledCallbacks);
  _enabledCallbacks = _enabledCallbacks & 0xffffff00 | (uint)(byte)((byte)(_enabledCallbacks >> 0x18) & 0xfe | (byte)cbToEnable >> 7) << 0x18 |
       (uint)(byte)(enabledCallbacks & 0xfd | ((cbToEnable & 0x1b) != 0) << 1);
  bufcEnabledCallbacks =  bufcEnabledCallbacks & 0xffffff00 | (uint)((byte)bufcEnabledCallbacks & 0xfd | (byte)(cbToEnable << 1) & 2);
  txConfigEvents = cbToEnable;
  GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
  BUFC_ConfigureCallbacks(bufcEnabledCallbacks);
  return RAIL_STATUS_NO_ERROR;
}


uint8_t RAIL_TxStartWithOptions(uint8_t channel,RAIL_TxOptions_t *options,RAIL_PreTxOp_t *preTxOp, void *preTxOpParams)

{
  if (RFHAL_OkToTransmit() == false) return 2;
  else 
  {
    if (RAILInt_SetChannel(channel) == 0) return RFHAL_TxStart(channel,options,preTxOp,preTxOpParams);
	else return 1;
  }
}


uint8_t RAIL_TxStart(uint8_t channel,RAIL_PreTxOp_t preTxOp,void *preTxOpParams)

{
  return RAIL_TxStartWithOptions(channel,NULL,preTxOp,preTxOpParams);
}



uint8_t RAIL_TxToneStart(uint8_t channel)

{
  if (RAILInt_SetChannel(channel) == 0) 
  {
    RFHAL_StartCWTestMode();
	return 0;
  }
  else return 1;
}



uint8_t RAIL_TxToneStop(void)

{
  RFHAL_StopTestMode();
  return 0;
}



uint8_t RAIL_TxStreamStart(uint8_t channel,RAIL_StreamMode_t mode)

{
  if (mode == 1) 
  {
    if (RAILInt_SetChannel(channel) == 0) 
	{
      RFHAL_StartStreamTestMode();
	  return 0;
    }
    else return 1;
  }
  else return 1;
}



uint8_t RAIL_TxStreamStop(void)

{
  RFHAL_StopTestMode();
  return 0;
}



int32_t RAIL_TxPowerSet(int32_t powerLevel)

{
  code *pcVar1;
  uint8_t uVar2;
  int32_t iVar3;
  
  iVar3 = PA_OutputPowerSet(powerLevel);
  pcVar1 = protChChngCB;
  if (protChChngCB != FUN_00000000) (*pcVar1)(RAILInt_GetChannel(),1);
  return iVar3;
}


int32_t RAIL_TxPowerGet(void)

{
  return (int)gPaConfig.power;
}
