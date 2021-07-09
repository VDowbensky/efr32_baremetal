#include <stdio.h>
#include "app_cli.h"
#include "em_system.h"
#include "bsp.h"
#include "adc.h"
#include "tempdrv.h"
#include "leds.h"
#include "radio_proc.h"
#include "mcu_memory.h"

CommandState_t state;
char ciBuffer[256];


//cli functions prototypes

void cli_reset(int argc, char **argv);
void cli_info(int argc, char **argv);

void cli_printmode(int argc, char **argv);
void cli_getver(int argc, char **argv);

void cli_getchannel(int argc, char **argv);
void cli_setchannel(int argc, char **argv);
void cli_getpower(int argc, char **argv);
void cli_setpower(int argc, char **argv);
void cli_getpowerlevel(int argc, char **argv);
void cli_setpowerlevel(int argc, char **argv);

void cli_getrssi(int argc, char **argv);
void cli_getrssioffset(int argc, char **argv);
void cli_setrssioffset(int argc, char **argv);
void cli_getfreqoffset(int argc, char **argv);


void cli_getctune(int argc, char **argv);
void cli_setctune(int argc, char **argv);
void cli_calctune(int argc, char **argv);
void cli_storectune(int argc, char **argv);
void cli_getpactune(int argc, char **argv);
void cli_setpactune(int argc, char **argv);
void cli_storepactune(int argc, char **argv);

void cli_sendburst(int argc, char **argv);
void cli_txstream(int argc, char **argv);
void cli_startrxcount(int argc, char **argv);
void cli_stoprxcount(int argc, char **argv);
void cli_getrxcount(int argc, char **argv);
void cli_startber(int argc, char **argv);
void cli_stopber(int argc, char **argv);
void cli_getber(int argc, char **argv);

void cli_getvt(int argc, char **argv);
void cli_setem(int argc, char **argv);




  
		
    CommandEntry_t commands[] = 
		{
			//general
			COMMAND_ENTRY("RESET", "", cli_reset, "Device reset"),
			COMMAND_ENTRY("INFO", "", cli_info, "Get CPU ID"),

			COMMAND_ENTRY("PRINT_MODE", "v", cli_printmode, "On/off additional printing"),
			COMMAND_ENTRY("GET_VERSION", "", cli_getver, "Get HW/FW version"),
			//RF settings
			COMMAND_ENTRY("GET_CHANNEL", "", cli_getchannel, "Get channel number"),
			COMMAND_ENTRY("SET_CHANNEL", "v", cli_setchannel, "Set channel number"),
			COMMAND_ENTRY("GET_POWER", "", cli_getpower, "Get TX power"),
			COMMAND_ENTRY("SET_POWER", "s", cli_setpower, "Set TX power"),
			COMMAND_ENTRY("GET_POWERLEVEL", "", cli_getpowerlevel, "Get TX power DAC"),
			COMMAND_ENTRY("SET_POWERLEVEL", "v", cli_setpowerlevel, "Set TX power DAC"),

			COMMAND_ENTRY("GET_RSSI", "", cli_getrssi, "Get RSSI value"),
			COMMAND_ENTRY("GET_RSSIOFFSET", "", cli_getrssioffset, "Get power meter offset"),
			COMMAND_ENTRY("SET_RSSIOFFSET", "v", cli_setrssioffset, "Set power meter offset"),
			COMMAND_ENTRY("GET_FREQOFFSET", "", cli_getfreqoffset, "Get frequency error"),
			//basic RF settings
			//modem settings
			//frame format settings etc.
			//RF calibrations
			COMMAND_ENTRY("GET_CTUNE", "", cli_getctune, "Get Ctune value"),
			COMMAND_ENTRY("SET_CTUNE", "v", cli_setctune, "Set Ctune value"),
			COMMAND_ENTRY("CAL_CTUNE", "", cli_calctune, "Ctune calibration"),
			COMMAND_ENTRY("STORE_CTUNE", "", cli_storectune, "Store Ctune value"),
			COMMAND_ENTRY("GET_PACTUNE", "", cli_getpactune, "Get PACtune value"),
			COMMAND_ENTRY("SET_PACTUNE", "vv", cli_setpactune, "Set PACtune value"),
			COMMAND_ENTRY("STORE_PACTUNE", "", cli_storepactune, "Store PACtune value"),			
			//RF tests			
			COMMAND_ENTRY("SEND_PACKET", "ww", cli_sendburst, "Start packet burst"),
			COMMAND_ENTRY("TX_STREAM", "v", cli_txstream, "Start/stop TX stream"),
			COMMAND_ENTRY("START_RXCOUNT", "", cli_startrxcount, "Start RX packet count"),
			COMMAND_ENTRY("STOP_RXCOUNT", "", cli_stoprxcount, "Stop RX packet count"),
			COMMAND_ENTRY("GET_RXCOUNT", "", cli_getrxcount, "Get RX packet count"),
			COMMAND_ENTRY("START_BER", "w", cli_startber, "Start BER test"),
			COMMAND_ENTRY("STOP_BER", "", cli_stopber, "Stop BER test"),
			COMMAND_ENTRY("GET_BER", "", cli_getber, "Get BER info"),
			//System health
			COMMAND_ENTRY("GET_VT", "", cli_getvt, "Get ADC data"),
			COMMAND_ENTRY("SET_EM", "v", cli_setem, "Set energy mode"),
			
			COMMAND_ENTRY(NULL, NULL, NULL, NULL)
    };
		

