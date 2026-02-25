/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define LED_PIN 18
#define BUTTON_PIN 19
#define LED_MOTOR_1 10
#define LED_MOTOR_2 11
#define LED_MOTOR_3 12
#define LED_MOTOR_4 13

int main()
{
    stdio_init_all();
    gpio_init(LED_PIN);
    gpio_init(BUTTON_PIN);
    gpio_init(LED_MOTOR_1);
    gpio_init(LED_MOTOR_2);
    gpio_init(LED_MOTOR_3);
    gpio_init(LED_MOTOR_4);

    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_set_dir(LED_MOTOR_1, GPIO_OUT);
    gpio_set_dir(LED_MOTOR_2, GPIO_OUT);
    gpio_set_dir(LED_MOTOR_3, GPIO_OUT);
    gpio_set_dir(LED_MOTOR_4, GPIO_OUT);

    gpio_put(LED_PIN, 0);


    gpio_pull_up(BUTTON_PIN);
    while (true)
    {
        if (gpio_get(BUTTON_PIN) == 0)
        {
            gpio_put(LED_PIN, 1);
            printf("Button pressed!\n");
            for (int i = 0; i < 512; i++)
            {
                gpio_put(LED_MOTOR_1, 1);
                sleep_ms(5);
                gpio_put(LED_MOTOR_1, 0);
                gpio_put(LED_MOTOR_2, 1);
                sleep_ms(5);
                gpio_put(LED_MOTOR_2, 0);
                gpio_put(LED_MOTOR_3, 1);
                sleep_ms(5);
                gpio_put(LED_MOTOR_3, 0);
                gpio_put(LED_MOTOR_4, 1);
                sleep_ms(5);
                gpio_put(LED_MOTOR_4, 0);
                sleep_ms(5);
            }
        }
        else
        {
            gpio_put(LED_PIN, 0);
        }
    
    }

}
