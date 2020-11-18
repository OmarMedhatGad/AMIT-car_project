/*
 * MOTORS.h
 *
 * Created: 11/18/2020 3:33:37 PM
 *  Author: Omar Medhat
 */ 


#ifndef MOTORS_H_
#define MOTORS_H_

#include "BITS.h"
#include <avr/io.h>

//#define MOTORs_PORT PORTA         ask how to do this ?  
#define M1 0
#define M2 2
 
/*									 how to do this ? 
#define Move_Forward(M)   SET_BIT(MOTORs_PORT,M) RESET_BIT(MOTORs_PORT,M+1)
#define Move_Backward(M)  RESET_BIT(MOTORs_PORT,M) SET_BIT(MOTORs_PORT,M+1)

#define Stop(M)           RESET_BIT(MOTORs_PORT,M) RESET_BIT(MOTORs_PORT,M+1)   

#define Move_Right(M,MM)  Move_Forward(M) Stop(MM)
#define Move_left(M,MM)   Stop(M)  Move_Forward(MM)
*/ 
void Move_Forward(char mo1,char mo2);

void Move_Backward(char mo1,char mo2);

void Stop(char mo1,char mo2);

void Move_Right(char mo1,char mo2);

void Move_Left(char mo1,char mo2);
#endif /* MOTORS_H_ */
