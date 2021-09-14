#include "cortex_utils.h"



int CORTEX_UTILS_BitsetLowestSetBit(int param_1,int param_2)

{
  uint8_t bVar1;
  uint8_t bVar2;
  uint8_t bVar3;
  uint8_t bVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  
  iVar5 = 0;
  while( true ) 
  {
    if (iVar5 == param_2) return -1;
    uVar6 = *(undefined4 *)(param_1 + iVar5 * 4);
    bVar2 = (uint8_t)uVar6;
    bVar3 = (uint8_t)((uint32_t)uVar6 >> 8);
    bVar4 = (uint8_t)((uint32_t)uVar6 >> 0x10);
    bVar1 = (uint8_t)((uint32_t)uVar6 >> 0x18);
    iVar7 = count_leading_zeroes
                      ((uint32_t)(uint8_t)((((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 | bVar2 >> 2 & 1)
                                        << 1 | bVar2 >> 3 & 1) << 1 | bVar2 >> 4 & 1) << 1 |
                                     bVar2 >> 5 & 1) << 1 | bVar2 >> 6 & 1) << 1 | bVar2 >> 7) <<
                       0x18 | (uint32_t)(uint8_t)((((((((bVar3 & 1) << 1 | bVar3 >> 1 & 1) << 1 |
                                               bVar3 >> 2 & 1) << 1 | bVar3 >> 3 & 1) << 1 |
                                             bVar3 >> 4 & 1) << 1 | bVar3 >> 5 & 1) << 1 |
                                           bVar3 >> 6 & 1) << 1 | bVar3 >> 7) << 0x10 |
                       (uint32_t)(uint8_t)((((((((bVar4 & 1) << 1 | bVar4 >> 1 & 1) << 1 | bVar4 >> 2 & 1)
                                        << 1 | bVar4 >> 3 & 1) << 1 | bVar4 >> 4 & 1) << 1 |
                                     bVar4 >> 5 & 1) << 1 | bVar4 >> 6 & 1) << 1 | bVar4 >> 7) << 8
                       | (uint32_t)(uint8_t)((((((((bVar1 & 1) << 1 | bVar1 >> 1 & 1) << 1 | bVar1 >> 2 & 1
                                          ) << 1 | bVar1 >> 3 & 1) << 1 | bVar1 >> 4 & 1) << 1 |
                                       bVar1 >> 5 & 1) << 1 | bVar1 >> 6 & 1) << 1 | bVar1 >> 7));
    if (iVar7 != 0x20) break;
    iVar5 = iVar5 + 1;
  }
  return iVar7 + iVar5 * 0x20;
}



int CORTEX_UTILS_BitsetHighestSetBit(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  while( true ) 
  {
    if (iVar1 == param_2) return -1;
    iVar2 = count_leading_zeroes(*(undefined4 *)(param_1 + iVar1 * 4));
    if (iVar2 != 0x20) break;
    iVar1 = iVar1 + 1;
  }
  return iVar1 * 0x20 - iVar2;
}


