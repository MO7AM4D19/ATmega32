/**********************************		Auther: Mohamed Khalid Anis		**********************************/
/**********************************		Layer: MCAL						**********************************/
/**********************************		SWC: Timer						**********************************/
/**********************************		Version: 1.00					**********************************/

#ifndef TMR_REGISTER_H
#define TMR_REGISTER_H

#define TIMSK               *((volatile u8*)0x59)
#define TIMSK_TOIE0         0
#define TIMSK_OCIE0         1

#define TIFR                *((volatile u8*)0x58)
#define TIFR_TOV0           0
#define TIFR_OCF0           1

/*Timer 0 registers*/
#define TCCR0               *((volatile u8*)0x53)
#define TCCR0_CS00          0
#define TCCR0_CS01          1
#define TCCR0_CS02          2
#define TCCR0_WGM01         3
#define TCCR0_COM00         4
#define TCCR0_COM01         5
#define TCCR0_WGM00         6
#define TCCR0_FOC           7

#define TCNT0               *((volatile u8*)0x52)
#define OCR0                *((volatile u8*)0x5C)

/*timer 1 registers*/

#define TCCR1A              *((volatile u8*)0x4F)
#define TCCR1A_WGM10        0
#define TCCR1A_WGM11        1
#define TCCR1A_FOC1B        2
#define TCCR1A_FOC1A        3
#define TCCR1A_COM1B0       4
#define TCCR1A_COM1B1       5
#define TCCR1A_COM1A0       6
#define TCCR1A_COM1A1       7

#define TCCR1B              *((volatile u8*)0x4E)
#define TCCR1B_CS10         0
#define TCCR1B_CS11         1
#define TCCR1B_CS12         2
#define TCCR1B_WGM12        3
#define TCCR1B_WGM13        4
#define TCCR1B_ICES1        6
#define TCCR1B_ICNC1        7

#define TCNT1H              *((volatile u8*)0x4D)
#define TCCR1L              *((volatile u8*)0x4C)
#define OCR1AH              *((volatile u8*)0x4B)
#define OCR1AL              *((volatile u8*)0x4A)
#define OCR1BH              *((volatile u8*)0x49)
#define OCR1BL              *((volatile u8*)0x48)
#define ICR1H               *((volatile u8*)0x47)
#define ICR1L               *((volatile u8*)0x46)

/*timer 2 registers*/
#define TCCR2               *((volatile u8*)0x45)
#define TCCR2_CS20          0
#define TCCR2_CS21          1
#define TCCR2_CS22          2
#define TCCR2_WGM21         3
#define TCCR2_COM20         4
#define TCCR2_COM21         5
#define TCCR2_WGM20         6
#define TCCR2_FOC2          7

#define TCNT2               *((volatile u8*)0x44)
#define OCR2                *((volatile u8*)0x43)







#endif