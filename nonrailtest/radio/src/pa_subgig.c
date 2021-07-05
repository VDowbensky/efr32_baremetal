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
	uint32_t rt;
	
}gPaConfig;
	
void PA_StripesAndSlicesCalc(int32_t pwr);




void apcConfigure(int32_t p)

{
  uint32_t uVar2;
  
  if ((apcEnabled == false) || (p < 0x79))
  {
    uVar2 = RAC->SR3 & 0xfffffff7;
  }
  else 
  {
    RAC->PAPKDCTRL &= 0xffff2082;
    RAC->SGPAPKDCTRL &= 0xffff2082;
    uVar2 = RAC->PAPKDCTRL;
    RAC->PAPKDCTRL |= 0xd700 | ((p - 0x93U) / 5 + 9) * 4;
    RAC->SGPAPKDCTRL |= uVar2 | 0xd700;
    uVar2 = RAC->SR3 | 8;
  }
  RAC->SR3 = uVar2;
  return;
}



int32_t PA_OutputPowerGet(void)

{
  //return (int16_t)gPaConfig._2_2_;
	return gPaConfig.pwr;
}



void PA_PowerOffsetSet(int16_t offset)

{
  //gPaConfig._4_2_ = offset;
	gPaConfig.offs = offset;
  return;
}



void PA_20dbmConfigSet(void)

{
  RAC->PACTRL0 &= 0xfffffff9;
  RAC->PACTRL0 |= 4;
  RAC->PABIASCTRL1 &= 0xfffffff8;
  RAC->PABIASCTRL1 |= 5;
  RAC->PABIASCTRL0 &= 0xffffff3f;
  RAC->PABIASCTRL0 |= 0x81;
}



void PA_0dbmConfigSet(void)

{
  RAC->PACTRL0 &= 0xfffffff9;
  RAC->PACTRL0 |= 2;
  RAC->PABIASCTRL1 &= 0xfffffff8;
  RAC->PABIASCTRL1 |= 6;
  RAC->PABIASCTRL0 &= 0xffbfff3e;
  RAC->PAPKDCTRL &= 0xffff3fff;
}



void PA_SubGhz20dbmConfigSet(void)

{
  RAC->SGPABIASCTRL1 &= 0xffff88ff; //8...10,12...14 - VCASCODEHV, VCASCODELV
  RAC->SGPABIASCTRL1 |= 0x4500; //8,10 VCASCODEHV 14 VCASCODELV
  RAC->SGPABIASCTRL0 |= 1; //LDOBIAS on
}



void PA_PowerModeConfigSet(void)

{
	  if (gPaConfig.pasel == PA_SEL_SUBGIG)
  {
    PA_SubGhz20dbmConfigSet();
    return;
  }
  if (gPaConfig.pasel == PA_SEL_2P4_LP)
  {
    PA_0dbmConfigSet();
    return;
  }
  PA_20dbmConfigSet();
}





uint32_t PA_StripesAndSlicesSet(uint32_t param_1)

