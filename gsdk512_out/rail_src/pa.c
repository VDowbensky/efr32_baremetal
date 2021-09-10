#include "pa.h"

static const unsigned char power0dBmParams[14UL + 1] = 
{
  0x83, 0xFF, 0xBF, 0xFF, 0xE2, 0xFF, 0xF1, 0xFF, 0xF9, 0xFF, 0xFE, 0xFF, 0x00, 0x00, 0x00
};

static const unsigned char paParams[272UL + 1] = 
{
  0xC8, 0x00, 0xFC, 0xFE, 0x1F, 0x81, 0x1D, 0x0B, 0x6A, 0xBD, 0xFB, 0xFF, 0xB0, 0x80, 0x7F, 0x05, 0x4A, 0x32, 0xFF, 0xFF, 0x74, 0x80, 0x16, 0x03, 0xEA, 0x4B, 0x00, 0x00, 0x51, 0x80, 0xB5, 0x01, 0x27, 0xB2, 0x00, 0x00, 0x3F, 0x80, 0x49, 0x01,
  0x84, 0xC5, 0x00, 0x00, 0x32, 0x80, 0xD1, 0x00, 0xF0, 0xC3, 0x00, 0x00, 0x28, 0x80, 0x74, 0x00, 0x34, 0xB4, 0x00, 0x00, 0x28, 0x00, 0x4B, 0x00, 0xEA, 0xB5, 0x00, 0x00, 0x8C, 0x00, 0xFC, 0xFE, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x1F, 0x81, 0x58, 0x11, 0x4C, 0x42, 0xFA, 0xFF, 0xA1, 0x80, 0xCA, 0x05, 0x01, 0x97, 0xFF, 0xFF, 0x5D, 0x80, 0x6A, 0x02, 0x4C, 0xA4, 0x00, 0x00, 0x41, 0x80, 0x57, 0x01, 0xA7, 0xCC, 0x00, 0x00, 0x34, 0x80, 0xE0, 0x00, 0xBE, 0xCA, 0x00, 0x00,
  0x2A, 0x80, 0x8C, 0x00, 0xCA, 0xBC, 0x00, 0x00, 0x29, 0x00, 0x52, 0x00, 0xB5, 0xB9, 0x00, 0x00, 0xC8, 0x00, 0xFC, 0xFE, 0x1F, 0x01, 0xC8, 0x0B, 0x7D, 0x30, 0xFB, 0xFF, 0xAB, 0x00, 0x1C, 0x05, 0x03, 0x5B, 0xFF, 0xFF, 0x73, 0x00, 0xFD, 0x02,
  0xDC, 0x55, 0x00, 0x00, 0x53, 0x00, 0xD5, 0x01, 0xBE, 0xAF, 0x00, 0x00, 0x3F, 0x00, 0x19, 0x01, 0xE4, 0xC8, 0x00, 0x00, 0x33, 0x00, 0xAC, 0x00, 0x90, 0xC7, 0x00, 0x00, 0x2C, 0x00, 0x6C, 0x00, 0xB1, 0xBC, 0x00, 0x00, 0x27, 0x00, 0x43, 0x00,
  0x46, 0xAF, 0x00, 0x00, 0x96, 0x00, 0xFC, 0xFE, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x01, 0x6D, 0x0F, 0xA1, 0x82, 0xFA, 0xFF, 0x7E, 0x00, 0xC1, 0x03, 0x79, 0x1F, 0x00, 0x00, 0x55, 0x00, 0xE4, 0x01, 0xF4, 0xB1, 0x00, 0x00,
  0x41, 0x00, 0x37, 0x01, 0xC7, 0xC9, 0x00, 0x00, 0x33, 0x00, 0xC0, 0x00, 0xCA, 0xC7, 0x00, 0x00, 0x2B, 0x00, 0x6E, 0x00, 0xF7, 0xB9, 0x00, 0x00, 0x26, 0x00, 0x38, 0x00, 0x8A, 0xA8, 0x00, 0x00, 0x00
};

