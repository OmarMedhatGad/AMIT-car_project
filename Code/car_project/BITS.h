/*
 * BITS.h
 *
 * Created: 11/18/2020 4:49:02 AM
 *  Author: Omar Medhat
 */ 


#ifndef BITS_H_
#define BITS_H_

#define SET_BIT(ADDRESS,BIT)	ADDRESS |= (1<<BIT)
#define RESET_BIT(ADDRESS,BIT)	ADDRESS &=~(1<<BIT)
#define TOGGLE_BIT(ADDRESS,BIT)	ADDRESS ^= (1<<BIT)
#define READ_BIT(ADDRESS,BIT)	((ADDRESS & (1<<BIT))>>BIT) 


#endif /* BITS_H_ */
