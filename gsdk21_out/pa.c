#include "pa.o.h"



void PA_ProtectPa(uint32_t param_1)

{
  bool bVar1;
  RAC_CLR *pRVar2;
  RAC_SET *pRVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  
  if ((char)gPaConfig != '\x03') {
    uVar5 = (SEQ->REG0E0);
    uVar4 = ((uVar5 << 10) >> 0x18) << 6;
    if (param_1 < 0x5b) {
      bVar1 = false;
    }
    else {
      if (gPaConfig._2_2_ < 1801) 
	  {
        bVar1 = 200 < param_1;
        if (bVar1) 
		{
          uVar4 = 0x3fc8;
        }
      }
      else 
	  {
        bVar1 = true;
        uVar4 = 0x3fc8;
      }
    }
    if (param_1 < 0x1f) 
	{
      pRVar2 = &Peripherals::RAC_CLR;
    }
    else 
	{
      pRVar2 = (RAC_CLR *)&Peripherals::RAC_SET;
    }
    write_volatile_4(SEQ->REG0E0,uVar4 | uVar5 & 0xffffc037);
    pRVar2->PABIASCTRL0 = 1;
    (&pRVar2->PABIASCTRL0)[6] = 1;
    if (((apcEnabled == '\0') || (param_1 < 0x51)) || ((gPaConfig._2_2_ < 0x709 && (param_1 < 0x79)))) 
	{
      pRVar3 = (RAC_SET *)&Peripherals::RAC_CLR;
    }
    else 
	{
      BUS_RegMaskedClear(&RAC->PAPKDCTRL,0xdf01);
      BUS_RegMaskedClear(&RAC->SGPAPKDCTRL,0xdf01);
      if (bVar1) uVar5 = 0xd700;
      else uVar5 = 0xd000;
      BUS_RegMaskedSet(&RAC->PAPKDCTRL,uVar5);
      BUS_RegMaskedSet(&RAC->SGPAPKDCTRL,uVar5);
      pRVar3 = &Peripherals::RAC_SET;
    }
    ((RAC_CLR *)pRVar3)->SR3 = 8;
  }
  return;
}



undefined4 getRampTimeFromLevelAndRate(int param_1,uint32_t param_2)

{
  uint32_t uVar1;
  
  uVar1 = SystemHFXOClockGet();
  return (int)((ulonglong)(uint32_t)(((param_1 << (param_2 & 0xff)) >> 5) * 10000) / ((ulonglong)uVar1 / 100));
}



undefined4 PA_GetTxPowerConfig(undefined4 *param_1)

{
  *param_1 = gPaConfig;
  *(undefined2 *)(param_1 + 1) = DAT_00010848;
  return 0;
}



undefined PA_GetPowerLevel(void)

{
  return currentPowerLevel;
}



uint32_t PA_SetPowerLevel(uint32_t param_1)

