#include "rail_ble_rf_hal.h"

//prevRadioCfg;
//lastSetTxPower;

void RFHAL_BLESetPhyforChan(int param_1,int param_2)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined *puVar5;
  
  if (param_2 != 0) {
    lastSetTxPower = RFHAL_GetCurrPowerLevel();
  }
  iVar2 = RFHAL_GetCurrPowerLevel();
  if (iVar2 < 0x65) {
    puVar5 = &ble_config_base_min;
    if (param_1 == 0x1c) {
      puVar5 = &ble_config_2458MHz_min;
    }
  }
  else {
    uVar3 = param_1 - 7U & 0xff;
    if (uVar3 < 0x17) {
      uVar3 = 1 << uVar3;
      if ((uVar3 & 0x58000b) == 0) {
        puVar5 = &ble_config_2458MHz_20dBm_min;
        if ((uVar3 & 0x200000) == 0) {
          puVar5 = &ble_config_base_20dBm_min;
        }
      }
      else {
        puVar5 = &ble_config_2416_2418_2422_2454_2456_2460_20dBm_min;
      }
    }
    else {
      puVar5 = &ble_config_base_20dBm_min;
    }
  }
  puVar1 = prevRadioCfg;
  if ((puVar5 != prevRadioCfg) &&
     (RAIL_RadioConfig(&ble_config_base_min), puVar1 = puVar5, puVar5 != &ble_config_base_min)) {
    RAIL_RadioConfig(puVar5);
  }
  prevRadioCfg = puVar1;
  iVar2 = RFHAL_GetCurrPowerLevel();
  if (param_1 == 0x1b) {
    iVar4 = 0x96;
  }
  else {
    iVar4 = 300;
  }
  if ((iVar2 <= iVar4) && (lastSetTxPower <= iVar4)) {
    if (iVar2 != lastSetTxPower) {
      lastSetTxPower = PA_OutputPowerSet(lastSetTxPower);
    }
    return;
  }
  PA_OutputPowerSet(iVar4);
  return;
}



undefined4 RFHAL_Ble2MbpsSet(void)

{
  return 0;
}



uint RFHAL_Ble1MbpsSet(void)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 in_r3;
  
  RAIL_RadioConfig(&ble_config_base);
  prevRadioCfg = &ble_config_base_min;
  uVar1 = RAILInt_CompensateForDelay(10000,0,&ble_config_base_min,&prevRadioCfg,in_r3);
  uVar2 = count_leading_zeroes(uVar1);
  return uVar2 >> 5;
}



void RFHAL_BleInit(void)

{
  TIMING_TxToRxSearchTimeSet(0x46);
  RFHAL_SetProtocolSpecificChCheckCB(RFHAL_BLESetPhyforChan);
  RFHAL_Ble1MbpsSet(0);
  RAIL_ChannelConfig(&bleChannelConfig);
  lastSetTxPower = RFHAL_GetCurrPowerLevel();
  return;
}



void RFHAL_BleDeinit(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 extraout_r1;
  
  RFHAL_SetProtocolSpecificChCheckCB(0);
  TIMING_TxToRxSearchTimeSet(0,extraout_r1,param_3,param_4);
  return;
}



void RFHAL_BLEPreambleSyncWordSet(int param_1,uint param_2)

{
  uint uVar1;
  
  write_volatile_4(Peripherals::MODEM.SYNC0,param_2);
  uVar1 = read_volatile_4(Peripherals::MODEM.PRE);
  if (param_1 == 0x55) {
    uVar1 = uVar1 & 0xfffffff0 | 1;
  }
  else {
    uVar1 = uVar1 & 0xfffffff0 | 2;
  }
  write_volatile_4(Peripherals::MODEM.PRE,uVar1);
  return;
}



void RFHAL_BLEWhiteningSet(uint param_1,uint param_2,int param_3)

{
  bool bVar1;
  
  write_volatile_4(Peripherals::FRC.WHITEPOLY,param_1);
  write_volatile_4(Peripherals::FRC.WHITEINIT,param_2);
  bVar1 = param_3 == 0;
  if (bVar1) {
    write_volatile_4(Peripherals::FRC.FECCTRL,0);
  }
  else {
    write_volatile_4(Peripherals::FRC.FECCTRL,1);
    param_3 = 0;
  }
  RADIO_FrameDescsConfig(bVar1,param_3,1,1);
  return;
}


