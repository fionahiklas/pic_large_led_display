## Overview 

Driver for a matrix of LEDs.  The idea for this was a Christmas display that could show scrolling messages and 
graphics.  Also I was originally looking at driving the output for a couple of 8x8 LED matrix displays also.

Based on the number of IO pins on the PIC16F877A (35 in total) it should be possible to drive 8 rows by 24 columns 
and still have pins spare for I2C or serial comms.  The idea being for the PIC chip to do the heavy lifting of 
running the display output but a Raspberry Pi to actually feed it the pixels to display.  

Also thought about driving several of these displays (with multiple PICs) from I2C and a local Raspberry PI.  OR using
a serial connection (from Pi) over a current loop to another PIC which then interfaces to I2C.  For now, going to use I2C 
as this is easiest and should be possible to locate Raspberry Pi near to PICs.

## Circuit

* Contains PIC 16F877A
* 5V supply (from bench PSU)
* LEDs (5mm)
 * Arranged in an 8 row x 24 column grid
 * Rows have series resistors to drop 5V


 

### Resitor Calculation

Total V = 5V
Forward voltage = 1.6V
Resistor voltage drop = 3.4V
Forward current = 20mA

Resistor = 3.4/0.02
         = 6400

Using 10k resistors for ease

 
