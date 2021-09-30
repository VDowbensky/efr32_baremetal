#include "rail_rf.h"



uint8_t RAIL_RfInit(RAIL_Init_t *railInit)

{
  uint8_t uVar1;
  
  RFHAL_CalibrationInit(railInit->calEnable & 0x10001);
  uVar1 = RFHAL_Init(railInit);
  return uVar1;
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



void RAIL_RfIdleExt(undefined4 mode,bool wait)

{
  RAIL_RadioState_t RVar1;
  
  RFHAL_IdleExt();
  if (wait != false) {
    do {
      RVar1 = RFHAL_StateGet();
    } while (RVar1 != RAIL_RF_STATE_IDLE);
  }
  return;
}



RAIL_RadioState_t RAIL_RfStateGet(void)

{
  uint uVar1;
  bool bVar2;
  
  uVar1 = read_volatile_4(RAC->.STATUS);
  uVar1 = uVar1 & 0xf000000;
  if (uVar1 != 0x6000000) {
    if (0x6000000 < uVar1) {
      if (uVar1 != 0x9000000) {
        if (uVar1 < 0x9000001) {
          if (uVar1 == 0x7000000) {
            return RAIL_RF_STATE_RX;
          }
          bVar2 = uVar1 == 0x8000000;
        }
        else {
          if (uVar1 == 0xb000000) {
            return RAIL_RF_STATE_TX;
          }
          if (uVar1 == 0xc000000) {
            return RAIL_RF_STATE_TX;
          }
          bVar2 = uVar1 == 0xa000000;
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



bool RAIL_ChannelExists(uint16_t channel)

{
  uint uVar1;
  byte bVar2;
  
  bVar2 = 0;
  while( true ) {
    uVar1 = (uint)bVar2;
    if (channelConfig->length <= uVar1) {
      return true;
    }
    if ((channelConfig->configs[uVar1].channelNumberStart <= channel) &&
       (channel <= channelConfig->configs[uVar1].channelNumberEnd)) break;
    bVar2 = bVar2 + 1;
  }
  return false;
}



void RAILInt_TrackChannelConfig(RAIL_ChannelConfig_t *param_1)

{
  channelConfig = param_1;
  return;
}



uint8_t RAILInt_SetChannel(uint8_t channel)

{
  int iVar1;
  uint32_t uVar2;
  RAIL_ChannelConfigEntry_t *pRVar3;
  
  if (((channelConfig != (RAIL_ChannelConfig_t *)0x0) &&
      (pRVar3 = channelConfig->configs, pRVar3 != (RAIL_ChannelConfigEntry_t *)0x0)) &&
     (channelConfig->length != 0)) {
    uVar2 = 0;
    do {
      if ((pRVar3->channelNumberStart <= (ushort)channel) &&
         ((ushort)channel <= pRVar3->channelNumberEnd)) {
        if ((currentEntry == pRVar3) && (currentChannel == channel)) {
          return '\0';
        }
        iVar1 = (int)currentEntry - (int)pRVar3;
        if (iVar1 != 0) {
          iVar1 = 1;
        }
        iVar1 = RFHAL_SetChannel(channel,pRVar3,iVar1);
        if (iVar1 == 0) {
          currentChannel = channel;
          currentEntry = pRVar3;
          return (uint8_t)iVar1;
        }
        return (uint8_t)iVar1;
      }
      uVar2 = uVar2 + 1;
      pRVar3 = pRVar3 + 1;
    } while (uVar2 != channelConfig->length);
  }
  return '\x01';
}




undefined RAILInt_GetChannel(void)

{
  return currentChannel;
}



void RAIL_VersionGet(RAIL_Version_t *version,bool verbose)

{
  version->major = '\x01';
  version->minor = '\x04';
  version->rev = '\x01';
  if (verbose != false) {
    version->build = '\x01';
    version->hash = 0x8cb9ff28;
    version->flags = '\0';
    return;
  }
  version->build = '\0';
  version->hash = 0;
  version->flags = '\0';
  return;
}



RAIL_Status_t RAIL_DebugModeSet(uint32_t DebugMode)

{
  if (RAIL_DebugMode == 1) {
    currentEntry = 0;
  }
  RAIL_DebugMode = DebugMode;
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



int RAIL_SetRxTransitions(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  if (param_2 == 2) {
    return 1;
  }
  iVar1 = RFHAL_StateGet();
  if (iVar1 == 1) {
    iVar1 = 2;
  }
  else {
    iVar1 = RFHAL_SetRxTransitions(param_1,param_2);
    if (iVar1 == 0) {
      iVar1 = RFHAL_ErrorConfig(param_3);
      return iVar1;
    }
  }
  return iVar1;
}



void RAIL_SetFixedLength(void)

{
  RFHAL_SetFixedLength();
  return;
}


