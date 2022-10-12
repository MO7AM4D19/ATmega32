/**********************************		Auther: Mohamed Khalid Anis		**********************************/
/**********************************		Layer: HAL						**********************************/
/**********************************		SWC: LED						**********************************/
/**********************************		Version: 1.00					**********************************/

#include "DIO_interface.h"
#include "LED_interface.h"
#include "LED_config.h"
#include "LED_private.h"

u8 LED_u8TurnOnLED(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8ConnectionMode)
{
    u8 Local_u8ErrorState = 0;
    if((Copy_u8Port<=DIO_u8PORTD) && (Copy_u8Pin<=DIO_u8PIN7) && (Copy_u8ConnectionMode<=1))
    {
        DIO_u8SetPinDirection(Copy_u8Port,Copy_u8Pin,DIO_u8PIN_OUTPUT);
        if(Copy_u8ConnectionMode == LED_u8SOURCE)
        {
            DIO_u8SetPinValue(Copy_u8Port,Copy_u8Pin,DIO_u8PIN_HIGH);
        }
        else
        {
            DIO_u8SetPinValue(Copy_u8Port,Copy_u8Pin,DIO_u8PIN_LOW);
        }
    }
    else
    {
        Local_u8ErrorState = 1;
    }
    return Local_u8ErrorState;
}

u8 LED_u8TurnOffLED(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8ConnectionMode)
{
    u8 Local_u8ErrorState = 0;
    if((Copy_u8Port<=DIO_u8PORTD) && (Copy_u8Pin<=DIO_u8PIN7) && (Copy_u8ConnectionMode<=1))
    {
        DIO_u8SetPinDirection(Copy_u8Port,Copy_u8Pin,DIO_u8PIN_OUTPUT);
        if(Copy_u8ConnectionMode == LED_u8SOURCE)
        {
            DIO_u8SetPinValue(Copy_u8Port,Copy_u8Pin,DIO_u8PIN_LOW);
        }
        else
        {
            DIO_u8SetPinValue(Copy_u8Port,Copy_u8Pin,DIO_u8PIN_HIGH);
        }
    }
    else
    {
        Local_u8ErrorState = 1;
    }
    return Local_u8ErrorState;
}
