/*
 * Temp_Prog.c
 *
 *  Created on: Jul 28, 2022
 *      Author: DELL
 */
#include"../../Libraries/errorState.h"
#include"../../Libraries/stdTypes.h"

#include "../../MCAL/ADC/ADC_Int.h"

#include"Temp_Config.h"
#include"Temp_Priv.h"

ES_t Temp_enuInit(void){
	ADC_enuInit();
	return ES_OK;
}

ES_t Temp_enuRead(u16* Copy_Pu16ReadValue){
	u16 Local_u16AdcValue;
	ADC_enuRead(&Local_u16AdcValue);
	*Copy_Pu16ReadValue = ((u32)Local_u16AdcValue * 500)/1023;
	return ES_OK;
}
ES_t Temp_enuEnableTemp(void){
	ADC_enuEnableADC();
	return ES_OK;
}

ES_t Temp_enuDisableTemp(void){
	ADC_enuDisableADC();
	return ES_OK;
}