{
  uint32_t uVar1;
  uint32_t uVar2;
  int32_t iVar3;
  uint32_t uVar4;
  
  uVar4 = *(uint32_t*) 0x400e4188; // DAT_400e4188; //CMU reg 188
  uVar2 = (param_1 << 0x17) >> 0x1c; //>>5 bits, most 17 bits cleared

//  iVar3 = count_leading_zeroes(~uVar4 & 0x1fc000);
  uVar4 = 0x13 - iVar3;
  if (uVar4 < uVar2)
  {
    if (uVar4 != 0)
    {
      uVar1 = 0x1f;
      uVar2 = uVar4;
      goto LAB_000101c0;
    }
  }
  else
  {
    if (uVar2 != 0)
    {
      uVar1 = param_1 & 0x1f;
      if (uVar1 == 0)
      {
        uVar1 = 1;
      }
      goto LAB_000101c0;
    }
  }
  uVar1 = 1;
  uVar2 = uVar1;
LAB_000101c0:
  //_DAT_21000fc0 = _DAT_21000fc0 & 0xe0c03fff | 0x3fc8 | uVar1 << 0x18 | ((1 << (uVar2 & 0xff)) - 1U & 0xff) << 0xe;
  SEQ->REG0C0 = SEQ->REG0C0 & 0xe0c03fff | 0x3fc8 | uVar1 << 0x18 | ((1 << (uVar2 & 0xff)) - 1U & 0xff) << 0xe;
  uVar1 = uVar1 | uVar2 << 5;
  if ((param_1 & 0x8000) == 0) 
  {
    RAC->PABIASCTRL0 &= 0xffbfffff; //TXPOWER off
    return uVar1;
  }
  RAC->PABIASCTRL0 |= 0x400000; //TXPOWER on
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
      if (pwr == 0)
      {
        pwr = 1;
      }
    }
    else
    {
      pwr = 7;
    }
    //_DAT_21000fc0 = _DAT_21000fc0 & 0xe0c0003f | param_1 << 0x18;
    SEQ->REG0C0 = SEQ->REG0C0 & 0xe0c0003f | pwr << 0x18;
    return pwr & 0xffff;
  }
  if (pwr < 0xf9)
  {
    if (pwr == 0) goto LAB_00010240;
  }
  else
  {
    pwr = 0xf8;
  }
  pwr = pwr - 1 & 0xff;
LAB_00010240:
  uVar1 = pwr % 0x1f + 1 | ((pwr / 0x1f & 0xff) + 1) * 0x20;
  if (pwr != 0)
  {
    uVar1 = uVar1 | 0x8000;
  }
  uVar1 = PA_StripesAndSlicesSet(uVar1);
  if ((uVar1 & 0x8000) == 0)
  {
    uVar2 = 0;
  }
  else
  {
    uVar2 = 0x100;
  }
  apcConfigure(200);
  return (uVar1 & 0x1f) + (((uVar1 & 0xffff7fe0) - ((uVar1 & 0xffff7fff) >> 5)) - 0x1f & 0xffff | uVar2) & 0xffff;
}



uint32_t PA_StripesAndSlicesCommonCalc(int param_1,int16_t *param_2)

{
  int iVar1;
  uint32_t uVar2;
  
  if (*param_2 <= param_1) //max power, *0.1 dBm
  {
    param_1 = (int)*param_2;
  }
  iVar1 = -((param_1 - 200U) / 0x28);
  if (6 < iVar1)
  {
    iVar1 = 7;
  }
  uVar2 = param_1 * (param_2 + iVar1 * 4)[3] + *(int *)(param_2 + iVar1 * 4 + 4);
  if (0 < param_1)
  {
    uVar2 = uVar2 + 500;
  }
  uVar2 = uVar2 / 1000;
  if ((iVar1 != 7) && (gPaConfig.pasel != PA_SEL_SUBGIG))
  {
    uVar2 = uVar2 | 0x8000;
  }
  return uVar2;
}



uint32_t PA_PowerFromStripesAndSlicesCommonCalc(uint32_t param_1,int32_t param_2)

{
  uint32_t uVar1;
  int32_t iVar2;
  
  iVar2 = 1;
  do
  {
    if (*(uint16_t *)(param_2 + iVar2 * 8) < param_1) break;
    iVar2 = iVar2 + 1;
  } while (iVar2 != 8);
  param_2 = param_2 + (iVar2 + -1) * 8;
  uVar1 = (param_1 & 0xffff7fff) * 1000 - *(int *)(param_2 + 4);
  if (0 < (int32_t)uVar1)
  {
    uVar1 = uVar1 + 500;
  }
  return uVar1 / (uint32_t)(int32_t)*(int16_t *)(param_2 + 2);
}




void PA_PowerLevelOptimize(int32_t p)

