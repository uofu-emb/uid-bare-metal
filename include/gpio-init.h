#include <stdint.h>
#include <stm32f4xx_hal.h>
#ifndef Err
#define Err uint8_t
#endif

/*
 * Sets GPIO_A5 as output
 *
 * @returns: non-zero on error
 */
Err startGPIO_A5();