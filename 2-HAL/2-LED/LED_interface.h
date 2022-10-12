/**********************************		Auther: Mohamed Khalid Anis		**********************************/
/**********************************		Layer: HAL						**********************************/
/**********************************		SWC: LED						**********************************/
/**********************************		Version: 1.00					**********************************/

#include "STD_TYPES.h"

#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

#define LED_u8SOURCE         0               
#define LED_u8SINK           1

u8 LED_u8TurnOnLED(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8ConnectionMode);
u8 LED_u8TurnOfLED(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8ConnectionMode);

#endif