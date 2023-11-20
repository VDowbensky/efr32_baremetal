#include "RADIO_config.h"

void RADIO_SetAndForgetWrite(void);
void RADIO_SeqInit(void *src,uint32_t len);


RadioConfig_t RadioConfig __attribute__((aligned (4)));
const uint32_t generated_phyInfo[] = {
  0UL,
  0x00100000UL, // 16.0
}; //freqOffsetFactor; must be variable calculated according deviation
//upper 4 bytes - integer part
//lower 4 bytes - fractional part
//fxo is fixed at 38400000
//freq_gain = 0.21875 = m * 2**(2-e);
//freq_offset_scale = fxo / (freq_gain * dec0 * dec1 * dec2 * 256.0);
//freqOffsetFactor = freqOffsetScale * (1.0/synthResolution);
//freqOffsetFactor_fxp = (long(freqOffsetFactor*65536) & 0xFFFFFFFF);


void RADIO_InitConfigStructure(void)
{
		uint32_t tmp;	
		uint32_t i;
		//RF frequency
	  RadioConfig.Initialized = HW_MAGIC_NUMBER;
		RadioConfig.base_freq = 868000000;
		RadioConfig.ch_spacing = 100000;
		RadioConfig.loside = 1;
		//Channels
		RadioConfig.min_channel = 0;
		RadioConfig.max_channel = 63;
	  RadioConfig.default_channel = 0;
		//Crystal
    RadioConfig.xtal_frequency_hz = 38400000;//EFR32 crystal clock frequency
		RadioConfig.rx_xtal_error_ppm = 0; //Crystal clock tolerance of receiver.
    RadioConfig.tx_xtal_error_ppm = 0; //Crystal clock tolerance of the transmitter
		//BUFC
		RadioConfig.txbuffersize = 2;
		RadioConfig.txbufferthreshold = 0x2020;
		RadioConfig.txbufferthresholdmode = 1;
		RadioConfig.rxbuffersize = 2;
		RadioConfig.rxbufferthreshold = 0xaf;
		RadioConfig.rxbufferthresholdmode = 0;
		RadioConfig.rxlenbuffersize = 0;
		RadioConfig.rxlenbufferthreshold = 0x3e; 
		RadioConfig.rxlenbufferthresholdmode = 0;
		//RadioConfig.ackbuffersize = 0;
		//RadioConfig.ackbufferthreshold = 0xff;
		//RadioConfig.ackbufferthresholdmode  = 0; 
		//Modem
		RadioConfig.modulation_type = MOD_TYPE_FSK2;
		RadioConfig.chiprate = 50000;
    RadioConfig.deviation = 25000; //Frequency deviation used in FSK modulation schemes
		RadioConfig.baudrate_tol_ppm = 0; //Maximum baud rate error of the expected signal
		RadioConfig.shaping = MOD_SHAPING_GAUSSIAN;
		RadioConfig.shaping_filter_param = 0.5;//BT value for Gaussian  and roll-off factor for Raised Cosine pulse shaping filter
		RadioConfig.mapfsk = FSK_MAP0;
		RadioConfig.async_direct_mode = false;//asynchronous_rx_enable; //Asynchronous RX mode enabled
		//Frame settings
		//general & fixed length
		RadioConfig.frame_bitendian = BIT_ORDER_LSB_FIRST;
		RadioConfig.frame_bitsperword = 7;
		RadioConfig.frame_type = FRAME_FIXED_LENGTH;
		RadioConfig.frame_white_en = true;
		RadioConfig.frame_crc_en = true;
		RadioConfig.frame_accept_crc_errors = false;
		RadioConfig.frame_header_en = false; //Set to true to enable a distinct header from the payload 
		RadioConfig.frame_header_size = 0; //Define the number of bytes that make up the header. Include the variable length byte(s)
		RadioConfig.frame_header_calc_crc = false; //Set to true to include the header bytes in the payload CRC
		RadioConfig.frame_header_include_crc = false; //Set to true to check/transmit crc specifically for the header
		RadioConfig.frame_header_white_en = false; //Set to true to enable whitening over the header
		RadioConfig.frame_fixed_length = 32; //Define the number of bytes in the payload. This does not include the length of the header if used. Header + Payload must be less than 4096 bytes
		//variable length
		RadioConfig.varlen_numbits = 0; //Define the size of the variable length field in bits
		RadioConfig.varlen_byteendian = VAR_LENGTH_BYTEENDIAN_LSB_FIRST;
		RadioConfig.varlen_loc = 0;
		RadioConfig.varlen_bitendian = VAR_LENGTH_BITENDIAN_LSB_FIRST;
		RadioConfig.varlen_shift = 0; //Define the location of the least significant bit of the variable length field
		RadioConfig.varlen_minlength = 0; //Define the minimum value of the variable length field
		RadioConfig.varlen_maxlength = 0; //Define the maximum value of the variable length field. Cannot exceed the variable length size
		RadioConfig.varlen_includecrc = false; //Set to true if the crc bytes are included in the variable length
		RadioConfig.varlen_adjust = 0; //Value to add to the variable length extracted from the packet when calculating the total payload length to receive.  A positive number here indicates the payload will be larger than the length value extracted from the variable length bits
		//frame type
		RadioConfig.frametype_loc =  0;//Define the zero-based start location in the frame that holds the frame type encoding
		RadioConfig.frametype_mask = 0; //Define the bitmask to extract the frame type in the byte
		RadioConfig.frametype_bits = 3; //Define the number of bits of the frame type field
		RadioConfig.frametype_lsbit = 0; //Define the bit location of the frame type's least significant bit
		for(i = 0; i < 8; i++) RadioConfig.frametype_filter[i] = false;
		for(i = 0; i < 8; i++) RadioConfig.frametype_lengths[i] = 32;
		for(i = 0; i < 8; i++) RadioConfig.frametype_valid[i] = false;
		//CRC
		RadioConfig.crc_poly = CRC_POLY_CRC_16;
		RadioConfig.crc_seed = 0;
		RadioConfig.crc_size = 2;
		RadioConfig.crc_inputbitorder = 1;
		RadioConfig.crc_inputpadding = 0;
		RadioConfig.crc_byteendian = 0;
		RadioConfig.crc_bitreverse = 1;
		RadioConfig.crc_outputbitorder = 0;
		RadioConfig.crc_invert = 0;
		//Whitening
		RadioConfig.white_poly = WHITE_POLY_PN9;
		RadioConfig.white_seed = 0xffff;
		RadioConfig.white_outputbit = 0;
		RadioConfig.white_xorfeedback = 0;
		RadioConfig.white_feedbacksel = 0;
		//Preamble
		RadioConfig.preamble_pattern = 1; //Preamble Base Pattern; Minimum repeated portion of the preamble such as binary 01 or 10
		RadioConfig.preamble_length = 40; //Preamble Length Total; Total length of the preamble
		RadioConfig.preamble_pattern_len = 2; //Preamble Pattern Length; Length of the preamble pattern in bits. This will be set to 2 for a simple 01 or 10 preamble pattern
		//Syncword
		RadioConfig.syncword_0 =  0x3693; //0x2dd4;//Default sync word.  Stored with the last bit transmitted in the LSB
    RadioConfig.syncword_1 = 0; //Alternative sync word for dual sync word cases.  Stored with the last bit transmitted in the LSB
    RadioConfig.syncword_length = 16; //Length of the sync word in bits
    RadioConfig.syncword_tx_skip = false; //Sync Word TX Skip
		//Symbol Coding
		RadioConfig.dsss_chipping_code = 0;//DSSS Chipping Code Base
		RadioConfig.dsss_len = 0;//DSSS Chipping Code Length
		RadioConfig.dsss_spreading_factor = 0;//DSSS Spreading Factor
		RadioConfig.diff_encoding_mode = DIFF_ENCODING_DISABLED; //Differential Encoding Mode
		RadioConfig.manchester_mapping = MANCHESTER_MAPPING_DEFAULT; //Manchester Code Mapping
		RadioConfig.symbol_encoding = SYMBOL_ENCODING_NRZ; //Symbol Encoding
		//Channel Coding
		RadioConfig.fec_algorithm = FEC_NONE; //FEC Algorithm
		//Advanced
		//Timing detection
		RadioConfig.errors_in_timing_window =  0;//Number of Errors Allowed
    RadioConfig.number_of_timing_windows = 1;//Number of Timing Windows
		RadioConfig.symbols_in_timing_window = 16; //Number of Symbols in Timing Window
    RadioConfig.timing_resync_period = 1; //Timing Resync Period
		RadioConfig.timing_detection_threshold = 31; //Timing Detection Threshold
    RadioConfig.timing_sample_threshold = 0; //10; //Timing Samples Threshold. Start timing detection only if samples for timing detection are stronger than this threshold
		RadioConfig.timing_sampling_delay = 0; //Timing Sampling delay
		//AGC
		RadioConfig.agc_speed = AGC_SPEED_NORMAL;
    RadioConfig.agc_period =  3;//AGC power measurement period
		RadioConfig.rssi_period = 1;//AGC power measurement period - ???
		RadioConfig.agc_setting_delay = 29;
		RadioConfig.agc_hysteresis =  3;//Hysteresis level for AGC in dB
		RadioConfig.agc_power_target = -2; //Power target in dBm at channel filter output, dBm
		//AFC
		RadioConfig.freq_comp_mode =  FREQ_COMP_DISABLED;//Frequency Compensation
		RadioConfig.afc_step_scale = 0; //Frequency Compensation Step Scale
		RadioConfig.afc_freq_limit = 0; //Frequency Compensation Limit, kHz
		RadioConfig.frequency_offset_period = 0; //Frequency Offset Period
		RadioConfig.afc_period = 0; //Period used to estimate frequency offset in AFC loop
		//Channel Bandwidth
		RadioConfig.acq_ch_bw = 100000; //Acquision Channel Bandwidth, in Hz
		RadioConfig.if_freq = 400000; //IF
		//Miscellaneous
		RadioConfig.tx_pll_bw = PLL_BW_TX_354KHz; //PLL Bandwidth in TX mode
		RadioConfig.rx_pll_bw = PLL_BW_RX_354KHz; //PLL Bandwidth in RX mode
		RadioConfig.ook_slicer_level = 3; //empirically determined to work well used as default value
		RadioConfig.ircal_power_level = -20; //IR cal power level
		
		//PA, LNA
		RadioConfig.txpower = 0; //dBm
		RadioConfig.txramptime = 10;
    RadioConfig.txpactune = TX_PACTUNE;
    RadioConfig.rxpactune = RX_PACTUNE;
		RadioConfig.answermode = 1;
		RadioConfig.printmode = 1;
		
		RadioConfig.K_Ctune_Khz = (int32_t)(K_CTUNE_KHZ * 1000000);
		RadioConfig.K_Ctune3_Khz = (int32_t)(K_CTUNE3_KHZ * 1000000);
		RadioConfig.K_Ctune2_Khz = (int32_t)(K_CTUNE2_KHZ * 1000000); 
		RadioConfig.K_Ctune1_Khz = (int32_t)(K_CTUNE1_KHZ * 1000000);
		RadioConfig.K_Ctune0_Khz = (int32_t)(K_CTUNE0_KHZ * 1000000);
}

