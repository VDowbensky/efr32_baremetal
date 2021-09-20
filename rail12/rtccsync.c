#include "rtccsync.h"



uint RTCCSYNC_RTCCClockFreqGet(void)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  
  uVar1 = 0;
  uVar2 = (Peripherals::RTCC.CTRL);
  bVar3 = (uVar2 & 0x1000) == 0;
  if (bVar3) 
  {
    uVar2 = (Peripherals::RTCC.CTRL);
    uVar1 = (uVar2 << 0x14) >> 0x1c;
  }
  uVar2 = 1;
  if (bVar3) 
  {
    uVar2 = 1 << uVar1;
  }
  uVar1 = CMU_ClockFreqGet(0x100980);
  return uVar1 / uVar2;
}



void RTCCSYNC_Init(void)

{
  write_volatile_4(Peripherals::PRS.CH7_CTRL,0x2901);
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined4 RTCCSYNC_PreSleep(int param_1,undefined4 param_2,undefined4 param_3)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  bool bVar13;
  undefined8 uVar14;
  uint uVar15;
  
  iVar7 = param_1;
  iVar4 = RTCCSYNC_RTCCClockFreqGet();
  uVar8 = 0;
  uVar15 = (PROTIMER->CTRL);
  uVar9 = (PROTIMER->WRAPCNT);
  uVar12 = 0xffffffff;
  iVar10 = 0;
  do {
    uVar11 = (&PROTIMER->CC0_CTRL)[iVar10 * 4] & 3;
    if (uVar11 == 1) 
	{
      uVar5 = PROTIMER_ElapsedTime
                        (uVar9,(&PROTIMER->CC0_WRAP)[iVar10 * 4],uVar8,0x40085080,iVar7,
                         param_2,param_3);
      uVar3 = (PROTIMER->IF);
      uVar8 = uVar11;
      if ((1 << (iVar10 + 8U & 0xff) & uVar3) == 0) 
	  {
        if (uVar5 <= uVar12) 
		{
          uVar12 = uVar5;
        }
      }
      else 
	  {
        uVar12 = 0;
      }
    }
    iVar10 = iVar10 + 1;
  } while (iVar10 != 5);
  if ((uVar15 & 0x30000) == 0x20000) 
  {
    uVar9 = (PROTIMER->BASECNTTOP);
    uVar9 = uVar9 + 1;
    if ((uVar15 & 0x3000) == 0x1000) 
	{
      uVar15 = (PROTIMER->PRECNTTOP);
      uVar9 = (uVar15 >> 8) * uVar9 + uVar9;
    }
  }
  else 
  {
    uVar15 = (PROTIMER->PRECNTTOP);
    uVar9 = (uVar15 >> 8) + 1;
  }
  uVar15 = (Peripherals::RTCC.CNT);
  uVar11 = (RAC->STATUS);
  if ((uVar11 & 0xf000000) == 0) 
  {
    uVar11 = (PROTIMER->STATUS);
    uVar11 = uVar11 & 6;
    if (uVar11 == 0) 
	{
      if (uVar8 == 0) 
	  {
        return 1;
      }
      uVar1 = (ulonglong)uVar9 * (ulonglong)uVar12;
      uVar12 = (uint)(uVar1 >> 0x20);
      uVar8 = (param_1 * iVar4 + 500000U) / 1000000;
      uVar9 = CMU_ClockFreqGet(0x11);
      lVar2 = (ulonglong)uVar9 * (ulonglong)(uVar8 + 5);
      uVar6 = RTCCSYNC_RTCCClockFreqGet();
      uVar14 = __aeabi_uldivmod((int)lVar2,(int)((ulonglong)lVar2 >> 0x20),uVar6,0,iVar7,uVar15);
      uVar9 = (uint)((ulonglong)uVar14 >> 0x20);
      bVar13 = uVar12 <= uVar9;
      if (uVar9 == uVar12) 
	  {
        bVar13 = (uint)uVar1 <= (uint)uVar14;
      }
      if (!bVar13) 
	  {
        uVar9 = RTCCSYNC_RTCCClockFreqGet();
        lVar2 = (ulonglong)uVar9 * (uVar1 & 0xffffffff);
        uVar6 = CMU_ClockFreqGet(0x11);
        iVar7 = __aeabi_uldivmod((int)lVar2,uVar9 * uVar12 + (int)((ulonglong)lVar2 >> 0x20),uVar6,0);
        write_volatile_4(Peripherals::RTCC.CC0_CTRL,0);
        ccCtrlBackup = (PROTIMER->CC0_CTRL);
        write_volatile_4(PROTIMER->CC0_CTRL,0x70003);
        write_volatile_4(Peripherals::RTCC.IFC,2);
        write_volatile_4(PROTIMER->IFC,0x100);
        uVar12 = (PROTIMER->IEN);
        write_volatile_4(PROTIMER->IEN,0);
        uVar9 = (Peripherals::RTCC.CNT);
        write_volatile_4(Peripherals::RTCC.CC0_CCV,uVar9 + 1);
        write_volatile_4(Peripherals::RTCC.CC0_CTRL,2);
        refRtcCnt = (Peripherals::RTCC.CC0_CCV);
        while( true ) 
		{
          do 
		  {
            uVar9 = (Peripherals::RTCC.CNT);
            uVar3 = (PROTIMER->IF);
            if ((uVar3 & 0x100) != 0) 
			{
              write_volatile_4(PROTIMER->IFC,0x100);
              write_volatile_4(PROTIMER->IEN,uVar12);
              iVar4 = uVar8 + 2;
              write_volatile_4(Peripherals::RTCC.CC0_CCV,(uVar15 - iVar4) + iVar7);
              write_volatile_4(Peripherals::RTCC.IFC,2);
              uVar15 = (Peripherals::RTCC.IEN);
              write_volatile_4(Peripherals::RTCC.IEN,uVar15 | 2);
              uVar15 = (Peripherals::RTCC.CNT);
              uVar9 = (Peripherals::RTCC.CC0_CCV);
              if (uVar15 - uVar9 < (uint)(iVar4 - iVar7)) 
			  {
                return 0;
              }
              rtccSyncFlag = 1;
              _DAT_430a0084 = 1;
              return 1;
            }
          } while (uVar9 != refRtcCnt + 1);
          if (uVar11 != 0) break;
          refRtcCnt = refRtcCnt + 2;
          write_volatile_4(Peripherals::RTCC.CC0_CCV,refRtcCnt);
          uVar11 = 1;
        }
      }
    }
  }
  return 0;
}



