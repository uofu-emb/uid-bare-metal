#include <mock_hal.h>
#include <gpio.c>
#include <unity.h>

/*
 * Sets GPIO as output
 *
 * @returns: non-zero on error
 */
void startGPIO_test() {

  ERROR_CODE error;
  GPIO_TypeDef GPIOZ = {0,0,0,0,0,0,0,0,0,0,0};
  struct GPIO_Init pin5;
  pin5.pin = 1 << 5; // assign pin 5
  pin5.mode = GPIO_MODE_OUTPUT_PP;
  pin5.speed = GPIO_SPEED_FREQ_LOW;
  pin5.pullDir = GPIO_PULLUP;

  error = startGPIO(&GPIOZ, &pin5);

  TEST_ASSERT_TRUE_MESSAGE(GPIOZ.MODER == (GPIO_MODE_OUTPUT_PP << 5*2u),"Incorrect bit assignment to gpio.MODER");
  TEST_ASSERT_TRUE(GPIOZ.OTYPER == 0);
  TEST_ASSERT_TRUE(GPIOZ.OSPEEDR == 0);
  TEST_ASSERT_TRUE(GPIOZ.PUPDR == 0);
  TEST_ASSERT_TRUE_MESSAGE(error == 0, "Make sure to implement this function, you silly goose!");
}

/*
 * Sets GPIO to 1
 *
 * @returns: non-zero on error
 */
void setGPIO_test() {
  
}

/*
 * Sets GPIO to 0
 *
 * @returns: non-zero on error
 */
void clearGPIO_test() {
  
}

/*
 * inverts GPIO from 0-> 1 or 1-> 0
 *
 * @returns: non-zero on error
 */
void invertGPIO_test() {
  
}