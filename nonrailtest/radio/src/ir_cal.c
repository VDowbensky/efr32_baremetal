#include "ir_cal.h"
#include <stdbool.h>
#include <stddef.h>
#include "em_bus.h"
#include "em_assert.h"
#include "radio.h"
#include "aux_pll.h"
#include "synth.h"
#include "phy_utils.h"
#include "protimer.h"

uint32_t reg_save[24] = {};
uint8_t rcIrCalData[] = {};
uint8_t globalCalType;


uint8_t IRCAL_Configure(uint8_t type)

{
  char cVar1;
  
  switch(type)
  {
  case 0:
    cVar1 = rcIrCalData[8];
    if (rcIrCalData[8] == '\x01')
    {
      if (rcIrCalData[5] == '\0')
      {
        return 0;
      }
    }
    else
    {
      if (rcIrCalData[8] == '\x02')
      {
        if (rcIrCalData[6] == '\0')
        {
          return 0;
        }
      }
      else {
        if (rcIrCalData[8] != '\x03')
        {
          return 0;
        }
        if (rcIrCalData[7] == '\0')
        {
          return 0;
        }
      }
    }
    break;
  case 1:
    if (rcIrCalData[5] == '\0')
    {
      return 0;
    }
    cVar1 = '\x01';
    break;
  case 2:
    if (rcIrCalData[6] == '\0')
    {
      return 0;
    }
    cVar1 = '\x02';
    break;
  case 3:
    if (rcIrCalData[7] == '\0')
    {
      return 0;
    }
    cVar1 = '\x03';
    break;
  default:
    return 0;
  }
  globalCalType = cVar1;
  return 1;
}



void IRCAL_SetGlobalCalType(uint8_t type)

{
  globalCalType = type;
  return;
}



uint8_t IRCAL_GetGlobalCalType(void)

{
  IRCAL_Configure(globalCalType);
  return globalCalType;
}



void IRCAL_Set(uint32_t pgacal)

{
  if (pgacal != 0xffffffff)
  {
    RAC->IFPGACAL &= 0xffff0000;
    RAC->IFPGACAL |= pgacal & 0xffff;
  }
  return;
}

//typedef struct RAIL_CalInit {
//  RAIL_CalMask_t calEnable; /**< Mask that defines calibrations to perform in RAIL. */
//  const uint8_t *irCalSettings; /**< Pointer to image rejection calibration settings. */
//} RAIL_CalInit_t;

uint8_t IRCAL_Init(RAIL_CalInit_t *data)

{
 // if ((data->calEnable != 0) && (0xf < data->calEnable))
 // {
 //   rcIrCalData[5] = data[6];
 //   if (rcIrCalData[5] != 0)
 //   {
 //     rcIrCalData[5] = 1;
 //   }
 //   rcIrCalData[6] = data[7];
 //   if (rcIrCalData[6] != 0)
 //   {
 //     rcIrCalData[6] = 1;
 //   }
 //   rcIrCalData[7] = data[8];
 //   if (rcIrCalData[7] != 0)
 //   {
 //     rcIrCalData[7] = 1;
 //   }
 //   rcIrCalData[9] = data[10];
 //   if (rcIrCalData[9] != 0)
 //   {
 //     rcIrCalData[9] = 1;
 //   }
 //   rcIrCalData[0] = data[1];
 //   rcIrCalData[1] = data[2];
 //   rcIrCalData[2] = data[3];
 //   rcIrCalData[3] = data[4];
 //   rcIrCalData[4] = data[5];
 //   rcIrCalData[8] = data[9];
 //   rcIrCalData[10] = data[11];
 //   rcIrCalData[11] = data[12];
 //   rcIrCalData[12] = data[13];
 //   rcIrCalData[13] = data[14];
 //   rcIrCalData[14] = data[15];
 //   rcIrCalData[15] = data[16];
   // rcIrCalData._12_2_ = CONCAT11(data[14],data[13]);
   // rcIrCalData._14_2_ = *(undefined2 *)(data + 0xf);
 //   return 0;
 // }
 // IRCAL_Set(0);
  return 1;
}





void IRCAL_SaveRegStates(void)

