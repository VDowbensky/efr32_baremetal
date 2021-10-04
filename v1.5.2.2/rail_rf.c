#include "rail_rf.h"



uint8_t RAIL_RfInit(RAIL_Init_t *railInit)

{
  RAIL_Status_t RVar1;
  RAIL_DataConfig_t local_c;
  
  RAILINT_CalibrationEnable(railInit->calEnable & 0x10001);
  RVar1 = RFHAL_Init(railInit);
  if (RVar1 == RAIL_STATUS_NO_ERROR) {
    local_c = (RAIL_DataConfig_t)0x0;
    RVar1 = RAIL_DataConfig(&local_c);
  }
  return (uint8_t)RVar1;
}



RAIL_Status_t RAIL_SetPtiProtocol(RAIL_PtiProtocol_t protocol)

{
  RAIL_RadioState_t RVar1;
  RAIL_Status_t RVar2;
  
  RVar1 = RFHAL_StateGet();
  if (RVar1 == RAIL_RF_STATE_IDLE) {
    RVar2 = RFHAL_SetPtiProtocol(protocol);
    return RVar2;
  }
  return RAIL_STATUS_INVALID_STATE;
}



void RAIL_RfIdle(void)

{
  RFHAL_IdleExt(1);
  return;
}


void RAIL_RfIdleExt(RAIL_RfIdleMode_t mode,bool wait)

{
  RAIL_RadioState_t RVar1;
  
  RFHAL_IdleExt(mode);
  if (wait != false) {
    do {
      RVar1 = RFHAL_StateGet();
    } while (RVar1 != RAIL_RF_STATE_IDLE);
  }
  return;
}



/* void RAIL_RfStateGet(void)

{
  RFHAL_StateGet();
  return;
} */

RAIL_RadioState_t RAIL_RfStateGet(void)

{
  uint uVar1;
  bool bVar2;
  
  uVar1 = (RAC->STATUS);
  uVar1 = uVar1 & 0xf000000;
  if (uVar1 != 0x7000000) {
    if (0x7000000 < uVar1) {
      if (uVar1 != 0xa000000) {
        if (uVar1 < 0xa000001) {
          if (uVar1 == 0x8000000) {
            return RAIL_RF_STATE_TX;
          }
          bVar2 = uVar1 == 0x9000000;
        }
        else {
          if (uVar1 == 0xb000000) {
            return RAIL_RF_STATE_TX;
          }
          bVar2 = uVar1 == 0xc000000;
        }
        if (!bVar2) {
          return RAIL_RF_STATE_IDLE;
        }
      }
      return RAIL_RF_STATE_TX;
    }
    if (uVar1 != 0x3000000) {
      if (uVar1 < 0x3000001) {
        if (uVar1 == 0x1000000) {
          return RAIL_RF_STATE_RX;
        }
        bVar2 = uVar1 == 0x2000000;
      }
      else {
        if (uVar1 == 0x4000000) {
          return RAIL_RF_STATE_RX;
        }
        bVar2 = uVar1 == 0x5000000;
      }
      if (!bVar2) {
        return RAIL_RF_STATE_IDLE;
      }
    }
  }
  return RAIL_RF_STATE_RX;
}

RAIL_Status_t RAIL_ChannelExists(uint8_t channel)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = 0;
  while( true ) {
    if ((uint)channelConfig[1] <= (uint)bVar1) {
      return RAIL_STATUS_INVALID_PARAMETER;
    }
    iVar2 = (uint)bVar1 * 0xc;
    if ((*(ushort *)(*channelConfig + iVar2) <= (ushort)channel) &&
       ((ushort)channel <= *(ushort *)(*channelConfig + iVar2 + 2))) break;
    bVar1 = bVar1 + 1;
  }
  return RAIL_STATUS_NO_ERROR;
}



void RAILInt_TrackChannelConfig(RAIL_ChannelConfig_t *config)

{
  channelConfig = config;
  return;
}



uint8_t RAILInt_SetChannel(uint8_t channel)

