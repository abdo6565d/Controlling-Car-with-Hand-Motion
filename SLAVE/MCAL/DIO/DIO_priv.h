/*
 * DIO_priv.h
 *
 *  Created on: May 28, 2022
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef DIO_PRIV_H_
#define DIO_PRIV_H_

#define PORTA 		*((volatile u8*)0x3B)
#define DDRA 		*((volatile u8*)0x3A)
#define PINA 		*((volatile u8*)0x39)

#define PORTB 		*((volatile u8*)56)
#define DDRB 		*((volatile u8*)0x37)
#define PINB 		*((volatile u8*)0x36)

#define PORTC 		*((volatile u8*)0x35)
#define DDRC 		*((volatile u8*)0x34)
#define PINC 		*((volatile u8*)0x33)

#define PORTD 		*((volatile u8*)0x32)
#define DDRD 		*((volatile u8*)0x31)
#define PIND 		*((volatile u8*)0x30)

#define DIO_u8GROUP_A			0
#define DIO_u8GROUP_B			1
#define DIO_u8GROUP_C			2
#define DIO_u8GROUP_D			3


#define DIO_u8PIN0				0
#define DIO_u8PIN1				1
#define DIO_u8PIN2				2
#define DIO_u8PIN3				3
#define DIO_u8PIN4				4
#define DIO_u8PIN5				5
#define DIO_u8PIN6				6
#define DIO_u8PIN7				7

#define DIO_u8INPUT				0
#define DIO_u8OUTPUT			1

#define DIO_u8HIGH				1
#define DIO_u8PULLUP			1

#define DIO_u8LOW				0
#define DIO_u8FLOAT				0

#define DIO_BIT_MASK			1

#endif /* DIO_PRIV_H_ */
