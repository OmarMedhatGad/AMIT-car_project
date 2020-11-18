/*
 * US.h
 *
 * Created: 11/18/2020 2:10:55 PM
 *  Author: Omar Medhat
 */ 


#ifndef US_H_
#define US_H_

#define  Trig_Pin  0         // pin 0 in port c
//#define  Echo_Pin  4		 // pin 4 in port c

void US_Init();
void Trig_ON();             // start measuring time 
double Calc_Distance(int ticks);         




#endif /* US_H_ */
