/**********************************		Auther: Mohamed Khalid Anis		**********************************/
/**********************************		Layer: MCAL						**********************************/
/**********************************		SWC: ADC						**********************************/
/**********************************		Version: 1.00					**********************************/

#include "STD_TYPES.h"

#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

typedef struct
{
	u8* pChanelsArr;
	u16* pResultArr;
	u8  ChainLength;
	void(*NotFunc)(void);
	
} ADC_ChanelChain;

#define ADC_u8AREF                      0
#define ADC_u8AVCC                      1
#define ADC_u8V2_65                     3

#define ADC_u8LEFT_ADJUST               1
#define ADC_u8RIGHT_ADJUST              0

#define ADC_u8SE0                     0b00000
#define ADC_u8SE1                     0b00001
#define ADC_u8SE2                     0b00010
#define ADC_u8SE3                     0b00011
#define ADC_u8SE4                     0b00100
#define ADC_u8SE5                     0b00101
#define ADC_u8SE6                     0b00110
#define ADC_u8SE7                     0b00111

#define ADC_u8DP0N0G10                0b01000
#define ADC_u8DP1N0G10                0b01001
#define ADC_u8DP0N0G200               0b01010
#define ADC_u8DP1N0G200               0b01011
#define ADC_u8DP2N2G10                0b01100
#define ADC_u8DP3N1G10                0b01101
#define ADC_u8DP2N2G200               0b01110
#define ADC_u8DP2N3G200               0b01111

#define ADC_u8DP0N1G1                 0b10000
#define ADC_u8DP1N1G1                 0b10001
#define ADC_u8DP2N1G1                 0b10010
#define ADC_u8DP3N1G1                 0b10011
#define ADC_u8DP4N1G1                 0b10100
#define ADC_u8DP5N1G1                 0b10101
#define ADC_u8DP6N1G1                 0b10110
#define ADC_u8DP7N1G1                 0b10111

#define ADC_u8DP0N2G1                 0b11000
#define ADC_u8DP1N2G1                 0b11001
#define ADC_u8DP2N2G1                 0b11010
#define ADC_u8DP3N2G1                 0b11011
#define ADC_u8DP4N2G1                 0b11100
#define ADC_u8DP5N2G1                 0b11101

#define ADC_u8SE1_22V                 0b11110
#define ADC_u8SE0V                    0b11111

#define ADC_u8BIT_10                 0
#define ADC_u8BIT_8                  1

#define ADC_u8AUTO_TRIGGER_DISABLE    0     
#define ADC_u8AUTO_TRIGGER_ENABLE     1    

#define ADC_u8INTRUPUT_DISABLE        0
#define ADC_u8INTRUPUT_ENABLE         1

#define ADC_u8PRESCALER_2             1
#define ADC_u8PRESCALER_4             2
#define ADC_u8PRESCALER_8             3
#define ADC_u8PRESCALER_16            4
#define ADC_u8PRESCALER_32            5
#define ADC_u8PRESCALER_64            6
#define ADC_u8PRESCALER_128           7

#define ADC_u8EXTERNAL_INT_0          2

void ADC_voidInint();
u8 ADC_u16GetChannelValueAsync(u8 Copy_Channel,u16* Copy_pu16PinValue,void(*Copy_voidFpNotificationFnction)(void));
u8 ADC_u16GetChannelValueSync(u8 Copy_Channel,u16* Copy_pu16PinValue);
u8 ADC_voidAsyncChainCheck(ADC_ChanelChain* Copy_pChanelChain);

#endif