#include "pa.o.h"



void PA_ProtectPa(uint param_1)

{
  bool bVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  
  if ((char)gPaConfig != '\x03') {
    uVar4 = read_volatile_4(DAT_21000fe0);
    uVar3 = ((uVar4 << 10) >> 0x18) << 6;
    if (param_1 < 0x5b) {
      bVar1 = false;
    }
    else {
      if (gPaConfig._2_2_ < 0x709) {
        bVar1 = 200 < param_1;
        if (bVar1) {
          uVar3 = 0x3fc8;
        }
      }
      else {
        bVar1 = true;
        uVar3 = 0x3fc8;
      }
    }
    if (param_1 < 0x1f) {
      puVar2 = &RAC_PABIASCTRL0_CLR;
    }
    else {
      puVar2 = &RAC_PABIASCTRL0_SET;
    }
    write_volatile_4(DAT_21000fe0,uVar3 | uVar4 & 0xffffc037);
    *puVar2 = 1;
    puVar2[6] = 1;
    if (((apcEnabled == '\0') || (param_1 < 0x51)) ||
       ((gPaConfig._2_2_ < 0x709 && (param_1 < 0x79)))) {
      puVar2 = &RAC_SR3_CLR;
    }
    else {
      write_volatile_4(RAC_PAPKDCTRL_CLR,0xdf01);
      write_volatile_4(RAC_SGPAPKDCTRL_CLR,0xdf01);
      if (bVar1) {
        uVar4 = 0xd700;
      }
      else {
        uVar4 = 0xd000;
      }
      write_volatile_4(RAC_PAPKDCTRL_SET,uVar4);
      write_volatile_4(RAC_SGPAPKDCTRL_SET,uVar4);
      puVar2 = &RAC_SR3_SET;
    }
    *puVar2 = 8;
  }
  return;
}



undefined4 getRampTimeFromLevelAndRate(int param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = SystemHFXOClockGet();
  return (int)((ulonglong)(uint)(((param_1 << (param_2 & 0xff)) >> 5) * 10000) /
              ((ulonglong)uVar1 / 100));
}



//undefined4 PA_GetTxPowerConfig(undefined4 *param_1)
RAIL_Status_t PA_GetTxPowerConfig(RAIL_TxPowerConfig_t *config)
{
  *param_1 = gPaConfig;
  *(undefined2 *)(param_1 + 1) = DAT_00010848;
  return 0;
}



