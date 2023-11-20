	#include "SYNTH.h"

	//#define DCDCRETIMECLKTARGET 7000000UL
	//#define DCDCRETIMECLKTARGET 9000000UL
	
	uint32_t lodiv;
	uint8_t vcoGainPte;
	uint32_t loside;
	uint8_t Channel;
	
	uint8_t divLookup[10] = {0,0,1,2,2,3,3,3,3,0};

	uint32_t dcdcRetimeClkTarget = 7000000;

	uint32_t SYNTH_GetRxVcoFreq(void);
	uint32_t SYNTH_GetTxVcoFreq(void);
	bool SYNTH_ValidateVcoFreq(uint32_t freq);
	float SYNTH_CalcSynthRes(void);
	void SYNTH_SetChspFreqReg(uint32_t freq, uint32_t spacing);
	void SYNTH_SetLodivValue(uint32_t freq);
	uint32_t SYNTH_SetIfFreqReg(void);
	void SYNTH_SetLoSideRegs(uint32_t ls);
	void SYNTH_DigRouteRetimeDisable(void);
	void SYNTH_DCDCRetimeEnable(void);
	void SYNTH_DCDCRetimeDisable(void);
	void SYNTH_RetimeClkConfig(void);
	void SYNTH_RetimeLimitsConfig(uint32_t freq);
	
  void SYNTH_SetSynthCtrlReg(void);

	
void SYNTH_init(void)
{
	uint32_t vcofreq;
	
	//SYNTH->CTRL = 0x0000AC3F; //15,13,11,10,5,4,3,2,1,0 //trim values
	SYNTH_SetSynthCtrlReg();
	SYNTH->CALOFFSET = 0;
	SYNTH_DCDCRetimeEnable(); //it works now!!!
	//config
	SYNTH_SetLodivValue(RadioConfig.base_freq);
	lodiv = SYNTH_GetLodivValue();
	if (lodiv == 1) RAC->IFPGACTRL |= RAC_IFPGACTRL_BANDSEL_Msk;//&= 0xffffffef;
	else RAC->IFPGACTRL &= ~RAC_IFPGACTRL_BANDSEL_Msk;//|= 0x10

	SYNTH_SetChspFreqReg(RadioConfig.base_freq, RadioConfig.ch_spacing);
	SYNTH_OverrideIfFreqReg(RadioConfig.if_freq);
	loside = RadioConfig.loside & 0x01;
	SYNTH_SetLoSideRegs(loside);
	if (vcoGainPte == 0) vcoGainPte = (uint8_t)(SYNTH->VCOGAIN & SYNTH_VCOGAIN_VCOGAIN_Msk);
	vcofreq = SYNTH_GetRxVcoFreq();
	if(RAC->SR3 & 0x10)
	{
		vcofreq = vcofreq / 24000000;
		//SYNTH->VCOGAIN = ((uint64_t)vcoGainPte * 10000000) / (vcofreq * vcofreq * 0x553 + vcofreq * -0xc60c + 0x192d50);
		SYNTH->VCOGAIN = ((uint64_t)vcoGainPte * 10000000) / (1363*(vcofreq*vcofreq) - 50700*vcofreq + 1650000);
	}
	SYNTH_RetimeClkConfig();
	NVIC_ClearPendingIRQ(SYNTH_IRQn);
	NVIC_DisableIRQ(SYNTH_IRQn);
}

void SYNTH_SetChannel(uint8_t ch,bool rxcal)

