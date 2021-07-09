#ifndef _LP5024_H_
#define _LP5024_H_

#include "em_cmu.h"
#include "sl_i2cspm.h"
#include "stdlib.h"
#include "stdio.h"
//#include "system.h"
#include "sl_i2cspm_instances.h"
#include "sl_i2cspm_inst_config.h"


//#define LP5024_ADDR      (0x28<<1)
//#define LP5024_ADDR      (0x29<<1)
//#define LP5024_ADDR      (0x2A<<1)
#define LP5024_ADDR      (0x2B<<1)
#define BUTTONS_ADDR     (0x0A<<1)
//registers definitions
#define DEVICE_CONFIG0    0x00
#define DEVICE_CONFIG1    0x01
#define LED_CONFIG0       0x02
#define BANK_BRIGHTNESS   0x03
#define BANK_A_COLOR      0x04
#define BANK_B_COLOR      0x05
#define BANK_C_COLOR      0x06
#define LED0_BRIGHTNESS   0x07
#define LED1_BRIGHTNESS   0x08
#define LED2_BRIGHTNESS   0x09
#define LED3_BRIGHTNESS   0x0A
#define LED4_BRIGHTNESS   0x0B
#define LED5_BRIGHTNESS   0x0C
#define LED6_BRIGHTNESS   0x0D
#define LED7_BRIGHTNESS   0x0E
#define OUT0_COLOR        0x0F
#define OUT1_COLOR        0x10
#define OUT2_COLOR        0x11
#define OUT3_COLOR        0x12
#define OUT4_COLOR        0x13
#define OUT5_COLOR        0x14
#define OUT6_COLOR        0x15
#define OUT7_COLOR        0x16
#define OUT8_COLOR        0x17
#define OUT9_COLOR        0x18
#define OUT10_COLOR       0x19
#define OUT11_COLOR       0x1A
#define OUT12_COLOR       0x1B
#define OUT13_COLOR       0x1C
#define OUT14_COLOR       0x1D
#define OUT15_COLOR       0x1E
#define OUT16_COLOR       0x1F
#define OUT17_COLOR       0x20
#define OUT18_COLOR       0x21
#define OUT19_COLOR       0x22
#define OUT20_COLOR       0x23
#define OUT21_COLOR       0x24
#define OUT22_COLOR       0x25
#define OUT23_COLOR       0x26
#define RESET_REG         0x27
//default values


//functions
//extern void i2c_init(void);
extern void dcdc_on(void);
extern void dcdc_off(void);
extern void lp5024_on(void);
extern void lp5024_off(void);
extern bool lp5024_init(void);
extern bool lp5024_data_buf(uint8_t *buf);
extern bool lp5024_set_color(uint8_t led, uint8_t color);//led[0..23] color[0..255]
extern bool lp5024_set_all(uint8_t color);//color[0..255]
extern bool lp5024_set_all2(uint8_t *buf);
extern bool lp5024_set_BRIGHTNESS(uint8_t value);

extern bool buttons_get(uint8_t *buf);
void cbGpioIrq(void);
extern uint8_t ledbuf[];
extern uint8_t btnbuf[];
#endif
