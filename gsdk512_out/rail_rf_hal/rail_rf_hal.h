#ifndef _RAIL_RFHAL_H_
#define _RAIL_RFHAL_H_

void pktTxDoneEvt(undefined4 param_1,undefined4 param_2,undefined4 param_3);
void pktRxFrmErr(void);
void pktRxOverflow(void);
void filterPass(void);
void pktRxAborted(void);
void preambleDetected(void);
void frameDet0(void);
void frameDet1(void);void rxFifoUnderflow(void);
void RAIL_RFSENSE_Callback(void);
void protmrRetry(void);
void protmrStartCca(void);
void txFifoOverflow(void);
void racStateChange(void);
void softwareTimerExpired(void);
void rxFifoAlmostFull(void);
void txFifoAlmostEmpty(void);
void racCalRequest(void);
void pktRxDoneEvt(void);

void rxTimeout(int param_1);
void sequencerInterrupt(int param_1);
void rssiAverageDone(void);
bool userTransmitStarted(void);
void pktTxErrorEvt(uint param_1);
void protmrLbtEvt(int param_1);
uint8_t RFHAL_Init(int param_1);

RAIL_Status_t RFHAL_SetPtiProtocol(RAIL_PtiProtocol_t protocol);
void RFHAL_IdleExt(RAIL_RfIdleMode_t mode);
RAIL_RadioState_t RFHAL_StateGet(void);
bool RFHAL_OkToTransmit(void);
int RFHAL_HeadedToIdle(void);
uint8_t RFHAL_TxDataLoad(RAIL_TxData_t *txData);
uint8_t RAIL_CcaCsma(void *params);
uint8_t RAIL_CcaLbt(void *params);
void RFHAL_SetCcaThreshold(void);
int16_t RFHAL_PollAverageRSSI(int32_t time)

{
  int16_t sVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  bool bVar10;
  
  if (time == 0) return RADIO_GetRSSI();

  uVar3 = PROTIMER_GetTime();
  uVar4 = PROTIMER_UsToPrecntOverflow(time);
  iVar2 = 0;
  uVar8 = 0;
  iVar9 = 0;
  while(true) 
  {
    uVar5 = PROTIMER_GetTime();
    uVar6 = PROTIMER_ElapsedTime(uVar3,uVar5);
    if (PROTIMER_GetTime() <= PROTIMER_ElapsedTime(uVar3,uVar5)) break;
    iVar7 = RADIO_GetRSSI();
    if (iVar7 != -0x200) 
	{
      uVar6 = SEXT24((int16_t)iVar7);
      bVar10 = CARRY4(uVar8,uVar6);
      uVar8 = uVar8 + uVar6;
      iVar9 = iVar9 + ((int)uVar6 >> 0x1f) + (uint)bVar10;
      iVar2 = iVar2 + 1;
    }
  }
  if (iVar2 == 0) return -0x200;
  else return (int)(__aeabi_ldivmod(uVar8,iVar9,iVar2,iVar2 >> 0x1f));
}



int RFHAL_StartAverageRSSI(undefined4 param_1,undefined4 param_2)

{
  int iVar2;
  
  isRssiReady = 0;
  saveRssiPeriod = AGC->CTRL1;
  if (RADIO_CalcRssiPeriod(param_2) == 0) 
  {
    //if (_DAT_430c0354 != 0) iVar2 = 1;
	if (MODEM->CTRL0 & MODEM_CTRL0_DETDIS_Msk) iVar2 = 1;
    saveFrameDetDisable = (uint8_t)iVar2;
    BUS_RegMaskedSet(&MODEM->CTRL0,0x200000);
    if (RAIL_RxStart(param_1) == 0) 
	{
      _enabledCallbacks = _enabledCallbacks | 0x4000000;
      GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
	  return 0;
    }
    else return 2;
  }
  else return 1;
}



int16_t RFHAL_GetAverageRSSI(void)

{
  return (int16_t)currentRssiAverage;
}



bool RFHAL_AverageRSSIReady(void)

{
  return isRssiReady;
}

