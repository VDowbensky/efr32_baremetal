#include "rail_rf.h"

//currentEntry;
//channelConfig;
//currentChannel;
static const unsigned char rail_ver[12UL + 1] = 
{
  0xAD, 0xEB, 0x69, 0x1E, 0x01, 0x05, 0x01, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00
};
uint8_t RAIL_RfInit(const RAIL_Init_t *railInit)

{
  int iVar1;
  undefined4 local_c;
  
  RAILINT_CalibrationEnable(*(uint *)(*railInit + 8) & 0x10001);
  iVar1 = RFHAL_Init(*railInit);
  if (RFHAL_Init(*railInit) == 0) 
  {
    local_c = 0;
    iVar1 = RAIL_DataConfig(&local_c);
  }
  return (uint8_t)iVar1;
}



RAIL_Status_t RAIL_SetPtiProtocol(RAIL_PtiProtocol_t protocol)

{
  if (RFHAL_StateGet() == 0) return RFHAL_SetPtiProtocol(protocol);
  else return 2;
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
	while (RFHAL_StateGet() != 0);
  }
}



RAIL_RadioState_t RAIL_RfStateGet(void)

{
  return RFHAL_StateGet();
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
    if ((*(ushort *)(*channelConfig + iVar2) <= (ushort)channel) && ((ushort)channel <= *(ushort *)(*channelConfig + iVar2 + 2))) break;
    bVar1++;
  }
  return RAIL_STATUS_NO_ERROR;
}



void RAILInt_TrackChannelConfig(undefined4 param_1)

{
  channelConfig = param_1;
}



int RAILInt_SetChannel(uint param_1)

{
  int iVar1;
  ushort *puVar2;
  ushort *puVar3;
  
  if (((channelConfig != (ushort **)0x0) && (puVar3 = *channelConfig, puVar3 != (ushort *)0x0)) &&
     (channelConfig[1] != (ushort *)0x0)) {
    puVar2 = (ushort *)0x0;
    do {
      if (((uint)*puVar3 <= (param_1 & 0xffff)) && ((param_1 & 0xffff) <= (uint)puVar3[1])) {
        if ((currentEntry == puVar3) && (currentChannel == param_1)) {
          return 0;
        }
        iVar1 = (int)currentEntry - (int)puVar3;
        if (iVar1 != 0) {
          iVar1 = 1;
        }
        iVar1 = RFHAL_SetChannel(param_1,puVar3,iVar1);
        if (iVar1 == 0) {
          currentChannel = (char)param_1;
          currentEntry = puVar3;
          return 0;
        }
        return iVar1;
      }
      puVar2 = (ushort *)((int)puVar2 + 1);
      puVar3 = puVar3 + 6;
    } while (puVar2 != channelConfig[1]);
  }
  return 1;
}



undefined RAILInt_GetChannel(void)

{
  return currentChannel;
}



void RAIL_VersionGet(RAIL_Version_t * version, bool verbose)

{
  *(undefined *)(version + 1) = 1;
  *(undefined *)((int)version + 5) = 5;
  *(undefined *)((int)version + 6) = 1;
  if (verbose != false) {
    *(undefined *)((int)version + 7) = 7;
    *version = 0x1e69ebad;
    *(undefined *)(version + 2) = 0;
    return;
  }
  *(undefined *)((int)version + 7) = 0;
  *version = 0;
  *(undefined *)(version + 2) = 0;
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
  if ((success == 2) || (error == 2)) return RAIL_STATUS_INVALID_PARAMETER;
  else 
  {
    if (RFHAL_StateGet() != 2) return RFHAL_SetTxTransitions(success,error);
  }
  return RAIL_STATUS_INVALID_PARAMETER;
}



RAIL_Status_t RAIL_SetRxTransitions(RAIL_RadioState_t success,RAIL_RadioState_t error,uint8_t ignoreErrors)

{
  if (error == 2) return RAIL_STATUS_INVALID_PARAMETER;
  if (RFHAL_StateGet() == 1) return RAIL_STATUS_INVALID_STATE;
  else 
  {
    if (RFHAL_SetRxTransitions(success,error) == 0) return RFHAL_ErrorConfig(ignoreErrors);
  }
  return RAIL_STATUS_INVALID_PARAMETER;
}



uint16_t RAIL_SetFixedLength(uint16_t length)

{
  RFHAL_SetFixedLength(length);
}


