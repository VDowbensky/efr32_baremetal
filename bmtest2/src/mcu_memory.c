#include <stdint.h>
#include "mcu_memory.h"

uint32_t userdata_buf[512];


uint32_t readmem(uint32_t addr)
{
	return *(uint32_t*)addr;
}

void writemem(uint32_t addr, uint32_t data)
{
	
}

void read_userpage(void)
{
  uint32_t i;
  for(i = 0; i < 512; i++) userdata_buf[i] = (*(uint32_t *) (USERDATA_BASE + i*4));
}
void write_userpage(void)
{
  MSC_WriteWord(USERDATA_BASE, (uint8_t*)&userdata_buf, 2048);
}


void storedevid(uint32_t id)
{
	
}