typedef struct RAIL_ScheduleRxConfig {
  uint32_t start;
  RAIL_TimeMode_t startMode;
  uint32_t end;
  RAIL_TimeMode_t endMode;
  uint8_t rxTransitionEndSchedule;
  uint8_t hardWindowEnd;
} RAIL_ScheduleRxConfig_t;



//void RFHAL_ScheduleRx(undefined4 param_1,undefined4 *param_2)
uint8_t RFHAL_ScheduleRx(uint8_t channel, RAIL_ScheduleRxConfig_t *cfg)
{
  undefined4 uVar1;
  undefined4 uVar2;
  char cVar3;
  uint uVar4;
  char cVar5;
  char cVar6;
  
  cVar6 = *(char *)(cfg + 1);
  if (cVar6 == 2) uVar1 = 0;
  else 
  {
    uVar1 = PROTIMER_UsToPrecntOverflow(cfg->start);
    cVar6 = *(char *)(cfg + 1);
    if (cVar6 != 0) cVar6 = 1;
  }
  cVar5 = *(char *)(cfg + 3);
  if (cVar5 == 2) uVar2 = 0;
  else 
  {
    uVar2 = PROTIMER_UsToPrecntOverflow(cfg[2]);
    cVar5 = *(char *)(cfg + 3);
    if (cVar5 != 1) cVar5 = 1;
  }
  uVar4 = count_leading_zeroes((uint)*(uint8_t *)((int)cfg + 0xd));
  cVar3 = *(char *)((int)cfg + 0xe);
  if (cVar3 != 0) cVar3 = 1;
  GENERIC_PHY_SchedulePacketRx(uVar1,cVar6,uVar2,cVar5,uVar4 >> 5,cVar3);
}



void RAIL_ScheduleTx(undefined4 *param_1)

{
  undefined4 uVar1;
  char cVar2;
  
  cVar2 = *(char *)(param_1 + 1);
  if (cVar2 != 0) cVar2 = 1;
  GENERIC_PHY_SchedulePacketTx(PROTIMER_UsToPrecntOverflow(*param_1),cVar2);
}



//undefined4 RFHAL_RxStart(void)
uint8_t RFHAL_RxStart(uint8_t channel)
{
  if ((RAC->RXENSRCEN & 0xff) == 0) BUFC_RxBufferReset();
  GENERIC_PHY_StartRx(channel);
  return 0;
}



undefined4 RFHAL_EnableRxRawCapture(int param_1,uint param_2)

{
  if (param_1 - 1U & 0xff < 3) param_2 = *(uint *)(&CSWTCH_104 + (param_1 - 1U & 0xff) * 4);
  if (2 < uVar2) param_2 = 0;
  MODEM->CTRL0 &= 0xc7ffffff;
  MODEM->CTRL0 |= param_2;
  BUS_RegMaskedSet(&MODEM->CTRL0,0x200000);
  FRC->BUFFERMODE &= 0xfffffff9;
  FRC->BUFFERMODE |= 4;
  BUS_RegMaskedSet(&RAC->SR3,0x10000000);
  FRC->RAWCTRL = 4;
  return 0;
}



void RFHAL_DisableRxRawCapture(void)

{
  BUS_RegMaskedClear(&FRC->BUFFERMODE,6);
  FRC->RAWCTRL = 0;
  BUS_RegMaskedClear(&RAC->SR3,0x10000000);
  BUS_RegMaskedClear(&MODEM->CTRL0,0x200000);
  BUS_RegMaskedClear(&MODEM->CTRL0,0x38000000);
}



void RFHAL_EnableRxAppendedInfo(void)

{
  FRC->TRAILRXDATA = 0x1b;
}



void RFHAL_DisableRxAppendedInfo(void)

{
  FRC->TRAILRXDATA = 0;
}

