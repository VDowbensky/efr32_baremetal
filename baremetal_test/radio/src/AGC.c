#include "AGC.h"    
	
	void AGC_Preset(void);
	void AGC_SetSpeed(uint8_t speed);
	void AGC_SetPowerTargetOptimal(void);
	void AGC_SetPowerTarget(int8_t target);
	void AGC_SetRssiPeriod(uint32_t period);
	void AGC_SetAgcHyst(uint32_t hyst);
	void AGC_SetAgcPeriod(uint32_t period);
	uint8_t AGC_GetAgcPeriod(void);
	void AGC_SetAgcDelay(uint8_t delay);
	void AGC_SetAgcFastStepUpReg(void);
	void AGC_SetAgcCfloopStepMaxReg(void);
	void AGC_SetAgcModeReg(void);
	void AGC_SetFastStepDownReg(uint8_t speed);
	void AGC_SetPkdWaitReg(uint8_t speed);
	void AGC_SetFastLoopDelReg(uint32_t delay);
	void AGC_SetLnaSlicesDelReg(uint32_t delay);
	void AGC_SetIfpgaDelReg(uint32_t delay);
	void AGC_GetRssiPeriod(void);
	
	void AGC_Init(void)
	{
		AGC_Preset();

		AGC_SetPowerTarget(RadioConfig.agc_power_target);
		AGC_SetRssiPeriod(RadioConfig.rssi_period);
		AGC_SetAgcPeriod(RadioConfig.agc_period);
		AGC_SetAgcHyst(RadioConfig.agc_hysteresis);
		AGC_SetAgcDelay(RadioConfig.agc_setting_delay);
		AGC_SetSpeed(RadioConfig.agc_speed);
	}		
	
	
	void AGC_Preset(void)
	{
		//calc_agc_reg
		AGC->GAINRANGE = ((0x3e << AGC_GAINRANGE_MAXGAIN_Pos) | (0x70 << AGC_GAINRANGE_MINGAIN_Pos)) & (AGC_GAINRANGE_MAXGAIN_Msk | AGC_GAINRANGE_MINGAIN_Msk);
		AGC->GAININDEX = (0x12 << AGC_GAININDEX_NUMINDEXATTEN_Pos) | (6 << AGC_GAININDEX_NUMINDEXSLICES_Pos) | (3 << AGC_GAININDEX_NUMINDEXDEGEN_Pos) | 0x0c;
		AGC->MININDEX = (0x1b << AGC_MININDEX_INDEXMINPGA_Pos) | (0x18 << AGC_MININDEX_INDEXMINDEGEN_Pos) | (0x12 << AGC_MININDEX_INDEXMINSLICES_Pos);
		// MCUW_RADIO_CFG-1
		AGC->MANGAIN &= ~(AGC_MANGAIN_MANGAININDEXEN_Msk | AGC_MANGAIN_MANGAININDEX_Msk | AGC_MANGAIN_MANGAINLNASLICESREG_Msk | AGC_MANGAIN_MANGAINLNASLICES_Msk | AGC_MANGAIN_MANGAINLNAATTEN_Msk);
		//calc_agc_misc
		AGC->CTRL0 &= ~(AGC_CTRL0_ADCRESETDURATION_Msk | AGC_CTRL0_RSSISHIFT_Msk);
		AGC->CTRL0 |= ((0x4e << AGC_CTRL0_RSSISHIFT_Pos) & AGC_CTRL0_RSSISHIFT_Msk);
		AGC->CTRL1 &= ~(AGC_CTRL1_SUBPERIOD_Msk | AGC_CTRL1_SUBINT_Msk | AGC_CTRL1_SUBNUM_Msk | AGC_CTRL1_SUBDEN_Msk);
		AGC->CTRL2 &= ~(AGC_CTRL2_MAXPWRVAR_Msk);
		AGC->CTRL2 |= (1 << AGC_CTRL2_ADCRSTSTARTUP_Pos);
		AGC->IFPEAKDET &= ~(AGC_IFPEAKDET_PKDTHRESH1_Msk | AGC_IFPEAKDET_PKDTHRESH2_Msk);
		AGC->IFPEAKDET |= (2 << AGC_IFPEAKDET_PKDTHRESH1_Pos) | (8 << AGC_IFPEAKDET_PKDTHRESH2_Pos);
	}
	
	void AGC_SetSpeed(uint8_t speed)
	{
		AGC_SetAgcFastStepUpReg();
		AGC_SetAgcCfloopStepMaxReg();
		AGC_SetAgcModeReg();
		AGC_SetFastStepDownReg(speed);
		AGC_SetPkdWaitReg(speed);
		AGC_SetFastLoopDelReg(1);
		AGC_SetLnaSlicesDelReg(1);
		AGC_SetIfpgaDelReg(1);
	}
	


	
	
	void AGC_SetPowerTargetOptimal(void)
	{
		if (RadioConfig.modulation_type == MOD_TYPE_OOK) AGC_SetPowerTarget(0);
		else AGC_SetPowerTarget(-2);
	}
	
	void AGC_SetPowerTarget(int8_t target)
	{
		AGC->CTRL0 &= ~AGC_CTRL0_PWRTARGET_Msk;
		//AGC->CTRL0 |= (target << AGC_CTRL0_PWRTARGET_Pos);
		AGC->CTRL0 |= (target & AGC_CTRL0_PWRTARGET_Msk);
	}
	
		
	void AGC_SetRssiPeriod(uint32_t period) //program RSSIPERIOD register
	{
		if (period > 15) period = 15;
		AGC->CTRL1 &= ~AGC_CTRL1_RSSIPERIOD_Msk;
		AGC->CTRL1 |= (period << AGC_CTRL1_RSSIPERIOD_Pos) & AGC_CTRL1_RSSIPERIOD_Msk;
	}
		
	void AGC_SetAgcHyst(uint32_t hyst) //program HYST register
	{
        if (hyst > 15) hyst = 15;
		AGC->CTRL2 &= ~AGC_CTRL2_HYST_Msk;
		AGC->CTRL2 |= (hyst << AGC_CTRL2_HYST_Pos);
	}
	
	void AGC_SetAgcPeriod(uint32_t period) //program AGCPERIOD register
	{
        if (period > 7) period = 7;
		AGC->CTRL1 &= ~AGC_CTRL1_AGCPERIOD_Msk;
		AGC->CTRL1 |= (period << AGC_CTRL1_AGCPERIOD_Pos);
	}
	
	uint8_t AGC_GetAgcPeriod(void) //calculate actual AGCPERIOD from register value
	{
        //val = 2**(AGC_CTRL1_AGCPERIOD);
        //agcperiod_actual = val;
		//return AGC_CTRL1_AGCPERIOD;
		return (AGC->CTRL1 & AGC_CTRL1_AGCPERIOD_Msk) >> AGC_CTRL1_AGCPERIOD_Pos;
	}
	
	void AGC_SetAgcDelay(uint8_t delay) //program CFLOOPDEL based on calculated value
	{
    if(delay > 63) delay = 63;
		AGC->CTRL2 &= ~AGC_CTRL2_CFLOOPDEL_Msk;
		AGC->CTRL2 |= (delay << AGC_CTRL2_CFLOOPDEL_Pos);
	}
	
	
		
	void AGC_SetAgcFastStepUpReg(void) //set FASTSTEPUP based on modulation method
	{
		AGC->GAINSTEPLIM &= ~(AGC_GAINSTEPLIM_FASTSTEPUP_Msk);
		if(RadioConfig.modulation_type != MOD_TYPE_OOK)  AGC->GAINSTEPLIM |= (2 << AGC_GAINSTEPLIM_FASTSTEPUP_Pos); //AGC_GAINSTEPLIM_FASTSTEPUP = 2; //???
	}
		
	void AGC_SetAgcCfloopStepMaxReg(void) //set CFLOOPSTEPMAX based on modulation method
	{
		//in MOD_FORMAT_OOK mode use max step size of 5 unless we are in a relatively
		//narrowband MOD_FORMAT_OOK case. In narrowband case for dumbo only disable
		//slow loop as it is causing an error floor.
		AGC->GAINSTEPLIM &= ~AGC_GAINSTEPLIM_CFLOOPSTEPMAX_Msk;
		if (RadioConfig.modulation_type == MOD_TYPE_OOK)
		{
			if (RadioConfig.acq_ch_bw >= 5 * RadioConfig.chiprate) AGC->GAINSTEPLIM |= (5 << AGC_GAINSTEPLIM_CFLOOPSTEPMAX_Pos); //AGC_GAINSTEPLIM_CFLOOPSTEPMAX = 5;
		}
		else 
		{	
			if (RadioConfig.modulation_type == MOD_TYPE_FSK4) AGC->GAINSTEPLIM |= (1 << AGC_GAINSTEPLIM_CFLOOPSTEPMAX_Pos); //AGC_GAINSTEPLIM_CFLOOPSTEPMAX = 1;
			else AGC->GAINSTEPLIM |= (8 << AGC_GAINSTEPLIM_CFLOOPSTEPMAX_Pos); //AGC_GAINSTEPLIM_CFLOOPSTEPMAX = 8;
		}
	}
		
	void AGC_SetAgcModeReg(void) //set MODE based on modulation method
	{
		AGC->CTRL0 &= ~AGC_CTRL0_MODE_Msk;
		//in MOD_FORMAT_OOK mode use LOCKPREDET lock gain once preamble is detected
		if (RadioConfig.modulation_type == MOD_TYPE_OOK) AGC->CTRL0 |= (1 << AGC_CTRL0_MODE_Pos); //AGC_CTRL0_MODE = 1;
	}
	
	/*
		
	void AGC_CalcAgcSpeedVal(void) //set agc_speed based on modulation method
	{
		//in MOD_FORMAT_OOK mode use FAST AGC
		if (mod_format == MOD_FORMAT_OOK) agc_speed = AGC_SPEED_FAST;
		else agc_speed = AGC_SPEED_NORMAL;
	}


	void AGC_CalcAgcSettlingDelay(void) //calculate AGC settling delay which is basically the group delay of decimation and
    //channel filters through the datapath plus AGC period at the AGC clock rate
	{
        //DEC0 filter(12) -> DEC0 -> DEC1 filter(3) -> DEC1 -> Channel filter (10)
        //we pad the resulting delay by scaling it with 1.45 to account for variations
        dec0 = dec0_actual;
        dec1 = dec1_actual;
        dec2 = dec2_actual;
        agcperiod =agcperiod_actual;
        osr = oversampling_rate_actual;
        cfloopdel = int(1.45*py2round(((12.0+3.0)/dec0+3.0)/dec1+10.0 + agcperiod * osr * dec2));
        if (cfloopdel) > 63 cfloopdel = 63;
        agc_settling_delay = cfloopdel;
	}

	

	void AGC_CalcAgcClockCycle(void) //programmable AGC delays are set in terms of AGC clock cycles so calculate that here
	{
        fxo = xtal_frequency * 1.0;
        dec0 = dec0_actual;
        dec1 = dec1_actual;
        agc_clock_cycle = (dec0 * dec1) / fxo;
	}
	
	void AGC_CalcAgcDelays(void) //function to set delays based on agc_speed input. For now keeping all delays the same
    //delays represent analog block delays to different AGC components
	{
        if (agc_speed == AGC_SPEED_FAST)
		{

            lna_slices_delay = 400e-9;
            fast_loop_delay = 250e-9;
            if_pga_delay = 300e-9;
		}
        else 
		{
			if (agc_speed == AGC_SPEED_SLOW)
			{
				lna_slices_delay = 400e-9;
				fast_loop_delay = 250e-9;
				if_pga_delay = 300e-9;
			}
			else
			{
				lna_slices_delay = 400e-9;
				fast_loop_delay = 250e-9;
				if_pga_delay = 300e-9;
			}
		}
	}
	*/
	
	void AGC_SetFastStepDownReg(uint8_t speed) //choose FASTSTEPDOWN value based on agc_speed
	{
        uint32_t step;
		if (speed == AGC_SPEED_FAST) step = 5;
        else
		{			
			if (speed == AGC_SPEED_SLOW) step = 3;  // TODO: come up with a value for this one
			else step = 4;
		}
		AGC->GAINSTEPLIM &= ~AGC_GAINSTEPLIM_FASTSTEPDOWN_Msk;
        AGC->GAINSTEPLIM |= (step << AGC_GAINSTEPLIM_FASTSTEPDOWN_Pos); //AGC_GAINSTEPLIM_FASTSTEPDOWN = step;
	}
	
	void AGC_SetPkdWaitReg(uint8_t speed) //calculate PKDWAIT based on agc_speed
	{
    int32_t wait;    
		if (speed == AGC_SPEED_FAST) wait = 3;
        else
		{
			if (speed == AGC_SPEED_SLOW) wait = 2;  // TODO: come up with a value for this one
			else wait = 3;
		}
		AGC->LOOPDEL = ~AGC_LOOPDEL_PKDWAIT_Msk;
        AGC->LOOPDEL |= (wait << AGC_LOOPDEL_PKDWAIT_Pos); //AGC_LOOPDEL_PKDWAIT = wait;
	}

	void AGC_SetFastLoopDelReg(uint32_t delay) //calculate FASTLOOPDEL based on corresponding delay
	{
        // TODO: add missing -1 to equation once verified
//		int32_t delay;
		
//        delay = ceil(fast_loop_delay / agc_clock_cycle);
        if (delay < 0) delay = 0;
        if (delay > 15)
			delay = 15;
		AGC->CTRL2 &= ~AGC_CTRL2_FASTLOOPDEL_Msk;
		AGC->CTRL2 |= (delay << AGC_CTRL2_FASTLOOPDEL_Pos); //AGC_CTRL2_FASTLOOPDEL = delay;
	}
	
	void AGC_SetLnaSlicesDelReg(uint32_t delay) //calculate LNASLICESDEL based on corresponding delay
	{
        // TODO: add missing -1 to equation once verified
        //delay = (ceil(lna_slices_delay / agc_clock_cycle));
        if (delay < 0) delay = 0;
        if (delay > 15) delay = 15;
				AGC->LOOPDEL &= ~AGC_LOOPDEL_LNASLICESDEL_Msk;
        AGC->LOOPDEL |= (delay << AGC_LOOPDEL_LNASLICESDEL_Pos); //AGC_LOOPDEL_LNASLICESDEL = delay;
	}

	void AGC_SetIfpgaDelReg(uint32_t delay) //calculate IFPGADEL based on corresponding delay
	{
        // TODO: add missing -1 to equation once verified
        //delay = (ceil(if_pga_delay / agc_clock_cycle));
        if (delay < 0) delay = 0;
        if (delay > 15) delay = 15;
				AGC->LOOPDEL &= ~AGC_LOOPDEL_IFPGADEL_Msk;
        AGC->LOOPDEL |= (delay << AGC_LOOPDEL_IFPGADEL_Pos); //AGC_LOOPDEL_IFPGADEL = delay;
	}
	
	void AGC_GetRssiPeriod(void) //Read in the RSSI period register and take 2 to that power to compute the symbols in the period
	{
        //rssi_period_reg = (AGC->CTRL1 & AGC_CTRL1_RSSIPERIOD_Msk) >> AGC_CTRL1_RSSIPERIOD_Pos; //AGC_CTRL1_RSSIPERIOD;
        //rssi_period_sym_actual = 2**rssi_period_reg;
        //rssi_period_sym_actual = rssi_period_sym_actual;
	}

	
	void AGC_IRQHandler(void)
{
	uint32_t flags;
	flags = AGC->IF & AGC->IEN;
	AGC->IFC = flags;
	
	if(flags & AGC_IFS_RSSIVALID_Msk)
	{
		RxEvents |= RXEVENT_RSSIVALID;
	}
	
	if(flags & AGC_IFS_CCA_Msk)
	{
		RxEvents |= RXEVENT_CCA;
	}
	
	if(flags & AGC_IFS_RSSIPOSSTEP_Msk)
	{
		RxEvents |= RXEVENT_RSSIPOSSTEP;
	}
	
	if(flags & AGC_IFS_RSSINEGSTEP_Msk)
	{
		RxEvents |= RXEVENT_RSSINEGSTEP;
	}
	
	if(flags & AGC_IFS_RSSIDONE_Msk)
	{
		RxEvents |= RXEVENT_RSSIDONE;
	}
}

int16_t AGC_GetRSSI(void)

{
  int16_t rssi;
  uint32_t state_before;
  uint32_t state_after;
  
  do 
  {
    INT_Disable();
    state_before = (RAC->STATUS & RAC_STATUS_STATE_Msk) >> RAC_STATUS_STATE_Pos;
	  rssi = (int16_t)(AGC->RSSI);
    state_after = (RAC->STATUS & RAC_STATUS_STATE_Msk) >> RAC_STATUS_STATE_Pos;
    INT_Enable();
    if (rssi != -0x200) 
	  {
      if ((state_after == 2 || state_after ==3) && (state_before == 2 || state_before == 3)) return rssi/64;
      return -0x200;
    }
  } while ((state_after == 2 || state_after == 3) && (state_before == 2 || state_before == 3));
  return -0x200;
}
