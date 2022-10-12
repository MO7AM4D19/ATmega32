/**********************************		Auther: Mohamed Khalid Anis		**********************************/
/**********************************		Layer: HAL						**********************************/
/**********************************		SWC: Mechanical Switch			**********************************/
/**********************************		Version: 1.00					**********************************/

#include "DIO_interface.h"

#ifndef MSW_INTERFACE_H
#define MSW_INTERFACE_H

#define MSW_u8DEACTIVATE_DEBOUNCER          0
#define MSW_u8ACTIVATE_DEBOUNCER            1

#define MSW_u8PULL_DOWN                     0
#define MSW_u8PULL_UP                       1

#define MSW_u8UNPRESSED                     0
#define MSW_u8PRESSED                       1

u8 MSW_u8GetState(u8 Copy_u8Port, u8 Copy_u8Pin,u8 Copy_u8Debouncer,u8 Copy_u8PullType,u8* Copy_pu8State);

#endif