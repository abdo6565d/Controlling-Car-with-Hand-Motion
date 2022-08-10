/*
 * EXTI_Config.c
 *
 *  Created on: Jun 30, 2022
 *      Author: DELL
 */
#include"../../Libraries/errorState.h"
#include"../../Libraries/stdTypes.h"

#include"EXTI_Config.h"
#include"EXTI_Priv.h"

u8 EXTI_u8InterNumber=InterNum;

EXTI_t EXTI_AstrConfig[InterNum]={
		{INT0,Enable,Rising},
		{INT1,Disable,Disable},
		{INT2,Enable,Falling}
};

