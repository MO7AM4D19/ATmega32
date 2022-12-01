/**********************************		Auther: Mohamed Khalid Anis		**********************************/
/**********************************		Layer: MCAL						**********************************/
/**********************************		SWC: UART						**********************************/
/**********************************		Version: 1.00					**********************************/

#include "STD_TYPES.h"

#ifndef USART_INTERFACE_H
#define USATT_INTERFACE_H

#define USART_ASYNC                 0
#define USART_SYNC                  1

#define USART_1STOP                 0
#define USART_2STOP                 1

#define USART_PARITY_OFF            0
#define USART_PARITY_EVEN           2
#define USART_PARITY_ODD            3

#define USART_INTRUPT_DISABLE       0
#define USART_INTRUPT_ENABLE        1

void USART_voidInit();
void USART_voidSend(u8 Copy_u8data);
u8   USART_u8Receive();
#endif