#include <gpio.h>
#include <error.h>

/*
 * Sets GPIO_A5 as output
 *
 * @retval: non-zero on error
 */
ERROR_CODE startGPIO_A5() {
  uint16_t pin = 5;
  GPIO_TypeDef *gpio = GPIOA;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	// MODER pins pin = GPIO_OUTPUT = 01 (*2 bit index for 2-bit data)
	gpio->MODER &= ~(0x3 << pin*2u); // sets to 00
	gpio->MODER |=   (GPIO_MODE_OUTPUT_PP << pin*2u);  // sets to 01
	// OTYPER pins pin = GPIO_OUTPUT = 0
	gpio->OTYPER &= (MODE_OUTPUT << pin);  // sets to 0
	// OSPEEDR pins pin = GPIO_SPEED_FREQ_LOW = 00 (*2 bit index for 2-bit data)
	gpio->OSPEEDR &= (GPIO_SPEED_FREQ_LOW << pin*2u); // sets to 00, no need to set
	// OSPEEDR pins pin = GPIO_NOPULL = 00 (*2 bit index for 2-bit data)
	gpio->PUPDR &= (GPIO_PULLUP << pin*2u); // sets 
	// Initiliazing pin pin to high
	gpio->ODR |=   (1 << pin);  // set pin pin to 1

  return NO_ERROR;
}

/*
 * Sets GPIO_A5 to 1
 *
 * @retval: non-zero on error
 */
ERROR_CODE setGPIO_A5() {
  GPIOA->ODR |= 0x1 << 5;
  return NOT_IMPLEMENTED;
}

/*
 * Sets GPIO_A5 to 0
 *
 * @retval: non-zero on error
 */
ERROR_CODE clearGPIO_A5() {
  GPIOA->ODR &= ~(0x1 << 5);
  return NOT_IMPLEMENTED;
}

/*
 * inverts GPIO_A5 from 0-> 1 or 1-> 0
 *
 * @retval: non-zero on error
 */
ERROR_CODE invertGPIO_A5() {
  GPIOA->ODR ^= 0x1 << 5;
  return NOT_IMPLEMENTED;
}

/**
  * @brief  Initialize the GPIOx peripheral according to the specified parameters in the GPIO_Init.
  * @param  GPIOx where x can be (A..F) to select the GPIO peripheral for STM32F0 family
  * @param  GPIO_Init pointer to a GPIO_InitTypeDef structure that contains
  *         the configuration information for the specified GPIO peripheral.
  * @retval Non-Zero on error
  */
ERROR_CODE startGPIO(GPIO_TypeDef *gpio, struct GPIO_Init* gpio_init) {
	return NOT_IMPLEMENTED;
}
