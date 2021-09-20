#include "protimer.h"




void PROTIMER_Start(void)

{
  _DAT_430a0080 = 1;
  _DAT_e000e100 = 0x10000000;
  _DAT_e000e280 = 0x10000000;
}



void PROTIMER_Stop(void)

{
  _DAT_430a0088 = 1;
  _DAT_e000e180 = 0x10000000;
  _DAT_e000e280 = 0x10000000;
}



bool PROTIMER_IsRunning(void)

{
  return PROTIMER->STATUS & 1;
}



void PROTIMER_Reset(void)

{
  PROTIMER->PRECNT,0;
  PROTIMER->BASECNT,0;
  PROTIMER->WRAPCNT,0;
}



int PROTIMER_ElapsedTime(uint param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = (PROTIMER->WRAPCNTTOP);
  iVar2 = param_2 - param_1;
  if (param_2 < param_1) iVar2 = iVar2 + uVar1 + 1; 
  return iVar2;
}



void PROTIMER_TOUTTimerStop(int param_1)

{
  undefined4 *puVar1;
  
  if (param_1 == 0) 
  {
    puVar1 = (undefined4 *)&DAT_430a0094;
  }
  else 
  {
    puVar1 = (undefined4 *)&DAT_430a009c;
  }
  *puVar1 = 1;
  return;
}



void PROTIMER_TOUTTimerStart(int param_1,int param_2)

{
  undefined4 *puVar1;
  
  if (param_2 == 0) 
  {
    write_volatile_4(PROTIMER->TOUT0CNTTOP,param_1 << 8);
    write_volatile_4(PROTIMER->IFC,0x50);
    puVar1 = (undefined4 *)&DAT_430a0090;
  }
  else 
  {
    write_volatile_4(PROTIMER->TOUT1CNTTOP,param_1 << 8);
    write_volatile_4(PROTIMER->IFC,0xa0);
    puVar1 = (undefined4 *)&DAT_430a0098;
  }
  *puVar1 = 1;
  return;
}



uint PROTIMER_TOUTTimerGet(int param_1)

{
  uint uVar1;
  
  if (param_1 == 0) 
  {
    uVar1 = (PROTIMER->TOUT0CNT);
  }
  else 
  {
    uVar1 = (PROTIMER->TOUT1CNT);
  }
  return (uVar1 << 0x10) >> 0x18;
}



void PROTIMER_CCTimerStop(uint8_t channel)

{
  *(undefined4 *)((uint)channel * 0x200 + 0x430a0e80) = 0;
  write_volatile_4(PROTIMER->IFC,0x100 << (uint)channel);
}



RAIL_Status_t PROTIMER_CCTimerStart(uint32_t channel,uint32_t time,uint32_t mode)

{
  uint uVar1;
  uint uVar2;
  
  INT_Disable();
  uVar1 = (PROTIMER->WRAPCNTTOP);
  uVar2 = (PROTIMER->WRAPCNT);
  if (mode != 1) 
  {
    if (mode != 2) goto LAB_00008e08;
    uVar2 = (&PROTIMER->CC0_WRAP)[channel * 4];
  }
  time = time + uVar2;
LAB_00008e08:
  if (uVar1 < time) 
  {
    time = (time - uVar1) - 1;
  }
  (&PROTIMER->CC0_WRAP)[channel * 4] = time & uVar1;
  uVar2 = (PROTIMER->WRAPCNT);
  uVar2 = PROTIMER_ElapsedTime(time & uVar1,uVar2);
  if (uVar1 >> 2 < uVar2) 
  {
    (&PROTIMER->CC0_CTRL)[channel * 4] = 0x11;
    INT_Enable();
    return RAIL_STATUS_INVALID_PARAMETER;
  }
  *(undefined4 *)((channel + 0x10c28308) * 4) = 1;
  INT_Enable();
  return RAIL_STATUS_NO_ERROR;
}