{
  do 
  {
		while ((RAC->STATUS & RAC_STATUS_STATE_Msk) >> RAC_STATUS_STATE_Pos == 4);
  } while ((RAC->STATUS & RAC_STATUS_STATE_Msk) >> RAC_STATUS_STATE_Pos == 10);

  SYNTH->CHCTRL = ch;
  if (rxcal == true) RAC->CMD = RAC_CMD_RXCAL_Msk;
  SYNTH_RetimeClkConfig();
}


    //TODO: add AFC adjustment term to rx_synth_freq once AFC is implemented
  uint32_t SYNTH_GetRxVcoFreq(void)
	{
        //calculate synthesizer frequency for RX
        //Equation (5.31) of EFR32 Reference Manual (internal.pdf)
		
		uint64_t tmp;
		
        if (loside) tmp = ((SYNTH->FREQ + (SYNTH->CHCTRL & SYNTH_CHCTRL_CHNO_Msk) * (SYNTH->CHSP & SYNTH_CHSP_CHSP_Msk) + (SYNTH->CALOFFSET & SYNTH_CALOFFSET_CALOFFSET_Msk) + SYNTH->IFFREQ) * (uint64_t)SystemHFXOClockGet())/524288;
        else tmp = ((SYNTH->FREQ + (SYNTH->CHCTRL & SYNTH_CHCTRL_CHNO_Msk) * (SYNTH->CHSP & SYNTH_CHSP_CHSP_Msk) + (SYNTH->CALOFFSET & SYNTH_CALOFFSET_CALOFFSET_Msk) - SYNTH->IFFREQ) * (uint64_t)SystemHFXOClockGet())/524288;
        return (uint32_t)tmp;
	}


    //TODO: add AFC adjustment term to tx_synth_freq once AFC is implemented
    //TODO: add calbiration offset to tx_synth_freq
    uint32_t SYNTH_GetTxVcoFreq(void)
	{
        //calculate synthesizer frequency for TX
        //Equation (5.32) of EFR32 Reference Manual (internal.pdf)
		uint64_t tmp;
        //tmp = (SYNTH_FREQ_FREQ + SYNTH_CHCTRL_CHNO * SYNTH_CHSP_CHSP + SYNTH_CALOFFSET_CALOFFSET) * (uint64_t)SystemHFXOClockGet())/524288;
		tmp = ((SYNTH->FREQ + ((SYNTH->CHSP & SYNTH_CHSP_CHSP_Msk) * (SYNTH->CHCTRL & SYNTH_CHCTRL_CHNO_Msk)) + (SYNTH->CALOFFSET & SYNTH_CALOFFSET_CALOFFSET_Msk)) * (uint64_t)SystemHFXOClockGet())/524288;
    return (uint32_t)tmp;
	}

	bool SYNTH_ValidateVcoFreq(uint32_t freq)
	{
		if((freq >= VCO_MIN_FREQ) && (freq <= VCO_MAX_FREQ)) return true;
		else return false;
	}

    float SYNTH_CalcSynthRes(void)
	{
        //calculate synthesizer frequency resolution
        //Equation (5.33) of EFR32 Reference Manual (internal.pdf)
		return ((float)SystemHFXOClockGet()) / (lodiv*524288);
	}


    void SYNTH_SetChspFreqReg(uint32_t freq, uint32_t spacing)
	{
        //calculate channel spacing and frequency register settings
        //Equation (5.34) of EFR32 Reference Manual (internal.pdf)
        //Equation (5.35) of EFR32 Reference Manual (internal.pdf)

		uint64_t tmp;
		
		tmp = ((uint64_t)spacing * lodiv * 524288) / SystemHFXOClockGet();
		SYNTH->CHSP = (uint32_t)tmp;
		tmp = ((uint64_t)freq * lodiv * 524288) / SystemHFXOClockGet();
		SYNTH->FREQ = (uint32_t)tmp;
	}

  uint32_t SYNTH_GetChanSpacing(void)
	{
        //calculate the actual channel spacing
        //Equation (5.35) of EFR32 Reference Manual (internal.pdf)

		uint64_t tmp;
		
		tmp = ((uint64_t)SYNTH->CHSP * SystemHFXOClockGet())/(lodiv*524288);
		return (uint32_t)tmp;
	}

  uint32_t  SYNTH_GetBaseFreq(void)
	{
        //calculate the actual base (RF) frequency
        //Equation (5.34) of EFR32 Reference Manual (internal.pdf)
		
		uint64_t tmp;
		
		tmp = ((uint64_t)SYNTH->FREQ * SystemHFXOClockGet())/(lodiv*524288);
		return (uint32_t)tmp;
	}
	
  void SYNTH_SetLodivValue(uint32_t freq) //valid frequency should be checked previously!!!
	{
		BUS_RegMaskedClear(&SYNTH->DIVCTRL, SYNTH_DIVCTRL_LODIVFREQCTRL_Msk); //reset SYNTH_DIVCTRL_LODIVFREQCTRL
		if((freq >=1150000000) && (freq < 1450000000))//2 1150...1450
		{
			lodiv = 2;
			SYNTH->DIVCTRL = 2;
			return;
		}
		if((freq >=745000000) && (freq < 956000000))//3 	766...967
		{
			lodiv = 3;
			SYNTH->DIVCTRL = 3;
			return;
		}
		if((freq >=575000000) && (freq < 745000000))//4 	575...725
		{
			lodiv = 4;
			SYNTH->DIVCTRL = 4;
			return;
		}
		if((freq >=467000000) && (freq < 575000000))//5 	460...574(580)
		{
			lodiv = 5;
			SYNTH->DIVCTRL = 5;
			return;
		}
		if((freq >=358000000) && (freq < 467000000))//6 	384...459(483)
		{
			lodiv = 6;
			SYNTH->DIVCTRL = 0x13;
			return;
		}
		if((freq >=292000000) && (freq < 358000000))//8 	288...362
		{
			lodiv = 8;
			SYNTH->DIVCTRL = 0x14;
			return;
		}
		if((freq >=260000000) && (freq < 292000000))//9 	256...287(322)
		{
			lodiv = 9;
			SYNTH->DIVCTRL = 0x1b;
			return;
		}
		if((freq >=234000000) && (freq < 260000000))//10 	230...269(290)
		{
			lodiv = 10;
			SYNTH->DIVCTRL =	0x15; //10		
			return;
		}
		if((freq >=192000000) && (freq < 234000000))//12	193...229(241)
		{
			lodiv = 12;
			SYNTH->DIVCTRL = 0x1c;
			return;
		}
		if((freq >=156000000) && (freq < 192000000))//15	154...192(193)
		{
			lodiv = 15;
			SYNTH->DIVCTRL = 0x1d;
			return;
		}
		if((freq >=146000000) && (freq < 156000000))//16	144...153(181)
		{
			lodiv = 16;
			SYNTH->DIVCTRL = 0x24;
			return;
		}
		if((freq >=130000000) && (freq < 146000000))//18	128...143(161)
		{
			lodiv = 18;
			SYNTH->DIVCTRL = 0x9b;
			return;
		}
		if((freq >=117000000) && (freq < 130000000))//20	115...127(145)
		{
			lodiv = 20;
			SYNTH->DIVCTRL = 0x25;
			return;
		}
		if((freq >=100000000) && (freq < 117000000))//24	 96...114(120)
		{
			lodiv = 24;			
			SYNTH->DIVCTRL = 0x9c;
			return;
		}
		SYNTH->DIVCTRL = 0x3; //!!! error
	}
	
	
	
  uint32_t SYNTH_GetLodivValue(void)
	{
        //read LODIV register value and return actual LO divider value
        // get divider ratios
		uint32_t divA,divB,divC,div;
		
        divA = (SYNTH->DIVCTRL & 0x1C0) >> 6;
        divB = (SYNTH->DIVCTRL & 0x38) >> 3;
        divC = SYNTH->DIVCTRL & 0x7;
        // if disabled set ratio to 1
        if (divA == 0) divA = 1;
        if (divB == 0) divB = 1;
        if (divC == 0) divC = 1;
        // calculate total factor
        div = divA * divB * divC;
        // calculate proper variable flag to determine sub-GHz
 		//if (div > 1) subgig_band = true;
		return div;
	}


  uint32_t SYNTH_SetIfFreqReg(void)
	{
        //calculate IFFREQ register\n
        //Equation (5.14), (5.33) and (5.37) of EFR32 Reference Manual (internal.pdf)\n
        //IFFREQ = f_IF / res;
        //f_IF = fxo / (DEC0 * CFOSR);
        //res = fxo / lodiv / pow(2,19);
        //IFFREQ = fxo / (DEC0 * CFOSR) * lodiv * pow(2,19) / fxo = lodiv *  pow(2,19) / (DEC0 * CFOSR);
        // calculate if frequency
		
		uint64_t tmp;
		uint32_t dec0, cfosr;
		
		dec0 = (MODEM->CF & MODEM_CF_DEC0_Msk) >> MODEM_CF_DEC0_Pos;
		cfosr = (MODEM->CF & MODEM_CF_CFOSR_Msk) >> MODEM_CF_CFOSR_Pos;
		tmp = (uint64_t)lodiv * 524288 / dec0 / cfosr;
        //SYNTH_IFFREQ_IFFREQ = tmp;
		SYNTH->IFFREQ &= ~(SYNTH_IFFREQ_IFFREQ_Msk);
		SYNTH->IFFREQ |= (uint32_t)tmp;
		return tmp;
	}

	
	
	void SYNTH_OverrideIfFreqReg(uint32_t iffreq) //in Hz
	{
		uint64_t tmp;
		
		tmp = ((uint64_t)iffreq * lodiv * 524288) / SystemHFXOClockGet();
		SYNTH->IFFREQ &= ~(SYNTH_IFFREQ_IFFREQ_Msk);
		SYNTH->IFFREQ |= (uint32_t)tmp; 
	}

    void SYNTH_SetLoSideRegs(uint32_t ls)
	{
        //calculate LOSIDE register in synth and matching one in modem
        //lo_injection_side = LO_INJECTION_HIGH_SIDE;  // default to high-side
        if (ls == LO_INJECTION_HIGH_SIDE)
		{
            //SYNTH_IFFREQ_LOSIDE = 1;
			BUS_RegMaskedSet(&SYNTH->IFFREQ,SYNTH_IFFREQ_LOSIDE_Msk); 
            //MODEM_MIXCTRL_MODE = 0;
			MODEM->MIXCTRL &= ~MODEM_MIXCTRL_MODE_Msk;
            //MODEM_MIXCTRL_DIGIQSWAPEN = 1;
			BUS_RegMaskedSet(&MODEM->MIXCTRL,MODEM_MIXCTRL_DIGIQSWAPEN_Msk);
		}
        else
		{
            //SYNTH_IFFREQ_LOSIDE = 0;
			BUS_RegMaskedClear(&SYNTH->IFFREQ,SYNTH_IFFREQ_LOSIDE_Msk);
            //MODEM_MIXCTRL_MODE = 2;
			MODEM->MIXCTRL &= ~MODEM_MIXCTRL_MODE_Msk;
			MODEM->MIXCTRL |= (2 << MODEM_MIXCTRL_MODE_Pos);
            BUS_RegMaskedClear(&MODEM->MIXCTRL,MODEM_MIXCTRL_DIGIQSWAPEN_Msk);
		}
	}

	
	void SYNTH_DigRouteRetimeDisable(void)
	{
		RAC->SR3 &= 0xfffffffd;
	}

	void SYNTH_DCDCRetimeEnable(void)
	{
		RAC->SR3 |= 4;
	}
	
	void SYNTH_DCDCRetimeDisable(void)
	{
		RAC->SR3 &= ~4;
	}
	
	void SYNTH_RetimeClkConfig(void)
	{
		uint32_t vcofreq;
		uint32_t MmdDivDcdc, MmdDivRsDcdc, MmdDivRsDig;
		EMU_DcdcLnRcoBand_TypeDef rcoband;
		
		if(loside) vcofreq = SYNTH_GetChanSpacing() * SYNTH->CHCTRL + SYNTH_GetBaseFreq() - RadioConfig.if_freq;
		else vcofreq = SYNTH_GetChanSpacing() * SYNTH->CHCTRL + SYNTH_GetBaseFreq() + RadioConfig.if_freq;
		if(vcofreq < 0x40000001) dcdcRetimeClkTarget = 3500000;
		else dcdcRetimeClkTarget = 7000000;
		if(EMU->DCDCMISCCTRL & _EMU_DCDCMISCCTRL_LNFORCECCM_MASK)
		{
			rcoband = (dcdcRetimeClkTarget + 500000) / 1000000 - 3 & 0xff;
			//if ((EMU->DCDCLNFREQCTRL & _EMU_DCDCLNFREQCTRL_RCOBAND_MASK) != rcoband) EMU_DCDCLnRcoBandSet(rcoband);
			EMU_DCDCLnRcoBandSet(rcoband);
		}
		
		MmdDivDcdc = (vcofreq + (dcdcRetimeClkTarget >> 1)) / dcdcRetimeClkTarget - 1;
		//MmdDivRsDig  = vcofreq / 625000000;
		MmdDivRsDig = divLookup[vcofreq / 625000000 + 1];
		//MmdDivRsDcdc = (vcofreq /(MmdDivRsDig + 1)) / 325000000;
		MmdDivRsDcdc = divLookup[vcofreq / 325000000 + 1];
		BUS_RegMaskedClear(&RAC->MMDCTRL, RAC_MMDCTRL_MMDDIVRSDIG_Msk | RAC_MMDCTRL_MMDDIVRSDCDC_Msk | RAC_MMDCTRL_MMDDIVDCDC_Msk);
		RAC->MMDCTRL |= MmdDivDcdc | (MmdDivRsDig << RAC_MMDCTRL_MMDDIVRSDIG_Pos) | (MmdDivRsDcdc << RAC_MMDCTRL_MMDDIVRSDCDC_Pos);
		//RAC->MMDCTRL = 0x1d47b; //1147b in tx and idle mode
		//SYNTH_RetimeLimitsConfig(vcofreq);
		SYNTH_RetimeLimitsConfig(vcofreq >> MmdDivRsDig);
	}
