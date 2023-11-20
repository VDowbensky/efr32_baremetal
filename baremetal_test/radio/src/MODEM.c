#include "MODEM.h"
#include "RFIF.h"
#include "radio_proc.h"

	void MODEM_ConfigFixup(void);
	void MODEM_DemodResetOnRxsearchEntryEnable(void);
	void MODEM_DemodResetOnRxsearchEntryDisable(void);
	void MODEM_DccalEnable(void);
	void MODEM_DccalDisable(void);
	uint32_t MODEM_ComputeTxBaudrate(void);
	uint32_t MODEM_ComputeTxSymbolRate(void);
	uint32_t MODEM_ComputeTxBitRate(void);
	
	void MODEM_SetModIndexReg(void);
	void MODEM_SetTxBrReg(void);
	void MODEM_SetTxBasesReg(void);
	void MODEM_SetSymbolEncoding(uint32_t coding);
	void MODEM_SetMapFskReg(uint32_t mapfsk);

    void MODEM_SetSyncWordTxSkipReg(bool skip);
    void MODEM_SetSyncWordsReg(void);
    void MODEM_SetSyncBitsReg(uint32_t len);
    void MODEM_SetTimBasesReg(uint32_t timingbases);
    void MODEM_SetAddTimSeqReg(uint32_t ats);
    void MODEM_SetBaseBitsReg(uint32_t bits);
    void MODEM_SetBaseReg(void);
    void MODEM_SetTimThreshReg(uint32_t tr);
    void MODEM_SetPreErrorsReg(uint32_t errors);
    void MODEM_SetDsss0Reg(uint32_t val);
    void MODEM_SetDsssShiftsReg(uint32_t sh);
    void MODEM_SetDsssLenReg(uint32_t len);
    void MODEM_SetDsssDoubleReg(uint32_t dsssdouble);
    void MODEM_SetTrTdEdge(void);
    void MODEM_SetDiffEncModeReg(uint32_t mode);
    void MODEM_SetDualSyncReg(uint32_t val);
    void MODEM_SetRxPinModeReg(bool asynchronous_rx_enable);
    void MODEM_SetFdm0DiffDisReg(void);
		void MODEM_CalcDec0CfOsrReg(void);
		void MODEM_CalcDec1Dec2Reg(void);
    //void MODEM_SetDec0Reg(void);
    //void MODEM_SetDec1Dec2Reg(uint32_t dec1, uint32_t dec2);
    void MODEM_SetCfReg(void);
    void MODEM_SetRxBrReg(void);

    void MODEM_SetFreqGainReg(void);
    void MODEM_SetModTypeReg(uint8_t modulation_type);
    void MODEM_CalcDec1Gain(void);
    void MODEM_SetDec1GainReg(uint32_t gain);
		void MODEM_SetDataFilterReg(uint32_t filter);
    void MODEM_SetPhaseDemodReg(void);
    void MODEM_SetResyncPerReg(uint32_t period);
    void MODEM_SetBrCalReg(uint32_t brcalavg, bool brcalen);
    void MODEM_SetIsiCompReg(bool fsk4);
    void MODEM_SetOffsetPhaseMaskingReg(bool bpsk);
    void MODEM_SetSqiThreshReg(uint32_t threshold);
	
	//Mod_Params_t modparams;
	//Misc_Params_t miscparams;

	//Stream_Coding_t coding;
	//Afc_Params_t afcparams;
	
uint32_t dec0, dec1, dec2, cfosr;
uint32_t txbrnum = 0;
uint32_t txbrden = 0;

uint32_t rxbrint = 0;
uint32_t rxbrnum = 0;
uint32_t rxbrden = 0;

int32_t iffreq;
float if_actual = 0;
float bw_actual = 0;

float txbr_actual = 0;
float rxbr_actual = 0;

bool calc_error = false;
bool brcalen = false;

float freq_gain = 0.0;
float modindex = 0.0;

uint8_t modulation_type;
	
	
//Upper level
void MODEM_IRQHandler(void)

{
	uint32_t flags;
	flags = MODEM->IF & MODEM->IEN;
	MODEM->IFC = flags;

	if(flags & MODEM_IF_TXFRAMESENT_Msk)
	{
		TxEvents |= TXEVENT_FRAMESENT;
	}
	
	if(flags & MODEM_IF_TXSYNCSENT_Msk)
	{
		TxEvents |= TXEVENT_SYNCSENT;
	}
	
	if(flags & MODEM_IF_TXPRESENT_Msk)
	{
		TxEvents |= TXEVENT_PRESENT;
	}
	
	if(flags & MODEM_IF_RXTIMDET_Msk)
	{
		RxEvents |= RXEVENT_TIMDET;
	}
	
	if(flags & MODEM_IF_RXPREDET_Msk)
	{
		RxEvents |= RXEVENT_PREDET;
	}
	
	if(flags & MODEM_IF_RXFRAMEDET0_Msk)
	{
		RxEvents |= RXEVENT_RXFRAMEDET0;
	}
	
	if(flags & MODEM_IF_RXFRAMEDET1_Msk)
	{
		RxEvents |= RXEVENT_RXFRAMEDET1;
	}
	
	if(flags & MODEM_IF_RXTIMLOST_Msk)
	{
		RxEvents |= RXEVENT_TIMLOST;
	}
	
	if(flags & MODEM_IF_RXPRELOST_Msk)
	{
		RxEvents |= RXEVENT_PRELOST;
	}
	
	if(flags & MODEM_IF_RXFRAMEDETOF_Msk)
	{
		RxEvents |= RXEVENT_RXFRAMEDETOF;
	}
	
	if(flags & MODEM_IF_RXTIMNF_Msk)
	{
		RxEvents |= RXEVENT_RXTIMNF;
	}
}


	void MODEM_init(void)
	{
		MODEM->DCCOMP |= MODEM_DCCOMP_DCCOMPEN_Msk | MODEM_DCCOMP_DCESTIEN_Msk; //3; 
		MODEM_DccalEnable();
		//MODEM->MIXCTRL = MODEM_MIXCTRL_DIGIQSWAPEN_Msk;

		MODEM_ModParamsSet();
		MODEM_MiscParamsSet();
		MODEM_StreamCodingSet();
		MODEM_PreParamsSet();
		MODEM_SyncParamsSet();
		//MODEM_AfcParamsSet();
	}
	
