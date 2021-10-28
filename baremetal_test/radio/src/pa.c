#include "pa.h"
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include "em_bus.h"
#include "em_assert.h"
#include "synth.h"
#include "radio.h"
//#include "radio_cmu.h"


#define MODEM_RAMPLEV0 (MODEM->RAMPLEV & MODEM_RAMPLEV_RAMPLEV0_Msk) >> MODEM_RAMPLEV_RAMPLEV0_Pos
#define MODEM_RAMPLEV1 (MODEM->RAMPLEV & MODEM_RAMPLEV_RAMPLEV1_Msk) >> MODEM_RAMPLEV_RAMPLEV1_Pos
#define MODEM_RAMPLEV2 (MODEM->RAMPLEV & MODEM_RAMPLEV_RAMPLEV2_Msk) >> MODEM_RAMPLEV_RAMPLEV2_Pos

#define MODEM_RAMPRATE0 (MODEM->RAMPCTRL & MODEM_RAMPCTRL_RAMPRATE0_Msk) >> MODEM_RAMPCTRL_RAMPRATE0_Pos
#define MODEM_RAMPRATE1 (MODEM->RAMPCTRL & MODEM_RAMPCTRL_RAMPRATE1_Msk) >> MODEM_RAMPCTRL_RAMPRATE1_Pos
#define MODEM_RAMPRATE2 (MODEM->RAMPCTRL & MODEM_RAMPCTRL_RAMPRATE2_Msk) >> MODEM_RAMPCTRL_RAMPRATE2_Pos

bool apcEnabled = false;
struct
{
	uint8_t pasel;
	uint8_t vm;
	int32_t pwr;
	int32_t offs;
	uint16_t rt;
	
}gPaConfig;

	uint8_t PA_Powerlevel;
	
	uint32_t bootstrap = 0;
	uint32_t cascode = 0;
	uint32_t slice = 1;
	uint32_t stripe = 1;
	uint32_t peakDetectorOldSlices;



void PA_CalcRegValues (uint8_t level);

void PA_SetPowerLevel(uint8_t level)
{
	if(level == 0) level = 1;
	if(level > 248) level = 248;
	PA_CalcRegValues(level);
	SEQ->REG0C0 &= 0xe0c03fff;
  //SEQ->REG0C0 |= 0x3fc8 | (stripe << 0x18) | (slice  << 0xe);
	SEQ->REG0C0 |= (bootstrap << 3) | (cascode << 6) | (stripe << 0x18) | (slice  << 0xe);
	//apcConfigure(200);
}

void PA_CalcRegValues (uint8_t level)
{
	if(level > 201) bootstrap = 1;
	else bootstrap = 0;
	if (level <= 31)
	{
		cascode = 1;
		slice = 1;
		stripe = level;
		return;
	}
	
	if ((level > 31) && (level < 63))
	{
		cascode = 3;
		slice = 3;
		stripe = level - 31;
		return;
	}	

	if ((level > 62) && (level < 94))
	{
		cascode = 7;
		slice = 7;
		stripe = level - 62;
		return;
	}

	if ((level > 93) && (level < 125))
	{
		cascode = 15;
		slice = 15;
		stripe = level - 93;
		return;
	}	
	
	if ((level > 124) && (level < 156))
	{
		cascode = 31;
		slice = 31;
		stripe = level - 124;
		return;
	}
	
	if ((level > 155) && (level < 187))
	{
		cascode = 63;
		slice = 63;
		stripe = level - 155;
		return;
	}
	
	if ((level > 186) && (level < 218))
	{
		if(level < 202) cascode = 127;
		else cascode = 255;
		slice = 127;
		stripe = level - 186;
		return;
	}
	//if ((level > 217) 
    cascode = 255;
		slice = 255;
		stripe = level - 217;
}

void apcConfigure(int32_t p)

{
  if ((apcEnabled == false) || (p < 0x79)) RAC->SR3 &= ~8;
  else 
  {
		BUS_RegMaskedClear(&RAC->SGPAPKDCTRL, RAC_SGPAPKDCTRL_CAPSEL_Msk | RAC_SGPAPKDCTRL_VTHSEL_Msk | RAC_SGPAPKDCTRL_PKDEN_Msk);
    RAC->SGPAPKDCTRL |= 0xd700;
    RAC->SR3 |= 8;
  }
}

void PA_APCEnable(void)

{
  apcEnabled = 1;
	apcConfigure(gPaConfig.pwr);
}



void PA_APCDisable(void)

{
  apcEnabled = 0;
	apcConfigure(gPaConfig.pwr);
}

void PA_PeakDetectorHighRun(void)

