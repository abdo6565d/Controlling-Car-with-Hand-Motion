/*
 * EXTI_Int.h
 *
 *  Created on: Jun 30, 2022
 *      Author: DELL
 */

#ifndef MCAL_EXTI_EXTI_INT_H_
#define MCAL_EXTI_EXTI_INT_H_

ES_t EXTI_enuInit(EXTI_t * Copy_pAstrEXTIConfig);

ES_t EXTI_enuSenseLevel(EXTI_t * Copy_pstrInteNumber, u8 Copy_u8SenseLevel);

ES_t EXTI_enuEnableInterrupt(EXTI_t* Copy_pstrInteNumber);

ES_t EXTI_enuDisableInterrupt(EXTI_t* Copy_pstrInteNumber);

void EXTI_voidSetCallBack(void(*ptr)(void));

#endif /* MCAL_EXTI_EXTI_INT_H_ */
