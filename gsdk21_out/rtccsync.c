#include "rtccsync.h"



uint RTCCSYNC_RTCCClockFreqGet(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  
  uVar1 = CMU_ClockFreqGet(0x120980);
  uVar2 = 0;
  uVar3 = read_volatile_4(Peripherals::RTCC.CTRL);
  bVar4 = (uVar3 & 0x1000) == 0;
  if (bVar4) {
    uVar2 = read_volatile_4(Peripherals::RTCC.CTRL);
  }
  uVar3 = 1;
  if (bVar4) {
    uVar3 = 1 << ((uVar2 << 0x14) >> 0x1c);
  }
  return uVar1 / uVar3;
}



void RTCCSYNC_Init(void)

{
  write_volatile_4(Peripherals::PRS.CH7_CTRL,0x102901);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined4 RTCCSYNC_PreSleep(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  bool bVar14;
  longlong lVar15;
  
  iVar2 = RTCCSYNC_RTCCClockFreqGet();
  uVar3 = CORE_EnterCritical();
  uVar9 = read_volatile_4(Peripherals::PROTIMER.CTRL);
  uVar4 = PROTIMER_GetTime();
  uVar11 = 0;
  uVar7 = 0xffffffff;
  iVar13 = 0;
  do {
    uVar8 = (&Peripherals::PROTIMER.CC0_CTRL)[iVar13 * 4] & 3;
    if (uVar8 == 1) {
      uVar5 = PROTIMER_GetCCTime(iVar13);
      uVar6 = PROTIMER_ElapsedTime(uVar4,uVar5);
      uVar1 = read_volatile_4(Peripherals::PROTIMER.IF);
      uVar11 = uVar8;
      if ((uVar1 >> (iVar13 + 8U & 0xff) & 1) == 0) {
        if (uVar6 <= uVar7) {
          uVar7 = uVar6;
        }
      }
      else {
        uVar7 = 0;
      }
    }
    iVar13 = iVar13 + 1;
  } while (iVar13 != 5);
  if ((uVar9 & 0x30000) == 0x20000) {
    uVar1 = read_volatile_4(Peripherals::PROTIMER.BASECNTTOP);
    uVar6 = uVar1 + 1;
    if ((uVar9 & 0x3000) == 0x1000) {
      uVar9 = read_volatile_4(Peripherals::PROTIMER.PRECNTTOP);
      lVar15 = (ulonglong)(uVar9 + 0x100) * (ulonglong)uVar6;
      uVar8 = (uint)lVar15;
      uVar9 = (int)((ulonglong)lVar15 >> 0x20) +
              uVar6 * (0xfffffeff < uVar9) + (uVar9 + 0x100) * (uint)(0xfffffffe < uVar1);
    }
    else {
      uVar9 = (uint)(0xfffffffe < uVar1) << 8 | uVar6 >> 0x18;
      uVar8 = uVar6 * 0x100;
    }
  }
  else {
    uVar9 = read_volatile_4(Peripherals::PROTIMER.PRECNTTOP);
    uVar8 = uVar9 + 0x100;
    uVar9 = (uint)(0xfffffeff < uVar9);
  }
  uVar1 = read_volatile_4(Peripherals::RTCC.CNT);
  uVar10 = read_volatile_4(Peripherals::PROTIMER.STATUS);
  uVar6 = read_volatile_4(Peripherals::RAC.STATUS);
  if (((uVar6 & 0xf000000) == 0) && (uVar10 = uVar10 & 6, uVar10 == 0)) {
    uVar6 = CMU_ClockFreqGet(0x11);
    uVar4 = RTCCSYNC_RTCCClockFreqGet();
    if (uVar11 == 0) {
      uVar4 = 1;
      goto LAB_00010266;
    }
    uVar12 = (uint)((ulonglong)uVar8 * (ulonglong)uVar7);
    uVar11 = (param_1 * iVar2 + 500000U) / 1000000;
    uVar7 = uVar7 * uVar9 + (int)((ulonglong)uVar8 * (ulonglong)uVar7 >> 0x20);
    lVar15 = (ulonglong)uVar6 * (ulonglong)(uVar11 + 6);
    lVar15 = __aeabi_uldivmod((int)lVar15,(int)((ulonglong)lVar15 >> 0x20),uVar4,0);
    uVar9 = (uint)((ulonglong)(lVar15 << 8) >> 0x20);
    bVar14 = uVar7 <= uVar9;
    if (uVar9 == uVar7) {
      bVar14 = uVar12 <= (uint)(lVar15 << 8);
    }
    if (!bVar14) {
      uVar9 = RTCCSYNC_RTCCClockFreqGet();
      lVar15 = (ulonglong)uVar9 * (ulonglong)(uVar12 >> 8 | uVar7 * 0x1000000);
      uVar4 = CMU_ClockFreqGet(0x11);
      iVar2 = __aeabi_uldivmod((int)lVar15,uVar9 * (uVar7 >> 8) + (int)((ulonglong)lVar15 >> 0x20),
                               uVar4,0);
      write_volatile_4(Peripherals::RTCC.CC0_CTRL,0);
      uVar7 = read_volatile_4(Peripherals::PROTIMER.IEN);
      write_volatile_4(Peripherals::PROTIMER.IEN,0);
      protimerCcCtrlBackup = read_volatile_4(Peripherals::PROTIMER.CC0_CTRL);
      write_volatile_4(Peripherals::PROTIMER.CC0_CTRL,0x70003);
      write_volatile_4(Peripherals::RTCC.IFC,2);
      write_volatile_4(Peripherals::PROTIMER.IFC,0x100);
      uVar9 = read_volatile_4(Peripherals::RTCC.CNT);
      write_volatile_4(Peripherals::RTCC.CC0_CCV,uVar9 + 1);
      write_volatile_4(Peripherals::RTCC.CC0_CTRL,2);
      refRtcCnt = read_volatile_4(Peripherals::RTCC.CC0_CCV);
      do {
        do {
          uVar9 = read_volatile_4(Peripherals::RTCC.CNT);
          uVar8 = read_volatile_4(Peripherals::PROTIMER.IF);
          if ((uVar8 & 0x100) != 0) {
            write_volatile_4(Peripherals::PROTIMER.IFC,0x100);
            write_volatile_4(Peripherals::PROTIMER.IEN,uVar7);
            iVar13 = uVar11 + 2;
            write_volatile_4(Peripherals::RTCC.CC0_CCV,(uVar1 - iVar13) + iVar2);
            write_volatile_4(Peripherals::RTCC.IFC,2);
            _DAT_46042024 = 2;
            uVar9 = read_volatile_4(Peripherals::RTCC.CNT);
            uVar7 = read_volatile_4(Peripherals::RTCC.CC0_CCV);
            if (uVar9 - uVar7 < (uint)(iVar13 - iVar2)) {
              write_volatile_4(Peripherals::PROTIMER.CC0_CTRL,protimerCcCtrlBackup);
              CORE_ExitCritical(uVar3);
              return 0;
            }
            uVar4 = 1;
            rtccSyncFlag = 1;
            write_volatile_4(Peripherals::PROTIMER.CMD,2);
            write_volatile_4(Peripherals::PROTIMER_CLR.CC0_CTRL,1);
            goto LAB_00010266;
          }
        } while (uVar9 != refRtcCnt + 1);
        if (uVar10 != 0) {
          CORE_ExitCritical(uVar3);
          RAILInt_Assert(0,0x1a);
        }
        refRtcCnt = refRtcCnt + 2;
        uVar10 = 1;
        write_volatile_4(Peripherals::RTCC.CC0_CCV,refRtcCnt);
      } while( true );
    }
  }
  uVar4 = 0;
LAB_00010266:
  CORE_ExitCritical(uVar3);
  return uVar4;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void RTCCSYNC_PostWakeUp(void)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
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
    uVar6 = read_volatile_4(Peripherals::PROTIMER.PRECNTTOP);
    uVar6 = uVar6 + 0x100;
    if (uVar6 == 0) {
      RAILInt_Assert(0,0x2b);
      uVar6 = 1;
    }
    lVar9 = (ulonglong)uVar3 * (ulonglong)(uVar7 - iVar5);
    lVar9 = __aeabi_uldivmod((int)lVar9,(int)((ulonglong)lVar9 >> 0x20),uVar4,0);
    uVar8 = (undefined4)((ulonglong)(lVar9 << 8) >> 0x20);
    uVar4 = (undefined4)(lVar9 << 8);
    iVar5 = 0;
    uVar3 = uVar6;
    __aeabi_uldivmod(uVar4,uVar8);
    uVar7 = read_volatile_4(Peripherals::PROTIMER.CC0_PRE);
    uVar7 = uVar7 + (uVar3 >> 8 | iVar5 << 0x18);
    iVar5 = __aeabi_uldivmod(uVar4,uVar8,uVar6,0);
    if (uVar6 >> 8 <= uVar7) {
      iVar5 = iVar5 + 1;
      uVar7 = uVar7 - (uVar6 >> 8);
    }
    write_volatile_4(Peripherals::PROTIMER.PRECNT,uVar7);
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
    uVar7 = read_volatile_4(Peripherals::RTCC.CNT);
    uVar6 = read_volatile_4(Peripherals::PROTIMER.IF);
    if ((uVar6 & 0x1000000) != 0) goto LAB_000103ca;
    uVar6 = read_volatile_4(Peripherals::RTCC.CC0_CCV);
  } while (uVar6 - uVar7 < 3);
  RAILInt_Assert(0,0xd);
LAB_000103ca:
  write_volatile_4(Peripherals::PROTIMER.IFC,0x1000000);
  write_volatile_4(Peripherals::PROTIMER.CC0_CTRL,protimerCcCtrlBackup);
  write_volatile_4(Peripherals::PROTIMER_CLR.PRSCTRL,0x720000);
  write_volatile_4(Peripherals::RTCC.CC0_CTRL,0);
  rtccSyncFlag = 0;
  CORE_EnterCritical();
  uVar7 = read_volatile_4(Peripherals::PROTIMER.WRAPCNT);
  iVar5 = 0;
  do {
    uVar6 = read_volatile_4(Peripherals::PROTIMER.IF);
    if (((int)((&Peripherals::PROTIMER.CC0_CTRL)[iVar5 * 4] << 0x1f) < 0) &&
       (-1 < (int)((uVar6 >> (iVar5 + 8U & 0xff)) << 0x1f))) {
      uVar6 = (&Peripherals::PROTIMER.CC0_WRAP)[iVar5 * 4];
      if (uVar7 < uVar1) {
        if (uVar6 <= uVar1) goto LAB_0001041a;
LAB_0001042c:
        write_volatile_4(Peripherals::PROTIMER.IFS,1 << (iVar5 + 8U & 0xff));
      }
      else {
        if (uVar1 < uVar6) {
LAB_0001041a:
          if (uVar6 <= uVar7) goto LAB_0001042c;
        }
      }
    }
    iVar5 = iVar5 + 1;
    if (iVar5 == 5) {
      CORE_ExitCritical();
      return;
    }
  } while( true );
}



uint RTCCSYNC_GetRtccCount(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::RTCC.CNT);
  return uVar1;
}


