## Automated Blind Control System
### CSE 499: Independent Study on Embedded Controls
#### Collaborators: Avi Tombak, Bodhiswattwa Basu, Gabriel Yengle & Jesse Both

## About the Project
A typical household loses about 10% of its heat through its windows. In an industrial building, the amount of heat energy loss would be at least thrice the amount. To counteract this loss of heat energy, heater and air ventilation systems produce more heat. This energy inefficiency could be cut down sufficiently with smart blind control. The embedded control system will take into account the amount of transient light available and the external temperature to deduce if the blinds need to be drawn or not. 

## Key Terminology
**Embedded Control Systems:** An embedded control system is a microcontroller or microprocessor based system which is designed to perform a specific task or set of tasks. It manages, commands, or regulates the behavior of other devices or peripherals using control loops. 

**Real-Time Operating System:** RTOS, or commonly known as Real-Time Operating System, is a software component that rapidly switches between tasks, giving the impression that multiple programs are being executed at the same time on a single processing core.

**Proportional, Integral and Differential Controller:** PID or a Proportional, Integral and Differential Controller sets to a certain reference as preferred ambient lighting in a room, thereby letting the controller adjust the blinds towards that reference value while conditions outside and inside change during the day. The controller regulates the light that is let through the blind based on a predefined reference value chosen as the amount of indoor lighting.

## Design Process

The microcontroller that used for all of the functionalities is the **STM32 L4R5ZI Nucleo-144**.

**Input Peripherals:** 
<ul> 
<li> **A photoresistor or a light-dependent resistor** decreases the resistance with respect to the level of luminosity on the component’s sensitive surface. </li>

<li> **A temperature and humidity sensor** measures the temperature of the surrounding area. The control system depends on the feedback of the DHT11. </li>
</ul>

**Output Peripherals:** 
<ul> 
<li> A stepper motor, also commonly known as a step motor or stepping motor, is a DC electric motor that divides a full rotation into a number of equal steps. </li>

<li> LED 7-segment display is used to determine the degree of  closed or opened the blinds are. </li>
</ul>

## More on the PID

By setting the 𝑲_𝒑 as 1.0, we reduce the rise time significantly and steady-state error of the system. However, this increases the overshoot of the system.

By setting the 𝑲_𝒊 as 1.0, again, we reduce the rise time substantially and completely eliminate the steady-state error. However, this makes the transient response and overshooting worse.

By setting the 𝑲_𝒅 as 2.0, we combat the undesirable transient response time and overshooting by making this value higher, which only results in a small change in the rise time.





