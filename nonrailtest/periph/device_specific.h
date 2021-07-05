#ifndef _DEV_SPEC_
#define _DEV_SPEC_

#include <stdint.h>

//#define HW_VERSION 2
#define SW_VERSION 2
#define SW_SUBVERSION 20

#define DEFAULT_CAL_TEMP 25

//#define RANGE_TEST 1
#define RANGE_TEST 0
//#define INITIAL_TX_POWER 10
#define LISTER 0
#define SENDTEMP 1

#define RSSITR -70

//RFRAM variables
//Attention!!! Here is some hack; addresses may be different for different RAIL versions!
#define TXPACTUNE_ADDR 0x21000FE8
#define RXPACTUNE_ADDR 0x21000FE4
//DevID manufacturing token (read-only in this project)
#define DEVID_ADDR 0x0FE00000 //0x0FE00002


//#define PIRSENSOR 1
//#define HALLSENSOR 1
//#define KEYFOB 1
#define MWRL 1
//#define GOLDENNODE 1
//#define KEYBOARD 1
//#define KB_OLD_VERSION

#define MAX_CHANNEL 13
#define DEFAULT_CHANNEL 0

#if GOLDENNODE
#define TCXO_PRESENT 1
#else
#define TCXO_PRESENT 0
#endif

#define INTER_PACKET_DELAY 500000UL //100ms
/// Size of RAIL RX/TX FIFO
#define RAIL_FIFO_SIZE (256u)
/// Transmit data length
#define TX_PAYLOAD_LENGTH (32u)

#define SWD_PORT    gpioPortF
#define SWDIO_PIN   1
#define SWCLK_PIN   0

#if PIRSENSOR
#define HW_VERSION 2
#define TX_PACTUNE 7
#define RX_PACTUNE 6
#define INITIAL_TX_POWER 10
#define RSSI_OFFSET -6
#define DEVICE_STRING_NAME "PIR Sensor test"
static uint8_t tx_fifo[RAIL_FIFO_SIZE] = {0, 0, 0, 0, -120, 0, 'T', 0, 0, 0, 0, 0, 0, 0, 0,'P', 'I', 'R', '_', 'S','e','n','s','o','r',' ',' '};//max length of string - 16 bytes
#define PIREN_PORT (gpioPortB)
#define PIREN_PIN (14U)
#define PIRINT_PORT gpioPortC
#define PIRINT_PIN 10

#define SL_IOSTREAM_USART_VCOM_PERIPHERAL        USART0
#define SL_IOSTREAM_USART_VCOM_PERIPHERAL_NO     0

// USART0 TX on PD14
#define SL_IOSTREAM_USART_VCOM_TX_PORT           gpioPortD
#define SL_IOSTREAM_USART_VCOM_TX_PIN            14
#define SL_IOSTREAM_USART_VCOM_TX_LOC            22

// USART0 RX on PD13
#define SL_IOSTREAM_USART_VCOM_RX_PORT           gpioPortD
#define SL_IOSTREAM_USART_VCOM_RX_PIN            13
#define SL_IOSTREAM_USART_VCOM_RX_LOC            20

#define SL_SIMPLE_BUTTON_BTN0_PORT               gpioPortF
#define SL_SIMPLE_BUTTON_BTN0_PIN                2
#define SL_SIMPLE_BUTTON_BTN1_PORT               gpioPortF
#define SL_SIMPLE_BUTTON_BTN1_PIN                2
#define SL_SIMPLE_LED_LED0_POLARITY SL_SIMPLE_LED_POLARITY_ACTIVE_HIGH
#define SL_SIMPLE_LED_LED0_PORT                  gpioPortB
#define SL_SIMPLE_LED_LED0_PIN                   15

#define SL_I2CSPM_INST_PERIPHERAL                I2C0
#define SL_I2CSPM_INST_PERIPHERAL_NO             0

