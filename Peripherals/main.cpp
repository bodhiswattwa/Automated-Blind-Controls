// File Name: main.cpp
// File Last Updated: 04/14/2022
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


#include "mbed.h"
#include <stdio.h>
#include <string.h>
#include "DHT.h"
#include "PinNames.h"

#include "stepper_test.h"

#define DHTC PA_3
#define LIGHT PA_4      // pin for light sensor

DHT11 dht(PA_3);
AnalogIn light_sens(LIGHT); 


// main() runs in its own thread in the OS
int main()
{
    int val = 0;
    int intensity = 0;
    step_test(0, 0);
    while (true) {
        printf("here\n");
        fullstep_anticlockwise();
        // printf("%f\n", dht.getFahrenheit());
        //printf("%d\n", val);
    }
}

