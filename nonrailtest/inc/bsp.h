#ifndef _BSP_H_
#define _BSP_H_

#include <stdint.h>
#include "mcu_memory.h"



#define SW_VERSION 3
#define SW_SUBVERSION 0

#define XMOTION 1
//#define XSHIFT 1
//#define XKEY 1
//#define MX 1
//#define GN 1
//#define XPAD 1
//#define XPAD_OLD_VERSION 1

//device specific settings
#if XMOTION
#define HW_VERSION 2
#define TX_PACTUNE 7
#define RX_PACTUNE 6
#define INITIAL_TX_POWER 10
#define RSSI_OFFSET -6
#define DEVICE_STRING_NAME "X-MOTION"
//static uint8_t tx_fifo[RAIL_FIFO_SIZE] = {0, 0, 0, 0, -120, 0, 'T', 0, 0, 0, 0, 0, 0, 0, 0,'P', 'I', 'R', '_', 'S','e','n','s','o','r',' ',' '};//max length of string - 16 bytes
#define PIREN_PORT (gpioPortB)
#define PIREN_PIN (14U)
#define PIRINT_PORT gpioPortC
#define PIRINT_PIN 10

#define HW_VERSION 2
#define TX_PACTUNE 7
#define RX_PACTUNE 6
#define INITIAL_TX_POWER 10
#define RSSI_OFFSET -6

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

#elif XSHIFT
#define HW_VERSION 2
#define TX_PACTUNE 1
#define RX_PACTUNE 5
#define INITIAL_TX_POWER 10
#define RSSI_OFFSET -6
#define DEVICE_STRING_NAME "X-SHIFT"
//static uint8_t tx_fifo[RAIL_FIFO_SIZE] = {0, 0, 0, 0, -120, 0, 'T', 0, 0, 0, 0, 0, 0, 0, 0,'X', '-', 'S', 'h', 'i','f','t',' ',' ',' ',' ',' '};//max length of string - 16 bytes

// USART0 TX on PA0
#define USART_TX_PORT           gpioPortA
#define USART_TX_PIN            0
#define USART_TX_LOC            0

// USART0 RX on PA1
#define USART_RX_PORT           gpioPortA
#define USART_RX_PIN            1
#define USART_RX_LOC            0

#define I2C I2C0
#define I2C_CLOCK 				cmuClock_I2C0
// I2C0 SCL on PB12
#define I2C_SCL_PORT                  gpioPortB
#define I2C_SCL_PIN                   12
#define I2C_SCL_LOC                   6//
// I2C0 SDA on PB11
#define I2C_SDA_PORT                  gpioPortB
#define I2C_SDA_PIN                   11
#define I2C_SDA_LOC                   6//

#define SI7210_ALERT_PORT				gpioPortF
#define SI7210_ALERT_PIN				2

#define BTN0_PORT               gpioPortB
#define BTN0_PIN                13
#define BTN1_PORT               gpioPortC
#define BTN1_PIN                10

//#define BTN2_PORT               gpioPortD
//#define BTN2_PIN                14
//#define BTN3_PORT               gpioPortF
//#define BTN3_PIN                2
#define LED0		 								1
#define LED0_PORT               gpioPortD
#define LED0_PIN                13
#define LED_POLARITY						0


#elif XKEY
#define HW_VERSION 2
#define TX_PACTUNE 1
#define RX_PACTUNE 5
#define INITIAL_TX_POWER 10
#define RSSI_OFFSET -6
#define DEVICE_STRING_NAME "X-KEY"
//static uint8_t tx_fifo[RAIL_FIFO_SIZE] = {0, 0, 0, 0, -120, 0, 'T', 0, 0, 0, 0, 0, 0, 0, 0,'X', '-', 'S', 'h', 'i','f','t',' ',' ',' ',' ',' '};//max length of string - 16 bytes

// USART0 TX on PA0
#define USART_TX_PORT           gpioPortA
#define USART_TX_PIN            0
#define USART_TX_LOC            0

// USART0 RX on PA1
#define USART_RX_PORT           gpioPortA
#define USART_RX_PIN            1
#define USART_RX_LOC            0

#define BTN0_PORT               gpioPortB
#define BTN0_PIN                13
#define BTN1_PORT               gpioPortC
#define BTN1_PIN                10

#define BTN2_PORT               gpioPortD
#define BTN2_PIN                14
#define BTN3_PORT               gpioPortF
#define BTN3_PIN                2

#define LED0		 								1
#define LED1		 								1
#define LED_POLARITY						1
#define LED0_PORT               gpioPortB
#define LED0_PIN                11
#define LED1_PORT               gpioPortB
#define LED1_PIN                12

