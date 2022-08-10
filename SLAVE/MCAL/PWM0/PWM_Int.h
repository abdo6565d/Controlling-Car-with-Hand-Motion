/*
 * PWM_Int.h
 *
 *  Created on: Aug 2, 2022
 *      Author: DELL
 */

#ifndef MCAL_PWM0_PWM_INT_H_
#define MCAL_PWM0_PWM_INT_H_

ES_t PWM0_enuInit(void);

ES_t PWM0_enuSetDutyCycle(u8 Copy_u8DutyCycle);

ES_t PWM0_Start(void);

ES_t PWM0_Stop(void);




#endif /* MCAL_PWM0_PWM_INT_H_ */
