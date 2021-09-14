#include "tempcal.h"



void TEMPCAL_Init(void)

{
  int iVar1;
  uint32_t uVar2;
  char cVar3;
  char cVar4;
  
  uVar2 = (DAT_0fe08204);
  iVar1 = (DAT_0fe081b0);
  cVar3 = (char)(uVar2 & 0xff);
  if ((uVar2 & 0xff) == 0xff) {
    cVar3 = -0x70;
    cVar4 = '\x19';
  }
  else {
    cVar4 = (char)((uint32_t)(iVar1 << 8) >> 0x18);
    if (cVar4 == -1) {
      cVar3 = -0x70;
      cVar4 = '\x19';
    }
  }
  write_volatile_1(SEQ->REG08C._3_1_,(char)((uint32_t)(int)cVar4 / 2) + cVar3);
  write_volatile_1(SEQ->REG08C._2_1_,2);
  write_volatile_1(SEQ->REG08C._1_1_,0x23);
  return;
}



void TEMPCAL_Perform(void)

{
  uint32_t uVar1;
  
  uVar1 = (RAC->STATUS);
  if ((uVar1 << 4) >> 0x1c == 2) {
    write_volatile_4(RAC->CMD,0x80);
  }
  return;
}


