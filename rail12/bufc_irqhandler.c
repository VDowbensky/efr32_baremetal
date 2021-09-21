#include "bufc_irqhandler.h"



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void BUFC_IRQHandler(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  CORE_irqState_t irqState;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  uVar4 = read_volatile_4(Peripherals::FRC.IF);
  uVar6 = read_volatile_4(Peripherals::FRC.IEN);
  uVar6 = uVar6 & uVar4;
  write_volatile_4(Peripherals::FRC.IFC,uVar6);
  uVar4 = read_volatile_4(Peripherals::BUFC.IF);
  uVar7 = read_volatile_4(Peripherals::BUFC.IEN);
  uVar7 = uVar7 & uVar4;
  write_volatile_4(Peripherals::BUFC.IFC,uVar7);
  uVar4 = read_volatile_4(Peripherals::MODEM.IF);
  uVar10 = read_volatile_4(Peripherals::MODEM.IEN);
  uVar10 = uVar10 & uVar4;
  write_volatile_4(Peripherals::MODEM.IFC,uVar10);
  uVar4 = read_volatile_4(Peripherals::RAC.IF);
  uVar8 = read_volatile_4(Peripherals::RAC.IEN);
  uVar8 = uVar8 & uVar4;
  write_volatile_4(Peripherals::RAC.IFC,uVar8 & 0xffff0000);
  iVar1 = PROTIMER_LBTIsActive();
  uVar4 = read_volatile_4(Peripherals::PROTIMER.IF);
  uVar9 = read_volatile_4(Peripherals::PROTIMER.IEN);
  uVar9 = uVar9 & uVar4;
  write_volatile_4(Peripherals::PROTIMER.IFC,uVar9 & 0xfffff7ff);
  if (uVar6 == 0) {
    uVar4 = 0;
  }
  else {
    if ((int)(uVar6 << 0x10) < 0) {
      uVar4 = read_volatile_4(Peripherals::RAC.SR0);
      write_volatile_4(Peripherals::RAC_CLR.SR0,uVar4 & 0x1c00);
      write_volatile_4(Peripherals::RAC_CLR.SR0,0x80);
      write_volatile_4(Peripherals::RAC_CLR.RXENSRCEN,0x10);
      if ((uVar4 & 0x1c00) == 0) {
        uVar4 = 0x40000;
      }
      else {
        if ((int)(uVar4 << 0x13) < 0) {
          uVar4 = 0x1000000;
        }
        else {
          if ((int)(uVar4 << 0x15) < 0) {
            uVar4 = 0x100000;
          }
          else {
            uVar4 = 0x400000;
          }
        }
      }
    }
    else {
      uVar4 = 0;
    }
    if ((int)(uVar6 << 0x1e) < 0) {
      uVar5 = read_volatile_4(Peripherals::RAC.SR0);
      write_volatile_4(Peripherals::RAC_CLR.SR0,uVar5 & 0xe000);
      if ((uVar5 & 0xe000) == 0) {
        uVar4 = uVar4 | 0x80000;
      }
      else {
        if ((int)(uVar5 << 0x10) < 0) {
          uVar4 = uVar4 | 0x2000000;
        }
        else {
          if ((int)(uVar5 << 0x12) < 0) {
            uVar4 = uVar4 | 0x200000;
          }
          else {
            uVar4 = uVar4 | 0x800000;
          }
        }
      }
    }
    if ((uVar6 & 0x2000) == 0) {
      uVar6 = 0;
    }
    else {
      uVar6 = 8;
    }
  }
  uVar5 = 0;
  if ((uVar7 & 0x90b0a09) != 0) {
    if ((uVar7 & 0xa00) != 0) {
      GENERIC_PHY_ResetRxFifo(0);
      uVar7 = uVar7 & 0xfffbffff;
      RAILInt_Assert(0,6);
    }
    if ((uVar7 & 9) != 0) {
      write_volatile_4(Peripherals::RAC.CMD,0x20);
      write_volatile_4(Peripherals::BUFC.BUF0_CMD,1);
      RAILInt_Assert(0,8);
    }
    if ((uVar7 & 0x9000000) != 0) {
      write_volatile_4(Peripherals::RAC.CMD,0x20);
      BUFC_TxAckBufferReset();
      RAILInt_Assert(0,9);
    }
    if ((uVar7 & 0xa0000) != 0) {
      GENERIC_PHY_ResetRxFifo(0);
      uVar7 = uVar7 & 0xfffbffff;
      RAILInt_Assert(0,7);
    }
    if ((int)(uVar7 << 0xf) < 0) {
      BUFC_HandleRxLenOvfEvent();
    }
  }
  if ((int)(uVar7 << 0x1d) < 0) {
    if (_DAT_430204b4 == 0) {
      write_volatile_4(Peripherals::BUFC_SET.BUF0_THRESHOLDCTRL,0x2000);
    }
    else {
      uVar4 = uVar4 | 0x20000;
      write_volatile_4(Peripherals::BUFC_CLR.BUF0_THRESHOLDCTRL,0x2000);
    }
  }
  if ((int)(uVar7 << 0x15) < 0) {
    uVar4 = uVar4 | 4;
  }
  if ((uVar7 & 0x40000) != 0) {
    uVar2 = BUFC_StartRxLenThrEvent();
    switch(uVar2) {
    case 1:
    case 3:
      uVar4 = uVar4 | 0x1000;
      break;
    case 2:
      uVar4 = uVar4 | 0x200;
      break;
    case 4:
      uVar4 = uVar4 | 0x100;
      break;
    case 5:
      uVar4 = uVar4 | 0x80;
      break;
    case 6:
    case 7:
      uVar4 = uVar4 | 8;
      break;
    default:
      RAILInt_Assert(0,3);
    }
  }
  if (uVar10 != 0) {
    if ((uVar10 & 0x1000) != 0) {
      uVar4 = uVar4 | 0x4000;
    }
    if ((uVar10 & 0x100) != 0) {
      uVar4 = uVar4 | 0x8000;
    }
    if ((uVar10 & 0x2000) != 0) {
      uVar6 = uVar6 | 1;
    }
    if ((uVar10 & 0x200) != 0) {
      uVar4 = uVar4 | 0x10;
    }
    if ((uVar10 & 0x400) != 0) {
      uVar4 = uVar4 | 0x20;
    }
    if ((uVar10 & 0x800) != 0) {
      uVar4 = uVar4 | 0x40;
    }
  }
  if (uVar8 != 0) {
    if ((uVar8 & 0x2000000) != 0) {
      uVar6 = uVar6 | 0x20;
    }
    if ((uVar8 & 0x4000000) != 0) {
      uVar6 = uVar6 | 0x40;
    }
    if ((uVar8 & 0x8000000) != 0) {
      uVar6 = uVar6 | 0x80;
    }
    if ((uVar8 & 0x40000) != 0) {
      uVar5 = 2;
    }
    if ((uVar8 & 0x10000) != 0) {
      uVar4 = uVar4 | 0x400;
    }
    if ((uVar8 & 0x100000) != 0) {
      uVar4 = uVar4 | 0x2000;
    }
    if ((uVar8 & 0x200000) != 0) {
      uVar4 = uVar4 | 2;
    }
    if (((uVar8 & 0x80000) != 0) && (iVar3 = GENERIC_PHY_CanModifyAck(), iVar3 != 0)) {
      uVar4 = uVar4 | 0x10000;
    }
  }
  if (uVar9 == 0) goto LAB_0000f236;
  if ((uVar9 & 0x800) != 0) {
    PROTIMER_CCTimerStop(3);
    write_volatile_4(Peripherals::PROTIMER_CLR.RXCTRL,0x1f1f);
    write_volatile_4(Peripherals::PROTIMER.IFC,0x800);
    PROTIMER_ClearTxEnable();
  }
  if ((uVar9 & 0x2000000) != 0) {
    PTI_AuxdataOutput(0x2b);
    uVar4 = uVar4 | 0x20000000;
  }
  if ((uVar9 & 0x700000) == 0) {
    if ((uVar9 & 0x1000) != 0) {
      if (iVar1 != 0) goto LAB_0000f120;
      PROTIMER_CCTimerStop(4);
      PROTIMER_CCTimerStop(3);
      PROTIMER_ClearRxEnable();
      irqState = CORE_EnterCritical();
      if (scheduledRxHardEnd != '\0') {
        RADIO_RACRxAbort();
      }
      iVar1 = BUFC_RxBufferBytesAvailable();
      uVar10 = read_volatile_4(Peripherals::RAC.STATUS);
      if (((uVar10 << 4) >> 0x1c == 3) || (iVar1 != 0)) {
        iVar1 = 1;
        pendedRxWindowEnd = scheduledRxLoop;
      }
      CORE_ExitCritical(irqState);
      if (iVar1 == 0) {
        overrideRxRollback = 0;
        GENERIC_PHY_ConfigureRollbackReporting();
        uVar10 = 0x800;
      }
      else {
        uVar10 = 0;
      }
      uVar4 = uVar4 | uVar10;
    }
  }
  else {
LAB_0000f120:
    uVar9 = PROTIMER_CheckCcaReallyFailed(uVar9);
    if ((uVar9 & 0x200000) != 0) {
      PTI_AuxdataOutput(0x29);
      uVar4 = uVar4 | 0x10000000;
    }
    if ((uVar9 & 0x400000) == 0) {
      if ((uVar9 & 0x100000) == 0) {
        if ((uVar9 & 0x1000) != 0) {
          PROTIMER_CCTimerStop(4);
          PROTIMER_LBTStop();
          uVar10 = read_volatile_4(Peripherals::PROTIMER.IF);
          if ((uVar10 & 0x500000) == 0) {
            PTI_AuxdataOutput(0x2a);
            write_volatile_4(Peripherals::BUFC.BUF0_CMD,1);
            goto LAB_0000f1ba;
          }
        }
      }
      else {
        PROTIMER_CCTimerStop(4);
        PTI_AuxdataOutput(0x28);
        uVar4 = uVar4 | 0x4000000;
      }
    }
    else {
      PROTIMER_CCTimerStop(4);
      PTI_AuxdataOutput(0x27);
      write_volatile_4(Peripherals::RAC_CLR.SR0,0x80);
      write_volatile_4(Peripherals::RAC_CLR.RXENSRCEN,0x10);
LAB_0000f1ba:
      uVar4 = uVar4 | 0x8000000;
    }
  }
  if ((uVar9 & 0x400) != 0) {
    PROTIMER_CCTimerStop(2);
    uVar6 = uVar6 | 4;
  }
LAB_0000f236:
  GENERIC_PHY_IssueCallback(enabledRailEvents & uVar4,DAT_200044f4 & uVar5,enabledPhyEvents & uVar6)
  ;
  if ((uVar7 & 0x40000) != 0) {
    BUFC_EndRxLenThrEvent();
    GENERIC_PHY_CheckPendedRxWindowEnd();
  }
  if (uVar8 != 0) {
    if ((uVar8 & 0x2000000) != 0) {
      PA_RunPeakDetectorHigh();
    }
    if ((uVar8 & 0x4000000) != 0) {
      PA_RunPeakDetectorLow();
    }
    if ((uVar8 & 0x8000000) != 0) {
      PA_RunBatHigh();
      return;
    }
  }
  return;
}