/****************************MODEM SETTINGS*************************************/
/****************************MODULATION FORMAT**********************************/

    //TODO: add support for ASK modulation
        //calculate MODINDEX value
        //Equations from Table 5.25 in EFR32 Reference Manual (internal.pdf)	
	void MODEM_ModParamsSet(void)
	{
		//reversed functions
		MODEM->CTRL2 = 0x00002000; //13 DATAFILTER
		MODEM->CTRL4 = 0x03000000; //24,25 ADCSATLEVEL
		MODEM->CTRL5 = 0x00000000;

		//MODFORMAT
		BUS_RegMaskedClear(&MODEM->CTRL0,MODEM_CTRL0_MODFORMAT_Msk);
		switch(RadioConfig.modulation_type)
		{
			case MOD_TYPE_FSK2:
			default: //else raise CalculationException('ERROR: modulation method in input file not recognized');
			break;
			
			case MOD_TYPE_FSK4:
			BUS_RegMaskedSet(&MODEM->CTRL0,1 << MODEM_CTRL0_MODFORMAT_Pos);
			break;
			
			case MOD_TYPE_BPSK:
			BUS_RegMaskedSet(&MODEM->CTRL0,2 << MODEM_CTRL0_MODFORMAT_Pos);
			break;
			
			case MOD_TYPE_DBPSK:
			BUS_RegMaskedSet(&MODEM->CTRL0,3 << MODEM_CTRL0_MODFORMAT_Pos);
			break;
			
			case MOD_TYPE_OQPSK:
			BUS_RegMaskedSet(&MODEM->CTRL0,4 << MODEM_CTRL0_MODFORMAT_Pos);
			break;
			
			case MOD_TYPE_MSK:
			BUS_RegMaskedSet(&MODEM->CTRL0,5 << MODEM_CTRL0_MODFORMAT_Pos);
			break;
			
			case MOD_TYPE_OOK:
			case MOD_TYPE_ASK:
			BUS_RegMaskedSet(&MODEM->CTRL0,6 << MODEM_CTRL0_MODFORMAT_Pos);
			break;
		}
		//MAPFSK
    if(RadioConfig.mapfsk > 7) RadioConfig.mapfsk = 7;
		BUS_RegMaskedClear(&MODEM->CTRL0,MODEM_CTRL0_MAPFSK_Msk);
		BUS_RegMaskedSet(&MODEM->CTRL0,RadioConfig.mapfsk << MODEM_CTRL0_MAPFSK_Pos);
		//SHAPING
		BUS_RegMaskedClear(&MODEM->CTRL0, MODEM_CTRL0_SHAPING_Msk);
		BUS_RegMaskedSet(&MODEM->CTRL0, RadioConfig.shaping << MODEM_CTRL0_SHAPING_Pos);
		MODEM->SHAPING0 = 0x22140A04;
		MODEM->SHAPING1 = 0x504B4133;
		MODEM->SHAPING2	= 0x00000000;
		
		//BR related
		//MODEM->TXBR = 0x00FF5FA0;
		MODEM_SetTxBrReg();
		//MODEM->CF = 0x020200F8; //!!!
		MODEM_SetCfReg();
		//MODEM->RXBR = 0x00000820;
		MODEM_SetRxBrReg();
		MODEM->MODINDEX = 0x00230390;
		MODEM_SetModIndexReg();
		//MODEM_SetFreqGainReg();
	}
	
	void MODEM_MiscParamsSet(void)
	{
		//miscparams.ook_slicer_level = 0; //!!!
		//miscparams.ant_path = 0; //!!!
	}

  void MODEM_PreParamsSet(void)
	{
		uint32_t pre_base, pre_pattern, pre_pattern_mask;
		uint32_t timingbases, threshold;
		int32_t addtimseq;
		//MODEM_SetTimingReg			
		MODEM->TIMING	= 0x02200000; //OFFSUBNUM = 1, OFFSUBDEN = 1
//        # given modulation method determine nominal soft decision values
//        if ((RadioConfig.modulation_type == MOD_TYPE_MSK) || (RadioConfig.modulation_type == MOD_TYPE_OQPSK) || 
//           (RadioConfig.modulation_type == MOD_TYPE_BPSK) || (RadioConfig.modulation_type == MOD_TYPE_DBPSK)) nominal_soft_decision = 64;
//        else if (RadioConfig.modulation_type == MOD_TYPE_FSK2)
//				{
//            if (in_2fsk_opt_scope)
//						{
//                if (bw_ratio < 1.0)  nominal_soft_decision = 64 / freq_gain_scale * bw_ratio;  // Adjust correlation threshold for low BW scenarios
//                else  nominal_soft_decision = 64 / freq_gain_scale;
//						}
//            else  nominal_soft_decision = 64;
//				}
//        else if (RadioConfig.modulation_type == MOD_TYPE_FSK4) nominal_soft_decision = 64;
//        else nominal_soft_decision = 0;
        // given nominal soft decision value and timing window size determine optimal threshold
        // TODO: equation for thresh is empirically derived and does need tuning
//        if (nominal_soft_decision > 0) thresh = timingwindow * nominal_soft_decision / 32.0 - 1.0;
//        else threshold = 0.0;
    if(RadioConfig.async_direct_mode == true) RadioConfig.timing_detection_threshold = 255;
		if (RadioConfig.timing_detection_threshold > 255) RadioConfig.timing_detection_threshold  = 255;
				
		timingbases = RadioConfig.symbols_in_timing_window / RadioConfig.preamble_pattern_len; 
		if(timingbases > 15) timingbases = 15; //RadioConfig.number_of_timing_windows / RadioConfig.preamble_pattern_len
		
    addtimseq = RadioConfig.preamble_length / RadioConfig.symbols_in_timing_window - 2; // one search is done by default
		if (addtimseq < 0) addtimseq = 0;
    if (addtimseq > 0) addtimseq --;
		if (addtimseq > 15) addtimseq = 15;
		
		BUS_RegMaskedClear(&MODEM->TIMING, MODEM_TIMING_TIMTHRESH_Msk | MODEM_TIMING_TIMINGBASES_Msk | MODEM_TIMING_ADDTIMSEQ_Msk);
		BUS_RegMaskedSet(&MODEM->TIMING, (RadioConfig.timing_detection_threshold << MODEM_TIMING_TIMTHRESH_Pos) | (timingbases << MODEM_TIMING_TIMINGBASES_Pos) |
		(addtimseq << MODEM_TIMING_ADDTIMSEQ_Pos));

		MODEM->CTRL3 = 0x00000000;
		//CTRL3	
		if (RadioConfig.async_direct_mode == true) RadioConfig.timing_sample_threshold = 65535;
    //else if ((RadioConfig.modulation_type == MOD_TYPE_OOK) ||  (RadioConfig.modulation_type == MOD_TYPE_ASK)) th = 0;
    //if in_2fsk_opt_scope and preamblebits >= 32 th = 0;
    // [MCUW_RADIO_CFG-1077] If we have at least 32 preamble bits then correlation is robust
    //else th = 10; // nominal threshold of 10 seems to work well for most PHYs
    //calculate TSAMPLIM register based on variable. Saturating to 100 based on the fact
    //that we have not seen a register setting greater than 20 up to this point despite
    //the the register being 16 bits
		//mode should be set to 0 if not FSK2/4 or if timing threshold == 0, else 1
    //We do not see a strong relation between performance and this delay parameter but
    //using hand optimized results for about 50 PHYs we came up with a simple equation
    //to calculate the delay parameter when TSAMPMODE is enabled.
    //if ((MODEM->CTRL3 & MODEM_CTRL3_TSAMPMODE_Msk) == 1) tsampdel = 2500000/baudrate/osr;
    //else tsampdel = 0;
    if ((RadioConfig.timing_sample_threshold > 100) && (!RadioConfig.async_direct_mode)) RadioConfig.timing_sample_threshold = 100;
		BUS_RegMaskedClear(&MODEM->CTRL3, MODEM_CTRL3_TSAMPLIM_Msk);
		BUS_RegMaskedSet(&MODEM->CTRL3, RadioConfig.timing_sample_threshold << MODEM_CTRL3_TSAMPLIM_Pos);
		BUS_RegMaskedClear(&MODEM->CTRL3,MODEM_CTRL3_TSAMPDEL_Msk);
    if ((RadioConfig.timing_sample_threshold == 0) || (RadioConfig.modulation_type == MOD_TYPE_OOK) || RadioConfig.modulation_type == MOD_TYPE_ASK || (RadioConfig.symbol_encoding == SYMBOL_ENCODING_DSSS)) 
		{
			BUS_RegMaskedClear(&MODEM->CTRL3, MODEM_CTRL3_TSAMPMODE_Msk);
			RadioConfig.timing_sampling_delay = 0;
		}
    else 
		{
			BUS_RegMaskedSet(&MODEM->CTRL3, 1<< MODEM_CTRL3_TSAMPMODE_Pos);
			BUS_RegMaskedSet(&MODEM->CTRL3, RadioConfig.timing_sampling_delay << MODEM_CTRL3_TSAMPDEL_Pos);
		}
		
		//MODEM->CTRL1 = 0x0001400F; //16,14,3,2,1,0 resync, compmode, syncbits (0f -> 16)
		if(RadioConfig.timing_resync_period > 15) RadioConfig.timing_resync_period = 15;
		BUS_RegMaskedClear(&MODEM->CTRL1,MODEM_CTRL1_RESYNCPER_Msk);
		BUS_RegMaskedSet(&MODEM->CTRL1,(RadioConfig.timing_resync_period << MODEM_CTRL1_RESYNCPER_Pos) | (1 << MODEM_CTRL1_COMPMODE_Pos)); //!!!
		//MODEM->PRE = 0x00140012;
		if(RadioConfig.preamble_pattern_len > 4) RadioConfig.preamble_pattern_len = 4;
		if (RadioConfig.errors_in_timing_window > 15) RadioConfig.errors_in_timing_window = 15;
		if (RadioConfig.preamble_length > 0xffff) RadioConfig.preamble_length = 0xffff;
		BUS_RegMaskedClear(&MODEM->PRE,MODEM_PRE_BASEBITS_Msk | MODEM_PRE_BASE_Msk | MODEM_PRE_PREERRORS_Msk | MODEM_PRE_TXBASES_Msk);
		//The bits have to be flipped around before writing the register
    // When manchester invert is selected, then elsewhere we flip the entire fsk mapping,
    // which also flips the preamble and sync word.  We don't want the the preamble and
    // syncword flipped, so to fix it, we invert the preamble pattern and sync word register
    // to undo the fsk mapping flip.
    if ((RadioConfig.symbol_encoding == SYMBOL_ENCODING_MANCHESTER) && (RadioConfig.manchester_mapping != MANCHESTER_MAPPING_DEFAULT))
		{
				pre_pattern_mask = (1 << RadioConfig.preamble_length) - 1;
        pre_pattern = RadioConfig.preamble_pattern ^ pre_pattern_mask;
		}
		else pre_pattern = RadioConfig.preamble_pattern;
    pre_base = UTILS_FlipBits(pre_pattern, RadioConfig.preamble_pattern_len);
		if (RadioConfig.preamble_pattern_len > 0) BUS_RegMaskedSet(&MODEM->PRE, (RadioConfig.preamble_pattern_len - 1) << MODEM_PRE_BASEBITS_Pos);
		BUS_RegMaskedSet(&MODEM->PRE,pre_base << MODEM_PRE_BASE_Pos);
		BUS_RegMaskedSet(&MODEM->PRE,RadioConfig.errors_in_timing_window << MODEM_PRE_PREERRORS_Pos);
		BUS_RegMaskedSet(&MODEM->PRE, ((RadioConfig.preamble_length/RadioConfig.preamble_pattern_len) & 0xffff) << MODEM_PRE_TXBASES_Pos);

	}
	
	void MODEM_SyncParamsSet(void)
	{
		uint32_t sync0, sync1, syncword_mask;

		if(RadioConfig.syncword_length > 32) RadioConfig.syncword_length = 32;
		sync0 = UTILS_FlipBits(RadioConfig.syncword_0, RadioConfig.syncword_length);
		sync1 = UTILS_FlipBits(RadioConfig.syncword_1, RadioConfig.syncword_length);
		BUS_RegMaskedClear(&MODEM->CTRL1,MODEM_CTRL1_SYNCBITS_Msk);
		BUS_RegMaskedSet(&MODEM->CTRL1, (RadioConfig.syncword_length - 1) << MODEM_CTRL1_SYNCBITS_Pos);
        // gdc:  Fix this after we get rid of the "_left" stuff above.
        // gdc:  Fix it so we just write syncword_0 before it gets flipped
        // When manchester invert is selected, then elsewhere we flip the entire fsk mapping,
        // which also flips the preamble and sync word.  We don't want the the preamble and
        // syncword flipped, so to fix it, we invert the preamble pattern and sync word register
        // to undo the fsk mapping flip.
    if ((RadioConfig.symbol_encoding == SYMBOL_ENCODING_MANCHESTER) && RadioConfig.manchester_mapping != MANCHESTER_MAPPING_DEFAULT)
		{
        syncword_mask = (1 << RadioConfig.syncword_length) - 1;
        sync0 ^= syncword_mask;
        sync1 ^= syncword_mask;
		}
		MODEM->SYNC0 = sync0;
		MODEM->SYNC1 = sync1;
    if ((MODEM->SYNC1 == 0) || ((MODEM->TIMING & MODEM_TIMING_TIMINGBASES_Msk) == 0)) BUS_RegMaskedClear(&MODEM->CTRL1,MODEM_CTRL1_DUALSYNC_Msk);
    else BUS_RegMaskedSet(&MODEM->CTRL1,MODEM_CTRL1_DUALSYNC_Msk);
		if (RadioConfig.syncword_tx_skip == true) BUS_RegMaskedSet(&MODEM->CTRL1,MODEM_CTRL1_SYNCDATA_Msk); // _SYNCDATA = 1;
    else BUS_RegMaskedClear(&MODEM->CTRL1,MODEM_CTRL1_SYNCDATA_Msk); //MODEM_CTRL1_SYNCDATA = 0;
	}
	
	void MODEM_StreamCodingSet(void)
	{
    //set CODING register
    if(RadioConfig.symbol_encoding > 2) RadioConfig.symbol_encoding = 0; //NRZ by default
		BUS_RegMaskedClear(&MODEM->CTRL0,MODEM_CTRL0_CODING_Msk);
		BUS_RegMaskedSet(&MODEM->CTRL0,	RadioConfig.symbol_encoding << MODEM_CTRL0_CODING_Pos);
		//DSSS
		//MODEM->DSSS0 = 0x00000000;
		MODEM->DSSS0 = RadioConfig.dsss_chipping_code; //dsss_chipping_code;
    if (RadioConfig.dsss_len > 32) RadioConfig.dsss_len = 32;
		BUS_RegMaskedClear(&MODEM->CTRL0,MODEM_CTRL0_DSSSLEN_Msk);
		if(RadioConfig.dsss_len != 0)BUS_RegMaskedSet(&MODEM->CTRL0, (RadioConfig.dsss_len - 1) << MODEM_CTRL0_DSSSLEN_Pos);
		BUS_RegMaskedClear(&MODEM->CTRL0,MODEM_CTRL0_DSSSSHIFTS_Msk); 
		//MODEM_SetDsssShiftsReg(uint32_t sh)
/*		switch(sh)
		{
			case 0:
			default:
			//s = 0;
			break;
			
			case 1:
			BUS_RegMaskedSet(&MODEM->CTRL0, 1 << MODEM_CTRL0_DSSSSHIFTS_Pos); //s = 1;
			break;
			
			case 2:
			BUS_RegMaskedSet(&MODEM->CTRL0, 2 << MODEM_CTRL0_DSSSSHIFTS_Pos); //s = 2;
			break;
			
			case 4:
			BUS_RegMaskedSet(&MODEM->CTRL0, 3 << MODEM_CTRL0_DSSSSHIFTS_Pos); //s = 3;
			break;
			
			case 8:
			BUS_RegMaskedSet(&MODEM->CTRL0, 4 << MODEM_CTRL0_DSSSSHIFTS_Pos); //s = 4;
			break;
			
			case 16:
			BUS_RegMaskedSet(&MODEM->CTRL0, 5 << MODEM_CTRL0_DSSSSHIFTS_Pos); //s = 5;
			break;
		}
		if(dsssdouble > 2) dsssdouble = 2;
		BUS_RegMaskedClear(&MODEM->CTRL0,MODEM_CTRL0_DSSSDOUBLE_Msk);
		MODEM->CTRL0 |= (dsssdouble << MODEM_CTRL0_DSSSDOUBLE_Pos);
*/		
		//MODEM_SetDiffEncModeReg(uint32_t mode)
		        //    DISABLED:  0,
        //    RR0:  1,
        //    RE0:  2,
        //    RR1:  3,
        //    RE1:  4,
		if(RadioConfig.diff_encoding_mode > 4) RadioConfig.diff_encoding_mode = 0; //disabled by default
		BUS_RegMaskedClear(&MODEM->CTRL0,MODEM_CTRL0_DIFFENCMODE_Msk);
		BUS_RegMaskedSet(&MODEM->CTRL0, RadioConfig.diff_encoding_mode << MODEM_CTRL0_DIFFENCMODE_Pos);
				
		//Channel coding must be here
	}

	void MODEM_SetSpreadingFactor(uint8_t sf) //shifts calculation, based on SF and DSSS length
	{
		
	}
	
	void MODEM_AfcParamsSet(void)
	{
		MODEM->AFC = 0x00000000;
		MODEM->AFCADJLIM = 0x00000000;
		//afcparams.mode = RadioConfig.freq_comp_mode;
		//afcparams.limit = RadioConfig.afc_freq_limit;
		//afcparams.afc_period = RadioConfig.afc_period;
		//afcparams.step_scale = RadioConfig.afc_step_scale;
		//afcparams.offset_period = RadioConfig.frequency_offset_period;
		if(RadioConfig.freq_comp_mode >= 4) RadioConfig.freq_comp_mode = 0;
		BUS_RegMaskedClear(&MODEM->CTRL1, MODEM_CTRL1_COMPMODE_Msk);
		BUS_RegMaskedSet(&MODEM->CTRL1,RadioConfig.freq_comp_mode << MODEM_CTRL1_COMPMODE_Pos);
		
	}

