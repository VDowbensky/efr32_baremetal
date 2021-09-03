#include "rail_ble.h"

//isBleEnabled;

void RAIL_BLE_Init(void)

{
  RFHAL_BleInit();
  isBleEnabled = true;
  RAIL_SetPtiProtocol(RAIL_PTI_PROTOCOL_BLE);
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
  if ((isBleEnabled != false) && (RFHAL_StateGet() == 0)) return RFHAL_Ble1MbpsSet();
  else return false;
}



bool RAIL_BLE_SetPhy1Mbps(void)

{
  if ((isBleEnabled != false) && (RFHAL_StateGet() == 0)) return RFHAL_Ble1MbpsSet();
  else return false;
}



bool RAIL_BLE_SetPhy2MbpsViterbi(void)

{
  if ((isBleEnabled != false) && (RFHAL_StateGet() == 0)) return RFHAL_Ble2MbpsSet();
  else return false;
}



bool RAIL_BLE_SetPhy2Mbps(void)

{
  if ((isBleEnabled != false) && (RFHAL_StateGet() == 0)) return RFHAL_Ble2MbpsSet();
  else return false;
}



bool RAIL_BLE_SetupChannelRadioParams(uint32_t crcInit,uint32_t accessAddress,uint8_t channel,bool disableWhitening)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  undefined4 uVar4;
  byte bVar5;
  
  cVar3 = isBleEnabled;
  if (isBleEnabled != false) 
  {
    bVar5 = (byte)crcInit;
    bVar1 = (byte)(crcInit >> 8);
    bVar2 = (byte)(crcInit >> 0x10);
    RFHAL_SetCRCInitVal(((uint)(byte)((((((((bVar5 & 1) << 1 | bVar5 >> 1 & 1) << 1 | bVar5 >> 2 & 1
                                          ) << 1 | bVar5 >> 3 & 1) << 1 | bVar5 >> 4 & 1) << 1 |
                                       bVar5 >> 5 & 1) << 1 | bVar5 >> 6 & 1) << 1 | bVar5 >> 7) <<
                         0x18 | (uint)(byte)((((((((bVar1 & 1) << 1 | bVar1 >> 1 & 1) << 1 |
                                                 bVar1 >> 2 & 1) << 1 | bVar1 >> 3 & 1) << 1 |
                                               bVar1 >> 4 & 1) << 1 | bVar1 >> 5 & 1) << 1 |
                                             bVar1 >> 6 & 1) << 1 | bVar1 >> 7) << 0x10 |
                        (uint)(byte)((((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 | bVar2 >> 2 & 1)
                                         << 1 | bVar2 >> 3 & 1) << 1 | bVar2 >> 4 & 1) << 1 |
                                      bVar2 >> 5 & 1) << 1 | bVar2 >> 6 & 1) << 1 | bVar2 >> 7) << 8
                        ) >> 8);
    if ((accessAddress & 1) == 0) RFHAL_BLEPreambleSyncWordSet(0xaa,accessAddress);// uVar4 = 0xaa;
    else RFHAL_BLEPreambleSyncWordSet(0x55,accessAddress);//uVar4 = 0x55;
    
    if (disableWhitening != false) 
	{
      uVar4 = 0;
      bVar5 = 0;
    }
    else 
	{
      uVar4 = 0x44;
      bVar5 = channel | 0x40;
    }
    RFHAL_BLEWhiteningSet(uVar4,bVar5,disableWhitening == false);
  }
  return (bool)cVar3;
}


