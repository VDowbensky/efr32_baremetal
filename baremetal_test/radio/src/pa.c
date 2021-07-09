#include "pa.h"
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include "em_bus.h"
#include "em_assert.h"
#include "synth.h"
#include "radio.h"
#include "radio_cmu.h"

bool apcEnabled = false;
struct
{
	uint8_t pasel;
	uint8_t vm;
	int32_t pwr;
	int32_t offs;
	uint16_t rt;
	
}gPaConfig;

uint8_t power0dBmParams[] = {0x83, 0xff, 0xbf, 0xff, 0xe2, 0xff, 0xf1, 0xff, 0xf9, 0xff}; 

uint8_t paParams[272UL + 1] = 
{
  0xC8, 0x00, 0xFC, 0xFE, 0x1F, 0x81, 0x1D, 0x0B, 0x6A, 0xBD, 0xFB, 0xFF, 0xB0, 0x80, 0x7F, 0x05, 0x4A, 0x32, 0xFF, 0xFF, 0x74, 0x80, 0x16, 0x03, 0xEA, 0x4B, 0x00, 0x00, 0x51, 0x80, 0xB5, 0x01, 0x27, 0xB2, 0x00, 0x00, 0x3F, 0x80, 0x49, 0x01,
  0x84, 0xC5, 0x00, 0x00, 0x32, 0x80, 0xD1, 0x00, 0xF0, 0xC3, 0x00, 0x00, 0x28, 0x80, 0x74, 0x00, 0x34, 0xB4, 0x00, 0x00, 0x28, 0x00, 0x4B, 0x00, 0xEA, 0xB5, 0x00, 0x00, 0x8C, 0x00, 0xFC, 0xFE, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x1F, 0x81, 0x58, 0x11, 0x4C, 0x42, 0xFA, 0xFF, 0xA1, 0x80, 0xCA, 0x05, 0x01, 0x97, 0xFF, 0xFF, 0x5D, 0x80, 0x6A, 0x02, 0x4C, 0xA4, 0x00, 0x00, 0x41, 0x80, 0x57, 0x01, 0xA7, 0xCC, 0x00, 0x00, 0x34, 0x80, 0xE0, 0x00, 0xBE, 0xCA, 0x00, 0x00,
  0x2A, 0x80, 0x8C, 0x00, 0xCA, 0xBC, 0x00, 0x00, 0x29, 0x00, 0x52, 0x00, 0xB5, 0xB9, 0x00, 0x00, 0xC8, 0x00, 0xFC, 0xFE, 0x1F, 0x01, 0xC8, 0x0B, 0x7D, 0x30, 0xFB, 0xFF, 0xAB, 0x00, 0x1C, 0x05, 0x03, 0x5B, 0xFF, 0xFF, 0x73, 0x00, 0xFD, 0x02,
  0xDC, 0x55, 0x00, 0x00, 0x53, 0x00, 0xD5, 0x01, 0xBE, 0xAF, 0x00, 0x00, 0x3F, 0x00, 0x19, 0x01, 0xE4, 0xC8, 0x00, 0x00, 0x33, 0x00, 0xAC, 0x00, 0x90, 0xC7, 0x00, 0x00, 0x2C, 0x00, 0x6C, 0x00, 0xB1, 0xBC, 0x00, 0x00, 0x27, 0x00, 0x43, 0x00,
  0x46, 0xAF, 0x00, 0x00, 0x96, 0x00, 0xFC, 0xFE, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x01, 0x6D, 0x0F, 0xA1, 0x82, 0xFA, 0xFF, 0x7E, 0x00, 0xC1, 0x03, 0x79, 0x1F, 0x00, 0x00, 0x55, 0x00, 0xE4, 0x01, 0xF4, 0xB1, 0x00, 0x00,
  0x41, 0x00, 0x37, 0x01, 0xC7, 0xC9, 0x00, 0x00, 0x33, 0x00, 0xC0, 0x00, 0xCA, 0xC7, 0x00, 0x00, 0x2B, 0x00, 0x6E, 0x00, 0xF7, 0xB9, 0x00, 0x00, 0x26, 0x00, 0x38, 0x00, 0x8A, 0xA8, 0x00, 0x00, 0x00
};

