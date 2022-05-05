// File Name: DHT.cpp
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

#include "DHT.h"
 
#define LOOP 10000
DHT11::DHT11(PinName const &p) : _pin(p) {
    // Set creation time so we can make 
    // sure we pause at least 1 second for 
    // startup.
    _timer.start();
    _temperature = 0; //default unit of Celcius 
    _humidity = 0;
    _error = false;
}

int DHT11::read() {
    // can not read more frequent than every 2 seconds
  
    // BUFFER TO RECEIVE
    uint8_t bits[5]; // DHT11 is a 40 bit signal, grouped in 5 bytes, each byte has own purpose
    uint8_t cnt = 7; //byte bit tracker
    uint8_t idx = 0; // bit set tracking
    //read in MSB to LSB 
 
    // EMPTY BUFFER
    for (int i=0; i< 5; i++) bits[i] = 0;
    
    // Verify sensor settled after boot
    while(_timer.elapsed_time().count() < 1500) {}
    _timer.stop();
 
    // Notify it we are ready to read
    _pin.output();
    _pin = 0;
    thread_sleep_for(18);
    _pin = 1;
    wait_us(40);
    _pin.input();
 
    // ACKNOWLEDGE or TIMEOUT
    unsigned int loopCnt = LOOP;
    while(_pin == 0)
        if (loopCnt-- == 0) {
            _error = true;
            return DHTLIB_ERROR_TIMEOUT;
        }
 
    loopCnt = LOOP;
    while(_pin == 1)
        if (loopCnt-- == 0) {
            _error = true;
            return DHTLIB_ERROR_TIMEOUT;
        }
 
    // READ OUTPUT - 40 BITS => 5 BYTES or TIMEOUT
    for (int i=0; i<40; i++)
    {
        loopCnt = LOOP;
        while(_pin == 0)
            if (loopCnt-- == 0) {
                _error = true;
                return DHTLIB_ERROR_TIMEOUT;
            }
 
        //unsigned long t = micros();
        Timer t;
        t. start();
 
        loopCnt = LOOP;
        while(_pin == 1) //track how long value is 1
            if (loopCnt-- == 0) {
                _error = true;
                return DHTLIB_ERROR_TIMEOUT;
            }

        //26-30us is 0, ~70us is 1, 40 is a good sample point
        if (t.elapsed_time().count() > 40) bits[idx] |= (1 << cnt);
        if (cnt == 0)   // next byte?
        {
            cnt = 7;    // restart at MSB
            idx++;      // next byte!
        }
        else cnt--;
    }
 
    // WRITE TO RIGHT VARS
    // as bits[1] and bits[3] are allways zero they are omitted in formulas.
    _humidity    = bits[0];
    _temperature = bits[2];
    uint8_t sum = bits[0] + bits[2];  
 
    if (bits[4] != sum) {
        _error = false;
        printf("\nChecksum: Temperature may be incorrect.\nTemperature: %d\nHumidity: %d\nSum: %d\n\n", _temperature, _humidity, sum);
        return DHTLIB_ERROR_CHECKSUM;
    }
    _error = false;
    return DHTLIB_OK;
}
 
float DHT11::getFahrenheit() { //performs C to F conversion
    return((_temperature * 1.8) + 32);
}
 
int DHT11::getCelsius() {
    return(_temperature);
}
int DHT11::getHumidity() {
    return(_humidity);
}

bool DHT11::getError(){
    return _error;
}