{
  RAC_SET *pRVar1;
  undefined *puVar2;
  char cVar3;
  uint32_t uVar4;
  int iVar5;
  uint32_t uVar6;
  
  PA_ProtectPa(200);
  if ((char)gPaConfig == '\x03') 
  {
    currentPowerLevel = 0xff;
    return 0xff;
  }
  if ((char)gPaConfig == '\x01') 
  {
    if (param_1 < 8) 
	{
      if (param_1 == 1) 
	  {
        param_1 = 2;
      }
    }
    else 
	{
      param_1 = 7;
    }
	SEQ->REG0E0 &= 0xe0c0003f;
	SEQ->REG0E0 | param_1 << 0x18;
    BUS_RegMaskedClear(&RAC->APC,4);
    param_1 = param_1 & 0xffff;
    goto LAB_0001024e;
  }
  SEQ->REG0E0 &= 0xe0c03fff;
  SEQ->REG0E0 |= 0x3fc8;
  if ((char)gPaConfig == '\0') 
  {
    cVar3 = (char)gPaConfig;
    if (4 < param_1) 
	{
      param_1 = param_1 - 4 & 0xff;
      cVar3 = '\x01';
    }
  }
  else 
  {
    cVar3 = '\0';
  }
  iVar5 = count_leading_zeroes(~CMU->RFLOCK0 & 0x1fc000 | 0x2000);
  uVar6 = (0x13 - iVar5) * 0x1f & 0xff;
  if (uVar6 <= param_1) 
  {
    param_1 = uVar6;
  }
  uVar6 = param_1 & 0xff;
  if ((char)gPaConfig == '\0') 
  {
    if (cVar3 == '\0') 
	{
      iVar5 = 0;
    }
    else 
	{
      iVar5 = 4;
    }
  }
  else 
  {
    iVar5 = 0;
  }
  param_1 = iVar5 + uVar6;
  if (uVar6 == 0) 
  {
    RAC->APC = 0x700002c;
  }
  else 
  {
    RAC->APC = 0x7000000;
    uVar6 = uVar6 - 1 & 0xff;
  }
  uVar6 = uVar4 | (uVar6 % 0x1f) * 0x1000000 + 0x1000000 | ((1 << uVar6 / 0x1f + 1) + -1) * 0x4000;
  SEQ->REG0E0 = uVar6;
  uVar4 = RAC->APC;
  if (paCalEnabled == '\0') 
  {
LAB_0001022e:
    if (param_1 == 0) 
	{
LAB_00010232:
      uVar4 = 0x7000004;
    }
    else 
	{
LAB_00010212:
      uVar4 = uVar4 & 0xfffffb | 0xff000000;
    }
  }
  else 
  {
    iVar5 = count_leading_zeroes((uVar6 << 10) >> 0x18);
    if ((char)gPaConfig == '\x02') 
	{
      puVar2 = &UNK_0fe083b0;
    }
    else 
	{
      puVar2 = &UNK_0fe083b8;
    }
    if (0x1f - iVar5 == -1) goto LAB_0001022e;
    if (param_1 == 0) goto LAB_00010232;
    if (0xfd < (byte)(puVar2[0x1f - iVar5] - 1)) goto LAB_00010212;
    uVar4 = uVar4 & 0xffffff | 4 | (uint32_t)(byte)puVar2[0x1f - iVar5] << 0x18;
  }
  write_volatile_4(RAC->APC,uVar4);
  if (cVar3 == '\0') 
  {
    pRVar1 = (RAC_SET *)&Peripherals::RAC_CLR;
  }
  else 
  {
    pRVar1 = &Peripherals::RAC_SET;
  }
  ((RAC_CLR *)pRVar1)->PABIASCTRL0 = 0x400000;
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
  uint32_t uVar1;
  uint32_t uVar2;
  int iVar3;
  
  iVar3 = SYNTH_Is2p4GHz();
  if (iVar3 == 0) 
  {
    uVar1 = (RAC->SGPACTRL0);
    uVar2 = (RAC->SGPACTRL0);
    write_volatile_4(RAC->SGPACTRL0,uVar1 & 0xffc03fff | (uVar2 & 0x3f8000) >> 1);
  }
  else 
  {
    uVar1 = (RAC->PACTRL0);
    uVar2 = (RAC->PACTRL0);
    write_volatile_4(RAC->PACTRL0,uVar1 & 0xffc03fff | (uVar2 & 0x3f8000) >> 1);
  }
  write_volatile_4(RAC->IFC,0x2000000);
}



void PA_RunPeakDetectorLow(void)

{
  return;
}



void PA_RunBatHigh(void)

{
  int iVar1;
  uint32_t *puVar2;
  
  iVar1 = SYNTH_Is2p4GHz();
  if (iVar1 == 0) 
  {
    puVar2 = &Peripherals::RAC_CLR.SGPACTRL0;
  }
  else 
  {
    puVar2 = &Peripherals::RAC_CLR.PACTRL0;
  }
  *puVar2 = 0x200000;
  BUS_RegMaskedClear(&RAC->IEN,0x8000000);
  return;
}



