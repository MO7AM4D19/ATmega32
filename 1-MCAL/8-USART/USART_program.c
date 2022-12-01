/**********************************		Auther: Mohamed Khalid Anis		**********************************/
/**********************************		Layer: MCAL						**********************************/
/**********************************		SWC: UART						**********************************/
/**********************************		Version: 1.00					**********************************/

#include "USART_config.h"
#include "USART_interface.h"
#include "USART_private.h"
#include "USART_register.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"

void USART_voidInit()
{
    u8  Local_u8TempUCSRC = 0;
    u16 Local_u16BaudRegValue = (USART_CLOCK/(16*USART_BAUD))-1;
    #if USART_INTRRUPT == USART_INTRUPT_DISABLE
    CLR_BIT(UCSRB,UCSRB_RXCIE);
    CLR_BIT(UCSRB,UCSRB_TXCIE);
    CLR_BIT(UCSRB,UCSRB_UDRIE);
    #elif USART_INTRRUPT == USART_INTRUPT_ENABLE
    SET_BIT(UCSRB,UCSRB_RXCIE);
    SET_BIT(UCSRB,UCSRB_TXCIE);
    SET_BIT(UCSRB,UCSRB_UDRIE);
    #endif

    #if USART_MODE == USART_ASYNC
    CLR_BIT(Local_u8TempUCSRC,UCSRC_UMSEL);
    #elif USART_MODE == USART_SYNC
    SET_BIT(Local_u8TempUCSRC,UCSRC_UMSEL);
    #endif

    #if USART_STOP == USART_1STOP
    CLR_BIT(Local_u8TempUCSRC,UCSRC_UMSEL);
    #elif USART_STOP == USART_2STOP
    SET_BIT(Local_u8TempUCSRC,UCSRC_UMSEL);
    #endif

    Local_u8TempUCSRC |= (USART_INTRRUPT<<4);
    Local_u8TempUCSRC |= ((USART_DATA-5)<<1);
    SET_BIT(Local_u8TempUCSRC,UCSRC_URSEL);
    UCSRC = Local_u8TempUCSRC;
    Local_u8TempUCSRC = 0;
    CLR_BIT(Local_u16BaudRegValue,15);
    UBRRL = (u8)((Local_u16BaudRegValue<<8)>>8);
    UBRRH = (u8)(Local_u16BaudRegValue>>8);

    SET_BIT(UCSRB,UCSRB_RXEN);
    SET_BIT(UCSRB,UCSRB_TXEN);
}

void USART_voidSend(u8 Copy_u8data)
{
    while(!GET_BIT(UCSRA,UCSRA_UDRE));
    UDR = Copy_u8data;
    while(!GET_BIT(UCSRA,UCSRA_TXC));
}

u8   USART_u8Receive()
{
    while(!GET_BIT(UCSRA,UCSRA_RXC));
    return UDR;
}