uint32_t peakDetectorOldSlices;
void PA_StripesAndSlicesCalc(int32_t pwr);


void apcConfigure(int32_t p)

{
  
  if ((apcEnabled == false) || (p < 0x79))
  {
    RAC->SR3 &= ~8;
		return;
  }
  else 
  {
    //RAC->PAPKDCTRL &= ~0xdf01;
		BUS_RegMaskedClear(&RAC->PAPKDCTRL, RAC_PAPKDCTRL_CAPSEL_Msk | RAC_PAPKDCTRL_VTHSEL_Msk | RAC_PAPKDCTRL_PKDEN_Msk);
    //RAC->SGPAPKDCTRL &= ~0xdf01;
		BUS_RegMaskedClear(&RAC->SGPAPKDCTRL, RAC_SGPAPKDCTRL_CAPSEL_Msk | RAC_SGPAPKDCTRL_VTHSEL_Msk | RAC_SGPAPKDCTRL_PKDEN_Msk);
    RAC->PAPKDCTRL |= 0xd700;
    RAC->SGPAPKDCTRL |= 0xd700;
    RAC->SR3 |= 8;
  }
}



int32_t PA_OutputPowerGet(void)

{
	return gPaConfig.pwr;
}



void PA_PowerOffsetSet(int16_t offset)

{
	gPaConfig.offs = offset;
}



void PA_20dbmConfigSet(void)

{
	//RAC->PACTRL0 &= ~0x7;
	BUS_RegMaskedClear(&RAC->PACTRL0, RAC_PACTRL0_RF2P4RFVDDSEL_Msk | RAC_PACTRL0_RF2P4PAVDDSEL_Msk); 
  //RAC->PACTRL0 |= 0x4;
	BUS_RegMaskedSet(&RAC->PACTRL0, RAC_PACTRL0_RF2P4RFVDDSEL_Msk);
  //RAC->PABIASCTRL1 &= 0xfffffff8;
	BUS_RegMaskedClear(&RAC->PABIASCTRL1, RAC_PABIASCTRL1_VLDO_Msk);
  //RAC->PABIASCTRL1 |= 0x5;
	BUS_RegMaskedSet(&RAC->PABIASCTRL1, 5);
  //RAC->PABIASCTRL0 &= ~0xc0;
	BUS_RegMaskedClear(&RAC->PABIASCTRL0, RAC_PABIASCTRL0_BUF0BIAS_Msk);
  //RAC->PABIASCTRL0 |= 0x81;
	BUS_RegMaskedSet(&RAC->PABIASCTRL0, 0x80 | RAC_PABIASCTRL0_LDOBIAS_Msk);
}



void PA_0dbmConfigSet(void)

{
  //RAC->PACTRL0 &= ~0x7;
	BUS_RegMaskedClear(&RAC->PACTRL0, RAC_PACTRL0_RF2P4RFVDDSEL_Msk | RAC_PACTRL0_RF2P4PAVDDSEL_Msk);
  //RAC->PACTRL0 |= 3;
	BUS_RegMaskedSet(&RAC->PACTRL0, RAC_PACTRL0_RF2P4PAVDDSEL_Msk);
  //RAC->PABIASCTRL1 &= ~0x7;
	BUS_RegMaskedClear(&RAC->PABIASCTRL1, RAC_PABIASCTRL1_VLDO_Msk);
  //RAC->PABIASCTRL1 |= 6;
	BUS_RegMaskedSet(&RAC->PABIASCTRL1, 6);
  //RAC->PABIASCTRL0 &= ~0x4000c1;
	BUS_RegMaskedClear(&RAC->PABIASCTRL0, RAC_PABIASCTRL0_TXPOWER_Msk | RAC_PABIASCTRL0_BUF0BIAS_Msk | RAC_PABIASCTRL0_LDOBIAS_Msk);
  //RAC->PAPKDCTRL &= ~0xc000;
	BUS_RegMaskedClear(&RAC->PAPKDCTRL, RAC_PAPKDCTRL_CAPSEL_Msk);
}



