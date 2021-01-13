/*	Author: Matthew Hunt
 *  Partner(s) Name: 
 *	Lab Section: 23
 *	Assignment: Lab #2  Exercise #4
 *	Exercise Description: amusement park ride weight sensor
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
	DDRA = 0x00; 
	PORTA = 0xFF; // Configure port A 8 pins as inputs
	DDRB = 0x00;
	PORTB = 0xFF; // Configure port B 8 pins as inputs
	DDRC = 0x00;
	PORTC = 0xFF; // Configure port C 8 pins as inputs
	DDRD = 0xFF; // Configure port D 8 pins as outputs
	PORTD = 0x00; // Initialize PORTD output to 0
	unsigned char shiftwgt = 0x00; // Temporary variable for holding amount of spaces left
	unsigned short actwgt = 0x0000;
	unsigned char diff = 0x00;

	while (1) {
		actwgt = 0x0000;
		PORTD = 0x00;

		// 1) calculate actwgt and diff
		actwgt = actwgt + PINA;
		actwgt = actwgt + PINB;
		actwgt = actwgt + PINC;

		if ((PINA - PINC) < 0) {
			diff = PINC - PINA;
		}
		else {
			diff = PINA - PINC;
		}
		
		if (actwgt > 140) { //140 or 10001100 or 0x008C
			PORTD = PORTD | 0x01;
		}
		else {
			PORTD = PORTD & 0xFE;
		}

		if (diff > 80) { 
			PORTD = PORTD | 0x02;
		}
		else {
			PORTD = PORTD & 0xFD;
		}

		// 2) calculate shiftwgt by making sure it can not go out of bounds for max value possible
		shiftwgt = (actwgt * 63) / 765;

		// 3) adding shiftwgt to output
		PORTD = PORTD + (shiftwgt << 2);
	}
	return 0;
}
