
/*
 * main.c
 *
 *  Created on: May 30, 2022
 *      Author: DELL
 */



#include"../Libraries/stdTypes.h"
#include"../Libraries/errorState.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/ADC/ADC_int.h"
#include "../MCAL/UART/UART_int.h"

#include <util/delay.h>

#define Open      < 800
#define Hold      > 800


//********************************************MASTER*****************************************************************************************************

int main(void){

	u16  THUMB,INDEX,MIDDLE,RING,LITTLE;
	DIO_enuInit();
	ADC_INIT();
	UART_enuInit();
	DIO_enuSetPinDirection(DIO_u8GROUP_D,DIO_u8PIN1,DIO_u8OUTPUT);			// SET TX AS OUTPUT





	while(1){

		_delay_ms(500);
		ADC_START_CONVERSION(0);
		ADC_GET_RESULT(&THUMB);
		_delay_ms(50);
		ADC_START_CONVERSION(1);
		ADC_GET_RESULT(&INDEX);
		_delay_ms(50);
		ADC_START_CONVERSION(2);
		ADC_GET_RESULT(&MIDDLE);
		_delay_ms(50);
		ADC_START_CONVERSION(3);
		ADC_GET_RESULT(&RING);
		_delay_ms(50);
		ADC_START_CONVERSION(4);
		ADC_GET_RESULT(&LITTLE);
		_delay_ms(50);

		if	   (THUMB Open && INDEX Open && MIDDLE Hold && RING Hold && LITTLE Open){

			UART_enuSendString("NF");
			UART_enuSendString("\r\n");			//Carriage Return,Line Feed

		}

		else if	   (THUMB Open && INDEX Hold && MIDDLE Open && RING Open && LITTLE Hold){
			UART_enuSendString("NB");
			UART_enuSendString("\r\n");

		}


		else if	   (THUMB Open && INDEX Hold && MIDDLE Open && RING Open && LITTLE Open){

			UART_enuSendString("NL");
			UART_enuSendString("\r\n");
		}
		else if	   (THUMB Open && INDEX Open && MIDDLE Open && RING Open && LITTLE Hold){

			UART_enuSendString("NR");
			UART_enuSendString("\r\n");
		}
		else if	   (THUMB Hold && INDEX Open && MIDDLE Hold && RING Hold && LITTLE Open){

			UART_enuSendString("DF");
			UART_enuSendString("\r\n");
		}

		else if	   (THUMB Hold && INDEX Hold && MIDDLE Open && RING Open && LITTLE Hold){

			UART_enuSendString("DB");
			UART_enuSendString("\r\n");

		}
		else if	   (THUMB Hold && INDEX Hold && MIDDLE Open && RING Open && LITTLE Open){

			UART_enuSendString("DL");
			UART_enuSendString("\r\n");
		}
		else if	   (THUMB Hold && INDEX Open && MIDDLE Open && RING Open && LITTLE Hold){

			UART_enuSendString("DR");
			UART_enuSendString("\r\n");
		}
		else if	   (THUMB Open && INDEX Open && MIDDLE Open && RING Open && LITTLE Open){

			UART_enuSendString("ST");
			UART_enuSendString("\r\n");
		}
		_delay_ms(1000);

	}

}











