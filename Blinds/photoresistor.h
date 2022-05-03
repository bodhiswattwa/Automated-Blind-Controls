// File Name: photoresistor.h
// File Last Updated: 04/14/2022
// Authors: Gabriel Yengle, Avi Tombak, Jesse Both and Bodhiswattwa Basu
// File Description: The following file is the file required to read from the photoresistor and get the intensity of light readings.
// File Functions and Returned Values:
//      1. check_photo_resistor() -> intensity of light.
// File Inclusions: 
//      1. stdio.h
//      2. mbed.h
//      3. string.h

#include <stdio.h>
#include <string.h>

#include "mbed.h"

#define LIGHT PA_4      // pin for light sensor
AnalogIn light_sens(LIGHT); 

int check_photo_resistor();