{
  reg_save[0] = RAC->SGRFENCTRL0;
  reg_save[1] = RAC->RFENCTRL0;
  reg_save[2] = AGC->CTRL0;
  reg_save[3] = AGC->MANGAIN;
  reg_save[4] = AGC->GAINRANGE;
  reg_save[5] = AGC->GAININDEX;
  reg_save[6] = AGC->MININDEX;
  reg_save[7] = MODEM->MODINDEX;
  reg_save[8] = MODEM->CTRL0;
  reg_save[9] = FRC->DFLCTRL;
  reg_save[10] = RAC->SGPACTRL0;
  reg_save[11] = RAC->SGPAPKDCTRL;
  reg_save[12] = RAC->SGPABIASCTRL0;
  reg_save[13] = RAC->SGPABIASCTRL1;
  reg_save[14] = RAC->PACTUNECTRL;
  reg_save[15] = MODEM->RAMPCTRL;
  reg_save[16] = RAC->TESTCTRL;
  reg_save[17] = SYNTH_RfFreqGet();
  reg_save[18] = SYNTH_ChSpacingGet();
  FRC->CTRL |= 1;
  RAC->CTRL |= 0x40;
  return;
}

void IRCAL_Teardown(void)

{
  IRCAL_StopRx();
  AUXPLL_Stop();
  RAC->SGRFENCTRL0 = reg_save[0];
  RAC->RFENCTRL0 = reg_save[1];
  AGC->CTRL0 = reg_save[2];
  AGC->MANGAIN = reg_save[3];
  AGC->GAINRANGE = reg_save[4];
  AGC->GAININDEX = reg_save[5];
  AGC->MININDEX = reg_save[6];
  MODEM->MODINDEX = reg_save[7];
  MODEM->CTRL0 = reg_save[8];
  FRC->DFLCTRL = reg_save[9];
  RAC->SGPACTRL0 = reg_save[10];
  RAC->SGPAPKDCTRL = reg_save[11];
  RAC->SGPABIASCTRL0 = reg_save[12];
  RAC->SGPABIASCTRL1 = reg_save[13];
  RAC->PACTUNECTRL = reg_save[14];
  MODEM->RAMPCTRL = reg_save[15];
  RAC->TESTCTRL = reg_save[16];
  SYNTH_Config(reg_save[17],reg_save[18]);
  RADIO_RxBufferReset();

  FRC->CTRL &= 0xfffffffe; //RANDOMTX
  RAC->CTRL &= 0xffffffbf; //TXPOSTPONE
  return;
}


int32_t IRCAL_SetRxFrequency(uint32_t rxfreq)

{
  //uint uVar1;
  //int iVar2;
  int32_t iffreq;
  
  //iVar2 = SYNTH_IfFreqGet();
  //uVar1 = SYNTH->IFFREQ;
  //iVar3 = iVar2 * 2;
  iffreq = SYNTH_IfFreqGet() * 2;
  if (SYNTH->IFFREQ & 0x100000) //LOSIDE
  {
    //iVar3 = iVar2 * -2;
	  iffreq = SYNTH_IfFreqGet() * -2;
  }
  //iVar2 = SYNTH_VcoRangeIsValid(rxfreq + iffreq);
  //if (iVar2 == 0)
  if (SYNTH_VcoRangeIsValid(rxfreq + iffreq) == false)
  {
    //IRCAL_Set();]
	  IRCAL_Set(0);
    return -1;
  }
  SYNTH_Config(rxfreq + iffreq,0);
  return 0;
}




void IRCAL_StartRx(void)

{
  MODEM->CTRL0 |= 0x200000; //
  while (RAC->STATUS & 0xf000000); //keep RXENS, TXENS, DEMODENS, 28
  RADIO_RxBufferReset();
  //while ((RAC->STATUS << 4) >> 0x1c != 2);
  while(RAC->STATUS & 0x0f); //RXMASK
  //_DAT_4308000c = 1; //RXENSRCEN bit 3 - SWRXEN
  RAC->RXENSRCEN |= 0x08;
  return;
}



void IRCAL_StopRx(void)

{
  RAC->RXENSRCEN &= 0xffffff00;
  FRC->CMD = 1;
  while (RAC->STATUS & 0xf000000);
  return;
}



void IRCAL_SetSubGhzPllLoopback(void)

{
  AGC->MANGAIN &= 0x801001ff;
  AGC->MANGAIN |= 0x40009800;
  AGC->CTRL0 |= 0x400000;
  RAC->SGRFENCTRL0 |= 0x80000;
  RAC->RFENCTRL0 |= 0x80000;
}



void IRCAL_SetSubGhzPaLoopback(void)

