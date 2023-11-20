
#include "FRAME.h"

    #define FRAME_BITENDIAN_LSB_FIRST 	0 //Least significant bit is transmitted first over the air
    #define FRAME_BITENDIAN_MSB_FIRST	1		//Most significant bit is transmitted first over the air'],
    #define FRAME_FIXED_LENGTH 			0 //The frame length is fixed and never changes'],
    #define FRAME_VARIABLE_LENGTH		1  //The frame length is determined by an explicit length field within the packet. Requires header to be enabled.'],
    #define FRAME_FRAME_TYPE			2 		  //The packet length is determined from an encoded set of bit that implicitly determines the length'],
    #define VAR_LEN_BYTEENDIAN_LSB_FIRST 		0 	//The least significant byte of the variable length field is transmitted over the air first
    #define VAR_LEN_BYTEENDIAN_MSB_FIRST		1 		//The most significant byte of the variable length field is transmitted over the air first
    #define VAR_LEN_BITENDIAN_LSB_FIRST			0 	//The variable length field is transmitted least signficant bit first
    #define VAR_LEN_BITENDIAN_MSB_FIRST			1 		//The variable length field is transmitted most significant bit first
	
    void FRAME_ConfigFrame(void);
    void FRAME_Preset(void);
    void FRAME_ConfigHeader(void);
    void FRAME_ConfigPayloadWithHeader(void);
    void FRAME_ConfigFixedLengthWithHeader(void);
    void FRAME_ConfigFixedLengthNoHeader(void);
    void FRAME_ConfigVariableLen(void);
    void FRAME_ConfigFcdForFrameType(void);
    void FRAME_ConfigFrameType(void);
    void Frame_CalcFrame(uint32_t bitendian);
    void FRAME_ConfigFcd(uint8_t index, FCDconfig_t *config);
 
    uint32_t firstframe_bitsperword;
    bool accept_crc_errors;
    
    // Frame Type Configurations --------
    //FRAME_TYPE
    uint8_t frame_type_loc; //Define the zero-based start location in the frame that holds the frame type encoding
    uint8_t frame_type_mask; //Define the bitmask to extract the frame type in the byte
    uint8_t frame_type_bits; //Define the number of bits of the frame type field
    uint8_t frame_type_lsbit; //Define the bit location of the frame type's least significant bit
    uint16_t frame_type_lengths[8]; //Define the frame length of each frame type
    bool frame_type_valid[8]; //Define the valid frame types
    bool frame_type_filter[8]; //Define the frame types that should have address filtering applied
	


    //Internal variables
    //VARIABLE_LENGTH_LOCATION
    uint16_t var_length_loc; //Define the zero-based start location in the header that holds the first byte of the variable length field
    //VARIABLE_LENGTH_NUMBYTES
    uint16_t var_length_numbytes; //Define the size of the variable length field in bytes
    //Internal HEADER_SIZE
    //uint16_t header_size_internal; //Internal representation of header size. 0 for no header
	
//////////////////////////////////////////////////////////////////////////

	void FRAME_Init(void) //global function
	{
		//copy parameters
		uint32_t i;
		//-------- General Frame Configurations --------
		// BIT_ORDER
		//FIRSTFRAME_BITSPERWORD
		firstframe_bitsperword = RadioConfig.frame_bitsperword;
		//FRAME_LENGTH
		//-------- Payload Configurations --------
		accept_crc_errors = RadioConfig.frame_accept_crc_errors;

		// Frame Type Configurations --------
		//FRAME_TYPE
		frame_type_loc = RadioConfig.frametype_loc;
		frame_type_mask = RadioConfig.frametype_mask;
		frame_type_bits = RadioConfig.frametype_bits;
		frame_type_lsbit = RadioConfig.frametype_lsbit;
		for(i = 0; i < 8; i++)
		{
			frame_type_lengths[i] = RadioConfig.frametype_lengths[i];
			frame_type_valid[i] = RadioConfig.frametype_valid[i];
			frame_type_filter[i] = RadioConfig.frametype_filter[i];
		}
		FRAME_ConfigFrame();
	}
	
 void FRAME_ConfigFrame(void) //calc_frame_length
	{
       
    if (RadioConfig.frame_type == FRAME_FIXED_LENGTH)
		{
      FRAME_Preset();
			if (RadioConfig.frame_header_en == true)  FRAME_ConfigFixedLengthWithHeader();
      else FRAME_ConfigFixedLengthNoHeader();
		}

    else 
		{
			if (RadioConfig.frame_type == FRAME_VARIABLE_LENGTH && RadioConfig.frame_header_en == true)
			{
				//Variable Length requires headers
				FRAME_ConfigHeader();
				//Configure rest of payload options
				FRAME_ConfigPayloadWithHeader();
				//Variable Length
				FRAME_ConfigVariableLen();
				//Use FCD0/2 for first subframe then FCD1/3 is used for all following subframes
				FRC->CTRL &= ~(FRC_CTRL_TXFCDMODE_Msk | FRC_CTRL_RXFCDMODE_Msk);
				FRC->CTRL |= (2 << FRC_CTRL_TXFCDMODE_Pos) | (2 << FRC_CTRL_RXFCDMODE_Pos);
			}
			else 
			{
				if (RadioConfig.frame_type == FRAME_FRAME_TYPE)
				{
					FRAME_Preset();
					FRAME_ConfigFcdForFrameType();
					//Frame Type
					FRAME_ConfigFrameType();
				}
			}
		}
	}
	
