#include "tempcal.h"


void TEMPCAL_Init(void)

{
  int8_t cVar1;
  int8_t cVar2;

  if ((DEVINFO->EMUTEMP & 0xff) == 0xff) 
  {
    cVar1 = -0x70;
    cVar2 = '\x19';
  }
  else 
  {
    cVar2 = (int8_t)((DEVINFO->CAL << 8) >> 0x18);
    if ((int8_t)((DEVINFO->CAL << 8) >> 0x18) == -1) 
	{
      cVar1 = -0x70;
      cVar2 = '\x19';
    }
  }
  SEQ->REG078._3_1_ = (int8_t)((uint)(int)cVar2 / 2) + cVar1;
  SEQ->REG078._2_1_ = 2;
  SEQ->REG078._1_1_ = 0x23;
  //SEQ->REG078 = 
}



void TEMPCAL_Perform(void)

{
  if (RAC->STATUS & RAC_STATUS_STATE_Msk == 2) RAC->CMD = RAC_CMD_RXCAL_Msk;
}


