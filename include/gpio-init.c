#include <gpio-init.h>

Err startGPIO_A5() {
  uint16_t pin = 5;
  GPIO_TypeDef *gpio = GPIOA_BASE;
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
	// Initilizing pin pin to high
	gpio->ODR |=   (1 << pin);  // set pin pin to 1

  return 0;
}