//undefined4 RFHAL_RxIntEnable(uint param_1)
uint32_t RFHAL_RxIntEnable(uint32_t cbToEnable);
{
  _enabledCallbacks =
       CONCAT11(DAT_000113b1 & 0xc5 | (uint8_t)(((cbToEnable << 0x1e) >> 0x1f) << 3) |
                (uint8_t)(((cbToEnable << 0x1d) >> 0x1f) << 4) | (uint8_t)(((cbToEnable << 0x1c) >> 0x1f) << 5)
                | (uint8_t)(((cbToEnable << 0x14) >> 0x1f) << 1),
                enabledCallbacks & 0x87 | (uint8_t)(((cbToEnable << 0x1b) >> 0x1f) << 3) |
                (uint8_t)(((cbToEnable << 0x1a) >> 0x1f) << 4) | (uint8_t)(((cbToEnable << 0x15) >> 0x1f) << 5)
                | ((cbToEnable & 0x300) != 0) << 6);
  _enabledCallbacks = _enabledCallbacks & 0xffff0000 | (uint)_enabledCallbacks;
  bufcEnabledCallbacks =
       bufcEnabledCallbacks & 0xffffff00 |
       (uint)((uint8_t)bufcEnabledCallbacks & 0xf7 | (uint8_t)(cbToEnable << 3) & 8);
  rxConfigEvents = cbToEnable;
  GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
  BUFC_ConfigureCallbacks(bufcEnabledCallbacks);
  return 0;
}


RAIL_Status_t RFHAL_SetRxOptions(uint32_t options)
{
  if ((RAC->STATUS << 4) >> 0x1c == 3) return RAIL_STATUS_INVALID_STATE;
  options &= 1;
  if (options == 0) BUS_RegMaskedClear(&FRC->RXCTRL,1);
  else 
  {
    options = 0;
    BUS_RegMaskedSet(&FRC->RXCTRL,1);
  }
  return (RAIL_Status_t)options;
}


uint32_t RFHAL_TxIntEnable(uint32_t cbToEnable)
{
  _enabledCallbacks =
       CONCAT12(DAT_000113b2 & 0x7f | 0x40 | (uint8_t)(((cbToEnable << 0x19) >> 0x1f) << 7),
                _enabledCallbacks);
  _enabledCallbacks =
       _enabledCallbacks & 0xffffff00 |
       (uint)(uint8_t)((uint8_t)(_enabledCallbacks >> 0x18) & 0xfe | (uint8_t)cbToEnable >> 7) << 0x18 |
       (uint)(uint8_t)(enabledCallbacks & 0xfd | ((cbToEnable & 0x1b) != 0) << 1);
  bufcEnabledCallbacks =
       bufcEnabledCallbacks & 0xffffff00 |
       (uint)((uint8_t)bufcEnabledCallbacks & 0xfd | (uint8_t)(cbToEnable << 1) & 2);
  txConfigEvents = cbToEnable;
  GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
  BUFC_ConfigureCallbacks(bufcEnabledCallbacks);
  return 0;
}



RAIL_Status_t RFHAL_ErrorConfig(uint8_t ignoreErrors)
{
  if ((ignoreErrors & 1) == 0) BUS_RegMaskedClear(&FRC->RXCTRL,2);
  else BUS_RegMaskedSet(&FRC->RXCTRL,2);
  return RAIL_STATUS_NO_ERROR;
}



RAIL_Status_t RAIL_PaCtuneSet(uint8_t txPaCtuneValue, uint8_t rxPaCtuneValue);

{
  return PA_CTuneSet(txPaCtuneValue, rxPaCtuneValue);
}


uint32_t RAIL_TimerGet(void)

{
  return PROTIMER_PrecntOverflowToUs(GENERIC_PHY_TimerGetTimeout());
}



void RAIL_TimerCancel(void)

{
  undefined4 extraout_r1;
  undefined4 in_r3;
  
  GENERIC_PHY_TimerStop();
  _enabledCallbacks = _enabledCallbacks & 0xfdffffff;
  GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks,extraout_r1,DAT_000113b3 & 0xfd,in_r3);
}


RAIL_Status_t RAIL_TimerSet(uint32_t time, RAIL_TimeMode_t mode);
{
  uint8_t bVar1;
  uint32_t tmp;
  int iVar4;
  
  if (mode != 0) iVar4 = 1;
  if (mode == 2) 
  {
    RAIL_TimerCancel();
    return RAIL_STATUS_NO_ERROR;
  }
  tmp = CORE_EnterCritical();
  _enabledCallbacks = _enabledCallbacks | 0x2000000;
  GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
  timerExpired = 0;
  bVar1 = GENERIC_PHY_TimerStart(PROTIMER_UsToPrecntOverflow(time),iVar4);
  CORE_ExitCritical(tmp);
  return (RAIL_Status_t)(bVar1 ^ 1);
}



