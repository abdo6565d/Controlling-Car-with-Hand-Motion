/*
 * TIMER_Prog.c
 *
 *
 *  Created on: Aug 1, 2022
 *      Author: DELL
 */
#include"../../Libraries/errorState.h"
#include"../../Libraries/stdTypes.h"



#include "../Timer0/TIMER_Config.h"
#include "../Timer0/TIMER_Priv.h"


u32 TIMER0_u32OverFlow=0;
u8  TIMER_0_u32Rem=0;
u32 TIMER0_u32CompareMatch= 0 ;

void(*callback)(void) =	NULL;

ES_t TIMER_enuInit(void){
	ES_t Local_enuErrorState =ES_NOK;


#if TIMER0_MODE ==  NORMAL_MODE
	TCCR0 &=~(1<<3);
	TCCR0 &=~(1<<6);
	//to enable overflow interrupt
	SREG |=(1<<7);
	TIMSK |=(1<<0);
#elif TIMER0_MODE == CTC_MODE
	TCCR0 |=(1<<3);
	TCCR0 &=~(1<<6);
	//to enable Compare Match Interrupt
	SREG |=(1<<7);
	TIMSK |=(1<<1);

#endif




	return Local_enuErrorState;

}
ES_t TIMER_enuSetDelay(u32 Copy_u32ReservedTime){
	ES_t Local_enuErrorState= ES_NOK;
#if TIMER0_MODE ==  NORMAL_MODE
	u32 Local_u32TickTime   = TIMER0_PRESCALER / F_OSC;		//the valu in MicroSec
	u32 Local_u32TotalTicks = (Copy_u32ReservedTime *1000)/ Local_u32TickTime ;
		TIMER0_u32OverFlow  = Local_u32TotalTicks / 256;
		TIMER_0_u32Rem      = Local_u32TotalTicks % 256;
		if(TIMER_0_u32Rem != 0){
			TCNT0 = 265 - TIMER_0_u32Rem;
			TIMER0_u32OverFlow++;			//to calculate the added ticks in the  Local_u32Rem
		}
#elif TIMER0_MODE == CTC_MODE
		u32 Local_u32TickTime   = TIMER0_PRESCALER / F_OSC;
		u32 Local_u32TotalTicks = (Copy_u32ReservedTime *1000)/ Local_u32TickTime ;
		u8  Local_u8DividedNumber = 255;
		while(Local_u32TotalTicks % Local_u8DividedNumber){
			Local_u8DividedNumber--;
		}
		TIMER0_u32CompareMatch = Local_u32TotalTicks / Local_u8DividedNumber;
		OCR0 = Local_u8DividedNumber-1;

#endif

		Local_enuErrorState= ES_OK;
	    return Local_enuErrorState;
}

ES_t TIMER0_Start(void){
	ES_t Local_enuErrorState= ES_NOK;
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
	Local_enuErrorState= ES_OK;
	return Local_enuErrorState;
}

ES_t TIMER0_Stop(void){
	ES_t Local_enuErrorState= ES_NOK;
	TCCR0 &=~(7<<0);
	Local_enuErrorState= ES_OK;
	return Local_enuErrorState;
}

void TIMER0_voidSetCallBack(void(*ptr)(void)){
	callback = ptr;
}

void __vector_11(void)__attribute__((signal));
void __vector_11(void){
	static u32 Local_u32Counter =0;
			   Local_u32Counter++;
			   if(Local_u32Counter == TIMER0_u32OverFlow){
				   callback();
				   Local_u32Counter =0;
				   TCNT0 = 265 - TIMER_0_u32Rem;

			   }


}
void __vector_10(void)__attribute__((signal));
void __vector_10(void){
	static u32 Local_u32Counter =0;
			   Local_u32Counter++;
			   if(Local_u32Counter == TIMER0_u32CompareMatch){
				   callback();
				   Local_u32Counter =0;


			   }


}