//////////////////////////////////////////////////////////////	

    void FRAME_Preset(void) //_calc_frame_length_defaults
	{
        FRC->WCNTCMP0 = 0;
        FRC->WCNTCMP1 = 0;
        FRC->DFLCTRL = 0;
        FRC->MAXLENGTH = 0;
	}

    void FRAME_ConfigHeader(void) //_configure_header
	{
     FCDconfig_t config;
	   config.skipwhite = !(RadioConfig.frame_header_white_en);
	   config.skipcrc = false;
	   config.calccrc = RadioConfig.frame_header_calc_crc;
	   config.includecrc = RadioConfig.frame_header_include_crc;
	   config.buf = 0;
	   config.words = RadioConfig.frame_header_size - 1;
	   //Configure TX FCD
	   FRAME_ConfigFcd(0, &config);
	   //Configure RX FCD
	   config.buf = 1;
	   FRAME_ConfigFcd(2, &config);
    }

    void FRAME_ConfigPayloadWithHeader(void) //_configure_payload_with_header
	{
		FCDconfig_t config;
		
		config.skipwhite = !(RadioConfig.frame_white_en);
		config.skipcrc = false;
		config.calccrc = RadioConfig.frame_crc_en;
		config.includecrc = RadioConfig.frame_crc_en;
		config.buf = 0;
		config.words = 0xff;
		//Configure TX FCD
		FRAME_ConfigFcd(1, &config);
		//Configure RX FCD
		config.buf = 1;
		FRAME_ConfigFcd(3, &config);
	}
	

  void FRAME_ConfigFixedLengthWithHeader(void) //_fixed_length_with_header
	{
   FRC->WCNTCMP0 = RadioConfig.frame_fixed_length + RadioConfig.frame_header_size - 1;
        //Header Configuration
   FRAME_ConfigHeader();
        //Payload Configuration
    FRAME_ConfigPayloadWithHeader();
        //Use FCD0/2 for first subframe then FCD1/3 is used for all following subframes
		FRC->CTRL &= ~(FRC_CTRL_TXFCDMODE_Msk | FRC_CTRL_RXFCDMODE_Msk);
		FRC->CTRL |= (2 << FRC_CTRL_TXFCDMODE_Pos) | (2 << FRC_CTRL_RXFCDMODE_Pos);
	}
 

  void FRAME_ConfigFixedLengthNoHeader(void) //_fixed_length_no_header
	{
        FCDconfig_t config;
		
		FRC->WCNTCMP0 = RadioConfig.frame_fixed_length - 1;
		config.skipwhite = !(RadioConfig.frame_white_en);
		config.skipcrc = false;
		config.calccrc = RadioConfig.frame_crc_en;
		config.includecrc = RadioConfig.frame_crc_en;
		config.buf = 0;
		config.words = 0xff;
        //Configure TX FCD
		FRAME_ConfigFcd(0, &config);
        //Configure RX FCD
		config.buf = 1;
		FRAME_ConfigFcd(2, &config);
		
		config.skipwhite = false;
		config.skipcrc = false;
		config.calccrc = false;
		config.includecrc = false;
		config.buf = 0;
		config.words = 0;
		FRAME_ConfigFcd(1, &config); // Turn off this fcd
		FRAME_ConfigFcd(3, &config); // Turn off this fcd
		FRC->CTRL &= ~(FRC_CTRL_RXFCDMODE_Msk | FRC_CTRL_TXFCDMODE_Msk);
	}


    void FRAME_ConfigVariableLen(void) //_configure_variable_length
	{
		FRC->WCNTCMP0 = 0;
        FRC->WCNTCMP1 = var_length_loc;
        FRC->MAXLENGTH = RadioConfig.varlen_maxlength + RadioConfig.frame_header_size - 1;
		FRC->DFLCTRL = ((RadioConfig.varlen_minlength + RadioConfig.frame_header_size - 1) << FRC_DFLCTRL_MINLENGTH_Pos) | 
		(RadioConfig.varlen_numbits << FRC_DFLCTRL_DFLBITS_Pos) | ((RadioConfig.frame_header_size + RadioConfig.varlen_adjust -1) << FRC_DFLCTRL_DFLOFFSET_Pos) | 
		(RadioConfig.varlen_shift << FRC_DFLCTRL_DFLSHIFT_Pos);
		if(RadioConfig.varlen_includecrc == true) FRC->DFLCTRL |= FRC_DFLCTRL_DFLINCLUDECRC_Msk;
        if (RadioConfig.varlen_bitendian != RadioConfig.frame_bitendian) FRC->DFLCTRL |= FRC_DFLCTRL_DFLBITORDER_Msk; //FRC_DFLCTRL_DFLBITORDER = 1;
        //DFLMODE
		if (var_length_numbytes == 1) FRC->DFLCTRL |= (1 << FRC_DFLCTRL_DFLMODE_Pos); //FRC_DFLCTRL_DFLMODE = 1; //SINGLEBYTE
			else //Two bytes
			{		
				if (RadioConfig.varlen_byteendian == VAR_LENGTH_BYTEENDIAN_LSB_FIRST) FRC->DFLCTRL |= (3 << FRC_DFLCTRL_DFLMODE_Pos); //DUALBYTELSBFIRST
				else FRC->DFLCTRL |= (4 << FRC_DFLCTRL_DFLMODE_Pos); //DUALBYTEMSBFIRST
			}

	}

    void FRAME_ConfigFcdForFrameType(void) // Only use one frame descriptor
	{
    FCDconfig_t fcdconfig;
		
		fcdconfig.skipwhite = !(RadioConfig.frame_white_en);
		fcdconfig.skipcrc = false;
		fcdconfig.calccrc = RadioConfig.frame_crc_en;
		fcdconfig.includecrc = RadioConfig.frame_crc_en;
		fcdconfig.buf = 0;
		fcdconfig.words = 0xff;
        //Configure TX FCD
		FRAME_ConfigFcd(0, &fcdconfig);
		FRC->CTRL &= ~FRC_CTRL_TXFCDMODE_Msk; 
        //Configure RX FCD
		fcdconfig.buf = 1;
		FRAME_ConfigFcd(2, &fcdconfig);
        FRC->CTRL &= ~FRC_CTRL_RXFCDMODE_Msk;
		
		fcdconfig.skipwhite = false;
		fcdconfig.skipcrc = false;
		fcdconfig.calccrc = false;
		fcdconfig.includecrc = false;
		fcdconfig.buf = 0;
		fcdconfig.words = 0;
		FRAME_ConfigFcd(1, &fcdconfig); // Turn off this fcd
		FRAME_ConfigFcd(3, &fcdconfig); // Turn off this fcd
	}
	
	
    void FRAME_ConfigFrameType(void) //_configure_frame_type
	{
	/*	uint32_t i;
        
		BIT_MASK = {0: 0x00, 1: 0x01, 2: 0x03, 3: 0x07};
        // Handle Code Generation in RAIL Adapter to create C structures
        //Move from discrete inputs to a list
        num_entries = 1 << frame_type_bits; //(2**frame_type_bits);
        frame_type_lengths = [];
        frame_type_valid = [];
        frame_type_filter = [];
        for (i = 0; i < num_entries; i++)
		{
          frame_type_lengths.append(eval("frame_type_{}_length".format(i)));
          frame_type_valid.append(eval("frame_type_{}_valid".format(i)));
          frame_type_filter.append(eval("frame_type_{}_filter".format(i)));
		}
        //Set FRC_WCNTCMP0 to the size of the header
        // The seqeuncer will write this register after it decodes the frame type
        // We just want to provide enough room in advance so that we don't complete the frame too early
        // Init to the smallest valid length
        min_size = 0xFF;
        for i in range(len(frame_type_lengths)):
          if (frame_type_valid[i] == true):
            if (frame_type_lengths[i] < min_size):
              min_size = frame_type_lengths[i]
        FRC_WCNTCMP0_FRAMELENGTH = min_size - 1;
        frame_type_mask = BIT_MASK[frame_type_bits] << frame_type_lsbit;
		*/
	}


  void Frame_CalcFrame(uint32_t bitendian) //Configure general frame configurations
	{
		FRC->CTRL &= ~FRC_CTRL_BITSPERWORD_Msk;
		FRC->CTRL |= (7 << FRC_CTRL_BITSPERWORD_Pos); //8 bits
		FRC->CTRL &= ~FRC_CTRL_BITORDER_Msk;
		if(bitendian == VAR_LENGTH_BITENDIAN_MSB_FIRST) FRC->CTRL |= FRC_CTRL_BITORDER_Msk;
		else FRC->CTRL &= ~FRC_CTRL_BITORDER_Msk;
	}


  void FRAME_ConfigFcd(uint8_t index, FCDconfig_t *config)
	{
		uint32_t skipwhite = 0;
		uint32_t skipcrc = 0;
		uint32_t calccrc = 0;
		uint32_t includecrc = 0;
		uint32_t buf;
		uint32_t words;
		
		if(config->skipwhite == true) skipwhite = 1;
		if(config->skipcrc == true) skipcrc = 1;
		if(config->calccrc == true) calccrc = 1;
		if(config->includecrc == true) includecrc = 1;
		buf = config->buf;
		if(buf > 3) buf = 3;
		words = config->words;
		(&FRC->FCD0)[index] = (skipwhite << FRC_FCD0_SKIPWHITE_Pos) | (skipcrc << FRC_FCD0_SKIPCRC_Pos) | 
		(calccrc << FRC_FCD0_CALCCRC_Pos) | (includecrc << FRC_FCD0_INCLUDECRC_Pos) | (buf << FRC_FCD0_BUFFER_Pos) | words;
	}
	



