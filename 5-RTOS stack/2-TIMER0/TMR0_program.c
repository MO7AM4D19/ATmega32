/**********************************		Auther: Mohamed Khalid Anis		**********************************/
/**********************************		Layer: MCAL						**********************************/
/**********************************		SWC: Timer						**********************************/
/**********************************		Version: 1.00					**********************************/

#include "TMR_interface.h"
#include "TMR_private.h"
#include "TMR_register.h"
#include "BIT_MATH.h"

/************************************Timer 0 *************************/
void (* TMR0_fpOverflowFunction)(void) = NULL;
void (* TMR0_fpCompareMatchFunction)(void) = NULL;


void TMR0_voidInit()
{
    /* Timer Mode: CTC*/
    CLR_BIT(TCCR0,TCCR0_WGM00);
    SET_BIT(TCCR0,TCCR0_WGM01);


    /* Setting Clock*/
    TCCR0 &= 0b11111000;
    TCCR0 |= TMR_PRESCALER_64;
    
    /* Setting Compare Match Value*/
    #if TMR0_MODE == TMR_CTC
    OCR0 = 125;
    #endif

    /* Enabling Timer Intrupt*/
    CLR_BIT(TIMSK,TIMSK_TOIE0);
    SET_BIT(TIMSK,TIMSK_OCIE0);

}

u8 TMR0_u8SetCallBack(void (*Copy_pvCallBackFunc)(void))
{
    u8 Local_u8ErrorState = OK;
    if(Copy_pvCallBackFunc == NULL)
    {
        Local_u8ErrorState = NULL_POINTER;
    }
    else
    {
        TMR0_fpCompareMatchFunction = Copy_pvCallBackFunc;
    }
    return Local_u8ErrorState;
}

void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
    TMR0_fpCompareMatchFunction();
}