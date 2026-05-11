/*
 * File:        led.c
 * Authors:     Girfanov.Ayrat@yandex.ru
 * Description: LED control functions
 * Revision history: 0.1
 */

#include "led.h"

//-------Global variables------

TaskHandle_t led_task_handle = {0};     // Handle for the LED task

//-------Static variables------

led_pcb_str led_pcb = {
    .pin = {PIN_LED},               // GPIO pin number for the LED
    .duration_ms = {0}              // Duration for which the LED should be on (in milliseconds)
}; // LED control block structure

//-------Static functions declaration-----------

//-------Functions----------

int led_init(led_pcb_str* led_pcb) {
    int result = 0;

    // Initialize the LED GPIO pin
    gpio_config_t io_conf = {0};

    io_conf.intr_type = GPIO_INTR_DISABLE;      // Disable interrupt
    io_conf.mode = GPIO_MODE_OUTPUT;            // Set as output mode
    io_conf.pull_down_en = 1;                   // Enable pull-down
    io_conf.pull_up_en = 0;                     // Disable pull-up

    for(int i = 0; i < LED_NMBR; i++) {
        io_conf.pin_bit_mask = (1ULL << PIN_LED);   // Bit mask for the LED pin
        if (gpio_config(&io_conf) != ESP_OK) {
            result = -1 - i;    // Error initializing GPIO
            break;
        }else{
            gpio_set_level(led_pcb->pin[i], 0);     // Ensure LED is off after initialization
        }
    }

    return result;
}

int led_deinit(led_pcb_str* led_pcb){
    int result = 0;

    for(int i = 0; i < LED_NMBR; i++) {
        if (gpio_reset_pin(led_pcb->pin[i]) != ESP_OK) {
            result = -1 - i;    // Error deinitializing GPIO
            break;
        }
    }

    return result;
}

int led_on(uint32_t pin, uint32_t duration_ms){
    int result = 0;

    for(int i = 0; i < LED_NMBR; i++) {
        if(led_pcb.pin[i] == pin) {                             // Found the LED pin in the control block
            if(gpio_get_level(led_pcb.pin[i]) == LED_OFF) {     // If the LED is already off
                gpio_set_level(led_pcb.pin[i], LED_ON);         // Turn on the LED
            }
            led_pcb.duration_ms[i] += duration_ms;              // Increase the duration for the LED
            break;
        }
    }

    return 0;
}

int led_off(uint32_t pin){
    int result = 0;

    if(gpio_get_level(pin) == LED_ON) {     // If the LED is currently on
        gpio_set_level(pin, LED_OFF);       // Turn off the LED
    }
    return result;
}

int led_toggle(uint32_t pin){
    int result = 0;

    if(gpio_get_level(pin) == LED_ON) {     // If the LED is currently on
        gpio_set_level(pin, LED_OFF);       // Turn off the LED
    } else {
        gpio_set_level(pin, LED_ON);        // Turn on the LED
    }
    return result;
}

void led_task(void *pvParameters){
    void* param = pvParameters;

    led_init(&led_pcb);    // Initialize the LED control block

    while (1) {
        for(int i = 0; i < LED_NMBR; i++) {
            if(led_pcb.duration_ms[i] > 0) {                    // If the LED should be on
                led_pcb.duration_ms[i] -= LED_TASK_PERIOD_MS;   // Decrease the remaining duration
                if(led_pcb.duration_ms[i] <= 0) {               // If the duration has elapsed
                    gpio_set_level(led_pcb.pin[i], LED_OFF);    // Turn off the LED
                    led_pcb.duration_ms[i] = 0;                 // Reset the duration
                }
            }
        }

        vTaskDelay(LED_TASK_PERIOD_MS / portTICK_PERIOD_MS);    // Delay for the next task execution
    }
}

int led_main_clb(uint32_t period_ms){
    int result = 0;

    for(int i = 0; i < LED_NMBR; i++) {
        if(led_pcb.duration_ms[i] > 0) {                    // If the LED should be on
            led_pcb.duration_ms[i] -= period_ms;            // Decrease the remaining duration
            if(led_pcb.duration_ms[i] <= 0) {               // If the duration has elapsed
                gpio_set_level(led_pcb.pin[i], LED_OFF);    // Turn off the LED
                led_pcb.duration_ms[i] = 0;                 // Reset the duration
            }
        }
    }

    return result;
}

//-------Static functions----------