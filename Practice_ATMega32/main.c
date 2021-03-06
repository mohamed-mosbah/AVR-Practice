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

static volatile u8 c=0;


int main(void)
{
	u32 num=0;
	DIO_Init();
	LCD_Init();
	ADC_Init(VREF_AVCC,ADC_SCALER_64);
	u16 x;
	ENABLE_GLOBAL_INT();
	//enable timer
	//OCR0=100;
	//TCCR0=0x02;
	
	//enable overflow interrupt
	//TIMSK= 0x01;
	SET_BIT(TIMSK,OCIE0); //enable compare match interrupt
	//SET_BIT(TCCR0,COM00);
	TCCR0=0b01111010; //fast PWM, inverting
	TCNT0=0;
	OCR0=64;
	
	while(1)
	{
		num=ADC_Read(CH_1);
		OCR0=num/4;
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
	
	DIO_TogglePin(PINC1);
}
ISR(TIMER0_OC_vect)
{
	DIO_TogglePin(PINC0);
}

