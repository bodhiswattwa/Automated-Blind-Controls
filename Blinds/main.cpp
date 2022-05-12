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

#include "EventQueue.h"
#include "InterruptIn.h"
#include "mbed.h"
#include "PinNames.h"

#include "DHT.h"
#include "mbed_thread.h"
#include "stepper.h"
#include "photoresistor.h"

#define DHT PA_3        // pin for DHT11
#define LIGHT PA_5      // pin for light sensor
#define IN1_LEFT PC_6
#define IN2_LEFT PB_15
#define IN3_LEFT PB_13
#define IN4_LEFT PB_12

#define IN1_RIGHT PA_7
#define IN2_RIGHT PD_14
#define IN3_RIGHT PD_15
#define IN4_RIGHT PF_12

#define MODE 0           // TODO: Which mode?
#define OPEN_LEFT 1
#define CLOSE_LEFT 0
#define CLOSE_RIGHT 1
#define OPEN_RIGHT 0
#define STEP_MULT 1

#define SLEEP 1000

/* Event Queues */
EventQueue EQ(32 * EVENTS_EVENT_SIZE);                  // DHT11
EventQueue STEPPER_LEFT_EQ(1024 * EVENTS_EVENT_SIZE);     // Stepper Left
EventQueue STEPPER_RIGHT_EQ(1024 * EVENTS_EVENT_SIZE);    // Stepper Right

/* Interrupts */
InterruptIn button(BUTTON1);
DigitalOut LED(LED2);
DigitalOut LEDERR(LED3);

/* Timer interrupt for DHT */
Ticker DHT_READ;

/* Threads for each stepper */
Thread STEPPER_LEFT_THREAD;
Thread STEPPER_RIGHT_THREAD;
Thread EQ_THREAD;

/* Initialize Peripherals */
DHT11 dht(DHT);
Photoresistor light(LIGHT);
Stepper stepper_left(IN1_LEFT, IN2_LEFT, IN3_LEFT, IN4_LEFT);
Stepper stepper_right(IN1_RIGHT, IN2_RIGHT, IN3_RIGHT, IN4_RIGHT);


float get_steps(int, int);
int update_step(int, int);
void dht_reader();
void stepper_wrapper(Stepper step, int mode, int dir);
void reset(void);

int current_step;           // value to iterate steppers back to default state
bool reset_flag = false;    // flag to wait for another press
bool re_entry = true;


int main()
{
    /* setup button handler */
    button.mode(PullDown);
    button.rise(EQ.event(reset));
    LED = 0;
    LEDERR = 0;

    /* setup stepper threads and queues */
    STEPPER_LEFT_THREAD.start(callback(&STEPPER_LEFT_EQ, &EventQueue::dispatch_forever));
    STEPPER_RIGHT_THREAD.start(callback(&STEPPER_RIGHT_EQ, &EventQueue::dispatch_forever));

    /* general purpose queue */
    EQ_THREAD.start(callback(&EQ, &EventQueue::dispatch_forever));

    /* dht timer interrupt */
    DHT_READ.attach(EQ.event(dht_reader), 2s);

    dht.read();     // get initial value.

    int prev_step = 0;      // determine how far to rotate relative to last position
    int steps = 0;          // number of steps to rotate 
    int step_size;          // step size before calculation
    float step_get;         // normalized step to make light and temp at same scale


    current_step = 0;
    while (true) {
        prev_step = current_step;
        
        if(!dht.getError() && !reset_flag){
            step_get = get_steps(light.get_intensity(), dht.getCelsius());

            /* check to see if the reading is valid */
            if(!dht.isValid() || dht.getCelsius() == 0){
                LEDERR = 1;
                thread_sleep_for(SLEEP);
                continue;
            }
            else{
                LEDERR = 0;
            }

            /* convert values */
            if(step_get < 25 && step_get >= 20){
                step_size = 25;
            }else if(step_get < 20 && step_get >= 15){
                step_size = 50;
            }else if(step_get < 15 && step_get >= 10){
                step_size = 75;
            }else if(step_get < 10 && step_get >= 5){
                step_size = 100;
            }else{
                step_size = 0;
            }
            current_step = step_size;

            steps = update_step(step_size, prev_step);

            printf("Current Temp: %d\n", dht.getCelsius());
            printf("stepget Value: %f\n", step_get);        
            printf("stepsize = %d\n", steps);
            
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
        re_entry = true;
        thread_sleep_for(SLEEP);
    }


}


/* get light and temperature on same scale
      @param light_int: light intensity value
      @param temp: temperature in C
      @return light_int * (temp/7)
*/
float get_steps(int light_int, int temp){
    return (float)light_int * (temp/7.0);
}

/* get step relative to previous step 
    @param current: current step
    @param prev: previous step
    @return current - prev
*/
int update_step(int current, int prev){
    return ((current - prev) * STEP_MULT);
}

/* wrapper to read from dht11 */
void dht_reader(){
    dht.read();
}

/* stepper wrapper to rotate stepper 
    @param step: Stepper class 
    @param mode: type of rotation
    @param dir: direction for rotation
*/
void stepper_wrapper(Stepper step, int mode, int dir){
    step.step_rot(mode, dir);
}

/* reset the steppers to the default state */
void reset(){
    if(re_entry){
        reset_flag = !reset_flag;
        LED = !LED;    
        printf("Reset: %d\n", reset_flag);
        if(reset_flag){
            re_entry = false;
            while(current_step < 0){
                current_step++;
                STEPPER_LEFT_EQ.call(stepper_wrapper, stepper_left, MODE, CLOSE_LEFT);
                STEPPER_RIGHT_EQ.call(stepper_wrapper, stepper_right, MODE, CLOSE_RIGHT);
            }
            while(current_step > 0){
                current_step--;
                STEPPER_LEFT_EQ.call(stepper_wrapper, stepper_left, MODE, OPEN_LEFT);
                STEPPER_RIGHT_EQ.call(stepper_wrapper, stepper_right, MODE, OPEN_RIGHT);
            }
        }
    }
}

