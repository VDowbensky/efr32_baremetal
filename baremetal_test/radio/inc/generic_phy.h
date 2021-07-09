#ifndef _GENERIC_PHY_H_
#define _GENERIC_PHY_H_

#include "em_device.h"
#include <stdint.h>
#include <stdbool.h>
#include "rail_types.h"

void GENERIC_PHY_RAC_IRQCallback(void);
void GENERIC_PHY_PROTIMER_IRQCallback(void);
void GENERIC_PHY_MODEM_IRQCallback(void);
void GENERIC_PHY_FRC_IRQCallback(void);
void GENERIC_PHY_SetAddressFilteringMatchTable(void);
void GENERIC_PHY_ChannelSet(uint16_t ch);
uint16_t GENERIC_PHY_ChannelGet(void);
void GENERIC_PHY_SYNTH_IRQHandler(void);
void GENERIC_PHY_ResetPacketConfig(void);
void GENERIC_PHY_ConfigureFixedLength(uint16_t len);
void GENERIC_PHY_ConfigureFrameType(const RAIL_FrameType_t *frameType);
bool GENERIC_PHY_EnableAddressFiltering(void);
bool GENERIC_PHY_DisableAddressFiltering(void);
bool GENERIC_PHY_IsEnabledAddressFiltering(void);
void GENERIC_PHY_ResetAddressFiltering(void);


void GENERIC_PHY_SeqAtomicLock(void);
void GENERIC_PHY_RadioEnable(uint32_t enable);
void GENERIC_PHY_SeqAtomicUnlock(void);
void GENERIC_PHY_TxDisable(void);
uint32_t  GENERIC_PHY_PreviousTxTime(void);
void GENERIC_PHY_RACConfig(void);
void GENERIC_PHY_PROTIMERConfig(void);
void GENERIC_PHY_Init(void);
RAIL_Status_t GENERIC_PHY_TimerStart(uint32_t time, RAIL_TimeMode_t mode);
bool GENERIC_PHY_TimerIsRunning(void);
bool GENERIC_PHY_TimerExpired(void);
uint32_t GENERIC_PHY_TimerGetTimeout(void);
void GENERIC_PHY_ConfigureCallbacks(uint32_t callbacks);
void GENERIC_PHY_SetCallbacks(int param_1);
void GENERIC_PHY_LoadTxPacketBuffer(uint8_t *buf);
void GENERIC_PHY_FlushTxPacketBuffer(void);
void GENERIC_PHY_PacketTxCommon(void);
uint32_t GENERIC_PHY_PacketTx(void);
uint32_t GENERIC_PHY_SchedulePacketTx(uint32_t param_1,uint32_t param_2);
void GENERIC_PHY_StopTx(void);
uint32_t GENERIC_PHY_PacketRxDataHelper(int32_t param_1,uint32_t param_2);
uint32_t GENERIC_PHY_PacketRxAppendedInfoHelper(uint32_t param_1,void *param_2);
uint32_t GENERIC_PHY_PacketRxHelper(int param_1,uint32_t param_2,uint32_t param_3);
void GENERIC_PHY_PacketRxGet(uint16_t *param_1);
void GENERIC_PHY_StartRx(int param_1);
void GENERIC_PHY_FrameConfig(void);
void GENERIC_PHY_DirectModeConfig(uint8_t *param_1);
void GENERIC_PHY_ConfigureVariableLength(uint32_t param_1,uint32_t param_2,int32_t param_3,int32_t param_4);
uint32_t GENERIC_PHY_ConfigureAddressFiltering(uint8_t *param_1);
uint32_t GENERIC_PHY_EnableAddress(uint32_t param_1,uint32_t param_2);
uint32_t GENERIC_PHY_DisableAddress(uint32_t param_1,uint32_t param_2);
uint32_t GENERIC_PHY_SetAddress(uint32_t param_1,uint32_t param_2,int32_t param_3,int32_t param_4);
uint32_t GENERIC_PHY_SetAddress(uint32_t param_1,uint32_t param_2,int32_t param_3,int32_t param_4);
void GENERIC_PHY_TimerStop(void);


extern uint32_t _enabledCallbacks;


#endif
