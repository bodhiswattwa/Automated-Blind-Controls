// File Name: phtoresistor.cpp
// File Last Updated: 04/14/2022
// Authors: Gabriel Yengle, Avi Tombak, Jesse Both and Bodhiswattwa Basu
// File Description: The following file is the file required to read from the DHT11 sensor and get appropriate readings, like temperature (degrees Fahrenheit or Celsius) and humidity.
// File Functions and Returned Values:
//      1. read() -> Initiates temperature and humidity values.
//      2. getFahrenheit() -> Temperature in Fahrenheit.
//      3. getCelsius() -> Temperature in Celsius.
//      4. getHumidity() -> Humidity level. 
// File Inclusions: 
//      1. DHT.h


#include "photoresistor.h"
 
Photoresistor::Photoresistor(PinName const &p) : _pin(p) {
    _light = 0; //default unit of Celcius 
    _intensity = 0;
}
 
int Photoresistor::read() { //performs C to F conversion
    _light = _pin.read_u16();
    return _light;
}
 
int Photoresistor::get_intensity() {
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