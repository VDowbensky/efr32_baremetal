#include "cli_common.h"

void common_reset(void)
{
	printf("RESET: OK\r\n");
  printf("Restart device.\r\n");
	radio_delayms(50);
  NVIC_SystemReset();
}

void common_info(void)
{
  printf("INFO: OK\r\n");
  printf("MCUID: 0x%llX\r\n", SYSTEM_GetUnique());
}

void common_getdevid(void)
{
  uint32_t id;

  id = ((*(uint32_t *) DEVID_ADDR) & 0xFFFF0000) >> 16;
  id += ((*(uint32_t *) (DEVID_ADDR+0x4)) << 16 ) & 0xFFFF0000;
  printf("GET_DEVID: 0x%X\r\n", id);
}

void common_setdevid(uint32_t id)
{
  if(id != 0)
    {
      storedevid(id);
      printf("SET_DEVID: OK\r\n");
    }
    else
    {
      printf("SET_DEVID: ERROR\r\n");
      if(RadioConfig.printmode) printf("Wrong parameter.\r\n");
    }
}

void common_printmode(uint8_t mode)
{
  RadioConfig.printmode = mode;
  if(RadioConfig.printmode != 0) RadioConfig.printmode = 1;
  if (RadioConfig.printmode == 0) printf("PRINT_MODE: SHORT\r\n");
  else printf("PRINT_MODE: FULL\r\n");
}

void common_answermode(uint8_t mode)
{
  RadioConfig.answermode = mode;
  if(RadioConfig.answermode != 0) RadioConfig.answermode = 1;
  if (RadioConfig.answermode == 0) printf("ANSWER_MODE: ADDRESS\r\n");
  else printf("ANSWER_MODE: BROADCAST\r\n");
}

void common_getver(void)
{
  printf("HW: %d SW: %d.%d\r\n", HW_VERSION, SW_VERSION, SW_SUBVERSION);
}

void common_getfreq(void)
{
	printf("GET_FREQ: %d,%d\r\n", RadioConfig.base_freq, RadioConfig.ch_spacing);
}

void common_setfreq(uint32_t f, uint32_t s)
{
	//validate
	//if((f < 766000) || (f > 966000))
	if((f < 96000000) || (f > 1450000000))
	{
		printf("SET_FREQ: ERROR\r\n");
		if(RadioConfig.printmode) printf("Wrong frequency.\r\n");
	}
	else
	{
		if((s == 0) || (s > 1000000))
		{
			printf("SET_FREQ: ERROR\r\n");
			if(RadioConfig.printmode) printf("Wrong channel spacing.\r\n");
		}
		else
		{
			//RadioConfig.base_freq = f * 1000;
			//RadioConfig.ch_spacing = s * 1000;
			RadioConfig.base_freq = f;
			RadioConfig.ch_spacing = s;
			radio_Enable(0);
			//SYNTH_init();
			RADIO_Config();
			printf("SET_FREQ: %d,%d\r\n", RadioConfig.base_freq, RadioConfig.ch_spacing);
		}
	}
}

void common_getiffreq(void)
{
	printf("GET_IFFREQ: %d\r\n", RadioConfig.if_freq);
}

void common_setiffreq(int32_t f)
{
	//take integer values only
	if(f < 150000) f = 150000;
	if((f >= 150000) && (f <= 225000)) f = 150000;
	if((f > 225000) && (f <= 350000)) f = 300000;
	if((f > 350000) && (f <= 500000)) f = 400000;
	if((f > 500000) && (f <= 700000)) f = 600000;
	if((f > 700000) && (f <= 1000000)) f = 800000;	
	if((f > 1000000) && (f <= 1400000)) f = 1200000;
	if(f > 1400000) f = 1600000;
	radio_Enable(0);
	RadioConfig.if_freq = f;
	RADIO_Config();
	printf("SET_IFFREQ: %d\r\n", RadioConfig.if_freq);
}

