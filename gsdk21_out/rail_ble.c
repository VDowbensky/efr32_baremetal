#include "rail_ble.h"



void RAILCore_BLE_Init(uint8_t *param_1)

{
  RFHAL_BleInit();
  *param_1 = *param_1 | 1;
  RFHAL_SetPtiProtocol(param_1,3);
  return;
}



//void RAIL_BLE_Init(int param_1)
void RAIL_BLE_Init(RAIL_Handle_t railHandle)
{
  RAILCore_BLE_Init(param_1 + 0xc);
  return;
}



void RAILCore_BLE_Deinit(uint8_t *param_1)

{
  if ((int)((uint32_t)*param_1 << 0x1f) < 0) {
    RFHAL_BleDeinit();
    *param_1 = *param_1 & 0xfe;
    RFHAL_SetPtiProtocol(param_1,0);
    return;
  }
  return;
}



//void RAIL_BLE_Deinit(int param_1)
void RAIL_BLE_Deinit(RAIL_Handle_t railHandle)
{
  RAILCore_BLE_Deinit(param_1 + 0xc);
  return;
}



//uint8_t RAIL_BLE_IsEnabled(int param_1)
bool RAIL_BLE_IsEnabled(RAIL_Handle_t railHandle)
{
  return *(uint8_t *)(param_1 + 0xc) & 1;
}



undefined4 RAILCore_BLE_ConfigPhy1MbpsViterbi(uint8_t *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((int)((uint32_t)*param_1 << 0x1f) < 0) && (iVar1 = RFHAL_GetRadioState(), iVar1 == 1)) {
    uVar2 = RFHAL_ConfigBle1MbpsViterbi(param_1);
    return uVar2;
  }
  return 2;
}



//void RAIL_BLE_ConfigPhy1MbpsViterbi(int param_1)
RAIL_Status_t RAIL_BLE_ConfigPhy1MbpsViterbi(RAIL_Handle_t railHandle)
{
  RAILCore_BLE_ConfigPhy1MbpsViterbi(param_1 + 0xc);
  return;
}



undefined4 RAILCore_BLE_ConfigPhy1Mbps(uint8_t *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((int)((uint32_t)*param_1 << 0x1f) < 0) && (iVar1 = RFHAL_GetRadioState(), iVar1 == 1)) {
    uVar2 = RFHAL_ConfigBle1Mbps(param_1);
    return uVar2;
  }
  return 2;
}



//void RAIL_BLE_ConfigPhy1Mbps(int param_1)
RAIL_Status_t RAIL_BLE_ConfigPhy1Mbps(RAIL_Handle_t railHandle)
{
  RAILCore_BLE_ConfigPhy1Mbps(param_1 + 0xc);
  return;
}



undefined4 RAILCore_BLE_ConfigPhy2MbpsViterbi(uint8_t *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((int)((uint32_t)*param_1 << 0x1f) < 0) && (iVar1 = RFHAL_GetRadioState(), iVar1 == 1)) {
    uVar2 = RFHAL_ConfigBle2MbpsViterbi(param_1);
    return uVar2;
  }
  return 2;
}



//void RAIL_BLE_ConfigPhy2MbpsViterbi(int param_1)
RAIL_Status_t RAIL_BLE_ConfigPhy2MbpsViterbi(RAIL_Handle_t railHandle)
{
  RAILCore_BLE_ConfigPhy2MbpsViterbi(param_1 + 0xc);
  return;
}



undefined4 RAILCore_BLE_ConfigPhy2Mbps(uint8_t *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((int)((uint32_t)*param_1 << 0x1f) < 0) && (iVar1 = RFHAL_GetRadioState(), iVar1 == 1)) {
    uVar2 = RFHAL_ConfigBle2Mbps(param_1);
    return uVar2;
  }
  return 2;
}



//void RAIL_BLE_ConfigPhy2Mbps(int param_1)
RAIL_Status_t RAIL_BLE_ConfigPhy2Mbps(RAIL_Handle_t railHandle)
{
  RAILCore_BLE_ConfigPhy2Mbps(param_1 + 0xc);
  return;
}



undefined4 RAILCore_BLE_ConfigPhyCoded(uint8_t *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((int)((uint32_t)*param_1 << 0x1f) < 0) && (iVar1 = RFHAL_GetRadioState(), iVar1 << 0x1f < 0)) {
    uVar2 = RFHAL_ConfigBleCoded(param_1,param_2);
    return uVar2;
  }
  return 2;
}


