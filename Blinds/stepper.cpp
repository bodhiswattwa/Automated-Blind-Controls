// File Name: stepper_test.cpp
// File Last Updated: 04/14/2022
// Authors: Gabriel Yengle, Avi Tombak, Jesse Both and Bodhiswattwa Basu
// File Description: The following file is the file required to test the stepper motor. 
// File Functions and Returned Values:
//      1. main() -> TBD
// File Inclusions: 
//      1. mbed.h

#include "mbed.h"
#include "stepper.h"

#define DLY 25000
 
DigitalOut orange(PB_12);
DigitalOut yellow(PB_13);
DigitalOut pink(PB_15);
DigitalOut blue(PC_6);

//    Blue  = coil 1      Pink  = coil 2
//     Yellow = coil 3     Orange = coil 4

/* enter mode in the following line
// 0 for wave drive, 1 for full step, 2 for half step

//enter dir = 0 for anticlockwise rotation, dir = 1 for clockwise rotation*/
int step_test(int mode, int dir) 
{    
    while (true) 
    {
        if (dir == 0)
        {
            // wave drive
            if (mode == 0)  
            {
                wave_anticlockwise();
            }
        
            // full step
            else if (mode == 1)
            {
                fullstep_anticlockwise();
            }
        
            // half step
            else if (mode == 2)
            {
                halfstep_anticlockwise();
            }
            else 
            {
                printf("Invalid mode, Motor idle \n\r");
                motor_idle();
            }
        }
        
        else if (dir == 1)
        {
            printf("Motor in clockwise rotation \n\r");
            // wave drive
            if (mode == 0)  
            {
                wave_clockwise();
            }
        
            // full step
            else if (mode == 1)
            {
                fullstep_clockwise();
            }
        
            // half step
            else if (mode == 2)
            {
                halfstep_clockwise();
            }
            
            else 
            {
                printf("Invalid mode, Motor idle \n\r");
                motor_idle(); 
            }
            
        }
        
        else
        {
            printf("Invalid direction, Motor idle \n\r");
            motor_idle();
        }
        
    }
}
 
// function for wave drive in anticlockwise direction
void wave_anticlockwise()
{
    printf("Motor in wave drive \n\r");
    blue = 0;
    pink = 0;
    yellow = 0;
    orange = 1;
    wait_us(DLY);
        
    blue = 0;
    pink = 0;
    yellow = 1;
    orange = 0;
    wait_us(DLY);
        
    blue = 0;
    pink = 1;
    yellow = 0;
    orange = 0;
    wait_us(DLY);
        
    blue = 1;
    pink = 0;
    yellow = 0;
    orange = 0;
    wait_us(DLY);
}
 
// function for full step in anticlockwise direction
void fullstep_anticlockwise()
{
    blue = 0;
    pink = 0;
    yellow = 1;
    orange = 1;
    wait_us(DLY);
        
    blue = 0;
    pink = 1;
    yellow = 1;
    orange = 0;
    wait_us(DLY);
        
    blue = 1;
    pink = 1;
    yellow = 0;
    orange = 0;
    wait_us(DLY);
        
    blue = 1;
    pink = 0;
    yellow = 0;
    orange = 1;
    wait_us(DLY);  
}
 
// function for half step in anticlockwise direction
void halfstep_anticlockwise()
{
    blue = 0;
    pink = 0;
    yellow = 0;
    orange = 1;
    wait_us(DLY);
        
    blue = 0;
    pink = 0;
    yellow = 1;
    orange = 1;
    wait_us(DLY);
        
    blue = 0;
    pink = 0;
    yellow = 1;
    orange = 0;
    wait_us(DLY);
        
    blue = 0;
    pink = 1;
    yellow = 1;
    orange = 0;
    wait_us(DLY);
        
    blue = 0;
    pink = 1;
    yellow = 0;
    orange = 0;
    wait_us(DLY);
        
    blue = 1;
    pink = 1;
    yellow = 0;
    orange = 0;
    wait_us(DLY);
        
    blue = 1;
    pink = 0;
    yellow = 0;
    orange = 0;
    wait_us(DLY);
        
    blue = 1;
    pink = 0;
    yellow = 0;
    orange = 1;
    wait_us(DLY);
    
}
 
// function for wave drive in clockwise direction
void wave_clockwise()
{
    blue = 1;
    pink = 0;
    yellow = 0;
    orange = 0;
    wait_us(DLY);
        
    blue = 0;
    pink = 1;
    yellow = 0;
    orange = 0;
    wait_us(DLY);
        
    blue = 0;
    pink = 0;
    yellow = 1;
    orange = 0;
    wait_us(DLY);
        
    blue = 0;
    pink = 0;
    yellow = 0;
    orange = 1;
    wait_us(DLY);
}
 
// function for full step in clockwise direction
void fullstep_clockwise()
{                
    blue = 1;
    pink = 0;
    yellow = 0;
    orange = 1;
    wait_us(DLY);
        
    blue = 1;
    pink = 1;
    yellow = 0;
    orange = 0;
    wait_us(DLY);
        
    blue = 0;
    pink = 1;
    yellow = 1;
    orange = 0;
    wait_us(DLY);
        
    blue = 0;
    pink = 0;
    yellow = 1;
    orange = 1;
    wait_us(DLY);  
}
 
void halfstep_clockwise(void)
{
    halfstep_clockwise();
    blue = 0;
    pink = 0;
    yellow = 0;
    orange = 1;
    wait_us(DLY);
        
    blue = 1;
    pink = 0;
    yellow = 0;
    orange = 1;
    wait_us(DLY);
        
    blue = 0;
    pink = 0;
    yellow = 1;
    orange = 0;
    wait_us(DLY);
        
    blue = 1;
    pink = 1;
    yellow = 0;
    orange = 0;
    wait_us(DLY);
        
    blue = 0;
    pink = 1;
    yellow = 0;
    orange = 0;
    wait_us(DLY);
        
    blue = 0;
    pink = 1;
    yellow = 1;
    orange = 0;
    wait_us(DLY);
        
    blue = 1;
    pink = 0;
    yellow = 0;
    orange = 0;
    wait_us(DLY);
        
    blue = 0;
    pink = 0;
    yellow = 1;
    orange = 1;
    wait_us(DLY);
}
 
void motor_idle(void)
{
    blue = 0;
    pink = 0;
    yellow = 0;
    orange = 0;
    wait_us(DLY); 
}