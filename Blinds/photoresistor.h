// File Name: DHT.h
// File Last Updated: 04/14/2022
// Authors: Gabriel Yengle, Avi Tombak, Jesse Both and Bodhiswattwa Basu
// File Description: The following file is the file required to aid the reading from the DHT11 sensor to get appropriate readings, like temperature (degrees Fahrenheit or Celsius) and humidity.
// File Functions and Returned Values:
//      1. Class DHT11 -> read(); getFahrenheit(); getCelsius(); getHumidity();
// File Inclusions: 
//      1. mbed.h
 
#include "mbed.h"
 
class Photoresistor
{
public:
    
    Photoresistor(PinName const &p);
    int read();
    int get_intensity();
private:
    int _light = 0;    
    int _intensity = 0;
    
    AnalogIn _pin;
};
 