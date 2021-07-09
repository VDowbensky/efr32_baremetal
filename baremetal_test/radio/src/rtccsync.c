#include "rtccsync.h"
#include <stdbool.h>
#include "em_bus.h"
#include "em_assert.h"
#include "em_cmu.h"


uint32_t RTCCSYNC_RTCCClockFreqGet(void)

{
	uint32_t uVar1;
	uint32_t uVar2;
  bool bVar3;
  
  uVar1 = 0;
  //uVar2 = read_volatile_4(RTCC->CTRL);
  bVar3 = (RTCC->CTRL & 0x1000) == 0;
  if (bVar3) 
  {
    //uVar2 = read_volatile_4(RTCC->CTRL);
    uVar1 = (RTCC->CTRL << 0x14) >> 0x1c;
  }
  uVar2 = 1;
  if (bVar3) {
    uVar2 = 1 << uVar1;
  }
  uVar1 = CMU_ClockFreqGet(0x100980);
  return uVar1 / uVar2;
}



void RTCCSYNC_Init(void)

{
//  PRS->CH7_CTRL = 0x2901;
}





uint32_t RTCCSYNC_PreSleep(int param_1,uint32_t param_2,uint32_t param_3)

{
//  uint64_t uVar1;
//  uint64_t lVar2;
//  uint32_t uVar3;
//  int iVar4;
//  uint32_t uVar5;
//  uint32_t uVar6;
//  int iVar7;
//  uint32_t uVar8;
//  uint32_t uVar9;
//  int iVar10;
//  uint32_t uVar11;
//  uint32_t uVar12;
//  bool bVar13;
//  uint64_t uVar14;
//  uint32_t uVar15;
//
//  iVar7 = param_1;
//  iVar4 = RTCCSYNC_RTCCClockFreqGet();
//  uVar8 = 0;
//  uVar15 = PROTIMER->CTRL;
//  uVar9 = PROTIMER->WRAPCNT;
//  uVar12 = 0xffffffff;
//  iVar10 = 0;
//  do {
//    uVar11 = (&PROTIMER->CC0_CTRL)[iVar10 * 4] & 3;
//    if (uVar11 == 1) {
//      uVar5 = PROTIMER_ElapsedTime
//                        (uVar9,(&PROTIMER->CC0_WRAP)[iVar10 * 4],uVar8,0x40085080,iVar7,
//                         param_2,param_3);
//      uVar3 = PROTIMER->IF;
//      uVar8 = uVar11;
//      if ((1 << (iVar10 + 8U & 0xff) & uVar3) == 0) {
//        if (uVar5 <= uVar12) {
//          uVar12 = uVar5;
//        }
//      }
//      else {
//        uVar12 = 0;
//      }
//    }
//    iVar10 = iVar10 + 1;
//  } while (iVar10 != 5);
//  if ((uVar15 & 0x30000) == 0x20000) {
//    uVar9 = PROTIMER->BASECNTTOP;
//    uVar9 = uVar9 + 1;
//    if ((uVar15 & 0x3000) == 0x1000) {
//      uVar15 = PROTIMER->PRECNTTOP;
//      uVar9 = (uVar15 >> 8) * uVar9 + uVar9;
//    }
//  }
//  else {
//    uVar15 = PROTIMER->PRECNTTOP;
//    uVar9 = (uVar15 >> 8) + 1;
//  }
//  uVar15 = RTCC->CNT;
//  uVar11 = RAC->STATUS;
//  if ((uVar11 & 0xf000000) == 0) {
//    uVar11 = PROTIMER->STATUS;
//    uVar11 = uVar11 & 6;
//    if (uVar11 == 0) {
//      if (uVar8 == 0) {
//        return 1;
//      }
//      uVar1 = (uint64_t)uVar9 * (uint64_t)uVar12;
//      uVar12 = (uint)(uVar1 >> 0x20);
//      uVar8 = (param_1 * iVar4 + 500000U) / 1000000;
//      uVar9 = CMU_ClockFreqGet(0x11);
//      lVar2 = (uint64_t)uVar9 * (uint64_t)(uVar8 + 5);
//      uVar6 = RTCCSYNC_RTCCClockFreqGet();
//      uVar14 = __aeabi_uldivmod((int)lVar2,(int)((uint64_t)lVar2 >> 0x20),uVar6,0,iVar7,uVar15);
//      uVar9 = (uint)((uint64_t)uVar14 >> 0x20);
//      bVar13 = uVar12 <= uVar9;
//      if (uVar9 == uVar12) {
//        bVar13 = (uint)uVar1 <= (uint)uVar14;
//      }
//      if (!bVar13) {
//        uVar9 = RTCCSYNC_RTCCClockFreqGet();
//        lVar2 = (uint64_t)uVar9 * (uVar1 & 0xffffffff);
//        uVar6 = CMU_ClockFreqGet(0x11);
//        iVar7 = __aeabi_uldivmod((int)lVar2,uVar9 * uVar12 + (int)((uint64_t)lVar2 >> 0x20),uVar6,0
//                                );
//        RTCC->CC0_CTRL = 0;
//        ccCtrlBackup = PROTIMER->CC0_CTRL;
//        PROTIMER->CC0_CTRL = 0x70003;
//        RTCC->IFC = 2;
//        PROTIMER->IFC = 0x100;
//        uVar12 = PROTIMER->IEN;
//        PROTIMER->IEN = 0;
//        RTCC->CC0_CCV = RTCC->CNT + 1;
//        RTCC->CC0_CTRL = 2;
//        refRtcCnt = RTCC->CC0_CCV;
//        while( true )
//		{
//          do {
//            uVar9 = RTCC->CNT;
//            uVar3 = PROTIMER->IF;
//            if ((PROTIMER->IF & 0x100) != 0)
//			{
//              PROTIMER->IFC = 0x100;
//              PROTIMER->IEN = uVar12;
//              iVar4 = uVar8 + 2;
//              RTCC->CC0_CCV = (uVar15 - iVar4) + iVar7;
//              RTCC->IFC = 2;
//              RTCC->IEN |= 2;
//              uVar15 = RTCC->CNT;
//              uVar9 = RTCC->CC0_CCV;
//              if (uVar15 - uVar9 < (uint)(iVar4 - iVar7)) {
//                return 0;
//              }
//              rtccSyncFlag = 1;
//              _DAT_430a0084 = 1;
//              return 1;
//            }
//          } while (uVar9 != refRtcCnt + 1);
//          if (uVar11 != 0) break;
//          refRtcCnt = refRtcCnt + 2;
//          RTCC->CC0_CCV = refRtcCnt;
//          uVar11 = 1;
//        }
//      }
//    }
//  }
  return 0;
}



