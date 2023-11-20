#include "RFIF.h"


	bool pll_bandwidth_miracle_mode; //Set to force the synth pll into miracle mode (whatever that means)
	uint32_t iffilt_bw[16] = {570000,630000,790000,890000,1040000,1140000,1250000,1400000,1585000,1660000,1820000,2140000,2280000,2600000,2800000,3040000};
	float iffilt_ratio[8] = {0.0,0.385,0.5,0.55,0.6,0.65,0.675,0.7};
	
	uint32_t target_bw_khz;
	uint32_t iffilt_bandwidth_actual;
	uint32_t bandwidth_actual;
	uint32_t if_frequency_hz_actual;
	uint32_t  pll_bandwidth_tx = 2;
	uint32_t  pll_bandwidth_rx = 2;
	uint32_t lodiv_actual;

    void RFIF_GetIffiltBw(void)
	{
        //given register setting return IFFILT bandwidth
        iffilt_bandwidth_actual = iffilt_bw[(RAC->IFFILTCTRL & RAC_IFFILTCTRL_BANDWIDTH_Msk)];
	}


    void RFIF_CalcIffiltRatio(void)
	{
        //given already decided center (IF) frequency and IFFILT bandwidth
        //find ratio value that would center the IFFILT around the IF frequency.
        //fc = if_frequency_hz_actual;
        //bw_ana = iffilt_bandwidth_actual;
        // calculate IF (center) frequency to BW ratio
        //iffilt_ratio = ((float)if_frequency_hz_actual) / iffilt_bandwidth_actual;

        //iffilt_ratio = target_ratio;
	}
	
	
	
	void RFIF_SetIffiltCtrlReg(void)
	{
        //find smallest IFFILT bandwidth we can use with given digital filter
        //bandwidth settings
        // find smallest bandwidth setting that is larger than bw_dig
        //for bw_reg, bw_ana in self.iffilt_bw.items()
		uint32_t i; 
		float error;
		uint32_t best_index;
		
		int32_t target_ratio;
		
		for(i = 0; i < 16; i++)
		{
            if (iffilt_bw[i] > bandwidth_actual) break;
		}
		RAC->IFFILTCTRL &= ~RAC_IFFILTCTRL_BANDWIDTH_Msk;
		RAC->IFFILTCTRL |= i;
        //RAC_IFFILTCTRL_VCM =          2;
        //RAC_IFFILTCTRL_VREG =         4;
		RAC->IFFILTCTRL &= ~(RAC_IFFILTCTRL_VCM_Msk | RAC_IFFILTCTRL_VREG_Msk);
		RAC->IFFILTCTRL |= (2 << RAC_IFFILTCTRL_VCM_Pos) | (4 << RAC_IFFILTCTRL_VREG_Pos);
        //Given desired ratio find best register setting
        float best_error = 9e9;
		//target_ratio = iffilt_ratio;
        // find smallest ratio that is larger than the target ratio
		for(i = 0; i < 8; i++)
		{
			error = fabsf(target_ratio - iffilt_ratio[i]);
            if (error < best_error)
			{
                best_error = error;
                best_index = i;
			}
		}
		RAC->IFFILTCTRL &= ~RAC_IFFILTCTRL_CENTFREQ_Msk;
		RAC->IFFILTCTRL |= best_index;
	}
    

 //   void RFIF_GetIffiltRatio(void)
//	{
        //given register setting return actual ratio used in the PHY
