// File Name: main.cpp
// File Last Updated: 05/02/2022
// Authors: Gabriel Yengle, Avi Tombak, Jesse Both and Bodhiswattwa Basu
// File Description: The following file is the main file required to read from the sensors and determine the output of actuators to control the system. 
// File Functions and Returned Values:
//      1. main -> TBD
// File Inclusions: 
//      1. DHT.h
//      2. PinNames.h
//      3. mbed.h
//      4. stdio.h
//      5. string.h

#include <string.h>
#include <stdio.h>
#include <iostream>

#include "mbed.h"
#include "PinNames.h"

#include "DHT.h"
#include "stepper.h"
#include "photoresistor.h"

#define DHT PA_3
#define LIGHT PA_4      // pin for light sensor

DHT11 dht(DHT);
Photoresistor light(LIGHT);

int main()
{
    while (true) {
        step_test(2, 0);

        printf("%d\n", light.get_intensity());
    }
}