void MODEM_ConfigFixup(void)

{
  SEQ->SYNTHLPFCTRLTX = RAC->LPFCTRL;
  SEQ->SYNTHLPFCTRLRX = RAC->LPFCTRL & 0xfffffff0;
}

	//deviation
	void MODEM_SetModIndexReg(void) //calculate from deviation and baudrate
	{
    int32_t m,e;
    //modindex = RadioConfig.deviation * 16.0 / (synth_res * shaping_filter_gain * interpolation_gain);
    modindex = (float)RadioConfig.deviation*2/RadioConfig.chiprate;
    //printf("Modindex=%.3f\r\n",modindex);
      //convert fractional modindex into m * 2^e format
    UTILS_frac2exp(31, modindex, &m, &e);
    //MODEINDEXE is a signed value
    if (e < 0) e += 32;
    //verify number fits into register
    if (m > 31)  m = 31;
    if (e > 31)  e = 31;
    if (m < 1)  m = 1;
		//printf("MODINDEXM=0x%X, MODINDEXE=0x%X\r\n",m,e);
		BUS_RegMaskedClear(&MODEM->MODINDEX,MODEM_MODINDEX_MODINDEXE_Msk | MODEM_MODINDEX_MODINDEXM_Msk);
		BUS_RegMaskedSet(&MODEM->MODINDEX,(e << MODEM_MODINDEX_MODINDEXE_Pos) | (m << MODEM_MODINDEX_MODINDEXM_Pos));
	}

	//baudrate
	