bool RAIL_TimerExpired(void)

{
  if (GENERIC_PHY_TimerExpired() != 0) return true;
  else return timerExpired & 1;
}



bool RAIL_TimerIsRunning(void)

{
  return GENERIC_PHY_TimerIsRunning();
}


uint32_t RAIL_SymbolRateGet(void)

{
  return RADIO_ComputeTxSymbolRate();
}



uint32_t RAIL_BitRateGet(void)

{
  return RADIO_ComputeTxBitRate();
}


//void RAIL_RfSense(undefined param_1,undefined4 param_2,int param_3,uint param_4)
uint32_t RAIL_RfSense(RAIL_RfSenseBand_t band, uint32_t senseTime, bool enableCb);
{
  code *local_14;
  undefined4 local_10;
  uint local_c;
  
  local_14 = RAIL_RFSENSE_Callback;
  if (param_3 == 0) local_14 = (code *)0x0;
  local_c._0_2_ = CONCAT11(1,param_1);
  local_c = param_4 & 0xffff0000 | (uint)(uint16_t)local_c;
  local_10 = param_2;
  RFSENSE_Init(&local_14);
}


bool RAIL_RfSensed(void)

{
  return RFSENSE_Sensed();
}


//void RAIL_DebugCbConfig(int param_1)
void RAIL_DebugCbConfig(uint32_t cbToEnable)
{
  _enabledCallbacks = CONCAT11(DAT_000113b1 & 0x7f | (uint8_t)(((uint)(cbToEnable << 0x1e) >> 0x1f) << 7),enabledCallbacks);
  _enabledCallbacks = _enabledCallbacks & 0xffff0000 | (uint)_enabledCallbacks;
  GENERIC_PHY_ConfigureCallbacks(_enabledCallbacks);
}


void RFHAL_CalibrationInit(int param_1)

{
  IRCAL_Init(*(undefined4 *)(param_1 + 4));
}



void RFHAL_CalibrationRun(int *param_1,int param_2)

{
  int iVar1;
  
  if (param_2 << 0x1f < 0) TEMPCAL_Perform();
  if (param_2 << 0xf < 0) 
  {
    if (*param_1 == -1) 
	{
      iVar1 = IRCAL_Perform();
      *param_1 = iVar1;
      return;
    }
    IRCAL_Set();
    return;
  }
  return;
}


RAIL_Status_t RFHAL_SetTxTransitions(RAIL_RadioState_t success,RAIL_RadioState_t error);
{
  SEQ->REG00C &= 0x0000ffff;
  SEQ->REG00C |= (1 << (success + 0x10U & 0xff)) | (1 << (error + 0x18U & 0xff));
  return RAIL_STATUS_NO_ERROR;
}


RAIL_Status_t RFHAL_SetRxTransitions(RAIL_RadioState_t success,RAIL_RadioState_t error);
{
  SEQ->REG00C &= 0xffff0000;
  SEQ->REG00C  |= (1 << (error + 8U & 0xff) | 1 << (success & 0xff));
  return RAIL_STATUS_NO_ERROR;
}



//void RFHAL_SetBerConfig(undefined4 *param_1)
void RFHAL_SetBerConfig(RAIL_BerConfig_t *berConfig);
{
  RFTEST_ResetBerStats(*berConfig);
}



void RFHAL_StartBerRx(void)

{
  RFTEST_SaveRadioConfiguration();
  FRC->SNIFFCTRL = 0;
  FRC->DFLCTRL = 5;
  BUS_RegMaskedClear(&MODEM->TIMING,0xf00);
  PTR_rxFifoAlmostFull_00011398 = &RFTEST_BerEmptyBufcAndUpdateStats;
  BUFC_SetCallbacks();
  bufcEnabledCallbacks &= 0xffffff00;
  bufcEnabledCallbacks |= 4;
  BUFC_ConfigureCallbacks(bufcEnabledCallbacks);
  BUFC->BUF1_THRESHOLDCTRL &= 0xfffff000;
  BUFC->BUF1_THRESHOLDCTRL |= 100;
  BUS_RegMaskedSet(&BUFC->IEN,0x400);
  RFTEST_StartRx();
}



