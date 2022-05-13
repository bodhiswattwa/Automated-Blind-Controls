## Automated Blind Control System
### CSE 499: Independent Study on Embedded Controls
#### Contributors: Avi Tombak, Bodhiswattwa Basu, Gabriel Yengle & Jesse Both
------------------------------------------------------------------------------

#### Table of Contents  
* [About the Project](#about-the-project)  
* [Key Terminology](#key-terminology)  
* [Design Process](#design-process)   
* [Code and Functionality](#code-and-funcionality)    
* [More on the PID](#more-on-the-pid)     
* [Demo Design](#demo-design)     
* [Schematic](#schematic)     
* [Block Diagram and Preliminary Designs](#block-diagram-and-preliminary-designs)


### About the Project
<a name="About"></a>
------------------------------------------------------------------------------
A typical household loses about 10% of its heat through its windows. In an industrial building, the amount of heat energy loss would be at least thrice the amount. To counteract this loss of heat energy, heater and air ventilation systems produce more heat. This energy inefficiency could be cut down sufficiently with smart blind control. The embedded control system will take into account the amount of transient light available and the external temperature to deduce if the blinds need to be drawn or not. 

### Key Terminology
<a name="Terminology"></a>
------------------------------------------------------------------------------
**Embedded Control Systems:** An embedded control system is a microcontroller or microprocessor based system which is designed to perform a specific task or set of tasks. It manages, commands, or regulates the behavior of other devices or peripherals using control loops. 

**Real-Time Operating System:** RTOS, or commonly known as Real-Time Operating System, is a software component that rapidly switches between tasks, giving the impression that multiple programs are being executed at the same time on a single processing core.

**Proportional, Integral and Differential Controller:** PID or a Proportional, Integral and Differential Controller sets to a certain reference as preferred ambient lighting in a room, thereby letting the controller adjust the blinds towards that reference value while conditions outside and inside change during the day. The controller regulates the light that is let through the blind based on a predefined reference value chosen as the amount of indoor lighting.

### Design Process
<a name="Design"></a>
------------------------------------------------------------------------------

The microcontroller that used for all of the functionalities is the **STM32 L4R5ZI Nucleo-144**.

**Input Peripherals:** 
<ul> 
<li> <strong>A photoresistor or a light-dependent resistor </strong> decreases the resistance with respect to the level of luminosity on the component’s sensitive surface. </li>

<li> <strong>A temperature and humidity sensor</strong> measures the temperature of the surrounding area. The control system depends on the feedback of the DHT11. </li>
</ul>

**Output Peripherals:** 
<ul> 
<li> <strong>A stepper motor</strong>, also commonly known as a step motor or stepping motor, is a DC electric motor that divides a full rotation into a number of equal steps. </li>

<li> <strong>LED 7-segment display</strong> is used to determine the degree of  closed or opened the blinds are. </li>
</ul>

### More on the PID
------------------------------------------------------------------------------

By setting the 𝑲_𝒑 as 1.0, we reduce the rise time significantly and steady-state error of the system. However, this increases the overshoot of the system.

By setting the 𝑲_𝒊 as 1.0, again, we reduce the rise time substantially and completely eliminate the steady-state error. However, this makes the transient response and overshooting worse.

By setting the 𝑲_𝒅 as 2.0, we combat the undesirable transient response time and overshooting by making this value higher, which only results in a small change in the rise time.

### Code and Functionality
------------------------------------------------------------------------------

<ol>
<li> <strong>DHT.cpp and DHT.h:</strong> These files allow the reading from the DHT11 sensor. Once humidity and temperature of the surrounding is recorded, it can be displayed in degrees Celsius or Fahrenheit. 
</li>

<li><strong>photoresistor.cpp and photoresistor.h:</strong> These files allow the reading from the photoresistor. Once the degree of ambient light is recorded, it outputs an intensity level of the light, ranging from 1 to 5, with 5 being the largest intensity. 
</li>

<li><strong>stepper.cpp and stepper.h:</strong> These files allow the movement of the stepper motor by being passed through the main function. The mode, 0 for wave drive, 1 for a full step and 2 for a halfstep, and the direction, either clockwise or anticlockwise, determines the movement of the stepper in that mode and direction.
</li>
<li><strong>main.cpp: </strong> The main function is the spine of the program and allows for the synchronization of the other functions. It controls the functionality of the embedded control system and allows for the stepper motor to output according to the other peripherals.
</li>
</ol>

### Demo Design
------------------------------------------------------------------------------

TODO: put diagram from lucid chart then images of actual design

### Schematic
------------------------------------------------------------------------------

TODO: put lucid chart schematic


### Block Diagram and Preliminary Designs
------------------------------------------------------------------------------


![Screenshot 2022-05-09 at 1 39 34 PM](https://user-images.githubusercontent.com/66216074/167466983-e798a709-d0f5-4051-b974-57385bf1a0c3.png)

Figure 1 - Control System Diagram

![Screenshot 2022-05-09 at 1 39 44 PM](https://user-images.githubusercontent.com/66216074/167466999-70f748e4-e964-4eb9-bc1c-1bf45f589d1a.png)

Figure 2 - Preliminary blind controls. Red line supports turning of blinds using stepper motor. Blue line spaces blinds during opening and closing.


