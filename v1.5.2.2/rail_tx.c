#include "rail_tx.h"



/* void RAIL_TxConfig(void)

{
  RFHAL_TxIntEnable();
  return;
}
 */

RAIL_Status_t RAIL_TxConfig(uint32_t cbToEnable)

{
  _enabledCallbacks =
       CONCAT12(DAT_20002dfa & 0x7f | 0x40 | (byte)(((cbToEnable << 0x19) >> 0x1f) << 7),
                _enabledCallbacks);
  _enabledCallbacks =
       _enabledCallbacks & 0xffffff00 |
       (uint)(byte)((byte)(_enabledCallbacks >> 0x18) & 0xfe | (byte)cbToEnable >> 7) << 0x18 |
       (uint)(byte)(enabledCallbacks & 0xfd | ((cbToEnable & 0x1b) != 0) << 1);
  bufcEnabledCallbacks =
       bufcEnabledCallbacks & 0xffffff00 |
       (uint)((byte)bufcEnabledCallbacks & 0xfd | (byte)(cbToEnable << 1) & 2);
  txConfigEvents = cbToEnable;
  GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
  BUFC_ConfigureCallbacks(bufcEnabledCallbacks);
  return RAIL_STATUS_NO_ERROR;
}


uint8_t RAIL_TxStartWithOptions
                  (uint8_t channel,RAIL_TxOptions_t *options,RAIL_PreTxOp_t *preTxOp,
                  void *preTxOpParams)

{
  bool bVar1;
  uint8_t uVar2;
  
  bVar1 = RFHAL_OkToTransmit();
  if (bVar1 == false) {
    uVar2 = '\x02';
  }
  else {
    uVar2 = RAILInt_SetChannel(channel);
    if (uVar2 == '\0') {
      uVar2 = RFHAL_TxStart(channel,options,preTxOp,preTxOpParams);
      return uVar2;
    }
  }
  return uVar2;
}


uint8_t RAIL_TxStart(uint8_t channel,RAIL_PreTxOp_t preTxOp,void *preTxOpParams)

{
  uint8_t uVar1;
  
  uVar1 = RAIL_TxStartWithOptions(channel,(RAIL_TxOptions_t *)0x0,preTxOp,preTxOpParams);
  return uVar1;
}



uint8_t RAIL_TxToneStart(uint8_t channel)

{
  uint8_t uVar1;
  
  uVar1 = RAILInt_SetChannel(channel);
  if (uVar1 == '\0') {
    RFHAL_StartCWTestMode();
  }
  return uVar1;
}



uint8_t RAIL_TxToneStop(void)

{
  RFHAL_StopTestMode();
  return '\0';
}



uint8_t RAIL_TxStreamStart(uint8_t channel,RAIL_StreamMode_t mode)

{
  uint8_t uVar1;
  
  if (mode == 1) {
    uVar1 = RAILInt_SetChannel(channel);
    if (uVar1 == '\0') {
      RFHAL_StartStreamTestMode();
    }
    return uVar1;
  }
  return '\x01';
}



uint8_t RAIL_TxStreamStop(void)

{
  RFHAL_StopTestMode();
  return '\0';
}



/* void RAIL_TxPowerSet(void)

{
  RFHAL_SetCurrPowerLevel();
  return;
} */

int32_t RAIL_TxPowerSet(int32_t powerLevel)

{
  code *pcVar1;
  uint8_t uVar2;
  int32_t iVar3;
  
  iVar3 = PA_OutputPowerSet(powerLevel);
  pcVar1 = protChChngCB;
  if (protChChngCB != FUN_00000000) {
    uVar2 = RAILInt_GetChannel();
    (*pcVar1)(uVar2,1);
  }
  return iVar3;
}


/* void RAIL_TxPowerGet(void)

{
  RFHAL_GetCurrPowerLevel();
  return;
}
 */
int32_t RAIL_TxPowerGet(void)

{
  return (int)gPaConfig.power;
}
