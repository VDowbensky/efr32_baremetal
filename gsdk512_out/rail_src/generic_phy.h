#ifndef _GENERIC_PHY_H_
#define _GENERIC_PHY_H_

//callbacks
void GENERIC_PHY_RAC_IRQCallback(void);
void GENERIC_PHY_MODEM_IRQCallback(void);
void GENERIC_PHY_AGC_IRQCallback(void);
void GENERIC_PHY_PROTIMER_IRQCallback(void);
void GENERIC_PHY_FRC_IRQCallback(void);
void GENERIC_PHY_ConfigureCallbacks(uint param_1);
void GENERIC_PHY_SetCallbacks(int param_1);

//void GENERIC_PHY_SYNTH_IRQHandler(void);

//config
void GENERIC_PHY_Init(void);
void GENERIC_PHY_RACConfig(void);
void GENERIC_PHY_PROTIMERConfig(void);
void GENERIC_PHY_FrameConfig(void);
void GENERIC_PHY_DirectModeConfig(byte *param_1);

//TRX control
void GENERIC_PHY_RadioIdle(int abort,int shutdown,int clearflags);
void GENERIC_PHY_ChannelSet(uint8_t channel);
uint16_t GENERIC_PHY_ChannelGet(void);
void RADIO_RACRxAbort(void);
void GENERIC_PHY_StopTx(void);
void GENERIC_PHY_TxDisable(void);
void GENERIC_PHY_PacketTxCommon(void);
bool GENERIC_PHY_PacketTx(void);
void GENERIC_PHY_StartRx(int param_1);

//timing control
bool GENERIC_PHY_TimerStart(uint32_t time,RAIL_TimeMode_t mode)
void GENERIC_PHY_TimerStop(void);
uint32_t GENERIC_PHY_TimerGetTimeout(void);
bool GENERIC_PHY_TimerExpired(void);
bool GENERIC_PHY_TimerIsRunning(void);
undefined4 GENERIC_PHY_SchedulePacketRx(undefined4 param_1,int param_2,int param_3,int param_4,char param_5,undefined param_6);
undefined4 GENERIC_PHY_SchedulePacketTx(undefined4 param_1,undefined4 param_2);
uint32_t GENERIC_PHY_PreviousTxTime(void);

//address filtering
void GENERIC_PHY_SetAddressFilteringMatchTable(void);
bool GENERIC_PHY_EnableAddressFiltering(void);
bool GENERIC_PHY_DisableAddressFiltering(void);
bool GENERIC_PHY_IsEnabledAddressFiltering(void);
void GENERIC_PHY_ResetAddressFiltering(void);
bool GENERIC_PHY_ConfigureAddressFiltering(undefined *param_1);
bool GENERIC_PHY_EnableAddress(uint param_1,uint param_2);
bool GENERIC_PHY_DisableAddress(uint param_1,uint param_2);
bool GENERIC_PHY_SetAddressData(uint param_1,uint param_2,uint param_3,uint param_4,byte param_5,byte *param_6);
int32_t GENERIC_PHY_SetIeeePanId(uint param_1,byte *param_2);
int32_t GENERIC_PHY_SetIeeeShortAddress(uint param_1,byte *param_2);
int32_t GENERIC_PHY_SetIeeeLongAddress(uint param_1,byte *param_2);
bool GENERIC_PHY_SetAddress(uint param_1,uint param_2,byte *param_3,int param_4);

//packets
uint GENERIC_PHY_PacketRxDataHelper(int param_1,uint param_2);
uint GENERIC_PHY_PacketRxAppendedInfoHelper(uint param_1,void *param_2,undefined4 param_3,undefined4 param_4);
uint16_t GENERIC_PHY_PacketRxHelper(int param_1,undefined4 param_2,undefined4 param_3;
void GENERIC_PHY_PacketRxGet(uint16_t *param_1);
void GENERIC_PHY_ResetPacketConfig(void);
void GENERIC_PHY_ConfigureVariableLength(uint param_1,uint param_2,int param_3,int param_4);
void GENERIC_PHY_ConfigureFixedLength(int16_t len);
void GENERIC_PHY_ConfigureFrameType(byte *param_1);

//IEEE802154
bool GENERIC_PHY_EnableIEEE802154(void);
bool GENERIC_PHY_DisableIEEE802154(void);
bool GENERIC_PHY_IsEnabledIEEE802154(void);
bool GENERIC_PHY_CanModifyAck(void);

//special sequencer control
void GENERIC_PHY_SeqAtomicLock(void);
void GENERIC_PHY_SeqAtomicUnlock(void);

#endif