{
  AGC->GAINRANGE &= 0xffffc000;
  AGC->GAINRANGE |= 0x383e;
  AGC->GAININDEX &= 0xfff00000;
  AGC->GAININDEX |= 0x25bc;
  AGC->MININDEX &= 0xff000000;
  AGC->MININDEX |= 0x6d8480;
  AGC->MANGAIN &= 0xffffff40;
  AGC->MANGAIN |= 0xa7;
  AGC->CTRL0 |= 0x400000;
  MODEM->MODINDEX = 0;
  MODEM->CTRL0 &= 0xfffffe3f;
  MODEM->CTRL0 |= 0x100;
  FRC->DFLCTRL &= 0xfffffff8;
  FRC->DFLCTRL |= 5;
  RAC->SGRFENCTRL0 &= 0xfff7ffff;
  RAC->SGPACTRL0 &= 0x3fffffff;
  RAC->SGPACTRL0 |= 0x40000000;
  RAC->SGPAPKDCTRL |= 0xc000;
  RAC->SGPABIASCTRL0 &= 0xff3ff332;
  RAC->SGPABIASCTRL0 |= 0x445;
  RAC->SGPABIASCTRL1 &= 0xffffffc8;
  RAC->SGPABIASCTRL1 |= 0x20;
  RAC->SGPABIASCTRL1 &= 0xfff388ff;
  RAC->SGPABIASCTRL1 |= 0x84500;
  RAC->PACTUNECTRL &= 0xfffffe0f;
  RAC->SGPACTRL0 |= 8;
  RAC->SGRFENCTRL0 |= 0x10000;
  PHY_UTILS_DelayUs(20);
  RAC->SGPACTRL0 &= 0xffffc03f;
  RAC->SGPACTRL0 |= 0x40;
  RAC->SGRFENCTRL0 |= 0x20000;
  PHY_UTILS_DelayUs(20);
  RAC->SGPACTRL0 &= 0xe0c03fff;
  RAC->SGPACTRL0 |= 0x1004000;
  PHY_UTILS_DelayUs(20);
  RAC->SGRFENCTRL0 |= 0x40000;
  PHY_UTILS_DelayUs(20);
  RAC->TESTCTRL |= 9;
  PHY_UTILS_DelayUs(20);
  RAC->SGPACTRL0 &= 0xe0c03fff;
  RAC->SGPACTRL0 |= 0x1004000;
  PHY_UTILS_DelayUs(20);
  MODEM->RAMPCTRL &= 0x7fffff;
  MODEM->RAMPCTRL |= 0x800000 | (uint32_t)rcIrCalData[2] << 0x18;
  PHY_UTILS_DelayUs(20);
  return;
}



int32_t IRCAL_Setup(int32_t param_1,uint32_t param_2,uint32_t param_3,uint32_t param_4)

{
  uint8_t uVar1;
  int32_t iVar2;
  
  IRCAL_SaveRegStates();
  uVar1 = rcIrCalData[3];
//  if (((param_1 == 2) || (uVar1 = rcIrCalData[4], param_1 == 3)) && (iVar2 = AUXPLL_Start(param_1,uVar1,rcIrCalData[0],rcIrCalData[1],param_4), iVar2 != -1)) //!!!!!!!!!!!!!!!!!!!!
  {
    IRCAL_StopRx();
    //iVar2 = IRCAL_SetRxFrequency(iVar2);
    //if (iVar2 != -1)
    if(IRCAL_SetRxFrequency(iVar2) != -1)
    {
      IRCAL_StartRx();
      if (param_1 == 2)
      {
        IRCAL_SetSubGhzPllLoopback();
      }
      else
      {
        if (param_1 != 3)
        {
          return -1;
        }
        IRCAL_SetSubGhzPaLoopback();
      }
      return 0;
    }
  }
  return -1;
}



uint32_t IRCAL_TranslateToRssiIndex(uint32_t param_1)

{
  if (param_1 < 0x40)
  {
    param_1 = 0x40 - param_1 & 0xff;
  }
  return param_1;
}



int16_t IRCAL_ReadRssi(uint32_t param_1,uint32_t param_2,uint32_t param_3,uint32_t param_4,uint16_t param_5) //some structure