void RTCCSYNC_PostWakeUp(void)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined8 uVar8;
  
  iVar5 = refRtcCnt;
  if (rtccSyncFlag == '\0') 
  {
    return;
  }
  uVar2 = (PROTIMER->CC0_WRAP);
  uVar7 = (PROTIMER->PRSCTRL);
  write_volatile_4(PROTIMER->PRSCTRL,uVar7 | 0x720000);
  uVar7 = (Peripherals::RTCC.IEN);
  write_volatile_4(Peripherals::RTCC.IEN,uVar7 & 0xfffffffd);
  uVar7 = (Peripherals::RTCC.CNT);
  write_volatile_4(Peripherals::RTCC.CC0_CCV,uVar7 + 2);
  uVar7 = (Peripherals::RTCC.CC0_CCV);
  uVar3 = CMU_ClockFreqGet(0x11);
  uVar4 = RTCCSYNC_RTCCClockFreqGet();
  uVar6 = (PROTIMER->CTRL);
  if ((uVar6 & 0x11000) != 0) 
  {
    lVar1 = (ulonglong)uVar3 * (ulonglong)(uVar7 - iVar5);
    uVar8 = __aeabi_uldivmod((int)lVar1,(int)((ulonglong)lVar1 >> 0x20),uVar4,0);
    uVar7 = (PROTIMER->PRECNTTOP);
    uVar6 = (PROTIMER->CC0_PRE);
    uVar7 = uVar7 >> 8;
    iVar5 = uVar7 + 1;
    __aeabi_uldivmod();
    uVar6 = uVar6 + iVar5;
    iVar5 = __aeabi_uldivmod((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),uVar7 + 1,0);
    if (uVar7 < uVar6) 
	{
      iVar5 = iVar5 + 1;
      uVar6 = (uVar6 - uVar7) - 1;
    }
    write_volatile_4(PROTIMER->PRECNT,uVar6);
    uVar6 = (PROTIMER->CC0_BASE);
    uVar7 = (PROTIMER->BASECNTTOP);
    write_volatile_4(PROTIMER->BASECNT,
                     (uVar6 + iVar5) - (uVar7 + 1) * ((uVar6 + iVar5) / (uVar7 + 1)));
    uVar6 = (PROTIMER->CC0_WRAP);
    uVar7 = (PROTIMER->WRAPCNTTOP);
    write_volatile_4(PROTIMER->WRAPCNT,
                     (iVar5 + uVar6) - (uVar7 + 1) * ((iVar5 + uVar6) / (uVar7 + 1)));
  }
  do 
  {
    uVar7 = (PROTIMER->IF);
    if ((int)(uVar7 << 7) < 0) break;
    uVar7 = (Peripherals::RTCC.CNT);
    uVar6 = (Peripherals::RTCC.CC0_CCV);
  } while (uVar6 - uVar7 < 3);
  write_volatile_4(PROTIMER->IFC,0x1000000);
  write_volatile_4(Peripherals::RTCC.IFC,2);
  write_volatile_4(PROTIMER->CC0_CTRL,ccCtrlBackup);
  uVar7 = (PROTIMER->PRSCTRL);
  write_volatile_4(PROTIMER->PRSCTRL,uVar7 & 0xff8dffff);
  iVar5 = 0;
  uVar7 = (PROTIMER->WRAPCNT);
  do 
  {
    if ((int)((&PROTIMER->CC0_CTRL)[iVar5 * 4] << 0x1f) < 0) 
	{
      uVar6 = (PROTIMER->IF);
      uVar3 = 1 << (iVar5 + 8U & 0xff);
      if ((uVar3 & uVar6) == 0) {
        uVar6 = (&PROTIMER->CC0_WRAP)[iVar5 * 4];
        if (uVar7 < uVar2) 
		{
          if (uVar6 <= uVar2) goto LAB_00010334;
LAB_00010342:
          write_volatile_4(PROTIMER->IFS,uVar3);
        }
        else 
		{
          if (uVar2 < uVar6) 
		  {
LAB_00010334:
            if (uVar6 <= uVar7) goto LAB_00010342;
          }
        }
      }
    }
    iVar5 = iVar5 + 1;
    if (iVar5 == 5) 
	{
      rtccSyncFlag = 0;
      return;
    }
  } while( true );
}


