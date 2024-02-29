//#include "pti.h"
#include "protimer.h"
#include <stdbool.h>
#include "em_bus.h"
#include "em_cmu.h"
#include "em_assert.h"
#include "em_int.h"
//#include "radio_cmu.h"
//#include "RADIO_pti.h"


float ratio;
uint16_t precntRatioInt; 
uint8_t precntRatioFrac;

void PROTIMER_IRQHandler(void)
{
	uint32_t flags;
	flags = PROTIMER->IF & PROTIMER->IEN;
	PROTIMER->IFC = flags;

	if(flags & PROTIMER_IF_PRECNTOF_Msk)
	{

	}

	if(flags & PROTIMER_IF_BASECNTOF_Msk)
	{

	}
	
	if(flags & PROTIMER_IF_WRAPCNTOF_Msk)
	{
		HardEvents |= HARDEVENT_WRAPCNTOF;
	}	
	
	if(flags & PROTIMER_IF_TOUT0_Msk)
	{
		
	}
	
	if(flags & PROTIMER_IF_TOUT1_Msk)
	{
		
	}
	
	if(flags & PROTIMER_IF_TOUT0MATCH_Msk)
	{
		
	}
	
	if(flags & PROTIMER_IF_TOUT1MATCH_Msk)
	{
		
	}
	
	if(flags & PROTIMER_IF_CC0_Msk)
	{
		
	}
	
	if(flags & PROTIMER_IF_CC1_Msk)
	{
		
	}
	
	if(flags & PROTIMER_IF_CC2_Msk)
	{
		
	}
	
	if(flags & PROTIMER_IF_CC3_Msk)
	{
    //PROTIMER_CCTimerStop(3);
    //BUS_RegMaskedClear(&PROTIMER->RXCTRL,0x1f1f);
    //PROTIMER->IFC = PROTIMER_IFC_CC3_Msk;
    //PROTIMER_ClearTxEnable();
	}
	
	if(flags & PROTIMER_IF_CC4_Msk)
	{
		
	}
	
	if(flags & PROTIMER_IF_COF0_Msk)
	{
		
	}
	
	if(flags & PROTIMER_IF_COF1_Msk)
	{
		
	}
	
	if(flags & PROTIMER_IF_COF2_Msk)
	{
		
	}
	
	if(flags & PROTIMER_IF_COF3_Msk)
	{
		
	}
	
	if(flags & PROTIMER_IF_COF4_Msk)
	{
		
	}
	
	if(flags & PROTIMER_IF_LBTSUCCESS_Msk)
	{
		
	}
	
	if(flags & PROTIMER_IF_LBTFAILURE_Msk)
	{
		
	}
	
	if(flags & PROTIMER_IF_LBTPAUSED_Msk)
	{
		
	}
	
	if(flags & PROTIMER_IF_LBTRETRY_Msk)
	{
		
	}
	
	if(flags & PROTIMER_IF_RTCCSYNCHED_Msk)
	{
		
	}
	
	if(flags & PROTIMER_IF_TOUT0MATCHLBT_Msk)
	{
		
	}
}

void PROTIMER_Start(void)

{
	BUS_RegMaskedSet(&PROTIMER->CMD, PROTIMER_CMD_START_Msk);
  NVIC_EnableIRQ(PROTIMER_IRQn);
  NVIC_ClearPendingIRQ(PROTIMER_IRQn);
}





void PROTIMER_Stop(void)

{
	BUS_RegMaskedSet(&PROTIMER->CMD, PROTIMER_CMD_STOP_Msk);
  NVIC_DisableIRQ(PROTIMER_IRQn);
  NVIC_ClearPendingIRQ(PROTIMER_IRQn);
}



bool PROTIMER_IsRunning(void)

{
	if(PROTIMER->STATUS & PROTIMER_STATUS_RUNNING_Msk) return true;
  else return false;
}



void PROTIMER_Reset(void)

{
  PROTIMER->PRECNT = 0;
  PROTIMER->BASECNT = 0;
  PROTIMER->WRAPCNT = 0;
}



uint32_t PROTIMER_ElapsedTime(uint32_t time,uint32_t cnt)

{
  int delta;
  delta = cnt - time;
  if (cnt < time) delta = delta + PROTIMER->WRAPCNTTOP + 1;
  return delta;
}



void PROTIMER_TOUTTimerStop(uint8_t num)

{
	if (num == 0) BUS_RegMaskedSet(&PROTIMER->CMD, PROTIMER_CMD_TOUT0STOP_Msk);
	else BUS_RegMaskedSet(&PROTIMER->CMD, PROTIMER_CMD_TOUT1STOP_Msk);
}



void PROTIMER_TOUTTimerStart(uint32_t time,uint8_t num)