void MODEM_CalcTxBrReg(void)
{
    float ratio;
    float num;
    uint8_t den;
    
    ratio = (float)RadioConfig.xtal_frequency_hz/(RadioConfig.chiprate * 8.0);
    //printf("TXBR ratio=%.3f\r\n", ratio);
        for (den = 255; den != 0; den--)
        //for(den = 1; den <=255; den++)
        {
             num = ratio * den;
             //printf("num=%.3f, den=%d\r\n", num, den);
             if ((fabs(round(num) - num) < 0.003) && (num < 32768)) break;
        }
    if(den == 0)
    {
       printf("Cannot calculate TXBR!\r\n");
			 den = 1;
       calc_error = true; 
    }
    else
    {
        txbrnum = (uint16_t)(round(num));
        txbrden = den;
        txbr_actual = (float)RadioConfig.xtal_frequency_hz/(8 * ((float)txbrnum/txbrden));
        //printf("TXBRNUM=%d, TXBRDEN=%d\r\n", txbrnum, txbrden);
    }
    
}
	
	void MODEM_SetTxBrReg(void)
	{
		MODEM_CalcTxBrReg();
		MODEM->TXBR = (txbrnum << MODEM_TXBR_TXBRNUM_Pos) | (txbrden << MODEM_TXBR_TXBRDEN_Pos); 
	}
	
