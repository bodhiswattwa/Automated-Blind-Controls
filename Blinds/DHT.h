// File Name: DHT.h
// File Last Updated: 04/14/2022
// Authors: Gabriel Yengle, Avi Tombak, Jesse Both and Bodhiswattwa Basu
// File Description: The following file is the file required to aid the reading from the DHT11 sensor to get appropriate readings, like temperature (degrees Fahrenheit or Celsius) and humidity.
// File Functions and Returned Values:
//      1. Class DHT11 -> read(); getFahrenheit(); getCelsius(); getHumidity();
// File Inclusions: 
//      1. mbed.h
 
#include "mbed.h"
 
#define DHTLIB_OK                0
#define DHTLIB_ERROR_CHECKSUM   -1
#define DHTLIB_ERROR_TIMEOUT    -2
 
/** Class for the DHT11 sensor.
 * 
 * Example:
 * @code
 * #include "mbed.h"
 * #include "DHT11.h"
 *
 * Serial pc(USBTX, USBRX);
 * DHT11 sensor(PTD7); //note this is from a different board
 * 
 * int main() {
 *     sensor.read()
 *     pc.printf("T: %f, H: %d\r\n", sensor.getFahrenheit(), sensor.getHumidity());
 * }
 * @endcode
 */
class DHT11
{
public:
    /** Construct the sensor object.
     *
     * @param pin PinName for the sensor pin.
     */
    DHT11(PinName const &p);
    
    /** Update the humidity and temp from the sensor.
     *
     * @returns
     *   0 on success, otherwise error.
     */
    int read();
    
    /** Get the temp(f) from the saved object.
     *
     * @returns
     *   Fahrenheit float
     */
    float getFahrenheit();
    
    /** Get the temp(c) from the saved object.
     *
     * @returns
     *   Celsius int
     */
    int getCelsius();
    
    /** Get the humidity from the saved object.
     *
     * @returns
     *   Humidity percent int
     */
    int getHumidity();
 
private:
    /// percentage of humidity
    int _humidity;
    /// celsius
    int _temperature;
    /// pin to read the sensor info on
    DigitalInOut _pin;
    /// times startup (must settle for at least a second)
    Timer _timer;
};
 