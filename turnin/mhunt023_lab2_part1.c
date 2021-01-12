/*	Author: Matthew Hunt
 *  Partner(s) Name: 
 *	Lab Section: 23
 *	Assignment: Lab #2  Exercise #1
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
	PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0xFF; // Configure port B's 8 pins as outputs
	PORTB = 0x00; // Initialize PORTB output to 0's
	unsigned char out0 = 0x00; // Temporary variable to hold the value of B
	unsigned char in0 = 0x00; // Temporary variable to hold the value of A
	unsigned char in1 = 0x00; // Temporary variable to hold the value of A

	while (1) {

		// 1) Read input
		in0 = PINA & 0x01;
		in1 = PINA & 0x02;
		// 2) Perform computation
		// if PA0 is 1 and PA1 is 0, then set PB0 = 1, else  PB0 = 0
		if (in0 == 0x01 && in1 == 0x00) { // True if PA0 is 1 and PA1 is 0
			out0 = (out0 & 0xFE) | 0x01; // Sets PB0 to bbbbbbb1
			// (clear rightmost bit, then set to 1)
		}
		else {
			out0 = out0 & 0xFE; // Sets tmpB to bbbbbbb0
			// (clear rightmost bit)
		}
		// 3) Write output
		PORTB = out0;
	}
	return 0;
}
