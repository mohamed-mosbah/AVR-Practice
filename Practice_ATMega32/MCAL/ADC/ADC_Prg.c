/*
 * ADC_Prg.c
 *
 * Created: 14/05/2022 22:53:08
 *  Author: Mohamed
 */ 
#include "ADC.h"

#define F_CPU 8000000
#include <util/delay.h>

static u8 read_flag=1;

void ADC_Init(ADC_Volt_type ref, ADC_Scaler_type scaler)
{
	//setting up the Prescaler 
	ADCSRA = ADCSRA & 0xF8; //0B11111000
	scaler = scaler & 0x07;
	ADCSRA = ADCSRA | scaler;
	
	//volt reference
	switch(ref)
	{
		case VREF_AREF:
		CLR_BIT(ADMUX,REFS1);
		CLR_BIT(ADMUX,REFS0);
		break;
		case VREF_AVCC:
		CLR_BIT(ADMUX,REFS1);
		SET_BIT(ADMUX,REFS0);
		break;
		case VREF_256V:
		SET_BIT(ADMUX,REFS1);
		SET_BIT(ADMUX,REFS0);
		break;
	}
	//READ adjusted
	CLR_BIT(ADMUX,ADLAR);
	
	// Enabling the ADC
	SET_BIT(ADCSRA,ADEN);
}
u16 ADC_Read(ADC_Channel_type ch)
{
	u16 adc;
	//select ch
	ADMUX=ADMUX&0xE0; //0B11100000
	ADMUX=ADMUX|ch;
	
	//start conversion
	SET_BIT(ADCSRA,ADSC);
	// waiting until ADC finishes the conversion
	while(GET_BIT(ADCSRA,ADSC)); //busy waiting
	//read
	//adc=((u16)ADCH<<8)|(u16)ADCL;
	adc=ADC;
	return adc;
}

void ADC_StartConversion(ADC_Channel_type ch)
{
	if (read_flag==1)
	{
		//select ch
		ADMUX=ADMUX&0xE0; //0B11100000
		ADMUX=ADMUX|ch;
		
		//start conversion
		SET_BIT(ADCSRA,ADSC);
		read_flag=0;
	}
	
}

u16 ADC_GetADCValue(void)
{
		while(GET_BIT(ADCSRA,ADSC)); //busy waiting
		read_flag=1;
		//read
		//adc=((u16)ADCH<<8)|(u16)ADCL;
		return ADC;
}

u16 ADC_GetADCValuePeriodicCheck(u16 *pdata)
{
	if(GET_BIT(ADCSRA,ADSC)==0) //busy waiting
	{
		*pdata=ADC;
		read_flag=1;
		return 1;
	}
	else
	{
		return 0;
	}
}