/**************************************************************************//**
 * @file coexistence_efr32.h
 * @brief This file contains the EFR32 radio coexistence interface.
 * @copyright Copyright 2017 Silicon Laboratories, Inc. www.silabs.com
 *****************************************************************************/

#ifndef __COEXISTENCE_EFR32_H__
#define __COEXISTENCE_EFR32_H__

#include "rail.h"
#include "coexistence/coexistence.h"
#include "em_gpio.h"
#include "gpiointerrupt.h"

typedef struct COEX_EFR32_GpioConfig {
  /** GPIO port */
  GPIO_Port_TypeDef port;

  /** GPIO pin */
  uint8_t pin;

  /** GPIO assert polarity */
  bool polarity;

  /** GPIO mode */
  GPIO_Mode_TypeDef mode;

  /** GPIO ISR */
  GPIOINT_IrqCallbackPtr_t isr;

  /** GPIO config */
  COEX_GpioConfig_t config;
} COEX_EFR32_GpioConfig_t;

void COEX_EFR32_SetCallbacks(RAIL_Handle_t railHandle);
void COEX_EFR32_Init(void);
bool COEX_EFR32_ConfigRequest(COEX_EFR32_GpioConfig_t *gpioConfig);
bool COEX_EFR32_ConfigRadioHoldOff(COEX_EFR32_GpioConfig_t *gpioConfig);
bool COEX_EFR32_ConfigPriority(COEX_EFR32_GpioConfig_t *gpioConfig);
bool COEX_EFR32_ConfigGrant(COEX_EFR32_GpioConfig_t *gpioConfig);

#endif  // __COEXISTENCE_EFR32_H__
