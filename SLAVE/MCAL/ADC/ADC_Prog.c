/*
 * ADC_Prog.c
 *
 *  Created on: Jul 27, 2022
 *      Author: DELL
 */
#include"../../Libraries/errorState.h"
#include"../../Libraries/stdTypes.h"

#include"ADC_Config.h"
#include"ADC_Priv.h"

ES_t ADC_enuInit(void){
	ES_t Local_enuErrorState=ES_NOK;
	//for selecting VoltageReference
#if VoltageReference == AREF
	ADMUX|=(0<<6);
#elif VoltageReference == AVCC
	ADMUX|=(1<<6);
#elif VoltageReference == TwoAndHalfV
	ADMUX|=(2<<6);
#endif

	//for the direction adjust
#if ADC_Adjust == RightAdjust
	ADMUX|=(0<<5);
#elif ADC_Adjust == LeftAdjust
	ADMUX|=(1<<5);
#endif

	// for selectinf of the Channel Number
#if ADC_ChannelNum == ADC0
	ADMUX|=(0<<0);
#elif ADC_ChannelNum == ADC1
	ADMUX|=(1<<0);
#elif ADC_ChannelNum == ADC2
	ADMUX|=(2<<0);
#elif ADC_ChannelNum == ADC3
	ADMUX|=(3<<0);
#elif ADC_ChannelNum == ADC4
	ADMUX|=(4<<1);
#elif ADC_ChannelNum == ADC5
	ADMUX|=(5<<1);
#elif ADC_ChannelNum == ADC6
	ADMUX|=(6<<1);
#elif ADC_ChannelNum == ADC7
	ADMUX|=(7<<1);
#endif

	// for prescaler Bit
	ADCSRA|=(7<<0);
	// Auto Trigger Enable
	ADCSRA|=(1<<5);
	//Enable ADC
	ADCSRA|=(1<<7);

	Local_enuErrorState=ES_OK;
	return Local_enuErrorState;
}

ES_t ADC_enuRead(u16* Copy_Pu16ReadValue){
	ES_t Local_enuErrorState=ES_NOK;
	if(Copy_Pu16ReadValue!=NULL){
		//Start Conversion
		ADCSRA|=(1<<6);
		while(((ADCSRA>>4)&1)==0);
#if ADC_Adjust == RightAdjust
		*Copy_Pu16ReadValue= ADCL + ((ADCH>>0)&1)*256 + ((ADCH>>1)&1)*512;
#elif ADC_Adjust == LeftAdjust
		*Copy_Pu16ReadValue= ADCH + ((ADCL>>0)&7)*128 + ((ADCL>>6)&1)*64;
#endif

		Local_enuErrorState=ES_OK;
	}
	else{
		Local_enuErrorState=ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}
ES_t ADC_enuDisableADC(void){
	ES_t Local_enuErrorState=ES_NOK;
	ADCSRA &=~(1<<7);
	Local_enuErrorState=ES_OK;
	return Local_enuErrorState;
}
ES_t ADC_enuEnableADC(void){
	ES_t Local_enuErrorState=ES_NOK;
	ADCSRA |=(1<<7);
	Local_enuErrorState=ES_OK;
	return Local_enuErrorState;
}
