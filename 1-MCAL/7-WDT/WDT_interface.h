/**********************************		Auther: Mohamed Khalid Anis		**********************************/
/**********************************		Layer: MCAL						**********************************/
/**********************************		SWC: Watch Dog Timer			**********************************/
/**********************************		Version: 1.00					**********************************/

#include "STD_TYPES.h"

#ifndef WDT_INTERFACE_H
#define WDT_INTERFACE_H
typedef enum {ms16_3,ms32_5,ms65,s0_13,s0_26,s0_52,s1,s2_1} WDT_timout;

void WDT_voidSleep(WDT_timout Copy_u8SleapTime);
void WDT_voidDisaple();

#endif