/**********************************		Auther: Mohamed Khalid Anis		**********************************/
/**********************************		Layer: HAL						**********************************/
/**********************************		SWC: EEPROM     				**********************************/
/**********************************		Version: 1.00					**********************************/

#include "EEPROM_config.h"
#include "EEPROM_interface.h"
#include "EEPROM_private.h"
#include "BIT_MATH.h"
#include "TWI_interface.h"

void EEPROM_voidWriteByte(u8 Copy_u8DataByte,u16 Copy_u16MemoryAddress)
{
    TWI_SendStartCondition();
    TWI_SendSlaveAddressWithWrite(((0xA0 | (MEMORY_BUSS_ID<<3)) | (u8)(Copy_u16MemoryAddress>>8)) + 1);
    TWI_MasterWriteDataByte((u8)Copy_u16MemoryAddress);
    TWI_MasterWriteDataByte(Copy_u8DataByte);
    TWI_SendStopCondition();
}

u8 EEPROM_u8ReadByte(u16 Copy_u16MemoryAddress)
{
    u8 Local_u8Data;
    TWI_SendStartCondition();
    TWI_SendSlaveAddressWithWrite(((0xA0 | (MEMORY_BUSS_ID<<3)) | (u8)(Copy_u16MemoryAddress>>8)) + 1);
    TWI_MasterWriteDataByte((u8)Copy_u16MemoryAddress);
    TWI_SendRepeatedStart();
    TWI_SendSlaveAddressWithRead(((0xA0 | (MEMORY_BUSS_ID<<3)) | (u8)(Copy_u16MemoryAddress>>8)) + 1);
    TWI_MasterReadDataByte(&Local_u8Data);
    TWI_SendStopCondition();
    return Local_u8Data;
}
