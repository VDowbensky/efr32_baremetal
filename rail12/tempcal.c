#include "tempcal.h"



void TEMPCAL_Init(void)

{
  int iVar1;
  uint uVar2;
  char cVar3;
  char cVar4;
  
  uVar2 = read_volatile_4(DAT_0fe08204);
  iVar1 = read_volatile_4(DAT_0fe081b0);
  cVar3 = (char)(uVar2 & 0xff);
  if ((uVar2 & 0xff) == 0xff) {
    cVar3 = -0x70;
    cVar4 = '\x19';
  }
  else {
    cVar4 = (char)((uint)(iVar1 << 8) >> 0x18);
    if (cVar4 == -1) {
      cVar3 = -0x70;
      cVar4 = '\x19';
    }
  }
  write_volatile_1(Peripherals::SEQ.REG080._3_1_,(char)((uint)(int)cVar4 / 2) + cVar3);
  write_volatile_1(Peripherals::SEQ.REG080._2_1_,2);
  write_volatile_1(Peripherals::SEQ.REG080._1_1_,0x23);
  return;
}



void TEMPCAL_Perform(void)

{
  uint uVar1;
  
  uVar1 = read_volatile_4(Peripherals::RAC.STATUS);
  if ((uVar1 << 4) >> 0x1c == 2) {
    write_volatile_4(Peripherals::RAC.CMD,0x80);
  }
  return;
}


