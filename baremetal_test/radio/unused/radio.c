#include "radio.h"
#include <stdbool.h>
#include <string.h>
#include "em_bus.h"
#include "em_int.h"
#include "em_cmu.h"
#include "em_assert.h"
//#include "tempcal.h"
#include "radio.h"
#include "radio_proc.h"
//#include "phy_utils.h"
#include "em_system.h"
#include "pa.h"
#include "rf_test.h"







void RADIO_WriteSync(uint32_t *addr,uint32_t data)

{
  *addr = data;
}



void RADIO_OrSync(uint32_t *addr,uint32_t data)

{
  *addr = data | *addr;
}



void RADIO_XorSync(uint32_t *addr,uint32_t data)

{
  *addr = data ^ *addr;
}



void RADIO_AndSync(uint32_t *addr,uint32_t data)

{
  *addr = data & *addr;
}



void RADIO_WaitForSetSync(uint32_t *addr,uint32_t data)

{
	INT_Disable();
	while ((*addr & data) != data);
	INT_Enable();
}






/*
void RADIO_Delay(uint32_t us)

{
  PHY_UTILS_DelayUs(us);
}
*/






void RADIO_ClrBitSync(int addr,int bit)

{
  *(uint32_t *)((bit + (addr + 0x2100000) * 8) * 4) = 0;
}



void RADIO_SetBitSync(int addr,int bit)

{
  *(uint32_t *)((addr + (bit + 0x2100000) * 8) * 4) = 1;
}



void RADIO_RegisterIrqCallback(int irqN,void *func)

{
  //(&EFRDRV_irqClbk)[irqN] = func;
}



void FRC_PRI_IRQHandler(void)

{
                    // WARNING: Could not recover jumptable at 0x000102e0. Too many branches
                    // WARNING: Treating indirect jump as call
//  (*EFRDRV_irqClbk)();
}



void FRC_IRQHandler(void)

{
                    // WARNING: Could not recover jumptable at 0x000102ec. Too many branches
                    // WARNING: Treating indirect jump as call
//  (*DAT_000109d0)();
}



void RAC_RSM_IRQHandler(void)

{
                    // WARNING: Could not recover jumptable at 0x000102f8. Too many branches
                    // WARNING: Treating indirect jump as call
//  (*DAT_000109e0)();
}



void RAC_SEQ_IRQHandler(void)

{
                    // WARNING: Could not recover jumptable at 0x00010304. Too many branches
                    // WARNING: Treating indirect jump as call
 // (*DAT_000109e0)();
}



void AGC_IRQHandler(void)

{
                    // WARNING: Could not recover jumptable at 0x00010310. Too many branches
                    // WARNING: Treating indirect jump as call
//  (*DAT_000109f0)();
}



void PROTIMER_IRQHandler(void)

{
  PROTIMER->IFC = 0xffffffff;   //temporary
}














bool RADIO_IsRxActive(void)

{
  if (((RAC->STATUS & 0x0f) != 3) && ((RAC->STATUS & 0x0f) != 7)) return (RAC->STATUS & 0x0f) == 4;
  return true;
}












