/*
 * PWM_Priv.h
 *
 *  Created on: Aug 2, 2022
 *      Author: DELL
 */

#ifndef MCAL_PWM0_PWM_PRIV_H_
#define MCAL_PWM0_PWM_PRIV_H_

#define TCNT0	     *((volatile u8*)0x52)
#define TCCR0	     *((volatile u8*)0x53)
#define TIMSK	     *((volatile u8*)0x59)
#define OCR0 		 *((volatile u8*)0x5C)

#define SREG 		 *((volatile u8*)0x5F)
#define DDRB 		*((volatile u8*)0x37)

#define No_prescaling		1

#define Fast_PWM			15
#define PHASE_CORRECT_PWM	115

#define NON_INVERTED		12
#define INVERTED			13

#endif /* MCAL_PWM0_PWM_PRIV_H_ */
