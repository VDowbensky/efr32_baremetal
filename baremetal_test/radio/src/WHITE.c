	#include "WHITE.h"
	

	void WHITE_Init (void) //enumerated poly setting, from 0 to 6
	{
		FRC->WHITECTRL &= ~(FRC_WHITECTRL_SHROUTPUTSEL_Msk | FRC_WHITECTRL_XORFEEDBACK_Msk | FRC_WHITECTRL_FEEDBACKSEL_Msk);
		switch(RadioConfig.white_poly)
		{
			case WHITE_POLY_NONE:
			default:
			// Defaults if whitening is disabled
			FRC->WHITEPOLY = 0;
			break;
			
			case WHITE_POLY_PN9: //WHITE_POLY_PN9:       ( 0x00000108, 0, 0 ),
			FRC->WHITEPOLY = 0x108;
			break;
			
			case WHITE_POLY_PN9_BYTE: //WHITE_POLY_PN9_BYTE:  ( 0x00000100, 1, 5 ),
			FRC->WHITEPOLY = 0x100;
			FRC->WHITECTRL |= (1 << FRC_WHITECTRL_XORFEEDBACK_Pos) | (5 << FRC_WHITECTRL_FEEDBACKSEL_Pos);
			break;
			
			case WHITE_POLY_PN16: //WHITE_POLY_PN16:      ( 0x00008016, 0, 0 ),
			FRC->WHITEPOLY = 0x8016;
			break;
			
			case WHITE_POLY_BLE: //WHITE_POLY_BLE:       ( 0x00000044, 0, 0 ),
			FRC->WHITEPOLY = 0x44;
			break;
			
			case WHITE_POLY_BYTEWIZE_XOR_SEED_LSB: //WHITE_POLY_Bytewise_XOR_seed_LSB: (0x00000080, 0, 0),
			FRC->WHITEPOLY = 0x80;
			break;
			
			case WHITE_POLY_PN9_802154: //WHITE_POLY_PN9_802154: ( 0x100, 1, 5)
			FRC->WHITEPOLY = 0x100;
			FRC->WHITECTRL |= (1 << FRC_WHITECTRL_XORFEEDBACK_Pos) | (5 << FRC_WHITECTRL_FEEDBACKSEL_Pos);
			break;
		}
		FRC->WHITEINIT = RadioConfig.white_seed;
		if(RadioConfig.white_outputbit > 15) RadioConfig.white_outputbit = 15;
		if(RadioConfig.white_xorfeedback > 3) RadioConfig.white_xorfeedback = 3;
		if(RadioConfig.white_feedbacksel > 31) RadioConfig.white_feedbacksel = 31;
		FRC->WHITECTRL |= (RadioConfig.white_outputbit << FRC_WHITECTRL_SHROUTPUTSEL_Pos) | (RadioConfig.white_xorfeedback << FRC_WHITECTRL_XORFEEDBACK_Pos) | (RadioConfig.white_feedbacksel << FRC_WHITECTRL_FEEDBACKSEL_Pos);
	}
	
	void WHITE_SetParams(WHITE_Params_t *params) //direct poly setting
	{
		FRC->WHITECTRL &= ~(FRC_WHITECTRL_SHROUTPUTSEL_Msk | FRC_WHITECTRL_XORFEEDBACK_Msk | FRC_WHITECTRL_FEEDBACKSEL_Msk);
		FRC->WHITEPOLY = params->poly;
		FRC->WHITEINIT = params->seed;
		if(params->outputbit > 15) params->outputbit = 15;
		if(params->xorfeedback > 3) params->xorfeedback = 3;
		if(params->feedbacksel > 31) params->feedbacksel = 31;
		FRC->WHITECTRL |= (params->outputbit << FRC_WHITECTRL_SHROUTPUTSEL_Pos) | (params->xorfeedback << FRC_WHITECTRL_XORFEEDBACK_Pos) | (params->feedbacksel << FRC_WHITECTRL_FEEDBACKSEL_Pos);
	}


