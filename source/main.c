/*	Author: mlips001
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif


enum States{init, inc, dec, zero} state;

unsigned char button0;
unsigned char button1;

unsigned char tempC;


void two_buttons(){
        button0 = PINA & 0x01;
        button1 = PINA & 0x02;

        switch(state){
                case init:
                        if(!button0 && !button1){
                                state = init;
                        }
                        else if(button0 && !button1){
                                state = inc;
                        }
                        else if(!button0 && button1){
                                state = dec;
                        }
                        else if(button0 && button1){
                                state = zero;
                        }
                        break;
                case inc:
                        if(button0 && button1){
                                state = zero;
                        }
                        else{
                                state = init;
                        }
                        break;
                case dec:
                        if(button0 && button1){
                                state = zero;
                        }
                        else{
                                state = init;
                        }
                        break;
                case zero:
                        if(!button0 && !button1){
                                state = init;
                        }
                        else if (button0 && !button1){
                                state = inc;
                        }
                        else if(!button0 && button1){
                                state = dec;
                        }
                        else if(button0 && button1){
                                state = zero;
                        }
                        break;
}
        switch(state){
                case init:
                        break;
                case inc:
                        if(tempC < 9){
                                tempC = tempC + 1;
                        }
                        break;
                case dec:
                        if(tempC > 0){
                                tempC = tempC - 1;
                        }
                        break;
                case zero:
                        tempC = 0;
                        break;
        }
}


int main(void) {
    /* Insert DDR and PORT initializations */
        DDRA = 0x00; PORTA = 0xFF;
        DDRC = 0xFF; PORTC = 0x00;

    /* Insert your solution below */
    while (1) {

        two_buttons();
        PORTC = tempC;

    }
    return 1;
}