//undefined PA_GetPowerLevel(void)
RAIL_TxPowerLevel_t PA_GetPowerLevel(void)
{
  return currentPowerLevel;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

//uint PA_SetPowerLevel(uint param_1)
RAIL_TxPowerLevel_t PA_SetPowerLevel(RAIL_TxPowerLevel_t powerLevel)
{
  byte bVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  uint uVar7;
  
  PA_ProtectPa(200);
  if ((char)gPaConfig == '\x03') {
    currentPowerLevel = 0xff;
    return 0xff;
  }
  if ((char)gPaConfig == '\x01') {
    if (param_1 < 8) {
      if (param_1 == 1) {
        param_1 = 2;
      }
    }
    else {
      param_1 = 7;
    }
    uVar4 = read_volatile_4(DAT_21000fe0);
    write_volatile_4(DAT_21000fe0,uVar4 & 0xe0c0003f | param_1 << 0x18);
    write_volatile_4(RAC_APC_CLR,4);
    param_1 = param_1 & 0xffff;
    goto LAB_0001024e;
  }
  uVar4 = read_volatile_4(DAT_21000fe0);
  uVar4 = uVar4 & 0xe0c03fff | 0x3fc8;
  write_volatile_4(DAT_21000fe0,uVar4);
  if ((char)gPaConfig == '\0') {
    cVar3 = (char)gPaConfig;
    if (4 < param_1) {
      param_1 = param_1 - 4 & 0xff;
      cVar3 = '\x01';
    }
  }
  else {
    cVar3 = '\0';
  }
  iVar6 = count_leading_zeroes(~_DAT_400e4188 & 0x1fc000 | 0x2000);
  uVar7 = (0x13 - iVar6) * 0x1f & 0xff;
  if (uVar7 <= param_1) {
    param_1 = uVar7;
  }
  uVar7 = param_1 & 0xff;
  if ((char)gPaConfig == '\0') {
    if (cVar3 == '\0') {
      iVar6 = 0;
    }
    else {
      iVar6 = 4;
    }
  }
  else {
    iVar6 = 0;
  }
  param_1 = iVar6 + uVar7;
  if (uVar7 == 0) {
    write_volatile_4(RAC_APC,0x700002c);
  }
  else {
    write_volatile_4(RAC_APC,0x7000000);
    uVar7 = uVar7 - 1 & 0xff;
  }
  uVar7 = uVar4 | (uVar7 % 0x1f) * 0x1000000 + 0x1000000 | ((1 << uVar7 / 0x1f + 1) + -1) * 0x4000;
  write_volatile_4(DAT_21000fe0,uVar7);
  uVar4 = read_volatile_4(RAC_APC);
  if (paCalEnabled == '\0') {
LAB_0001022e:
    if (param_1 == 0) {
LAB_00010232:
      uVar4 = 0x7000004;
    }
    else {
LAB_00010212:
      uVar4 = uVar4 & 0xfffffb | 0xff000000;
    }
  }
  else {
    iVar6 = count_leading_zeroes((uVar7 << 10) >> 0x18);
    if ((char)gPaConfig == '\x02') {
      iVar2 = 0xfe083b0;
    }
    else {
      iVar2 = 0xfe083b8;
    }
    if (0x1f - iVar6 == -1) goto LAB_0001022e;
    bVar1 = *(byte *)(iVar2 + (0x1f - iVar6));
    if (param_1 == 0) goto LAB_00010232;
    if (0xfd < (byte)(bVar1 - 1)) goto LAB_00010212;
    uVar4 = uVar4 & 0xffffff | 4 | (uint)bVar1 << 0x18;
  }
  write_volatile_4(RAC_APC,uVar4);
  if (cVar3 == '\0') {
    puVar5 = &RAC_PABIASCTRL0_CLR;
  }
  else {
    puVar5 = &RAC_PABIASCTRL0_SET;
  }
  *puVar5 = 0x400000;
LAB_0001024e:
  param_1 = param_1 & 0xff;
  currentPowerLevel = (undefined)param_1;
  PA_ProtectPa(param_1);
  return param_1;
}



void PA_EnableApc(void)

{
  apcEnabled = 1;
  PA_ProtectPa(currentPowerLevel);
  return;
}



void PA_DisableApc(void)

{
  apcEnabled = 0;
  PA_ProtectPa(currentPowerLevel);
  return;
}



void PA_RunPeakDetectorHigh(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = SYNTH_Is2p4GHz();
  if (iVar3 == 0) {
    uVar1 = read_volatile_4(RAC_SGPACTRL0);
    uVar2 = read_volatile_4(RAC_SGPACTRL0);
    write_volatile_4(RAC_SGPACTRL0,uVar1 & 0xffc03fff | (uVar2 & 0x3f8000) >> 1);
  }
  else {
    uVar1 = read_volatile_4(RAC_PACTRL0);
    uVar2 = read_volatile_4(RAC_PACTRL0);
    write_volatile_4(RAC_PACTRL0,uVar1 & 0xffc03fff | (uVar2 & 0x3f8000) >> 1);
  }
  write_volatile_4(RAC_IFC,0x2000000);
  return;
}



void PA_RunPeakDetectorLow(void)

{
  return;
}



void PA_RunBatHigh(void)

{
  int iVar1;
  uint *puVar2;
  
  iVar1 = SYNTH_Is2p4GHz();
  if (iVar1 == 0) {
    puVar2 = &RAC_SGPACTRL0_CLR;
  }
  else {
    puVar2 = &RAC_PACTRL0_CLR;
  }
  *puVar2 = 0x200000;
  write_volatile_4(RAC_IEN_CLR,0x8000000);
  return;
}



//undefined2 PA_GetRampTime(void)
uint32_t PA_GetRampTime(void)
{
  return DAT_00010848;
}



void PA_ConfigRamp(uint *param_1)

{
  write_volatile_4(MODEM_RAMPLEV,param_1[1]);
  write_volatile_4(MODEM_RAMPCTRL_CLR,0xfff);
  write_volatile_4(MODEM_RAMPCTRL_SET,*param_1);
  return;
}



int PA_CalcRampTime(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  uVar4 = read_volatile_4(MODEM_RAMPLEV);
  uVar5 = read_volatile_4(MODEM_RAMPLEV);
  uVar6 = read_volatile_4(MODEM_RAMPLEV);
  uVar1 = read_volatile_4(MODEM_RAMPCTRL);
  uVar2 = read_volatile_4(MODEM_RAMPCTRL);
  uVar3 = read_volatile_4(MODEM_RAMPCTRL);
  iVar7 = getRampTimeFromLevelAndRate(uVar4 & 0xff,uVar1 & 0xf);
  iVar8 = getRampTimeFromLevelAndRate((uVar5 << 0x10) >> 0x18,(uVar2 << 0x18) >> 0x1c);
  iVar9 = getRampTimeFromLevelAndRate((uVar6 << 8) >> 0x18,(uVar3 << 0x14) >> 0x1c);
  return iVar9 + iVar7 + iVar8;
}



//undefined2 PA_SetRampTime(uint param_1,undefined4 param_2,undefined4 param_3)
uint32_t PA_SetRampTime(uint32_t rampTime, StateTimings_t *timings)
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint local_20;
  int local_1c;
  undefined4 uStack24;
  
  gDesiredRampTime = param_1;
  if (param_1 == 0) {
    gDesiredRampTime = 1;
  }
  uVar2 = read_volatile_4(MODEM_CTRL0);
  gCurrentModulation = (byte)((uVar2 << 0x17) >> 0x1d);
  uVar2 = ((uVar2 << 0x17) >> 0x1d) - 2 & 0xff;
  if ((uVar2 < 5) && ((1 << uVar2 & 0x13U) != 0)) {
    iVar3 = 0;
  }
  else {
    if ((char)gPaConfig == '\x02') {
      if (paCalEnabled == '\0') {
        iVar3 = 0x96;
      }
      else {
        iVar3 = 200;
      }
    }
    else {
      if ((char)gPaConfig == '\x01') {
        iVar3 = 0x32;
      }
      else {
        if (paCalEnabled == '\0') {
          iVar3 = 0xb4;
        }
        else {
          iVar3 = 0xf0;
        }
      }
    }
  }
  uVar2 = 0;
  local_20 = param_1;
  local_1c = param_2;
  uStack24 = param_3;
  do {
    uVar1 = getRampTimeFromLevelAndRate(iVar3,uVar2 & 0xff);
    if (gDesiredRampTime < uVar1) break;
    uVar2 = uVar2 + 1;
  } while (uVar2 != 0x10);
  local_20 = (uVar2 - 1) * 0x100;
  local_1c = iVar3 << 0x10;
  PA_ConfigRamp(&local_20);
  DAT_00010848 = PA_CalcRampTime();
  TIMING_RecalculatePaRampChanged(param_2);
  return DAT_00010848;
}



