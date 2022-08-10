/*
 * ADC_Config.h
 *
 *  Created on: Jul 27, 2022
 *      Author: DELL
 */

#ifndef MCAL_ADC_ADC_CONFIG_H_
#define MCAL_ADC_ADC_CONFIG_H_
// The selection of voltages is [AREF,AVCC, TwoAndHalfV]

#define VoltageReference		AVCC

//The selection of adjust is [RightAdjust,LeftAdjust]

#define ADC_Adjust				RightAdjust

// The selection of the channel[ADC0:ADC7]

#define ADC_ChannelNum			ADC3



#endif /* MCAL_ADC_ADC_CONFIG_H_ */
