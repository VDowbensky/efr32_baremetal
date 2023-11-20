#ifndef _CLI_COMMON_PROTOTYPES_H_
#define _CLI_COMMON_PROTOTYPES_H_
//general
void cli_reset(int argc, char **argv);
void cli_info(int argc, char **argv);
void cli_getdevid(int argc, char **argv);
void cli_setdevid(int argc, char **argv);
void cli_printmode(int argc, char **argv);
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
void cli_calctune(int argc, char **argv);
void cli_storectune(int argc, char **argv);
void cli_getpactune(int argc, char **argv);
void cli_setpactune(int argc, char **argv);
void cli_storepactune(int argc, char **argv);
void cli_storeconfig(int argc, char **argv);
void cli_sendburst(int argc, char **argv);
void cli_stopburst (int argc, char **argv);
void cli_txstream(int argc, char **argv);
void cli_startrxcount(int argc, char **argv);
void cli_stoprxcount(int argc, char **argv);
void cli_getrxcount(int argc, char **argv);
void cli_startber(int argc, char **argv);
void cli_stopber(int argc, char **argv);
void cli_getber(int argc, char **argv);

#endif