void PA_SubGhz20dbmConfigSet(void)

{
  //RAC->SGPABIASCTRL1 &= ~0x7700; //8...10,12...14 - VCASCODEHV, VCASCODELV
	BUS_RegMaskedClear(&RAC->SGPABIASCTRL1, RAC_SGPABIASCTRL1_VCASCODELV_Msk | RAC_SGPABIASCTRL1_VCASCODEHV_Msk);
  //RAC->SGPABIASCTRL1 |= 0x4500; //8,10 VCASCODEHV 14 VCASCODELV
	BUS_RegMaskedSet(&RAC->SGPABIASCTRL1, 0x4500);
  //RAC->SGPABIASCTRL0 |= 1; //LDOBIAS on
	BUS_RegMaskedSet(&RAC->SGPABIASCTRL0, RAC_SGPABIASCTRL0_LDOBIAS_Msk); //LDO on
	//BUS_RegMaskedSet(&RAC->SGPABIASCTRL0, 0x80 | RAC_SGPABIASCTRL0_LDOBIAS_Msk); //LDO on
}



void PA_PowerModeConfigSet(void)

{
	switch(gPaConfig.pasel)
	{
		case PA_SEL_2P4_LP:
		PA_0dbmConfigSet();
		break;
		
		case PA_SEL_2P4_HP:
		PA_20dbmConfigSet();
		break;
		
		case PA_SEL_SUBGIG:
		default:
		PA_SubGhz20dbmConfigSet();
		break;		
	}
}





uint32_t PA_StripesAndSlicesSet(uint32_t param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  int32_t iVar3;
  uint32_t uVar4;
	#if PWR_DEBUG_MODE
	printf("PA_StripesAndSlicesSet:input: %X\r\n", param_1);
	#endif
  
  //uVar4 = *(uint32_t*) 0x400e4188; // DAT_400e4188; //CMU reg 188
  uVar2 = (param_1 << 0x17) >> 0x1c; //>>5 bits
	
  //iVar3 = count_leading_zeroes(~uVar4 & 0x1fc000); //0xdc0000 - 14 !!!!!
	//iVar3 = 14;
  //uVar4 = 0x13 - iVar3; //5
	uVar4 = 5;
  //if (uVar4 < uVar2)
	if (uVar2 > 5)
  {
    if (uVar4 != 0)
    {
      //uVar1 = 0x1f;
			uVar1 = 31;
      //uVar2 = uVar4;
			uVar2 = 5;
      goto LAB_000101c0;
    }
  }
  else
  {
    if (uVar2 != 0)
    {
      uVar1 = param_1 & 0x1f;
      if (uVar1 == 0) uVar1 = 1;
      goto LAB_000101c0;
    }
  }
  uVar1 = 1;
  //uVar2 = uVar1;
	uVar2 = 1;
LAB_000101c0:
  //_DAT_21000fc0 = _DAT_21000fc0 & 0xe0c03fff | 0x3fc8 | uVar1 << 0x18 | ((1 << (uVar2 & 0xff)) - 1U & 0xff) << 0xe;
  //SEQ->REG0C0 = SEQ->REG0C0 & 0xe0c03fff | 0x3fc8 | uVar1 << 0x18 | ((1 << (uVar2 & 0xff)) - 1U & 0xff) << 0xe;
	SEQ->REG0C0 &= 0xe0c03fff;
	SEQ->REG0C0 |= 0x3fc8 | uVar1 << 0x18 | ((1 << (uVar2 & 0xff)) - 1U & 0xff) << 0xe;
  uVar1 |= uVar2 << 5;
  if ((param_1 & 0x8000) == 0) 
  {
  //RAC->PABIASCTRL0 &= 0xffbfffff; //TXPOWER off
	BUS_RegMaskedClear(&RAC->PABIASCTRL0 , RAC_PABIASCTRL0_TXPOWER_Msk);
	#if PWR_DEBUG_MODE
	printf("PA_StripesAndSlicesSet:%X\r\n", uVar1);
	printf("PA_StripesAndSlicesSet: PA:%X, REG0C0:%X\r\n", gPaConfig.pasel, SEQ->REG0C0);
	#endif
    return uVar1;
  }
  //RAC->PABIASCTRL0 |= 0x400000; //TXPOWER on bit 22
	BUS_RegMaskedSet(&RAC->PABIASCTRL0 , RAC_PABIASCTRL0_TXPOWER_Msk);
	#if PWR_DEBUG_MODE
	printf("PA_StripesAndSlicesSet:%X\r\n", uVar1);
	printf("PA_StripesAndSlicesSet: PA:%X, REG0C0:%X\r\n", gPaConfig.pasel, SEQ->REG0C0);
	#endif
  return uVar1 | 0x8000;
}



