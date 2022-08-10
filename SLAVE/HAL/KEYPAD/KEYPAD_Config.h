/*
 * KEYPAD_Config.h
 *
 *  Created on: Jul 16, 2022
 *      Author: DELL
 */

#ifndef HAL_KEYPAD_KEYPAD_CONFIG_H_
#define HAL_KEYPAD_KEYPAD_CONFIG_H_


                           // the maximum pins of KeyPad is 4x4
#define Col_Num				4
#define Row_Num				4

#define R1_GRB				DIO_u8GROUP_C
#define R1_PIN				DIO_u8PIN0
#define R2_GRB				DIO_u8GROUP_C
#define R2_PIN				DIO_u8PIN1
#define R3_GRB				DIO_u8GROUP_C
#define R3_PIN				DIO_u8PIN2
#define R4_GRB				DIO_u8GROUP_C
#define R4_PIN				DIO_u8PIN3


#define C1_GRB				DIO_u8GROUP_D
#define C1_PIN				DIO_u8PIN4
#define C2_GRB				DIO_u8GROUP_D
#define C2_PIN				DIO_u8PIN5
#define C3_GRB				DIO_u8GROUP_D
#define C3_PIN				DIO_u8PIN6
#define C4_GRB				DIO_u8GROUP_D
#define C4_PIN				DIO_u8PIN7

#define Key_Values			{{'7','8','9','A'},\
							 {'4','5','6','B'},\
							 {'1','2','3','E'},\
							 {'C','0','=','D'}}









#endif /* HAL_KEYPAD_KEYPAD_CONFIG_H_ */
