#include "tempcal.h"



void TEMPCAL_Init(void)

{
  char cVar1;
  char cVar2;
  
  cVar1 = (char)(_DAT_0fe08204 & 0xff);
  if ((_DAT_0fe08204 & 0xff) == 0xff) {
    cVar1 = -0x70;
    cVar2 = '\x19';
  }
  else {
    cVar2 = (char)((uint)(_DAT_0fe081b0 << 8) >> 0x18);
    if (cVar2 == -1) {
      cVar1 = -0x70;
      cVar2 = '\x19';
    }
  }
  write_volatile_1(SEQ->REG078._3_1_,(char)((uint)(int)cVar2 / 2) + cVar1);
  write_volatile_1(SEQ->REG078._2_1_,2);
  write_volatile_1(SEQ->REG078._1_1_,0x23);
  return;
}



void TEMPCAL_Perform(void)

{
  uint uVar1;
  
  uVar1 = (RAC->STATUS);
  if ((uVar1 << 4) >> 0x1c == 2) {
    write_volatile_4(RAC->CMD,0x80);
  }
  return;
}


