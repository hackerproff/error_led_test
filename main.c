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

#define barrier() do { __asm__ __volatile__ (""); } while (0)

#include <libopencm3/cm3/scb.h>
#include <libopencm3/cm3/nvic.h>
#include <libopencm3/cm3/cortex.h>

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/flash.h>
#include <libopencm3/stm32/exti.h>
#include <libopencm3/stm32/timer.h>

#include <libopencm3/cm3/systick.h>

static uint32_t erledpin[] = {
	GPIO4,
	GPIO5,
	GPIO7,
	GPIO0,
	GPIO2,
	GPIO10,
	GPIO11,
	GPIO12,
};

static uint32_t erledport[] = {
	GPIOA,
	GPIOA,
	GPIOA,
	GPIOB,
	GPIOB,
	GPIOB,
	GPIOB,
	GPIOB,
};

void sys_tick_handler(void)  // 1 KHz
{
	static uint8_t i = 0;
	gpio_toggle(erledport[i], erledpin[i]);
	++i;
	if (i > 7) i = 0;
} 

int main(void)
{
	extern uint32_t vector_table __asm__("vector_table");
	SCB_VTOR = (uint32_t) &vector_table;
	
	rcc_clock_setup_in_hse_8mhz_out_72mhz();
	
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_IOPAEN);
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_IOPBEN);
	
	systick_set_clocksource(STK_CTRL_CLKSOURCE_AHB);
	systick_set_reload(14399999); //24 bit reload value. 16777216
	systick_interrupt_enable();
	
	for (uint8_t i = 0; i < 8; ++i) {
		gpio_clear(erledport[i], erledpin[i]);
		gpio_set_mode(erledport[i], GPIO_MODE_OUTPUT_2_MHZ, GPIO_CNF_OUTPUT_PUSHPULL, erledpin[i] );
	}
	
	systick_counter_enable();
	
	while ( 1 )	{
		barrier();
	}
	return 0;
}