{
  if (num == 0)
  {
	    PROTIMER->TOUT0CNTTOP = time << 8;
			PROTIMER->IFC = PROTIMER_IF_TOUT0MATCH_Msk | PROTIMER_IF_TOUT0_Msk;
			BUS_RegMaskedSet(&PROTIMER->CMD, PROTIMER_CMD_TOUT0START_Msk);
  }
  else
  {
	    PROTIMER->TOUT1CNTTOP = time << 8;
			PROTIMER->IFC = PROTIMER_IF_TOUT1MATCH_Msk | PROTIMER_IF_TOUT1_Msk;
			BUS_RegMaskedSet(&PROTIMER->CMD, PROTIMER_CMD_TOUT1START_Msk);
  }
}



uint32_t PROTIMER_TOUTTimerGet(uint8_t num)

{
  if (num == 0) return (PROTIMER->TOUT0CNT << 0x10) >> 0x18;
  else return (PROTIMER->TOUT1CNT << 0x10) >> 0x18;
}



void PROTIMER_CCTimerStop(uint8_t num) //CC number

{
  *(uint32_t *)(num * 0x200 + 0x430a0e80) = 0; //5074 - PROTIMER->CC0_CTRL bit 0
  PROTIMER->IFC = 0x100 << (num & 0xff);
	
//	(&PROTIMER_CLR->CC0_CTRL)[(uint32_t)num * 4] = 1;
//  PROTIMER->IFC = 0x100 << (uint32_t)num;
}



uint32_t PROTIMER_CCTimerStart(int8_t timer,uint32_t time, uint8_t mode)

{
  uint32_t top;
  uint32_t cnt;
  
  INT_Disable();
  top = PROTIMER->WRAPCNTTOP;
  cnt = PROTIMER->WRAPCNT;
  if (mode != 1)
  {
    if (mode != 2) goto LAB_0001013c;
    cnt = (&PROTIMER->CC0_WRAP)[timer * 4];
  }
  time = time + cnt;

LAB_0001013c:
  if (top < time) time = (time - top) - 1;
  (&PROTIMER->CC0_WRAP)[timer * 4] = time & top;
  cnt = PROTIMER->WRAPCNT;
  cnt = PROTIMER_ElapsedTime(time & top,cnt);
  if (top >> 2 < cnt)
  {
    (&PROTIMER->CC0_CTRL)[timer * 4] = 0x11;
    INT_Enable();
    return 1;
  }
  *(uint32_t *)((timer + 0x10c28308) * 4) = 1; //!!!!!!!!!
  INT_Enable();
  return 0;
}



bool PROTIMER_CCTimerIsEnabled(int num)

{
  if((&PROTIMER->CC0_CTRL)[num * 4] & 1) return true;
  else return false;
}



void PROTIMER_ScheduleTxEnable(int timer,uint32_t time,uint32_t mode)

{
  if((&PROTIMER->CC0_CTRL)[timer * 4] & 0x01) PROTIMER_CCTimerStop(timer);
  PROTIMER->TXCTRL = (timer + 9) * 0x100 | 1;
  PROTIMER_CCTimerStart(timer,time,mode);
}



void PROTIMER_CCTimerCapture(int num,uint32_t cnt)

{
  (&PROTIMER->CC0_CTRL)[num * 4] = (cnt & 0xe00000) | 3;
}



uint32_t PROTIMER_GetTime(void)

{
  return PROTIMER->WRAPCNT;
}



uint32_t PROTIMER_GetCCTime(int num)

{
  return (&PROTIMER->CC0_WRAP)[num * 4];
}


void PROTIMER_LBTStart(void)

{
  //RADIO_PTI_AuxdataOutput(0x21);
	BUS_RegMaskedSet(&PROTIMER->CMD, PROTIMER_CMD_LBTSTART_Msk); 
}


void PROTIMER_LBTPause(void)

{
  //RADIO_PTI_AuxdataOutput(0x23);
  BUS_RegMaskedSet(&PROTIMER->CMD, PROTIMER_CMD_LBTPAUSE_Msk);
}





void PROTIMER_LBTStop(void)

{
  //RADIO_PTI_AuxdataOutput(0x22);
  INT_Disable();
	PROTIMER->CMD |= PROTIMER_CMD_LBTSTOP_Msk;
	BUS_RegMaskedSet(&PROTIMER->CMD, PROTIMER_CMD_LBTSTOP_Msk);
  INT_Enable();
}



uint32_t PROTIMER_LBTStateGet(void)

{
  return PROTIMER->LBTSTATE;
}



void PROTIMER_LBTStateSet(uint32_t state)

{
	PROTIMER->LBTSTATE = state;
}



bool PROTIMER_LBTIsActive(void)

{
	if((PROTIMER->STATUS & (PROTIMER_STATUS_LBTRUNNING_Msk | PROTIMER_STATUS_LBTSYNC_Msk)) != 0) return true;
  else return false;
}



uint32_t PROTIMER_PrecntOverflowToUs (uint32_t cnt)

