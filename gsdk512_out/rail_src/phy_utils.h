#ifndef _PHY_UTILS_H_
#define _PHY_UTILS_H_

int PHY_UTILS_ConvertHexToAscii(uint8_t val);
uint32_t PHY_UTILS_CheckParity(uint32_t val);
bool PHY_UTILS_BitsetIsSet(uint32_t addr,uint32_t bit);
void PHY_UTILS_BitsetClearAll(uint32_t *addr,uint32_t cnt);
int PHY_UTILS_BitsetLowestSetBit(uint32_t addr,uint32_t bit);
int PHY_UTILS_BitsetHighestSetBit(uint32_t addr,uint32_t bit);
void PHY_UTILS_DelayUs(uint32_t us);

uint PHY_UTILS_genPRBS9Data(undefined *param_1,uint param_2,int param_3);
#endif