{
  int iVar1;
  ushort *puVar2;
  ushort *puVar3;
  
  if (((channelConfig != (ushort **)0x0) && (puVar3 = *channelConfig, puVar3 != (ushort *)0x0)) &&
     (channelConfig[1] != (ushort *)0x0)) {
    puVar2 = (ushort *)0x0;
    do {
      if ((*puVar3 <= (ushort)channel) && ((ushort)channel <= puVar3[1])) {
        if ((currentEntry == puVar3) && (currentChannel == channel)) {
          return '\0';
        }
        iVar1 = (int)currentEntry - (int)puVar3;
        if (iVar1 != 0) {
          iVar1 = 1;
        }
        iVar1 = RFHAL_SetChannel(channel,puVar3,iVar1);
        if (iVar1 == 0) {
          currentChannel = channel;
          currentEntry = puVar3;
          return (uint8_t)iVar1;
        }
        return (uint8_t)iVar1;
      }
      puVar2 = (ushort *)((int)puVar2 + 1);
      puVar3 = puVar3 + 6;
    } while (puVar2 != channelConfig[1]);
  }
  return '\x01';
}



uint8_t RAILInt_GetChannel(void)

{
  return currentChannel;
}


void RAIL_VersionGet(RAIL_Version_t *version,bool verbose)

{
  version->major = '\x01';
  version->minor = '\x05';
  version->rev = '\x02';
  if (verbose != false) {
    version->build = '\x02';
    version->hash = 0xa397d602;
    version->flags = '\0';
    return;
  }
  version->build = '\0';
  version->hash = 0;
  version->flags = '\0';
  return;
}



RAIL_Status_t RAIL_DebugModeSet(uint32_t debugMode)

{
  if (RAIL_DebugMode == 1) {
    currentEntry = 0;
  }
  RAIL_DebugMode = debugMode;
  return RAIL_STATUS_NO_ERROR;
}



uint32_t RAIL_DebugModeGet(void)

{
  return RAIL_DebugMode;
}



RAIL_Status_t RAIL_SetTxTransitions(RAIL_RadioState_t success,RAIL_RadioState_t error)

{
  RAIL_RadioState_t RVar1;
  RAIL_Status_t RVar2;
  
  if ((success == RAIL_RF_STATE_TX) || (error == RAIL_RF_STATE_TX)) {
    RVar1 = RAIL_RF_STATE_RX;
  }
  else {
    RVar1 = RFHAL_StateGet();
    if (RVar1 != RAIL_RF_STATE_TX) {
      RVar2 = RFHAL_SetTxTransitions(success,error);
      return RVar2;
    }
  }
  return (RAIL_Status_t)RVar1;
}



RAIL_Status_t
RAIL_SetRxTransitions(RAIL_RadioState_t success,RAIL_RadioState_t error,uint8_t ignoreErrors)

{
  RAIL_RadioState_t RVar1;
  RAIL_Status_t RVar2;
  
  if (error == RAIL_RF_STATE_TX) {
    return RAIL_STATUS_INVALID_PARAMETER;
  }
  RVar1 = RFHAL_StateGet();
  if (RVar1 == RAIL_RF_STATE_RX) {
    RVar2 = RAIL_STATUS_INVALID_STATE;
  }
  else {
    RVar2 = RFHAL_SetRxTransitions(success,error);
    if (RVar2 == RAIL_STATUS_NO_ERROR) {
      RVar2 = RFHAL_ErrorConfig(ignoreErrors);
      return RVar2;
    }
  }
  return RVar2;
}



/* void RAIL_SetFixedLength(void)

{
  RFHAL_SetFixedLength();
  return;
} */

uint16_t RAIL_SetFixedLength(uint16_t length)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (uint)length;
  uVar1 = (FRC->DFLCTRL);
  if (((uVar1 & 7) != 0) && ((uVar1 & 7) != 5)) {
    return 0xffff;
  }
  if (uVar2 == 0) {
    uVar1 = (FRC->DFLCTRL);
    write_volatile_4(FRC->DFLCTRL,uVar1 & 0xfffffff8 | 5);
    return length;
  }
  BUS_RegMaskedClear(&FRC->DFLCTRL,7);
  if (0xfff < uVar2) {
    uVar2 = 0x1000;
  }
  write_volatile_4(FRC->WCNTCMP0,uVar2 - 1);
  return (uint16_t)uVar2;
}