/*
	void SYNTH_RetimeLimitsConfig(uint32_t freq)
	{
		uint32_t liml;
		uint32_t limh;
		BUS_RegMaskedClear(&RAC->HFXORETIMECTRL, (RAC_HFXORETIMECTRL_LIMITH_Msk | RAC_HFXORETIMECTRL_LIMITL_Msk));
		liml = freq / (SystemHFXOClockGet() * 4); //???
		limh = liml - 1;
		if (6 < liml) liml = 7;
		if (6 < limh) limh = 7;
		RAC->HFXORETIMECTRL &= ~0x770;
		RAC->HFXORETIMECTRL |= (liml << RAC_HFXORETIMECTRL_LIMITL_Pos) | (limh << RAC_HFXORETIMECTRL_LIMITH_Pos);
	}
*/
	
void SYNTH_RetimeLimitsConfig(uint32_t freq)
{
  uint32_t sysclk;
  uint32_t limit_h;
  uint32_t limit_l;
  bool digRtRetimeAllowed;
	
  sysclk = SystemHFXOClockGet();
  limit_l = freq / sysclk;
  if (((freq - sysclk * limit_l) * 100) / sysclk == 0) limit_l --;
  limit_h = (limit_l >> 1) - 1;
  limit_l = ((limit_l + 1) >> 1) - 1;
  if (((limit_h < 8) && (limit_l < 8)) && ((limit_h != 0 || (limit_l != 0)))) digRtRetimeAllowed = true;
  else digRtRetimeAllowed = false;
  if (digRtRetimeAllowed) SYNTH_DCDCRetimeEnable();
	else SYNTH_DCDCRetimeDisable();
	RAC->HFXORETIMECTRL &= ~0x770;
	RAC->HFXORETIMECTRL |= (limit_l << RAC_HFXORETIMECTRL_LIMITL_Pos) | (limit_h << RAC_HFXORETIMECTRL_LIMITH_Pos);
}
	
  void SYNTH_SetSynthCtrlReg(void)
	{
		SYNTH->CTRL = (7 << SYNTH_CTRL_DITHERDSMOUTPUT_Pos) | (3 << SYNTH_CTRL_DITHERDAC_Pos) | (1 << SYNTH_CTRL_DITHERDSMINPUT_Pos) | 
		(3 << SYNTH_CTRL_LOCKTHRESHOLD_Pos) | (5 << SYNTH_CTRL_AUXLOCKTHRESHOLD_Pos);
	}	
	
void SYNTH_IRQHandler(void)
{
	uint32_t flags;
	flags = SYNTH->IEN & SYNTH->IF;
	SYNTH->IFC = flags;
}