/* typedef struct RADIO_PAInit {
  RADIO_PASel_t paSel;
  RADIO_PAVoltMode_t voltMode;
  int16_t power;
  int16_t offset;
  uint16_t rampTime;
} RADIO_PAInit_t;

typedef enum RADIO_PASel
{
    PA_SEL_2P4_HP,
    PA_SEL_2P4_LP,
    PA_SEL_SUBGIG,
    PA_SEL_INVALID
} RADIO_PASel_t;

typedef enum RADIO_PAVoltMode
{
    PA_VOLTMODE_VBAT,
    PA_VOLTMODE_DCDC
} RADIO_PAVoltMode_t;
 */
 
RADIO_PAInit_t gPaConfig;
 
void apcConfigure(int power)

{
  if ((apcEnabled == false) || (power < 0x79)) BUS_RegMaskedClear(&RAC->SR3, 8);
  else 
  {
    BUS_RegMaskedClear(&RAC->PAPKDCTRL,RAC_PAPKDCTRL_CAPSEL_Msk | RAC_PAPKDCTRL_VTHSEL_Msk | RAC_PAPKDCTRL_PKDEN_Msk); //0xdf01); //15,14,12,11...8,0
    BUS_RegMaskedClear(&RAC->SGPAPKDCTRL,RAC_SGPAPKDCTRL_CAPSEL_Msk | RAC_SGPAPKDCTRL_VTHSEL_Msk | RAC_SGPAPKDCTRL_PKDEN_Msk); //0xdf01);
    BUS_RegMaskedSet(&RAC->PAPKDCTRL,0xd700);
    BUS_RegMaskedSet(&RAC->SGPAPKDCTRL,0xd700);
    BUS_RegMaskedSet(&RAC->SR3, 8);
  }
}



int32_t PA_OutputPowerGet(void)

{
  return (int32_t)gPaConfig.power;
}



void PA_PowerOffsetSet(int16_t offset)

{
  gPaConfig.offset = offset;
}



void PA_20dbmConfigSet(void)

{
  SEQ->REG0E4 &= 0xbfffffe8;
  SEQ->REG0E4 |= 0x40000014;
  BUS_RegMaskedClear(&RAC->PACTRL0, RAC_PACTRL0_RF2P4RFVDDSEL_Msk | RAC_PACTRL0_RF2P4PAVDDSEL_Msk | RAC_PACTRL0_RF2P4PASEL_Msk); //7);
  BUS_RegMaskedSet(&RAC->PACTRL0, RAC_PACTRL0_RF2P4RFVDDSEL_Msk); //4);
  BUS_RegMaskedClear(&RAC->PABIASCTRL1,RAC_PABIASCTRL1_VLDO_Msk); //7);
  BUS_RegMaskedSet(&RAC->PABIASCTRL1,5 << RAC_PABIASCTRL1_VLDO_Pos);
  BUS_RegMaskedClear(&RAC->PABIASCTRL0,RAC_PABIASCTRL0_BUF0BIAS_Msk); //0xc0);
  BUS_RegMaskedSet(&RAC->PABIASCTRL0,0x80 | RAC_PABIASCTRL0_LDOBIAS_Msk); //1);
}



void PA_0dbmConfigSet(void)

{
  SEQ->REG0E4 &= 0xbfffffe8;
  SEQ->REG0E4 |= 3;
  BUS_RegMaskedClear(&RAC->PACTRL0,RAC_PACTRL0_RF2P4RFVDDSEL_Msk | RAC_PACTRL0_RF2P4PAVDDSEL_Msk | RAC_PACTRL0_RF2P4PASEL_Msk); //7);
  BUS_RegMaskedSet(&RAC->PACTRL0,RAC_PACTRL0_RF2P4PAVDDSEL_Msk | RAC_PACTRL0_RF2P4PASEL_Msk); //3);
  BUS_RegMaskedClear(&RAC->PABIASCTRL1,RAC_PABIASCTRL1_VLDO_Msk); //7);
  BUS_RegMaskedSet(&RAC->PABIASCTRL1,6 << RAC_PABIASCTRL1_VLDO_Msk);
  BUS_RegMaskedClear(&RAC->PABIASCTRL0,RAC_PABIASCTRL0_TXPOWER_Msk | RAC_PABIASCTRL0_BUF0BIAS_Msk | RAC_PABIASCTRL0_LDOBIAS_Msk); //0x4000c1);
  BUS_RegMaskedClear(&RAC->PAPKDCTRL,RAC_PAPKDCTRL_CAPSEL_Msk); //0xc000);
}



