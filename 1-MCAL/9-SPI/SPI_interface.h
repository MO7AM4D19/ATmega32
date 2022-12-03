/**********************************		Auther: Mohamed Khalid Anis		**********************************/
/**********************************		Layer: MCAL						**********************************/
/**********************************		SWC: SPI						**********************************/
/**********************************		Version: 1.00					**********************************/

#include "STD_TYPES.h"

#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

#define SPI_CLOCK_RISING_LEAD               0
#define SPI_CLOCK_FALLIG_LEAD               1

#define SPI_CLOCK_SAMPLE_LEAD               0
#define SPI_CLOCK_SETUP_LEAD                1

#define SPI_PRESCALER_4                     0
#define SPI_PRESCALER_16                    1
#define SPI_PRESCALER_64                    2
#define SPI_PRESCALER_128                   3
#define SPI_PRESCALER_2                     4
#define SPI_PRESCALER_8                     5
#define SPI_PRESCALER_32                    6


#define SPI_INTRRUPT_ENABLE                 1
#define SPI_INTRRUPT_DISABLE                0

#define SPI_SHIFT_LEFT                      0
#define SPI_SHIFT_RIGHT                     1

#define SPI_MASTER                          1                          
#define SPI_SLAVE                           0

void SPI_voidInit();
u8 SPI_u8TranciveSynch(u8* Copy_pu8Received,u8 Copy_u8Sent);
u8 SPI_u8TranciveAsynch(u8* Copy_pu8Received,u8 Copy_u8Sent);
#endif