// I2C0 SCL on PF3
#define SL_I2CSPM_INST_SCL_PORT                  gpioPortF
#define SL_I2CSPM_INST_SCL_PIN                   3
#define SL_I2CSPM_INST_SCL_LOC                   26

// I2C0 SDA on PD15
#define SL_I2CSPM_INST_SDA_PORT                  gpioPortD
#define SL_I2CSPM_INST_SDA_PIN                   15
#define SL_I2CSPM_INST_SDA_LOC                   23

#elif HALLSENSOR
#define HW_VERSION 4
#define TX_PACTUNE 7
#define RX_PACTUNE 13
#define INITIAL_TX_POWER 10
#define RSSI_OFFSET -6
#define DEVICE_STRING_NAME "Hall Sensor test"
static uint8_t tx_fifo[RAIL_FIFO_SIZE] = {0, 0, 0, 0, -120, 0, 'T', 0, 0, 0, 0, 0, 0, 0, 0,'H', 'a', 'l', 'l', '_','S','e','n','s','o','r',' '};//max length of string - 16 bytes
#define SL_IOSTREAM_USART_VCOM_PERIPHERAL        USART0
#define SL_IOSTREAM_USART_VCOM_PERIPHERAL_NO     0

// USART0 TX on PA0
#define SL_IOSTREAM_USART_VCOM_TX_PORT           gpioPortA
#define SL_IOSTREAM_USART_VCOM_TX_PIN            0
#define SL_IOSTREAM_USART_VCOM_TX_LOC            0

// USART0 RX on PA1
#define SL_IOSTREAM_USART_VCOM_RX_PORT           gpioPortA
#define SL_IOSTREAM_USART_VCOM_RX_PIN            1
#define SL_IOSTREAM_USART_VCOM_RX_LOC            0

#define SL_SIMPLE_BUTTON_BTN0_PORT               gpioPortC
#define SL_SIMPLE_BUTTON_BTN0_PIN                10
#define SL_SIMPLE_BUTTON_BTN1_PORT               gpioPortB
#define SL_SIMPLE_BUTTON_BTN1_PIN                13
#define SL_SIMPLE_LED_LED0_POLARITY SL_SIMPLE_LED_POLARITY_ACTIVE_LOW
#define SL_SIMPLE_LED_LED0_PORT                  gpioPortD
#define SL_SIMPLE_LED_LED0_PIN                   13

// I2C0 SCL on PB12
#define SL_I2CSPM_INST_SCL_PORT                  gpioPortB
#define SL_I2CSPM_INST_SCL_PIN                   12
#define SL_I2CSPM_INST_SCL_LOC                   6//

// I2C0 SDA on PB11
#define SL_I2CSPM_INST_SDA_PORT                  gpioPortB
#define SL_I2CSPM_INST_SDA_PIN                   11
#define SL_I2CSPM_INST_SDA_LOC                   6//

#define SI7210_ALERT_PORT                        gpioPortF
#define SI7210_ALERT_PIN                         2
#define SI7210_ALERT_INT_NO                      2

#define SI7210_OP_DEFAULT                        48 //sw_operation mode & threshold
//#define SI7210_OP_DEFAULT                        126
//#define SI7210_HYST_DEFAULT                      120
#define SI7210_HYST_DEFAULT                      0


#elif KEYFOB
#define HW_VERSION 1
#define TX_PACTUNE 1
#define RX_PACTUNE 5
#define INITIAL_TX_POWER 10
#define RSSI_OFFSET -6
#define DEVICE_STRING_NAME "KeyFob test"
static uint8_t tx_fifo[RAIL_FIFO_SIZE] = {0, 0, 0, 0, -120, 0, 'T', 0, 0, 0, 0, 0, 0, 0, 0,'K', 'e', 'y', 'F', 'o','b',' ',' ',' ',' ',' ',' '};//max length of string - 16 bytes
#define SL_IOSTREAM_USART_VCOM_PERIPHERAL        USART0
#define SL_IOSTREAM_USART_VCOM_PERIPHERAL_NO     0

