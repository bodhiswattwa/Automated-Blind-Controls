// File Name: photoresistor.h
// File Last Updated: 05/03/2022
// Authors: Gabriel Yengle, Avi Tombak, Jesse Both and Bodhiswattwa Basu
// File Description: 
// File Functions and Returned Values:
//      1. 
// File Inclusions: 
//      1. mbed.h

#ifndef PHOTORESISTOR_H
#define PHOTORESISTOR_H
 
#include "mbed.h"
 
class Photoresistor
{
public:
    Photoresistor(PinName const &p);
    int read();
    int intensity();
 
private:
    int _light;
    int _intensity;
    AnalogIn _pin;
};
 
#endif
