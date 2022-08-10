/*
 * PWM_Prog.c
 *
 *  Created on: Aug 2, 2022
 *      Author: DELL
 */
#include"../../Libraries/errorState.h"
#include"../../Libraries/stdTypes.h"

#include "../PWM0/PWM_Config.h"
#include "../PWM0/PWM_Priv.h"


ES_t PWM0_enuInit(void){
	ES_t Local_enuErrorState =ES_NOK;
	DDRB |=(1<<3);		//set OC0 as PWM output
#if PWM_MODE == Fast_PWM
	TCCR0 |=(1<<3);
	TCCR0 |=(1<<6);

#elif PWM_MODE == PHASE_CORRECT_PWM
	TCCR0 &=~(1<<3);
	TCCR0 |=(1<<6);

#endif
#if Compare_Output_Mode == NON_INVERTED
		TCCR0 &=~(1<<4);
		TCCR0 |=(1<<5);
#elif Compare_Output_Mode == INVERTED
		TCCR0 |=(1<<4);
		TCCR0 |=(1<<5);
#endif
	return Local_enuErrorState;
}

ES_t PWM0_enuSetDutyCycle(u8 Copy_u8DutyCycle){
	ES_t Local_enuErrorState =ES_NOK;
#if PWM_MODE == Fast_PWM

	#if Compare_Output_Mode == NON_INVERTED
		if(Copy_u8DutyCycle <= 100 && Copy_u8DutyCycle >0){
			OCR0=(((Copy_u8DutyCycle *255)/100)-1);
		}

	#elif Compare_Output_Mode == INVERTED
		if(Copy_u8DutyCycle < 100 && Copy_u8DutyCycle >=0){
			OCR0 = (254-((Copy_u8DutyCycle * 255)/100));
		}
	#endif
#elif PWM_MODE == PHASE_CORRECT_PWM
	#if Compare_Output_Mode == NON_INVERTED
		if(Copy_u8DutyCycle <= 100 && Copy_u8DutyCycle >=0){
			OCR0=((Copy_u8DutyCycle *255)/100);
		}

	#elif Compare_Output_Mode == INVERTED
		if(Copy_u8DutyCycle <= 100 && Copy_u8DutyCycle >=0){
			OCR0 = 255-((Copy_u8DutyCycle * 255)/100);
		}
	#endif

#endif

	Local_enuErrorState =ES_OK;
	return Local_enuErrorState;
}

ES_t PWM0_Start(void){
	ES_t Local_enuErrorState =ES_NOK;
#if TIMER0_PRESCALER == 1024
	TCCR0 |=(5<<0);
#elif TIMER0_PRESCALER == 256
	TCCR0 |=(4<<0);
#elif TIMER0_PRESCALER == 64
	TCCR0 |=(3<<0);
#elif TIMER0_PRESCALER == 8
	TCCR0 |=(2<<0);
#elif TIMER0_PRESCALER == No_prescaling
	TCCR0 &=~(1<<0);
#endif
	Local_enuErrorState =ES_OK;
	return Local_enuErrorState;
}

ES_t PWM0_Stop(void){
	ES_t Local_enuErrorState =ES_NOK;
	TCCR0 &=~(7<<0);
	Local_enuErrorState =ES_OK;
	return Local_enuErrorState;
}



