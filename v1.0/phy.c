#include "phy.h"



uint16_t validateSetTiming(uint16_t *timing)

{
  uint16_t uVar1;
  
  if (*timing < 0x3c) {
    uVar1 = 0x3c;
  }
  else {
    uVar1 = 13000;
    if (*timing < 0x32c9) goto LAB_00010014;
  }
  *timing = uVar1;
LAB_00010014:
  return *timing;
}



uint8_t RAIL_RadioConfig(void *radioConfig)

{
  RADIO_Config(radioConfig);
  forceIrCal = 1;
  return '\0';
}



uint8_t RAIL_ChannelConfig(RAIL_ChannelConfig_t *config)

{
  int iVar1;
  undefined4 uVar2;
  
  RAILInt_TrackChannelConfig();
  SYNTH_Config(config->configs->baseFrequency,config->configs->channelSpacing);
  iVar1 = SYNTH_Is2p4GHz();
  if (iVar1 == 0) {
    uVar2 = 3500000;
  }
  else {
    uVar2 = 7000000;
  }
  SYNTH_DCDCRetimeClkSet(uVar2);
  if (forceIrCal != '\0') {
    forceIrCal = '\0';
    RFHAL_CalibrationPend(0x10000);
  }
  return *(uint8_t *)&config->configs->channelNumberStart;
}



void RAIL_DirectModeConfig(bool enable)

{
  undefined1 *puVar1;
  
  if (enable == false) {
    puVar1 = &directModeDisableConfig;
  }
  else {
    puVar1 = &directModeEnableConfig;
  }
  GENERIC_PHY_DirectModeConfig(puVar1);
  return;
}



uint8_t RAIL_TxToneStart(uint8_t channel)

{
  uint8_t uVar1;
  
  uVar1 = RAILInt_SetChannel(channel);
  if (uVar1 == '\0') {
    RFHAL_StartCWTestMode();
  }
  return uVar1;
}




/* uint8_t RAIL_TxToneStop(void)

{
  RFTEST_StopTx();
  RFTEST_RestoreRadioConfiguration();
  return 0;
}
 */
uint8_t RAIL_TxToneStop(void)

{
  RFHAL_StopTestMode();
  return '\0';
}

uint8_t RAIL_TxStreamStart(uint8_t channel,RAIL_StreamMode_t mode)

{
  uint8_t uVar1;
  
  if (mode == 1) {
    uVar1 = RAILInt_SetChannel(channel);
    if (uVar1 == '\0') {
      RFHAL_StartStreamTestMode();
    }
    return uVar1;
  }
  return '\x01';
}



uint8_t RAIL_TxStreamStop(void)

{
  RFTEST_StopTx();
  RFTEST_RestoreRadioConfiguration();
  return 0;
}



int32_t RAIL_TxPowerSet(int32_t powerLevel);

{
  PA_OutputPowerSet();
  return;
}

/* int32_t RAIL_TxPowerSet(int32_t powerLevel)

{
  code *pcVar1;
  byte bVar2;
  undefined4 uVar3;
  
  bVar2 = PA_OutputPowerSet((uint8_t)powerLevel);
  pcVar1 = protChChngCB;
  if (protChChngCB != FUN_00000000) {
    uVar3 = RAILInt_GetChannel();
    (*pcVar1)(uVar3,1);
  }
  return (uint)bVar2;
} */

void RAIL_TxPowerGet(void)

{
  return PA_OutputPowerGet();
}

/* int32_t RAIL_TxPowerGet(void)

{
  return (int)gPaConfig.power;
}
 */

RAIL_Status_t RAIL_DebugFrequencyOverride(uint32_t freq)

{
  SYNTH_Config(freq,0);
  return RAIL_STATUS_NO_ERROR;
}



void RAIL_PacketLengthConfigFrameType(RAIL_FrameType_t *frameType)

{
  GENERIC_PHY_ConfigureFrameType();
  return;
}