uint32_t PA_PowerLevelSet(uint32_t pwr)

{
  uint32_t uVar1;
  uint32_t uVar2;
  
  if (gPaConfig.pasel == PA_SEL_2P4_LP)
  {
    if (pwr < 8)
    {
      if (pwr == 0) pwr = 1;
    }
    else pwr = 7;
    //_DAT_21000fc0 = _DAT_21000fc0 & 0xe0c0003f | param_1 << 0x18;
    //SEQ->REG0C0 = SEQ->REG0C0 & 0xe0c0003f | pwr << 0x18;
		SEQ->REG0C0 &= 0xe0c0003f;
		SEQ->REG0C0 |= pwr << 0x18; //stripe
    return pwr & 0xffff;
  }
  if (pwr < 0xf9)
  {
    if (pwr == 0) goto LAB_00010240;
  }
  else pwr = 0xf8; //248 - ???
  pwr = pwr - 1 & 0xff;
LAB_00010240:
  uVar1 = pwr % 0x1f + 1 | ((pwr / 0x1f & 0xff) + 1) * 0x20;
  if (pwr != 0) uVar1 = uVar1 | 0x8000;
  uVar1 = PA_StripesAndSlicesSet(uVar1);
  if ((uVar1 & 0x8000) == 0) uVar2 = 0;
  else uVar2 = 0x100;
  apcConfigure(200);
	#if PWR_DEBUG_MODE
	printf ("PA_PowerLevelSet:%X\r\n", (uVar1 & 0x1f) + (((uVar1 & 0xffff7fe0) - ((uVar1 & 0xffff7fff) >> 5)) - 0x1f & 0xffff | uVar2) & 0xffff);
	printf("PA_PowerLevelSet: PA:%X, SYNTH:%X\r\n", gPaConfig.pasel, SYNTH_LoDivGet());
	#endif
  return (uVar1 & 0x1f) + (((uVar1 & 0xffff7fe0) - ((uVar1 & 0xffff7fff) >> 5)) - 0x1f & 0xffff | uVar2) & 0xffff;
}



uint32_t PA_StripesAndSlicesCommonCalc(int32_t param_1,uint8_t *param_2)

{
  int iVar1;
  uint32_t uVar2;
  
  if (*param_2 <= param_1) param_1 = (int)*param_2;//max power, *0.1 dBm
  iVar1 = -((param_1 - 200U) / 0x28);
  if (6 < iVar1) iVar1 = 7;
  uVar2 = param_1 * (param_2 + iVar1 * 4)[3] + *(int *)(param_2 + iVar1 * 4 + 4);
  if (0 < param_1) uVar2 = uVar2 + 500;
  uVar2 = uVar2 / 1000;
  if ((iVar1 != 7) && (gPaConfig.pasel != PA_SEL_SUBGIG)) uVar2 = uVar2 | 0x8000;
	#if PWR_DEBUG_MODE
	printf("PA_StripesAndSlicesCommonCalc: PA:%X, SYNTH:%X, return value: %X\r\n", gPaConfig.pasel, SYNTH_LoDivGet(), uVar2);
	#endif
  return uVar2;
}



