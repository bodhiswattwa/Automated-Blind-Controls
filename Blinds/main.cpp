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

#include "mbed.h"
#include "PinNames.h"

#include "DHT.h"
#include "mbed_thread.h"
#include "stepper.h"
#include "photoresistor.h"

#define DHT PA_3        // pin for DHT11
#define LIGHT PA_4      // pin for light sensor
#define IN1 PC_6
#define IN2 PB_15
#define IN3 PB_13
#define IN4 PB_12

#define MODE 0      // TODO: Which mode?
#define OPEN 1      // TODO: figure out which is open and close
#define CLOSE 0

DHT11 dht(DHT);
Photoresistor light(LIGHT);
Stepper stepper(IN1, IN2, IN3, IN4);

float get_steps(int, float);
float update_step(int, int);

int main()
{

    int prev_step = 0;
    int steps = 0;
    int step_size;
    float step_get;
    while (true) {
        dht.read();
        
        /* update blind positions -> 
                                    - open = 0 (full step = 0) 
                                    - open-ish (full step = 1, half step = 1)
                                    - halfway (step = 3, half step = 1)
                                    - closed-ish (steps = 5, half = 1) 
                                    - closed (step = 7)
        */
        step_get = get_steps(light.get_intensity(), dht.getCelsius());
        
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
            stepper.step_rot(MODE, CLOSE);
        }
        while(steps < 0){
            steps++;
            stepper.step_rot(MODE, OPEN);
        }

        thread_sleep_for(500);
    }

}

float get_steps(int light_int, float temp){
    return (float)light_int * (temp/7.0);
}

float update_step(int current, int prev){
    return current - prev;
}


