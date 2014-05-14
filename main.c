/*     main.c
	
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


static inline void gpio_init( void )
{
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_IOPAEN);
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_IOPBEN);
	gpio_clear(LED_PORT, LED_PIN);
	gpio_set_mode(LED_PORT, GPIO_MODE_OUTPUT_2_MHZ, GPIO_CNF_OUTPUT_PUSHPULL, LED_PIN);
}

int main(void)
{
	extern uint32_t vector_table __asm__("vector_table");
	SCB_VTOR = (uint32_t) &vector_table;
	rcc_clock_setup_in_hse_8mhz_out_72mhz();
	

	gpio_init();



	while ( 1 )	{
	}
	return 0;
}
