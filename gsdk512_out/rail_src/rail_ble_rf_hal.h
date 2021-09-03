#ifndef _RAIL_BLE_RFHAL_H_
#define _RAIL_BLE_RFHAL_H_

void RFHAL_BLESetPhyforChan(int param_1,int param_2);

bool RFHAL_Ble2MbpsSet(void);
bool RFHAL_Ble1MbpsSet(void);
void RFHAL_BleInit(void);
void RFHAL_BleDeinit(void);
void RFHAL_BLEPreambleSyncWordSet(int pre,uint32_t sync);
void RFHAL_BLEWhiteningSet(uint32_t poly,uint32_t init,int fecctrl);

#endif
