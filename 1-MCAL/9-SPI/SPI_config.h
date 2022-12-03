/**********************************		Auther: Mohamed Khalid Anis		**********************************/
/**********************************		Layer: MCAL						**********************************/
/**********************************		SWC: SPI						**********************************/
/**********************************		Version: 1.00					**********************************/
#include "SPI_interface.h"

#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

#define SPI_MODE                            SPI_MASTER
#define SPI_CLOCK_POLARITY                  SPI_CLOCK_RISING_LEAD
#define SPI_CLOCK_PHASE                     SPI_CLOCK_SETUP_LEAD
#define SPI_CLOCK_PRESCALER                 SPI_PRESCALER_2
#define SPI_INTRRUPT                        SPI_INTRRUPT_DISABLE
#define SPI_DATA_ORDER                      SPI_SHIFT_LEFT


#endif