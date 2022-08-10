/*
 * LCD_int.h
 *
 *  Created on: Jun 4, 2022
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef HAL_LCD_LCD_INT_H_
#define HAL_LCD_LCD_INT_H_

ES_t LCD_enuInit(void);

ES_t LCD_enuSendData(u8 Copy_u8Data);

ES_t LCD_enuSendCommand(u8 Copy_u8Cmnd);

ES_t LCD_enuSendString(const char * Copy_pcString);

ES_t LCD_enuGoToPosition(u8 Copy_u8Row , u8 Copy_u8Column);

ES_t LCD_enuStoreCustom(u8* Copy_pu8Pattern , u8 Copy_u8CGRamIndex);

ES_t LCD_enuDisplayCustom(u8 Copy_u8CGRamIndex);

ES_t LCD_enuSendIntegerNum(s32 Copy_s32Num);
#endif /* HAL_LCD_LCD_INT_H_ */
