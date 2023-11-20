#ifndef _WHITE_H_
#define _WHITE_H_

#include "em_device.h"
#include "RADIO_config.h"

    //WHITE_POLY
    #define WHITE_POLY_NONE 					0//'No Whitening'],
    #define WHITE_POLY_PN9						1// 'X9+X5+1'],
    #define WHITE_POLY_PN9_BYTE					2// 'X9+X5+X1'],
    #define WHITE_POLY_PN16						3// 'X16+X14+X13+X11+1'],
    #define WHITE_POLY_BLE						4// 'X7+X4+1'],
    #define WHITE_POLY_BYTEWIZE_XOR_SEED_LSB	5// 'Each byte is XORed LSbyte of whitening seed'],
    #define WHITE_POLY_PN9_802154				6// 'PN9 sequence per IEEE 802.15.4']


	typedef struct WHITE_Params
	{
		uint32_t 	poly;
		uint32_t 	seed;
		uint32_t 	outputbit;
		uint32_t 	xorfeedback;
		uint32_t 	feedbacksel;
	}WHITE_Params_t;

	void WHITE_Init (void);
	void WHITE_SetParams(WHITE_Params_t *params);

#endif