//void MODEM_CalcRxBrReg(void)
void MODEM_SetRxBrReg(void)
{
    float ratio;
    uint32_t rxbrdenmin, rxbrdenmax;
    float best_error = 99.0;
    uint32_t best_num = 0;
    float best_den = 0.0;
    float error = 0.0;

    //ratio = (float)RadioConfig.xtal_frequency_hz/(dec0 * dec1 * dec2 * RadioConfig.chiprate * 2.0);
	  ratio = 2; //temporary
    //printf("RXBR ratio=%.3f\r\n", ratio);
        //alculate total fractional multiplier for the target RX baud rate
        // fraction is less than we can represent with 5 bits ratio
        //turn the smallest possible value
        if (ratio < 1/31.0)
        {
            rxbrint = 0;
            rxbrnum = 1;
            rxbrden = 31;
            calc_error = true;
            return;
        }
        //get the integer part
        rxbrint = floor(ratio);
        if (rxbrint > 7) rxbrint = 7;
        //remove the integer part from the multiplier
        ratio -= rxbrint;
        // brcalen is enabled HW requires that rxbrden to be 16
        //see BRCALEN entry in datasheet
        if (brcalen == true) 
        {
            rxbrdenmin = 16;
            rxbrdenmax = 16;
        }
        else         
        {
            rxbrdenmin = 1;
            rxbrdenmax = 32;
        }

        //loop over all possible denominators and find best numarator
        for (rxbrden = rxbrdenmin; rxbrden <= rxbrdenmax; rxbrden++)
        {
            rxbrnum = round(rxbrden * ratio);
            if (rxbrnum > 31) continue; //???
            error = fabs(rxbrnum*1.0/rxbrden - ratio);
            if ((brcalen == true) && (rxbrnum*1.0/rxbrden < ratio)) rxbrnum ++;
            if (error < best_error)
            {
                best_error = error;
                best_num = rxbrnum;
                best_den = rxbrden*1.0;
							  //printf("RXBRINT=0x%X, RXBRNUM=0x%X, RXBRDEN=0x%X, error=%.3f\r\n",rxbrint,rxbrnum,rxbrden,best_error);
            }
            if (error == 0) break;
        }
/*    //calculate actual RXBR
		rxbrnum = best_num;
		rxbrden =	floor(best_den);
    rxbr_actual = (float)RadioConfig.xtal_frequency_hz/(dec0 * dec1 * dec2 * (rxbrint + (float)rxbrnum/rxbrden) * 2.0);
				*/
		MODEM->RXBR = (rxbrint << MODEM_RXBR_RXBRINT_Pos) | (rxbrnum << MODEM_RXBR_RXBRNUM_Pos) | (rxbrden << MODEM_RXBR_RXBRDEN_Pos);

		
}

