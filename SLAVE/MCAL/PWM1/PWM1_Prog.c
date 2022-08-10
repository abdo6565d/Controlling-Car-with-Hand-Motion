/*
 * PWM1_Prog.c
 *
 *  Created on: Aug 4, 2022
 *      Author: DELL
 */
#include"../../Libraries/errorState.h"
#include"../../Libraries/stdTypes.h"

#include "../PWM1/PWM1_Config.h"
#include "../PWM1/PWM1_Priv.h"


ES_t PWM1_enuInit(void){

#if PWM1_MODE ==Fast_PWM
	#if PWM1_TOP_MODE == ICR1
		DDRD |=(1<<5);
		TCCR1A &=~(1<<0);
		TCCR1A |=(1<<1);
		TCCR1B |=(1<<3);
		TCCR1B |=(1<<4);
		#if Compare_Output_Mode == NON_INVERTED
			TCCR1A &=~(1<<6);
			TCCR1A |=(1<<7);

		#elif Compare_Output_Mode == INVERTED
			TCCR1A |=(1<<6);
			TCCR1A |=(1<<7);
		#endif
	#elif PWM1_TOP_MODE == OCR1A1
			DDRD |=(1<<4);
	#endif
#elif PWM1_MODE == PHASE_CORRECT_PWM
#endif
}

ES_t PWM1_enuSetFrequency(u32 Copy_u8Frequency){
//	ICR1 = ((F_OSC *1000000 / TIMER1_PRESCALER) / Copy_u8Frequency);
}

ES_t PWM1_enuSetDutyCycle(u8 Copy_u8DutyCycle){
	ES_t Local_enuErrorState =ES_NOK;
}

ES_t PWM1_Start(void);

ES_t PWM1_Stop(void);