{
  if (p < 0x83)
  {
    //_DAT_21000fc0 = _DAT_21000fc0 & 0xffffc037 | ((_DAT_21000fc0 << 10) >> 0x18) << 6;
	  SEQ->REG0C0 = SEQ->REG0C0 & 0xffffc037 | ((SEQ->REG0C0 << 10) >> 0x18) << 6;
    if (p < 0x1f)
	  {
      RAC->SGPABIASCTRL0 &= 0xfffffffe;
      apcConfigure(p);
	  return;
    }
  }
  else 
  {
    //_DAT_21000fc0 = _DAT_21000fc0 & 0xffffc037 | 0x3fc8;
    SEQ->REG0C0 = (SEQ->REG0C0 & 0xffffc037) | 0x3fc8;
  }
  RAC->SGPABIASCTRL0 |= 1;
//LAB_0001037a:
  apcConfigure(p);
  return;
}



//void PA_StripesAndSlicesCalc(int32_t param_1,uint32_t param_2,uint32_t param_3,uint32_t param_4)
void PA_StripesAndSlicesCalc(int32_t pwr)

{
  int32_t iVar1;
  int32_t iVar2;
  uint32_t uVar3;
  
  if (gPaConfig.pasel == PA_SEL_2P4_LP)
  {
    iVar1 = 6;
    do
    {
      //if ((int)*(uint16_t *)(&power0dBmParams + iVar1 * 2) <= param_1 + gPaConfig._4_2_) break; //!!!!!!
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    //iVar2 = (int)*(uint16_t *)(&power0dBmParams + iVar1 * 2); //!!!!!!
    SEQ->REG0C0 = SEQ->REG0C0 & 0xe0c0003f | (iVar1 + 1) * 0x1000000;
  }
  else
  {
    //uVar3 = (uint)gPaConfig._1_1_; //!!!!!!
    if (gPaConfig.pasel != PA_SEL_2P4_HP)
    {
      uVar3 = uVar3 + 2;
    }
    iVar2 = uVar3 * 0x44;
    //PA_StripesAndSlicesCommonCalc(param_1 + gPaConfig._4_2_,&paParams + iVar2,&paParams,uVar3,param_4); //!!!!!!
    //iVar1 = PA_StripesAndSlicesSet(); //!!!!!!
    if (iVar1 == 0x21)
    {
      //iVar2 = (int)*(short *)(&DAT_00010726 + iVar2); //!!!!!!
    }
    else
    {
      //iVar2 = PA_PowerFromStripesAndSlicesCommonCalc(iVar1,&UNK_00010728 + iVar2); //!!!!!!
    }
  }
  PA_PowerLevelOptimize(iVar2);
  //peakDetectorOldSlices = SEQ->REG0C0; //!!!!!!
  //gPaConfig._2_2_ = (short)iVar2 - gPaConfig._4_2_; //!!!!!!
	gPaConfig.pwr = (int16_t)iVar2 - gPaConfig.offs;
  return;
}



int PA_OutputPowerSet(int32_t level)

{
  PA_StripesAndSlicesCalc(level); //!!!!!!
  return gPaConfig.pwr; //!!!!!!
}



int PA_MaxOutputPowerSet(void) //20 dBm

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
  return;
}



void PA_APCDisable(void)

{
  apcEnabled = 0;
  //apcConfigure((int)gPaConfig._2_2_); //!!!!!!
	apcConfigure(gPaConfig.pwr);
  return;
}


void PA_PeakDetectorHighRun(void)

{
  uint32_t uVar3;
  
  uVar3 = SEQ->REG0C0 >> 1 & 0x1fc000;

  //SEQ->REG0C0 >>= 1;
  //_DAT_21000fc0 = _DAT_21000fc0 & 0xffc03fff | uVar3;
  SEQ->REG0C0 |= 0xffc03fff;
  SEQ->REG0C0 &= uVar3;
  //iVar2 = SYNTH_Is2p4GHz();
  if (!(SYNTH_Is2p4GHz()))
  {
	RAC->SGPACTRL0 &= 0xffc03fff; //14...21 SLICE
	RAC->SGPACTRL0 |= uVar3; //
  }
  else 
  {
    RAC->PACTRL0 &= 0xffc03fff;
		RAC->PACTRL0 |= uVar3;
  }
  RAC->IFC = 0x2000000;
}