// USART0 TX on PA0
#define SL_IOSTREAM_USART_VCOM_TX_PORT           gpioPortA
#define SL_IOSTREAM_USART_VCOM_TX_PIN            0
#define SL_IOSTREAM_USART_VCOM_TX_LOC            0

// USART0 RX on PA1
#define SL_IOSTREAM_USART_VCOM_RX_PORT           gpioPortA
#define SL_IOSTREAM_USART_VCOM_RX_PIN            1
#define SL_IOSTREAM_USART_VCOM_RX_LOC            0

#define SL_SIMPLE_BUTTON_BTN0_PORT               gpioPortB
#define SL_SIMPLE_BUTTON_BTN0_PIN                13
#define SL_SIMPLE_BUTTON_BTN1_PORT               gpioPortC
#define SL_SIMPLE_BUTTON_BTN1_PIN                10

#define SL_SIMPLE_BUTTON_BTN2_PORT               gpioPortD
#define SL_SIMPLE_BUTTON_BTN2_PIN                14
#define SL_SIMPLE_BUTTON_BTN3_PORT               gpioPortF
#define SL_SIMPLE_BUTTON_BTN3_PIN                2

#define SL_SIMPLE_LED_LED0_POLARITY SL_SIMPLE_LED_POLARITY_ACTIVE_HIGH
#define SL_SIMPLE_LED_LED0_PORT                  gpioPortB
#define SL_SIMPLE_LED_LED0_PIN                   11
#define SL_SIMPLE_LED_LED1_POLARITY SL_SIMPLE_LED_POLARITY_ACTIVE_HIGH
#define SL_SIMPLE_LED_LED1_PORT                  gpioPortB
#define SL_SIMPLE_LED_LED1_PIN                   12
// I2C0 SCL on PF3
#define SL_I2CSPM_INST_SCL_PORT                  gpioPortF
#define SL_I2CSPM_INST_SCL_PIN                   3
#define SL_I2CSPM_INST_SCL_LOC                   26

// I2C0 SDA on PD15
#define SL_I2CSPM_INST_SDA_PORT                  gpioPortD
#define SL_I2CSPM_INST_SDA_PIN                   15
#define SL_I2CSPM_INST_SDA_LOC                   23

#elif MWRL
#define HW_VERSION 3
#define TX_PACTUNE 7
#define RX_PACTUNE 12
#define INITIAL_TX_POWER 14
#define RSSI_OFFSET -5
#define RXTX_PIN                                 (11U)
#define RXTX_PORT                                (gpioPortB)
#define DEVICE_STRING_NAME "M-WRL test"
static uint8_t tx_fifo[RAIL_FIFO_SIZE] = {0, 0, 0, 0, -120, 0, 'T', 0, 0, 0, 0, 0, 0, 0, 0,'M', '-', 'W', 'R', 'L',' ',' ',' ',' ',' ',' ',' '};//max length of string - 16 bytes
#define SL_IOSTREAM_USART_VCOM_PERIPHERAL        USART0
#define SL_IOSTREAM_USART_VCOM_PERIPHERAL_NO     0

// USART0 TX on PD14 - normal
#define SL_IOSTREAM_USART_VCOM_TX_PORT           gpioPortD
#define SL_IOSTREAM_USART_VCOM_TX_PIN            14
#define SL_IOSTREAM_USART_VCOM_TX_LOC            22

// USART0 RX on PD13 - normal
#define SL_IOSTREAM_USART_VCOM_RX_PORT           gpioPortD
#define SL_IOSTREAM_USART_VCOM_RX_PIN            13
#define SL_IOSTREAM_USART_VCOM_RX_LOC            20

// USART0 TX on PA0
//#define SL_IOSTREAM_USART_VCOM_TX_PORT           gpioPortA
//#define SL_IOSTREAM_USART_VCOM_TX_PIN            0
//#define SL_IOSTREAM_USART_VCOM_TX_LOC            0
//
// USART0 RX on PA1
//#define SL_IOSTREAM_USART_VCOM_RX_PORT           gpioPortA
//#define SL_IOSTREAM_USART_VCOM_RX_PIN            1
//#define SL_IOSTREAM_USART_VCOM_RX_LOC            0

