/*
 * EXTI_Priv.h
 *
 *  Created on: Jun 30, 2022
 *      Author: DELL
 */

#ifndef MCAL_EXTI_EXTI_PRIV_H_
#define MCAL_EXTI_EXTI_PRIV_H_
enum{
	Disable=0,
	Enable,

	Low_level=0,
	AnyLogic,
	Rising,
	Falling,

	INT0=0,
	INT1,
	INT2

};


#define MCUCR			*((volatile u8*)0x55)
#define MCUCSR			*((volatile u8*)0x54)
#define GICR			*((volatile u8*)0x5B)
#define GIFR			*((volatile u8*)0x5A)

#endif /* MCAL_EXTI_EXTI_PRIV_H_ */
