/*     main.c
	
	20140514
	
	hackerproff@gmail.com
	hackerproff@ya.ru

error led test

PA4		ERR_LED_0	со стороны юсб входа
PA5		ERR_LED_1
PA7		ERR_LED_2
PB0		ERR_LED_3
PB2		ERR_LED_4
PB10	ERR_LED_5
PB11	ERR_LED_6
PB12	ERR_LED_7

===========================================================================*/

#include "common.h"

enum errled
{
	ERLED_0 = GPIO4,
	ERLED_1 = GPIO5,
	ERLED_2 = GPIO7,
	ERLED_3 = GPIO0,
	ERLED_4 = GPIO2,
	ERLED_5 = GPIO10,
	ERLED_6 = GPIO11,
	ERLED_7 = GPIO12,
};

static inline void toogle_led(enum errled in)
{
	switch (in) {
		case ERLED_0: gpio_toggle(GPIOA, in); return;
		case ERLED_1: gpio_toggle(GPIOA, in); return;
		case ERLED_2: gpio_toggle(GPIOA, in); return;
		default:      gpio_toggle(GPIOB, in);      return;
	}
}

int main(void)
{
	extern uint32_t vector_table __asm__("vector_table");
	SCB_VTOR = (uint32_t) &vector_table;
	
	rcc_clock_setup_in_hse_8mhz_out_72mhz();
	
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_IOPAEN);
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_IOPBEN);
	
	gpio_clear(GPIOA, ERLED_0);
	gpio_clear(GPIOA, ERLED_1);
	gpio_clear(GPIOA, ERLED_2);

	gpio_clear(GPIOB, ERLED_3);
	gpio_clear(GPIOB, ERLED_4);
	gpio_clear(GPIOB, ERLED_5);
	gpio_clear(GPIOB, ERLED_6);
	gpio_clear(GPIOB, ERLED_7);



	gpio_set_mode(LED_PORT, GPIO_MODE_OUTPUT_2_MHZ, GPIO_CNF_OUTPUT_PUSHPULL, LED_PIN);
	
	



	while ( 1 )	{
	}
	return 0;
}