void RADIO_Config(void)
{
	CMU_ClockEnable(0x63400,true); //3
	CMU_ClockEnable(0x60400,true); //0 - PROTIMER
	CMU_ClockEnable(0x64400,true); //4
	CMU_ClockEnable(0x67400,true); //7
	CMU_ClockEnable(0x66400,true); //6
	CMU_ClockEnable(0x65400,true); //5
	CMU_ClockEnable(0x62400,true); //2
	CMU_ClockEnable(0x68400,true); //8

	RADIO_SetAndForgetWrite();
  //sequencer init
	//RADIO_SeqInit(&genericSeqProg, GENERIC_SEQPROG_SIZE);
	RADIO_SeqInit((void *)&genericSeqProg, GENERIC_SEQPROG_SIZE);
  //TEMPCAL_Init();
	//sequencer timing init
	RADIO_RxSearchTimeSet(0);
	RADIO_TxToRxSearchTimeSet(0);
	RADIO_RxWarmTimeSet(100);
	RADIO_TxToRxTimeSet(100);
	RADIO_TxToTxTimeSet(100);
	RADIO_RxToTxTimeSet(100);
	RADIO_RxFrameToTxTimeSet(100);
	RADIO_TxWarmTimeSet(100); 
//  RADIO_PTI_Enable();
	if (RAC->CTRL & RAC_CTRL_FORCEDISABLE_Msk) RAC->CTRL &= ~RAC_CTRL_FORCEDISABLE_Msk; //FORCEDISABLE
//  GENERIC_PHY_ResetAddressFiltering();
	SEQ_CONTROL_REG = SEQ_CONTROL_REG | 8;
	PROTIMER_Init();
  //PROTIMER_Start();
  //PROTIMER_CCTimerCapture(0,0xc00000);
  //PROTIMER_CCTimerCapture(1,0x200000);
  //RFRAND_SeedProtimerRandom();
	//RAC configuration (TBD: using RFIF.c functions) 
	SEQ->REG070 = 0; //GENERIC_PHY_Init
	SEQ->PHYINFO = 	(uint32_t) &generated_phyInfo;
	SEQ->MISC = 0x00000000;
	RFIF_SetLpfBw(); //SEQ->SYNTHLPFCTRLRX = 0x0003C002;//SEQ->SYNTHLPFCTRLTX = 0x0003C002;	
	RAC->IFFILTCTRL = 0x008800E0; //

	MODEM_init(); //maybe splitted
	//FRC
	FRC_init();
	//Whitening
	WHITE_Init();
	//BUFC
	BUFC_Init();
	//SYNTH
	SYNTH_init();
	//AGC
	AGC_Init();
	//CRC
	CRC_Init();
	//PA
	PA_SetPowerDbm(RadioConfig.txpower);
	PA_RampTimeSet(RadioConfig.txramptime);
	
	PA_CTuneSet(RadioConfig.txpactune,RadioConfig.rxpactune);
	//radio_SetTxTransitions(RAIL_RF_STATE_RX,RAIL_RF_STATE_RX);
	//radio_SetTxTransitions(RAIL_RF_STATE_IDLE,RAIL_RF_STATE_IDLE);
	//radio_SetRxTransitions(RAIL_RF_STATE_RX,RAIL_RF_STATE_RX);
	//radio_SetRxTransitions(RAIL_RF_STATE_IDLE,RAIL_RF_STATE_IDLE);
	RxEvents = 0;
	TxEvents = 0;
	HardEvents = 0;
	masterID = SYSTEM_GetUnique() & 0x00000000ffffffff;
	Channel = RadioConfig.default_channel;
	SYNTH_SetChannel(Channel,false);
	//RADIO_CtuneCorrection();
	radio_startrx();
	RADIO_CtuneCorrection();
	//RAC->SEQCMD = RAC_SEQCMD_HALT_Msk;
}

