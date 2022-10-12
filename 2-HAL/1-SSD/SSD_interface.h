/**********************************		Auther: Mohamed Khalid Anis		**********************************/
/**********************************		Layer: HAL						**********************************/
/**********************************		SWC: Seven Segmant display		**********************************/
/**********************************		Version: 1.00					**********************************/

#include "STD_TYPES.h"

#ifndef SSD_INTERFACE_H
#define SSD_INTERFACE_h

typedef struct 
{
    u8 SSD_u8CommonType:1;      /*0 for common cathod and 1 for common anode*/
    u8 SSD_u8EnablePort:2;
    u8 SSD_u8DisplPort :2;      
    u8 SSD_u8EnaplePin :3;
    u8 SSD_u8Number;
}SSD;

#define SSD_u8COMMON_CATHOD     0
#define SSD_u8COMMON_ANODE      1

#define SSD_u8NUMBER0			0x3F
#define SSD_u8NUMBER1			0x06
#define SSD_u8NUMBER2           0x5B
#define SSD_u8NUMBER3           0x4F
#define SSD_u8NUMBER4           0x66
#define SSD_u8NUMBER5           0x6D
#define SSD_u8NUMBER6           0xFD
#define SSD_u8NUMBER7           0x07
#define SSD_u8NUMBER8           0xFF
#define SSD_u8NUMBER9           0x6F

u8 SSD_u8DisplayNumber(SSD* Copy_pu8SSD,u8 Copy_u8Number);

#endif