#include "radio_callbacks.h"

void RAILCb_RadioStateChanged(uint8_t state)

{
  return;
}

void RAILCb_RfReady(void)

{
  return;
}

void RAILCb_RxRadioStatus(uint8_t status)

{/*
  uint uVar1;
  Counters_t *pCVar2;
  uint32_t uVar3;
  bool bVar4;
  
  uVar1 = (uint)status;
  pCVar2 = (Counters_t *)(uVar1 << 0x1b);
  if ((int)pCVar2 < 0) {
    receivingPacket = false;
    pCVar2 = &counters;
    counters.frameError = counters.frameError + 1;
    LedToggle(1);
  }
  uVar3 = uVar1 << 0x1d;
  if ((int)uVar3 < 0) {
    receivingPacket = true;
    pCVar2 = &counters;
    uVar3 = counters.syncDetect + 1;
    counters.syncDetect = uVar3;
  }
  bVar4 = (int)(uVar1 << 0x1e) < 0;
  if (bVar4) {
    pCVar2 = &counters;
    uVar3 = counters.preambleDetect + 1;
  }
  if (bVar4) {
    pCVar2->preambleDetect = uVar3;
  }
  if ((int)(uVar1 << 0x1a) < 0) {
    receivingPacket = false;
    counters.rxOfEvent = counters.rxOfEvent + 1;
  }
  if ((int)(uVar1 << 0x19) < 0) {
    receivingPacket = false;
    counters.addrFilterEvent = counters.addrFilterEvent + 1;
  }
  if (((int)(uVar1 << 0x18) < 0) &&
     (counters.rfSensedEvent = counters.rfSensedEvent + 1, counters.rfSensedEvent == 0)) {
    counters.rfSensedEvent = 1;
  }
  return;
	*/
}

uint32_t RAILCb_TimerExpired(void)

{
	return 0;
}

void RAILCb_TxPacketSent(void)

{

}

void RAILCb_TxRadioStatus(uint8_t status)

{

}

void RAILCb_CalNeeded(void)
{
	
}



