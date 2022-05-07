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
#define IN1_LEFT PC_6
#define IN2_LEFT PB_15
#define IN3_LEFT PB_13
#define IN4_LEFT PB_12

#define IN1_RIGHT PB_5
#define IN2_RIGHT PB_3
#define IN3_RIGHT PA_4
#define IN4_RIGHT PB_4

#define MODE 0           // TODO: Which mode?
#define OPEN_LEFT 1      // TODO: figure out which is open and close
#define CLOSE_RIGHT 0
#define OPEN_RIGHT 0
#define CLOSE_LEFT 1
#define STEP_MULT 5

#define DHT_DELAY 30

/* Event Queues */
EventQueue EQ(32 * EVENTS_EVENT_SIZE);                  // DHT11
EventQueue STEPPER_LEFT_EQ(32 * EVENTS_EVENT_SIZE);     // Stepper Left
EventQueue STEPPER_RIGHT_EQ(32 * EVENTS_EVENT_SIZE);    // Stepper Right

/* Timer interrupt for DHT */
Ticker DHT_READ;

/* Threads for each stepper */
Thread STEPPER_LEFT_THREAD;
Thread STEPPER_RIGHT_THREAD;

/* Initialize Peripherals */
DHT11 dht(DHT);
Photoresistor light(LIGHT);
Stepper stepper_left(IN1_LEFT, IN2_LEFT, IN3_LEFT, IN4_LEFT);
Stepper stepper_right(IN1_RIGHT, IN2_RIGHT, IN3_RIGHT, IN4_RIGHT);


float get_steps(int, int);
int update_step(int, int);
void dht_reader();
void stepper_wrapper(Stepper step, int mode, int dir);

int main()
{
    STEPPER_LEFT_THREAD.start(callback(&STEPPER_LEFT_EQ, &EventQueue::dispatch_forever));
    STEPPER_RIGHT_THREAD.start(callback(&STEPPER_RIGHT_EQ, &EventQueue::dispatch_forever));

    DHT_READ.attach(EQ.event(dht_reader), 2s);
    dht.read();
    int count = 0;
    int prev_step = 0;
    int steps = 0;
    int step_size;
    float step_get;
    while (true) {
        /* update blind positions -> 
                                    - open = 0 (full step = 0) 
                                    - open-ish (full step = 1, half step = 1)
                                    - halfway (step = 3, half step = 1)
                                    - closed-ish (steps = 5, half = 1) 
                                    - closed (step = 7)
        */

        if(!dht.getError()){
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
            if (steps != 0){
                printf("stepsize%d\n", steps);
            }
            prev_step = step_size;
            while(steps > 0){
                steps--;
                STEPPER_LEFT_EQ.call(stepper_wrapper, stepper_left, MODE, CLOSE_LEFT);
                STEPPER_RIGHT_EQ.call(stepper_wrapper, stepper_right, MODE, CLOSE_RIGHT);
            }
            while(steps < 0){
                steps++;
                STEPPER_LEFT_EQ.call(stepper_wrapper, stepper_left, MODE, OPEN_LEFT);
                STEPPER_RIGHT_EQ.call(stepper_wrapper, stepper_right, MODE, OPEN_RIGHT);
            }
        }
        EQ.dispatch_once();
        thread_sleep_for(500);
    }


}

float get_steps(int light_int, int temp){
    return (float)light_int * (temp/7.0);
}

int update_step(int current, int prev){
    return ((current - prev) * STEP_MULT);
}

void dht_reader(){
    dht.read();
}

void stepper_wrapper(Stepper step, int mode, int dir){
    step.step_rot(mode, dir);
}