void PA_PeakDetectorLowRun(void)

{
  RAC->IEN &= 0xfbffffff; //bit 26 PAVLOW
  //_DAT_21000fc0 = peakDetectorOldSlices;
  //SEQ->REG0C0 = peakDetectorOldSlices; //!!!!!!!
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



void PA_RampConfigSet(uint32_t *param_1)

{
  MODEM->RAMPLEV = param_1[1];
  MODEM->RAMPCTRL &= 0xfffff000;
  MODEM->RAMPCTRL |= *param_1;
}



int32_t PA_RampTimeCalc(void)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  
  uVar4 = MODEM->RAMPLEV;
  uVar6 = MODEM->RAMPLEV;
  uVar5 = MODEM->RAMPLEV;
  uVar1 = MODEM->RAMPCTRL;
  uVar2 = MODEM->RAMPCTRL;
  uVar3 = MODEM->RAMPCTRL;
  uVar6 = (uVar6 << 0x10) >> 0x18;

 // return ((int32_t)(((uVar5 << 8) >> 0x18) - (uVar6 << ((uVar3 << 0x14) >> 0x1c)) >> 5)) +
 //        ((int32_t)((uVar6 - (uVar4 & 0xff)) << ((uVar2 << 0x18) >> 0x1c)) >> 5) +
 //        ((int32_t)((uVar4 & 0xff) << (uVar1 & 0xf)) >> 5);
  return(MODEM->RAMPLEV & 0x00ff0000) - (MODEM->RAMPLEV & 0x0000ff00) ; //maybe incorrect!
}



uint32_t PA_RampTimeSet(uint32_t ramptime)

{
  uint32_t uVar1;
  char cVar2;
  int32_t iVar3;
  uint32_t * local_18;
  int32_t local_14;
  
  if (gPaConfig.pasel == PA_SEL_SUBGIG) 
	{
    iVar3 = 0x96;
  }
  else 
		{
    if (gPaConfig.pasel == PA_SEL_2P4_LP) 
		{
      iVar3 = 0x32;
    }
    else 
		{
      iVar3 = 0xb4;
    }
  }
  if (ramptime != 0) 
		{
    *local_18 = ramptime;
   // local_14 = param_2;
    uVar1 = SystemHFXOClockGet();
    uVar1 = (uint32_t)(0x8000 / ((uint64_t)(uint32_t)(iVar3 * 0x9c4000) /
                            (uint64_t)(ramptime * (uVar1 / 100))));
    cVar2 = -1;
    while (uVar1 != 0) {
      cVar2 = cVar2 + '\x01';
      uVar1 = uVar1 >> 1;
    }
    *local_18 = (int32_t)cVar2;
    if (0xf < *local_18) 
		{
      *local_18 = 0xf;
      goto LAB_000105e4;
    }
    if (-1 < *local_18) goto LAB_000105e4;
  }
  *local_18 = 1;
LAB_000105e4:
  *local_18 = *local_18 << 8;
  local_14 = iVar3 << 0x10;
  PA_RampConfigSet(local_18);
  iVar3 = PA_RampTimeCalc();
  uVar1 = SystemHFXOClockGet();
  //gPaConfig._6_2_ = (undefined2)((ulonglong)(uint)(iVar3 * 10000) / ((ulonglong)uVar1 / 100));//!!!!!!!!!!!!!!!!!!!
	gPaConfig.rt = (uint16_t)((uint64_t)(uint32_t)(iVar3 * 10000) / ((uint64_t)uVar1 / 100));
  //return gPaConfig._6_2_;//!!!!!!!!!!!!!!!!!!!
  return gPaConfig.rt;
}


void     PA_CTuneSet(uint8_t txPaCtuneValue, uint8_t rxPaCtuneValue)

{
  //_DAT_21000fc4 = param_2 & 7 | (param_2 & 0x1f) << 4;
  SEQ->REG0C4 = rxPaCtuneValue & 7 | (rxPaCtuneValue & 0x1f) << 4;
  //_DAT_21000fc8 = param_1 & 7 | (param_1 & 0x1f) << 4;
  SEQ->REG0C8 = txPaCtuneValue & 7 | (txPaCtuneValue & 0x1f) << 4;
  return;
}


