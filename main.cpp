/* mbed Microcontroller Library
 * Copyright (c) 2021 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

#define WAIT_TIME_MS 5000
DigitalOut led1(P0_5);

int main()
{

    while (true)
    {
        led1 = !led1;
        thread_sleep_for(WAIT_TIME_MS);
    }
}