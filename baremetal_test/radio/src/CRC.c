	#include "CRC.h"

	uint32_t polyreg;
	uint32_t seedreg;
	
	void CRC_CalcCrcPolyReg(uint32_t polyval, uint32_t seedval);

	void CRC_Init(void)
	{
		CRC->CTRL = (7 << CRC_CTRL_BITSPERWORD_Pos) | ((RadioConfig.crc_size - 1) << CRC_CTRL_CRCWIDTH_Pos); //Always set BITSPERWORD to 7 because we work with bytes
		// Subtract 1 from the CRC size to get the proper value
		CRC_CalcCrcPolyReg(RadioConfig.crc_poly, RadioConfig.crc_seed);
        CRC->POLY = polyreg;
        CRC->INIT = seedreg;
        //Handle Endianness
        if (RadioConfig.crc_byteendian == CRC_BYTE_ENDIAN_LSB_FIRST) CRC->CTRL |= (1 << CRC_CTRL_BYTEREVERSE_Pos); //CRC_CTRL_BYTEREVERSE = 1;
				//if(initstruct->bitreverse == 1) CRC->CTRL |= (1 << 
        if(RadioConfig.crc_outputbitorder == 1) CRC->CTRL |= (1 << CRC_CTRL_BITREVERSE_Pos); //CRC_CTRL_BITREVERSE = 1;
        //Handle Input Bit Order
        if (RadioConfig.crc_inputbitorder == CRC_BIT_ORDER_LSB_FIRST) CRC->CTRL |= (1 << CRC_CTRL_INPUTBITORDER_Pos); //CRC_CTRL_INPUTBITORDER = 1;
        //Handle pad crc input
        if (RadioConfig.crc_inputpadding == 1) CRC->CTRL |= (1 << CRC_CTRL_PADCRCINPUT_Pos); //CRC_CTRL_PADCRCINPUT = 1;
        if (RadioConfig.crc_invert == 1) CRC->CTRL |= (1 << CRC_CTRL_OUTPUTINV_Pos); //CRC_CTRL_OUTPUTINV = 1;
	}

    void CRC_CalcCrcPolyReg(uint32_t polyval, uint32_t seedval) //
	{
        polyreg = 0;
        seedreg = 0;
		if (polyval == 0) return;
        else
		{
            while (polyval != 1)
			{
                polyreg <<= 1;
                if (polyval & 0x01) polyreg |= 1;
                polyval >>= 1;
                seedreg <<= 1;
                if (seedval & 0x01) seedreg |= 1;
                seedval >>= 1;
			}
		}
	}