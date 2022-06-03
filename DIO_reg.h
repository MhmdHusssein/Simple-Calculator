/*
 * Name: Muhammad Hussein Muhammad Salem
 * Layer: MCAL
 * Version: V1.0 - 01/10/2021
 *
 */
 
#ifndef _DIO_REG_H
#define _DIO_REG_H

/* PORT A Related Register*/
#define PORTA *((volatile u08*) 0x3B )
#define DDRA  *((volatile u08*) 0x3A )
#define PINA  *((volatile u08*) 0x39 )

/* PORT B Related Register*/
#define PORTB *((volatile u08*) 0x38 )
#define DDRB  *((volatile u08*) 0x37 )
#define PINB  *((volatile u08*) 0x36 )

/* PORT C Related Register*/
#define PORTC *((volatile u08*) 0x35 )
#define DDRC  *((volatile u08*) 0x34 )
#define PINC  *((volatile u08*) 0x33 )

/* PORT D Related Register*/
#define PORTD *((volatile u08*) 0x32 )
#define DDRD  *((volatile u08*) 0x31 )
#define PIND  *((volatile u08*) 0x30 )
 
#endif