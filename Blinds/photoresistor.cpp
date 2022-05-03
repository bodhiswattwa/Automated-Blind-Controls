// File Name: photoresistor.cpp
// File Last Updated: 04/14/2022
// Authors: Gabriel Yengle, Avi Tombak, Jesse Both and Bodhiswattwa Basu
// File Description: The following file is the file required to read from the photoresistor and get the intensity of light readings.
// File Functions and Returned Values:
//      1. check_photo_resistor() -> intensity of light.
// File Inclusions: 
//      1. stdio.h
//      2. mbed.h
//      3. string.h

#include "mbed.h"
#include <stdio.h>
#include <string.h>

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