//        iffilt_ratio_actual = iffilt_ratio[(RAC->IFFILTCTRL & RAC_IFFILTCTRL_CENTFREQ_Msk) >> RAC_IFFILTCTRL_CENTFREQ_Pos];
//	}



	void RFIF_SetIfadcCtrlReg(void)
	{
        //Given channel bandwidth choose between real and complex ADC modes
		uint32_t bw;
		bw = bandwidth_actual;
        // discovered that if RX signal fits into the ADC bandwidth we get better
        // performance with real mode. So check if channel bandwidth is less than
        // 1 MHz and choose real mode else choose default complex mode.
        if (bw < bandwidth_actual) BUS_RegMaskedSet(&RAC->IFADCCTRL, RAC_IFADCCTRL_REALMODE_Msk); //realmode = 1;   // set ADC in real-mode
        else BUS_RegMaskedClear(&RAC->IFADCCTRL, RAC_IFADCCTRL_REALMODE_Msk);
        //gdc:  Set based on request from Euisoo:  https://jira.silabs.com/browse/LABATEPDB-36
        //RAC_IFADCCTRL_VLDOCLKGEN = 3;
        //RAC_IFADCCTRL_REGENCLKDELAY = 4;
        //RAC_IFADCCTRL_INPUTSCALE = 0;
        //RAC_IFADCCTRL_OTA1CURRENT = 2;
        //RAC_IFADCCTRL_OTA2CURRENT = 2;
        //RAC_IFADCCTRL_OTA3CURRENT = 2;
        //RAC_IFADCCTRL_VCM = 3;
        //RAC_IFADCCTRL_VLDOSERIES = 3;
        //RAC_IFADCCTRL_VLDOSERIESCURR = 3;
        //RAC_IFADCCTRL_VLDOSHUNT = 2;
        //RAC_IFADCCTRL_INVERTCLK = 0;
		RAC->IFADCCTRL = (3 << RAC_IFADCCTRL_VLDOCLKGEN_Pos) | (4 << RAC_IFADCCTRL_REGENCLKDELAY_Pos) | (2 << RAC_IFADCCTRL_OTA1CURRENT_Pos) |
		(2 << RAC_IFADCCTRL_OTA2CURRENT_Pos) | (2 << RAC_IFADCCTRL_OTA3CURRENT_Pos) | (3 << RAC_IFADCCTRL_VCM_Pos) | (3 << RAC_IFADCCTRL_VLDOSERIES_Pos) |
		(3 << RAC_IFADCCTRL_VLDOSERIESCURR_Pos) | (2 << RAC_IFADCCTRL_VLDOSHUNT_Pos);
    }    
        

    
        
	void RFIF_CalcLpfBwTx(void)
	{
        //calculate frequency synthesizer's LPF bandwidth for TX and write to register
        // Due to a HW problem with PLL overshooting choose target BW of frequency synthesize
        // LPF as 1.5 times the channel bandwidth chosen.
        target_bw_khz = 1.5 * bandwidth_actual / 1000.0;
        if (target_bw_khz < 250)        pll_bandwidth_tx = PLL_BW_TX_250KHz;
        else if (target_bw_khz < 297)  pll_bandwidth_tx = PLL_BW_TX_297KHz;
        else if (target_bw_khz < 354)  pll_bandwidth_tx = PLL_BW_TX_354KHz;
        else if (target_bw_khz < 420)  pll_bandwidth_tx = PLL_BW_TX_420KHz;
        else if (target_bw_khz < 500)  pll_bandwidth_tx = PLL_BW_TX_500KHz;
        else if (target_bw_khz < 594)  pll_bandwidth_tx = PLL_BW_TX_594KHz;
        else if (target_bw_khz < 1260) pll_bandwidth_tx = PLL_BW_TX_1260KHz;
        else if (target_bw_khz < 1500) pll_bandwidth_tx = PLL_BW_TX_1500KHz;
        else if (target_bw_khz < 1780) pll_bandwidth_tx = PLL_BW_TX_1780KHz;
        else if (target_bw_khz < 2120) pll_bandwidth_tx = PLL_BW_TX_2120KHz;
        else if (target_bw_khz < 2520) pll_bandwidth_tx = PLL_BW_TX_2520KHz;
        else  pll_bandwidth_tx = PLL_BW_TX_3000KHz;
        // anything smaller than 2 is not performing well at this point
        // use 2 as the smallest setting for now based on feedback from Ravi
        if (pll_bandwidth_tx < 2) pll_bandwidth_tx = PLL_BW_TX_354KHz;
	}


	void RFIF_CalcLpfBwRx(void)
	{
        //calculate frequency synthesizer's LPF bandwidth for TX and write to register
        // John Wang recommends that we use the LPFBW=2 setting in the RX mode to improve the phase noise.
        // The phase noise fundamentally limits the ACS (if the RX channel filter is not a limitation in itself).
        // based on Ravi's feedback we should do this only for PHYs with datarate < 100kbps
        if (RadioConfig.chiprate < 100e3)  pll_bandwidth_rx = PLL_BW_RX_354KHz;
        else pll_bandwidth_rx = PLL_BW_RX_250KHz;
	}


	void RFIF_SetLpfBw(void)
	{
        //Write the rx and tx sequencer registers for the SYNTH_LPFCTRL register
        // We need to set some bits in the upper part of SYNTHLPFCTRL
        // Since we don't have proper fields defined for them in the 
        // sequencer register, just hard-code a constant... at least for today
        //
        // This is really setting:
        //
        // bit 17:       LPFGNDSWITCHINGEN = 1   - LPF input ground switching enable
        // bit 16:       LPFSWITCHINGEN    = 1   - Enables switching in the LPF
        // bits 15:14    LPFINPUTCAP       = 0x3 - Controls the input capacitance of the LPF
        //
        //synthlpfctrl_upper_bits = 0x3c000;
        // We also conditionally set bit 4, the miracle mode bit.  Usually this is
        // cleared, but it can be forced to a 1.  So set the global variable to
        // 0, then read it back.  The readback will be a 1 if it was forced to a 1,
        // and otherwise it will get set to 0.
        //pll_bandwidth_miracle_mode = false;
        //if (pll_bandwidth_miracle_mode == true) synthlpfctrl_upper_bits |= 0x10;
        //synthlpfctrlrx = synthlpfctrl_upper_bits | pll_bandwidth_rx;
        //synthlpfctrltx = synthlpfctrl_upper_bits | pll_bandwidth_tx;
				SEQ->SYNTHLPFCTRLRX = 0x3c000 | pll_bandwidth_rx;
        SEQ->SYNTHLPFCTRLTX = 0x3c000 | pll_bandwidth_tx;
	}



	void RFIF_SetIfpgaCtrlReg(void)
	{
        //given LODIV setting set BANDSEL register
        //for 2.4 GHz LODIV is always set to 1 so if LODIV is one set BANDSEL to 2P4G band (0)
        //else set to SUBG mode (1)
		if (lodiv_actual == 1) BUS_RegMaskedClear(&RAC->IFPGACTRL,RAC_IFPGACTRL_BANDSEL_Msk); 
        else BUS_RegMaskedSet(&RAC->IFPGACTRL,RAC_IFPGACTRL_BANDSEL_Msk);
        // The following will be written with constants from Ravi's spreadsheet
        //RAC_IFPGACTRL_VLDO =          3;
        //RAC_IFPGACTRL_CASCBIAS =      7;
        //RAC_IFPGACTRL_TRIMVCASLDO =   1;
        //RAC_IFPGACTRL_TRIMVCM =       3;
        //RAC_IFPGACTRL_TRIMVREFLDO =   0;
        //RAC_IFPGACTRL_TRIMVREGMIN =   1;
        //RAC_IFPGACTRL_ENHYST =        0;
        //RAC_IFPGACTRL_ENOFFD =        0;
		RAC->IFPGACTRL = (3 << RAC_IFPGACTRL_VLDO_Pos) | (7 << RAC_IFPGACTRL_CASCBIAS_Pos) | (1 << RAC_IFPGACTRL_TRIMVCASLDO_Pos) |
		(3 << RAC_IFPGACTRL_TRIMVCM_Pos) | (1 << RAC_IFPGACTRL_TRIMVREGMIN_Pos);
	}


	
    void RFIF_SetRfEnReg(void)
	{
        //DEM stands for dynamic element matching.  Has nothing to do with demod.
        //RAC_RFENCTRL_DEMEN =        1;
		RAC->RFENCTRL = RAC_RFENCTRL_DEMEN_Msk | RAC_RFENCTRL_IFADCCAPRESET_Msk;
        /// Set this to a 1 just to match the register default
        // It really is a don't care, but it makes sense to set it to 1
        // to make some diff's simpler
		//BUS_RegMaskedSet(&RAC->RFENCTRL,RAC_RFENCTRL_IFADCCAPRESET_Msk);
	}

    void RFIF_SetlnaMixCtrl1Reg(void)
	{
        //RAC_LNAMIXCTRL1_TRIMAUXPLLCLK =  0;
        //RAC_LNAMIXCTRL1_TRIMTRSWGATEV =  0;
        //RAC_LNAMIXCTRL1_TRIMVCASLDO =    1;
        //RAC_LNAMIXCTRL1_TRIMVREFLDO =    0;
        //RAC_LNAMIXCTRL1_TRIMVREGMIN =    1;
        //RAC_LNAMIXCTRL1_TRIMAUXBIAS =    0;
        //RAC_LNAMIXCTRL1_ENBIASCAL =      0;
		
		RAC->LNAMIXCTRL1 |= RAC_LNAMIXCTRL1_TRIMVCASLDO_Msk | (1 << RAC_LNAMIXCTRL1_TRIMVREGMIN_Pos);
	}

    void RFIF_SetVcoCtrlReg(void)
	{
        //RAC_VCOCTRL_VCOAMPLITUDE =      10;
        //RAC_VCOCTRL_VCODETAMPLITUDE =    7;
        //RAC_VCOCTRL_VCODETEN =           1;
        //RAC_VCOCTRL_VCODETMODE =         1;
        //RAC_VCOCTRL_VCOAREGCURR =        1;
        //RAC_VCOCTRL_VCOCREGCURR =        2;
        //RAC_VCOCTRL_VCODIVCURR =        15;
		RAC->VCOCTRL = (10 << RAC_VCOCTRL_VCOAMPLITUDE_Pos) | (7 << RAC_VCOCTRL_VCODETAMPLITUDE_Pos) | 
		(1 << RAC_VCOCTRL_VCODETEN_Pos) | (1 << RAC_VCOCTRL_VCODETMODE_Pos) | (1 << RAC_VCOCTRL_VCOAREGCURR_Pos) | 
		(2 << RAC_VCOCTRL_VCOCREGCURR_Pos) | (15 << RAC_VCOCTRL_VCODIVCURR_Pos);
	}

	


