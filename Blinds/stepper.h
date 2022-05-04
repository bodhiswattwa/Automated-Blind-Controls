#include "mbed.h"
 
class Stepper
{
public:
    
    //    Blue  = coil 1      Pink  = coil 2
    //    Yellow = coil 3     Orange = coil 4
    Stepper(PinName const &blue, PinName const &pink, PinName const &yellow, PinName const &orange);
    void step_rot(int mode , int dir);
    void set_dly(int dly);
    void wave_anticlockwise(void);
    void fullstep_anticlockwise(void);
    void halfstep_anticlockwise(void);
    
    void wave_clockwise(void);
    void fullstep_clockwise(void);
    void halfstep_clockwise(void);
    
    void motor_idle(void);
private:
    int _mode;    
    int _dir;
    int _DLY;

    DigitalOut _orange;
    DigitalOut _yellow;
    DigitalOut _pink;
    DigitalOut _blue;
};
 