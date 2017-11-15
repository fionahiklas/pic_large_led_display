/*
 * File:   main.c
 * Author: Fiona Bianchi
 *
 * Created on 14th November 2017
 */


#include <xc.h>
#include <pic16f884.h>

// CONFIG
#pragma config FOSC = INTRC_NOCLKOUT  // Oscillator Selection bits (INTOSC oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)

// Don't really need this for this program, in fact it should be off 
// otherwise it'll keep restarting your code!
#pragma config WDTE = ON        // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is MCLR)
#pragma config BOREN = ON       // Brown-out Detect Enable bit (BOD enabled)

// Make damn sure that this is OFF otherwise your PIC will go mental if you 
// even wave your hand near it or the circuit!  Do NOT waste the hours I did 
// on trying to 'debug' weird glitches and pauses
#pragma config LVP = OFF         // Low-Voltage Programming Enable bit (RB4/PGM pin has PGM function, low-voltage programming enabled)
#pragma config CPD = OFF        // Data EE Memory Code Protection bit (Data memory code protection off)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

void delay(int delay) {
    while(--delay) {
        delay = delay;
    }
}

/**
 * Init code for slave I2C comms
 * 
 * Copied from https://electrosome.com/i2c-pic-microcontroller-mplab-xc8/ 
 *
 * @param address
 */
void I2C_Slave_Init(short address) 
{
  SSPSTAT = 0x80;    
  SSPADD = address; //Setting address
  SSPCON = 0x36;    //As a slave device
  SSPCON2 = 0x01;
  TRISC3 = 1;       //Setting as input as given in datasheet
  TRISC4 = 1;       //Setting as input as given in datasheet
  GIE = 1;          //Global interrupt enable
  PEIE = 1;         //Peripheral interrupt enable
  SSPIF = 0;        //Clear interrupt flag
  SSPIE = 1;        //Synchronous serial port interrupt enable
}

void main(void) {

    TRISA = 0;
    TRISB = 0;
    TRISD = 0;
    TRISC = 0; // In actual fact pins C3 and C4 will be used for I2C comms
    TRISE = 0;
    
    while(1) {
        PORTA = 0x01;
                
        delay(10000);
        
        PORTA = 0x02;
        
        delay(10000);
    }
}
