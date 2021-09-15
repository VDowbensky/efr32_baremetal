#include "rail_rf.h"



bool isTransitionState(int param_1)

{
  if (1 < param_1 - 1U) return param_1 == 4;
  return true;
}



undefined4 RAILCore_Init(undefined4 param_1)

{
  if (RFHAL_Init() != 0) param_1 = 0;
  return param_1;
}


RAIL_Status_t RAIL_ConfigRadio(RAIL_Handle_t railHandle,
                               RAIL_RadioConfig_t config)
{
  if (config != NULL) return  RFHAL_ConfigRadio(railHandle + 0xc, config);
  return 0;
}


RAIL_ENUM(RAIL_PtiProtocol_t) {
  RAIL_PTI_PROTOCOL_CUSTOM = 0, /**< PTI output for a custom protocol */
  RAIL_PTI_PROTOCOL_THREAD = 2, /**< PTI output for the Thread protocol */
  RAIL_PTI_PROTOCOL_BLE = 3, /**< PTI output for the Bluetooth Smart protocol */
  RAIL_PTI_PROTOCOL_CONNECT = 4, /**< PTI output for the Connect protocol */
  RAIL_PTI_PROTOCOL_ZIGBEE = 5, /**< PTI output for the zigbee protocol */
};
//undefined4 RAIL_SetPtiProtocol(int param_1,undefined4 param_2)
RAIL_Status_t RAIL_SetPtiProtocol(RAIL_Handle_t railHandle,RAIL_PtiProtocol_t protocol)
{
  if (RFHAL_GetRadioState() == 1) return RFHAL_SetPtiProtocol(railHandle + 0xc,protocol);
  else return 2;
}



undefined4 RAILInt_GetActiveChannelConfigEntry(void)

{
  return currentChannelConfigEntry;
}



undefined4 RAILInt_GetActiveChannelConfig(void)

{
  return currentChannelConfig;
}



void RAILCore_Idle(undefined4 param_1,int param_2)

{
  int iVar1;
  
  RFHAL_Idle();
  if (param_2 != 0) 
  {
	while (RFHAL_GetRadioState() != 1);
  }
  return;
}



void RAILCore_GetRadioState(void)

{
  return RFHAL_GetRadioState();
}



void RAILCore_EnableDirectMode(void)

{
  RFHAL_EnableDirectMode();
  return;
}



//void RAIL_GetSymbolRate(int param_1)
uint32_t RAIL_GetSymbolRate(RAIL_Handle_t railHandle)
{
  return RFHAL_GetSymbolRate(param_1 + 0xc);
}



//void RAIL_GetBitRate(int param_1)
uint32_t RAIL_GetBitRate(RAIL_Handle_t railHandle)
{
  return RFHAL_GetBitRate(param_1 + 0xc);
}



//void RAIL_SetStateTiming(int param_1)
RAIL_Status_t RAIL_SetStateTiming(RAIL_Handle_t railHandle,
                                  RAIL_StateTiming_t *timings)
{
  return RFHAL_SetStateTiming(param_1 + 0xc);
}



void RAILCore_InitTimerSync(void)

{
  RFHAL_InitTimerSync();
  return;
}



void RAILCore_Wake(void)

{
  RFHAL_Wake();
  return;
}



void RAILCore_Sleep(void)

{
  RFHAL_Sleep();
  return;
}



//undefined4 RAIL_IsValidChannel(int param_1,uint32_t param_2)
RAIL_Status_t RAIL_IsValidChannel(RAIL_Handle_t railHandle,
                                  uint16_t channel)
{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  while( true ) 
  {
    if (iVar2 == *(int *)(*(int *)(param_1 + 0x2c) + 0xc)) return 1;
    iVar1 = iVar2 * 0x18 + *(int *)(*(int *)(param_1 + 0x2c) + 8);
    if ((*(uint16_t *)(iVar1 + 0xe) <= param_2) && (param_2 <= *(uint16_t *)(iVar1 + 0x10))) break;
    iVar2 = iVar2 + 1;
  }
  return 0;
}



int RAILInt_SetChannel(int param_1,uint32_t param_2)

