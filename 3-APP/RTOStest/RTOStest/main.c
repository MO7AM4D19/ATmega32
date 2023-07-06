/*
 * RTOStest.c
 *
 * Created: 7/5/2023 3:13:45 AM
 * Author : MO7AM4D KH4LID
 */ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "FreeRTOS.h"
#include "task.h"

void LED1(void* pvLED1r);
void LED2(void* pvLED2r);
void LED3(void* pvLED3r);

int main(void)
{
	PORT_voidInint();
	xTaskCreate(&LED1,NULL,100,NULL,0,NULL);
	xTaskCreate(&LED2,NULL,100,NULL,1,NULL);
	xTaskCreate(&LED3,NULL,100,NULL,2,NULL);
	vTaskStartScheduler();

	while(1)
	{
		
	}
}

void LED1(void* pvLED1r)
{
	static u8 Local_u8LED1state = 0;
	while(1)
	{
		TOG_BIT(Local_u8LED1state,0);
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,Local_u8LED1state);
		vTaskDelay(1000);
	}
}

void LED2(void* pvLED2r)
{
	static u8 Local_u8LED2state = 0;
	while(1)
	{
		TOG_BIT(Local_u8LED2state,0);
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN1, Local_u8LED2state);
		vTaskDelay(2000);
	}
}

void LED3(void* pvLED3r)
{
	static u8 Local_u8LED3state = 0;
	while(1)
	{
		TOG_BIT(Local_u8LED3state,0);
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN2,Local_u8LED3state);
		vTaskDelay(3000);
	}
}

