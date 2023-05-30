#include <mock_hal.h>
#include <gpio.c>
#include <unity.h>

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
  TEST_ASSERT_TRUE_MESSAGE(GPIOZ.OTYPER == 0,"Incorrect bit assignment to gpio.OTYPER");
  TEST_ASSERT_TRUE_MESSAGE(GPIOZ.OSPEEDR == 0,"Incorrect bit assignment to gpio.OSPEEDR");
  TEST_ASSERT_TRUE_MESSAGE(GPIOZ.PUPDR == 0,"Incorrect bit assignment to gpio.PUPDR");
  TEST_ASSERT_TRUE_MESSAGE(error == 0, "Make sure to implement startGPIO, you silly goose!");
}