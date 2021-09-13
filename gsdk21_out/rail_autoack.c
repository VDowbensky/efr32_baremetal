#include "rail_autoack.h"



// WARNING: Could not reconcile some variable overlaps

uint RAILCore_ConfigAutoAck(undefined4 param_1,byte *param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  byte *local_14;
  
  local_14 = param_2;
  if (*param_2 == 0) {
    RFHAL_EnableAutoAck(param_1,0,param_3,param_4,param_1);
    RFHAL_PauseRxAutoAck(param_1,0);
    RFHAL_PauseTxAutoAck(param_1,0);
  }
  if (*param_2 == 0) {
    bVar4 = param_2[4];
    bVar1 = param_2[5];
  }
  else {
    bVar4 = 4;
    bVar1 = param_2[4];
  }
  local_14._0_2_ = CONCAT11(bVar1,bVar4);
  local_14 = (byte *)((uint)local_14 & 0xffff0000 | (uint)(ushort)local_14);
  uVar2 = RAILCore_SetRxTransitions(param_1,&local_14);
  if (uVar2 == 0) {
    if (*param_2 == 0) {
      bVar4 = param_2[6];
      bVar1 = param_2[7];
    }
    else {
      bVar4 = 2;
      bVar1 = param_2[6];
    }
    local_14._0_2_ = CONCAT11(bVar1,bVar4);
    local_14 = (byte *)((uint)local_14 & 0xffff0000 | (uint)(ushort)local_14);
    uVar3 = RAILCore_SetTxTransitions(param_1,&local_14);
    uVar2 = uVar3;
    if ((uVar3 == 0) && (uVar2 = (uint)*param_2, *param_2 != 0)) {
      RFHAL_SetAutoAckTimeout(param_1,*(undefined2 *)(param_2 + 2));
      RFHAL_EnableAutoAck(param_1,1);
      uVar2 = uVar3;
    }
  }
  return uVar2;
}



void RAIL_ConfigAutoAck(int param_1)

{
  RAILCore_ConfigAutoAck(param_1 + 0xc);
  return;
}



void RAIL_IsAutoAckEnabled(int param_1)

{
  RFHAL_IsAutoAckEnabled(param_1 + 0xc);
  return;
}



undefined4 RAIL_WriteAutoAckFifo(int param_1,undefined4 param_2,uint param_3)

{
  undefined4 uVar1;
  
  if (param_3 < 0x41) {
    uVar1 = RFHAL_WriteAutoAckFifo(param_1 + 0xc);
    return uVar1;
  }
  return 1;
}



void RAIL_UseTxFifoForAutoAck(int param_1)

{
  RFHAL_UseTxFifoForAutoAck(param_1 + 0xc);
  return;
}



void RAIL_CancelAutoAck(int param_1)

{
  RFHAL_CancelAutoAck(param_1 + 0xc);
  return;
}



void RAIL_IsAutoAckWaitingForAck(int param_1)

{
  RFHAL_IsAutoAckWaitingForAck(param_1 + 0xc);
  return;
}



void RAIL_PauseRxAutoAck(int param_1)

{
  RFHAL_PauseRxAutoAck(param_1 + 0xc);
  return;
}



void RAIL_IsRxAutoAckPaused(int param_1)

{
  RFHAL_IsRxAutoAckPaused(param_1 + 0xc);
  return;
}



void RAIL_PauseTxAutoAck(int param_1)

{
  RFHAL_PauseTxAutoAck(param_1 + 0xc);
  return;
}



void RAIL_IsTxAutoAckPaused(int param_1)

{
  RFHAL_IsTxAutoAckPaused(param_1 + 0xc);
  return;
}


