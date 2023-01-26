/**********************************		Auther: Mohamed Khalid Anis		**********************************/
/**********************************		Layer: HAL						**********************************/
/**********************************		SWC: Motors     				**********************************/
/**********************************		Version: 1.00					**********************************/

#include "MOT_config.h"
#include "MOT_interface.h"
#include "MOT_private.h"
#include "DIO_interface.h"

void MOT_voidDCRotate(struct DCMotor * MOT_pu8MotorConfig,u8 Copy_u8RotationDir)
{
    if(MOT_ROTATE_CW==Copy_u8RotationDir)
    {
        DIO_u8SetPinValue(MOT_pu8MotorConfig->MOT_u8MotorPort,MOT_pu8MotorConfig->MOT_u8ControlPin1,DIO_u8PIN_HIGH);
        DIO_u8SetPinValue(MOT_pu8MotorConfig->MOT_u8MotorPort,MOT_pu8MotorConfig->MOT_u8ControlPin2,DIO_u8PIN_LOW);

    }
    else if(MOT_ROTATE_CCW==Copy_u8RotationDir)
    {
        DIO_u8SetPinValue(MOT_pu8MotorConfig->MOT_u8MotorPort,MOT_pu8MotorConfig->MOT_u8ControlPin2,DIO_u8PIN_HIGH);
        DIO_u8SetPinValue(MOT_pu8MotorConfig->MOT_u8MotorPort,MOT_pu8MotorConfig->MOT_u8ControlPin1,DIO_u8PIN_LOW);

    }
}

void MOT_voidDCStop(struct DCMotor * MOT_pu8MotorConfig)
{
    DIO_u8SetPinValue(MOT_pu8MotorConfig->MOT_u8MotorPort,MOT_pu8MotorConfig->MOT_u8ControlPin2,DIO_u8PIN_HIGH);
    DIO_u8SetPinValue(MOT_pu8MotorConfig->MOT_u8MotorPort,MOT_pu8MotorConfig->MOT_u8ControlPin1,DIO_u8PIN_HIGH);
}
