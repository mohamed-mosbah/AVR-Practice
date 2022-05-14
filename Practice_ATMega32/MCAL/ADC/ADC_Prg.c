/*
 * ADC_Prg.c
 *
 * Created: 14/05/2022 22:53:08
 *  Author: Mohamed
 */ 
#include "ADC.h"

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
	// Enabling the ADC
	SET_BIT(ADCSRA,ADEN);
}
u16 ADC_Read(ADC_Channel_type ch)
{
	//select ch
	//read
}