void RTCCSYNC_PostWakeUp(void)

{
//  longlong lVar1;
//  uint uVar2;
//  uint uVar3;
//  undefined4 uVar4;
//  int iVar5;
//  uint uVar6;
//  uint uVar7;
//  undefined8 uVar8;
//
//  iVar5 = refRtcCnt;
//  if (rtccSyncFlag == '\0') {
//    return;
//  }
//  uVar2 = PROTIMER->CC0_WRAP;
//
//  PROTIMER->PRSCTRL |= 0x720000;
//  RTCC->IEN &= 0xfffffffd;
//  RTCC->CC0_CCV = RTCC->CNT + 2;
//  uVar7 = RTCC->CC0_CCV;
//
//  uVar3 = CMU_ClockFreqGet(0x11);
//  uVar4 = RTCCSYNC_RTCCClockFreqGet();
//  uVar6 = PROTIMER->CTRL;
//
//  if ((PROTIMER->CTRL & 0x11000) != 0)
//  {
//    lVar1 = (ulonglong)uVar3 * (ulonglong)(uVar7 - iVar5);
//    uVar8 = __aeabi_uldivmod((int)lVar1,(int)((ulonglong)lVar1 >> 0x20),uVar4,0);
//    uVar7 = PROTIMER->PRECNTTOP;
//    uVar6 = PROTIMER->CC0_PRE;
//    uVar7 = uVar7 >> 8;
//    iVar5 = uVar7 + 1;
//    __aeabi_uldivmod();
//    uVar6 = uVar6 + iVar5;
//    iVar5 = __aeabi_uldivmod((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),uVar7 + 1,0);
//    if (uVar7 < uVar6) {
//      iVar5 = iVar5 + 1;
//      uVar6 = (uVar6 - uVar7) - 1;
//    }
//    PROTIMER->PRECNT = uVar6;
//    uVar6 = PROTIMER->CC0_BASE;
//    uVar7 = PROTIMER->BASECNTTOP;
//    PROTIMER->BASECNT = (uVar6 + iVar5) - (uVar7 + 1) * ((uVar6 + iVar5) / (uVar7 + 1));
//    uVar6 = PROTIMER->CC0_WRAP;
//    uVar7 = PROTIMER->WRAPCNTTOP;
//    PROTIMER->WRAPCNT = (iVar5 + uVar6) - (uVar7 + 1) * ((iVar5 + uVar6) / (uVar7 + 1));
//  }
//  do {
//    uVar7 = PROTIMER->IF;
//    if ((int)(PROTIMER->IF << 7) < 0) break;
//    //uVar7 = RTCC->CNT;
//    //uVar6 = RTCC->CC0_CCV;
//  } while (RTCC->CC0_CCV - RTCC->CNT < 3);
//  PROTIMER->IFC = 0x1000000;
//  RTCC->IFC = 2;
//  PROTIMER->CC0_CTRL = ccCtrlBackup;
//  PROTIMER->PRSCTRL &= 0xff8dffff;
//  iVar5 = 0;
//  uVar7 = PROTIMER->WRAPCNT;
//  do {
//    if ((int)((&PROTIMER->CC0_CTRL)[iVar5 * 4] << 0x1f) < 0) {
//      uVar6 = PROTIMER->IF;
//      uVar3 = 1 << (iVar5 + 8U & 0xff);
//      if ((uVar3 & uVar6) == 0) {
//        uVar6 = (&PROTIMER->CC0_WRAP)[iVar5 * 4];
//        if (uVar7 < uVar2) {
//          if (uVar6 <= uVar2) goto LAB_00010334;
//LAB_00010342:
//          PROTIMER->IFS = uVar3;
//        }
//        else {
//          if (uVar2 < uVar6) {
//LAB_00010334:
//            if (uVar6 <= uVar7) goto LAB_00010342;
//          }
//        }
//      }
//    }
//    iVar5 = iVar5 + 1;
//    if (iVar5 == 5) {
//      rtccSyncFlag = 0;
//      return;
//    }
//  } while( true );
}


