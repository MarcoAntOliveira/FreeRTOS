#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#define LED 2

TaskHandle_t task1Handle = NULL;
TaskHandle_t task2Handle = NULL;
TaskHandle_t task3Handle = NULL;

void vTask1(void *pvParameters);
void vTask2(void *pvParameters);
void vTask3(void *pvParameters);

void setup() {
    Serial.begin(115200);

    xTaskCreatePinnedToCore(
        vTask1,
        "TASK1",
        4096,
        (void*)LED,
        1,
        &task1Handle,
        APP_CPU_NUM
    );

    xTaskCreatePinnedToCore(
        vTask2,
        "TASK2",
        4096,
        NULL,
        1,
        &task2Handle,
        PRO_CPU_NUM
    );

    xTaskCreatePinnedToCore(
        vTask3,
        "TASK3",
        4096,
        NULL,
        1,
        &task3Handle,
        APP_CPU_NUM
    );
}

void loop() {
    vTaskDelay(3000);
}

void vTask1(void *pvParameters)
{
    int pin = (int)pvParameters;
    pinMode(pin, OUTPUT);

    while(1){
        digitalWrite(pin, !digitalRead(pin));
        vTaskDelay(pdMS_TO_TICKS(200));

        UBaseType_t freeStack = uxTaskGetStackHighWaterMark(NULL);
        Serial.println("Task 1 stack livre: " + String(freeStack));
    }
}

void vTask2(void *pvParameters)
{
    int count = 0;

    while (1)
    {
        Serial.println("Task 2: " + String(count++));
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void vTask3(void *pvParameters)
{
    int count1 = 5;

    while (1)
    {
        count1 += 5;
        Serial.println("Task 3: " + String(count1));

        UBaseType_t freeStack = uxTaskGetStackHighWaterMark(NULL);
        Serial.println("Task 3 stack livre: " + String(freeStack));

        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
