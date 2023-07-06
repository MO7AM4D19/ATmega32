/**********************************		Auther: Mohamed Khalid Anis		**********************************/
/**********************************		Layer: RTOS stack				**********************************/
/**********************************		SWC: RTOS						**********************************/
/**********************************		Version: 1.00					**********************************/
#include "STD_TYPES.h"
#include "TMR0_interface.h"
#include "GIE_interface.h"
#include "RTOS_private.h"
#include "RTOS_config.h"
#include "RTOS_interface.h"
#include "GIE_interface.h"
#include "TMR0_interface.h"

RTOS_task_t TaskQueue[RTOS_TASKS_NUMBER] = {{NULL,0,0,0}};

void RTOS_Start()
{
    TMR0_u8SetCallBack(&RTOS_Scheduler);
    GIE_voidEnabaleGeneralIntrupt();
    TMR0_voidInit();
}

void RTOS_CreateTask(u8 Copy_u8Priority,u8 Copy_u8FirstDelay,u16 Copy_u16Periodicity, void (*Copy_fpTaskFunction)(void))
{
    TaskQueue[Copy_u8Priority].Periodicity = Copy_u16Periodicity;
    TaskQueue[Copy_u8Priority].TaskFunction = Copy_fpTaskFunction;
    TaskQueue[Copy_u8Priority].FirstDelay = Copy_u8FirstDelay;

}

static void RTOS_Scheduler()
{
    for(u8 TskCounter = 0;TskCounter<RTOS_TASKS_NUMBER;TskCounter++)
    {
        if(TaskQueue[TskCounter].FirstDelay ==0)
        {
            if(TaskQueue[TskCounter].TaskFunction != NULL)
            {
                TaskQueue[TskCounter].TaskFunction();
            }
            TaskQueue[TskCounter].FirstDelay = TaskQueue[TskCounter].Periodicity;
        }
        else
        {
            TaskQueue[TskCounter].FirstDelay--;
        }
    }
}