/* void RAIL_PacketLengthConfigFrameType(RAIL_FrameType_t *frameType)

{
  char cVar1;
  uint uVar2;
  
  GENERIC_PHY_ResetPacketConfig();
  if (frameType == (RAIL_FrameType_t *)0x0) {
    memset(&Peripherals::SEQ.REG05C,0,0xc);
    return;
  }
  write_volatile_1(Peripherals::SEQ.REG05C._0_1_,frameType->offset);
  write_volatile_1(Peripherals::SEQ.REG05C._1_1_,frameType->mask);
  write_volatile_1(Peripherals::SEQ.REG05C._2_1_,0);
  write_volatile_4(Peripherals::SEQ.REG060,(uint)frameType->frameLen);
  write_volatile_4(Peripherals::SEQ.REG064,(uint)frameType->isValid);
  uVar2 = (uint)frameType->mask;
  if (uVar2 != 0) {
    while (-1 < (int)(uVar2 << 0x1f)) {
      cVar1 = read_volatile_1(Peripherals::SEQ.REG05C._2_1_);
      uVar2 = uVar2 >> 1;
      write_volatile_1(Peripherals::SEQ.REG05C._2_1_,cVar1 + '\x01');
    }
  }
  write_volatile_4(Peripherals::FRC.WCNTCMP0,frameType->offset + 1);
  uVar2 = read_volatile_4(Peripherals::SEQ.REG000);
  write_volatile_4(Peripherals::SEQ.REG000,uVar2 | 7);
  return;
} */

int16_t RAIL_RxGetRSSI(void)

{
  return RADIO_GetRSSI();
}



void RAIL_SetTune(uint32_t tune)

{
  uint uVar1;
  
  CMU_ClockSelectSet(cmuClock_HF,cmuSelect_HFRCO);
  CMU_OscillatorEnable(cmuOsc_HFXO,false,false);
  uVar1 = read_volatile_4(Peripherals::CMU.HFXOSTEADYSTATECTRL);
  write_volatile_4(Peripherals::CMU.HFXOSTEADYSTATECTRL,uVar1 & 0xfff007ff);
  uVar1 = read_volatile_4(Peripherals::CMU.HFXOSTEADYSTATECTRL);
  write_volatile_4(Peripherals::CMU.HFXOSTEADYSTATECTRL,(tune & 0x1ff) << 0xb | uVar1);
  CMU_OscillatorEnable(cmuOsc_HFXO,true,true);
  CMU_ClockSelectSet(cmuClock_HF,cmuSelect_HFXO);
  return;
}



uint32_t RAIL_GetTune(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::CMU.HFXOSTEADYSTATECTRL);
  return (uVar1 << 0xc) >> 0x17;
}




uint32_t RAIL_GetTime(void)

{
  uint32_t uVar1;
  
  uVar1 = PROTIMER_GetTime();
  uVar1 = PROTIMER_PrecntOverflowToUs(uVar1);
  return uVar1;
}



RAIL_Status_t RAIL_SetTime(uint32_t time)

{
  bool bVar1;
  RAIL_Status_t RVar2;
  
  bVar1 = PROTIMER_SetTime(time);
  if (bVar1 == false) {
    RVar2 = RAIL_STATUS_INVALID_STATE;
  }
  else {
    RVar2 = RAIL_STATUS_NO_ERROR;
  }
  return RVar2;
}



RAIL_Status_t RAIL_SetStateTiming(RAIL_StateTiming_t *timings)

{
  uint16_t uVar1;
  
  uVar1 = RADIO_RxWarmTimeSet(timings->idleToRx);
  timings->idleToRx = uVar1;
  uVar1 = RADIO_TxToRxTimeSet(timings->txToRx);
  timings->txToRx = uVar1;
  uVar1 = RADIO_TxWarmTimeSet(timings->idleToTx);
  timings->idleToTx = uVar1;
  uVar1 = RADIO_RxFrameToTxTimeSet(timings->rxToTx);
  timings->rxToTx = uVar1;
  return RAIL_STATUS_NO_ERROR;
}




