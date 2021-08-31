#ifndef _RAIL_RX_H_
#define _RAIL_RX_H_

uint8_t RAIL_RxConfig(uint32_t cbToEnable,bool appendedInfoEnable);

RAIL_Status_t RAIL_SetRxOptions(uint32_t options);
uint8_t RAIL_RxStart(uint8_t channel);
uint8_t RAIL_ScheduleRx(uint8_t channel, RAIL_ScheduleRxConfig_t *cfg);
void RAILCb_RxRadioStatus(uint8_t status);
void RAILCb_RxRadioStatusExt(uint32_t status);

#endif


