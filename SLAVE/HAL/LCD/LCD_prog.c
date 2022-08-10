/*
 * LCD_prog.c
 *
 *  Created on: Jun 4, 2022
 *      Author: Ahmed El-Gaafrawy
 */
#include "../../Libraries/stdTypes.h"
#include "../../Libraries/errorState.h"


#include "../../MCAL/DIO/DIO_int.h"

#include "LCD_config.h"
#include "LCD_priv.h"

#include <util/delay.h>


ES_t LCD_enuInit(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	_delay_ms(35);
	DIO_enuSetPinDirection(RS_GRP , RS_PIN , DIO_u8OUTPUT);
	DIO_enuSetPinDirection(RW_GRP , RW_PIN , DIO_u8OUTPUT);
	DIO_enuSetPinDirection(EN_GRP , EN_PIN , DIO_u8OUTPUT);

	DIO_enuSetPinDirection(D7_GRP , D7_PIN , DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D6_GRP , D6_PIN , DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D5_GRP , D5_PIN , DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D4_GRP , D4_PIN , DIO_u8OUTPUT);

#if LCD_MODE == EIGHT_BIT

	DIO_enuSetPinDirection(D3_GRP , D3_PIN , DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D2_GRP , D2_PIN , DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D1_GRP , D1_PIN , DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D0_GRP , D0_PIN , DIO_u8OUTPUT);

	DIO_enuSetPinValue(RS_GRP , RS_PIN , DIO_u8LOW);
	LCD_enuWriteNLatch(0x38);

#elif LCD_MODE == FOUR_BIT
	DIO_enuSetPinValue(RS_GRP , RS_PIN , DIO_u8LOW);

	DIO_enuSetPinValue(D7_GRP , D7_PIN ,  0 );
	DIO_enuSetPinValue(D6_GRP , D6_PIN ,  0 );
	DIO_enuSetPinValue(D5_GRP , D5_PIN ,  1 );
	DIO_enuSetPinValue(D4_GRP , D4_PIN ,  0 );

	DIO_enuSetPinValue(EN_GRP , EN_PIN ,  DIO_u8HIGH );
	_delay_ms (2);
	DIO_enuSetPinValue(EN_GRP , EN_PIN ,  DIO_u8LOW );
	_delay_ms (2);

	LCD_enuWriteNLatch(0x28);

#else
#error "LCD mode is wrong ya 7ayawan"
#endif

	//display control
	DIO_enuSetPinValue(RS_GRP , RS_PIN , DIO_u8LOW);
	LCD_enuWriteNLatch(0x0F);

	//clear display control
	DIO_enuSetPinValue(RS_GRP , RS_PIN , DIO_u8LOW);
	LCD_enuWriteNLatch(0x1);

	//entry set
	DIO_enuSetPinValue(RS_GRP , RS_PIN , DIO_u8LOW);
	LCD_enuWriteNLatch(0x6);

	return Local_enuErrorState;
}

ES_t LCD_enuSendData(u8 Copy_u8Data)
{
	ES_t Local_enuErrorState = ES_NOK;

	DIO_enuSetPinValue(RS_GRP , RS_PIN , DIO_u8HIGH);
	LCD_enuWriteNLatch(Copy_u8Data);

	return Local_enuErrorState;
}

ES_t LCD_enuSendCommand(u8 Copy_u8Cmnd)
{
	ES_t Local_enuErrorState = ES_NOK;

	DIO_enuSetPinValue(RS_GRP , RS_PIN , DIO_u8LOW);
	//SEND DATA & LATCH
	LCD_enuWriteNLatch(Copy_u8Cmnd);

	return Local_enuErrorState;
}

ES_t LCD_enuSendString(const char * Copy_pcString)
{
	if (Copy_pcString != NULL)
	{
		while (*Copy_pcString)
		{
			LCD_enuSendData(*Copy_pcString++);
		}
	}
}

ES_t LCD_enuGoToPosition(u8 Copy_u8Row , u8 Copy_u8Column){
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_u8Row<2 && Copy_u8Column<16){
		u8 address = Copy_u8Row * 0x40 +Copy_u8Column; // row one:0x00 to 0x0f,row two :0x40 to 0x4f
		address|=(1<<7);                             //for set an address location you must set 1 in pin 7 in the address
		LCD_enuSendCommand(address);
		Local_enuErrorState = ES_OK;

	}


	return Local_enuErrorState;
}

ES_t LCD_enuStoreCustom(u8* Copy_pu8Pattern , u8 Copy_u8CGRamIndex){
	ES_t Local_enuErrorState = ES_NOK;
	u8 address;
	u8 index=0;
	if(Copy_u8CGRamIndex<8){           //CGRAM contain 8 locations.
		address= Copy_u8CGRamIndex * 8;
		address|=(1<<6);      //set CGRAM Address
		LCD_enuSendCommand(address);
		for(;index<8;index++){
			LCD_enuSendData(Copy_pu8Pattern[index]);
		}
		Local_enuErrorState = ES_OK;
	}
	LCD_enuSendCommand(0x02);
	return Local_enuErrorState ;
}