void PA_SubGhz20dbmConfigSet(void)

{
  SEQ->REG0E4 &= 0xbfffffe8;
  SEQ->REG0E4 |= 0x40000020;
  BUS_RegMaskedClear(&RAC->SGPABIASCTRL1,RAC_SGPABIASCTRL1_VCASCODELV_Msk | RAC_SGPABIASCTRL1_VCASCODEHV_Msk); //0x7700);
  BUS_RegMaskedSet(&RAC->SGPABIASCTRL1, (4 << RAC_SGPABIASCTRL1_VCASCODELV_Pos) | (5 << RAC_SGPABIASCTRL1_VCASCODEHV_Pos)); // 0x4500);
  BUS_RegMaskedSet(&RAC->SGPABIASCTRL0,RAC_SGPABIASCTRL0_LDOBIAS_Msk); //1);
}



void PA_PowerModeConfigSet(void)

{
  if ((char)gPaConfig == 2) 
  {
    PA_SubGhz20dbmConfigSet();
    return;
  }
  if ((char)gPaConfig == 1) 
  {
    PA_0dbmConfigSet();
    return;
  }
  PA_20dbmConfigSet();
  return;
}



//uint PA_PowerLevelSet(uint param_1,uint param_2)
uint16_t PA_PowerLevelSet(uint8_t pwrLevel, uint8_t boostMode)

{
  int iVar2;
  uint32_t uVar3;
  
  if ((char)gPaConfig == 3) return 0;
  if ((char)gPaConfig != 1) 
  {
	SEQ->REG0E4 &= 0xe0c03fff;
	SEQ->REG0E4 |= 0x3fc8;; 
    uVar3 = CMU->RFLOCK0;
    iVar2 = count_leading_zeroes(~CMU->RFLOCK0 & 0x1fc000);
    uVar3 = (0x13 - iVar2) * 0x1f & 0xff;
    if (uVar3 <= pwrLevel) pwrLevel = uVar3;
    uVar3 = pwrLevel & 0xffff;
    if (pwrLevel == 0) 
	{
      RAC->APC = 0x700002c;
      boostMode = pwrLevel;
    }
    else 
	{
      RAC->APC = 0x7000000;
      pwrLevel = pwrLevel - 1 & 0xff;
    }
    SEQ->REG0E4 |= (pwrLevel % 0x1f) * 0x1000000 + 0x1000000 | ((1 << ((pwrLevel / 0x1f & 0xff) + 1 & 0xff)) - 1U & 0xff) << 0xe;
    if ((boostMode == 0) || ((char)gPaConfig != '\0')) BUS_RegMaskedClear(&RAC->PABIASCTRL0,RAC_PABIASCTRL0_TXPOWER_Msk);
    else 
	{
      uVar3 = uVar3 | 0x100;
      BUS_RegMaskedSet(&RAC->PABIASCTRL0,RAC_PABIASCTRL0_TXPOWER_Msk); //0x400000);
    }
    apcConfigure(200);
    return uVar3;
  }
  if (pwrLevel < 8) 
  {
    if (pwrLevel == 0) pwrLevel = 1;
  }
  else pwrLevel = 7;
  SEQ->REG0E4 &= 0xe0c0003f;
  SEQ->REG0E4 |= pwrLevel << 0x18;
  return pwrLevel & 0xffff;
}



uint32_t PA_StripesAndSlicesSet(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  iVar1 = (((int)(param_1 & 0xffff7fff) >> 5) + -1) * 0x1f;
  iVar3 = (param_1 & 0x1f) + iVar1;
  if (iVar3 < 1) uVar2 = 1;
  else 
  {
    if (0xfe < iVar3) iVar3 = 0xff;
    uVar2 = (undefined)iVar3;
  }
  uVar4 = PA_PowerLevelSet(uVar2,(param_1 << 0x10) >> 0x1f,param_3,iVar1,param_4);
  if ((uVar4 & 0xff00) == 0) uVar5 = 0;
  else uVar5 = 0x8000;
  return (uVar4 & 0xffff00ff) % 0x1f | ((uVar4 & 0xffff00ff) / 0x1f + 1) * 0x20 | uVar5;
}



uint32_t PA_StripesAndSlicesCommonCalc(int param_1,short *param_2)

