/*
 * Practice_ATMega32.c
 *
 * Created: 07/05/2022 01:35:47
 * Author : Mohamed
 */ 

#include "StdTypes.h"
#include "MemMap.h"
#include "DIO_Interface.h"
#include "LCD.h"
#include "KeyPad.h"
#include "Calculator.h"
#include "ADC.h"
#include "Sensors.h"

#define F_CPU 8000000
#include <util/delay.h>


int main(void)
{
	DIO_Init();
	LCD_Init();
	ADC_Init(VREF_AVCC,ADC_SCALER_64);
	//CLR_BIT(ADMUX,REFS1);
	//SET_BIT(ADMUX,REFS0);
	//ADC_Init(VREF_AVCC,ADC_SCALER_64);
	u16 x;
	
	
	while(1)
	{
		x=POT_ReadPercentage();
		LCD_SetCursor(0,0);
		LCD_WriteNumber(x);
		LCD_WriteString("   ");
		//LCD_WriteChar('c');
		
		LCD_SetCursor(0,5);
		x=ReadTemp();
		LCD_WriteNumber(x);
		
		LCD_SetCursor(1,10);
		x=ADC_Read(CH_0);
		LCD_WriteNumber(x);
		
		LCD_SetCursor(1,0);
		x=POT_ReadVolt();
		LCD_WriteNumber(x);
		LCD_WriteString("   ");
	}
	

}

