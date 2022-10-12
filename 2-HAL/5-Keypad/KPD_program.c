/**********************************		Auther: Mohamed Khalid Anis		**********************************/
/**********************************		Layer: HAL						**********************************/
/**********************************		SWC: Keypad     				**********************************/
/**********************************		Version: 1.00					**********************************/

#include "STD_TYPES.h"
#include "KPD_config.h"
#include "KPD_interface.h"
#include "KPD_private.h"
#include "DIO_interface.h"
#include "avr/delay.h"

u8 KPD_u8GetPressedKey()
{
	u8 KPD_u8PressedKey = KPD_u8NOT_PRESSED; 
	u8 Local_u8PinState = 0;
    static u8 Local_u8KeyArr[KPD_u8RowSize][KPD_u8ColumnSize]=KPD_pu8KEYS;
	static u8 Local_u8ColumnArr[KPD_u8ColumnSize]={KPD_u8COUMN1_PIN,KPD_u8COUMN2_PIN,KPD_u8COUMN3_PIN,KPD_u8COUMN4_PIN};
    static u8 Local_u8RowArr[KPD_u8RowSize]={KPD_u8ROW1_PIN,KPD_u8ROW2_PIN,KPD_u8ROW3_PIN,KPD_u8ROW4_PIN};
    for(u8 Local_u8ColumnCounter=0;Local_u8ColumnCounter<KPD_u8ColumnSize;Local_u8ColumnCounter++)
    {
        DIO_u8SetPinValue(KPD_u8KEYPAD_PORT,Local_u8ColumnArr[Local_u8ColumnCounter],DIO_u8PIN_LOW);
        for(u8 Local_u8RowCounter=0;Local_u8RowCounter<KPD_u8RowSize;Local_u8RowCounter++)
        {
            DIO_u8GetPinValue(KPD_u8KEYPAD_PORT,Local_u8RowArr[Local_u8RowCounter],(&Local_u8PinState));
            while(DIO_u8PIN_LOW == Local_u8PinState)
            {
                KPD_u8PressedKey = Local_u8KeyArr[Local_u8RowCounter][Local_u8ColumnCounter];
                return KPD_u8PressedKey;
            }
        }
        DIO_u8SetPinValue(KPD_u8KEYPAD_PORT,Local_u8ColumnArr[Local_u8ColumnCounter],DIO_u8PIN_HIGH);
		_delay_ms(10);
    }
    return KPD_u8PressedKey;
}
