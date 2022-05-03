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

#include <iterator>
#include <string.h>
#include <stdio.h>
#include <iostream>

#include "mbed.h"
#include "PinNames.h"

#include "DHT.h"
#include "mbed_thread.h"
#include "stepper.h"
#include "photoresistor.cpp"

#define DHT PA_3
#define LIGHT PA_4      // pin for light sensor

float get_steps(int, float);
float update_step(int, int);


DHT11 dht(DHT);
//Photoresistor light(LIGHT);
AnalogIn light(LIGHT);
int main()
{
    int prev_step = 0;
    int steps = 0;
    int step_size;
    float step_get;
    while (true) {
        
        // update blind positions -> open = 0 (full step = 0), open-ish (full step = 1, half step = 1), halfway (step = 3, half step = 1), closed-ish (steps = 5, half = 1), closed (step = 7)
        step_test(0, 0);
        // step_get = get_steps(light.get_intensity(), dht.getCelsius());
        // std::cout << "light_get = " << light.get_intensity() << std::endl; 
        step_get = light.read_u16();
        std::cout << "light_get = " << step_get << std::endl;
        if(step_get < 25 && step_get > 20){
            step_size = 14;
        }else if(step_get < 20 && step_get > 15){
            step_size = 11;
        }else if(step_get < 15 && step_get > 10){
            step_size = 7;
        }else if(step_get < 10 && step_get > 5){
            step_size = 3;
        }else{
            step_size = 0;
        }
        steps = update_step(step_size, prev_step);
        while(steps > 0){
            steps--;
            step_test(2, 1);
        }
        while(steps < 0){
            steps++;
            step_test(2, 0);
        }

    thread_sleep_for(500);
    }

}

float get_steps(int light_int, float temp){
    // std::cout << "light intensity = " << light_int << std::endl; 
    // std::cout << "temp = " << temp << std::endl; 

    return light_int * (temp/7.0);
}

float update_step(int current, int prev){
    return current - prev;
}