// USART0 TX on PA0 - reverse
//#define SL_IOSTREAM_USART_VCOM_TX_PORT           gpioPortA
//#define SL_IOSTREAM_USART_VCOM_TX_PIN            1
//#define SL_IOSTREAM_USART_VCOM_TX_LOC            1
//
// USART0 RX on PA1 - reverse
//#define SL_IOSTREAM_USART_VCOM_RX_PORT           gpioPortA
//#define SL_IOSTREAM_USART_VCOM_RX_PIN            0
//#define SL_IOSTREAM_USART_VCOM_RX_LOC            31

#define SL_SIMPLE_BUTTON_BTN0_PORT               gpioPortC
#define SL_SIMPLE_BUTTON_BTN0_PIN                10
#define SL_SIMPLE_BUTTON_BTN1_PORT               gpioPortC
#define SL_SIMPLE_BUTTON_BTN1_PIN                10
#define SL_SIMPLE_LED_LED0_POLARITY SL_SIMPLE_LED_POLARITY_ACTIVE_LOW
#define SL_SIMPLE_LED_LED0_PORT                  gpioPortC
#define SL_SIMPLE_LED_LED0_PIN                   11

// I2C0 SCL on PF3
#define SL_I2CSPM_INST_SCL_PORT                  gpioPortF
#define SL_I2CSPM_INST_SCL_PIN                   3
#define SL_I2CSPM_INST_SCL_LOC                   26

// I2C0 SDA on PD15
#define SL_I2CSPM_INST_SDA_PORT                  gpioPortD
#define SL_I2CSPM_INST_SDA_PIN                   15
#define SL_I2CSPM_INST_SDA_LOC                   23

#elif GOLDENNODE
#define HW_VERSION 1
#define TX_PACTUNE 5
#define RX_PACTUNE 5
#define INITIAL_TX_POWER 10

/*
#define RF_LEVEL_HIGH     41 //MCUID: 0xCCCCCCFFFEDE1938
#define RF_LEVEL_LOW      3
#define RF_ATT_HIGH       0
#define RF_ATT_MID1       50
#define RF_ATT_MID2       55
#define RF_ATT_LOW        62
*/
/*
#define RF_LEVEL_HIGH     36 //MCUID: 0xCCCCCCFFFED9F7AF
#define RF_LEVEL_LOW      3
#define RF_ATT_HIGH       0
#define RF_ATT_MID1       50
#define RF_ATT_MID2       57
#define RF_ATT_LOW        62
*/

/*
#define RF_LEVEL_HIGH     37 //MCUID: 0xCCCCCCFFFEDE1C56
#define RF_LEVEL_LOW      3
#define RF_ATT_HIGH       0
#define RF_ATT_MID1       50
#define RF_ATT_MID2       57
#define RF_ATT_LOW        62
*/

/*
#define RF_LEVEL_HIGH     37 //MCUID: 0xCCCCCCFFFEDCB724
#define RF_LEVEL_LOW      3
#define RF_ATT_HIGH       0
#define RF_ATT_MID1       50
#define RF_ATT_MID2       57
#define RF_ATT_LOW        62
*/


#define RF_LEVEL_HIGH     40 //MCUID: 0xCCCCCCFFFEDE1CB5

#define RF_LEVEL_LOW      3
#define RF_ATT_HIGH       0
#define RF_ATT_MID1       50
#define RF_ATT_MID2       57
#define RF_ATT_LOW        62



#define RSSI_OFFSET -4
#define HFXO_PORT                  gpioPortF
#define HFXO_PIN                   3
#define STB_PORT                  gpioPortD
#define STB_PIN                   15
#define DEVICE_STRING_NAME "Golden Node"
static uint8_t tx_fifo[RAIL_FIFO_SIZE] = {0, 0, 0, 0, -120, 0, 'T', 0, 0, 0, 0, 0, 0, 0, 0,'G', 'o', 'l', 'd', 'e','n','_','N','o','d','e',' '};//max length of string - 16 bytes
#define SL_IOSTREAM_USART_VCOM_PERIPHERAL        USART0
#define SL_IOSTREAM_USART_VCOM_PERIPHERAL_NO     0

