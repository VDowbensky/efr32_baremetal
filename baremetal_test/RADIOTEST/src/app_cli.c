#include <stdio.h>
#include "app_cli.h"
#include "em_system.h"
#include "bsp.h"
#include "adc.h"
#include "tempdrv.h"
#include "leds.h"
#include "radio_proc.h"
#include "mcu_memory.h"
#include "ITDS.h"
#include "cli_common.h"

CommandState_t state;
char ciBuffer[256];
//uint8_t printmode = 0;

//cli functions prototypes
//general
void cli_reset(int argc, char **argv);
void cli_info(int argc, char **argv);
void cli_getdevid(int argc, char **argv);
void cli_setdevid(int argc, char **argv);
void cli_printmode(int argc, char **argv);
void cli_answermode(int argc, char **argv);
void cli_getver(int argc, char **argv);
//RF settings
void cli_getfreq(int argc, char **argv);
void cli_setfreq(int argc, char **argv);
void cli_getiffreq(int argc, char **argv);
void cli_setiffreq(int argc, char **argv);
void cli_getbaudrate(int argc, char **argv);
void cli_setbaudrate(int argc, char **argv);
void cli_getdeviation(int argc, char **argv);
void cli_setdeviation(int argc, char **argv);
void cli_getchannel(int argc, char **argv);
void cli_setchannel(int argc, char **argv);
void cli_storechannel(int argc, char **argv);
void cli_getpower(int argc, char **argv);
void cli_setpower(int argc, char **argv);
void cli_getpowerlevel(int argc, char **argv);
void cli_setpowerlevel(int argc, char **argv);
void cli_getrssi(int argc, char **argv);
void cli_getrssioffset(int argc, char **argv);
void cli_setrssioffset(int argc, char **argv);
void cli_getfreqoffset(int argc, char **argv);
void cli_getrxbw(int argc, char **argv);
void cli_setrxbw(int argc, char **argv);
void cli_getsyncwords(int argc, char **argv);
void cli_setsyncwords(int argc, char **argv);	
void cli_getctune(int argc, char **argv);
void cli_setctune(int argc, char **argv);
void cli_storectune(int argc, char **argv);
void cli_getpactune(int argc, char **argv);
void cli_setpactune(int argc, char **argv);
void cli_storepactune(int argc, char **argv);
void cli_storeconfig(int argc, char **argv);
void cli_initconfig(int argc, char **argv);
void cli_sendburst(int argc, char **argv);
void cli_stopburst (int argc, char **argv);
void cli_txstream(int argc, char **argv);
void cli_startrxcount(int argc, char **argv);
void cli_stoprxcount(int argc, char **argv);
void cli_getrxcount(int argc, char **argv);
void cli_startber(int argc, char **argv);
void cli_stopber(int argc, char **argv);
void cli_getber(int argc, char **argv);
//device dependent
void cli_getvt(int argc, char **argv);
void cli_startiq(int argc, char **argv);
void cli_stopiq(int argc, char **argv);

void cli_startsweepfreq(int argc, char **argv);
void cli_stopsweepfreq(int argc, char **argv);
void cli_startfm(int argc, char **argv);
void cli_stopfm(int argc, char **argv);

