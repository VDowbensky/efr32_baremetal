#include "rail_rf.h"



uint8_t RAIL_RfInit(RAIL_Init_t *railInit)

{
  RAIL_Status_t RVar1;
  RAIL_DataConfig_t local_c;
  
  RAILINT_CalibrationEnable(railInit->calEnable & 0x10001);
  if (RFHAL_Init(railInit) == RAIL_STATUS_NO_ERROR) 
  {
    local_c = (RAIL_DataConfig_t)0x0;
    RVar1 = RAIL_DataConfig(&local_c);
  }
  return (uint8_t)RVar1;
}



RAIL_Status_t RAIL_SetPtiProtocol(RAIL_PtiProtocol_t protocol)

{
  if (RFHAL_StateGet() == RAIL_RF_STATE_IDLE) return RFHAL_SetPtiProtocol(protocol);
  else return RAIL_STATUS_INVALID_STATE;
}



void RAIL_RfIdle(void)

{
  RFHAL_IdleExt(1);
}


void RAIL_RfIdleExt(RAIL_RfIdleMode_t mode,bool wait)

{
  RFHAL_IdleExt(mode);
  if (wait != false) 
  {
     while (RFHAL_StateGet() != RAIL_RF_STATE_IDLE);
  }
}



/* void RAIL_RfStateGet(void)

{
  RFHAL_StateGet();
  return;
} */

RAIL_RadioState_t RAIL_RfStateGet(void)

{
  uint32_t state;
  bool bVar2;
  
  state = RAC->STATUS & 0xf000000;
  if (state != 0x7000000) 
  {
    if (0x7000000 < state) 
	{
      if (state != 0xa000000) 
	  {
        if (state < 0xa000001) 
		{
          if (state == 0x8000000) return RAIL_RF_STATE_TX;
          bVar2 = state == 0x9000000;
        }
        else 
		{
          if (state == 0xb000000) return RAIL_RF_STATE_TX;
          bVar2 = state == 0xc000000;
        }
        if (!bVar2) return RAIL_RF_STATE_IDLE;
      }
      return RAIL_RF_STATE_TX;
    }
    if (state != 0x3000000) 
	{
      if (state < 0x3000001) 
	  {
        if (state == 0x1000000) return RAIL_RF_STATE_RX;
        bVar2 = state == 0x2000000;
      }
      else 
	  {
        if (state == 0x4000000) return RAIL_RF_STATE_RX;
        bVar2 = state == 0x5000000;
      }
      if (!bVar2) return RAIL_RF_STATE_IDLE;
    }
  }
  return RAIL_RF_STATE_RX;
}

RAIL_Status_t RAIL_ChannelExists(uint8_t channel)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = 0;
  while( true ) 
  {
    if ((uint)channelConfig[1] <= (uint)bVar1) return RAIL_STATUS_INVALID_PARAMETER;
    iVar2 = (uint)bVar1 * 0xc;
    if ((*(uint16_t *)(*channelConfig + iVar2) <= (uint16_t)channel) && ((uint16_t)channel <= *(uint16_t *)(*channelConfig + iVar2 + 2))) break;
    bVar1 = bVar1 + 1;
  }
  return RAIL_STATUS_NO_ERROR;
}



void RAILInt_TrackChannelConfig(RAIL_ChannelConfig_t *config)

{
  channelConfig = config;
}



uint8_t RAILInt_SetChannel(uint8_t channel)

{
  int iVar1;
  uint16_t *puVar2;
  uint16_t *puVar3;
  
  if (((channelConfig != (uint16_t **)0x0) && (puVar3 = *channelConfig, puVar3 != (uint16_t *)0x0)) && (channelConfig[1] != (uint16_t *)0x0)) 
  {
    puVar2 = (uint16_t *)0x0;
    do {
      if ((*puVar3 <= (uint16_t)channel) && ((uint16_t)channel <= puVar3[1])) 
	  {
        if ((currentEntry == puVar3) && (currentChannel == channel)) return 0;
        iVar1 = (int)currentEntry - (int)puVar3;
        if (iVar1 != 0) iVar1 = 1;
        iVar1 = RFHAL_SetChannel(channel,puVar3,iVar1);
        if (iVar1 == 0) 
		{
          currentChannel = channel;
          currentEntry = puVar3;
          return (uint8_t)iVar1;
        }
        return (uint8_t)iVar1;
      }
      puVar2 = (uint16_t *)((int)puVar2 + 1);
      puVar3 = puVar3 + 6;
    } while (puVar2 != channelConfig[1]);
  }
  return 1;
}



uint8_t RAILInt_GetChannel(void)

{
  return currentChannel;
}


void RAIL_VersionGet(RAIL_Version_t *version,bool verbose)

{
  version->major = 1;
  version->minor = 5;
  version->rev = 2;
  if (verbose != false) 
  {
    version->build = 2;
    version->hash = 0xa397d602;
    version->flags = 0;
    return;
  }
  version->build = 0;
  version->hash = 0;
  version->flags = 0;
}



RAIL_Status_t RAIL_DebugModeSet(uint32_t debugMode)

{
  if (RAIL_DebugMode == 1) currentEntry = 0;
  RAIL_DebugMode = debugMode;
  return RAIL_STATUS_NO_ERROR;
}



uint32_t RAIL_DebugModeGet(void)

{
  return RAIL_DebugMode;
}



RAIL_Status_t RAIL_SetTxTransitions(RAIL_RadioState_t success,RAIL_RadioState_t error)

{
  if ((success == RAIL_RF_STATE_TX) || (error == RAIL_RF_STATE_TX)) return RAIL_STATUS_INVALID_PARAMETER;
  else 
  {
    if (RFHAL_StateGet() != RAIL_RF_STATE_TX) return RFHAL_SetTxTransitions(success,error);
	else return RAIL_STATUS_INVALID_STATE;
  }
}



RAIL_Status_t RAIL_SetRxTransitions(RAIL_RadioState_t success,RAIL_RadioState_t error,uint8_t ignoreErrors)

{
  if (error == RAIL_RF_STATE_TX) return RAIL_STATUS_INVALID_PARAMETER;
  if (RFHAL_StateGet() == RAIL_RF_STATE_RX) return RAIL_STATUS_INVALID_STATE;
  else 
  {
    if (RFHAL_SetRxTransitions(success,error) == RAIL_STATUS_NO_ERROR) return RFHAL_ErrorConfig(ignoreErrors);
	else return RAIL_STATUS_INVALID_STATE;
  }
}



/* void RAIL_SetFixedLength(void)

{
  RFHAL_SetFixedLength();
  return;
} */

uint16_t RAIL_SetFixedLength(uint16_t length)

{
  uint32_t len;
  
  len = (uint32_t)length;
  if (((FRC->DFLCTRL & 7) != 0) && ((FRC->DFLCTRL & 7) != 5)) return 0xffff;
  if (len == 0) 
  {
	FRC->DFLCTRL &= 0xfffffff8;
	FRC->DFLCTRL |= 5;
    return length;
  }
  BUS_RegMaskedClear(&FRC->DFLCTRL,7);
  if (0xfff < len) len = 0x1000;
  FRC->WCNTCMP0 = len - 1;
  return (uint16_t)len;
}

