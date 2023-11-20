#ifndef _RFINIT_H_
#define _RFINIT_H_

#include "em_device.h"
#include <stdbool.h>
#include <string.h>
#include "MODEM.h"
#include "RFIF.h"
#include "AGC.h"
#include "CRC.h"
#include "WHITE.h"
#include "FRAME.h"
#include "BUFC.h"


    //Global config structure
	typedef struct RADIO_Config
	{
		//RF frequency
		uint32_t Initialized;
		uint32_t base_freq;
		uint32_t ch_spacing;
		uint8_t loside; //generally bool
		//Channels
		uint8_t min_channel;
		uint8_t max_channel;
		uint8_t default_channel;
		//Crystal
    uint32_t xtal_frequency_hz; //EFR32 crystal clock frequency
		uint32_t rx_xtal_error_ppm; //Crystal clock tolerance of receiver.
    uint32_t tx_xtal_error_ppm; //Crystal clock tolerance of the transmitter
		//uint16_t ctune; //this parameter must be placed at fixed location
		//Buffers parameters (not in configurator)
		uint32_t txbuffersize;
		uint32_t txbufferthreshold;
		uint32_t txbufferthresholdmode;
		uint32_t rxbuffersize;
		uint32_t rxbufferthreshold;
		uint32_t rxbufferthresholdmode;
		uint32_t rxlenbuffersize;
		uint32_t rxlenbufferthreshold;
		uint32_t rxlenbufferthresholdmode;
		uint32_t ackbuffersize;
		uint32_t ackbufferthreshold;
		uint32_t ackbufferthresholdmode;
		//Modem
		uint32_t modulation_type;
		uint32_t chiprate;
    uint32_t deviation; //Frequency deviation used in FSK modulation schemes
		uint32_t baudrate_tol_ppm; //Maximum baud rate error of the expected signal
		uint32_t shaping;
		float shaping_filter_param; //BT value for Gaussian  and roll-off factor for Raised Cosine pulse shaping filter
		//probably maybe some enum (from 0 to 100 step 5)
		uint32_t mapfsk;
		bool async_direct_mode; //asynchronous_rx_enable; //Asynchronous RX mode enabled
		//Frame settings
		//general & fixed length
		uint32_t frame_bitendian;
		uint32_t frame_bitsperword;
		uint32_t frame_type;
		bool frame_white_en;
		bool frame_crc_en;
		bool frame_accept_crc_errors;
		bool frame_header_en; //Set to true to enable a distinct header from the payload
		uint32_t frame_header_size; //Define the number of bytes that make up the header. Include the variable length byte(s)
		bool frame_header_calc_crc; //Set to true to include the header bytes in the payload CRC
		bool frame_header_include_crc; //Set to true to check/transmit crc specifically for the header
		bool frame_header_white_en; //Set to true to enable whitening over the header
		uint16_t frame_fixed_length; //Define the number of bytes in the payload. This does not include the length of the header if used. Header + Payload must be less than 4096 bytes
		//variable length
		uint16_t varlen_numbits; //Define the size of the variable length field in bits
		uint32_t varlen_byteendian;
		uint16_t varlen_loc;
		uint32_t varlen_bitendian;
		uint8_t varlen_shift; //Define the location of the least significant bit of the variable length field
		uint16_t varlen_minlength; //Define the minimum value of the variable length field
		uint16_t varlen_maxlength; //Define the maximum value of the variable length field. Cannot exceed the variable length size
		bool varlen_includecrc; //Set to true if the crc bytes are included in the variable length
		uint16_t varlen_adjust; //Value to add to the variable length extracted from the packet when calculating the total payload length to receive.  A positive number here indicates the payload will be larger than the length value extracted from the variable length bits
		//frame type
		uint8_t frametype_loc; //Define the zero-based start location in the frame that holds the frame type encoding
		uint8_t frametype_mask; //Define the bitmask to extract the frame type in the byte
		uint8_t frametype_bits; //Define the number of bits of the frame type field
		uint8_t frametype_lsbit; //Define the bit location of the frame type's least significant bit
		uint16_t frametype_lengths[8]; //Define the frame length of each frame type
		bool frametype_valid[8]; //Define the valid frame types
		bool frametype_filter[8]; //Define the frame types that should have address filtering applied
		//CRC
		uint32_t 	crc_poly;
		uint32_t 	crc_seed;
		uint8_t 	crc_size;
		uint8_t 	crc_inputbitorder:1;
		uint8_t 	crc_inputpadding:1;
		uint8_t 	crc_byteendian:1;
		uint8_t 	crc_bitreverse:1;
		uint8_t 	crc_outputbitorder:1;
		uint8_t 	crc_invert:1;
		//Whitening
		uint32_t 	white_poly;
		uint32_t 	white_seed;
		uint32_t 	white_outputbit;
		uint32_t 	white_xorfeedback;
		uint32_t 	white_feedbacksel;
		//Preamble
		uint8_t preamble_pattern; //Preamble Base Pattern; Minimum repeated portion of the preamble such as binary 01 or 10
		uint32_t preamble_length; //Preamble Length Total; Total length of the preamble
		uint32_t preamble_pattern_len; //Preamble Pattern Length; Length of the preamble pattern in bits. This will be set to 2 for a simple 01 or 10 preamble pattern
		//Syncword
		uint32_t syncword_0; //Default sync word.  Stored with the last bit transmitted in the LSB
    uint32_t syncword_1; //Alternative sync word for dual sync word cases.  Stored with the last bit transmitted in the LSB
    uint8_t syncword_length; //Length of the sync word in bits
    bool syncword_tx_skip; //Sync Word TX Skip
		//Symbol Coding
		uint32_t dsss_chipping_code; //DSSS Chipping Code Base
		uint32_t dsss_len; //DSSS Chipping Code Length
		uint32_t dsss_spreading_factor; //DSSS Spreading Factor
		uint32_t diff_encoding_mode; //Differential Encoding Mode
		uint32_t manchester_mapping; //Manchester Code Mapping
		uint32_t symbol_encoding; //Symbol Encoding
		//Channel Coding
		uint32_t fec_algorithm; //FEC Algorithm
		//Advanced
		//Timing detection
		uint8_t errors_in_timing_window; //Number of Errors Allowed
    uint8_t number_of_timing_windows; //Number of Timing Windows
		uint8_t symbols_in_timing_window; //Number of Symbols in Timing Window
    uint8_t timing_resync_period; //Timing Resync Period
		uint8_t timing_detection_threshold; //Timing Detection Threshold
    uint32_t timing_sample_threshold; //Timing Samples Threshold. Start timing detection only if samples for timing detection are stronger than this threshold
		uint32_t timing_sampling_delay;
		//AGC
		uint8_t agc_speed;
    uint8_t agc_period; //AGC power measurement period
		uint8_t agc_setting_delay;
		uint8_t agc_hysteresis; //Hysteresis level for AGC in dB
		int8_t agc_power_target; //Power target in dBm at channel filter output, dBm
		//AFC
		uint32_t freq_comp_mode; //Frequency Compensation
		float afc_step_scale; //Frequency Compensation Step Scale
		uint32_t afc_freq_limit; //Frequency Compensation Limit, kHz
		uint8_t frequency_offset_period; //Frequency Offset Period
		uint8_t afc_period; //Period used to estimate frequency offset in AFC loop
		//Channel Bandwidth
		uint32_t acq_ch_bw; //Acquision Channel Bandwidth, in Hz
		uint32_t if_freq; //IF
		//Miscellaneous
		uint8_t rssi_period; //RSSI Update Period
		uint32_t tx_pll_bw; //PLL Bandwidth in TX mode
		uint32_t rx_pll_bw; //PLL Bandwidth in RX mode
		uint8_t ook_slicer_level; //Level to slice OOK symbols at as referenced from signal
		int32_t ircal_power_level; //IR cal power level
		//Length of the First Word
		//Bit position of dynamic length byte
		
		//Antenna diversity
		//Power amplifier
		int32_t txpower;
		uint32_t txramptime;
		uint8_t txpactune;
		//LNA settings
		uint8_t rxpactune;
		
		uint8_t answermode;
		uint8_t printmode;
		
		//HFXO temp. drift compensation
		int32_t K_Ctune_Khz;
		int32_t K_Ctune3_Khz;
		int32_t K_Ctune2_Khz; 
		int32_t K_Ctune1_Khz;
		int32_t K_Ctune0_Khz;
		
	}RadioConfig_t;
	
	void RADIO_InitConfigStructure(void);
	void RADIO_Config(void);
	extern RadioConfig_t RadioConfig;

#endif

