/*
 * MOTORS.c
 *
 * Created: 11/18/2020 3:33:18 PM
 *  Author: Omar Medhat
 */ 

#include "MOTORS.h"

void Move_Forward(char mo1,char mo2){
	SET_BIT(PORTA,mo1);
	RESET_BIT(PORTA,mo1 +1);
	
	SET_BIT(PORTA,mo2);
	RESET_BIT(PORTA,mo2 +1);
}


void Move_Backward(char mo1,char mo2){
	RESET_BIT(PORTA,mo1);
	SET_BIT(PORTA,mo1+1);
	
	RESET_BIT(PORTA,mo2);
	SET_BIT(PORTA,mo2+1);
}

void Stop(char mo1,char mo2){
	RESET_BIT(PORTA,mo1);
	RESET_BIT(PORTA,mo1+1);
	
	RESET_BIT(PORTA,mo2);
	RESET_BIT(PORTA,mo2+1);
}

void Move_Right(char mo1,char mo2){
	SET_BIT(PORTA,mo1);
	RESET_BIT(PORTA,mo1+1);
	
	RESET_BIT(PORTA,mo2);
	RESET_BIT(PORTA,mo2+1);
}

void Move_Left(char mo1,char mo2){
	SET_BIT(PORTA,mo2);
	RESET_BIT(PORTA,mo2+1);
	
	RESET_BIT(PORTA,mo1);
	RESET_BIT(PORTA,mo1+1);		
}
