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

/*Prototípos das tasks*/
TaskHandle_t task1Handle = Null;
void vTask1(void *pvParameters);
void vTask2(void *pvParameters);


void setup() {
    
    xTaskCreate(vTask1, "TASK1", configMINIMAL_STACK_SIZE, NULL, 1, &taskslHandle);
    xTaskCreate(vTask1, "TASK1", configMINIMAL_STACK_SIZE + 1024, NULL, 1, &taskslHandle);
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

void vTask2(void *pvParameters)
{   int count = 0;
    while (1)
    {
        serial.println("Task 2:" + String(count++));
         vTaskDelay(pdMS_TO_TICKS(1000));

    }
    

}
