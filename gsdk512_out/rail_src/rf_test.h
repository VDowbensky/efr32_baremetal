#ifndef _RFTEST_H_
#define _RFTEST_H_

void setupPnForTest(void);
void RFTEST_BerEmptyBufcAndUpdateStats(void);
void RFTEST_StartRx(void);
void RFTEST_StopRx(void);
void RFTEST_SaveRadioConfiguration(void);
void RFTEST_RestoreRadioConfiguration(void);
void RFTEST_StartCwTx(void);
void RFTEST_StartStreamTx(void);
void RFTEST_StartTx(void);
void RFTEST_StopTx(void);
void RFTEST_BerStop(void);
void RFTEST_ConfigBerRx(void);
void RFTEST_ResetBerStats(uint32_t bytes);
void RFTEST_ReportBerStats(RAIL_BerStatus_t *berstatus);
void RFTEST_StartBerRx(uint32_t bytes);

#endif