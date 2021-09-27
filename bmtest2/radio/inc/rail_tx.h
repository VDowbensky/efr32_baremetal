#ifndef _RAIL_TX_H_
#define _RAIL_TX_H_

#include "em_device.h"
#include <stdint.h>
#include <stdbool.h>
#include "rail_types.h"

uint8_t RAIL_TxDataLoad(RAIL_TxData_t *txData);
uint8_t RAIL_TxStart(uint8_t channel, RAIL_PreTxOp_t preTxOp, void *preTxOpParams);


#endif
