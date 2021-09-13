#include "rail_assert.h"



void RAILCb_AssertFailed(void)

{
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



void RAILInt_Assert(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    errorCodeEncountered = param_2;
    uVar1 = RAILInt_GetActiveConfig();
    RAILCb_AssertFailed(uVar1,param_2);
  }
  return;
}


