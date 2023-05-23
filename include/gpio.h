#include <stdint.h>

#include <error.h>

struct GPIO_Init
{
  uint32_t pin;       /*!< Specifies the GPIO pins to be configured.
                           This parameter can be any value of @ref GPIO_pins */

  uint32_t mode;      /*!< Specifies the operating mode for the selected pins.
                           This parameter can be a value of @ref GPIO_mode */

  uint32_t pullDir;      /*!< Specifies the Pull-up or Pull-Down activation for the selected pins.
                           This parameter can be a value of @ref GPIO_pull */

  uint32_t speed;     /*!< Specifies the speed for the selected pins.
                           This parameter can be a value of @ref GPIO_speed */
};

/**
  * @brief  Initialize the GPIOx peripheral according to the specified parameters in the GPIO_Init.
  * @param  GPIOx where x can be (A..F) to select the GPIO peripheral for STM32F0 family
  * @param  GPIO_Init pointer to a GPIO_InitTypeDef structure that contains
  *         the configuration information for the specified GPIO peripheral.
  * @retval Non-Zero on error
  */
ERROR_CODE startGPIO(GPIO_TypeDef *gpio, struct GPIO_Init* gpio_init);