{
  uint8_t bVar1;
  bool bVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  uint32_t uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 *puVar9;
  int *piVar10;
  uint32_t uVar11;
  undefined4 *puVar12;
  char local_32;
  undefined local_30 [12];
  
  puVar4 = currentChannelConfigEntry;
  piVar3 = currentChannelConfig;
  piVar10 = *(int **)(param_1 + 0x20);
  puVar9 = *(undefined4 **)(param_1 + 0x24);
  uVar11 = 0;
  local_32 = '\0';
  bVar2 = false;
  if (((piVar10 == (int *)0x0) || (piVar10[2] == 0)) || (piVar10[3] == 0)) {
    return 3;
  }
  for (; puVar12 = puVar9, uVar11 < (uint32_t)piVar10[3]; uVar11 = uVar11 + 1) {
    puVar12 = (undefined4 *)(uVar11 * 0x18 + piVar10[2]);
    if ((*(uint16_t *)((int)puVar12 + 0xe) <= param_2) && (param_2 <= *(uint16_t *)(puVar12 + 4))) {
      bVar2 = true;
      uVar5 = RAILInt_GetActiveConfig();
      RFHAL_GetTxPowerConfig(param_1,local_30);
      bVar1 = *(uint8_t *)(param_1 + 4);
      if ((*(int16_t *)((int)puVar12 + 0x12) == 0x7fff) ||
         (uVar6 = RAIL_ConvertDbmToRaw(uVar5,local_30[0]), puVar9 = puVar12, bVar1 <= uVar6)) {
        local_32 = '\x01';
        break;
      }
    }
  }
  uVar5 = RAILInt_GetActiveConfig();
  RFHAL_GetTxPowerConfig(param_1,local_30);
  uVar7 = RFHAL_GetTxPower(param_1);
  if (local_32 == '\0') {
    if (!bVar2) {
      return 1;
    }
    uVar11 = RAIL_ConvertDbmToRaw(uVar5,local_30[0],(int)*(int16_t *)((int)puVar12 + 0x12));
  }
  else {
    uVar11 = (uint32_t)*(uint8_t *)(param_1 + 4);
    local_32 = '\0';
  }
  RFHAL_SetTxPower(param_1,uVar11,local_32);
  uVar11 = (uint32_t)*(uint16_t *)(param_1 + 2);
  if (currentChannelConfig != (int *)0x0) {
    if (((currentChannelConfig == piVar10) && (currentChannelConfigEntry != NULL)) &&
       (currentChannelConfigEntry == puVar12)) {
      if (uVar11 == param_2) {
        return 0;
      }
      iVar8 = RFHAL_SetChannel(param_1,param_2,puVar12,0);
      if (iVar8 == 0) {
        *(int16_t *)(param_1 + 2) = (int16_t)param_2;
        return 0;
      }
      RFHAL_SetTxPower(param_1,uVar7,0);
      RFHAL_SetChannel(param_1,uVar11,currentChannelConfigEntry,0);
      return iVar8;
    }
    if ((*currentChannelConfig != 0) && (*currentChannelConfig == *piVar10)) {
      iVar8 = currentChannelConfig[1];
      goto LAB_0001022a;
    }
  }
  iVar8 = *piVar10;
LAB_0001022a:
  iVar8 = RFHAL_ConfigRadio(param_1,iVar8);
  if ((iVar8 == 0) && (iVar8 = RFHAL_ConfigRadio(param_1,*puVar12), iVar8 == 0)) {
    *(undefined4 **)(param_1 + 0x24) = puVar12;
    *(int16_t *)(param_1 + 2) = (int16_t)param_2;
    currentChannelConfig = piVar10;
    currentChannelConfigEntry = puVar12;
    iVar8 = RFHAL_SetChannel(param_1,param_2,puVar12,1);
    if (iVar8 == 0) {
      RFHAL_IssueRadioConfigChangedCallback(puVar12);
      return 0;
    }
  }
  currentChannelConfig = piVar3;
  currentChannelConfigEntry = puVar4;
  if (piVar3 != (int *)0x0) {
    RFHAL_ConfigRadio(param_1,*piVar3);
  }
  RFHAL_SetTxPower(param_1,uVar7,0);
  if (currentChannelConfigEntry != NULL) {
    RFHAL_ConfigRadio(param_1,*currentChannelConfigEntry);
    RFHAL_SetChannel(param_1,uVar11,currentChannelConfigEntry,0);
  }
  return iVar8;
}



uint16_t RAILCore_ConfigChannels(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  uint8_t bVar1;
  uint16_t uVar2;
  uint16_t uVar3;
  int iVar4;
  
  iVar4 = param_2;
  if (param_2 != 0) {
    iVar4 = 1;
  }
  RAILInt_Assert(iVar4,0x1f,param_3,param_4,param_4);
  *(int *)(param_1 + 0x20) = param_2;
  RAILInt_Assert(iVar4,0x1f);
  bVar1 = 0;
  uVar2 = 0xffff;
  while ((uVar3 = uVar2, (uint32_t)bVar1 < *(uint32_t *)(param_2 + 0xc) &&
         ((uVar3 = *(uint16_t *)((uint32_t)bVar1 * 0x18 + *(int *)(param_2 + 8) + 0xe), uVar2 <= uVar3 ||
          (uVar2 = uVar3, uVar3 != 0))))) {
    bVar1 = bVar1 + 1;
  }
  RAILInt_SetChannel(param_1,uVar3);
  return uVar3;
}



//undefined4 RAIL_ConfigChannels(int param_1,undefined4 param_2,undefined4 param_3)
uint16_t RAIL_ConfigChannels(RAIL_Handle_t railHandle,
                             const RAIL_ChannelConfig_t *config,
                             RAIL_RadioConfigChangedCallback_t cb)
{
  undefined4 uVar1;
  
  uVar1 = RAILCore_ConfigChannels(railHandle + 0xc, &config);
  RFHAL_SetRadioConfigChangedCallback(railHandle + 0xc,cb);
  return uVar1;
}



