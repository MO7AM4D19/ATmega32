/**********************************		Auther: Mohamed Khalid Anis		**********************************/
/**********************************		Layer: HAL						**********************************/
/**********************************		SWC: Seven Segmant Display		**********************************/
/**********************************		Version: 1.00					**********************************/

#include "SSD_interface.h"
#include "SSD_config.h"
#include "SSD_private.h"
#include "DIO_interface.h"

u8 SSD_u8DisplayNumber(SSD* Copy_pu8SSD,u8 Copy_u8Number)
{
    u8 SSD_u8ErrorState = 0;
    DIO_u8SetPinDirection(Copy_pu8SSD->SSD_u8EnablePort,Copy_pu8SSD->SSD_u8EnaplePin,DIO_u8PIN_OUTPUT);
    DIO_u8SetPortDirection(Copy_pu8SSD->SSD_u8DisplPort,DIO_u8PORT_OUTPUT);
    if((Copy_u8Number<=SSD_u8NUMBER9) && (Copy_pu8SSD->SSD_u8CommonType<=SSD_u8COMMON_ANODE) && (Copy_pu8SSD->SSD_u8EnablePort<=DIO_u8PORTD) && (Copy_pu8SSD->SSD_u8EnaplePin<=DIO_u8PIN7))
    {         
        if(Copy_pu8SSD->SSD_u8CommonType == SSD_u8COMMON_CATHOD)
        {
            DIO_u8SetPinValue(Copy_pu8SSD->SSD_u8EnablePort,Copy_pu8SSD->SSD_u8EnaplePin,DIO_u8PIN_LOW);
        }
        else
        {
            DIO_u8SetPinValue(Copy_pu8SSD->SSD_u8EnablePort,Copy_pu8SSD->SSD_u8EnaplePin,DIO_u8PIN_HIGH);
        }
        DIO_u8SetPortValue(Copy_pu8SSD->SSD_u8DisplPort,Copy_u8Number);
    }
    else
    {
        SSD_u8ErrorState = 1;
    }
    return SSD_u8ErrorState;
}

