#include "mbed.h"
#include <stdio.h>
#include <string.h>
#include "DHT.h"
#include "PinNames.h"

#include "stepper_test.h"

#define DHTC PA_3
#define LIGHT PA_4      // pin for light sensor

DHT11 dht(PA_3);
AnalogIn light_sens(LIGHT); 

// main() runs in its own thread in the OS
int main()
{
    while (true) {

    }
}

