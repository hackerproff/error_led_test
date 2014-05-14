/*	file: common.h						
	
	hackerproff@gmail.com
	hackerproff@ya.ru			*/

#pragma once

#include <libopencm3/cm3/scb.h>
#include <libopencm3/cm3/nvic.h>
#include <libopencm3/cm3/cortex.h>

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/flash.h>
#include <libopencm3/stm32/exti.h>
#include <libopencm3/stm32/timer.h>

#define ARRAY_SIZE(x) (sizeof(x)/sizeof(x[0]))

#define barrier() do { __asm__ __volatile__ (""); } while (0)
