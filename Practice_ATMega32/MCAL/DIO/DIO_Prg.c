/*
 * DIO_Prg.c
 *
 * Created: 07/05/2022 12:56:42
 *  Author: Mohamed
 */ 


#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "Utils.h"

void DIO_InitPin(DIO_Pin_type pin,DIO_PinMode_type mode)
{
	u8 pin_num;
	DIO_Port_type port;
	pin_num=pin%8;
	port=pin/8;
	
	switch(mode)
	{
		case OUTPUT:
		switch(port)
		{
			case PA:
			SET_BIT(DDRA,pin_num);
			CLR_BIT(PORTA,pin_num);
			break;
			case PB:
			SET_BIT(DDRB,pin_num);
			CLR_BIT(PORTB,pin_num);
			break;
			case PC:
			SET_BIT(DDRC,pin_num);
			CLR_BIT(PORTC,pin_num);
			break;
			case PD:
			SET_BIT(DDRD,pin_num);
			CLR_BIT(PORTD,pin_num);
			break;
		}
		break;
		case INFREE:
		switch(port)
		{
			case PA:
			CLR_BIT(DDRA,pin_num);
			CLR_BIT(PORTA,pin_num);
			break;
			case PB:
			CLR_BIT(DDRB,pin_num);
			CLR_BIT(PORTB,pin_num);
			break;
			case PC:
			CLR_BIT(DDRC,pin_num);
			CLR_BIT(PORTC,pin_num);
			break;
			case PD:
			CLR_BIT(DDRD,pin_num);
			CLR_BIT(PORTD,pin_num);
			break;
		}
		break;
		case INPULL:
		switch(port)
		{
			case PA:
			CLR_BIT(DDRA,pin_num);
			SET_BIT(PORTA,pin_num);
			break;
			case PB:
			CLR_BIT(DDRB,pin_num);
			SET_BIT(PORTB,pin_num);
			break;
			case PC:
			CLR_BIT(DDRC,pin_num);
			SET_BIT(PORTC,pin_num);
			break;
			case PD:
			CLR_BIT(DDRD,pin_num);
			SET_BIT(PORTD,pin_num);
			break;
		}
		break;
	}

}

void DIO_Init(void)
{
	DIO_Pin_type i;
	for(i=PINA0;i<TOTAL_PINS;i++)
	{
		DIO_InitPin(i,PinsModeArray[i]);
	}
}



void DIO_WritePin(DIO_Pin_type pin,DIO_PinVoltage_type volt)
{
	u8 pin_num;
	DIO_Port_type port;
	pin_num=pin%8;
	port=pin/8;
	if (volt==HIGH)
	{
		switch(port)
		{
			case PA:
			SET_BIT(PORTA,pin_num);
			break;
			case PB:
			
			SET_BIT(PORTB,pin_num);
			break;
			case PC:
			
			SET_BIT(PORTC,pin_num);
			break;
			case PD:
			
			SET_BIT(PORTD,pin_num);
			break;
		}
	}
	else if (volt==LOW)
	{
		switch(port)
		{
			case PA:
			CLR_BIT(PORTA,pin_num);
			break;
			
			case PB:
			CLR_BIT(PORTB,pin_num);
			break;
			
			case PC:
			CLR_BIT(PORTC,pin_num);
			break;
			
			case PD:
			CLR_BIT(PORTD,pin_num);
			break;
		}
	}
}


DIO_PinVoltage_type DIO_ReadPin(DIO_Pin_type pin)
{
	u8 pin_num;
	DIO_Port_type port;
	pin_num=pin%8;
	port=pin/8;
	DIO_PinVoltage_type volt =LOW;
	switch(port)
	{
		case PA:
		volt = GET_BIT(PINA,pin_num);
		break;
		case PB:
		
		volt = GET_BIT(PINB,pin_num);
		break;
		case PC:
		
		volt = GET_BIT(PINC,pin_num);
		break;
		case PD:
		
		volt = GET_BIT(PIND,pin_num);
		break;
	}
	return volt;
}

void DIO_TogglePin(DIO_Pin_type pin)
{
	u8 pin_num;
	DIO_Port_type port;
	pin_num=pin%8;
	port=pin/8;
	switch(port)
	{
		case PA:
		
		TOG_BIT(PORTA,pin_num);
		break;
		case PB:
		
		TOG_BIT(PORTB,pin_num);
		break;
		case PC:
		
		TOG_BIT(PORTC,pin_num);
		break;
		case PD:
		
		TOG_BIT(PORTD,pin_num);
		break;
	}
	
}

u8 DIO_ReadPort(DIO_Port_type port)
{
	u8 volt=0;
	switch(port)
	{
		case PA:
		volt = PINA;
		break;
		
		case PB:
		volt = PINB;
		break;
		
		case PC:
		volt = PINC;
		break;
		
		case PD:
		volt = PIND;
		break;
	}
	return volt;
}

void DIO_WritePort(DIO_Port_type port,u8 value)
{
	switch(port)
	{
		case PA:
		PORTA = value;
		break;
		
		case PB:
		PORTB = value;
		break;
		
		case PC:
		PORTC = value;
		break;
		
		case PD:
		PORTD = value;
		break;
	}
}