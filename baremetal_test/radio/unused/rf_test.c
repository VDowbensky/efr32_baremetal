#include "rf_test.h"
#include <stdbool.h>
#include "em_bus.h"
#include "em_assert.h"
#include "radio_proc.h"


uint32_t rfparamsfbuffer[20] = {};
uint8_t testModeRegisterState;

uint32_t berSkipBytesLeft;
uint32_t berTotalBytesLeft;
uint32_t berTotalErrors;
uint32_t berTotalBits;
bool berInfiniteMode;
uint32_t berSkipBytes;

BerStatus_t berStats;























void RFTEST_StartTx(void)

{
  RAC->CMD = 0x01; //TXEN
}





void RFTEST_StopTx(void)

{

}



