#elif MX
#define HW_VERSION 2
#define TX_PACTUNE 1
#define RX_PACTUNE 5
#define INITIAL_TX_POWER 10
#define RSSI_OFFSET -6
#define DEVICE_STRING_NAME "M-X"
//static uint8_t tx_fifo[RAIL_FIFO_SIZE] = {0, 0, 0, 0, -120, 0, 'T', 0, 0, 0, 0, 0, 0, 0, 0,'X', '-', 'S', 'h', 'i','f','t',' ',' ',' ',' ',' '};//max length of string - 16 bytes

// USART0 TX on PA0
#define USART_TX_PORT           gpioPortA
#define USART_TX_PIN            0
#define USART_TX_LOC            0

// USART0 RX on PA1
#define USART_RX_PORT           gpioPortA
#define USART_RX_PIN            1
#define USART_RX_LOC            0

//SPI
#define SPI_USART USART1
#define SPI_CLOCK cmuClock_USART1
#define SPI_BAUDRATE 9600000
#define SCK_PORT    (gpioPortB)
#define SCK_PIN     (14U)
#define MOSI_PORT   (gpioPortB)
#define MOSI_PIN    (15U)
#define MISO_PORT   (gpioPortB)
#define MISO_PIN    (13U)
#define CS_PORT     (gpioPortB)
#define CS_PIN      (12U)

#define SCK_LOC USART_ROUTELOC0_CLKLOC_LOC20 //PD14
#define CS_LOC USART_ROUTELOC0_CSLOC_LOC20 //PD15 - not used
#define MOSI_LOC USART_ROUTELOC0_TXLOC_LOC21 //PD13
#define MISO_LOC USART_ROUTELOC0_RXLOC_LOC25 //PF2 - not used

#elif XPAD
#define HW_VERSION 2
#define TX_PACTUNE 1
#define RX_PACTUNE 5
#define INITIAL_TX_POWER 10
#define RSSI_OFFSET -6
#define DEVICE_STRING_NAME "X-PAD"
//static uint8_t tx_fifo[RAIL_FIFO_SIZE] = {0, 0, 0, 0, -120, 0, 'T', 0, 0, 0, 0, 0, 0, 0, 0,'X', '-', 'S', 'h', 'i','f','t',' ',' ',' ',' ',' '};//max length of string - 16 bytes

// USART0 TX on PA0
#define USART_TX_PORT           gpioPortA
#define USART_TX_PIN            0
#define USART_TX_LOC            0

// USART0 RX on PA1
#define USART_RX_PORT           gpioPortA
#define USART_RX_PIN            1
#define USART_RX_LOC            0


#define I2C I2C0
#define I2C_CLOCK 				cmuClock_I2C0
// I2C0 SCL on PB12
#define I2C_SCL_PORT                  gpioPortB
#define I2C_SCL_PIN                   12
#define I2C_SCL_LOC                   6//
// I2C0 SDA on PB11
#define I2C_SDA_PORT                  gpioPortB
#define I2C_SDA_PIN                   11
#define I2C_SDA_LOC                   6//



#elif GN
#define HW_VERSION 2
#define TX_PACTUNE 1
#define RX_PACTUNE 5
#define INITIAL_TX_POWER 10
#define RSSI_OFFSET -6
#define DEVICE_STRING_NAME "GOLDEN NODE"
//static uint8_t tx_fifo[RAIL_FIFO_SIZE] = {0, 0, 0, 0, -120, 0, 'T', 0, 0, 0, 0, 0, 0, 0, 0,'X', '-', 'S', 'h', 'i','f','t',' ',' ',' ',' ',' '};//max length of string - 16 bytes

// USART0 TX on PA0
#define USART_TX_PORT           gpioPortA
#define USART_TX_PIN            0
#define USART_TX_LOC            0

// USART0 RX on PA1
#define USART_RX_PORT           gpioPortA
#define USART_RX_PIN            1
#define USART_RX_LOC            0

//SPI
#define SPI_USART USART1
#define SPI_CLOCK cmuClock_USART1
#define SPI_BAUDRATE 1000000 //for attenuators
#define SCK_PORT    (gpioPortB)
#define SCK_PIN     (14U)
#define MOSI_PORT   (gpioPortB)
#define MOSI_PIN    (15U)
#define CS_PORT     (gpioPortB)
#define CS_PIN      (12U)

#define EXT_SCK_PORT    (gpioPortB)
#define EXT_SCK_PIN     (14U)
#define EXT_MOSI_PORT   (gpioPortB)
#define EXT_MOSI_PIN    (15U)
#define EXT_CS_PORT     (gpioPortB)
#define EXT_CS_PIN      (12U)

#define SCK_LOC USART_ROUTELOC0_CLKLOC_LOC20 //PD14
#define MOSI_LOC USART_ROUTELOC0_TXLOC_LOC21 //PD13
#define EXT_SCK_LOC USART_ROUTELOC0_CLKLOC_LOC5 //PB12
#define EXT_MOSI_LOC USART_ROUTELOC0_TXLOC_LOC8 //PB13

#else

#endif


#endif //_BSP_H_