void common_getbaudrate(void)
{
	printf("GET_BR: %d\r\n", RadioConfig.chiprate);
}

void common_setbaudrate(uint32_t br)
{
	if(br < 100) br = 100;
	if(br > 1000000) br = 1000000;
	radio_Enable(0);
	RadioConfig.chiprate = br;
	RADIO_Config();
	printf("SET_BR: %d\r\n", RadioConfig.chiprate);
}

void common_getdeviation(void)
{
	printf("GET_DEV: %d\r\n", RadioConfig.deviation);
}

void common_setdeviation(uint32_t d)
{
	if(d < 100) d = 100;
	if(d > 500000) d = 500000;
	radio_Enable(0);
	RadioConfig.deviation = d;
	RADIO_Config();
	printf("SET_DEV: %d\r\n", RadioConfig.deviation);
}

void common_getchannel(void)
{
	printf("GET_CHANNEL: %d\r\n", Channel);
}

void common_setchannel(uint16_t ch)
{
	if(ch > 63) ch = 63;
	Channel = ch;
	if(txmode != 0) 
	{
		radio_stoptx();
		Timing_DelayUs(100);
	}
	SYNTH_SetChannel(ch,false);
	if(txmode == 1) radio_startCW();
	if(txmode == 2) radio_startPN9();
	if(txmode == 3) radio_start01();
	printf("SET_CHANNEL: %d\r\n", Channel);
}

void common_storechannel(void)
{
	RadioConfig.default_channel = Channel;
	store_config();
	printf("STORE_CHANNEL: %d\r\n", Channel);
}

void common_getpower(void)
{
	printf("GET_POWER: %d dBm\r\n",PA_GetPowerDbm());
}

void common_setpower(int32_t p)
{
	if(p < -20) p = -20;
	if (p > 20) p = 20;
		if(txmode != 0) 
	{
		radio_stoptx();
		Timing_DelayUs(100);
	}
	RadioConfig.txpower = p;
	PA_SetPowerDbm(p);
	if(txmode == 1) radio_startCW();
	if(txmode == 2) radio_startPN9();
	if(txmode == 3) radio_start01();
	printf("SET_POWER: %d dBm\r\n", PA_GetPowerDbm());
}

void common_getpowerlevel(void)
{
	printf("GET_POWERLEVEL: %d\r\n", PA_Powerlevel);
}

void common_setpowerlevel(uint32_t p)
{
	if(p == 0) p = 1;
	if(p > 248) p = 248;
	if(txmode != 0) 
	{
		radio_stoptx();
		Timing_DelayUs(100);
	}
	PA_Powerlevel = p;
	PA_SetPowerLevel(PA_Powerlevel);
	if(txmode == 1) radio_startCW();
	if(txmode == 2) radio_startPN9();
	if(txmode == 3) radio_start01();
	printf("SET_POWERLEVEL: %d\r\n", PA_Powerlevel);
}

void common_getfreqoffset(void)
{
	printf("GET_FREQOFFSET: %d\r\n", (int8_t)(MODEM->FREQOFFSET & 0xff));
}

void common_getrxbw(void)
{
	printf("GET_RXBW: %d\r\n", RadioConfig.acq_ch_bw);
}

void common_setrxbw(uint32_t bw)
{
	if(bw < 5000) bw = 5000;
	if(bw > 1000000) bw = 1000000;
	radio_Enable(0);
	RadioConfig.acq_ch_bw = bw;
	RADIO_Config();
	printf("SET_RXBW: %d\r\n", RadioConfig.acq_ch_bw);
}

void common_getsyncwords(void)
{
	printf("GET_SYNC: 0x%X,0x%X,%d,%d\r\n", RadioConfig.syncword_0,RadioConfig.syncword_1,RadioConfig.syncword_length,RadioConfig.syncword_tx_skip);
}

