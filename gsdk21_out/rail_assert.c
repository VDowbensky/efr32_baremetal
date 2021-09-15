#include "rail_assert.h"



//void RAILCb_AssertFailed(void)
void RAILCb_AssertFailed(RAIL_Handle_t railHandle, uint32_t errorCode);
{
  while(1);
}



void RAILInt_Assert(int param_1,undefined4 param_2)

{
  if (param_1 == 0) 
  {
    errorCodeEncountered = param_2;
    RAILCb_AssertFailed(RAILInt_GetActiveConfig(),param_2);
  }
}


