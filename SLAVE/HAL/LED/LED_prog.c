/*
 * SW_prog.c
 *
 *  Created on: Jun 3, 2022
 *      Author: DELL
 */
#include "../../Libraries/stdTypes.h"

#include "../../Libraries/errorState.h"


#include "../../MCAL/DIO/DIO_int.h"

#include"LED_priv.h"
#include"LED_config.h"






ES_t LED_enuInit(void){
	ES_t Local_enuErrorState = ES_NOK;

	ES_t Loca_AenuReturnError[2];
	Loca_AenuReturnError[0]=DIO_enuSetPinDirection(LED_u8GROUB, LED_u8PIN, DIO_u8OUTPUT);
	Loca_AenuReturnError[1]=DIO_enuSetPinValue(LED_u8GROUB, LED_u8PIN, LED_u8state);
	for(u8 i=0;i<2;i++){
		if(Loca_AenuReturnError[i]==ES_OK){
			Local_enuErrorState = ES_OK;
		}
		else{
			Local_enuErrorState=Loca_AenuReturnError[i];
			break;
		}
	}
	return Local_enuErrorState;
}
ES_t LED_enuSetLed(){
	ES_t Local_enuErrorState = ES_NOK;
	DIO_enuSetPinValue(LED_u8GROUB, LED_u8PIN, LED_u8state);
	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}