void cli_startspecan(int argc, char **argv);
void cli_stopspecan(int argc, char **argv);

    CommandEntry_t commands[] = 
		{
			//general
			COMMAND_ENTRY("RESET", "", cli_reset, "Device reset"),
			COMMAND_ENTRY("INFO", "", cli_info, "Get CPU ID"),
			COMMAND_ENTRY("GET_DEVID", "", cli_getdevid, "Get device ID"),
			COMMAND_ENTRY("SET_DEVID", "w", cli_setdevid, "Set device ID"),
			COMMAND_ENTRY("PRINT_MODE", "v", cli_printmode, "On/off additional printing"),
			COMMAND_ENTRY("ANSWER_MODE", "v", cli_answermode, "Enable/disable autoreply"),
			COMMAND_ENTRY("GET_VERSION", "", cli_getver, "Get HW/FW version"),
			//RF settings
			COMMAND_ENTRY("GET_FREQ", "", cli_getfreq, "Get RF frequency & channel spacing"),
			COMMAND_ENTRY("SET_FREQ", "ww", cli_setfreq, "Set RF frequency & channel spacing"),
			COMMAND_ENTRY("GET_IFFREQ", "", cli_getiffreq, "Get IF frequency"),
			COMMAND_ENTRY("SET_IFFREQ", "w", cli_setiffreq, "Set IF frequency"),
			COMMAND_ENTRY("GET_BR", "", cli_getbaudrate, "Get baud rate"),
			COMMAND_ENTRY("SET_BR", "w", cli_setbaudrate, "Set baud rate"),
			COMMAND_ENTRY("GET_DEV", "", cli_getdeviation, "Get freq. deviation"),
			COMMAND_ENTRY("SET_DEV", "w", cli_setdeviation, "Set freq. deviation"),
			COMMAND_ENTRY("GET_CHANNEL", "", cli_getchannel, "Get channel number"),
			COMMAND_ENTRY("SET_CHANNEL", "v", cli_setchannel, "Set channel number"),
			COMMAND_ENTRY("STORE_CHANNEL", "", cli_storechannel, "Store channel number"),
			COMMAND_ENTRY("GET_POWER", "", cli_getpower, "Get TX power"),
			COMMAND_ENTRY("SET_POWER", "s", cli_setpower, "Set TX power"),
			COMMAND_ENTRY("GET_POWERLEVEL", "", cli_getpowerlevel, "Get TX power DAC"),
			COMMAND_ENTRY("SET_POWERLEVEL", "v", cli_setpowerlevel, "Set TX power DAC"),
			COMMAND_ENTRY("GET_RSSI", "", cli_getrssi, "Get RSSI value"),
			COMMAND_ENTRY("GET_RSSIOFFSET", "", cli_getrssioffset, "Get RSSI offset in dBm"),
			COMMAND_ENTRY("SET_RSSIOFFSET", "s", cli_getrssioffset, "Set RSSI offset in dBm"),
			COMMAND_ENTRY("GET_FREQOFFSET", "", cli_getfreqoffset, "Get frequency error"),
			COMMAND_ENTRY("GET_RXBW", "", cli_getrxbw, "Get RX Bandwidth"),
			COMMAND_ENTRY("SET_RXBW", "w", cli_setrxbw, "Set RX Bandwidth"),
			COMMAND_ENTRY("GET_SYNC", "", cli_getsyncwords, "Get Syncwords"),
			COMMAND_ENTRY("SET_SYNC", "wwww", cli_setsyncwords, "Set Syncwords"),	
			COMMAND_ENTRY("GET_CTUNE", "", cli_getctune, "Get Ctune value"),
			COMMAND_ENTRY("SET_CTUNE", "v", cli_setctune, "Set Ctune value"),
			COMMAND_ENTRY("STORE_CTUNE", "", cli_storectune, "Store Ctune value"),
			COMMAND_ENTRY("GET_PACTUNE", "", cli_getpactune, "Get PACtune value"),
			COMMAND_ENTRY("SET_PACTUNE", "vv", cli_setpactune, "Set PACtune value"),
			COMMAND_ENTRY("STORE_PACTUNE", "", cli_storepactune, "Store PACtune value"),
			COMMAND_ENTRY("STORE_CONFIG", "", cli_storeconfig, "Store radio configuration"),
			COMMAND_ENTRY("INIT_CONFIG", "", cli_initconfig, "Reset radio configuration"),
			//RF tests			
			COMMAND_ENTRY("SEND_PACKET", "www", cli_sendburst, "Start packet burst"),
			COMMAND_ENTRY("STOP_TX", "", cli_stopburst, "Stop packet burst"),
			COMMAND_ENTRY("TX_STREAM", "v", cli_txstream, "Start/stop TX stream"),
			COMMAND_ENTRY("START_RXCOUNT", "", cli_startrxcount, "Start RX packet count"),
			COMMAND_ENTRY("STOP_RXCOUNT", "", cli_stoprxcount, "Stop RX packet count"),
			COMMAND_ENTRY("GET_RXCOUNT", "", cli_getrxcount, "Get RX packet count"),
			COMMAND_ENTRY("START_BER", "w", cli_startber, "Start BER test"),
			COMMAND_ENTRY("STOP_BER", "", cli_stopber, "Stop BER test"),
			COMMAND_ENTRY("GET_BER", "", cli_getber, "Get BER info"),
			//System health - device dependent
			COMMAND_ENTRY("GET_VT", "", cli_getvt, "Get ADC data"),
			COMMAND_ENTRY("START_IQ", "", cli_startiq, "Start raw receiving"),
			COMMAND_ENTRY("STOP_IQ", "", cli_stopiq, "Stop raw receiving"),
			COMMAND_ENTRY("START_SWEEP", "ww", cli_startsweepfreq, "FM test"),
			COMMAND_ENTRY("STOP_SWEEP", "", cli_stopsweepfreq, "FM test"),
			COMMAND_ENTRY("START_FM", "", cli_startfm, "FM test"),
			COMMAND_ENTRY("STOP_FM", "", cli_stopfm, "FM test"),
			
			COMMAND_ENTRY("START_SPEC", "www", cli_startspecan, "Start RX sweep"),
			COMMAND_ENTRY("STOP_SPEC", "", cli_stopspecan, "Stop RX sweep"),
			
			COMMAND_ENTRY(NULL, NULL, NULL, NULL)
    };
		