uint8_t printmode;

void cli_init(void)
{
		ciInitState(&state, ciBuffer, sizeof(ciBuffer), commands);
}
		
void process_cli(void)
{
   //char input = getchar();
	char input = RETARGET_ReadChar();
	  if(input != '\0' && input != 0xFF) 
		 {
			ciProcessInput(&state, &input, 1); 
    //if(ciProcessInput(&state, &input, 1) > 0)
  	//	{
    //   printf("> ");
    //  }
     }
}

//cli functions implementation

void cli_reset(int argc, char **argv)
{
	printf("RESET: OK\r\n");
  printf("Restart device.\r\n");
      //RAIL_DelayUs(50000);
      //peripherals_off();
      //RAIL_DelayUs(50000);
  NVIC_SystemReset();
}

void cli_info(int argc, char **argv)
{
	printf("INFO: OK\r\n");
  printf("MCUID: 0x%llX\r\n", SYSTEM_GetUnique());
}

void cli_printmode(int argc, char **argv)
{
	printmode = ciGetUnsigned(argv[1]);
	if(printmode != 0) printmode = 1;
	if (printmode == 0) printf("PRINT_MODE: SHORT\r\n");
	else printf("PRINT_MODE: FULL\r\n");
}

void cli_getver(int argc, char **argv)
{
	printf("HW: %d SW: %d.%d\r\n", HW_VERSION, SW_VERSION, SW_SUBVERSION);
}


void cli_getchannel(int argc, char **argv)
{
	printf("GET_CHANNEL: Under development\r\n");
	printf("GET_CHANNEL: 0\r\n");
}

void cli_setchannel(int argc, char **argv)
{
	uint16_t ch;
	ch = ciGetUnsigned(argv[1]);
	if(ch > 1023) ch = 1023;
	printf("SET_CHANNEL: Under development\r\n");
	//set  actual channel here
	printf("SET_CHANNEL: %d\r\n", ch);
}

void cli_getpower(int argc, char **argv)
{
	int32_t p;
	printf("GET_POWER: Under development\r\n");
	printf("GET_POWER: 0 dBm\r\n");
}

void cli_setpower(int argc, char **argv)
{
	int32_t p;
	printf("SET_POWER: Under development\r\n");
	p = ciGetSigned(argv[1]);
	if(p < -20) p = -20;
	if (p > 20) p = 20;
	//set power here
	printf("SET_POWER: %d dBm\r\n", p);
}

void cli_getpowerlevel(int argc, char **argv)
{
	printf("GET_POWERLEVEL: Under development\r\n");
	printf("GET_POWERLEVEL: 0\r\n");
}

void cli_setpowerlevel(int argc, char **argv)
{
	uint32_t p;
	printf("SET_POWERLEVEL: Under development\r\n");
	p = ciGetUnsigned(argv[1]);
	if(p > 252) p = 252;
	printf("SET_POWERLEVEL: %d\r\n", p);
	
}


void cli_getrssi(int argc, char **argv)
{
	printf("GET_RSSI: Under development\r\n");
	printf("GET_RSSI: -200 dBm\r\n");
}

void cli_getrssioffset(int argc, char **argv)
{
	printf("GET_RSSIOFFSET: Under development\r\n");
	printf("GET_RSSIOFFSET: 0 dB\r\n");
}

void cli_setrssioffset(int argc, char **argv)
{
	int32_t p;
	//float f;
	printf("SET_RSSIOFFSET: Under development\r\n");
	p = ciGetSigned(argv[1]);
	printf("SET_RSSIOFFSET: %.2f dB\r\n", ((float)p)/4);
}

