#include "radio_crc.h"

void CRC_init(void)
{
	CRC->POLY = 0x0000A001;
	//seed
	CRC->INIT = 0x00000000;
	//input bit endian
	//CRC input padding
	//output byte endian
	//output bit endian
	//invert
	CRC->CTRL = 0x00000744;
}