bool RAIL_AddressFilterConfig(RAIL_AddrConfig_t *addrConfig)

{
  byte bVar1;
  undefined uVar2;
  undefined4 in_r3;
  int iVar3;
  uint8_t local_1c [4];
  uint32_t local_18;
  undefined4 local_14;
  
  bVar1 = addrConfig->numFields;
  if (bVar1 < 3) {
    local_14 = in_r3;
    memset(local_1c,0,0xc);
    for (iVar3 = 0; iVar3 < (int)(uint)bVar1; iVar3 = iVar3 + 1) {
      local_1c[iVar3] = addrConfig->offsets[iVar3];
      local_1c[iVar3 + 2] = addrConfig->sizes[iVar3];
    }
    local_18 = addrConfig->matchTable;
    local_14 = CONCAT31(local_14._1_3_,0xff);
    uVar2 = GENERIC_PHY_ConfigureAddressFiltering(local_1c);
  }
  else {
    uVar2 = 0;
  }
  return (bool)uVar2;
}


bool RAIL_AddressFilterByFrameType(uint8_t validFrames)

{
  write_volatile_1(Peripherals::SEQ.REG058._2_1_,validFrames);
  return true;
}



bool RAIL_AddressFilterEnable(void)

{
  return GENERIC_PHY_EnableAddressFiltering();
}

/* bool RAIL_AddressFilterEnable(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::SEQ.REG000);
  write_volatile_4(Peripherals::SEQ.REG000,uVar1 | 0x10);
  return SUB41((uVar1 << 0x1b) >> 0x1f,0);
} */


bool RAIL_AddressFilterDisable(void)

{
  return GENERIC_PHY_DisableAddressFiltering();
}

/* bool RAIL_AddressFilterDisable(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::SEQ.REG000);
  write_volatile_4(Peripherals::SEQ.REG000,uVar1 & 0xffffffef);
  return SUB41((uVar1 << 0x1b) >> 0x1f,0);
}
 */
bool RAIL_AddressFilterIsEnabled(void)

{
  return GENERIC_PHY_IsEnabledAddressFiltering();
}

/* bool RAIL_AddressFilterIsEnabled(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::SEQ.REG000);
  return SUB41((uVar1 << 0x1b) >> 0x1f,0);
} */

void RAIL_AddressFilterReset(void)

{
  GENERIC_PHY_ResetAddressFiltering();
  return;
}

/* void RAIL_AddressFilterReset(void)

{
  memset(&Peripherals::SEQ.REG010,0,0x4c);
  addressFilterMatchTable = 0;
  return;
} */

bool RAIL_AddressFilterSetAddress(uint8_t field,uint8_t index,uint8_t *value,bool enable)

{
  GENERIC_PHY_SetAddress();
  return;
}

/* bool RAIL_AddressFilterSetAddress(uint8_t field,uint8_t index,uint8_t *value,bool enable)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = (uint)field;
  iVar3 = GENERIC_PHY_SetAddressData
                    (uVar2,uVar2,index,0,*(undefined *)((int)&Peripherals::SEQ.REG054 + uVar2 + 2),
                     value);
  if ((enable != false) && (iVar3 != 0)) {
    bVar1 = GENERIC_PHY_EnableAddress(field,index);
    return bVar1;
  }
  return SUB41(iVar3,0);
}
 */

bool RAIL_AddressFilterEnableAddress(uint8_t field,uint8_t index)

{
  return GENERIC_PHY_EnableAddress();
}