// USART0 TX on PA0
#define SL_IOSTREAM_USART_VCOM_TX_PORT           gpioPortA
#define SL_IOSTREAM_USART_VCOM_TX_PIN            0
#define SL_IOSTREAM_USART_VCOM_TX_LOC            0

// USART0 RX on PA1
#define SL_IOSTREAM_USART_VCOM_RX_PORT           gpioPortA
#define SL_IOSTREAM_USART_VCOM_RX_PIN            1
#define SL_IOSTREAM_USART_VCOM_RX_LOC            0

#define SL_SIMPLE_BUTTON_BTN0_PORT               gpioPortB
#define SL_SIMPLE_BUTTON_BTN0_PIN                14
#define SL_SIMPLE_BUTTON_BTN1_PORT               gpioPortB
#define SL_SIMPLE_BUTTON_BTN1_PIN                14
#define SL_SIMPLE_LED_LED0_POLARITY              SL_SIMPLE_LED_POLARITY_ACTIVE_HIGH
#define SL_SIMPLE_LED_LED0_PORT                  gpioPortB
#define SL_SIMPLE_LED_LED0_PIN                   15

// I2C0 SCL
#define SL_I2CSPM_INST_SCL_PORT                  gpioPortC
#define SL_I2CSPM_INST_SCL_PIN                   10
#define SL_I2CSPM_INST_SCL_LOC                   6//

// I2C0 SDA
#define SL_I2CSPM_INST_SDA_PORT                  gpioPortC
#define SL_I2CSPM_INST_SDA_PIN                   11
#define SL_I2CSPM_INST_SDA_LOC                   6//

#define LE_PORT (gpioPortD)
#define LE_PIN (15U)
#define SCK_PORT  (gpioPortD)
#define SCK_PIN   (14U)
#define MOSI_PORT gpioPortD
#define MOSI_PIN  (13U)

#define EXT_LE_PORT (gpioPortB)
#define EXT_LE_PIN (11U)
#define EXT_SCK_PORT  (gpioPortB)
#define EXT_SCK_PIN   (12U)
#define EXT_MOSI_PORT gpioPortB
#define EXT_MOSI_PIN  (13U)

#elif KEYBOARD
#define HW_VERSION 3
#define LED_COUNT 24
#define TX_PACTUNE 14
#define RX_PACTUNE 14
#define INITIAL_TX_POWER 10
#define RSSI_OFFSET -6
#define DEVICE_STRING_NAME "Key Board test"
static uint8_t tx_fifo[RAIL_FIFO_SIZE] = {0, 0, 0, 0, -120, 0, 'T', 0, 0, 0, 0, 0, 0, 0, 0,'K', 'e', 'y', '_', 'B','o','a','r','d',' ',' ',' '};//max length of string - 16 bytes
#define SL_IOSTREAM_USART_VCOM_PERIPHERAL        USART0
#define SL_IOSTREAM_USART_VCOM_PERIPHERAL_NO     0

// USART0 TX on PD14
#define SL_IOSTREAM_USART_VCOM_TX_PORT           gpioPortD
#define SL_IOSTREAM_USART_VCOM_TX_PIN            14
#define SL_IOSTREAM_USART_VCOM_TX_LOC            22

// USART0 RX on PD13
#define SL_IOSTREAM_USART_VCOM_RX_PORT           gpioPortD
#define SL_IOSTREAM_USART_VCOM_RX_PIN            13
#define SL_IOSTREAM_USART_VCOM_RX_LOC            20

