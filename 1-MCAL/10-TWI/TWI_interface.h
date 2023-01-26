/**********************************		Auther: Mohamed Khalid Anis		**********************************/
/**********************************		Layer: MCAL						**********************************/
/**********************************		SWC: TWI						**********************************/
/**********************************		Version: 1.00					**********************************/

#include "STD_TYPES.h"

#ifndef TWI_INTERFACE_H
#define TWI_INTERFACE_H 

typedef enum
{
    NoError,StartFailed,RepeatedStartFailed,SlaveWriteReqFailed,SlaveReadReqFailed,MasterWriteFailed,MasterReadFailed
}TW_ErrState;

/* Pass 0 to create an unaddressed master*/
void TWI_voidMasterInit(u8 Copy_u8SlaveAddress);
void TWI_voidSlaveInit(u8 Copy_u8SlaveAddress);
TW_ErrState TWI_SendStartCondition();
TW_ErrState TWI_SendRepeatedStart();
TW_ErrState TWI_SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress);
TW_ErrState TWI_SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress);
TW_ErrState TWI_MasterWriteDataByte(u8 Copy_u8DataByte);
TW_ErrState TWI_MasterReadDataByte(u8* Copy_pu8DataByte);
void TWI_SendStopCondition();

#endif