void PA_BandSelect(void)

{
  uint32_t uVar1;
  
  uVar1 = SYNTH_LoDivGet();
  if (false) 
	{
switchD_0001064e_caseD_2:
    //_DAT_21000fc8 = 0xf7;
    SEQ->REG0C8 = 0xf7;
    //_DAT_21000fc4 = 0xa2;
    SEQ->REG0C4 = 0xa2;
  }
  else 
		{
    switch(uVar1) 
			{
    case 1:
      //_DAT_21000fc4 = 0x44;
      SEQ->REG0C4 = 0x44;
      //_DAT_21000fc8 = _DAT_21000fc4;
      SEQ->REG0C8 = SEQ->REG0C4;
      if (gPaConfig.pasel != PA_SEL_2P4_LP) 
			{
        //_DAT_21000fc8 = 0;
        SEQ->REG0C8 = 0;
      }
      break;
    default:
      goto switchD_0001064e_caseD_2;
    case 3:
    case 4:
      //_DAT_21000fc4 = 0;
      SEQ->REG0C4 = 0;
      SEQ->REG0C8 = SEQ->REG0C4;
      break;
    case 5:
    case 6:
    	SEQ->REG0C4 = 0x33;
    	SEQ->REG0C8 = SEQ->REG0C4;
    }
  }
  return;
}


bool     RADIO_PA_Init(RADIO_PAInit_t * paInit) //power config structure

{
  uint32_t uVar1;
  bool bVar2;
  
  if (paInit != NULL)
	{
    RADIO_CLKEnable();
    //memset(&DAT_21000fc0,0,0xc);
    memset((void*)SEQ->REG0C0,0,0xc);
    if (paInit->paSel == PA_SEL_SUBGIG) 
		{
      //uVar1 = read_volatile_4(DAT_400e4188);
      //bVar2 = (DAT_400e4188 & 0x200000) == 0;
      bVar2 = (*(uint32_t*)0x400e4188 & 0x200000) == 0;
    }
    else 
		{
      if (paInit->paSel == PA_SEL_2P4_LP) 
			{
        //uVar1 = read_volatile_4(DAT_400e4188);
				//uVar1 = *(uint32_t*)(0x400e4188);
        bVar2 = (*(uint32_t*)0x400e4188 & 0xc00000) == 0;
      }
      else 
			{
        //uVar1 = read_volatile_4(DAT_400e4188);
        bVar2 = (*(uint32_t*)0x0fe081d4 & 1 ^ 1 | *(uint32_t*)0x400e4188 & 0x400000) == 0; //check 2G4 HP PA presence
      }
    }
    if (bVar2)
    {
     // gPaConfig._0_4_ = *param_1; //!!!!!!!!!!!!!!!!!!!!!!!!!!paInit->paSel
			gPaConfig.pasel = paInit->paSel;
     // gPaConfig._4_4_ = param_1[1]; //!!!!!!!!!!!!!!!!!!!!!!!!!!paInit->voltMode
			gPaConfig.vm = paInit->voltMode;
     // PA_RampTimeSet(*(undefined2 *)((int)param_1 + 6)); //!!!!!!!!!!!!!!!!!!!!!!!!!!
//			PA_RampTimeSet(paInit->rampTime);
//			gPaConfig.rt = paInit->rampTime;
//			gPaConfig.pwr = paInit->power;
//			PA_RampTimeSet(gPaConfig.rt);
      //PA_PowerModeConfigSet();
			PA_SubGhz20dbmConfigSet();
      //PA_OutputPowerSet((int)*(short *)((int)paInit + 2));
			PA_OutputPowerSet(paInit->power);
			//PA_OutputPowerSet(gPaConfig.pwr);
      RAC->APC &= 0xfffffff8;
      PA_BandSelect();
      return 1;
    }
  }
  return 0;
}


