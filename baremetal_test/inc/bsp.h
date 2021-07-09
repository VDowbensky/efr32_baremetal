#ifndef _BSP_H_
#define _BSP_H_

#include <stdint.h>
#include "mcu_memory.h"


#define HW_VERSION 2
#define SW_VERSION 3
#define SW_SUBVERSION 0

#define TX_PACTUNE 7
#define RX_PACTUNE 6
#define INITIAL_TX_POWER 10
#define RSSI_OFFSET -6

#define RAIL_FIFO_SIZE 32
static uint8_t tx_fifo[RAIL_FIFO_SIZE] = {0, 0, 0, 0, -120, 0, 'T', 0, 0, 0, 0, 0, 0, 0, 0,'B', 'a', 'r', 'e', ' ','M','e','t','a','l',' ',' '};//max length of string - 16 bytes


// USART0 TX on PD14
#define USART_TX_PORT           gpioPortD
#define USART_TX_PIN            14
#define USART_TX_LOC            22
// USART0 RX on PD13
#define USART_RX_PORT           gpioPortD
#define USART_RX_PIN            13
#define USART_RX_LOC            20

#define I2C I2C0
#define I2C_CLOCK 							cmuClock_I2C0
// I2C0 SCL on PF3
#define I2C_SCL_PORT                  gpioPortF
#define I2C_SCL_PIN                   3
#define I2C_SCL_LOC                   26
// I2C0 SDA on PD15
#define I2C_SDA_PORT                  gpioPortD
#define I2C_SDA_PIN                   15
#define I2C_SDA_LOC                   23

#define BTN0_PORT               gpioPortF
#define BTN0_PIN                2
#define BTN1_PORT               gpioPortF
#define BTN1_PIN                2

#define LED0		 								1
#define LED0_PORT               gpioPortB
#define LED0_PIN                15
#define LED_POLARITY						1



#endif //_BSP_H_
