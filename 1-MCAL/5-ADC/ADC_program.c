/**********************************		Auther: Mohamed Khalid Anis		**********************************/
/**********************************		Layer: MCAL						**********************************/
/**********************************		SWC: ADC						**********************************/
/**********************************		Version: 1.00					**********************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_config.h"
#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_register.h"

ADC_ChanelChain*  ADC_ChainInfoPointer = NULL;

static u16* ADC_u16AsyncChannelReading = NULL;
static void (*ADC_voidFpNotificationFunctionHolder)(void) = NULL;

struct  
{
	u8 ADC_u8AsynchMode:1;
	u8 ADC_u8AsyncFlag:2;
	u8 ADC_u8ChainCounter:4;
}ADC_util;

void ADC_voidInint()
{
    ADC_util.ADC_u8AsynchMode = ASYNCH_INDV;
	ADC_util.ADC_u8AsyncFlag = IDLE;
	ADC_util.ADC_u8ChainCounter = 0;
	ADMUX &= 0b00000000;
    ADMUX |= (ADC_u8REFRANCE_VOLTAGE<<6);
	#if ADC_u8RESOLUTION == ADC_u8BIT_8
	SET_BIT(ADMUX,ADMUX_ADLAR);
	#endif
		
    #if ADC_u8AUTO_TRIGGER == ADC_u8AUTO_TRIGGER_ENABLE
    SET_BIT(ADCSRA,ADCSRA_ADATA);
    #endif

    #if ADC_u8INTRUPUT == ADC_u8INTRUPUT_ENABLE
    SET_BIT(ADCSRA,ADCSRA_ADIE);
    SET_BIT(SFIOR,SFIOR_ADTS1);
    #endif


    ADCSRA |= ADC_u8PRESCALER;
    SET_BIT(ADCSRA,ADCSRA_ADEN);
}

u8 ADC_u16GetChannelValueSync(u8 Copy_Channel,u16* Copy_pu16PinValue)
{
	u8 Local_u8ErrorState = OK;
	if((Copy_pu16PinValue == NULL))
	{
		Local_u8ErrorState = NULL_POINTER;
	}
	else
	{
		u32 Local_u32TimeOutCounter = 0;
		ADMUX &= 0b11100000;
		ADMUX |= Copy_Channel;
		SET_BIT(ADCSRA,ADCSRA_ADSC);
		CLR_BIT(ADCSRA,ADCSRA_ADIE);
		while((0 == GET_BIT(ADCSRA,ADCSRA_ADIF)) && (Local_u32TimeOutCounter < ADC_u32TIME_OUT))
		{
			Local_u32TimeOutCounter++;
		}
		if(Local_u32TimeOutCounter == ADC_u32TIME_OUT)
		{
			Local_u8ErrorState = TIME_OVER;
		}
		else
		{
			SET_BIT(ADCSRA,ADCSRA_ADIF);
			#if ADC_u8RESOLUTION  == ADC_u8BIT_8
			*Copy_pu16PinValue = ADCH;
			#elif ADC_u8RESOLUTION  == ADC_u8BIT_10
			*Copy_pu16PinValue = ADC;
			#endif
		}
	}
	return Local_u8ErrorState;
}

u8 ADC_u16GetChannelValueAsync(u8 Copy_Channel,u16* Copy_pu16PinValue,void(*Copy_voidFpNotificationFnction)(void))
{
	u8 Local_u8ErrorState = OK;
	ADC_util.ADC_u8AsynchMode = ASYNCH_CHAIN;
	if(BUSEY == ADC_util.ADC_u8AsyncFlag)
	{
		Local_u8ErrorState = BUSEY;
	}
	else
	{
		if(Copy_pu16PinValue == NULL || Copy_voidFpNotificationFnction == NULL)
		{
			Local_u8ErrorState = NULL_POINTER;
		}
		else
		{
			ADMUX &= 0b11100000;
			ADMUX |= Copy_Channel;
			SET_BIT(ADCSRA,ADCSRA_ADSC);
			SET_BIT(ADCSRA,ADCSRA_ADIE);
			ADC_u16AsyncChannelReading = Copy_pu16PinValue;
			ADC_voidFpNotificationFunctionHolder = Copy_voidFpNotificationFnction;
		}	
	}
	return Local_u8ErrorState;
}

u8 ADC_voidAsyncChainCheck(ADC_ChanelChain* Copy_pChanelChain)
{
	u8 Local_u8ErrorState = OK;
	if(NULL == Copy_pChanelChain || NULL == Copy_pChanelChain->pResultArr || NULL == Copy_pChanelChain->pChanelsArr || NULL == Copy_pChanelChain->NotFunc)
	{
		Local_u8ErrorState = NULL_POINTER;
	}
	else if(Copy_pChanelChain->ChainLength > 8 || Copy_pChanelChain->ChainLength < 1)
	{
		Local_u8ErrorState = ZERO_SIZE;
	}
	else
	{
		ADC_util.ADC_u8AsynchMode = ASYNCH_CHAIN;
		ADC_ChainInfoPointer = Copy_pChanelChain;
		if(ADC_util.ADC_u8ChainCounter<Copy_pChanelChain->ChainLength)
		{
			ADC_u16GetChannelValueAsync(*(Copy_pChanelChain->pChanelsArr),Copy_pChanelChain->pResultArr,Copy_pChanelChain->NotFunc);
			Copy_pChanelChain->pChanelsArr++;
			Copy_pChanelChain->pResultArr++;
		}
		else
		{
			ADC_util.ADC_u8AsynchMode = ASYNCH_INDV;
		}	
	}
	return Local_u8ErrorState;
}

void __vector_16(void) __attribute__((signal));
void __vector_16(void)
{
	#if ADC_u8RESOLUTION  == ADC_u8BIT_8
	*ADC_u16AsyncChannelReading= ADCH;
	#elif ADC_u8RESOLUTION  == ADC_u8BIT_10
	*ADC_u16AsyncChannelReading = ADC;
	#endif
	ADC_voidFpNotificationFunctionHolder();	
	ADC_util.ADC_u8AsyncFlag = IDLE;
	if(ASYNCH_CHAIN == ADC_util.ADC_u8AsynchMode)
	{
		ADC_u16GetChannelValueAsync((*ADC_ChainInfoPointer->pChanelsArr),ADC_ChainInfoPointer->pResultArr,ADC_ChainInfoPointer->NotFunc);
	}
}
