#include "rtccsync.h"

//rtccSyncFlag;
//refRtcCnt;
//ccCtrlBackup;

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

undefined4 RTCCSYNC_PreSleep(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  PROTIMER *pPVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  bool bVar13;
  longlong lVar14;
  
  iVar5 = param_1;
  iVar1 = RTCCSYNC_RTCCClockFreqGet();
  uVar6 = read_volatile_4(Peripherals::PROTIMER.CTRL);
  uVar8 = read_volatile_4(Peripherals::PROTIMER.WRAPCNT);
  uVar2 = 0;
  uVar12 = 0xffffffff;
  iVar11 = 0;
  do {
    uVar9 = (&Peripherals::PROTIMER.CC0_CTRL)[iVar11 * 4] & 3;
    if (uVar9 == 1) {
      uVar3 = PROTIMER_ElapsedTime
                        (uVar8,(&Peripherals::PROTIMER.CC0_WRAP)[iVar11 * 4],iVar11 * 0x10,
                         0x40085080,iVar5,param_2,param_3);
      uVar10 = read_volatile_4(Peripherals::PROTIMER.IF);
      uVar2 = uVar9;
      if ((1 << (iVar11 + 8U & 0xff) & uVar10) == 0) {
        if (uVar3 <= uVar12) {
          uVar12 = uVar3;
        }
      }
      else {
        uVar12 = 0;
      }
    }
    iVar11 = iVar11 + 1;
  } while (iVar11 != 5);
  pPVar7 = &Peripherals::PROTIMER;
  if ((uVar6 & 0x30000) == 0x20000) {
    bVar13 = (uVar6 & 0x3000) == 0x1000;
    uVar6 = read_volatile_4(Peripherals::PROTIMER.BASECNTTOP);
    if (bVar13) {
      pPVar7 = (PROTIMER *)read_volatile_4(Peripherals::PROTIMER.PRECNTTOP);
    }
    uVar6 = uVar6 + 1;
    if (bVar13) {
      lVar14 = ZEXT48(&pPVar7[1].TOUT0COMP) * (ulonglong)uVar6;
      uVar6 = (uint)lVar14;
      uVar8 = (uint)((ulonglong)lVar14 >> 0x20);
    }
    else {
      uVar8 = uVar6 >> 0x18;
      uVar6 = uVar6 * 0x100;
    }
  }
  else {
    uVar6 = read_volatile_4(Peripherals::PROTIMER.PRECNTTOP);
    uVar8 = 0;
    uVar6 = uVar6 + 0x100;
  }
  uVar9 = read_volatile_4(Peripherals::RTCC.CNT);
  uVar10 = read_volatile_4(Peripherals::RAC.STATUS);
  if ((uVar10 & 0xf000000) == 0) {
    uVar10 = read_volatile_4(Peripherals::PROTIMER.STATUS);
    uVar10 = uVar10 & 6;
    if (uVar10 == 0) {
      if (uVar2 == 0) {
        return 1;
      }
      uVar2 = (uint)((ulonglong)uVar6 * (ulonglong)uVar12);
      uVar12 = uVar12 * uVar8 + (int)((ulonglong)uVar6 * (ulonglong)uVar12 >> 0x20);
      uVar8 = (iVar1 * param_1 + 500000U) / 1000000;
      uVar6 = CMU_ClockFreqGet(0x11);
      lVar14 = (ulonglong)uVar6 * (ulonglong)(uVar8 + 6);
      uVar4 = RTCCSYNC_RTCCClockFreqGet();
      lVar14 = __aeabi_uldivmod((int)lVar14,(int)((ulonglong)lVar14 >> 0x20),uVar4,0,iVar5,uVar9);
      uVar6 = (uint)((ulonglong)(lVar14 << 8) >> 0x20);
      bVar13 = uVar12 <= uVar6;
      if (uVar6 == uVar12) {
        bVar13 = uVar2 <= (uint)(lVar14 << 8);
      }
      if (!bVar13) {
        uVar6 = RTCCSYNC_RTCCClockFreqGet();
        lVar14 = (ulonglong)uVar6 * (ulonglong)(uVar2 >> 8 | uVar12 * 0x1000000);
        uVar4 = CMU_ClockFreqGet(0x11);
        iVar5 = __aeabi_uldivmod((int)lVar14,
                                 uVar6 * (uVar12 >> 8) + (int)((ulonglong)lVar14 >> 0x20),uVar4,0);
        write_volatile_4(Peripherals::RTCC.CC0_CTRL,0);
        ccCtrlBackup = read_volatile_4(Peripherals::PROTIMER.CC0_CTRL);
        write_volatile_4(Peripherals::PROTIMER.CC0_CTRL,0x70003);
        write_volatile_4(Peripherals::RTCC.IFC,2);
        write_volatile_4(Peripherals::PROTIMER.IFC,0x100);
        uVar2 = read_volatile_4(Peripherals::PROTIMER.IEN);
        write_volatile_4(Peripherals::PROTIMER.IEN,0);
        uVar6 = read_volatile_4(Peripherals::RTCC.CNT);
        write_volatile_4(Peripherals::RTCC.CC0_CCV,uVar6 + 1);
        write_volatile_4(Peripherals::RTCC.CC0_CTRL,2);
        refRtcCnt = read_volatile_4(Peripherals::RTCC.CC0_CCV);
        while( true ) {
          do {
            uVar6 = read_volatile_4(Peripherals::RTCC.CNT);
            uVar12 = read_volatile_4(Peripherals::PROTIMER.IF);
            if ((uVar12 & 0x100) != 0) {
              write_volatile_4(Peripherals::PROTIMER.IFC,0x100);
              write_volatile_4(Peripherals::PROTIMER.IEN,uVar2);
              iVar1 = uVar8 + 2;
              write_volatile_4(Peripherals::RTCC.CC0_CCV,(uVar9 - iVar1) + iVar5);
              write_volatile_4(Peripherals::RTCC.IFC,2);
              uVar6 = read_volatile_4(Peripherals::RTCC.CNT);
              uVar8 = read_volatile_4(Peripherals::RTCC.CC0_CCV);
              if (uVar6 - uVar8 < (uint)(iVar1 - iVar5)) {
                _DAT_46042024 = 2;
                return 0;
              }
              write_volatile_4(Peripherals::PROTIMER.CMD,2);
              rtccSyncFlag = 1;
              _DAT_46042024 = 2;
              return 1;
            }
          } while (uVar6 != refRtcCnt + 1);
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
  uint uVar2;
  undefined4 uVar3;
  undefined4 in_r3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  longlong lVar8;
  
  iVar4 = refRtcCnt;
  if (rtccSyncFlag == '\0') {
    return;
  }
  uVar1 = read_volatile_4(Peripherals::PROTIMER.CC0_WRAP);
  write_volatile_4(Peripherals::PROTIMER_SET.PRSCTRL,0x720000);
  _DAT_44042024 = 2;
  uVar6 = read_volatile_4(Peripherals::RTCC.CNT);
  write_volatile_4(Peripherals::RTCC.CC0_CCV,uVar6 + 2);
  uVar6 = read_volatile_4(Peripherals::RTCC.CC0_CCV);
  uVar2 = CMU_ClockFreqGet(0x11);
  uVar3 = RTCCSYNC_RTCCClockFreqGet();
  uVar5 = read_volatile_4(Peripherals::PROTIMER.CTRL);
  if ((uVar5 & 0x11000) != 0) {
    lVar8 = (ulonglong)uVar2 * (ulonglong)(uVar6 - iVar4);
    lVar8 = __aeabi_uldivmod((int)lVar8,(int)((ulonglong)lVar8 >> 0x20),uVar3,0,in_r3);
    uVar6 = read_volatile_4(Peripherals::PROTIMER.PRECNTTOP);
    uVar5 = read_volatile_4(Peripherals::PROTIMER.CC0_PRE);
    uVar7 = (undefined4)((ulonglong)(lVar8 << 8) >> 0x20);
    uVar6 = uVar6 + 0x100;
    uVar3 = (undefined4)(lVar8 << 8);
    iVar4 = 0;
    uVar2 = uVar6;
    __aeabi_uldivmod(uVar3,uVar7);
    uVar5 = uVar5 + (uVar2 >> 8 | iVar4 << 0x18);
    iVar4 = __aeabi_uldivmod(uVar3,uVar7,uVar6,0);
    if (uVar6 >> 8 <= uVar5) {
      iVar4 = iVar4 + 1;
      uVar5 = uVar5 - (uVar6 >> 8);
    }
    write_volatile_4(Peripherals::PROTIMER.PRECNT,uVar5);
    uVar5 = read_volatile_4(Peripherals::PROTIMER.CC0_BASE);
    uVar6 = read_volatile_4(Peripherals::PROTIMER.BASECNTTOP);
    write_volatile_4(Peripherals::PROTIMER.BASECNT,
                     (uVar5 + iVar4) - (uVar6 + 1) * ((uVar5 + iVar4) / (uVar6 + 1)));
    uVar5 = read_volatile_4(Peripherals::PROTIMER.CC0_WRAP);
    uVar6 = read_volatile_4(Peripherals::PROTIMER.WRAPCNTTOP);
    write_volatile_4(Peripherals::PROTIMER.WRAPCNT,
                     (iVar4 + uVar5) - (uVar6 + 1) * ((iVar4 + uVar5) / (uVar6 + 1)));
  }
  do {
    uVar6 = read_volatile_4(Peripherals::PROTIMER.IF);
    if ((int)(uVar6 << 7) < 0) break;
    uVar6 = read_volatile_4(Peripherals::RTCC.CNT);
    uVar5 = read_volatile_4(Peripherals::RTCC.CC0_CCV);
  } while (uVar5 - uVar6 < 3);
  write_volatile_4(Peripherals::PROTIMER.IFC,0x1000000);
  write_volatile_4(Peripherals::RTCC.IFC,2);
  write_volatile_4(Peripherals::PROTIMER.CC0_CTRL,ccCtrlBackup);
  write_volatile_4(Peripherals::PROTIMER_CLR.PRSCTRL,0x720000);
  iVar4 = 0;
  uVar6 = read_volatile_4(Peripherals::PROTIMER.WRAPCNT);
  do {
    if ((int)((&Peripherals::PROTIMER.CC0_CTRL)[iVar4 * 4] << 0x1f) < 0) {
      uVar5 = read_volatile_4(Peripherals::PROTIMER.IF);
      uVar2 = 1 << (iVar4 + 8U & 0xff);
      if ((uVar2 & uVar5) == 0) {
        uVar5 = (&Peripherals::PROTIMER.CC0_WRAP)[iVar4 * 4];
        if (uVar6 < uVar1) {
          if (uVar5 <= uVar1) goto LAB_00010362;
LAB_00010370:
          write_volatile_4(Peripherals::PROTIMER.IFS,uVar2);
        }
        else {
          if (uVar1 < uVar5) {
LAB_00010362:
            if (uVar5 <= uVar6) goto LAB_00010370;
          }
        }
      }
    }
    iVar4 = iVar4 + 1;
    if (iVar4 == 5) {
      rtccSyncFlag = 0;
      return;
    }
  } while( true );
}


