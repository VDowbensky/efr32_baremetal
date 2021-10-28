#ifndef _APP_CLI_H_
#define _APP_CLI_H_

#include "retargetserial.h"
#include "command_interpreter.h"
#include "rail_rf_hal.h"

#define CLI_COMMAND_NOP           0
#define CLI_COMMAND_SENDBURST     1
#define CLI_COMMAND_STARTCW       2
#define CLI_COMMAND_STOPSTREAM    3
#define CLI_COMMAND_STARTPN9      4
#define CLI_COMMAND_START01       5
#define CLI_COMMAND_GETCTUNE      6
#define CLI_COMMAND_SETCTUNE      7
#define CLI_COMMAND_GETPACTUNE    8
#define CLI_COMMAND_SETPACTUNE    9
#define CLI_COMMAND_GETRSSI       10
#define CLI_COMMAND_GETCHANNEL    11
#define CLI_COMMAND_SETCHANNEL    12
#define CLI_COMMAND_GETPOWER      13
#define CLI_COMMAND_SETPOWER      14
#define CLI_COMMAND_MASTER        15
#define CLI_COMMAND_SLAVE         16
#define CLI_COMMAND_GETTEMP       17

#define CLI_COMMAND_GETVERSION    20
#define CLI_COMMAND_PRINTRX       21
#define CLI_COMMAND_STORECTUNE    22
#define CLI_COMMAND_STARTRXCOUNT  23
#define CLI_COMMAND_GETRXCOUNT    24
#define CLI_COMMAND_STOPRXCOUNT   25
#define CLI_COMMAND_GOTOSLEEP     26
#define CLI_COMMAND_STARTBER      27
#define CLI_COMMAND_GETBER        28
#define CLI_COMMAND_STOPBER       29

#define CLI_COMMAND_GETFREQOFFSET 34
#define CLI_COMMAND_CTUNEAUTOCAL  35

//almost for Golden Node
#define CLI_COMMAND_GETRSSIOFFSET 41
#define CLI_COMMAND_SETRSSIOFFSET 42
#define CLI_COMMAND_GETPWRLEVEL   43
#define CLI_COMMAND_SETPWRLEVEL   44

#define CLI_COMMAND_STOREPACTUNE  51


void cli_init(void);
void process_cli(void);
extern uint8_t printmode;

#endif