void common_setsyncwords(uint32_t s0, uint32_t s1, uint32_t len, uint32_t skip)
{
	radio_Enable(0);
	RadioConfig.syncword_0 = s0;
	RadioConfig.syncword_1 = s1;
	RadioConfig.syncword_length = len;
	//if(skip == 0) RadioConfig.syncword_tx_skip = false;
	//else RadioConfig.syncword_tx_skip = true;
	RADIO_Config();
	printf("SET_SYNC: 0x%X,0x%X,%d,%d\r\n", RadioConfig.syncword_0,RadioConfig.syncword_1,RadioConfig.syncword_length,RadioConfig.syncword_tx_skip);
}

void common_getctune(void)
{
	uint16_t t;
	
	t = *(uint16_t*)(USERDATA_BASE + 0x100);
	printf("GET_CTUNE: %d,%d\r\n",radio_GetCtune(),t);
}

void common_setctune(uint32_t t)
{
	ctunecomp = false;
	if(t > 511) t = 511;
	if(txmode != 0) 
	{
		radio_stoptx();
		Timing_DelayUs(100);
	}
	radio_Enable(0);
	radio_SetCtune(t);
	restoretxmode();
	printf("SET_CTUNE: %d\r\n", t);
}

void common_calctune(void)
{
	printf("CAL_CTUNE: Not implemented\r\n");
}

void common_storectune(void)
{
	uint16_t t;
	//t = radio_GetCtune();
	t = radio_GetCtune() - (uint16_t)((Temp - DEFAULT_CAL_TEMP) * K_CTUNE);
	if((Temp < 15) || (Temp > 45))
	{
		printf("STORE_CTUNE: ERROR\r\n");
		if(RadioConfig.printmode) printf("Temperature out of range.\r\n");
	}
	else
	{
		read_userpage();
		MSC_ErasePage((uint32_t*)USERDATA_BASE);
		userdata_buf[0x40] = t; // 0x100/4
		write_userpage();
		printf("STORE_CTUNE: %d\r\n", t);
	}
#if CTUNE_CORR_ON_THE_FLY
	ctunecomp = true;
#endif
}

void common_getpactune(void)
{
	printf("GET_PACTUNE: %d,%d\r\n", RadioConfig.txpactune, RadioConfig.rxpactune);
}

void common_setpactune(uint8_t txpactune, uint8_t rxpactune)
{
	RadioConfig.txpactune = txpactune;
	if(RadioConfig.txpactune > 31) RadioConfig.txpactune = 31;
	RadioConfig.rxpactune = rxpactune;
	if(RadioConfig.rxpactune > 31) RadioConfig.rxpactune = 31;
	PA_CTuneSet(RadioConfig.txpactune, RadioConfig.rxpactune);
	printf("SET_PACTUNE: %d,%d\r\n", RadioConfig.txpactune, RadioConfig.rxpactune);
}

void common_storepactune(void)
{
  store_config();
  printf("STORE_PACTUNE: %d,%d\r\n",RadioConfig.txpactune, RadioConfig.rxpactune);
}

void common_storeconfig(void)
{
	store_config();
  printf("STORE_CONFIG: OK\r\n");
}

void common_initconfig(void)
{
	RADIO_InitConfigStructure();
	store_config();
	RADIO_Config();
	printf("INIT_CONFIG: OK\r\n");
}

void common_sendburst(uint32_t cnt, uint32_t del, uint32_t id)
{
	//RADIO_CtuneCorrection();
	if(!master)
	{
  txpacketcount = cnt; //count
	slaveID = id;
  if(del < 50)
    {
      del = 50;
      if(RadioConfig.printmode) printf("Warning: time interval too short, 50 ms will be set.\r\n");
    }
  inter_packet_delay = del*1000;
  printf("SEND_PACKET: OK\r\n");
  if(RadioConfig.printmode) printf("Wait %d s.\r\n", (inter_packet_delay*txpacketcount/1000000));
	radio_startburst();
	}
	else
	{
		printf("SEND_PACKET: ERROR\r\n");
		if(RadioConfig.printmode) printf("Device in master mode.\r\n");
	}
}