void RFHAL_StopBerRx(void)

{
  RFTEST_BerStop();
  bufcEnabledCallbacks &= 0xffffff00;
  bufcEnabledCallbacks |= bufcEnabledCallbacks & 0xfb);
  BUFC_ConfigureCallbacks(bufcEnabledCallbacks);
  BUS_RegMaskedClear(&BUFC->IEN,0x400);
  RFTEST_RestoreRadioConfiguration();
}


void RFHAL_GetBerStatus(RAIL_BerStatus_t *status)
{
  RFTEST_ReportBerStats(&status);
}



void RFHAL_SetCRCInitVal(uint16_t val)

{
  RADIO_SetCRCInitVal(val);
}



int32_t RFHAL_GetCurrPowerLevel(void)

{
  return PA_OutputPowerGet();
}

int32_t RFHAL_SetCurrPowerLevel(int32_t powerLevel)
{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar2 = PA_OutputPowerSet(powerLevel);
  pcVar1 = protChChngCB;
  if (protChChngCB != NULL) 
  {
    uVar3 = RAILInt_GetChannel();
    (*pcVar1)(uVar3,1);
  }
  return uVar2;
}



void RFHAL_SetProtocolSpecificChCheckCB(uint32_t cb)

{
  protChChngCB = cb;
}



void RFHAL_StopTestMode(void)

{
  RFTEST_StopTx();
  RFTEST_RestoreRadioConfiguration();
}



void RFHAL_StartCWTestMode(void)

{
  RFTEST_SaveRadioConfiguration();
  RFTEST_StartCwTx();
}



void RFHAL_StartStreamTestMode(void)

{
  RFTEST_SaveRadioConfiguration();
  RFTEST_StartStreamTx();
}



uint32_t RFHAL_SetChannel(int param_1,uint8_t *cfg,int param_3)

{
  if (RAIL_DebugModeGet() != 1) 
  {
    do 
	{
      if (RFHAL_HeadedToIdle() == 0) break;
    } while ((RAC->STATUS & 0xf000000) != 0);
    if ((RAC->STATUS & 0xf000000) != 0) return 2;
    if (protChChngCB != NULL) (*protChChngCB)(param_1);
    if (param_3 != 0) SYNTH_Config(*(uint32_t *)(cfg + 8),*(uint32_t *)(cfg + 4));
    GENERIC_PHY_ChannelSet(param_1 - (uint)*cfg & 0xff);
  }
  return 0;
}



bool RFHAL_AutoAckEnable(void)

{
  uint32_t tmp;
  uint32_t reg;
  tmp = CORE_EnterCritical();
  reg = SEQ->REG000;
  SEQ->REG000 |= 0x20;
  CORE_ExitCritical(tmp);
  return (reg << 0x1a) >> 0x1f;
}



bool RFHAL_AutoAckDisable(void)

{
  uint32_t tmp;
  uint32_t reg;
  tmp = CORE_EnterCritical();
  reg = SEQ->REG000;
  SEQ->REG000 &= 0xffffffdf;
  CORE_ExitCritical(tmp);
  return (reg << 0x1a) >> 0x1f;
}



bool RFHAL_AutoAckIsEnabled(void)

{
  return (SEQ->REG000 << 0x1a) >> 0x1f;
}


void RFHAL_AutoAckConfig(RAIL_AutoAckConfig_t *config)
{
  SEQ->REG008 = -(PROTIMER_UsToPrecntOverflow(*(uint16_t *)(config + 6)));
}