//    void MODEM_SetRxBrReg(void) //write RXBR register values
//	{
//		MODEM_CalcRxBrReg();
//		
//	}

//shaping settings should be here

//async direct mode should be here
	
/***************************DEMODULATOR******************************/
void MODEM_CalcDec0CfOsrReg(void)
{
		switch(RadioConfig.if_freq)
		{
			case 150000:
			dec0 = 8;
			cfosr = 32;
			break;
			
			case 300000:
			dec0 = 4;
			cfosr = 32;
			break;
			
			case 400000:
			dec0 = 3;
			cfosr = 32;
			break;
			
			case 600000:
			dec0 = 4;
			cfosr = 16;
			break;
			
			case 800000:
			dec0 = 3;
			cfosr = 16;
			break;
			
			case 1200000:
			dec0 = 4;
			cfosr = 8;
			break;
			
			case 1600000:
			dec0 = 3;
			cfosr = 8;
			break;
			
			default:
			dec0 = 3;
			cfosr = 32;
			RadioConfig.if_freq = 400000;
			break;
		}
		//printf("DEC0 = %d\r\n",dec0);
}

void MODEM_CalcDec1Dec2Reg(void)
{
//   float dec;
//   dec = ((float)RadioConfig.xtal_frequency_hz * 0.263)/(RadioConfig.acq_ch_bw * dec0);
//   printf("DEC = %.3f\r\n",dec);
//   dec1 = round(dec);
//   if(dec1 == 0) dec1 = 1;
//   if(dec1 > 16383) dec1 = 16383;
//   printf("DEC1 = %.d\r\n",dec1);
//   bw_actual = (RadioConfig.xtal_frequency_hz * 0.263)/(dec0 * dec1);
     //MODEM_CalcDec2Reg();
		dec2 = 1; //temporary
		dec1 = (RadioConfig.xtal_frequency_hz * 4)/(dec0 * dec2 * cfosr * RadioConfig.chiprate) - 1;
		//printf("DEC1 = %d, DEC1 = %d\r\n",dec1, dec2);
}
//void MODEM_CalcDec2Reg(void)
//{
//    float dec;
//    dec = (RadioConfig.xtal_frequency_hz / (5.0 * dec0 * dec1 * RadioConfig.chiprate));
//    printf("DEC2 = %.1f\r\n",dec);
//    dec2 = floor(dec);
//    if(dec2 == 0) 
//    {
//        dec2 = 1;
//        calc_error = true;
//    }
//		dec2 = 1; //temporary
//}