bool PROTIMER_CCTimerIsEnabled(uint8_t channel)

{
  return (bool)((byte)(&PROTIMER->CC0_CTRL)[(uint)channel * 4] & 1);
}



RAIL_Status_t PROTIMER_ScheduleTxEnable(uint32_t param_1,uint32_t param_2,uint32_t param_3)

{
  RAIL_Status_t RVar1;
  
  if ((int)((&PROTIMER->CC0_CTRL)[param_1 * 4] << 0x1f) < 0) 
  {
    PROTIMER_CCTimerStop((uint8_t)param_1);
  }
  write_volatile_4(PROTIMER->TXCTRL,(param_1 + 9) * 0x100 | 1);
  RVar1 = PROTIMER_CCTimerStart(param_1,param_2,param_3);
  return RVar1;
}



void PROTIMER_CCTimerCapture(int param_1,uint param_2)

{
  (&PROTIMER->CC0_CTRL)[param_1 * 4] = param_2 & 0xe00000 | 3;
  return;
}



uint32_t PROTIMER_GetTime(void)

{
  return PROTIMER->WRAPCNT;
}



uint32_t PROTIMER_GetCCTime(int channel)

{
  return (&PROTIMER->CC0_WRAP)[channel * 4];
}



void PROTIMER_LBTStart(void)

{
  RADIO_PTI_AuxdataOutput(0x21);
  _DAT_430a00c0 = 1;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void PROTIMER_LBTPause(void)

{
  RADIO_PTI_AuxdataOutput(0x23);
  _DAT_430a00c4 = 1;
}



void PROTIMER_LBTStop(void)

{
  RADIO_PTI_AuxdataOutput(0x22);
  INT_Disable();
  _DAT_430a00c8 = 1;
  INT_Enable();
}



uint PROTIMER_LBTStateGet(void)

{
  return PROTIMER->LBTSTATE;
}



void PROTIMER_LBTStateSet(uint32_t state)

{
  PROTIMER->LBTSTATE = state;
}



bool PROTIMER_LBTIsActive(void)

{
  return (PROTIMER->STATUS & 6) != 0;
}



uint32_t PROTIMER_PrecntOverflowToUs(uint32_t count)

{
  longlong lVar1;
  ulonglong uVar2;
  uint uVar3;
  uint32_t uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar3 = RADIOCMU_ClockFreqGet(0x60400);
  uVar5 = (PROTIMER->PRECNTTOP);
  uVar6 = (PROTIMER->PRECNTTOP);
  lVar1 = (ulonglong)count * (ulonglong)(uVar6 & 0xff);
  lVar1 = __aeabi_uldivmod((int)lVar1,(int)((ulonglong)lVar1 >> 0x20),0xff,0);
  uVar2 = (ulonglong)count * (ulonglong)(((uVar5 << 8) >> 0x10) + 1) + lVar1;
  lVar1 = (uVar2 & 0xffffffff) * 1000;
  uVar5 = (uint)lVar1;
  uVar6 = uVar3 / 1000 >> 1;
  uVar4 = __aeabi_uldivmod(uVar6 + uVar5,
                           (int)(uVar2 >> 0x20) * 1000 + (int)((ulonglong)lVar1 >> 0x20) +
                           (uint)CARRY4(uVar6,uVar5),uVar3 / 1000,0);
  return uVar4;
}



uint32_t PROTIMER_UsToPrecntOverflow(uint32_t us)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint32_t uVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  
  uVar2 = RADIOCMU_ClockFreqGet(0x60400);
  uVar3 = (PROTIMER->PRECNTTOP);
  uVar5 = (PROTIMER->PRECNTTOP);
  uVar6 = (((uVar3 << 8) >> 0x10) + 1) * 0xff + (uVar5 & 0xff);
  lVar1 = (ulonglong)us * ((ulonglong)uVar2 / 1000) + 500;
  uVar7 = __aeabi_uldivmod((int)lVar1,(int)((ulonglong)lVar1 >> 0x20),1000,0);
  lVar1 = (uVar7 & 0xffffffff) * 0xff;
  uVar5 = (uint)lVar1;
  uVar3 = uVar6 >> 1;
  uVar4 = __aeabi_uldivmod(uVar5 + uVar3,
                           (int)(uVar7 >> 0x20) * 0xff + (int)((ulonglong)lVar1 >> 0x20) +
                           (uint)CARRY4(uVar5,uVar3),uVar6,0);
  return uVar4;
}



