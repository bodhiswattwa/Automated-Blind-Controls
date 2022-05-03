// File Name: photoresistor.cpp
// File Last Updated: 05/03/2022
// Authors: Gabriel Yengle, Avi Tombak, Jesse Both and Bodhiswattwa Basu
// File Description: 
// File Functions and Returned Values:

// File Inclusions: 
//      1. 


#include "photoresistor.h"
 
Photoresistor::Photoresistor(PinName const &p) : _pin(p) {
    _light = 0; //default unit of Celcius 
    _intensity = 0;
}

int Photoresistor::read() {
    _light = _pin.read_u16();   
    return _light;
}

int Photoresistor::intensity() {
    read();
    if(_light > 50000){
        _intensity = 5;
    } 
    else if (_light > 40000 ){
        _intensity = 4;
    } 
    else if(_light > 30000){
        _intensity = 3;
    } 
    else if(_light > 20000){
        _intensity = 2;
    } else {
        _intensity = 1;
    }
    return _intensity;
}
