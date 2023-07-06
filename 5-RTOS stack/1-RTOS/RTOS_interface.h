/**********************************		Auther: Mohamed Khalid Anis		**********************************/
/**********************************		Layer: RTOS stack				**********************************/
/**********************************		SWC: RTOS						**********************************/
/**********************************		Version: 1.00					**********************************/

#include "STD_TYPES.h"
#ifndef RTOS_INTERFACE_H
#define RTOS_INTERFACE_H

void RTOS_Start();
void RTOS_CreateTask(u8 Copy_u8Priority,u16 Copy_u16Periodicity, void (*Copy_fpTaskFunction)(void));

#endif