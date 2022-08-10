/*
 * GIE_Prog.c
 *
 *  Created on: Jun 30, 2022
 *      Author: DELL
 */

#include"../../Libraries/errorState.h"
#include"../../Libraries/stdTypes.h"




#include"GIE_Priv.h"




ES_t GIE_enuInit(void)
{
	ES_t Local_enuErrorState=ES_NOK;
	SREG &=~(1<<7);
	Local_enuErrorState=ES_OK;
	return Local_enuErrorState;
	}
ES_t GIE_enuEnable(void){
	ES_t Local_enuErrorState=ES_NOK;
	SREG |=(1<<7);
	Local_enuErrorState=ES_OK;
	return Local_enuErrorState;
}
ES_t GIE_enuDisable(void){
	ES_t Local_enuErrorState=ES_NOK;
	SREG &=~(1<<7);
	Local_enuErrorState=ES_OK;
	return Local_enuErrorState;
}