void cli_init(void)
{
	ciInitState(&state, ciBuffer, sizeof(ciBuffer), commands);
}
		
void process_cli(void)
{
   //char input = getchar();
	char input = RETARGET_ReadChar();
	if(input != '\0' && input != 0xFF) ciProcessInput(&state, &input, 1); 
}

//cli functions implementation

void cli_reset(int argc, char **argv)
{
	common_reset();
}

void cli_info(int argc, char **argv)
{
	common_info();
}

void cli_getdevid(int argc, char **argv)
{
	common_getdevid();
}

void cli_setdevid(int argc, char **argv)
{
	common_setdevid(ciGetUnsigned(argv[1]));
}

void cli_printmode(int argc, char **argv)
{
	common_printmode(ciGetUnsigned(argv[1]));
}

void cli_answermode(int argc, char **argv)
{
	common_answermode(ciGetUnsigned(argv[1]));
}

void cli_getver(int argc, char **argv)
{
	common_getver();
}

//RF
void cli_getfreq(int argc, char **argv)
{
	common_getfreq();
}
void cli_setfreq(int argc, char **argv)
{
	common_setfreq(ciGetUnsigned(argv[1]), ciGetUnsigned(argv[2]));
}

void cli_getiffreq(int argc, char **argv)
{
	common_getiffreq();
}

void cli_setiffreq(int argc, char **argv)
{
	common_setiffreq(ciGetSigned(argv[1]));
}

void cli_getbaudrate(int argc, char **argv)
{
	common_getbaudrate();
}

void cli_setbaudrate(int argc, char **argv)
{
	common_setbaudrate(ciGetUnsigned(argv[1]));
}

void cli_getdeviation(int argc, char **argv)
{
	common_getdeviation();
}

void cli_setdeviation(int argc, char **argv)
{
	common_setdeviation(ciGetUnsigned(argv[1]));
}

void cli_getchannel(int argc, char **argv)
{
	common_getchannel();
}

void cli_setchannel(int argc, char **argv)
{
	common_setchannel(ciGetUnsigned(argv[1]));
}

void cli_storechannel(int argc, char **argv)
{
	common_storechannel();
}

void cli_getpower(int argc, char **argv)
{
	common_getpower();
}

void cli_setpower(int argc, char **argv)
{
	common_setpower(ciGetSigned(argv[1]));
}

void cli_getpowerlevel(int argc, char **argv)
{
	common_getpowerlevel();
}

void cli_setpowerlevel(int argc, char **argv)
{
	common_setpowerlevel(ciGetUnsigned(argv[1]));
}

void cli_getfreqoffset(int argc, char **argv)
{
	common_getfreqoffset();
}

void cli_getrxbw(int argc, char **argv)
{
	common_getrxbw();
}

void cli_setrxbw(int argc, char **argv)
{
	common_setrxbw(ciGetUnsigned(argv[1]));
}


void cli_getsyncwords(int argc, char **argv)
{
	common_getsyncwords();
}

void cli_setsyncwords(int argc, char **argv)
{
	common_setsyncwords(ciGetUnsigned(argv[1]), ciGetUnsigned(argv[2]), ciGetUnsigned(argv[3]), ciGetUnsigned(argv[4]));
}

void cli_getctune(int argc, char **argv)
{
	common_getctune();
}

void cli_setctune(int argc, char **argv)
{
	common_setctune(ciGetUnsigned(argv[1]));
}


