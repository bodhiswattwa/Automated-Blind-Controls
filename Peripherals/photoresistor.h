#include "mbed.h"
#include <stdio.h>
#include <string.h>

#define LIGHT PA_4      // pin for light sensor
AnalogIn light_sens(LIGHT); 

int check_photo_resistor()
{
    int val = 0;
    int intensity = 0;
    while (true) {
        val = light_sens.read_u16();    
        if(val > 50000){
            intensity = 5;
        } 
        else if (val > 40000 ){
            intensity = 4;
        } 
        else if(val > 30000){
            intensity = 3;
        } 
        else if(val > 20000){
            intensity = 2;
        } else {
           intensity = 1;
        }
    }
    return intensity;
}

