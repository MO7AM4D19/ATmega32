/**********************************		Auther: Mohamed Khalid Anis		**********************************/
/**********************************		Layer: HAL						**********************************/
/**********************************		SWC: Character LCD				**********************************/
/**********************************		Version: 1.00					**********************************/

#include "DIO_interface.h"

#ifndef CLCD_CONFIG_H
#define CLCD_CONFIG_H

#define CLCD_u8CTRL_PORT                  DIO_u8PORTC
#define CLCD_u8CTRL_RS_PIN                DIO_u8PIN0
#define CLCD_u8CTRL_RW_PIN                DIO_u8PIN1
#define CLCD_u8CTRL_E_PIN                 DIO_u8PIN2
#define CLCD_u8DATA_PORT                  DIO_u8PORTD

#endif