undefined2 PA_GetRampTime(void)

{
  return DAT_00010848;
}



void PA_ConfigRamp(uint32_t *param_1)

{
  MODEM->RAMPLEV = param_1[1];
  BUS_RegMaskedClear(&MODEM->RAMPCTRL,0xfff);
  BUS_RegMaskedSet(&MODEM->RAMPCTRL,*param_1);
}



int PA_CalcRampTime(void)

{
  int iVar7;
  int iVar8;
  int iVar9;
  
//  iVar7 = getRampTimeFromLevelAndRate(MODEM->RAMPLEV & 0xff,MODEM->RAMPCTRL & 0xf);
//  iVar8 = getRampTimeFromLevelAndRate((MODEM->RAMPLEV << 0x10) >> 0x18,(MODEM->RAMPCTRL << 0x18) >> 0x1c);
//  iVar9 = getRampTimeFromLevelAndRate((MODEM->RAMPLEV << 8) >> 0x18,(MODEM->RAMPCTRL << 0x14) >> 0x1c);
  
  return 	getRampTimeFromLevelAndRate((MODEM->RAMPLEV << 8) >> 0x18,(MODEM->RAMPCTRL << 0x14) >> 0x1c) +
			getRampTimeFromLevelAndRate(MODEM->RAMPLEV & 0xff,MODEM->RAMPCTRL & 0xf) + 
			getRampTimeFromLevelAndRate((MODEM->RAMPLEV << 0x10) >> 0x18,(MODEM->RAMPCTRL << 0x18) >> 0x1c);
  
  //return iVar9 + iVar7 + iVar8;
}



undefined2 PA_SetRampTime(uint32_t param_1,undefined4 param_2,undefined4 param_3)

{
  uint32_t uVar1;
  uint32_t uVar2;
  int iVar3;
  uint32_t local_20;
  int local_1c;
  undefined4 uStack24;
  
  gDesiredRampTime = param_1;
  if (param_1 == 0) 
  {
    gDesiredRampTime = 1;
  }
  uVar2 = (MODEM->CTRL0);
  gCurrentModulation = (byte)((uVar2 << 0x17) >> 0x1d);
  uVar2 = ((uVar2 << 0x17) >> 0x1d) - 2 & 0xff;
  if ((uVar2 < 5) && ((1 << uVar2 & 0x13U) != 0)) iVar3 = 0;
  else 
  {
    if ((char)gPaConfig == '\x02') 
	{
      if (paCalEnabled == '\0') iVar3 = 0x96;
      else iVar3 = 200;
    }
    else 
	{
      if ((char)gPaConfig == '\x01') iVar3 = 0x32;
      else 
	  {
        if (paCalEnabled == '\0') iVar3 = 0xb4;
        else iVar3 = 0xf0;
      }
    }
  }
  uVar2 = 0;
  local_20 = param_1;
  local_1c = param_2;
  uStack24 = param_3;
  do 
  {
    uVar1 = getRampTimeFromLevelAndRate(iVar3,uVar2 & 0xff);
    if (gDesiredRampTime < uVar1) break;
    uVar2 ++;
  } while (uVar2 != 0x10);
  local_20 = (uVar2 - 1) * 0x100;
  local_1c = iVar3 << 0x10;
  PA_ConfigRamp(&local_20);
  DAT_00010848 = PA_CalcRampTime();
  TIMING_RecalculatePaRampChanged(param_2);
  return DAT_00010848;
}



void PA_SetCTune(uint32_t param_1,uint32_t param_2)

{
  SEQ->REG0E8 = param_1 & 7 | (param_1 & 0x1f) << 4;
  SEQ->REG0E4 = param_2 & 7 | (param_2 & 0x1f) << 4;
}



void PA_SelectBand(void)

