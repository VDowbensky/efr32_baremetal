#ifndef _FRAME_H_
#define _FRAME_H_

#include "em_device.h"
#include <stdbool.h>
#include "RADIO_config.h"

#define BIT_ORDER_LSB_FIRST  			0
#define BIT_ORDER_MSB_FIRST 			1
#define FRAME_FIXED_LENGTH  			0
#define FRAME_VARIABLE_LENGTH 			1
#define FRAME_FRAME_TYPE 				2
#define VAR_LENGTH_BYTEENDIAN_LSB_FIRST  			0 // The least significant byte of the variable length field is transmitted over the air first
#define VAR_LENGTH_BYTEENDIAN_MSB_FIRST 			1 // The most significant byte of the variable length field is transmitted over the air first
#define VAR_LENGTH_BITENDIAN_LSB_FIRST   			0 // The variable length field is transmitted least signficant bit first
#define VAR_LENGTH_BITENDIAN_MSB_FIRST 				1 // The variable length field is transmitted most significant bit first
	
	typedef struct FrameConfig
	{
		uint32_t bitendian;
		uint32_t bitsperword;
		uint32_t type;
		bool white_en;
		bool crc_en;
		bool accept_crc_errors;
		bool header_en; //Set to true to enable a distinct header from the payload
		uint32_t header_size; //Define the number of bytes that make up the header. Include the variable length byte(s)
		bool header_calc_crc; //Set to true to include the header bytes in the payload CRC
		bool header_include_crc; //Set to true to check/transmit crc specifically for the header
		bool header_white_en; //Set to true to enable whitening over the header
		uint16_t fixed_length; //Define the number of bytes in the payload. This does not include the length of the header if used. Header + Payload must be less than 4096 bytes
	}FrameConfig_t;
	
	typedef struct VarLenConfig
	{
		uint16_t numbits; //Define the size of the variable length field in bits
		uint32_t byteendian;
		uint16_t loc;
		uint32_t bitendian;
		uint8_t shift; //Define the location of the least significant bit of the variable length field
		uint16_t minlength; //Define the minimum value of the variable length field
		uint16_t maxlength; //Define the maximum value of the variable length field. Cannot exceed the variable length size
		bool includecrc; //Set to true if the crc bytes are included in the variable length
		uint16_t adjust; //Value to add to the variable length extracted from the packet when calculating the total payload length to receive.  A positive number here indicates the payload will be larger than the length value extracted from the variable length bits

	}VarLenConfig_t;
	
	typedef struct FrameTypeConfig
	{
		uint8_t loc; //Define the zero-based start location in the frame that holds the frame type encoding
		uint8_t mask; //Define the bitmask to extract the frame type in the byte
		uint8_t bits; //Define the number of bits of the frame type field
		uint8_t lsbit; //Define the bit location of the frame type's least significant bit
		uint16_t lengths[8]; //Define the frame length of each frame type
		bool valid[8]; //Define the valid frame types
		bool filter[8]; //Define the frame types that should have address filtering applied
	}FrameTypeConfig_t;
	
	typedef struct FrameInit
	{
		FrameConfig_t FrameConfig;
		VarLenConfig_t VarLenConfig;
		FrameTypeConfig_t FrameTypeConfig;
	}FrameInit_t;
	
	typedef struct FCDconfig
	{
		bool skipwhite; 
		bool skipcrc; 
		bool calccrc; 
		bool includecrc; 
		uint8_t buf;
		uint8_t words;
	}FCDconfig_t;
	
void FRAME_Init(void);


#endif