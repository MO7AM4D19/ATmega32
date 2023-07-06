/**********************************		Auther: Mohamed Khalid Anis		**********************************/
/**********************************		Layer: MCAL						**********************************/
/**********************************		SWC: Timer						**********************************/
/**********************************		Version: 1.00					**********************************/

#include "STD_TYPES.h"

#ifndef TMR_INTERFACE_H
#define TMR_INTERFACE_H
#define TMR_CTC                             3
#define TMR_PRESCALER_64                    3


void TMR0_voidInit();
u8   TMR0_u8SetCallBack(void (*Copy_pvCallBackFunc)(void));

#endif