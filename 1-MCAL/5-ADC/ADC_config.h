/**********************************		Auther: Mohamed Khalid Anis		**********************************/
/**********************************		Layer: MCAL						**********************************/
/**********************************		SWC: ADC						**********************************/
/**********************************		Version: 1.00					**********************************/

#include "ADC_interface.h"

#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H

#define ADC_u8RESOLUTION                    ADC_u8BIT_10
#define ADC_u8REFRANCE_VOLTAGE              ADC_u8AVCC
#define ADC_u8AUTO_TRIGGER                  ADC_u8AUTO_TRIGGER_DISABLE
#define ADC_u8INTRUPUT                      ADC_u8INTRUPUT_DISABLE
#define ADC_u8PRESCALER                     ADC_u8PRESCALER_128
#define ADC_u32TIME_OUT						5000

#endif