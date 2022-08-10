/*
 * EXTI_Prog.c
 *
 *  Created on: Jun 30, 2022
 *      Author: DELL
 */
#include"../../Libraries/stdTypes.h"
#include"../../Libraries/errorState.h"



#include"EXTI_Config.h"
#include"EXTI_Priv.h"

extern u8 EXTI_u8InterNumber;
void(*callbac)(void) =	NULL;
ES_t EXTI_enuInit(EXTI_t * Copy_pAstrEXTIConfig){
	ES_t Local_enuErrorState = ES_NOK;
	if (Copy_pAstrEXTIConfig !=NULL){
		u8 Local_u8Iter=0;
		for(;Local_u8Iter<EXTI_u8InterNumber;Local_u8Iter++){
			if(Copy_pAstrEXTIConfig[Local_u8Iter].IntPin == INT0){
				if(Copy_pAstrEXTIConfig[Local_u8Iter].InterruptState == Enable){
					GICR|=(1<<6);
				}
				else if(Copy_pAstrEXTIConfig[Local_u8Iter].InterruptState == Disable){
					GICR &=~(1<<6);
				}
				switch(Copy_pAstrEXTIConfig[Local_u8Iter].SenseLevel){
				case Low_level:
					MCUCR &= ~(3<<0);
					break;
				case AnyLogic:
					MCUCR |= (1<<0);
					break;
				case Rising:
					MCUCR |=(3<<0);
					break;
				case Falling:
					MCUCR |=(2<<0);
					break;
				default:
					Local_enuErrorState = ES_OUT_OF_RANGE;

				}
			}
			else if(Copy_pAstrEXTIConfig[Local_u8Iter].IntPin == INT1){
				if (Copy_pAstrEXTIConfig[Local_u8Iter].InterruptState == Enable){
					GICR|=(1<<7);
				}
				else if (Copy_pAstrEXTIConfig[Local_u8Iter].InterruptState == Disable){
					GICR &=~(1<<7);

				}
				switch(Copy_pAstrEXTIConfig[Local_u8Iter].SenseLevel){
				case Low_level:
					MCUCR &=~(3<<2);
					break;
				case AnyLogic:
					MCUCR &=~(2<<2);
					break;
				case Rising:
					MCUCR |=(3<<2);
					break;
				case Falling:
					MCUCR |=(2<<2);
					break;
				default:
					Local_enuErrorState = ES_OUT_OF_RANGE;


				}


			}
			else if(Copy_pAstrEXTIConfig[Local_u8Iter].IntPin == INT2){
				if (Copy_pAstrEXTIConfig[Local_u8Iter].InterruptState == Enable){
					GICR |=(1<<5);
				}
				else if (Copy_pAstrEXTIConfig[Local_u8Iter].InterruptState == Disable){
					GICR&=~(1<<5);
				}
				switch(Copy_pAstrEXTIConfig[Local_u8Iter].SenseLevel){
				case Rising:
					MCUCSR |=(1<<6);
					break;
				case Falling:
					MCUCSR &=~(1<<6);
					break;
				default:
					Local_enuErrorState = ES_OUT_OF_RANGE;

				}
			}


		}
		Local_enuErrorState=ES_OK;
	}
	else{
		Local_enuErrorState=ES_NULL_POINTER;
	}

	return Local_enuErrorState;

}
ES_t EXTI_enuSenseLevel(EXTI_t *Copy_pstrInteNumber,u8 Copy_u8SenseLevel){

	ES_t Local_enuErrorState=ES_NOK;
	if(!Local_enuErrorState){
		if(Copy_pstrInteNumber ->IntPin == INT0){

			switch(Copy_u8SenseLevel){
			case Low_level:
				MCUCR &= ~(3<<0);
				break;
			case AnyLogic:
				MCUCR |= (1<<0);
				break;
			case Rising:
				MCUCR |=(3<<0);
				break;
			case Falling:
				MCUCR |=(2<<0);
				break;
			default:
				Local_enuErrorState = ES_OUT_OF_RANGE;

			}
		}
		else if(Copy_pstrInteNumber ->IntPin == INT1 ){

			switch(Copy_u8SenseLevel){
			case Low_level:
				MCUCR &=~(3<<2);
				break;
			case AnyLogic:
				MCUCR &=~(2<<2);
				break;
			case Rising:
				MCUCR |=(3<<2);
				break;
			case Falling:
				MCUCR |=(2<<2);
				break;
			default:
				Local_enuErrorState = ES_OUT_OF_RANGE;


			}
		}
		else if(Copy_pstrInteNumber ->IntPin == INT2){

			switch(Copy_u8SenseLevel){
			case Rising:
				MCUCSR |=(1<<6);
				break;
			case Falling:
				MCUCSR &=~(1<<6);
				break;
			default:
				Local_enuErrorState = ES_OUT_OF_RANGE;

			}
		}

		Local_enuErrorState=ES_OK;

	}
	else{
		Local_enuErrorState=ES_NULL_POINTER;
	}
	return Local_enuErrorState;



}
ES_t EXTI_enuEnableInterrupt(EXTI_t *Copy_pstrInteNumber){
	ES_t Local_enuErrorState=ES_NOK;
	if(!Copy_pstrInteNumber){
		if(Copy_pstrInteNumber ->IntPin == INT0){
			GICR|=(1<<6);
		}
		else if(Copy_pstrInteNumber ->IntPin == INT1){
			GICR|=(1<<7);
		}
		else if(Copy_pstrInteNumber ->IntPin == INT2){
			GICR|=(1<<5);
		}
		Local_enuErrorState=ES_OK;
	}
	else{
		Local_enuErrorState=ES_NULL_POINTER;
	}
	return Local_enuErrorState;
}
ES_t EXTI_enuDisableInterrupt(EXTI_t *Copy_pstrInteNumber){
	ES_t Local_enuErrorState=ES_NOK;
	if(!Copy_pstrInteNumber){
		if(Copy_pstrInteNumber ->IntPin == INT0){
			GICR|=(0<<6);
		}
		else if(Copy_pstrInteNumber ->IntPin == INT1){
			GICR|=(0<<7);
		}
		else if(Copy_pstrInteNumber ->IntPin == INT2){
			GICR|=(0<<5);
		}
		Local_enuErrorState=ES_OK;
	}
	else{
		Local_enuErrorState=ES_NULL_POINTER;
	}
	return Local_enuErrorState;

}

void EXTI_voidSetCallBack(void(*ptr)(void)){
	callbac = ptr;
}


void __vector_1(void)__attribute__((signal));
void __vector_2(void)__attribute__((signal));
void __vector_3(void)__attribute__((signal));

void __vector_1(void){
	callbac();
}

