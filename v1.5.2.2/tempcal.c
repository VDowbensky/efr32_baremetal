#include "tempcal.h"



void TEMPCAL_Init(void)

{
  char cVar1;
  char cVar2;
  
  cVar1 = (char)(_DAT_0fe08204 & 0xff);
  if ((_DAT_0fe08204 & 0xff) == 0xff) 
  {
    cVar1 = -0x70;
    cVar2 = '\x19';
  }
  else 
  {
    cVar2 = (char)((uint)(_DAT_0fe081b0 << 8) >> 0x18);
    if (cVar2 == -1) 
	{
      cVar1 = -0x70;
      cVar2 = '\x19';
    }
  }
  SEQ->REG078._3_1_ = (char)((uint)(int)cVar2 / 2) + cVar1;
  SEQ->REG078._2_1_ = 2;
  SEQ->REG078._1_1_ = 0x23;
}



void TEMPCAL_Perform(void)

{
  if ((RAC->STATUS & RAC_STATUS_STATE_Msk) >> RAC_STATUS_STATE_Pos == 2) RAC->CMD = RAC_CMD_RXCAL_Msk; //0x80;
}


