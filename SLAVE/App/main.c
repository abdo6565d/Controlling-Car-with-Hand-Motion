
/*
 * main.c
 *
 *  Created on: May 30, 2022
 *      Author: DELL
 */
#define PORTA 		*((volatile u8*)0x3B)
#define DDRA 		*((volatile u8*)0x3A)
#define PINA 		*((volatile u8*)0x39)

#define PORTB 		*((volatile u8*)56)
#define DDRB 		*((volatile u8*)0x37)
#define PINB 		*((volatile u8*)0x36)

#define PORTC 		*((volatile u8*)0x35)
#define DDRC 		*((volatile u8*)0x34)
#define PINC 		*((volatile u8*)0x33)

#define PORTD 		*((volatile u8*)0x32)
#define DDRD 		*((volatile u8*)0x31)

#define PIND 		*((volatile u8*)0x30)
#define CLW		37
#define ACLW	47
#define A		0
#define B		1
#define STOP	4

#include"../Libraries/stdTypes.h"
#include"../Libraries/errorState.h"

#include"../MCAL/DIO/DIO_int.h"
#include "../HAL/LCD/LCD_int.h"
#include "../MCAL/UART/UART_int.h"
#include "../HAL/DcMotor/DCMOTOR_Int.h"

#include <string.h>
#include <util/delay.h>



//************************************************************************Slave***********************************************************************

int main(void){

	DIO_enuInit();
	DCMOTOR_enuInit();
	UART_enuInit();
	LCD_enuInit();

	DIO_enuSetPinDirection(DIO_u8GROUP_D,DIO_u8PIN0,DIO_u8INPUT); 		// SET RX AS INPUT


	DCMOTOR_Start();

	u8 data[2];

	while (1)
	{

		_delay_ms(500);

		DCMOTOR_Start();
		UART_enuRecieveString(&data);



		if(strcmp(data , "NB")==0){

			LCD_enuSendCommand(0X01);
			DCMOTOR_enuSetSpeed(65);
			DCMOTOR_enuSetDirectionAndMotorNum(CLW,A);
			DCMOTOR_enuSetDirectionAndMotorNum(CLW,B);
			LCD_enuSendString("Direction: Back");
			LCD_enuGoToPosition(1,0);
			LCD_enuSendString("Speed : Normal");

		}

		else if(strcmp(data , "NF")==0){

			LCD_enuSendCommand(0X01);
			DCMOTOR_enuSetSpeed(65);
			DCMOTOR_enuSetDirectionAndMotorNum(ACLW,A);
			DCMOTOR_enuSetDirectionAndMotorNum(ACLW,B);
			LCD_enuSendString("Direction: UP");
			LCD_enuGoToPosition(1,0);
			LCD_enuSendString("Speed : Normal");
		}
		else if(strcmp(data , "NR")==0){

			LCD_enuSendCommand(0X01);
			DCMOTOR_enuSetSpeed(65);
			DCMOTOR_enuSetDirectionAndMotorNum(ACLW,A);
			DCMOTOR_enuSetDirectionAndMotorNum(CLW,B);
			LCD_enuSendString("Direction: Right");
			LCD_enuGoToPosition(1,0);
			LCD_enuSendString("Speed : Normal");
		}
		else if(strcmp(data , "NL")==0){

			LCD_enuSendCommand(0X01);
			DCMOTOR_enuSetSpeed(65);
			DCMOTOR_enuSetDirectionAndMotorNum(CLW,A);
			DCMOTOR_enuSetDirectionAndMotorNum(ACLW,B);
			LCD_enuSendString("Direction: Left");
			LCD_enuGoToPosition(1,0);
			LCD_enuSendString("Speed : Normal");
		}
		else if(strcmp(data , "DB")==0){

			LCD_enuSendCommand(0X01);
			DCMOTOR_enuSetSpeed(100);
			DCMOTOR_enuSetDirectionAndMotorNum(CLW,A);
			DCMOTOR_enuSetDirectionAndMotorNum(CLW,B);
			LCD_enuSendString("Direction: Back");
			LCD_enuGoToPosition(1,0);
			LCD_enuSendString("Speed : Double");

		}

		else if(strcmp(data , "DF")==0){

			LCD_enuSendCommand(0X01);
			DCMOTOR_enuSetSpeed(100);
			DCMOTOR_enuSetDirectionAndMotorNum(ACLW,A);
			DCMOTOR_enuSetDirectionAndMotorNum(ACLW,B);
			LCD_enuSendString("Direction: UP");
			LCD_enuGoToPosition(1,0);
			LCD_enuSendString("Speed : Double");
		}
		else if(strcmp(data , "DR")==0){

			LCD_enuSendCommand(0X01);
			DCMOTOR_enuSetSpeed(100);
			DCMOTOR_enuSetDirectionAndMotorNum(ACLW,A);
			DCMOTOR_enuSetDirectionAndMotorNum(CLW,B);
			LCD_enuSendString("Direction: Right");
			LCD_enuGoToPosition(1,0);
			LCD_enuSendString("Speed : Double");
		}
		else if(strcmp(data , "DL")==0){

			LCD_enuSendCommand(0X01);
			DCMOTOR_enuSetSpeed(100);
			DCMOTOR_enuSetDirectionAndMotorNum(CLW,A);
			DCMOTOR_enuSetDirectionAndMotorNum(ACLW,B);
			LCD_enuSendString("Direction: Left");
			LCD_enuGoToPosition(1,0);
			LCD_enuSendString("Speed : Double");

		}
		else if(strcmp(data , "ST")==0){
			LCD_enuSendCommand(0X01);
			DCMOTOR_enuSetDirectionAndMotorNum(STOP,A);
			DCMOTOR_enuSetDirectionAndMotorNum(STOP,B);
			LCD_enuGoToPosition(0,7);
			LCD_enuSendString("CAR");
			LCD_enuGoToPosition(1,3);
			LCD_enuSendString("IS STOPPED");


		}






	}

}





