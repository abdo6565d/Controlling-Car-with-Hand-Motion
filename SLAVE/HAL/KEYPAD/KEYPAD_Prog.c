/*
 * KEYPAD_Prog.c
 *
 *  Created on: Jul 16, 2022
 *      Author: DELL
 */

#include"../../Libraries/errorState.h"
#include"../../Libraries/stdTypes.h"

#include "../../MCAL/DIO/DIO_int.h"


#include "../KEYPAD/KEYPAD_Config.h"
#include "../KEYPAD/KEYPAD_Priv.h"

#include <util/delay.h>





ES_t Keypad_enuInit(void){
	ES_t Local_enuErrorState=ES_NOK;

#if Col_Num>0 &&Col_Num<=4 && Row_Num>0 && Row_Num<=4

	DIO_enuSetPinDirection(R1_GRB,R1_PIN,DIO_u8INPUT);
	DIO_enuSetPinDirection(R2_GRB,R2_PIN,DIO_u8INPUT);
	DIO_enuSetPinDirection(R3_GRB,R3_PIN,DIO_u8INPUT);
	DIO_enuSetPinDirection(R4_GRB,R4_PIN,DIO_u8INPUT);

	DIO_enuSetPinDirection(C1_GRB,C1_PIN,DIO_u8OUTPUT);
	DIO_enuSetPinDirection(C2_GRB,C2_PIN,DIO_u8OUTPUT);
	DIO_enuSetPinDirection(C3_GRB,C3_PIN,DIO_u8OUTPUT);
	DIO_enuSetPinDirection(C4_GRB,C4_PIN,DIO_u8OUTPUT);

	DIO_enuSetPinValue(R1_GRB,R1_PIN,DIO_u8PULLUP);
	DIO_enuSetPinValue(R2_GRB,R2_PIN,DIO_u8PULLUP);
	DIO_enuSetPinValue(R3_GRB,R3_PIN,DIO_u8PULLUP);
	DIO_enuSetPinValue(R4_GRB,R4_PIN,DIO_u8PULLUP);

	DIO_enuSetPinValue(C1_GRB , C1_PIN , DIO_u8HIGH);
	DIO_enuSetPinValue(C2_GRB , C2_PIN , DIO_u8HIGH);
	DIO_enuSetPinValue(C3_GRB , C3_PIN , DIO_u8HIGH);
	DIO_enuSetPinValue(C4_GRB , C4_PIN , DIO_u8HIGH);
#else
#error"the KeyPad size is wrong "
#endif

	Local_enuErrorState=ES_OK;

	return Local_enuErrorState;
}

ES_t Keypad_enuGetPressedKey(u8* Copy_Pu8KeyValue){
	ES_t Local_enuErrorState=ES_NOK;
	if(Copy_Pu8KeyValue!=NULL){
		u8 Local_u8RowIter=0,Local_u8RowValue;
		u8 Local_u8ColGRB[]={C1_GRB,C2_GRB,C3_GRB,C4_GRB};
		u8 Local_u8ColPIN[]={C1_PIN,C2_PIN,C3_PIN,C4_PIN};

		u8 Local_u8RowGRB[]={R1_GRB,R2_GRB,R3_GRB,R4_GRB};
		u8 Local_u8RowPIN[]={R1_PIN,R2_PIN,R3_PIN,R4_PIN};
		u8 Local_u8ColIter=0;
		*Copy_Pu8KeyValue=0xff;
		for(;Local_u8ColIter< Col_Num ;Local_u8ColIter++){

			DIO_enuSetPinValue(Local_u8ColGRB[Local_u8ColIter],Local_u8ColPIN[Local_u8ColIter],DIO_u8LOW);

			for(Local_u8RowIter=0;Local_u8RowIter<Row_Num;Local_u8RowIter++){
				DIO_enuGetPinValue(Local_u8RowGRB[Local_u8RowIter],Local_u8RowPIN[Local_u8RowIter],&Local_u8RowValue);

				if(!Local_u8RowValue){
					// for depouncing
					_delay_ms(10);
					DIO_enuGetPinValue(Local_u8RowGRB[Local_u8RowIter],Local_u8RowPIN[Local_u8RowIter],&Local_u8RowValue);
					 if(!Local_u8RowValue){
						 while(!Local_u8RowValue){
							 DIO_enuGetPinValue(Local_u8RowGRB[Local_u8RowIter],Local_u8RowPIN[Local_u8RowIter],&Local_u8RowValue);
						 }

						 //take action
						 u8 Local_Au8KeyValue[Row_Num][Col_Num]= Key_Values;
						 * Copy_Pu8KeyValue=Local_Au8KeyValue[Local_u8RowIter][Local_u8ColIter];

					 }


				}

			}

			DIO_enuSetPinValue(Local_u8ColGRB[Local_u8ColIter],Local_u8ColPIN[Local_u8ColIter],DIO_u8HIGH);
			Local_enuErrorState=ES_OK;
		}
	}
	else{
		Local_enuErrorState=ES_NULL_POINTER;
	}



	return Local_enuErrorState;
}


