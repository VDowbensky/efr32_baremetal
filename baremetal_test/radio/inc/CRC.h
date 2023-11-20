#ifndef _CRC_H_
#define _CRC_H_

#include "em_device.h"
#include "RADIO_config.h"

	//CRC POLY
	#define 	CRC_NONE 			0
	#define		CRC_CRC_8 			1 //0x107
	#define		CRC_CRC_16  		2 //0x18005
	#define		CRC_CCITT_16 		3 //0x11021
	#define		CRC_DNP_16 			4 //0x13d65
	#define		CRC_BLE_24 			5 //0x100065b
	#define		CRC_CRC_32Q 		6 //0x1814141ab
	#define		CRC_ANSIX366_1979 	7 //0x104c11db7
	#define		CRC_ZWAVE 			8 //0x101
	#define		CRC_BCH15_11 		9 //0x13
	 
	#define 	CRC_POLY_NONE 			0
	#define		CRC_POLY_CRC_8 			0x107
	#define		CRC_POLY_CRC_16  		0x18005
	#define		CRC_POLY_CCITT_16 		0x11021
	#define		CRC_POLY_DNP_16 		0x13d65
	#define		CRC_POLY_BLE_24 		0x100065b
	#define		CRC_POLY_CRC_32Q 		0x1814141ab
	#define		CRC_POLY_ANSIX366_1979 	0x104c11db7
	#define		CRC_POLY_ZWAVE 			0x101
	#define		CRC_POLY_BCH15_11 		0x13
	
	#define CRC_SIZE_NONE				0
	#define CRC_SIZE_CRC_8				1
	#define CRC_SIZE_CRC_16				2
	#define CRC_SIZE_CCITT_16			2
	#define CRC_SIZE_DNP_16				2
	#define CRC_SIZE_BLE_24				3
	#define CRC_SIZE_CRC_32Q			4
	#define CRC_SIZE_ANSIX366_1979		4
	#define CRC_SIZE_ZWAVE				1
	#define CRC_SIZE_BCH15_11			1
/*	
    uint32_t CRC_POLY_LOOKUP[] = {CRC_POLY_NONE,CRC_POLY_CRC_8,CRC_POLY_CRC_16,CRC_POLY_CCITT_16,CRC_POLY_DNP_16,CRC_POLY_BLE_24,CRC_POLY_CRC_32Q,
	CRC_POLY_ANSIX366_1979,CRC_POLY_ZWAVE,CRC_POLY_BCH15_11};
	uint32_t CRC_SIZE_LOOKUP[] = {CRC_SIZE_NONE,CRC_SIZE_CRC_8,CRC_SIZE_CRC_16,CRC_SIZE_CCITT_16,CRC_SIZE_DNP_16,CRC_SIZE_BLE_24,CRC_SIZE_CRC_32Q,
	CRC_SIZE_ANSIX366_1979,CRC_SIZE_ZWAVE,CRC_SIZE_BCH15_11};
	*/

	#define CRC_BYTE_ENDIAN_LSB_FIRST  	0 //Least significant byte of the CRC is transmitted first
	#define CRC_BYTE_ENDIAN_MSB_FIRST 	1

	#define CRC_BIT_ENDIAN_LSB_FIRST  	0 //Over the air CRC bit order is sent least significant bit first
	#define CRC_BIT_ENDIAN_MSB_FIRST  	1//Over the air CRC bit order is sent most significant bit first

	#define	CRC_BIT_ORDER_LSB_FIRST  	0 //The least significant data bit is first input to the CRC generator
	#define CRC_BIT_ORDER_MSB_FIRST 	1//The most significant data bit is first input to the CRC generator
	
	void CRC_Init(void);
	
#endif
