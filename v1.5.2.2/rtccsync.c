#include "rtccsync.h"



uint RTCCSYNC_RTCCClockFreqGet(void)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  
  uVar1 = 0;
  uVar2 = read_volatile_4(Peripherals::RTCC.CTRL);
  bVar3 = (uVar2 & 0x1000) == 0;
  if (bVar3) {
    uVar2 = read_volatile_4(Peripherals::RTCC.CTRL);
    uVar1 = (uVar2 << 0x14) >> 0x1c;
  }
  uVar2 = 1;
  if (bVar3) {
    uVar2 = 1 << uVar1;
  }
  uVar1 = CMU_ClockFreqGet(0x120980);
  return uVar1 / uVar2;
}



void RTCCSYNC_Init(void)

{
  write_volatile_4(Peripherals::PRS.CH7_CTRL,0x2901);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined4 RTCCSYNC_PreSleep(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  bool bVar13;
  longlong lVar14;
  
  iVar6 = param_1;
  iVar1 = RTCCSYNC_RTCCClockFreqGet();
  uVar7 = read_volatile_4(Peripherals::PROTIMER.CTRL);
  uVar2 = PROTIMER_GetTime();
  uVar3 = 0;
  uVar12 = 0xffffffff;
  iVar9 = 0;
  do {
    uVar8 = iVar9 * 0x10;
    uVar11 = (&Peripherals::PROTIMER.CC0_CTRL)[iVar9 * 4] & 3;
    if (uVar11 == 1) {
      uVar4 = PROTIMER_GetCCTime(iVar9);
      uVar5 = PROTIMER_ElapsedTime(uVar2,uVar4);
      uVar10 = read_volatile_4(Peripherals::PROTIMER.IF);
      uVar8 = 1 << (iVar9 + 8U & 0xff);
      uVar3 = uVar11;
      if ((uVar8 & uVar10) == 0) {
        if (uVar5 <= uVar12) {
          uVar12 = uVar5;
        }
      }
      else {
        uVar12 = 0;
      }
    }
    iVar9 = iVar9 + 1;
  } while (iVar9 != 5);
  if ((uVar7 & 0x30000) == 0x20000) {
    bVar13 = (uVar7 & 0x3000) == 0x1000;
    uVar7 = read_volatile_4(Peripherals::PROTIMER.BASECNTTOP);
    if (bVar13) {
      uVar8 = read_volatile_4(Peripherals::PROTIMER.PRECNTTOP);
    }
    uVar7 = uVar7 + 1;
    if (bVar13) {
      lVar14 = (ulonglong)(uVar8 + 0x100) * (ulonglong)uVar7;
      uVar7 = (uint)lVar14;
      uVar8 = (uint)((ulonglong)lVar14 >> 0x20);
    }
    else {
      uVar8 = uVar7 >> 0x18;
      uVar7 = uVar7 * 0x100;
    }
  }
  else {
    uVar7 = read_volatile_4(Peripherals::PROTIMER.PRECNTTOP);
    uVar8 = 0;
    uVar7 = uVar7 + 0x100;
  }
  uVar11 = read_volatile_4(Peripherals::RTCC.CNT);
  uVar10 = read_volatile_4(Peripherals::RAC.STATUS);
  if ((uVar10 & 0xf000000) == 0) {
    uVar10 = read_volatile_4(Peripherals::PROTIMER.STATUS);
    uVar10 = uVar10 & 6;
    if (uVar10 == 0) {
      if (uVar3 == 0) {
        return 1;
      }
      uVar5 = (uint)((ulonglong)uVar7 * (ulonglong)uVar12);
      uVar3 = (iVar1 * param_1 + 500000U) / 1000000;
      uVar12 = uVar12 * uVar8 + (int)((ulonglong)uVar7 * (ulonglong)uVar12 >> 0x20);
      uVar7 = CMU_ClockFreqGet(0x11);
      lVar14 = (ulonglong)uVar7 * (ulonglong)(uVar3 + 6);
      uVar2 = RTCCSYNC_RTCCClockFreqGet();
      lVar14 = __aeabi_uldivmod((int)lVar14,(int)((ulonglong)lVar14 >> 0x20),uVar2,0,iVar6,uVar11);
      uVar7 = (uint)((ulonglong)(lVar14 << 8) >> 0x20);
      bVar13 = uVar12 <= uVar7;
      if (uVar7 == uVar12) {
        bVar13 = uVar5 <= (uint)(lVar14 << 8);
      }
      if (!bVar13) {
        uVar7 = RTCCSYNC_RTCCClockFreqGet();
        lVar14 = (ulonglong)uVar7 * (ulonglong)(uVar5 >> 8 | uVar12 * 0x1000000);
        uVar2 = CMU_ClockFreqGet(0x11);
        iVar6 = __aeabi_uldivmod((int)lVar14,
                                 uVar7 * (uVar12 >> 8) + (int)((ulonglong)lVar14 >> 0x20),uVar2,0);
        write_volatile_4(Peripherals::RTCC.CC0_CTRL,0);
        ccCtrlBackup = read_volatile_4(Peripherals::PROTIMER.CC0_CTRL);
        write_volatile_4(Peripherals::PROTIMER.CC0_CTRL,0x70003);
        write_volatile_4(Peripherals::RTCC.IFC,2);
        write_volatile_4(Peripherals::PROTIMER.IFC,0x100);
        uVar12 = read_volatile_4(Peripherals::PROTIMER.IEN);
        write_volatile_4(Peripherals::PROTIMER.IEN,0);
        uVar7 = read_volatile_4(Peripherals::RTCC.CNT);
        write_volatile_4(Peripherals::RTCC.CC0_CCV,uVar7 + 1);
        write_volatile_4(Peripherals::RTCC.CC0_CTRL,2);
        refRtcCnt = read_volatile_4(Peripherals::RTCC.CC0_CCV);
        while( true ) {
          do {
            uVar7 = read_volatile_4(Peripherals::RTCC.CNT);
            uVar8 = read_volatile_4(Peripherals::PROTIMER.IF);
            if ((uVar8 & 0x100) != 0) {
              write_volatile_4(Peripherals::PROTIMER.IFC,0x100);
              write_volatile_4(Peripherals::PROTIMER.IEN,uVar12);
              iVar1 = uVar3 + 2;
              write_volatile_4(Peripherals::RTCC.CC0_CCV,(uVar11 - iVar1) + iVar6);
              write_volatile_4(Peripherals::RTCC.IFC,2);
              uVar7 = read_volatile_4(Peripherals::RTCC.CNT);
              uVar3 = read_volatile_4(Peripherals::RTCC.CC0_CCV);
              if (uVar7 - uVar3 < (uint)(iVar1 - iVar6)) {
                _DAT_46042024 = 2;
                return 0;
              }
              write_volatile_4(Peripherals::PROTIMER.CMD,2);
              write_volatile_4(Peripherals::PROTIMER_CLR.CC0_CTRL,1);
              rtccSyncFlag = 1;
              _DAT_46042024 = 2;
              return 1;
            }
          } while (uVar7 != refRtcCnt + 1);
          if (uVar10 != 0) break;
          refRtcCnt = refRtcCnt + 2;
          write_volatile_4(Peripherals::RTCC.CC0_CCV,refRtcCnt);
          uVar10 = 1;
        }
      }
    }
  }
  return 0;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void RTCCSYNC_PostWakeUp(void)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 in_r3;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  longlong lVar9;
  
  if (rtccSyncFlag == '\0') {
    return;
  }
  uVar1 = read_volatile_4(Peripherals::PROTIMER.CC0_WRAP);
  _DAT_44042024 = 2;
  uVar2 = CORE_EnterCritical();
  iVar5 = refRtcCnt;
  write_volatile_4(Peripherals::RTCC.CC0_CTRL,0);
  write_volatile_4(Peripherals::PROTIMER_SET.PRSCTRL,0x700000);
  write_volatile_4(Peripherals::PROTIMER_SET.PRSCTRL,0x20000);
  write_volatile_4(Peripherals::PROTIMER.CMD,2);
  write_volatile_4(Peripherals::PROTIMER.IFC,0x1000000);
  uVar7 = read_volatile_4(Peripherals::RTCC.CNT);
  write_volatile_4(Peripherals::RTCC.CC0_CCV,uVar7 + 2);
  write_volatile_4(Peripherals::RTCC.CC0_CTRL,2);
  uVar7 = read_volatile_4(Peripherals::RTCC.CC0_CCV);
  uVar3 = CMU_ClockFreqGet(0x11);
  uVar4 = RTCCSYNC_RTCCClockFreqGet();
  uVar6 = read_volatile_4(Peripherals::PROTIMER.CTRL);
  if ((uVar6 & 0x11000) != 0) {
    lVar9 = (ulonglong)uVar3 * (ulonglong)(uVar7 - iVar5);
    lVar9 = __aeabi_uldivmod((int)lVar9,(int)((ulonglong)lVar9 >> 0x20),uVar4,0,in_r3);
    uVar7 = read_volatile_4(Peripherals::PROTIMER.PRECNTTOP);
    uVar6 = read_volatile_4(Peripherals::PROTIMER.CC0_PRE);
    uVar8 = (undefined4)((ulonglong)(lVar9 << 8) >> 0x20);
    uVar7 = uVar7 + 0x100;
    uVar4 = (undefined4)(lVar9 << 8);
    iVar5 = 0;
    uVar3 = uVar7;
    __aeabi_uldivmod(uVar4,uVar8);
    uVar6 = uVar6 + (uVar3 >> 8 | iVar5 << 0x18);
    iVar5 = __aeabi_uldivmod(uVar4,uVar8,uVar7,0);
    if (uVar7 >> 8 <= uVar6) {
      iVar5 = iVar5 + 1;
      uVar6 = uVar6 - (uVar7 >> 8);
    }
    write_volatile_4(Peripherals::PROTIMER.PRECNT,uVar6);
    uVar6 = read_volatile_4(Peripherals::PROTIMER.CC0_BASE);
    uVar7 = read_volatile_4(Peripherals::PROTIMER.BASECNTTOP);
    write_volatile_4(Peripherals::PROTIMER.BASECNT,
                     (uVar6 + iVar5) - (uVar7 + 1) * ((uVar6 + iVar5) / (uVar7 + 1)));
    uVar6 = read_volatile_4(Peripherals::PROTIMER.CC0_WRAP);
    uVar6 = iVar5 + uVar6;
    uVar7 = read_volatile_4(Peripherals::PROTIMER.WRAPCNTTOP);
    if (uVar7 != 0xffffffff) {
      uVar6 = uVar6 - (uVar7 + 1) * (uVar6 / (uVar7 + 1));
    }
    write_volatile_4(Peripherals::PROTIMER.WRAPCNT,uVar6);
  }
  CORE_ExitCritical(uVar2);
  do {
    uVar7 = read_volatile_4(Peripherals::PROTIMER.IF);
    if ((int)(uVar7 << 7) < 0) break;
    uVar7 = read_volatile_4(Peripherals::RTCC.CNT);
    uVar6 = read_volatile_4(Peripherals::RTCC.CC0_CCV);
  } while (uVar6 - uVar7 < 3);
  write_volatile_4(Peripherals::PROTIMER.IFC,0x1000000);
  write_volatile_4(Peripherals::PROTIMER.CC0_CTRL,ccCtrlBackup);
  write_volatile_4(Peripherals::PROTIMER_CLR.PRSCTRL,0x720000);
  iVar5 = 0;
  write_volatile_4(Peripherals::RTCC.CC0_CTRL,0);
  uVar7 = read_volatile_4(Peripherals::PROTIMER.WRAPCNT);
  do {
    if ((int)((&Peripherals::PROTIMER.CC0_CTRL)[iVar5 * 4] << 0x1f) < 0) {
      uVar6 = read_volatile_4(Peripherals::PROTIMER.IF);
      uVar3 = 1 << (iVar5 + 8U & 0xff);
      if ((uVar3 & uVar6) == 0) {
        uVar6 = (&Peripherals::PROTIMER.CC0_WRAP)[iVar5 * 4];
        if (uVar7 < uVar1) {
          if (uVar6 <= uVar1) goto LAB_000103a2;
LAB_000103b0:
          write_volatile_4(Peripherals::PROTIMER.IFS,uVar3);
        }
        else {
          if (uVar1 < uVar6) {
LAB_000103a2:
            if (uVar6 <= uVar7) goto LAB_000103b0;
          }
        }
      }
    }
    iVar5 = iVar5 + 1;
    if (iVar5 == 5) {
      rtccSyncFlag = 0;
      return;
    }
  } while( true );
}