{
  int iVar1;
  uint32_t uVar2;
  
  if (*param_2 <= param_1) param_1 = (int)*param_2;
  iVar1 = -((param_1 - 200U) / 0x28);
  if (6 < iVar1) iVar1 = 7;
  uVar2 = param_1 * (param_2 + iVar1 * 4)[3] + *(int *)(param_2 + iVar1 * 4 + 4);
  if (0 < param_1) uVar2 = uVar2 + 500;
  uVar2 = uVar2 / 1000;
  if ((iVar1 != 7) && ((char)gPaConfig != '\x02')) uVar2 = uVar2 | 0x8000;
  return uVar2;
}



uint PA_PowerFromStripesAndSlicesCommonCalc(uint param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 1;
  do 
  {
    if (*(ushort *)(param_2 + iVar2 * 8) < param_1) break;
    iVar2 = iVar2 + 1;
  } while (iVar2 != 8);
  param_2 = param_2 + (iVar2 + -1) * 8;
  uVar1 = (param_1 & 0xffff7fff) * 1000 - *(int *)(param_2 + 4);
  if (0 < (int)uVar1)  uVar1 = uVar1 + 500;
  return uVar1 / (uint)(int)*(short *)(param_2 + 2);
}


void PA_PowerLevelOptimize(int32_t power)

{
  uint uVar1;
  
  if ((char)gPaConfig == '\x03') return;
  uVar1 = SEQ->REG0E4;
  if (power < 0x83) 
  {
	SEQ->REG0E4 &= 0xffffc037; 
	SEQ->REG0E4 |= ((uVar1 << 10) >> 0x18) << 6;
    if (power < 0x1f) 
	{
	  BUS_RegMaskedClear(&RAC->PABIASCTRL0,RAC_PABIASCTRL0_LDOBIAS_Msk); //1);
	  BUS_RegMaskedClear(&RAC->SGPABIASCTRL0,RAC_SGPABIASCTRL0_LDOBIAS_Msk); //1);
	}
  }
  else 
  {
	SEQ->REG0E4 &= 0xffffc037;
	SEQ->REG0E4 |= 0x3fc8;
  }
	BUS_RegMaskedSet(&RAC->PABIASCTRL0,RAC_PABIASCTRL0_LDOBIAS_Msk); //1);
	BUS_RegMaskedSet(&RAC->SGPABIASCTRL0,RAC_SGPABIASCTRL0_LDOBIAS_Msk); //1); 
	apcConfigure();
}