//typedef struct RAIL_AutoAckData {
//  uint8_t *dataPtr; /**< Pointer to ack data to transmit */
//  uint8_t dataLength; /**< Number of ack bytes to transmit */
//} RAIL_AutoAckData_t;
//undefined4 RFHAL_AutoAckLoadBuffer(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
RAIL_Status_t RFHAL_AutoAckLoadBuffer(RAIL_AutoAckData_t *ackData)
{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  RAC *pRVar4;
  undefined4 uVar5;
  
  uVar2 = CORE_EnterCritical();
  BUS_RegMaskedSet(&RAC->SR0,2);
  pRVar4 = &RAC;
  uVar3 = (RAC->STATUS << 4) >> 0x1c;
  if (((uVar3 - 7 < 3) || (uVar3 == 0xc)) && (uVar1 = (RAC->SR0), pRVar4 = (RAC *)(uVar1 << 0xe), (int)pRVar4 < 0)) uVar5 = 3;
  else 
  {
    BUFC_TxAckBufferSet(*param_1,*(undefined *)(param_1 + 1),uVar3,pRVar4,param_4);
    uVar5 = 0;
  }
  BUS_RegMaskedClear(&RAC->SR0,2);
  CORE_ExitCritical(uVar2);
  return uVar5;
}



void RFHAL_AutoAckRxPause(void)

{
  uint32_t tmp;
  
  tmp = CORE_EnterCritical();
  SEQ->REG000 |= 8;
  CORE_ExitCritical(tmp);
}



void RFHAL_AutoAckRxResume(void)

{
  uint32_t tmp;
  
  tmp = CORE_EnterCritical();
  SEQ->REG000 &= 0xfffffff7;
  CORE_ExitCritical(tmp);
}



void RFHAL_AutoAckTxPause(void)

{
  uint32_t tmp;
  
  tmp = CORE_EnterCritical();
  SEQ->REG000 |= 0x100;
  CORE_ExitCritical(tmp);
}



void RFHAL_AutoAckTxResume(void)

{
  uint32_t tmp;
  
  tmp = CORE_EnterCritical();
  SEQ->REG000 &= 0xfffffeff;
  CORE_ExitCritical(tmp);
}



bool RFHAL_AutoAckRxIsPaused(void)

{
  return (SEQ->REG000 << 0x1c) >> 0x1f;
}



bool RFHAL_AutoAckTxIsPaused(void)

{
  return (SEQ->REG000 << 0x17) >> 0x1f;
}



bool RFHAL_AutoAckUseTxBuffer(void)

{
  undefined4 uVar1;
  uint uVar2;
  bool bVar3;
  
  uVar1 = CORE_EnterCritical();
  if (GENERIC_PHY_CanModifyAck() != 0) 
  {
    BUS_RegMaskedSet(&RAC->SR0,2);
    bVar3 = -1 < (int)(RAC->SR0 << 0xe);
    if (bVar3) BUS_RegMaskedSet(&RAC->SR2,0x40);
    uVar2 = (uint32_t)bVar3;
    BUS_RegMaskedClear(&RAC->SR0,2);
  }
  CORE_ExitCritical(uVar1);
  return uVar2;
}



bool RFHAL_AutoAckCancelAck(void)

{
  uint32_t tmp;
  uint uVar2;
  bool bVar3;
  
  tmp = CORE_EnterCritical();
  uVar2 = GENERIC_PHY_CanModifyAck();
  if (GENERIC_PHY_CanModifyAck() == 0) 
  {
	CORE_ExitCritical(tmp);
	return false;
  }
  else
  {
    BUS_RegMaskedSet(&RAC->SR0,2);
    uVar2 = (RAC->SR0);
    bVar3 = -1 < (int)(RAC->SR0 << 0xe);
    if (-1 < (int)(RAC->SR0 << 0xe)) BUS_RegMaskedSet(&RAC->SR2,0x20);
    uVar2 = (uint32_t)bVar3;
    BUS_RegMaskedClear(&RAC->SR0,2);
	return uVar2;
  }

}



void RFHAL_AutoAckWaitForAck(int enable)

{
  if (enable == 0) BUS_RegMaskedSet(&RAC->SR0,0x100);
  else BUS_RegMaskedClear(&RAC->SR0,0x100);
}



