#include "tempcal.h"



void TEMPCAL_Init(void)

{
  char cVar3;
  char cVar4;
  
  cVar3 = (char)(DAT_0fe08204 & 0xff);
  if ((DAT_0fe08204 & 0xff) == 0xff) 
  {
    cVar3 = -0x70;
    cVar4 = 0x19;
  }
  else 
  {
    cVar4 = (char)((uint)(DAT_0fe081b0 << 8) >> 0x18);
    if (cVar4 == -1) 
	{
      cVar3 = -0x70;
      cVar4 = 0x19;
    }
  }
  SEQ->REG080._3_1_ = (char)((uint)(int)cVar4 / 2) + cVar3;
  SEQ->REG080._2_1_ = 2;
  SEQ->REG080._1_1_ = 0x23;
}



void TEMPCAL_Perform(void)

{
  if ((RAC->STATUS & RAC_STATUS_STATE_Msk) >> RAC_STATUS_STATE_Pos == 2) RAC->CMD = 0x80;
}


