/*
 * DIO_prog2.c
 *
 *  Created on: May 30, 2022
 *      Author: DELL
 */

#include "../../Libraries/stdTypes.h"
//#include "BIT_MATH.h"
#include "../../Libraries/errorState.h"


//lower libraries
#include "DIO_int.h"

//own libraries
#include "DIO_priv.h"
#include "DIO_config.h"

ES_t DIO_enuInit(void){
	ES_t Local_enuErrorState=ES_NOK ;
#if DIO_u8PA0DIR == DIO_u8INPUT
	DDRA&=~(1<<0);
#elif DIO_u8PA0DIR == DIO_u8OUTPUT
	DDRA|=(1<<0);
#else
#error "Direction of pin A is wrong !!"
#endif

#if DIO_u8PA1DIR == DIO_u8OUTPUT
	DDRA|=(1<<1);
#elif DIO_u8PA1DIR == DIO_u8INPUT
	DDRA&=~(1<<1);
#else
#error "Direction of pin A is wrong !!"
#endif

#if DIO_u8PA2DIR == DIO_u8OUTPUT
	DDRA|=(1<<2);
#elif DIO_u8PA2DIR == DIO_u8INPUT
	DDRA&=~(1<<2);
#else
#error "Direction of pin A is wrong !!"
#endif

#if DIO_u8PA3DIR == DIO_u8OUTPUT
	DDRA|=(1<<3);
#elif DIO_u8PA31DIR == DIO_u8INPUT
	DDRA&=~(1<<3);
#else
#error "Direction of pin A is wrong !!"
#endif

#if DIO_u8PA4DIR == DIO_u8OUTPUT
	DDRA|=(1<<4);
#elif DIO_u8PA4DIR == DIO_u8INPUT
	DDRA&=~(1<<4);
#else
#error "Direction of pin A is wrong !!"
#endif

#if DIO_u8PA5DIR == DIO_u8OUTPUT
	DDRA|=(1<<5);
#elif DIO_u8PA5DIR == DIO_u8INPUT
	DDRA&=~(1<<5);
#else
#error "Direction of pin A is wrong !!"
#endif

#if DIO_u8PA6DIR == DIO_u8OUTPUT
	DDRA|=(1<<6);
#elif DIO_u8PA6DIR == DIO_u8INPUT
	DDRA&=~(1<<6);
#else
#error "Direction of pin A is wrong !!"
#endif

#if DIO_u8PA7DIR == DIO_u8OUTPUT
	DDRA|=(1<<7);
#elif DIO_u8PA7DIR == DIO_u8INPUT
	DDRA&=~(1<<7);
#else
#error "Direction of pin A is wrong !!"
#endif



//    B pins
#if DIO_u8PB0DIR == DIO_u8OUTPUT
	DDRB|=(1<<0);
#elif DIO_u8PB0DIR == DIO_u8INPUT
	DDRB&=~(1<<0);
#else
#error "Direction of pin B is wrong !!"
#endif

#if DIO_u8PB1DIR == DIO_u8OUTPUT
	DDRB|=(1<<1);
#elif DIO_u8PB1DIR == DIO_u8INPUT
	DDRB&=~(1<<1);
#else
#error "Direction of pin B is wrong !!"
#endif

#if DIO_u8PB2DIR == DIO_u8OUTPUT
	DDRB|=(1<<2);
#elif DIO_u8PB2DIR == DIO_u8INPUT
	DDRB&=~(1<<2);
#else
#error "Direction of pin B is wrong !!"
#endif

#if DIO_u8PB3DIR == DIO_u8OUTPUT
	DDRB|=(1<<3);
#elif DIO_u8PB3DIR == DIO_u8INPUT
	DDRB&=~(1<<3);
#else
#error "Direction of pin B is wrong !!"
#endif

#if DIO_u8PB4DIR == DIO_u8OUTPUT
	DDRB|=(1<<4);
#elif DIO_u8PB4DIR == DIO_u8INPUT
	DDRB&=~(1<<4);
#else
#error "Direction of pin B is wrong !!"
#endif

#if DIO_u8PB5DIR == DIO_u8OUTPUT
	DDRB|=(1<<5);
#elif DIO_u8PB5DIR == DIO_u8INPUT
	DDRB&=~(1<<5);
#else
#error "Direction of pin B is wrong !!"
#endif

#if DIO_u8PB6DIR == DIO_u8OUTPUT
	DDRB|=(1<<6);
#elif DIO_u8PB6DIR == DIO_u8INPUT
	DDRB&=~(1<<6);
#else
#error "Direction of pin B is wrong !!"
#endif

#if DIO_u8PB7DIR == DIO_u8OUTPUT
	DDRB|=(1<<7);
#elif DIO_u8PB7DIR == DIO_u8INPUT
	DDRB&=~(1<<7);

#else
#error "Direction of pin B is wrong !!"
#endif

//    C pins
#if DIO_u8PC0DIR == DIO_u8OUTPUT
	DDRC|=(1<<0);
#elif DIO_u8PC0DIR == DIO_u8INPUT
	DDRC&=~(1<<0);
#else
#error "Direction of pin C is wrong !!"
#endif

#if DIO_u8PC1DIR == DIO_u8OUTPUT
	DDRC|=(1<<1);
#elif DIO_u8PC1DIR == DIO_u8INPUT
	DDRC&=~(1<<1);
#else
#error "Direction of pin C is wrong !!"
#endif

#if DIO_u8PC2DIR == DIO_u8OUTPUT
	DDRC|=(1<<2);
#elif DIO_u8PC2DIR == DIO_u8INPUT
	DDRC&=~(1<<2);
#else
#error "Direction of pin C is wrong !!"
#endif

#if DIO_u8PC3DIR == DIO_u8OUTPUT
	DDRC|=(1<<3);
#elif DIO_u8PC3DIR == DIO_u8INPUT
	DDRC&=~(1<<3);
#else
#error "Direction of pin C is wrong !!"
#endif

#if DIO_u8PC4DIR == DIO_u8OUTPUT
	DDRC|=(1<<4);
#elif DIO_u8PC4DIR == DIO_u8INPUT
	DDRC&=~(1<<4);
#else
#error "Direction of pin C is wrong !!"
#endif

#if DIO_u8PC5DIR == DIO_u8OUTPUT
	DDRC|=(1<<5);
#elif DIO_u8PC5DIR == DIO_u8INPUT
	DDRC&=~(1<<5);
#else
#error "Direction of pin C is wrong !!"
#endif

#if DIO_u8PC6DIR == DIO_u8OUTPUT
	DDRC|=(1<<6);
#elif DIO_u8PC6DIR == DIO_u8INPUT
	DDRC&=~(1<<6);
#else
#error "Direction of pin C is wrong !!"
#endif

#if DIO_u8PC7DIR == DIO_u8OUTPUT
	DDRC|=(1<<7);
#elif DIO_u8PC7DIR == DIO_u8INPUT
	DDRC&=~(1<<7);

#else
#error "Direction of pin C is wrong !!"
#endif

// D pins
#if DIO_u8PD0DIR == DIO_u8OUTPUT
	DDRD|=(1<<0);
#elif DIO_u8PD0DIR == DIO_u8INPUT
	DDRD&=~(1<<0);
#else
#error "Direction of pin D is wrong !!"
#endif

#if DIO_u8PD1DIR == DIO_u8OUTPUT
	DDRD|=(1<<1);
#elif DIO_u8PD1DIR == DIO_u8INPUT
	DDRD&=~(1<<1);
#else
#error "Direction of pin D is wrong !!"
#endif

#if DIO_u8PD2DIR == DIO_u8OUTPUT
	DDRD|=(1<<2);
#elif DIO_u8PD2DIR == DIO_u8INPUT
	DDRD&=~(1<<2);
#else
#error "Direction of pin D is wrong !!"
#endif

#if DIO_u8PD3DIR == DIO_u8OUTPUT
	DDRD|=(1<<3);
#elif DIO_u8PD3DIR == DIO_u8INPUT
	DDRD&=~(1<<3);
#else
#error "Direction of pin D is wrong !!"
#endif

#if DIO_u8PD4DIR == DIO_u8OUTPUT
	DDRD|=(1<<4);
#elif DIO_u8PD4DIR == DIO_u8INPUT
	DDRD&=~(1<<4);
#else
#error "Direction of pin D is wrong !!"
#endif

#if DIO_u8PD5DIR == DIO_u8OUTPUT
	DDRD|=(1<<5);
#elif DIO_u8PD5DIR == DIO_u8INPUT
	DDRD&=~(1<<5);
#else
#error "Direction of pin D is wrong !!"
#endif

#if DIO_u8PD6DIR == DIO_u8OUTPUT
	DDRD|=(1<<6);
#elif DIO_u8PD6DIR == DIO_u8INPUT
	DDRD&=~(1<<6);
#else
#error "Direction of pin D is wrong !!"
#endif

#if DIO_u8PD7DIR == DIO_u8OUTPUT
	DDRD|=(1<<7);
#elif DIO_u8PD7DIR == DIO_u8INPUT
	DDRD&=~(1<<7);

#else
#error "Direction of pin A is wrong !!"
#endif
	Local_enuErrorState=ES_OK;
	return Local_enuErrorState;
}
ES_t DIO_enuSetPinDirection(u8 Copy_u8GroupID, u8 Copy_u8PinID, u8 Copy_u8Direction){     //  set input or output pin
	ES_t Local_enuErrorState = ES_NOK;
	if (Copy_u8GroupID <= DIO_u8GROUP_D && Copy_u8PinID<=DIO_u8PIN7 && Copy_u8Direction<=DIO_u8OUTPUT){
		switch(Copy_u8GroupID){
		case DIO_u8GROUP_A :
			DDRA &=~(DIO_BIT_MASK<<Copy_u8PinID);
			DDRA |=(Copy_u8Direction<<Copy_u8PinID);  //SET OR CLEAR
			break;
		case DIO_u8GROUP_B :
			DDRB &=~(DIO_BIT_MASK<<Copy_u8PinID);
			DDRB |=(Copy_u8Direction<<Copy_u8PinID);  //SET OR CLEAR
			break;
		case DIO_u8GROUP_C :
			DDRC &=~(DIO_BIT_MASK<<Copy_u8PinID);
			DDRC |=(Copy_u8Direction<<Copy_u8PinID);  //SET OR CLEAR
			break;
		case DIO_u8GROUP_D :
			DDRD &=~(DIO_BIT_MASK<<Copy_u8PinID);
			DDRD |=(Copy_u8Direction<<Copy_u8PinID);  //SET OR CLEAR
			break;

		}
		Local_enuErrorState=ES_OK;

	}
	else{
		Local_enuErrorState=ES_OUT_OF_RANGE;
	}
	return Local_enuErrorState;

}
ES_t DIO_enuSetPinValue(u8 Copy_u8GroupID, u8 Copy_u8PinID, u8 Copy_u8Value){				//  set or clear pin
	ES_t Local_enuErrorState = ES_NOK;
	if (Copy_u8GroupID <= DIO_u8GROUP_D && Copy_u8PinID<=DIO_u8PIN7 && Copy_u8Value <=DIO_u8OUTPUT){
		switch(Copy_u8GroupID){
		case DIO_u8GROUP_A:
			PORTA &=~(DIO_BIT_MASK<<Copy_u8PinID);
			PORTA |=(Copy_u8Value<<Copy_u8PinID);
			break;
		case DIO_u8GROUP_B:
			PORTB &=~(DIO_BIT_MASK<<Copy_u8PinID);
			PORTB |=(Copy_u8Value<<Copy_u8PinID);
			break;
		case DIO_u8GROUP_C:
			PORTC &=~(DIO_BIT_MASK<<Copy_u8PinID);
			PORTC |=(Copy_u8Value<<Copy_u8PinID);
			break;
		case DIO_u8GROUP_D:
			PORTD &=~(DIO_BIT_MASK<<Copy_u8PinID);
			PORTD |=(Copy_u8Value<<Copy_u8PinID);
			break;
		}
		Local_enuErrorState = ES_OK;
	}
	else{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}
	return Local_enuErrorState ;
}
ES_t DIO_enuTogglePinValue(u8 Copy_u8GroupID, u8 Copy_u8PinID){
	ES_t Local_enuErrorState = ES_NOK;

	if (Copy_u8GroupID <= DIO_u8GROUP_D &&
			Copy_u8PinID <= DIO_u8PIN7 )
	{
		switch (Copy_u8GroupID)
		{
		case DIO_u8GROUP_A:
			PORTA ^=  (DIO_BIT_MASK << Copy_u8PinID);
			break;

		case DIO_u8GROUP_B:
			PORTB ^=  (DIO_BIT_MASK << Copy_u8PinID);

			break;

		case DIO_u8GROUP_C:
			PORTC ^=  (DIO_BIT_MASK << Copy_u8PinID);

			break;

		case DIO_u8GROUP_D:
			PORTD ^=  (DIO_BIT_MASK << Copy_u8PinID);

			break;

		}

		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}
ES_t DIO_enuGetPinValue(u8 Copy_u8GroupID, u8 Copy_u8PinID, u8 * Copy_u8PinValue){       // get the value of the input pin(0/1)
	ES_t Local_enuErrorState = ES_NOK;
	if( Copy_u8PinValue != '\0'){
		if (Copy_u8GroupID <= DIO_u8GROUP_D &&
					Copy_u8PinID <= DIO_u8PIN7 )
			{
				switch (Copy_u8GroupID)
				{
				case DIO_u8GROUP_A:
					* Copy_u8PinValue =  ( (PINA>>Copy_u8PinID)& DIO_BIT_MASK);
					break;

				case DIO_u8GROUP_B:
					* Copy_u8PinValue =  ( (PINB>>Copy_u8PinID)& DIO_BIT_MASK);

					break;

				case DIO_u8GROUP_C:
					* Copy_u8PinValue =  ( (PINC>>Copy_u8PinID)& DIO_BIT_MASK);

					break;

				case DIO_u8GROUP_D:
					* Copy_u8PinValue =  ( (PIND>>Copy_u8PinID)& DIO_BIT_MASK);

					break;

				}

				Local_enuErrorState = ES_OK;
			}
			else
			{
				Local_enuErrorState = ES_OUT_OF_RANGE;
			}
	}
	else{
		Local_enuErrorState = ES_NULL_POINTER;
	}


	return Local_enuErrorState;
}
