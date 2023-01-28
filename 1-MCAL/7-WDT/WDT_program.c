/**********************************		Auther: Mohamed Khalid Anis		**********************************/
/**********************************		Layer: MCAL						**********************************/
/**********************************		SWC: Watch Dog Timer			**********************************/
/**********************************		Version: 1.00					**********************************/

#include "WDT_private.h"
#include "WDT_config.h"
#include "WDT_register.h"
#include "WDT_interface.h"
#include "BIT_MATH.h"

void WDT_voidSleep(WDT_timout Copy_u8SleapTime)
{
    WDTCR = 0b00011000;
    CLR_BIT(WDTCR,WDTCR_WDE);
    switch(Copy_u8SleapTime)
    {
        case ms16_3:
        CLR_BIT(WDTCR,WDTCR_WDP0);
        CLR_BIT(WDTCR,WDTCR_WDP1);
        CLR_BIT(WDTCR,WDTCR_WDP2);
        break;
        case ms32_5:
        SET_BIT(WDTCR,WDTCR_WDP0);
        CLR_BIT(WDTCR,WDTCR_WDP1);
        CLR_BIT(WDTCR,WDTCR_WDP2);
        break;
        case ms65:
        CLR_BIT(WDTCR,WDTCR_WDP0);
        SET_BIT(WDTCR,WDTCR_WDP1);
        CLR_BIT(WDTCR,WDTCR_WDP2);
        break;
        case s0_13:
        SET_BIT(WDTCR,WDTCR_WDP0);
        SET_BIT(WDTCR,WDTCR_WDP1);
        CLR_BIT(WDTCR,WDTCR_WDP2);
        break;
        case s0_26:
        CLR_BIT(WDTCR,WDTCR_WDP0);
        CLR_BIT(WDTCR,WDTCR_WDP1);
        SET_BIT(WDTCR,WDTCR_WDP2);
        break;
        case s0_52:
        SET_BIT(WDTCR,WDTCR_WDP0);
        CLR_BIT(WDTCR,WDTCR_WDP1);
        SET_BIT(WDTCR,WDTCR_WDP2);
        break;
        case s1:
        CLR_BIT(WDTCR,WDTCR_WDP0);
        SET_BIT(WDTCR,WDTCR_WDP1);
        SET_BIT(WDTCR,WDTCR_WDP2);
        break;
        case s2_1:
        SET_BIT(WDTCR,WDTCR_WDP0);
        SET_BIT(WDTCR,WDTCR_WDP1);
        SET_BIT(WDTCR,WDTCR_WDP2);
        break;
    }
    SET_BIT(WDTCR,WDTCR_WDE);
}

void WDT_voidDisaple()
{
    WDTCR = 0b00011000;
    CLR_BIT(WDTCR,WDTCR_WDE);
}