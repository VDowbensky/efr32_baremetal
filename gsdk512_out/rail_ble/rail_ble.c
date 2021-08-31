#include "rail_ble.h"

//isBleEnabled;

void RAIL_BLE_Init(void)

{
  undefined4 extraout_r1;
  undefined4 in_r3;
  
  RFHAL_BleInit();
  isBleEnabled = 1;
  RAIL_SetPtiProtocol(3,extraout_r1,1,in_r3);
  return;
}



void RAIL_BLE_Deinit(void)

{
  if (isBleEnabled != '\0') {
    RFHAL_BleDeinit();
    isBleEnabled = 0;
    RAIL_SetPtiProtocol();
    return;
  }
  return;
}



bool RAIL_BLE_IsEnabled(void)

{
  return (bool)isBleEnabled;
}



bool RAIL_BLE_SetPhy1MbpsViterbi(void)

{
  undefined uVar1;
  int iVar2;
  
  if ((isBleEnabled != '\0') && (iVar2 = RFHAL_StateGet(), iVar2 == 0)) {
    uVar1 = RFHAL_Ble1MbpsSet();
    return (bool)uVar1;
  }
  return false;
}



bool RAIL_BLE_SetPhy1Mbps(void)

{
  undefined uVar1;
  undefined4 in_r2;
  undefined4 in_r3;
  undefined8 uVar2;
  
  if ((isBleEnabled != '\0') && (uVar2 = RFHAL_StateGet(), (int)uVar2 == 0)) {
    uVar1 = RFHAL_Ble1MbpsSet(1,(int)((ulonglong)uVar2 >> 0x20),in_r2,in_r3);
    return (bool)uVar1;
  }
  return false;
}



bool RAIL_BLE_SetPhy2MbpsViterbi(void)

{
  undefined uVar1;
  int iVar2;
  
  if ((isBleEnabled != '\0') && (iVar2 = RFHAL_StateGet(), iVar2 == 0)) {
    uVar1 = RFHAL_Ble2MbpsSet();
    return (bool)uVar1;
  }
  return false;
}



bool RAIL_BLE_SetPhy2Mbps(void)

{
  undefined uVar1;
  undefined4 in_r2;
  undefined4 in_r3;
  undefined8 uVar2;
  
  if ((isBleEnabled != '\0') && (uVar2 = RFHAL_StateGet(), (int)uVar2 == 0)) {
    uVar1 = RFHAL_Ble2MbpsSet(1,(int)((ulonglong)uVar2 >> 0x20),in_r2,in_r3);
    return (bool)uVar1;
  }
  return false;
}



bool RAIL_BLE_SetupChannelRadioParams
               (uint32_t crcInit,uint32_t accessAddress,uint8_t channel,bool disableWhitening)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  undefined4 uVar4;
  byte bVar5;
  
  cVar3 = isBleEnabled;
  if (isBleEnabled != '\0') {
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
    if ((accessAddress & 1) == 0) {
      uVar4 = 0xaa;
    }
    else {
      uVar4 = 0x55;
    }
    RFHAL_BLEPreambleSyncWordSet(uVar4,accessAddress);
    if (disableWhitening != false) {
      uVar4 = 0;
      bVar5 = 0;
    }
    else {
      uVar4 = 0x44;
      bVar5 = channel | 0x40;
    }
    RFHAL_BLEWhiteningSet(uVar4,bVar5,disableWhitening == false);
  }
  return (bool)cVar3;
}


