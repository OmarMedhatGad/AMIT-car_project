/*
 * Created: 11/18/2020 9:04:04 AM
 * Author : Omar Medhat
 */ 

#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


//#define MOTORs_PORT PORTA  
// IR PINS are Right on PINB0 & left on PINB1 
#include "BITS.h"
#include "INTS.h"
#include "US.h"
#include "MOTORS.h"
#include "uart.h"
 

#define FULL_CMD_CNT 1
double distance = 0;
int ticks = 0;
int Timer_Running_Flag =0;
int No_Wall = 1;

int main(void)
{
		/* Init UART driver. */
	UART_cfg my_uart_cfg;
		
		/* Set USART mode. */
	my_uart_cfg.UBRRL_cfg = (BAUD_RATE_VALUE)&0x00FF;
	my_uart_cfg.UBRRH_cfg = 0x00; //(((BAUD_RATE_VALUE)&0xFF00)>>8);
		
	my_uart_cfg.UCSRA_cfg = 0;
	my_uart_cfg.UCSRB_cfg = (1<<RXEN)  | (1<<TXEN) | (1<<TXCIE) | (1<<RXCIE);
	my_uart_cfg.UCSRC_cfg = (1<<URSEL) | (3<<UCSZ0);
		
	UART_Init(&my_uart_cfg);
	
	INT_Init();
	sei();
	DDRC = 0x0F;
    DDRB = 0x00;
	//PORTB = 0xff; //enabling pull up resistor ,remove before burning 
	DDRA = 0xFF;
	DDRD = 0x00;
	uint8_t cmd_buffer[10];
    while (1) 
    {
		UART_SendPayload((uint8_t *)">", 1);
		while (0 == UART_IsTxComplete());

		/* Receive the full buffer command. */
		UART_ReceivePayload(cmd_buffer, FULL_CMD_CNT);
		
		/* Pull until reception is complete. */
		while(0 == UART_IsRxComplete());
		
		switch(cmd_buffer[0]){ // nyahahahahha numbers are characters xD xD.
		case '2':Move_Forward(M1,M2);  break;
		case '4':Move_Left(M1,M2);	 break;
		case '6':Move_Right(M1,M2);	 break;
		case '8':Move_Backward(M1,M2); break;
		case '5':Stop(M1,M2); break;
		case '0': //all this in case 0  
				while(!READ_BIT(PINB,7)){	
					Trig_ON();
					_delay_ms(60);
		
				//	No_Wall ? Move_Forward(M1,M2) : Stop(M1,M2);
					if (No_Wall)
					{
						switch(PINB&0x03){  //masking the first two bits of PINB 
						case 0x00: Stop(M1,M2);			break;
						case 0x01: Move_Left(M1,M2);	break;
						case 0x02: Move_Right(M1,M2);	break;
						case 0x03: Move_Forward(M1,M2);	break;
						}
					}
					else{
						//PORTA = 0x00;      //stop motors
						Stop(M1,M2); 
					}
		//break;
		//default: continue; //hat mn awl el while tany lw das ay 7aga 8alat :D :D
			}
		}
	}	
}

ISR(INT0_vect){
	
	if (Timer_Running_Flag)    // at the falling edge of echo signal 
	{
		//stopping timer1 , in normal mode(default).
		RESET_BIT(TCCR1B,CS10);
		Timer_Running_Flag = 0;
		
		//PORTA = TCNT1L;
		//_delay_ms(100);
		//ticks = (TCNT1H<<8) | TCNT1L ;
		ticks = TCNT1;
		//distance = ticks*(17/1000);
		distance = ticks/58;
		if (distance < 100)
		{
			//PORTA = 0x00;       //stop the motors
			//PORTB = 0xFF;
			 No_Wall = 0;
		}
		else{
			No_Wall = 1;          //run the motors 
			//PORTB = 0x00;       
		}
		TCNT1 =0x0000; 
	}
	
	else {                     //at the rising edge of echo signal 
	
		//starting timer1 , in normal mode(default).
		SET_BIT(TCCR1B,CS10);
		Timer_Running_Flag = 1;
	}
		
	//PORTB ^= 0xFF;
}

