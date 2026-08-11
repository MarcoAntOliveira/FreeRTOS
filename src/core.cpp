/************************************
 Exemplo para a criação de tasks no Freertos
 ************************************/

#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>


#define LED 2
/*variaveis para armazenamento do handle das tasks*/
TaskHandle_t task1Handle = NULL;
TaskHandle_t task2Handle = NULL;
TaskHandle_t task3Handle = NULL;

void vTask1(void *pvParameters);
void vTask2(void *pvParameters);
void vTask3(void *pvParameters);
int valor = 500;
int valor1 = 500;
void setup() {
    Serial.begin(115200);
    xTaskCreatePinnedToCore(
        vTask1,          /* Function that implements the task. */
        "TASK1",        /* Text name for the task. */
        configMINIMAL_STACK_SIZE,      /* Stack size in words, not bytes. */
        (void*)LED,           /* Parameter passed into the task. */
        1,              /* Priority at which the task is created. */
        &task1Handle,  /* Used to pass out the created task's handle. */
        APP_CPU_NUM);             /* Core where the task should run */

    xTaskCreatePinnedToCore(
        vTask2,          /* Function that implements the task. */
        "TASK2",        /* Text name for the task. */
        configMINIMAL_STACK_SIZE+1024,      /* Stack size in words, not bytes. */
        (void*)valor,           /* Parameter passed into the task. */
        1,              /* Priority at which the task is created. */
        &task2Handle,  /* Used to pass out the created task's handle. */
        PRO_CPU_NUM);             /* Core where the task should run */

    xTaskCreatePinnedToCore(
        vTask3,          /* Function that implements the task. */
        "TASK3",        /* Text name for the task. */
        configMINIMAL_STACK_SIZE+1024,      /* Stack size in words, not bytes. */
        (void*)valor1,           /* Parameter passed into the task. */
        1,              /* Priority at which the task is created. */
        &task3Handle,  /* Used to pass out the created task's handle. */
        APP_CPU_NUM);             /* Core where the task should run */
}

void loop() {
    vTaskDelay(3000);

}

void vTask1(void *pvParameters)
{   pinMode(LED, OUTPUT);
    while(1){
        digitalWrite(LED, !digitalRead(LED));
        vTaskDelay(pdMS_TO_TICKS(200));

    }
}

void vTask2(void *pvParameters){   
    int count = 0;
    while (1)
    {
        Serial.println("Task 2:" + String(count++));
         vTaskDelay(pdMS_TO_TICKS(1000));

}
}
void vTask3(void *pvParameters)
{   int count1 = 5;
    while (1)
    {
        Serial.println("Task 3:" + String(count1 = count1 + 5));
         vTaskDelay(pdMS_TO_TICKS(1000));

    }
}