//code * RFHAL_TxStart(undefined4 param_1,undefined *param_2,code *param_3,undefined4 param_4)
//uint8_t RAIL_TxStartWithOptions(uint8_t channel,RAIL_TxOptions_t *options,RAIL_PreTxOp_t preTxOp,void *preTxOpParams);
uint8_t RFHAL_TxStart(uint8_t channel,RAIL_TxOptions_t *options,code void *preTxOpParams,RAIL_PreTxOp_t preTxOp)

{
  if ((preTxOpParams != NULL) && (RFHAL_AutoAckIsEnabled() != 0)) RFHAL_AutoAckWaitForAck(*options);
  if (preTxOpParams == NULL) GENERIC_PHY_PacketTx();
  else 
  {
    preTxOpParams = (code *)(*preTxOpParams)(preTxOp);
    if (preTxOpParams != NULL) 
	{
      BUS_RegMaskedClear(&RAC->SR0,0x100);
      return preTxOpParams;
    }
  }
  return preTxOpParams;
}



bool RFHAL_AutoAckWaitingForAck(void)

{
  return (RAC->SR1 << 0x1c) >> 0x1f;
}


uint16_t RFHAL_WriteTxFifo(uint8_t *dataPtr, uint16_t writeLength)
{
  if (BUFC_GetSpaceAvailable(0) <= writeLength) writeLength = BUFC_GetSpaceAvailable(0);
  BUFC_WriteBuffer(0,dataPtr,writeLength);
  return writeLength;
}


uint16_t RFHAL_ReadRxFifo(uint8_t *dataPtr, uint16_t readLength)
{
  if (BUFC_GetBytesAvailable(1) <= readLength) readLength = BUFC_GetBytesAvailable(1);
  BUFC_ReadBuffer(1,dataPtr,readLength);
  return readLength;
}

//typedef struct RAIL_AppendedInfo {
//  uint32_t timeUs;
//  bool crcStatus:1;
//  bool frameCodingStatus:1;
//  bool isAck:1;
//  int8_t rssiLatch;
//  uint8_t lqi;
//  uint8_t syncWordId;
//} RAIL_AppendedInfo_t;

//void RFHAL_ReadRxFifoAppendedInfo(undefined4 *param_1)
void RFHAL_ReadRxFifoAppendedInfo(RAIL_AppendedInfo_t *appendedInfo)
{
  uint uVar1;
  undefined4 uVar2;
  undefined auStack28 [5];
  undefined local_17;
  uint8_t local_16;
  undefined4 local_10;
  
  uVar2 = RADIO_RxTrailDataLength();
  GENERIC_PHY_PacketRxAppendedInfoHelper(uVar2,auStack28);
  read_volatile(FRC->IEN._0_1_);
  
  uVar1 = FRC->IF;
  *(uint8_t *)(param_1 + 1) = *(uint8_t *)(param_1 + 1) & 0xfd | (uint8_t)((((uVar1 ^ 0x80) << 0x18) >> 0x1f) << 1);
  FRC->IFC = 0x80;
  if (local_16 != 0) local_16 = 1;
  *(undefined *)((int)param_1 + 5) = local_17;
  *(uint8_t *)(param_1 + 1) = *(uint8_t *)(param_1 + 1) & 0xfe | local_16 & 1;
  uVar2 = TIMING_GetRxTimestampUs(local_10);
  *param_1 = uVar2;
  *(undefined *)((int)param_1 + 7) = 0;
}


uint16_t RFHAL_SetRxFifoThreshold(uint16_t rxThreshold)
{
  if (rxThreshold < 0x201) rxThreshold = rxThreshold | BUFC->BUF1_THRESHOLDCTRL & 0xfffff000;
  else rxThreshold = BUFC->BUF1_THRESHOLDCTRL & 0xfffff000 | 0x200;
  BUFC->BUF1_THRESHOLDCTRL = rxThreshold;
  return BUFC->BUF1_THRESHOLDCTRL & 0xfff;
}



uint16_t RFHAL_GetTxFifoThreshold(void)

{
  return (BUFC->BUF0_THRESHOLDCTRL & 0xfff) + 1;
}