uint32_t PA_PowerFromStripesAndSlicesCommonCalc(uint32_t param_1, uint8_t *param_2)

{
  uint32_t uVar1;
  int32_t iVar2;
	uint32_t retval;
  
  iVar2 = 1;
  do
  {
    if (*(uint16_t *)(param_2 + iVar2 * 8) < param_1) break;
    iVar2 = iVar2 + 1;
  } while (iVar2 != 8);
  param_2 = param_2 + (iVar2 + -1) * 8;
  uVar1 = (param_1 & 0xffff7fff) * 1000 - *(int *)(param_2 + 4);
  //if (0 < (int32_t)uVar1) uVar1 = uVar1 + 500;
	if (!(uVar1 & 0x80000000)) uVar1 += 500;
  return uVar1 / (uint32_t)(int32_t)*(int16_t *)(param_2 + 2);
	#if PWR_DEBUG_MODE
	printf("PA_PowerFromStripesAndSlicesCommonCalc: PA:%X, SYNTH:%X, return value: %X\r\n", gPaConfig.pasel, SYNTH_LoDivGet(), retval);
	#endif
	return retval;
	
}




void PA_PowerLevelOptimize(int32_t p)

{
  if (p < 0x83)
  {
    //_DAT_21000fc0 = _DAT_21000fc0 & 0xffffc037 | ((_DAT_21000fc0 << 10) >> 0x18) << 6;
	  SEQ->REG0C0 = SEQ->REG0C0 & 0xffffc037 | ((SEQ->REG0C0 << 10) >> 0x18) << 6;
    if (p < 0x1f)
	  {
      //RAC->SGPABIASCTRL0 &= 0xfffffffe;
			BUS_RegMaskedClear(&RAC->SGPABIASCTRL0,1);
			//printf("PA_PowerLevelOptimize: PA:%X, SYNTH:%X, return value: %X\r\n", gPaConfig.pasel, SYNTH_LoDivGet(), RAC->SGPABIASCTRL0);
      apcConfigure(p);
	  return;
    }
  }
  else 
  {
    //_DAT_21000fc0 = _DAT_21000fc0 & 0xffffc037 | 0x3fc8;
    SEQ->REG0C0 = (SEQ->REG0C0 & 0xffffc037) | 0x3fc8;
  }
  //RAC->SGPABIASCTRL0 |= 1;
	BUS_RegMaskedSet(&RAC->SGPABIASCTRL0, 1);
//LAB_0001037a:
  apcConfigure(p);
	#if PWR_DEBUG_MODE
	printf("PA_PowerLevelOptimize: PA:%X, SYNTH:%X, return value: %X\r\n", gPaConfig.pasel, SYNTH_LoDivGet(), RAC->SGPABIASCTRL0);
	#endif
  return;
}



//void PA_StripesAndSlicesCalc(int32_t param_1,uint32_t param_2,uint32_t param_3,uint32_t param_4)
void PA_StripesAndSlicesCalc(int32_t pwr)

