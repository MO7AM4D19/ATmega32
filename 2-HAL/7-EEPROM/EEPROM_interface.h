/**********************************		Auther: Mohamed Khalid Anis		**********************************/
/**********************************		Layer: HAL						**********************************/
/**********************************		SWC: EEPROM     				**********************************/
/**********************************		Version: 1.00					**********************************/

#include "STD_TYPES.h"

#ifndef EEPROM_INTERFACE_H
#define EEPROM_INTERFACE_H

void EEPROM_voidWriteByte(u8 Copy_u8DataByte,u16 Copy_u16MemoryAddress);
u8 EEPROM_u8ReadByte(u16 Copy_u16MemoryAddress);

#endif