#include "rail_ble.h"



RAIL_Status_t RAIL_BLE_Init(void)

{
  RFHAL_BleInit();
  isBleEnabled = true;
  return RAIL_SetPtiProtocol(RAIL_PTI_PROTOCOL_BLE);
}



void RAIL_BLE_Deinit(void)

{
  if (isBleEnabled != false) 
  {
    RFHAL_BleDeinit();
    isBleEnabled = false;
    RAIL_SetPtiProtocol(RAIL_PTI_PROTOCOL_CUSTOM);
  }
}



bool RAIL_BLE_IsEnabled(void)

{
  return isBleEnabled;
}



bool RAIL_BLE_SetPhy1MbpsViterbi(void)

{
  if ((isBleEnabled != false) && (RFHAL_StateGet() == RAIL_RF_STATE_IDLE)) return RFHAL_Ble1MbpsSet();
  else return false;
}



bool RAIL_BLE_SetPhy1Mbps(void)

{
  if ((isBleEnabled != false) && (RFHAL_StateGet() == RAIL_RF_STATE_IDLE)) return RFHAL_Ble1MbpsSet();
  else return false;
}



bool RAIL_BLE_SetPhy2MbpsViterbi(void)

{
  if ((isBleEnabled != false) && (RFHAL_StateGet() == RAIL_RF_STATE_IDLE)) return RFHAL_Ble2MbpsSet();
  else return false;
}



bool RAIL_BLE_SetPhy2Mbps(void)

{
  if ((isBleEnabled != false) && (RFHAL_StateGet() == RAIL_RF_STATE_IDLE)) return RFHAL_Ble2MbpsSet();
  else return false;
}



bool RAIL_BLE_SetupChannelRadioParams(uint32_t crcInit,uint32_t accessAddress,uint8_t channel,bool disableWhitening)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  bool bVar4;
  uint32_t poly;
  uint32_t init;
  
  bVar4 = isBleEnabled;
  if (isBleEnabled != false) 
  {
    bVar1 = (byte)crcInit;
    bVar2 = (byte)(crcInit >> 8);
    bVar3 = (byte)(crcInit >> 0x10);
    RFHAL_SetCRCInitVal(((uint)(byte)((((((((bVar1 & 1) << 1 | bVar1 >> 1 & 1) << 1 | bVar1 >> 2 & 1
                                          ) << 1 | bVar1 >> 3 & 1) << 1 | bVar1 >> 4 & 1) << 1 |
                                       bVar1 >> 5 & 1) << 1 | bVar1 >> 6 & 1) << 1 | bVar1 >> 7) <<
                         0x18 | (uint)(byte)((((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 |
                                                 bVar2 >> 2 & 1) << 1 | bVar2 >> 3 & 1) << 1 |
                                               bVar2 >> 4 & 1) << 1 | bVar2 >> 5 & 1) << 1 |
                                             bVar2 >> 6 & 1) << 1 | bVar2 >> 7) << 0x10 |
                        (uint)(byte)((((((((bVar3 & 1) << 1 | bVar3 >> 1 & 1) << 1 | bVar3 >> 2 & 1)
                                         << 1 | bVar3 >> 3 & 1) << 1 | bVar3 >> 4 & 1) << 1 |
                                      bVar3 >> 5 & 1) << 1 | bVar3 >> 6 & 1) << 1 | bVar3 >> 7) << 8
                        ) >> 8);
    RFHAL_BLEPreambleSyncWordSet();
    if (disableWhitening != false) 
	{
      poly = 0;
      init = 0;
    }
    else 
	{
      poly = 0x44;
      init = channel | 0x40;
    }
    RFHAL_BLEWhiteningSet(poly,init,disableWhitening == false);
  }
  return bVar4;
}

