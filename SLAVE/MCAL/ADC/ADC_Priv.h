/*
 * ADC_Priv.h
 *
 *  Created on: Jul 27, 2022
 *      Author: DELL
 */

#ifndef MCAL_ADC_ADC_PRIV_H_
#define MCAL_ADC_ADC_PRIV_H_
#define AVCC		      	1
#define AREF	 			2
#define TwoAndHalfV	 		3

#define RightAdjust			12
#define LeftAdjust			45
#define ADC0				123
#define ADC1				22
#define ADC2				56
#define ADC3				2356
#define ADC4				11
#define ADC5				221
#define ADC6				417
#define ADC7				1554



#define ADMUX		*((volatile u8*)0x27)
#define ADCSRA		*((volatile u8*)0x26)
#define ADCH		*((volatile u8*)0x25)
#define ADCL		*((volatile u8*)0x24)

#endif /* MCAL_ADC_ADC_PRIV_H_ */
