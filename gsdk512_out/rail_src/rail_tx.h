#ifndef _RAIL_TX_H_
#define _RAIL_TX_H_

uint32_t RAIL_TxConfig(uint32_t cbToEnable);
uint8_t RAIL_TxStartWithOptions(uint8_t channel,RAIL_TxOptions_t *options,RAIL_PreTxOp_t preTxOp,void *preTxOpParams);
uint8_t RAIL_TxStart(uint8_t channel,uint32_t preTxOp,uint32_t *preTxOpParams);
uint8_t RAIL_TxToneStart(void);
uint8_t RAIL_TxToneStop(void);
uint8_t RAIL_TxStreamStart(uint8_t channel, RAIL_StreamMode_t mode);
uint8_t RAIL_TxStreamStop(void);
int32_t RAIL_TxPowerSet(int32_t powerLevel);
int32_t RAIL_TxPowerGet(void);

#endif