void cli_getfreqoffset(int argc, char **argv)
{
	printf("GET_FREQOFFSET: Under development\r\n");
	printf("GET_FREQOFFSET: 0\r\n");
}


void cli_getctune(int argc, char **argv)
{
	printf("GET_CTUNE: %d\r\n",RAIL_GetTune());
}

void cli_setctune(int argc, char **argv)
{
	uint32_t t;
	//printf("SET_CTUNE: Under development\r\n");
	t = ciGetUnsigned(argv[1]);
	if(t > 511) t = 511;
	RAIL_RfIdle();
	RAIL_SetTune(t);
	printf("SET_CTUNE: %d\r\n", t);
}

void cli_calctune(int argc, char **argv)
{
	printf("CAL_CTUNE: Not implemented\r\n");
}

void cli_storectune(int argc, char **argv)
{
	uint16_t t;
	t = RAIL_GetTune();
	read_userpage();
  MSC_ErasePage((uint32_t*)USERDATA_BASE);
  userdata_buf[0x40] = t; // 0x100/4
  write_userpage();
	printf("STORE_CTUNE: %d\r\n", t);
}

void cli_getpactune(int argc, char **argv)
{
	printf("GET_PACTUNE: %d,%d\r\n", txpactune, rxpactune);
}

void cli_setpactune(int argc, char **argv)
{
	//uint32_t t, r;
	txpactune = ciGetUnsigned(argv[1]);
	if(txpactune > 31) txpactune = 31;
	rxpactune = ciGetUnsigned(argv[2]);
	if(rxpactune > 31) rxpactune = 31;
	PA_CTuneSet(txpactune, rxpactune);
	printf("SET_PACTUNE: %d,%d\r\n", txpactune, rxpactune);
}

void cli_storepactune(int argc, char **argv)
{
	read_userpage();
  MSC_ErasePage((uint32_t*)USERDATA_BASE);
  userdata_buf[0x41] = (rxpactune << 8) + txpactune;
  write_userpage();
  printf("STORE_PACTUNE: %d,%d\r\n",txpactune, rxpactune);
}


void cli_sendburst(int argc, char **argv)
{
	printf("SEND_PACKET: Not implemented\r\n");
}

void cli_txstream(int argc, char **argv)
{
	uint32_t t;
	t = ciGetUnsigned(argv[1]);
	switch(t)
	{
		case 0:
			RFTEST_StopTx();
			PHY_UTILS_DelayUs(10);
		  RFTEST_RestoreRadioConfiguration();
			printf("TX_STREAM: 0\r\n");
		break;
		
		case 1:
			RAIL_RfIdle();
			SYNTH_Config(868000000, 100000);
			PHY_UTILS_DelayUs(10);
			RFTEST_SaveRadioConfiguration();
			RFTEST_StartCwTx();
			printf("TX_STREAM: 1\r\n");
		break;
		
		case 2:
			RAIL_RfIdle();
			SYNTH_Config(868000000, 100000);
			PHY_UTILS_DelayUs(10);
			RFTEST_SaveRadioConfiguration();
			RFTEST_StartStreamTx();
			printf("TX_STREAM: 2\r\n");
		break;
		
		default:
		printf("TX_STREAM: ERROR\r\n");
		break;
	}
}

void cli_startrxcount(int argc, char **argv)
{
	printf("START_RXCOUNT: Not implemented\r\n");
}

void cli_stoprxcount(int argc, char **argv)
{
	printf("STOP_RXCOUNT: Not implemented\r\n");
}

void cli_getrxcount(int argc, char **argv)
{
	printf("GET_RXCOUNT: Not implemented\r\n");
}

void cli_startber(int argc, char **argv)
{
	printf("START_BER: Not implemented\r\n");
}

void cli_stopber(int argc, char **argv)
{
	printf("STOP_BER: Not implemented\r\n");
}

void cli_getber(int argc, char **argv)
{
	printf("GET_BER: Not implemented\r\n");
}


void cli_getvt(int argc, char **argv)
{
#if XMOTION
      printf("GET_VT: %d, %.1f, %.1f, %.1f, %.1f\r\n", TEMPDRV_GetTemp(), Temp, Vcc, Dvdd, Vref);
#else
      printf("GET_VT: %d, %.1f, %.1f, %.1f\r\n", TEMPDRV_GetTemp(), Temp, Vcc, Dvdd);
#endif
}

void cli_setem(int argc, char **argv)
{
	printf("SET_EM: Not implemented\r\n");
}



