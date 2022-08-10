/*
 * prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Nader
 */

#include "../../Libraries/errorState.h"
#include "../../Libraries/stdTypes.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "ADC_config.h"
#include "ADC_priv.h"

static void(*ptr_global)(void) = NULL;


ES_t ADC_INIT(void){

	u8 error_state = ES_OK;

#if ADC_refrence == AREF_internal
	ADMUX &=~ (3<<6);

#elif ADC_refrence == AVCC_external
	ADMUX |= (1<<6);

#elif ADC_refrence == Internal_V
	ADMUX |= (3<<6);

#endif

#if ADC_Adjust == Right_Adjust
	ADMUX &=~ (1<<5);

#elif ADC_Adjust == Left_Adjust
	ADMUX |= (1<<5);

#endif

#if PRESSCALER == 128
	ADCSRA |= (7<<0);

#elif PRESSCALER == 64
	ADCSRA |= (6<<0);

#endif

	ADCSRA |= (1<<7);
	ADCSRA &=~ (1<<5);

	return error_state;
}
ES_t ADC_START_CONVERSION(u8 CH){

	u8 error_state = ES_NOK;

if (CH <= 7 && CH >= 0) {

	ADCSRA |= (1<<6);
	ADMUX &=~ (7<<0);
	ADMUX  |= (CH<<0);

	error_state = ES_OK;
}

	return error_state;
}

ES_t ADC_GET_RESULT(u16 *RESULT){

	u8 error_state = ES_NOK;

if(ADC_Adjust == Right_Adjust){

	while(!((ADCSRA>>6)&1));
	*RESULT = ADCL;
	*RESULT |= ((u16)ADCH<<8);
	error_state = ES_OK;
}
else if (ADC_Adjust == Left_Adjust){

	while((ADCSRA>>6)&1);
	*RESULT = (ADCL >>6);
	*RESULT |= ((u16)ADCH<<2);

	error_state = ES_OK;
}

else error_state = ES_OUT_OF_RANGE;

	return error_state;
}

ES_t ADC_SET_AUTO_TRIGGER(u8 copy_source){

	u8 error_state = ES_NOK;

	if (copy_source <= 7 && copy_source >= 0){
		ADCSRA &=~ (1<<5);
		ADCSRA  |= (1<<5);

		SFIOR  &=~ (7<<5);
		SFIOR  |=  (copy_source << 5);

		error_state = ES_OK;
}

	else error_state = ES_OUT_OF_RANGE;

		return error_state;
}
ES_t ADC_DISABLE_AUTO_TRIGGER(){

	ADCSRA &=~ (1<<5);

		return ES_OK;
}
ES_t ADC_ENABlE_ENTRRUPT(void){

	ADCSRA &=~ (1<<3);
	ADCSRA |=  (1<<3);

		return ES_NOK;
}

ES_t ADC_DISABlE_ENTRRUPT(void){

	ADCSRA &=~ (1<<3);

		return ES_NOK;
}

ES_t ADC_call_back_fun(void(*copy_fun)(void)){

	ptr_global = copy_fun;

	return ES_OK;

}
void__victor_16(void)__attribute__((signal));
void__victor_16(void){
	if(ptr_global != NULL)
	ptr_global();
}

