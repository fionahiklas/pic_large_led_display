## Overview 

PIC Code for LED driver circuit for LEGO lights.

My partner has made several of the LEGO Creator sets (Tower Bridge, Houses of Parliament so far)
and we want to put these in cases and also add small LED lights.

Given the number of LEDs and power output (we're looking at maybe 40 or so, each 3V 20mA) it makes
sense to use some sort of circuit to drive these in a matrix arrangement such that only a 
limited number are on at any given time.  The device can whizz through all the rows/columns in 
quick succession giving the illusion that all the LEDs are on permanently.

This is a relatively simple project and it's just something I'm playing with to learn more 
about micro controllers, PIC, electronics, etc

## Getting Started

### PICKit3

I've got two of these, one an official device and another Chinese clone.
The Chinese clone isn't able to drive enough power from USB to run a simple
circuit and program a device in-circuit.  However it seems capable of programming
a PIC device using the provided board 


#### Project Configuration

* Find the `Production` -> `Set Project Configuration` -> `Customize ...` menu
* From the dialog that appears select PICKit3 in the LHS and `Power` in the drop-down
* Make sure that the "Power Target circuit from PICKit3" is selected if you use a programming board (I did)
* Also I double clicked on the PICKit3 serial number/name and renamed the boards to distinguish between them

#### 


## Circuit

* Contains PIC 16F884
* Transistors to drive 5V and GND to LEDs
* 5V supply 
* LEDs surface mount 
 * Arranged in an 8 row x 16 column grid
 * Need to work columns change every clock tick




## Notes 

### Resistor Calculation

Total V = 5V
Forward voltage = 3V
Resistor voltage drop = 3.4V
Forward current = 20mA

Resistor = 3.4/0.02
         = 6400

Using 10k resistors for ease

 
## References

### PIC

* [Timer interrupt](http://ww1.microchip.com/downloads/en/DeviceDoc/51702A.pdf)
* [PIC interrupts](http://picguides.com/beginner/interrupts.php)

### C/C++

* [Initialise Array](http://www.cplusplus.com/doc/tutorial/arrays/)
* [Logical shift operators](https://stackoverflow.com/questions/7622/are-the-shift-operators-arithmetic-or-logical-in-c)