#include "rail_ble_rf_hal.h"



void RFHAL_BLESetPhyforChan(int param_1,int param_2)

{
  undefined1 *puVar1;
  int32_t iVar2;
  uint uVar3;
  int32_t power;
  undefined1 *radioConfig;
  
  if (param_2 != 0) {
    lastSetTxPower = RFHAL_GetCurrPowerLevel();
  }
  iVar2 = RFHAL_GetCurrPowerLevel();
  if (iVar2 < 0x65) {
    radioConfig = &ble_config_base_min;
    if (param_1 == 0x1c) {
      radioConfig = &ble_config_2458MHz_min;
    }
  }
  else {
    uVar3 = param_1 - 7U & 0xff;
    if (uVar3 < 0x17) {
      uVar3 = 1 << uVar3;
      if ((uVar3 & 0x58000b) == 0) {
        radioConfig = &ble_config_2458MHz_20dBm_min;
        if ((uVar3 & 0x200000) == 0) {
          radioConfig = &ble_config_base_20dBm_min;
        }
      }
      else {
        radioConfig = &ble_config_2416_2418_2422_2454_2456_2460_20dBm_min;
      }
    }
    else {
      radioConfig = &ble_config_base_20dBm_min;
    }
  }
  puVar1 = prevRadioCfg;
  if ((radioConfig != prevRadioCfg) &&
     (RAIL_RadioConfig(&ble_config_base_min), puVar1 = radioConfig,
     radioConfig != &ble_config_base_min)) {
    RAIL_RadioConfig(radioConfig);
  }
  prevRadioCfg = puVar1;
  iVar2 = RFHAL_GetCurrPowerLevel();
  if (param_1 == 0x1b) {
    power = 0x96;
  }
  else {
    power = 300;
  }
  if ((iVar2 <= power) && (lastSetTxPower <= power)) {
    if (iVar2 != lastSetTxPower) {
      lastSetTxPower = PA_OutputPowerSet(lastSetTxPower);
    }
    return;
  }
  PA_OutputPowerSet(power);
  return;
}



bool RFHAL_Ble2MbpsSet(void)

{
  return false;
}


bool RFHAL_Ble1MbpsSet(void)

{
  uint32_t uVar1;
  uint uVar2;
  
  RAIL_RadioConfig(&ble_config_base);
  prevRadioCfg = &ble_config_base_min;
  uVar1 = RAILInt_CompensateForDelay(10000,0);
  uVar2 = count_leading_zeroes(uVar1);
  return SUB41(uVar2 >> 5,0);
}



void RFHAL_BleInit(void)

{
  TIMING_TxToRxSearchTimeSet(0x46);
  RFHAL_SetProtocolSpecificChCheckCB(0x12b5d);
  RFHAL_Ble1MbpsSet();
  RAIL_ChannelConfig((RAIL_ChannelConfig_t *)&bleChannelConfig);
  lastSetTxPower = RFHAL_GetCurrPowerLevel();
  return;
}




void RFHAL_BleDeinit(void)

{
  undefined4 extraout_r1;
  undefined4 in_r2;
  undefined4 in_r3;
  
  RFHAL_SetProtocolSpecificChCheckCB(0);
  TIMING_TxToRxSearchTimeSet(0,extraout_r1,in_r2,in_r3);
  return;
}



void RFHAL_BLEPreambleSyncWordSet(uint32_t pre,uint32_t sync)

{
  uint uVar1;
  
  write_volatile_4(Peripherals::MODEM.SYNC0,sync);
  uVar1 = read_volatile_4(Peripherals::MODEM.PRE);
  if (pre == 0x55) {
    uVar1 = uVar1 & 0xfffffff0 | 1;
  }
  else {
    uVar1 = uVar1 & 0xfffffff0 | 2;
  }
  write_volatile_4(Peripherals::MODEM.PRE,uVar1);
  return;
}


void RFHAL_BLEWhiteningSet(uint32_t poly,uint32_t init,bool enable)

{
  bool bVar1;
  
  write_volatile_4(FRC->WHITEPOLY,poly);
  write_volatile_4(FRC->WHITEINIT,init);
  bVar1 = enable == false;
  if (bVar1) {
    write_volatile_4(FRC->FECCTRL,0);
  }
  else {
    write_volatile_4(FRC->FECCTRL,1);
    enable = false;
  }
  RADIO_FrameDescsConfig(bVar1,enable,1,1);
  return;
}


