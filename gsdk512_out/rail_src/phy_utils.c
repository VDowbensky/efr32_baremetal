#include "phy_utils.h"



int PHY_UTILS_ConvertHexToAscii(uint8_t val)

{
  if ((val & 0xf) < 10) return (val & 0xf) + 0x30; 
  else return (val & 0xf) + 0x37;
}



uint32_t PHY_UTILS_CheckParity(uint32_t val)

{
  val = val ^ val >> 0x10;
  val = val ^ val >> 8;
  return 0x6996 >> ((val ^ val >> 4) & 0xf) & 1;
}



bool PHY_UTILS_BitsetIsSet(uint32_t addr,uint32_t bit)

{
  return *(uint32_t *)(addr + (bit >> 5) * 4) >> (bit & 0x1f) & 1;
}



void PHY_UTILS_BitsetClearAll(uint32_t *addr,uint32_t cnt)

{
  uint32_t *puVar1;
  
  puVar1 = addr + cnt;
  while (puVar1 != addr) 
  {
    puVar1--;
    *puVar1 = 0;
  }
}



int PHY_UTILS_BitsetLowestSetBit(uint32_t addr,uint32_t bit)

{
//  byte bVar1;
//  byte bVar2;
//  byte bVar3;
//  byte bVar4;
  int iVar5;
//  undefined4 uVar6;
  int iVar7;
  
  iVar5 = 0;
  while( true ) 
  {
    if (iVar5 == bit) return -1;
    uVar6 = *(undefined4 *)(addr + iVar5 * 4);
/*     bVar2 = (byte)uVar6;
    bVar3 = (byte)((uint)uVar6 >> 8);
    bVar4 = (byte)((uint)uVar6 >> 0x10);
    bVar1 = (byte)((uint)uVar6 >> 0x18);
    iVar7 = count_leading_zeroes
                      ((uint)(byte)((((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 | bVar2 >> 2 & 1)
                                        << 1 | bVar2 >> 3 & 1) << 1 | bVar2 >> 4 & 1) << 1 |
                                     bVar2 >> 5 & 1) << 1 | bVar2 >> 6 & 1) << 1 | bVar2 >> 7) <<
                       0x18 | (uint)(byte)((((((((bVar3 & 1) << 1 | bVar3 >> 1 & 1) << 1 |
                                               bVar3 >> 2 & 1) << 1 | bVar3 >> 3 & 1) << 1 |
                                             bVar3 >> 4 & 1) << 1 | bVar3 >> 5 & 1) << 1 |
                                           bVar3 >> 6 & 1) << 1 | bVar3 >> 7) << 0x10 |
                       (uint)(byte)((((((((bVar4 & 1) << 1 | bVar4 >> 1 & 1) << 1 | bVar4 >> 2 & 1)
                                        << 1 | bVar4 >> 3 & 1) << 1 | bVar4 >> 4 & 1) << 1 |
                                     bVar4 >> 5 & 1) << 1 | bVar4 >> 6 & 1) << 1 | bVar4 >> 7) << 8
                       | (uint)(byte)((((((((bVar1 & 1) << 1 | bVar1 >> 1 & 1) << 1 | bVar1 >> 2 & 1
                                          ) << 1 | bVar1 >> 3 & 1) << 1 | bVar1 >> 4 & 1) << 1 |
                                       bVar1 >> 5 & 1) << 1 | bVar1 >> 6 & 1) << 1 | bVar1 >> 7)); //bit reverse */
	iVar7 = count_trailing_zeroes(*(undefined4 *)(addr + iVar5 * 4)); //count_trailing_zeroes fcn must be written
    if (iVar7 != 0x20) break;
    iVar5++;
  }
  return iVar7 + iVar5 * 0x20;
}



int PHY_UTILS_BitsetHighestSetBit(uint32_t addr,uint32_t bit)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  while( true ) 
  {
    if (iVar1 == bit) return -1;
    iVar2 = count_leading_zeroes(*(undefined4 *)(addr + iVar1 * 4));
    if (iVar2 != 0x20) break;
    iVar1++;
  }
  return iVar1 * 0x20 - iVar2;
}



void PHY_UTILS_DelayUs(uint32_t us)

{
  if (PROTIMER_IsRunning() == false) 
  {
    PROTIMER_Init();
    PROTIMER_Start();
  }
  PROTIMER_DelayUs(us);
  if (PROTIMER_IsRunning() == false) //???
  {
    PROTIMER_Stop();
    PROTIMER_Reset();
  }
}



uint PHY_UTILS_genPRBS9Data(undefined *param_1,uint param_2,int param_3)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  
  puVar1 = param_1 + param_3;
  for (; param_1 != puVar1; param_1 = param_1 + 1) 
  {
    iVar3 = 8;
    uVar2 = 0;
    do 
	{
      iVar3--;
      uVar2 = param_2 & 1 | (uVar2 & 0x7f) << 1;
      param_2 = param_2 >> 1 | (param_2 & 1 ^ (param_2 << 0x1b) >> 0x1f) << 8;
    } while (iVar3 != 0);
    *param_1 = (char)uVar2;
  }
  return param_2;
}


