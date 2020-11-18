/*
 * US.c
 *
 * Created: 11/18/2020 2:11:08 PM
 *  Author: Omar Medhat
 */
#define F_CPU 1000000UL

#include<util/delay.h>
#include "US.h"
#include "BITS.h"
#include <avr/io.h>

void US_Init(){
	DDRC = 0x0F;
}
void Trig_ON(){
	SET_BIT(PORTC,Trig_Pin);
	_delay_us(15);				//increase this if the US doesn't work
	RESET_BIT(PORTC,Trig_Pin);
}

double Calc_Distance(int ticks)
{
	double distance = ticks*17/1000;  //speed of ultra sonic = 340 M/S =34000 CM/S,time of each timer tick = 10^-6,one way wave to get distance /2      
	return distance;
}
