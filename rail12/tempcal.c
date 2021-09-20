#include "tempcal.h"



void TEMPCAL_Init(void)

{
  char cVar3;
  char cVar4;
  
  cVar3 = (char)(DAT_0fe08204 & 0xff);
  if ((DAT_0fe08204 & 0xff) == 0xff) SEQ->REG080 |= (0x23 << 8) | (2 << 16) | (0x9c << 24);//SEQ->REG080._3_1_ = 0x9c;
  else 
  {
    cVar4 = (DAT_0fe081b0 << 8) >> 24;
    if (cVar4 == 0xff) SEQ->REG080 |= SEQ->REG080 |= (0x23 << 8) | (2 << 16) | (0x9c << 24);//SEQ->REG080._3_1_ = 0x9c;
	else SEQ->REG080 |= (0x23 << 8) | (2 << 16) | (cVar4 / 2 + cVar3) << 24; //SEQ->REG080._3_1_ = cVar4 / 2 + cVar3;
  }
}



void TEMPCAL_Perform(void)

{
  if ((RAC->STATUS & RAC_STATUS_STATE_Msk) >> RAC_STATUS_STATE_Pos == 2) RAC->CMD = 0x80;
}