{
  //uint32_t uVar1;
  int16_t sVar2;
  int32_t iVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  
  if ((param_1 & 0x80) != 0)
  {
    param_1 = 0x7f;
  }
  if ((param_2 & 0x80) != 0)
  {
    param_2 = 0x7f;
  }
  if (param_3 < 0x10)
  {
    //uVar4 = read_volatile_4(RAC->IFPGACAL);
    //write_volatile_4(RAC->IFPGACAL,(uVar4 & 0xffff8080_ | param_1 << 8 | param_2);
    RAC->IFPGACAL &= 0xffff8080;
    RAC->IFPGACAL |= (param_1 << 8 | param_2);
    PHY_UTILS_DelayUs(param_4);
    uVar5 = (uint32_t)(rcIrCalData[9]);
    uVar4 = uVar5;
    uVar6 = uVar5;
    if (uVar5 == 0) 
		{
      //while (_DAT_430e0714 = 1, uVar6 >> (param_3 & 0xff) == 0) //!!!!!!!!!!!!!!!!!!!!!!!!!7038 bit 5 - gainindex
     // while ((AGC->STATUS0 & 0x20), (uVar6 >> (param_3 & 0xff) == 0))
			while (AGC->STATUS0 & 0x20)
      {
        //write_volatile_4(AGC->CMD,1);
        AGC->CMD = 1;
        //do {
        //  uVar1 = read_volatile_4(AGC->IF);
        //} while (-1 < (int)(uVar1 << 0x1a));
        while(AGC->IF & 0x00200000);
        if (rcIrCalData[11] <= uVar6)
        {
          iVar3 = RADIO_GetRSSI();
          uVar4 = uVar4 + 1;
          uVar5 = uVar5 + iVar3;
        }
        uVar6++;
      }
    }
    else
    {
      uVar6 = 0;
      uVar4 = 0;
      uVar5 = 0;
      while (uVar6 >> (param_3 & 0xff) == 0)
      {
        PHY_UTILS_DelayUs(param_5);
        if (rcIrCalData[11] <= uVar6)
        {
          iVar3 = RADIO_GetRSSI();
          uVar4 = uVar4 + 1;
          uVar5 = uVar5 + iVar3;
        }
        uVar6 = uVar6 + 1;
      }
    }
    if (uVar4 == 0) uVar4 = 1;
    sVar2 = (short)(uVar5 / uVar4);
  }
  else sVar2 = -1;
  return (int16_t)sVar2;
}



uint32_t IRCAL_SearchLinear2Stage(uint32_t param_1,int32_t param_2,uint32_t param_3,uint32_t param_4,uint16_t param_5)

{
  int16_t sVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  int16_t sVar5;
  uint32_t uVar6;
  uint32_t uVar7;
  uint32_t uVar8;
  
  uVar8 = 0;
  sVar5 = 0x7fff;
  uVar6 = 5;
  do
  {
    uVar3 = 0x40 - uVar6 & 0xff;
    do
    {
      uVar7 = param_1;
      if (param_2 != 0)
      {
        uVar7 = uVar3;
        uVar3 = param_1;
      }
      sVar1 = IRCAL_ReadRssi(uVar7,uVar3,param_3,param_4,param_5);
      uVar3 = uVar6 + 10 & 0xff;
      if (sVar1 < sVar5)
      {
        uVar8 = uVar6;
        sVar5 = sVar1;
      }
      if (uVar3 == 0x87)
      {
        uVar3 = uVar8 - 5;
        uVar7 = 0x45 - uVar8;
        uVar6 = 0;
        sVar5 = 0x7fff;
        while( true )
        {
          uVar3 = uVar3 & 0xff;
          if ((uVar8 + 5 < uVar3) || ((int)(uVar3 << 0x18) < 0)) break;
          if (uVar3 != 0)
          {
            uVar4 = uVar3;
            if (uVar3 < 0x40)
            {
              uVar4 = uVar7 & 0xff;
            }
            uVar2 = param_1;
            if (param_2 != 0)
            {
              uVar2 = uVar4;
              uVar4 = param_1;
            }
            sVar1 = IRCAL_ReadRssi(uVar2,uVar4,param_3,param_4,param_5);
            if (sVar1 < sVar5)
            {
              uVar6 = uVar3;
              sVar5 = sVar1;
            }
          }
          uVar3 = uVar3 + 1;
          uVar7 = (uVar7 & 0xff) - 1;
        }
        if (uVar6 < 0x40)
        {
          uVar6 = 0x40 - uVar6 & 0xff;
        }
        return uVar6;
      }
      uVar6 = uVar3;
    } while (0x3f < uVar3);
  } while( true );
}