void MODEM_SetCfReg(void)
{
	uint32_t dec0reg;
	
	MODEM_CalcDec0CfOsrReg();
	MODEM_CalcDec1Dec2Reg();
	//MODEM_CalcDec2Reg();
	//if(dec0 > 7) dec0 = 7;
	if(dec0 == 3) dec0reg = 0;
  else if (dec0 == 4)
				{
// in dumbo and jumbo we have two dec0 filters wide and narrow
// choose between them based on bw
// for other chips set this to 1
          if (RadioConfig.acq_ch_bw > RadioConfig.xtal_frequency_hz * 0.037f) dec0reg = 1;
          else  dec0reg = 2;
					//dec0reg = 1;
				}
        else //if (dec0 == 8)
				{
          if (RadioConfig.acq_ch_bw > RadioConfig.xtal_frequency_hz * 0.005f)  dec0reg = 3;
					else  dec0reg = 4;
					//dec0reg = 4;
				}

	if(dec2 > 0x3f) dec2 = 0x3f;
	BUS_RegMaskedClear(&MODEM->CF,MODEM_CF_DEC0_Msk | MODEM_CF_DEC1_Msk | MODEM_CF_DEC2_Msk);
	BUS_RegMaskedSet(&MODEM->CF, (dec0reg << MODEM_CF_DEC0_Pos) | (dec1 << MODEM_CF_DEC1_Pos) | (dec2 << MODEM_CF_DEC2_Pos));
	BUS_RegMaskedClear(&MODEM->CF, MODEM_CF_CFOSR_Msk);
	switch(cfosr)
	{
		case 7:
		default:
		break;
			
		case 8:
		BUS_RegMaskedSet(&MODEM->CF, 1 << MODEM_CF_CFOSR_Pos);
		break;
			
		case 12:
		BUS_RegMaskedSet(&MODEM->CF, 2 << MODEM_CF_CFOSR_Pos);
		break;
			
		case 16:
		BUS_RegMaskedSet(&MODEM->CF, 3 << MODEM_CF_CFOSR_Pos);
		break;
			
		case 32:
		BUS_RegMaskedSet(&MODEM->CF, 4 << MODEM_CF_CFOSR_Pos);
		break;
	}
}

    void MODEM_SetFreqGainReg() //calculate register setting for frequency gain
	{
        // need target_freq_gain in m * 2^(2-e) format
		int32_t m, e;
        if (freq_gain > 0)
		{
            UTILS_frac2exp(7, freq_gain, &m, &e);
            e = (2 - e) & 0x07; //???
		}
        else m = e = 0;
        // Some input combinations can produce values out of range for the register fields,
        // such as applying crystal accuracy  > 7ppm for PHY 915MHz/600bps/300Hz
        // MCUW_RADIO_CFG-799
        // TODO: is would be best to query the register model to determine these two fields are 7 bits wide
        if (m > 7) m = 7; // Calculated frequency signal scaling coefficient of %s exceeds limit of 7
        if (e > 7) e = 7; // Calculated frequency signal scaling exponent of %s exceeds limit of 7
		BUS_RegMaskedClear(&MODEM->MODINDEX, MODEM_MODINDEX_FREQGAINM_Msk | MODEM_MODINDEX_FREQGAINE_Msk);
		BUS_RegMaskedSet(&MODEM->MODINDEX, (m << MODEM_MODINDEX_FREQGAINM_Pos) | (e << MODEM_MODINDEX_FREQGAINE_Pos));
	}


    void MODEM_CalcDec1Gain(void) //calculate additional gain we want in the DEC1 decimator for very low bandwidth PHY settings.
	{
        //see register definition of DEC1GAIN in EFR32 Reference Manual (internal.pdf)
 //       RadioConfig.acq_ch_bw = bandwidth_actual;
 //       if (RadioConfig.acq_ch_bw < 500) dec1gain = 12;
 //       else if (RadioConfig.acq_ch_bw < 2000) dec1gain = 6;
 //       else dec1gain = 0;
	}


    void MODEM_SetDec1GainReg(uint32_t gain) //set DEC1GAIN register based on calculated value
	{
		gain = gain / 6;
		if(gain > 2) gain = 2; //maybe 3
		BUS_RegMaskedClear(&MODEM->CF,MODEM_CF_DEC1GAIN_Msk);
		BUS_RegMaskedSet(&MODEM->CF, gain << MODEM_CF_DEC1GAIN_Pos);		
	}
	