//helpers
void RADIO_SetAndForgetWrite(void)

{
	SYSTEM_ChipRevision_TypeDef revision;

	SYSTEM_ChipRevisionGet(&revision);
	RFIF_SetIfadcCtrlReg(); //RAC->IFADCCTRL = 0x1153e6c0;
	RFIF_SetIfpgaCtrlReg(); //RAC->IFPGACTRL = 0x87f6;
	RFIF_SetlnaMixCtrl1Reg(); //RAC->LNAMIXCTRL1 = 0x880;
	RFIF_SetVcoCtrlReg(); //RAC->VCOCTRL = 0xf00277a;
	if((revision.major == 0x01) && (revision.minor < 2)) SYNTH->VCOGAIN = 0x28;
	RAC->LNAMIXCTRL = 0;
	RAC->SYNTHREGCTRL = (3 << RAC_SYNTHREGCTRL_CHPLDOVREFTRIM_Pos) | (3 << RAC_SYNTHREGCTRL_CHPLDOAMPCURR_Pos) | (3 << RAC_SYNTHREGCTRL_VCOLDOVREFTRIM_Pos) |
	(3 << RAC_SYNTHREGCTRL_VCOLDOAMPCURR_Pos) | (3 << RAC_SYNTHREGCTRL_MMDLDOVREFTRIM_Pos) | (2 << RAC_SYNTHREGCTRL_MMDLDOVREFTRIM_Pos) | (3 << RAC_SYNTHREGCTRL_MMDLDOAMPCURR_Pos);
	RAC->SR3 = 0;
	BUS_RegMaskedSet(&RAC->CTRL, RAC_CTRL_ACTIVEPOL_Msk | RAC_CTRL_PAENPOL_Msk | 	RAC_CTRL_LNAENPOL_Msk);
}

