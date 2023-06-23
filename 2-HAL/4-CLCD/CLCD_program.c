/**********************************		Auther: Mohamed Khalid Anis		**********************************/
/**********************************		Layer: HAL						**********************************/
/**********************************		SWC: Character LCD				**********************************/
/**********************************		Version: 1.00					**********************************/
#define F_CPU 8000000
#include "avr\delay.h"
#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "CLCD_config.h"
#include "CLCD_private.h"

void CLCD_voidInit(void)
{
    _delay_ms(40);
    CLCD_voidSendComand(CLCD_u8FUNCTION_SET);
    CLCD_voidSendComand(CLCD_u8DISPLAY_CTRL);
    CLCD_voidSendComand(CLCD_u8DISPLAY_CLR);
}

void CLCD_voidSendComand(u8 Copy_u8ComandCode)
{
    DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8CTRL_RS_PIN,DIO_u8PIN_LOW);
    DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8CTRL_RW_PIN,DIO_u8PIN_LOW);
    DIO_u8SetPortValue(CLCD_u8DATA_PORT,Copy_u8ComandCode);
    DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8CTRL_E_PIN,DIO_u8PIN_HIGH);
    _delay_ms(2);
    DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8CTRL_E_PIN,DIO_u8PIN_LOW);
}

void CLCD_voidSendData(u8 Copy_u8DataCode)
{
    DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8CTRL_RS_PIN,DIO_u8PIN_HIGH);
    DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8CTRL_RW_PIN,DIO_u8PIN_LOW);
    DIO_u8SetPortValue(CLCD_u8DATA_PORT,Copy_u8DataCode);
    DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8CTRL_E_PIN,DIO_u8PIN_HIGH);
    _delay_ms(2);
    DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8CTRL_E_PIN,DIO_u8PIN_LOW);
}

void CLCD_voidDisplayString(char* Copy_pCharString)
{
    u8 Local_u8Counter = 0;
    while (Copy_pCharString[Local_u8Counter]!='\0')
    {
        CLCD_voidSendData(Copy_pCharString[Local_u8Counter]);
        Local_u8Counter++;
    }
}

void CLCD_voidGoToX_Y(u8 Copy_u8X,u8 Copy_u8Y)
{
    if(Copy_u8Y == 0)
    {
        CLCD_voidSendComand(Copy_u8X+128);
    }
    else if(Copy_u8Y == 1)
    {
        CLCD_voidSendComand(Copy_u8X+128+0x40);
    }
}

void CLCD_voidDisplaySpcialChar(u8* Copy_pu8SplChar,u8 Copy_u8PatternNum,u8 Copy_u8X,u8 Copy_u8Y)
{
    u8 Copy_u8CGAdress=Copy_u8PatternNum*8;
    CLCD_voidSendComand(Copy_u8CGAdress+64);
    for(u8 Local_u8Counter=0;Local_u8Counter<8;Local_u8Counter++)
    {
        CLCD_voidSendData(Copy_pu8SplChar[Local_u8Counter]);
    }
    CLCD_voidGoToX_Y(Copy_u8X,Copy_u8Y);
    CLCD_voidSendData(Copy_u8PatternNum);
}

void CLCD_voidDisplayNumber(u32 Copy_u32Number)
{
    u32 Local_u32ModGetter=1000000000;
	u32 Local_u32SentNumber=0;
	u8 Local_u8StartFlag = 0;
    while(Local_u32ModGetter>0)
    {
        if(Copy_u32Number>=Local_u32ModGetter)
        {
            Local_u32SentNumber=(Copy_u32Number/Local_u32ModGetter);
			CLCD_voidSendData(Local_u32SentNumber+'0');
			Copy_u32Number-=Local_u32ModGetter*Local_u32SentNumber;
			Local_u32ModGetter/=10;
			Local_u8StartFlag = 1;
        }
        else
        {
			if(Local_u8StartFlag == 1)
			{
				CLCD_voidSendData('0');
			}
			Local_u32ModGetter/=10;
        }
    }
}





