#ifndef _CLI_COMMON_H_
#define _CLI_COMMON_H_

#include "bsp.h"
#include "radio_proc.h"

void common_reset(void);
void common_info(void);
void common_getdevid(void);
void common_setdevid(uint32_t id);
void common_printmode(uint8_t mode);
void common_answermode(uint8_t mode);
void common_getver(void);
void common_getfreq(void);
void common_setfreq(uint32_t f, uint32_t s);
void common_getiffreq(void);
void common_setiffreq(int32_t iffreq);
void common_getbaudrate(void);
void common_setbaudrate(uint32_t br);
void common_getdeviation(void);
void common_setdeviation(uint32_t d);
void common_getchannel(void);
void common_setchannel(uint16_t ch);
void common_storechannel(void);
void common_getpower(void);
void common_setpower(int32_t p);
void common_getpowerlevel(void);
void common_setpowerlevel(uint32_t p);
void common_getfreqoffset(void);
void common_getrxbw(void);
void common_setrxbw(uint32_t bw);
void common_getsyncwords(void);
void common_setsyncwords(uint32_t s0, uint32_t s1, uint32_t len, uint32_t skip);
void common_getctune(void);
void common_setctune(uint32_t t);
void common_calctune(void);
void common_storectune(void);
void common_getpactune(void);
void common_setpactune(uint8_t txpactune, uint8_t rxpactune);
void common_storepactune(void);
void common_storeconfig(void);
void common_initconfig(void);
void common_sendburst(uint32_t cnt, uint32_t del, uint32_t id);
void common_stopburst (void);
void common_txstream(uint32_t s);
void common_getrssi(void);
void common_getrssioffset(void);
void common_setrssioffset(int32_t offset);
void common_startrxcount(void);
void common_stoprxcount(void);
void common_getrxcount(void);
void common_startber(uint32_t bytes);
void common_stopber(void);
void common_getber(void);

#endif