//CTRL2
    void MODEM_SetDataFilterReg(uint32_t filter) //set register for datafilter size
	{
        //see DATAFILTER register entry in EFR32 Reference Manual (internal.pdf)
 //       modformat = modulation_type;
 //       osr = oversampling_rate_actual;

 //       if ((modformat == MOD_FORMAT_FSK2) ||  (modformat == MOD_FORMAT_FSK4) || (modformat == MOD_FORMAT_BPSK))
//		{
//            if (osr >= 4.5) datafilter = 3;
//            else if (osr >= 3.5) datafilter = 2;
//            else if (osr >= 2.5) datafilter = 1;
//            else  datafilter = 0;
//		}		
//        else 
//		{
//			if ((modformat == MOD_FORMAT_OOK) ||  (modformat == MOD_FORMAT_ASK))
//			{
//				if (osr >= 2.5) datafilter = 1;
//				else datafilter = 0;
//			}
//			else datafilter = 0;
//		}
		if(filter > 3) filter = 3;
		BUS_RegMaskedClear(&MODEM->CTRL2,MODEM_CTRL2_DATAFILTER_Msk);
		BUS_RegMaskedSet(&MODEM->CTRL2,filter << MODEM_CTRL2_DATAFILTER_Pos);
	}



    void MODEM_SetRxPinModeReg(bool asynchronous_rx_enable)
	{
		if (asynchronous_rx_enable == true) BUS_RegMaskedSet(&MODEM->CTRL2, MODEM_CTRL2_RXPINMODE_Msk);
        else BUS_RegMaskedClear(&MODEM->CTRL2, MODEM_CTRL2_RXPINMODE_Msk); //mode = 0;
	}
	
    void MODEM_SetSqiThreshReg(uint32_t threshold) //set sqithresh register - intermediate variable used to override as advanced input
	{
		BUS_RegMaskedClear(&MODEM->CTRL2,MODEM_CTRL2_SQITHRESH_Msk);
		BUS_RegMaskedSet(&MODEM->CTRL2,threshold << MODEM_CTRL2_SQITHRESH_Pos);
	}
    // TODO: disable weighting also if DEVMULA/DEVMULB is used
//    void MODEM_SetDevWeightDisReg(void) //determine if deviation weighting should be disabled
//	{
        //see section 5.7.5 in EFR32 Reference Manual (internal.pdf)
//        scale = freq_gain_scale;
		// disable weighting if we scaled frequency gain
//        if (scale < 1) MODEM_CTRL2_DEVWEIGHTDIS = 1;
//        else MODEM_CTRL2_DEVWEIGHTDIS = 0;
//	}


    void MODEM_SetPhaseDemodReg(void) //set register to define demodulation method for phase modulated signals
	{
    uint32_t phasedemod;
		
		if ((RadioConfig.modulation_type == MOD_TYPE_OQPSK) || (RadioConfig.modulation_type == MOD_TYPE_MSK)) phasedemod = 1;
        else 
			if ((RadioConfig.modulation_type == MOD_TYPE_BPSK) || (RadioConfig.modulation_type == MOD_TYPE_DBPSK))
			{
				if (RadioConfig.dsss_len > 0) phasedemod = 2;
				else  phasedemod = 1;
			}
        else phasedemod = 0;
		BUS_RegMaskedClear(&MODEM->CTRL1, MODEM_CTRL1_PHASEDEMOD_Msk);
		BUS_RegMaskedSet(&MODEM->CTRL1, phasedemod << MODEM_CTRL1_PHASEDEMOD_Pos);
	}


//CTRL4
  void MODEM_SetIsiCompReg(bool fsk4) //calc_isicomp_reg. Set to 8 if FSK4 otherwise 0
	{
        BUS_RegMaskedClear(&MODEM->CTRL4,MODEM_CTRL4_ISICOMP_Msk);
		if (fsk4 == true) BUS_RegMaskedSet(&MODEM->CTRL4, 8 << MODEM_CTRL4_ISICOMP_Pos); 
	}
	
    void MODEM_SetOffsetPhaseMaskingReg(bool bpsk)  //calc_offsetphasemasking_reg
	{
        //modulation = modulation_type;
        //if ((modulation == MOD_FORMAT_BPSK) || (modulation == MOD_FORMAT_DBPSK)) MODEM_CTRL4_OFFSETPHASEMASKING = 1;
        //else MODEM_CTRL4_OFFSETPHASEMASKING = 0;
		if(bpsk == true) BUS_RegMaskedSet(&MODEM->CTRL4,MODEM_CTRL4_OFFSETPHASEMASKING_Msk);
		else BUS_RegMaskedClear(&MODEM->CTRL4,MODEM_CTRL4_OFFSETPHASEMASKING_Msk);
		
	}
	
//CTRL5

  void MODEM_SetTrTdEdge(void)
	{

        if ((RadioConfig.modulation_type == MOD_TYPE_BPSK) || (RadioConfig.modulation_type== MOD_TYPE_DBPSK)) BUS_RegMaskedSet(&MODEM->CTRL5, MODEM_CTRL5_TDEDGE_Msk | MODEM_CTRL5_TREDGE_Msk);
        else BUS_RegMaskedClear(&MODEM->CTRL5, MODEM_CTRL5_TDEDGE_Msk | MODEM_CTRL5_TREDGE_Msk);
	}

    void MODEM_SetBrCalReg(uint32_t brcalavg, bool brcalen) //write BRCALAVG AND BRCALEN register
	{
        BUS_RegMaskedClear(&MODEM->CTRL5, MODEM_CTRL5_BRCALEN_Msk | MODEM_CTRL5_BRCALAVG_Msk);
		if(brcalavg > 3) brcalavg = 3;
		if(brcalen == true) BUS_RegMaskedSet(&MODEM->CTRL5, (brcalavg << MODEM_CTRL5_BRCALAVG_Pos) | (1 << MODEM_CTRL5_BRCALEN_Pos));
	}

void MODEM_DemodResetOnRxsearchEntryDisable(void)

{
  RAC->SR3 &= 0xfffffeff;
}

void MODEM_DccalEnable(void)

{
  RAC->SR3 |= 1;
}

void MODEM_DccalDisable(void)

{
	RAC->SR3 &= 0xfffffffe;
}

void MODEM_DemodResetOnRxsearchEntryEnable(void)

{
  RAC->SR3 |= 0x100;
}


