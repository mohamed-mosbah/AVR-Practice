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


int main(void)
{
	DIO_Init();
	LCD_Init();
	u8 i=0;
	u8 row=0;
	LCD_Clear();
	LCD_SetCursor(0,0);
	LCD_WriteString("Char :");
	LCD_SetCursor(1,0);
	LCD_WriteString("Ascii:");
    while (1) 
    {
		u8 i ;
		
		for(i='A';i<='Z';i++)
		{
			LCD_SetCursor(0,7);
			LCD_WriteChar(i);
			LCD_SetCursor(1,7);
			LCD_WriteString("   ");
			LCD_SetCursor(1,7);
			LCD_WriteNumber(i);
			_delay_ms(300);
		}
		
		for(i='a';i<='z';i++)
		{
			LCD_SetCursor(0,7);
			LCD_WriteChar(i);
			LCD_SetCursor(1,7);
			LCD_WriteString("   ");
			LCD_SetCursor(1,7);
			LCD_WriteNumber(i);
			_delay_ms(300);
		}
	
		for(i='0';i<='9';i++)
		{
			LCD_SetCursor(0,7);
			LCD_WriteChar(i);
			LCD_SetCursor(1,7);
			LCD_WriteString("   ");
			LCD_SetCursor(1,7);
			LCD_WriteNumber(i);
			_delay_ms(300);
		}
		
    }
}

