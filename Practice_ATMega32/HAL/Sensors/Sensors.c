/*
 * Sensors.c
 *
 * Created: 16/05/2022 01:43:35
 *  Author: Mohamed
 */ 


#include "Sensors.h"

/** return volt in mV **/
u16 POT_ReadVolt(void)
{
	u16 volt;
	u16 adc = ADC_Read(POT_CH);
	volt=((u32)adc*5000)/1024;
	return volt;
}

/** returns temperature in 10*Celsius**/
u16 ReadTemp()
{
	u16 volt;
	u16 temp;
	u16 adc = ADC_Read(LM35_CH);
	volt=((u32)adc*5000)/1024;
	temp=volt;
	return temp;
}

u16 POT_ReadPercentage(void)
{
	u16 adc = ADC_Read(POT_CH);
	u8 per = ((u32)100*adc)/1023;
	return per;
	
}