/* bool RAIL_AddressFilterEnableAddress(uint8_t field,uint8_t index)

{
  uint uVar1;
  
  uVar1 = (uint)field;
  if ((uVar1 < 2) && (index < 4)) {
    *(byte *)((int)&Peripherals::SEQ.REG058 + uVar1) =
         (byte)(1 << (uint)index) | *(byte *)((int)&Peripherals::SEQ.REG058 + uVar1);
    GENERIC_PHY_SetAddressFilteringMatchTable();
    return true;
  }
  return false;
}
 */

bool RAIL_AddressFilterDisableAddress(uint8_t field,uint8_t index)

{
  return GENERIC_PHY_DisableAddress();
}

/* bool RAIL_AddressFilterDisableAddress(uint8_t field,uint8_t index)

{
  uint uVar1;
  
  uVar1 = (uint)field;
  if ((uVar1 < 2) && (index < 4)) {
    *(byte *)((int)&Peripherals::SEQ.REG058 + uVar1) =
         *(byte *)((int)&Peripherals::SEQ.REG058 + uVar1) & ~(byte)(1 << (uint)index);
    GENERIC_PHY_SetAddressFilteringMatchTable();
    return true;
  }
  return false;
} */

uint16_t RAIL_GetRadioEntropy(uint8_t *buffer,uint16_t bytes)

{
  return RFRAND_GetRadioEntropy();
}

/* uint16_t RAIL_GetRadioEntropy(uint8_t *buffer,uint16_t bytes)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  CORE_irqState_t irqState;
  uint __n;
  size_t __n_00;
  uint uStack36;
  
  __n = (uint)bytes;
  uVar4 = read_volatile_4(Peripherals::CMU.HFRADIOCLKEN0);
  uStack36 = __n;
  memset(buffer,0,__n);
  if ((((uVar4 | 0xcc) == uVar4) &&
      (uVar4 = read_volatile_4(Peripherals::RAC.CTRL), -1 < (int)(uVar4 << 0x1f))) &&
     (uVar4 = RADIOCMU_ClockPrescGet(0x75160), uVar4 == 0)) {
    irqState = CORE_EnterCritical();
    uVar3 = read_volatile_4(Peripherals::MODEM.CTRL0);
    uVar2 = read_volatile_4(Peripherals::FRC.RAWCTRL);
    uVar1 = read_volatile_4(Peripherals::MODEM.CTRL0);
    write_volatile_4(Peripherals::MODEM.CTRL0,uVar1 & 0xc7ffffff);
    uVar1 = read_volatile_4(Peripherals::MODEM.CTRL0);
    write_volatile_4(Peripherals::MODEM.CTRL0,uVar1 | 0x8000000);
    write_volatile_4(Peripherals::FRC.RAWCTRL,0x24);
    _DAT_43080008 = 1;
    write_volatile_4(Peripherals::FRC.IFC,0x4000);
    write_volatile_4(Peripherals::FRC.CMD,0x1000);
    for (; uVar4 < __n; uVar4 = uVar4 + __n_00 & 0xffff) {
      do {
        do {
          uVar1 = read_volatile_4(Peripherals::FRC.IF);
        } while (-1 < (int)(uVar1 << 0x11));
        uVar1 = read_volatile_4(Peripherals::FRC.STATUS);
      } while (-1 < (int)(uVar1 << 0x17));
      __n_00 = __n - uVar4;
      write_volatile_4(Peripherals::FRC.IFC,0x4000);
      if (3 < (int)__n_00) {
        __n_00 = 4;
      }
      uStack36 = read_volatile_4(Peripherals::FRC.RXRAWDATA);
      memcpy(buffer + uVar4,&uStack36,__n_00);
    }
    _DAT_43080008 = 0;
    write_volatile_4(Peripherals::FRC.RAWCTRL,uVar2);
    write_volatile_4(Peripherals::MODEM.CTRL0,uVar3);
    write_volatile_4(Peripherals::FRC.IFC,0x4000);
    CORE_ExitCritical(irqState);
  }
  else {
    bytes = 0;
  }
  return bytes;
}

 */