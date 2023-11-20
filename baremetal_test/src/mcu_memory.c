#include <stdint.h>
#include "mcu_memory.h"

uint32_t userdata_buf[512] __attribute__((aligned (4)));


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
	MSC_ErasePage((uint32_t*)USERDATA_BASE);
	MSC_WriteWord((uint32_t*)USERDATA_BASE, (uint8_t*)&userdata_buf, 2048);
}

void storedevid(uint32_t id)
{
  read_userpage();
  MSC_ErasePage((uint32_t*)USERDATA_BASE);
  //userdata_buf[0x0] = (id << 16) | 0x0000FFFF; //(id >> 16) | 0xFFFF0000;
  userdata_buf[0x0] &= 0x0000FFFF;//keep low halfword
  userdata_buf[0x0] |= (id << 16);
  //userdata_buf[0x1] = (id >> 16) | 0xFFFF0000;
  userdata_buf[0x1] &= 0xFFFF0000; //keep high halfword
  userdata_buf[0x1] |= (id >> 16);
  write_userpage();
}

void store_config(void)
{
	read_userpage();
	//memcpy((void *)(&userdata_buf + 0x108),(void*)&RadioConfig,sizeof(RadioConfig));
	memcpy((void *)(&userdata_buf[0x42]),(uint8_t*)&RadioConfig,sizeof(RadioConfig));
	write_userpage();
}

void read_config(void)
{
	memcpy((void *)&RadioConfig,(uint8_t*)(USERDATA_BASE + 0x108),sizeof(RadioConfig));
}