#define SL_SIMPLE_BUTTON_BTN0_PORT               gpioPortC
#define SL_SIMPLE_BUTTON_BTN0_PIN                10
#define SL_SIMPLE_BUTTON_BTN1_PORT               gpioPortB
#define SL_SIMPLE_BUTTON_BTN1_PIN                13
#define SL_SIMPLE_LED_LED0_POLARITY SL_SIMPLE_LED_POLARITY_ACTIVE_HIGH
//#define SL_SIMPLE_LED_LED0_PORT                  gpioPortC //fake!!!
//#define SL_SIMPLE_LED_LED0_PIN                   11

#define SL_I2CSPM_INST_PERIPHERAL                I2C0
#define SL_I2CSPM_INST_PERIPHERAL_NO             0
// I2C0 SCL on PF3
#define SL_I2CSPM_INST_SCL_PORT                  gpioPortF
#define SL_I2CSPM_INST_SCL_PIN                   3
#define SL_I2CSPM_INST_SCL_LOC                   26
// I2C0 SDA on PD15
#define SL_I2CSPM_INST_SDA_PORT                  gpioPortD
#define SL_I2CSPM_INST_SDA_PIN                   15
#define SL_I2CSPM_INST_SDA_LOC                   23

#define SFH7771INT_PORT                          gpioPortF //not in use
#define SFH7771INT_PIN                           2

#define DCDC_PORT                  gpioPortB
#define DCDC_PIN                   14
#define EN5024_PORT                gpioPortB
#define EN5024_PIN                 15

#define CAPRES_PORT                gpioPortA //keypad reset, active 0
#define CAPRES_PIN                 0
#define CAPSYNC_PORT               gpioPortA //keypad sync - ???
#define CAPSYNC_PIN                1

#define SENSE_PORT                 gpioPortB //keypad interrupt, falling edge - ???
#define SENSE_PIN                  11
#define SENSE_INT_NO               11 //2

#define BUZZER_PORT                gpioPortB //beeper, active 1
#define BUZZER_PIN                 12
#define KEYPAD_PORT                gpioPortC //keypad power, active 0
#define KEYPAD_PIN                 11

#define DEF_COLOR 127
#define DEF_BRIGHT 127


#else
#define HW_VERSION 0
#define TX_PACTUNE 4
#define RX_PACTUNE 5
#define INITIAL_TX_POWER 10
#define RSSI_OFFSET -4
#define DEVICE_STRING_NAME "New device test"
static uint8_t tx_fifo[RAIL_FIFO_SIZE] = {0, 0, 0, 0, -120, 0, 'T', 0, 0, 0, 0, 0, 0, 0, 0,'N', 'e', 'w', '_', 'D','e','v','i','c','e',' ',' '};//max length of string - 16 bytes
#define SL_IOSTREAM_USART_VCOM_PERIPHERAL        USART0
#define SL_IOSTREAM_USART_VCOM_PERIPHERAL_NO     0

// USART0 TX on PA0
#define SL_IOSTREAM_USART_VCOM_TX_PORT           gpioPortA
#define SL_IOSTREAM_USART_VCOM_TX_PIN            0
#define SL_IOSTREAM_USART_VCOM_TX_LOC            0

// USART0 RX on PA1
#define SL_IOSTREAM_USART_VCOM_RX_PORT           gpioPortA
#define SL_IOSTREAM_USART_VCOM_RX_PIN            1
#define SL_IOSTREAM_USART_VCOM_RX_LOC            0

#define SL_SIMPLE_BUTTON_BTN0_PORT               gpioPortB
#define SL_SIMPLE_BUTTON_BTN0_PIN                11
#define SL_SIMPLE_BUTTON_BTN1_PORT               gpioPortB
#define SL_SIMPLE_BUTTON_BTN1_PIN                12
#define SL_SIMPLE_LED_LED0_POLARITY SL_SIMPLE_LED_POLARITY_ACTIVE_HIGH
#define SL_SIMPLE_LED_LED0_PORT                  gpioPortB
#define SL_SIMPLE_LED_LED0_PIN                   13

#endif


#endif