{
 uint32_t uVar3;
  
  uVar3 = SEQ->REG0C0 >> 1 & 0x1fc000; //??? slice decrement;

		BUS_RegMaskedClear(&RAC->SGPACTRL0, 0xffc0); //14...21 SLICE
		BUS_RegMaskedSet(&RAC->SGPACTRL0, uVar3);
  //RAC->IFC = 0x2000000; //25
	  BUS_RegMaskedSet(&RAC->IFC, RAC_IFC_PAVHIGH_Msk);
}


void PA_PeakDetectorLowRun(void)

{
  RAC->IEN &= 0xfbffffff; //bit 26 PAVLOW
	BUS_RegMaskedClear(&RAC->IEN, RAC_IEN_PAVLOW_Msk);
  //SEQ->REG0C0 = peakDetectorOldSlices; //!!!!!!!
}

void PA_BatHighRun(void)

{
  RAC->SGPACTRL0 &= 0x7fdfffff; //31, 17 CASCODEBYPASSEN, SLICE
  RAC->IEN &= 0xf7ffffff; //27 PABATHIGH
}

int32_t PA_OutputPowerGet(void)

{
	return gPaConfig.pwr;
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




int PA_RampTimeCalc(void)

{
  return (((MODEM_RAMPLEV2 - MODEM_RAMPLEV1) << MODEM_RAMPRATE2)/32) + (((MODEM_RAMPLEV1 - MODEM_RAMPLEV0) << MODEM_RAMPRATE1)/32) + ((MODEM_RAMPLEV0 << MODEM_RAMPRATE0)/32);
}
				 
		 

uint16_t PA_RampTimeSet(uint16_t ramptime)
{
  uint32_t uVar1;
  char cVar3;
  uint32_t uVar4;
  int local_18;
  int local_14;
  
	//gCurrentModulation = (uint8_t)((MODEM->CTRL0 & MODEM_CTRL0_MODFORMAT_Msk) >> MODEM_CTRL0_MODFORMAT_Pos);
  uVar4 = ((MODEM->CTRL0 & MODEM_CTRL0_MODFORMAT_Msk) >> MODEM_CTRL0_MODFORMAT_Pos) - 2 & 0xff;

  if ((uVar4 < 5) && ((1 << uVar4 & 0x13U) != 0)) uVar4 = 0;
  else uVar4 = 0x96;
  //gDesiredRampTime = ramptime;
  cVar3 = -1;
  for (uVar1 = (((SystemHFXOClockGet() / 1000) * ramptime) / uVar4 << 5) / 1000; uVar1 != 0; uVar1 >>= 1) cVar3 ++;
  local_18 = (int32_t)cVar3;
  if (local_18 >= 0x10) local_18 = 0xf;
  if (local_18 < 0) local_18 = 0; 
  local_18 <<= 8;
  local_14 = uVar4 << 0x10;
	PA_RampConfigSet(local_14, local_18);
  gPaConfig.rt = (uint16_t)((uint32_t)(PA_RampTimeCalc() * 10000) / (SystemHFXOClockGet() / 100));
  //TIMING_RecalculateAll();
  return gPaConfig.rt;
}

void PA_CTuneSet(uint8_t txPaCtuneValue, uint8_t rxPaCtuneValue)

{
  SEQ->REG0C4 = rxPaCtuneValue & 7 | (rxPaCtuneValue & 0x1f) << 4;
  SEQ->REG0C8 = txPaCtuneValue & 7 | (txPaCtuneValue & 0x1f) << 4;
}


bool RADIO_PA_Init(RADIO_PAInit_t * paInit) //power config structure

{
  if (paInit != NULL)
	{
			gPaConfig.pasel = paInit->paSel;
			gPaConfig.vm = paInit->voltMode;
			gPaConfig.rt = paInit->rampTime;
			gPaConfig.pwr = paInit->power;
			PA_RampTimeSet(gPaConfig.rt);
			BUS_RegMaskedClear(&RAC->SGPABIASCTRL1, RAC_SGPABIASCTRL1_VCASCODELV_Msk | RAC_SGPABIASCTRL1_VCASCODEHV_Msk); //8...10,12...14 - VCASCODEHV, VCASCODELV
			BUS_RegMaskedSet(&RAC->SGPABIASCTRL1, 0x4500); //8,10 VCASCODEHV 14 VCASCODELV
			BUS_RegMaskedSet(&RAC->SGPABIASCTRL0, RAC_SGPABIASCTRL0_LDOBIAS_Msk); //LDO on
			//PA_OutputPowerSet(gPaConfig.pwr);
      //RAC->APC &= 0xfffffff8;
			BUS_RegMaskedClear(&RAC->APC, RAC_APC_ENAPCSW_Msk  | RAC_APC_ENPASTATUSPKDVTH_Msk | RAC_APC_ENPASTATUSVDDPA_Msk);
      //PA_BandSelect(); not needed. PA_Ctune will be set separately
      return true;
  }
  return false; //PA not present
}


