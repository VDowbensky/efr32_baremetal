#include "phy_utils.h"
#include <stdbool.h>
#include "em_bus.h"
#include "em_assert.h"

#include "protimer.h"



uint8_t PHY_UTILS_ConvertHexToAscii(uint8_t value)

{
	if ((value & 0xf) < 10) return (value & 0xf) + 0x30;
	else return (value & 0xf) + 0x37;
}



uint32_t PHY_UTILS_CheckParity(uint32_t value)

{
  value = value ^ value >> 0x10;
  value = value ^ value >> 8;
  return 0x6996 >> ((value ^ value >> 4) & 0xf) & 1;
}



uint32_t PHY_UTILS_BitsetIsSet(int param_1,uint32_t param_2)

{
  return *(uint32_t *)(param_1 + (param_2 >> 5) * 4) >> (param_2 & 0x1f) & 1;
}



void PHY_UTILS_BitsetClearAll(uint32_t *param_1,int param_2)

{
  uint32_t *puVar1;
  
  puVar1 = param_1 + param_2;
  while (puVar1 != param_1) {
    puVar1 = puVar1 + -1;
    *puVar1 = 0;
  }
  return;
}



int PHY_UTILS_BitsetLowestSetBit(int param_1,int param_2)

{
  uint8_t bVar1;
  uint8_t bVar2;
  uint8_t bVar3;
  uint8_t bVar4;
  int iVar5;
  uint32_t uVar6;
  int iVar7;
  
  iVar5 = 0;
  while( true ) {
    if (iVar5 == param_2) {
      return -1;
    }
    uVar6 = *(uint32_t *)(param_1 + iVar5 * 4);
    bVar2 = (uint8_t)uVar6;
    bVar3 = (uint8_t)((uint32_t)uVar6 >> 8);
    bVar4 = (uint8_t)((uint32_t)uVar6 >> 0x10);
    bVar1 = (uint8_t)((uint32_t)uVar6 >> 0x18);
//    iVar7 = count_leading_zeroes
//                      ((uint32_t)(uint8_t)((((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 | bVar2 >> 2 & 1)
//                                        << 1 | bVar2 >> 3 & 1) << 1 | bVar2 >> 4 & 1) << 1 |
//                                     bVar2 >> 5 & 1) << 1 | bVar2 >> 6 & 1) << 1 | bVar2 >> 7) <<
//                       0x18 | (uint32_t)(uint8_t)((((((((bVar3 & 1) << 1 | bVar3 >> 1 & 1) << 1 |
//                                               bVar3 >> 2 & 1) << 1 | bVar3 >> 3 & 1) << 1 |
//                                             bVar3 >> 4 & 1) << 1 | bVar3 >> 5 & 1) << 1 |
//                                           bVar3 >> 6 & 1) << 1 | bVar3 >> 7) << 0x10 |
//                       (uint32_t)(uint8_t)((((((((bVar4 & 1) << 1 | bVar4 >> 1 & 1) << 1 | bVar4 >> 2 & 1)
//                                        << 1 | bVar4 >> 3 & 1) << 1 | bVar4 >> 4 & 1) << 1 |
//                                     bVar4 >> 5 & 1) << 1 | bVar4 >> 6 & 1) << 1 | bVar4 >> 7) << 8
//                       | (uint32_t)(uint8_t)((((((((bVar1 & 1) << 1 | bVar1 >> 1 & 1) << 1 | bVar1 >> 2 & 1
//                                          ) << 1 | bVar1 >> 3 & 1) << 1 | bVar1 >> 4 & 1) << 1 |
//                                       bVar1 >> 5 & 1) << 1 | bVar1 >> 6 & 1) << 1 | bVar1 >> 7));
    if (iVar7 != 0x20) break;
    iVar5 = iVar5 + 1;
  }
  return iVar7 + iVar5 * 0x20;
}



int PHY_UTILS_BitsetHighestSetBit(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  while( true ) {
    if (iVar1 == param_2) {
      return -1;
    }
//    iVar2 = count_leading_zeroes(*(uint32_t *)(param_1 + iVar1 * 4));
    if (iVar2 != 0x20) break;
    iVar1 = iVar1 + 1;
  }
  return iVar1 * 0x20 - iVar2;
}



void PHY_UTILS_DelayUs(uint32_t us)

{
  if (PROTIMER_IsRunning() == 0) 
  {
    PROTIMER_Init();
    PROTIMER_Start();
  }
  PROTIMER_DelayUs(us);
  if (PROTIMER_IsRunning() == 0)
  {
    PROTIMER_Stop();
    PROTIMER_Reset();
    return;
  }
}



uint32_t PHY_UTILS_genPRBS9Data(uint8_t *param_1,uint32_t param_2,int param_3)

{
  uint8_t *puVar1;
  uint32_t uVar2;
  int iVar3;
  
  puVar1 = param_1;
  while (puVar1 != param_1 + param_3) {
    iVar3 = 8;
    uVar2 = 0;
    do {
      iVar3 = iVar3 + -1;
      uVar2 = param_2 & 1 | (uVar2 & 0x7f) << 1;
      param_2 = param_2 >> 1 | (param_2 & 1 ^ (param_2 << 0x1b) >> 0x1f) << 8;
    } while (iVar3 != 0);
    *puVar1 = (char)uVar2;
    puVar1 = puVar1 + 1;
  }
  return param_2;
}


