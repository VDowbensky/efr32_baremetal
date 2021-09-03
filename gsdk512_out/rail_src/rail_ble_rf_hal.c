#include "rail_ble_rf_hal.h"

//prevRadioCfg;
//lastSetTxPower;

static const unsigned char bleChannelConfig[8UL + 1] = {0x78, 0x01, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00};

static const unsigned char bleChannels[12UL + 1] = {0x00, 0x00, 0x27, 0x00, 0x80, 0x84, 0x1E, 0x00, 0x80, 0x9C, 0x2B, 0x8F, 0x00};

void RFHAL_BLESetPhyforChan(int param_1,int param_2)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined *puVar5;
  
  if (param_2 != 0) lastSetTxPower = RFHAL_GetCurrPowerLevel();
  iVar2 = RFHAL_GetCurrPowerLevel();
  if (iVar2 < 0x65) 
  {
    puVar5 = &ble_config_base_min;
    if (param_1 == 0x1c) puVar5 = &ble_config_2458MHz_min;
  }
  else 
  {
    uVar3 = param_1 - 7U & 0xff;
    if (uVar3 < 0x17)
		{
      uVar3 = 1 << uVar3;
      if ((uVar3 & 0x58000b) == 0) 
	  {
        puVar5 = &ble_config_2458MHz_20dBm_min;
        if ((uVar3 & 0x200000) == 0) puVar5 = &ble_config_base_20dBm_min;
      }
      else puVar5 = &ble_config_2416_2418_2422_2454_2456_2460_20dBm_min;
    }
    else puVar5 = &ble_config_base_20dBm_min;
  }
  puVar1 = prevRadioCfg;
  if ((puVar5 != prevRadioCfg) && (RAIL_RadioConfig(&ble_config_base_min), puVar1 = puVar5, puVar5 != &ble_config_base_min)) RAIL_RadioConfig(puVar5);
  prevRadioCfg = puVar1;
  iVar2 = RFHAL_GetCurrPowerLevel();
  if (param_1 == 0x1b) iVar4 = 0x96;
  else iVar4 = 300;
  if ((iVar2 <= iVar4) && (lastSetTxPower <= iVar4)) 
  {
    if (iVar2 != lastSetTxPower) lastSetTxPower = PA_OutputPowerSet(lastSetTxPower);
    return;
  }
  PA_OutputPowerSet(iVar4);
}



bool RFHAL_Ble2MbpsSet(void)

{
  return false;
}



bool RFHAL_Ble1MbpsSet(void)

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
}



void RFHAL_BleDeinit(void)

{
  RFHAL_SetProtocolSpecificChCheckCB(0);
  TIMING_TxToRxSearchTimeSet(0);
}



void RFHAL_BLEPreambleSyncWordSet(int pre,uint32_t sync)

{
  MODEM->SYNC0 = sync;
  if (pre == 0x55) MODEM->PRE |= 1;
  else MODEM->PRE |= 2;
}



void RFHAL_BLEWhiteningSet(uint32_t poly,uint32_t init,int fecctrl)

{
  bool bVar1;
  
  FRC->WHITEPOLY,poly;
  FRC->WHITEINIT,init;
  bVar1 = fecctrl == 0;
  if (bVar1) FRC->FECCTRL = 0;
  else 
  {
    FRC->FECCTRL = 1;
    fecctrl = 0;
  }
  RADIO_FrameDescsConfig(bVar1,fecctrl,1,1);
}


