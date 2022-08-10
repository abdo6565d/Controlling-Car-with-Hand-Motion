/*
 * EXTI_Config.h
 *
 *  Created on: Jun 30, 2022
 *      Author: DELL
 */

#ifndef MCAL_EXTI_EXTI_CONFIG_H_
#define MCAL_EXTI_EXTI_CONFIG_H_
typedef struct{
	u8 IntPin;
	u8 InterruptState;
	u8 SenseLevel;


}EXTI_t;

#define InterNum 	3

#endif /* MCAL_EXTI_EXTI_CONFIG_H_ */
