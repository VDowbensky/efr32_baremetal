#include "rail_autoack.h"



RAIL_Status_t RAIL_AutoAckDisable(void)

{
  if ((RAIL_SetTxTransitions(0,0) == 0) && (RAIL_SetRxTransitions(0,0,0) == 0)) 
  {
    RFHAL_AutoAckRxResume();
    RFHAL_AutoAckTxResume();
    RFHAL_AutoAckDisable();
    return RAIL_STATUS_NO_ERROR;
  }
  else return RAIL_STATUS_INVALID_PARAMETER;
}



bool RAIL_AutoAckIsEnabled(void)

{
  return RFHAL_AutoAckIsEnabled();
}



//uint32_t RAIL_AutoAckConfig(uint32_t _config)
RAIL_Status_t RAIL_AutoAckConfig(RAIL_AutoAckConfig_t *config)
{
  int iVar1;
  uint32_t uVar2;
  uint32_t local_18;
  undefined4 local_14;
  
  local_18 = *config;
  iVar1 = RAIL_SetRxTransitions(2,*(undefined *)config,0);
  if ((iVar1 == 0) && (uVar2 = RAIL_SetTxTransitions(1,*(undefined *)config), uVar2 == 0)) 
  {
    local_14 = *(undefined4 *)(config + 2);
    local_18 = CONCAT22(*(short *)(config + 4) + -10,*(undefined2 *)(undefined4 *)(config + 2));
    RAIL_SetStateTiming(&local_18);
    RFHAL_AutoAckConfig(*config);
    uVar2 = RFHAL_AutoAckEnable(); //???
  }
  else uVar2 = 1;
  return uVar2;
}



//undefined4 RAIL_AutoAckLoadBuffer(int _ackData)
RAIL_Status_t RAIL_AutoAckLoadBuffer(RAIL_AutoAckData_t *ackData)
{
  undefined4 uVar1;
  
  if (*(byte *)(ackData + 4) < 0x41) return RFHAL_AutoAckLoadBuffer();
  else return RAIL_STATUS_INVALID_PARAMETER;
}



void RAIL_AutoAckRxPause(void)

{
  RFHAL_AutoAckRxPause();
}



void RAIL_AutoAckRxResume(void)

{
  RFHAL_AutoAckRxResume();
}



bool RAIL_AutoAckRxIsPaused(void)

{
  return RFHAL_AutoAckRxIsPaused();
}



void RAIL_AutoAckTxPause(void)

{
  RFHAL_AutoAckTxPause();
}



void RAIL_AutoAckTxResume(void)

{
  RFHAL_AutoAckTxResume();
}



bool RAIL_AutoAckTxIsPaused(void)

{
  return RFHAL_AutoAckTxIsPaused();
}



bool RAIL_AutoAckUseTxBuffer(void)

{
  return RFHAL_AutoAckUseTxBuffer();
}



bool RAIL_AutoAckCancelAck(void)

{
  return RFHAL_AutoAckCancelAck();
}



bool RAIL_AutoAckWaitingForAck(void)

{
  return RFHAL_AutoAckWaitingForAck();
}