{
  return cnt * 2;
}




uint32_t PROTIMER_UsToPrecntOverflow(uint32_t us)
{
	return (us & 1) + (us >> 1);
}



void PROTIMER_Init(void)

{
  uint32_t precnttop;
	
	CMU_ClockEnable(0x60400, true);
  //PROTIMER->CTRL = 0x11100;
  //ratio = 2*((float)CMU_ClockFreqGet(0x60400))/1000000;
	//ratio = 2*((float)SystemHFClockGet())/1000000;
  //precntRatioInt = (uint16_t)(ratio) - 1;
  //precntRatioFrac = (uint8_t)((ratio - precntRatioInt - 1) * 256);
	//PROTIMER->PRECNTTOP = 0x4bcc;
  //PROTIMER->PRECNTTOP = precntRatioInt << 8;
  //PROTIMER->PRECNTTOP |= precntRatioFrac;
	
  PROTIMER->CTRL = 0x11100;
  precnttop = ((SystemHFClockGet() / 1000) * 0x200 + 500) / 1000;
  PROTIMER->PRECNTTOP = precnttop & 0xff | (precnttop & 0xffffff00) - 0x100;
  //PROTIMER->WRAPCNTTOP = 0x7fffffff;

  PROTIMER->WRAPCNTTOP = 0; //PROTIMER_UsToPrecntOverflow(0xffffffff) - 1;
	PROTIMER->IEN |= PROTIMER_IEN_WRAPCNTOF_Msk;
	PROTIMER_Stop();
}



bool PROTIMER_SetTime(uint32_t time)

{
	if(PROTIMER_IsRunning()) PROTIMER_Stop();
	PROTIMER_Reset();
	PROTIMER->WRAPCNT = PROTIMER_UsToPrecntOverflow(time);
	PROTIMER_Start();
	return true;
}

void PROTIMER_SetInterval(uint32_t us)
{
	if(PROTIMER_IsRunning()) PROTIMER_Stop();
	PROTIMER_Reset();
	PROTIMER->WRAPCNTTOP = PROTIMER_UsToPrecntOverflow(us) - 1;
	PROTIMER_Start();	
}



void PROTIMER_LBTCfgSet(uint32_t startexp,uint32_t ccarepeat,uint32_t maxexp,uint32_t retrylimit,uint8_t ccadelay)

{
  PROTIMER->CTRL &= 0xff0fffff;
  PROTIMER->CTRL |= 0x900000;
  if (maxexp == 0) 
  {
    PROTIMER->RXCTRL = 0;
    startexp = maxexp;
  }
  PROTIMER->LBTCTRL = (uint32_t)ccadelay << 8 | retrylimit << 0x18 | ccarepeat << 4 | maxexp << 0x10 | startexp;
  PROTIMER->TOUT0CNTTOP = PROTIMER->BASECNTTOP;
  if (maxexp != 0) 
  {
    PROTIMER->TOUT0COMP = PROTIMER_UsToPrecntOverflow(RADIO_RxWarmTimeGet());
    PROTIMER->RXCTRL = 0x18011b01;
  }
  PROTIMER->TXCTRL = 0x1401;
}


/*
void PROTIMER_DelayUs(uint32_t us)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t cnt;
  uint32_t uVar5;
  uint32_t starttime;
  uint32_t uVar7;
  
  starttime = PROTIMER->WRAPCNT;
  cnt = PROTIMER_UsToPrecntOverflow(us);
  uVar2 = PROTIMER->WRAPCNTTOP;
  if (PROTIMER_IsRunning() != false)
  {
    while(true)
    {
      //uVar7 = cnt;
			//if (PROTIMER->WRAPCNTTOP >> 1 <= cnt) uVar7 = PROTIMER->WRAPCNTTOP >> 1;
			if (PROTIMER->WRAPCNTTOP >> 1 <= cnt) cnt = PROTIMER->WRAPCNTTOP >> 1;
      //do {
      //  uVar5 = PROTIMER_ElapsedTime(starttime,PROTIMER->WRAPCNT);
      //} while (uVar5 < uVar7);
			while(PROTIMER_ElapsedTime(starttime,PROTIMER->WRAPCNT) < cnt);
			if (cnt <= PROTIMER_ElapsedTime(starttime,PROTIMER->WRAPCNT)) break;
      cnt = cnt - PROTIMER_ElapsedTime(starttime,PROTIMER->WRAPCNT);
      starttime = PROTIMER->WRAPCNT;
    }
  }
}
*/

void PROTIMER_DelayUs(uint32_t us)
{
	PROTIMER_SetInterval(us);
	while(!(PROTIMER->IF & PROTIMER_IF_WRAPCNTOF_Msk));
	PROTIMER->IFC |= PROTIMER_IFC_WRAPCNTOF_Msk;
	PROTIMER_Stop();
}