//void PA_StripesAndSlicesCalc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
void PA_StripesAndSlicesCalc(int level)
{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if ((char)gPaConfig != '\x03') 
  {
    if ((char)gPaConfig == '\x01') 
	{
      uVar3 = SEQ->REG0E4;
      iVar1 = 6;
      do 
	  {
        if ((int)*(short *)(power0dBmParams + iVar1 * 2) <= param_1 + gPaConfig.offset) break;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
      iVar2 = (int)*(short *)(power0dBmParams + iVar1 * 2);
	  SEQ->REG0E4 &= 0xe0c0003f;
	  SEQ->REG0E4 |= (iVar1 + 1) * 0x1000000;
    }
    else 
	{
      uVar3 = (uint)gPaConfig._1_1_;
      if ((char)gPaConfig != '\0') uVar3 = uVar3 + 2;
      iVar2 = uVar3 * 0x44;
      PA_StripesAndSlicesCommonCalc(param_1 + gPaConfig.offset,paParams + iVar2,paParams,uVar3,param_4);
      iVar1 = PA_StripesAndSlicesSet();
      if (iVar1 == 0x21) iVar2 = (int)*(short *)(paParams + iVar2 + 2);
      else iVar2 = PA_PowerFromStripesAndSlicesCommonCalc(iVar1,iVar2 + 0x1074c);
    }
    PA_PowerLevelOptimize(iVar2);
    gPaConfig.power = (short)iVar2 - gPaConfig.offset;
  }
}



//int32_t PA_OutputPowerSet(void)
//int32_t PA_OutputPowerSet(int32_t powerLevel)
int32_t PA_OutputPowerSet(int32_t power)
{
  PA_StripesAndSlicesCalc(powerLevel);
  return (int)gPaConfig.power;
}



int32_t PA_MaxOutputPowerSet(void)

{
  PA_StripesAndSlicesCalc(200);
  return (int)gPaConfig.power;
}



void PA_APCEnable(void)

{
  apcEnabled = 1;
  apcConfigure((int)gPaConfig.power);
}



void PA_APCDisable(void)

{
  apcEnabled = 0;
  apcConfigure((int)gPaConfig.power);
}



void PA_PeakDetectorHighRun(void)

{
  if (SYNTH_Is2p4GHz() == false) RAC->SGPACTRL0 = (RAC->SGPACTRL0 & ~RAC_SGPACTRL0_SLICE_Msk) | ((RAC->SGPACTRL0 & 0x3f8000) >> 1); 
  else RAC->PACTRL0 = (RAC->PACTRL0 & RAC_PACTRL0_SLICE_Msk) | ((RAC->PACTRL0 & 0x3f8000) >> 1);
  RAC->IFC = RAC_IFC_PAVHIGH_Msk; //0x2000000;
}



void PA_PeakDetectorLowRun(void)

{

}



void PA_BatHighRun(void)

{
  if (SYNTH_Is2p4GHz() == false) BUS_RegMaskedClear(&RAC->SGPACTRL0,0x200000); 
  else BUS_RegMaskedClear(&RAC->PACTRL0,0x200000); 
  BUS_RegMaskedClear(&RAC->IEN,RAC_IEN_PABATHIGH_Msk); //0x8000000);
}



//undefined2 PA_RampTimeGet(void)
uint32_t PA_RampTimeGet(void)

{
  return gPaConfig.ramptime;
}



void PA_RampConfigSet(uint32_t *ramp)

{
  MODEM->RAMPLEV = ramp[1];
  BUS_RegMaskedClear(&MODEM->RAMPCTRL,MODEM_RAMPCTRL_RAMPRATE2_Msk | MODEM_RAMPCTRL_RAMPRATE1_Msk | MODEM_RAMPCTRL_RAMPRATE0_Msk); //0xfff);
  BUS_RegMaskedSet(&MODEM->RAMPCTRL,*ramp);
}



int32_t PA_RampTimeCalc(void)

{
  return (((int32_t)(MODEM->RAMPLEV & MODEM_RAMPLEV_RAMPLEV2_Msk) >> MODEM_RAMPLEV_RAMPLEV2_Pos) - 
  ((MODEM->RAMPLEV & MODEM_RAMPLEV_RAMPLEV1_Msk) >> MODEM_RAMPLEV_RAMPLEV1_Pos) << ((MODEM->RAMPCTRL & MODEM_RAMPCTRL_RAMPRATE2_Msk) >> MODEM_RAMPCTRL_RAMPRATE2_Pos)) >> 5) + 
  ((int32_t)(((MODEM->RAMPLEV & MODEM_RAMPLEV_RAMPLEV1_Msk) >> MODEM_RAMPLEV_RAMPLEV1_Pos) - 
  (MODEM->RAMPLEV & MODEM_RAMPLEV_RAMPLEV0_Msk) << ((MODEM->RAMPCTRL & MODEM_RAMPCTRL_RAMPRATE1_Msk) >> MODEM_RAMPCTRL_RAMPRATE1_Pos)) >> 5) + 
  ((int32_t)((MODEM->RAMPLEV & MODEM_RAMPLEV_RAMPLEV0_Msk) << (MODEM->RAMPCTRL & MODEM_RAMPCTRL_RAMPRATE0_Msk)) >> 5);
}



//undefined2 PA_RampTimeSet(int param_1,undefined4 param_2,undefined4 param_3)
uint32_t PA_RampTimeSet(uint32_t ramptime)

