#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

#include "app_cli.h"
#include "em_system.h"
#include "bsp.h"
#include "adc.h"
#include "tempdrv.h"
#include "leds.h"
#include "radio_proc.h"
#include "mcu_memory.h"
#include "cli_common.h"

//CommandState_t state;
uint8_t ciBuffer[CLISIZE];
uint8_t printmode = 0;

char* str_ptr = NULL;
char string[CLISIZE] = " ";
static uint16_t ciPointer = 0;

void CLIhandler(char* data_ptr, uint16_t data_len);

//cli functions prototypes
//RF settings

//void cli_getsyncwords(int argc, char **argv);
//void cli_setsyncwords(int argc, char **argv);	

//			COMMAND_ENTRY("GET_SYNC", "", cli_getsyncwords, "Get Syncwords"),
//			COMMAND_ENTRY("SET_SYNC", "wwww", cli_setsyncwords, "Set Syncwords"),	
		

void cli_init(void)
{
	//ciInitState(&state, ciBuffer, sizeof(ciBuffer), commands);
}
		
void process_cli(void)
{
	int input = RETARGET_ReadChar();
	if(input != -1)
	{
		ciBuffer[ciPointer] = input;
		if(input == 0x0a) 
		{
			ciBuffer[ciPointer] = 0;
			CLIhandler((char*)ciBuffer, ciPointer + 1);
			ciPointer = 0;
		}
		ciPointer++;
		if (ciPointer == CLISIZE) ciPointer = 0;
	}
}

//void cli_setsyncwords(int argc, char **argv)
//{
//	common_setsyncwords(ciGetUnsigned(argv[1]), ciGetUnsigned(argv[2]), ciGetUnsigned(argv[3]), ciGetUnsigned(argv[4]));
//}

