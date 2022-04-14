

// #include "mbed.h"

 
// #define DLY 1  // delay in seconds
 
// DigitalOut blue(PB_12);
// DigitalOut pink(PB_13);
// DigitalOut yellow(PB_15);
// DigitalOut orange(PC_6);

// //variable
// static int mode = 0;
// static int dir = 0;
 
// void wave_anticlockwise(void);
// void fullstep_anticlockwise(void);
// void halfstep_anticlockwise(void);
 
// void wave_clockwise(void);
// void fullstep_clockwise(void);
// void halfstep_clockwise(void);
 
// void motor_idle(void);
 
// int main() 
// {
    
//     // enter mode in the following line
//     // 0 for wave drive, 1 for full step, 2 for half step
    
//     mode = 0;
    
//     //enter dir = 0 for anticlockwise rotation, dir = 1 for clockwise rotation
//     dir = 0;
    
//     printf("\n\r");
//     printf("****** Stepper Motor starting ******* \n\r");
//     printf("Mode = %d  Direction = %d  \n\r", mode, dir);
    
//     while (true) 
//     {
//         if (dir == 0)
//         {
//             printf("Motor in anticlockwise rotation\n\r");
//             // wave drive
//             if (mode == 0)  
//             {
//                 wave_anticlockwise();
//             }
        
//             // full step
//             else if (mode == 1)
//             {
//                 fullstep_anticlockwise();
//             }
        
//             // half step
//             else if (mode == 2)
//             {
//                 halfstep_anticlockwise();
//             }
//             else 
//             {
//                 printf("Invalid mode, Motor idle \n\r");
//                 motor_idle();
//             }
//         }
        
//         else if (dir == 1)
//         {
//             printf("Motor in clockwise rotation \n\r");
//             // wave drive
//             if (mode == 0)  
//             {
//                 wave_clockwise();
//             }
        
//             // full step
//             else if (mode == 1)
//             {
//                 fullstep_clockwise();
//             }
        
//             // half step
//             else if (mode == 2)
//             {
//                 halfstep_clockwise();
//             }
            
//             else 
//             {
//                 printf("Invalid mode, Motor idle \n\r");
//                 motor_idle(); 
//             }
            
//         }
        
//         else
//         {
//             printf("Invalid direction, Motor idle \n\r");
//             motor_idle();
//         }
        
//     }
// }
 
// // function for wave drive in anticlockwise direction
// void wave_anticlockwise()
// {
//     printf("Motor in wave drive \n\r");
//     blue = 0;
//     pink = 0;
//     yellow = 0;
//     orange = 1;
//     wait_us(DLY);
        
//     blue = 0;
//     pink = 0;
//     yellow = 1;
//     orange = 0;
//     wait_us(DLY);
        
//     blue = 0;
//     pink = 1;
//     yellow = 0;
//     orange = 0;
//     wait_us(DLY);
        
//     blue = 1;
//     pink = 0;
//     yellow = 0;
//     orange = 0;
//     wait_us(DLY);
// }
 
// // function for full step in anticlockwise direction
// void fullstep_anticlockwise()
// {
//     printf("Motor in full step \n\r");
//     blue = 0;
//     pink = 0;
//     yellow = 1;
//     orange = 1;
//     wait_us(DLY);
        
//     blue = 0;
//     pink = 1;
//     yellow = 1;
//     orange = 0;
//     wait_us(DLY);
        
//     blue = 1;
//     pink = 1;
//     yellow = 0;
//     orange = 0;
//     wait_us(DLY);
        
//     blue = 1;
//     pink = 0;
//     yellow = 0;
//     orange = 1;
//     wait_us(DLY);  
// }
 
// // function for half step in anticlockwise direction
// void halfstep_anticlockwise()
// {
//     printf("Motor in half step \n\r");
//     blue = 0;
//     pink = 0;
//     yellow = 0;
//     orange = 1;
//     wait_us(DLY);
        
//     blue = 0;
//     pink = 0;
//     yellow = 1;
//     orange = 1;
//     wait_us(DLY);
        
//     blue = 0;
//     pink = 0;
//     yellow = 1;
//     orange = 0;
//     wait_us(DLY);
        
//     blue = 0;
//     pink = 1;
//     yellow = 1;
//     orange = 0;
//     wait_us(DLY);
        
//     blue = 0;
//     pink = 1;
//     yellow = 0;
//     orange = 0;
//     wait_us(DLY);
        
//     blue = 1;
//     pink = 1;
//     yellow = 0;
//     orange = 0;
//     wait_us(DLY);
        
//     blue = 1;
//     pink = 0;
//     yellow = 0;
//     orange = 0;
//     wait_us(DLY);
        
//     blue = 1;
//     pink = 0;
//     yellow = 0;
//     orange = 1;
//     wait_us(DLY);
    
// }
 
// // function for wave drive in clockwise direction
// void wave_clockwise()
// {
//     printf("Motor in wave drive \n\r");
//     blue = 1;
//     pink = 0;
//     yellow = 0;
//     orange = 0;
//     wait_us(DLY);
        
//     blue = 0;
//     pink = 1;
//     yellow = 0;
//     orange = 0;
//     wait_us(DLY);
        
//     blue = 0;
//     pink = 0;
//     yellow = 1;
//     orange = 0;
//     wait_us(DLY);
        
//     blue = 0;
//     pink = 0;
//     yellow = 0;
//     orange = 1;
//     wait_us(DLY);
// }
 
// // function for full step in clockwise direction
// void fullstep_clockwise()
// {
//     printf("Motor in full step \n\r");
                
//     blue = 1;
//     pink = 0;
//     yellow = 0;
//     orange = 1;
//     wait_us(DLY);
        
//     blue = 1;
//     pink = 1;
//     yellow = 0;
//     orange = 0;
//     wait_us(DLY);
        
//     blue = 0;
//     pink = 1;
//     yellow = 1;
//     orange = 0;
//     wait_us(DLY);
        
//     blue = 0;
//     pink = 0;
//     yellow = 1;
//     orange = 1;
//     wait_us(DLY);  
// }
 
// void halfstep_clockwise(void)
// {
//     halfstep_clockwise();
//     printf("Motor in half step \n\r");
//     blue = 0;
//     pink = 0;
//     yellow = 0;
//     orange = 1;
//     wait_us(DLY);
        
//     blue = 1;
//     pink = 0;
//     yellow = 0;
//     orange = 1;
//     wait_us(DLY);
        
//     blue = 0;
//     pink = 0;
//     yellow = 1;
//     orange = 0;
//     wait_us(DLY);
        
//     blue = 1;
//     pink = 1;
//     yellow = 0;
//     orange = 0;
//     wait_us(DLY);
        
//     blue = 0;
//     pink = 1;
//     yellow = 0;
//     orange = 0;
//     wait_us(DLY);
        
//     blue = 0;
//     pink = 1;
//     yellow = 1;
//     orange = 0;
//     wait_us(DLY);
        
//     blue = 1;
//     pink = 0;
//     yellow = 0;
//     orange = 0;
//     wait_us(DLY);
        
//     blue = 0;
//     pink = 0;
//     yellow = 1;
//     orange = 1;
//     wait_us(DLY);
// }
 
// void motor_idle(void)
// {
//     blue = 0;
//     pink = 0;
//     yellow = 0;
//     orange = 0;
//     wait_us(DLY); 
    
// }