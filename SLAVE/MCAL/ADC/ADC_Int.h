/*
 * ADC_Int.h
 *
 *  Created on: Jul 27, 2022
 *      Author: DELL
 */

#ifndef MCAL_ADC_ADC_INT_H_
#define MCAL_ADC_ADC_INT_H_

ES_t ADC_enuInit(void);

ES_t ADC_enuRead(u16* Copy_Pu16ReadValue);

ES_t ADC_enuEnableADC(void);

ES_t ADC_enuDisableADC(void);
#endif /* MCAL_ADC_ADC_INT_H_ */
