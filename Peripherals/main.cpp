#include "mbed.h"
#include <stdio.h>
#include <string.h>
#include "DHT.h"
#include "PinNames.h"

#define DHTC PA_3
#define LIGHT PA_4      // pin for light sensor

DHT::DHT(PA_3);
AnalogIn light_sens(LIGHT); 


// main() runs in its own thread in the OS
int main()
{
    int val = 0;
    int intensity = 0;
    while (true) {
        printf("%f\n", DHT::ReadTemperature());
        //printf("%d\n", val);
    }
}