void common_stopburst (void)
{
	if(master == false)
	{
		printf("STOP_TX: ERROR\r\n");
		if(RadioConfig.printmode) printf("Device in slave mode.\r\n");
	}
	else
	{
		master = false;
		printf("STOP_TX: OK\r\n");
		if(RadioConfig.printmode) printf("Master mode off.\r\n");
	}
}

void common_txstream(uint32_t s)
{
	//RADIO_CtuneCorrection();
	switch(s)
	{
		case 0:
			if(txmode != 0)
			{
				radio_stoptx();
				Timing_DelayUs(10);
				txmode = 0;
				printf("TX_STREAM: 0\r\n");
			}
			else
			{
				printf("TX_STREAM: ERROR\r\n");
			}
		break;
		
		case 1:
		  radio_Enable(0);
			Timing_DelayUs(10);
			radio_startCW();
		  txmode = 1;
			printf("TX_STREAM: 1\r\n");
		break;
		
		case 2:
		  radio_Enable(0);
			Timing_DelayUs(10);
			radio_startPN9();
		  txmode = 2;
			printf("TX_STREAM: 2\r\n");
		break;
		
		case 3:
			radio_Enable(0);
			Timing_DelayUs(10);
			radio_start01();
		  txmode = 3;
			printf("TX_STREAM: 3\r\n");
		  break;
		
		default:
		printf("TX_STREAM: ERROR\r\n");
		break;
	}
}

void common_startrxcount(void)
{
	rxc = true;
  rxpacketcount = 0;
  RssiAccum = 0;
  printf("START_RXCOUNT: OK\r\n");
}

void common_stoprxcount(void)
{
  rxc = false;
  printf("STOP_RXCOUNT: OK\r\n");
  if(RadioConfig.printmode) printf("Packet count stopped.\r\n");
}

void common_getrxcount(void)
{
  printf("GET_RXCOUNT: %d", rxpacketcount);
  if (rxpacketcount != 0) printf(", RSSI: %.1f dBm\r\n", (float)RssiAccum/rxpacketcount);
  else printf("\r\n");
}

void common_getrssi(void)
{
	printf("GET_RSSI: %.2f dBm\r\n",((float)AGC_GetRSSI())/4);
}

void common_getrssioffset(void)
{
  //printf("GET_RSSIOFFSET: %.2f dBm\r\n", rssioffset);
}

void common_setrssioffset(int32_t offset)
{
  //rssioffset = (float)offset/4;
  //printf("SET_RSSIOFFSET: %.2f dBm\r\n", rssioffset);
}



void common_startber(uint32_t bytes)
{
	berRx = true;
	radio_startberrx(bytes);
	printf("START_BER: OK\r\n");
}

void common_stopber(void)
{
	if(berRx)
	{
		radio_stopberrx();
		berRx = false;
		printf("STOP_BER: OK\r\n");
		if(RadioConfig.printmode) printf("BER test stopped.\r\n");
	}
	else
	{
		printf("STOP_BER: ERROR\r\n");
		if(RadioConfig.printmode) printf("BER test mode already off.\r\n");
	}
}

void common_getber(void)
{
	RAIL_BerStatus_t berstatus;
	float ber_percent;
	radio_reportberstats(&berstatus);
	  
  if(berstatus.bitsTested != 0) ber_percent = ((float)berstatus.bitErrors/(berstatus.bitsTested))*100;
  else ber_percent = 100.0;
  printf("GET_BER: %.3f%%, RSSI: %d dBm\r\n", ber_percent, berstatus.rssi);
  if(RadioConfig.printmode) printf("Total: %d, Tested: %d, Errors: %d\r\n", berstatus.bitsTotal, berstatus.bitsTested, berstatus.bitErrors);
}
