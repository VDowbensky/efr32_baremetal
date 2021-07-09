#include "leds.h"

void leds_init(void)
{
#if LED0
	#if LED_POLARITY
	GPIO_PinModeSet(LED0_PORT, LED0_PIN, gpioModePushPull, 0);
	#else
	GPIO_PinModeSet(LED0_PORT, LED0_PIN, gpioModePushPull, 1);
	#endif
#endif
	
#if LED1
	#if LED_POLARITY
	GPIO_PinModeSet(LED1_PORT, LED1_PIN, gpioModePushPull, 1);
	#else
	GPIO_PinModeSet(LED1_PORT, LED1_PIN, gpioModePushPull, 0);
	#endif
#endif
}

#if LED0
void led0_on(void)
{
#if LED_POLARITY
	GPIO_PinOutSet(LED0_PORT, LED0_PIN);
#else
	GPIO_PinOutClear(LED0_PORT, LED0_PIN);
#endif	
}

void led0_off(void)
{
#if LED_POLARITY
	GPIO_PinOutClear(LED0_PORT, LED0_PIN);
#else
	GPIO_PinOutSet(LED0_PORT, LED0_PIN);
#endif	
}
#endif //LED0

#if LED1
void led1_on(void)
{
#if LED_POLARITY
	GPIO_PinOutSet(LED1_PORT, LED1_PIN);
#else
	GPIO_PinOutClear(LED1_PORT, LED1_PIN);
#endif	
}


void led1_off(void)
{
#if LED_POLARITY
	GPIO_PinOutClear(LED1_PORT, LED1_PIN);
#else
	GPIO_PinOutSet(LED1_PORT, LED1_PIN);
#endif	
}
#endif //LED1