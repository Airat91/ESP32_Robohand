/*
 * File:        main.c
 * Authors:     Girfanov.Ayrat@yandex.ru
 * Description: System debug functions and control
 * Revision history: 0.1
 */

#include "main.h"

//-------Global variables------

//-------Static variables------

//-------Static functions declaration-----------

//-------Functions----------

// Задача 1
void task1(void *pvParameters) {
    while (1) {
        printf("Task 1 is running\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

// Задача 2
void task2(void *pvParameters) {
    while (1) {
        printf("Task 2 is running\n");
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}

void app_main() {
    // Создаем две задачи, которые будут работать параллельно
    led_task_handle = xTaskCreateStatic(led_task, "LED_TASK", LED_TASK_STACK_SIZE, NULL, LED_TASK_PRIORITY, NULL, NULL);
    
    printf("Both tasks created in IDF!\n");
}

//-------Static functions----------