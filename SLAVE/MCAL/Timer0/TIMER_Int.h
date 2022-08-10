/*
 * TIMER_Int.h
 *
 *  Created on: Aug 1, 2022
 *      Author: DELL
 */

#ifndef MCAL_TIMER0_TIMER_INT_H_
#define MCAL_TIMER0_TIMER_INT_H_

ES_t TIMER_enuInit(void);

ES_t TIMER_enuSetDelay(u32 Copy_u32ReservedTime);

ES_t TIMER0_Start(void);

ES_t TIMER0_Stop(void);

void TIMER0_voidSetCallBack(void(*ptr)(void));



#endif /* MCAL_TIMER0_TIMER_INT_H_ */
