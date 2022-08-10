/*
 * PWM_Config.h
 *
 *  Created on: Aug 2, 2022
 *      Author: DELL
 */

#ifndef MCAL_PWM0_PWM_CONFIG_H_
#define MCAL_PWM0_PWM_CONFIG_H_

#define F_OSC						16

//[1024,256,64,8,No_prescaling]
#define TIMER0_PRESCALER			1024
//[NON_INVERTED,INVERTED]
#define Compare_Output_Mode			NON_INVERTED

//[Fast_PWM,PHASE_CORRECT_PWM]
#define PWM_MODE					Fast_PWM

#endif /* MCAL_PWM0_PWM_CONFIG_H_ */
