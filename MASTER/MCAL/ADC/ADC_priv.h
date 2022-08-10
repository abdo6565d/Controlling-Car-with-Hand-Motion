/*
 * ADC_priv.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Nader
 */

#ifndef MCAL_ADC_ADC_PRIV_H_
#define MCAL_ADC_ADC_PRIV_H_

#define AREF_internal				11
#define AVCC_external				12
#define Reserved					13
#define Internal_V					14
#define Left_Adjust					15
#define Right_Adjust				16
#define High_Read					17
#define SINGLE						90
#define FREE_RUN					40
#define TRIGGERED					30

#define ADMUX			*((volatile u8*)0x27)
#define ADCSRA			*((volatile u8*)0x26)
#define SFIOR			*((volatile u8*)0x50)
#define ADCH			*((volatile u8*)0x25)
#define ADCL			*((volatile u8*)0x24)

typedef enum {

	FERR_RUNNING_MODE,
	ANALOG_COMPARATOR,
	EXTERNAL_INTERRUPT_REQUEST,
	TIMMER0_COMPARE_MATCH,
	TIMMER0_OVER_FLOW,
	TIMMER1_COMPARE_MATCH,
	TIMMER1_OVER_FLOW,
	TIMMER1_CAPTURE_EVENT

}ADC_MODE;

#endif /* MCAL_ADC_ADC_PRIV_H_ */
