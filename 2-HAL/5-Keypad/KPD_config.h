/**********************************		Auther: Mohamed Khalid Anis		**********************************/
/**********************************		Layer: HAL						**********************************/
/**********************************		SWC: Keypad     				**********************************/
/**********************************		Version: 1.00					**********************************/

#ifndef KPD_CONFIG_H
#define KPD_CONFIG_H
#define KPD_pu8KEYS                      {{'7','8','9','/'},{'4','5','6','x'},{'1','2','3','-'},{'_','0','=','+'}}
#define KPD_u8NOT_PRESSED               0xff
#define KPD_u8KEYPAD_PORT               DIO_u8PORTD
#define KPD_u8COUMN1_PIN                DIO_u8PIN4
#define KPD_u8COUMN2_PIN                DIO_u8PIN5
#define KPD_u8COUMN3_PIN                DIO_u8PIN6
#define KPD_u8COUMN4_PIN                DIO_u8PIN7
#define KPD_u8ROW1_PIN                  DIO_u8PIN0
#define KPD_u8ROW2_PIN                  DIO_u8PIN1
#define KPD_u8ROW3_PIN                  DIO_u8PIN2
#define KPD_u8ROW4_PIN                  DIO_u8PIN3
#endif