void RADIO_SeqInit(void *src,uint32_t len)

{
  uint32_t t1, t2, t3;
  RAC->SEQCMD = RAC_SEQCMD_HALT_Msk;
  memset((void*)0x21000000,0,0x1000);
  t1 = RAC->STATUS & RAC_RXENSRCEN_SWRXEN_Msk; //dummy read
  RAC->VECTADDR = 0x21000000;
  RAC->SEQCTRL = RAC_SEQCTRL_COMPACT_Msk; 
  INT_Disable();
  memcpy((void *)0x21000000,src,len);
  INT_Enable();
  t3 = TX_PA_CTUNE;
  t2 = RX_PA_CTUNE;
  t1 = PA_SLICES;
  RAC->R6 = 0x21000fcc;
  memset((void *)0x21000f6c,0,0x94);
  PA_SLICES = t1;
  RX_PA_CTUNE = t2;
  TX_PA_CTUNE = t3;
  STIMER_VALUE = -(RADIO_UsToStimerTickCalc(0x3c));
	memset((void*)0x21000efc,0,0x70); //clear sequencer variables
	RAC->SEQCMD = RAC_SEQCMD_RESUME_Msk;
	RAC->SR0 = 0;
	RAC->SR1 = 0;
	RAC->SR2 = 0;
}