RAIL_ENUM(RAIL_BLE_Coding_t) {
  RAIL_BLE_Coding_125kbps = 0,
  RAIL_BLE_Coding_125kbps_DSA = 1,
  RAIL_BLE_Coding_500kbps = 2,
  RAIL_BLE_Coding_500kbps_DSA = 3,
};
//void RAIL_BLE_ConfigPhyCoded(int param_1)
RAIL_Status_t RAIL_BLE_ConfigPhyCoded(RAIL_Handle_t railHandle,
                                      RAIL_BLE_Coding_t bleCoding)
{
  RAILCore_BLE_ConfigPhyCoded(param_1 + 0xc);
  return;
}



undefined4
RAILCore_BLE_ConfigChannelRadioParams
          (uint8_t *param_1,undefined4 param_2,int param_3,uint32_t param_4,char param_5)

{
  uint8_t bVar1;
  uint8_t bVar2;
  uint8_t bVar3;
  int iVar4;
  undefined4 uVar5;
  
  if ((int)((uint32_t)*param_1 << 0x1f) < 0) {
    bVar1 = (uint8_t)param_2;
    bVar2 = (uint8_t)((uint32_t)param_2 >> 8);
    bVar3 = (uint8_t)((uint32_t)param_2 >> 0x10);
    RFHAL_SetCRCInitVal(((uint32_t)(uint8_t)((((((((bVar1 & 1) << 1 | bVar1 >> 1 & 1) << 1 | bVar1 >> 2 & 1
                                          ) << 1 | bVar1 >> 3 & 1) << 1 | bVar1 >> 4 & 1) << 1 |
                                       bVar1 >> 5 & 1) << 1 | bVar1 >> 6 & 1) << 1 | bVar1 >> 7) <<
                         0x18 | (uint32_t)(uint8_t)((((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 |
                                                 bVar2 >> 2 & 1) << 1 | bVar2 >> 3 & 1) << 1 |
                                               bVar2 >> 4 & 1) << 1 | bVar2 >> 5 & 1) << 1 |
                                             bVar2 >> 6 & 1) << 1 | bVar2 >> 7) << 0x10 |
                        (uint32_t)(uint8_t)((((((((bVar3 & 1) << 1 | bVar3 >> 1 & 1) << 1 | bVar3 >> 2 & 1)
                                         << 1 | bVar3 >> 3 & 1) << 1 | bVar3 >> 4 & 1) << 1 |
                                      bVar3 >> 5 & 1) << 1 | bVar3 >> 6 & 1) << 1 | bVar3 >> 7) << 8
                        ) >> 8);
    if (param_3 << 0x1f < 0) {
      iVar4 = RFHAL_IsBleLongRangeEnabled(param_1);
      if (iVar4 == 0) {
        uVar5 = 0x55;
      }
      else {
        uVar5 = 0xaa;
      }
    }
    else {
      uVar5 = 0xaa;
    }
    RFHAL_BLEPreambleSyncWordSet(uVar5,param_3);
    if (param_5 != '\0') {
      uVar5 = 0;
      param_4 = 0;
    }
    else {
      uVar5 = 0x44;
      param_4 = param_4 | 0x40;
    }
    RFHAL_BLEWhiteningSet(uVar5,param_4,param_5 == '\0');
    return 0;
  }
  return 2;
}



void RAILCore_BLE_Reinit(undefined4 param_1,undefined4 *param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  
  puVar1 = param_2;
  RFHAL_BleReinit();
  RAILCore_BLE_ConfigChannelRadioParams
            (param_1,*param_2,param_2[1],*(undefined2 *)(param_2 + 2),
             *(undefined *)((int)param_2 + 10),puVar1,param_3);
  return;
}



//void RAIL_BLE_ConfigChannelRadioParams(int param_1)
RAIL_Status_t RAIL_BLE_ConfigChannelRadioParams(RAIL_Handle_t railHandle,
                                                uint32_t crcInit,
                                                uint32_t accessAddress,
                                                uint16_t channel,
                                                bool disableWhitening);
{
  RAILCore_BLE_ConfigChannelRadioParams(param_1 + 0xc);
  return;
}


