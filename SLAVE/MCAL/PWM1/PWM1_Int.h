/*
 * PWM1_Int.h
 *
 *  Created on: Aug 4, 2022
 *      Author: DELL
 */

#ifndef MCAL_PWM1_PWM1_INT_H_
#define MCAL_PWM1_PWM1_INT_H_

ES_t PWM1_enuInit(void);

ES_t PWM1_enuSetFrequency(u32 Copy_u8Frequency);

ES_t PWM1_enuSetDutyCycle(u8 Copy_u8DutyCycle);

ES_t PWM1_Start(void);

ES_t PWM1_Stop(void);

#endif /* MCAL_PWM1_PWM1_INT_H_ */
