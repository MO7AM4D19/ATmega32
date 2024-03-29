/**********************************		Auther: Mohamed Khalid Anis		**********************************/
/**********************************		Layer: RTOS stack				**********************************/
/**********************************		SWC: RTOS						**********************************/
/**********************************		Version: 1.00					**********************************/

#include "STD_TYPES.h"
#ifndef RTOS_PRIVATE_H
#define RTOS_PRIVATE_H

typedef struct
{
    void (*TaskFunction)(void);
    u16 Periodicity;
    u8 Priority;
    u8 FirstDelay;
    
}RTOS_task_t;

#endif
