#include "main.h"
#include "project_config.h"

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
    xTaskCreate(task1, "TASK1", 2048, NULL, 1, NULL);
    xTaskCreate(task2, "TASK2", 2048, NULL, 1, NULL);
    
    printf("Both tasks created in IDF!\n");
}