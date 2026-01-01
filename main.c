/* 
 * File:   main.c
 * Author: mimim
 *
 * Created on November 9, 2025, 11:25 AM
 */


#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 14745600UL


#define G0  PD0
#define G2  PC5
#define AS0 PC2
#define AS1 PC3
#define AS2 PC4

int main(void) {
    DDRC |= (1<<G2)|(1<<AS0)|(1<<AS1)|(1<<AS2);
    DDRD |= (1<<G0);
    
    // G0:2 = 0b0X1
    PORTD &= ~(1<<G0);
    PORTC |= (1<<G2);
    
    
    
    PORTC |= (0b00010100);
    
    uint8_t x = 0b00000000;
    
    while(1) { 
        // AS0:2 = 000 -> &= ~ 0x8F
        PORTC &= ~((1<<AS1)|(1<<AS2)|(1<<AS0));
        PORTC |= (0b00001000);
        _delay_ms(10000); 
        x = x + 1;
        if (x > 0b101){
            x = 0b000;
        }

    }


    
    return 0;
}

