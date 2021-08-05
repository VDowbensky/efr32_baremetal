#include "tempcal.h"
#include <stdbool.h>
#include "em_bus.h"
#include "em_assert.h"




void TEMPCAL_Init(void)

{
  int8_t cVar1;
  int8_t cVar2;
  
//  cVar1 = (char)(_DAT_0fe08204 & 0xff);
	cVar1 = *(int8_t*)0x0fe08204;
  if (cVar1 == -1)
  {
    cVar1 = -0x70;
    cVar2 = 0x19;
  }
  else
  {
    //cVar2 = (char)((uint)(_DAT_0fe081b0 << 8) >> 0x18);
		cVar2 = (uint8_t)((*(uint32_t*)0x0fe081b0 << 8) >> 0x18);
    if (cVar2 == -1) 
		{
      cVar1 = -0x70;
      cVar2 = 0x19;
    }
  }
  //DAT_21000f81 = 0x23;
//  SEQ->REG081 = 0x23; //!!!!!!!!!!!!!!!!!!!!
  //DAT_21000f82 = 2;
//  SEQ->REG082 = 0x23;//!!!!!!!!!!!!!!!!!!!!
  //DAT_21000f83 = (char)((uint)(int)cVar2 / 2) + cVar1;//!!!!!!!!!!!!!!!!!!!!
//  SEQ->REG083 = ((char)((uint)(int)cVar2) / 2 + cVar1;//!!!!!!!!!!!!!!!!!!!!
	SEQ->REG080 = (0x23 << 8) | (2 << 16) | (((uint8_t)cVar2/2 + cVar1) << 24);
}



void TEMPCAL_Perform(void)

{
  if ((RAC->STATUS << 4) >> 0x1c == 2) RAC->CMD = 0x80;
}


