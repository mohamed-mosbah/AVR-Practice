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
	LCD_Clear();
	
	LCD_WriteString("D:");
	LCD_SetCursor(0,6);
	LCD_WriteString("H:");
	LCD_SetCursor(1,0);
	LCD_WriteString("B:");
	u8 x=0;
    while (1) 
    {
		
		LCD_SetCursor(0,2);
		LCD_WriteNumber(x);
		LCD_SetCursor(0,8);
		LCD_WriteHex(x);
		LCD_SetCursor(1,2);
		LCD_WriteBinary_8B(x);

		x++;
		_delay_ms(1000);
    }
}

