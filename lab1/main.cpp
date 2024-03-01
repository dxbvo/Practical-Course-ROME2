/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

// Blinking rate in milliseconds
#define BLINKING_RATE    100ms

int main() {
    // Initialise the digital pin LED1 as an output
    DigitalOut led(LED1);
    DigitalOut led0(PD_4); 
    DigitalOut led1(PD_3); 
    DigitalOut led2(PD_6); 
    DigitalOut led3(PD_2); 
    DigitalOut led4(PD_7); 
    DigitalOut led5(PD_5);

    // Kreieren der Ein- und Ausgangsobjekte DigitalOut enable(PG_1);
    AnalogIn distance(PA_0); 
    DigitalOut enable(PG_1); 
    DigitalOut bit0(PF_0);
    DigitalOut bit1(PF_1);
    DigitalOut bit2(PF_2);

    while (true) {
        led0 = 1;
        ThisThread::sleep_for(BLINKING_RATE);
        led0 = 0;

        led1 = 1;
        ThisThread::sleep_for(BLINKING_RATE);
        led1 = 0;

        led2 = 1;
        ThisThread::sleep_for(BLINKING_RATE);
        led2 = 0;

        led3 = 1;
        ThisThread::sleep_for(BLINKING_RATE);
        led3 = 0;

        led4 = 1;
        ThisThread::sleep_for(BLINKING_RATE);
        led4 = 0;

        led5 = 1;
        ThisThread::sleep_for(BLINKING_RATE);
        led5 = 0;

        // Schaltet die Sensoren ein
        enable = 1; 
    
        // Wahl des Sensors mit dem Multiplexer (hier: Sensor vorne)
        bit0 = 1;
        bit1 = 1;
        bit2 = 0;
    
        // Lesen der Distanz in [m] und Umrechnung
        float d = 0.09f / (distance + 0.001f) - 0.03f;

        printf("distance=%dmm\r\n", (int)(1000.0f*d));
    }
}