void PROTIMER_Init(void)

{
  uint uVar1;
  uint32_t uVar2;
  
  RADIOCMU_ClockEnable(0x60400,true);
  write_volatile_4(PROTIMER->CTRL,(uint)&DAT_00011100);
  uVar1 = RADIOCMU_ClockFreqGet(0x60400);
  uVar1 = (uVar1 / 1000 << 9) / 1000;
  write_volatile_4(PROTIMER->PRECNTTOP,uVar1 & 0xff | (uVar1 & 0xffffff00) - 0x100);
  uVar2 = PROTIMER_UsToPrecntOverflow(0xffffffff);
  write_volatile_4(PROTIMER->WRAPCNTTOP,uVar2 - 1);
}



bool PROTIMER_SetTime(uint32_t time)

{
  char cVar1;
  uint32_t uVar2;
  
  cVar1 = PROTIMER_IsRunning();
  if ((bool)cVar1 != false) 
  {
    PROTIMER_Stop();
    cVar1 = '\x01';
  }
  PROTIMER_Reset();
  uVar2 = PROTIMER_UsToPrecntOverflow(time);
  write_volatile_4(PROTIMER->WRAPCNT,uVar2);
  if (cVar1 != '\0') 
  {
    PROTIMER_Start();
  }
  return true;
}



void PROTIMER_LBTCfgSet(uint param_1,int param_2,uint param_3,int param_4,byte param_5)

{
  uint uVar1;
  
  uVar1 = (PROTIMER->CTRL);
  write_volatile_4(PROTIMER->CTRL,uVar1 & 0xff0fffff | 0x900000);
  if (param_3 == 0) 
  {
    write_volatile_4(PROTIMER->RXCTRL,0);
    param_1 = param_3;
  }
  write_volatile_4(PROTIMER->LBTCTRL,
                   (uint)param_5 << 8 | param_4 << 0x18 | param_2 << 4 | param_3 << 0x10 | param_1);
  uVar1 = (PROTIMER->BASECNTTOP);
  write_volatile_4(PROTIMER->TOUT0CNTTOP,uVar1);
  if (param_3 != 0) 
  {
    RADIO_RxWarmTimeGet();
    uVar1 = PROTIMER_UsToPrecntOverflow();
    write_volatile_4(PROTIMER->TOUT0COMP,uVar1);
    write_volatile_4(PROTIMER->RXCTRL,0x18011b01);
  }
  write_volatile_4(PROTIMER->TXCTRL,0x1401);
}



void PROTIMER_DelayUs(uint32_t us)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  uint32_t uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar6 = (PROTIMER->WRAPCNT);
  uVar4 = PROTIMER_UsToPrecntOverflow(us);
  uVar2 = (PROTIMER->WRAPCNTTOP);
  bVar3 = PROTIMER_IsRunning();
  if (bVar3 != false) 
  {
    while( true ) 
	{
      uVar7 = uVar4;
      if (uVar2 >> 1 <= uVar4) 
	  {
        uVar7 = uVar2 >> 1;
      }
      do 
	  {
        uVar1 = (PROTIMER->WRAPCNT);
        uVar5 = PROTIMER_ElapsedTime(uVar6,uVar1);
      } while (uVar5 < uVar7);
      if (uVar4 <= uVar5) break;
      uVar4 = uVar4 - uVar5;
      uVar6 = uVar1;
    }
  }
  return;
}