void cli_storectune(int argc, char **argv)
{
	common_storectune();
}

void cli_getpactune(int argc, char **argv)
{
	common_getpactune();
}

void cli_setpactune(int argc, char **argv)
{
	common_setpactune(ciGetUnsigned(argv[1]), ciGetUnsigned(argv[2]));
}

void cli_storepactune(int argc, char **argv)
{
  common_storepactune();
}

void cli_storeconfig(int argc, char **argv)
{
  common_storeconfig();
}

void cli_initconfig(int argc, char **argv)
{
	common_initconfig();
}

void cli_sendburst(int argc, char **argv)
{
	common_sendburst(ciGetUnsigned(argv[1]), ciGetUnsigned(argv[2]), ciGetUnsigned(argv[3]));
}

void cli_stopburst (int argc, char **argv)
{
	common_stopburst();
}

void cli_txstream(int argc, char **argv)
{
	common_txstream(ciGetUnsigned(argv[1]));
}

void cli_startrxcount(int argc, char **argv)
{
	common_startrxcount();
}

void cli_stoprxcount(int argc, char **argv)
{
  common_stoprxcount();
}

void cli_getrxcount(int argc, char **argv)
{
  common_getrxcount();
}

void cli_getrssi(int argc, char **argv)
{
	common_getrssi();
}

void cli_getrssioffset(int argc, char **argv)
{
	common_getrssioffset();
}

void cli_setrssioffset(int argc, char **argv)
{
	common_setrssioffset(ciGetSigned(argv[1]));
}

void cli_startber(int argc, char **argv)
{
	common_startber(ciGetUnsigned(argv[1]));
}

void cli_stopber(int argc, char **argv)
{
	common_stopber();
}

void cli_getber(int argc, char **argv)
{
	common_getber();
}

//Device dependent commands
void cli_getvt(int argc, char **argv)
{
	//printf("GET_VT: %.1f, %.1f, %.1f, %.1f\r\n", Temp, EmuTemp, Vcc, Dvdd);
	printf("GET_VT: %.1f, %.1f, %.1f\r\n", Temp, Vcc, Dvdd);
}

void cli_startiq(int argc, char **argv)
{
	radio_startiqrx();
	printf("START_IQ: OK\r\n");
}

void cli_stopiq(int argc, char **argv)
{
	radio_stopiqrx();
	printf("STOP_IQ: OK\r\n");
}

void cli_startsweepfreq(int argc, char **argv)
{
	uint8_t stream;
	
	stream = ciGetUnsigned(argv[1]);
	sweepdelay = ciGetUnsigned(argv[2]);
	if(stream < 1) stream = 1;
	if(stream > 3) stream = 3;
	printf("SWEEP_FREQ: START\r\n");
	radio_Enable(0);
	Timing_DelayUs(10);
	//SYNTH_SetChannel(32,false);
	PROTIMER_SetInterval(sweepdelay);
	sweepfreq = true;
	//radio_startCW();
	common_txstream(stream);
}


void cli_stopsweepfreq(int argc, char **argv)
{
	sweepfreq = false;
	//PROTIMER_SetInterval(100000);
	common_txstream(0);
	printf("SWEEP_FREQ: STOP\r\n");
}

void cli_startfm(int argc, char **argv)
{
	initADC_for_mic();
	mic_on();
	SYNTH_SetChannel(32,false);
	radio_startCW();
	printf("START_FM: OK\r\n");
}

void cli_stopfm(int argc, char **argv)
{
	radio_stoptx();
	mic_off();
	micadc = false;
  initLETIMER();
  initADC();
	printf("STOP_FM: OK\r\n");
}

void cli_startspecan(int argc, char **argv)
{
	minchan = ciGetUnsigned(argv[1]);
	maxchan = ciGetUnsigned(argv[2]);
	if(minchan > 63) minchan = 63;
	if(maxchan > 63) maxchan = 63;
	sweepdelay = ciGetUnsigned(argv[3]) * 1000;
	printf("SWEEP_RX: START\r\n");
	SYNTH_SetChannel(minchan,false);
	PROTIMER_SetInterval(sweepdelay);
	sweeprx = true;
}

void cli_stopspecan(int argc, char **argv)
{
	sweeprx = false;
	printf("SWEEP_RX: STOP\r\n");
}




