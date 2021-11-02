#ifndef _MODEM_MODEM_H_
#define _MODEM_MODEM_H_

#include "radio_proc.h"


//void MODEM_IRQHandler(void);
void MODEM_init(void);
void MODEM_ConfigFixup(void);
void MODEM_DemodResetOnRxsearchEntryEnable(void);
void MODEM_DemodResetOnRxsearchEntryDisable(void);
void MODEM_DccalEnable(void);
void MODEM_DccalDisable(void);
uint32_t MODEM_ComputeTxBaudrate(void);
uint32_t MODEM_ComputeTxSymbolRate(void);
uint32_t MODEM_ComputeTxBitRate(void);

#endif