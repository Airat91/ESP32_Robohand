/*
 * File:        led.h
 * Authors:     Girfanov.Ayrat@yandex.ru
 * Description: LED control functions
 * Revision history: 0.1
 */

#ifndef LED_H
#define LED_H
/*add includes below */
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "pin_map.h"
/*add includes before */

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/**
 * @defgroup led
 * @brief LED control functions
 */

//--------Defines--------

#define LED_TASK_STACK_SIZE     20      // LED task stack size in words
#define LED_TASK_PRIORITY       1       // LED task priority
#define LED_TASK_PERIOD_MS      10      // LED task execution period in milliseconds
#define LED_NMBR                1       // Number of LEDs in the system

#define LED_ON                  1       // LED ON state
#define LED_OFF                 0       // LED OFF state

#define LED_OK                  PIN_LED // LED OK pin number

#ifndef PIN_LED
#error "PIN_LED is not defined"
#endif // PIN_LED

//--------Macro--------

//--------Typedefs-------

typedef struct {
    uint32_t pin[LED_NMBR];             // GPIO pin number for the LED
    uint32_t duration_ms[LED_NMBR];     // Duration for which the LED should be on (in milliseconds)
} led_pcb_str;

//-------Function prototypes----------

/**
 * @brief Initialize the LED GPIO pin
 * @ingroup led
 * @param led_pcb - pointer to the LED control block structure
 * @return  0 ok,\n
 *          negative value - gpio_config error number
 */
int led_init(led_pcb_str* led_pcb);

/**
 * @brief Deinitialize the LED GPIO pin
 * @ingroup led
 * @param led_pcb - pointer to the LED control block structure
 * @return  0 ok,\n
 *          negative value if error
 */
int led_deinit(led_pcb_str* led_pcb);

/**
 * @brief Turn on the LED for a specified duration
 * @ingroup led
 * @param pin - GPIO pin number for the LED
 * @param duration_ms - duration for which to turn on the LED (in milliseconds)
 * @return  0 ok,\n
 *          negative value if error
 */
int led_on(uint32_t pin, uint32_t duration_ms);

/**
 * @brief Turn off the LED
 * @ingroup led
 * @param pin - GPIO pin number for the LED
 * @return  0 ok,\n
 *          negative value if error
 */
int led_off(uint32_t pin);

/**
 * @brief Toggle the LED state
 * @ingroup led
 * @param pin - GPIO pin number for the LED
 * @return  0 ok,\n
 *          negative value if error
 */
int led_toggle(uint32_t pin);

/**
 * @brief LED task function
 * @ingroup led
 * @param pvParameters - task parameters
 */
void led_task(void *pvParameters);

/**
 * @brief LED main callback function to be called periodically
 * @ingroup led
 * @param period_ms - period for which to execute the callback (in milliseconds)
 * @return  0 ok,\n
 *          negative value if error
 */
int led_main_clb(uint32_t period_ms);

//-------External variables------

extern TaskHandle_t led_task_handle;    // Handle for the LED task

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // LED_H