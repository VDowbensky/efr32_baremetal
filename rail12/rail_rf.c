#include "rail_rf.h"



uint8_t RAIL_RfInit(RAIL_Init_t *railInit)

{
  RAIL_Status_t RVar1;
  
  RAIL_RfHalCalibrationInit(railInit->calEnable & 0x10001);
  RVar1 = RAIL_RfHalInit((uint32_t *)railInit);
  return (uint8_t)RVar1;
}



void RAIL_RfIdle(void)

{
  GENERIC_PHY_RadioEnable(false);
  return;
}



RAIL_RadioState_t RAIL_RfStateGet(void)

{
  uint uVar1;
  bool bVar2;
  
  uVar1 = (RAC->STATUS);
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



RAIL_ChannelConfigEntry_t * RAILInt_SetChannelConfig(uint16_t config)

{
  RAIL_ChannelConfigEntry_t *config_00;
  RAIL_ChannelConfigEntry_t *pRVar1;
  RAIL_ChannelConfigEntry_t *pRVar2;
  
  pRVar2 = channelConfig;
  if (channelConfig != (RAIL_ChannelConfigEntry_t *)0x0) {
    config_00 = *(RAIL_ChannelConfigEntry_t **)channelConfig;
    if (config_00 == (RAIL_ChannelConfigEntry_t *)0x0) {
      return (RAIL_ChannelConfigEntry_t *)0x0;
    }
    pRVar2 = (RAIL_ChannelConfigEntry_t *)channelConfig->channelSpacing;
    if (pRVar2 != (RAIL_ChannelConfigEntry_t *)0x0) {
      pRVar1 = (RAIL_ChannelConfigEntry_t *)0x0;
      while ((config < config_00->channelNumberStart || (config_00->channelNumberEnd < config))) {
        pRVar1 = (RAIL_ChannelConfigEntry_t *)((int)&pRVar1->channelNumberStart + 1);
        config_00 = config_00 + 1;
        if (pRVar1 == pRVar2) {
          return (RAIL_ChannelConfigEntry_t *)0x0;
        }
      }
      if (currentConfig != config_00) {
        currentConfig = config_00;
        RAIL_RfHalSetChannelConfig(config_00);
      }
      return currentConfig;
    }
  }
  return pRVar2;
}




void RAILInt_TrackChannelConfig(uint32_t config)

{
  channelConfig = config;
  return;
}



void RAIL_VersionGet(RAIL_Version_t *version,bool verbose)

{
  version->minor = '\x02';
  version->major = '\x01';
  version->rev = '\a';
  if (verbose != false) {
    version->build = '\x01';
    version->hash = 0x5bbde257;
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
    currentConfig = 0;
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
    RVar1 = RAIL_RfHalStateGet();
    if (RVar1 != RAIL_RF_STATE_TX) {
      RVar2 = RAIL_RfHalSetTxTransitions(success,error);
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
  RVar1 = RAIL_RfHalStateGet();
  if (RVar1 == RAIL_RF_STATE_RX) {
    RVar2 = RAIL_STATUS_INVALID_STATE;
  }
  else {
    RVar2 = RAIL_RfHalSetRxTransitions(success,error);
    if (RVar2 == RAIL_STATUS_NO_ERROR) {
      RVar2 = RAIL_RfHalErrorConfig(ignoreErrors);
      return RVar2;
    }
  }
  return RVar2;
}


