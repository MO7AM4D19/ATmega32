/**********************************		Auther: Mohamed Khalid Anis		**********************************/
/**********************************		Layer: HAL						**********************************/
/**********************************		SWC: Character LCD				**********************************/
/**********************************		Version: 1.00					**********************************/

#include "STD_TYPES.h"


#ifndef CLCD_INTERFACE_H
#define CLCD_INTERFACE_H

#define CLCD_u8FUNCTION_SET             0x38
#define CLCD_u8DISPLAY_CTRL             0x0C
#define CLCD_u8DISPLAY_CLR              0x01

void CLCD_voidInit(void);
void CLCD_voidSendComand(u8 Copy_u8ComandCode);
void CLCD_voidSendData(u8 Copu_u8DataCode);
void CLCD_voidGoToX_Y(u8 Copy_u8X,u8 Copy_u8Y);
void CLCD_voidDisplayString(char* Copy_pCharString);
void CLCD_voidDisplaySpcialChar(u8* Copy_pu8SplChar,u8 Copy_u8PatternNum,u8 Copy_u8X,u8 Copy_u8Y);
void CLCD_voidDisplayNumber(u32 Copy_u32Number);

#endif