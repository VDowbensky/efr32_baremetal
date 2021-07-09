#ifndef _RF_TEST_H_
#define _RF_TEST_H_

#include "em_device.h"
#include <stdint.h>
#include <stdbool.h>
#include "rail_types.h"

typedef struct BerStatus
{
  uint32_t bytesTotal; /**< Number of bytes to receive */
  uint32_t bytesTested; /**< Number of bytes currently tested */
  uint32_t bitErrors; /**< Number of bits errors detected */
  int8_t   rssi; /**< Current RSSI value during pattern acquisition */
} BerStatus_t;


void setupPnForTest(void);
void RFTEST_StartRx(void);
void RFTEST_StopRx(void);
void RFTEST_SaveRadioConfiguration(void);
void RFTEST_RestoreRadioConfiguration(void);
void RFTEST_StartCwTx(void);
void RFTEST_StartStreamTx(void);
void RFTEST_StartTx(void);
void RFTEST_StopTx(void);
void RFTEST_BerStop(void);

void RFTEST_BerEmptyBufcAndUpdateStats(void);

void RFTEST_ConfigBerRx(void);
void RFTEST_ResetBerStats(uint32_t bytes);
void RFTEST_ReportBerStats(RAIL_BerStatus_t *berstatus);
void RFTEST_StartBerRx(uint32_t bytes);

#endif

