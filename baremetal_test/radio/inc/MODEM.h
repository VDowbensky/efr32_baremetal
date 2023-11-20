#ifndef _MODEM_H_
#define _MODEM_H_

#include <stdbool.h>
#include "em_device.h"
#include "RADIO_config.h"
#include "UTILS.h"

#define FXO 38400000UL

	#define MANCHESTER_MAPPING_DEFAULT  	0 //0-bit corresponds to a 0 to 1 transition and 1-bit corresponds to 1 to 0 transition
	#define MANCHESTER_MAPPING_INVERTED		1 //0-bit corresponds to a 1 to 0 transition and 1-bit corresponds to 0 to 1 transition

	#define SYMBOL_ENCODING_NRZ 					0 //Non Return Zero Coding
	#define SYMBOL_ENCODING_MANCHESTER		1 //Manchester Coding
	#define SYMBOL_ENCODING_DSSS					2 //Direct Sequence Spread Spectrum Coding

        //This method is needed so that we can easily override the modulation type in future parts
    #define MOD_TYPE_FSK2  		0 // Frequency Shift Keying on two frequencies
    #define MOD_TYPE_FSK4 		1 // Frequency Shift Keying on four frequencies
    #define MOD_TYPE_BPSK			2 // Binary Phase Shift Keying: the 2 symbols are represented by 0 or 180 degree phase shifts wrt the carrier
    #define MOD_TYPE_DBPSK		3 // Differential Binary Phase Shift Keying: the 2 symbols are represented by 0 or 180 degree phase shifts wrt the preceding symbol
    #define MOD_TYPE_OOK			4 // On Off Keying: the 2 symbols are represented by the presence / absence of the carrier
    #define MOD_TYPE_ASK			5 // Amplitude Shift Keying: the 2 symbols are represented by two different power levels of the carrier
    #define MOD_TYPE_MSK			6 // Minimum Shift Keying: Special case of FSK2 where the phase shift in one symbol is +/- 90 degree
    #define MOD_TYPE_OQPSK		7 // Offset Quadrature Phase Shift Keying: 4 state phase modulation with 0, 90, 180 and 270 degrees wrt the carrier. Only +/-90 degree changes are allowed at any one transition that take place at twice the symbol rate.
		
        // FSK MAP
    #define FSK_MAP0 		0// 4FSK: 11, 10, 00, 01 in decreasing frequency, 2FSK: 1 high, 0 low frequency 
    #define FSK_MAP1		1// 4FSK: 01, 00, 10, 11 in decreasing frequency, 2FSK: 0 high, 1 low frequency 
    #define FSK_MAP2		2// 4FSK: 10, 11, 01, 00 in decreasing frequency, 2FSK: undefined 
    #define FSK_MAP3		3// 4FSK: 00, 01, 11, 10 in decreasing frequency, 2FSK: undefined 
    #define FSK_MAP4		4// 4FSK: 11, 01, 00, 10 in decreasing frequency, 2FSK: undefined 
    #define FSK_MAP5		5// 4FSK: 10, 00, 01, 11 in decreasing frequency, 2FSK: undefined 
    #define FSK_MAP6		6// 4FSK: 01, 11, 10, 00 in decreasing frequency, 2FSK: undefined
    #define FSK_MAP7		7// 4FSK: 00, 10, 11, 01 in decreasing frequency, 2FSK: undefined
	
		//SHAPING
		#define MOD_SHAPING_NONE						0 // No shaping filter is applied
    #define MOD_SHAPING_GAUSSIAN	  		1 // Gaussian shaping filter - BT is defined at entry field Shaping Filter Parameter
    #define MOD_SHAPING_RAISED_COSINE		2 // Raised Cosine shaping filter - R is defined at entry field Shaping Filter Parameter
    #define MOD_SHAPING_ROOT_RAISED_COSINE  3 // Filter for 802.15.4 250 kbps DSSS OQPSK PHY
    #define MOD_SHAPING_CUSTOM_OQPSK		4 // Filter for 802.15.4 250 kbps DSSS OQPSK PHY
    #define MOD_SHAPING_CUSTOM_PSK			5 // Legacy 3rd party MSK filter
		
        // DIFFENCMODE
    #define DIFF_ENCODING_DISABLED  		0// Differential encoding is disabled
    #define DIFF_ENCODING_RR0				1// Transmit the xor-ed value of the Raw symbol and the last Raw symbol. Initial Raw symbol is 0.
    #define DIFF_ENCODING_RE0				2// Transmit the xor-ed value of the Raw symbol and the last Encoded symbol. Initial Encoded symbol is 0.
    #define DIFF_ENCODING_RR1				3// Transmit the xor-ed value of the Raw symbol and the last Raw symbol. Initial Raw symbol is 1.
    #define DIFF_ENCODING_RE1				4// Transmit the xor-ed value of the Raw symbol and the last Encoded symbol. Initial Encoded symbol is 1.
	
		//FEC
	#define FEC_NONE						0
	#define FEC_154G						1
	#define FEC_154G_K7					2
		
		//AFC
    #define FREQ_COMP_DISABLED 																		0// Neither Frequency Offset Compensation (AFC) nor internal frequency compensation is enabled
    #define FREQ_COMP_INTERNAL_LOCK_AT_PREAMBLE_DETECT						1// Internal frequency compensation is enabled only freezing at PREAMBLE_DETECT
    #define FREQ_COMP_INTERNAL_LOCK_AT_FRAME_DETECT								2// Internal frequency compensation is enabled only freezing at FRAME_DETECT
    #define FREQ_COMP_INTERNAL_ALWAYS_ON													3// Internal frequency compensation is enabled only and is always on
    #define FREQ_COMP_AFC_FREE_RUNNING														4// Frequency Offset Compensation (AFC) is enabled only and is always on
    #define FREQ_COMP_AFC_START_AT_PREAMBLE_FREE_RUNNING					5// AFC is enabled only starting at PREAMBLE_DETECT'],
    #define FREQ_COMP_AFC_LOCK_AT_TIMING_DETECT										6// Frequency Offset Compensation (AFC) is enabled only freezing at TIMING_DETECT
    #define FREQ_COMP_AFC_LOCK_AT_PREAMBLE_DETECT									7// Frequency Offset Compensation (AFC) is enabled only freezing at PREAMBLE_DETECT
    #define FREQ_COMP_AFC_LOCK_AT_FRAME_DETECT										8// Frequency Offset Compensation (AFC) is enabled only freezing at FRAME_DETECT
    #define FREQ_COMP_AFC_START_AT_PREAMBLE_LOCK_AT_FRAME_DETECT	9// Frequency Offset Compensation (AFC) is enabled only starting at PREAMBLE_DETECT and freezing at FRAME_DETECT

	void MODEM_init(void);
	void MODEM_ModParamsSet(void);
	void MODEM_MiscParamsSet(void);
  void MODEM_PreParamsSet(void);
	void MODEM_SyncParamsSet(void);
	void MODEM_StreamCodingSet(void);
	void MODEM_AfcParamsSet(void);

#endif