uint16_t RFHAL_SetTxFifoThreshold(uint16_t txThreshold)
{
  if (0x1ff < txThreshold) txThreshold = 0x200;
  BUFC->BUF0_THRESHOLDCTRL &= 0xfffff000;
  BUFC->BUF0_THRESHOLDCTRL |= (txThreshold - 1) & 0xffff;
  return RFHAL_GetTxFifoThreshold();
}



uint16_t RFHAL_GetRxFifoThreshold(void)

{
  return BUFC->BUF1_THRESHOLDCTRL & 0xfff;
}



void RFHAL_EnableRxFifoThreshold(void)

{
  BUS_RegMaskedSet(&BUFC->IEN,0x400);
}



void RFHAL_DisableRxFifoThreshold(void)

{
  BUS_RegMaskedClear(&BUFC->IEN,0x400);
}



uint16_t RFHAL_GetTxFifoSpaceAvailable(void)

{
  return BUFC_GetSpaceAvailable(0);
}



uint16_t RFHAL_GetRxFifoBytesAvailable(void)

{
  return BUFC_GetBytesAvailable(1);
}



void RFHAL_ResetTxFifo(void)

{
  BUS_RegMaskedClear(&BUFC->IEN,4);
  BUFC->BUF0_CMD = 1;
  BUS_RegMaskedClear(&BUFC->BUF0_THRESHOLDCTRL,0x2000);
  BUS_RegMaskedSet(&BUFC->IEN,4);
}



void RFHAL_ResetRxFifo(void)

{
  BUS_RegMaskedClear(&BUFC->IEN,0x400);
  BUFC->BUF1_CMD = 1;
  BUS_RegMaskedClear(&BUFC->BUF1_THRESHOLDCTRL,0x2000);
  BUS_RegMaskedSet(&BUFC->IEN,0x400);
}


RAIL_Status_t RFHAL_DataConfig(RAIL_DataConfig_t *dataConfig)
{
  if (*(char *)(dataConfig + 2) == *(char *)(dataConfig + 3)) 
  {
    if (*(char *)(dataConfig + 1) == '\0') RFHAL_DisableRxRawCapture();
    else RFHAL_EnableRxRawCapture();
    if (*(char *)(dataConfig + 2) == '\0') bufcEnabledCallbacks = bufcEnabledCallbacks & 0xffffff00 | (uint)((uint8_t)bufcEnabledCallbacks & 0xfe);
    else 
	{
      bufcEnabledCallbacks = bufcEnabledCallbacks & 0xffffff00 | (uint)((uint8_t)bufcEnabledCallbacks | 1);
      RFHAL_ResetTxFifo();
    }
    if (*(char *)(dataConfig + 3) == '\0') 
	{
      bufcEnabledCallbacks = bufcEnabledCallbacks & 0xffffff00 | (uint)((uint8_t)bufcEnabledCallbacks & 0xfb);
      BUS_RegMaskedSet(&FRC->RXCTRL,0x60);
      BUS_RegMaskedClear(&RAC->SR0,0x40);
      BUS_RegMaskedClear(&FRC->RXCTRL,2);
    }
    else 
	{
      bufcEnabledCallbacks = bufcEnabledCallbacks | 4;
      BUS_RegMaskedClear(&FRC->RXCTRL,0x60);
      RFHAL_ResetRxFifo();
      BUS_RegMaskedSet(&RAC->SR0,0x40);
      BUS_RegMaskedSet(&FRC->RXCTRL,2);
    }
    BUFC_ConfigureCallbacks(bufcEnabledCallbacks);
    return RAIL_STATUS_NO_ERROR;
  }
  return RAIL_STATUS_INVALID_PARAMETER;
}


uint16_t RFHAL_SetFixedLength(uint16_t length)

{
  if (((FRC->DFLCTRL & 7) != 0) && ((FRC->DFLCTRL & 7) != 5)) return 0xffff;
  if (length == 0) 
  {
	FRC->DFLCTRL &= 0xfffffff8;
	FRC->DFLCTRL |= 5;
    return 0;
  }
  BUS_RegMaskedClear(&FRC->DFLCTRL,7);
  if (0xfff < length) length = 0x1000;
  FRC->WCNTCMP0 = length - 1;
  return length;
}


#endif