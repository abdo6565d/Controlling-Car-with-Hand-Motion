/*
 * PWM1_Priv.h
 *
 *  Created on: Aug 4, 2022
 *      Author: DELL
 */

#ifndef MCAL_PWM1_PWM1_PRIV_H_
#define MCAL_PWM1_PWM1_PRIV_H_


#define TCCR1A	     *((volatile u8*)0x4F)
#define TCCR1B	     *((volatile u8*)0x4E)
#define DDRD 		*((volatile u8*)0x31)



#define ICR1				32
#define OCR1A1				2
#define No_prescaling		1

#define Fast_PWM			15
#define PHASE_CORRECT_PWM	115

#define NON_INVERTED		12
#define INVERTED			13


#endif /* MCAL_PWM1_PWM1_PRIV_H_ */