uint32_t IRCAL_Search(int32_t param_1,uint32_t param_2,uint32_t param_3,uint32_t param_4)

{
  uint32_t uVar1;
  uint32_t uVar2;
  int iVar3;
  
  if (param_1 == 2)
  {
    uVar1 = IRCAL_SearchLinear2Stage(0,1,param_2,param_3,param_4);
    uVar2 = IRCAL_SearchLinear2Stage(uVar1,0,param_2,param_3,param_4);
    iVar3 = IRCAL_SearchLinear2Stage(uVar2,1,param_2,param_3,param_4);
    uVar2 = uVar2 | iVar3 << 8;
  }
  else
  {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}








uint16_t IRCAL_Get(void)

{
  return RAC->IFPGACAL & 0xffff;
}



uint16_t IRCAL_GetDiValue(void)

{
  uint32_t uVar1;
  uint32_t puVar2;
  
  uVar1 = SYNTH_RfFreqGet();
  if (uVar1 == 0)
  {
    uVar1 = 0xffffffff;
  }
  else
  {
    if (uVar1 < 1000000000)
    {
      //puVar2 = *(uint32_t *)0x0fe081c8; //DEVINFO reg 018
			puVar2 = DEVINFO->RESERVED0[3];
    }
    else
    {
      //uVar1 = read_volatile_4(MODEM->CTRL0);
      //if ((MODEM->CTRL0 << 0x17) >> 0x1d == 4)
      if((MODEM->CTRL0 & 0x7) == 4)
      {
       // puVar2 = (uint *)0xfe081c4; //!!!!!!!!!!!!!!!!!!
      }
      else
      {
       // puVar2 = (uint *)0xfe081c0; //!!!!!!!!!!!!!!!!!!
      }
    }
    uVar1 = puVar2;
    if (uVar1 != 0xffffffff)
    {
      return uVar1 & 0xffff;
    }
  }
  return uVar1;
}



uint32_t IRCAL_PerformSubfunction(uint32_t param_1,uint32_t param_2,uint32_t param_3,uint32_t param_4,uint16_t param_5)

{
  int iVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  bool bVar4;
  uint64_t lVar5;
  uint64_t lVar6;
  uint64_t uVar7;
  
  uVar2 = PROTIMER->WRAPCNT;
  lVar5 = PROTIMER_PrecntOverflowToUs(uVar2);
  if (param_1 == 1)
  {
    uVar2 = IRCAL_GetDiValue();
    RADIO_RxBufferReset();
  }
  else
  {
    if ((param_1 == 0) || (3 < param_1))
    {
      uVar2 = 0xffffffff;
    }
    else
    {
     // uVar2 = IRCAL_Setup(param_1); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
      if (uVar2 != 0xffffffff)
      {
        uVar2 = IRCAL_Search(param_2,param_3,param_4,param_5);
      }
      IRCAL_Teardown();
    }
  }
  uVar3 = PROTIMER->WRAPCNT;
  lVar6 = PROTIMER_PrecntOverflowToUs(uVar3);
//  uVar7 = __aeabi_uldivmod((int)(lVar6 - lVar5),(int)((uint64_t)(lVar6 - lVar5) >> 0x20),1000,0);//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  iVar1 = (int)((uint64_t)uVar7 >> 0x20);//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  bVar4 = iVar1 == 0;
  if (iVar1 == 0)
  {
    bVar4 = (uint32_t)uVar7 < 0xffff;
  }
  if (bVar4)
  {
    uVar3 = (uint32_t)uVar7 & 0xfffe;
  }
  else
  {
    uVar3 = 0;
  }
  if (uVar2 != 0xffffffff)
  {
    IRCAL_Set(uVar2);
    uVar2 = uVar2 | uVar3 << 0x10;
  }
  return uVar2;
}



uint32_t IRCAL_Perform(void)

{
  int iVar1;
  uint32_t uVar2;
  
  iVar1 = IRCAL_GetGlobalCalType();
  if (iVar1 == 0xff)
  {
    uVar2 = 0xffffffff;
  }
  else
  {
  //  uVar2 = IRCAL_PerformSubfunction(iVar1,2,rcIrCalData[10],rcIrCalData._12_2_,rcIrCalData._14_2_,param_2,param_3); //!!!!!!!!!!!!!!!!!!!!!!!!!!!
  }
  return uVar2;
}


