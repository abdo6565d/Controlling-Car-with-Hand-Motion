/*
 * DCMOTOR_Prog.c
 *
 *  Created on: Aug 3, 2022
 *      Author: DELL
 */
#include"../../Libraries/errorState.h"
#include"../../Libraries/stdTypes.h"

#include "../../MCAL/DIO/DIO_int.h"
#include "../../MCAL/PWM0/PWM_Int.h"

#include"DCMOTOR_Config.h"
#include"DCMOTOR_Priv.h"

ES_t DCMOTOR_enuInit(void){
	ES_t Local_enuErrorState =ES_NOK;
	DIO_enuSetPinDirection(Motor1_1GRP,Motor1_1PIN,DIO_u8OUTPUT);
	DIO_enuSetPinDirection(Motor1_2GRP,Motor1_2PIN,DIO_u8OUTPUT);
	DIO_enuSetPinDirection(Motor2_3GRP,Motor2_3PIN,DIO_u8OUTPUT);
	DIO_enuSetPinDirection(Motor2_4GRP,Motor2_4PIN,DIO_u8OUTPUT);

	PWM0_enuInit();

	return Local_enuErrorState ;
}

ES_t DCMOTOR_enuSetDirectionAndMotorNum(u16 Copy_u8Direction,u8 Copy_u8MotorNumber){
	ES_t Local_enuErrorState =ES_NOK;

	switch (Copy_u8MotorNumber){
		case A :			//MOTOR A

			switch(Copy_u8Direction){
				case CLW :
					DIO_enuSetPinValue(Motor1_1GRP,Motor1_1PIN,DIO_u8HIGH);
					DIO_enuSetPinValue(Motor1_2GRP,Motor1_2PIN,DIO_u8LOW);
					break;

				case ACLW:
					DIO_enuSetPinValue(Motor1_1GRP,Motor1_1PIN,DIO_u8LOW);
					DIO_enuSetPinValue(Motor1_2GRP,Motor1_2PIN,DIO_u8HIGH);
					break;
				case STOP :
					DIO_enuSetPinValue(Motor1_1GRP,Motor1_1PIN,DIO_u8LOW);
					DIO_enuSetPinValue(Motor1_2GRP,Motor1_2PIN,DIO_u8LOW);
					break;

				default:
					break;
			}
			break;
		case B:					//MOTOR B
			switch(Copy_u8Direction){
				case CLW :
					DIO_enuSetPinValue(Motor2_3GRP,Motor2_3PIN,DIO_u8HIGH);
					DIO_enuSetPinValue(Motor2_4GRP,Motor2_4PIN,DIO_u8LOW);
					break;

				case ACLW:
					DIO_enuSetPinValue(Motor2_3GRP,Motor2_3PIN,DIO_u8LOW);
					DIO_enuSetPinValue(Motor2_4GRP,Motor2_4PIN,DIO_u8HIGH);
					break;
				case STOP:
					DIO_enuSetPinValue(Motor2_3GRP,Motor2_3PIN,DIO_u8LOW);
					DIO_enuSetPinValue(Motor2_4GRP,Motor2_4PIN,DIO_u8LOW);
					break;
				default:
					break;
			}
			break;

		default:
				break;

	}


	Local_enuErrorState =ES_OK;
	return Local_enuErrorState ;
}
ES_t DCMOTOR_enuSetSpeed(u8 Copy_u8Speed){
	ES_t Local_enuErrorState =ES_NOK;
	PWM0_enuSetDutyCycle(Copy_u8Speed);
	return Local_enuErrorState ;

}

ES_t DCMOTOR_Start(void){
	ES_t Local_enuErrorState =ES_NOK;
	PWM0_Start();
	return Local_enuErrorState ;

}

ES_t DCMOTOR_Stop(void){
	ES_t Local_enuErrorState =ES_NOK;
	PWM0_Stop();
	return Local_enuErrorState ;
}
