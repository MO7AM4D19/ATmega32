/**********************************		Auther: Mohamed Khalid Anis		**********************************/
/**********************************		Layer: MCAL						**********************************/
/**********************************		SWC: TWI						**********************************/
/**********************************		Version: 1.00					**********************************/

#include "TWI_register.h"
#include "TWI_config.h"
#include "TWI_private.h"
#include "TWI_interface.h"
#include "BIT_MATH.h"

void TWI_voidMasterInit(u8 Copy_u8SlaveAddress)
{
    TWBR = 2;
    CLR_BIT(TWSR,TWSR_TWPS0);
    CLR_BIT(TWSR,TWSR_TWPS1);
    SET_BIT(TWCR,TWCR_TWEN);
    if(Copy_u8SlaveAddress !=0)
    {
        TWAR = 0;
        TWAR |= Copy_u8SlaveAddress<<1;
    }
    SET_BIT(TWAR,TWAR_TWGCE);
    CLR_BIT(TWCR,TWCR_TWIE);
    SET_BIT(TWCR,TWCR_TWEN);
}

void TWI_voidSlaveInit(u8 Copy_u8SlaveAddress)
{
    TWAR = 0;
    TWAR |= Copy_u8SlaveAddress<<1;
    SET_BIT(TWCR,TWCR_TWEN);
}

TW_ErrState TWI_SendStartCondition()
{
    TW_ErrState Local_Error = NoError;
    SET_BIT(TWCR,TWCR_TWSTA);
    SET_BIT(TWCR,TWCR_TWINT);
    while(0 == GET_BIT(TWCR,TWCR_TWINT));
    if((TWSR & 0xF8) != START_ACK)
    {
        Local_Error = StartFailed;
    }
    else
    {
        CLR_BIT(TWCR,TWCR_TWSTO);
    }
    return Local_Error;
}

TW_ErrState TWI_SendRepeatedStart()
{
    TW_ErrState Local_Error = NoError;
    SET_BIT(TWCR,TWCR_TWSTA);
    SET_BIT(TWCR,TWCR_TWINT);
    while(0 == GET_BIT(TWCR,TWCR_TWINT));
    if((TWSR & 0xF8) != REP_START_ACK)
    {
        Local_Error = RepeatedStartFailed;
    }
    else
    {
        CLR_BIT(TWCR,TWCR_TWSTO);
    }
    return Local_Error;
}

TW_ErrState TWI_SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress)
{
    TW_ErrState Local_Error = NoError;
    TWBR = (Copy_u8SlaveAddress<<1)+1;
    SET_BIT(TWCR,TWCR_TWINT);
    while(0 == GET_BIT(TWCR,TWCR_TWINT));
    if((TWSR & 0xF8) != SLAVE_ADD_AND_WR_ACK)
    {
        Local_Error = SlaveWriteReqFailed;
    }
    return Local_Error;
}

TW_ErrState TWI_SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress)
{
    TW_ErrState Local_Error = NoError;
    TWBR = Copy_u8SlaveAddress<<1;
    SET_BIT(TWCR,TWCR_TWINT);
    while(0 == GET_BIT(TWCR,TWCR_TWINT));
    if((TWSR & 0xF8) != SLAVE_ADD_AND_RD_ACK)
    {
        Local_Error = SlaveReadReqFailed;
    }
    return Local_Error;
}

TW_ErrState TWI_MasterWriteDataByte(u8 Copy_u8DataByte)
{
    TW_ErrState Local_Error = NoError;
    TWBR = Copy_u8DataByte;
    SET_BIT(TWCR,TWCR_TWINT);
    while(0 == GET_BIT(TWCR,TWCR_TWINT));
    if((TWSR & 0xF8) != MSTR_WR_BYTE_ACK)
    {
        Local_Error = MasterWriteFailed;
    }
    return Local_Error;
}

TW_ErrState TWI_MasterReadDataByte(u8* Copy_pu8DataByte)
{
    TW_ErrState Local_Error = NoError;
    SET_BIT(TWCR,TWCR_TWEA);
    SET_BIT(TWCR,TWCR_TWINT);
    while(0 == GET_BIT(TWCR,TWCR_TWINT));
    if((TWSR & 0xF8) != MSTR_RD_BYTE_WITH_ACK)
    {
        Local_Error = MasterReadFailed;
    }
    else
    {
        *Copy_pu8DataByte = TWBR;
    }
    return Local_Error;
}

void TWI_SendStopCondition()
{
    SET_BIT(TWCR,TWCR_TWSTO);
    SET_BIT(TWCR,TWCR_TWINT);
}
