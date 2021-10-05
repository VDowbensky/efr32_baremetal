#include "rail_autoack.h"



RAIL_Status_t RAIL_AutoAckDisable(void)

{
  RAIL_Status_t RVar1;
  RAIL_Status_t RVar2;
  
  RVar1 = RAIL_SetRxTransitions(RAIL_RF_STATE_IDLE,RAIL_RF_STATE_IDLE,'\0');
  RVar2 = RAIL_SetTxTransitions(RAIL_RF_STATE_IDLE,RAIL_RF_STATE_IDLE);
  if ((RVar2 == RAIL_STATUS_NO_ERROR) && (RVar1 == RAIL_STATUS_NO_ERROR)) 
  {
    RFHAL_AutoAckRxResume();
    RFHAL_AutoAckTxResume();
    RFHAL_AutoAckDisable();
    return RAIL_STATUS_NO_ERROR;
  }
  return RAIL_STATUS_INVALID_PARAMETER;
}



/* void RAIL_AutoAckIsEnabled(void)

{
  RFHAL_AutoAckIsEnabled();
  return;
} */

bool RAIL_AutoAckIsEnabled(void)

{
  return SUB41((SEQ->REG000 << 0x1a) >> 0x1f,0);
}



RAIL_Status_t RAIL_AutoAckConfig(RAIL_AutoAckConfig_t *config)

{
  RAIL_Status_t RVar1;
  RAIL_AutoAckConfig_t *local_18;
  undefined4 local_14;
  
  local_18 = config;
  RVar1 = RAIL_SetRxTransitions(RAIL_RF_STATE_TX,config->defaultState,'\0');
  if ((RAIL_SetRxTransitions(RAIL_RF_STATE_TX,config->defaultState,'\0') == RAIL_STATUS_NO_ERROR) &&(RAIL_SetTxTransitions(RAIL_RF_STATE_RX,config->defaultState) == RAIL_STATUS_NO_ERROR)) 
  {
    local_14 = *(undefined4 *)&config->idleTiming;
    local_18 = (RAIL_AutoAckConfig_t *)CONCAT22(config->turnaroundTime - 10,config->idleTiming);
    RAIL_SetStateTiming((RAIL_StateTiming_t *)&local_18);
    RFHAL_AutoAckConfig(config);
    RFHAL_AutoAckEnable();
  }
  else RVar1 = RAIL_STATUS_INVALID_PARAMETER;
  return RVar1;
}


RAIL_Status_t RAIL_AutoAckLoadBuffer(RAIL_AutoAckData_t *ackData)

{
  if (ackData->dataLength < 0x41) return RFHAL_AutoAckLoadBuffer(ackData);
  else return RAIL_STATUS_INVALID_PARAMETER;
}



/* void RAIL_AutoAckRxPause(void)

{
  RFHAL_AutoAckRxPause();
  return;
} */

void RAIL_AutoAckRxPause(void)

{
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  SEQ->REG000 |= 8;
  CORE_ExitCritical(irqState);
}

/* void RAIL_AutoAckRxResume(void)

{
  RFHAL_AutoAckRxResume();
  return;
} */

void RAIL_AutoAckRxResume(void)

{
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  SEQ->REG000 &= 0xfffffff7;
  CORE_ExitCritical(irqState);
}

/* void RAIL_AutoAckRxIsPaused(void)

{
  RFHAL_AutoAckRxIsPaused();
  return;
} */

bool RAIL_AutoAckRxIsPaused(void)

{
  return SUB41((SEQ->REG000 << 0x1c) >> 0x1f,0);
}

/* void RAIL_AutoAckTxPause(void)

{
  RFHAL_AutoAckTxPause();
  return;
} */

void RAIL_AutoAckTxPause(void)

{
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  SEQ->REG000 |= 0x100;
  CORE_ExitCritical(irqState);
}

/* void RAIL_AutoAckTxResume(void)

{
  RFHAL_AutoAckTxResume();
  return;
} */

void RAIL_AutoAckTxResume(void)

{
  CORE_irqState_t irqState;
  
  irqState = CORE_EnterCritical();
  SEQ->REG000 &= 0xfffffeff;
  CORE_ExitCritical(irqState);
}

/* void RAIL_AutoAckTxIsPaused(void)

{
  RFHAL_AutoAckTxIsPaused();
  return;
} */

bool RAIL_AutoAckTxIsPaused(void)

{
  return SUB41((SEQ->REG000 << 0x17) >> 0x1f,0);
}

/* void RAIL_AutoAckUseTxBuffer(void)

{
  RFHAL_AutoAckUseTxBuffer();
  return;
}
 */
bool RAIL_AutoAckUseTxBuffer(void)

{
  CORE_irqState_t irqState;
  bool bVar2;
  
  irqState = CORE_EnterCritical();
  if (GENERIC_PHY_CanModifyAck() != false) 
  {
    BUS_RegMaskedSet(&RAC->SR0,2);
    bVar2 = -1 < (int)(RAC->SR0 << 0xe);
    if (bVar2) BUS_RegMaskedSet(&RAC->SR2,0x40);
    BUS_RegMaskedClear(&RAC->SR0,2);
  }
  CORE_ExitCritical(irqState);
  return bVar2;
}

/* void RAIL_AutoAckCancelAck(void)

{
  RFHAL_AutoAckCancelAck();
  return;
} */

bool RAIL_AutoAckCancelAck(void)

{
  CORE_irqState_t irqState;
  bool bVar2;
  
  irqState = CORE_EnterCritical();
  if (GENERIC_PHY_CanModifyAck() != false) 
  {
    BUS_RegMaskedSet(&RAC->SR0,2);
    bVar2 = -1 < (int)(RAC->SR0 << 0xe);
    if (bVar2) BUS_RegMaskedSet(&RAC->SR2,0x20);
    BUS_RegMaskedClear(&RAC->SR0,2);
  }
  CORE_ExitCritical(irqState);
  return bVar2;
}

void RAIL_AutoAckWaitingForAck(void)

{
  RFHAL_AutoAckWaitingForAck();
}


