/*
 * DCMOTOR_Int.h
 *
 *  Created on: Aug 3, 2022
 *      Author: DELL
 */

#ifndef HAL_DCMOTOR_DCMOTOR_INT_H_
#define HAL_DCMOTOR_DCMOTOR_INT_H_


ES_t DCMOTOR_enuInit(void);

ES_t DCMOTOR_enuSetDirectionAndMotorNum(u8 Copy_u8Direction,u8 Copy_u8MotorNumber);

ES_t DCMOTOR_enuSetSpeed(u8 Copy_u8Speed);

ES_t DCMOTOR_Start(void);

ES_t DCMOTOR_Stop(void);


#endif /* HAL_DCMOTOR_DCMOTOR_INT_H_ */
