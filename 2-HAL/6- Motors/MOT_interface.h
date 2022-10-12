/**********************************		Auther: Mohamed Khalid Anis		**********************************/
/**********************************		Layer: HAL						**********************************/
/**********************************		SWC: Motors     				**********************************/
/**********************************		Version: 1.00					**********************************/

#include "STD_TYPES.h"

#ifndef MOT_INTERFACE_H
#define MOT_INTERFACE_H

/* DC Motors */
struct DCMotor
{
    u8 MOT_u8MotorPort:2;
    u8 MOT_u8ControlPin1:3;
    u8 MOT_u8ControlPin2:3;
};

#define MOT_ROTATE_CW                           0
#define MOT_ROTATE_CCW                          1


void MOT_voidDCRotate(struct DCMotor * MOT_pu8MotorConfig,u8 Copy_u8RotationDir);
void MOT_voidDCStop(struct DCMotor * MOT_pu8MotorConfig);

/* Stepper Motor */


#endif