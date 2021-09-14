#include "rail_ble_rf_hal.h"



undefined4 RFHAL_ConfigBle2Mbps(void)

{
  return 3;
}



undefined4 RFHAL_ConfigBle2MbpsViterbi(void)

{
  return 3;
}



undefined4
RFHAL_ConfigBle1Mbps(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  RAILCore_ConfigChannels(param_1,&ble_1M_channelConfig,param_3,param_4,param_4);
  return 0;
}



undefined4
RFHAL_ConfigBle1MbpsViterbi
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  RAILCore_ConfigChannels(param_1,&ble_1M_channelConfig,param_3,param_4,param_4);
  return 0;
}



undefined4 RFHAL_ConfigBleCoded(void)

{
  return 3;
}



void RFHAL_BleInit(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 extraout_r1;
  
  RFHAL_ConfigBle1MbpsViterbi();
  PTI_EnableSyncword(1,extraout_r1,param_3,param_4);
  return;
}



void RFHAL_BleReinit(void)

{
  PTI_EnableSyncword(1);
  return;
}



void RFHAL_BleDeinit(int param_1)

{
  *(undefined4 *)(param_1 + 0x1c) = 0;
  PTI_EnableSyncword(0);
  return;
}



undefined4 RFHAL_IsBleLongRangeEnabled(void)

{
  return 0;
}



void RFHAL_BLEPreambleSyncWordSet(int param_1,uint32_t param_2)

{
  uint32_t uVar1;
  
  write_volatile_4(MODEM->SYNC0,param_2);
  uVar1 = (MODEM->PRE);
  if (param_1 == 0x55) {
    uVar1 = uVar1 & 0xfffffff0 | 1;
  }
  else {
    uVar1 = uVar1 & 0xfffffff0 | 2;
  }
  write_volatile_4(MODEM->PRE,uVar1);
  return;
}



void RFHAL_BLEWhiteningSet(uint32_t param_1,uint32_t param_2,int param_3)

{
  bool bVar1;
  
  write_volatile_4(FRC->WHITEPOLY,param_1);
  write_volatile_4(FRC->WHITEINIT,param_2);
  BUS_RegMaskedClear(&FRC->FECCTRL,7);
  bVar1 = param_3 == 0;
  if (bVar1) {
    BUS_RegMaskedSet(&FRC->FECCTRL,0);
  }
  else {
    BUS_RegMaskedSet(&FRC->FECCTRL,1);
    param_3 = 0;
  }
  RADIO_FrameDescsConfig(bVar1,param_3,1,1);
  return;
}


