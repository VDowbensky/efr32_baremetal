#include "rail_autoack.h"



// WARNING: Could not reconcile some variable overlaps

uint32_t RAILCore_ConfigAutoAck(undefined4 param_1,uint8_t *param_2,undefined4 param_3,undefined4 param_4)

{
  uint8_t bVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint8_t bVar4;
  uint8_t *local_14;
  
  local_14 = param_2;
  if (*param_2 == 0) 
  {
    RFHAL_EnableAutoAck(param_1,0,param_3,param_4,param_1);
    RFHAL_PauseRxAutoAck(param_1,0);
    RFHAL_PauseTxAutoAck(param_1,0);
  }
  if (*param_2 == 0) 
  {
    bVar4 = param_2[4];
    bVar1 = param_2[5];
  }
  else 
  {
    bVar4 = 4;
    bVar1 = param_2[4];
  }
  local_14._0_2_ = CONCAT11(bVar1,bVar4);
  local_14 = (uint8_t *)((uint32_t)local_14 & 0xffff0000 | (uint32_t)(uint16_t)local_14);
  uVar2 = RAILCore_SetRxTransitions(param_1,&local_14);
  if (uVar2 == 0) 
  {
    if (*param_2 == 0) 
	{
      bVar4 = param_2[6];
      bVar1 = param_2[7];
    }
    else 
	{
      bVar4 = 2;
      bVar1 = param_2[6];
    }
    local_14._0_2_ = CONCAT11(bVar1,bVar4);
    local_14 = (uint8_t *)((uint32_t)local_14 & 0xffff0000 | (uint32_t)(uint16_t)local_14);
    uVar3 = RAILCore_SetTxTransitions(param_1,&local_14);
    uVar2 = uVar3;
    if ((uVar3 == 0) && (uVar2 = (uint32_t)*param_2, *param_2 != 0)) 
	{
      RFHAL_SetAutoAckTimeout(param_1,*(undefined2 *)(param_2 + 2));
      RFHAL_EnableAutoAck(param_1,1);
      uVar2 = uVar3;
    }
  }
  return uVar2;
}

/* typedef struct RAIL_AutoAckConfig {
  bool enable;
  uint16_t ackTimeout;
  RAIL_StateTransitions_t rxTransitions;
  RAIL_StateTransitions_t txTransitions;
} RAIL_AutoAckConfig_t; */

//void RAIL_ConfigAutoAck(int param_1)
RAIL_Status_t RAIL_ConfigAutoAck(RAIL_Handle_t railHandle,
                                 const RAIL_AutoAckConfig_t *config)
{
  RAILCore_ConfigAutoAck(param_1 + 0xc);
  return;
}



//void RAIL_IsAutoAckEnabled(int param_1)
bool RAIL_IsAutoAckEnabled(RAIL_Handle_t railHandle)
{
  RFHAL_IsAutoAckEnabled(param_1 + 0xc);
  return;
}



//undefined4 RAIL_WriteAutoAckFifo(int param_1,undefined4 param_2,uint32_t param_3)
RAIL_Status_t RAIL_WriteAutoAckFifo(RAIL_Handle_t railHandle,
                                    const uint8_t *ackData,
                                    uint8_t ackDataLen)
{
  if (param_3 < 0x41) return RFHAL_WriteAutoAckFifo(param_1 + 0xc);
  else return 1;
}



//void RAIL_UseTxFifoForAutoAck(int param_1)
RAIL_Status_t RAIL_UseTxFifoForAutoAck(RAIL_Handle_t railHandle)
{
  RFHAL_UseTxFifoForAutoAck(param_1 + 0xc);
  return;
}



//void RAIL_CancelAutoAck(int param_1)
RAIL_Status_t RAIL_CancelAutoAck(RAIL_Handle_t railHandle)
{
  RFHAL_CancelAutoAck(param_1 + 0xc);
  return;
}



//void RAIL_IsAutoAckWaitingForAck(int param_1)
bool RAIL_IsAutoAckWaitingForAck(RAIL_Handle_t railHandle)
{
  RFHAL_IsAutoAckWaitingForAck(param_1 + 0xc);
  return;
}



//void RAIL_PauseRxAutoAck(int param_1)
void RAIL_PauseRxAutoAck(RAIL_Handle_t railHandle,
                         bool pause);
{
  RFHAL_PauseRxAutoAck(param_1 + 0xc);
  return;
}



//void RAIL_IsRxAutoAckPaused(int param_1)
bool RAIL_IsRxAutoAckPaused(RAIL_Handle_t railHandle)
{
  RFHAL_IsRxAutoAckPaused(param_1 + 0xc);
  return;
}



//void RAIL_PauseTxAutoAck(int param_1)
void RAIL_PauseTxAutoAck(RAIL_Handle_t railHandle, bool pause)
{
  RFHAL_PauseTxAutoAck(param_1 + 0xc);
  return;
}



//void RAIL_IsTxAutoAckPaused(int param_1)
bool RAIL_IsTxAutoAckPaused(RAIL_Handle_t railHandle)
{
  RFHAL_IsTxAutoAckPaused(param_1 + 0xc);
  return;
}