void CLIhandler(char* data_ptr, uint16_t data_len)
{
	uint8_t u8Data = 0xff;
	str_ptr = strstr((char*)data_ptr, "RESET");
	if(str_ptr != NULL)
	{
		common_reset();
		return;
	}
	
	str_ptr = strstr((char*)data_ptr, "INFO");
	if(str_ptr != NULL)
	{
		common_info();
		return;
	}
	
	str_ptr = strstr((char*)data_ptr, "GET_VERSION");
	if(str_ptr != NULL)
	{
		common_getver();
		return;
	}
	
	str_ptr = strstr((char*)data_ptr, "PRINT_MODE:");

	if(str_ptr != NULL)
	{
		str_ptr += strlen("PRINT_MODE:");
		uint16_t p = atoi(str_ptr);
		if(p > 1) p = 1;	
		common_printmode(p);		
		return;
	}

	//RF
	str_ptr = strstr((char*)data_ptr, "GET_FREQ");
	if(str_ptr != NULL)
	{
		common_getfreq();
		return;
	}
	
	str_ptr = strstr((char*)data_ptr, "SET_FREQ:");
	if(str_ptr != NULL)
	{
		str_ptr += strlen("SET_FREQ:");
		uint32_t freq = atoi(str_ptr); 
		str_ptr = strstr((char*)str_ptr, ":");
		if(str_ptr != NULL)
		{
			str_ptr += strlen(":");
			uint32_t step = atoi(str_ptr); 
			common_setfreq(freq, step);
		}
		else printf("SET_FREQ: ERROR\r\n");
		return;
	}	
	
	str_ptr = strstr((char*)data_ptr, "GET_IFFREQ");
	if(str_ptr != NULL)
	{
		common_getiffreq();
		return;
	}
	
	str_ptr = strstr((char*)data_ptr, "SET_IFFREQ:");
	if(str_ptr != NULL)
	{
		str_ptr += strlen("SET_IFFREQ:");
		uint32_t iffreq = atoi(str_ptr); 
		common_setiffreq(iffreq);
		return;
	}
	
	str_ptr = strstr((char*)data_ptr, "GET_BR");
	if(str_ptr != NULL)
	{
		common_getbaudrate();
		return;
	}
	
	str_ptr = strstr((char*)data_ptr, "SET_BR:");
	if(str_ptr != NULL)
	{
		str_ptr += strlen("SET_BR:");
		uint32_t br = atoi(str_ptr); 
		common_setbaudrate(br);
		return;
	}
	
	str_ptr = strstr((char*)data_ptr, "GET_DEV");
	if(str_ptr != NULL)
	{
		common_getdeviation();
		return;
	}
	
	str_ptr = strstr((char*)data_ptr, "SET_DEV:");
	if(str_ptr != NULL)
	{
		str_ptr += strlen("SET_DEV:");
		uint32_t d = atoi(str_ptr); 
		common_setdeviation(d);
		return;
	}
	
	str_ptr = strstr((char*)data_ptr, "GET_CHANNEL");
	if(str_ptr != NULL)
	{
		common_getchannel();
		return;
	}
	
	str_ptr = strstr((char*)data_ptr, "SET_CHANNEL:");
	if(str_ptr != NULL)
	{
		str_ptr += strlen("SET_CHANNEL:");
		uint8_t ch = atoi(str_ptr); 
		common_setchannel(ch);
		return;
	}
	
	str_ptr = strstr((char*)data_ptr, "GET_POWER");
	if(str_ptr != NULL)
	{
		common_getpower();
		return;
	}
	
	str_ptr = strstr((char*)data_ptr, "SET_POWER:");
	if(str_ptr != NULL)
	{
		str_ptr += strlen("SET_POWER:");
		int16_t p = atoi(str_ptr); 
		common_setpower(p);
		return;
	}
	
	str_ptr = strstr((char*)data_ptr, "GET_PWRLEVEL");
	if(str_ptr != NULL)
	{
		common_getpowerlevel();
		return;
	}
	
	str_ptr = strstr((char*)data_ptr, "SET_PWRLEVEL:");
	if(str_ptr != NULL)
	{
		str_ptr += strlen("SET_PWRLEVEL:");
		uint8_t p = atoi(str_ptr); 
		common_setpowerlevel(p);
		return;
	}
	
	str_ptr = strstr((char*)data_ptr, "GET_RSSI");
	if(str_ptr != NULL)
	{
		common_getrssi();
		return;
	}
	
	str_ptr = strstr((char*)data_ptr, "GET_RSOFFSET");
	if(str_ptr != NULL)
	{
		common_getrssioffset();
		return;
	}
	
	str_ptr = strstr((char*)data_ptr, "SET_RSOFFSET:");
	if(str_ptr != NULL)
	{
		str_ptr += strlen("SET_RSOFFSET:");
		int16_t p = atoi(str_ptr); 
		common_setrssioffset(p);
		return;
	}
	
	str_ptr = strstr((char*)data_ptr, "GET_FROFFSET");
	if(str_ptr != NULL)
	{
		common_getfreqoffset();
		return;
	}
	
	str_ptr = strstr((char*)data_ptr, "GET_RXBW");
	if(str_ptr != NULL)
	{
		common_getrxbw();
		return;
	}
	
	str_ptr = strstr((char*)data_ptr, "SET_RXBW:");
	if(str_ptr != NULL)
	{
		str_ptr += strlen("SET_RXBW:");
		uint32_t bw = atoi(str_ptr); 
		common_setrxbw(bw);
		return;
	}
	
	str_ptr = strstr((char*)data_ptr, "GET_CTUNE");
	if(str_ptr != NULL)
	{
		common_getctune();
		return;
	}
	
	str_ptr = strstr((char*)data_ptr, "SET_CTUNE:");
	if(str_ptr != NULL)
	{
		str_ptr += strlen("SET_CTUNE:");
		uint16_t ct = atoi(str_ptr); 
		common_setctune(ct);
		return;
	}
	
	str_ptr = strstr((char*)data_ptr, "STORE_CTUNE");
	if(str_ptr != NULL)
	{
		common_storectune();
		return;
	}
	
	str_ptr = strstr((char*)data_ptr, "GET_PACTUNE");
	if(str_ptr != NULL)
	{
		common_getpactune();
		return;
	}
	
	str_ptr = strstr((char*)data_ptr, "SET_PACTUNE:");
	if(str_ptr != NULL)
	{
		str_ptr += strlen("SET_PACTUNE:");
		uint8_t t = atoi(str_ptr); 
		str_ptr = strstr((char*)str_ptr, ":");
		if(str_ptr != NULL)
		{
			str_ptr += strlen(":");
			uint8_t r = atoi(str_ptr); 
			common_setpactune(t, r);
		}
		else printf("SET_PACTUNE: ERROR\r\n");
		return;
	}	
	
	str_ptr = strstr((char*)data_ptr, "STORE_PACTUNE");
	if(str_ptr != NULL)
	{
		common_storepactune();
		return;
	}
	
	str_ptr = strstr((char*)data_ptr, "STORE_CONFIG");
	if(str_ptr != NULL)
	{
		common_storeconfig();
		return;
	}
	
	str_ptr = strstr((char*)data_ptr, "SEND_PACKET:");

	if(str_ptr != NULL){
		str_ptr += strlen("SEND_PACKET:");
		uint32_t count = atoi(str_ptr); 
		str_ptr = strstr((char*)str_ptr, ":");
		if(str_ptr != NULL)
			{
				str_ptr += strlen(":");
				uint32_t interval = atoi(str_ptr); 
				str_ptr = strstr((char*)str_ptr, ":");
				if(str_ptr != NULL)
				{
					str_ptr += strlen(":");
					uint32_t id = atoi(str_ptr);
					common_sendburst(count, interval, id);
				}
				else printf("SEND_PACKET: ERROR\r\n");
			}
			else printf("SEND_PACKET:ERROR\r\n");
		return;
	}
	
	str_ptr = strstr((char*)data_ptr, "STOP_TX");
	if(str_ptr != NULL)
	{
		common_stopburst();
		return;
	}

	str_ptr = strstr((char*)data_ptr, "TX_STREAM:");
	if(str_ptr != NULL)
	{
		str_ptr += strlen("TX_STREAM:");
		uint8_t s = atoi(str_ptr); 
		common_txstream(s);
		return;
	}
	
	str_ptr = strstr((char*)data_ptr, "START_RXCOUNT");
	if(str_ptr != NULL)
	{
		common_startrxcount();
		return;
	}
	
	str_ptr = strstr((char*)data_ptr, "STOP_RXCOUNT");
	if(str_ptr != NULL)
	{
		common_stoprxcount();
		return;
	}
	
	str_ptr = strstr((char*)data_ptr, "GET_RXCOUNT");
	if(str_ptr != NULL)
	{
		common_getrxcount();
		return;
	}
	
	str_ptr = strstr((char*)data_ptr, "START_BER:");
	if(str_ptr != NULL)
	{
		str_ptr += strlen("START_BER:");
		uint32_t b = atoi(str_ptr); 
		common_startber(b);
		return;
	}
	
	str_ptr = strstr((char*)data_ptr, "STOP_BER");
	if(str_ptr != NULL)
	{
		common_stopber();
		return;
	}
	
	str_ptr = strstr((char*)data_ptr, "GET_BER");
	if(str_ptr != NULL)
	{
		common_getber();
		return;
	}
	
	str_ptr = strstr((char*)data_ptr, "GET_SYNC");
	if(str_ptr != NULL)
	{
		common_getsyncwords();
		return;
	}
	
	str_ptr = strstr((char*)data_ptr, "GET_VT");
	if(str_ptr != NULL)
	{
		printf("GET_VT: %.1f, %.1f, %.1f\r\n", Temp, Vcc, Dvdd);
		return;
	}
}


