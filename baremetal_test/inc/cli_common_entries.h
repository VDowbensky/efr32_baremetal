#ifndef _CLI_COMMON_ENTRIES_H_
#define _CLI_COMMON_ENTRIES_H_

#define COMMON_COMMAND_ENTRIES
			//general
			COMMAND_ENTRY("RESET", "", cli_reset, "Device reset"),\
			COMMAND_ENTRY("INFO", "", cli_info, "Get CPU ID"),\
			COMMAND_ENTRY("GET_DEVID", "", cli_getdevid, "Get serial number"),\
      COMMAND_ENTRY("SET_DEVID", "w", cli_setdevid, "Set serial number"),\
			COMMAND_ENTRY("PRINT_MODE", "v", cli_printmode, "On/off additional printing"),\
			COMMAND_ENTRY("GET_VERSION", "", cli_getver, "Get HW/FW version"),\
			//RF settings
			COMMAND_ENTRY("GET_FREQ", "", cli_getfreq, "Get RF frequency & channel spacing"),\
			COMMAND_ENTRY("SET_FREQ", "ww", cli_setfreq, "Set RF frequency & channel spacing"),\
			COMMAND_ENTRY("GET_IFFREQ", "", cli_getiffreq, "Get IF frequency"),\
			COMMAND_ENTRY("SET_IFFREQ", "w", cli_setiffreq, "Set IF frequency"),\
			COMMAND_ENTRY("GET_BR", "", cli_getbaudrate, "Get baud rate"),\
			COMMAND_ENTRY("SET_BR", "w", cli_setbaudrate, "Set baud rate"),\
			COMMAND_ENTRY("GET_DEV", "", cli_getdeviation, "Get freq. deviation"),\
			COMMAND_ENTRY("SET_DEV", "w", cli_setdeviation, "Set freq. deviation"),\
			COMMAND_ENTRY("GET_CHANNEL", "", cli_getchannel, "Get channel number"),\
			COMMAND_ENTRY("SET_CHANNEL", "v", cli_setchannel, "Set channel number"),\
			COMMAND_ENTRY("GET_POWER", "", cli_getpower, "Get TX power"),\
			COMMAND_ENTRY("SET_POWER", "s", cli_setpower, "Set TX power"),\
			COMMAND_ENTRY("GET_POWERLEVEL", "", cli_getpowerlevel, "Get TX power DAC"),\
			COMMAND_ENTRY("SET_POWERLEVEL", "v", cli_setpowerlevel, "Set TX power DAC"),\
			COMMAND_ENTRY("GET_RSSI", "", cli_getrssi, "Get RSSI value"),\
			COMMAND_ENTRY("GET_RSSIOFFSET", "", cli_getrssioffset, "Get RSSI offset in dBm"),\
			COMMAND_ENTRY("SET_RSSIOFFSET", "s", cli_getrssioffset, "Set RSSI offset in dBm"),\
			COMMAND_ENTRY("GET_FREQOFFSET", "", cli_getfreqoffset, "Get frequency error"),\
			COMMAND_ENTRY("GET_RXBW", "", cli_getrxbw, "Get RX Bandwidth"),\
			COMMAND_ENTRY("SET_RXBW", "w", cli_setrxbw, "Set RX Bandwidth"),\
			COMMAND_ENTRY("GET_SYNC", "", cli_getsyncwords, "Get Syncwords"),\
			COMMAND_ENTRY("SET_SYNC", "wwww", cli_setsyncwords, "Set Syncwords"),\	
			COMMAND_ENTRY("GET_CTUNE", "", cli_getctune, "Get Ctune value"),\
			COMMAND_ENTRY("SET_CTUNE", "v", cli_setctune, "Set Ctune value"),\
			COMMAND_ENTRY("CAL_CTUNE", "", cli_calctune, "Ctune calibration"),\
			COMMAND_ENTRY("STORE_CTUNE", "", cli_storectune, "Store Ctune value"),\
			COMMAND_ENTRY("GET_PACTUNE", "", cli_getpactune, "Get PACtune value"),\
			COMMAND_ENTRY("SET_PACTUNE", "vv", cli_setpactune, "Set PACtune value"),\
			COMMAND_ENTRY("STORE_PACTUNE", "", cli_storepactune, "Store PACtune value"),\
			COMMAND_ENTRY("STORE_CONFIG", "", cli_storeconfig, "Store PACtune value"),\
			//RF tests			
			COMMAND_ENTRY("SEND_PACKET", "www", cli_sendburst, "Start packet burst"),\
			COMMAND_ENTRY("STOP_TX", "", cli_stopburst, "Stop packet burst"),\
			COMMAND_ENTRY("TX_STREAM", "v", cli_txstream, "Start/stop TX stream"),\
			COMMAND_ENTRY("START_RXCOUNT", "", cli_startrxcount, "Start RX packet count"),\
			COMMAND_ENTRY("STOP_RXCOUNT", "", cli_stoprxcount, "Stop RX packet count"),\
			COMMAND_ENTRY("GET_RXCOUNT", "", cli_getrxcount, "Get RX packet count"),\
			COMMAND_ENTRY("START_BER", "w", cli_startber, "Start BER test"),\
			COMMAND_ENTRY("STOP_BER", "", cli_stopber, "Stop BER test"),\
			COMMAND_ENTRY("GET_BER", "", cli_getber, "Get BER info")
			
#endif