{
  undefined4 uVar1;
  uint32_t uVar2;
  
  uVar1 = SYNTH_LoDivGet();
  if (false) 
  {
switchD_0001048a_caseD_2:
    uVar2 = 0xf7;
LAB_000104ba:
    SEQ->REG0E8 = uVar2;
    uVar2 = 0xa2;
  }
  else {
    switch(uVar1) 
	{
    case 1:
      uVar2 = 0x44;
      if ((char)gPaConfig != '\x01') 
	  {
        SEQ->REG0E8 = 0;
        goto LAB_000104be;
      }
      break;
    default:
      goto switchD_0001048a_caseD_2;
    case 3:
    case 4:
      uVar2 = 0;
      break;
    case 5:
    case 6:
      uVar2 = 0x33;
      break;
    default:
      uVar2 = 0;
      goto LAB_000104ba;
    }
    SEQ->REG0E8 = uVar2;
  }
LAB_000104be:
  SEQ->REG0E4 = uVar2;
  return;
}



undefined4 PA_Config(uint32_t *param_1)

{
  char cVar1;
  uint32_t uVar3;
  uint32_t *puVar4;
  bool bVar5;
  
  if (param_1 == NULL) return 1;
  RADIO_CLKEnable();
  memset(&SEQ->REG0E0,0,0xc);
  cVar1 = *(char *)param_1;
  if (cVar1 == '\x02') bVar5 = (CMU->RFLOCK0 & 0x200000) == 0;
  else 
  {
    if (cVar1 == '\x01') bVar5 = (CMU->RFLOCK0 & 0xc00000) == 0;
    else 
	{
      if (cVar1 != '\0') goto LAB_00010520;
      bVar5 = (DAT_0fe081d4 & 1 ^ 1 | CMU->RFLOCK0 & 0x400000) == 0;
    }
  }
  if (bVar5) 
  {
    gPaConfig = *param_1;
    DAT_00010848 = *(undefined2 *)(param_1 + 1);
    PA_SetPowerLevel(0);
    PA_SetRampTime(*(undefined2 *)(param_1 + 1),0);
    if ((gPaConfig & 0xff) == 2) 
	{
	  SEQ->REG0E0 &= 0xbfffffe8;
	  SEQ->REG0E0 |= 0x40000020;
      BUS_RegMaskedClear(&RAC->SGPABIASCTRL1,0x7700);
      BUS_RegMaskedSet(&RAC->SGPABIASCTRL1,0x4500);
      BUS_RegMaskedSet(&RAC->SGPABIASCTRL0,1);
    }
    else 
	{
      if ((gPaConfig & 0xff) == 1) 
	  {
		SEQ->REG0E0 &= 0xbfffffe8;
		SEQ->REG0E0 |= 3;
        BUS_RegMaskedClear(&RAC->PACTRL0,7);
        BUS_RegMaskedSet(&RAC->PACTRL0,3);
        BUS_RegMaskedClear(&RAC->PABIASCTRL1,7);
        BUS_RegMaskedSet(&RAC->PABIASCTRL1,6);
        BUS_RegMaskedClear(&RAC->PABIASCTRL0,0x4000c1);
        uVar3 = 0xc000;
        puVar4 = &Peripherals::RAC_CLR.PAPKDCTRL;
      }
      else 
	  {
		SEQ->REG0E0 &= 0xbfffffe8;
		SEQ->REG0E0 |= 0x40000014;
        BUS_RegMaskedClear(&RAC->PACTRL0,7);
        BUS_RegMaskedSet(&RAC->PACTRL0,4);
        BUS_RegMaskedClear(&RAC->PABIASCTRL1,7);
        BUS_RegMaskedSet(&RAC->PABIASCTRL1,5);
        BUS_RegMaskedClear(&RAC->PABIASCTRL0,0xc0);
        puVar4 = &Peripherals::RAC_SET.PABIASCTRL0;
        uVar3 = 0x81;
      }
      *puVar4 = uVar3;
    }
    PA_SetPowerLevel(0);
    BUS_RegMaskedClear(&RAC->APC,3);
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
  PA_SelectBand();
  if ((uint32_t)gCurrentModulation != (MODEM->CTRL0 << 0x17) >> 0x1d) 
  {
    PA_SetRampTime(gDesiredRampTime,param_1);
    return 1;
  }
  return 0;
}



void PA_EnableCal(undefined param_1)

{
  paCalEnabled = param_1;
}



undefined1 * PA_GetTxPowerCurve(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  if (gPaConfig._2_2_ < 1801) 
  {
    puVar2 = &curvesSgDcdc;
    puVar1 = &curves24HpDcdc;
  }
  else 
  {
    puVar2 = &curvesSgVbat;
    puVar1 = &curves24HpVbat;
  }
  if ((char)gPaConfig != '\0') puVar1 = puVar2;
  return puVar1;
}



uint32_t PA_ConvertDbmToRaw(int param_1)

{
  int16_t *psVar1;
  uint32_t uVar2;
  int iVar3;
  int iVar4;
  int16_t sVar5;
  uint32_t uVar6;
  int iVar7;
  
  psVar1 = (int16_t *)PA_GetTxPowerCurve();
  if ((char)gPaConfig == '\x01') 
  {
    psVar1 = (int16_t *)0x107a2;
    uVar2 = 6;
    do 
	{
      psVar1 = psVar1 + -1;
      if (*psVar1 <= param_1) break;
      uVar2 = uVar2 - 1 & 0xffff;
    } while (uVar2 != 0);
    uVar2 = uVar2 + 1;
  }
  else 
  {
    iVar4 = (int)*psVar1;
    if (param_1 <= *psVar1) iVar4 = param_1;
    sVar5 = -(int16_t)((iVar4 - 200U) / 0x28);
    if (6 < sVar5) sVar5 = 7;
    iVar7 = *(int *)(psVar1 + 2);
    do 
	{
      iVar3 = iVar7 + sVar5 * 8;
      sVar5 = sVar5 + 1;
      uVar2 = (int)*(int16_t *)(iVar3 + 2) * (int)(int16_t)iVar4 + *(int *)(iVar3 + 4);
      uVar2 = (uVar2 & ~((int)uVar2 >> 0x1f)) / 1000;
      iVar3 = (int)sVar5;
      if (iVar3 == 8) break;
    } while (uVar2 <= *(uint16_t *)(iVar7 + iVar3 * 8));
    uVar6 = (uint32_t)*(uint16_t *)(iVar7 + (iVar3 + 0x1fffffff) * 8);
    if (uVar6 <= uVar2) uVar2 = uVar6;
  }
  return uVar2 & 0xff;
}



int PA_ConvertRawToDbm(uint32_t param_1)

{
  int16_t sVar1;
  int iVar2;
  uint16_t uVar3;
  int iVar4;
  
  if ((char)gPaConfig != '\x01') 
  {
    iVar2 = PA_GetTxPowerCurve();
    iVar4 = 0;
    do 
	{
      uVar3 = (uint16_t)iVar4 & 0xff;
      if (*(uint16_t *)(*(int *)(iVar2 + 4) + iVar4 * 8 + 8) < param_1) goto LAB_0001076e;
      iVar4 = iVar4 + 1;
    } while (iVar4 != 7);
    uVar3 = 7;
LAB_0001076e:
    iVar2 = *(int *)(iVar2 + 4) + (int16_t)uVar3 * 8;
    sVar1 = (int16_t)((param_1 * 1000 - *(int *)(iVar2 + 4)) / (uint32_t)(int)*(int16_t *)(iVar2 + 2));
    goto LAB_00010788;
  }
  if (param_1 < 8) 
  {
    if (param_1 != 0) goto LAB_00010746;
  }
  else 
  {
    param_1 = 7;
LAB_00010746:
    param_1 = param_1 - 1 & 0xff;
  }
  sVar1 = *(int16_t *)(&curves24Lp + param_1 * 2);
LAB_00010788:
  return (int)sVar1;
}


