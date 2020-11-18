/*
 * uart.h
 *
 * Created: 11/17/2020 5:53:01 AM
 *  Author: Omar Medhat
 */ 


#ifndef _UART_H_
#define _UART_H_

//#define F_CPU 1843200
//#define F_CPU 1000000
#define BAUD_RATE 9600          //put the U2X  bit = 1 in USCRA Register to decrease the error rate as shown from the table 
//#define BAUD_RATE_VALUE (((F_CPU)/(BAUD_RATE*16UL))-1)
#define BAUD_RATE_VALUE 0x000C
#define _MEM(address) (*(volatile uint8_t *)(address)) //this macro to access the memory.
//#define BAUD_RATE_VALUE 12
typedef struct {
	
	/* Place here module configuration registers. */
	uint8_t UBRRH_cfg;
	uint8_t UBRRL_cfg;
	uint8_t UCSRA_cfg;
	uint8_t UCSRB_cfg;
	uint8_t UCSRC_cfg;
	
}UART_cfg;

extern void 	 UART_Init(UART_cfg *my_cfg);
extern void 	 UART_SendPayload(uint8_t *tx_data, uint16_t len);
extern void      UART_ReceivePayload(uint8_t *rx_data, uint16_t len);
extern uint8_t 	 UART_IsDataAvaiable(void);
extern uint8_t 	 UART_IsTxComplete(void);
extern uint8_t 	 UART_IsRxComplete(void);

#endif
