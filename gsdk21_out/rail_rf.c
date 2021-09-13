#include "rail_rf.h"



bool isTransitionState(int param_1)

{
  if (1 < param_1 - 1U) {
    return param_1 == 4;
  }
  return true;
}



undefined4 RAILCore_Init(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = RFHAL_Init();
  if (iVar1 != 0) {
    param_1 = 0;
  }
  return param_1;
}



//undefined4 RAIL_ConfigRadio(int param_1,int param_2)
RAIL_Status_t RAIL_ConfigRadio(RAIL_Handle_t railHandle,
                               RAIL_RadioConfig_t config)
{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    uVar1 = RFHAL_ConfigRadio(param_1 + 0xc);
    return uVar1;
  }
  return 0;
}



//undefined4 RAIL_SetPtiProtocol(int param_1,undefined4 param_2)
RAIL_Status_t RAIL_SetPtiProtocol(RAIL_Handle_t railHandle,
                                  RAIL_PtiProtocol_t protocol)
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = RFHAL_GetRadioState();
  if (iVar1 == 1) {
    uVar2 = RFHAL_SetPtiProtocol(param_1 + 0xc,param_2);
    return uVar2;
  }
  return 2;
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
  if (param_2 != 0) {
    do {
      iVar1 = RFHAL_GetRadioState();
    } while (iVar1 != 1);
  }
  return;
}



void RAILCore_GetRadioState(void)

{
  RFHAL_GetRadioState();
  return;
}



void RAILCore_EnableDirectMode(void)

{
  RFHAL_EnableDirectMode();
  return;
}



//void RAIL_GetSymbolRate(int param_1)
uint32_t RAIL_GetSymbolRate(RAIL_Handle_t railHandle)
{
  RFHAL_GetSymbolRate(param_1 + 0xc);
  return;
}



//void RAIL_GetBitRate(int param_1)
uint32_t RAIL_GetBitRate(RAIL_Handle_t railHandle)
{
  RFHAL_GetBitRate(param_1 + 0xc);
  return;
}