undefined2 RAILInt_GetChannel(int param_1)

{
  return *(undefined2 *)(param_1 + 2);
}


/* typedef struct RAIL_Version {
  uint32_t hash;  
  uint8_t  major;   
  uint8_t  minor;   
  uint8_t  rev;      
  uint8_t  build;    
  uint8_t  flags;     
  bool     multiprotocol;
} RAIL_Version_t; */
//void RAIL_GetVersion(undefined4 *param_1,int param_2)
void RAIL_GetVersion(RAIL_Version_t *version, bool verbose)
{
  *(undefined *)(version + 1) = 2;
  *(undefined *)((int)version + 5) = 1;
  *(undefined *)((int)version + 6) = 3;
  *(undefined *)((int)version + 9) = 0;
  if (verbose == true) 
  {
    *(undefined *)((int)version + 7) = 0;
    *version = 0x6be0298c;
    *(undefined *)(version + 2) = 0;
    return;
  }
  *(undefined *)((int)version + 7) = 0;
  *version = 0;
  *(undefined *)(version + 2) = 0;
  return;
}



//undefined4 RAIL_SetDebugMode(int param_1,undefined4 param_2)
RAIL_Status_t RAIL_SetDebugMode(RAIL_Handle_t railHandle, uint32_t debugMode)
{
  int iVar1;
  bool bVar2;
  
  iVar1 = *(int *)(railHandle + 0x1c);
  *(undefined4 *)(railHandle + 0x1c) = debugMode;
  bVar2 = iVar1 == 1;
  if (bVar2) iVar1 = 0;
  if (bVar2) *(int *)(railHandle + 0x30) = iVar1;
  return RAIL_STATUS_NO_ERROR;
}



//undefined4 RAIL_GetDebugMode(int param_1)
uint32_t RAIL_GetDebugMode(RAIL_Handle_t railHandle)
{
  return *(uint32_t *)(railHandle + 0x1c);
}



RAIL_Status_t RAILCore_SetTxTransitions(undefined4 param_1,uint8_t *param_2)

{
  uint8_t bVar1;
  uint8_t bVar2;
  int iVar3;
  undefined4 uVar4;
  
  bVar1 = *param_2;
  if (isTransitionState(bVar1) != 0) 
  {
    bVar2 = param_2[1];
    if ((isTransitionState(bVar2) != 0) && (-1 < (int)((uint32_t)(bVar1 | bVar2) << 0x1d))) 
	{
      if (-1 < RFHAL_GetRadioState() << 0x1d) return RFHAL_SetTxTransitions(param_1,param_2);
      return RAIL_STATUS_INVALID_STATE;
    }
  }
  return RAIL_STATUS_INVALID_PARAMETER;
}



//void RAIL_SetTxTransitions(int param_1)
RAIL_Status_t RAIL_SetTxTransitions(RAIL_Handle_t railHandle,
                                    const RAIL_StateTransitions_t *transitions)
{
  return RAILCore_SetTxTransitions(railHandle + 0xc);
}



RAIL_Status_t RAILCore_SetRxTransitions(undefined4 param_1,undefined *param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = isTransitionState(*param_2);
  if (iVar2 != 0) 
  {
    cVar1 = param_2[1];
    if ((isTransitionState(cVar1) != 0) && (cVar1 != '\x04')) 
	{
      if (-1 < RFHAL_GetRadioState() << 0x1e) return RFHAL_SetRxTransitions(param_1,param_2);
      return RAIL_STATUS_INVALID_STATE;
    }
  }
  return RAIL_STATUS_INVALID_PARAMETER;
}



//void RAIL_SetRxTransitions(int param_1)
RAIL_Status_t RAIL_SetTxTransitions(RAIL_Handle_t railHandle,const RAIL_StateTransitions_t *transitions)
{
  return RAILCore_SetRxTransitions(param_1 + 0xc);
}



//void RAIL_SetFixedLength(int param_1)
uint16_t RAIL_SetFixedLength(RAIL_Handle_t railHandle, uint16_t length)
{
  return RFHAL_SetFixedLength(railHandle + 0xc,length);
}



//void RAIL_ConfigEvents(int param_1)
RAIL_Status_t RAIL_ConfigEvents(RAIL_Handle_t railHandle,
                                RAIL_Events_t mask,
                                RAIL_Events_t events)
{
  return RFHAL_IntEnable(railHandle + 0xc);
}



//void RAIL_GetRxFreqOffset(int param_1)
RAIL_FrequencyOffset_t RAIL_GetRxFreqOffset(RAIL_Handle_t railHandle)
{
  return RFHAL_GetRxFreqOffset(railHandle + 0xc);
}



//void RAIL_SetFreqOffset(int param_1)
RAIL_Status_t RAIL_SetFreqOffset(RAIL_Handle_t railHandle,
                                 RAIL_FrequencyOffset_t freqOffset)
{
  return RFHAL_SetFreqOffset(param_1 + 0xc,freqOffset);
}


