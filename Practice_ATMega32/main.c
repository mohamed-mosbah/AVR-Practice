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
#include "Exinterrupt.h"

#define F_CPU 8000000
#include <util/delay.h>


#define		ADC_VECT		__vector_10




int main(void)
{
	DIO_Init();
	LCD_Init();
	ADC_Init(VREF_AVCC,ADC_SCALER_64);
	u16 x;
	ENABLE_GLOBAL_INT();
	//enable timer
	TCCR0=0x02;
	//enable overflow interrupt
	TIMSK= 0x01;
	
	
	while(1)
	{
		x=POT_ReadPercentage();
		LCD_SetCursor(0,0);
		LCD_WriteNumber(x);
		LCD_WriteString("   ");
		//LCD_WriteChar('c');
		
		
		ADC_StartConversion(CH_1);
		if(ADC_GetADCValuePeriodicCheck(&x))
		{
			LCD_SetCursor(1,10);
			LCD_WriteNumber(x);
			LCD_WriteString("   ");
		}
		
		
		LCD_SetCursor(1,0);
		x=POT_ReadVolt();
		LCD_WriteNumber(x);
		LCD_WriteString("   ");
	}
	

}
/*
ISR(TIMER0_OVF_vect)
{
	 static u16 c=0;
	 c++;
	 if((c==3906)||(c==7812))
	 {
		 DIO_TogglePin(PINC0);
	 }
	 if(c==7812)
	 {
		DIO_TogglePin(PINC1);
		c=0;
	 }
}
*/

ISR(TIMER0_OVF_vect)
{
	static u8 c=0;
	c++;
	TCNT0=6;
	if(c==72)
	{
		DIO_WritePin(PINC3,HIGH);
	}
	else if (c==80)
	{
		DIO_WritePin(PINC3,LOW);
		c=0;
	}
}


