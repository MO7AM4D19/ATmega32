/**********************************		Auther: Mohamed Khalid Anis		**********************************/
/**********************************		Layer: MCAL						**********************************/
/**********************************		SWC: SPI						**********************************/
/**********************************		Version: 1.00					**********************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SPI_config.h"
#include "SPI_interface.h"
#include "SPI_register.h"
#include "SPI_private.h"

void SPI_voidInit()
{
    SPCR = 0;
    SPCR |= SPI_CLOCK_PRESCALER;

    #if SPI_INTRRUPT == SPI_INTRRUPT_ENABLE
    SET_BIT(SPCR,SPCR_SPIE);
    #elif SPI_INTRRUPT == SPI_INTRRUPT_DISABLE
    CLR_BIT(SPCR,SPCR_SPIE);
    #endif

    #if SPI_DATA_ORDER == SPI_SHIFT_LEFT
    CLR_BIT(SPCR,SPCR_DORD);
    #elif SPI_DATA_ORDER == SPI_SHIFT_RIGHT
    SET_BIT(SPCR,SPCR_DORD);
    #endif

    #if SPI_MODE == SPI_SLAVE
    CLR_BIT(SPCR,SPCR_MSTR);
    #elif SPI_MODE == SPI_MASTER
    SET_BIT(SPCR,SPCR_MSTR);
    #endif  

    #if SPI_CLOCK_POLARITY == SPI_CLOCK_RISING_LEAD
    CLR_BIT(SPCR,SPCR_CPOL);
    #elif SPI_CLOCK_POLARITY == SPI_CLOCK_FALLIG_LEAD
    SET_BIT(SPCR,SPCR_CPOL);
    #endif

    #if SPI_CLOCK_PHASE == SPI_CLOCK_SAMPLE_LEAD
    CLR_BIT(SPCR,SPCR_CPHA);
    #elif SPI_CLOCK_PHASE == SPI_CLOCK_SETUP_LEAD
    SET_BIT(SPCR,SPCR_CPHA);
    #endif

    SET_BIT(SPCR,SPCR_SPE);
}

u8 SPI_u8TranciveSynch(u8* Copy_pu8Received,u8 Copy_u8Sent)
{
    u8 Local_u8ErrorState = OK;
    if(NULL == Copy_pu8Received)
    {
        Local_u8ErrorState = NULL_POINTER;
    }
    else
    {
        while(!GET_BIT(SPSR,SPSR_SPIF));
        SPDR = Copy_u8Sent;
        while(!GET_BIT(SPSR,SPSR_SPIF));
        *Copy_pu8Received = SPDR;
    }

    return Local_u8ErrorState;
}

u8 SPI_u8TranciveAsynch(u8* Copy_pu8Received,u8 Copy_u8Sent)
{

}