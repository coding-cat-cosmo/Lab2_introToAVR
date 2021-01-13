/*	Author: Matthew Hunt
 *  Partner(s) Name: 
 *	Lab Section: 23
 *	Assignment: Lab #2  Exercise #2
 *	Exercise Description: garage door sensor
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
		DDRB = 0xFF; // Configure port B 8 pins as outputs
	PORTB = 0x00; // Initialize PORTB output to 0
	unsigned char cntavail = 0x04; // Temporary variable for holding amount of spaces left

	while (1) {

		// 1) Calculate leftover parking spots from input PINA
		cntavail = 0x04 - (((PINA & 0x08) >> 3) + ((PINA & 0x04) >> 2) + ((PINA & 0x02) >> 1) + (PINA & 0x01));
		// 2) Write output
		PORTC = cntavail;
	}
	return 0;
}
