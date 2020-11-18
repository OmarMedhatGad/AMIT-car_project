/*
 * INTS.c
 *
 * Created: 11/18/2020 5:24:55 PM
 *  Author: Omar Medhat
 */ 

#include "INTS.h"
#include "BITS.h"
#include <avr/interrupt.h>

void INT_Init(){
	//Setting the Ext. interrupts to any logical change.
	SET_BIT(MCUCR,ISC00);
	
	//Enabling the mask register 
	SET_BIT(GICR,INT0);	
}

void INT_Disable(){
	RESET_BIT(GICR,INT0);	
}
void INT_Enable(){
	SET_BIT(GICR,INT0);	
}
