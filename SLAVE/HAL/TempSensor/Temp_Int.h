/*
 * Temp_Int.h
 *
 *  Created on: Jul 28, 2022
 *      Author: DELL
 */

#ifndef HAL_TEMPSENSOR_TEMP_INT_H_
#define HAL_TEMPSENSOR_TEMP_INT_H_

ES_t Temp_enuInit(void);

ES_t Temp_enuRead(u16* Copy_Pu16ReadValue);

ES_t Temp_enuEnableTemp(void);

ES_t Temp_enuDisableTemp(void);

#endif /* HAL_TEMPSENSOR_TEMP_INT_H_ */
