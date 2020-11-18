/*
 * Timer.c
 *
 * Created: 11/17/2020 4:46:06 PM
 *  Author: Omar Medhat
 */ 
#include "Timer.h"
#include "BITS.h"
#include <avr/interrupt.h>


void Timer_Start(){
	//Enabling the ovf interrupt
	/*SET_BIT(TIMSK,TOIE0);*/
	
	//starting and setting timer1 (16 bit) prescaler =1, in normal mode(default).
	SET_BIT(TCCR1B,CS10);
}

void Timer_Stop(){ //ask can we make it inline function and call it inside the ISR ? 
	//disabling the ovf interrupt
/*	RESET_BIT(TIMSK,TOIE0);*/
	
	//stoping timer1 , in normal mode(default).
	RESET_BIT(TCCR1B,CS10);
}
