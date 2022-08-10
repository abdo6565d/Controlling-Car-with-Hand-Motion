/*
 * ADC_int.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Nader
 */

#ifndef MCAL_ADC_ADC_INT_H_
#define MCAL_ADC_ADC_INT_H_

ES_t ADC_INIT(void);
ES_t ADC_START_CONVERSION(u8 CH);
ES_t ADC_GET_RESULT(u16 *RESULT);
ES_t ADC_SET_AUTO_TRIGGER(u8 copy_source);
ES_t ADC_DISABLE_AUTO_TRIGGER();
ES_t ADC_ENABlE_ENTRRUPT();
ES_t ADC_DISABlE_ENTRRUPT();

#endif /* MCAL_ADC_ADC_INT_H_ */
