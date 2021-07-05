#include <stdio.h>
#include "app_cli.h"
#include "em_system.h"
#include "bsp.h"
#include "adc.h"
#include "tempdrv.h"
#include "leds.h"
#include "radio_proc.h"
//#include "command_interpreter.h"
#if XSHIFT
#include "si7210.h"
#endif
#if (XMOTION || XPAD)
#include "sfh7771.h"
#endif
#if MX
#include "spi_ram.h"
#endif
#if GN
#include "atten.h"
#endif

CommandState_t state;
char ciBuffer[256];

//cli functions prototypes

void cli_reset(int argc, char **argv);
void cli_info(int argc, char **argv);
void cli_getdevid(int argc, char **argv);
void cli_setdevid(int argc, char **argv);
void cli_printmode(int argc, char **argv);
void cli_getver(int argc, char **argv);

void cli_getchannel(int argc, char **argv);
void cli_setchannel(int argc, char **argv);
void cli_getpower(int argc, char **argv);
void cli_setpower(int argc, char **argv);
void cli_getpowerlevel(int argc, char **argv);
void cli_setpowerlevel(int argc, char **argv);
void cli_setrflevel(int argc, char **argv);
void cli_getrssi(int argc, char **argv);
void cli_getrssioffset(int argc, char **argv);
void cli_setrssioffset(int argc, char **argv);
void cli_getfreqoffset(int argc, char **argv);
void cli_getatten(int argc, char **argv);
void cli_setatten(int argc, char **argv);
void cli_getextatten(int argc, char **argv);
void cli_setextatten(int argc, char **argv);

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
void cli_ledtest(int argc, char **argv);
void cli_piren(int argc, char **argv);
void cli_startpir(int argc, char **argv);
void cli_getpir(int argc, char **argv);

void cli_getlight(int argc, char **argv);
void cli_setbright(int argc, char **argv);
void cli_getkey(int argc, char **argv);
void cli_beep(int argc, char **argv);
void cli_readram(int argc, char **argv);
void cli_writeram(int argc, char **argv);
void cli_ramtest(int argc, char **argv);
void cli_read7210(int argc, char **argv);

