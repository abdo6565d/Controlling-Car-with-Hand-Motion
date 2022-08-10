/*
 * PWM1_Config.h
 *
 *  Created on: Aug 4, 2022
 *      Author: DELL
 */

#ifndef MCAL_PWM1_PWM1_CONFIG_H_
#define MCAL_PWM1_PWM1_CONFIG_H_

#define F_OSC						16

//[1024,256,64,8,No_prescaling]
#define TIMER1_PRESCALER			256
//[NON_INVERTED,INVERTED]
#define Compare_Output_Mode			NON_INVERTED

//[Fast_PWM,PHASE_CORRECT_PWM]
#define PWM1_MODE					Fast_PWM
//[ICR1,OCR1A1]
#define PWM1_TOP_MODE				ICR1



#endif /* MCAL_PWM1_PWM1_CONFIG_H_ */
