#include "radio_crc.h"


void CRC_init(void)
{
	CRCsettings_t CRCsettings;
	CRCsettings.poly = 0xa001;
	CRCsettings.seed = 0;
	CRCsettings.inputinv = 0; //0
	CRCsettings.outputinv = 0; //1
	CRCsettings.width = 1; //2,3
	CRCsettings.inputbitorder = 0; //5
	CRCsettings.bytereverse = 1; //6
	CRCsettings.bitreverse = 0; //7
	CRCsettings.bitsperword = 7; //8...11
	CRCsettings.padcrcinput = 0; //12
	
	CRC->POLY = CRCsettings.poly;
	CRC->INIT = CRCsettings.seed;
	CRC->CTRL = (CRCsettings.inputinv << CRC_CTRL_INPUTINV_Pos) | (CRCsettings.outputinv << CRC_CTRL_OUTPUTINV_Pos) | (CRCsettings.width << CRC_CTRL_CRCWIDTH_Pos) |
	(CRCsettings.inputbitorder << CRC_CTRL_INPUTBITORDER_Pos) | (CRCsettings.bytereverse << CRC_CTRL_BYTEREVERSE_Pos) | (CRCsettings.bitreverse << CRC_CTRL_BITREVERSE_Pos) | 
	(CRCsettings.bitsperword << CRC_CTRL_BITSPERWORD_Pos) | (CRCsettings.padcrcinput << CRC_CTRL_PADCRCINPUT_Pos);
}