//void PA_SetCTune(uint param_1,uint param_2)
void PA_SetCTune(uint8_t txPaCtuneValue, uint8_t rxPaCtuneValue)
{
  write_volatile_4(DAT_21000fe8,param_1 & 7 | (param_1 & 0x1f) << 4);
  write_volatile_4(DAT_21000fe4,param_2 & 7 | (param_2 & 0x1f) << 4);
  return;
}



void PA_SelectBand(void)

{
  undefined4 uVar1;
  
  uVar1 = SYNTH_LoDivGet();
  if (false) {
switchD_0001048a_caseD_2:
    uVar1 = 0xf7;
LAB_000104ba:
    write_volatile_4(DAT_21000fe8,uVar1);
    uVar1 = 0xa2;
  }
  else {
    switch(uVar1) {
    case 1:
      uVar1 = 0x44;
      if ((char)gPaConfig != '\x01') {
        write_volatile_4(DAT_21000fe8,0);
        goto LAB_000104be;
      }
      break;
    default:
      goto switchD_0001048a_caseD_2;
    case 3:
    case 4:
      uVar1 = 0;
      break;
    case 5:
    case 6:
      uVar1 = 0x33;
      break;
    default:
      uVar1 = 0;
      goto LAB_000104ba;
    }
    write_volatile_4(DAT_21000fe8,uVar1);
  }
LAB_000104be:
  write_volatile_4(DAT_21000fe4,uVar1);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

//undefined4 PA_Config(uint *param_1)
RAIL_Status_t PA_Config(const RAIL_TxPowerConfig_t *paConfig)
{
  char cVar1;
  uint uVar2;
  uint *puVar3;
  bool bVar4;
  
  if (param_1 == (uint *)0x0) {
    return 1;
  }
  RADIO_CLKEnable();
  memset(&DAT_21000fe0,0,0xc);
  cVar1 = *(char *)param_1;
  if (cVar1 == '\x02') {
    bVar4 = (_DAT_400e4188 & 0x200000) == 0;
  }
  else {
    if (cVar1 == '\x01') {
      bVar4 = (_DAT_400e4188 & 0xc00000) == 0;
    }
    else {
      if (cVar1 != '\0') goto LAB_00010520;
      bVar4 = (_DAT_0fe081d4 & 1 ^ 1 | _DAT_400e4188 & 0x400000) == 0;
    }
  }
  if (bVar4) {
    gPaConfig = *param_1;
    DAT_00010848 = *(undefined2 *)(param_1 + 1);
    PA_SetPowerLevel(0);
    PA_SetRampTime(*(undefined2 *)(param_1 + 1),0);
    if ((gPaConfig & 0xff) == 2) {
      uVar2 = read_volatile_4(DAT_21000fe0);
      write_volatile_4(DAT_21000fe0,uVar2 & 0xbfffffe8 | 0x40000020);
      write_volatile_4(RAC_SGPABIASCTRL1_CLR,0x7700);
      write_volatile_4(RAC_SGPABIASCTRL1_SET,0x4500);
      write_volatile_4(RAC_SGPABIASCTRL0_SET,1);
    }
    else {
      uVar2 = read_volatile_4(DAT_21000fe0);
      if ((gPaConfig & 0xff) == 1) {
        write_volatile_4(DAT_21000fe0,uVar2 & 0xbfffffe8 | 3);
        write_volatile_4(RAC_PACTRL0_CLR,7);
        write_volatile_4(RAC_PACTRL0_SET,3);
        write_volatile_4(RAC_PABIASCTRL1_CLR,7);
        write_volatile_4(RAC_PABIASCTRL1_SET,6);
        write_volatile_4(RAC_PABIASCTRL0_CLR,0x4000c1);
        uVar2 = 0xc000;
        puVar3 = &RAC_PAPKDCTRL_CLR;
      }
      else {
        write_volatile_4(DAT_21000fe0,uVar2 & 0xbfffffe8 | 0x40000014);
        write_volatile_4(RAC_PACTRL0_CLR,7);
        write_volatile_4(RAC_PACTRL0_SET,4);
        write_volatile_4(RAC_PABIASCTRL1_CLR,7);
        write_volatile_4(RAC_PABIASCTRL1_SET,5);
        write_volatile_4(RAC_PABIASCTRL0_CLR,0xc0);
        puVar3 = &RAC_PABIASCTRL0_SET;
        uVar2 = 0x81;
      }
      *puVar3 = uVar2;
    }
    PA_SetPowerLevel(0);
    write_volatile_4(RAC_APC_CLR,3);
    PA_SelectBand();
    return 0;
  }
LAB_00010520:
  gPaConfig = CONCAT31(gPaConfig._1_3_,3);
  currentPowerLevel = 0xff;
  return 1;
}



undefined4 PA_UpdateConfig(undefined4 param_1)

{
  uint uVar1;
  
  PA_SelectBand();
  uVar1 = read_volatile_4(MODEM_CTRL0);
  if ((uint)gCurrentModulation != (uVar1 << 0x17) >> 0x1d) {
    PA_SetRampTime(gDesiredRampTime,param_1);
    return 1;
  }
  return 0;
}



void PA_EnableCal(bool enable)

{
  paCalEnabled = param_1;
  return;
}



undefined1 * PA_GetTxPowerCurve(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  if (gPaConfig._2_2_ < 0x709) {
    puVar2 = &curvesSgDcdc;
    puVar1 = &curves24HpDcdc;
  }
  else {
    puVar2 = &curvesSgVbat;
    puVar1 = &curves24HpVbat;
  }
  if ((char)gPaConfig != '\0') {
    puVar1 = puVar2;
  }
  return puVar1;
}



//uint PA_ConvertDbmToRaw(int param_1)
RAIL_TxPowerLevel_t PA_ConvertDbmToRaw(RAIL_TxPower_t power)
{
  short *psVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  short sVar5;
  uint uVar6;
  int iVar7;
  
  psVar1 = (short *)PA_GetTxPowerCurve();
  if ((char)gPaConfig == '\x01') {
    psVar1 = (short *)0x107a2;
    uVar2 = 6;
    do {
      psVar1 = psVar1 + -1;
      if (*psVar1 <= param_1) break;
      uVar2 = uVar2 - 1 & 0xffff;
    } while (uVar2 != 0);
    uVar2 = uVar2 + 1;
  }
  else {
    iVar4 = (int)*psVar1;
    if (param_1 <= *psVar1) {
      iVar4 = param_1;
    }
    sVar5 = -(short)((iVar4 - 200U) / 0x28);
    if (6 < sVar5) {
      sVar5 = 7;
    }
    iVar7 = *(int *)(psVar1 + 2);
    do {
      iVar3 = iVar7 + sVar5 * 8;
      sVar5 = sVar5 + 1;
      uVar2 = (int)*(short *)(iVar3 + 2) * (int)(short)iVar4 + *(int *)(iVar3 + 4);
      uVar2 = (uVar2 & ~((int)uVar2 >> 0x1f)) / 1000;
      iVar3 = (int)sVar5;
      if (iVar3 == 8) break;
    } while (uVar2 <= *(ushort *)(iVar7 + iVar3 * 8));
    uVar6 = (uint)*(ushort *)(iVar7 + (iVar3 + 0x1fffffff) * 8);
    if (uVar6 <= uVar2) {
      uVar2 = uVar6;
    }
  }
  return uVar2 & 0xff;
}



//int PA_ConvertRawToDbm(uint param_1)
RAIL_TxPower_t PA_ConvertRawToDbm(RAIL_TxPowerLevel_t powerLevel)
{
  short sVar1;
  int iVar2;
  ushort uVar3;
  int iVar4;
  
  if ((char)gPaConfig != '\x01') {
    iVar2 = PA_GetTxPowerCurve();
    iVar4 = 0;
    do {
      uVar3 = (ushort)iVar4 & 0xff;
      if (*(ushort *)(*(int *)(iVar2 + 4) + iVar4 * 8 + 8) < param_1) goto LAB_0001076e;
      iVar4 = iVar4 + 1;
    } while (iVar4 != 7);
    uVar3 = 7;
LAB_0001076e:
    iVar2 = *(int *)(iVar2 + 4) + (short)uVar3 * 8;
    sVar1 = (short)((param_1 * 1000 - *(int *)(iVar2 + 4)) / (uint)(int)*(short *)(iVar2 + 2));
    goto LAB_00010788;
  }
  if (param_1 < 8) {
    if (param_1 != 0) goto LAB_00010746;
  }
  else {
    param_1 = 7;
LAB_00010746:
    param_1 = param_1 - 1 & 0xff;
  }
  sVar1 = *(short *)(&curves24Lp + param_1 * 2);
LAB_00010788:
  return (int)sVar1;
}


