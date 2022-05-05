// File Last Updated: 04/14/2022
// File Name: stepper_test.cpp
// Authors: Gabriel Yengle, Avi Tombak, Jesse Both and Bodhiswattwa Basu
// File Description: The following file is the file required to test the stepper motor. 
// File Functions and Returned Values:
//      1. main() -> TBD
// File Inclusions: 
//      1. mbed.h

#include "mbed.h"
#include "stepper.h"

Stepper::Stepper(PinName const &blue, PinName const &pink, PinName const &yellow, PinName const &orange) :
                            _blue(blue), _pink(pink), _yellow(yellow), _orange(orange) {
    _mode = 0;
    _dir = 0;
    _DLY = 5000;
}

/* enter mode in the following line
// 0 for wave drive, 1 for full step, 2 for half step

//enter dir = 0 for anticlockwise rotation, dir = 1 for clockwise rotation*/
void Stepper::step_rot(int mode, int dir) 
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
        printf("Invalid mode, Motor idle \n\r");
        motor_idle();
    }
}

// set DLY
void Stepper::set_dly(int dly){
    _DLY = dly;
}

// function for wave drive in anticlockwise direction
void Stepper::wave_anticlockwise()
{
    _blue = 0;
    _pink = 0;
    _yellow = 0;
    _orange = 1;
    wait_us(_DLY);
        
    _blue = 0;
    _pink = 0;
    _yellow = 1;
    _orange = 0;
    wait_us(_DLY);
        
    _blue = 0;
    _pink = 1;
    _yellow = 0;
    _orange = 0;
    wait_us(_DLY);
        
    _blue = 1;
    _pink = 0;
    _yellow = 0;
    _orange = 0;
    wait_us(_DLY);
}
 
// function for full step in anticlockwise direction
void Stepper::fullstep_anticlockwise()
{
    _blue = 0;
    _pink = 0;
    _yellow = 1;
    _orange = 1;
    wait_us(_DLY);
        
    _blue = 0;
    _pink = 1;
    _yellow = 1;
    _orange = 0;
    wait_us(_DLY);
        
    _blue = 1;
    _pink = 1;
    _yellow = 0;
    _orange = 0;
    wait_us(_DLY);
        
    _blue = 1;
    _pink = 0;
    _yellow = 0;
    _orange = 1;
    wait_us(_DLY);  
}
 
// function for half step in anticlockwise direction
void Stepper::halfstep_anticlockwise()
{
    _blue = 0;
    _pink = 0;
    _yellow = 0;
    _orange = 1;
    wait_us(_DLY);
        
    _blue = 0;
    _pink = 0;
    _yellow = 1;
    _orange = 1;
    wait_us(_DLY);
        
    _blue = 0;
    _pink = 0;
    _yellow = 1;
    _orange = 0;
    wait_us(_DLY);
        
    _blue = 0;
    _pink = 1;
    _yellow = 1;
    _orange = 0;
    wait_us(_DLY);
        
    _blue = 0;
    _pink = 1;
    _yellow = 0;
    _orange = 0;
    wait_us(_DLY);
        
    _blue = 1;
    _pink = 1;
    _yellow = 0;
    _orange = 0;
    wait_us(_DLY);
        
    _blue = 1;
    _pink = 0;
    _yellow = 0;
    _orange = 0;
    wait_us(_DLY);
        
    _blue = 1;
    _pink = 0;
    _yellow = 0;
    _orange = 1;
    wait_us(_DLY);
    
}
 
// function for wave drive in clockwise direction
void Stepper::wave_clockwise()
{
    _blue = 1;
    _pink = 0;
    _yellow = 0;
    _orange = 0;
    wait_us(_DLY);
        
    _blue = 0;
    _pink = 1;
    _yellow = 0;
    _orange = 0;
    wait_us(_DLY);
        
    _blue = 0;
    _pink = 0;
    _yellow = 1;
    _orange = 0;
    wait_us(_DLY);
        
    _blue = 0;
    _pink = 0;
    _yellow = 0;
    _orange = 1;
    wait_us(_DLY);
}
 
// function for full step in clockwise direction
void Stepper::fullstep_clockwise()
{                
    _blue = 1;
    _pink = 0;
    _yellow = 0;
    _orange = 1;
    wait_us(_DLY);
        
    _blue = 1;
    _pink = 1;
    _yellow = 0;
    _orange = 0;
    wait_us(_DLY);
        
    _blue = 0;
    _pink = 1;
    _yellow = 1;
    _orange = 0;
    wait_us(_DLY);
        
    _blue = 0;
    _pink = 0;
    _yellow = 1;
    _orange = 1;
    wait_us(_DLY);  
}
 
void Stepper::halfstep_clockwise(void)
{
    halfstep_clockwise();
    _blue = 0;
    _pink = 0;
    _yellow = 0;
    _orange = 1;
    wait_us(_DLY);
        
    _blue = 1;
    _pink = 0;
    _yellow = 0;
    _orange = 1;
    wait_us(_DLY);
        
    _blue = 0;
    _pink = 0;
    _yellow = 1;
    _orange = 0;
    wait_us(_DLY);
        
    _blue = 1;
    _pink = 1;
    _yellow = 0;
    _orange = 0;
    wait_us(_DLY);
        
    _blue = 0;
    _pink = 1;
    _yellow = 0;
    _orange = 0;
    wait_us(_DLY);
        
    _blue = 0;
    _pink = 1;
    _yellow = 1;
    _orange = 0;
    wait_us(_DLY);
        
    _blue = 1;
    _pink = 0;
    _yellow = 0;
    _orange = 0;
    wait_us(_DLY);
        
    _blue = 0;
    _pink = 0;
    _yellow = 1;
    _orange = 1;
    wait_us(_DLY);
}
 
void Stepper::motor_idle(void)
{
    _blue = 0;
    _pink = 0;
    _yellow = 0;
    _orange = 0;
    wait_us(_DLY); 
}