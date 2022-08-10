/*
 * TIMER_Priv.h
 *
 *  Created on: Aug 1, 2022
 *      Author: DELL
 */

#ifndef MCAL_TIMER0_TIMER_PRIV_H_
#define MCAL_TIMER0_TIMER_PRIV_H_

#define TCNT0	     *((volatile u8*)0x52)
#define TCCR0	     *((volatile u8*)0x53)
#define TIMSK	     *((volatile u8*)0x59)
#define OCR0 		 *((volatile u8*)0x5C)

#define SREG 		 *((volatile u8*)0x5F)


#define CTC_MODE			12
#define NORMAL_MODE			11

#define No_prescaling		1


#endif /* MCAL_TIMER0_TIMER_PRIV_H_ */
