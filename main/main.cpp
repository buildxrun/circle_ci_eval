
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/spi_common.h"
#include "driver/spi_master.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "esp_err.h"
#include "sdkconfig.h"
#include "driver/uart.h"


extern "C" void app_main(void)
{
    gpio_set_direction(GPIO_NUM_32, GPIO_MODE_OUTPUT);
    gpio_set_level(GPIO_NUM_32, 0);
    vTaskDelay(10);
    gpio_set_level(GPIO_NUM_32, 1);
    vTaskDelay(10);

    while (true)
    {
        gpio_set_level(GPIO_NUM_32, 0);
        vTaskDelay(500 / portTICK_PERIOD_MS);

        gpio_set_level(GPIO_NUM_32, 1);
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}