void print_light_data(void);
    
		
    CommandEntry_t commands[] = 
		{
			//general
			COMMAND_ENTRY("RESET", "", cli_reset, "Device reset"),
			COMMAND_ENTRY("INFO", "", cli_info, "Get CPU ID"),
			COMMAND_ENTRY("GET_DEVID", "", cli_getdevid, "Get device ID"),
			COMMAND_ENTRY("SET_DEVID", "w", cli_setdevid, "Get device ID"),
			COMMAND_ENTRY("PRINT_MODE", "v", cli_printmode, "On/off additional printing"),
			COMMAND_ENTRY("GET_VERSION", "", cli_getver, "Get HW/FW version"),
			//RF settings
			COMMAND_ENTRY("GET_CHANNEL", "", cli_getchannel, "Get channel number"),
			COMMAND_ENTRY("SET_CHANNEL", "v", cli_setchannel, "Set channel number"),
			COMMAND_ENTRY("GET_POWER", "", cli_getpower, "Get TX power"),
			COMMAND_ENTRY("SET_POWER", "s", cli_setpower, "Set TX power"),
			COMMAND_ENTRY("GET_POWERLEVEL", "", cli_getpowerlevel, "Get TX power DAC"),
			COMMAND_ENTRY("SET_POWERLEVEL", "v", cli_setpowerlevel, "Set TX power DAC"),
			COMMAND_ENTRY("SET_RFLEVEL", "s", cli_setrflevel, "Set RF level, dBm"),	
			COMMAND_ENTRY("GET_RSSI", "", cli_getrssi, "Get RSSI value"),
			COMMAND_ENTRY("GET_RSSIOFFSET", "", cli_getrssioffset, "Get power meter offset"),
			COMMAND_ENTRY("SET_RSSIOFFSET", "v", cli_setrssioffset, "Set power meter offset"),
			COMMAND_ENTRY("GET_FREQOFFSET", "", cli_getfreqoffset, "Get frequency error"),
			COMMAND_ENTRY("GET_ATT", "", cli_getatten, "Get main att. value"),
			COMMAND_ENTRY("SET_ATT", "v", cli_setatten, "Set main att. value"),
			COMMAND_ENTRY("GET_EXTATT", "", cli_getextatten, "Get aux att. value"),
			COMMAND_ENTRY("SET_EXTATT", "v", cli_setextatten, "Set aux att. value"),
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
			//LED's
			COMMAND_ENTRY("LED_TEST", "vv", cli_ledtest, "LED's test"),
			//PIR
			COMMAND_ENTRY("PIR_EN", "v", cli_piren, "PIR sensor on/off"),
			COMMAND_ENTRY("START_PIR", "v", cli_startpir, "Start PIR measuring"),
			COMMAND_ENTRY("GET_PIR", "", cli_getpir, "Get PIR data"),
			//PIR & KB
			COMMAND_ENTRY("GET_LIGHT", "", cli_getlight, "Read light sensor"),
			//KB
			COMMAND_ENTRY("SET_BRIGHT", "v", cli_setbright, "Set LED bright"),
			COMMAND_ENTRY("GET_KEY", "", cli_getkey, "Get key code"),
			COMMAND_ENTRY("BEEP", "v", cli_beep, "Buzzer sound test"),
			COMMAND_ENTRY("READ_RAM", "v", cli_readram, "SPI RAM read"),
			COMMAND_ENTRY("WRITE_RAM", "vu", cli_writeram, "SPI RAM write"),
			COMMAND_ENTRY("TEST_RAM", "u", cli_ramtest, "SPI RAM fast test"),
			//Hall sensor
			COMMAND_ENTRY("GET_FIELD", "", cli_read7210, "Get magnetic field value"),
			
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

void cli_getdevid(int argc, char **argv)
{
	uint32_t n;
  n = ((*(uint32_t *) DEVID_ADDR) & 0xFFFF0000) >> 16;
  n += ((*(uint32_t *) (DEVID_ADDR+0x4)) << 16 ) & 0xFFFF0000;
  printf("GET_DEVID: 0x%X\r\n", n);
}

void cli_setdevid(int argc, char **argv)
{
	uint32_t v;
	printf("SET_DEVID: Not implemented\r\n");
	//v = 
	//storedevid(v);
  //printf("SET_DEVID: OK\r\n");
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

void cli_setrflevel(int argc, char **argv)
{
	int32_t p;
	printf("SET_RFLEVEL: Under development\r\n");
	p = ciGetSigned(argv[1]);
	if(p > -40) p = -40;
	if(p < -200) p = -200;
	printf("SET_RFLEVEL: %d\r\n", p);
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

void cli_getatten(int argc, char **argv)
{
#if(GN)
      printf("GET_ATT: %2.1f dB\r\n", i_att);
#else
	printf("GET_ATT: ERROR\r\n");
	if(printmode) printf("Command not allowed.\r\n");
#endif
}

void cli_setatten(int argc, char **argv)
{
#if GN
	uint32_t a;
	a = ciGetUnsigned(argv[1]);
	if(a > 63) a = 63;
	i_att = ((float)a)/2;
	setattenuation(a);
	printf("SET_ATT: %.2f dB\r\n", i_att);
#else
	printf("SET_ATT: ERROR\r\n");
	if(printmode) printf("Command not allowed.\r\n");	
#endif
}

void cli_getextatten(int argc, char **argv)
{
#if(GN)
      printf("GET_EXTATT: %2.1f dB\r\n", i_extatt);
#else
	printf("GET_EXTATT: ERROR\r\n");
	if(printmode) printf("Command not allowed.\r\n");
#endif
}

void cli_setextatten(int argc, char **argv)
{
#if GN
	uint32_t a;
	a = ciGetUnsigned(argv[1]);
	if(a > 63) a = 63;
	i_extatt = ((float)a)/2;
	setattenuation(a);
	printf("SET_EXTATT: %.2f dB\r\n", i_extatt);
#else
	printf("SET_EXTATT: ERROR\r\n");
	if(printmode) printf("Command not allowed.\r\n");	
#endif
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
	printf("STORE_CTUNE: Not implemented\r\n");
}

void cli_getpactune(int argc, char **argv)
{
	printf("GET_PACTUNE: Under development\r\n");
	printf("GET_PACTUNE: 0,0\r\n");
}

void cli_setpactune(int argc, char **argv)
{
	uint32_t t, r;
	printf("SET_PACTUNE: Under development\r\n");
	t = ciGetUnsigned(argv[1]);
	if(t > 31) t = 31;
	r = ciGetUnsigned(argv[2]);
	if(r > 31) r = 31;
	PA_CTuneSet(t, r);
	printf("SET_PACTUNE: %d,%d\r\n", t, r);
}

void cli_storepactune(int argc, char **argv)
{
	printf("STORE_PACTUNE: Not implemented\r\n");
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

void cli_ledtest(int argc, char **argv)
{
			uint8_t p16;
			uint8_t p32;
			p16 = ciGetUnsigned(argv[1]);
			p32 = ciGetUnsigned(argv[2]);
#if XPAD
      //LED number in p16, value in p32

      if(p16 > 23) p16 = 23;
      if(p32 > 255) p16 = 255;
      //load LP5024
      ledbuf[p16] = p32;
      lp5024_set_all(0);
      lp5024_on();
      lp5024_set_all2(ledbuf);
      printf("LED_TEST: %d, %d\r\n", p16, p32);
      break;
#elif (XMOTION || XSHIFT)
      if(p16==0)
        {
          if (p32 != 0)
            {
              led0_on();
              printf("LED_TEST: 0, 1\r\n");
            }
          else
            {
              led0_off();
              printf("LED_TEST: 0, 0\r\n");
            }
        }
      else
        {
          printf("LED_TEST: ERROR\r\n");
          if(printmode) printf("Wrong LED number.\r\n");
        }


#elif XKEY
      if(p16 < 2)
        {
          if (p32 != 0)
            {
              if(p16 == 0) led0_on(); //sl_led_turn_on(&sl_led_led0);
              else led1_on();//sl_led_turn_on(&sl_led_led1);
              printf("LED_TEST: %d, 1\r\n", p16);
            }
          else
            {
              if(p16 == 0) led0_off(); //sl_led_turn_on(&sl_led_led0);
              else led1_off();//sl_led_turn_on(&sl_led_led1);
              printf("LED_TEST: %d, 0\r\n", p16);
            }
        }
      else
        {
          printf("LED_TEST: ERROR\r\n");
          if(printmode) printf("Wrong LED number.\r\n");
        }

#else	
	printf("LED_TEST: ERROR\r\n");
	if(printmode) printf("Command not allowed.\r\n");
#endif
}

void cli_piren(int argc, char **argv)
{
#if (XMOTION)	      
	uint8_t t;
	t = ciGetUnsigned(argv[1]);			
	if(t != 0)
        {
          CMU_ClockEnable(cmuClock_I2C0, true);
          //enable I2C lines
          GPIO_PinModeSet(I2C_SCL_PORT, I2C_SCL_PIN, gpioModeWiredAndAlternate, 1);
          GPIO_PinModeSet(I2C_SDA_PORT, I2C_SDA_PIN, gpioModeWiredAndAlternate, 1);
          //gpioModeWiredAndPullUp
          GPIO_PinModeSet(PIREN_PORT, PIREN_PIN, gpioModePushPull, 0);
          init_i2c();
          sfh7771_SensorStart();
          piron = true;
          //dummy read
          printf("PIR_EN: ON\r\n");
          if(printmode) printf("AVDD on.\r\n");
        }
      else
        {

              GPIO_PinModeSet(PIREN_PORT, PIREN_PIN, gpioModePushPull, 1);
              //disable i2c
              CMU_ClockEnable(cmuClock_I2C0, false);
              GPIO_PinModeSet(I2C_SCL_PORT, I2C_SCL_PIN, gpioModeDisabled, 0);
              GPIO_PinModeSet(I2C_SDA_PORT, I2C_SDA_PIN, gpioModeDisabled, 0);
              piron = false;
              printf("PIR_EN: OFF\r\n");
              if(printmode) printf("AVDD off.\r\n");

        }
#else
				printf("PIR_EN: ERROR\r\n");
				printf("Command not allowed.\r\n");
#endif
}

void cli_startpir(int argc, char **argv)
{
#if XMOTION
   
    uint16_t p;    
		uint32_t i;
		p = ciGetUnsigned(argv[1]);
        if(piron == true)
          {
            if (p > ADCBUFFERSIZE)
          {
            p = ADCBUFFERSIZE;
            if(printmode) printf("Warning. Too big number. %d is set.\r\n", ADCBUFFERSIZE);
          }
        PIRcount = p;
        //clear buffer
        for(i = 0; i < ADCBUFFERSIZE; i++) adcbuffer[i] = 0;
        printf("START_PIR: %d\r\n", PIRcount);
					if(printmode) printf("Start PIR measuring.\r\n");
        PIR_on = true;
          }
        else
          {
            printf("START_PIR: ERROR\r\n");
            if(printmode) printf("Sensor is off.\r\n");
          }
#else
	printf("START_PIR: ERROR\r\n");
	if (printmode) printf("Command not allowed.\r\n");
#endif
}

void cli_getpir(int argc, char **argv)
{
#if XMOTION
	     {
        uint32_t i;
        int32_t accplus;
        int32_t accminus;
        uint32_t cp, cm;
        int32_t s;
        //APP_INFO("Warning. Command in development.\r\n");
        accplus = 0;
        accminus = 0;
        cp = 0;
        cm = 0;
        for(i = 0; i < PIRcount; i++)
          {
            s = adcbuffer[i];
            if(s < PIR_N_TRESHOLD)
              {
                accminus = accminus + s;
                cm++;
//#if PIR_DEBUG
//                printf("%d, %d, %d, %d, %d, %d\r\n", i, s, accplus, cp, accminus, cm);
//#endif
              }
            else if (s > PIR_P_TRESHOLD)
              {
                accplus = accplus + s;
                cp++;
//#if PIR_DEBUG
//                printf("%d, %d, %d, %d, %d, %d\r\n", i, s, accplus, cp, accminus, cm);
//#endif
              }
            else {}
          }

        //accplus =accplus*cp/PIRcount;
        //accminus = accminus*cm/PIRcount;

        printf("GET_PIR: %d, %d, %d, %d\r\n", accplus, cp, accminus, cm);

        if (printmode)
          {
        printf("RAW PIR DATA:\r\n");
        for (i = 0; i < (PIRcount); i++) printf("%d\r\n", (adcbuffer[i]));

        //optional graphics
            printf("Graph.\r\n");
            for (i = 0; i < (PIRcount); i++)
          {
            uint32_t j, l;
            l = (adcbuffer[i] + 2048)/64;
            for(j = 0; j < l; j++) printf("@");
            printf("\r\n");
          }
          }
        ;
      }
#else
	printf("GET_PIR: ERROR\r\n");
	if (printmode) printf("Command not allowed.\r\n");		
#endif
}


void cli_getlight(int argc, char **argv)
{
#if (XMOTION || XPAD)
	      if(piron == true)
        {
      //APP_INFO("Warning. Command in development.\r\n");
          print_light_data();
      //start new measuring
          sfh7771_SensorStart();
        }
      else
        {
          printf("GET_LIGHT: ERROR\r\n");
          if (printmode) printf("Sensor is off.\r\n");
        }
#else	
	printf("GET_LIGHT: ERROR\r\n");
	if (printmode) printf("Command not allowed.\r\n");
#endif
}

void cli_setbright(int argc, char **argv)
{
#if XPAD
	uint8_t b;
  lp5024_set_BRIGHTNESS(b);
  APP_INFO("SET_BRIGHT: %d\r\n", b);
#else	
	printf("SET_BRIGHT: ERROR\r\n");
	if (printmode) printf("Command not allowed.\r\n");
#endif
}	

void cli_getkey(int argc, char **argv)
{
#if XPAD
	printf("GET_KEY: 0x%X",btnbuf[0]);
#else
	printf("GET_KEY: ERROR\r\n");
	if (printmode) printf("Command not allowed.\r\n");
#endif
}

void cli_beep(int argc, char **argv)
{
#if XPAD
	      beepduration = p16*LETIMERDESIRED/1000;
      if(beepduration > 0)
        {
          buzzer_on();
          APP_INFO("BEEP: %d\r\n", p16);
          break;
        }
      else
        {
          buzzer_off();
          APP_INFO("BEEP: OFF\r\n");
          break;
        }
#else
	printf("BEEP: ERROR\r\n");
	if (printmode) printf("Command not allowed.\r\n");
#endif
}

void cli_readram(int argc, char **argv)
{
#if MX
      uint16_t t;
			t = ciGetUnsigned(argv[1]);		
      if(t > MAX_RAM_ADDR)
        {
          printf("READ_RAM: ERROR\r\n");
          if(printmode) printf("Address out of range.\r\n");
        }
      else
        {
          printf("READ_RAM: ADDR=0x%X, DATA=0x%X\r\n", t, spiram_readbyte(t));
        }
#else
	printf("READ_RAM: ERROR\r\n");
	if (printmode) printf("Command not allowed.\r\n");
#endif
}

void cli_writeram(int argc, char **argv)
{
#if MX
      uint16_t a;
			uint8_t v;
      if(a > MAX_RAM_ADDR)
        {
          printf("WRITE_RAM: ERROR\r\n");
          if(printmode) printf("Address out of range.\r\n");
        }
      else
        {
          spiram_writebyte(a, v);
          printf("WRITE_RAM: OK\r\n");
          if(printmode) printf("ADDR=0x%X, DATA=0x%X\r\n", a, v);
        }
#else
	printf("WRITE_RAM: ERROR\r\n");
	if (printmode) printf("Command not allowed.\r\n");
#endif
}

void cli_ramtest(int argc, char **argv)
{
		          //execute full RAM test, data byte in p16
#if MX
	uint8_t t;
  t = ciGetUnsigned(argv[1]);      
	if (testram (t) == true)
            {
              printf("TEST_RAM: OK\r\n");
              if(printmode) printf("RAM test passed, value=0x%X\r\n",t);
            }
        else
          {
            printf("TEST_RAM: ERROR. ADDR=0x%X, WRITE:0x%X, READ:0x%X\r\n",ramtest_addr,  t, ramtest_val);
            if(printmode) printf("RAM test failed, value=0x%X\r\n",t);
          }
#else					
	printf("TEST_RAM: ERROR\r\n");
	if (printmode) printf("Command not allowed.\r\n");
#endif
}

void cli_read7210(int argc, char **argv)
{
#if XSHIFT
	ReadField();
  printf("GET_FIELD: %.4f mT\r\n", FieldValue);
#else
	printf("READ_FIELD: ERROR\r\n");
	if (printmode) printf("Command not allowed.\r\n");
#endif
}
#if (XMOTION || XPAD)
void print_light_data(void)
{
     uint8_t buf[10];
     uint32_t vis, ir;
  if (sfh7771_Standby())
    {


    if (sfh7771_Data_2(buf) == true)
    {
      vis = (buf[3]<<8) + buf[2];
      ir = (buf[5]<<8) + buf[4];
      printf("GET_LIGHT: VIS: %d, IR: %d\r\n", vis, ir);

    }
    else
      {
        printf("GET_LIGHT: ERROR\r\n");
        if(printmode) printf("Light sensor fail.\r\n");
      }

   }

  else
    {
      printf("GET_LIGHT: ERROR\r\n");
      if(printmode) printf("Light sensor fail.\r\n");
    }
}

#endif