ES_t LCD_enuDisplayCustom(u8 Copy_u8CGRamIndex){
	LCD_enuSendData(Copy_u8CGRamIndex);
	return ES_OK;
}

ES_t LCD_enuSendIntegerNum(s32 Copy_s32Num){
	ES_t Local_enuErrorState = ES_NOK;
	u8 num[13]={0} , digit=0 , modelus;
	s32 reminder =Copy_s32Num;
	if(Copy_s32Num != 0){
		if(Copy_s32Num < 0){
			LCD_enuSendData('-');
			Copy_s32Num*=-1;
			reminder*=-1;
		}
		while(Copy_s32Num){
			digit++;
			Copy_s32Num/=10;
		}
		Copy_s32Num=reminder;
		while(Copy_s32Num){
			modelus=Copy_s32Num % 10;
			num[digit-1]=modelus+'0';
			Copy_s32Num/=10;
			digit--;
		}
		while(num[digit]){
			LCD_enuSendData(num[digit++]);
		}
	}
	else{
		LCD_enuSendData('0');
		Local_enuErrorState = ES_OK;

	}

	return Local_enuErrorState;

}

static ES_t LCD_enuWriteNLatch(u8 Copy_u8Byte)
{
	DIO_enuSetPinValue( RW_GRP , RW_PIN , DIO_u8LOW); //RW
	DIO_enuSetPinValue( EN_GRP , EN_PIN , DIO_u8LOW); //EN

#if LCD_MODE == EIGHT_BIT

	DIO_enuSetPinValue(D7_GRP , D7_PIN ,  ((Copy_u8Byte >> 7) & 1) );
	DIO_enuSetPinValue(D6_GRP , D6_PIN ,  ((Copy_u8Byte >> 6) & 1) );
	DIO_enuSetPinValue(D5_GRP , D5_PIN ,  ((Copy_u8Byte >> 5) & 1) );
	DIO_enuSetPinValue(D4_GRP , D4_PIN ,  ((Copy_u8Byte >> 4) & 1) );
	DIO_enuSetPinValue(D3_GRP , D3_PIN ,  ((Copy_u8Byte >> 3) & 1) );
	DIO_enuSetPinValue(D2_GRP , D2_PIN ,  ((Copy_u8Byte >> 2) & 1) );
	DIO_enuSetPinValue(D1_GRP , D1_PIN ,  ((Copy_u8Byte >> 1) & 1) );
	DIO_enuSetPinValue(D0_GRP , D0_PIN ,  ((Copy_u8Byte >> 0) & 1) );


	DIO_enuSetPinValue(EN_GRP , EN_PIN ,  DIO_u8HIGH );
	_delay_ms (2);
	DIO_enuSetPinValue(EN_GRP , EN_PIN ,  DIO_u8LOW );
	_delay_ms (2);


#elif LCD_MODE == FOUR_BIT

	DIO_enuSetPinValue(D7_GRP , D7_PIN ,  ((Copy_u8Byte >> 7) & 1) );
	DIO_enuSetPinValue(D6_GRP , D6_PIN ,  ((Copy_u8Byte >> 6) & 1) );
	DIO_enuSetPinValue(D5_GRP , D5_PIN ,  ((Copy_u8Byte >> 5) & 1) );
	DIO_enuSetPinValue(D4_GRP , D4_PIN ,  ((Copy_u8Byte >> 4) & 1) );

	DIO_enuSetPinValue(EN_GRP , EN_PIN ,  DIO_u8HIGH );
	_delay_ms (2);
	DIO_enuSetPinValue(EN_GRP , EN_PIN ,  DIO_u8LOW );
	_delay_ms (2);

	DIO_enuSetPinValue(D7_GRP , D7_PIN ,  ((Copy_u8Byte >> 3) & 1) );
	DIO_enuSetPinValue(D6_GRP , D6_PIN ,  ((Copy_u8Byte >> 2) & 1) );
	DIO_enuSetPinValue(D5_GRP , D5_PIN ,  ((Copy_u8Byte >> 1) & 1) );
	DIO_enuSetPinValue(D4_GRP , D4_PIN ,  ((Copy_u8Byte >> 0) & 1) );


	DIO_enuSetPinValue(EN_GRP , EN_PIN ,  DIO_u8HIGH );
	_delay_ms (2);
	DIO_enuSetPinValue(EN_GRP , EN_PIN ,  DIO_u8LOW );
	_delay_ms (2);

#else
#error "LCD mode is wrong ya 7ayawan"
#endif

}


