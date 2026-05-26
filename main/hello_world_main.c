#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_err.h"
#include "dht.h"

#define DHT_GPIO GPIO_NUM_0

void app_main(void)
{
   float humidity = 0;
   float temperature = 0;
   while (1){
    esp_err_t result = dht_read_float_data(
        DHT_TYPE_DHT11,
        DHT_GPIO,
        &humidity,
        &temperature
    );
    if (result == ESP_OK)
    {
        printf("Temp: %.1f C | Humid: %.1f %%\n",
        temperature,
        humidity);
    }
    else
    {
        printf("failed to read DHT. Error: %s\n",
        esp_err_to_name(result));
    }
    vTaskDelay(pdMS_TO_TICKS(2000));
   }
}