{
  uint uVar1;
  char cVar3;
  uint32_t tmp;
  int local_18;
  int local_14;
  
  tmp = MODEM->CTRL0;
  gCurrentModulation = (uint8_t)((MODEM->CTRL0 & MODEM_CTRL0_MODFORMAT_Msk) >> MODEM_CTRL0_MODFORMAT_Pos);
  
  tmp = ((MODEM->CTRL0 & MODEM_CTRL0_MODFORMAT_Msk) >> MODEM_CTRL0_MODFORMAT_Pos) - 2 & 0xff;
  
  if ((tmp < 5) && ((1 << tmp & 0x13U) != 0)) tmp = 0;
  else 
  {
    if ((char)gPaConfig == 2') tmp = 0x96;
    else 
	{
      if ((char)gPaConfig == 1) tmp = 0x32;
      else tmp = 0xb4;
    }
  }
  gDesiredRampTime = ramptime;
  local_18 = param_1;
  local_14 = param_2;

  uVar1 = SystemHFXOClockGet();
  cVar3 = -1;
  for (uVar1 = (((uVar1 / 1000) * param_1) / tmp << 5) / 1000; uVar1 != 0; uVar1 = uVar1 >> 1) cVar3++;
  local_18 = (int)cVar3;
  if (local_18 < 0x10) 
  {
    if (local_18 < 0) local_18 = 0;
  }
  else local_18 = 0xf;
  local_18 = local_18 << 8;
  local_14 = tmp << 0x10;
  PA_RampConfigSet(&local_18);
  gPaConfig.ramptime = (uint16_t)((uint32_t)(PA_RampTimeCalc() * 10000) / (SystemHFXOClockGet() / 100));
  TIMING_RecalculateAll();
  return gPaConfig.ramptime;
}



void PA_CTuneSet(uint8_t txPaCtuneValue, uint8_t rxPaCtuneValue)

{
  SEQ->DYNAMIC_CHPWR_TABLE = txPaCtuneValue & 7 | (txPaCtuneValue & 0x1f) << 4;
  SEQ->REG0E8 = rxPaCtuneValue & 7 | (rxPaCtuneValue & 0x1f) << 4;
}



void PA_BandSelect(void)

{
  uint uVar2;
  
  if (false) 
  {
switchD_0001062e_caseD_2:
    uVar2 = 0xf7;
LAB_0001065e:
    SEQ->DYNAMIC_CHPWR_TABLE = uVar2;
    uVar2 = 0xa2;
  }
  else 
  {
    switch(SYNTH_LoDivGet()) 
	{
    case 1:
      uVar2 = 0x44;
      if ((char)gPaConfig != '\x01') 
	  {
        SEQ->DYNAMIC_CHPWR_TABLE = 0;
        goto LAB_00010662;
      }
      break;
    default:
      goto switchD_0001062e_caseD_2;
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
      goto LAB_0001065e;
    }
    SEQ->DYNAMIC_CHPWR_TABLE = uVar2;
  }
LAB_00010662:
  SEQ->REG0E8 = uVar2;
}


bool RADIO_PA_Init(RADIO_PAInit_t * paInit)

{
  if (paInit == NULL) return false;
  RADIO_CLKEnable();
  memset(&SEQ->REG0E4,0,0xc);
  
  if((paInit->paSel != PA_SEL_SUBGIG) && (paInit->paSel != PA_SEL_2P4_LP) && (paInit->paSel != PA_SEL_2P4_HP)
  {
	gPaConfig.power = 0x8000;
	return false;
  }
  
  else
  {
	//check PA presence - maybe omitted
	if(((paInit->paSel == PA_SEL_SUBGIG) &&  (CMU->RFLOCK0 & 0x200000 == 0)) || ((paInit->paSel == PA_SEL_2P4_LP) &&  (CMU->RFLOCK0 & 0xc00000 == 0)) || ((paInit->paSel == PA_SEL_2P4_HP) &&  (CMU->RFLOCK0 & 0x400000 | (_DAT_0fe081d4 & 1 ^ 1) == 0))) 
	{
		gPaConfig.power = paInit->paSel;
		gPaConfig.voltmode = paInit->voltMode;
		PA_RampTimeSet(paInit->rampTime);
		PA_PowerModeConfigSet();
		PA_OutputPowerSet(paInit->power);
		BUS_RegMaskedClear(&RAC->APC,3);
		PA_BandSelect();
		return true;		
	}
	
	else
	{
		gPaConfig.power = 0x8000;
		return false;
	}
  }
}



bool PA_UpdateConfig(void)

{
  PA_BandSelect();
  if ((uint32_t)gCurrentModulation != (MODEM->CTRL0 && MODEM_CTRL0_MODFORMAT_Msk) >> MODEM_CTRL0_MODFORMAT_Pos) 
  {
    PA_RampTimeSet(gDesiredRampTime);
    return true;
  }
  return false;
}