//void RAIL_SetStateTiming(int param_1)
RAIL_Status_t RAIL_SetStateTiming(RAIL_Handle_t railHandle,
                                  RAIL_StateTiming_t *timings)
{
  RFHAL_SetStateTiming(param_1 + 0xc);
  return;
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



//undefined4 RAIL_IsValidChannel(int param_1,uint param_2)
RAIL_Status_t RAIL_IsValidChannel(RAIL_Handle_t railHandle,
                                  uint16_t channel)
{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  while( true ) {
    if (iVar2 == *(int *)(*(int *)(param_1 + 0x2c) + 0xc)) {
      return 1;
    }
    iVar1 = iVar2 * 0x18 + *(int *)(*(int *)(param_1 + 0x2c) + 8);
    if ((*(ushort *)(iVar1 + 0xe) <= param_2) && (param_2 <= *(ushort *)(iVar1 + 0x10))) break;
    iVar2 = iVar2 + 1;
  }
  return 0;
}



int RAILInt_SetChannel(int param_1,uint param_2)

{
  byte bVar1;
  bool bVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 *puVar9;
  int *piVar10;
  uint uVar11;
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
  for (; puVar12 = puVar9, uVar11 < (uint)piVar10[3]; uVar11 = uVar11 + 1) {
    puVar12 = (undefined4 *)(uVar11 * 0x18 + piVar10[2]);
    if ((*(ushort *)((int)puVar12 + 0xe) <= param_2) && (param_2 <= *(ushort *)(puVar12 + 4))) {
      bVar2 = true;
      uVar5 = RAILInt_GetActiveConfig();
      RFHAL_GetTxPowerConfig(param_1,local_30);
      bVar1 = *(byte *)(param_1 + 4);
      if ((*(short *)((int)puVar12 + 0x12) == 0x7fff) ||
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
    uVar11 = RAIL_ConvertDbmToRaw(uVar5,local_30[0],(int)*(short *)((int)puVar12 + 0x12));
  }
  else {
    uVar11 = (uint)*(byte *)(param_1 + 4);
    local_32 = '\0';
  }
  RFHAL_SetTxPower(param_1,uVar11,local_32);
  uVar11 = (uint)*(ushort *)(param_1 + 2);
  if (currentChannelConfig != (int *)0x0) {
    if (((currentChannelConfig == piVar10) && (currentChannelConfigEntry != (undefined4 *)0x0)) &&
       (currentChannelConfigEntry == puVar12)) {
      if (uVar11 == param_2) {
        return 0;
      }
      iVar8 = RFHAL_SetChannel(param_1,param_2,puVar12,0);
      if (iVar8 == 0) {
        *(short *)(param_1 + 2) = (short)param_2;
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
    *(short *)(param_1 + 2) = (short)param_2;
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
  if (currentChannelConfigEntry != (undefined4 *)0x0) {
    RFHAL_ConfigRadio(param_1,*currentChannelConfigEntry);
    RFHAL_SetChannel(param_1,uVar11,currentChannelConfigEntry,0);
  }
  return iVar8;
}



ushort RAILCore_ConfigChannels(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
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
  while ((uVar3 = uVar2, (uint)bVar1 < *(uint *)(param_2 + 0xc) &&
         ((uVar3 = *(ushort *)((uint)bVar1 * 0x18 + *(int *)(param_2 + 8) + 0xe), uVar2 <= uVar3 ||
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
  
  uVar1 = RAILCore_ConfigChannels(param_1 + 0xc);
  RFHAL_SetRadioConfigChangedCallback(param_1 + 0xc,param_3);
  return uVar1;
}



undefined2 RAILInt_GetChannel(int param_1)

{
  return *(undefined2 *)(param_1 + 2);
}



//void RAIL_GetVersion(undefined4 *param_1,int param_2)
void RAIL_GetVersion(RAIL_Version_t *version, bool verbose)
{
  *(undefined *)(param_1 + 1) = 2;
  *(undefined *)((int)param_1 + 5) = 1;
  *(undefined *)((int)param_1 + 6) = 3;
  *(undefined *)((int)param_1 + 9) = 0;
  if (param_2 != 0) {
    *(undefined *)((int)param_1 + 7) = 0;
    *param_1 = 0x6be0298c;
    *(undefined *)(param_1 + 2) = 0;
    return;
  }
  *(undefined *)((int)param_1 + 7) = 0;
  *param_1 = 0;
  *(undefined *)(param_1 + 2) = 0;
  return;
}



//undefined4 RAIL_SetDebugMode(int param_1,undefined4 param_2)
RAIL_Status_t RAIL_SetDebugMode(RAIL_Handle_t railHandle, uint32_t debugMode)
{
  int iVar1;
  bool bVar2;
  
  iVar1 = *(int *)(param_1 + 0x1c);
  *(undefined4 *)(param_1 + 0x1c) = param_2;
  bVar2 = iVar1 == 1;
  if (bVar2) {
    iVar1 = 0;
  }
  if (bVar2) {
    *(int *)(param_1 + 0x30) = iVar1;
  }
  return 0;
}



//undefined4 RAIL_GetDebugMode(int param_1)
uint32_t RAIL_GetDebugMode(RAIL_Handle_t railHandle)
{
  return *(undefined4 *)(param_1 + 0x1c);
}



undefined4 RAILCore_SetTxTransitions(undefined4 param_1,byte *param_2)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  undefined4 uVar4;
  
  bVar1 = *param_2;
  iVar3 = isTransitionState(bVar1);
  if (iVar3 != 0) {
    bVar2 = param_2[1];
    iVar3 = isTransitionState(bVar2);
    if ((iVar3 != 0) && (-1 < (int)((uint)(bVar1 | bVar2) << 0x1d))) {
      iVar3 = RFHAL_GetRadioState();
      if (-1 < iVar3 << 0x1d) {
        uVar4 = RFHAL_SetTxTransitions(param_1,param_2);
        return uVar4;
      }
      return 2;
    }
  }
  return 1;
}



//void RAIL_SetTxTransitions(int param_1)
RAIL_Status_t RAIL_SetTxTransitions(RAIL_Handle_t railHandle,
                                    const RAIL_StateTransitions_t *transitions)
{
  RAILCore_SetTxTransitions(param_1 + 0xc);
  return;
}



undefined4 RAILCore_SetRxTransitions(undefined4 param_1,undefined *param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = isTransitionState(*param_2);
  if (iVar2 != 0) {
    cVar1 = param_2[1];
    iVar2 = isTransitionState(cVar1);
    if ((iVar2 != 0) && (cVar1 != '\x04')) {
      iVar2 = RFHAL_GetRadioState();
      if (-1 < iVar2 << 0x1e) {
        uVar3 = RFHAL_SetRxTransitions(param_1,param_2);
        return uVar3;
      }
      return 2;
    }
  }
  return 1;
}



//void RAIL_SetRxTransitions(int param_1)
RAIL_Status_t RAIL_SetTxTransitions(RAIL_Handle_t railHandle,
                                    const RAIL_StateTransitions_t *transitions)
{
  RAILCore_SetRxTransitions(param_1 + 0xc);
  return;
}



//void RAIL_SetFixedLength(int param_1)
uint16_t RAIL_SetFixedLength(RAIL_Handle_t railHandle, uint16_t length)
{
  RFHAL_SetFixedLength(param_1 + 0xc);
  return;
}



//void RAIL_ConfigEvents(int param_1)
RAIL_Status_t RAIL_ConfigEvents(RAIL_Handle_t railHandle,
                                RAIL_Events_t mask,
                                RAIL_Events_t events)
{
  RFHAL_IntEnable(param_1 + 0xc);
  return;
}



//void RAIL_GetRxFreqOffset(int param_1)
RAIL_FrequencyOffset_t RAIL_GetRxFreqOffset(RAIL_Handle_t railHandle)
{
  RFHAL_GetRxFreqOffset(param_1 + 0xc);
  return;
}



//void RAIL_SetFreqOffset(int param_1)
RAIL_Status_t RAIL_SetFreqOffset(RAIL_Handle_t railHandle,
                                 RAIL_FrequencyOffset_t freqOffset)
{
  RFHAL_SetFreqOffset(param_1 + 0xc);
  return;
}