{
  int32_t iVar1;
	int32_t i;
  int32_t iVar2;
  uint32_t uVar3;
 
   if (gPaConfig.pasel == PA_SEL_2P4_LP)
  {
    iVar1 = 6;
    do {
      if ((int)*(short *)(&power0dBmParams + iVar1 * 2) <= pwr + gPaConfig.offs) break;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    iVar2 = (int32_t)*(int16_t *)(&power0dBmParams + iVar1 * 2);
		SEQ->REG0C0 &= 0xe0c0003f;
		SEQ->REG0C0 |= (iVar1 + 1) * 0x1000000;
  }
	
  else
  {
    uVar3 = (uint32_t)gPaConfig.vm;
    if (gPaConfig.pasel != PA_SEL_2P4_HP) uVar3 = uVar3 + 2;
    iVar2 = uVar3 * 0x44;
    //PA_StripesAndSlicesCommonCalc(pwr + gPaConfig.offs, &paParams + iVar2,&paParams,uVar3,param_4);uint32_t
		uVar3 = PA_StripesAndSlicesCommonCalc(pwr + gPaConfig.offs, paParams + iVar2);
    //iVar1 = PA_StripesAndSlicesSet();
    if (PA_StripesAndSlicesSet(uVar3) == 0x21) 
		{
      //iVar2 = (int32_t)*(int16_t *)(&DAT_00010726 + iVar2);
			iVar2 = (int32_t)*(int16_t *)(paParams + 2 + iVar2);
    }
    else 
		{
      //iVar2 = PA_PowerFromStripesAndSlicesCommonCalc(iVar1,&UNK_00010728 + iVar2);
			iVar2 = PA_PowerFromStripesAndSlicesCommonCalc(iVar1, paParams + 4 + iVar2);
    }
  }
  PA_PowerLevelOptimize(iVar2);
  peakDetectorOldSlices = SEQ->REG0C0; //!!!!!!
	gPaConfig.pwr = (int16_t)iVar2 - gPaConfig.offs;
  return;
}



int32_t PA_OutputPowerSet(int32_t level)

{
  PA_StripesAndSlicesCalc(level); //!!!!!!
  return gPaConfig.pwr; //!!!!!!
}



int32_t PA_MaxOutputPowerSet(void) //20 dBm

{
  PA_StripesAndSlicesCalc(200); //!!!!!!
  //return (int)gPaConfig._2_2_; //!!!!!!
	return gPaConfig.pwr;
}



void PA_APCEnable(void)

{
  apcEnabled = 1;
 // apcConfigure((int)gPaConfig._2_2_); //!!!!!!
	apcConfigure(gPaConfig.pwr);
}



void PA_APCDisable(void)

{
  apcEnabled = 0;
  //apcConfigure((int)gPaConfig._2_2_); //!!!!!!
	apcConfigure(gPaConfig.pwr);
}


void PA_PeakDetectorHighRun(void)

{
  uint32_t uVar3;
  
  uVar3 = SEQ->REG0C0 >> 1 & 0x1fc000;

  //SEQ->REG0C0 >>= 1;
  //_DAT_21000fc0 = _DAT_21000fc0 & 0xffc03fff | uVar3;
  SEQ->REG0C0 |= 0xffc03fff;
  SEQ->REG0C0 &= uVar3;
  if (!(SYNTH_Is2p4GHz()))
  {
		//RAC->SGPACTRL0 &= 0xffc03fff; //14...21 SLICE
		BUS_RegMaskedClear(&RAC->SGPACTRL0, 0xffc0);
		//RAC->SGPACTRL0 |= uVar3; //
		BUS_RegMaskedSet(&RAC->SGPACTRL0, uVar3);
  }
  else 
  {
    //RAC->PACTRL0 &= 0xffc03fff;
		BUS_RegMaskedClear(&RAC->PACTRL0, 0xffc0);
		//RAC->PACTRL0 |= uVar3;
		BUS_RegMaskedSet(&RAC->PACTRL0, uVar3);
  }
  //RAC->IFC = 0x2000000; //25
	BUS_RegMaskedSet(&RAC->IFC, RAC_IFC_PAVHIGH_Msk);
	
}


void PA_PeakDetectorLowRun(void)

{
  RAC->IEN &= 0xfbffffff; //bit 26 PAVLOW
	BUS_RegMaskedClear(&RAC->IEN, RAC_IEN_PAVLOW_Msk);
  //_DAT_21000fc0 = peakDetectorOldSlices;
  SEQ->REG0C0 = peakDetectorOldSlices; //!!!!!!!
}



void PA_BatHighRun(void)

{
  if (!(SYNTH_Is2p4GHz()))
  {
    RAC->SGPACTRL0 &= 0x7fdfffff; //31, 17 CASCODEBYPASSEN, SLICE
  }
  else 
  {
    RAC->PACTRL0 &= 0x7fdfffff; //
  }
  RAC->IEN &= 0xf7ffffff; //27 PABATHIGH
}



uint32_t PA_RampTimeGet(void)

{
  return gPaConfig.rt;
}



void PA_RampConfigSet(uint32_t level,  uint16_t rate)

{
	MODEM->RAMPLEV = level;
	BUS_RegMaskedClear(&MODEM->RAMPCTRL, MODEM_RAMPCTRL_RAMPRATE0_Msk | MODEM_RAMPCTRL_RAMPRATE1_Msk | MODEM_RAMPCTRL_RAMPRATE2_Msk);
	BUS_RegMaskedSet(&MODEM->RAMPCTRL, rate);
}



int32_t PA_RampTimeCalc(void)

{

//  return (int)((MODEM_RAMPLEV_RAMPLEV2) - MODEM_RAMPLEV_RAMPLEV1 << (MODEM_RAMPCTRL_RAMPRATE2) >> 5) 
//	       +
//         (int)(MODEM_RAMPLEV_RAMPLEV1 - (MODEM_RAMPLEV_RAMPLEV0) << (MODEM_RAMPCTRL_RAMPRATE1) >> 5) 
//         +
//         (int)((MODEM_RAMPLEV_RAMPLEV0 << MODEM_RAMPCTRL_RAMPRATE0) >> 5);
				 
				 return ((MODEM_RAMPLEV_RAMPLEV2 - MODEM_RAMPLEV_RAMPLEV1) << MODEM_RAMPCTRL_RAMPRATE2) / 32 
	       +
         ((MODEM_RAMPLEV_RAMPLEV1 - MODEM_RAMPLEV_RAMPLEV0) << MODEM_RAMPCTRL_RAMPRATE1) / 32
         +
         (MODEM_RAMPLEV_RAMPLEV0 << MODEM_RAMPCTRL_RAMPRATE0) / 32;
}
				 
				 
				 
				 

uint16_t PA_RampTimeSet(uint16_t ramptime)
{
  uint32_t uVar1;
  int iVar2;
  char cVar3;
  uint32_t uVar4;
  int local_18;
  int local_14;
  
  //uVar4 = MODEM->CTRL0;
  //gCurrentModulation = (uint8_t)((uVar4 << 0x17) >> 0x1d);
	
	//gCurrentModulation = (uint8_t)((MODEM->CTRL0 & MODEM_CTRL0_MODFORMAT_Msk) >> MODEM_CTRL0_MODFORMAT_Pos);
	
  uVar4 = ((MODEM->CTRL0 & MODEM_CTRL0_MODFORMAT_Msk) >> MODEM_CTRL0_MODFORMAT_Pos) - 2 & 0xff;

  if ((uVar4 < 5) && ((1 << uVar4 & 0x13U) != 0)) uVar4 = 0;

  else 
	{
    if (gPaConfig.pasel == PA_SEL_SUBGIG) uVar4 = 0x96;
    else 
		{
      if (gPaConfig.pasel == PA_SEL_2P4_LP) uVar4 = 0x32;
      else uVar4 = 0xb4;
    }
  }
  //gDesiredRampTime = ramptime;
  local_18 = ramptime;
  uVar1 = SystemHFXOClockGet();
  cVar3 = -1;
  for (uVar1 = (((uVar1 / 1000) * ramptime) / uVar4 << 5) / 1000; uVar1 != 0; uVar1 = uVar1 >> 1) cVar3 ++;

  local_18 = (int32_t)cVar3;
  if (local_18 < 0x10) 
	{
    if (local_18 < 0) local_18 = 0; 
  }
  else local_18 = 0xf;
  local_18 = local_18 << 8;
  local_14 = uVar4 << 0x10;
  //PA_RampConfigSet(&local_18);
	//PA_RampConfigSet(local_18, local_14); //????
	PA_RampConfigSet(local_14, local_18);
  //iVar2 = PA_RampTimeCalc();
  gPaConfig.rt = (uint16_t)((uint32_t)(PA_RampTimeCalc() * 10000) / (SystemHFXOClockGet() / 100));
  //TIMING_RecalculateAll();
  return gPaConfig.rt;
}





void PA_CTuneSet(uint8_t txPaCtuneValue, uint8_t rxPaCtuneValue)

{
  SEQ->REG0C4 = rxPaCtuneValue & 7 | (rxPaCtuneValue & 0x1f) << 4;
  SEQ->REG0C8 = txPaCtuneValue & 7 | (txPaCtuneValue & 0x1f) << 4;
}


void PA_BandSelect(void) //in fact it's PA_Ctune setting. Not needed in case of custom PA_Ctune values.

{
    switch(SYNTH_LoDivGet()) 
			{
			case 1: //2300...2900 MHz
			{
      if (gPaConfig.pasel != PA_SEL_2P4_LP) 
			{
        SEQ->REG0C8 = 0;
				SEQ->REG0C4 = 0;
				break;
      }
			else
			{
				SEQ->REG0C8 = 0x44;
				SEQ->REG0C4 = 0x44;
				break;	
			}
			}
          	
			case 3: //770...960 MHz
			case 4: //575...725 MHz
      SEQ->REG0C4 = 0;
      SEQ->REG0C8 = 0;
      break;
			
			case 5: //460...580
			case 6: //390...480
    	SEQ->REG0C4 = 0x33;
    	SEQ->REG0C8 = 0x33;
		
			default: //unknown band
			SEQ->REG0C8 = 0xf7;
			SEQ->REG0C4 = 0xa2;
			break;
    }
}


bool     RADIO_PA_Init(RADIO_PAInit_t * paInit) //power config structure

{
  uint32_t uVar1;
  bool papresent;
  
  if (paInit != NULL)
	{
   // RADIO_CLKEnable();
   // memset((void*)SEQ->REG0C0,0,0xc);
//check PA presence (skipped)
    if (paInit->paSel == PA_SEL_SUBGIG) 
		{
      //uVar1 = read_volatile_4(DAT_400e4188);
      //bVar2 = (DAT_400e4188 & 0x200000) == 0;
      papresent = (*(uint32_t*)0x400e4188 & 0x200000) == 0;
    }
    else 
		{
      if (paInit->paSel == PA_SEL_2P4_LP) 
			{
        //uVar1 = read_volatile_4(DAT_400e4188);
				//uVar1 = *(uint32_t*)(0x400e4188);
        papresent = (*(uint32_t*)0x400e4188 & 0xc00000) == 0;
      }
      else 
			{
        //uVar1 = read_volatile_4(DAT_400e4188);
        papresent = (*(uint32_t*)0x0fe081d4 & 1 ^ 1 | *(uint32_t*)0x400e4188 & 0x400000) == 0; //check 2G4 HP PA presence
      }
    }
    if (papresent) //PA exist
    {
			gPaConfig.pasel = paInit->paSel;
			gPaConfig.vm = paInit->voltMode;
			gPaConfig.rt = paInit->rampTime;
			gPaConfig.pwr = paInit->power;
			PA_RampTimeSet(gPaConfig.rt);
      PA_PowerModeConfigSet();
			//PA_OutputPowerSet(gPaConfig.pwr);
      //RAC->APC &= 0xfffffff8;
			BUS_RegMaskedClear(&RAC->APC, RAC_APC_ENAPCSW_Msk  | RAC_APC_ENPASTATUSPKDVTH_Msk | RAC_APC_ENPASTATUSVDDPA_Msk);
      //PA_BandSelect(); not needed. PA_Ctune will be set separately
      return true;
    }
  }
  return false; //PA not present
}


